#ifndef _jdk_internal_net_http_hpack_QuickHuffman_h_
#define _jdk_internal_net_http_hpack_QuickHuffman_h_
//$ class jdk.internal.net.http.hpack.QuickHuffman
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("EOS_LENGTH")
#undef EOS_LENGTH
#pragma push_macro("EOS_LSB")
#undef EOS_LSB
#pragma push_macro("EOS_MSB")
#undef EOS_MSB

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {
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

class QuickHuffman : public ::java::lang::Object {
	$class(QuickHuffman, 0, ::java::lang::Object)
public:
	QuickHuffman();
	void init$();
	static void addChar(::jdk::internal::net::http::hpack::QuickHuffman$Node* root, int32_t symbol, int32_t code, int32_t bitLength);
	static void addEOS(::jdk::internal::net::http::hpack::QuickHuffman$Node* root, int32_t symbol, int32_t code, int32_t bitLength);
	static void addLeaf(::jdk::internal::net::http::hpack::QuickHuffman$Node* root, char16_t symbol, int32_t code, int32_t bitLength, bool isEOS);
	static ::jdk::internal::net::http::hpack::QuickHuffman$Node* buildTrie();
	static int64_t codeLengthOf(char16_t c);
	static int64_t codeValueOf(char16_t c);
	static bool $assertionsDisabled;
	static $longs* codes;
	static const int32_t EOS_LENGTH = 30;
	static const int32_t EOS_LSB = 0x3FFFFFFF;
	static const int64_t EOS_MSB = -17179869184; // ((int64_t)EOS_LSB) << (64 - EOS_LENGTH)
	static ::jdk::internal::net::http::hpack::QuickHuffman$Node* root;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("EOS_LENGTH")
#pragma pop_macro("EOS_LSB")
#pragma pop_macro("EOS_MSB")

#endif // _jdk_internal_net_http_hpack_QuickHuffman_h_