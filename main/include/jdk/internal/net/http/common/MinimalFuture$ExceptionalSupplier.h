#ifndef _jdk_internal_net_http_common_MinimalFuture$ExceptionalSupplier_h_
#define _jdk_internal_net_http_common_MinimalFuture$ExceptionalSupplier_h_
//$ interface jdk.internal.net.http.common.MinimalFuture$ExceptionalSupplier
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $import MinimalFuture$ExceptionalSupplier : public ::java::lang::Object {
	$interface(MinimalFuture$ExceptionalSupplier, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual $Object* get() {return nullptr;}
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_MinimalFuture$ExceptionalSupplier_h_