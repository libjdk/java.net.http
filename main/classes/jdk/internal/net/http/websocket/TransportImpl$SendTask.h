#ifndef _jdk_internal_net_http_websocket_TransportImpl$SendTask_h_
#define _jdk_internal_net_http_websocket_TransportImpl$SendTask_h_
//$ class jdk.internal.net.http.websocket.TransportImpl$SendTask
//$ extends jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask

#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class BiConsumer;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {
					class MessageQueue$QueueCallback;
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

class TransportImpl$SendTask : public ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask {
	$class(TransportImpl$SendTask, $NO_CLASS_INIT, ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask)
public:
	TransportImpl$SendTask();
	void init$(::jdk::internal::net::http::websocket::TransportImpl* this$0);
	void removeAndComplete($Throwable* error);
	using ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask::run;
	virtual void run() override;
	bool tryCompleteWrite();
	::jdk::internal::net::http::websocket::TransportImpl* this$0 = nullptr;
	::jdk::internal::net::http::websocket::MessageQueue$QueueCallback* encodingCallback = nullptr;
	bool firstPass = false;
	bool encoded = false;
	$Object* attachment = nullptr;
	::java::util::function::BiConsumer* action = nullptr;
	::java::util::concurrent::CompletableFuture* future = nullptr;
	::jdk::internal::net::http::websocket::MessageQueue$QueueCallback* loadCallback = nullptr;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_TransportImpl$SendTask_h_