#include <jdk/internal/net/http/frame/FramesDecoder.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Math.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayDeque.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/frame/ContinuationFrame.h>
#include <jdk/internal/net/http/frame/DataFrame.h>
#include <jdk/internal/net/http/frame/ErrorFrame.h>
#include <jdk/internal/net/http/frame/FramesDecoder$FrameProcessor.h>
#include <jdk/internal/net/http/frame/GoAwayFrame.h>
#include <jdk/internal/net/http/frame/HeaderFrame.h>
#include <jdk/internal/net/http/frame/HeadersFrame.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jdk/internal/net/http/frame/MalformedFrame.h>
#include <jdk/internal/net/http/frame/PingFrame.h>
#include <jdk/internal/net/http/frame/PriorityFrame.h>
#include <jdk/internal/net/http/frame/PushPromiseFrame.h>
#include <jdk/internal/net/http/frame/ResetFrame.h>
#include <jdk/internal/net/http/frame/SettingsFrame.h>
#include <jdk/internal/net/http/frame/WindowUpdateFrame.h>
#include <jcpp.h>

#undef ACK
#undef COPY_THRESHOLD
#undef DEBUG
#undef FRAME_HEADER_SIZE
#undef FRAME_SIZE_ERROR
#undef MAX_PARAM
#undef PADDED
#undef PRIORITY
#undef PROTOCOL_ERROR
#undef TYPE
#undef UTF_8

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $AbstractList = ::java::util::AbstractList;
using $ArrayDeque = ::java::util::ArrayDeque;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Supplier = ::java::util::function::Supplier;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $ContinuationFrame = ::jdk::internal::net::http::frame::ContinuationFrame;
using $DataFrame = ::jdk::internal::net::http::frame::DataFrame;
using $ErrorFrame = ::jdk::internal::net::http::frame::ErrorFrame;
using $FramesDecoder$FrameProcessor = ::jdk::internal::net::http::frame::FramesDecoder$FrameProcessor;
using $GoAwayFrame = ::jdk::internal::net::http::frame::GoAwayFrame;
using $HeaderFrame = ::jdk::internal::net::http::frame::HeaderFrame;
using $HeadersFrame = ::jdk::internal::net::http::frame::HeadersFrame;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;
using $MalformedFrame = ::jdk::internal::net::http::frame::MalformedFrame;
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

class FramesDecoder$$Lambda$toString : public $Supplier {
	$class(FramesDecoder$$Lambda$toString, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<FramesDecoder$$Lambda$toString>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo FramesDecoder$$Lambda$toString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(FramesDecoder$$Lambda$toString, inst$)},
	{}
};
$MethodInfo FramesDecoder$$Lambda$toString::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(FramesDecoder$$Lambda$toString::*)($String*)>(&FramesDecoder$$Lambda$toString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo FramesDecoder$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.frame.FramesDecoder$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* FramesDecoder$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(FramesDecoder$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* FramesDecoder$$Lambda$toString::class$ = nullptr;

$FieldInfo _FramesDecoder_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(FramesDecoder, $assertionsDisabled)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $STATIC | $FINAL, $staticField(FramesDecoder, debug)},
	{"frameProcessor", "Ljdk/internal/net/http/frame/FramesDecoder$FrameProcessor;", nullptr, $PRIVATE | $FINAL, $field(FramesDecoder, frameProcessor)},
	{"maxFrameSize", "I", nullptr, $PRIVATE | $FINAL, $field(FramesDecoder, maxFrameSize)},
	{"currentBuffer", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $field(FramesDecoder, currentBuffer)},
	{"tailBuffers", "Ljava/util/ArrayDeque;", "Ljava/util/ArrayDeque<Ljava/nio/ByteBuffer;>;", $PRIVATE | $FINAL, $field(FramesDecoder, tailBuffers)},
	{"tailSize", "I", nullptr, $PRIVATE, $field(FramesDecoder, tailSize)},
	{"slicedToDataFrame", "Z", nullptr, $PRIVATE, $field(FramesDecoder, slicedToDataFrame)},
	{"prepareToRelease", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE | $FINAL, $field(FramesDecoder, prepareToRelease)},
	{"frameHeaderParsed", "Z", nullptr, $PRIVATE, $field(FramesDecoder, frameHeaderParsed)},
	{"frameLength", "I", nullptr, $PRIVATE, $field(FramesDecoder, frameLength)},
	{"frameType", "I", nullptr, $PRIVATE, $field(FramesDecoder, frameType)},
	{"frameFlags", "I", nullptr, $PRIVATE, $field(FramesDecoder, frameFlags)},
	{"frameStreamid", "I", nullptr, $PRIVATE, $field(FramesDecoder, frameStreamid)},
	{"closed", "Z", nullptr, $PRIVATE, $field(FramesDecoder, closed)},
	{"COPY_THRESHOLD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FramesDecoder, COPY_THRESHOLD)},
	{}
};

$MethodInfo _FramesDecoder_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/frame/FramesDecoder$FrameProcessor;)V", nullptr, $PUBLIC, $method(static_cast<void(FramesDecoder::*)($FramesDecoder$FrameProcessor*)>(&FramesDecoder::init$))},
	{"<init>", "(Ljdk/internal/net/http/frame/FramesDecoder$FrameProcessor;I)V", nullptr, $PUBLIC, $method(static_cast<void(FramesDecoder::*)($FramesDecoder$FrameProcessor*,int32_t)>(&FramesDecoder::init$))},
	{"close", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"decode", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"frameProcessed", "()V", nullptr, $PRIVATE, $method(static_cast<void(FramesDecoder::*)()>(&FramesDecoder::frameProcessed))},
	{"getBuffers", "(ZI)Ljava/util/List;", "(ZI)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(FramesDecoder::*)(bool,int32_t)>(&FramesDecoder::getBuffers))},
	{"getByte", "()I", nullptr, $PUBLIC},
	{"getBytes", "(I)[B", nullptr, $PUBLIC},
	{"getInt", "()I", nullptr, $PUBLIC},
	{"getShort", "()I", nullptr, $PUBLIC},
	{"nextBuffer", "()V", nullptr, $PRIVATE, $method(static_cast<void(FramesDecoder::*)()>(&FramesDecoder::nextBuffer))},
	{"nextFrame", "()Ljdk/internal/net/http/frame/Http2Frame;", nullptr, $PRIVATE, $method(static_cast<$Http2Frame*(FramesDecoder::*)()>(&FramesDecoder::nextFrame)), "java.io.IOException"},
	{"parseContinuationFrame", "(III)Ljdk/internal/net/http/frame/Http2Frame;", nullptr, $PRIVATE, $method(static_cast<$Http2Frame*(FramesDecoder::*)(int32_t,int32_t,int32_t)>(&FramesDecoder::parseContinuationFrame))},
	{"parseDataFrame", "(III)Ljdk/internal/net/http/frame/Http2Frame;", nullptr, $PRIVATE, $method(static_cast<$Http2Frame*(FramesDecoder::*)(int32_t,int32_t,int32_t)>(&FramesDecoder::parseDataFrame))},
	{"parseFrameBody", "()Ljdk/internal/net/http/frame/Http2Frame;", nullptr, $PRIVATE, $method(static_cast<$Http2Frame*(FramesDecoder::*)()>(&FramesDecoder::parseFrameBody)), "java.io.IOException"},
	{"parseFrameHeader", "()V", nullptr, $PRIVATE, $method(static_cast<void(FramesDecoder::*)()>(&FramesDecoder::parseFrameHeader)), "java.io.IOException"},
	{"parseGoAwayFrame", "(III)Ljdk/internal/net/http/frame/Http2Frame;", nullptr, $PRIVATE, $method(static_cast<$Http2Frame*(FramesDecoder::*)(int32_t,int32_t,int32_t)>(&FramesDecoder::parseGoAwayFrame))},
	{"parseHeadersFrame", "(III)Ljdk/internal/net/http/frame/Http2Frame;", nullptr, $PRIVATE, $method(static_cast<$Http2Frame*(FramesDecoder::*)(int32_t,int32_t,int32_t)>(&FramesDecoder::parseHeadersFrame))},
	{"parsePingFrame", "(III)Ljdk/internal/net/http/frame/Http2Frame;", nullptr, $PRIVATE, $method(static_cast<$Http2Frame*(FramesDecoder::*)(int32_t,int32_t,int32_t)>(&FramesDecoder::parsePingFrame))},
	{"parsePriorityFrame", "(III)Ljdk/internal/net/http/frame/Http2Frame;", nullptr, $PRIVATE, $method(static_cast<$Http2Frame*(FramesDecoder::*)(int32_t,int32_t,int32_t)>(&FramesDecoder::parsePriorityFrame))},
	{"parsePushPromiseFrame", "(III)Ljdk/internal/net/http/frame/Http2Frame;", nullptr, $PRIVATE, $method(static_cast<$Http2Frame*(FramesDecoder::*)(int32_t,int32_t,int32_t)>(&FramesDecoder::parsePushPromiseFrame))},
	{"parseResetFrame", "(III)Ljdk/internal/net/http/frame/Http2Frame;", nullptr, $PRIVATE, $method(static_cast<$Http2Frame*(FramesDecoder::*)(int32_t,int32_t,int32_t)>(&FramesDecoder::parseResetFrame))},
	{"parseSettingsFrame", "(III)Ljdk/internal/net/http/frame/Http2Frame;", nullptr, $PRIVATE, $method(static_cast<$Http2Frame*(FramesDecoder::*)(int32_t,int32_t,int32_t)>(&FramesDecoder::parseSettingsFrame))},
	{"parseWindowUpdateFrame", "(III)Ljdk/internal/net/http/frame/Http2Frame;", nullptr, $PRIVATE, $method(static_cast<$Http2Frame*(FramesDecoder::*)(int32_t,int32_t,int32_t)>(&FramesDecoder::parseWindowUpdateFrame))},
	{"skipBytes", "(I)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _FramesDecoder_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.frame.FramesDecoder$FrameProcessor", "jdk.internal.net.http.frame.FramesDecoder", "FrameProcessor", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _FramesDecoder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.frame.FramesDecoder",
	"java.lang.Object",
	nullptr,
	_FramesDecoder_FieldInfo_,
	_FramesDecoder_MethodInfo_,
	nullptr,
	nullptr,
	_FramesDecoder_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.frame.FramesDecoder$FrameProcessor"
};

$Object* allocate$FramesDecoder($Class* clazz) {
	return $of($alloc(FramesDecoder));
}

bool FramesDecoder::$assertionsDisabled = false;
$Logger* FramesDecoder::debug = nullptr;

void FramesDecoder::init$($FramesDecoder$FrameProcessor* frameProcessor) {
	FramesDecoder::init$(frameProcessor, 16 * 1024);
}

void FramesDecoder::init$($FramesDecoder$FrameProcessor* frameProcessor, int32_t maxFrameSize) {
	$set(this, tailBuffers, $new($ArrayDeque));
	this->tailSize = 0;
	this->slicedToDataFrame = false;
	$set(this, prepareToRelease, $new($ArrayList));
	this->frameHeaderParsed = false;
	$set(this, frameProcessor, frameProcessor);
	this->maxFrameSize = $Math::min($Math::max(16 * 1024, maxFrameSize), 16 * 1024 * 1024 - 1);
}

void FramesDecoder::decode($ByteBuffer* inBoundBuffer) {
	$useLocalCurrentObjectStackCache();
	if (this->closed) {
		if ($nc(FramesDecoder::debug)->on()) {
			$nc(FramesDecoder::debug)->log("closed: ignoring buffer (%s bytes)"_s, $$new($ObjectArray, {$($of($Integer::valueOf($nc(inBoundBuffer)->remaining())))}));
		}
		$nc(inBoundBuffer)->position(inBoundBuffer->limit());
		return;
	}
	int32_t remaining = $nc(inBoundBuffer)->remaining();
	if ($nc(FramesDecoder::debug)->on()) {
		$nc(FramesDecoder::debug)->log("decodes: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(remaining)))}));
	}
	if (remaining > 0) {
		if (this->currentBuffer == nullptr) {
			$set(this, currentBuffer, inBoundBuffer);
		} else {
			$var($ByteBuffer, b, this->currentBuffer);
			if (!$nc(this->tailBuffers)->isEmpty()) {
				$assign(b, $cast($ByteBuffer, $nc(this->tailBuffers)->getLast()));
			}
			int32_t limit = $nc(b)->limit();
			int32_t freeSpace = b->capacity() - limit;
			if (remaining <= FramesDecoder::COPY_THRESHOLD && freeSpace >= remaining) {
				int32_t position = b->position();
				b->position(limit);
				b->limit(limit + inBoundBuffer->remaining());
				b->put(inBoundBuffer);
				b->position(position);
				if (b != this->currentBuffer) {
					this->tailSize += remaining;
				}
				if ($nc(FramesDecoder::debug)->on()) {
					$nc(FramesDecoder::debug)->log("copied: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(remaining)))}));
				}
			} else {
				if ($nc(FramesDecoder::debug)->on()) {
					$nc(FramesDecoder::debug)->log("added: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(remaining)))}));
				}
				$nc(this->tailBuffers)->add(inBoundBuffer);
				this->tailSize += remaining;
			}
		}
	}
	if ($nc(FramesDecoder::debug)->on()) {
		$nc(FramesDecoder::debug)->log("Tail size is now: %d, current="_s, $$new($ObjectArray, {
			$($of($Integer::valueOf(this->tailSize))),
			$($of($Integer::valueOf((this->currentBuffer == nullptr ? 0 : $nc(this->currentBuffer)->remaining()))))
		}));
	}
	$var($Http2Frame, frame, nullptr);
	while (($assign(frame, nextFrame())) != nullptr) {
		if ($nc(FramesDecoder::debug)->on()) {
			$nc(FramesDecoder::debug)->log("Got frame: %s"_s, $$new($ObjectArray, {$of(frame)}));
		}
		$nc(this->frameProcessor)->processFrame(frame);
		frameProcessed();
	}
}

$Http2Frame* FramesDecoder::nextFrame() {
	$useLocalCurrentObjectStackCache();
	while (true) {
		if (this->currentBuffer == nullptr) {
			return nullptr;
		}
		int64_t available = $nc(this->currentBuffer)->remaining() + this->tailSize;
		if (!this->frameHeaderParsed) {
			if (available >= $Http2Frame::FRAME_HEADER_SIZE) {
				parseFrameHeader();
				if (this->frameLength > this->maxFrameSize) {
					return $new($MalformedFrame, $ErrorFrame::FRAME_SIZE_ERROR, $$str({"Frame type("_s, $$str(this->frameType), ") length("_s, $$str(this->frameLength), ") exceeds MAX_FRAME_SIZE("_s, $$str(this->maxFrameSize), ")"_s}));
				}
				this->frameHeaderParsed = true;
			} else {
				if ($nc(FramesDecoder::debug)->on()) {
					$nc(FramesDecoder::debug)->log("Not enough data to parse header, needs: %d, has: %d"_s, $$new($ObjectArray, {
						$($of($Integer::valueOf($Http2Frame::FRAME_HEADER_SIZE))),
						$($of($Long::valueOf(available)))
					}));
				}
				return nullptr;
			}
		}
		available = this->currentBuffer == nullptr ? 0 : $nc(this->currentBuffer)->remaining() + this->tailSize;
		if ((this->frameLength == 0) || (this->currentBuffer != nullptr && available >= this->frameLength)) {
			$var($Http2Frame, frame, parseFrameBody());
			this->frameHeaderParsed = false;
			if (frame != nullptr) {
				return frame;
			}
		} else {
			if ($nc(FramesDecoder::debug)->on()) {
				$nc(FramesDecoder::debug)->log("Not enough data to parse frame body, needs: %d,  has: %d"_s, $$new($ObjectArray, {
					$($of($Integer::valueOf(this->frameLength))),
					$($of($Long::valueOf(available)))
				}));
			}
			return nullptr;
		}
	}
}

void FramesDecoder::frameProcessed() {
	$nc(this->prepareToRelease)->clear();
}

void FramesDecoder::parseFrameHeader() {
	int32_t x = getInt();
	this->frameLength = (int32_t)(((int32_t)((uint32_t)x >> 8)) & (uint32_t)0x00FFFFFF);
	this->frameType = (int32_t)(x & (uint32_t)255);
	this->frameFlags = getByte();
	this->frameStreamid = (int32_t)(getInt() & (uint32_t)0x7FFFFFFF);
}

void FramesDecoder::nextBuffer() {
	if (!$nc(this->currentBuffer)->hasRemaining()) {
		if (!this->slicedToDataFrame) {
			$nc(this->prepareToRelease)->add(this->currentBuffer);
		}
		this->slicedToDataFrame = false;
		$set(this, currentBuffer, $cast($ByteBuffer, $nc(this->tailBuffers)->poll()));
		if (this->currentBuffer != nullptr) {
			this->tailSize -= $nc(this->currentBuffer)->remaining();
		}
	}
}

int32_t FramesDecoder::getByte() {
	int32_t res = (int32_t)($nc(this->currentBuffer)->get() & (uint32_t)255);
	nextBuffer();
	return res;
}

int32_t FramesDecoder::getShort() {
	if ($nc(this->currentBuffer)->remaining() >= 2) {
		int32_t res = (int32_t)($nc(this->currentBuffer)->getShort() & (uint32_t)0x0000FFFF);
		nextBuffer();
		return res;
	}
	int32_t val = getByte();
	val = (val << 8) + getByte();
	return val;
}

int32_t FramesDecoder::getInt() {
	if ($nc(this->currentBuffer)->remaining() >= 4) {
		int32_t res = $nc(this->currentBuffer)->getInt();
		nextBuffer();
		return res;
	}
	int32_t val = getByte();
	val = (val << 8) + getByte();
	val = (val << 8) + getByte();
	val = (val << 8) + getByte();
	return val;
}

$bytes* FramesDecoder::getBytes(int32_t n) {
	$var($bytes, bytes, $new($bytes, n));
	int32_t offset = 0;
	while (n > 0) {
		int32_t length = $Math::min(n, $nc(this->currentBuffer)->remaining());
		$nc(this->currentBuffer)->get(bytes, offset, length);
		offset += length;
		n -= length;
		nextBuffer();
	}
	return bytes;
}

$List* FramesDecoder::getBuffers(bool isDataFrame, int32_t bytecount) {
	$useLocalCurrentObjectStackCache();
	$var($List, res, $new($ArrayList));
	while (bytecount > 0) {
		int32_t remaining = $nc(this->currentBuffer)->remaining();
		int32_t extract = $Math::min(remaining, bytecount);
		$var($ByteBuffer, extractedBuf, nullptr);
		if (isDataFrame) {
			$assign(extractedBuf, $nc($($Utils::sliceWithLimitedCapacity(this->currentBuffer, extract)))->asReadOnlyBuffer());
			this->slicedToDataFrame = true;
		} else {
			$assign(extractedBuf, $Utils::sliceWithLimitedCapacity(this->currentBuffer, extract));
		}
		res->add(extractedBuf);
		bytecount -= extract;
		nextBuffer();
	}
	return res;
}

void FramesDecoder::close($String* msg) {
	$useLocalCurrentObjectStackCache();
	this->closed = true;
	$nc(this->tailBuffers)->clear();
	int32_t bytes = this->tailSize;
	$var($ByteBuffer, b, this->currentBuffer);
	if (b != nullptr) {
		bytes += b->remaining();
		b->position(b->limit());
	}
	this->tailSize = 0;
	$set(this, currentBuffer, nullptr);
	if ($nc(FramesDecoder::debug)->on()) {
		$nc(FramesDecoder::debug)->log("closed %s, ignoring %d bytes"_s, $$new($ObjectArray, {
			$of(msg),
			$($of($Integer::valueOf(bytes)))
		}));
	}
}

void FramesDecoder::skipBytes(int32_t bytecount) {
	while (bytecount > 0) {
		int32_t remaining = $nc(this->currentBuffer)->remaining();
		int32_t extract = $Math::min(remaining, bytecount);
		$nc(this->currentBuffer)->position($nc(this->currentBuffer)->position() + extract);
		bytecount -= remaining;
		nextBuffer();
	}
}

$Http2Frame* FramesDecoder::parseFrameBody() {
	$useLocalCurrentObjectStackCache();
	if (!FramesDecoder::$assertionsDisabled && !this->frameHeaderParsed) {
		$throwNew($AssertionError);
	}
	switch (this->frameType) {
	case $DataFrame::TYPE:
		{
			return parseDataFrame(this->frameLength, this->frameStreamid, this->frameFlags);
		}
	case $HeadersFrame::TYPE:
		{
			return parseHeadersFrame(this->frameLength, this->frameStreamid, this->frameFlags);
		}
	case $PriorityFrame::TYPE:
		{
			return parsePriorityFrame(this->frameLength, this->frameStreamid, this->frameFlags);
		}
	case $ResetFrame::TYPE:
		{
			return parseResetFrame(this->frameLength, this->frameStreamid, this->frameFlags);
		}
	case $SettingsFrame::TYPE:
		{
			return parseSettingsFrame(this->frameLength, this->frameStreamid, this->frameFlags);
		}
	case $PushPromiseFrame::TYPE:
		{
			return parsePushPromiseFrame(this->frameLength, this->frameStreamid, this->frameFlags);
		}
	case $PingFrame::TYPE:
		{
			return parsePingFrame(this->frameLength, this->frameStreamid, this->frameFlags);
		}
	case $GoAwayFrame::TYPE:
		{
			return parseGoAwayFrame(this->frameLength, this->frameStreamid, this->frameFlags);
		}
	case $WindowUpdateFrame::TYPE:
		{
			return parseWindowUpdateFrame(this->frameLength, this->frameStreamid, this->frameFlags);
		}
	case $ContinuationFrame::TYPE:
		{
			return parseContinuationFrame(this->frameLength, this->frameStreamid, this->frameFlags);
		}
	default:
		{
			$Log::logTrace("Unknown incoming frame type: {0}"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->frameType)))}));
			skipBytes(this->frameLength);
			return nullptr;
		}
	}
}

$Http2Frame* FramesDecoder::parseDataFrame(int32_t frameLength, int32_t streamid, int32_t flags) {
	$useLocalCurrentObjectStackCache();
	if (streamid == 0) {
		return $new($MalformedFrame, $ErrorFrame::PROTOCOL_ERROR, "zero streamId for DataFrame"_s);
	}
	int32_t padLength = 0;
	if (((int32_t)(flags & (uint32_t)$DataFrame::PADDED)) != 0) {
		padLength = getByte();
		if (padLength >= frameLength) {
			return $new($MalformedFrame, $ErrorFrame::PROTOCOL_ERROR, "the length of the padding is the length of the frame payload or greater"_s);
		}
		--frameLength;
	}
	$var($DataFrame, df, $new($DataFrame, streamid, flags, $(getBuffers(true, frameLength - padLength)), padLength));
	skipBytes(padLength);
	return df;
}

$Http2Frame* FramesDecoder::parseHeadersFrame(int32_t frameLength, int32_t streamid, int32_t flags) {
	$useLocalCurrentObjectStackCache();
	if (streamid == 0) {
		return $new($MalformedFrame, $ErrorFrame::PROTOCOL_ERROR, "zero streamId for HeadersFrame"_s);
	}
	int32_t padLength = 0;
	if (((int32_t)(flags & (uint32_t)$HeadersFrame::PADDED)) != 0) {
		padLength = getByte();
		--frameLength;
	}
	bool hasPriority = ((int32_t)(flags & (uint32_t)$HeadersFrame::PRIORITY)) != 0;
	bool exclusive = false;
	int32_t streamDependency = 0;
	int32_t weight = 0;
	if (hasPriority) {
		int32_t x = getInt();
		exclusive = ((int32_t)(x & (uint32_t)(int32_t)0x80000000)) != 0;
		streamDependency = (int32_t)(x & (uint32_t)0x7FFFFFFF);
		weight = getByte();
		frameLength -= 5;
	}
	if (frameLength < padLength) {
		return $new($MalformedFrame, $ErrorFrame::PROTOCOL_ERROR, "Padding exceeds the size remaining for the header block"_s);
	}
	$var($HeadersFrame, hf, $new($HeadersFrame, streamid, flags, $(getBuffers(false, frameLength - padLength)), padLength));
	skipBytes(padLength);
	if (hasPriority) {
		hf->setPriority(streamDependency, exclusive, weight);
	}
	return hf;
}

$Http2Frame* FramesDecoder::parsePriorityFrame(int32_t frameLength, int32_t streamid, int32_t flags) {
	$useLocalCurrentObjectStackCache();
	if (streamid == 0) {
		return $new($MalformedFrame, $ErrorFrame::PROTOCOL_ERROR, "zero streamId for PriorityFrame"_s);
	}
	if (frameLength != 5) {
		skipBytes(frameLength);
		return $new($MalformedFrame, $ErrorFrame::FRAME_SIZE_ERROR, streamid, $$str({"PriorityFrame length is "_s, $$str(frameLength), ", expected 5"_s}));
	}
	int32_t x = getInt();
	int32_t weight = getByte();
	return $new($PriorityFrame, streamid, (int32_t)(x & (uint32_t)0x7FFFFFFF), ((int32_t)(x & (uint32_t)(int32_t)0x80000000)) != 0, weight);
}

$Http2Frame* FramesDecoder::parseResetFrame(int32_t frameLength, int32_t streamid, int32_t flags) {
	$useLocalCurrentObjectStackCache();
	if (streamid == 0) {
		return $new($MalformedFrame, $ErrorFrame::PROTOCOL_ERROR, "zero streamId for ResetFrame"_s);
	}
	if (frameLength != 4) {
		return $new($MalformedFrame, $ErrorFrame::FRAME_SIZE_ERROR, $$str({"ResetFrame length is "_s, $$str(frameLength), ", expected 4"_s}));
	}
	return $new($ResetFrame, streamid, getInt());
}

$Http2Frame* FramesDecoder::parseSettingsFrame(int32_t frameLength, int32_t streamid, int32_t flags) {
	$useLocalCurrentObjectStackCache();
	if (streamid != 0) {
		return $new($MalformedFrame, $ErrorFrame::PROTOCOL_ERROR, "non-zero streamId for SettingsFrame"_s);
	}
	if (((int32_t)($SettingsFrame::ACK & (uint32_t)flags)) != 0 && frameLength > 0) {
		return $new($MalformedFrame, $ErrorFrame::FRAME_SIZE_ERROR, "ACK SettingsFrame is not empty"_s);
	}
	if (frameLength % 6 != 0) {
		return $new($MalformedFrame, $ErrorFrame::FRAME_SIZE_ERROR, $$str({"invalid SettingsFrame size: "_s, $$str(frameLength)}));
	}
	$var($SettingsFrame, sf, $new($SettingsFrame, flags));
	int32_t n = frameLength / 6;
	for (int32_t i = 0; i < n; ++i) {
		int32_t id = getShort();
		int32_t val = getInt();
		if (id > 0 && id <= $SettingsFrame::MAX_PARAM) {
			sf->setParameter(id, val);
		}
	}
	return sf;
}

$Http2Frame* FramesDecoder::parsePushPromiseFrame(int32_t frameLength, int32_t streamid, int32_t flags) {
	$useLocalCurrentObjectStackCache();
	if (streamid == 0) {
		return $new($MalformedFrame, $ErrorFrame::PROTOCOL_ERROR, "zero streamId for PushPromiseFrame"_s);
	}
	int32_t padLength = 0;
	if (((int32_t)(flags & (uint32_t)$PushPromiseFrame::PADDED)) != 0) {
		padLength = getByte();
		--frameLength;
	}
	int32_t promisedStream = (int32_t)(getInt() & (uint32_t)0x7FFFFFFF);
	frameLength -= 4;
	if (frameLength < padLength) {
		return $new($MalformedFrame, $ErrorFrame::PROTOCOL_ERROR, "Padding exceeds the size remaining for the PushPromiseFrame"_s);
	}
	$var($PushPromiseFrame, ppf, $new($PushPromiseFrame, streamid, flags, promisedStream, $(getBuffers(false, frameLength - padLength)), padLength));
	skipBytes(padLength);
	return ppf;
}

$Http2Frame* FramesDecoder::parsePingFrame(int32_t frameLength, int32_t streamid, int32_t flags) {
	$useLocalCurrentObjectStackCache();
	if (streamid != 0) {
		return $new($MalformedFrame, $ErrorFrame::PROTOCOL_ERROR, "non-zero streamId for PingFrame"_s);
	}
	if (frameLength != 8) {
		return $new($MalformedFrame, $ErrorFrame::FRAME_SIZE_ERROR, $$str({"PingFrame length is "_s, $$str(frameLength), ", expected 8"_s}));
	}
	return $new($PingFrame, flags, $(getBytes(8)));
}

$Http2Frame* FramesDecoder::parseGoAwayFrame(int32_t frameLength, int32_t streamid, int32_t flags) {
	$useLocalCurrentObjectStackCache();
	if (streamid != 0) {
		return $new($MalformedFrame, $ErrorFrame::PROTOCOL_ERROR, "non-zero streamId for GoAwayFrame"_s);
	}
	if (frameLength < 8) {
		return $new($MalformedFrame, $ErrorFrame::FRAME_SIZE_ERROR, "Invalid GoAway frame size"_s);
	}
	int32_t lastStream = (int32_t)(getInt() & (uint32_t)0x7FFFFFFF);
	int32_t errorCode = getInt();
	$var($bytes, debugData, getBytes(frameLength - 8));
	if ($nc(debugData)->length > 0) {
		$init($StandardCharsets);
		$Log::logError($$str({"GoAway debugData "_s, $$new($String, debugData, $StandardCharsets::UTF_8)}), $$new($ObjectArray, 0));
	}
	return $new($GoAwayFrame, lastStream, errorCode, debugData);
}

$Http2Frame* FramesDecoder::parseWindowUpdateFrame(int32_t frameLength, int32_t streamid, int32_t flags) {
	$useLocalCurrentObjectStackCache();
	if (frameLength != 4) {
		return $new($MalformedFrame, $ErrorFrame::FRAME_SIZE_ERROR, $$str({"WindowUpdateFrame length is "_s, $$str(frameLength), ", expected 4"_s}));
	}
	return $new($WindowUpdateFrame, streamid, (int32_t)(getInt() & (uint32_t)0x7FFFFFFF));
}

$Http2Frame* FramesDecoder::parseContinuationFrame(int32_t frameLength, int32_t streamid, int32_t flags) {
	if (streamid == 0) {
		return $new($MalformedFrame, $ErrorFrame::PROTOCOL_ERROR, "zero streamId for ContinuationFrame"_s);
	}
	return $new($ContinuationFrame, streamid, flags, $(getBuffers(false, frameLength)));
}

void clinit$FramesDecoder($Class* class$) {
	FramesDecoder::$assertionsDisabled = !FramesDecoder::class$->desiredAssertionStatus();
	$init($Utils);
	$assignStatic(FramesDecoder::debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(FramesDecoder$$Lambda$toString, static_cast<$String*>("FramesDecoder"_s))), $Utils::DEBUG));
}

FramesDecoder::FramesDecoder() {
}

$Class* FramesDecoder::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(FramesDecoder$$Lambda$toString::classInfo$.name)) {
			return FramesDecoder$$Lambda$toString::load$(name, initialize);
		}
	}
	$loadClass(FramesDecoder, name, initialize, &_FramesDecoder_ClassInfo_, clinit$FramesDecoder, allocate$FramesDecoder);
	return class$;
}

$Class* FramesDecoder::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk