#ifndef _jdk_internal_net_http_BufferingSubscriber$DownstreamSubscription$PushDemandedTask_h_
#define _jdk_internal_net_http_BufferingSubscriber$DownstreamSubscription$PushDemandedTask_h_
//$ class jdk.internal.net.http.BufferingSubscriber$DownstreamSubscription$PushDemandedTask
//$ extends jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask

#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class BufferingSubscriber$DownstreamSubscription;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import BufferingSubscriber$DownstreamSubscription$PushDemandedTask : public ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask {
	$class(BufferingSubscriber$DownstreamSubscription$PushDemandedTask, 0, ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask)
public:
	BufferingSubscriber$DownstreamSubscription$PushDemandedTask();
	void init$(::jdk::internal::net::http::BufferingSubscriber$DownstreamSubscription* this$1);
	using ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask::run;
	virtual void run() override;
	::jdk::internal::net::http::BufferingSubscriber$DownstreamSubscription* this$1 = nullptr;
	static bool $assertionsDisabled;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_BufferingSubscriber$DownstreamSubscription$PushDemandedTask_h_