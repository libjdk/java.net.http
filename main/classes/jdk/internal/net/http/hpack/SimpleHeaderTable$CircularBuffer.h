#ifndef _jdk_internal_net_http_hpack_SimpleHeaderTable$CircularBuffer_h_
#define _jdk_internal_net_http_hpack_SimpleHeaderTable$CircularBuffer_h_
//$ class jdk.internal.net.http.hpack.SimpleHeaderTable$CircularBuffer
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class SimpleHeaderTable$CircularBuffer : public ::java::lang::Object {
	$class(SimpleHeaderTable$CircularBuffer, $NO_CLASS_INIT, ::java::lang::Object)
public:
	SimpleHeaderTable$CircularBuffer();
	void init$(int32_t capacity);
	void add(Object$* elem);
	$Object* get(int32_t index);
	$Object* remove();
	void resize(int32_t newCapacity);
	int32_t tail = 0;
	int32_t head = 0;
	int32_t size = 0;
	int32_t capacity = 0;
	$ObjectArray* elements = nullptr;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_SimpleHeaderTable$CircularBuffer_h_