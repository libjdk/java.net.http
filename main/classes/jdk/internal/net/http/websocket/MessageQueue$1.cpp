#include <jdk/internal/net/http/websocket/MessageQueue$1.h>

#include <java/lang/NoSuchFieldError.h>
#include <jdk/internal/net/http/websocket/MessageQueue$Type.h>
#include <jdk/internal/net/http/websocket/MessageQueue.h>
#include <jcpp.h>

#undef BINARY
#undef CLOSE
#undef PING
#undef PONG
#undef TEXT

using $MessageQueue$TypeArray = $Array<::jdk::internal::net::http::websocket::MessageQueue$Type>;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $NoSuchFieldError = ::java::lang::NoSuchFieldError;
using $MessageQueue = ::jdk::internal::net::http::websocket::MessageQueue;
using $MessageQueue$Type = ::jdk::internal::net::http::websocket::MessageQueue$Type;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _MessageQueue$1_FieldInfo_[] = {
	{"$SwitchMap$jdk$internal$net$http$websocket$MessageQueue$Type", "[I", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(MessageQueue$1, $SwitchMap$jdk$internal$net$http$websocket$MessageQueue$Type)},
	{}
};

$EnclosingMethodInfo _MessageQueue$1_EnclosingMethodInfo_ = {
	"jdk.internal.net.http.websocket.MessageQueue",
	nullptr,
	nullptr
};

$InnerClassInfo _MessageQueue$1_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.MessageQueue$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _MessageQueue$1_ClassInfo_ = {
	$ACC_SUPER | $SYNTHETIC,
	"jdk.internal.net.http.websocket.MessageQueue$1",
	"java.lang.Object",
	nullptr,
	_MessageQueue$1_FieldInfo_,
	nullptr,
	nullptr,
	&_MessageQueue$1_EnclosingMethodInfo_,
	_MessageQueue$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.MessageQueue"
};

$Object* allocate$MessageQueue$1($Class* clazz) {
	return $of($alloc(MessageQueue$1));
}

$ints* MessageQueue$1::$SwitchMap$jdk$internal$net$http$websocket$MessageQueue$Type = nullptr;

void clinit$MessageQueue$1($Class* class$) {
	$assignStatic(MessageQueue$1::$SwitchMap$jdk$internal$net$http$websocket$MessageQueue$Type, $new($ints, $($MessageQueue$Type::values())->length));
	{
		try {
			$nc(MessageQueue$1::$SwitchMap$jdk$internal$net$http$websocket$MessageQueue$Type)->set($MessageQueue$Type::TEXT->ordinal(), 1);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(MessageQueue$1::$SwitchMap$jdk$internal$net$http$websocket$MessageQueue$Type)->set($MessageQueue$Type::BINARY->ordinal(), 2);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(MessageQueue$1::$SwitchMap$jdk$internal$net$http$websocket$MessageQueue$Type)->set($MessageQueue$Type::PING->ordinal(), 3);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(MessageQueue$1::$SwitchMap$jdk$internal$net$http$websocket$MessageQueue$Type)->set($MessageQueue$Type::PONG->ordinal(), 4);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(MessageQueue$1::$SwitchMap$jdk$internal$net$http$websocket$MessageQueue$Type)->set($MessageQueue$Type::CLOSE->ordinal(), 5);
		} catch ($NoSuchFieldError& ex) {
		}
	}
}

MessageQueue$1::MessageQueue$1() {
}

$Class* MessageQueue$1::load$($String* name, bool initialize) {
	$loadClass(MessageQueue$1, name, initialize, &_MessageQueue$1_ClassInfo_, clinit$MessageQueue$1, allocate$MessageQueue$1);
	return class$;
}

$Class* MessageQueue$1::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk