#ifndef _jdk_internal_net_http_ResponseSubscribers$PublishingBodySubscriber$1_h_
#define _jdk_internal_net_http_ResponseSubscribers$PublishingBodySubscriber$1_h_
//$ class jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$1
//$ extends java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class ResponseSubscribers$PublishingBodySubscriber;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export ResponseSubscribers$PublishingBodySubscriber$1 : public ::java::util::concurrent::Flow$Subscription {
	$class(ResponseSubscribers$PublishingBodySubscriber$1, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscription)
public:
	ResponseSubscribers$PublishingBodySubscriber$1();
	void init$(::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber* this$0);
	virtual void cancel() override;
	virtual void request(int64_t n) override;
	::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber* this$0 = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseSubscribers$PublishingBodySubscriber$1_h_