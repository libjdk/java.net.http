#ifndef _java_net_http_HttpClient$Builder_h_
#define _java_net_http_HttpClient$Builder_h_
//$ interface java.net.http.HttpClient$Builder
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("NO_PROXY")
#undef NO_PROXY

namespace java {
	namespace net {
		class Authenticator;
		class CookieHandler;
		class ProxySelector;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpClient;
			class HttpClient$Redirect;
			class HttpClient$Version;
		}
	}
}
namespace java {
	namespace time {
		class Duration;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class Executor;
		}
	}
}
namespace javax {
	namespace net {
		namespace ssl {
			class SSLContext;
			class SSLParameters;
		}
	}
}

namespace java {
	namespace net {
		namespace http {

class $export HttpClient$Builder : public ::java::lang::Object {
	$interface(HttpClient$Builder, 0, ::java::lang::Object)
public:
	virtual ::java::net::http::HttpClient$Builder* authenticator(::java::net::Authenticator* authenticator) {return nullptr;}
	virtual ::java::net::http::HttpClient* build() {return nullptr;}
	virtual ::java::net::http::HttpClient$Builder* connectTimeout(::java::time::Duration* duration) {return nullptr;}
	virtual ::java::net::http::HttpClient$Builder* cookieHandler(::java::net::CookieHandler* cookieHandler) {return nullptr;}
	virtual ::java::net::http::HttpClient$Builder* executor(::java::util::concurrent::Executor* executor) {return nullptr;}
	virtual ::java::net::http::HttpClient$Builder* followRedirects(::java::net::http::HttpClient$Redirect* policy) {return nullptr;}
	virtual ::java::net::http::HttpClient$Builder* priority(int32_t priority) {return nullptr;}
	virtual ::java::net::http::HttpClient$Builder* proxy(::java::net::ProxySelector* proxySelector) {return nullptr;}
	virtual ::java::net::http::HttpClient$Builder* sslContext(::javax::net::ssl::SSLContext* sslContext) {return nullptr;}
	virtual ::java::net::http::HttpClient$Builder* sslParameters(::javax::net::ssl::SSLParameters* sslParameters) {return nullptr;}
	virtual ::java::net::http::HttpClient$Builder* version(::java::net::http::HttpClient$Version* version) {return nullptr;}
	static ::java::net::ProxySelector* NO_PROXY;
};

		} // http
	} // net
} // java

#pragma pop_macro("NO_PROXY")

#endif // _java_net_http_HttpClient$Builder_h_