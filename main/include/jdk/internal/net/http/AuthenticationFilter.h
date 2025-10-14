#ifndef _jdk_internal_net_http_AuthenticationFilter_h_
#define _jdk_internal_net_http_AuthenticationFilter_h_
//$ class jdk.internal.net.http.AuthenticationFilter
//$ extends jdk.internal.net.http.HeaderFilter

#include <jdk/internal/net/http/HeaderFilter.h>

#pragma push_macro("BASIC_DUMMY")
#undef BASIC_DUMMY
#pragma push_macro("DEFAULT_RETRY_LIMIT")
#undef DEFAULT_RETRY_LIMIT
#pragma push_macro("PROXY_UNAUTHORIZED")
#undef PROXY_UNAUTHORIZED
#pragma push_macro("UNAUTHORIZED")
#undef UNAUTHORIZED

namespace java {
	namespace io {
		class IOException;
	}
}
namespace java {
	namespace net {
		class PasswordAuthentication;
		class URI;
		class URL;
	}
}
namespace java {
	namespace util {
		class Base64$Encoder;
		class WeakHashMap;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class AuthenticationFilter$Cache;
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

class $import AuthenticationFilter : public ::jdk::internal::net::http::HeaderFilter {
	$class(AuthenticationFilter, 0, ::jdk::internal::net::http::HeaderFilter)
public:
	AuthenticationFilter();
	void init$();
	static void addBasicCredentials(::jdk::internal::net::http::HttpRequestImpl* r, bool proxy, ::java::net::PasswordAuthentication* pw, bool isUTF8);
	static ::jdk::internal::net::http::AuthenticationFilter$Cache* getCache(::jdk::internal::net::http::MultiExchange* exchange);
	::java::net::PasswordAuthentication* getCredentials($String* header, bool proxy, ::jdk::internal::net::http::HttpRequestImpl* req);
	::java::net::URI* getProxyURI(::jdk::internal::net::http::HttpRequestImpl* r);
	static ::java::io::IOException* lambda$getCredentials$0();
	static ::java::net::URI* normalize(::java::net::URI* uri, bool isPrimaryKey);
	virtual void request(::jdk::internal::net::http::HttpRequestImpl* r, ::jdk::internal::net::http::MultiExchange* e) override;
	virtual ::jdk::internal::net::http::HttpRequestImpl* response(::jdk::internal::net::http::Response* r) override;
	::java::net::URL* toURL(::java::net::URI* uri, $String* method, bool proxy);
	$volatile(::jdk::internal::net::http::MultiExchange*) exchange = nullptr;
	static ::java::util::Base64$Encoder* encoder;
	static const int32_t DEFAULT_RETRY_LIMIT = 3;
	static int32_t retry_limit;
	static const int32_t UNAUTHORIZED = 401;
	static const int32_t PROXY_UNAUTHORIZED = 407;
	static $String* BASIC_DUMMY;
	static ::java::util::WeakHashMap* caches;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("BASIC_DUMMY")
#pragma pop_macro("DEFAULT_RETRY_LIMIT")
#pragma pop_macro("PROXY_UNAUTHORIZED")
#pragma pop_macro("UNAUTHORIZED")

#endif // _jdk_internal_net_http_AuthenticationFilter_h_