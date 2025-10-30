#include <jdk/internal/net/http/frame/Http2Frame.h>

#include <jdk/internal/net/http/frame/ContinuationFrame.h>
#include <jdk/internal/net/http/frame/DataFrame.h>
#include <jdk/internal/net/http/frame/GoAwayFrame.h>
#include <jdk/internal/net/http/frame/HeadersFrame.h>
#include <jdk/internal/net/http/frame/PingFrame.h>
#include <jdk/internal/net/http/frame/PriorityFrame.h>
#include <jdk/internal/net/http/frame/PushPromiseFrame.h>
#include <jdk/internal/net/http/frame/ResetFrame.h>
#include <jdk/internal/net/http/frame/SettingsFrame.h>
#include <jdk/internal/net/http/frame/WindowUpdateFrame.h>
#include <jcpp.h>

#undef FRAME_HEADER_SIZE
#undef TYPE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $ContinuationFrame = ::jdk::internal::net::http::frame::ContinuationFrame;
using $DataFrame = ::jdk::internal::net::http::frame::DataFrame;
using $GoAwayFrame = ::jdk::internal::net::http::frame::GoAwayFrame;
using $HeadersFrame = ::jdk::internal::net::http::frame::HeadersFrame;
using $PingFrame = ::jdk::internal::net::http::frame::PingFrame;
using $PriorityFrame = ::jdk::internal::net::http::frame::PriorityFrame;
using $PushPromiseFrame = ::jdk::internal::net::http::frame::PushPromiseFrame;
using $ResetFrame = ::jdk::internal::net::http::frame::ResetFrame;
using $SettingsFrame = ::jdk::internal::net::http::frame::SettingsFrame;
using $WindowUpdateFrame = ::jdk::internal::net::http::frame::WindowUpdateFrame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

$FieldInfo _Http2Frame_FieldInfo_[] = {
	{"FRAME_HEADER_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Http2Frame, FRAME_HEADER_SIZE)},
	{"streamid", "I", nullptr, $PROTECTED, $field(Http2Frame, streamid$)},
	{"flags", "I", nullptr, $PROTECTED, $field(Http2Frame, flags)},
	{}
};

$MethodInfo _Http2Frame_MethodInfo_[] = {
	{"<init>", "(II)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Frame::*)(int32_t,int32_t)>(&Http2Frame::init$))},
	{"asString", "(I)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)(int32_t)>(&Http2Frame::asString))},
	{"flagAsString", "(I)Ljava/lang/String;", nullptr, $PUBLIC},
	{"getFlag", "(I)Z", nullptr, $PUBLIC},
	{"getFlags", "()I", nullptr, $PUBLIC},
	{"length", "()I", nullptr, 0},
	{"setFlag", "(I)V", nullptr, $PUBLIC},
	{"streamid", "()I", nullptr, $PUBLIC},
	{"streamid", "(I)V", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"type", "()I", nullptr, $PUBLIC},
	{"typeAsString", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(Http2Frame::*)()>(&Http2Frame::typeAsString))},
	{}
};

$ClassInfo _Http2Frame_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.frame.Http2Frame",
	"java.lang.Object",
	nullptr,
	_Http2Frame_FieldInfo_,
	_Http2Frame_MethodInfo_
};

$Object* allocate$Http2Frame($Class* clazz) {
	return $of($alloc(Http2Frame));
}

void Http2Frame::init$(int32_t streamid, int32_t flags) {
	this->streamid$ = streamid;
	this->flags = flags;
}

int32_t Http2Frame::streamid() {
	return this->streamid$;
}

void Http2Frame::setFlag(int32_t flag) {
	this->flags |= flag;
}

int32_t Http2Frame::getFlags() {
	return this->flags;
}

bool Http2Frame::getFlag(int32_t flag) {
	return ((int32_t)(this->flags & (uint32_t)flag)) != 0;
}

void Http2Frame::streamid(int32_t streamid) {
	this->streamid$ = streamid;
}

$String* Http2Frame::typeAsString() {
	return asString(type());
}

int32_t Http2Frame::type() {
	return -1;
}

int32_t Http2Frame::length() {
	return -1;
}

$String* Http2Frame::asString(int32_t type) {

	$var($String, var$0, nullptr)
	switch (type) {
	case $DataFrame::TYPE:
		{
			$assign(var$0, "DATA"_s);
			break;
		}
	case $HeadersFrame::TYPE:
		{
			$assign(var$0, "HEADERS"_s);
			break;
		}
	case $ContinuationFrame::TYPE:
		{
			$assign(var$0, "CONTINUATION"_s);
			break;
		}
	case $ResetFrame::TYPE:
		{
			$assign(var$0, "RESET"_s);
			break;
		}
	case $PriorityFrame::TYPE:
		{
			$assign(var$0, "PRIORITY"_s);
			break;
		}
	case $SettingsFrame::TYPE:
		{
			$assign(var$0, "SETTINGS"_s);
			break;
		}
	case $GoAwayFrame::TYPE:
		{
			$assign(var$0, "GOAWAY"_s);
			break;
		}
	case $PingFrame::TYPE:
		{
			$assign(var$0, "PING"_s);
			break;
		}
	case $PushPromiseFrame::TYPE:
		{
			$assign(var$0, "PUSH_PROMISE"_s);
			break;
		}
	case $WindowUpdateFrame::TYPE:
		{
			$assign(var$0, "WINDOW_UPDATE"_s);
			break;
		}
	default:
		{
			$assign(var$0, "UNKNOWN"_s);
			break;
		}
	}
	return var$0;
}

$String* Http2Frame::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($(typeAsString()))->append(": length="_s)->append($($Integer::toString(length())))->append(", streamid="_s)->append(this->streamid$)->append(", flags="_s);
	int32_t f = this->flags;
	int32_t i = 0;
	if (f == 0) {
		sb->append("0 "_s);
	} else {
		while (f != 0) {
			if (((int32_t)(f & (uint32_t)1)) == 1) {
				sb->append($(flagAsString($sl(1, i))))->append(u' ');
			}
			f = f >> 1;
			++i;
		}
	}
	return sb->toString();
}

$String* Http2Frame::flagAsString(int32_t f) {
	return "unknown"_s;
}

Http2Frame::Http2Frame() {
}

$Class* Http2Frame::load$($String* name, bool initialize) {
	$loadClass(Http2Frame, name, initialize, &_Http2Frame_ClassInfo_, allocate$Http2Frame);
	return class$;
}

$Class* Http2Frame::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk