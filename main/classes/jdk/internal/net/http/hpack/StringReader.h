#ifndef _jdk_internal_net_http_hpack_StringReader_h_
#define _jdk_internal_net_http_hpack_StringReader_h_
//$ class jdk.internal.net.http.hpack.StringReader
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("DONE")
#undef DONE
#pragma push_macro("FIRST_BYTE_READ")
#undef FIRST_BYTE_READ
#pragma push_macro("LENGTH_READ")
#undef LENGTH_READ
#pragma push_macro("NEW")
#undef NEW

namespace java {
	namespace lang {
		class Appendable;
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
					class Huffman$Reader;
					class ISO_8859_1$Reader;
					class IntegerReader;
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

class StringReader : public ::java::lang::Object {
	$class(StringReader, $NO_CLASS_INIT, ::java::lang::Object)
public:
	StringReader();
	void init$();
	bool isHuffmanEncoded();
	bool read(::java::nio::ByteBuffer* input, ::java::lang::Appendable* output);
	void reset();
	static const int32_t NEW = 0;
	static const int32_t FIRST_BYTE_READ = 1;
	static const int32_t LENGTH_READ = 2;
	static const int32_t DONE = 4;
	::jdk::internal::net::http::hpack::IntegerReader* intReader = nullptr;
	::jdk::internal::net::http::hpack::Huffman$Reader* huffmanReader = nullptr;
	::jdk::internal::net::http::hpack::ISO_8859_1$Reader* plainReader = nullptr;
	int32_t state = 0;
	bool huffman = false;
	int32_t remainingLength = 0;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("DONE")
#pragma pop_macro("FIRST_BYTE_READ")
#pragma pop_macro("LENGTH_READ")
#pragma pop_macro("NEW")

#endif // _jdk_internal_net_http_hpack_StringReader_h_