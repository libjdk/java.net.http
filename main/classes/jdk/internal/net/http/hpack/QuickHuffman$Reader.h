#ifndef _jdk_internal_net_http_hpack_QuickHuffman$Reader_h_
#define _jdk_internal_net_http_hpack_QuickHuffman$Reader_h_
//$ class jdk.internal.net.http.hpack.QuickHuffman$Reader
//$ extends jdk.internal.net.http.hpack.Huffman$Reader

#include <jdk/internal/net/http/hpack/Huffman$Reader.h>

#pragma push_macro("UPDATER")
#undef UPDATER

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
					class HPACK$BufferUpdateConsumer;
					class QuickHuffman$Node;
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

class QuickHuffman$Reader : public ::jdk::internal::net::http::hpack::Huffman$Reader {
	$class(QuickHuffman$Reader, $NO_CLASS_INIT, ::jdk::internal::net::http::hpack::Huffman$Reader)
public:
	QuickHuffman$Reader();
	void init$();
	void lambda$new$0(int64_t buf, int32_t bufLen);
	virtual void read(::java::nio::ByteBuffer* source, ::java::lang::Appendable* destination, bool isLast) override;
	virtual void reset() override;
	::jdk::internal::net::http::hpack::HPACK$BufferUpdateConsumer* UPDATER = nullptr;
	::jdk::internal::net::http::hpack::QuickHuffman$Node* curr = nullptr;
	int64_t buffer = 0;
	int32_t bufferLen = 0;
	int32_t len = 0;
	bool done = false;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("UPDATER")

#endif // _jdk_internal_net_http_hpack_QuickHuffman$Reader_h_