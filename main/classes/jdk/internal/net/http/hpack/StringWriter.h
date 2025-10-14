#ifndef _jdk_internal_net_http_hpack_StringWriter_h_
#define _jdk_internal_net_http_hpack_StringWriter_h_
//$ class jdk.internal.net.http.hpack.StringWriter
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("CONFIGURED")
#undef CONFIGURED
#pragma push_macro("DONE")
#undef DONE
#pragma push_macro("LENGTH_WRITTEN")
#undef LENGTH_WRITTEN
#pragma push_macro("NEW")
#undef NEW

namespace java {
	namespace lang {
		class CharSequence;
	}
}
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
					class Huffman$Writer;
					class ISO_8859_1$Writer;
					class IntegerWriter;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class StringWriter : public ::java::lang::Object {
	$class(StringWriter, $NO_CLASS_INIT, ::java::lang::Object)
public:
	StringWriter();
	void init$();
	::jdk::internal::net::http::hpack::StringWriter* configure(::java::lang::CharSequence* input, bool huffman);
	::jdk::internal::net::http::hpack::StringWriter* configure(::java::lang::CharSequence* input, int32_t start, int32_t end, bool huffman);
	void reset();
	bool write(::java::nio::ByteBuffer* output);
	static const int32_t NEW = 0;
	static const int32_t CONFIGURED = 1;
	static const int32_t LENGTH_WRITTEN = 2;
	static const int32_t DONE = 4;
	::jdk::internal::net::http::hpack::IntegerWriter* intWriter = nullptr;
	::jdk::internal::net::http::hpack::Huffman$Writer* huffmanWriter = nullptr;
	::jdk::internal::net::http::hpack::ISO_8859_1$Writer* plainWriter = nullptr;
	int32_t state = 0;
	bool huffman = false;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("CONFIGURED")
#pragma pop_macro("DONE")
#pragma pop_macro("LENGTH_WRITTEN")
#pragma pop_macro("NEW")

#endif // _jdk_internal_net_http_hpack_StringWriter_h_