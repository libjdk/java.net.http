#ifndef _jdk_internal_net_http_PullPublisher$Subscription$PullTask_h_
#define _jdk_internal_net_http_PullPublisher$Subscription$PullTask_h_
//$ class jdk.internal.net.http.PullPublisher$Subscription$PullTask
//$ extends jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask

#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class PullPublisher$Subscription;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import PullPublisher$Subscription$PullTask : public ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask {
	$class(PullPublisher$Subscription$PullTask, $NO_CLASS_INIT, ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask)
public:
	PullPublisher$Subscription$PullTask();
	void init$(::jdk::internal::net::http::PullPublisher$Subscription* this$1);
	using ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask::run;
	virtual void run() override;
	::jdk::internal::net::http::PullPublisher$Subscription* this$1 = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_PullPublisher$Subscription$PullTask_h_