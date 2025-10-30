#include <jdk/internal/net/http/frame/PushPromiseFrame.h>

#include <java/util/List.h>
#include <jdk/internal/net/http/frame/HeaderFrame.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jcpp.h>

#undef END_HEADERS
#undef PADDED
#undef TYPE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $List = ::java::util::List;
using $HeaderFrame = ::jdk::internal::net::http::frame::HeaderFrame;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

$FieldInfo _PushPromiseFrame_FieldInfo_[] = {
	{"padLength", "I", nullptr, $PRIVATE, $field(PushPromiseFrame, padLength)},
	{"promisedStream", "I", nullptr, $PRIVATE | $FINAL, $field(PushPromiseFrame, promisedStream)},
	{"TYPE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PushPromiseFrame, TYPE)},
	{"END_HEADERS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PushPromiseFrame, END_HEADERS)},
	{"PADDED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PushPromiseFrame, PADDED)},
	{}
};

$MethodInfo _PushPromiseFrame_MethodInfo_[] = {
	{"<init>", "(IIILjava/util/List;I)V", "(IIILjava/util/List<Ljava/nio/ByteBuffer;>;I)V", $PUBLIC, $method(static_cast<void(PushPromiseFrame::*)(int32_t,int32_t,int32_t,$List*,int32_t)>(&PushPromiseFrame::init$))},
	{"endHeaders", "()Z", nullptr, $PUBLIC},
	{"flagAsString", "(I)Ljava/lang/String;", nullptr, $PUBLIC},
	{"getPadLength", "()I", nullptr, $PUBLIC},
	{"getPromisedStream", "()I", nullptr, $PUBLIC},
	{"length", "()I", nullptr, 0},
	{"setPadLength", "(I)V", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"type", "()I", nullptr, $PUBLIC},
	{}
};

$ClassInfo _PushPromiseFrame_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.frame.PushPromiseFrame",
	"jdk.internal.net.http.frame.HeaderFrame",
	nullptr,
	_PushPromiseFrame_FieldInfo_,
	_PushPromiseFrame_MethodInfo_
};

$Object* allocate$PushPromiseFrame($Class* clazz) {
	return $of($alloc(PushPromiseFrame));
}

void PushPromiseFrame::init$(int32_t streamid, int32_t flags, int32_t promisedStream, $List* buffers, int32_t padLength) {
	$HeaderFrame::init$(streamid, flags, buffers);
	this->promisedStream = promisedStream;
	if (padLength > 0) {
		setPadLength(padLength);
	}
}

int32_t PushPromiseFrame::type() {
	return PushPromiseFrame::TYPE;
}

int32_t PushPromiseFrame::length() {
	return this->headerLength + (((int32_t)(this->flags & (uint32_t)PushPromiseFrame::PADDED)) != 0 ? 5 : 4);
}

$String* PushPromiseFrame::toString() {
	$useLocalCurrentObjectStackCache();
	return $str({$($HeaderFrame::toString()), " promisedStreamid: "_s, $$str(this->promisedStream), " headerLength: "_s, $$str(this->headerLength)});
}

$String* PushPromiseFrame::flagAsString(int32_t flag) {

	$var($String, var$0, nullptr)
	switch (flag) {
	case PushPromiseFrame::PADDED:
		{
			$assign(var$0, "PADDED"_s);
			break;
		}
	case PushPromiseFrame::END_HEADERS:
		{
			$assign(var$0, "END_HEADERS"_s);
			break;
		}
	default:
		{
			$assign(var$0, $HeaderFrame::flagAsString(flag));
			break;
		}
	}
	return var$0;
}

void PushPromiseFrame::setPadLength(int32_t padLength) {
	this->padLength = padLength;
	this->flags |= PushPromiseFrame::PADDED;
}

int32_t PushPromiseFrame::getPadLength() {
	return this->padLength;
}

int32_t PushPromiseFrame::getPromisedStream() {
	return this->promisedStream;
}

bool PushPromiseFrame::endHeaders() {
	return getFlag(PushPromiseFrame::END_HEADERS);
}

PushPromiseFrame::PushPromiseFrame() {
}

$Class* PushPromiseFrame::load$($String* name, bool initialize) {
	$loadClass(PushPromiseFrame, name, initialize, &_PushPromiseFrame_ClassInfo_, allocate$PushPromiseFrame);
	return class$;
}

$Class* PushPromiseFrame::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk