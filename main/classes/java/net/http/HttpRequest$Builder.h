#ifndef _java_net_http_HttpRequest$Builder_h_
#define _java_net_http_HttpRequest$Builder_h_
//$ interface java.net.http.HttpRequest$Builder
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("DELETE")
#undef DELETE
#pragma push_macro("GET")
#undef GET
#pragma push_macro("POST")
#undef POST
#pragma push_macro("PUT")
#undef PUT

namespace java {
	namespace net {
		class URI;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpClient$Version;
			class HttpRequest;
			class HttpRequest$BodyPublisher;
		}
	}
}
namespace java {
	namespace time {
		class Duration;
	}
}

namespace java {
	namespace net {
		namespace http {

class $export HttpRequest$Builder : public ::java::lang::Object {
	$interface(HttpRequest$Builder, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::java::net::http::HttpRequest$Builder* DELETE() {return nullptr;}
	virtual ::java::net::http::HttpRequest$Builder* GET() {return nullptr;}
	virtual ::java::net::http::HttpRequest$Builder* POST(::java::net::http::HttpRequest$BodyPublisher* bodyPublisher) {return nullptr;}
	virtual ::java::net::http::HttpRequest$Builder* PUT(::java::net::http::HttpRequest$BodyPublisher* bodyPublisher) {return nullptr;}
	virtual ::java::net::http::HttpRequest* build() {return nullptr;}
	virtual ::java::net::http::HttpRequest$Builder* copy() {return nullptr;}
	virtual ::java::net::http::HttpRequest$Builder* expectContinue(bool enable) {return nullptr;}
	virtual ::java::net::http::HttpRequest$Builder* header($String* name, $String* value) {return nullptr;}
	virtual ::java::net::http::HttpRequest$Builder* headers($StringArray* headers) {return nullptr;}
	virtual ::java::net::http::HttpRequest$Builder* method($String* method, ::java::net::http::HttpRequest$BodyPublisher* bodyPublisher) {return nullptr;}
	virtual ::java::net::http::HttpRequest$Builder* setHeader($String* name, $String* value) {return nullptr;}
	virtual ::java::net::http::HttpRequest$Builder* timeout(::java::time::Duration* duration) {return nullptr;}
	virtual ::java::net::http::HttpRequest$Builder* uri(::java::net::URI* uri) {return nullptr;}
	virtual ::java::net::http::HttpRequest$Builder* version(::java::net::http::HttpClient$Version* version) {return nullptr;}
};

		} // http
	} // net
} // java

#pragma pop_macro("DELETE")
#pragma pop_macro("GET")
#pragma pop_macro("POST")
#pragma pop_macro("PUT")

#endif // _java_net_http_HttpRequest$Builder_h_