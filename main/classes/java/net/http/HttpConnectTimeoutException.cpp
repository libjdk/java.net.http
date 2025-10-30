#include <java/net/http/HttpConnectTimeoutException.h>

#include <java/net/http/HttpTimeoutException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpTimeoutException = ::java::net::http::HttpTimeoutException;

namespace java {
	namespace net {
		namespace http {

$FieldInfo _HttpConnectTimeoutException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HttpConnectTimeoutException, serialVersionUID)},
	{}
};

$MethodInfo _HttpConnectTimeoutException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpConnectTimeoutException::*)($String*)>(&HttpConnectTimeoutException::init$))},
	{}
};

$ClassInfo _HttpConnectTimeoutException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.net.http.HttpConnectTimeoutException",
	"java.net.http.HttpTimeoutException",
	nullptr,
	_HttpConnectTimeoutException_FieldInfo_,
	_HttpConnectTimeoutException_MethodInfo_
};

$Object* allocate$HttpConnectTimeoutException($Class* clazz) {
	return $of($alloc(HttpConnectTimeoutException));
}

void HttpConnectTimeoutException::init$($String* message) {
	$HttpTimeoutException::init$(message);
}

HttpConnectTimeoutException::HttpConnectTimeoutException() {
}

HttpConnectTimeoutException::HttpConnectTimeoutException(const HttpConnectTimeoutException& e) : $HttpTimeoutException(e) {
}

void HttpConnectTimeoutException::throw$() {
	throw *this;
}

$Class* HttpConnectTimeoutException::load$($String* name, bool initialize) {
	$loadClass(HttpConnectTimeoutException, name, initialize, &_HttpConnectTimeoutException_ClassInfo_, allocate$HttpConnectTimeoutException);
	return class$;
}

$Class* HttpConnectTimeoutException::class$ = nullptr;

		} // http
	} // net
} // java