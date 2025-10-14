#ifndef _jdk_internal_net_http_HeaderFilter_h_
#define _jdk_internal_net_http_HeaderFilter_h_
//$ interface jdk.internal.net.http.HeaderFilter
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

class $export HeaderFilter : public ::java::lang::Object {
	$interface(HeaderFilter, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void request(::jdk::internal::net::http::HttpRequestImpl* r, ::jdk::internal::net::http::MultiExchange* e) {}
	virtual ::jdk::internal::net::http::HttpRequestImpl* response(::jdk::internal::net::http::Response* r) {return nullptr;}
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HeaderFilter_h_