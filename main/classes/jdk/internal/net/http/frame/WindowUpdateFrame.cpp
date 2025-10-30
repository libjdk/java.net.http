#include <jdk/internal/net/http/frame/WindowUpdateFrame.h>

#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jcpp.h>

#undef TYPE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

$FieldInfo _WindowUpdateFrame_FieldInfo_[] = {
	{"windowUpdate", "I", nullptr, $PRIVATE | $FINAL, $field(WindowUpdateFrame, windowUpdate)},
	{"TYPE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(WindowUpdateFrame, TYPE)},
	{}
};

$MethodInfo _WindowUpdateFrame_MethodInfo_[] = {
	{"<init>", "(II)V", nullptr, $PUBLIC, $method(static_cast<void(WindowUpdateFrame::*)(int32_t,int32_t)>(&WindowUpdateFrame::init$))},
	{"getUpdate", "()I", nullptr, $PUBLIC},
	{"length", "()I", nullptr, 0},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"type", "()I", nullptr, $PUBLIC},
	{}
};

$ClassInfo _WindowUpdateFrame_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.frame.WindowUpdateFrame",
	"jdk.internal.net.http.frame.Http2Frame",
	nullptr,
	_WindowUpdateFrame_FieldInfo_,
	_WindowUpdateFrame_MethodInfo_
};

$Object* allocate$WindowUpdateFrame($Class* clazz) {
	return $of($alloc(WindowUpdateFrame));
}

void WindowUpdateFrame::init$(int32_t streamid, int32_t windowUpdate) {
	$Http2Frame::init$(streamid, 0);
	this->windowUpdate = windowUpdate;
}

int32_t WindowUpdateFrame::type() {
	return WindowUpdateFrame::TYPE;
}

int32_t WindowUpdateFrame::length() {
	return 4;
}

$String* WindowUpdateFrame::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($($Http2Frame::toString()))->append(" WindowUpdate: "_s)->append(this->windowUpdate);
	return sb->toString();
}

int32_t WindowUpdateFrame::getUpdate() {
	return this->windowUpdate;
}

WindowUpdateFrame::WindowUpdateFrame() {
}

$Class* WindowUpdateFrame::load$($String* name, bool initialize) {
	$loadClass(WindowUpdateFrame, name, initialize, &_WindowUpdateFrame_ClassInfo_, allocate$WindowUpdateFrame);
	return class$;
}

$Class* WindowUpdateFrame::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk