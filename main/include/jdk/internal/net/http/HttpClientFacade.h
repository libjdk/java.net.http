#ifndef _jdk_internal_net_http_HttpClientFacade_h_
#define _jdk_internal_net_http_HttpClientFacade_h_
//$ class jdk.internal.net.http.HttpClientFacade
//$ extends java.net.http.HttpClient
//$ implements jdk.internal.net.http.common.OperationTrackers$Trackable

#include <java/net/http/HttpClient.h>
#include <jdk/internal/net/http/common/OperationTrackers$Trackable.h>

namespace java {
	namespace net {
		namespace http {
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
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class HttpClientImpl;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class OperationTrackers$Tracker;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import HttpClientFacade : public ::java::net::http::HttpClient, public ::jdk::internal::net::http::common::OperationTrackers$Trackable {
	$class(HttpClientFacade, $NO_CLASS_INIT, ::java::net::http::HttpClient, ::jdk::internal::net::http::common::OperationTrackers$Trackable)
public:
	HttpClientFacade();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::jdk::internal::net::http::HttpClientImpl* impl);
	virtual ::java::util::Optional* authenticator() override;
	virtual ::java::util::Optional* connectTimeout() override;
	virtual ::java::util::Optional* cookieHandler() override;
	virtual ::java::util::Optional* executor() override;
	virtual ::java::net::http::HttpClient$Redirect* followRedirects() override;
	virtual ::jdk::internal::net::http::common::OperationTrackers$Tracker* getOperationsTracker() override;
	virtual ::java::net::http::WebSocket$Builder* newWebSocketBuilder() override;
	virtual ::java::util::Optional* proxy() override;
	virtual ::java::net::http::HttpResponse* send(::java::net::http::HttpRequest* req, ::java::net::http::HttpResponse$BodyHandler* responseBodyHandler) override;
	virtual ::java::util::concurrent::CompletableFuture* sendAsync(::java::net::http::HttpRequest* req, ::java::net::http::HttpResponse$BodyHandler* responseBodyHandler) override;
	virtual ::java::util::concurrent::CompletableFuture* sendAsync(::java::net::http::HttpRequest* req, ::java::net::http::HttpResponse$BodyHandler* responseBodyHandler, ::java::net::http::HttpResponse$PushPromiseHandler* pushPromiseHandler) override;
	virtual ::javax::net::ssl::SSLContext* sslContext() override;
	virtual ::javax::net::ssl::SSLParameters* sslParameters() override;
	virtual $String* toString() override;
	virtual ::java::net::http::HttpClient$Version* version() override;
	::jdk::internal::net::http::HttpClientImpl* impl = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HttpClientFacade_h_