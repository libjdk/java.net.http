#ifndef _jdk_internal_net_http_common_SSLFlowDelegate$Monitorable_h_
#define _jdk_internal_net_http_common_SSLFlowDelegate$Monitorable_h_
//$ interface jdk.internal.net.http.common.SSLFlowDelegate$Monitorable
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export SSLFlowDelegate$Monitorable : public ::java::lang::Object {
	$interface(SSLFlowDelegate$Monitorable, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual $String* getInfo() {return nullptr;}
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SSLFlowDelegate$Monitorable_h_