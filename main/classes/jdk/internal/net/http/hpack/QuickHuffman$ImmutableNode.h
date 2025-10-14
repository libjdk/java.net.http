#ifndef _jdk_internal_net_http_hpack_QuickHuffman$ImmutableNode_h_
#define _jdk_internal_net_http_hpack_QuickHuffman$ImmutableNode_h_
//$ class jdk.internal.net.http.hpack.QuickHuffman$ImmutableNode
//$ extends jdk.internal.net.http.hpack.QuickHuffman$Node

#include <java/lang/Array.h>
#include <jdk/internal/net/http/hpack/QuickHuffman$Node.h>

namespace java {
	namespace util {
		class List;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class QuickHuffman$ImmutableNode : public ::jdk::internal::net::http::hpack::QuickHuffman$Node {
	$class(QuickHuffman$ImmutableNode, $NO_CLASS_INIT, ::jdk::internal::net::http::hpack::QuickHuffman$Node)
public:
	QuickHuffman$ImmutableNode();
	void init$(char16_t symbol, bool eosPath, int32_t length);
	void init$(bool eosPath, int32_t length, $Array<::jdk::internal::net::http::hpack::QuickHuffman$ImmutableNode>* children);
	static ::jdk::internal::net::http::hpack::QuickHuffman$ImmutableNode* copyOf(::jdk::internal::net::http::hpack::QuickHuffman$Node* node);
	virtual ::jdk::internal::net::http::hpack::QuickHuffman$ImmutableNode* getChild(int32_t index) override;
	virtual $Array<::jdk::internal::net::http::hpack::QuickHuffman$Node>* getChildren() override;
	virtual int32_t getLength() override;
	virtual ::jdk::internal::net::http::hpack::QuickHuffman$ImmutableNode* getOrCreateChild(int32_t index) override;
	virtual char16_t getSymbol() override;
	virtual bool isEOSPath() override;
	virtual bool isLeaf() override;
	virtual void setEOSPath(bool value) override;
	virtual void setLength(int32_t value) override;
	virtual void setSymbol(char16_t symbol) override;
	char16_t symbol = 0;
	bool eosPath = false;
	int32_t length = 0;
	::java::util::List* children = nullptr;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_QuickHuffman$ImmutableNode_h_