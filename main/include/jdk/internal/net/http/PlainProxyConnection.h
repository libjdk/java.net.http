#ifndef _jdk_internal_net_http_PlainProxyConnection_h_
#define _jdk_internal_net_http_PlainProxyConnection_h_
//$ class jdk.internal.net.http.PlainProxyConnection
//$ extends jdk.internal.net.http.PlainHttpConnection

#include <jdk/internal/net/http/PlainHttpConnection.h>

namespace java {
	namespace net {
		class InetSocketAddress;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class ConnectionPool$CacheKey;
				class HttpClientImpl;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import PlainProxyConnection : public ::jdk::internal::net::http::PlainHttpConnection {
	$class(PlainProxyConnection, $NO_CLASS_INIT, ::jdk::internal::net::http::PlainHttpConnection)
public:
	PlainProxyConnection();
	void init$(::java::net::InetSocketAddress* proxy, ::jdk::internal::net::http::HttpClientImpl* client);
	virtual ::jdk::internal::net::http::ConnectionPool$CacheKey* cacheKey() override;
	virtual bool isProxied() override;
	virtual ::java::net::InetSocketAddress* proxy() override;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_PlainProxyConnection_h_