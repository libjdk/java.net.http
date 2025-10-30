#include <jdk/internal/net/http/ResponseBodyHandlers$PushPromisesHandlerWithMap.h>

#include <java/net/URI.h>
#include <java/net/http/HttpRequest.h>
#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/function/Function.h>
#include <jdk/internal/net/http/ResponseBodyHandlers.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URI = ::java::net::URI;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $HttpResponse$PushPromiseHandler = ::java::net::http::HttpResponse$PushPromiseHandler;
using $Map = ::java::util::Map;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $Function = ::java::util::function::Function;
using $ResponseBodyHandlers = ::jdk::internal::net::http::ResponseBodyHandlers;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ResponseBodyHandlers$PushPromisesHandlerWithMap_FieldInfo_[] = {
	{"pushPromisesMap", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/net/http/HttpRequest;Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;>;", $PRIVATE | $FINAL, $field(ResponseBodyHandlers$PushPromisesHandlerWithMap, pushPromisesMap)},
	{"pushPromiseHandler", "Ljava/util/function/Function;", "Ljava/util/function/Function<Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler<TT;>;>;", $PRIVATE | $FINAL, $field(ResponseBodyHandlers$PushPromisesHandlerWithMap, pushPromiseHandler)},
	{}
};

$MethodInfo _ResponseBodyHandlers$PushPromisesHandlerWithMap_MethodInfo_[] = {
	{"<init>", "(Ljava/util/function/Function;Ljava/util/concurrent/ConcurrentMap;)V", "(Ljava/util/function/Function<Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler<TT;>;>;Ljava/util/concurrent/ConcurrentMap<Ljava/net/http/HttpRequest;Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;>;)V", $PUBLIC, $method(static_cast<void(ResponseBodyHandlers$PushPromisesHandlerWithMap::*)($Function*,$ConcurrentMap*)>(&ResponseBodyHandlers$PushPromisesHandlerWithMap::init$))},
	{"applyPushPromise", "(Ljava/net/http/HttpRequest;Ljava/net/http/HttpRequest;Ljava/util/function/Function;)V", "(Ljava/net/http/HttpRequest;Ljava/net/http/HttpRequest;Ljava/util/function/Function<Ljava/net/http/HttpResponse$BodyHandler<TT;>;Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;>;)V", $PUBLIC},
	{}
};

$InnerClassInfo _ResponseBodyHandlers$PushPromisesHandlerWithMap_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseBodyHandlers$PushPromisesHandlerWithMap", "jdk.internal.net.http.ResponseBodyHandlers", "PushPromisesHandlerWithMap", $PUBLIC | $STATIC},
	{"java.net.http.HttpResponse$PushPromiseHandler", "java.net.http.HttpResponse", "PushPromiseHandler", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseBodyHandlers$PushPromisesHandlerWithMap_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.ResponseBodyHandlers$PushPromisesHandlerWithMap",
	"java.lang.Object",
	"java.net.http.HttpResponse$PushPromiseHandler",
	_ResponseBodyHandlers$PushPromisesHandlerWithMap_FieldInfo_,
	_ResponseBodyHandlers$PushPromisesHandlerWithMap_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljava/net/http/HttpResponse$PushPromiseHandler<TT;>;",
	nullptr,
	_ResponseBodyHandlers$PushPromisesHandlerWithMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseBodyHandlers"
};

$Object* allocate$ResponseBodyHandlers$PushPromisesHandlerWithMap($Class* clazz) {
	return $of($alloc(ResponseBodyHandlers$PushPromisesHandlerWithMap));
}

void ResponseBodyHandlers$PushPromisesHandlerWithMap::init$($Function* pushPromiseHandler, $ConcurrentMap* pushPromisesMap) {
	$set(this, pushPromiseHandler, pushPromiseHandler);
	$set(this, pushPromisesMap, pushPromisesMap);
}

void ResponseBodyHandlers$PushPromisesHandlerWithMap::applyPushPromise($HttpRequest* initiatingRequest, $HttpRequest* pushRequest, $Function* acceptor) {
	$useLocalCurrentObjectStackCache();
	$var($URI, initiatingURI, $nc(initiatingRequest)->uri());
	$var($URI, pushRequestURI, $nc(pushRequest)->uri());
	if (!$nc($($nc(initiatingURI)->getHost()))->equalsIgnoreCase($($nc(pushRequestURI)->getHost()))) {
		return;
	}
	int32_t initiatingPort = $nc(initiatingURI)->getPort();
	if (initiatingPort == -1) {
		if ("https"_s->equalsIgnoreCase($(initiatingURI->getScheme()))) {
			initiatingPort = 443;
		} else {
			initiatingPort = 80;
		}
	}
	int32_t pushPort = $nc(pushRequestURI)->getPort();
	if (pushPort == -1) {
		if ("https"_s->equalsIgnoreCase($(pushRequestURI->getScheme()))) {
			pushPort = 443;
		} else {
			pushPort = 80;
		}
	}
	if (initiatingPort != pushPort) {
		return;
	}
	$var($CompletableFuture, cf, $cast($CompletableFuture, $nc(acceptor)->apply($cast($HttpResponse$BodyHandler, $($nc(this->pushPromiseHandler)->apply(pushRequest))))));
	$nc(this->pushPromisesMap)->put(pushRequest, cf);
}

ResponseBodyHandlers$PushPromisesHandlerWithMap::ResponseBodyHandlers$PushPromisesHandlerWithMap() {
}

$Class* ResponseBodyHandlers$PushPromisesHandlerWithMap::load$($String* name, bool initialize) {
	$loadClass(ResponseBodyHandlers$PushPromisesHandlerWithMap, name, initialize, &_ResponseBodyHandlers$PushPromisesHandlerWithMap_ClassInfo_, allocate$ResponseBodyHandlers$PushPromisesHandlerWithMap);
	return class$;
}

$Class* ResponseBodyHandlers$PushPromisesHandlerWithMap::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk