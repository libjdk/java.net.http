#ifndef _java_net_http_HttpClient_h_
#define _java_net_http_HttpClient_h_
//$ class java.net.http.HttpClient
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		namespace http {
			class HttpClient$Builder;
			class HttpClient$Redirect;
			class HttpClient$Version;
			class HttpRequest;
			class HttpResponse;
			class HttpResponse$BodyHandler;
			class HttpResponse$PushPromiseHandler;
			class WebSocket$Builder;
		}
	}
}
namespace java {
	namespace util {
		class Optional;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
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

class $import HttpClient : public ::java::lang::Object {
	$class(HttpClient, $NO_CLASS_INIT, ::java::lang::Object)
public:
	HttpClient();
	void init$();
	virtual ::java::util::Optional* authenticator() {return nullptr;}
	virtual ::java::util::Optional* connectTimeout() {return nullptr;}
	virtual ::java::util::Optional* cookieHandler() {return nullptr;}
	virtual ::java::util::Optional* executor() {return nullptr;}
	virtual ::java::net::http::HttpClient$Redirect* followRedirects() {return nullptr;}
	static ::java::net::http::HttpClient$Builder* newBuilder();
	static ::java::net::http::HttpClient* newHttpClient();
	virtual ::java::net::http::WebSocket$Builder* newWebSocketBuilder();
	virtual ::java::util::Optional* proxy() {return nullptr;}
	virtual ::java::net::http::HttpResponse* send(::java::net::http::HttpRequest* request, ::java::net::http::HttpResponse$BodyHandler* responseBodyHandler) {return nullptr;}
	virtual ::java::util::concurrent::CompletableFuture* sendAsync(::java::net::http::HttpRequest* request, ::java::net::http::HttpResponse$BodyHandler* responseBodyHandler) {return nullptr;}
	virtual ::java::util::concurrent::CompletableFuture* sendAsync(::java::net::http::HttpRequest* request, ::java::net::http::HttpResponse$BodyHandler* responseBodyHandler, ::java::net::http::HttpResponse$PushPromiseHandler* pushPromiseHandler) {return nullptr;}
	virtual ::javax::net::ssl::SSLContext* sslContext() {return nullptr;}
	virtual ::javax::net::ssl::SSLParameters* sslParameters() {return nullptr;}
	virtual ::java::net::http::HttpClient$Version* version() {return nullptr;}
};

		} // http
	} // net
} // java

#endif // _java_net_http_HttpClient_h_