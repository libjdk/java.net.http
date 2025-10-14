#ifndef _java_net_http_HttpResponse_h_
#define _java_net_http_HttpResponse_h_
//$ interface java.net.http.HttpResponse
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		class URI;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpClient$Version;
			class HttpHeaders;
			class HttpRequest;
		}
	}
}
namespace java {
	namespace util {
		class Optional;
	}
}

namespace java {
	namespace net {
		namespace http {

class $export HttpResponse : public ::java::lang::Object {
	$interface(HttpResponse, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual $Object* body() {return nullptr;}
	virtual ::java::net::http::HttpHeaders* headers() {return nullptr;}
	virtual ::java::util::Optional* previousResponse() {return nullptr;}
	virtual ::java::net::http::HttpRequest* request() {return nullptr;}
	virtual ::java::util::Optional* sslSession() {return nullptr;}
	virtual int32_t statusCode() {return 0;}
	virtual ::java::net::URI* uri() {return nullptr;}
	virtual ::java::net::http::HttpClient$Version* version() {return nullptr;}
};

		} // http
	} // net
} // java

#endif // _java_net_http_HttpResponse_h_