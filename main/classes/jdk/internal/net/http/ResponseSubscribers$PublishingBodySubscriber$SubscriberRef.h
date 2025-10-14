#ifndef _jdk_internal_net_http_ResponseSubscribers$PublishingBodySubscriber$SubscriberRef_h_
#define _jdk_internal_net_http_ResponseSubscribers$PublishingBodySubscriber$SubscriberRef_h_
//$ class jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$SubscriberRef
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace util {
		namespace concurrent {
			class Flow$Subscriber;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export ResponseSubscribers$PublishingBodySubscriber$SubscriberRef : public ::java::lang::Object {
	$class(ResponseSubscribers$PublishingBodySubscriber$SubscriberRef, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ResponseSubscribers$PublishingBodySubscriber$SubscriberRef();
	void init$(::java::util::concurrent::Flow$Subscriber* subscriber);
	::java::util::concurrent::Flow$Subscriber* clear();
	::java::util::concurrent::Flow$Subscriber* get();
	$volatile(::java::util::concurrent::Flow$Subscriber*) ref = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseSubscribers$PublishingBodySubscriber$SubscriberRef_h_