#ifndef _jdk_internal_net_http_websocket_Frame$Consumer_h_
#define _jdk_internal_net_http_websocket_Frame$Consumer_h_
//$ interface jdk.internal.net.http.websocket.Frame$Consumer
//$ extends java.lang.Object

#include <java/lang/Object.h>

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
					class Frame$Opcode;
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

class Frame$Consumer : public ::java::lang::Object {
	$interface(Frame$Consumer, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void endFrame() {}
	virtual void fin(bool value) {}
	virtual void mask(bool value) {}
	virtual void maskingKey(int32_t value) {}
	virtual void opcode(::jdk::internal::net::http::websocket::Frame$Opcode* value) {}
	virtual void payloadData(::java::nio::ByteBuffer* data) {}
	virtual void payloadLen(int64_t value) {}
	virtual void rsv1(bool value) {}
	virtual void rsv2(bool value) {}
	virtual void rsv3(bool value) {}
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_Frame$Consumer_h_