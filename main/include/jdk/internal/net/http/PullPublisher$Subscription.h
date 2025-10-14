#ifndef _jdk_internal_net_http_PullPublisher$Subscription_h_
#define _jdk_internal_net_http_PullPublisher$Subscription_h_
//$ class jdk.internal.net.http.PullPublisher$Subscription
//$ extends java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace util {
		class Iterator;
	}
}
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
				class PullPublisher;
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

class $import PullPublisher$Subscription : public ::java::util::concurrent::Flow$Subscription {
	$class(PullPublisher$Subscription, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscription)
public:
	PullPublisher$Subscription();
	void init$(::jdk::internal::net::http::PullPublisher* this$0, ::java::util::concurrent::Flow$Subscriber* subscriber, ::java::util::Iterator* iter, $Throwable* throwable);
	virtual void cancel() override;
	virtual void request(int64_t n) override;
	::jdk::internal::net::http::PullPublisher* this$0 = nullptr;
	::java::util::concurrent::Flow$Subscriber* subscriber = nullptr;
	::java::util::Iterator* iter = nullptr;
	$volatile(bool) completed = false;
	$volatile(bool) cancelled = false;
	$volatile($Throwable*) error = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* pullScheduler = nullptr;
	::jdk::internal::net::http::common::Demand* demand = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_PullPublisher$Subscription_h_