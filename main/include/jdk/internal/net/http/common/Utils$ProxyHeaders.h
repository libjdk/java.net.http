#ifndef _jdk_internal_net_http_common_Utils$ProxyHeaders_h_
#define _jdk_internal_net_http_common_Utils$ProxyHeaders_h_
//$ class jdk.internal.net.http.common.Utils$ProxyHeaders
//$ extends java.lang.Record

#include <java/lang/Record.h>

namespace java {
	namespace net {
		namespace http {
			class HttpHeaders;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $import Utils$ProxyHeaders : public ::java::lang::Record {
	$class(Utils$ProxyHeaders, $NO_CLASS_INIT, ::java::lang::Record)
public:
	Utils$ProxyHeaders();
	void init$(::java::net::http::HttpHeaders* userHeaders, ::java::net::http::HttpHeaders* systemHeaders);
	virtual bool equals(Object$* o) override;
	virtual int32_t hashCode() override;
	virtual ::java::net::http::HttpHeaders* systemHeaders();
	virtual $String* toString() override;
	virtual ::java::net::http::HttpHeaders* userHeaders();
	::java::net::http::HttpHeaders* userHeaders$ = nullptr;
	::java::net::http::HttpHeaders* systemHeaders$ = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_Utils$ProxyHeaders_h_