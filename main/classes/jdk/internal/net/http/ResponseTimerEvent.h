#ifndef _jdk_internal_net_http_ResponseTimerEvent_h_
#define _jdk_internal_net_http_ResponseTimerEvent_h_
//$ class jdk.internal.net.http.ResponseTimerEvent
//$ extends jdk.internal.net.http.TimeoutEvent

#include <jdk/internal/net/http/TimeoutEvent.h>

namespace java {
	namespace time {
		class Instant;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class MultiExchange;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Logger;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export ResponseTimerEvent : public ::jdk::internal::net::http::TimeoutEvent {
	$class(ResponseTimerEvent, 0, ::jdk::internal::net::http::TimeoutEvent)
public:
	ResponseTimerEvent();
	using ::jdk::internal::net::http::TimeoutEvent::compareTo;
	void init$(::jdk::internal::net::http::MultiExchange* multiExchange);
	virtual int32_t compareTo(::jdk::internal::net::http::TimeoutEvent* other) override;
	virtual ::java::time::Instant* deadline() override;
	virtual void handle() override;
	static ::jdk::internal::net::http::ResponseTimerEvent* of(::jdk::internal::net::http::MultiExchange* exchange);
	virtual $String* toString() override;
	static ::jdk::internal::net::http::common::Logger* debug;
	::jdk::internal::net::http::MultiExchange* multiExchange = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseTimerEvent_h_