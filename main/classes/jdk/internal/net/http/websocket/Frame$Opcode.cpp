#include <jdk/internal/net/http/websocket/Frame$Opcode.h>

#include <java/lang/Enum.h>
#include <jdk/internal/net/http/websocket/Frame.h>
#include <jcpp.h>

#undef BINARY
#undef CLOSE
#undef CONTINUATION
#undef PING
#undef PONG
#undef TEXT

using $Frame$OpcodeArray = $Array<::jdk::internal::net::http::websocket::Frame$Opcode>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Frame = ::jdk::internal::net::http::websocket::Frame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _Frame$Opcode_FieldInfo_[] = {
	{"CONTINUATION", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, CONTINUATION)},
	{"TEXT", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, TEXT)},
	{"BINARY", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, BINARY)},
	{"NON_CONTROL_0x3", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, NON_CONTROL_0x3)},
	{"NON_CONTROL_0x4", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, NON_CONTROL_0x4)},
	{"NON_CONTROL_0x5", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, NON_CONTROL_0x5)},
	{"NON_CONTROL_0x6", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, NON_CONTROL_0x6)},
	{"NON_CONTROL_0x7", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, NON_CONTROL_0x7)},
	{"CLOSE", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, CLOSE)},
	{"PING", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, PING)},
	{"PONG", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, PONG)},
	{"CONTROL_0xB", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, CONTROL_0xB)},
	{"CONTROL_0xC", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, CONTROL_0xC)},
	{"CONTROL_0xD", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, CONTROL_0xD)},
	{"CONTROL_0xE", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, CONTROL_0xE)},
	{"CONTROL_0xF", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Frame$Opcode, CONTROL_0xF)},
	{"$VALUES", "[Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(Frame$Opcode, $VALUES)},
	{"opcodes", "[Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Frame$Opcode, opcodes)},
	{"code", "B", nullptr, $PRIVATE | $FINAL, $field(Frame$Opcode, code)},
	{}
};

$MethodInfo _Frame$Opcode_MethodInfo_[] = {
	{"$values", "()[Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Frame$OpcodeArray*(*)()>(&Frame$Opcode::$values))},
	{"<init>", "(Ljava/lang/String;II)V", "(I)V", $PRIVATE, $method(static_cast<void(Frame$Opcode::*)($String*,int32_t,int32_t)>(&Frame$Opcode::init$))},
	{"isControl", "()Z", nullptr, 0, $method(static_cast<bool(Frame$Opcode::*)()>(&Frame$Opcode::isControl))},
	{"ofCode", "(I)Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $STATIC, $method(static_cast<Frame$Opcode*(*)(int32_t)>(&Frame$Opcode::ofCode))},
	{"valueOf", "(Ljava/lang/String;)Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Frame$Opcode*(*)($String*)>(&Frame$Opcode::valueOf))},
	{"values", "()[Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Frame$OpcodeArray*(*)()>(&Frame$Opcode::values))},
	{}
};

$InnerClassInfo _Frame$Opcode_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.Frame$Opcode", "jdk.internal.net.http.websocket.Frame", "Opcode", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _Frame$Opcode_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"jdk.internal.net.http.websocket.Frame$Opcode",
	"java.lang.Enum",
	nullptr,
	_Frame$Opcode_FieldInfo_,
	_Frame$Opcode_MethodInfo_,
	"Ljava/lang/Enum<Ljdk/internal/net/http/websocket/Frame$Opcode;>;",
	nullptr,
	_Frame$Opcode_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.Frame"
};

$Object* allocate$Frame$Opcode($Class* clazz) {
	return $of($alloc(Frame$Opcode));
}

Frame$Opcode* Frame$Opcode::CONTINUATION = nullptr;
Frame$Opcode* Frame$Opcode::TEXT = nullptr;
Frame$Opcode* Frame$Opcode::BINARY = nullptr;
Frame$Opcode* Frame$Opcode::NON_CONTROL_0x3 = nullptr;
Frame$Opcode* Frame$Opcode::NON_CONTROL_0x4 = nullptr;
Frame$Opcode* Frame$Opcode::NON_CONTROL_0x5 = nullptr;
Frame$Opcode* Frame$Opcode::NON_CONTROL_0x6 = nullptr;
Frame$Opcode* Frame$Opcode::NON_CONTROL_0x7 = nullptr;
Frame$Opcode* Frame$Opcode::CLOSE = nullptr;
Frame$Opcode* Frame$Opcode::PING = nullptr;
Frame$Opcode* Frame$Opcode::PONG = nullptr;
Frame$Opcode* Frame$Opcode::CONTROL_0xB = nullptr;
Frame$Opcode* Frame$Opcode::CONTROL_0xC = nullptr;
Frame$Opcode* Frame$Opcode::CONTROL_0xD = nullptr;
Frame$Opcode* Frame$Opcode::CONTROL_0xE = nullptr;
Frame$Opcode* Frame$Opcode::CONTROL_0xF = nullptr;
$Frame$OpcodeArray* Frame$Opcode::$VALUES = nullptr;
$Frame$OpcodeArray* Frame$Opcode::opcodes = nullptr;

$Frame$OpcodeArray* Frame$Opcode::$values() {
	$init(Frame$Opcode);
	return $new($Frame$OpcodeArray, {
		Frame$Opcode::CONTINUATION,
		Frame$Opcode::TEXT,
		Frame$Opcode::BINARY,
		Frame$Opcode::NON_CONTROL_0x3,
		Frame$Opcode::NON_CONTROL_0x4,
		Frame$Opcode::NON_CONTROL_0x5,
		Frame$Opcode::NON_CONTROL_0x6,
		Frame$Opcode::NON_CONTROL_0x7,
		Frame$Opcode::CLOSE,
		Frame$Opcode::PING,
		Frame$Opcode::PONG,
		Frame$Opcode::CONTROL_0xB,
		Frame$Opcode::CONTROL_0xC,
		Frame$Opcode::CONTROL_0xD,
		Frame$Opcode::CONTROL_0xE,
		Frame$Opcode::CONTROL_0xF
	});
}

$Frame$OpcodeArray* Frame$Opcode::values() {
	$init(Frame$Opcode);
	return $cast($Frame$OpcodeArray, Frame$Opcode::$VALUES->clone());
}

Frame$Opcode* Frame$Opcode::valueOf($String* name) {
	$init(Frame$Opcode);
	return $cast(Frame$Opcode, $Enum::valueOf(Frame$Opcode::class$, name));
}

void Frame$Opcode::init$($String* $enum$name, int32_t $enum$ordinal, int32_t code) {
	$Enum::init$($enum$name, $enum$ordinal);
	this->code = (int8_t)code;
}

bool Frame$Opcode::isControl() {
	return ((int32_t)(this->code & (uint32_t)8)) != 0;
}

Frame$Opcode* Frame$Opcode::ofCode(int32_t code) {
	$init(Frame$Opcode);
	return $nc(Frame$Opcode::opcodes)->get((int32_t)(code & (uint32_t)15));
}

void clinit$Frame$Opcode($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(Frame$Opcode::CONTINUATION, $new(Frame$Opcode, "CONTINUATION"_s, 0, 0));
	$assignStatic(Frame$Opcode::TEXT, $new(Frame$Opcode, "TEXT"_s, 1, 1));
	$assignStatic(Frame$Opcode::BINARY, $new(Frame$Opcode, "BINARY"_s, 2, 2));
	$assignStatic(Frame$Opcode::NON_CONTROL_0x3, $new(Frame$Opcode, "NON_CONTROL_0x3"_s, 3, 3));
	$assignStatic(Frame$Opcode::NON_CONTROL_0x4, $new(Frame$Opcode, "NON_CONTROL_0x4"_s, 4, 4));
	$assignStatic(Frame$Opcode::NON_CONTROL_0x5, $new(Frame$Opcode, "NON_CONTROL_0x5"_s, 5, 5));
	$assignStatic(Frame$Opcode::NON_CONTROL_0x6, $new(Frame$Opcode, "NON_CONTROL_0x6"_s, 6, 6));
	$assignStatic(Frame$Opcode::NON_CONTROL_0x7, $new(Frame$Opcode, "NON_CONTROL_0x7"_s, 7, 7));
	$assignStatic(Frame$Opcode::CLOSE, $new(Frame$Opcode, "CLOSE"_s, 8, 8));
	$assignStatic(Frame$Opcode::PING, $new(Frame$Opcode, "PING"_s, 9, 9));
	$assignStatic(Frame$Opcode::PONG, $new(Frame$Opcode, "PONG"_s, 10, 10));
	$assignStatic(Frame$Opcode::CONTROL_0xB, $new(Frame$Opcode, "CONTROL_0xB"_s, 11, 11));
	$assignStatic(Frame$Opcode::CONTROL_0xC, $new(Frame$Opcode, "CONTROL_0xC"_s, 12, 12));
	$assignStatic(Frame$Opcode::CONTROL_0xD, $new(Frame$Opcode, "CONTROL_0xD"_s, 13, 13));
	$assignStatic(Frame$Opcode::CONTROL_0xE, $new(Frame$Opcode, "CONTROL_0xE"_s, 14, 14));
	$assignStatic(Frame$Opcode::CONTROL_0xF, $new(Frame$Opcode, "CONTROL_0xF"_s, 15, 15));
	$assignStatic(Frame$Opcode::$VALUES, Frame$Opcode::$values());
	{
		$var($Frame$OpcodeArray, values, Frame$Opcode::values());
		$assignStatic(Frame$Opcode::opcodes, $new($Frame$OpcodeArray, $nc(values)->length));
		{
			$var($Frame$OpcodeArray, arr$, values);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				Frame$Opcode* c = arr$->get(i$);
				{
					$nc(Frame$Opcode::opcodes)->set($nc(c)->code, c);
				}
			}
		}
	}
}

Frame$Opcode::Frame$Opcode() {
}

$Class* Frame$Opcode::load$($String* name, bool initialize) {
	$loadClass(Frame$Opcode, name, initialize, &_Frame$Opcode_ClassInfo_, clinit$Frame$Opcode, allocate$Frame$Opcode);
	return class$;
}

$Class* Frame$Opcode::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk