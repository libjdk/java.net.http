#include <java/net/http/HttpResponse.h>

#include <java/net/URI.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpRequest.h>
#include <java/util/Optional.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URI = ::java::net::URI;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpRequest = ::java::net::http::HttpRequest;
using $Optional = ::java::util::Optional;

namespace java {
	namespace net {
		namespace http {

$MethodInfo _HttpResponse_MethodInfo_[] = {
	{"body", "()Ljava/lang/Object;", "()TT;", $PUBLIC | $ABSTRACT},
	{"headers", "()Ljava/net/http/HttpHeaders;", nullptr, $PUBLIC | $ABSTRACT},
	{"previousResponse", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/http/HttpResponse<TT;>;>;", $PUBLIC | $ABSTRACT},
	{"request", "()Ljava/net/http/HttpRequest;", nullptr, $PUBLIC | $ABSTRACT},
	{"sslSession", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljavax/net/ssl/SSLSession;>;", $PUBLIC | $ABSTRACT},
	{"statusCode", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"uri", "()Ljava/net/URI;", nullptr, $PUBLIC | $ABSTRACT},
	{"version", "()Ljava/net/http/HttpClient$Version;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _HttpResponse_InnerClassesInfo_[] = {
	{"java.net.http.HttpResponse$BodySubscribers", "java.net.http.HttpResponse", "BodySubscribers", $PUBLIC | $STATIC},
	{"java.net.http.HttpResponse$BodySubscriber", "java.net.http.HttpResponse", "BodySubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.net.http.HttpResponse$PushPromiseHandler", "java.net.http.HttpResponse", "PushPromiseHandler", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.net.http.HttpResponse$BodyHandlers", "java.net.http.HttpResponse", "BodyHandlers", $PUBLIC | $STATIC},
	{"java.net.http.HttpResponse$BodyHandler", "java.net.http.HttpResponse", "BodyHandler", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.net.http.HttpResponse$ResponseInfo", "java.net.http.HttpResponse", "ResponseInfo", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpResponse_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.net.http.HttpResponse",
	nullptr,
	nullptr,
	nullptr,
	_HttpResponse_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	_HttpResponse_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.net.http.HttpResponse$BodySubscribers,java.net.http.HttpResponse$BodySubscriber,java.net.http.HttpResponse$PushPromiseHandler,java.net.http.HttpResponse$BodyHandlers,java.net.http.HttpResponse$BodyHandler,java.net.http.HttpResponse$ResponseInfo"
};

$Object* allocate$HttpResponse($Class* clazz) {
	return $of($alloc(HttpResponse));
}

$Class* HttpResponse::load$($String* name, bool initialize) {
	$loadClass(HttpResponse, name, initialize, &_HttpResponse_ClassInfo_, allocate$HttpResponse);
	return class$;
}

$Class* HttpResponse::class$ = nullptr;

		} // http
	} // net
} // java