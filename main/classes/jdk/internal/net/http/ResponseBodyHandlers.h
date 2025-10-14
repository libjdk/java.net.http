#ifndef _jdk_internal_net_http_ResponseBodyHandlers_h_
#define _jdk_internal_net_http_ResponseBodyHandlers_h_
//$ class jdk.internal.net.http.ResponseBodyHandlers
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace nio {
		namespace file {
			class Path;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export ResponseBodyHandlers : public ::java::lang::Object {
	$class(ResponseBodyHandlers, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ResponseBodyHandlers();
	void init$();
	static $String* pathForSecurityCheck(::java::nio::file::Path* path);
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseBodyHandlers_h_