#ifndef _jdk_internal_net_http_hpack_NaiveHuffman$Code_h_
#define _jdk_internal_net_http_hpack_NaiveHuffman$Code_h_
//$ class jdk.internal.net.http.hpack.NaiveHuffman$Code
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class NaiveHuffman$Code : public ::java::lang::Object {
	$class(NaiveHuffman$Code, $NO_CLASS_INIT, ::java::lang::Object)
public:
	NaiveHuffman$Code();
	void init$(int32_t code, int32_t length);
	int32_t getCode();
	int32_t getLength();
	virtual $String* toString() override;
	int32_t code = 0;
	int32_t length = 0;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_NaiveHuffman$Code_h_