#ifndef _jdk_internal_net_http_hpack_DecodingCallback_h_
#define _jdk_internal_net_http_hpack_DecodingCallback_h_
//$ interface jdk.internal.net.http.hpack.DecodingCallback
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

class $import DecodingCallback : public ::java::lang::Object {
	$interface(DecodingCallback, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void onDecoded(::java::lang::CharSequence* name, ::java::lang::CharSequence* value) {}
	virtual void onDecoded(::java::lang::CharSequence* name, ::java::lang::CharSequence* value, bool sensitive);
	virtual void onIndexed(int32_t index, ::java::lang::CharSequence* name, ::java::lang::CharSequence* value);
	virtual void onLiteral(int32_t index, ::java::lang::CharSequence* name, ::java::lang::CharSequence* value, bool valueHuffman);
	virtual void onLiteral(::java::lang::CharSequence* name, bool nameHuffman, ::java::lang::CharSequence* value, bool valueHuffman);
	virtual void onLiteralNeverIndexed(int32_t index, ::java::lang::CharSequence* name, ::java::lang::CharSequence* value, bool valueHuffman);
	virtual void onLiteralNeverIndexed(::java::lang::CharSequence* name, bool nameHuffman, ::java::lang::CharSequence* value, bool valueHuffman);
	virtual void onLiteralWithIndexing(int32_t index, ::java::lang::CharSequence* name, ::java::lang::CharSequence* value, bool valueHuffman);
	virtual void onLiteralWithIndexing(::java::lang::CharSequence* name, bool nameHuffman, ::java::lang::CharSequence* value, bool valueHuffman);
	virtual void onSizeUpdate(int32_t capacity);
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_DecodingCallback_h_