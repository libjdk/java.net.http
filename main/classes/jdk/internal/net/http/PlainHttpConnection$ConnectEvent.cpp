#include <jdk/internal/net/http/PlainHttpConnection$ConnectEvent.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/SocketAddress.h>
#include <java/nio/channels/SelectableChannel.h>
#include <java/nio/channels/SelectionKey.h>
#include <java/nio/channels/SocketChannel.h>
#include <java/nio/channels/spi/AbstractSelectableChannel.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/AsyncEvent.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/HttpClientImpl$DelegatingExecutor.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/PlainHttpConnection$ConnectState.h>
#include <jdk/internal/net/http/PlainHttpConnection.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef OP_CONNECT
#undef RETRY
#undef SUCCESS

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $SocketAddress = ::java::net::SocketAddress;
using $SelectableChannel = ::java::nio::channels::SelectableChannel;
using $SelectionKey = ::java::nio::channels::SelectionKey;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $AbstractSelectableChannel = ::java::nio::channels::spi::AbstractSelectableChannel;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $Executor = ::java::util::concurrent::Executor;
using $Supplier = ::java::util::function::Supplier;
using $AsyncEvent = ::jdk::internal::net::http::AsyncEvent;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpClientImpl$DelegatingExecutor = ::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;
using $PlainHttpConnection = ::jdk::internal::net::http::PlainHttpConnection;
using $PlainHttpConnection$ConnectState = ::jdk::internal::net::http::PlainHttpConnection$ConnectState;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$0 : public $Supplier {
	$class(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$0, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(PlainHttpConnection$ConnectEvent::lambda$handle$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$0::*)()>(&PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$0::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$0",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$0::load$($String* name, bool initialize) {
	$loadClass(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$0::class$ = nullptr;

class PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$1$1 : public $Supplier {
	$class(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$1$1, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(PlainHttpConnection$ConnectEvent::lambda$handle$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$1$1::*)()>(&PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$1$1::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$1$1",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$1$1::load$($String* name, bool initialize) {
	$loadClass(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$1$1::class$ = nullptr;

class PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2 : public $Runnable {
	$class(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2, $NO_CLASS_INIT, $Runnable)
public:
	void init$(PlainHttpConnection$ConnectEvent* inst, $Throwable* t) {
		$set(this, inst$, inst);
		$set(this, t, t);
	}
	virtual void run() override {
		$nc(inst$)->lambda$handle$2(t);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2>());
	}
	PlainHttpConnection$ConnectEvent* inst$ = nullptr;
	$Throwable* t = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2, inst$)},
	{"t", "Ljava/lang/Throwable;", nullptr, $PUBLIC, $field(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2, t)},
	{}
};
$MethodInfo PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/PlainHttpConnection$ConnectEvent;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(static_cast<void(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2::*)(PlainHttpConnection$ConnectEvent*,$Throwable*)>(&PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2::load$($String* name, bool initialize) {
	$loadClass(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2::class$ = nullptr;

class PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3 : public $Runnable {
	$class(PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3, $NO_CLASS_INIT, $Runnable)
public:
	void init$(PlainHttpConnection$ConnectEvent* inst, $IOException* ioe) {
		$set(this, inst$, inst);
		$set(this, ioe, ioe);
	}
	virtual void run() override {
		$nc(inst$)->lambda$abort$3(ioe);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3>());
	}
	PlainHttpConnection$ConnectEvent* inst$ = nullptr;
	$IOException* ioe = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3, inst$)},
	{"ioe", "Ljava/io/IOException;", nullptr, $PUBLIC, $field(PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3, ioe)},
	{}
};
$MethodInfo PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/PlainHttpConnection$ConnectEvent;Ljava/io/IOException;)V", nullptr, $PUBLIC, $method(static_cast<void(PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3::*)(PlainHttpConnection$ConnectEvent*,$IOException*)>(&PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3::load$($String* name, bool initialize) {
	$loadClass(PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3::class$ = nullptr;

$FieldInfo _PlainHttpConnection$ConnectEvent_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/PlainHttpConnection;", nullptr, $FINAL | $SYNTHETIC, $field(PlainHttpConnection$ConnectEvent, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(PlainHttpConnection$ConnectEvent, $assertionsDisabled)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/PlainHttpConnection$ConnectState;>;", $PRIVATE | $FINAL, $field(PlainHttpConnection$ConnectEvent, cf)},
	{"exchange", "Ljdk/internal/net/http/Exchange;", "Ljdk/internal/net/http/Exchange<*>;", $PRIVATE | $FINAL, $field(PlainHttpConnection$ConnectEvent, exchange)},
	{}
};

$MethodInfo _PlainHttpConnection$ConnectEvent_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/PlainHttpConnection;Ljava/util/concurrent/CompletableFuture;Ljdk/internal/net/http/Exchange;)V", "(Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/PlainHttpConnection$ConnectState;>;Ljdk/internal/net/http/Exchange<*>;)V", 0, $method(static_cast<void(PlainHttpConnection$ConnectEvent::*)($PlainHttpConnection*,$CompletableFuture*,$Exchange*)>(&PlainHttpConnection$ConnectEvent::init$))},
	{"abort", "(Ljava/io/IOException;)V", nullptr, $PUBLIC},
	{"channel", "()Ljava/nio/channels/SelectableChannel;", nullptr, $PUBLIC},
	{"handle", "()V", nullptr, $PUBLIC},
	{"interestOps", "()I", nullptr, $PUBLIC},
	{"lambda$abort$3", "(Ljava/io/IOException;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(PlainHttpConnection$ConnectEvent::*)($IOException*)>(&PlainHttpConnection$ConnectEvent::lambda$abort$3))},
	{"lambda$handle$0", "()Ljdk/internal/net/http/PlainHttpConnection$ConnectState;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$PlainHttpConnection$ConnectState*(*)()>(&PlainHttpConnection$ConnectEvent::lambda$handle$0))},
	{"lambda$handle$1", "()Ljdk/internal/net/http/PlainHttpConnection$ConnectState;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$PlainHttpConnection$ConnectState*(*)()>(&PlainHttpConnection$ConnectEvent::lambda$handle$1))},
	{"lambda$handle$2", "(Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(PlainHttpConnection$ConnectEvent::*)($Throwable*)>(&PlainHttpConnection$ConnectEvent::lambda$handle$2))},
	{}
};

$InnerClassInfo _PlainHttpConnection$ConnectEvent_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.PlainHttpConnection$ConnectEvent", "jdk.internal.net.http.PlainHttpConnection", "ConnectEvent", $FINAL},
	{}
};

$ClassInfo _PlainHttpConnection$ConnectEvent_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.PlainHttpConnection$ConnectEvent",
	"jdk.internal.net.http.AsyncEvent",
	nullptr,
	_PlainHttpConnection$ConnectEvent_FieldInfo_,
	_PlainHttpConnection$ConnectEvent_MethodInfo_,
	nullptr,
	nullptr,
	_PlainHttpConnection$ConnectEvent_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.PlainHttpConnection"
};

$Object* allocate$PlainHttpConnection$ConnectEvent($Class* clazz) {
	return $of($alloc(PlainHttpConnection$ConnectEvent));
}

bool PlainHttpConnection$ConnectEvent::$assertionsDisabled = false;

void PlainHttpConnection$ConnectEvent::init$($PlainHttpConnection* this$0, $CompletableFuture* cf, $Exchange* exchange) {
	$set(this, this$0, this$0);
	$AsyncEvent::init$();
	$set(this, cf, cf);
	$set(this, exchange, exchange);
}

$SelectableChannel* PlainHttpConnection$ConnectEvent::channel() {
	return this->this$0->chan;
}

int32_t PlainHttpConnection$ConnectEvent::interestOps() {
	return $SelectionKey::OP_CONNECT;
}

void PlainHttpConnection$ConnectEvent::handle() {
	$useLocalCurrentObjectStackCache();
	try {
		if (!PlainHttpConnection$ConnectEvent::$assertionsDisabled && ! !this->this$0->connected$) {
			$throwNew($AssertionError, $of("Already connected"_s));
		}
		if (!PlainHttpConnection$ConnectEvent::$assertionsDisabled && ! !$nc(this->this$0->chan)->isBlocking()) {
			$throwNew($AssertionError, $of("Unexpected blocking channel"_s));
		}
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("ConnectEvent: finishing connect"_s);
		}
		bool finished = $nc(this->this$0->chan)->finishConnect();
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("ConnectEvent: connect finished: %s, cancelled: %s, Local addr: %s"_s, $$new($ObjectArray, {
				$($of($Boolean::valueOf(finished))),
				$($of($Boolean::valueOf($nc($nc(this->exchange)->multi)->requestCancelled()))),
				$($of($nc(this->this$0->chan)->getLocalAddress()))
			}));
		}
		if (!PlainHttpConnection$ConnectEvent::$assertionsDisabled && !(finished || $nc($nc(this->exchange)->multi)->requestCancelled())) {
			$throwNew($AssertionError, $of("Expected channel to be connected"_s));
		}
		$var($Supplier, var$0, static_cast<$Supplier*>($new(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$0)));
		$nc(this->cf)->completeAsync(var$0, $($nc($(this->this$0->client()))->theExecutor()));
	} catch ($Throwable& e) {
		if (this->this$0->canRetryConnect(e)) {
			++this->this$0->unsuccessfulAttempts;
			$var($Supplier, var$1, static_cast<$Supplier*>($new(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$1$1)));
			$nc(this->cf)->completeAsync(var$1, $($nc($(this->this$0->client()))->theExecutor()));
			return;
		}
		$var($Throwable, t, $Utils::toConnectException(e));
		$nc($($nc($(this->this$0->client()))->theExecutor()))->execute(static_cast<$Runnable*>($$new(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2, this, t)));
		this->this$0->close();
	}
}

void PlainHttpConnection$ConnectEvent::abort($IOException* ioe) {
	$useLocalCurrentObjectStackCache();
	$nc($($nc($(this->this$0->client()))->theExecutor()))->execute(static_cast<$Runnable*>($$new(PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3, this, ioe)));
	this->this$0->close();
}

void PlainHttpConnection$ConnectEvent::lambda$abort$3($IOException* ioe) {
	$nc(this->cf)->completeExceptionally(ioe);
}

void PlainHttpConnection$ConnectEvent::lambda$handle$2($Throwable* t) {
	$nc(this->cf)->completeExceptionally(t);
}

$PlainHttpConnection$ConnectState* PlainHttpConnection$ConnectEvent::lambda$handle$1() {
	$init(PlainHttpConnection$ConnectEvent);
	$init($PlainHttpConnection$ConnectState);
	return $PlainHttpConnection$ConnectState::RETRY;
}

$PlainHttpConnection$ConnectState* PlainHttpConnection$ConnectEvent::lambda$handle$0() {
	$init(PlainHttpConnection$ConnectEvent);
	$init($PlainHttpConnection$ConnectState);
	return $PlainHttpConnection$ConnectState::SUCCESS;
}

void clinit$PlainHttpConnection$ConnectEvent($Class* class$) {
	$load($PlainHttpConnection);
	PlainHttpConnection$ConnectEvent::$assertionsDisabled = !$PlainHttpConnection::class$->desiredAssertionStatus();
}

PlainHttpConnection$ConnectEvent::PlainHttpConnection$ConnectEvent() {
}

$Class* PlainHttpConnection$ConnectEvent::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$0::classInfo$.name)) {
			return PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$0::load$(name, initialize);
		}
		if (name->equals(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$1$1::classInfo$.name)) {
			return PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$1$1::load$(name, initialize);
		}
		if (name->equals(PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2::classInfo$.name)) {
			return PlainHttpConnection$ConnectEvent$$Lambda$lambda$handle$2$2::load$(name, initialize);
		}
		if (name->equals(PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3::classInfo$.name)) {
			return PlainHttpConnection$ConnectEvent$$Lambda$lambda$abort$3$3::load$(name, initialize);
		}
	}
	$loadClass(PlainHttpConnection$ConnectEvent, name, initialize, &_PlainHttpConnection$ConnectEvent_ClassInfo_, clinit$PlainHttpConnection$ConnectEvent, allocate$PlainHttpConnection$ConnectEvent);
	return class$;
}

$Class* PlainHttpConnection$ConnectEvent::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk