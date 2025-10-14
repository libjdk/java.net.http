#ifndef _jdk_internal_net_http_common_SubscriptionBase_h_
#define _jdk_internal_net_http_common_SubscriptionBase_h_
//$ class jdk.internal.net.http.common.SubscriptionBase
//$ extends java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>

namespace java {
	namespace lang {
		class Runnable;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicBoolean;
			}
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Consumer;
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
				namespace common {

class $export SubscriptionBase : public ::java::util::concurrent::Flow$Subscription {
	$class(SubscriptionBase, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscription)
public:
	SubscriptionBase();
	void init$(::jdk::internal::net::http::common::SequentialScheduler* scheduler, ::java::lang::Runnable* cancelAction);
	void init$(::jdk::internal::net::http::common::SequentialScheduler* scheduler, ::java::lang::Runnable* cancelAction, ::java::util::function::Consumer* onError);
	virtual void cancel() override;
	virtual void request(int64_t n) override;
	virtual $String* toString() override;
	virtual bool tryDecrement();
	virtual int64_t window();
	::jdk::internal::net::http::common::Demand* demand = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* scheduler = nullptr;
	::java::lang::Runnable* cancelAction = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* cancelled = nullptr;
	::java::util::function::Consumer* onError = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SubscriptionBase_h_