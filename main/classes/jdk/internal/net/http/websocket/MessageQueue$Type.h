#ifndef _jdk_internal_net_http_websocket_MessageQueue$Type_h_
#define _jdk_internal_net_http_websocket_MessageQueue$Type_h_
//$ class jdk.internal.net.http.websocket.MessageQueue$Type
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("BINARY")
#undef BINARY
#pragma push_macro("CLOSE")
#undef CLOSE
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

class MessageQueue$Type : public ::java::lang::Enum {
	$class(MessageQueue$Type, 0, ::java::lang::Enum)
public:
	MessageQueue$Type();
	static $Array<::jdk::internal::net::http::websocket::MessageQueue$Type>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::jdk::internal::net::http::websocket::MessageQueue$Type* valueOf($String* name);
	static $Array<::jdk::internal::net::http::websocket::MessageQueue$Type>* values();
	static ::jdk::internal::net::http::websocket::MessageQueue$Type* TEXT;
	static ::jdk::internal::net::http::websocket::MessageQueue$Type* BINARY;
	static ::jdk::internal::net::http::websocket::MessageQueue$Type* PING;
	static ::jdk::internal::net::http::websocket::MessageQueue$Type* PONG;
	static ::jdk::internal::net::http::websocket::MessageQueue$Type* CLOSE;
	static $Array<::jdk::internal::net::http::websocket::MessageQueue$Type>* $VALUES;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("BINARY")
#pragma pop_macro("CLOSE")
#pragma pop_macro("PING")
#pragma pop_macro("PONG")
#pragma pop_macro("TEXT")

#endif // _jdk_internal_net_http_websocket_MessageQueue$Type_h_