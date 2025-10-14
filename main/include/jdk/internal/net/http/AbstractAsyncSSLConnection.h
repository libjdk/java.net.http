#ifndef _jdk_internal_net_http_AbstractAsyncSSLConnection_h_
#define _jdk_internal_net_http_AbstractAsyncSSLConnection_h_
//$ class jdk.internal.net.http.AbstractAsyncSSLConnection
//$ extends jdk.internal.net.http.HttpConnection

#include <java/lang/Array.h>
#include <jdk/internal/net/http/HttpConnection.h>

namespace java {
	namespace net {
		class InetSocketAddress;
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
			class SSLEngine;
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
					class Utils$ServerName;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import AbstractAsyncSSLConnection : public ::jdk::internal::net::http::HttpConnection {
	$class(AbstractAsyncSSLConnection, 0, ::jdk::internal::net::http::HttpConnection)
public:
	AbstractAsyncSSLConnection();
	virtual ::jdk::internal::net::http::common::FlowTube* getConnectionFlow() override {return nullptr;}
	void init$(::java::net::InetSocketAddress* addr, ::jdk::internal::net::http::HttpClientImpl* client, ::jdk::internal::net::http::common::Utils$ServerName* serverName, int32_t port, $StringArray* alpn);
	static bool contains($StringArray* rr, $String* target);
	static ::javax::net::ssl::SSLEngine* createEngine(::javax::net::ssl::SSLContext* context, $String* serverName, int32_t port, ::javax::net::ssl::SSLParameters* sslParameters);
	static ::javax::net::ssl::SSLParameters* createSSLParameters(::jdk::internal::net::http::HttpClientImpl* client, ::jdk::internal::net::http::common::Utils$ServerName* serverName, $StringArray* alpn);
	::java::util::concurrent::CompletableFuture* getALPN();
	::javax::net::ssl::SSLEngine* getEngine();
	virtual bool isSecure() override;
	::javax::net::ssl::SSLEngine* engine = nullptr;
	$String* serverName = nullptr;
	::javax::net::ssl::SSLParameters* sslParameters = nullptr;
	static bool disableHostnameVerification;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_AbstractAsyncSSLConnection_h_