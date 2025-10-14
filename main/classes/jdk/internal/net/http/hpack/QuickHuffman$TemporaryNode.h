#ifndef _jdk_internal_net_http_hpack_QuickHuffman$TemporaryNode_h_
#define _jdk_internal_net_http_hpack_QuickHuffman$TemporaryNode_h_
//$ class jdk.internal.net.http.hpack.QuickHuffman$TemporaryNode
//$ extends jdk.internal.net.http.hpack.QuickHuffman$Node

#include <java/lang/Array.h>
#include <jdk/internal/net/http/hpack/QuickHuffman$Node.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class QuickHuffman$TemporaryNode : public ::jdk::internal::net::http::hpack::QuickHuffman$Node {
	$class(QuickHuffman$TemporaryNode, $NO_CLASS_INIT, ::jdk::internal::net::http::hpack::QuickHuffman$Node)
public:
	QuickHuffman$TemporaryNode();
	void init$();
	void ensureChildrenExist();
	virtual ::jdk::internal::net::http::hpack::QuickHuffman$TemporaryNode* getChild(int32_t index) override;
	virtual $Array<::jdk::internal::net::http::hpack::QuickHuffman$Node>* getChildren() override;
	virtual int32_t getLength() override;
	virtual ::jdk::internal::net::http::hpack::QuickHuffman$TemporaryNode* getOrCreateChild(int32_t index) override;
	virtual char16_t getSymbol() override;
	virtual bool isEOSPath() override;
	virtual bool isLeaf() override;
	virtual void setEOSPath(bool value) override;
	virtual void setLength(int32_t value) override;
	virtual void setSymbol(char16_t value) override;
	char16_t symbol = 0;
	bool eosPath = false;
	$Array<::jdk::internal::net::http::hpack::QuickHuffman$TemporaryNode>* children = nullptr;
	int32_t length = 0;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_QuickHuffman$TemporaryNode_h_