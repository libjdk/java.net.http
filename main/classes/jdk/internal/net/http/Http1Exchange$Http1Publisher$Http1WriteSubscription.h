#ifndef _jdk_internal_net_http_Http1Exchange$Http1Publisher$Http1WriteSubscription_h_
#define _jdk_internal_net_http_Http1Exchange$Http1Publisher$Http1WriteSubscription_h_
//$ class jdk.internal.net.http.Http1Exchange$Http1Publisher$Http1WriteSubscription
//$ extends java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Http1Exchange$Http1Publisher;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Http1Exchange$Http1Publisher$Http1WriteSubscription : public ::java::util::concurrent::Flow$Subscription {
	$class(Http1Exchange$Http1Publisher$Http1WriteSubscription, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscription)
public:
	Http1Exchange$Http1Publisher$Http1WriteSubscription();
	void init$(::jdk::internal::net::http::Http1Exchange$Http1Publisher* this$1);
	virtual void cancel() override;
	virtual void request(int64_t n) override;
	::jdk::internal::net::http::Http1Exchange$Http1Publisher* this$1 = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1Exchange$Http1Publisher$Http1WriteSubscription_h_