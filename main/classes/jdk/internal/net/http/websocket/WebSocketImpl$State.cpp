#include <jdk/internal/net/http/websocket/WebSocketImpl$State.h>

#include <java/lang/Enum.h>
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
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $WebSocketImpl = ::jdk::internal::net::http::websocket::WebSocketImpl;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _WebSocketImpl$State_FieldInfo_[] = {
	{"OPEN", "Ljdk/internal/net/http/websocket/WebSocketImpl$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(WebSocketImpl$State, OPEN)},
	{"IDLE", "Ljdk/internal/net/http/websocket/WebSocketImpl$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(WebSocketImpl$State, IDLE)},
	{"WAITING", "Ljdk/internal/net/http/websocket/WebSocketImpl$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(WebSocketImpl$State, WAITING)},
	{"TEXT", "Ljdk/internal/net/http/websocket/WebSocketImpl$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(WebSocketImpl$State, TEXT)},
	{"BINARY", "Ljdk/internal/net/http/websocket/WebSocketImpl$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(WebSocketImpl$State, BINARY)},
	{"PING", "Ljdk/internal/net/http/websocket/WebSocketImpl$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(WebSocketImpl$State, PING)},
	{"PONG", "Ljdk/internal/net/http/websocket/WebSocketImpl$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(WebSocketImpl$State, PONG)},
	{"CLOSE", "Ljdk/internal/net/http/websocket/WebSocketImpl$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(WebSocketImpl$State, CLOSE)},
	{"ERROR", "Ljdk/internal/net/http/websocket/WebSocketImpl$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(WebSocketImpl$State, ERROR)},
	{"$VALUES", "[Ljdk/internal/net/http/websocket/WebSocketImpl$State;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(WebSocketImpl$State, $VALUES)},
	{}
};

$MethodInfo _WebSocketImpl$State_MethodInfo_[] = {
	{"$values", "()[Ljdk/internal/net/http/websocket/WebSocketImpl$State;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$WebSocketImpl$StateArray*(*)()>(&WebSocketImpl$State::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(WebSocketImpl$State::*)($String*,int32_t)>(&WebSocketImpl$State::init$))},
	{"valueOf", "(Ljava/lang/String;)Ljdk/internal/net/http/websocket/WebSocketImpl$State;", nullptr, $PUBLIC | $STATIC, $method(static_cast<WebSocketImpl$State*(*)($String*)>(&WebSocketImpl$State::valueOf))},
	{"values", "()[Ljdk/internal/net/http/websocket/WebSocketImpl$State;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$WebSocketImpl$StateArray*(*)()>(&WebSocketImpl$State::values))},
	{}
};

$InnerClassInfo _WebSocketImpl$State_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.WebSocketImpl$State", "jdk.internal.net.http.websocket.WebSocketImpl", "State", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _WebSocketImpl$State_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"jdk.internal.net.http.websocket.WebSocketImpl$State",
	"java.lang.Enum",
	nullptr,
	_WebSocketImpl$State_FieldInfo_,
	_WebSocketImpl$State_MethodInfo_,
	"Ljava/lang/Enum<Ljdk/internal/net/http/websocket/WebSocketImpl$State;>;",
	nullptr,
	_WebSocketImpl$State_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.WebSocketImpl"
};

$Object* allocate$WebSocketImpl$State($Class* clazz) {
	return $of($alloc(WebSocketImpl$State));
}

WebSocketImpl$State* WebSocketImpl$State::OPEN = nullptr;
WebSocketImpl$State* WebSocketImpl$State::IDLE = nullptr;
WebSocketImpl$State* WebSocketImpl$State::WAITING = nullptr;
WebSocketImpl$State* WebSocketImpl$State::TEXT = nullptr;
WebSocketImpl$State* WebSocketImpl$State::BINARY = nullptr;
WebSocketImpl$State* WebSocketImpl$State::PING = nullptr;
WebSocketImpl$State* WebSocketImpl$State::PONG = nullptr;
WebSocketImpl$State* WebSocketImpl$State::CLOSE = nullptr;
WebSocketImpl$State* WebSocketImpl$State::ERROR = nullptr;
$WebSocketImpl$StateArray* WebSocketImpl$State::$VALUES = nullptr;

$WebSocketImpl$StateArray* WebSocketImpl$State::$values() {
	$init(WebSocketImpl$State);
	return $new($WebSocketImpl$StateArray, {
		WebSocketImpl$State::OPEN,
		WebSocketImpl$State::IDLE,
		WebSocketImpl$State::WAITING,
		WebSocketImpl$State::TEXT,
		WebSocketImpl$State::BINARY,
		WebSocketImpl$State::PING,
		WebSocketImpl$State::PONG,
		WebSocketImpl$State::CLOSE,
		WebSocketImpl$State::ERROR
	});
}

$WebSocketImpl$StateArray* WebSocketImpl$State::values() {
	$init(WebSocketImpl$State);
	return $cast($WebSocketImpl$StateArray, WebSocketImpl$State::$VALUES->clone());
}

WebSocketImpl$State* WebSocketImpl$State::valueOf($String* name) {
	$init(WebSocketImpl$State);
	return $cast(WebSocketImpl$State, $Enum::valueOf(WebSocketImpl$State::class$, name));
}

void WebSocketImpl$State::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void clinit$WebSocketImpl$State($Class* class$) {
	$assignStatic(WebSocketImpl$State::OPEN, $new(WebSocketImpl$State, "OPEN"_s, 0));
	$assignStatic(WebSocketImpl$State::IDLE, $new(WebSocketImpl$State, "IDLE"_s, 1));
	$assignStatic(WebSocketImpl$State::WAITING, $new(WebSocketImpl$State, "WAITING"_s, 2));
	$assignStatic(WebSocketImpl$State::TEXT, $new(WebSocketImpl$State, "TEXT"_s, 3));
	$assignStatic(WebSocketImpl$State::BINARY, $new(WebSocketImpl$State, "BINARY"_s, 4));
	$assignStatic(WebSocketImpl$State::PING, $new(WebSocketImpl$State, "PING"_s, 5));
	$assignStatic(WebSocketImpl$State::PONG, $new(WebSocketImpl$State, "PONG"_s, 6));
	$assignStatic(WebSocketImpl$State::CLOSE, $new(WebSocketImpl$State, "CLOSE"_s, 7));
	$assignStatic(WebSocketImpl$State::ERROR, $new(WebSocketImpl$State, "ERROR"_s, 8));
	$assignStatic(WebSocketImpl$State::$VALUES, WebSocketImpl$State::$values());
}

WebSocketImpl$State::WebSocketImpl$State() {
}

$Class* WebSocketImpl$State::load$($String* name, bool initialize) {
	$loadClass(WebSocketImpl$State, name, initialize, &_WebSocketImpl$State_ClassInfo_, clinit$WebSocketImpl$State, allocate$WebSocketImpl$State);
	return class$;
}

$Class* WebSocketImpl$State::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk