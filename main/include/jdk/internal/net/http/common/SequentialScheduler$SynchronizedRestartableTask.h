#ifndef _jdk_internal_net_http_common_SequentialScheduler$SynchronizedRestartableTask_h_
#define _jdk_internal_net_http_common_SequentialScheduler$SynchronizedRestartableTask_h_
//$ class jdk.internal.net.http.common.SequentialScheduler$SynchronizedRestartableTask
//$ extends jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask

#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>

namespace java {
	namespace lang {
		class Runnable;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $import SequentialScheduler$SynchronizedRestartableTask : public ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask {
	$class(SequentialScheduler$SynchronizedRestartableTask, $NO_CLASS_INIT, ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask)
public:
	SequentialScheduler$SynchronizedRestartableTask();
	void init$(::java::lang::Runnable* mainLoop);
	using ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask::run;
	virtual void run() override;
	::java::lang::Runnable* mainLoop = nullptr;
	$Object* lock = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SequentialScheduler$SynchronizedRestartableTask_h_