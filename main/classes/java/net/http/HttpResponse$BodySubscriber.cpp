#include <java/net/http/HttpResponse$BodySubscriber.h>

#include <java/net/http/HttpResponse.h>
#include <java/util/concurrent/CompletionStage.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpResponse = ::java::net::http::HttpResponse;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;

namespace java {
	namespace net {
		namespace http {

$MethodInfo _HttpResponse$BodySubscriber_MethodInfo_[] = {
	{"getBody", "()Ljava/util/concurrent/CompletionStage;", "()Ljava/util/concurrent/CompletionStage<TT;>;", $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _HttpResponse$BodySubscriber_InnerClassesInfo_[] = {
	{"java.net.http.HttpResponse$BodySubscriber", "java.net.http.HttpResponse", "BodySubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.Flow$Subscriber", "java.util.concurrent.Flow", "Subscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpResponse$BodySubscriber_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.net.http.HttpResponse$BodySubscriber",
	nullptr,
	"java.util.concurrent.Flow$Subscriber",
	nullptr,
	_HttpResponse$BodySubscriber_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/concurrent/Flow$Subscriber<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;",
	nullptr,
	_HttpResponse$BodySubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.net.http.HttpResponse"
};

$Object* allocate$HttpResponse$BodySubscriber($Class* clazz) {
	return $of($alloc(HttpResponse$BodySubscriber));
}

$Class* HttpResponse$BodySubscriber::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodySubscriber, name, initialize, &_HttpResponse$BodySubscriber_ClassInfo_, allocate$HttpResponse$BodySubscriber);
	return class$;
}

$Class* HttpResponse$BodySubscriber::class$ = nullptr;

		} // http
	} // net
} // java