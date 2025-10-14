#ifndef _jdk_internal_net_http_BufferingSubscriber$DownstreamSubscription_h_
#define _jdk_internal_net_http_BufferingSubscriber$DownstreamSubscription_h_
//$ class jdk.internal.net.http.BufferingSubscriber$DownstreamSubscription
//$ extends java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>

namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicBoolean;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class BufferingSubscriber;
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
					class SequentialScheduler;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export BufferingSubscriber$DownstreamSubscription : public ::java::util::concurrent::Flow$Subscription {
	$class(BufferingSubscriber$DownstreamSubscription, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscription)
public:
	BufferingSubscriber$DownstreamSubscription();
	void init$(::jdk::internal::net::http::BufferingSubscriber* this$0);
	virtual void cancel() override;
	virtual void pushDemanded();
	virtual void request(int64_t n) override;
	::jdk::internal::net::http::BufferingSubscriber* this$0 = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* cancelled = nullptr;
	::jdk::internal::net::http::common::Demand* demand = nullptr;
	$volatile(bool) illegalArg = false;
	::jdk::internal::net::http::common::SequentialScheduler* pushDemandedScheduler = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_BufferingSubscriber$DownstreamSubscription_h_