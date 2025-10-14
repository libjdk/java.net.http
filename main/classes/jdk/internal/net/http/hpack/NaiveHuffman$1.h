#ifndef _jdk_internal_net_http_hpack_NaiveHuffman$1_h_
#define _jdk_internal_net_http_hpack_NaiveHuffman$1_h_
//$ class jdk.internal.net.http.hpack.NaiveHuffman$1
//$ extends jdk.internal.net.http.hpack.NaiveHuffman$Node

#include <jdk/internal/net/http/hpack/NaiveHuffman$Node.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {
					class NaiveHuffman;
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

class NaiveHuffman$1 : public ::jdk::internal::net::http::hpack::NaiveHuffman$Node {
	$class(NaiveHuffman$1, $NO_CLASS_INIT, ::jdk::internal::net::http::hpack::NaiveHuffman$Node)
public:
	NaiveHuffman$1();
	void init$(::jdk::internal::net::http::hpack::NaiveHuffman* this$0);
	virtual $String* toString() override;
	::jdk::internal::net::http::hpack::NaiveHuffman* this$0 = nullptr;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_NaiveHuffman$1_h_