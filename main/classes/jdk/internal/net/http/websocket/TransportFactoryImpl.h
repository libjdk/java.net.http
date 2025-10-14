#ifndef _jdk_internal_net_http_websocket_TransportFactoryImpl_h_
#define _jdk_internal_net_http_websocket_TransportFactoryImpl_h_
//$ class jdk.internal.net.http.websocket.TransportFactoryImpl
//$ extends jdk.internal.net.http.websocket.TransportFactory

#include <jdk/internal/net/http/websocket/TransportFactory.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {
					class MessageQueue;
					class MessageStreamConsumer;
					class RawChannel;
					class Transport;
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

class TransportFactoryImpl : public ::jdk::internal::net::http::websocket::TransportFactory {
	$class(TransportFactoryImpl, $NO_CLASS_INIT, ::jdk::internal::net::http::websocket::TransportFactory)
public:
	TransportFactoryImpl();
	void init$(::jdk::internal::net::http::websocket::RawChannel* channel);
	virtual ::jdk::internal::net::http::websocket::Transport* createTransport(::jdk::internal::net::http::websocket::MessageQueue* queue, ::jdk::internal::net::http::websocket::MessageStreamConsumer* consumer) override;
	::jdk::internal::net::http::websocket::RawChannel* channel = nullptr;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_TransportFactoryImpl_h_