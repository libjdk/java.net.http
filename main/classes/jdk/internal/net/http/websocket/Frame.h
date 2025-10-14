#ifndef _jdk_internal_net_http_websocket_Frame_h_
#define _jdk_internal_net_http_websocket_Frame_h_
//$ class jdk.internal.net.http.websocket.Frame
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("MAX_CONTROL_FRAME_PAYLOAD_LENGTH")
#undef MAX_CONTROL_FRAME_PAYLOAD_LENGTH
#pragma push_macro("MAX_HEADER_SIZE_BYTES")
#undef MAX_HEADER_SIZE_BYTES

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class Frame : public ::java::lang::Object {
	$class(Frame, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Frame();
	void init$();
	static const int32_t MAX_HEADER_SIZE_BYTES = 14; // 2 + 8 + 4
	static const int32_t MAX_CONTROL_FRAME_PAYLOAD_LENGTH = 125;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("MAX_CONTROL_FRAME_PAYLOAD_LENGTH")
#pragma pop_macro("MAX_HEADER_SIZE_BYTES")

#endif // _jdk_internal_net_http_websocket_Frame_h_