#include <jdk/internal/net/http/frame/MalformedFrame.h>

#include <jdk/internal/net/http/frame/ErrorFrame.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ErrorFrame = ::jdk::internal::net::http::frame::ErrorFrame;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

$FieldInfo _MalformedFrame_FieldInfo_[] = {
	{"errorCode", "I", nullptr, $PRIVATE, $field(MalformedFrame, errorCode)},
	{"errorStream", "I", nullptr, $PRIVATE, $field(MalformedFrame, errorStream)},
	{"msg", "Ljava/lang/String;", nullptr, $PRIVATE, $field(MalformedFrame, msg)},
	{}
};

$MethodInfo _MalformedFrame_MethodInfo_[] = {
	{"<init>", "(ILjava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(MalformedFrame::*)(int32_t,$String*)>(&MalformedFrame::init$))},
	{"<init>", "(IILjava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(MalformedFrame::*)(int32_t,int32_t,$String*)>(&MalformedFrame::init$))},
	{"getErrorCode", "()I", nullptr, $PUBLIC},
	{"getMessage", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _MalformedFrame_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.frame.MalformedFrame",
	"jdk.internal.net.http.frame.Http2Frame",
	nullptr,
	_MalformedFrame_FieldInfo_,
	_MalformedFrame_MethodInfo_
};

$Object* allocate$MalformedFrame($Class* clazz) {
	return $of($alloc(MalformedFrame));
}

void MalformedFrame::init$(int32_t errorCode, $String* msg) {
	MalformedFrame::init$(errorCode, 0, msg);
}

void MalformedFrame::init$(int32_t errorCode, int32_t errorStream, $String* msg) {
	$Http2Frame::init$(0, 0);
	this->errorCode = errorCode;
	this->errorStream = errorStream;
	$set(this, msg, msg);
}

$String* MalformedFrame::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$4, $$str({$($Http2Frame::toString()), " MalformedFrame, Error: "_s}));
	$var($String, var$3, $$concat(var$4, $($ErrorFrame::stringForCode(this->errorCode))));
	$var($String, var$2, $$concat(var$3, " streamid: "));
	$var($String, var$1, $$concat(var$2, $$str(this->streamid$)));
	$var($String, var$0, $$concat(var$1, " reason: "));
	return $concat(var$0, this->msg);
}

int32_t MalformedFrame::getErrorCode() {
	return this->errorCode;
}

$String* MalformedFrame::getMessage() {
	return this->msg;
}

MalformedFrame::MalformedFrame() {
}

$Class* MalformedFrame::load$($String* name, bool initialize) {
	$loadClass(MalformedFrame, name, initialize, &_MalformedFrame_ClassInfo_, allocate$MalformedFrame);
	return class$;
}

$Class* MalformedFrame::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk