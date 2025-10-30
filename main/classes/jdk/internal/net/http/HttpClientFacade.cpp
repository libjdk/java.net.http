#include <jdk/internal/net/http/HttpClientFacade.h>

#include <java/lang/ref/Reference.h>
#include <java/net/http/HttpClient$Redirect.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpClient.h>
#include <java/net/http/HttpRequest.h>
#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/net/http/HttpResponse$PushPromiseHandler.h>
#include <java/net/http/HttpResponse.h>
#include <java/net/http/WebSocket$Builder.h>
#include <java/util/Optional.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <javax/net/ssl/SSLContext.h>
#include <javax/net/ssl/SSLParameters.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/common/OperationTrackers$Tracker.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Reference = ::java::lang::ref::Reference;
using $HttpClient = ::java::net::http::HttpClient;
using $HttpClient$Redirect = ::java::net::http::HttpClient$Redirect;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpResponse = ::java::net::http::HttpResponse;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $HttpResponse$PushPromiseHandler = ::java::net::http::HttpResponse$PushPromiseHandler;
using $WebSocket$Builder = ::java::net::http::WebSocket$Builder;
using $Optional = ::java::util::Optional;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $SSLContext = ::javax::net::ssl::SSLContext;
using $SSLParameters = ::javax::net::ssl::SSLParameters;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $OperationTrackers$Trackable = ::jdk::internal::net::http::common::OperationTrackers$Trackable;
using $OperationTrackers$Tracker = ::jdk::internal::net::http::common::OperationTrackers$Tracker;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _HttpClientFacade_FieldInfo_[] = {
	{"impl", "Ljdk/internal/net/http/HttpClientImpl;", nullptr, $FINAL, $field(HttpClientFacade, impl)},
	{}
};

$MethodInfo _HttpClientFacade_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljdk/internal/net/http/HttpClientImpl;)V", nullptr, 0, $method(static_cast<void(HttpClientFacade::*)($HttpClientImpl*)>(&HttpClientFacade::init$))},
	{"authenticator", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/Authenticator;>;", $PUBLIC},
	{"connectTimeout", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/time/Duration;>;", $PUBLIC},
	{"cookieHandler", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/CookieHandler;>;", $PUBLIC},
	{"executor", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/util/concurrent/Executor;>;", $PUBLIC},
	{"followRedirects", "()Ljava/net/http/HttpClient$Redirect;", nullptr, $PUBLIC},
	{"getOperationsTracker", "()Ljdk/internal/net/http/common/OperationTrackers$Tracker;", nullptr, $PUBLIC},
	{"newWebSocketBuilder", "()Ljava/net/http/WebSocket$Builder;", nullptr, $PUBLIC},
	{"proxy", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/ProxySelector;>;", $PUBLIC},
	{"send", "(Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler;)Ljava/net/http/HttpResponse;", "<T:Ljava/lang/Object;>(Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler<TT;>;)Ljava/net/http/HttpResponse<TT;>;", $PUBLIC, nullptr, "java.io.IOException,java.lang.InterruptedException"},
	{"sendAsync", "(Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler;)Ljava/util/concurrent/CompletableFuture;", "<T:Ljava/lang/Object;>(Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler<TT;>;)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;", $PUBLIC},
	{"sendAsync", "(Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler;Ljava/net/http/HttpResponse$PushPromiseHandler;)Ljava/util/concurrent/CompletableFuture;", "<T:Ljava/lang/Object;>(Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler<TT;>;Ljava/net/http/HttpResponse$PushPromiseHandler<TT;>;)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;", $PUBLIC},
	{"sslContext", "()Ljavax/net/ssl/SSLContext;", nullptr, $PUBLIC},
	{"sslParameters", "()Ljavax/net/ssl/SSLParameters;", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"version", "()Ljava/net/http/HttpClient$Version;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _HttpClientFacade_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.OperationTrackers$Trackable", "jdk.internal.net.http.common.OperationTrackers", "Trackable", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpClientFacade_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.HttpClientFacade",
	"java.net.http.HttpClient",
	"jdk.internal.net.http.common.OperationTrackers$Trackable",
	_HttpClientFacade_FieldInfo_,
	_HttpClientFacade_MethodInfo_,
	nullptr,
	nullptr,
	_HttpClientFacade_InnerClassesInfo_
};

$Object* allocate$HttpClientFacade($Class* clazz) {
	return $of($alloc(HttpClientFacade));
}

int32_t HttpClientFacade::hashCode() {
	 return this->$HttpClient::hashCode();
}

bool HttpClientFacade::equals(Object$* arg0) {
	 return this->$HttpClient::equals(arg0);
}

$Object* HttpClientFacade::clone() {
	 return this->$HttpClient::clone();
}

void HttpClientFacade::finalize() {
	this->$HttpClient::finalize();
}

void HttpClientFacade::init$($HttpClientImpl* impl) {
	$HttpClient::init$();
	$set(this, impl, impl);
}

$OperationTrackers$Tracker* HttpClientFacade::getOperationsTracker() {
	return $nc(this->impl)->getOperationsTracker();
}

$Optional* HttpClientFacade::cookieHandler() {
	return $nc(this->impl)->cookieHandler();
}

$Optional* HttpClientFacade::connectTimeout() {
	return $nc(this->impl)->connectTimeout();
}

$HttpClient$Redirect* HttpClientFacade::followRedirects() {
	return $nc(this->impl)->followRedirects();
}

$Optional* HttpClientFacade::proxy() {
	return $nc(this->impl)->proxy();
}

$SSLContext* HttpClientFacade::sslContext() {
	return $nc(this->impl)->sslContext();
}

$SSLParameters* HttpClientFacade::sslParameters() {
	return $nc(this->impl)->sslParameters();
}

$Optional* HttpClientFacade::authenticator() {
	return $nc(this->impl)->authenticator();
}

$HttpClient$Version* HttpClientFacade::version() {
	return $nc(this->impl)->version();
}

$Optional* HttpClientFacade::executor() {
	return $nc(this->impl)->executor();
}

$HttpResponse* HttpClientFacade::send($HttpRequest* req, $HttpResponse$BodyHandler* responseBodyHandler) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		$var($HttpResponse, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $nc(this->impl)->send(req, responseBodyHandler));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$Reference::reachabilityFence(this);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$CompletableFuture* HttpClientFacade::sendAsync($HttpRequest* req, $HttpResponse$BodyHandler* responseBodyHandler) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		$var($CompletableFuture, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $nc(this->impl)->sendAsync(req, responseBodyHandler));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$Reference::reachabilityFence(this);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$CompletableFuture* HttpClientFacade::sendAsync($HttpRequest* req, $HttpResponse$BodyHandler* responseBodyHandler, $HttpResponse$PushPromiseHandler* pushPromiseHandler) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		$var($CompletableFuture, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $nc(this->impl)->sendAsync(req, responseBodyHandler, pushPromiseHandler));
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$Reference::reachabilityFence(this);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$WebSocket$Builder* HttpClientFacade::newWebSocketBuilder() {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		$var($WebSocket$Builder, var$2, nullptr);
		bool return$1 = false;
		try {
			$assign(var$2, $nc(this->impl)->newWebSocketBuilder());
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$Reference::reachabilityFence(this);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$String* HttpClientFacade::toString() {
	return $nc(this->impl)->toString();
}

HttpClientFacade::HttpClientFacade() {
}

$Class* HttpClientFacade::load$($String* name, bool initialize) {
	$loadClass(HttpClientFacade, name, initialize, &_HttpClientFacade_ClassInfo_, allocate$HttpClientFacade);
	return class$;
}

$Class* HttpClientFacade::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk