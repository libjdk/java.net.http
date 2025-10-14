#ifndef _jdk_internal_net_http_websocket_Frame$Opcode_h_
#define _jdk_internal_net_http_websocket_Frame$Opcode_h_
//$ class jdk.internal.net.http.websocket.Frame$Opcode
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("BINARY")
#undef BINARY
#pragma push_macro("CLOSE")
#undef CLOSE
#pragma push_macro("CONTINUATION")
#undef CONTINUATION
#pragma push_macro("PING")
#undef PING
#pragma push_macro("PONG")
#undef PONG
#pragma push_macro("TEXT")
#undef TEXT

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class Frame$Opcode : public ::java::lang::Enum {
	$class(Frame$Opcode, 0, ::java::lang::Enum)
public:
	Frame$Opcode();
	static $Array<::jdk::internal::net::http::websocket::Frame$Opcode>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal, int32_t code);
	virtual bool isControl();
	static ::jdk::internal::net::http::websocket::Frame$Opcode* ofCode(int32_t code);
	static ::jdk::internal::net::http::websocket::Frame$Opcode* valueOf($String* name);
	static $Array<::jdk::internal::net::http::websocket::Frame$Opcode>* values();
	static ::jdk::internal::net::http::websocket::Frame$Opcode* CONTINUATION;
	static ::jdk::internal::net::http::websocket::Frame$Opcode* TEXT;
	static ::jdk::internal::net::http::websocket::Frame$Opcode* BINARY;
	static ::jdk::internal::net::http::websocket::Frame$Opcode* NON_CONTROL_0x3;
	static ::jdk::internal::net::http::websocket::Frame$Opcode* NON_CONTROL_0x4;
	static ::jdk::internal::net::http::websocket::Frame$Opcode* NON_CONTROL_0x5;
	static ::jdk::internal::net::http::websocket::Frame$Opcode* NON_CONTROL_0x6;
	static ::jdk::internal::net::http::websocket::Frame$Opcode* NON_CONTROL_0x7;
	static ::jdk::internal::net::http::websocket::Frame$Opcode* CLOSE;
	static ::jdk::internal::net::http::websocket::Frame$Opcode* PING;
	static ::jdk::internal::net::http::websocket::Frame$Opcode* PONG;
	static ::jdk::internal::net::http::websocket::Frame$Opcode* CONTROL_0xB;
	static ::jdk::internal::net::http::websocket::Frame$Opcode* CONTROL_0xC;
	static ::jdk::internal::net::http::websocket::Frame$Opcode* CONTROL_0xD;
	static ::jdk::internal::net::http::websocket::Frame$Opcode* CONTROL_0xE;
	static ::jdk::internal::net::http::websocket::Frame$Opcode* CONTROL_0xF;
	static $Array<::jdk::internal::net::http::websocket::Frame$Opcode>* $VALUES;
	static $Array<::jdk::internal::net::http::websocket::Frame$Opcode>* opcodes;
	int8_t code = 0;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("BINARY")
#pragma pop_macro("CLOSE")
#pragma pop_macro("CONTINUATION")
#pragma pop_macro("PING")
#pragma pop_macro("PONG")
#pragma pop_macro("TEXT")

#endif // _jdk_internal_net_http_websocket_Frame$Opcode_h_