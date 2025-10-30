#include <java/net/http/HttpTimeoutException.h>

#include <java/io/IOException.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace java {
	namespace net {
		namespace http {

$FieldInfo _HttpTimeoutException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HttpTimeoutException, serialVersionUID)},
	{}
};

$MethodInfo _HttpTimeoutException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpTimeoutException::*)($String*)>(&HttpTimeoutException::init$))},
	{}
};

$ClassInfo _HttpTimeoutException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.net.http.HttpTimeoutException",
	"java.io.IOException",
	nullptr,
	_HttpTimeoutException_FieldInfo_,
	_HttpTimeoutException_MethodInfo_
};

$Object* allocate$HttpTimeoutException($Class* clazz) {
	return $of($alloc(HttpTimeoutException));
}

void HttpTimeoutException::init$($String* message) {
	$IOException::init$(message);
}

HttpTimeoutException::HttpTimeoutException() {
}

HttpTimeoutException::HttpTimeoutException(const HttpTimeoutException& e) : $IOException(e) {
}

void HttpTimeoutException::throw$() {
	throw *this;
}

$Class* HttpTimeoutException::load$($String* name, bool initialize) {
	$loadClass(HttpTimeoutException, name, initialize, &_HttpTimeoutException_ClassInfo_, allocate$HttpTimeoutException);
	return class$;
}

$Class* HttpTimeoutException::class$ = nullptr;

		} // http
	} // net
} // java