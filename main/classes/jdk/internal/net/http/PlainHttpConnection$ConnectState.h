#ifndef _jdk_internal_net_http_PlainHttpConnection$ConnectState_h_
#define _jdk_internal_net_http_PlainHttpConnection$ConnectState_h_
//$ class jdk.internal.net.http.PlainHttpConnection$ConnectState
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("RETRY")
#undef RETRY
#pragma push_macro("SUCCESS")
#undef SUCCESS

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export PlainHttpConnection$ConnectState : public ::java::lang::Enum {
	$class(PlainHttpConnection$ConnectState, 0, ::java::lang::Enum)
public:
	PlainHttpConnection$ConnectState();
	static $Array<::jdk::internal::net::http::PlainHttpConnection$ConnectState>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::jdk::internal::net::http::PlainHttpConnection$ConnectState* valueOf($String* name);
	static $Array<::jdk::internal::net::http::PlainHttpConnection$ConnectState>* values();
	static ::jdk::internal::net::http::PlainHttpConnection$ConnectState* SUCCESS;
	static ::jdk::internal::net::http::PlainHttpConnection$ConnectState* RETRY;
	static $Array<::jdk::internal::net::http::PlainHttpConnection$ConnectState>* $VALUES;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("RETRY")
#pragma pop_macro("SUCCESS")

#endif // _jdk_internal_net_http_PlainHttpConnection$ConnectState_h_