#ifndef _jdk_internal_net_http_AsyncTriggerEvent_h_
#define _jdk_internal_net_http_AsyncTriggerEvent_h_
//$ class jdk.internal.net.http.AsyncTriggerEvent
//$ extends jdk.internal.net.http.AsyncEvent

#include <jdk/internal/net/http/AsyncEvent.h>

namespace java {
	namespace io {
		class IOException;
	}
}
namespace java {
	namespace lang {
		class Runnable;
	}
}
namespace java {
	namespace nio {
		namespace channels {
			class SelectableChannel;
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Consumer;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import AsyncTriggerEvent : public ::jdk::internal::net::http::AsyncEvent {
	$class(AsyncTriggerEvent, $NO_CLASS_INIT, ::jdk::internal::net::http::AsyncEvent)
public:
	AsyncTriggerEvent();
	void init$(::java::util::function::Consumer* errorHandler, ::java::lang::Runnable* trigger);
	virtual void abort(::java::io::IOException* ioe) override;
	virtual ::java::nio::channels::SelectableChannel* channel() override;
	virtual void handle() override;
	virtual int32_t interestOps() override;
	virtual bool repeating() override;
	::java::lang::Runnable* trigger = nullptr;
	::java::util::function::Consumer* errorHandler = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_AsyncTriggerEvent_h_