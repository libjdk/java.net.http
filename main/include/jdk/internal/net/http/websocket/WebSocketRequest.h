#ifndef _jdk_internal_net_http_websocket_WebSocketRequest_h_
#define _jdk_internal_net_http_websocket_WebSocketRequest_h_
//$ interface jdk.internal.net.http.websocket.WebSocketRequest
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		class Proxy;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class $import WebSocketRequest : public ::java::lang::Object {
	$interface(WebSocketRequest, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void isWebSocket(bool flag) {}
	virtual void setProxy(::java::net::Proxy* proxy) {}
	virtual void setSystemHeader($String* name, $String* value) {}
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_WebSocketRequest_h_