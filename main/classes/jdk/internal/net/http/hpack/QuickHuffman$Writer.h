#ifndef _jdk_internal_net_http_hpack_QuickHuffman$Writer_h_
#define _jdk_internal_net_http_hpack_QuickHuffman$Writer_h_
//$ class jdk.internal.net.http.hpack.QuickHuffman$Writer
//$ extends jdk.internal.net.http.hpack.Huffman$Writer

#include <jdk/internal/net/http/hpack/Huffman$Writer.h>

#pragma push_macro("UPDATER")
#undef UPDATER

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
					class HPACK$BufferUpdateConsumer;
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

class QuickHuffman$Writer : public ::jdk::internal::net::http::hpack::Huffman$Writer {
	$class(QuickHuffman$Writer, $NO_CLASS_INIT, ::jdk::internal::net::http::hpack::Huffman$Writer)
public:
	QuickHuffman$Writer();
	void init$();
	virtual ::jdk::internal::net::http::hpack::QuickHuffman$Writer* from(::java::lang::CharSequence* input, int32_t start, int32_t end) override;
	void lambda$new$0(int64_t buf, int32_t bufLen);
	using ::jdk::internal::net::http::hpack::Huffman$Writer::lengthOf;
	virtual int32_t lengthOf(::java::lang::CharSequence* value, int32_t start, int32_t end) override;
	virtual ::jdk::internal::net::http::hpack::QuickHuffman$Writer* reset() override;
	virtual bool write(::java::nio::ByteBuffer* destination) override;
	::jdk::internal::net::http::hpack::HPACK$BufferUpdateConsumer* UPDATER = nullptr;
	::java::lang::CharSequence* source = nullptr;
	bool padded = false;
	int32_t pos = 0;
	int32_t end = 0;
	int64_t buffer = 0;
	int32_t bufferLen = 0;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("UPDATER")

#endif // _jdk_internal_net_http_hpack_QuickHuffman$Writer_h_