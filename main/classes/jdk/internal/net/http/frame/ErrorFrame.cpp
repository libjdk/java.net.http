#include <jdk/internal/net/http/frame/ErrorFrame.h>

#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jcpp.h>

#undef CANCEL
#undef COMPRESSION_ERROR
#undef CONNECT_ERROR
#undef ENHANCE_YOUR_CALM
#undef FLOW_CONTROL_ERROR
#undef FRAME_SIZE_ERROR
#undef HTTP_1_1_REQUIRED
#undef INADEQUATE_SECURITY
#undef INTERNAL_ERROR
#undef LAST_ERROR
#undef NO_ERROR
#undef PROTOCOL_ERROR
#undef REFUSED_STREAM
#undef SETTINGS_TIMEOUT
#undef STREAM_CLOSED

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

$FieldInfo _ErrorFrame_FieldInfo_[] = {
	{"NO_ERROR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorFrame, NO_ERROR)},
	{"PROTOCOL_ERROR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorFrame, PROTOCOL_ERROR)},
	{"INTERNAL_ERROR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorFrame, INTERNAL_ERROR)},
	{"FLOW_CONTROL_ERROR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorFrame, FLOW_CONTROL_ERROR)},
	{"SETTINGS_TIMEOUT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorFrame, SETTINGS_TIMEOUT)},
	{"STREAM_CLOSED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorFrame, STREAM_CLOSED)},
	{"FRAME_SIZE_ERROR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorFrame, FRAME_SIZE_ERROR)},
	{"REFUSED_STREAM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorFrame, REFUSED_STREAM)},
	{"CANCEL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorFrame, CANCEL)},
	{"COMPRESSION_ERROR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorFrame, COMPRESSION_ERROR)},
	{"CONNECT_ERROR", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorFrame, CONNECT_ERROR)},
	{"ENHANCE_YOUR_CALM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorFrame, ENHANCE_YOUR_CALM)},
	{"INADEQUATE_SECURITY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorFrame, INADEQUATE_SECURITY)},
	{"HTTP_1_1_REQUIRED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorFrame, HTTP_1_1_REQUIRED)},
	{"LAST_ERROR", "I", nullptr, $STATIC | $FINAL, $constField(ErrorFrame, LAST_ERROR)},
	{"errorStrings", "[Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(ErrorFrame, errorStrings)},
	{"errorCode", "I", nullptr, 0, $field(ErrorFrame, errorCode)},
	{}
};

$MethodInfo _ErrorFrame_MethodInfo_[] = {
	{"<init>", "(III)V", nullptr, $PUBLIC, $method(static_cast<void(ErrorFrame::*)(int32_t,int32_t,int32_t)>(&ErrorFrame::init$))},
	{"getErrorCode", "()I", nullptr, $PUBLIC},
	{"stringForCode", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)(int32_t)>(&ErrorFrame::stringForCode))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _ErrorFrame_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.frame.ErrorFrame",
	"jdk.internal.net.http.frame.Http2Frame",
	nullptr,
	_ErrorFrame_FieldInfo_,
	_ErrorFrame_MethodInfo_
};

$Object* allocate$ErrorFrame($Class* clazz) {
	return $of($alloc(ErrorFrame));
}

$StringArray* ErrorFrame::errorStrings = nullptr;

$String* ErrorFrame::stringForCode(int32_t code) {
	$init(ErrorFrame);
	if (code < 0) {
		$throwNew($IllegalArgumentException);
	}
	if (code > ErrorFrame::LAST_ERROR) {
		return $str({"Error: "_s, $($Integer::toString(code))});
	} else {
		return $nc(ErrorFrame::errorStrings)->get(code);
	}
}

void ErrorFrame::init$(int32_t streamid, int32_t flags, int32_t errorCode) {
	$Http2Frame::init$(streamid, flags);
	this->errorCode = errorCode;
}

$String* ErrorFrame::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $$str({$($Http2Frame::toString()), " Error: "_s}));
	return $concat(var$0, $(stringForCode(this->errorCode)));
}

int32_t ErrorFrame::getErrorCode() {
	return this->errorCode;
}

void clinit$ErrorFrame($Class* class$) {
	$assignStatic(ErrorFrame::errorStrings, $new($StringArray, {
		"Not an error"_s,
		"Protocol error"_s,
		"Internal error"_s,
		"Flow control error"_s,
		"Settings timeout"_s,
		"Stream is closed"_s,
		"Frame size error"_s,
		"Stream not processed"_s,
		"Stream cancelled"_s,
		"Compression state not updated"_s,
		"TCP Connection error on CONNECT"_s,
		"Processing capacity exceeded"_s,
		"Negotiated TLS parameters not acceptable"_s,
		"Use HTTP/1.1 for request"_s
	}));
}

ErrorFrame::ErrorFrame() {
}

$Class* ErrorFrame::load$($String* name, bool initialize) {
	$loadClass(ErrorFrame, name, initialize, &_ErrorFrame_ClassInfo_, clinit$ErrorFrame, allocate$ErrorFrame);
	return class$;
}

$Class* ErrorFrame::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk