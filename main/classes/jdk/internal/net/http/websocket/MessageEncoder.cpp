#include <jdk/internal/net/http/websocket/MessageEncoder.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/charset/CharacterCodingException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <java/nio/charset/CoderResult.h>
#include <java/nio/charset/CodingErrorAction.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/SecureRandom.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/websocket/Frame$HeaderWriter.h>
#include <jdk/internal/net/http/websocket/Frame$Masker.h>
#include <jdk/internal/net/http/websocket/Frame$Opcode.h>
#include <jdk/internal/net/http/websocket/Frame.h>
#include <jcpp.h>

#undef BINARY
#undef CLOSE
#undef CONTINUATION
#undef DEBUG_WS
#undef MAX_CONTROL_FRAME_PAYLOAD_LENGTH
#undef MAX_HEADER_SIZE_BYTES
#undef PING
#undef PONG
#undef REPORT
#undef TEXT
#undef UTF_8

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
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
using $CharBuffer = ::java::nio::CharBuffer;
using $CharacterCodingException = ::java::nio::charset::CharacterCodingException;
using $Charset = ::java::nio::charset::Charset;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $CoderResult = ::java::nio::charset::CoderResult;
using $CodingErrorAction = ::java::nio::charset::CodingErrorAction;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $SecureRandom = ::java::security::SecureRandom;
using $Random = ::java::util::Random;
using $Supplier = ::java::util::function::Supplier;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $Frame = ::jdk::internal::net::http::websocket::Frame;
using $Frame$HeaderWriter = ::jdk::internal::net::http::websocket::Frame$HeaderWriter;
using $Frame$Masker = ::jdk::internal::net::http::websocket::Frame$Masker;
using $Frame$Opcode = ::jdk::internal::net::http::websocket::Frame$Opcode;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class MessageEncoder$$Lambda$toString : public $Supplier {
	$class(MessageEncoder$$Lambda$toString, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MessageEncoder$$Lambda$toString>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo MessageEncoder$$Lambda$toString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(MessageEncoder$$Lambda$toString, inst$)},
	{}
};
$MethodInfo MessageEncoder$$Lambda$toString::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(MessageEncoder$$Lambda$toString::*)($String*)>(&MessageEncoder$$Lambda$toString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MessageEncoder$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.websocket.MessageEncoder$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* MessageEncoder$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(MessageEncoder$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MessageEncoder$$Lambda$toString::class$ = nullptr;

$FieldInfo _MessageEncoder_FieldInfo_[] = {
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MessageEncoder, debug)},
	{"maskingKeySource", "Ljava/security/SecureRandom;", nullptr, $PRIVATE | $FINAL, $field(MessageEncoder, maskingKeySource)},
	{"headerWriter", "Ljdk/internal/net/http/websocket/Frame$HeaderWriter;", nullptr, $PRIVATE | $FINAL, $field(MessageEncoder, headerWriter)},
	{"payloadMasker", "Ljdk/internal/net/http/websocket/Frame$Masker;", nullptr, $PRIVATE | $FINAL, $field(MessageEncoder, payloadMasker)},
	{"charsetEncoder", "Ljava/nio/charset/CharsetEncoder;", nullptr, $PRIVATE | $FINAL, $field(MessageEncoder, charsetEncoder)},
	{"intermediateBuffer", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $FINAL, $field(MessageEncoder, intermediateBuffer)},
	{"headerBuffer", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $FINAL, $field(MessageEncoder, headerBuffer)},
	{"started", "Z", nullptr, $PRIVATE, $field(MessageEncoder, started)},
	{"flushing", "Z", nullptr, $PRIVATE, $field(MessageEncoder, flushing)},
	{"moreText", "Z", nullptr, $PRIVATE, $field(MessageEncoder, moreText)},
	{"headerCount", "J", nullptr, $PRIVATE, $field(MessageEncoder, headerCount)},
	{"previousFin", "Z", nullptr, $PRIVATE, $field(MessageEncoder, previousFin)},
	{"previousText", "Z", nullptr, $PRIVATE, $field(MessageEncoder, previousText)},
	{"closed", "Z", nullptr, $PRIVATE, $field(MessageEncoder, closed)},
	{"actualLen", "I", nullptr, $PRIVATE, $field(MessageEncoder, actualLen)},
	{"expectedLen", "I", nullptr, $PRIVATE, $field(MessageEncoder, expectedLen)},
	{}
};

$MethodInfo _MessageEncoder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(MessageEncoder::*)()>(&MessageEncoder::init$))},
	{"createIntermediateBuffer", "(I)Ljava/nio/ByteBuffer;", nullptr, $PROTECTED},
	{"encodeBinary", "(Ljava/nio/ByteBuffer;ZLjava/nio/ByteBuffer;)Z", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"encodeClose", "(ILjava/nio/CharBuffer;Ljava/nio/ByteBuffer;)Z", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"encodePing", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)Z", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"encodePong", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)Z", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"encodeText", "(Ljava/nio/CharBuffer;ZLjava/nio/ByteBuffer;)Z", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"maskAvailable", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)I", nullptr, $PRIVATE, $method(static_cast<int32_t(MessageEncoder::*)($ByteBuffer*,$ByteBuffer*)>(&MessageEncoder::maskAvailable))},
	{"putAvailable", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)Z", nullptr, $PRIVATE, $method(static_cast<bool(MessageEncoder::*)($ByteBuffer*,$ByteBuffer*)>(&MessageEncoder::putAvailable))},
	{"reset", "()V", nullptr, $PUBLIC},
	{"setupHeader", "(Ljdk/internal/net/http/websocket/Frame$Opcode;ZJ)V", nullptr, $PRIVATE, $method(static_cast<void(MessageEncoder::*)($Frame$Opcode*,bool,int64_t)>(&MessageEncoder::setupHeader))},
	{}
};

$ClassInfo _MessageEncoder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.websocket.MessageEncoder",
	"java.lang.Object",
	nullptr,
	_MessageEncoder_FieldInfo_,
	_MessageEncoder_MethodInfo_
};

$Object* allocate$MessageEncoder($Class* clazz) {
	return $of($alloc(MessageEncoder));
}

$Logger* MessageEncoder::debug = nullptr;

void MessageEncoder::init$() {
	$useLocalCurrentObjectStackCache();
	$set(this, maskingKeySource, $new($SecureRandom));
	$set(this, headerWriter, $new($Frame$HeaderWriter));
	$set(this, payloadMasker, $new($Frame$Masker));
	$init($StandardCharsets);
	$init($CodingErrorAction);
	$set(this, charsetEncoder, $nc($($nc($($nc($StandardCharsets::UTF_8)->newEncoder()))->onMalformedInput($CodingErrorAction::REPORT)))->onUnmappableCharacter($CodingErrorAction::REPORT));
	$set(this, intermediateBuffer, createIntermediateBuffer($Frame::MAX_CONTROL_FRAME_PAYLOAD_LENGTH));
	$set(this, headerBuffer, $ByteBuffer::allocate($Frame::MAX_HEADER_SIZE_BYTES));
	this->moreText = true;
	this->previousFin = true;
}

$ByteBuffer* MessageEncoder::createIntermediateBuffer(int32_t minSize) {
	int32_t capacity = $Utils::getIntegerNetProperty("jdk.httpclient.websocket.intermediateBufferSize"_s, 16384);
	return $ByteBuffer::allocate($Math::max(minSize, capacity));
}

void MessageEncoder::reset() {
	this->started = false;
	this->flushing = false;
	this->moreText = true;
	this->headerCount = 0;
	this->actualLen = 0;
}

bool MessageEncoder::encodeText($CharBuffer* src, bool last, $ByteBuffer* dst) {
	$useLocalCurrentObjectStackCache();
	if ($nc(MessageEncoder::debug)->on()) {
		$nc(MessageEncoder::debug)->log("encode text src=[pos=%s lim=%s cap=%s] last=%s dst=%s"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf($nc(src)->position()))),
			$($of($Integer::valueOf($nc(src)->limit()))),
			$($of($Integer::valueOf($nc(src)->capacity()))),
			$($of($Boolean::valueOf(last))),
			$of(dst)
		}));
	}
	if (this->closed) {
		$throwNew($IOException, "Output closed"_s);
	}
	if (!this->started) {
		if (!this->previousText && !this->previousFin) {
			$throwNew($IllegalStateException, "Unexpected text message"_s);
		}
		this->started = true;
		$nc($($nc(this->headerBuffer)->position(0)))->limit(0);
		$nc($($nc(this->intermediateBuffer)->position(0)))->limit(0);
		$nc(this->charsetEncoder)->reset();
	}
	while (true) {
		if ($nc(MessageEncoder::debug)->on()) {
			$nc(MessageEncoder::debug)->log("put"_s);
		}
		if (!putAvailable(this->headerBuffer, dst)) {
			return false;
		}
		if ($nc(MessageEncoder::debug)->on()) {
			$nc(MessageEncoder::debug)->log("mask"_s);
		}
		if (maskAvailable(this->intermediateBuffer, dst) < 0) {
			return false;
		}
		if ($nc(MessageEncoder::debug)->on()) {
			$nc(MessageEncoder::debug)->log("moreText"_s);
		}
		if (!this->moreText) {
			this->previousFin = last;
			this->previousText = true;
			return true;
		}
		$nc(this->intermediateBuffer)->clear();
		$var($CoderResult, r, nullptr);
		if (!this->flushing) {
			$assign(r, $nc(this->charsetEncoder)->encode(src, this->intermediateBuffer, true));
			if ($nc(r)->isUnderflow()) {
				this->flushing = true;
			}
		}
		if (this->flushing) {
			$assign(r, $nc(this->charsetEncoder)->flush(this->intermediateBuffer));
			if ($nc(r)->isUnderflow()) {
				this->moreText = false;
			}
		}
		if ($nc(r)->isError()) {
			try {
				r->throwException();
			} catch ($CharacterCodingException& e) {
				$throwNew($IOException, "Malformed text message"_s, e);
			}
		}
		if ($nc(MessageEncoder::debug)->on()) {
			$nc(MessageEncoder::debug)->log("frame #%s"_s, $$new($ObjectArray, {$($of($Long::valueOf(this->headerCount)))}));
		}
		$nc(this->intermediateBuffer)->flip();
		$init($Frame$Opcode);
		$Frame$Opcode* opcode = this->previousFin && this->headerCount == 0 ? $Frame$Opcode::TEXT : $Frame$Opcode::CONTINUATION;
		bool fin = last && !this->moreText;
		setupHeader(opcode, fin, $nc(this->intermediateBuffer)->remaining());
		++this->headerCount;
	}
	$shouldNotReachHere();
}

bool MessageEncoder::putAvailable($ByteBuffer* src, $ByteBuffer* dst) {
	int32_t available = $nc(dst)->remaining();
	if (available >= $nc(src)->remaining()) {
		dst->put(src);
		return true;
	} else {
		int32_t lim = src->limit();
		src->limit(src->position() + available);
		dst->put(src);
		src->limit(lim);
		return false;
	}
}

bool MessageEncoder::encodeBinary($ByteBuffer* src, bool last, $ByteBuffer* dst) {
	$useLocalCurrentObjectStackCache();
	if ($nc(MessageEncoder::debug)->on()) {
		$nc(MessageEncoder::debug)->log("encode binary src=%s last=%s dst=%s"_s, $$new($ObjectArray, {
			$of(src),
			$($of($Boolean::valueOf(last))),
			$of(dst)
		}));
	}
	if (this->closed) {
		$throwNew($IOException, "Output closed"_s);
	}
	if (!this->started) {
		if (this->previousText && !this->previousFin) {
			$throwNew($IllegalStateException, "Unexpected binary message"_s);
		}
		this->expectedLen = $nc(src)->remaining();
		$init($Frame$Opcode);
		$Frame$Opcode* opcode = this->previousFin ? $Frame$Opcode::BINARY : $Frame$Opcode::CONTINUATION;
		setupHeader(opcode, last, this->expectedLen);
		this->previousFin = last;
		this->previousText = false;
		this->started = true;
	}
	if (!putAvailable(this->headerBuffer, dst)) {
		return false;
	}
	int32_t count = maskAvailable(src, dst);
	this->actualLen += $Math::abs(count);
	if (count >= 0 && this->actualLen != this->expectedLen) {
		$throwNew($IOException, "Concurrent message modification"_s);
	}
	return count >= 0;
}

int32_t MessageEncoder::maskAvailable($ByteBuffer* src, $ByteBuffer* dst) {
	int32_t r0 = $nc(dst)->remaining();
	$nc(this->payloadMasker)->transferMasking(src, dst);
	int32_t masked = r0 - dst->remaining();
	return $nc(src)->hasRemaining() ? -masked : masked;
}

bool MessageEncoder::encodePing($ByteBuffer* src, $ByteBuffer* dst) {
	$useLocalCurrentObjectStackCache();
	if ($nc(MessageEncoder::debug)->on()) {
		$nc(MessageEncoder::debug)->log("encode ping src=%s dst=%s"_s, $$new($ObjectArray, {
			$of(src),
			$of(dst)
		}));
	}
	if (this->closed) {
		$throwNew($IOException, "Output closed"_s);
	}
	if (!this->started) {
		this->expectedLen = $nc(src)->remaining();
		if (this->expectedLen > $Frame::MAX_CONTROL_FRAME_PAYLOAD_LENGTH) {
			$throwNew($IllegalArgumentException, $$str({"Long message: "_s, $$str(this->expectedLen)}));
		}
		$init($Frame$Opcode);
		setupHeader($Frame$Opcode::PING, true, this->expectedLen);
		this->started = true;
	}
	if (!putAvailable(this->headerBuffer, dst)) {
		return false;
	}
	int32_t count = maskAvailable(src, dst);
	this->actualLen += $Math::abs(count);
	if (count >= 0 && this->actualLen != this->expectedLen) {
		$throwNew($IOException, "Concurrent message modification"_s);
	}
	return count >= 0;
}

bool MessageEncoder::encodePong($ByteBuffer* src, $ByteBuffer* dst) {
	$useLocalCurrentObjectStackCache();
	if ($nc(MessageEncoder::debug)->on()) {
		$nc(MessageEncoder::debug)->log("encode pong src=%s dst=%s"_s, $$new($ObjectArray, {
			$of(src),
			$of(dst)
		}));
	}
	if (this->closed) {
		$throwNew($IOException, "Output closed"_s);
	}
	if (!this->started) {
		this->expectedLen = $nc(src)->remaining();
		if (this->expectedLen > $Frame::MAX_CONTROL_FRAME_PAYLOAD_LENGTH) {
			$throwNew($IllegalArgumentException, $$str({"Long message: "_s, $$str(this->expectedLen)}));
		}
		$init($Frame$Opcode);
		setupHeader($Frame$Opcode::PONG, true, this->expectedLen);
		this->started = true;
	}
	if (!putAvailable(this->headerBuffer, dst)) {
		return false;
	}
	int32_t count = maskAvailable(src, dst);
	this->actualLen += $Math::abs(count);
	if (count >= 0 && this->actualLen != this->expectedLen) {
		$throwNew($IOException, "Concurrent message modification"_s);
	}
	return count >= 0;
}

bool MessageEncoder::encodeClose(int32_t statusCode, $CharBuffer* reason, $ByteBuffer* dst) {
	$useLocalCurrentObjectStackCache();
	if ($nc(MessageEncoder::debug)->on()) {
		$nc(MessageEncoder::debug)->log("encode close statusCode=%s reason=[pos=%s lim=%s cap=%s] dst=%s"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf(statusCode))),
			$($of($Integer::valueOf($nc(reason)->position()))),
			$($of($Integer::valueOf($nc(reason)->limit()))),
			$($of($Integer::valueOf($nc(reason)->capacity()))),
			$of(dst)
		}));
	}
	if (this->closed) {
		$throwNew($IOException, "Output closed"_s);
	}
	if (!this->started) {
		if ($nc(MessageEncoder::debug)->on()) {
			$nc(MessageEncoder::debug)->log("reason [pos=%s lim=%s cap=%s]"_s, $$new($ObjectArray, {
				$($of($Integer::valueOf($nc(reason)->position()))),
				$($of($Integer::valueOf($nc(reason)->limit()))),
				$($of($Integer::valueOf($nc(reason)->capacity())))
			}));
		}
		$nc($($nc(this->intermediateBuffer)->position(0)))->limit($Frame::MAX_CONTROL_FRAME_PAYLOAD_LENGTH);
		$nc(this->intermediateBuffer)->putChar((char16_t)statusCode);
		$var($CoderResult, r, $nc($($nc(this->charsetEncoder)->reset()))->encode(reason, this->intermediateBuffer, true));
		if ($nc(r)->isUnderflow()) {
			if ($nc(MessageEncoder::debug)->on()) {
				$nc(MessageEncoder::debug)->log("flushing"_s);
			}
			$assign(r, $nc(this->charsetEncoder)->flush(this->intermediateBuffer));
		}
		if ($nc(MessageEncoder::debug)->on()) {
			$nc(MessageEncoder::debug)->log("encoding result: %s"_s, $$new($ObjectArray, {$of(r)}));
		}
		if ($nc(r)->isError()) {
			try {
				r->throwException();
			} catch ($CharacterCodingException& e) {
				$throwNew($IOException, "Malformed reason"_s, e);
			}
		} else if (r->isOverflow()) {
			$throwNew($IOException, "Long reason"_s);
		} else if (!r->isUnderflow()) {
			$throwNew($InternalError);
		}
		$nc(this->intermediateBuffer)->flip();
		$init($Frame$Opcode);
		setupHeader($Frame$Opcode::CLOSE, true, $nc(this->intermediateBuffer)->remaining());
		this->started = true;
		this->closed = true;
		if ($nc(MessageEncoder::debug)->on()) {
			$nc(MessageEncoder::debug)->log("intermediateBuffer=%s"_s, $$new($ObjectArray, {$of(this->intermediateBuffer)}));
		}
	}
	if (!putAvailable(this->headerBuffer, dst)) {
		return false;
	}
	return maskAvailable(this->intermediateBuffer, dst) >= 0;
}

void MessageEncoder::setupHeader($Frame$Opcode* opcode, bool fin, int64_t payloadLen) {
	$useLocalCurrentObjectStackCache();
	if ($nc(MessageEncoder::debug)->on()) {
		$nc(MessageEncoder::debug)->log("frame opcode=%s fin=%s len=%s"_s, $$new($ObjectArray, {
			$of(opcode),
			$($of($Boolean::valueOf(fin))),
			$($of($Long::valueOf(payloadLen)))
		}));
	}
	$nc(this->headerBuffer)->clear();
	int32_t mask = $nc(this->maskingKeySource)->nextInt();
	$nc($($nc($($nc($($nc($($nc(this->headerWriter)->fin(fin)))->opcode(opcode)))->payloadLen(payloadLen)))->mask(mask)))->write(this->headerBuffer);
	$nc(this->headerBuffer)->flip();
	$nc(this->payloadMasker)->mask(mask);
}

void clinit$MessageEncoder($Class* class$) {
	$init($Utils);
	$assignStatic(MessageEncoder::debug, $Utils::getWebSocketLogger(static_cast<$Supplier*>($$new(MessageEncoder$$Lambda$toString, static_cast<$String*>("[Output]"_s))), $Utils::DEBUG_WS));
}

MessageEncoder::MessageEncoder() {
}

$Class* MessageEncoder::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(MessageEncoder$$Lambda$toString::classInfo$.name)) {
			return MessageEncoder$$Lambda$toString::load$(name, initialize);
		}
	}
	$loadClass(MessageEncoder, name, initialize, &_MessageEncoder_ClassInfo_, clinit$MessageEncoder, allocate$MessageEncoder);
	return class$;
}

$Class* MessageEncoder::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk