#include <jdk/internal/net/http/websocket/WebSocketImpl$1.h>

#include <java/lang/NoSuchFieldError.h>
#include <jdk/internal/net/http/websocket/WebSocketImpl$State.h>
#include <jdk/internal/net/http/websocket/WebSocketImpl.h>
#include <jcpp.h>

#undef BINARY
#undef CLOSE
#undef ERROR
#undef IDLE
#undef OPEN
#undef PING
#undef PONG
#undef TEXT
#undef WAITING

using $WebSocketImpl$StateArray = $Array<::jdk::internal::net::http::websocket::WebSocketImpl$State>;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $NoSuchFieldError = ::java::lang::NoSuchFieldError;
using $WebSocketImpl = ::jdk::internal::net::http::websocket::WebSocketImpl;
using $WebSocketImpl$State = ::jdk::internal::net::http::websocket::WebSocketImpl$State;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _WebSocketImpl$1_FieldInfo_[] = {
	{"$SwitchMap$jdk$internal$net$http$websocket$WebSocketImpl$State", "[I", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(WebSocketImpl$1, $SwitchMap$jdk$internal$net$http$websocket$WebSocketImpl$State)},
	{}
};

$EnclosingMethodInfo _WebSocketImpl$1_EnclosingMethodInfo_ = {
	"jdk.internal.net.http.websocket.WebSocketImpl",
	nullptr,
	nullptr
};

$InnerClassInfo _WebSocketImpl$1_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.WebSocketImpl$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _WebSocketImpl$1_ClassInfo_ = {
	$ACC_SUPER | $SYNTHETIC,
	"jdk.internal.net.http.websocket.WebSocketImpl$1",
	"java.lang.Object",
	nullptr,
	_WebSocketImpl$1_FieldInfo_,
	nullptr,
	nullptr,
	&_WebSocketImpl$1_EnclosingMethodInfo_,
	_WebSocketImpl$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.WebSocketImpl"
};

$Object* allocate$WebSocketImpl$1($Class* clazz) {
	return $of($alloc(WebSocketImpl$1));
}

$ints* WebSocketImpl$1::$SwitchMap$jdk$internal$net$http$websocket$WebSocketImpl$State = nullptr;

void clinit$WebSocketImpl$1($Class* class$) {
	$assignStatic(WebSocketImpl$1::$SwitchMap$jdk$internal$net$http$websocket$WebSocketImpl$State, $new($ints, $($WebSocketImpl$State::values())->length));
	{
		try {
			$nc(WebSocketImpl$1::$SwitchMap$jdk$internal$net$http$websocket$WebSocketImpl$State)->set($WebSocketImpl$State::OPEN->ordinal(), 1);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(WebSocketImpl$1::$SwitchMap$jdk$internal$net$http$websocket$WebSocketImpl$State)->set($WebSocketImpl$State::TEXT->ordinal(), 2);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(WebSocketImpl$1::$SwitchMap$jdk$internal$net$http$websocket$WebSocketImpl$State)->set($WebSocketImpl$State::BINARY->ordinal(), 3);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(WebSocketImpl$1::$SwitchMap$jdk$internal$net$http$websocket$WebSocketImpl$State)->set($WebSocketImpl$State::PING->ordinal(), 4);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(WebSocketImpl$1::$SwitchMap$jdk$internal$net$http$websocket$WebSocketImpl$State)->set($WebSocketImpl$State::PONG->ordinal(), 5);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(WebSocketImpl$1::$SwitchMap$jdk$internal$net$http$websocket$WebSocketImpl$State)->set($WebSocketImpl$State::CLOSE->ordinal(), 6);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(WebSocketImpl$1::$SwitchMap$jdk$internal$net$http$websocket$WebSocketImpl$State)->set($WebSocketImpl$State::ERROR->ordinal(), 7);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(WebSocketImpl$1::$SwitchMap$jdk$internal$net$http$websocket$WebSocketImpl$State)->set($WebSocketImpl$State::IDLE->ordinal(), 8);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(WebSocketImpl$1::$SwitchMap$jdk$internal$net$http$websocket$WebSocketImpl$State)->set($WebSocketImpl$State::WAITING->ordinal(), 9);
		} catch ($NoSuchFieldError& ex) {
		}
	}
}

WebSocketImpl$1::WebSocketImpl$1() {
}

$Class* WebSocketImpl$1::load$($String* name, bool initialize) {
	$loadClass(WebSocketImpl$1, name, initialize, &_WebSocketImpl$1_ClassInfo_, clinit$WebSocketImpl$1, allocate$WebSocketImpl$1);
	return class$;
}

$Class* WebSocketImpl$1::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk