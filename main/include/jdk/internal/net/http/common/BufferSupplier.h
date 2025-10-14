#ifndef _jdk_internal_net_http_common_BufferSupplier_h_
#define _jdk_internal_net_http_common_BufferSupplier_h_
//$ interface jdk.internal.net.http.common.BufferSupplier
//$ extends java.util.function.Supplier

#include <java/util/function/Supplier.h>

namespace java {
	namespace nio {
		class ByteBuffer;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $import BufferSupplier : public ::java::util::function::Supplier {
	$interface(BufferSupplier, $NO_CLASS_INIT, ::java::util::function::Supplier)
public:
	virtual $Object* get() override {return nullptr;}
	virtual void recycle(::java::nio::ByteBuffer* buffer) {}
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_BufferSupplier_h_