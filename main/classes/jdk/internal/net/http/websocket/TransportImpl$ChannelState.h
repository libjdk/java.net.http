#ifndef _jdk_internal_net_http_websocket_TransportImpl$ChannelState_h_
#define _jdk_internal_net_http_websocket_TransportImpl$ChannelState_h_
//$ class jdk.internal.net.http.websocket.TransportImpl$ChannelState
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("AVAILABLE")
#undef AVAILABLE
#pragma push_macro("CLOSED")
#undef CLOSED
#pragma push_macro("UNREGISTERED")
#undef UNREGISTERED
#pragma push_macro("WAITING")
#undef WAITING

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class TransportImpl$ChannelState : public ::java::lang::Enum {
	$class(TransportImpl$ChannelState, 0, ::java::lang::Enum)
public:
	TransportImpl$ChannelState();
	static $Array<::jdk::internal::net::http::websocket::TransportImpl$ChannelState>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::jdk::internal::net::http::websocket::TransportImpl$ChannelState* valueOf($String* name);
	static $Array<::jdk::internal::net::http::websocket::TransportImpl$ChannelState>* values();
	static ::jdk::internal::net::http::websocket::TransportImpl$ChannelState* UNREGISTERED;
	static ::jdk::internal::net::http::websocket::TransportImpl$ChannelState* AVAILABLE;
	static ::jdk::internal::net::http::websocket::TransportImpl$ChannelState* WAITING;
	static ::jdk::internal::net::http::websocket::TransportImpl$ChannelState* CLOSED;
	static $Array<::jdk::internal::net::http::websocket::TransportImpl$ChannelState>* $VALUES;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("AVAILABLE")
#pragma pop_macro("CLOSED")
#pragma pop_macro("UNREGISTERED")
#pragma pop_macro("WAITING")

#endif // _jdk_internal_net_http_websocket_TransportImpl$ChannelState_h_