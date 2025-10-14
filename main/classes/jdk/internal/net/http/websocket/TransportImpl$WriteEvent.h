#ifndef _jdk_internal_net_http_websocket_TransportImpl$WriteEvent_h_
#define _jdk_internal_net_http_websocket_TransportImpl$WriteEvent_h_
//$ class jdk.internal.net.http.websocket.TransportImpl$WriteEvent
//$ extends jdk.internal.net.http.websocket.RawChannel$RawEvent

#include <jdk/internal/net/http/websocket/RawChannel$RawEvent.h>

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

class TransportImpl$WriteEvent : public ::jdk::internal::net::http::websocket::RawChannel$RawEvent {
	$class(TransportImpl$WriteEvent, $NO_CLASS_INIT, ::jdk::internal::net::http::websocket::RawChannel$RawEvent)
public:
	TransportImpl$WriteEvent();
	void init$(::jdk::internal::net::http::websocket::TransportImpl* this$0);
	virtual void handle() override;
	virtual int32_t interestOps() override;
	::jdk::internal::net::http::websocket::TransportImpl* this$0 = nullptr;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_TransportImpl$WriteEvent_h_