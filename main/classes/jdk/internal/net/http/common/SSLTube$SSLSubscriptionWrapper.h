#ifndef _jdk_internal_net_http_common_SSLTube$SSLSubscriptionWrapper_h_
#define _jdk_internal_net_http_common_SSLTube$SSLSubscriptionWrapper_h_
//$ class jdk.internal.net.http.common.SSLTube$SSLSubscriptionWrapper
//$ extends java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class SSLTube;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export SSLTube$SSLSubscriptionWrapper : public ::java::util::concurrent::Flow$Subscription {
	$class(SSLTube$SSLSubscriptionWrapper, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscription)
public:
	SSLTube$SSLSubscriptionWrapper();
	void init$(::jdk::internal::net::http::common::SSLTube* this$0);
	virtual void cancel() override;
	virtual void request(int64_t n) override;
	void setSubscription(::java::util::concurrent::Flow$Subscription* sub);
	::jdk::internal::net::http::common::SSLTube* this$0 = nullptr;
	$volatile(::java::util::concurrent::Flow$Subscription*) delegate = nullptr;
	$volatile(bool) cancelled = false;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SSLTube$SSLSubscriptionWrapper_h_