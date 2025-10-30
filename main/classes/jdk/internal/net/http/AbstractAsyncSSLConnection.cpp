#include <jdk/internal/net/http/AbstractAsyncSSLConnection.h>

#include <java/net/InetSocketAddress.h>
#include <java/util/ArrayDeque.h>
#include <java/util/Arrays.h>
#include <java/util/List.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <javax/net/ssl/SNIHostName.h>
#include <javax/net/ssl/SSLContext.h>
#include <javax/net/ssl/SSLEngine.h>
#include <javax/net/ssl/SSLParameters.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/SSLTube.h>
#include <jdk/internal/net/http/common/Utils$ServerName.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $ArrayDeque = ::java::util::ArrayDeque;
using $Arrays = ::java::util::Arrays;
using $List = ::java::util::List;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $SNIHostName = ::javax::net::ssl::SNIHostName;
using $SSLContext = ::javax::net::ssl::SSLContext;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $SSLParameters = ::javax::net::ssl::SSLParameters;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $Log = ::jdk::internal::net::http::common::Log;
using $SSLTube = ::jdk::internal::net::http::common::SSLTube;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $Utils$ServerName = ::jdk::internal::net::http::common::Utils$ServerName;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _AbstractAsyncSSLConnection_FieldInfo_[] = {
	{"engine", "Ljavax/net/ssl/SSLEngine;", nullptr, $PROTECTED | $FINAL, $field(AbstractAsyncSSLConnection, engine)},
	{"serverName", "Ljava/lang/String;", nullptr, $PROTECTED | $FINAL, $field(AbstractAsyncSSLConnection, serverName)},
	{"sslParameters", "Ljavax/net/ssl/SSLParameters;", nullptr, $PROTECTED | $FINAL, $field(AbstractAsyncSSLConnection, sslParameters)},
	{"disableHostnameVerification", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AbstractAsyncSSLConnection, disableHostnameVerification)},
	{}
};

$MethodInfo _AbstractAsyncSSLConnection_MethodInfo_[] = {
	{"getConnectionFlow", "()Ljdk/internal/net/http/common/FlowTube;", nullptr, $ABSTRACT},
	{"<init>", "(Ljava/net/InetSocketAddress;Ljdk/internal/net/http/HttpClientImpl;Ljdk/internal/net/http/common/Utils$ServerName;I[Ljava/lang/String;)V", nullptr, 0, $method(static_cast<void(AbstractAsyncSSLConnection::*)($InetSocketAddress*,$HttpClientImpl*,$Utils$ServerName*,int32_t,$StringArray*)>(&AbstractAsyncSSLConnection::init$))},
	{"contains", "([Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)($StringArray*,$String*)>(&AbstractAsyncSSLConnection::contains))},
	{"createEngine", "(Ljavax/net/ssl/SSLContext;Ljava/lang/String;ILjavax/net/ssl/SSLParameters;)Ljavax/net/ssl/SSLEngine;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$SSLEngine*(*)($SSLContext*,$String*,int32_t,$SSLParameters*)>(&AbstractAsyncSSLConnection::createEngine))},
	{"createSSLParameters", "(Ljdk/internal/net/http/HttpClientImpl;Ljdk/internal/net/http/common/Utils$ServerName;[Ljava/lang/String;)Ljavax/net/ssl/SSLParameters;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$SSLParameters*(*)($HttpClientImpl*,$Utils$ServerName*,$StringArray*)>(&AbstractAsyncSSLConnection::createSSLParameters))},
	{"getALPN", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/String;>;", $FINAL, $method(static_cast<$CompletableFuture*(AbstractAsyncSSLConnection::*)()>(&AbstractAsyncSSLConnection::getALPN))},
	{"getEngine", "()Ljavax/net/ssl/SSLEngine;", nullptr, $FINAL, $method(static_cast<$SSLEngine*(AbstractAsyncSSLConnection::*)()>(&AbstractAsyncSSLConnection::getEngine))},
	{"isSecure", "()Z", nullptr, $FINAL},
	{}
};

$ClassInfo _AbstractAsyncSSLConnection_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.AbstractAsyncSSLConnection",
	"jdk.internal.net.http.HttpConnection",
	nullptr,
	_AbstractAsyncSSLConnection_FieldInfo_,
	_AbstractAsyncSSLConnection_MethodInfo_
};

$Object* allocate$AbstractAsyncSSLConnection($Class* clazz) {
	return $of($alloc(AbstractAsyncSSLConnection));
}

bool AbstractAsyncSSLConnection::disableHostnameVerification = false;

void AbstractAsyncSSLConnection::init$($InetSocketAddress* addr, $HttpClientImpl* client, $Utils$ServerName* serverName, int32_t port, $StringArray* alpn) {
	$useLocalCurrentObjectStackCache();
	$HttpConnection::init$(addr, client);
	$set(this, serverName, $nc(serverName)->getName());
	$var($SSLContext, context, $nc(client)->theSSLContext());
	$set(this, sslParameters, createSSLParameters(client, serverName, alpn));
	$Log::logParams(this->sslParameters);
	$set(this, engine, createEngine(context, $(serverName->getName()), port, this->sslParameters));
}

$CompletableFuture* AbstractAsyncSSLConnection::getALPN() {
	return $nc($($cast($SSLTube, getConnectionFlow())))->getALPN();
}

$SSLEngine* AbstractAsyncSSLConnection::getEngine() {
	return this->engine;
}

bool AbstractAsyncSSLConnection::contains($StringArray* rr, $String* target) {
	$init(AbstractAsyncSSLConnection);
	$useLocalCurrentObjectStackCache();
	{
		$var($StringArray, arr$, rr);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, s, arr$->get(i$));
			if ($nc(target)->equalsIgnoreCase(s)) {
				return true;
			}
		}
	}
	return false;
}

$SSLParameters* AbstractAsyncSSLConnection::createSSLParameters($HttpClientImpl* client, $Utils$ServerName* serverName, $StringArray* alpn) {
	$init(AbstractAsyncSSLConnection);
	$useLocalCurrentObjectStackCache();
	$var($SSLParameters, sslp, $nc(client)->sslParameters());
	$var($SSLParameters, sslParameters, $Utils::copySSLParameters(sslp));
	if (alpn != nullptr && alpn->length != 0 && !contains(alpn, "http/1.1"_s)) {
		$var($ArrayDeque, l, $new($ArrayDeque));
		{
			$var($StringArray, arr$, $nc(sslParameters)->getProtocols());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, proto, arr$->get(i$));
				{
					bool var$1 = !$nc(proto)->startsWith("SSL"_s);
					bool var$0 = var$1 && !proto->endsWith("v1.1"_s);
					if (var$0 && !proto->endsWith("v1"_s)) {
						l->add(proto);
					}
				}
			}
		}
		$var($StringArray, a1, $fcast($StringArray, l->toArray($$new($StringArray, 0))));
		sslParameters->setProtocols(a1);
	}
	if (!AbstractAsyncSSLConnection::disableHostnameVerification) {
		$nc(sslParameters)->setEndpointIdentificationAlgorithm("HTTPS"_s);
	}
	if (alpn != nullptr) {
		$Log::logSSL("AbstractAsyncSSLConnection: Setting application protocols: {0}"_s, $$new($ObjectArray, {$($of($Arrays::toString(alpn)))}));
		$nc(sslParameters)->setApplicationProtocols(alpn);
	} else {
		$Log::logSSL("AbstractAsyncSSLConnection: no applications set!"_s, $$new($ObjectArray, 0));
	}
	if (!$nc(serverName)->isLiteral()) {
		$var($String, name, serverName->getName());
		if (name != nullptr && name->length() > 0) {
			$nc(sslParameters)->setServerNames($($List::of($of($$new($SNIHostName, name)))));
		}
	}
	return sslParameters;
}

$SSLEngine* AbstractAsyncSSLConnection::createEngine($SSLContext* context, $String* serverName, int32_t port, $SSLParameters* sslParameters) {
	$init(AbstractAsyncSSLConnection);
	$var($SSLEngine, engine, $nc(context)->createSSLEngine(serverName, port));
	$nc(engine)->setUseClientMode(true);
	engine->setSSLParameters(sslParameters);
	return engine;
}

bool AbstractAsyncSSLConnection::isSecure() {
	return true;
}

void clinit$AbstractAsyncSSLConnection($Class* class$) {
	AbstractAsyncSSLConnection::disableHostnameVerification = $Utils::isHostnameVerificationDisabled();
}

AbstractAsyncSSLConnection::AbstractAsyncSSLConnection() {
}

$Class* AbstractAsyncSSLConnection::load$($String* name, bool initialize) {
	$loadClass(AbstractAsyncSSLConnection, name, initialize, &_AbstractAsyncSSLConnection_ClassInfo_, clinit$AbstractAsyncSSLConnection, allocate$AbstractAsyncSSLConnection);
	return class$;
}

$Class* AbstractAsyncSSLConnection::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk