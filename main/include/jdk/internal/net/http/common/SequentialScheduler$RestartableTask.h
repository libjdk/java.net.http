#ifndef _jdk_internal_net_http_common_SequentialScheduler$RestartableTask_h_
#define _jdk_internal_net_http_common_SequentialScheduler$RestartableTask_h_
//$ interface jdk.internal.net.http.common.SequentialScheduler$RestartableTask
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

class $import SequentialScheduler$RestartableTask : public ::java::lang::Object {
	$interface(SequentialScheduler$RestartableTask, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void run(::jdk::internal::net::http::common::SequentialScheduler$DeferredCompleter* taskCompleter) {}
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SequentialScheduler$RestartableTask_h_