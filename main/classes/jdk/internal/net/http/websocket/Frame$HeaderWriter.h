#ifndef _jdk_internal_net_http_websocket_Frame$HeaderWriter_h_
#define _jdk_internal_net_http_websocket_Frame$HeaderWriter_h_
//$ class jdk.internal.net.http.websocket.Frame$HeaderWriter
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

class Frame$HeaderWriter : public ::java::lang::Object {
	$class(Frame$HeaderWriter, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Frame$HeaderWriter();
	void init$();
	::jdk::internal::net::http::websocket::Frame$HeaderWriter* fin(bool value);
	::jdk::internal::net::http::websocket::Frame$HeaderWriter* mask(int32_t value);
	::jdk::internal::net::http::websocket::Frame$HeaderWriter* noMask();
	::jdk::internal::net::http::websocket::Frame$HeaderWriter* opcode(::jdk::internal::net::http::websocket::Frame$Opcode* value);
	::jdk::internal::net::http::websocket::Frame$HeaderWriter* payloadLen(int64_t value);
	::jdk::internal::net::http::websocket::Frame$HeaderWriter* rsv1(bool value);
	::jdk::internal::net::http::websocket::Frame$HeaderWriter* rsv2(bool value);
	::jdk::internal::net::http::websocket::Frame$HeaderWriter* rsv3(bool value);
	void write(::java::nio::ByteBuffer* buffer);
	char16_t firstChar = 0;
	int64_t payloadLen$ = 0;
	int32_t maskingKey = 0;
	bool mask$ = false;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_Frame$HeaderWriter_h_