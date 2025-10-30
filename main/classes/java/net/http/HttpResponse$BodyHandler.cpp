#include <java/net/http/HttpResponse$BodyHandler.h>

#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/net/http/HttpResponse$ResponseInfo.h>
#include <java/net/http/HttpResponse.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpResponse = ::java::net::http::HttpResponse;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $HttpResponse$ResponseInfo = ::java::net::http::HttpResponse$ResponseInfo;

namespace java {
	namespace net {
		namespace http {

$CompoundAttribute _HttpResponse$BodyHandler_Annotations_[] = {
	{"Ljava/lang/FunctionalInterface;", nullptr},
	{}
};

$MethodInfo _HttpResponse$BodyHandler_MethodInfo_[] = {
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber<TT;>;", $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _HttpResponse$BodyHandler_InnerClassesInfo_[] = {
	{"java.net.http.HttpResponse$BodyHandler", "java.net.http.HttpResponse", "BodyHandler", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpResponse$BodyHandler_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.net.http.HttpResponse$BodyHandler",
	nullptr,
	nullptr,
	nullptr,
	_HttpResponse$BodyHandler_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	_HttpResponse$BodyHandler_InnerClassesInfo_,
	_HttpResponse$BodyHandler_Annotations_,
	nullptr,
	nullptr,
	"java.net.http.HttpResponse"
};

$Object* allocate$HttpResponse$BodyHandler($Class* clazz) {
	return $of($alloc(HttpResponse$BodyHandler));
}

$Class* HttpResponse$BodyHandler::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandler, name, initialize, &_HttpResponse$BodyHandler_ClassInfo_, allocate$HttpResponse$BodyHandler);
	return class$;
}

$Class* HttpResponse$BodyHandler::class$ = nullptr;

		} // http
	} // net
} // java