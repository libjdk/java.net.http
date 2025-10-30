#include <jdk/internal/net/http/websocket/TransportImpl$ChannelState.h>

#include <java/lang/Enum.h>
#include <jdk/internal/net/http/websocket/TransportImpl.h>
#include <jcpp.h>

#undef AVAILABLE
#undef CLOSED
#undef UNREGISTERED
#undef WAITING

using $TransportImpl$ChannelStateArray = $Array<::jdk::internal::net::http::websocket::TransportImpl$ChannelState>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $TransportImpl = ::jdk::internal::net::http::websocket::TransportImpl;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _TransportImpl$ChannelState_FieldInfo_[] = {
	{"UNREGISTERED", "Ljdk/internal/net/http/websocket/TransportImpl$ChannelState;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(TransportImpl$ChannelState, UNREGISTERED)},
	{"AVAILABLE", "Ljdk/internal/net/http/websocket/TransportImpl$ChannelState;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(TransportImpl$ChannelState, AVAILABLE)},
	{"WAITING", "Ljdk/internal/net/http/websocket/TransportImpl$ChannelState;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(TransportImpl$ChannelState, WAITING)},
	{"CLOSED", "Ljdk/internal/net/http/websocket/TransportImpl$ChannelState;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(TransportImpl$ChannelState, CLOSED)},
	{"$VALUES", "[Ljdk/internal/net/http/websocket/TransportImpl$ChannelState;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(TransportImpl$ChannelState, $VALUES)},
	{}
};

$MethodInfo _TransportImpl$ChannelState_MethodInfo_[] = {
	{"$values", "()[Ljdk/internal/net/http/websocket/TransportImpl$ChannelState;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$TransportImpl$ChannelStateArray*(*)()>(&TransportImpl$ChannelState::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(TransportImpl$ChannelState::*)($String*,int32_t)>(&TransportImpl$ChannelState::init$))},
	{"valueOf", "(Ljava/lang/String;)Ljdk/internal/net/http/websocket/TransportImpl$ChannelState;", nullptr, $PUBLIC | $STATIC, $method(static_cast<TransportImpl$ChannelState*(*)($String*)>(&TransportImpl$ChannelState::valueOf))},
	{"values", "()[Ljdk/internal/net/http/websocket/TransportImpl$ChannelState;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$TransportImpl$ChannelStateArray*(*)()>(&TransportImpl$ChannelState::values))},
	{}
};

$InnerClassInfo _TransportImpl$ChannelState_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.TransportImpl$ChannelState", "jdk.internal.net.http.websocket.TransportImpl", "ChannelState", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _TransportImpl$ChannelState_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"jdk.internal.net.http.websocket.TransportImpl$ChannelState",
	"java.lang.Enum",
	nullptr,
	_TransportImpl$ChannelState_FieldInfo_,
	_TransportImpl$ChannelState_MethodInfo_,
	"Ljava/lang/Enum<Ljdk/internal/net/http/websocket/TransportImpl$ChannelState;>;",
	nullptr,
	_TransportImpl$ChannelState_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.TransportImpl"
};

$Object* allocate$TransportImpl$ChannelState($Class* clazz) {
	return $of($alloc(TransportImpl$ChannelState));
}

TransportImpl$ChannelState* TransportImpl$ChannelState::UNREGISTERED = nullptr;
TransportImpl$ChannelState* TransportImpl$ChannelState::AVAILABLE = nullptr;
TransportImpl$ChannelState* TransportImpl$ChannelState::WAITING = nullptr;
TransportImpl$ChannelState* TransportImpl$ChannelState::CLOSED = nullptr;
$TransportImpl$ChannelStateArray* TransportImpl$ChannelState::$VALUES = nullptr;

$TransportImpl$ChannelStateArray* TransportImpl$ChannelState::$values() {
	$init(TransportImpl$ChannelState);
	return $new($TransportImpl$ChannelStateArray, {
		TransportImpl$ChannelState::UNREGISTERED,
		TransportImpl$ChannelState::AVAILABLE,
		TransportImpl$ChannelState::WAITING,
		TransportImpl$ChannelState::CLOSED
	});
}

$TransportImpl$ChannelStateArray* TransportImpl$ChannelState::values() {
	$init(TransportImpl$ChannelState);
	return $cast($TransportImpl$ChannelStateArray, TransportImpl$ChannelState::$VALUES->clone());
}

TransportImpl$ChannelState* TransportImpl$ChannelState::valueOf($String* name) {
	$init(TransportImpl$ChannelState);
	return $cast(TransportImpl$ChannelState, $Enum::valueOf(TransportImpl$ChannelState::class$, name));
}

void TransportImpl$ChannelState::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void clinit$TransportImpl$ChannelState($Class* class$) {
	$assignStatic(TransportImpl$ChannelState::UNREGISTERED, $new(TransportImpl$ChannelState, "UNREGISTERED"_s, 0));
	$assignStatic(TransportImpl$ChannelState::AVAILABLE, $new(TransportImpl$ChannelState, "AVAILABLE"_s, 1));
	$assignStatic(TransportImpl$ChannelState::WAITING, $new(TransportImpl$ChannelState, "WAITING"_s, 2));
	$assignStatic(TransportImpl$ChannelState::CLOSED, $new(TransportImpl$ChannelState, "CLOSED"_s, 3));
	$assignStatic(TransportImpl$ChannelState::$VALUES, TransportImpl$ChannelState::$values());
}

TransportImpl$ChannelState::TransportImpl$ChannelState() {
}

$Class* TransportImpl$ChannelState::load$($String* name, bool initialize) {
	$loadClass(TransportImpl$ChannelState, name, initialize, &_TransportImpl$ChannelState_ClassInfo_, clinit$TransportImpl$ChannelState, allocate$TransportImpl$ChannelState);
	return class$;
}

$Class* TransportImpl$ChannelState::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk