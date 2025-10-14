#ifndef _jdk_internal_net_http_RawChannelTube$WriteSubscription_h_
#define _jdk_internal_net_http_RawChannelTube$WriteSubscription_h_
//$ class jdk.internal.net.http.RawChannelTube$WriteSubscription
//$ extends java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>

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
				class RawChannelTube;
			}
		}
	}
}
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

class $import RawChannelTube$WriteSubscription : public ::java::util::concurrent::Flow$Subscription {
	$class(RawChannelTube$WriteSubscription, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscription)
public:
	RawChannelTube$WriteSubscription();
	void init$(::jdk::internal::net::http::RawChannelTube* this$0, ::java::util::concurrent::Flow$Subscriber* subscriber);
	virtual void cancel() override;
	virtual void request(int64_t n) override;
	::jdk::internal::net::http::RawChannelTube* this$0 = nullptr;
	::java::util::concurrent::Flow$Subscriber* subscriber = nullptr;
	::jdk::internal::net::http::common::Demand* demand = nullptr;
	$volatile(bool) cancelled = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RawChannelTube$WriteSubscription_h_