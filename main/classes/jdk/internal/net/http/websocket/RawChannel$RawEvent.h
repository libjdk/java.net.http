#ifndef _jdk_internal_net_http_websocket_RawChannel$RawEvent_h_
#define _jdk_internal_net_http_websocket_RawChannel$RawEvent_h_
//$ interface jdk.internal.net.http.websocket.RawChannel$RawEvent
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class RawChannel$RawEvent : public ::java::lang::Object {
	$interface(RawChannel$RawEvent, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void handle() {}
	virtual int32_t interestOps() {return 0;}
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_RawChannel$RawEvent_h_