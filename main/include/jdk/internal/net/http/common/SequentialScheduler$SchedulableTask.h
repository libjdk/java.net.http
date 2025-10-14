#ifndef _jdk_internal_net_http_common_SequentialScheduler$SchedulableTask_h_
#define _jdk_internal_net_http_common_SequentialScheduler$SchedulableTask_h_
//$ class jdk.internal.net.http.common.SequentialScheduler$SchedulableTask
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
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

class $import SequentialScheduler$SchedulableTask : public ::java::lang::Runnable {
	$class(SequentialScheduler$SchedulableTask, $NO_CLASS_INIT, ::java::lang::Runnable)
public:
	SequentialScheduler$SchedulableTask();
	void init$(::jdk::internal::net::http::common::SequentialScheduler* this$0);
	virtual void run() override;
	::jdk::internal::net::http::common::SequentialScheduler* this$0 = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SequentialScheduler$SchedulableTask_h_