#ifndef _jdk_internal_net_http_common_SequentialScheduler$LockingRestartableTask_h_
#define _jdk_internal_net_http_common_SequentialScheduler$LockingRestartableTask_h_
//$ class jdk.internal.net.http.common.SequentialScheduler$LockingRestartableTask
//$ extends jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask

#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>

namespace java {
	namespace lang {
		class Runnable;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace locks {
				class Lock;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $import SequentialScheduler$LockingRestartableTask : public ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask {
	$class(SequentialScheduler$LockingRestartableTask, 0, ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask)
public:
	SequentialScheduler$LockingRestartableTask();
	void init$(::java::lang::Runnable* mainLoop);
	using ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask::run;
	virtual void run() override;
	static bool $assertionsDisabled;
	::java::lang::Runnable* mainLoop = nullptr;
	::java::util::concurrent::locks::Lock* lock = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SequentialScheduler$LockingRestartableTask_h_