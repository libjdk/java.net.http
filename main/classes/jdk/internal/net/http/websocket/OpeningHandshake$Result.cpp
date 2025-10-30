#include <jdk/internal/net/http/websocket/OpeningHandshake$Result.h>

#include <jdk/internal/net/http/websocket/OpeningHandshake.h>
#include <jdk/internal/net/http/websocket/TransportFactory.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $OpeningHandshake = ::jdk::internal::net::http::websocket::OpeningHandshake;
using $TransportFactory = ::jdk::internal::net::http::websocket::TransportFactory;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _OpeningHandshake$Result_FieldInfo_[] = {
	{"subprotocol", "Ljava/lang/String;", nullptr, $FINAL, $field(OpeningHandshake$Result, subprotocol)},
	{"transport", "Ljdk/internal/net/http/websocket/TransportFactory;", nullptr, $FINAL, $field(OpeningHandshake$Result, transport)},
	{}
};

$MethodInfo _OpeningHandshake$Result_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljdk/internal/net/http/websocket/TransportFactory;)V", nullptr, $PRIVATE, $method(static_cast<void(OpeningHandshake$Result::*)($String*,$TransportFactory*)>(&OpeningHandshake$Result::init$))},
	{}
};

$InnerClassInfo _OpeningHandshake$Result_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.OpeningHandshake$Result", "jdk.internal.net.http.websocket.OpeningHandshake", "Result", $STATIC | $FINAL},
	{}
};

$ClassInfo _OpeningHandshake$Result_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.websocket.OpeningHandshake$Result",
	"java.lang.Object",
	nullptr,
	_OpeningHandshake$Result_FieldInfo_,
	_OpeningHandshake$Result_MethodInfo_,
	nullptr,
	nullptr,
	_OpeningHandshake$Result_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.OpeningHandshake"
};

$Object* allocate$OpeningHandshake$Result($Class* clazz) {
	return $of($alloc(OpeningHandshake$Result));
}

void OpeningHandshake$Result::init$($String* subprotocol, $TransportFactory* transport) {
	$set(this, subprotocol, subprotocol);
	$set(this, transport, transport);
}

OpeningHandshake$Result::OpeningHandshake$Result() {
}

$Class* OpeningHandshake$Result::load$($String* name, bool initialize) {
	$loadClass(OpeningHandshake$Result, name, initialize, &_OpeningHandshake$Result_ClassInfo_, allocate$OpeningHandshake$Result);
	return class$;
}

$Class* OpeningHandshake$Result::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk