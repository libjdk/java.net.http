#ifndef _jdk_internal_net_http_Http1Response$State_h_
#define _jdk_internal_net_http_Http1Response$State_h_
//$ class jdk.internal.net.http.Http1Response$State
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("DONE")
#undef DONE
#pragma push_macro("INITIAL")
#undef INITIAL
#pragma push_macro("READING_BODY")
#undef READING_BODY
#pragma push_macro("READING_HEADERS")
#undef READING_HEADERS

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Http1Response$State : public ::java::lang::Enum {
	$class(Http1Response$State, 0, ::java::lang::Enum)
public:
	Http1Response$State();
	static $Array<::jdk::internal::net::http::Http1Response$State>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::jdk::internal::net::http::Http1Response$State* valueOf($String* name);
	static $Array<::jdk::internal::net::http::Http1Response$State>* values();
	static ::jdk::internal::net::http::Http1Response$State* INITIAL;
	static ::jdk::internal::net::http::Http1Response$State* READING_HEADERS;
	static ::jdk::internal::net::http::Http1Response$State* READING_BODY;
	static ::jdk::internal::net::http::Http1Response$State* DONE;
	static $Array<::jdk::internal::net::http::Http1Response$State>* $VALUES;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("DONE")
#pragma pop_macro("INITIAL")
#pragma pop_macro("READING_BODY")
#pragma pop_macro("READING_HEADERS")

#endif // _jdk_internal_net_http_Http1Response$State_h_