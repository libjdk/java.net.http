#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef.h>

#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriberRef.h>
#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $ResponseSubscribers$PublishingBodySubscriber = ::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber;
using $ResponseSubscribers$PublishingBodySubscriber$SubscriberRef = ::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber$SubscriberRef;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef_FieldInfo_[] = {
	{"subscription", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $FINAL, $field(ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef, subscription)},
	{"subscriberRef", "Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriberRef;", nullptr, $FINAL, $field(ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef, subscriberRef)},
	{}
};

$MethodInfo _ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/Flow$Subscription;Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriberRef;)V", nullptr, 0, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef::*)($Flow$Subscription*,$ResponseSubscribers$PublishingBodySubscriber$SubscriberRef*)>(&ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"request", "(J)V", nullptr, $PUBLIC},
	{"subscribe", "()V", nullptr, 0, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef::*)()>(&ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef::subscribe))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber", "jdk.internal.net.http.ResponseSubscribers", "PublishingBodySubscriber", $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef", "jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber", "SubscriptionRef", $STATIC | $FINAL},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription",
	_ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef_FieldInfo_,
	_ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef_MethodInfo_,
	nullptr,
	nullptr,
	_ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseSubscribers"
};

$Object* allocate$ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef($Class* clazz) {
	return $of($alloc(ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef));
}

void ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef::init$($Flow$Subscription* subscription, $ResponseSubscribers$PublishingBodySubscriber$SubscriberRef* subscriberRef) {
	$set(this, subscription, subscription);
	$set(this, subscriberRef, subscriberRef);
}

void ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef::request(int64_t n) {
	if ($nc(this->subscriberRef)->get() != nullptr) {
		$nc(this->subscription)->request(n);
	}
}

void ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef::cancel() {
	$nc(this->subscription)->cancel();
	$nc(this->subscriberRef)->clear();
}

void ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef::subscribe() {
	$var($Flow$Subscriber, subscriber, $nc(this->subscriberRef)->get());
	if (subscriber != nullptr) {
		subscriber->onSubscribe(this);
	}
}

$String* ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $$str({"SubscriptionRef/"_s, $($nc($of(this->subscription))->getClass()->getName()), "@"_s}));
	return $concat(var$0, $$str($System::identityHashCode(this->subscription)));
}

ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef::ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef() {
}

$Class* ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef, name, initialize, &_ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef_ClassInfo_, allocate$ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef);
	return class$;
}

$Class* ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk