#ifndef _jdk_internal_net_http_CookieFilter_h_
#define _jdk_internal_net_http_CookieFilter_h_
//$ class jdk.internal.net.http.CookieFilter
//$ extends jdk.internal.net.http.HeaderFilter

#include <jdk/internal/net/http/HeaderFilter.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
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

class $import CookieFilter : public ::jdk::internal::net::http::HeaderFilter {
	$class(CookieFilter, $NO_CLASS_INIT, ::jdk::internal::net::http::HeaderFilter)
public:
	CookieFilter();
	void init$();
	virtual void request(::jdk::internal::net::http::HttpRequestImpl* r, ::jdk::internal::net::http::MultiExchange* e) override;
	virtual ::jdk::internal::net::http::HttpRequestImpl* response(::jdk::internal::net::http::Response* r) override;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_CookieFilter_h_