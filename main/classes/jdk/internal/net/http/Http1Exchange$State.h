#ifndef _jdk_internal_net_http_Http1Exchange$State_h_
#define _jdk_internal_net_http_Http1Exchange$State_h_
//$ class jdk.internal.net.http.Http1Exchange$State
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("BODY")
#undef BODY
#pragma push_macro("COMPLETED")
#undef COMPLETED
#pragma push_macro("COMPLETING")
#undef COMPLETING
#pragma push_macro("ERROR")
#undef ERROR
#pragma push_macro("HEADERS")
#undef HEADERS
#pragma push_macro("INITIAL")
#undef INITIAL

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Http1Exchange$State : public ::java::lang::Enum {
	$class(Http1Exchange$State, 0, ::java::lang::Enum)
public:
	Http1Exchange$State();
	static $Array<::jdk::internal::net::http::Http1Exchange$State>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::jdk::internal::net::http::Http1Exchange$State* valueOf($String* name);
	static $Array<::jdk::internal::net::http::Http1Exchange$State>* values();
	static ::jdk::internal::net::http::Http1Exchange$State* INITIAL;
	static ::jdk::internal::net::http::Http1Exchange$State* HEADERS;
	static ::jdk::internal::net::http::Http1Exchange$State* BODY;
	static ::jdk::internal::net::http::Http1Exchange$State* ERROR;
	static ::jdk::internal::net::http::Http1Exchange$State* COMPLETING;
	static ::jdk::internal::net::http::Http1Exchange$State* COMPLETED;
	static $Array<::jdk::internal::net::http::Http1Exchange$State>* $VALUES;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("BODY")
#pragma pop_macro("COMPLETED")
#pragma pop_macro("COMPLETING")
#pragma pop_macro("ERROR")
#pragma pop_macro("HEADERS")
#pragma pop_macro("INITIAL")

#endif // _jdk_internal_net_http_Http1Exchange$State_h_