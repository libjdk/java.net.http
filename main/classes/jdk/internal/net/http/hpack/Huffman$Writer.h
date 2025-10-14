#ifndef _jdk_internal_net_http_hpack_Huffman$Writer_h_
#define _jdk_internal_net_http_hpack_Huffman$Writer_h_
//$ interface jdk.internal.net.http.hpack.Huffman$Writer
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

class Huffman$Writer : public ::java::lang::Object {
	$interface(Huffman$Writer, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::jdk::internal::net::http::hpack::Huffman$Writer* from(::java::lang::CharSequence* input, int32_t start, int32_t end) {return nullptr;}
	virtual int32_t lengthOf(::java::lang::CharSequence* value, int32_t start, int32_t end) {return 0;}
	virtual int32_t lengthOf(::java::lang::CharSequence* value);
	virtual ::jdk::internal::net::http::hpack::Huffman$Writer* reset() {return nullptr;}
	virtual bool write(::java::nio::ByteBuffer* destination) {return false;}
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_Huffman$Writer_h_