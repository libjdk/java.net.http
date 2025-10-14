#ifndef _jdk_internal_net_http_hpack_IntegerReader_h_
#define _jdk_internal_net_http_hpack_IntegerReader_h_
//$ class jdk.internal.net.http.hpack.IntegerReader
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("CONFIGURED")
#undef CONFIGURED
#pragma push_macro("DONE")
#undef DONE
#pragma push_macro("FIRST_BYTE_READ")
#undef FIRST_BYTE_READ
#pragma push_macro("N")
#undef N
#pragma push_macro("NEW")
#undef NEW

namespace java {
	namespace nio {
		class ByteBuffer;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class IntegerReader : public ::java::lang::Object {
	$class(IntegerReader, $NO_CLASS_INIT, ::java::lang::Object)
public:
	IntegerReader();
	void init$();
	static void checkPrefix(int32_t N);
	::jdk::internal::net::http::hpack::IntegerReader* configure(int32_t N);
	::jdk::internal::net::http::hpack::IntegerReader* configure(int32_t N, int32_t maxValue);
	int32_t get();
	bool read(::java::nio::ByteBuffer* input);
	::jdk::internal::net::http::hpack::IntegerReader* reset();
	static const int32_t NEW = 0;
	static const int32_t CONFIGURED = 1;
	static const int32_t FIRST_BYTE_READ = 2;
	static const int32_t DONE = 4;
	int32_t state = 0;
	int32_t N = 0;
	int32_t maxValue = 0;
	int32_t value = 0;
	int64_t r = 0;
	int64_t b = 0;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("CONFIGURED")
#pragma pop_macro("DONE")
#pragma pop_macro("FIRST_BYTE_READ")
#pragma pop_macro("N")
#pragma pop_macro("NEW")

#endif // _jdk_internal_net_http_hpack_IntegerReader_h_