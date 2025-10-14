#ifndef _java_net_http_HttpResponse$ResponseInfo_h_
#define _java_net_http_HttpResponse$ResponseInfo_h_
//$ interface java.net.http.HttpResponse$ResponseInfo
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		namespace http {
			class HttpClient$Version;
			class HttpHeaders;
		}
	}
}

namespace java {
	namespace net {
		namespace http {

class $export HttpResponse$ResponseInfo : public ::java::lang::Object {
	$interface(HttpResponse$ResponseInfo, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::java::net::http::HttpHeaders* headers() {return nullptr;}
	virtual int32_t statusCode() {return 0;}
	virtual ::java::net::http::HttpClient$Version* version() {return nullptr;}
};

		} // http
	} // net
} // java

#endif // _java_net_http_HttpResponse$ResponseInfo_h_