#ifndef _jdk_internal_net_http_websocket_OpeningHandshake$Result_h_
#define _jdk_internal_net_http_websocket_OpeningHandshake$Result_h_
//$ class jdk.internal.net.http.websocket.OpeningHandshake$Result
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {
					class TransportFactory;
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

class OpeningHandshake$Result : public ::java::lang::Object {
	$class(OpeningHandshake$Result, $NO_CLASS_INIT, ::java::lang::Object)
public:
	OpeningHandshake$Result();
	void init$($String* subprotocol, ::jdk::internal::net::http::websocket::TransportFactory* transport);
	$String* subprotocol = nullptr;
	::jdk::internal::net::http::websocket::TransportFactory* transport = nullptr;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_OpeningHandshake$Result_h_