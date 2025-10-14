#ifndef _jdk_internal_net_http_hpack_IntegerWriter_h_
#define _jdk_internal_net_http_hpack_IntegerWriter_h_
//$ class jdk.internal.net.http.hpack.IntegerWriter
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("CONFIGURED")
#undef CONFIGURED
#pragma push_macro("DONE")
#undef DONE
#pragma push_macro("FIRST_BYTE_WRITTEN")
#undef FIRST_BYTE_WRITTEN
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

class IntegerWriter : public ::java::lang::Object {
	$class(IntegerWriter, $NO_CLASS_INIT, ::java::lang::Object)
public:
	IntegerWriter();
	void init$();
	static void checkPrefix(int32_t N);
	::jdk::internal::net::http::hpack::IntegerWriter* configure(int32_t value, int32_t N, int32_t payload);
	::jdk::internal::net::http::hpack::IntegerWriter* reset();
	bool write(::java::nio::ByteBuffer* output);
	static const int32_t NEW = 0;
	static const int32_t CONFIGURED = 1;
	static const int32_t FIRST_BYTE_WRITTEN = 2;
	static const int32_t DONE = 4;
	int32_t state = 0;
	int32_t payload = 0;
	int32_t N = 0;
	int32_t value = 0;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("CONFIGURED")
#pragma pop_macro("DONE")
#pragma pop_macro("FIRST_BYTE_WRITTEN")
#pragma pop_macro("N")
#pragma pop_macro("NEW")

#endif // _jdk_internal_net_http_hpack_IntegerWriter_h_