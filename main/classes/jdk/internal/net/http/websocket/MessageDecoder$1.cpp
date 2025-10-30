#include <jdk/internal/net/http/websocket/MessageDecoder$1.h>

#include <java/lang/NoSuchFieldError.h>
#include <jdk/internal/net/http/websocket/Frame$Opcode.h>
#include <jdk/internal/net/http/websocket/MessageDecoder.h>
#include <jcpp.h>

#undef CLOSE
#undef PING
#undef PONG

using $Frame$OpcodeArray = $Array<::jdk::internal::net::http::websocket::Frame$Opcode>;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $NoSuchFieldError = ::java::lang::NoSuchFieldError;
using $Frame$Opcode = ::jdk::internal::net::http::websocket::Frame$Opcode;
using $MessageDecoder = ::jdk::internal::net::http::websocket::MessageDecoder;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _MessageDecoder$1_FieldInfo_[] = {
	{"$SwitchMap$jdk$internal$net$http$websocket$Frame$Opcode", "[I", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(MessageDecoder$1, $SwitchMap$jdk$internal$net$http$websocket$Frame$Opcode)},
	{}
};

$EnclosingMethodInfo _MessageDecoder$1_EnclosingMethodInfo_ = {
	"jdk.internal.net.http.websocket.MessageDecoder",
	nullptr,
	nullptr
};

$InnerClassInfo _MessageDecoder$1_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.MessageDecoder$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _MessageDecoder$1_ClassInfo_ = {
	$ACC_SUPER | $SYNTHETIC,
	"jdk.internal.net.http.websocket.MessageDecoder$1",
	"java.lang.Object",
	nullptr,
	_MessageDecoder$1_FieldInfo_,
	nullptr,
	nullptr,
	&_MessageDecoder$1_EnclosingMethodInfo_,
	_MessageDecoder$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.MessageDecoder"
};

$Object* allocate$MessageDecoder$1($Class* clazz) {
	return $of($alloc(MessageDecoder$1));
}

$ints* MessageDecoder$1::$SwitchMap$jdk$internal$net$http$websocket$Frame$Opcode = nullptr;

void clinit$MessageDecoder$1($Class* class$) {
	$assignStatic(MessageDecoder$1::$SwitchMap$jdk$internal$net$http$websocket$Frame$Opcode, $new($ints, $($Frame$Opcode::values())->length));
	{
		try {
			$nc(MessageDecoder$1::$SwitchMap$jdk$internal$net$http$websocket$Frame$Opcode)->set($Frame$Opcode::CLOSE->ordinal(), 1);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(MessageDecoder$1::$SwitchMap$jdk$internal$net$http$websocket$Frame$Opcode)->set($Frame$Opcode::PING->ordinal(), 2);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(MessageDecoder$1::$SwitchMap$jdk$internal$net$http$websocket$Frame$Opcode)->set($Frame$Opcode::PONG->ordinal(), 3);
		} catch ($NoSuchFieldError& ex) {
		}
	}
}

MessageDecoder$1::MessageDecoder$1() {
}

$Class* MessageDecoder$1::load$($String* name, bool initialize) {
	$loadClass(MessageDecoder$1, name, initialize, &_MessageDecoder$1_ClassInfo_, clinit$MessageDecoder$1, allocate$MessageDecoder$1);
	return class$;
}

$Class* MessageDecoder$1::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk