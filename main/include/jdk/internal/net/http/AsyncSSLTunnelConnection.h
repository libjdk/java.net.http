#ifndef _jdk_internal_net_http_AsyncSSLTunnelConnection_h_
#define _jdk_internal_net_http_AsyncSSLTunnelConnection_h_
//$ class jdk.internal.net.http.AsyncSSLTunnelConnection
//$ extends jdk.internal.net.http.AbstractAsyncSSLConnection

#include <java/lang/Array.h>
#include <jdk/internal/net/http/AbstractAsyncSSLConnection.h>

namespace java {
	namespace lang {
		class Throwable;
		class Void;
	}
}
namespace java {
	namespace net {
		class InetSocketAddress;
	}
}
namespace java {
	namespace nio {
		namespace channels {
			class SocketChannel;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class ConnectionPool$CacheKey;
				class Exchange;
				class HttpClientImpl;
				class HttpConnection$HttpPublisher;
				class HttpConnection$PlainHttpPublisher;
				class PlainTunnelingConnection;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class FlowTube;
					class SSLTube;
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

class $import AsyncSSLTunnelConnection : public ::jdk::internal::net::http::AbstractAsyncSSLConnection {
	$class(AsyncSSLTunnelConnection, $NO_CLASS_INIT, ::jdk::internal::net::http::AbstractAsyncSSLConnection)
public:
	AsyncSSLTunnelConnection();
	void init$(::java::net::InetSocketAddress* addr, ::jdk::internal::net::http::HttpClientImpl* client, $StringArray* alpn, ::java::net::InetSocketAddress* proxy, ::jdk::internal::net::http::common::Utils$ProxyHeaders* proxyHeaders);
	virtual ::jdk::internal::net::http::ConnectionPool$CacheKey* cacheKey() override;
	virtual ::java::nio::channels::SocketChannel* channel() override;
	virtual void close() override;
	virtual ::java::util::concurrent::CompletableFuture* connectAsync(::jdk::internal::net::http::Exchange* exchange) override;
	virtual bool connected() override;
	virtual ::java::util::concurrent::CompletableFuture* finishConnect() override;
	virtual ::jdk::internal::net::http::common::FlowTube* getConnectionFlow() override;
	virtual bool isProxied() override;
	virtual bool isTunnel() override;
	::java::lang::Void* lambda$connectAsync$0(::java::lang::Void* unused);
	::java::util::concurrent::CompletableFuture* lambda$finishConnect$1($String* unused, $Throwable* ex);
	virtual ::java::net::InetSocketAddress* proxy() override;
	virtual ::jdk::internal::net::http::HttpConnection$HttpPublisher* publisher() override;
	virtual $String* toString() override;
	::jdk::internal::net::http::PlainTunnelingConnection* plainConnection = nullptr;
	::jdk::internal::net::http::HttpConnection$PlainHttpPublisher* writePublisher = nullptr;
	$volatile(::jdk::internal::net::http::common::SSLTube*) flow = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_AsyncSSLTunnelConnection_h_