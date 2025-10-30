#include <jdk/internal/net/http/Http2Connection$ALPNException.h>

#include <java/io/IOException.h>
#include <jdk/internal/net/http/AbstractAsyncSSLConnection.h>
#include <jdk/internal/net/http/Http2Connection.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractAsyncSSLConnection = ::jdk::internal::net::http::AbstractAsyncSSLConnection;
using $Http2Connection = ::jdk::internal::net::http::Http2Connection;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Http2Connection$ALPNException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Http2Connection$ALPNException, serialVersionUID)},
	{"connection", "Ljdk/internal/net/http/AbstractAsyncSSLConnection;", nullptr, $FINAL | $TRANSIENT, $field(Http2Connection$ALPNException, connection)},
	{}
};

$MethodInfo _Http2Connection$ALPNException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljdk/internal/net/http/AbstractAsyncSSLConnection;)V", nullptr, 0, $method(static_cast<void(Http2Connection$ALPNException::*)($String*,$AbstractAsyncSSLConnection*)>(&Http2Connection$ALPNException::init$))},
	{"getConnection", "()Ljdk/internal/net/http/AbstractAsyncSSLConnection;", nullptr, 0, $method(static_cast<$AbstractAsyncSSLConnection*(Http2Connection$ALPNException::*)()>(&Http2Connection$ALPNException::getConnection))},
	{}
};

$InnerClassInfo _Http2Connection$ALPNException_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http2Connection$ALPNException", "jdk.internal.net.http.Http2Connection", "ALPNException", $STATIC | $FINAL},
	{}
};

$ClassInfo _Http2Connection$ALPNException_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Http2Connection$ALPNException",
	"java.io.IOException",
	nullptr,
	_Http2Connection$ALPNException_FieldInfo_,
	_Http2Connection$ALPNException_MethodInfo_,
	nullptr,
	nullptr,
	_Http2Connection$ALPNException_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http2Connection"
};

$Object* allocate$Http2Connection$ALPNException($Class* clazz) {
	return $of($alloc(Http2Connection$ALPNException));
}

void Http2Connection$ALPNException::init$($String* msg, $AbstractAsyncSSLConnection* connection) {
	$IOException::init$(msg);
	$set(this, connection, connection);
}

$AbstractAsyncSSLConnection* Http2Connection$ALPNException::getConnection() {
	return this->connection;
}

Http2Connection$ALPNException::Http2Connection$ALPNException() {
}

Http2Connection$ALPNException::Http2Connection$ALPNException(const Http2Connection$ALPNException& e) : $IOException(e) {
}

void Http2Connection$ALPNException::throw$() {
	throw *this;
}

$Class* Http2Connection$ALPNException::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$ALPNException, name, initialize, &_Http2Connection$ALPNException_ClassInfo_, allocate$Http2Connection$ALPNException);
	return class$;
}

$Class* Http2Connection$ALPNException::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk