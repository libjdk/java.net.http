#include <jdk/internal/net/http/frame/ResetFrame.h>

#include <jdk/internal/net/http/frame/ErrorFrame.h>
#include <jcpp.h>

#undef TYPE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ErrorFrame = ::jdk::internal::net::http::frame::ErrorFrame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

$FieldInfo _ResetFrame_FieldInfo_[] = {
	{"TYPE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ResetFrame, TYPE)},
	{}
};

$MethodInfo _ResetFrame_MethodInfo_[] = {
	{"<init>", "(II)V", nullptr, $PUBLIC, $method(static_cast<void(ResetFrame::*)(int32_t,int32_t)>(&ResetFrame::init$))},
	{"length", "()I", nullptr, 0},
	{"type", "()I", nullptr, $PUBLIC},
	{}
};

$ClassInfo _ResetFrame_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.frame.ResetFrame",
	"jdk.internal.net.http.frame.ErrorFrame",
	nullptr,
	_ResetFrame_FieldInfo_,
	_ResetFrame_MethodInfo_
};

$Object* allocate$ResetFrame($Class* clazz) {
	return $of($alloc(ResetFrame));
}

void ResetFrame::init$(int32_t streamid, int32_t errorCode) {
	$ErrorFrame::init$(streamid, 0, errorCode);
}

int32_t ResetFrame::type() {
	return ResetFrame::TYPE;
}

int32_t ResetFrame::length() {
	return 4;
}

ResetFrame::ResetFrame() {
}

$Class* ResetFrame::load$($String* name, bool initialize) {
	$loadClass(ResetFrame, name, initialize, &_ResetFrame_ClassInfo_, allocate$ResetFrame);
	return class$;
}

$Class* ResetFrame::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk