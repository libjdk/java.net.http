#include <jdk/internal/net/http/PlainProxyConnection.h>

#include <java/net/InetSocketAddress.h>
#include <jdk/internal/net/http/ConnectionPool$CacheKey.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/PlainHttpConnection.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $ConnectionPool$CacheKey = ::jdk::internal::net::http::ConnectionPool$CacheKey;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $PlainHttpConnection = ::jdk::internal::net::http::PlainHttpConnection;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$MethodInfo _PlainProxyConnection_MethodInfo_[] = {
	{"<init>", "(Ljava/net/InetSocketAddress;Ljdk/internal/net/http/HttpClientImpl;)V", nullptr, 0, $method(static_cast<void(PlainProxyConnection::*)($InetSocketAddress*,$HttpClientImpl*)>(&PlainProxyConnection::init$))},
	{"cacheKey", "()Ljdk/internal/net/http/ConnectionPool$CacheKey;", nullptr, 0},
	{"isProxied", "()Z", nullptr, $PUBLIC},
	{"proxy", "()Ljava/net/InetSocketAddress;", nullptr, 0},
	{}
};

$ClassInfo _PlainProxyConnection_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.PlainProxyConnection",
	"jdk.internal.net.http.PlainHttpConnection",
	nullptr,
	nullptr,
	_PlainProxyConnection_MethodInfo_
};

$Object* allocate$PlainProxyConnection($Class* clazz) {
	return $of($alloc(PlainProxyConnection));
}

void PlainProxyConnection::init$($InetSocketAddress* proxy, $HttpClientImpl* client) {
	$PlainHttpConnection::init$(proxy, client);
}

$ConnectionPool$CacheKey* PlainProxyConnection::cacheKey() {
	return $new($ConnectionPool$CacheKey, nullptr, this->address$);
}

bool PlainProxyConnection::isProxied() {
	return true;
}

$InetSocketAddress* PlainProxyConnection::proxy() {
	return this->address$;
}

PlainProxyConnection::PlainProxyConnection() {
}

$Class* PlainProxyConnection::load$($String* name, bool initialize) {
	$loadClass(PlainProxyConnection, name, initialize, &_PlainProxyConnection_ClassInfo_, allocate$PlainProxyConnection);
	return class$;
}

$Class* PlainProxyConnection::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk