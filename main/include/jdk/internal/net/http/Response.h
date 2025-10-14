#ifndef _jdk_internal_net_http_Response_h_
#define _jdk_internal_net_http_Response_h_
//$ class jdk.internal.net.http.Response
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		class InetSocketAddress;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpClient$Version;
			class HttpHeaders;
		}
	}
}
namespace javax {
	namespace net {
		namespace ssl {
			class SSLSession;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Exchange;
				class HttpConnection;
				class HttpRequestImpl;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Response : public ::java::lang::Object {
	$class(Response, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Response();
	void init$(::jdk::internal::net::http::HttpRequestImpl* req, ::jdk::internal::net::http::Exchange* exchange, ::java::net::http::HttpHeaders* headers, ::jdk::internal::net::http::HttpConnection* connection, int32_t statusCode, ::java::net::http::HttpClient$Version* version);
	void init$(::jdk::internal::net::http::HttpRequestImpl* req, ::jdk::internal::net::http::Exchange* exchange, ::java::net::http::HttpHeaders* headers, ::jdk::internal::net::http::HttpConnection* connection, int32_t statusCode, ::java::net::http::HttpClient$Version* version, bool isConnectResponse);
	virtual ::javax::net::ssl::SSLSession* getSSLSession();
	virtual ::java::net::http::HttpHeaders* headers();
	virtual ::jdk::internal::net::http::HttpRequestImpl* request();
	virtual int32_t statusCode();
	virtual $String* toString() override;
	virtual ::java::net::http::HttpClient$Version* version();
	::java::net::http::HttpHeaders* headers$ = nullptr;
	int32_t statusCode$ = 0;
	::jdk::internal::net::http::HttpRequestImpl* request$ = nullptr;
	::jdk::internal::net::http::Exchange* exchange = nullptr;
	::java::net::http::HttpClient$Version* version$ = nullptr;
	bool isConnectResponse = false;
	::javax::net::ssl::SSLSession* sslSession = nullptr;
	::java::net::InetSocketAddress* localAddress = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Response_h_