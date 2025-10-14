#ifndef _jdk_internal_net_http_ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef_h_
#define _jdk_internal_net_http_ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef_h_
//$ class jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef
//$ extends java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class ResponseSubscribers$PublishingBodySubscriber$SubscriberRef;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef : public ::java::util::concurrent::Flow$Subscription {
	$class(ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscription)
public:
	ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef();
	void init$(::java::util::concurrent::Flow$Subscription* subscription, ::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber$SubscriberRef* subscriberRef);
	virtual void cancel() override;
	virtual void request(int64_t n) override;
	void subscribe();
	virtual $String* toString() override;
	::java::util::concurrent::Flow$Subscription* subscription = nullptr;
	::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber$SubscriberRef* subscriberRef = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef_h_