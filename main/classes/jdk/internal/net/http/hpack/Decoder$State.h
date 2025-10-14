#ifndef _jdk_internal_net_http_hpack_Decoder$State_h_
#define _jdk_internal_net_http_hpack_Decoder$State_h_
//$ class jdk.internal.net.http.hpack.Decoder$State
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("INDEXED")
#undef INDEXED
#pragma push_macro("LITERAL")
#undef LITERAL
#pragma push_macro("LITERAL_NEVER_INDEXED")
#undef LITERAL_NEVER_INDEXED
#pragma push_macro("LITERAL_WITH_INDEXING")
#undef LITERAL_WITH_INDEXING
#pragma push_macro("READY")
#undef READY
#pragma push_macro("SIZE_UPDATE")
#undef SIZE_UPDATE

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class Decoder$State : public ::java::lang::Enum {
	$class(Decoder$State, 0, ::java::lang::Enum)
public:
	Decoder$State();
	static $Array<::jdk::internal::net::http::hpack::Decoder$State>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::jdk::internal::net::http::hpack::Decoder$State* valueOf($String* name);
	static $Array<::jdk::internal::net::http::hpack::Decoder$State>* values();
	static ::jdk::internal::net::http::hpack::Decoder$State* READY;
	static ::jdk::internal::net::http::hpack::Decoder$State* INDEXED;
	static ::jdk::internal::net::http::hpack::Decoder$State* LITERAL_NEVER_INDEXED;
	static ::jdk::internal::net::http::hpack::Decoder$State* LITERAL;
	static ::jdk::internal::net::http::hpack::Decoder$State* LITERAL_WITH_INDEXING;
	static ::jdk::internal::net::http::hpack::Decoder$State* SIZE_UPDATE;
	static $Array<::jdk::internal::net::http::hpack::Decoder$State>* $VALUES;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("INDEXED")
#pragma pop_macro("LITERAL")
#pragma pop_macro("LITERAL_NEVER_INDEXED")
#pragma pop_macro("LITERAL_WITH_INDEXING")
#pragma pop_macro("READY")
#pragma pop_macro("SIZE_UPDATE")

#endif // _jdk_internal_net_http_hpack_Decoder$State_h_