#ifndef _jdk_internal_net_http_HttpResponseImpl_h_
#define _jdk_internal_net_http_HttpResponseImpl_h_
//$ class jdk.internal.net.http.HttpResponseImpl
//$ extends java.net.http.HttpResponse
//$ implements jdk.internal.net.http.websocket.RawChannel$Provider

#include <java/net/http/HttpResponse.h>
#include <jdk/internal/net/http/websocket/RawChannel$Provider.h>

namespace java {
	namespace net {
		class URI;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpClient$Version;
			class HttpHeaders;
			class HttpRequest;
		}
	}
}
namespace java {
	namespace util {
		class Optional;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Exchange;
				class HttpResponseImpl$RawChannelProvider;
				class Response;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {
					class RawChannel;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export HttpResponseImpl : public ::java::net::http::HttpResponse, public ::jdk::internal::net::http::websocket::RawChannel$Provider {
	$class(HttpResponseImpl, $NO_CLASS_INIT, ::java::net::http::HttpResponse, ::jdk::internal::net::http::websocket::RawChannel$Provider)
public:
	HttpResponseImpl();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::java::net::http::HttpRequest* initialRequest, ::jdk::internal::net::http::Response* response, ::java::net::http::HttpResponse* previousResponse, Object$* body, ::jdk::internal::net::http::Exchange* exch);
	virtual $Object* body() override;
	virtual void closeRawChannel() override;
	virtual ::java::net::http::HttpHeaders* headers() override;
	virtual ::java::util::Optional* previousResponse() override;
	virtual ::jdk::internal::net::http::websocket::RawChannel* rawChannel() override;
	virtual ::java::net::http::HttpRequest* request() override;
	virtual ::java::util::Optional* sslSession() override;
	virtual int32_t statusCode() override;
	virtual $String* toString() override;
	virtual ::java::net::URI* uri() override;
	virtual ::java::net::http::HttpClient$Version* version() override;
	int32_t responseCode = 0;
	::java::net::http::HttpRequest* initialRequest = nullptr;
	::java::util::Optional* previousResponse$ = nullptr;
	::java::net::http::HttpHeaders* headers$ = nullptr;
	::java::util::Optional* sslSession$ = nullptr;
	::java::net::URI* uri$ = nullptr;
	::java::net::http::HttpClient$Version* version$ = nullptr;
	::jdk::internal::net::http::HttpResponseImpl$RawChannelProvider* rawChannelProvider = nullptr;
	$Object* body$ = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HttpResponseImpl_h_