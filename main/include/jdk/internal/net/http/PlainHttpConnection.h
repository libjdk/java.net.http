#ifndef _jdk_internal_net_http_PlainHttpConnection_h_
#define _jdk_internal_net_http_PlainHttpConnection_h_
//$ class jdk.internal.net.http.PlainHttpConnection
//$ extends jdk.internal.net.http.HttpConnection

#include <jdk/internal/net/http/HttpConnection.h>

namespace java {
	namespace lang {
		class Boolean;
		class Throwable;
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
				class PlainHttpConnection$ConnectState;
				class PlainHttpConnection$ConnectTimerEvent;
				class SocketTube;
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
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import PlainHttpConnection : public ::jdk::internal::net::http::HttpConnection {
	$class(PlainHttpConnection, 0, ::jdk::internal::net::http::HttpConnection)
public:
	PlainHttpConnection();
	void init$(::java::net::InetSocketAddress* addr, ::jdk::internal::net::http::HttpClientImpl* client);
	virtual ::jdk::internal::net::http::ConnectionPool$CacheKey* cacheKey() override;
	bool canRetryConnect($Throwable* e);
	virtual ::java::nio::channels::SocketChannel* channel() override;
	::java::util::concurrent::CompletableFuture* checkRetryConnect(::jdk::internal::net::http::PlainHttpConnection$ConnectState* connect, $Throwable* failed, ::jdk::internal::net::http::Exchange* exchange);
	virtual void close() override;
	virtual ::java::util::concurrent::CompletableFuture* connectAsync(::jdk::internal::net::http::Exchange* exchange) override;
	virtual bool connected() override;
	virtual ::java::util::concurrent::CompletableFuture* finishConnect() override;
	virtual ::jdk::internal::net::http::common::FlowTube* getConnectionFlow() override;
	int32_t getSoReceiveBufferSize();
	int32_t getSoSendBufferSize();
	virtual bool isProxied() override;
	virtual bool isSecure() override;
	::java::lang::Boolean* lambda$connectAsync$0();
	::java::util::concurrent::CompletableFuture* lambda$connectAsync$1(::jdk::internal::net::http::Exchange* exchange, ::jdk::internal::net::http::PlainHttpConnection$ConnectState* r, $Throwable* t);
	::jdk::internal::net::http::PlainHttpConnection$ConnectTimerEvent* newConnectTimer(::jdk::internal::net::http::Exchange* exchange, ::java::util::concurrent::CompletableFuture* cf);
	virtual ::java::net::InetSocketAddress* proxy() override;
	virtual ::jdk::internal::net::http::HttpConnection$HttpPublisher* publisher() override;
	virtual $String* toString() override;
	bool trySetReceiveBufferSize(int32_t bufsize);
	bool trySetSendBufferSize(int32_t bufsize);
	static bool $assertionsDisabled;
	$Object* reading = nullptr;
	::java::nio::channels::SocketChannel* chan = nullptr;
	::jdk::internal::net::http::SocketTube* tube = nullptr;
	::jdk::internal::net::http::HttpConnection$PlainHttpPublisher* writePublisher = nullptr;
	$volatile(bool) connected$ = false;
	bool closed = false;
	$volatile(::jdk::internal::net::http::PlainHttpConnection$ConnectTimerEvent*) connectTimerEvent = nullptr;
	$volatile(int32_t) unsuccessfulAttempts = 0;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_PlainHttpConnection_h_