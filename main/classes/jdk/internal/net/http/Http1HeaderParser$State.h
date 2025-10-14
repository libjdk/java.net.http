#ifndef _jdk_internal_net_http_Http1HeaderParser$State_h_
#define _jdk_internal_net_http_Http1HeaderParser$State_h_
//$ class jdk.internal.net.http.Http1HeaderParser$State
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("FINISHED")
#undef FINISHED
#pragma push_macro("HEADER")
#undef HEADER
#pragma push_macro("HEADER_FOUND_CR")
#undef HEADER_FOUND_CR
#pragma push_macro("HEADER_FOUND_CR_LF")
#undef HEADER_FOUND_CR_LF
#pragma push_macro("HEADER_FOUND_CR_LF_CR")
#undef HEADER_FOUND_CR_LF_CR
#pragma push_macro("HEADER_FOUND_LF")
#undef HEADER_FOUND_LF
#pragma push_macro("INITIAL")
#undef INITIAL
#pragma push_macro("STATUS_LINE")
#undef STATUS_LINE
#pragma push_macro("STATUS_LINE_END")
#undef STATUS_LINE_END
#pragma push_macro("STATUS_LINE_END_CR")
#undef STATUS_LINE_END_CR
#pragma push_macro("STATUS_LINE_END_LF")
#undef STATUS_LINE_END_LF
#pragma push_macro("STATUS_LINE_FOUND_CR")
#undef STATUS_LINE_FOUND_CR
#pragma push_macro("STATUS_LINE_FOUND_LF")
#undef STATUS_LINE_FOUND_LF

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Http1HeaderParser$State : public ::java::lang::Enum {
	$class(Http1HeaderParser$State, 0, ::java::lang::Enum)
public:
	Http1HeaderParser$State();
	static $Array<::jdk::internal::net::http::Http1HeaderParser$State>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::jdk::internal::net::http::Http1HeaderParser$State* valueOf($String* name);
	static $Array<::jdk::internal::net::http::Http1HeaderParser$State>* values();
	static ::jdk::internal::net::http::Http1HeaderParser$State* INITIAL;
	static ::jdk::internal::net::http::Http1HeaderParser$State* STATUS_LINE;
	static ::jdk::internal::net::http::Http1HeaderParser$State* STATUS_LINE_FOUND_CR;
	static ::jdk::internal::net::http::Http1HeaderParser$State* STATUS_LINE_FOUND_LF;
	static ::jdk::internal::net::http::Http1HeaderParser$State* STATUS_LINE_END;
	static ::jdk::internal::net::http::Http1HeaderParser$State* STATUS_LINE_END_CR;
	static ::jdk::internal::net::http::Http1HeaderParser$State* STATUS_LINE_END_LF;
	static ::jdk::internal::net::http::Http1HeaderParser$State* HEADER;
	static ::jdk::internal::net::http::Http1HeaderParser$State* HEADER_FOUND_CR;
	static ::jdk::internal::net::http::Http1HeaderParser$State* HEADER_FOUND_LF;
	static ::jdk::internal::net::http::Http1HeaderParser$State* HEADER_FOUND_CR_LF;
	static ::jdk::internal::net::http::Http1HeaderParser$State* HEADER_FOUND_CR_LF_CR;
	static ::jdk::internal::net::http::Http1HeaderParser$State* FINISHED;
	static $Array<::jdk::internal::net::http::Http1HeaderParser$State>* $VALUES;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("FINISHED")
#pragma pop_macro("HEADER")
#pragma pop_macro("HEADER_FOUND_CR")
#pragma pop_macro("HEADER_FOUND_CR_LF")
#pragma pop_macro("HEADER_FOUND_CR_LF_CR")
#pragma pop_macro("HEADER_FOUND_LF")
#pragma pop_macro("INITIAL")
#pragma pop_macro("STATUS_LINE")
#pragma pop_macro("STATUS_LINE_END")
#pragma pop_macro("STATUS_LINE_END_CR")
#pragma pop_macro("STATUS_LINE_END_LF")
#pragma pop_macro("STATUS_LINE_FOUND_CR")
#pragma pop_macro("STATUS_LINE_FOUND_LF")

#endif // _jdk_internal_net_http_Http1HeaderParser$State_h_