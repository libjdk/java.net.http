#ifndef _jdk_internal_net_http_websocket_WebSocketImpl$SignallingMessageConsumer_h_
#define _jdk_internal_net_http_websocket_WebSocketImpl$SignallingMessageConsumer_h_
//$ class jdk.internal.net.http.websocket.WebSocketImpl$SignallingMessageConsumer
//$ extends jdk.internal.net.http.websocket.MessageStreamConsumer

#include <jdk/internal/net/http/websocket/MessageStreamConsumer.h>

namespace java {
	namespace lang {
		class CharSequence;
		class Throwable;
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
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

class WebSocketImpl$SignallingMessageConsumer : public ::jdk::internal::net::http::websocket::MessageStreamConsumer {
	$class(WebSocketImpl$SignallingMessageConsumer, $NO_CLASS_INIT, ::jdk::internal::net::http::websocket::MessageStreamConsumer)
public:
	WebSocketImpl$SignallingMessageConsumer();
	void init$(::jdk::internal::net::http::websocket::WebSocketImpl* this$0);
	virtual void onBinary(::java::nio::ByteBuffer* data, bool last) override;
	virtual void onClose(int32_t statusCode, ::java::lang::CharSequence* reason) override;
	virtual void onComplete() override;
	virtual void onError($Throwable* error) override;
	virtual void onPing(::java::nio::ByteBuffer* data) override;
	virtual void onPong(::java::nio::ByteBuffer* data) override;
	virtual void onText(::java::lang::CharSequence* data, bool last) override;
	::jdk::internal::net::http::websocket::WebSocketImpl* this$0 = nullptr;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_WebSocketImpl$SignallingMessageConsumer_h_