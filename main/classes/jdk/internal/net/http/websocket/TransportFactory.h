#ifndef _jdk_internal_net_http_websocket_TransportFactory_h_
#define _jdk_internal_net_http_websocket_TransportFactory_h_
//$ interface jdk.internal.net.http.websocket.TransportFactory
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {
					class MessageQueue;
					class MessageStreamConsumer;
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

class TransportFactory : public ::java::lang::Object {
	$interface(TransportFactory, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::jdk::internal::net::http::websocket::Transport* createTransport(::jdk::internal::net::http::websocket::MessageQueue* queue, ::jdk::internal::net::http::websocket::MessageStreamConsumer* consumer) {return nullptr;}
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_TransportFactory_h_