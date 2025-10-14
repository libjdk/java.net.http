#ifndef _jdk_internal_net_http_hpack_HPACK$Logger$Level_h_
#define _jdk_internal_net_http_hpack_HPACK$Logger$Level_h_
//$ class jdk.internal.net.http.hpack.HPACK$Logger$Level
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("EXTRA")
#undef EXTRA
#pragma push_macro("NONE")
#undef NONE
#pragma push_macro("NORMAL")
#undef NORMAL

namespace java {
	namespace lang {
		class System$Logger$Level;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class HPACK$Logger$Level : public ::java::lang::Enum {
	$class(HPACK$Logger$Level, 0, ::java::lang::Enum)
public:
	HPACK$Logger$Level();
	static $Array<::jdk::internal::net::http::hpack::HPACK$Logger$Level>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal, int32_t i, ::java::lang::System$Logger$Level* system);
	bool implies(::jdk::internal::net::http::hpack::HPACK$Logger$Level* other);
	static ::jdk::internal::net::http::hpack::HPACK$Logger$Level* valueOf($String* name);
	static $Array<::jdk::internal::net::http::hpack::HPACK$Logger$Level>* values();
	static ::jdk::internal::net::http::hpack::HPACK$Logger$Level* NONE;
	static ::jdk::internal::net::http::hpack::HPACK$Logger$Level* NORMAL;
	static ::jdk::internal::net::http::hpack::HPACK$Logger$Level* EXTRA;
	static $Array<::jdk::internal::net::http::hpack::HPACK$Logger$Level>* $VALUES;
	int32_t level = 0;
	::java::lang::System$Logger$Level* systemLevel = nullptr;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("EXTRA")
#pragma pop_macro("NONE")
#pragma pop_macro("NORMAL")

#endif // _jdk_internal_net_http_hpack_HPACK$Logger$Level_h_