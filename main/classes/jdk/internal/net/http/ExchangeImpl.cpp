#include <jdk/internal/net/http/ExchangeImpl.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpClient.h>
#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/net/http/HttpResponse.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/AbstractAsyncSSLConnection.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jdk/internal/net/http/Http2ClientImpl.h>
#include <jdk/internal/net/http/Http2Connection$ALPNException.h>
#include <jdk/internal/net/http/Http2Connection.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/Stream.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef DEBUG
#undef HTTP_1_1

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $HttpClient = ::java::net::http::HttpClient;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpResponse = ::java::net::http::HttpResponse;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Executor = ::java::util::concurrent::Executor;
using $BiFunction = ::java::util::function::BiFunction;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;
using $AbstractAsyncSSLConnection = ::jdk::internal::net::http::AbstractAsyncSSLConnection;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;
using $Http2ClientImpl = ::jdk::internal::net::http::Http2ClientImpl;
using $Http2Connection = ::jdk::internal::net::http::Http2Connection;
using $Http2Connection$ALPNException = ::jdk::internal::net::http::Http2Connection$ALPNException;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $Stream = ::jdk::internal::net::http::Stream;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class ExchangeImpl$$Lambda$toString : public $Supplier {
	$class(ExchangeImpl$$Lambda$toString, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ExchangeImpl$$Lambda$toString>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ExchangeImpl$$Lambda$toString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ExchangeImpl$$Lambda$toString, inst$)},
	{}
};
$MethodInfo ExchangeImpl$$Lambda$toString::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(ExchangeImpl$$Lambda$toString::*)($String*)>(&ExchangeImpl$$Lambda$toString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ExchangeImpl$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ExchangeImpl$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* ExchangeImpl$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(ExchangeImpl$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ExchangeImpl$$Lambda$toString::class$ = nullptr;

class ExchangeImpl$$Lambda$lambda$get$0$1 : public $BiFunction {
	$class(ExchangeImpl$$Lambda$lambda$get$0$1, $NO_CLASS_INIT, $BiFunction)
public:
	void init$($Exchange* exchange, $HttpConnection* connection) {
		$set(this, exchange, exchange);
		$set(this, connection, connection);
	}
	virtual $Object* apply(Object$* h2c, Object$* t) override {
		 return $of(ExchangeImpl::lambda$get$0(exchange, connection, $cast($Http2Connection, h2c), $cast($Throwable, t)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ExchangeImpl$$Lambda$lambda$get$0$1>());
	}
	$Exchange* exchange = nullptr;
	$HttpConnection* connection = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ExchangeImpl$$Lambda$lambda$get$0$1::fieldInfos[3] = {
	{"exchange", "Ljdk/internal/net/http/Exchange;", nullptr, $PUBLIC, $field(ExchangeImpl$$Lambda$lambda$get$0$1, exchange)},
	{"connection", "Ljdk/internal/net/http/HttpConnection;", nullptr, $PUBLIC, $field(ExchangeImpl$$Lambda$lambda$get$0$1, connection)},
	{}
};
$MethodInfo ExchangeImpl$$Lambda$lambda$get$0$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;Ljdk/internal/net/http/HttpConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(ExchangeImpl$$Lambda$lambda$get$0$1::*)($Exchange*,$HttpConnection*)>(&ExchangeImpl$$Lambda$lambda$get$0$1::init$))},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ExchangeImpl$$Lambda$lambda$get$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ExchangeImpl$$Lambda$lambda$get$0$1",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* ExchangeImpl$$Lambda$lambda$get$0$1::load$($String* name, bool initialize) {
	$loadClass(ExchangeImpl$$Lambda$lambda$get$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ExchangeImpl$$Lambda$lambda$get$0$1::class$ = nullptr;

class ExchangeImpl$$Lambda$lambda$get$1$2 : public $Function {
	$class(ExchangeImpl$$Lambda$lambda$get$1$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* x) override {
		 return $of(ExchangeImpl::lambda$get$1($cast($CompletableFuture, x)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ExchangeImpl$$Lambda$lambda$get$1$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ExchangeImpl$$Lambda$lambda$get$1$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ExchangeImpl$$Lambda$lambda$get$1$2::*)()>(&ExchangeImpl$$Lambda$lambda$get$1$2::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ExchangeImpl$$Lambda$lambda$get$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ExchangeImpl$$Lambda$lambda$get$1$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ExchangeImpl$$Lambda$lambda$get$1$2::load$($String* name, bool initialize) {
	$loadClass(ExchangeImpl$$Lambda$lambda$get$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ExchangeImpl$$Lambda$lambda$get$1$2::class$ = nullptr;

class ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3 : public $Function {
	$class(ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3, $NO_CLASS_INIT, $Function)
public:
	void init$($Exchange* exchange) {
		$set(this, exchange, exchange);
	}
	virtual $Object* apply(Object$* e) override {
		 return $of(ExchangeImpl::lambda$createExchangeImpl$2(exchange, $cast($Http1Exchange, e)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3>());
	}
	$Exchange* exchange = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3::fieldInfos[2] = {
	{"exchange", "Ljdk/internal/net/http/Exchange;", nullptr, $PUBLIC, $field(ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3, exchange)},
	{}
};
$MethodInfo ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3::*)($Exchange*)>(&ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3::load$($String* name, bool initialize) {
	$loadClass(ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3::class$ = nullptr;

$FieldInfo _ExchangeImpl_FieldInfo_[] = {
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ExchangeImpl, debug)},
	{"exchange", "Ljdk/internal/net/http/Exchange;", "Ljdk/internal/net/http/Exchange<TT;>;", $FINAL, $field(ExchangeImpl, exchange)},
	{}
};

$MethodInfo _ExchangeImpl_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;)V", "(Ljdk/internal/net/http/Exchange<TT;>;)V", 0, $method(static_cast<void(ExchangeImpl::*)($Exchange*)>(&ExchangeImpl::init$))},
	{"cancel", "()V", nullptr, $ABSTRACT},
	{"cancel", "(Ljava/io/IOException;)V", nullptr, $ABSTRACT},
	{"client", "()Ljava/net/http/HttpClient;", nullptr, 0},
	{"completed", "()V", nullptr, $ABSTRACT},
	{"connection", "()Ljdk/internal/net/http/HttpConnection;", nullptr, $ABSTRACT},
	{"createExchangeImpl", "(Ljdk/internal/net/http/Http2Connection;Ljava/lang/Throwable;Ljdk/internal/net/http/Exchange;Ljdk/internal/net/http/HttpConnection;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljdk/internal/net/http/Http2Connection;Ljava/lang/Throwable;Ljdk/internal/net/http/Exchange<TU;>;Ljdk/internal/net/http/HttpConnection;)Ljava/util/concurrent/CompletableFuture<+Ljdk/internal/net/http/ExchangeImpl<TU;>;>;", $PRIVATE | $STATIC, $method(static_cast<$CompletableFuture*(*)($Http2Connection*,$Throwable*,$Exchange*,$HttpConnection*)>(&ExchangeImpl::createExchangeImpl))},
	{"createHttp1Exchange", "(Ljdk/internal/net/http/Exchange;Ljdk/internal/net/http/HttpConnection;)Ljava/util/concurrent/CompletableFuture;", "<T:Ljava/lang/Object;>(Ljdk/internal/net/http/Exchange<TT;>;Ljdk/internal/net/http/HttpConnection;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Http1Exchange<TT;>;>;", $PRIVATE | $STATIC, $method(static_cast<$CompletableFuture*(*)($Exchange*,$HttpConnection*)>(&ExchangeImpl::createHttp1Exchange))},
	{"get", "(Ljdk/internal/net/http/Exchange;Ljdk/internal/net/http/HttpConnection;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljdk/internal/net/http/Exchange<TU;>;Ljdk/internal/net/http/HttpConnection;)Ljava/util/concurrent/CompletableFuture<+Ljdk/internal/net/http/ExchangeImpl<TU;>;>;", $STATIC, $method(static_cast<$CompletableFuture*(*)($Exchange*,$HttpConnection*)>(&ExchangeImpl::get))},
	{"getCancelCause", "()Ljava/lang/Throwable;", nullptr, $ABSTRACT},
	{"getExchange", "()Ljdk/internal/net/http/Exchange;", "()Ljdk/internal/net/http/Exchange<TT;>;", $FINAL, $method(static_cast<$Exchange*(ExchangeImpl::*)()>(&ExchangeImpl::getExchange))},
	{"getResponseAsync", "(Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", $ABSTRACT},
	{"ignoreBody", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $ABSTRACT},
	{"isCanceled", "()Z", nullptr, $ABSTRACT},
	{"lambda$createExchangeImpl$2", "(Ljdk/internal/net/http/Exchange;Ljdk/internal/net/http/Http1Exchange;)Ljdk/internal/net/http/Http1Exchange;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Http1Exchange*(*)($Exchange*,$Http1Exchange*)>(&ExchangeImpl::lambda$createExchangeImpl$2))},
	{"lambda$get$0", "(Ljdk/internal/net/http/Exchange;Ljdk/internal/net/http/HttpConnection;Ljdk/internal/net/http/Http2Connection;Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$CompletableFuture*(*)($Exchange*,$HttpConnection*,$Http2Connection*,$Throwable*)>(&ExchangeImpl::lambda$get$0))},
	{"lambda$get$1", "(Ljava/util/concurrent/CompletableFuture;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$CompletionStage*(*)($CompletableFuture*)>(&ExchangeImpl::lambda$get$1))},
	{"nullBody", "(Ljava/net/http/HttpResponse;Ljava/lang/Throwable;)V", "(Ljava/net/http/HttpResponse<TT;>;Ljava/lang/Throwable;)V", 0},
	{"readBodyAsync", "(Ljava/net/http/HttpResponse$BodyHandler;ZLjava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/net/http/HttpResponse$BodyHandler<TT;>;ZLjava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TT;>;", $ABSTRACT},
	{"released", "()V", nullptr, $ABSTRACT},
	{"sendBodyAsync", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/ExchangeImpl<TT;>;>;", $ABSTRACT},
	{"sendHeadersAsync", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/ExchangeImpl<TT;>;>;", $ABSTRACT},
	{"upgraded", "()V", nullptr, 0},
	{}
};

$ClassInfo _ExchangeImpl_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.ExchangeImpl",
	"java.lang.Object",
	nullptr,
	_ExchangeImpl_FieldInfo_,
	_ExchangeImpl_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;"
};

$Object* allocate$ExchangeImpl($Class* clazz) {
	return $of($alloc(ExchangeImpl));
}

$Logger* ExchangeImpl::debug = nullptr;

void ExchangeImpl::init$($Exchange* e) {
	$set(this, exchange, e);
}

$Exchange* ExchangeImpl::getExchange() {
	return this->exchange;
}

$HttpClient* ExchangeImpl::client() {
	return $nc(this->exchange)->client();
}

$CompletableFuture* ExchangeImpl::get($Exchange* exchange, $HttpConnection* connection) {
	$init(ExchangeImpl);
	$useLocalCurrentObjectStackCache();
	$init($HttpClient$Version);
	if ($nc(exchange)->version() == $HttpClient$Version::HTTP_1_1) {
		if ($nc(ExchangeImpl::debug)->on()) {
			$nc(ExchangeImpl::debug)->log("get: HTTP/1.1: new Http1Exchange"_s);
		}
		return createHttp1Exchange(exchange, connection);
	} else {
		$var($Http2ClientImpl, c2, $nc($(exchange->client()))->client2());
		$var($HttpRequestImpl, request, exchange->request());
		$var($CompletableFuture, c2f, $nc(c2)->getConnectionFor(request, exchange));
		if ($nc(ExchangeImpl::debug)->on()) {
			$nc(ExchangeImpl::debug)->log("get: Trying to get HTTP/2 connection"_s);
		}
		$var($CompletableFuture, fxi, $cast($CompletableFuture, $nc(c2f)->handle(static_cast<$BiFunction*>($$new(ExchangeImpl$$Lambda$lambda$get$0$1, exchange, connection)))));
		return $cast($CompletableFuture, $nc(fxi)->thenCompose(static_cast<$Function*>($$new(ExchangeImpl$$Lambda$lambda$get$1$2))));
	}
}

$CompletableFuture* ExchangeImpl::createExchangeImpl($Http2Connection* c, $Throwable* t$renamed, $Exchange* exchange, $HttpConnection* connection) {
	$init(ExchangeImpl);
	$useLocalCurrentObjectStackCache();
	$var($Throwable, t, t$renamed);
	if ($nc(ExchangeImpl::debug)->on()) {
		$nc(ExchangeImpl::debug)->log("handling HTTP/2 connection creation result"_s);
	}
	bool secure = $nc($($nc(exchange)->request()))->secure();
	if (t != nullptr) {
		if ($nc(ExchangeImpl::debug)->on()) {
			$nc(ExchangeImpl::debug)->log("handling HTTP/2 connection creation failed: %s"_s, $$new($ObjectArray, {$of(t)}));
		}
		$assign(t, $Utils::getCompletionCause(t));
		if ($instanceOf($Http2Connection$ALPNException, t)) {
			$var($Http2Connection$ALPNException, ee, $cast($Http2Connection$ALPNException, t));
			$var($AbstractAsyncSSLConnection, as, $nc(ee)->getConnection());
			if ($nc(ExchangeImpl::debug)->on()) {
				$nc(ExchangeImpl::debug)->log("downgrading to HTTP/1.1 with: %s"_s, $$new($ObjectArray, {$of(as)}));
			}
			$var($CompletableFuture, ex, createHttp1Exchange(exchange, as));
			return ex;
		} else {
			if ($nc(ExchangeImpl::debug)->on()) {
				$nc(ExchangeImpl::debug)->log("HTTP/2 connection creation failed with unexpected exception: %s"_s, $$new($ObjectArray, {$of(t)}));
			}
			return $MinimalFuture::failedFuture(t);
		}
	}
	if (secure && c == nullptr) {
		if ($nc(ExchangeImpl::debug)->on()) {
			$nc(ExchangeImpl::debug)->log("downgrading to HTTP/1.1 "_s);
		}
		$var($CompletableFuture, ex, createHttp1Exchange(exchange, nullptr));
		return ex;
	}
	if (c == nullptr) {
		if ($nc(ExchangeImpl::debug)->on()) {
			$nc(ExchangeImpl::debug)->log("new Http1Exchange, try to upgrade"_s);
		}
		return $cast($CompletableFuture, $nc($(createHttp1Exchange(exchange, connection)))->thenApply(static_cast<$Function*>($$new(ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3, exchange))));
	} else {
		if ($nc(ExchangeImpl::debug)->on()) {
			$nc(ExchangeImpl::debug)->log("creating HTTP/2 streams"_s);
		}
		$var($Stream, s, $nc(c)->createStream(exchange));
		$var($CompletableFuture, ex, $MinimalFuture::completedFuture(s));
		return ex;
	}
}

$CompletableFuture* ExchangeImpl::createHttp1Exchange($Exchange* ex, $HttpConnection* as) {
	$init(ExchangeImpl);
	try {
		return $MinimalFuture::completedFuture($$new($Http1Exchange, ex, as));
	} catch ($Throwable& e) {
		return $MinimalFuture::failedFuture(e);
	}
	$shouldNotReachHere();
}

void ExchangeImpl::nullBody($HttpResponse* resp, $Throwable* t) {
}

void ExchangeImpl::upgraded() {
}

$Http1Exchange* ExchangeImpl::lambda$createExchangeImpl$2($Exchange* exchange, $Http1Exchange* e) {
	$init(ExchangeImpl);
	$nc(exchange)->h2Upgrade();
	return e;
}

$CompletionStage* ExchangeImpl::lambda$get$1($CompletableFuture* x) {
	$init(ExchangeImpl);
	return x;
}

$CompletableFuture* ExchangeImpl::lambda$get$0($Exchange* exchange, $HttpConnection* connection, $Http2Connection* h2c, $Throwable* t) {
	$init(ExchangeImpl);
	return createExchangeImpl(h2c, t, exchange, connection);
}

void clinit$ExchangeImpl($Class* class$) {
	$init($Utils);
	$assignStatic(ExchangeImpl::debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(ExchangeImpl$$Lambda$toString, static_cast<$String*>("ExchangeImpl"_s))), $Utils::DEBUG));
}

ExchangeImpl::ExchangeImpl() {
}

$Class* ExchangeImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ExchangeImpl$$Lambda$toString::classInfo$.name)) {
			return ExchangeImpl$$Lambda$toString::load$(name, initialize);
		}
		if (name->equals(ExchangeImpl$$Lambda$lambda$get$0$1::classInfo$.name)) {
			return ExchangeImpl$$Lambda$lambda$get$0$1::load$(name, initialize);
		}
		if (name->equals(ExchangeImpl$$Lambda$lambda$get$1$2::classInfo$.name)) {
			return ExchangeImpl$$Lambda$lambda$get$1$2::load$(name, initialize);
		}
		if (name->equals(ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3::classInfo$.name)) {
			return ExchangeImpl$$Lambda$lambda$createExchangeImpl$2$3::load$(name, initialize);
		}
	}
	$loadClass(ExchangeImpl, name, initialize, &_ExchangeImpl_ClassInfo_, clinit$ExchangeImpl, allocate$ExchangeImpl);
	return class$;
}

$Class* ExchangeImpl::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk