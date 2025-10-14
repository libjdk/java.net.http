#ifndef _jdk_internal_net_http_hpack_NaiveHuffman$Node_h_
#define _jdk_internal_net_http_hpack_NaiveHuffman$Node_h_
//$ class jdk.internal.net.http.hpack.NaiveHuffman$Node
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class NaiveHuffman$Node : public ::java::lang::Object {
	$class(NaiveHuffman$Node, $NO_CLASS_INIT, ::java::lang::Object)
public:
	NaiveHuffman$Node();
	void init$();
	virtual ::jdk::internal::net::http::hpack::NaiveHuffman$Node* addChildIfAbsent(int32_t i);
	virtual char16_t getChar();
	virtual ::jdk::internal::net::http::hpack::NaiveHuffman$Node* getChild(int32_t selector);
	virtual bool isLeaf();
	virtual void setChar(char16_t c);
	virtual $String* toString() override;
	::jdk::internal::net::http::hpack::NaiveHuffman$Node* left = nullptr;
	::jdk::internal::net::http::hpack::NaiveHuffman$Node* right = nullptr;
	bool isEOSPath = false;
	bool charIsSet = false;
	char16_t c = 0;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_NaiveHuffman$Node_h_