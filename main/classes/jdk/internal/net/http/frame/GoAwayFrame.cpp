#include <jdk/internal/net/http/frame/GoAwayFrame.h>

#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <jdk/internal/net/http/frame/ErrorFrame.h>
#include <jcpp.h>

#undef TYPE
#undef UTF_8

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $ErrorFrame = ::jdk::internal::net::http::frame::ErrorFrame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

$FieldInfo _GoAwayFrame_FieldInfo_[] = {
	{"lastStream", "I", nullptr, $PRIVATE | $FINAL, $field(GoAwayFrame, lastStream)},
	{"debugData", "[B", nullptr, $PRIVATE | $FINAL, $field(GoAwayFrame, debugData)},
	{"TYPE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GoAwayFrame, TYPE)},
	{}
};

$MethodInfo _GoAwayFrame_MethodInfo_[] = {
	{"<init>", "(II)V", nullptr, $PUBLIC, $method(static_cast<void(GoAwayFrame::*)(int32_t,int32_t)>(&GoAwayFrame::init$))},
	{"<init>", "(II[B)V", nullptr, $PUBLIC, $method(static_cast<void(GoAwayFrame::*)(int32_t,int32_t,$bytes*)>(&GoAwayFrame::init$))},
	{"getDebugData", "()[B", nullptr, $PUBLIC},
	{"getLastStream", "()I", nullptr, $PUBLIC},
	{"length", "()I", nullptr, 0},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"type", "()I", nullptr, $PUBLIC},
	{}
};

$ClassInfo _GoAwayFrame_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.frame.GoAwayFrame",
	"jdk.internal.net.http.frame.ErrorFrame",
	nullptr,
	_GoAwayFrame_FieldInfo_,
	_GoAwayFrame_MethodInfo_
};

$Object* allocate$GoAwayFrame($Class* clazz) {
	return $of($alloc(GoAwayFrame));
}

void GoAwayFrame::init$(int32_t lastStream, int32_t errorCode) {
	GoAwayFrame::init$(lastStream, errorCode, $$new($bytes, 0));
}

void GoAwayFrame::init$(int32_t lastStream, int32_t errorCode, $bytes* debugData) {
	$ErrorFrame::init$(0, 0, errorCode);
	this->lastStream = lastStream;
	$set(this, debugData, $cast($bytes, $nc(debugData)->clone()));
}

int32_t GoAwayFrame::type() {
	return GoAwayFrame::TYPE;
}

int32_t GoAwayFrame::length() {
	return 8 + $nc(this->debugData)->length;
}

$String* GoAwayFrame::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $$str({$($ErrorFrame::toString()), " Debugdata: "_s}));
	$init($StandardCharsets);
	return $concat(var$0, $$new($String, this->debugData, $StandardCharsets::UTF_8));
}

int32_t GoAwayFrame::getLastStream() {
	return this->lastStream;
}

$bytes* GoAwayFrame::getDebugData() {
	return $cast($bytes, $nc(this->debugData)->clone());
}

GoAwayFrame::GoAwayFrame() {
}

$Class* GoAwayFrame::load$($String* name, bool initialize) {
	$loadClass(GoAwayFrame, name, initialize, &_GoAwayFrame_ClassInfo_, allocate$GoAwayFrame);
	return class$;
}

$Class* GoAwayFrame::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk