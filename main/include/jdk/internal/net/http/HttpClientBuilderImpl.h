#ifndef _jdk_internal_net_http_HttpClientBuilderImpl_h_
#define _jdk_internal_net_http_HttpClientBuilderImpl_h_
//$ class jdk.internal.net.http.HttpClientBuilderImpl
//$ extends java.net.http.HttpClient$Builder

#include <java/net/http/HttpClient$Builder.h>

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

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import HttpClientBuilderImpl : public ::java::net::http::HttpClient$Builder {
	$class(HttpClientBuilderImpl, $NO_CLASS_INIT, ::java::net::http::HttpClient$Builder)
public:
	HttpClientBuilderImpl();
	void init$();
	virtual ::jdk::internal::net::http::HttpClientBuilderImpl* authenticator(::java::net::Authenticator* a) override;
	virtual ::java::net::http::HttpClient* build() override;
	virtual ::jdk::internal::net::http::HttpClientBuilderImpl* connectTimeout(::java::time::Duration* duration) override;
	virtual ::jdk::internal::net::http::HttpClientBuilderImpl* cookieHandler(::java::net::CookieHandler* cookieHandler) override;
	virtual ::jdk::internal::net::http::HttpClientBuilderImpl* executor(::java::util::concurrent::Executor* s) override;
	virtual ::jdk::internal::net::http::HttpClientBuilderImpl* followRedirects(::java::net::http::HttpClient$Redirect* policy) override;
	virtual ::jdk::internal::net::http::HttpClientBuilderImpl* priority(int32_t priority) override;
	virtual ::jdk::internal::net::http::HttpClientBuilderImpl* proxy(::java::net::ProxySelector* proxy) override;
	virtual ::jdk::internal::net::http::HttpClientBuilderImpl* sslContext(::javax::net::ssl::SSLContext* sslContext) override;
	virtual ::jdk::internal::net::http::HttpClientBuilderImpl* sslParameters(::javax::net::ssl::SSLParameters* sslParameters) override;
	virtual ::jdk::internal::net::http::HttpClientBuilderImpl* version(::java::net::http::HttpClient$Version* version) override;
	::java::net::CookieHandler* cookieHandler$ = nullptr;
	::java::time::Duration* connectTimeout$ = nullptr;
	::java::net::http::HttpClient$Redirect* followRedirects$ = nullptr;
	::java::net::ProxySelector* proxy$ = nullptr;
	::java::net::Authenticator* authenticator$ = nullptr;
	::java::net::http::HttpClient$Version* version$ = nullptr;
	::java::util::concurrent::Executor* executor$ = nullptr;
	::javax::net::ssl::SSLContext* sslContext$ = nullptr;
	::javax::net::ssl::SSLParameters* sslParams = nullptr;
	int32_t priority$ = 0;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HttpClientBuilderImpl_h_