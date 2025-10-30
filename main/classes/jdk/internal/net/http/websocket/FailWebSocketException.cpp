#include <jdk/internal/net/http/websocket/FailWebSocketException.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _FailWebSocketException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FailWebSocketException, serialVersionUID)},
	{"statusCode", "I", nullptr, $PRIVATE | $FINAL, $field(FailWebSocketException, statusCode)},
	{}
};

$MethodInfo _FailWebSocketException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, 0, $method(static_cast<void(FailWebSocketException::*)($String*)>(&FailWebSocketException::init$))},
	{"<init>", "(Ljava/lang/String;I)V", nullptr, 0, $method(static_cast<void(FailWebSocketException::*)($String*,int32_t)>(&FailWebSocketException::init$))},
	{"getStatusCode", "()I", nullptr, 0, $method(static_cast<int32_t(FailWebSocketException::*)()>(&FailWebSocketException::getStatusCode))},
	{"initCause", "(Ljava/lang/Throwable;)Ljdk/internal/net/http/websocket/FailWebSocketException;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _FailWebSocketException_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.websocket.FailWebSocketException",
	"java.lang.RuntimeException",
	nullptr,
	_FailWebSocketException_FieldInfo_,
	_FailWebSocketException_MethodInfo_
};

$Object* allocate$FailWebSocketException($Class* clazz) {
	return $of($alloc(FailWebSocketException));
}

void FailWebSocketException::init$($String* detail) {
	FailWebSocketException::init$(detail, 1002);
}

void FailWebSocketException::init$($String* detail, int32_t statusCode) {
	$RuntimeException::init$(detail);
	this->statusCode = statusCode;
}

int32_t FailWebSocketException::getStatusCode() {
	return this->statusCode;
}

FailWebSocketException* FailWebSocketException::initCause($Throwable* cause) {
	return $cast(FailWebSocketException, $RuntimeException::initCause(cause));
}

FailWebSocketException::FailWebSocketException() {
}

FailWebSocketException::FailWebSocketException(const FailWebSocketException& e) : $RuntimeException(e) {
}

void FailWebSocketException::throw$() {
	throw *this;
}

$Class* FailWebSocketException::load$($String* name, bool initialize) {
	$loadClass(FailWebSocketException, name, initialize, &_FailWebSocketException_ClassInfo_, allocate$FailWebSocketException);
	return class$;
}

$Class* FailWebSocketException::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk