#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriberRef.h>

#include <java/util/concurrent/Flow$Subscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $ResponseSubscribers$PublishingBodySubscriber = ::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ResponseSubscribers$PublishingBodySubscriber$SubscriberRef_FieldInfo_[] = {
	{"ref", "Ljava/util/concurrent/Flow$Subscriber;", "Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;", $VOLATILE, $field(ResponseSubscribers$PublishingBodySubscriber$SubscriberRef, ref)},
	{}
};

$MethodInfo _ResponseSubscribers$PublishingBodySubscriber$SubscriberRef_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", 0, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber$SubscriberRef::*)($Flow$Subscriber*)>(&ResponseSubscribers$PublishingBodySubscriber$SubscriberRef::init$))},
	{"clear", "()Ljava/util/concurrent/Flow$Subscriber;", "()Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;", 0, $method(static_cast<$Flow$Subscriber*(ResponseSubscribers$PublishingBodySubscriber$SubscriberRef::*)()>(&ResponseSubscribers$PublishingBodySubscriber$SubscriberRef::clear))},
	{"get", "()Ljava/util/concurrent/Flow$Subscriber;", "()Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;", 0, $method(static_cast<$Flow$Subscriber*(ResponseSubscribers$PublishingBodySubscriber$SubscriberRef::*)()>(&ResponseSubscribers$PublishingBodySubscriber$SubscriberRef::get))},
	{}
};

$InnerClassInfo _ResponseSubscribers$PublishingBodySubscriber$SubscriberRef_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber", "jdk.internal.net.http.ResponseSubscribers", "PublishingBodySubscriber", $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$SubscriberRef", "jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber", "SubscriberRef", $STATIC | $FINAL},
	{}
};

$ClassInfo _ResponseSubscribers$PublishingBodySubscriber$SubscriberRef_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$SubscriberRef",
	"java.lang.Object",
	nullptr,
	_ResponseSubscribers$PublishingBodySubscriber$SubscriberRef_FieldInfo_,
	_ResponseSubscribers$PublishingBodySubscriber$SubscriberRef_MethodInfo_,
	nullptr,
	nullptr,
	_ResponseSubscribers$PublishingBodySubscriber$SubscriberRef_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseSubscribers"
};

$Object* allocate$ResponseSubscribers$PublishingBodySubscriber$SubscriberRef($Class* clazz) {
	return $of($alloc(ResponseSubscribers$PublishingBodySubscriber$SubscriberRef));
}

void ResponseSubscribers$PublishingBodySubscriber$SubscriberRef::init$($Flow$Subscriber* subscriber) {
	$set(this, ref, subscriber);
}

$Flow$Subscriber* ResponseSubscribers$PublishingBodySubscriber$SubscriberRef::get() {
	return this->ref;
}

$Flow$Subscriber* ResponseSubscribers$PublishingBodySubscriber$SubscriberRef::clear() {
	$var($Flow$Subscriber, res, this->ref);
	$set(this, ref, nullptr);
	return res;
}

ResponseSubscribers$PublishingBodySubscriber$SubscriberRef::ResponseSubscribers$PublishingBodySubscriber$SubscriberRef() {
}

$Class* ResponseSubscribers$PublishingBodySubscriber$SubscriberRef::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$PublishingBodySubscriber$SubscriberRef, name, initialize, &_ResponseSubscribers$PublishingBodySubscriber$SubscriberRef_ClassInfo_, allocate$ResponseSubscribers$PublishingBodySubscriber$SubscriberRef);
	return class$;
}

$Class* ResponseSubscribers$PublishingBodySubscriber$SubscriberRef::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk