#include <jdk/internal/net/http/PlainTunnelingConnection.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/http/HttpRequest.h>
#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/net/http/HttpResponse$BodyHandlers.h>
#include <java/net/http/HttpResponse$PushPromiseHandler.h>
#include <java/net/http/HttpTimeoutException.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/SocketChannel.h>
#include <java/security/AccessControlContext.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionException.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Function.h>
#include <jdk/internal/net/http/ConnectionPool$CacheKey.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/ExchangeImpl.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpConnection$HttpPublisher.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/PlainHttpConnection.h>
#include <jdk/internal/net/http/ProxyAuthenticationRequired.h>
#include <jdk/internal/net/http/Response.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/Utils$ProxyHeaders.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $HttpResponse$BodyHandlers = ::java::net::http::HttpResponse$BodyHandlers;
using $HttpResponse$PushPromiseHandler = ::java::net::http::HttpResponse$PushPromiseHandler;
using $HttpTimeoutException = ::java::net::http::HttpTimeoutException;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $AccessControlContext = ::java::security::AccessControlContext;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionException = ::java::util::concurrent::CompletionException;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $BiFunction = ::java::util::function::BiFunction;
using $Function = ::java::util::function::Function;
using $ConnectionPool$CacheKey = ::jdk::internal::net::http::ConnectionPool$CacheKey;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $ExchangeImpl = ::jdk::internal::net::http::ExchangeImpl;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpConnection$HttpPublisher = ::jdk::internal::net::http::HttpConnection$HttpPublisher;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;
using $PlainHttpConnection = ::jdk::internal::net::http::PlainHttpConnection;
using $ProxyAuthenticationRequired = ::jdk::internal::net::http::ProxyAuthenticationRequired;
using $Response = ::jdk::internal::net::http::Response;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $Utils$ProxyHeaders = ::jdk::internal::net::http::common::Utils$ProxyHeaders;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class PlainTunnelingConnection$$Lambda$lambda$connectAsync$0 : public $Function {
	$class(PlainTunnelingConnection$$Lambda$lambda$connectAsync$0, $NO_CLASS_INIT, $Function)
public:
	void init$(PlainTunnelingConnection* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* unused) override {
		 return $of($nc(inst$)->lambda$connectAsync$0($cast($Void, unused)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PlainTunnelingConnection$$Lambda$lambda$connectAsync$0>());
	}
	PlainTunnelingConnection* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PlainTunnelingConnection$$Lambda$lambda$connectAsync$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(PlainTunnelingConnection$$Lambda$lambda$connectAsync$0, inst$)},
	{}
};
$MethodInfo PlainTunnelingConnection$$Lambda$lambda$connectAsync$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/PlainTunnelingConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(PlainTunnelingConnection$$Lambda$lambda$connectAsync$0::*)(PlainTunnelingConnection*)>(&PlainTunnelingConnection$$Lambda$lambda$connectAsync$0::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo PlainTunnelingConnection$$Lambda$lambda$connectAsync$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PlainTunnelingConnection$$Lambda$lambda$connectAsync$0",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* PlainTunnelingConnection$$Lambda$lambda$connectAsync$0::load$($String* name, bool initialize) {
	$loadClass(PlainTunnelingConnection$$Lambda$lambda$connectAsync$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PlainTunnelingConnection$$Lambda$lambda$connectAsync$0::class$ = nullptr;

class PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1 : public $Function {
	$class(PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1, $NO_CLASS_INIT, $Function)
public:
	void init$(PlainTunnelingConnection* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* v) override {
		 return $of($nc(inst$)->lambda$connectAsync$4($cast($Void, v)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1>());
	}
	PlainTunnelingConnection* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1, inst$)},
	{}
};
$MethodInfo PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/PlainTunnelingConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1::*)(PlainTunnelingConnection*)>(&PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1::load$($String* name, bool initialize) {
	$loadClass(PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1::class$ = nullptr;

class PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2 : public $Function {
	$class(PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2, $NO_CLASS_INIT, $Function)
public:
	void init$(PlainTunnelingConnection* inst, $Exchange* connectExchange) {
		$set(this, inst$, inst);
		$set(this, connectExchange, connectExchange);
	}
	virtual $Object* apply(Object$* resp) override {
		 return $of($nc(inst$)->lambda$connectAsync$2(connectExchange, $cast($Response, resp)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2>());
	}
	PlainTunnelingConnection* inst$ = nullptr;
	$Exchange* connectExchange = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2, inst$)},
	{"connectExchange", "Ljdk/internal/net/http/Exchange;", nullptr, $PUBLIC, $field(PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2, connectExchange)},
	{}
};
$MethodInfo PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/PlainTunnelingConnection;Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2::*)(PlainTunnelingConnection*,$Exchange*)>(&PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2::load$($String* name, bool initialize) {
	$loadClass(PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2::class$ = nullptr;

class PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3 : public $BiFunction {
	$class(PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(PlainTunnelingConnection* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* result, Object$* ex) override {
		 return $of($nc(inst$)->lambda$connectAsync$3($cast($Void, result), $cast($Throwable, ex)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3>());
	}
	PlainTunnelingConnection* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3, inst$)},
	{}
};
$MethodInfo PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/PlainTunnelingConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3::*)(PlainTunnelingConnection*)>(&PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3::init$))},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3::load$($String* name, bool initialize) {
	$loadClass(PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3::class$ = nullptr;

class PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4 : public $BiFunction {
	$class(PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(PlainTunnelingConnection* inst, $Response* resp, $CompletableFuture* cf) {
		$set(this, inst$, inst);
		$set(this, resp, resp);
		$set(this, cf, cf);
	}
	virtual $Object* apply(Object$* r, Object$* t) override {
		 return $of($nc(inst$)->lambda$connectAsync$1(resp, cf, $cast($Void, r), $cast($Throwable, t)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4>());
	}
	PlainTunnelingConnection* inst$ = nullptr;
	$Response* resp = nullptr;
	$CompletableFuture* cf = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4, inst$)},
	{"resp", "Ljdk/internal/net/http/Response;", nullptr, $PUBLIC, $field(PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4, resp)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", nullptr, $PUBLIC, $field(PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4, cf)},
	{}
};
$MethodInfo PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/PlainTunnelingConnection;Ljdk/internal/net/http/Response;Ljava/util/concurrent/CompletableFuture;)V", nullptr, $PUBLIC, $method(static_cast<void(PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4::*)(PlainTunnelingConnection*,$Response*,$CompletableFuture*)>(&PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4::init$))},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4::load$($String* name, bool initialize) {
	$loadClass(PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4::class$ = nullptr;

$FieldInfo _PlainTunnelingConnection_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(PlainTunnelingConnection, $assertionsDisabled)},
	{"delegate", "Ljdk/internal/net/http/PlainHttpConnection;", nullptr, $FINAL, $field(PlainTunnelingConnection, delegate)},
	{"proxyHeaders", "Ljdk/internal/net/http/common/Utils$ProxyHeaders;", nullptr, $FINAL, $field(PlainTunnelingConnection, proxyHeaders)},
	{"proxyAddr", "Ljava/net/InetSocketAddress;", nullptr, $FINAL, $field(PlainTunnelingConnection, proxyAddr)},
	{"connected", "Z", nullptr, $PRIVATE | $VOLATILE, $field(PlainTunnelingConnection, connected$)},
	{}
};

$MethodInfo _PlainTunnelingConnection_MethodInfo_[] = {
	{"<init>", "(Ljava/net/InetSocketAddress;Ljava/net/InetSocketAddress;Ljdk/internal/net/http/HttpClientImpl;Ljdk/internal/net/http/common/Utils$ProxyHeaders;)V", nullptr, $PROTECTED, $method(static_cast<void(PlainTunnelingConnection::*)($InetSocketAddress*,$InetSocketAddress*,$HttpClientImpl*,$Utils$ProxyHeaders*)>(&PlainTunnelingConnection::init$))},
	{"cacheKey", "()Ljdk/internal/net/http/ConnectionPool$CacheKey;", nullptr, 0},
	{"channel", "()Ljava/nio/channels/SocketChannel;", nullptr, 0},
	{"close", "()V", nullptr, $PUBLIC},
	{"connectAsync", "(Ljdk/internal/net/http/Exchange;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/Exchange<*>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC},
	{"connected", "()Z", nullptr, 0},
	{"finishConnect", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC},
	{"getConnectionFlow", "()Ljdk/internal/net/http/common/FlowTube;", nullptr, 0},
	{"isProxied", "()Z", nullptr, 0},
	{"isSecure", "()Z", nullptr, 0},
	{"isTunnel", "()Z", nullptr, 0},
	{"lambda$connectAsync$0", "(Ljava/lang/Void;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(PlainTunnelingConnection::*)($Void*)>(&PlainTunnelingConnection::lambda$connectAsync$0))},
	{"lambda$connectAsync$1", "(Ljdk/internal/net/http/Response;Ljava/util/concurrent/CompletableFuture;Ljava/lang/Void;Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletableFuture*(PlainTunnelingConnection::*)($Response*,$CompletableFuture*,$Void*,$Throwable*)>(&PlainTunnelingConnection::lambda$connectAsync$1))},
	{"lambda$connectAsync$2", "(Ljdk/internal/net/http/Exchange;Ljdk/internal/net/http/Response;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(PlainTunnelingConnection::*)($Exchange*,$Response*)>(&PlainTunnelingConnection::lambda$connectAsync$2))},
	{"lambda$connectAsync$3", "(Ljava/lang/Void;Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletableFuture*(PlainTunnelingConnection::*)($Void*,$Throwable*)>(&PlainTunnelingConnection::lambda$connectAsync$3))},
	{"lambda$connectAsync$4", "(Ljava/lang/Void;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(PlainTunnelingConnection::*)($Void*)>(&PlainTunnelingConnection::lambda$connectAsync$4))},
	{"proxy", "()Ljava/net/InetSocketAddress;", nullptr, 0},
	{"publisher", "()Ljdk/internal/net/http/HttpConnection$HttpPublisher;", nullptr, 0},
	{}
};

$ClassInfo _PlainTunnelingConnection_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.PlainTunnelingConnection",
	"jdk.internal.net.http.HttpConnection",
	nullptr,
	_PlainTunnelingConnection_FieldInfo_,
	_PlainTunnelingConnection_MethodInfo_
};

$Object* allocate$PlainTunnelingConnection($Class* clazz) {
	return $of($alloc(PlainTunnelingConnection));
}

bool PlainTunnelingConnection::$assertionsDisabled = false;

void PlainTunnelingConnection::init$($InetSocketAddress* addr, $InetSocketAddress* proxy, $HttpClientImpl* client, $Utils$ProxyHeaders* proxyHeaders) {
	$HttpConnection::init$(addr, client);
	$set(this, proxyAddr, proxy);
	$set(this, proxyHeaders, proxyHeaders);
	$set(this, delegate, $new($PlainHttpConnection, proxy, client));
}

$CompletableFuture* PlainTunnelingConnection::connectAsync($Exchange* exchange) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Connecting plain connection"_s);
	}
	return $cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc($($nc(this->delegate)->connectAsync(exchange)))->thenCompose(static_cast<$Function*>($$new(PlainTunnelingConnection$$Lambda$lambda$connectAsync$0, this))))))->thenCompose(static_cast<$Function*>($$new(PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1, this))));
}

$CompletableFuture* PlainTunnelingConnection::finishConnect() {
	this->connected$ = true;
	return $MinimalFuture::completedFuture(nullptr);
}

bool PlainTunnelingConnection::isTunnel() {
	return true;
}

$HttpConnection$HttpPublisher* PlainTunnelingConnection::publisher() {
	return $nc(this->delegate)->publisher();
}

bool PlainTunnelingConnection::connected() {
	return this->connected$;
}

$SocketChannel* PlainTunnelingConnection::channel() {
	return $nc(this->delegate)->channel();
}

$FlowTube* PlainTunnelingConnection::getConnectionFlow() {
	return $nc(this->delegate)->getConnectionFlow();
}

$ConnectionPool$CacheKey* PlainTunnelingConnection::cacheKey() {
	return $new($ConnectionPool$CacheKey, nullptr, this->proxyAddr);
}

void PlainTunnelingConnection::close() {
	$nc(this->delegate)->close();
	this->connected$ = false;
}

bool PlainTunnelingConnection::isSecure() {
	return false;
}

bool PlainTunnelingConnection::isProxied() {
	return true;
}

$InetSocketAddress* PlainTunnelingConnection::proxy() {
	return this->proxyAddr;
}

$CompletionStage* PlainTunnelingConnection::lambda$connectAsync$4($Void* v) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("sending HTTP/1.1 CONNECT"_s);
	}
	$var($HttpClientImpl, client, this->client());
	if (!PlainTunnelingConnection::$assertionsDisabled && !(client != nullptr)) {
		$throwNew($AssertionError);
	}
	$var($HttpRequestImpl, req, $new($HttpRequestImpl, "CONNECT"_s, this->address$, this->proxyHeaders));
	$var($MultiExchange, mulEx, $new($MultiExchange, nullptr, req, client, $($HttpResponse$BodyHandlers::discarding()), nullptr, nullptr));
	$var($Exchange, connectExchange, mulEx->getExchange());
	return $nc($($cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc($($nc(connectExchange)->responseAsyncImpl(this->delegate)))->thenCompose(static_cast<$Function*>($$new(PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2, this, connectExchange))))))->handle(static_cast<$BiFunction*>($$new(PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3, this))))))->thenCompose($($Function::identity()));
}

$CompletableFuture* PlainTunnelingConnection::lambda$connectAsync$3($Void* result, $Throwable* ex) {
	$useLocalCurrentObjectStackCache();
	if (ex == nullptr) {
		return $MinimalFuture::completedFuture(result);
	} else {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("tunnel failed with \"%s\""_s, $$new($ObjectArray, {$($of($nc(ex)->toString()))}));
		}
		$var($Throwable, t, ex);
		if ($instanceOf($CompletionException, t)) {
			$assign(t, $nc(t)->getCause());
		}
		if ($instanceOf($HttpTimeoutException, t)) {
			$var($String, msg, "proxy tunneling CONNECT request timed out"_s);
			$assign(t, $new($HttpTimeoutException, msg));
			t->initCause(ex);
		}
		return $MinimalFuture::failedFuture(t);
	}
}

$CompletionStage* PlainTunnelingConnection::lambda$connectAsync$2($Exchange* connectExchange, $Response* resp) {
	$useLocalCurrentObjectStackCache();
	$var($CompletableFuture, cf, $new($MinimalFuture));
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("got response: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf($nc(resp)->statusCode())))}));
	}
	if ($nc(resp)->statusCode() == 407) {
		return $nc($($cast($CompletableFuture, $nc($($nc(connectExchange)->ignoreBody()))->handle(static_cast<$BiFunction*>($$new(PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4, this, resp, cf))))))->thenCompose($($Function::identity()));
	} else if (resp->statusCode() != 200) {
		$nc(this->delegate)->close();
		cf->completeExceptionally($$new($IOException, $$str({"Tunnel failed, got: "_s, $$str(resp->statusCode())})));
	} else {
		$var($ByteBuffer, b, $nc(($cast($Http1Exchange, $nc(connectExchange)->exchImpl)))->drainLeftOverBytes());
		int32_t remaining = $nc(b)->remaining();
		if (!PlainTunnelingConnection::$assertionsDisabled && !(remaining == 0)) {
			$throwNew($AssertionError, $of($$str({"Unexpected remaining: "_s, $$str(remaining)})));
		}
		cf->complete(nullptr);
	}
	return cf;
}

$CompletableFuture* PlainTunnelingConnection::lambda$connectAsync$1($Response* resp, $CompletableFuture* cf, $Void* r, $Throwable* t) {
	$nc(this->delegate)->close();
	$var($ProxyAuthenticationRequired, authenticationRequired, $new($ProxyAuthenticationRequired, resp));
	$nc(cf)->completeExceptionally(authenticationRequired);
	return cf;
}

$CompletionStage* PlainTunnelingConnection::lambda$connectAsync$0($Void* unused) {
	return $nc(this->delegate)->finishConnect();
}

void clinit$PlainTunnelingConnection($Class* class$) {
	PlainTunnelingConnection::$assertionsDisabled = !PlainTunnelingConnection::class$->desiredAssertionStatus();
}

PlainTunnelingConnection::PlainTunnelingConnection() {
}

$Class* PlainTunnelingConnection::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(PlainTunnelingConnection$$Lambda$lambda$connectAsync$0::classInfo$.name)) {
			return PlainTunnelingConnection$$Lambda$lambda$connectAsync$0::load$(name, initialize);
		}
		if (name->equals(PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1::classInfo$.name)) {
			return PlainTunnelingConnection$$Lambda$lambda$connectAsync$4$1::load$(name, initialize);
		}
		if (name->equals(PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2::classInfo$.name)) {
			return PlainTunnelingConnection$$Lambda$lambda$connectAsync$2$2::load$(name, initialize);
		}
		if (name->equals(PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3::classInfo$.name)) {
			return PlainTunnelingConnection$$Lambda$lambda$connectAsync$3$3::load$(name, initialize);
		}
		if (name->equals(PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4::classInfo$.name)) {
			return PlainTunnelingConnection$$Lambda$lambda$connectAsync$1$4::load$(name, initialize);
		}
	}
	$loadClass(PlainTunnelingConnection, name, initialize, &_PlainTunnelingConnection_ClassInfo_, clinit$PlainTunnelingConnection, allocate$PlainTunnelingConnection);
	return class$;
}

$Class* PlainTunnelingConnection::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk