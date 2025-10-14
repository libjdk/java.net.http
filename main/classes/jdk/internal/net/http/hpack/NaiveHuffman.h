#ifndef _jdk_internal_net_http_hpack_NaiveHuffman_h_
#define _jdk_internal_net_http_hpack_NaiveHuffman_h_
//$ class jdk.internal.net.http.hpack.NaiveHuffman
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("EOS")
#undef EOS
#pragma push_macro("INSTANCE")
#undef INSTANCE

namespace java {
	namespace lang {
		class CharSequence;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {
					class NaiveHuffman$Code;
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

class NaiveHuffman : public ::java::lang::Object {
	$class(NaiveHuffman, 0, ::java::lang::Object)
public:
	NaiveHuffman();
	void init$();
	void addChar(int32_t c, int32_t code, int32_t bitLength);
	void addEOS(int32_t c, int32_t code, int32_t bitLength);
	void addLeaf(int32_t c, int32_t code, int32_t bitLength, bool isEOS);
	::jdk::internal::net::http::hpack::NaiveHuffman$Code* codeOf(char16_t c);
	::jdk::internal::net::http::hpack::NaiveHuffman$Node* getRoot();
	int32_t lengthOf(::java::lang::CharSequence* value);
	int32_t lengthOf(::java::lang::CharSequence* value, int32_t start, int32_t end);
	static bool $assertionsDisabled;
	static ::jdk::internal::net::http::hpack::NaiveHuffman* INSTANCE;
	::jdk::internal::net::http::hpack::NaiveHuffman$Code* EOS = nullptr;
	$Array<::jdk::internal::net::http::hpack::NaiveHuffman$Code>* codes = nullptr;
	::jdk::internal::net::http::hpack::NaiveHuffman$Node* root = nullptr;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("EOS")
#pragma pop_macro("INSTANCE")

#endif // _jdk_internal_net_http_hpack_NaiveHuffman_h_