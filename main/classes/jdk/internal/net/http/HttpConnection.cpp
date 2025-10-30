#include <jdk/internal/net/http/HttpConnection.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpClient.h>
#include <java/net/http/HttpHeaders.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/SocketChannel.h>
#include <java/nio/channels/spi/AbstractInterruptibleChannel.h>
#include <java/util/Arrays.h>
#include <java/util/Map.h>
#include <java/util/Optional.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/function/BiPredicate.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/Stream.h>
#include <javax/net/ssl/SSLParameters.h>
#include <jdk/internal/net/http/AbstractAsyncSSLConnection.h>
#include <jdk/internal/net/http/AsyncSSLConnection.h>
#include <jdk/internal/net/http/AsyncSSLTunnelConnection.h>
#include <jdk/internal/net/http/ConnectionPool$CacheKey.h>
#include <jdk/internal/net/http/ConnectionPool.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpConnection$HttpPublisher.h>
#include <jdk/internal/net/http/HttpConnection$TrailingOperations.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/PlainHttpConnection.h>
#include <jdk/internal/net/http/PlainProxyConnection.h>
#include <jdk/internal/net/http/PlainTunnelingConnection.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/HttpHeadersBuilder.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils$ProxyHeaders.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef DEBUG
#undef DEBUG_LOGGER
#undef HTTP_2
#undef NO_PROXY_HEADERS_FILTER
#undef PROXY_FILTER
#undef PROXY_TUNNEL_FILTER

using $Closeable = ::java::io::Closeable;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $HttpClient = ::java::net::http::HttpClient;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $AbstractInterruptibleChannel = ::java::nio::channels::spi::AbstractInterruptibleChannel;
using $Arrays = ::java::util::Arrays;
using $Map = ::java::util::Map;
using $Optional = ::java::util::Optional;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $BiPredicate = ::java::util::function::BiPredicate;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Supplier = ::java::util::function::Supplier;
using $Stream = ::java::util::stream::Stream;
using $SSLParameters = ::javax::net::ssl::SSLParameters;
using $AbstractAsyncSSLConnection = ::jdk::internal::net::http::AbstractAsyncSSLConnection;
using $AsyncSSLConnection = ::jdk::internal::net::http::AsyncSSLConnection;
using $AsyncSSLTunnelConnection = ::jdk::internal::net::http::AsyncSSLTunnelConnection;
using $ConnectionPool = ::jdk::internal::net::http::ConnectionPool;
using $ConnectionPool$CacheKey = ::jdk::internal::net::http::ConnectionPool$CacheKey;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpConnection$HttpPublisher = ::jdk::internal::net::http::HttpConnection$HttpPublisher;
using $HttpConnection$TrailingOperations = ::jdk::internal::net::http::HttpConnection$TrailingOperations;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $PlainHttpConnection = ::jdk::internal::net::http::PlainHttpConnection;
using $PlainProxyConnection = ::jdk::internal::net::http::PlainProxyConnection;
using $PlainTunnelingConnection = ::jdk::internal::net::http::PlainTunnelingConnection;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $HttpHeadersBuilder = ::jdk::internal::net::http::common::HttpHeadersBuilder;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $Utils$ProxyHeaders = ::jdk::internal::net::http::common::Utils$ProxyHeaders;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class HttpConnection$$Lambda$dbgString : public $Supplier {
	$class(HttpConnection$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(HttpConnection* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpConnection$$Lambda$dbgString>());
	}
	HttpConnection* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpConnection$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HttpConnection$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo HttpConnection$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/HttpConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpConnection$$Lambda$dbgString::*)(HttpConnection*)>(&HttpConnection$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpConnection$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpConnection$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* HttpConnection$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(HttpConnection$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpConnection$$Lambda$dbgString::class$ = nullptr;

class HttpConnection$$Lambda$lambda$static$0$1 : public $Supplier {
	$class(HttpConnection$$Lambda$lambda$static$0$1, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(HttpConnection::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpConnection$$Lambda$lambda$static$0$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpConnection$$Lambda$lambda$static$0$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpConnection$$Lambda$lambda$static$0$1::*)()>(&HttpConnection$$Lambda$lambda$static$0$1::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpConnection$$Lambda$lambda$static$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpConnection$$Lambda$lambda$static$0$1",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* HttpConnection$$Lambda$lambda$static$0$1::load$($String* name, bool initialize) {
	$loadClass(HttpConnection$$Lambda$lambda$static$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpConnection$$Lambda$lambda$static$0$1::class$ = nullptr;

class HttpConnection$$Lambda$lambda$static$1$2 : public $Predicate {
	$class(HttpConnection$$Lambda$lambda$static$1$2, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* proto) override {
		 return HttpConnection::lambda$static$1($cast($String, proto));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpConnection$$Lambda$lambda$static$1$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpConnection$$Lambda$lambda$static$1$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpConnection$$Lambda$lambda$static$1$2::*)()>(&HttpConnection$$Lambda$lambda$static$1$2::init$))},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpConnection$$Lambda$lambda$static$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpConnection$$Lambda$lambda$static$1$2",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* HttpConnection$$Lambda$lambda$static$1$2::load$($String* name, bool initialize) {
	$loadClass(HttpConnection$$Lambda$lambda$static$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpConnection$$Lambda$lambda$static$1$2::class$ = nullptr;

class HttpConnection$$Lambda$lambda$closeOrReturnToCache$2$3 : public $Function {
	$class(HttpConnection$$Lambda$lambda$closeOrReturnToCache$2$3, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* s) override {
		 return $of(HttpConnection::lambda$closeOrReturnToCache$2($cast($String, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpConnection$$Lambda$lambda$closeOrReturnToCache$2$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpConnection$$Lambda$lambda$closeOrReturnToCache$2$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpConnection$$Lambda$lambda$closeOrReturnToCache$2$3::*)()>(&HttpConnection$$Lambda$lambda$closeOrReturnToCache$2$3::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpConnection$$Lambda$lambda$closeOrReturnToCache$2$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpConnection$$Lambda$lambda$closeOrReturnToCache$2$3",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* HttpConnection$$Lambda$lambda$closeOrReturnToCache$2$3::load$($String* name, bool initialize) {
	$loadClass(HttpConnection$$Lambda$lambda$closeOrReturnToCache$2$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpConnection$$Lambda$lambda$closeOrReturnToCache$2$3::class$ = nullptr;

$FieldInfo _HttpConnection_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HttpConnection, $assertionsDisabled)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(HttpConnection, debug)},
	{"DEBUG_LOGGER", "Ljdk/internal/net/http/common/Logger;", nullptr, $STATIC | $FINAL, $staticField(HttpConnection, DEBUG_LOGGER)},
	{"address", "Ljava/net/InetSocketAddress;", nullptr, $FINAL, $field(HttpConnection, address$)},
	{"client", "Ljdk/internal/net/http/HttpClientImpl;", nullptr, $PRIVATE | $FINAL, $field(HttpConnection, client$)},
	{"trailingOperations", "Ljdk/internal/net/http/HttpConnection$TrailingOperations;", nullptr, $PRIVATE | $FINAL, $field(HttpConnection, trailingOperations)},
	{"testRequiredHTTP2TLSVersion", "Ljava/util/function/Predicate;", "Ljava/util/function/Predicate<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(HttpConnection, testRequiredHTTP2TLSVersion)},
	{"dbgTag", "Ljava/lang/String;", nullptr, 0, $field(HttpConnection, dbgTag)},
	{}
};

$MethodInfo _HttpConnection_MethodInfo_[] = {
	{"close", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{"<init>", "(Ljava/net/InetSocketAddress;Ljdk/internal/net/http/HttpClientImpl;)V", nullptr, 0, $method(static_cast<void(HttpConnection::*)($InetSocketAddress*,$HttpClientImpl*)>(&HttpConnection::init$))},
	{"addTrailingOperation", "(Ljava/util/concurrent/CompletionStage;)V", "(Ljava/util/concurrent/CompletionStage<*>;)V", $FINAL, $method(static_cast<void(HttpConnection::*)($CompletionStage*)>(&HttpConnection::addTrailingOperation))},
	{"address", "()Ljava/net/InetSocketAddress;", nullptr, $FINAL, $method(static_cast<$InetSocketAddress*(HttpConnection::*)()>(&HttpConnection::address))},
	{"cacheKey", "()Ljdk/internal/net/http/ConnectionPool$CacheKey;", nullptr, $ABSTRACT},
	{"channel", "()Ljava/nio/channels/SocketChannel;", nullptr, $ABSTRACT},
	{"checkOpen", "()Z", nullptr, $FINAL, $method(static_cast<bool(HttpConnection::*)()>(&HttpConnection::checkOpen))},
	{"client", "()Ljdk/internal/net/http/HttpClientImpl;", nullptr, $FINAL, $method(static_cast<$HttpClientImpl*(HttpConnection::*)()>(&HttpConnection::client))},
	{"closeOrReturnToCache", "(Ljava/net/http/HttpHeaders;)V", nullptr, 0},
	{"connectAsync", "(Ljdk/internal/net/http/Exchange;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/Exchange<*>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC | $ABSTRACT},
	{"connected", "()Z", nullptr, $ABSTRACT},
	{"contextRestricted", "(Ljdk/internal/net/http/HttpRequestImpl;Ljava/net/http/HttpClient;)Ljava/util/function/BiPredicate;", "(Ljdk/internal/net/http/HttpRequestImpl;Ljava/net/http/HttpClient;)Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;", 0},
	{"dbgString", "()Ljava/lang/String;", nullptr, $FINAL, $method(static_cast<$String*(HttpConnection::*)()>(&HttpConnection::dbgString))},
	{"finishConnect", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC | $ABSTRACT},
	{"getConnection", "(Ljava/net/InetSocketAddress;Ljdk/internal/net/http/HttpClientImpl;Ljdk/internal/net/http/HttpRequestImpl;Ljava/net/http/HttpClient$Version;)Ljdk/internal/net/http/HttpConnection;", nullptr, $PUBLIC | $STATIC, $method(static_cast<HttpConnection*(*)($InetSocketAddress*,$HttpClientImpl*,$HttpRequestImpl*,$HttpClient$Version*)>(&HttpConnection::getConnection))},
	{"getConnectionFlow", "()Ljdk/internal/net/http/common/FlowTube;", nullptr, $ABSTRACT},
	{"getPlainConnection", "(Ljava/net/InetSocketAddress;Ljava/net/InetSocketAddress;Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/HttpClientImpl;)Ljdk/internal/net/http/HttpConnection;", nullptr, $PRIVATE | $STATIC, $method(static_cast<HttpConnection*(*)($InetSocketAddress*,$InetSocketAddress*,$HttpRequestImpl*,$HttpClientImpl*)>(&HttpConnection::getPlainConnection))},
	{"getSSLConnection", "(Ljava/net/InetSocketAddress;Ljava/net/InetSocketAddress;[Ljava/lang/String;Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/HttpClientImpl;)Ljdk/internal/net/http/HttpConnection;", nullptr, $PRIVATE | $STATIC, $method(static_cast<HttpConnection*(*)($InetSocketAddress*,$InetSocketAddress*,$StringArray*,$HttpRequestImpl*,$HttpClientImpl*)>(&HttpConnection::getSSLConnection))},
	{"hasRequiredHTTP2TLSVersion", "(Ljava/net/http/HttpClient;)Z", nullptr, $PRIVATE | $STATIC | $FINAL, $method(static_cast<bool(*)($HttpClient*)>(&HttpConnection::hasRequiredHTTP2TLSVersion))},
	{"headerFilter", "(Ljdk/internal/net/http/HttpRequestImpl;)Ljava/util/function/BiPredicate;", "(Ljdk/internal/net/http/HttpRequestImpl;)Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;", 0},
	{"isOpen", "()Z", nullptr, $FINAL, $method(static_cast<bool(HttpConnection::*)()>(&HttpConnection::isOpen))},
	{"isProxied", "()Z", nullptr, $ABSTRACT},
	{"isSecure", "()Z", nullptr, $ABSTRACT},
	{"isTunnel", "()Z", nullptr, 0},
	{"lambda$closeOrReturnToCache$2", "(Ljava/lang/String;)Ljava/lang/Boolean;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Boolean*(*)($String*)>(&HttpConnection::lambda$closeOrReturnToCache$2))},
	{"lambda$static$0", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)()>(&HttpConnection::lambda$static$0))},
	{"lambda$static$1", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($String*)>(&HttpConnection::lambda$static$1))},
	{"proxy", "()Ljava/net/InetSocketAddress;", nullptr, $ABSTRACT},
	{"proxyTunnelHeaders", "(Ljdk/internal/net/http/HttpRequestImpl;)Ljdk/internal/net/http/common/Utils$ProxyHeaders;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Utils$ProxyHeaders*(*)($HttpRequestImpl*)>(&HttpConnection::proxyTunnelHeaders))},
	{"publisher", "()Ljdk/internal/net/http/HttpConnection$HttpPublisher;", nullptr, $ABSTRACT},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _HttpConnection_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.HttpConnection$PlainHttpPublisher", "jdk.internal.net.http.HttpConnection", "PlainHttpPublisher", $FINAL},
	{"jdk.internal.net.http.HttpConnection$HttpPublisher", "jdk.internal.net.http.HttpConnection", "HttpPublisher", $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.HttpConnection$TrailingOperations", "jdk.internal.net.http.HttpConnection", "TrailingOperations", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _HttpConnection_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.HttpConnection",
	"java.lang.Object",
	"java.io.Closeable",
	_HttpConnection_FieldInfo_,
	_HttpConnection_MethodInfo_,
	nullptr,
	nullptr,
	_HttpConnection_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HttpConnection$PlainHttpPublisher,jdk.internal.net.http.HttpConnection$PlainHttpPublisher$HttpWriteSubscription,jdk.internal.net.http.HttpConnection$HttpPublisher,jdk.internal.net.http.HttpConnection$TrailingOperations"
};

$Object* allocate$HttpConnection($Class* clazz) {
	return $of($alloc(HttpConnection));
}

bool HttpConnection::$assertionsDisabled = false;
$Logger* HttpConnection::DEBUG_LOGGER = nullptr;
$Predicate* HttpConnection::testRequiredHTTP2TLSVersion = nullptr;

void HttpConnection::init$($InetSocketAddress* address, $HttpClientImpl* client) {
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(HttpConnection$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, address$, address);
	$set(this, client$, client);
	$set(this, trailingOperations, $new($HttpConnection$TrailingOperations));
}

void HttpConnection::addTrailingOperation($CompletionStage* cf) {
	$nc(this->trailingOperations)->add(cf);
}

$HttpClientImpl* HttpConnection::client() {
	return this->client$;
}

bool HttpConnection::isOpen() {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc($(channel()))->isOpen();
	return var$0 && (connected() ? !$nc($(getConnectionFlow()))->isFinished() : true);
}

bool HttpConnection::checkOpen() {
	$useLocalCurrentObjectStackCache();
	if (isOpen()) {
		try {
			int32_t read = $nc($(channel()))->read($($ByteBuffer::allocate(1)));
			if (read == 0) {
				return true;
			}
			close();
		} catch ($IOException& x) {
			$nc(this->debug)->log("Pooled connection is no longer operational: %s"_s, $$new($ObjectArray, {$($of(x->toString()))}));
			return false;
		}
	}
	return false;
}

bool HttpConnection::hasRequiredHTTP2TLSVersion($HttpClient* client) {
	$init(HttpConnection);
	$useLocalCurrentObjectStackCache();
	$var($StringArray, protos, $nc($($nc(client)->sslParameters()))->getProtocols());
	if (protos != nullptr) {
		return $nc($($nc($($nc($($Arrays::stream(protos)))->filter(HttpConnection::testRequiredHTTP2TLSVersion)))->findAny()))->isPresent();
	} else {
		return false;
	}
}

HttpConnection* HttpConnection::getConnection($InetSocketAddress* addr, $HttpClientImpl* client, $HttpRequestImpl* request, $HttpClient$Version* version) {
	$init(HttpConnection);
	$useLocalCurrentObjectStackCache();
	$var($InetSocketAddress, proxy, $Utils::resolveAddress($($nc(request)->proxy())));
	$var(HttpConnection, c, nullptr);
	bool secure = $nc(request)->secure();
	$var($ConnectionPool, pool, $nc(client)->connectionPool());
	if (!secure) {
		$assign(c, $nc(pool)->getConnection(false, addr, proxy));
		if (c != nullptr && c->checkOpen()) {
			$var(HttpConnection, conn, c);
			if ($nc(HttpConnection::DEBUG_LOGGER)->on()) {
				$nc(HttpConnection::DEBUG_LOGGER)->log($$str({$(conn->getConnectionFlow()), ": plain connection retrieved from HTTP/1.1 pool"_s}));
			}
			return c;
		} else {
			return getPlainConnection(addr, proxy, request, client);
		}
	} else {
		$init($HttpClient$Version);
		if (version != $HttpClient$Version::HTTP_2) {
			$assign(c, $nc(pool)->getConnection(true, addr, proxy));
		}
		if (c != nullptr && c->isOpen()) {
			$var(HttpConnection, conn, c);
			if ($nc(HttpConnection::DEBUG_LOGGER)->on()) {
				$nc(HttpConnection::DEBUG_LOGGER)->log($$str({$(conn->getConnectionFlow()), ": SSL connection retrieved from HTTP/1.1 pool"_s}));
			}
			return c;
		} else {
			$var($StringArray, alpn, nullptr);
			if (version == $HttpClient$Version::HTTP_2 && hasRequiredHTTP2TLSVersion(client)) {
				$assign(alpn, $new($StringArray, {
					"h2"_s,
					"http/1.1"_s
				}));
			}
			return getSSLConnection(addr, proxy, alpn, request, client);
		}
	}
}

HttpConnection* HttpConnection::getSSLConnection($InetSocketAddress* addr, $InetSocketAddress* proxy, $StringArray* alpn, $HttpRequestImpl* request, $HttpClientImpl* client) {
	$init(HttpConnection);
	if (proxy != nullptr) {
		return $new($AsyncSSLTunnelConnection, addr, client, alpn, proxy, $(proxyTunnelHeaders(request)));
	} else {
		return $new($AsyncSSLConnection, addr, client, alpn);
	}
}

$BiPredicate* HttpConnection::headerFilter($HttpRequestImpl* request) {
	if (isTunnel()) {
		if (!HttpConnection::$assertionsDisabled && ! !$nc(request)->isConnect()) {
			$throwNew($AssertionError);
		}
		$init($Utils);
		return $Utils::NO_PROXY_HEADERS_FILTER;
	} else if ($nc(request)->isConnect()) {
		if (!HttpConnection::$assertionsDisabled && !(request->proxy() == nullptr)) {
			$throwNew($AssertionError);
		}
		$init($Utils);
		return $Utils::PROXY_TUNNEL_FILTER;
	} else if (request->proxy() != nullptr) {
		$init($Utils);
		return $Utils::PROXY_FILTER;
	} else {
		$init($Utils);
		return $Utils::NO_PROXY_HEADERS_FILTER;
	}
}

$BiPredicate* HttpConnection::contextRestricted($HttpRequestImpl* request, $HttpClient* client) {
	bool var$0 = !isTunnel();
	if (var$0 && $nc(request)->isConnect()) {
		if (!HttpConnection::$assertionsDisabled && !(request->proxy() == nullptr)) {
			$throwNew($AssertionError);
		}
		return $Utils::PROXY_TUNNEL_RESTRICTED(client);
	} else {
		return $Utils::CONTEXT_RESTRICTED(client);
	}
}

$Utils$ProxyHeaders* HttpConnection::proxyTunnelHeaders($HttpRequestImpl* request) {
	$init(HttpConnection);
	$useLocalCurrentObjectStackCache();
	$init($Utils);
	$var($HttpHeaders, userHeaders, $HttpHeaders::of($($nc($($nc(request)->headers()))->map()), $Utils::PROXY_TUNNEL_FILTER));
	$var($HttpHeaders, systemHeaders, $HttpHeaders::of($($nc($($nc(request)->getSystemHeadersBuilder()))->map()), $Utils::PROXY_TUNNEL_FILTER));
	return $new($Utils$ProxyHeaders, userHeaders, systemHeaders);
}

HttpConnection* HttpConnection::getPlainConnection($InetSocketAddress* addr, $InetSocketAddress* proxy, $HttpRequestImpl* request, $HttpClientImpl* client) {
	$init(HttpConnection);
	if ($nc(request)->isWebSocket() && proxy != nullptr) {
		return $new($PlainTunnelingConnection, addr, proxy, client, $(proxyTunnelHeaders(request)));
	}
	if (proxy == nullptr) {
		return $new($PlainHttpConnection, addr, client);
	} else {
		return $new($PlainProxyConnection, proxy, client);
	}
}

void HttpConnection::closeOrReturnToCache($HttpHeaders* hdrs) {
	$useLocalCurrentObjectStackCache();
	if (hdrs == nullptr) {
		$Log::logTrace("Cannot return connection to pool: closing {0}"_s, $$new($ObjectArray, {$of(this)}));
		close();
		return;
	}
	$var($HttpClientImpl, client, this->client());
	if (client == nullptr) {
		$Log::logTrace("Client released: closing {0}"_s, $$new($ObjectArray, {$of(this)}));
		close();
		return;
	}
	$var($ConnectionPool, pool, $nc(client)->connectionPool());
	bool keepAlive = $nc(($cast($Boolean, $($nc($($nc($($nc(hdrs)->firstValue("Connection"_s)))->map(static_cast<$Function*>($$new(HttpConnection$$Lambda$lambda$closeOrReturnToCache$2$3)))))->orElse($($Boolean::valueOf(true)))))))->booleanValue();
	if (keepAlive && checkOpen()) {
		$Log::logTrace("Returning connection to the pool: {0}"_s, $$new($ObjectArray, {$of(this)}));
		$nc(pool)->returnToPool(this);
	} else {
		$Log::logTrace("Closing connection (keepAlive={0}, isOpen={1}): {2}"_s, $$new($ObjectArray, {
			$($of($Boolean::valueOf(keepAlive))),
			$($of($Boolean::valueOf(isOpen()))),
			$of(this)
		}));
		close();
	}
}

bool HttpConnection::isTunnel() {
	return false;
}

$InetSocketAddress* HttpConnection::address() {
	return this->address$;
}

$String* HttpConnection::dbgString() {
	$useLocalCurrentObjectStackCache();
	$var($FlowTube, flow, getConnectionFlow());
	$var($String, tag, this->dbgTag);
	if (tag == nullptr && flow != nullptr) {
		$set(this, dbgTag, ($assign(tag, $str({$($of(this)->getClass()->getSimpleName()), "("_s, flow, ")"_s}))));
	} else if (tag == nullptr) {
		$assign(tag, $str({$($of(this)->getClass()->getSimpleName()), "(?)"_s}));
	}
	return tag;
}

$String* HttpConnection::toString() {
	$useLocalCurrentObjectStackCache();
	return $str({"HttpConnection: "_s, $($nc($of($(channel())))->toString())});
}

$Boolean* HttpConnection::lambda$closeOrReturnToCache$2($String* s) {
	$init(HttpConnection);
	return $Boolean::valueOf(!$nc(s)->equalsIgnoreCase("close"_s));
}

bool HttpConnection::lambda$static$1($String* proto) {
	$init(HttpConnection);
	bool var$0 = $nc(proto)->equals("TLSv1.2"_s);
	return var$0 || $nc(proto)->equals("TLSv1.3"_s);
}

$String* HttpConnection::lambda$static$0() {
	$init(HttpConnection);
	return "HttpConnection(SocketTube(?))"_s;
}

void clinit$HttpConnection($Class* class$) {
	HttpConnection::$assertionsDisabled = !HttpConnection::class$->desiredAssertionStatus();
	$init($Utils);
	$assignStatic(HttpConnection::DEBUG_LOGGER, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(HttpConnection$$Lambda$lambda$static$0$1)), $Utils::DEBUG));
	$assignStatic(HttpConnection::testRequiredHTTP2TLSVersion, static_cast<$Predicate*>($new(HttpConnection$$Lambda$lambda$static$1$2)));
}

HttpConnection::HttpConnection() {
}

$Class* HttpConnection::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HttpConnection$$Lambda$dbgString::classInfo$.name)) {
			return HttpConnection$$Lambda$dbgString::load$(name, initialize);
		}
		if (name->equals(HttpConnection$$Lambda$lambda$static$0$1::classInfo$.name)) {
			return HttpConnection$$Lambda$lambda$static$0$1::load$(name, initialize);
		}
		if (name->equals(HttpConnection$$Lambda$lambda$static$1$2::classInfo$.name)) {
			return HttpConnection$$Lambda$lambda$static$1$2::load$(name, initialize);
		}
		if (name->equals(HttpConnection$$Lambda$lambda$closeOrReturnToCache$2$3::classInfo$.name)) {
			return HttpConnection$$Lambda$lambda$closeOrReturnToCache$2$3::load$(name, initialize);
		}
	}
	$loadClass(HttpConnection, name, initialize, &_HttpConnection_ClassInfo_, clinit$HttpConnection, allocate$HttpConnection);
	return class$;
}

$Class* HttpConnection::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk