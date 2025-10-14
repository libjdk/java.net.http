#ifndef _jdk_internal_net_http_common_SequentialScheduler$CompleteRestartableTask_h_
#define _jdk_internal_net_http_common_SequentialScheduler$CompleteRestartableTask_h_
//$ class jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask
//$ extends jdk.internal.net.http.common.SequentialScheduler$RestartableTask

#include <jdk/internal/net/http/common/SequentialScheduler$RestartableTask.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class SequentialScheduler$DeferredCompleter;
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

class $import SequentialScheduler$CompleteRestartableTask : public ::jdk::internal::net::http::common::SequentialScheduler$RestartableTask {
	$class(SequentialScheduler$CompleteRestartableTask, $NO_CLASS_INIT, ::jdk::internal::net::http::common::SequentialScheduler$RestartableTask)
public:
	SequentialScheduler$CompleteRestartableTask();
	void init$();
	virtual void run(::jdk::internal::net::http::common::SequentialScheduler$DeferredCompleter* taskCompleter) override;
	virtual void run() {}
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SequentialScheduler$CompleteRestartableTask_h_