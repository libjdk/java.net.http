#ifndef _jdk_internal_net_http_hpack_NaiveHuffman$Reader_h_
#define _jdk_internal_net_http_hpack_NaiveHuffman$Reader_h_
//$ class jdk.internal.net.http.hpack.NaiveHuffman$Reader
//$ extends jdk.internal.net.http.hpack.Huffman$Reader

#include <jdk/internal/net/http/hpack/Huffman$Reader.h>

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
					class NaiveHuffman$Node;
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

class NaiveHuffman$Reader : public ::jdk::internal::net::http::hpack::Huffman$Reader {
	$class(NaiveHuffman$Reader, $NO_CLASS_INIT, ::jdk::internal::net::http::hpack::Huffman$Reader)
public:
	NaiveHuffman$Reader();
	void init$();
	virtual void read(::java::nio::ByteBuffer* source, ::java::lang::Appendable* destination, bool isLast) override;
	void read(::java::nio::ByteBuffer* source, ::java::lang::Appendable* destination, bool reportEOS, bool isLast);
	virtual void reset() override;
	void resetProbe();
	::jdk::internal::net::http::hpack::NaiveHuffman$Node* curr = nullptr;
	int32_t len = 0;
	int32_t p = 0;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_NaiveHuffman$Reader_h_