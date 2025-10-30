#include <java/net/http/HttpResponse$PushPromiseHandler.h>

#include <java/net/http/HttpRequest.h>
#include <java/net/http/HttpResponse.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/function/Function.h>
#include <jdk/internal/net/http/ResponseBodyHandlers$PushPromisesHandlerWithMap.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpResponse = ::java::net::http::HttpResponse;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $Function = ::java::util::function::Function;
using $ResponseBodyHandlers$PushPromisesHandlerWithMap = ::jdk::internal::net::http::ResponseBodyHandlers$PushPromisesHandlerWithMap;

namespace java {
	namespace net {
		namespace http {

$MethodInfo _HttpResponse$PushPromiseHandler_MethodInfo_[] = {
	{"applyPushPromise", "(Ljava/net/http/HttpRequest;Ljava/net/http/HttpRequest;Ljava/util/function/Function;)V", "(Ljava/net/http/HttpRequest;Ljava/net/http/HttpRequest;Ljava/util/function/Function<Ljava/net/http/HttpResponse$BodyHandler<TT;>;Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;>;)V", $PUBLIC | $ABSTRACT},
	{"of", "(Ljava/util/function/Function;Ljava/util/concurrent/ConcurrentMap;)Ljava/net/http/HttpResponse$PushPromiseHandler;", "<T:Ljava/lang/Object;>(Ljava/util/function/Function<Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler<TT;>;>;Ljava/util/concurrent/ConcurrentMap<Ljava/net/http/HttpRequest;Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;>;)Ljava/net/http/HttpResponse$PushPromiseHandler<TT;>;", $PUBLIC | $STATIC, $method(static_cast<HttpResponse$PushPromiseHandler*(*)($Function*,$ConcurrentMap*)>(&HttpResponse$PushPromiseHandler::of))},
	{}
};

$InnerClassInfo _HttpResponse$PushPromiseHandler_InnerClassesInfo_[] = {
	{"java.net.http.HttpResponse$PushPromiseHandler", "java.net.http.HttpResponse", "PushPromiseHandler", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpResponse$PushPromiseHandler_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.net.http.HttpResponse$PushPromiseHandler",
	nullptr,
	nullptr,
	nullptr,
	_HttpResponse$PushPromiseHandler_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	_HttpResponse$PushPromiseHandler_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.net.http.HttpResponse"
};

$Object* allocate$HttpResponse$PushPromiseHandler($Class* clazz) {
	return $of($alloc(HttpResponse$PushPromiseHandler));
}

HttpResponse$PushPromiseHandler* HttpResponse$PushPromiseHandler::of($Function* pushPromiseHandler, $ConcurrentMap* pushPromisesMap) {
	return $new($ResponseBodyHandlers$PushPromisesHandlerWithMap, pushPromiseHandler, pushPromisesMap);
}

$Class* HttpResponse$PushPromiseHandler::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$PushPromiseHandler, name, initialize, &_HttpResponse$PushPromiseHandler_ClassInfo_, allocate$HttpResponse$PushPromiseHandler);
	return class$;
}

$Class* HttpResponse$PushPromiseHandler::class$ = nullptr;

		} // http
	} // net
} // java