#ifndef _jdk_internal_net_http_SocketTube$SocketFlowTask_h_
#define _jdk_internal_net_http_SocketTube$SocketFlowTask_h_
//$ class jdk.internal.net.http.SocketTube$SocketFlowTask
//$ extends jdk.internal.net.http.common.SequentialScheduler$RestartableTask

#include <jdk/internal/net/http/common/SequentialScheduler$RestartableTask.h>

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

class $import SocketTube$SocketFlowTask : public ::jdk::internal::net::http::common::SequentialScheduler$RestartableTask {
	$class(SocketTube$SocketFlowTask, 0, ::jdk::internal::net::http::common::SequentialScheduler$RestartableTask)
public:
	SocketTube$SocketFlowTask();
	void init$(::java::lang::Runnable* task);
	virtual void run(::jdk::internal::net::http::common::SequentialScheduler$DeferredCompleter* taskCompleter) override;
	static bool $assertionsDisabled;
	::java::lang::Runnable* task = nullptr;
	::java::util::concurrent::locks::Lock* lock = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_SocketTube$SocketFlowTask_h_