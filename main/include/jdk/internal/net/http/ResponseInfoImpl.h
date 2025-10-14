#ifndef _jdk_internal_net_http_ResponseInfoImpl_h_
#define _jdk_internal_net_http_ResponseInfoImpl_h_
//$ class jdk.internal.net.http.ResponseInfoImpl
//$ extends java.net.http.HttpResponse$ResponseInfo

#include <java/net/http/HttpResponse$ResponseInfo.h>

namespace java {
	namespace net {
		namespace http {
			class HttpClient$Version;
			class HttpHeaders;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Response;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import ResponseInfoImpl : public ::java::net::http::HttpResponse$ResponseInfo {
	$class(ResponseInfoImpl, $NO_CLASS_INIT, ::java::net::http::HttpResponse$ResponseInfo)
public:
	ResponseInfoImpl();
	void init$(::jdk::internal::net::http::Response* response);
	void init$(int32_t statusCode, ::java::net::http::HttpHeaders* headers, ::java::net::http::HttpClient$Version* version);
	virtual ::java::net::http::HttpHeaders* headers() override;
	virtual int32_t statusCode() override;
	virtual ::java::net::http::HttpClient$Version* version() override;
	int32_t statusCode$ = 0;
	::java::net::http::HttpHeaders* headers$ = nullptr;
	::java::net::http::HttpClient$Version* version$ = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseInfoImpl_h_