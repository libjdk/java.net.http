#ifndef _jdk_internal_net_http_common_ConnectionExpiredException_h_
#define _jdk_internal_net_http_common_ConnectionExpiredException_h_
//$ class jdk.internal.net.http.common.ConnectionExpiredException
//$ extends java.io.IOException

#include <java/io/IOException.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export ConnectionExpiredException : public ::java::io::IOException {
	$class(ConnectionExpiredException, $NO_CLASS_INIT, ::java::io::IOException)
public:
	ConnectionExpiredException();
	void init$($Throwable* cause);
	static const int64_t serialVersionUID = 0;
	ConnectionExpiredException(const ConnectionExpiredException& e);
	virtual void throw$() override;
	inline ConnectionExpiredException* operator ->() {
		return (ConnectionExpiredException*)throwing$;
	}
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_ConnectionExpiredException_h_