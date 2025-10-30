#include <jdk/internal/net/http/Response.h>

#include <java/io/IOException.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/SocketAddress.h>
#include <java/net/URI.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpHeaders.h>
#include <java/nio/channels/SocketChannel.h>
#include <javax/net/ssl/SSLEngine.h>
#include <javax/net/ssl/SSLSession.h>
#include <jdk/internal/net/http/AbstractAsyncSSLConnection.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $SocketAddress = ::java::net::SocketAddress;
using $URI = ::java::net::URI;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $AbstractAsyncSSLConnection = ::jdk::internal::net::http::AbstractAsyncSSLConnection;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Response_FieldInfo_[] = {
	{"headers", "Ljava/net/http/HttpHeaders;", nullptr, $FINAL, $field(Response, headers$)},
	{"statusCode", "I", nullptr, $FINAL, $field(Response, statusCode$)},
	{"request", "Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $FINAL, $field(Response, request$)},
	{"exchange", "Ljdk/internal/net/http/Exchange;", "Ljdk/internal/net/http/Exchange<*>;", $FINAL, $field(Response, exchange)},
	{"version", "Ljava/net/http/HttpClient$Version;", nullptr, $FINAL, $field(Response, version$)},
	{"isConnectResponse", "Z", nullptr, $FINAL, $field(Response, isConnectResponse)},
	{"sslSession", "Ljavax/net/ssl/SSLSession;", nullptr, $FINAL, $field(Response, sslSession)},
	{"localAddress", "Ljava/net/InetSocketAddress;", nullptr, $FINAL, $field(Response, localAddress)},
	{}
};

$MethodInfo _Response_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/Exchange;Ljava/net/http/HttpHeaders;Ljdk/internal/net/http/HttpConnection;ILjava/net/http/HttpClient$Version;)V", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/Exchange<*>;Ljava/net/http/HttpHeaders;Ljdk/internal/net/http/HttpConnection;ILjava/net/http/HttpClient$Version;)V", 0, $method(static_cast<void(Response::*)($HttpRequestImpl*,$Exchange*,$HttpHeaders*,$HttpConnection*,int32_t,$HttpClient$Version*)>(&Response::init$))},
	{"<init>", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/Exchange;Ljava/net/http/HttpHeaders;Ljdk/internal/net/http/HttpConnection;ILjava/net/http/HttpClient$Version;Z)V", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/Exchange<*>;Ljava/net/http/HttpHeaders;Ljdk/internal/net/http/HttpConnection;ILjava/net/http/HttpClient$Version;Z)V", 0, $method(static_cast<void(Response::*)($HttpRequestImpl*,$Exchange*,$HttpHeaders*,$HttpConnection*,int32_t,$HttpClient$Version*,bool)>(&Response::init$))},
	{"getSSLSession", "()Ljavax/net/ssl/SSLSession;", nullptr, 0},
	{"headers", "()Ljava/net/http/HttpHeaders;", nullptr, 0},
	{"request", "()Ljdk/internal/net/http/HttpRequestImpl;", nullptr, 0},
	{"statusCode", "()I", nullptr, 0},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"version", "()Ljava/net/http/HttpClient$Version;", nullptr, 0},
	{}
};

$ClassInfo _Response_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.Response",
	"java.lang.Object",
	nullptr,
	_Response_FieldInfo_,
	_Response_MethodInfo_
};

$Object* allocate$Response($Class* clazz) {
	return $of($alloc(Response));
}

void Response::init$($HttpRequestImpl* req, $Exchange* exchange, $HttpHeaders* headers, $HttpConnection* connection, int32_t statusCode, $HttpClient$Version* version) {
	Response::init$(req, exchange, headers, connection, statusCode, version, "CONNECT"_s->equalsIgnoreCase($($nc(req)->method())));
}

void Response::init$($HttpRequestImpl* req, $Exchange* exchange, $HttpHeaders* headers, $HttpConnection* connection, int32_t statusCode, $HttpClient$Version* version, bool isConnectResponse) {
	$useLocalCurrentObjectStackCache();
	$set(this, headers$, headers);
	$set(this, request$, req);
	$set(this, version$, version);
	$set(this, exchange, exchange);
	this->statusCode$ = statusCode;
	this->isConnectResponse = isConnectResponse;
	if (connection != nullptr) {
		$var($InetSocketAddress, a, nullptr);
		try {
			$assign(a, $cast($InetSocketAddress, $nc($(connection->channel()))->getLocalAddress()));
		} catch ($IOException& e) {
			$assign(a, nullptr);
		}
		$set(this, localAddress, a);
		if ($instanceOf($AbstractAsyncSSLConnection, connection)) {
			$var($AbstractAsyncSSLConnection, cc, $cast($AbstractAsyncSSLConnection, connection));
			$var($SSLEngine, engine, cc->getEngine());
			$set(this, sslSession, $Utils::immutableSession($($nc(engine)->getSession())));
		} else {
			$set(this, sslSession, nullptr);
		}
	} else {
		$set(this, sslSession, nullptr);
		$set(this, localAddress, nullptr);
	}
}

$HttpRequestImpl* Response::request() {
	return this->request$;
}

$HttpClient$Version* Response::version() {
	return this->version$;
}

$HttpHeaders* Response::headers() {
	return this->headers$;
}

int32_t Response::statusCode() {
	return this->statusCode$;
}

$SSLSession* Response::getSSLSession() {
	return this->sslSession;
}

$String* Response::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	$var($String, method, $nc($(request()))->method());
	$var($URI, uri, $nc($(request()))->uri());
	$var($String, uristring, uri == nullptr ? ""_s : $nc(uri)->toString());
	sb->append(u'(')->append(method)->append(" "_s)->append(uristring)->append(") "_s)->append(statusCode());
	sb->append(" "_s)->append($of(this->version$));
	if (this->localAddress != nullptr) {
		sb->append(" Local port:  "_s)->append($nc(this->localAddress)->getPort());
	}
	return sb->toString();
}

Response::Response() {
}

$Class* Response::load$($String* name, bool initialize) {
	$loadClass(Response, name, initialize, &_Response_ClassInfo_, allocate$Response);
	return class$;
}

$Class* Response::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk