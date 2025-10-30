#include <jdk/internal/net/http/websocket/Frame.h>

#include <jcpp.h>

#undef MAX_CONTROL_FRAME_PAYLOAD_LENGTH
#undef MAX_HEADER_SIZE_BYTES

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _Frame_FieldInfo_[] = {
	{"MAX_HEADER_SIZE_BYTES", "I", nullptr, $STATIC | $FINAL, $constField(Frame, MAX_HEADER_SIZE_BYTES)},
	{"MAX_CONTROL_FRAME_PAYLOAD_LENGTH", "I", nullptr, $STATIC | $FINAL, $constField(Frame, MAX_CONTROL_FRAME_PAYLOAD_LENGTH)},
	{}
};

$MethodInfo _Frame_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Frame::*)()>(&Frame::init$))},
	{}
};

$InnerClassInfo _Frame_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.Frame$Reader", "jdk.internal.net.http.websocket.Frame", "Reader", $STATIC | $FINAL},
	{"jdk.internal.net.http.websocket.Frame$Consumer", "jdk.internal.net.http.websocket.Frame", "Consumer", $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.websocket.Frame$HeaderWriter", "jdk.internal.net.http.websocket.Frame", "HeaderWriter", $STATIC | $FINAL},
	{"jdk.internal.net.http.websocket.Frame$Masker", "jdk.internal.net.http.websocket.Frame", "Masker", $STATIC | $FINAL},
	{"jdk.internal.net.http.websocket.Frame$Opcode", "jdk.internal.net.http.websocket.Frame", "Opcode", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _Frame_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.websocket.Frame",
	"java.lang.Object",
	nullptr,
	_Frame_FieldInfo_,
	_Frame_MethodInfo_,
	nullptr,
	nullptr,
	_Frame_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.Frame$Reader,jdk.internal.net.http.websocket.Frame$Consumer,jdk.internal.net.http.websocket.Frame$HeaderWriter,jdk.internal.net.http.websocket.Frame$Masker,jdk.internal.net.http.websocket.Frame$Opcode"
};

$Object* allocate$Frame($Class* clazz) {
	return $of($alloc(Frame));
}

void Frame::init$() {
}

Frame::Frame() {
}

$Class* Frame::load$($String* name, bool initialize) {
	$loadClass(Frame, name, initialize, &_Frame_ClassInfo_, allocate$Frame);
	return class$;
}

$Class* Frame::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk