#ifndef _jdk_internal_net_http_RedirectFilter_h_
#define _jdk_internal_net_http_RedirectFilter_h_
//$ class jdk.internal.net.http.RedirectFilter
//$ extends jdk.internal.net.http.HeaderFilter

#include <jdk/internal/net/http/HeaderFilter.h>

#pragma push_macro("DEFAULT_MAX_REDIRECTS")
#undef DEFAULT_MAX_REDIRECTS
#pragma push_macro("HTTP_NOT_MODIFIED")
#undef HTTP_NOT_MODIFIED

namespace java {
	namespace io {
		class UncheckedIOException;
	}
}
namespace java {
	namespace net {
		class URI;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpClient$Redirect;
			class HttpHeaders;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class HttpClientImpl;
				class HttpRequestImpl;
				class MultiExchange;
				class Response;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export RedirectFilter : public ::jdk::internal::net::http::HeaderFilter {
	$class(RedirectFilter, 0, ::jdk::internal::net::http::HeaderFilter)
public:
	RedirectFilter();
	void init$();
	bool canRedirect(::java::net::URI* redir);
	::java::net::URI* getRedirectedURI(::java::net::http::HttpHeaders* headers);
	::jdk::internal::net::http::HttpRequestImpl* handleResponse(::jdk::internal::net::http::Response* r);
	static bool isRedirecting(int32_t statusCode);
	static ::java::io::UncheckedIOException* lambda$getRedirectedURI$0();
	static $String* redirectedMethod(int32_t statusCode, $String* orig);
	virtual void request(::jdk::internal::net::http::HttpRequestImpl* r, ::jdk::internal::net::http::MultiExchange* e) override;
	virtual ::jdk::internal::net::http::HttpRequestImpl* response(::jdk::internal::net::http::Response* r) override;
	::jdk::internal::net::http::HttpRequestImpl* request$ = nullptr;
	::jdk::internal::net::http::HttpClientImpl* client = nullptr;
	::java::net::http::HttpClient$Redirect* policy = nullptr;
	$String* method = nullptr;
	::jdk::internal::net::http::MultiExchange* exchange = nullptr;
	static const int32_t DEFAULT_MAX_REDIRECTS = 5;
	::java::net::URI* uri = nullptr;
	static const int32_t HTTP_NOT_MODIFIED = 304;
	static int32_t max_redirects;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("DEFAULT_MAX_REDIRECTS")
#pragma pop_macro("HTTP_NOT_MODIFIED")

#endif // _jdk_internal_net_http_RedirectFilter_h_