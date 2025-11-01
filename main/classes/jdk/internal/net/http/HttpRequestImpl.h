#ifndef _jdk_internal_net_http_HttpRequestImpl_h_
#define _jdk_internal_net_http_HttpRequestImpl_h_
//$ class jdk.internal.net.http.HttpRequestImpl
//$ extends java.net.http.HttpRequest
//$ implements jdk.internal.net.http.websocket.WebSocketRequest

#include <java/net/http/HttpRequest.h>
#include <jdk/internal/net/http/websocket/WebSocketRequest.h>

#pragma push_macro("USER_AGENT")
#undef USER_AGENT

namespace java {
	namespace io {
		class IOException;
	}
}
namespace java {
	namespace net {
		class InetSocketAddress;
		class Proxy;
		class ProxySelector;
		class URI;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpHeaders;
			class HttpRequest$BodyPublisher;
		}
	}
}
namespace java {
	namespace security {
		class AccessControlContext;
	}
}
namespace java {
	namespace time {
		class Duration;
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
				class Http2ClientImpl;
				class HttpRequestBuilderImpl;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class HttpHeadersBuilder;
					class Utils$ProxyHeaders;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export HttpRequestImpl : public ::java::net::http::HttpRequest, public ::jdk::internal::net::http::websocket::WebSocketRequest {
	$class(HttpRequestImpl, 0, ::java::net::http::HttpRequest, ::jdk::internal::net::http::websocket::WebSocketRequest)
public:
	HttpRequestImpl();
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::jdk::internal::net::http::HttpRequestBuilderImpl* builder);
	void init$(::java::net::http::HttpRequest* request, ::java::net::ProxySelector* ps);
	void init$(::java::net::URI* uri, $String* method, ::jdk::internal::net::http::HttpRequestImpl* other, bool mayHaveBody);
	void init$($String* method, ::java::net::InetSocketAddress* authority, ::jdk::internal::net::http::common::Utils$ProxyHeaders* headers);
	void init$(::jdk::internal::net::http::HttpRequestImpl* parent, ::java::net::http::HttpHeaders* headers);
	virtual void addSystemHeader($String* name, $String* value);
	virtual ::java::net::InetSocketAddress* authority();
	virtual ::java::util::Optional* bodyPublisher() override;
	static void checkTimeout(::java::time::Duration* duration);
	static ::jdk::internal::net::http::HttpRequestImpl* createPushRequest(::jdk::internal::net::http::HttpRequestImpl* parent, ::java::net::http::HttpHeaders* headers);
	virtual bool expectContinue() override;
	virtual ::java::net::InetSocketAddress* getAddress();
	virtual ::jdk::internal::net::http::common::HttpHeadersBuilder* getSystemHeadersBuilder();
	virtual ::java::net::http::HttpHeaders* getUserHeaders();
	virtual ::java::net::http::HttpHeaders* headers() override;
	bool isConnect();
	virtual void isWebSocket(bool is) override;
	virtual bool isWebSocket();
	static ::java::net::InetSocketAddress* lambda$getAddress$5($String* host, int32_t port);
	static ::java::io::IOException* lambda$new$1();
	static ::java::io::IOException* lambda$new$2();
	static ::java::io::IOException* lambda$new$3();
	static ::java::io::IOException* lambda$new$4();
	static $String* lambda$userAgent$0();
	virtual $String* method() override;
	static ::jdk::internal::net::http::HttpRequestImpl* newInstanceForAuthentication(::jdk::internal::net::http::HttpRequestImpl* other);
	static ::jdk::internal::net::http::HttpRequestImpl* newInstanceForRedirection(::java::net::URI* uri, $String* method, ::jdk::internal::net::http::HttpRequestImpl* other, bool mayHaveBody);
	virtual ::java::net::InetSocketAddress* proxy();
	::java::net::http::HttpRequest$BodyPublisher* publisher(::jdk::internal::net::http::HttpRequestImpl* other);
	static ::java::net::Proxy* retrieveProxy(::java::net::ProxySelector* ps, ::java::net::URI* uri);
	virtual bool secure();
	virtual void setH2Upgrade(::jdk::internal::net::http::Http2ClientImpl* h2client);
	virtual void setProxy(::java::net::Proxy* proxy) override;
	virtual void setSystemHeader($String* name, $String* value) override;
	virtual ::java::util::Optional* timeout() override;
	virtual $String* toString() override;
	virtual ::java::net::URI* uri() override;
	static $String* userAgent();
	virtual ::java::util::Optional* version() override;
	static bool $assertionsDisabled;
	::java::net::http::HttpHeaders* userHeaders = nullptr;
	::jdk::internal::net::http::common::HttpHeadersBuilder* systemHeadersBuilder = nullptr;
	::java::net::URI* uri$ = nullptr;
	$volatile(::java::net::Proxy*) proxy$ = nullptr;
	::java::net::InetSocketAddress* authority$ = nullptr;
	$String* method$ = nullptr;
	::java::net::http::HttpRequest$BodyPublisher* requestPublisher = nullptr;
	bool secure$ = false;
	bool expectContinue$ = false;
	$volatile(bool) isWebSocket$ = false;
	$volatile(::java::security::AccessControlContext*) acc = nullptr;
	::java::time::Duration* timeout$ = nullptr;
	::java::util::Optional* version$ = nullptr;
	static $String* USER_AGENT;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("USER_AGENT")

#endif // _jdk_internal_net_http_HttpRequestImpl_h_