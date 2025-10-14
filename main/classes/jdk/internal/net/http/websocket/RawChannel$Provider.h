#ifndef _jdk_internal_net_http_websocket_RawChannel$Provider_h_
#define _jdk_internal_net_http_websocket_RawChannel$Provider_h_
//$ interface jdk.internal.net.http.websocket.RawChannel$Provider
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {
					class RawChannel;
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

class $export RawChannel$Provider : public ::java::lang::Object {
	$interface(RawChannel$Provider, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void closeRawChannel() {}
	virtual ::jdk::internal::net::http::websocket::RawChannel* rawChannel() {return nullptr;}
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_RawChannel$Provider_h_