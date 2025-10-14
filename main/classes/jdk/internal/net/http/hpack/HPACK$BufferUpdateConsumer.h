#ifndef _jdk_internal_net_http_hpack_HPACK$BufferUpdateConsumer_h_
#define _jdk_internal_net_http_hpack_HPACK$BufferUpdateConsumer_h_
//$ interface jdk.internal.net.http.hpack.HPACK$BufferUpdateConsumer
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class HPACK$BufferUpdateConsumer : public ::java::lang::Object {
	$interface(HPACK$BufferUpdateConsumer, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void accept(int64_t data, int32_t len) {}
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_HPACK$BufferUpdateConsumer_h_