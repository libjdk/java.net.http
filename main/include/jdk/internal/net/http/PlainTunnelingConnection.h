#ifndef _jdk_internal_net_http_PlainTunnelingConnection_h_
#define _jdk_internal_net_http_PlainTunnelingConnection_h_
//$ class jdk.internal.net.http.PlainTunnelingConnection
//$ extends jdk.internal.net.http.HttpConnection

#include <jdk/internal/net/http/HttpConnection.h>

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
			class CompletionStage;
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
				class PlainHttpConnection;
				class Response;
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

class $import PlainTunnelingConnection : public ::jdk::internal::net::http::HttpConnection {
	$class(PlainTunnelingConnection, 0, ::jdk::internal::net::http::HttpConnection)
public:
	PlainTunnelingConnection();
	void init$(::java::net::InetSocketAddress* addr, ::java::net::InetSocketAddress* proxy, ::jdk::internal::net::http::HttpClientImpl* client, ::jdk::internal::net::http::common::Utils$ProxyHeaders* proxyHeaders);
	virtual ::jdk::internal::net::http::ConnectionPool$CacheKey* cacheKey() override;
	virtual ::java::nio::channels::SocketChannel* channel() override;
	virtual void close() override;
	virtual ::java::util::concurrent::CompletableFuture* connectAsync(::jdk::internal::net::http::Exchange* exchange) override;
	virtual bool connected() override;
	virtual ::java::util::concurrent::CompletableFuture* finishConnect() override;
	virtual ::jdk::internal::net::http::common::FlowTube* getConnectionFlow() override;
	virtual bool isProxied() override;
	virtual bool isSecure() override;
	virtual bool isTunnel() override;
	::java::util::concurrent::CompletionStage* lambda$connectAsync$0(::java::lang::Void* unused);
	::java::util::concurrent::CompletableFuture* lambda$connectAsync$1(::jdk::internal::net::http::Response* resp, ::java::util::concurrent::CompletableFuture* cf, ::java::lang::Void* r, $Throwable* t);
	::java::util::concurrent::CompletionStage* lambda$connectAsync$2(::jdk::internal::net::http::Exchange* connectExchange, ::jdk::internal::net::http::Response* resp);
	::java::util::concurrent::CompletableFuture* lambda$connectAsync$3(::java::lang::Void* result, $Throwable* ex);
	::java::util::concurrent::CompletionStage* lambda$connectAsync$4(::java::lang::Void* v);
	virtual ::java::net::InetSocketAddress* proxy() override;
	virtual ::jdk::internal::net::http::HttpConnection$HttpPublisher* publisher() override;
	static bool $assertionsDisabled;
	::jdk::internal::net::http::PlainHttpConnection* delegate = nullptr;
	::jdk::internal::net::http::common::Utils$ProxyHeaders* proxyHeaders = nullptr;
	::java::net::InetSocketAddress* proxyAddr = nullptr;
	$volatile(bool) connected$ = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_PlainTunnelingConnection_h_