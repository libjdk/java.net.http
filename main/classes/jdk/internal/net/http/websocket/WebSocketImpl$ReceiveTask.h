#ifndef _jdk_internal_net_http_websocket_WebSocketImpl$ReceiveTask_h_
#define _jdk_internal_net_http_websocket_WebSocketImpl$ReceiveTask_h_
//$ class jdk.internal.net.http.websocket.WebSocketImpl$ReceiveTask
//$ extends jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask

#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {
					class WebSocketImpl;
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

class WebSocketImpl$ReceiveTask : public ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask {
	$class(WebSocketImpl$ReceiveTask, $NO_CLASS_INIT, ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask)
public:
	WebSocketImpl$ReceiveTask();
	void init$(::jdk::internal::net::http::websocket::WebSocketImpl* this$0);
	void lambda$processClose$0(int32_t code, Object$* r, $Throwable* e);
	void lambda$processPing$1(::jdk::internal::net::http::websocket::WebSocketImpl* r, $Throwable* e);
	void processBinary();
	void processClose();
	void processError();
	void processOpen();
	void processPing();
	void processPong();
	void processText();
	using ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask::run;
	virtual void run() override;
	::jdk::internal::net::http::websocket::WebSocketImpl* this$0 = nullptr;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_WebSocketImpl$ReceiveTask_h_