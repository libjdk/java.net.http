#include <jdk/internal/net/http/common/ConnectionExpiredException.h>

#include <java/io/IOException.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _ConnectionExpiredException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConnectionExpiredException, serialVersionUID)},
	{}
};

$MethodInfo _ConnectionExpiredException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(static_cast<void(ConnectionExpiredException::*)($Throwable*)>(&ConnectionExpiredException::init$))},
	{}
};

$ClassInfo _ConnectionExpiredException_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.ConnectionExpiredException",
	"java.io.IOException",
	nullptr,
	_ConnectionExpiredException_FieldInfo_,
	_ConnectionExpiredException_MethodInfo_
};

$Object* allocate$ConnectionExpiredException($Class* clazz) {
	return $of($alloc(ConnectionExpiredException));
}

void ConnectionExpiredException::init$($Throwable* cause) {
	$IOException::init$("subscription is finished"_s, cause);
}

ConnectionExpiredException::ConnectionExpiredException() {
}

ConnectionExpiredException::ConnectionExpiredException(const ConnectionExpiredException& e) : $IOException(e) {
}

void ConnectionExpiredException::throw$() {
	throw *this;
}

$Class* ConnectionExpiredException::load$($String* name, bool initialize) {
	$loadClass(ConnectionExpiredException, name, initialize, &_ConnectionExpiredException_ClassInfo_, allocate$ConnectionExpiredException);
	return class$;
}

$Class* ConnectionExpiredException::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk