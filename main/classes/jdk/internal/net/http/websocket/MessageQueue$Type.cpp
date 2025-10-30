#include <jdk/internal/net/http/websocket/MessageQueue$Type.h>

#include <java/lang/Enum.h>
#include <jdk/internal/net/http/websocket/MessageQueue.h>
#include <jcpp.h>

#undef BINARY
#undef CLOSE
#undef PING
#undef PONG
#undef TEXT

using $MessageQueue$TypeArray = $Array<::jdk::internal::net::http::websocket::MessageQueue$Type>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MessageQueue = ::jdk::internal::net::http::websocket::MessageQueue;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _MessageQueue$Type_FieldInfo_[] = {
	{"TEXT", "Ljdk/internal/net/http/websocket/MessageQueue$Type;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(MessageQueue$Type, TEXT)},
	{"BINARY", "Ljdk/internal/net/http/websocket/MessageQueue$Type;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(MessageQueue$Type, BINARY)},
	{"PING", "Ljdk/internal/net/http/websocket/MessageQueue$Type;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(MessageQueue$Type, PING)},
	{"PONG", "Ljdk/internal/net/http/websocket/MessageQueue$Type;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(MessageQueue$Type, PONG)},
	{"CLOSE", "Ljdk/internal/net/http/websocket/MessageQueue$Type;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(MessageQueue$Type, CLOSE)},
	{"$VALUES", "[Ljdk/internal/net/http/websocket/MessageQueue$Type;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(MessageQueue$Type, $VALUES)},
	{}
};

$MethodInfo _MessageQueue$Type_MethodInfo_[] = {
	{"$values", "()[Ljdk/internal/net/http/websocket/MessageQueue$Type;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$MessageQueue$TypeArray*(*)()>(&MessageQueue$Type::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(MessageQueue$Type::*)($String*,int32_t)>(&MessageQueue$Type::init$))},
	{"valueOf", "(Ljava/lang/String;)Ljdk/internal/net/http/websocket/MessageQueue$Type;", nullptr, $PUBLIC | $STATIC, $method(static_cast<MessageQueue$Type*(*)($String*)>(&MessageQueue$Type::valueOf))},
	{"values", "()[Ljdk/internal/net/http/websocket/MessageQueue$Type;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$MessageQueue$TypeArray*(*)()>(&MessageQueue$Type::values))},
	{}
};

$InnerClassInfo _MessageQueue$Type_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.MessageQueue$Type", "jdk.internal.net.http.websocket.MessageQueue", "Type", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _MessageQueue$Type_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"jdk.internal.net.http.websocket.MessageQueue$Type",
	"java.lang.Enum",
	nullptr,
	_MessageQueue$Type_FieldInfo_,
	_MessageQueue$Type_MethodInfo_,
	"Ljava/lang/Enum<Ljdk/internal/net/http/websocket/MessageQueue$Type;>;",
	nullptr,
	_MessageQueue$Type_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.MessageQueue"
};

$Object* allocate$MessageQueue$Type($Class* clazz) {
	return $of($alloc(MessageQueue$Type));
}

MessageQueue$Type* MessageQueue$Type::TEXT = nullptr;
MessageQueue$Type* MessageQueue$Type::BINARY = nullptr;
MessageQueue$Type* MessageQueue$Type::PING = nullptr;
MessageQueue$Type* MessageQueue$Type::PONG = nullptr;
MessageQueue$Type* MessageQueue$Type::CLOSE = nullptr;
$MessageQueue$TypeArray* MessageQueue$Type::$VALUES = nullptr;

$MessageQueue$TypeArray* MessageQueue$Type::$values() {
	$init(MessageQueue$Type);
	return $new($MessageQueue$TypeArray, {
		MessageQueue$Type::TEXT,
		MessageQueue$Type::BINARY,
		MessageQueue$Type::PING,
		MessageQueue$Type::PONG,
		MessageQueue$Type::CLOSE
	});
}

$MessageQueue$TypeArray* MessageQueue$Type::values() {
	$init(MessageQueue$Type);
	return $cast($MessageQueue$TypeArray, MessageQueue$Type::$VALUES->clone());
}

MessageQueue$Type* MessageQueue$Type::valueOf($String* name) {
	$init(MessageQueue$Type);
	return $cast(MessageQueue$Type, $Enum::valueOf(MessageQueue$Type::class$, name));
}

void MessageQueue$Type::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void clinit$MessageQueue$Type($Class* class$) {
	$assignStatic(MessageQueue$Type::TEXT, $new(MessageQueue$Type, "TEXT"_s, 0));
	$assignStatic(MessageQueue$Type::BINARY, $new(MessageQueue$Type, "BINARY"_s, 1));
	$assignStatic(MessageQueue$Type::PING, $new(MessageQueue$Type, "PING"_s, 2));
	$assignStatic(MessageQueue$Type::PONG, $new(MessageQueue$Type, "PONG"_s, 3));
	$assignStatic(MessageQueue$Type::CLOSE, $new(MessageQueue$Type, "CLOSE"_s, 4));
	$assignStatic(MessageQueue$Type::$VALUES, MessageQueue$Type::$values());
}

MessageQueue$Type::MessageQueue$Type() {
}

$Class* MessageQueue$Type::load$($String* name, bool initialize) {
	$loadClass(MessageQueue$Type, name, initialize, &_MessageQueue$Type_ClassInfo_, clinit$MessageQueue$Type, allocate$MessageQueue$Type);
	return class$;
}

$Class* MessageQueue$Type::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk