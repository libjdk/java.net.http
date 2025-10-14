#ifndef _jdk_internal_net_http_AbstractSubscription_h_
#define _jdk_internal_net_http_AbstractSubscription_h_
//$ class jdk.internal.net.http.AbstractSubscription
//$ extends java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Demand;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export AbstractSubscription : public ::java::util::concurrent::Flow$Subscription {
	$class(AbstractSubscription, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscription)
public:
	AbstractSubscription();
	void init$();
	virtual ::jdk::internal::net::http::common::Demand* demand();
	::jdk::internal::net::http::common::Demand* demand$ = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_AbstractSubscription_h_