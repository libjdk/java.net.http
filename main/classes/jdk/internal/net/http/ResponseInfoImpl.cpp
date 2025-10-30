#include <jdk/internal/net/http/ResponseInfoImpl.h>

#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpHeaders.h>
#include <jdk/internal/net/http/Response.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpResponse$ResponseInfo = ::java::net::http::HttpResponse$ResponseInfo;
using $Response = ::jdk::internal::net::http::Response;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ResponseInfoImpl_FieldInfo_[] = {
	{"statusCode", "I", nullptr, $PRIVATE | $FINAL, $field(ResponseInfoImpl, statusCode$)},
	{"headers", "Ljava/net/http/HttpHeaders;", nullptr, $PRIVATE | $FINAL, $field(ResponseInfoImpl, headers$)},
	{"version", "Ljava/net/http/HttpClient$Version;", nullptr, $PRIVATE | $FINAL, $field(ResponseInfoImpl, version$)},
	{}
};

$MethodInfo _ResponseInfoImpl_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Response;)V", nullptr, 0, $method(static_cast<void(ResponseInfoImpl::*)($Response*)>(&ResponseInfoImpl::init$))},
	{"<init>", "(ILjava/net/http/HttpHeaders;Ljava/net/http/HttpClient$Version;)V", nullptr, 0, $method(static_cast<void(ResponseInfoImpl::*)(int32_t,$HttpHeaders*,$HttpClient$Version*)>(&ResponseInfoImpl::init$))},
	{"headers", "()Ljava/net/http/HttpHeaders;", nullptr, $PUBLIC},
	{"statusCode", "()I", nullptr, $PUBLIC},
	{"version", "()Ljava/net/http/HttpClient$Version;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _ResponseInfoImpl_InnerClassesInfo_[] = {
	{"java.net.http.HttpResponse$ResponseInfo", "java.net.http.HttpResponse", "ResponseInfo", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseInfoImpl_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.ResponseInfoImpl",
	"java.lang.Object",
	"java.net.http.HttpResponse$ResponseInfo",
	_ResponseInfoImpl_FieldInfo_,
	_ResponseInfoImpl_MethodInfo_,
	nullptr,
	nullptr,
	_ResponseInfoImpl_InnerClassesInfo_
};

$Object* allocate$ResponseInfoImpl($Class* clazz) {
	return $of($alloc(ResponseInfoImpl));
}

void ResponseInfoImpl::init$($Response* response) {
	this->statusCode$ = $nc(response)->statusCode();
	$set(this, headers$, response->headers());
	$set(this, version$, response->version());
}

void ResponseInfoImpl::init$(int32_t statusCode, $HttpHeaders* headers, $HttpClient$Version* version) {
	this->statusCode$ = statusCode;
	$set(this, headers$, headers);
	$set(this, version$, version);
}

int32_t ResponseInfoImpl::statusCode() {
	return this->statusCode$;
}

$HttpHeaders* ResponseInfoImpl::headers() {
	return this->headers$;
}

$HttpClient$Version* ResponseInfoImpl::version() {
	return this->version$;
}

ResponseInfoImpl::ResponseInfoImpl() {
}

$Class* ResponseInfoImpl::load$($String* name, bool initialize) {
	$loadClass(ResponseInfoImpl, name, initialize, &_ResponseInfoImpl_ClassInfo_, allocate$ResponseInfoImpl);
	return class$;
}

$Class* ResponseInfoImpl::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk