#ifndef _jdk_internal_net_http_hpack_Huffman$Reader_h_
#define _jdk_internal_net_http_hpack_Huffman$Reader_h_
//$ interface jdk.internal.net.http.hpack.Huffman$Reader
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

class Huffman$Reader : public ::java::lang::Object {
	$interface(Huffman$Reader, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void read(::java::nio::ByteBuffer* source, ::java::lang::Appendable* destination, bool isLast) {}
	virtual void reset() {}
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_Huffman$Reader_h_