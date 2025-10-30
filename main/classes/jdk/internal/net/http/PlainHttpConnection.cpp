#include <jdk/internal/net/http/PlainHttpConnection.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/ConnectException.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketOption.h>
#include <java/net/StandardSocketOptions.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/NetworkChannel.h>
#include <java/nio/channels/SelectableChannel.h>
#include <java/nio/channels/SocketChannel.h>
#include <java/nio/channels/spi/AbstractSelectableChannel.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/time/Duration.h>
#include <java/time/Instant.h>
#include <java/util/Optional.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/AsyncEvent.h>
#include <jdk/internal/net/http/ConnectionPool$CacheKey.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpConnection$HttpPublisher.h>
#include <jdk/internal/net/http/HttpConnection$PlainHttpPublisher.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/PlainHttpConnection$ConnectEvent.h>
#include <jdk/internal/net/http/PlainHttpConnection$ConnectState.h>
#include <jdk/internal/net/http/PlainHttpConnection$ConnectTimerEvent.h>
#include <jdk/internal/net/http/SocketTube.h>
#include <jdk/internal/net/http/TimeoutEvent.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef RETRY
#undef RETRY_CONNECT
#undef SO_RCVBUF
#undef SO_SNDBUF
#undef SUCCESS
#undef TCP_NODELAY

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ConnectException = ::java::net::ConnectException;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketOption = ::java::net::SocketOption;
using $StandardSocketOptions = ::java::net::StandardSocketOptions;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $NetworkChannel = ::java::nio::channels::NetworkChannel;
using $SelectableChannel = ::java::nio::channels::SelectableChannel;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $AbstractInterruptibleChannel = ::java::nio::channels::spi::AbstractInterruptibleChannel;
using $AbstractSelectableChannel = ::java::nio::channels::spi::AbstractSelectableChannel;
using $AccessController = ::java::security::AccessController;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Duration = ::java::time::Duration;
using $Instant = ::java::time::Instant;
using $Optional = ::java::util::Optional;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $BiFunction = ::java::util::function::BiFunction;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;
using $AsyncEvent = ::jdk::internal::net::http::AsyncEvent;
using $ConnectionPool$CacheKey = ::jdk::internal::net::http::ConnectionPool$CacheKey;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpConnection$HttpPublisher = ::jdk::internal::net::http::HttpConnection$HttpPublisher;
using $HttpConnection$PlainHttpPublisher = ::jdk::internal::net::http::HttpConnection$PlainHttpPublisher;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;
using $PlainHttpConnection$ConnectEvent = ::jdk::internal::net::http::PlainHttpConnection$ConnectEvent;
using $PlainHttpConnection$ConnectState = ::jdk::internal::net::http::PlainHttpConnection$ConnectState;
using $PlainHttpConnection$ConnectTimerEvent = ::jdk::internal::net::http::PlainHttpConnection$ConnectTimerEvent;
using $SocketTube = ::jdk::internal::net::http::SocketTube;
using $TimeoutEvent = ::jdk::internal::net::http::TimeoutEvent;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class PlainHttpConnection$$Lambda$lambda$connectAsync$0 : public $PrivilegedExceptionAction {
	$class(PlainHttpConnection$$Lambda$lambda$connectAsync$0, $NO_CLASS_INIT, $PrivilegedExceptionAction)
public:
	void init$(PlainHttpConnection* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$connectAsync$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PlainHttpConnection$$Lambda$lambda$connectAsync$0>());
	}
	PlainHttpConnection* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PlainHttpConnection$$Lambda$lambda$connectAsync$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(PlainHttpConnection$$Lambda$lambda$connectAsync$0, inst$)},
	{}
};
$MethodInfo PlainHttpConnection$$Lambda$lambda$connectAsync$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/PlainHttpConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(PlainHttpConnection$$Lambda$lambda$connectAsync$0::*)(PlainHttpConnection*)>(&PlainHttpConnection$$Lambda$lambda$connectAsync$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo PlainHttpConnection$$Lambda$lambda$connectAsync$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PlainHttpConnection$$Lambda$lambda$connectAsync$0",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	fieldInfos,
	methodInfos
};
$Class* PlainHttpConnection$$Lambda$lambda$connectAsync$0::load$($String* name, bool initialize) {
	$loadClass(PlainHttpConnection$$Lambda$lambda$connectAsync$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PlainHttpConnection$$Lambda$lambda$connectAsync$0::class$ = nullptr;

class PlainHttpConnection$$Lambda$lambda$connectAsync$1$1 : public $BiFunction {
	$class(PlainHttpConnection$$Lambda$lambda$connectAsync$1$1, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(PlainHttpConnection* inst, $Exchange* exchange) {
		$set(this, inst$, inst);
		$set(this, exchange, exchange);
	}
	virtual $Object* apply(Object$* r, Object$* t) override {
		 return $of($nc(inst$)->lambda$connectAsync$1(exchange, $cast($PlainHttpConnection$ConnectState, r), $cast($Throwable, t)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PlainHttpConnection$$Lambda$lambda$connectAsync$1$1>());
	}
	PlainHttpConnection* inst$ = nullptr;
	$Exchange* exchange = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PlainHttpConnection$$Lambda$lambda$connectAsync$1$1::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(PlainHttpConnection$$Lambda$lambda$connectAsync$1$1, inst$)},
	{"exchange", "Ljdk/internal/net/http/Exchange;", nullptr, $PUBLIC, $field(PlainHttpConnection$$Lambda$lambda$connectAsync$1$1, exchange)},
	{}
};
$MethodInfo PlainHttpConnection$$Lambda$lambda$connectAsync$1$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/PlainHttpConnection;Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(PlainHttpConnection$$Lambda$lambda$connectAsync$1$1::*)(PlainHttpConnection*,$Exchange*)>(&PlainHttpConnection$$Lambda$lambda$connectAsync$1$1::init$))},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo PlainHttpConnection$$Lambda$lambda$connectAsync$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PlainHttpConnection$$Lambda$lambda$connectAsync$1$1",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* PlainHttpConnection$$Lambda$lambda$connectAsync$1$1::load$($String* name, bool initialize) {
	$loadClass(PlainHttpConnection$$Lambda$lambda$connectAsync$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PlainHttpConnection$$Lambda$lambda$connectAsync$1$1::class$ = nullptr;

class PlainHttpConnection$$Lambda$getBuffer$2 : public $Supplier {
	$class(PlainHttpConnection$$Lambda$getBuffer$2, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($Utils::getBuffer());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PlainHttpConnection$$Lambda$getBuffer$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo PlainHttpConnection$$Lambda$getBuffer$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(PlainHttpConnection$$Lambda$getBuffer$2::*)()>(&PlainHttpConnection$$Lambda$getBuffer$2::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo PlainHttpConnection$$Lambda$getBuffer$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PlainHttpConnection$$Lambda$getBuffer$2",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* PlainHttpConnection$$Lambda$getBuffer$2::load$($String* name, bool initialize) {
	$loadClass(PlainHttpConnection$$Lambda$getBuffer$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PlainHttpConnection$$Lambda$getBuffer$2::class$ = nullptr;

$FieldInfo _PlainHttpConnection_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(PlainHttpConnection, $assertionsDisabled)},
	{"reading", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(PlainHttpConnection, reading)},
	{"chan", "Ljava/nio/channels/SocketChannel;", nullptr, $PROTECTED | $FINAL, $field(PlainHttpConnection, chan)},
	{"tube", "Ljdk/internal/net/http/SocketTube;", nullptr, $PRIVATE | $FINAL, $field(PlainHttpConnection, tube)},
	{"writePublisher", "Ljdk/internal/net/http/HttpConnection$PlainHttpPublisher;", nullptr, $PRIVATE | $FINAL, $field(PlainHttpConnection, writePublisher)},
	{"connected", "Z", nullptr, $PRIVATE | $VOLATILE, $field(PlainHttpConnection, connected$)},
	{"closed", "Z", nullptr, $PRIVATE, $field(PlainHttpConnection, closed)},
	{"connectTimerEvent", "Ljdk/internal/net/http/PlainHttpConnection$ConnectTimerEvent;", nullptr, $PRIVATE | $VOLATILE, $field(PlainHttpConnection, connectTimerEvent)},
	{"unsuccessfulAttempts", "I", nullptr, $PRIVATE | $VOLATILE, $field(PlainHttpConnection, unsuccessfulAttempts)},
	{}
};

$MethodInfo _PlainHttpConnection_MethodInfo_[] = {
	{"<init>", "(Ljava/net/InetSocketAddress;Ljdk/internal/net/http/HttpClientImpl;)V", nullptr, 0, $method(static_cast<void(PlainHttpConnection::*)($InetSocketAddress*,$HttpClientImpl*)>(&PlainHttpConnection::init$))},
	{"cacheKey", "()Ljdk/internal/net/http/ConnectionPool$CacheKey;", nullptr, 0},
	{"canRetryConnect", "(Ljava/lang/Throwable;)Z", nullptr, $PRIVATE, $method(static_cast<bool(PlainHttpConnection::*)($Throwable*)>(&PlainHttpConnection::canRetryConnect))},
	{"channel", "()Ljava/nio/channels/SocketChannel;", nullptr, 0},
	{"checkRetryConnect", "(Ljdk/internal/net/http/PlainHttpConnection$ConnectState;Ljava/lang/Throwable;Ljdk/internal/net/http/Exchange;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/PlainHttpConnection$ConnectState;Ljava/lang/Throwable;Ljdk/internal/net/http/Exchange<*>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PRIVATE, $method(static_cast<$CompletableFuture*(PlainHttpConnection::*)($PlainHttpConnection$ConnectState*,$Throwable*,$Exchange*)>(&PlainHttpConnection::checkRetryConnect))},
	{"close", "()V", nullptr, $PUBLIC},
	{"connectAsync", "(Ljdk/internal/net/http/Exchange;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/Exchange<*>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC},
	{"connected", "()Z", nullptr, $SYNCHRONIZED},
	{"finishConnect", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC},
	{"getConnectionFlow", "()Ljdk/internal/net/http/common/FlowTube;", nullptr, $FINAL},
	{"getSoReceiveBufferSize", "()I", nullptr, $PRIVATE, $method(static_cast<int32_t(PlainHttpConnection::*)()>(&PlainHttpConnection::getSoReceiveBufferSize))},
	{"getSoSendBufferSize", "()I", nullptr, $PRIVATE, $method(static_cast<int32_t(PlainHttpConnection::*)()>(&PlainHttpConnection::getSoSendBufferSize))},
	{"isProxied", "()Z", nullptr, 0},
	{"isSecure", "()Z", nullptr, 0},
	{"lambda$connectAsync$0", "()Ljava/lang/Boolean;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$Boolean*(PlainHttpConnection::*)()>(&PlainHttpConnection::lambda$connectAsync$0)), "java.lang.Exception"},
	{"lambda$connectAsync$1", "(Ljdk/internal/net/http/Exchange;Ljdk/internal/net/http/PlainHttpConnection$ConnectState;Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletableFuture*(PlainHttpConnection::*)($Exchange*,$PlainHttpConnection$ConnectState*,$Throwable*)>(&PlainHttpConnection::lambda$connectAsync$1))},
	{"newConnectTimer", "(Ljdk/internal/net/http/Exchange;Ljava/util/concurrent/CompletableFuture;)Ljdk/internal/net/http/PlainHttpConnection$ConnectTimerEvent;", "(Ljdk/internal/net/http/Exchange<*>;Ljava/util/concurrent/CompletableFuture<*>;)Ljdk/internal/net/http/PlainHttpConnection$ConnectTimerEvent;", $PRIVATE, $method(static_cast<$PlainHttpConnection$ConnectTimerEvent*(PlainHttpConnection::*)($Exchange*,$CompletableFuture*)>(&PlainHttpConnection::newConnectTimer))},
	{"proxy", "()Ljava/net/InetSocketAddress;", nullptr, 0},
	{"publisher", "()Ljdk/internal/net/http/HttpConnection$HttpPublisher;", nullptr, 0},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"trySetReceiveBufferSize", "(I)Z", nullptr, $PRIVATE, $method(static_cast<bool(PlainHttpConnection::*)(int32_t)>(&PlainHttpConnection::trySetReceiveBufferSize))},
	{"trySetSendBufferSize", "(I)Z", nullptr, $PRIVATE, $method(static_cast<bool(PlainHttpConnection::*)(int32_t)>(&PlainHttpConnection::trySetSendBufferSize))},
	{}
};

$InnerClassInfo _PlainHttpConnection_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.PlainHttpConnection$ConnectEvent", "jdk.internal.net.http.PlainHttpConnection", "ConnectEvent", $FINAL},
	{"jdk.internal.net.http.PlainHttpConnection$ConnectTimerEvent", "jdk.internal.net.http.PlainHttpConnection", "ConnectTimerEvent", $FINAL},
	{"jdk.internal.net.http.PlainHttpConnection$ConnectState", "jdk.internal.net.http.PlainHttpConnection", "ConnectState", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _PlainHttpConnection_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.PlainHttpConnection",
	"jdk.internal.net.http.HttpConnection",
	nullptr,
	_PlainHttpConnection_FieldInfo_,
	_PlainHttpConnection_MethodInfo_,
	nullptr,
	nullptr,
	_PlainHttpConnection_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.PlainHttpConnection$ConnectEvent,jdk.internal.net.http.PlainHttpConnection$ConnectTimerEvent,jdk.internal.net.http.PlainHttpConnection$ConnectState"
};

$Object* allocate$PlainHttpConnection($Class* clazz) {
	return $of($alloc(PlainHttpConnection));
}

bool PlainHttpConnection::$assertionsDisabled = false;

$PlainHttpConnection$ConnectTimerEvent* PlainHttpConnection::newConnectTimer($Exchange* exchange, $CompletableFuture* cf) {
	$useLocalCurrentObjectStackCache();
	$var($Duration, duration, $cast($Duration, $nc($($nc(exchange)->remainingConnectTimeout()))->orElse(nullptr)));
	if (duration != nullptr) {
		$var($PlainHttpConnection$ConnectTimerEvent, cte, $new($PlainHttpConnection$ConnectTimerEvent, this, duration, exchange, cf));
		return cte;
	}
	return nullptr;
}

$CompletableFuture* PlainHttpConnection::connectAsync($Exchange* exchange) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($CompletableFuture, cf, $new($MinimalFuture));
	try {
		if (!PlainHttpConnection::$assertionsDisabled && ! !this->connected$) {
			$throwNew($AssertionError, $of("Already connected"_s));
		}
		if (!PlainHttpConnection::$assertionsDisabled && ! !$nc(this->chan)->isBlocking()) {
			$throwNew($AssertionError, $of("Unexpected blocking channel"_s));
		}
		bool finished = false;
		if (this->connectTimerEvent == nullptr) {
			$set(this, connectTimerEvent, newConnectTimer(exchange, cf));
			if (this->connectTimerEvent != nullptr) {
				if ($nc(this->debug)->on()) {
					$nc(this->debug)->log($$str({"registering connect timer: "_s, this->connectTimerEvent}));
				}
				$nc($(client()))->registerTimer(this->connectTimerEvent);
			}
		}
		$var($PrivilegedExceptionAction, pa, static_cast<$PrivilegedExceptionAction*>($new(PlainHttpConnection$$Lambda$lambda$connectAsync$0, this)));
		try {
			finished = $nc(($cast($Boolean, $($AccessController::doPrivileged(pa)))))->booleanValue();
		} catch ($PrivilegedActionException& e) {
			$throw($(e->getCause()));
		}
		if (finished) {
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("connect finished without blocking"_s);
			}
			$init($PlainHttpConnection$ConnectState);
			cf->complete($PlainHttpConnection$ConnectState::SUCCESS);
		} else {
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("registering connect event"_s);
			}
			$nc($(client()))->registerEvent($$new($PlainHttpConnection$ConnectEvent, this, cf, exchange));
		}
		$assign(cf, $nc(exchange)->checkCancelled(cf, this));
	} catch ($Throwable& throwable) {
		cf->completeExceptionally($($Utils::toConnectException(throwable)));
		try {
			close();
		} catch ($Exception& x) {
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("Failed to close channel after unsuccessful connect"_s);
			}
		}
	}
	return $cast($CompletableFuture, $nc($($cast($CompletableFuture, cf->handle(static_cast<$BiFunction*>($$new(PlainHttpConnection$$Lambda$lambda$connectAsync$1$1, this, exchange))))))->thenCompose($($Function::identity())));
}

$CompletableFuture* PlainHttpConnection::checkRetryConnect($PlainHttpConnection$ConnectState* connect, $Throwable* failed, $Exchange* exchange) {
	$useLocalCurrentObjectStackCache();
	if (failed != nullptr) {
		return $MinimalFuture::failedFuture(failed);
	}
	$init($PlainHttpConnection$ConnectState);
	if (connect == $PlainHttpConnection$ConnectState::RETRY) {
		int32_t attempts = this->unsuccessfulAttempts;
		if (!PlainHttpConnection::$assertionsDisabled && !(attempts <= 1)) {
			$throwNew($AssertionError);
		}
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Retrying connect after %d attempts"_s, $$new($ObjectArray, {$($of($Integer::valueOf(attempts)))}));
		}
		return connectAsync(exchange);
	}
	if (!PlainHttpConnection::$assertionsDisabled && !(connect == $PlainHttpConnection$ConnectState::SUCCESS)) {
		$throwNew($AssertionError);
	}
	return $MinimalFuture::completedFuture(nullptr);
}

bool PlainHttpConnection::canRetryConnect($Throwable* e) {
	$useLocalCurrentObjectStackCache();
	$init($MultiExchange);
	if (!$MultiExchange::RETRY_CONNECT) {
		return false;
	}
	if (!($instanceOf($ConnectException, e))) {
		return false;
	}
	if (this->unsuccessfulAttempts > 0) {
		return false;
	}
	$var($PlainHttpConnection$ConnectTimerEvent, timer, this->connectTimerEvent);
	if (timer == nullptr) {
		return true;
	}
	return $nc($($nc(timer)->deadline()))->isAfter($($Instant::now()));
}

$CompletableFuture* PlainHttpConnection::finishConnect() {
	if (!PlainHttpConnection::$assertionsDisabled && !(this->connected$ == false)) {
		$throwNew($AssertionError);
	}
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("finishConnect, setting connected=true"_s);
	}
	this->connected$ = true;
	if (this->connectTimerEvent != nullptr) {
		$nc($(client()))->cancelTimer(this->connectTimerEvent);
	}
	return $MinimalFuture::completedFuture(nullptr);
}

$SocketChannel* PlainHttpConnection::channel() {
	return this->chan;
}

$FlowTube* PlainHttpConnection::getConnectionFlow() {
	return this->tube;
}

void PlainHttpConnection::init$($InetSocketAddress* addr, $HttpClientImpl* client) {
	$useLocalCurrentObjectStackCache();
	$HttpConnection::init$(addr, client);
	$set(this, reading, $new($Object));
	$set(this, writePublisher, $new($HttpConnection$PlainHttpPublisher, this, this->reading));
	try {
		$set(this, chan, $SocketChannel::open());
		$nc(this->chan)->configureBlocking(false);
		if ($nc(this->debug)->on()) {
			int32_t bufsize = getSoReceiveBufferSize();
			$nc(this->debug)->log("Initial receive buffer size is: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(bufsize)))}));
			bufsize = getSoSendBufferSize();
			$nc(this->debug)->log("Initial send buffer size is: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(bufsize)))}));
		}
		if (trySetReceiveBufferSize($nc(client)->getReceiveBufferSize())) {
			if ($nc(this->debug)->on()) {
				int32_t bufsize = getSoReceiveBufferSize();
				$nc(this->debug)->log("Receive buffer size configured: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(bufsize)))}));
			}
		}
		if (trySetSendBufferSize($nc(client)->getSendBufferSize())) {
			if ($nc(this->debug)->on()) {
				int32_t bufsize = getSoSendBufferSize();
				$nc(this->debug)->log("Send buffer size configured: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(bufsize)))}));
			}
		}
		$init($StandardSocketOptions);
		$nc(this->chan)->setOption($StandardSocketOptions::TCP_NODELAY, $($Boolean::valueOf(true)));
		$var($HttpClientImpl, var$0, this->client());
		$var($SocketChannel, var$1, this->chan);
		$set(this, tube, $new($SocketTube, var$0, var$1, static_cast<$Supplier*>($$new(PlainHttpConnection$$Lambda$getBuffer$2))));
	} catch ($IOException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
}

int32_t PlainHttpConnection::getSoReceiveBufferSize() {
	$useLocalCurrentObjectStackCache();
	try {
		$init($StandardSocketOptions);
		return $nc(($cast($Integer, $($nc(this->chan)->getOption($StandardSocketOptions::SO_RCVBUF)))))->intValue();
	} catch ($IOException& x) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Failed to get initial receive buffer size on %s"_s, $$new($ObjectArray, {$of(this->chan)}));
		}
	}
	return 0;
}

int32_t PlainHttpConnection::getSoSendBufferSize() {
	$useLocalCurrentObjectStackCache();
	try {
		$init($StandardSocketOptions);
		return $nc(($cast($Integer, $($nc(this->chan)->getOption($StandardSocketOptions::SO_SNDBUF)))))->intValue();
	} catch ($IOException& x) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Failed to get initial receive buffer size on %s"_s, $$new($ObjectArray, {$of(this->chan)}));
		}
	}
	return 0;
}

bool PlainHttpConnection::trySetReceiveBufferSize(int32_t bufsize) {
	$useLocalCurrentObjectStackCache();
	try {
		if (bufsize > 0) {
			$init($StandardSocketOptions);
			$nc(this->chan)->setOption($StandardSocketOptions::SO_RCVBUF, $($Integer::valueOf(bufsize)));
			return true;
		}
	} catch ($IOException& x) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Failed to set receive buffer size to %d on %s"_s, $$new($ObjectArray, {
				$($of($Integer::valueOf(bufsize))),
				$of(this->chan)
			}));
		}
	}
	return false;
}

bool PlainHttpConnection::trySetSendBufferSize(int32_t bufsize) {
	$useLocalCurrentObjectStackCache();
	try {
		if (bufsize > 0) {
			$init($StandardSocketOptions);
			$nc(this->chan)->setOption($StandardSocketOptions::SO_SNDBUF, $($Integer::valueOf(bufsize)));
			return true;
		}
	} catch ($IOException& x) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Failed to set send buffer size to %d on %s"_s, $$new($ObjectArray, {
				$($of($Integer::valueOf(bufsize))),
				$of(this->chan)
			}));
		}
	}
	return false;
}

$HttpConnection$HttpPublisher* PlainHttpConnection::publisher() {
	return this->writePublisher;
}

$String* PlainHttpConnection::toString() {
	return $str({"PlainHttpConnection: "_s, $($HttpConnection::toString())});
}

void PlainHttpConnection::close() {
	$useLocalCurrentObjectStackCache();
	$synchronized(this) {
		if (this->closed) {
			return;
		}
		this->closed = true;
	}
	try {
		$Log::logTrace($$str({"Closing: "_s, $(toString())}), $$new($ObjectArray, 0));
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log($$str({"Closing channel: "_s, $($nc($(client()))->debugInterestOps(this->chan))}));
		}
		if (this->connectTimerEvent != nullptr) {
			$nc($(client()))->cancelTimer(this->connectTimerEvent);
		}
		$nc(this->chan)->close();
		$nc(this->tube)->signalClosed();
	} catch ($IOException& e) {
		$Log::logTrace($$str({"Closing resulted in "_s, e}), $$new($ObjectArray, 0));
	}
}

$ConnectionPool$CacheKey* PlainHttpConnection::cacheKey() {
	return $new($ConnectionPool$CacheKey, this->address$, nullptr);
}

bool PlainHttpConnection::connected() {
	$synchronized(this) {
		return this->connected$;
	}
}

bool PlainHttpConnection::isSecure() {
	return false;
}

bool PlainHttpConnection::isProxied() {
	return false;
}

$InetSocketAddress* PlainHttpConnection::proxy() {
	return nullptr;
}

$CompletableFuture* PlainHttpConnection::lambda$connectAsync$1($Exchange* exchange, $PlainHttpConnection$ConnectState* r, $Throwable* t) {
	return checkRetryConnect(r, t, exchange);
}

$Boolean* PlainHttpConnection::lambda$connectAsync$0() {
	return $Boolean::valueOf($nc(this->chan)->connect($($Utils::resolveAddress(this->address$))));
}

void clinit$PlainHttpConnection($Class* class$) {
	PlainHttpConnection::$assertionsDisabled = !PlainHttpConnection::class$->desiredAssertionStatus();
}

PlainHttpConnection::PlainHttpConnection() {
}

$Class* PlainHttpConnection::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(PlainHttpConnection$$Lambda$lambda$connectAsync$0::classInfo$.name)) {
			return PlainHttpConnection$$Lambda$lambda$connectAsync$0::load$(name, initialize);
		}
		if (name->equals(PlainHttpConnection$$Lambda$lambda$connectAsync$1$1::classInfo$.name)) {
			return PlainHttpConnection$$Lambda$lambda$connectAsync$1$1::load$(name, initialize);
		}
		if (name->equals(PlainHttpConnection$$Lambda$getBuffer$2::classInfo$.name)) {
			return PlainHttpConnection$$Lambda$getBuffer$2::load$(name, initialize);
		}
	}
	$loadClass(PlainHttpConnection, name, initialize, &_PlainHttpConnection_ClassInfo_, clinit$PlainHttpConnection, allocate$PlainHttpConnection);
	return class$;
}

$Class* PlainHttpConnection::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk