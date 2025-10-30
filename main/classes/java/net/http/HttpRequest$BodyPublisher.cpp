#include <java/net/http/HttpRequest$BodyPublisher.h>

#include <java/net/http/HttpRequest.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpRequest = ::java::net::http::HttpRequest;
using $Flow$Publisher = ::java::util::concurrent::Flow$Publisher;

namespace java {
	namespace net {
		namespace http {

$MethodInfo _HttpRequest$BodyPublisher_MethodInfo_[] = {
	{"contentLength", "()J", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _HttpRequest$BodyPublisher_InnerClassesInfo_[] = {
	{"java.net.http.HttpRequest$BodyPublisher", "java.net.http.HttpRequest", "BodyPublisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.Flow$Publisher", "java.util.concurrent.Flow", "Publisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpRequest$BodyPublisher_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.net.http.HttpRequest$BodyPublisher",
	nullptr,
	"java.util.concurrent.Flow$Publisher",
	nullptr,
	_HttpRequest$BodyPublisher_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/concurrent/Flow$Publisher<Ljava/nio/ByteBuffer;>;",
	nullptr,
	_HttpRequest$BodyPublisher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.net.http.HttpRequest"
};

$Object* allocate$HttpRequest$BodyPublisher($Class* clazz) {
	return $of($alloc(HttpRequest$BodyPublisher));
}

$Class* HttpRequest$BodyPublisher::load$($String* name, bool initialize) {
	$loadClass(HttpRequest$BodyPublisher, name, initialize, &_HttpRequest$BodyPublisher_ClassInfo_, allocate$HttpRequest$BodyPublisher);
	return class$;
}

$Class* HttpRequest$BodyPublisher::class$ = nullptr;

		} // http
	} // net
} // java