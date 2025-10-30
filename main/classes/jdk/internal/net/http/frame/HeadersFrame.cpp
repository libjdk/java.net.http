#include <jdk/internal/net/http/frame/HeadersFrame.h>

#include <java/nio/ByteBuffer.h>
#include <java/util/List.h>
#include <jdk/internal/net/http/frame/HeaderFrame.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jcpp.h>

#undef END_STREAM
#undef PADDED
#undef PRIORITY
#undef TYPE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $List = ::java::util::List;
using $HeaderFrame = ::jdk::internal::net::http::frame::HeaderFrame;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

$FieldInfo _HeadersFrame_FieldInfo_[] = {
	{"TYPE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HeadersFrame, TYPE)},
	{"END_STREAM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HeadersFrame, END_STREAM)},
	{"PADDED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HeadersFrame, PADDED)},
	{"PRIORITY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HeadersFrame, PRIORITY)},
	{"padLength", "I", nullptr, $PRIVATE, $field(HeadersFrame, padLength)},
	{"streamDependency", "I", nullptr, $PRIVATE, $field(HeadersFrame, streamDependency)},
	{"weight", "I", nullptr, $PRIVATE, $field(HeadersFrame, weight)},
	{"exclusive", "Z", nullptr, $PRIVATE, $field(HeadersFrame, exclusive)},
	{}
};

$MethodInfo _HeadersFrame_MethodInfo_[] = {
	{"<init>", "(IILjava/util/List;I)V", "(IILjava/util/List<Ljava/nio/ByteBuffer;>;I)V", $PUBLIC, $method(static_cast<void(HeadersFrame::*)(int32_t,int32_t,$List*,int32_t)>(&HeadersFrame::init$))},
	{"<init>", "(IILjava/util/List;)V", "(IILjava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, $method(static_cast<void(HeadersFrame::*)(int32_t,int32_t,$List*)>(&HeadersFrame::init$))},
	{"<init>", "(IILjava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $method(static_cast<void(HeadersFrame::*)(int32_t,int32_t,$ByteBuffer*)>(&HeadersFrame::init$))},
	{"flagAsString", "(I)Ljava/lang/String;", nullptr, $PUBLIC},
	{"getExclusive", "()Z", nullptr, $PUBLIC},
	{"getPadLength", "()I", nullptr, 0},
	{"getStreamDependency", "()I", nullptr, $PUBLIC},
	{"getWeight", "()I", nullptr, $PUBLIC},
	{"length", "()I", nullptr, 0},
	{"setPadLength", "(I)V", nullptr, $PUBLIC},
	{"setPriority", "(IZI)V", nullptr, $PUBLIC},
	{"type", "()I", nullptr, $PUBLIC},
	{}
};

$ClassInfo _HeadersFrame_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.frame.HeadersFrame",
	"jdk.internal.net.http.frame.HeaderFrame",
	nullptr,
	_HeadersFrame_FieldInfo_,
	_HeadersFrame_MethodInfo_
};

$Object* allocate$HeadersFrame($Class* clazz) {
	return $of($alloc(HeadersFrame));
}

void HeadersFrame::init$(int32_t streamid, int32_t flags, $List* headerBlocks, int32_t padLength) {
	$HeaderFrame::init$(streamid, flags, headerBlocks);
	if (padLength > 0) {
		setPadLength(padLength);
	}
}

void HeadersFrame::init$(int32_t streamid, int32_t flags, $List* headerBlocks) {
	$HeaderFrame::init$(streamid, flags, headerBlocks);
}

void HeadersFrame::init$(int32_t streamid, int32_t flags, $ByteBuffer* headerBlock) {
	HeadersFrame::init$(streamid, flags, $($List::of($of(headerBlock))));
}

int32_t HeadersFrame::type() {
	return HeadersFrame::TYPE;
}

int32_t HeadersFrame::length() {
	return this->headerLength + (((int32_t)(this->flags & (uint32_t)HeadersFrame::PADDED)) != 0 ? (1 + this->padLength) : 0) + (((int32_t)(this->flags & (uint32_t)HeadersFrame::PRIORITY)) != 0 ? 5 : 0);
}

$String* HeadersFrame::flagAsString(int32_t flag) {

	$var($String, var$0, nullptr)
	switch (flag) {
	case HeadersFrame::END_STREAM:
		{
			$assign(var$0, "END_STREAM"_s);
			break;
		}
	case HeadersFrame::PADDED:
		{
			$assign(var$0, "PADDED"_s);
			break;
		}
	case HeadersFrame::PRIORITY:
		{
			$assign(var$0, "PRIORITY"_s);
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

void HeadersFrame::setPadLength(int32_t padLength) {
	this->padLength = padLength;
	this->flags |= HeadersFrame::PADDED;
}

int32_t HeadersFrame::getPadLength() {
	return this->padLength;
}

void HeadersFrame::setPriority(int32_t streamDependency, bool exclusive, int32_t weight) {
	this->streamDependency = streamDependency;
	this->exclusive = exclusive;
	this->weight = weight;
	this->flags |= HeadersFrame::PRIORITY;
}

int32_t HeadersFrame::getStreamDependency() {
	return this->streamDependency;
}

int32_t HeadersFrame::getWeight() {
	return this->weight;
}

bool HeadersFrame::getExclusive() {
	return this->exclusive;
}

HeadersFrame::HeadersFrame() {
}

$Class* HeadersFrame::load$($String* name, bool initialize) {
	$loadClass(HeadersFrame, name, initialize, &_HeadersFrame_ClassInfo_, allocate$HeadersFrame);
	return class$;
}

$Class* HeadersFrame::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk