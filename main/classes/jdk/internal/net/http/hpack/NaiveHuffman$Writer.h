#ifndef _jdk_internal_net_http_hpack_NaiveHuffman$Writer_h_
#define _jdk_internal_net_http_hpack_NaiveHuffman$Writer_h_
//$ class jdk.internal.net.http.hpack.NaiveHuffman$Writer
//$ extends jdk.internal.net.http.hpack.Huffman$Writer

#include <jdk/internal/net/http/hpack/Huffman$Writer.h>

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

class NaiveHuffman$Writer : public ::jdk::internal::net::http::hpack::Huffman$Writer {
	$class(NaiveHuffman$Writer, $NO_CLASS_INIT, ::jdk::internal::net::http::hpack::Huffman$Writer)
public:
	NaiveHuffman$Writer();
	void init$();
	virtual ::jdk::internal::net::http::hpack::NaiveHuffman$Writer* from(::java::lang::CharSequence* input, int32_t start, int32_t end) override;
	using ::jdk::internal::net::http::hpack::Huffman$Writer::lengthOf;
	virtual int32_t lengthOf(::java::lang::CharSequence* value, int32_t start, int32_t end) override;
	virtual ::jdk::internal::net::http::hpack::NaiveHuffman$Writer* reset() override;
	virtual bool write(::java::nio::ByteBuffer* destination) override;
	int32_t pos = 0;
	int32_t avail = 0;
	int32_t curr = 0;
	int32_t rem = 0;
	int32_t code = 0;
	::java::lang::CharSequence* source = nullptr;
	int32_t end = 0;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_NaiveHuffman$Writer_h_