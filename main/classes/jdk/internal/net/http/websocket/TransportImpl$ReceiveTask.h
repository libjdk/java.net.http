#ifndef _jdk_internal_net_http_websocket_TransportImpl$ReceiveTask_h_
#define _jdk_internal_net_http_websocket_TransportImpl$ReceiveTask_h_
//$ class jdk.internal.net.http.websocket.TransportImpl$ReceiveTask
//$ extends jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask

#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {
					class TransportImpl;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class TransportImpl$ReceiveTask : public ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask {
	$class(TransportImpl$ReceiveTask, 0, ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask)
public:
	TransportImpl$ReceiveTask();
	void init$(::jdk::internal::net::http::websocket::TransportImpl* this$0);
	using ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask::run;
	virtual void run() override;
	::jdk::internal::net::http::websocket::TransportImpl* this$0 = nullptr;
	static bool $assertionsDisabled;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_TransportImpl$ReceiveTask_h_