#include <jdk/internal/net/http/common/ConnectionExpiredException.h>

#include <java/io/IOException.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
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

ConnectionExpiredException::ConnectionExpiredException(const ConnectionExpiredException& e) {
}

ConnectionExpiredException ConnectionExpiredException::wrapper$() {
	$pendingException(this);
	return *this;
}

void ConnectionExpiredException::throwWrapper$() {
	$pendingException(this);
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