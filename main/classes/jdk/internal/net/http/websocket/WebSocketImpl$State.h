#ifndef _jdk_internal_net_http_websocket_WebSocketImpl$State_h_
#define _jdk_internal_net_http_websocket_WebSocketImpl$State_h_
//$ class jdk.internal.net.http.websocket.WebSocketImpl$State
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("BINARY")
#undef BINARY
#pragma push_macro("CLOSE")
#undef CLOSE
#pragma push_macro("ERROR")
#undef ERROR
#pragma push_macro("IDLE")
#undef IDLE
#pragma push_macro("OPEN")
#undef OPEN
#pragma push_macro("PING")
#undef PING
#pragma push_macro("PONG")
#undef PONG
#pragma push_macro("TEXT")
#undef TEXT
#pragma push_macro("WAITING")
#undef WAITING

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class WebSocketImpl$State : public ::java::lang::Enum {
	$class(WebSocketImpl$State, 0, ::java::lang::Enum)
public:
	WebSocketImpl$State();
	static $Array<::jdk::internal::net::http::websocket::WebSocketImpl$State>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::jdk::internal::net::http::websocket::WebSocketImpl$State* valueOf($String* name);
	static $Array<::jdk::internal::net::http::websocket::WebSocketImpl$State>* values();
	static ::jdk::internal::net::http::websocket::WebSocketImpl$State* OPEN;
	static ::jdk::internal::net::http::websocket::WebSocketImpl$State* IDLE;
	static ::jdk::internal::net::http::websocket::WebSocketImpl$State* WAITING;
	static ::jdk::internal::net::http::websocket::WebSocketImpl$State* TEXT;
	static ::jdk::internal::net::http::websocket::WebSocketImpl$State* BINARY;
	static ::jdk::internal::net::http::websocket::WebSocketImpl$State* PING;
	static ::jdk::internal::net::http::websocket::WebSocketImpl$State* PONG;
	static ::jdk::internal::net::http::websocket::WebSocketImpl$State* CLOSE;
	static ::jdk::internal::net::http::websocket::WebSocketImpl$State* ERROR;
	static $Array<::jdk::internal::net::http::websocket::WebSocketImpl$State>* $VALUES;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("BINARY")
#pragma pop_macro("CLOSE")
#pragma pop_macro("ERROR")
#pragma pop_macro("IDLE")
#pragma pop_macro("OPEN")
#pragma pop_macro("PING")
#pragma pop_macro("PONG")
#pragma pop_macro("TEXT")
#pragma pop_macro("WAITING")

#endif // _jdk_internal_net_http_websocket_WebSocketImpl$State_h_