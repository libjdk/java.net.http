#ifndef _jdk_internal_net_http_HttpConnection_h_
#define _jdk_internal_net_http_HttpConnection_h_
//$ class jdk.internal.net.http.HttpConnection
//$ extends java.io.Closeable

#include <java/io/Closeable.h>
#include <java/lang/Array.h>

#pragma push_macro("DEBUG_LOGGER")
#undef DEBUG_LOGGER

namespace java {
	namespace lang {
		class Boolean;
	}
}
namespace java {
	namespace net {
		class InetSocketAddress;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpClient;
			class HttpClient$Version;
			class HttpHeaders;
		}
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
namespace java {
	namespace util {
		namespace function {
			class BiPredicate;
			class Predicate;
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
				class HttpConnection$TrailingOperations;
				class HttpRequestImpl;
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
					class Logger;
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

class $export HttpConnection : public ::java::io::Closeable {
	$class(HttpConnection, 0, ::java::io::Closeable)
public:
	HttpConnection();
	virtual void close() override {}
	void init$(::java::net::InetSocketAddress* address, ::jdk::internal::net::http::HttpClientImpl* client);
	void addTrailingOperation(::java::util::concurrent::CompletionStage* cf);
	::java::net::InetSocketAddress* address();
	virtual ::jdk::internal::net::http::ConnectionPool$CacheKey* cacheKey() {return nullptr;}
	virtual ::java::nio::channels::SocketChannel* channel() {return nullptr;}
	bool checkOpen();
	::jdk::internal::net::http::HttpClientImpl* client();
	virtual void closeOrReturnToCache(::java::net::http::HttpHeaders* hdrs);
	virtual ::java::util::concurrent::CompletableFuture* connectAsync(::jdk::internal::net::http::Exchange* exchange) {return nullptr;}
	virtual bool connected() {return false;}
	virtual ::java::util::function::BiPredicate* contextRestricted(::jdk::internal::net::http::HttpRequestImpl* request, ::java::net::http::HttpClient* client);
	$String* dbgString();
	virtual ::java::util::concurrent::CompletableFuture* finishConnect() {return nullptr;}
	static ::jdk::internal::net::http::HttpConnection* getConnection(::java::net::InetSocketAddress* addr, ::jdk::internal::net::http::HttpClientImpl* client, ::jdk::internal::net::http::HttpRequestImpl* request, ::java::net::http::HttpClient$Version* version);
	virtual ::jdk::internal::net::http::common::FlowTube* getConnectionFlow() {return nullptr;}
	static ::jdk::internal::net::http::HttpConnection* getPlainConnection(::java::net::InetSocketAddress* addr, ::java::net::InetSocketAddress* proxy, ::jdk::internal::net::http::HttpRequestImpl* request, ::jdk::internal::net::http::HttpClientImpl* client);
	static ::jdk::internal::net::http::HttpConnection* getSSLConnection(::java::net::InetSocketAddress* addr, ::java::net::InetSocketAddress* proxy, $StringArray* alpn, ::jdk::internal::net::http::HttpRequestImpl* request, ::jdk::internal::net::http::HttpClientImpl* client);
	static bool hasRequiredHTTP2TLSVersion(::java::net::http::HttpClient* client);
	virtual ::java::util::function::BiPredicate* headerFilter(::jdk::internal::net::http::HttpRequestImpl* request);
	bool isOpen();
	virtual bool isProxied() {return false;}
	virtual bool isSecure() {return false;}
	virtual bool isTunnel();
	static ::java::lang::Boolean* lambda$closeOrReturnToCache$2($String* s);
	static $String* lambda$static$0();
	static bool lambda$static$1($String* proto);
	virtual ::java::net::InetSocketAddress* proxy() {return nullptr;}
	static ::jdk::internal::net::http::common::Utils$ProxyHeaders* proxyTunnelHeaders(::jdk::internal::net::http::HttpRequestImpl* request);
	virtual ::jdk::internal::net::http::HttpConnection$HttpPublisher* publisher() {return nullptr;}
	virtual $String* toString() override;
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	static ::jdk::internal::net::http::common::Logger* DEBUG_LOGGER;
	::java::net::InetSocketAddress* address$ = nullptr;
	::jdk::internal::net::http::HttpClientImpl* client$ = nullptr;
	::jdk::internal::net::http::HttpConnection$TrailingOperations* trailingOperations = nullptr;
	static ::java::util::function::Predicate* testRequiredHTTP2TLSVersion;
	$String* dbgTag = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("DEBUG_LOGGER")

#endif // _jdk_internal_net_http_HttpConnection_h_