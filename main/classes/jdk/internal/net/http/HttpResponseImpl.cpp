#include <jdk/internal/net/http/HttpResponseImpl.h>

#include <java/lang/UnsupportedOperationException.h>
#include <java/net/URI.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpRequest.h>
#include <java/net/http/HttpResponse.h>
#include <java/util/Optional.h>
#include <javax/net/ssl/SSLSession.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/HttpResponseImpl$RawChannelProvider.h>
#include <jdk/internal/net/http/Response.h>
#include <jdk/internal/net/http/websocket/RawChannel.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $URI = ::java::net::URI;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpResponse = ::java::net::http::HttpResponse;
using $Optional = ::java::util::Optional;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $HttpResponseImpl$RawChannelProvider = ::jdk::internal::net::http::HttpResponseImpl$RawChannelProvider;
using $Response = ::jdk::internal::net::http::Response;
using $RawChannel = ::jdk::internal::net::http::websocket::RawChannel;
using $RawChannel$Provider = ::jdk::internal::net::http::websocket::RawChannel$Provider;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _HttpResponseImpl_FieldInfo_[] = {
	{"responseCode", "I", nullptr, $FINAL, $field(HttpResponseImpl, responseCode)},
	{"initialRequest", "Ljava/net/http/HttpRequest;", nullptr, $FINAL, $field(HttpResponseImpl, initialRequest)},
	{"previousResponse", "Ljava/util/Optional;", "Ljava/util/Optional<Ljava/net/http/HttpResponse<TT;>;>;", $FINAL, $field(HttpResponseImpl, previousResponse$)},
	{"headers", "Ljava/net/http/HttpHeaders;", nullptr, $FINAL, $field(HttpResponseImpl, headers$)},
	{"sslSession", "Ljava/util/Optional;", "Ljava/util/Optional<Ljavax/net/ssl/SSLSession;>;", $FINAL, $field(HttpResponseImpl, sslSession$)},
	{"uri", "Ljava/net/URI;", nullptr, $FINAL, $field(HttpResponseImpl, uri$)},
	{"version", "Ljava/net/http/HttpClient$Version;", nullptr, $FINAL, $field(HttpResponseImpl, version$)},
	{"rawChannelProvider", "Ljdk/internal/net/http/HttpResponseImpl$RawChannelProvider;", nullptr, $FINAL, $field(HttpResponseImpl, rawChannelProvider)},
	{"body", "Ljava/lang/Object;", "TT;", $FINAL, $field(HttpResponseImpl, body$)},
	{}
};

$MethodInfo _HttpResponseImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/net/http/HttpRequest;Ljdk/internal/net/http/Response;Ljava/net/http/HttpResponse;Ljava/lang/Object;Ljdk/internal/net/http/Exchange;)V", "(Ljava/net/http/HttpRequest;Ljdk/internal/net/http/Response;Ljava/net/http/HttpResponse<TT;>;TT;Ljdk/internal/net/http/Exchange<TT;>;)V", $PUBLIC, $method(static_cast<void(HttpResponseImpl::*)($HttpRequest*,$Response*,$HttpResponse*,Object$*,$Exchange*)>(&HttpResponseImpl::init$))},
	{"body", "()Ljava/lang/Object;", "()TT;", $PUBLIC},
	{"closeRawChannel", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{"headers", "()Ljava/net/http/HttpHeaders;", nullptr, $PUBLIC},
	{"previousResponse", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/http/HttpResponse<TT;>;>;", $PUBLIC},
	{"rawChannel", "()Ljdk/internal/net/http/websocket/RawChannel;", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{"request", "()Ljava/net/http/HttpRequest;", nullptr, $PUBLIC},
	{"sslSession", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljavax/net/ssl/SSLSession;>;", $PUBLIC},
	{"statusCode", "()I", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"uri", "()Ljava/net/URI;", nullptr, $PUBLIC},
	{"version", "()Ljava/net/http/HttpClient$Version;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _HttpResponseImpl_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.RawChannel$Provider", "jdk.internal.net.http.websocket.RawChannel", "Provider", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.HttpResponseImpl$RawChannelProvider", "jdk.internal.net.http.HttpResponseImpl", "RawChannelProvider", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _HttpResponseImpl_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.HttpResponseImpl",
	"java.lang.Object",
	"java.net.http.HttpResponse,jdk.internal.net.http.websocket.RawChannel$Provider",
	_HttpResponseImpl_FieldInfo_,
	_HttpResponseImpl_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljava/net/http/HttpResponse<TT;>;Ljdk/internal/net/http/websocket/RawChannel$Provider;",
	nullptr,
	_HttpResponseImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HttpResponseImpl$RawChannelProvider"
};

$Object* allocate$HttpResponseImpl($Class* clazz) {
	return $of($alloc(HttpResponseImpl));
}

int32_t HttpResponseImpl::hashCode() {
	 return this->$HttpResponse::hashCode();
}

bool HttpResponseImpl::equals(Object$* arg0) {
	 return this->$HttpResponse::equals(arg0);
}

$Object* HttpResponseImpl::clone() {
	 return this->$HttpResponse::clone();
}

void HttpResponseImpl::finalize() {
	this->$HttpResponse::finalize();
}

void HttpResponseImpl::init$($HttpRequest* initialRequest, $Response* response, $HttpResponse* previousResponse, Object$* body, $Exchange* exch) {
	$useLocalCurrentObjectStackCache();
	this->responseCode = $nc(response)->statusCode();
	$set(this, initialRequest, initialRequest);
	$set(this, previousResponse$, $Optional::ofNullable(previousResponse));
	$set(this, headers$, response->headers());
	$set(this, sslSession$, $Optional::ofNullable($(response->getSSLSession())));
	$set(this, uri$, $nc($(response->request()))->uri());
	$set(this, version$, response->version());
	$set(this, rawChannelProvider, $HttpResponseImpl$RawChannelProvider::create(response, exch));
	$set(this, body$, body);
}

int32_t HttpResponseImpl::statusCode() {
	return this->responseCode;
}

$HttpRequest* HttpResponseImpl::request() {
	return this->initialRequest;
}

$Optional* HttpResponseImpl::previousResponse() {
	return this->previousResponse$;
}

$HttpHeaders* HttpResponseImpl::headers() {
	return this->headers$;
}

$Object* HttpResponseImpl::body() {
	return $of(this->body$);
}

$Optional* HttpResponseImpl::sslSession() {
	return this->sslSession$;
}

$URI* HttpResponseImpl::uri() {
	return this->uri$;
}

$HttpClient$Version* HttpResponseImpl::version() {
	return this->version$;
}

$RawChannel* HttpResponseImpl::rawChannel() {
	$synchronized(this) {
		if (this->rawChannelProvider == nullptr) {
			$throwNew($UnsupportedOperationException, "RawChannel is only supported for WebSocket creation"_s);
		}
		return $nc(this->rawChannelProvider)->rawChannel();
	}
}

void HttpResponseImpl::closeRawChannel() {
	$synchronized(this) {
		if (this->rawChannelProvider == nullptr) {
			$throwNew($UnsupportedOperationException, "RawChannel is only supported for WebSocket creation"_s);
		}
		$nc(this->rawChannelProvider)->closeRawChannel();
	}
}

$String* HttpResponseImpl::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	$var($String, method, $nc($(request()))->method());
	$var($URI, uri, $nc($(request()))->uri());
	$var($String, uristring, uri == nullptr ? ""_s : $nc(uri)->toString());
	sb->append(u'(')->append(method)->append(" "_s)->append(uristring)->append(") "_s)->append(statusCode());
	return sb->toString();
}

HttpResponseImpl::HttpResponseImpl() {
}

$Class* HttpResponseImpl::load$($String* name, bool initialize) {
	$loadClass(HttpResponseImpl, name, initialize, &_HttpResponseImpl_ClassInfo_, allocate$HttpResponseImpl);
	return class$;
}

$Class* HttpResponseImpl::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk