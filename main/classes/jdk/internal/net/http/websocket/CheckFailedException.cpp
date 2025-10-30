#include <jdk/internal/net/http/websocket/CheckFailedException.h>

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

$FieldInfo _CheckFailedException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(CheckFailedException, serialVersionUID)},
	{}
};

$MethodInfo _CheckFailedException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, 0, $method(static_cast<void(CheckFailedException::*)($String*)>(&CheckFailedException::init$))},
	{}
};

$ClassInfo _CheckFailedException_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.websocket.CheckFailedException",
	"java.lang.RuntimeException",
	nullptr,
	_CheckFailedException_FieldInfo_,
	_CheckFailedException_MethodInfo_
};

$Object* allocate$CheckFailedException($Class* clazz) {
	return $of($alloc(CheckFailedException));
}

void CheckFailedException::init$($String* message) {
	$RuntimeException::init$(message);
}

CheckFailedException::CheckFailedException() {
}

CheckFailedException::CheckFailedException(const CheckFailedException& e) : $RuntimeException(e) {
}

void CheckFailedException::throw$() {
	throw *this;
}

$Class* CheckFailedException::load$($String* name, bool initialize) {
	$loadClass(CheckFailedException, name, initialize, &_CheckFailedException_ClassInfo_, allocate$CheckFailedException);
	return class$;
}

$Class* CheckFailedException::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk