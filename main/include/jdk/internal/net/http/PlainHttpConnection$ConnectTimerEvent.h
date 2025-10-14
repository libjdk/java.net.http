#ifndef _jdk_internal_net_http_PlainHttpConnection$ConnectTimerEvent_h_
#define _jdk_internal_net_http_PlainHttpConnection$ConnectTimerEvent_h_
//$ class jdk.internal.net.http.PlainHttpConnection$ConnectTimerEvent
//$ extends jdk.internal.net.http.TimeoutEvent

#include <jdk/internal/net/http/TimeoutEvent.h>

namespace java {
	namespace net {
		class ConnectException;
	}
}
namespace java {
	namespace time {
		class Duration;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Exchange;
				class PlainHttpConnection;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import PlainHttpConnection$ConnectTimerEvent : public ::jdk::internal::net::http::TimeoutEvent {
	$class(PlainHttpConnection$ConnectTimerEvent, $NO_CLASS_INIT, ::jdk::internal::net::http::TimeoutEvent)
public:
	PlainHttpConnection$ConnectTimerEvent();
	void init$(::jdk::internal::net::http::PlainHttpConnection* this$0, ::java::time::Duration* duration, ::jdk::internal::net::http::Exchange* exchange, ::java::util::concurrent::CompletableFuture* cf);
	virtual void handle() override;
	void lambda$handle$0(::java::net::ConnectException* ce);
	virtual $String* toString() override;
	::jdk::internal::net::http::PlainHttpConnection* this$0 = nullptr;
	::java::util::concurrent::CompletableFuture* cf = nullptr;
	::jdk::internal::net::http::Exchange* exchange = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_PlainHttpConnection$ConnectTimerEvent_h_