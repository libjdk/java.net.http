#ifndef _java_net_http_HttpResponse$BodyHandler_h_
#define _java_net_http_HttpResponse$BodyHandler_h_
//$ interface java.net.http.HttpResponse$BodyHandler
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		namespace http {
			class HttpResponse$BodySubscriber;
			class HttpResponse$ResponseInfo;
		}
	}
}

namespace java {
	namespace net {
		namespace http {

class $import HttpResponse$BodyHandler : public ::java::lang::Object {
	$interface(HttpResponse$BodyHandler, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::java::net::http::HttpResponse$BodySubscriber* apply(::java::net::http::HttpResponse$ResponseInfo* responseInfo) {return nullptr;}
};

		} // http
	} // net
} // java

#endif // _java_net_http_HttpResponse$BodyHandler_h_