#ifndef _jdk_internal_net_http_common_Cancelable_h_
#define _jdk_internal_net_http_common_Cancelable_h_
//$ interface jdk.internal.net.http.common.Cancelable
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $import Cancelable : public ::java::lang::Object {
	$interface(Cancelable, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual bool cancel(bool mayInterruptIfRunning) {return false;}
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_Cancelable_h_