#include <jdk/internal/net/http/frame/FramesEncoder.h>

#include <java/lang/AssertionError.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jdk/internal/net/http/frame/ContinuationFrame.h>
#include <jdk/internal/net/http/frame/DataFrame.h>
#include <jdk/internal/net/http/frame/GoAwayFrame.h>
#include <jdk/internal/net/http/frame/HeaderFrame.h>
#include <jdk/internal/net/http/frame/HeadersFrame.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jdk/internal/net/http/frame/PingFrame.h>
#include <jdk/internal/net/http/frame/PriorityFrame.h>
#include <jdk/internal/net/http/frame/PushPromiseFrame.h>
#include <jdk/internal/net/http/frame/ResetFrame.h>
#include <jdk/internal/net/http/frame/SettingsFrame.h>
#include <jdk/internal/net/http/frame/WindowUpdateFrame.h>
#include <jcpp.h>

#undef FRAME_HEADER_SIZE
#undef NO_FLAGS
#undef PADDED
#undef PRIORITY
#undef TYPE
#undef ZERO_STREAM

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $ContinuationFrame = ::jdk::internal::net::http::frame::ContinuationFrame;
using $DataFrame = ::jdk::internal::net::http::frame::DataFrame;
using $ErrorFrame = ::jdk::internal::net::http::frame::ErrorFrame;
using $GoAwayFrame = ::jdk::internal::net::http::frame::GoAwayFrame;
using $HeaderFrame = ::jdk::internal::net::http::frame::HeaderFrame;
using $HeadersFrame = ::jdk::internal::net::http::frame::HeadersFrame;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;
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

$FieldInfo _FramesEncoder_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(FramesEncoder, $assertionsDisabled)},
	{"NO_FLAGS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FramesEncoder, NO_FLAGS)},
	{"ZERO_STREAM", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FramesEncoder, ZERO_STREAM)},
	{}
};

$MethodInfo _FramesEncoder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(FramesEncoder::*)()>(&FramesEncoder::init$))},
	{"encodeConnectionPreface", "([BLjdk/internal/net/http/frame/SettingsFrame;)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC},
	{"encodeContinuationFrame", "(Ljdk/internal/net/http/frame/ContinuationFrame;)Ljava/util/List;", "(Ljdk/internal/net/http/frame/ContinuationFrame;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(FramesEncoder::*)($ContinuationFrame*)>(&FramesEncoder::encodeContinuationFrame))},
	{"encodeDataFrame", "(Ljdk/internal/net/http/frame/DataFrame;)Ljava/util/List;", "(Ljdk/internal/net/http/frame/DataFrame;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(FramesEncoder::*)($DataFrame*)>(&FramesEncoder::encodeDataFrame))},
	{"encodeDataFrameStart", "(Ljdk/internal/net/http/frame/DataFrame;)Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $method(static_cast<$ByteBuffer*(FramesEncoder::*)($DataFrame*)>(&FramesEncoder::encodeDataFrameStart))},
	{"encodeFrame", "(Ljdk/internal/net/http/frame/Http2Frame;)Ljava/util/List;", "(Ljdk/internal/net/http/frame/Http2Frame;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PUBLIC},
	{"encodeFrames", "(Ljava/util/List;)Ljava/util/List;", "(Ljava/util/List<Ljdk/internal/net/http/frame/HeaderFrame;>;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PUBLIC},
	{"encodeGoAwayFrame", "(Ljdk/internal/net/http/frame/GoAwayFrame;)Ljava/util/List;", "(Ljdk/internal/net/http/frame/GoAwayFrame;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(FramesEncoder::*)($GoAwayFrame*)>(&FramesEncoder::encodeGoAwayFrame))},
	{"encodeHeadersFrame", "(Ljdk/internal/net/http/frame/HeadersFrame;)Ljava/util/List;", "(Ljdk/internal/net/http/frame/HeadersFrame;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(FramesEncoder::*)($HeadersFrame*)>(&FramesEncoder::encodeHeadersFrame))},
	{"encodeHeadersFrameStart", "(Ljdk/internal/net/http/frame/HeadersFrame;)Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $method(static_cast<$ByteBuffer*(FramesEncoder::*)($HeadersFrame*)>(&FramesEncoder::encodeHeadersFrameStart))},
	{"encodePingFrame", "(Ljdk/internal/net/http/frame/PingFrame;)Ljava/util/List;", "(Ljdk/internal/net/http/frame/PingFrame;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(FramesEncoder::*)($PingFrame*)>(&FramesEncoder::encodePingFrame))},
	{"encodePriorityFrame", "(Ljdk/internal/net/http/frame/PriorityFrame;)Ljava/util/List;", "(Ljdk/internal/net/http/frame/PriorityFrame;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(FramesEncoder::*)($PriorityFrame*)>(&FramesEncoder::encodePriorityFrame))},
	{"encodePushPromiseFrame", "(Ljdk/internal/net/http/frame/PushPromiseFrame;)Ljava/util/List;", "(Ljdk/internal/net/http/frame/PushPromiseFrame;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(FramesEncoder::*)($PushPromiseFrame*)>(&FramesEncoder::encodePushPromiseFrame))},
	{"encodeResetFrame", "(Ljdk/internal/net/http/frame/ResetFrame;)Ljava/util/List;", "(Ljdk/internal/net/http/frame/ResetFrame;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(FramesEncoder::*)($ResetFrame*)>(&FramesEncoder::encodeResetFrame))},
	{"encodeSettingsFrame", "(Ljdk/internal/net/http/frame/SettingsFrame;)Ljava/util/List;", "(Ljdk/internal/net/http/frame/SettingsFrame;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(FramesEncoder::*)($SettingsFrame*)>(&FramesEncoder::encodeSettingsFrame))},
	{"encodeWindowUpdateFrame", "(Ljdk/internal/net/http/frame/WindowUpdateFrame;)Ljava/util/List;", "(Ljdk/internal/net/http/frame/WindowUpdateFrame;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(FramesEncoder::*)($WindowUpdateFrame*)>(&FramesEncoder::encodeWindowUpdateFrame))},
	{"getBuffer", "(I)Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $method(static_cast<$ByteBuffer*(FramesEncoder::*)(int32_t)>(&FramesEncoder::getBuffer))},
	{"getPadding", "(I)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC},
	{"join", "(Ljava/nio/ByteBuffer;Ljava/util/List;)Ljava/util/List;", "(Ljava/nio/ByteBuffer;Ljava/util/List<Ljava/nio/ByteBuffer;>;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(FramesEncoder::*)($ByteBuffer*,$List*)>(&FramesEncoder::join))},
	{"joinWithPadding", "(Ljava/nio/ByteBuffer;Ljava/util/List;I)Ljava/util/List;", "(Ljava/nio/ByteBuffer;Ljava/util/List<Ljava/nio/ByteBuffer;>;I)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(FramesEncoder::*)($ByteBuffer*,$List*,int32_t)>(&FramesEncoder::joinWithPadding))},
	{"putHeader", "(Ljava/nio/ByteBuffer;IIII)V", nullptr, $PRIVATE, $method(static_cast<void(FramesEncoder::*)($ByteBuffer*,int32_t,int32_t,int32_t,int32_t)>(&FramesEncoder::putHeader))},
	{"putPriority", "(Ljava/nio/ByteBuffer;ZII)V", nullptr, $PRIVATE, $method(static_cast<void(FramesEncoder::*)($ByteBuffer*,bool,int32_t,int32_t)>(&FramesEncoder::putPriority))},
	{"putSettingsFrame", "(Ljava/nio/ByteBuffer;Ljdk/internal/net/http/frame/SettingsFrame;I)V", nullptr, $PRIVATE, $method(static_cast<void(FramesEncoder::*)($ByteBuffer*,$SettingsFrame*,int32_t)>(&FramesEncoder::putSettingsFrame))},
	{}
};

$ClassInfo _FramesEncoder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.frame.FramesEncoder",
	"java.lang.Object",
	nullptr,
	_FramesEncoder_FieldInfo_,
	_FramesEncoder_MethodInfo_
};

$Object* allocate$FramesEncoder($Class* clazz) {
	return $of($alloc(FramesEncoder));
}

bool FramesEncoder::$assertionsDisabled = false;

void FramesEncoder::init$() {
}

$List* FramesEncoder::encodeFrames($List* frames) {
	$useLocalCurrentObjectStackCache();
	$var($List, bufs, $new($ArrayList, $nc(frames)->size() * 2));
	{
		$var($Iterator, i$, $nc(frames)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($HeaderFrame, f, $cast($HeaderFrame, i$->next()));
			{
				bufs->addAll($(encodeFrame(f)));
			}
		}
	}
	return bufs;
}

$ByteBuffer* FramesEncoder::encodeConnectionPreface($bytes* preface, $SettingsFrame* frame) {
	int32_t length = $nc(frame)->length();
	$var($ByteBuffer, buf, getBuffer($Http2Frame::FRAME_HEADER_SIZE + length + $nc(preface)->length));
	$nc(buf)->put(preface);
	putSettingsFrame(buf, frame, length);
	buf->flip();
	return buf;
}

$List* FramesEncoder::encodeFrame($Http2Frame* frame) {
	$useLocalCurrentObjectStackCache();

	$var($List, var$0, nullptr)
	switch ($nc(frame)->type()) {
	case $DataFrame::TYPE:
		{
			$assign(var$0, encodeDataFrame($cast($DataFrame, frame)));
			break;
		}
	case $HeadersFrame::TYPE:
		{
			$assign(var$0, encodeHeadersFrame($cast($HeadersFrame, frame)));
			break;
		}
	case $PriorityFrame::TYPE:
		{
			$assign(var$0, encodePriorityFrame($cast($PriorityFrame, frame)));
			break;
		}
	case $ResetFrame::TYPE:
		{
			$assign(var$0, encodeResetFrame($cast($ResetFrame, frame)));
			break;
		}
	case $SettingsFrame::TYPE:
		{
			$assign(var$0, encodeSettingsFrame($cast($SettingsFrame, frame)));
			break;
		}
	case $PushPromiseFrame::TYPE:
		{
			$assign(var$0, encodePushPromiseFrame($cast($PushPromiseFrame, frame)));
			break;
		}
	case $PingFrame::TYPE:
		{
			$assign(var$0, encodePingFrame($cast($PingFrame, frame)));
			break;
		}
	case $GoAwayFrame::TYPE:
		{
			$assign(var$0, encodeGoAwayFrame($cast($GoAwayFrame, frame)));
			break;
		}
	case $WindowUpdateFrame::TYPE:
		{
			$assign(var$0, encodeWindowUpdateFrame($cast($WindowUpdateFrame, frame)));
			break;
		}
	case $ContinuationFrame::TYPE:
		{
			$assign(var$0, encodeContinuationFrame($cast($ContinuationFrame, frame)));
			break;
		}
	default:
		{
			$var($String, var$2, $$str({"Not supported frame "_s, $$str(frame->type()), " ("_s}));
			$var($String, var$1, $$concat(var$2, $($of(frame)->getClass()->getName())));
			$throwNew($UnsupportedOperationException, $$concat(var$1, ")"));
		}
	}
	return var$0;
}

$List* FramesEncoder::encodeDataFrame($DataFrame* frame) {
	$useLocalCurrentObjectStackCache();
	if (!FramesEncoder::$assertionsDisabled && !($nc(frame)->streamid() != 0)) {
		$throwNew($AssertionError);
	}
	$var($ByteBuffer, buf, encodeDataFrameStart(frame));
	if ($nc(frame)->getFlag($DataFrame::PADDED)) {
		$var($ByteBuffer, var$0, buf);
		$var($List, var$1, frame->getData());
		return joinWithPadding(var$0, var$1, frame->getPadLength());
	} else {
		return join(buf, $(frame->getData()));
	}
}

$ByteBuffer* FramesEncoder::encodeDataFrameStart($DataFrame* frame) {
	$useLocalCurrentObjectStackCache();
	bool isPadded = $nc(frame)->getFlag($DataFrame::PADDED);
	int32_t var$0 = frame->getDataLength();
	int32_t length = var$0 + (isPadded ? (frame->getPadLength() + 1) : 0);
	$var($ByteBuffer, buf, getBuffer($Http2Frame::FRAME_HEADER_SIZE + (isPadded ? 1 : 0)));
	$var($ByteBuffer, var$1, buf);
	int32_t var$2 = length;
	int32_t var$3 = frame->getFlags();
	putHeader(var$1, var$2, $DataFrame::TYPE, var$3, frame->streamid());
	if (isPadded) {
		$nc(buf)->put((int8_t)frame->getPadLength());
	}
	$nc(buf)->flip();
	return buf;
}

$List* FramesEncoder::encodeHeadersFrame($HeadersFrame* frame) {
	$useLocalCurrentObjectStackCache();
	if (!FramesEncoder::$assertionsDisabled && !($nc(frame)->streamid() != 0)) {
		$throwNew($AssertionError);
	}
	$var($ByteBuffer, buf, encodeHeadersFrameStart(frame));
	if ($nc(frame)->getFlag($HeadersFrame::PADDED)) {
		$var($ByteBuffer, var$0, buf);
		$var($List, var$1, frame->getHeaderBlock());
		return joinWithPadding(var$0, var$1, frame->getPadLength());
	} else {
		return join(buf, $(frame->getHeaderBlock()));
	}
}

$ByteBuffer* FramesEncoder::encodeHeadersFrameStart($HeadersFrame* frame) {
	$useLocalCurrentObjectStackCache();
	bool isPadded = $nc(frame)->getFlag($HeadersFrame::PADDED);
	bool hasPriority = frame->getFlag($HeadersFrame::PRIORITY);
	int32_t var$0 = frame->getHeaderLength();
	int32_t length = var$0 + (isPadded ? (frame->getPadLength() + 1) : 0) + (hasPriority ? 5 : 0);
	$var($ByteBuffer, buf, getBuffer($Http2Frame::FRAME_HEADER_SIZE + (isPadded ? 1 : 0) + (hasPriority ? 5 : 0)));
	$var($ByteBuffer, var$1, buf);
	int32_t var$2 = length;
	int32_t var$3 = frame->getFlags();
	putHeader(var$1, var$2, $HeadersFrame::TYPE, var$3, frame->streamid());
	if (isPadded) {
		$nc(buf)->put((int8_t)frame->getPadLength());
	}
	if (hasPriority) {
		$var($ByteBuffer, var$4, buf);
		bool var$5 = frame->getExclusive();
		int32_t var$6 = frame->getStreamDependency();
		putPriority(var$4, var$5, var$6, frame->getWeight());
	}
	$nc(buf)->flip();
	return buf;
}

$List* FramesEncoder::encodePriorityFrame($PriorityFrame* frame) {
	$useLocalCurrentObjectStackCache();
	if (!FramesEncoder::$assertionsDisabled && !($nc(frame)->streamid() != 0)) {
		$throwNew($AssertionError);
	}
	int32_t length = 5;
	$var($ByteBuffer, buf, getBuffer($Http2Frame::FRAME_HEADER_SIZE + length));
	putHeader(buf, length, $PriorityFrame::TYPE, FramesEncoder::NO_FLAGS, $nc(frame)->streamid());
	$var($ByteBuffer, var$0, buf);
	bool var$1 = $nc(frame)->exclusive();
	int32_t var$2 = frame->streamDependency();
	putPriority(var$0, var$1, var$2, frame->weight());
	$nc(buf)->flip();
	return $List::of($of(buf));
}

$List* FramesEncoder::encodeResetFrame($ResetFrame* frame) {
	if (!FramesEncoder::$assertionsDisabled && !($nc(frame)->streamid() != 0)) {
		$throwNew($AssertionError);
	}
	int32_t length = 4;
	$var($ByteBuffer, buf, getBuffer($Http2Frame::FRAME_HEADER_SIZE + length));
	putHeader(buf, length, $ResetFrame::TYPE, FramesEncoder::NO_FLAGS, $nc(frame)->streamid());
	$nc(buf)->putInt($nc(frame)->getErrorCode());
	buf->flip();
	return $List::of($of(buf));
}

$List* FramesEncoder::encodeSettingsFrame($SettingsFrame* frame) {
	if (!FramesEncoder::$assertionsDisabled && !($nc(frame)->streamid() == 0)) {
		$throwNew($AssertionError);
	}
	int32_t length = $nc(frame)->length();
	$var($ByteBuffer, buf, getBuffer($Http2Frame::FRAME_HEADER_SIZE + length));
	putSettingsFrame(buf, frame, length);
	$nc(buf)->flip();
	return $List::of($of(buf));
}

$List* FramesEncoder::encodePushPromiseFrame($PushPromiseFrame* frame) {
	$useLocalCurrentObjectStackCache();
	if (!FramesEncoder::$assertionsDisabled && !($nc(frame)->streamid() != 0)) {
		$throwNew($AssertionError);
	}
	bool isPadded = $nc(frame)->getFlag($PushPromiseFrame::PADDED);
	int32_t length = frame->getHeaderLength() + (isPadded ? 5 : 4);
	$var($ByteBuffer, buf, getBuffer($Http2Frame::FRAME_HEADER_SIZE + (isPadded ? 5 : 4)));
	$var($ByteBuffer, var$0, buf);
	int32_t var$1 = length;
	int32_t var$2 = frame->getFlags();
	putHeader(var$0, var$1, $PushPromiseFrame::TYPE, var$2, frame->streamid());
	if (isPadded) {
		$nc(buf)->put((int8_t)frame->getPadLength());
	}
	$nc(buf)->putInt(frame->getPromisedStream());
	buf->flip();
	if (frame->getFlag($PushPromiseFrame::PADDED)) {
		$var($ByteBuffer, var$3, buf);
		$var($List, var$4, frame->getHeaderBlock());
		return joinWithPadding(var$3, var$4, frame->getPadLength());
	} else {
		return join(buf, $(frame->getHeaderBlock()));
	}
}

$List* FramesEncoder::encodePingFrame($PingFrame* frame) {
	$useLocalCurrentObjectStackCache();
	if (!FramesEncoder::$assertionsDisabled && !($nc(frame)->streamid() == 0)) {
		$throwNew($AssertionError);
	}
	int32_t length = 8;
	$var($ByteBuffer, buf, getBuffer($Http2Frame::FRAME_HEADER_SIZE + length));
	putHeader(buf, length, $PingFrame::TYPE, $nc(frame)->getFlags(), FramesEncoder::ZERO_STREAM);
	$nc(buf)->put($($nc(frame)->getData()));
	buf->flip();
	return $List::of($of(buf));
}

$List* FramesEncoder::encodeGoAwayFrame($GoAwayFrame* frame) {
	$useLocalCurrentObjectStackCache();
	if (!FramesEncoder::$assertionsDisabled && !($nc(frame)->streamid() == 0)) {
		$throwNew($AssertionError);
	}
	$var($bytes, debugData, $nc(frame)->getDebugData());
	int32_t length = 8 + $nc(debugData)->length;
	$var($ByteBuffer, buf, getBuffer($Http2Frame::FRAME_HEADER_SIZE + length));
	putHeader(buf, length, $GoAwayFrame::TYPE, FramesEncoder::NO_FLAGS, FramesEncoder::ZERO_STREAM);
	$nc(buf)->putInt(frame->getLastStream());
	buf->putInt(frame->getErrorCode());
	if (debugData->length > 0) {
		buf->put(debugData);
	}
	buf->flip();
	return $List::of($of(buf));
}

$List* FramesEncoder::encodeWindowUpdateFrame($WindowUpdateFrame* frame) {
	int32_t length = 4;
	$var($ByteBuffer, buf, getBuffer($Http2Frame::FRAME_HEADER_SIZE + length));
	putHeader(buf, length, $WindowUpdateFrame::TYPE, FramesEncoder::NO_FLAGS, $nc(frame)->streamid$);
	$nc(buf)->putInt($nc(frame)->getUpdate());
	buf->flip();
	return $List::of($of(buf));
}

$List* FramesEncoder::encodeContinuationFrame($ContinuationFrame* frame) {
	$useLocalCurrentObjectStackCache();
	if (!FramesEncoder::$assertionsDisabled && !($nc(frame)->streamid() != 0)) {
		$throwNew($AssertionError);
	}
	int32_t length = $nc(frame)->getHeaderLength();
	$var($ByteBuffer, buf, getBuffer($Http2Frame::FRAME_HEADER_SIZE));
	$var($ByteBuffer, var$0, buf);
	int32_t var$1 = length;
	int32_t var$2 = frame->getFlags();
	putHeader(var$0, var$1, $ContinuationFrame::TYPE, var$2, frame->streamid());
	$nc(buf)->flip();
	return join(buf, $(frame->getHeaderBlock()));
}

$List* FramesEncoder::joinWithPadding($ByteBuffer* buf, $List* data, int32_t padLength) {
	$useLocalCurrentObjectStackCache();
	int32_t len = $nc(data)->size();
	if (len == 0) {
		return $List::of(buf, $(getPadding(padLength)));
	} else if (len == 1) {
		$var($Object, var$0, $of(buf));
		$var($Object, var$1, $cast($ByteBuffer, data->get(0)));
		return $List::of(var$0, var$1, $(getPadding(padLength)));
	} else if (len == 2) {
		$var($Object, var$2, $of(buf));
		$var($Object, var$3, $cast($ByteBuffer, data->get(0)));
		$var($Object, var$4, $cast($ByteBuffer, data->get(1)));
		return $List::of(var$2, var$3, var$4, $(getPadding(padLength)));
	}
	$var($List, res, $new($ArrayList, len + 2));
	res->add(buf);
	res->addAll(data);
	res->add($(getPadding(padLength)));
	return res;
}

$List* FramesEncoder::join($ByteBuffer* buf, $List* data) {
	$useLocalCurrentObjectStackCache();
	int32_t len = $nc(data)->size();
	if (len == 0) {
		return $List::of($of(buf));
	} else if (len == 1) {
		return $List::of(buf, $cast($ByteBuffer, $(data->get(0))));
	} else if (len == 2) {
		$var($Object, var$0, $of(buf));
		$var($Object, var$1, $cast($ByteBuffer, data->get(0)));
		return $List::of(var$0, var$1, $cast($ByteBuffer, $(data->get(1))));
	}
	$var($List, joined, $new($ArrayList, len + 1));
	joined->add(buf);
	joined->addAll(data);
	return joined;
}

void FramesEncoder::putSettingsFrame($ByteBuffer* buf, $SettingsFrame* frame, int32_t length) {
	if (!FramesEncoder::$assertionsDisabled && !($nc(frame)->streamid() == 0)) {
		$throwNew($AssertionError);
	}
	putHeader(buf, length, $SettingsFrame::TYPE, $nc(frame)->getFlags(), FramesEncoder::ZERO_STREAM);
	$nc(frame)->toByteBuffer(buf);
}

void FramesEncoder::putHeader($ByteBuffer* buf, int32_t length, int32_t type, int32_t flags, int32_t streamId) {
	int32_t x = (length << 8) + type;
	$nc(buf)->putInt(x);
	buf->put((int8_t)flags);
	buf->putInt(streamId);
}

void FramesEncoder::putPriority($ByteBuffer* buf, bool exclusive, int32_t streamDependency, int32_t weight) {
	$nc(buf)->putInt(exclusive ? (1 << 31) + streamDependency : streamDependency);
	buf->put((int8_t)weight);
}

$ByteBuffer* FramesEncoder::getBuffer(int32_t capacity) {
	return $ByteBuffer::allocate(capacity);
}

$ByteBuffer* FramesEncoder::getPadding(int32_t length) {
	if (length > 255) {
		$throwNew($IllegalArgumentException, "Padding too big"_s);
	}
	return $ByteBuffer::allocate(length);
}

void clinit$FramesEncoder($Class* class$) {
	FramesEncoder::$assertionsDisabled = !FramesEncoder::class$->desiredAssertionStatus();
}

FramesEncoder::FramesEncoder() {
}

$Class* FramesEncoder::load$($String* name, bool initialize) {
	$loadClass(FramesEncoder, name, initialize, &_FramesEncoder_ClassInfo_, clinit$FramesEncoder, allocate$FramesEncoder);
	return class$;
}

$Class* FramesEncoder::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk