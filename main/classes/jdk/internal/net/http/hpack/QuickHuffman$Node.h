#ifndef _jdk_internal_net_http_hpack_QuickHuffman$Node_h_
#define _jdk_internal_net_http_hpack_QuickHuffman$Node_h_
//$ interface jdk.internal.net.http.hpack.QuickHuffman$Node
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class QuickHuffman$Node : public ::java::lang::Object {
	$interface(QuickHuffman$Node, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::jdk::internal::net::http::hpack::QuickHuffman$Node* getChild(int32_t index) {return nullptr;}
	virtual $Array<::jdk::internal::net::http::hpack::QuickHuffman$Node>* getChildren() {return nullptr;}
	virtual int32_t getLength() {return 0;}
	virtual ::jdk::internal::net::http::hpack::QuickHuffman$Node* getOrCreateChild(int32_t index) {return nullptr;}
	virtual char16_t getSymbol() {return 0;}
	virtual bool isEOSPath() {return false;}
	virtual bool isLeaf() {return false;}
	virtual void setEOSPath(bool value) {}
	virtual void setLength(int32_t value) {}
	virtual void setSymbol(char16_t symbol) {}
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_QuickHuffman$Node_h_