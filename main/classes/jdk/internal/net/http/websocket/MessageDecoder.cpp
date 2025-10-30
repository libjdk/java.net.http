#include <jdk/internal/net/http/websocket/MessageDecoder.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/InternalError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/charset/CharacterCodingException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/util/Objects.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/websocket/FailWebSocketException.h>
#include <jdk/internal/net/http/websocket/Frame$Opcode.h>
#include <jdk/internal/net/http/websocket/Frame.h>
#include <jdk/internal/net/http/websocket/MessageDecoder$1.h>
#include <jdk/internal/net/http/websocket/MessageStreamConsumer.h>
#include <jdk/internal/net/http/websocket/StatusCodes.h>
#include <jdk/internal/net/http/websocket/UTF8AccumulatingDecoder.h>
#include <jcpp.h>

#undef BINARY
#undef CLOSE
#undef CONTINUATION
#undef DEBUG_WS
#undef MAX_CONTROL_FRAME_PAYLOAD_LENGTH
#undef NOT_CONSISTENT
#undef PING
#undef PONG
#undef TEXT
#undef UTF_8

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
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
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $Objects = ::java::util::Objects;
using $Supplier = ::java::util::function::Supplier;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $FailWebSocketException = ::jdk::internal::net::http::websocket::FailWebSocketException;
using $Frame = ::jdk::internal::net::http::websocket::Frame;
using $Frame$Consumer = ::jdk::internal::net::http::websocket::Frame$Consumer;
using $Frame$Opcode = ::jdk::internal::net::http::websocket::Frame$Opcode;
using $MessageDecoder$1 = ::jdk::internal::net::http::websocket::MessageDecoder$1;
using $MessageStreamConsumer = ::jdk::internal::net::http::websocket::MessageStreamConsumer;
using $StatusCodes = ::jdk::internal::net::http::websocket::StatusCodes;
using $UTF8AccumulatingDecoder = ::jdk::internal::net::http::websocket::UTF8AccumulatingDecoder;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class MessageDecoder$$Lambda$toString : public $Supplier {
	$class(MessageDecoder$$Lambda$toString, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MessageDecoder$$Lambda$toString>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo MessageDecoder$$Lambda$toString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(MessageDecoder$$Lambda$toString, inst$)},
	{}
};
$MethodInfo MessageDecoder$$Lambda$toString::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(MessageDecoder$$Lambda$toString::*)($String*)>(&MessageDecoder$$Lambda$toString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MessageDecoder$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.websocket.MessageDecoder$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* MessageDecoder$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(MessageDecoder$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MessageDecoder$$Lambda$toString::class$ = nullptr;

$FieldInfo _MessageDecoder_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(MessageDecoder, $assertionsDisabled)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MessageDecoder, debug)},
	{"output", "Ljdk/internal/net/http/websocket/MessageStreamConsumer;", nullptr, $PRIVATE | $FINAL, $field(MessageDecoder, output)},
	{"decoder", "Ljdk/internal/net/http/websocket/UTF8AccumulatingDecoder;", nullptr, $PRIVATE | $FINAL, $field(MessageDecoder, decoder)},
	{"fin", "Z", nullptr, $PRIVATE, $field(MessageDecoder, fin$)},
	{"opcode", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PRIVATE, $field(MessageDecoder, opcode$)},
	{"originatingOpcode", "Ljdk/internal/net/http/websocket/Frame$Opcode;", nullptr, $PRIVATE, $field(MessageDecoder, originatingOpcode)},
	{"payloadLen", "J", nullptr, $PRIVATE, $field(MessageDecoder, payloadLen$)},
	{"unconsumedPayloadLen", "J", nullptr, $PRIVATE, $field(MessageDecoder, unconsumedPayloadLen)},
	{"binaryData", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $field(MessageDecoder, binaryData)},
	{}
};

$MethodInfo _MessageDecoder_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/websocket/MessageStreamConsumer;)V", nullptr, 0, $method(static_cast<void(MessageDecoder::*)($MessageStreamConsumer*)>(&MessageDecoder::init$))},
	{"endFrame", "()V", nullptr, $PUBLIC},
	{"fin", "(Z)V", nullptr, $PUBLIC},
	{"getOutput", "()Ljdk/internal/net/http/websocket/MessageStreamConsumer;", nullptr, 0},
	{"mask", "(Z)V", nullptr, $PUBLIC},
	{"maskingKey", "(I)V", nullptr, $PUBLIC},
	{"opcode", "(Ljdk/internal/net/http/websocket/Frame$Opcode;)V", nullptr, $PUBLIC},
	{"payloadData", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC},
	{"payloadLen", "(J)V", nullptr, $PUBLIC},
	{"rsv1", "(Z)V", nullptr, $PUBLIC},
	{"rsv2", "(Z)V", nullptr, $PUBLIC},
	{"rsv3", "(Z)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _MessageDecoder_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.Frame$Consumer", "jdk.internal.net.http.websocket.Frame", "Consumer", $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.websocket.MessageDecoder$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _MessageDecoder_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.websocket.MessageDecoder",
	"java.lang.Object",
	"jdk.internal.net.http.websocket.Frame$Consumer",
	_MessageDecoder_FieldInfo_,
	_MessageDecoder_MethodInfo_,
	nullptr,
	nullptr,
	_MessageDecoder_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.MessageDecoder$1"
};

$Object* allocate$MessageDecoder($Class* clazz) {
	return $of($alloc(MessageDecoder));
}

bool MessageDecoder::$assertionsDisabled = false;
$Logger* MessageDecoder::debug = nullptr;

void MessageDecoder::init$($MessageStreamConsumer* output) {
	$set(this, decoder, $new($UTF8AccumulatingDecoder));
	$set(this, output, $cast($MessageStreamConsumer, $Objects::requireNonNull(output)));
}

$MessageStreamConsumer* MessageDecoder::getOutput() {
	return this->output;
}

void MessageDecoder::fin(bool value) {
	$useLocalCurrentObjectStackCache();
	if ($nc(MessageDecoder::debug)->on()) {
		$nc(MessageDecoder::debug)->log("fin %s"_s, $$new($ObjectArray, {$($of($Boolean::valueOf(value)))}));
	}
	this->fin$ = value;
}

void MessageDecoder::rsv1(bool value) {
	$useLocalCurrentObjectStackCache();
	if ($nc(MessageDecoder::debug)->on()) {
		$nc(MessageDecoder::debug)->log("rsv1 %s"_s, $$new($ObjectArray, {$($of($Boolean::valueOf(value)))}));
	}
	if (value) {
		$throwNew($FailWebSocketException, "Unexpected rsv1 bit"_s);
	}
}

void MessageDecoder::rsv2(bool value) {
	$useLocalCurrentObjectStackCache();
	if ($nc(MessageDecoder::debug)->on()) {
		$nc(MessageDecoder::debug)->log("rsv2 %s"_s, $$new($ObjectArray, {$($of($Boolean::valueOf(value)))}));
	}
	if (value) {
		$throwNew($FailWebSocketException, "Unexpected rsv2 bit"_s);
	}
}

void MessageDecoder::rsv3(bool value) {
	$useLocalCurrentObjectStackCache();
	if ($nc(MessageDecoder::debug)->on()) {
		$nc(MessageDecoder::debug)->log("rsv3 %s"_s, $$new($ObjectArray, {$($of($Boolean::valueOf(value)))}));
	}
	if (value) {
		$throwNew($FailWebSocketException, "Unexpected rsv3 bit"_s);
	}
}

void MessageDecoder::opcode($Frame$Opcode* v) {
	$useLocalCurrentObjectStackCache();
	if ($nc(MessageDecoder::debug)->on()) {
		$nc(MessageDecoder::debug)->log("opcode %s"_s, $$new($ObjectArray, {$of(v)}));
	}
	$init($Frame$Opcode);
	if (v == $Frame$Opcode::PING || v == $Frame$Opcode::PONG || v == $Frame$Opcode::CLOSE) {
		if (!this->fin$) {
			$throwNew($FailWebSocketException, $$str({"Fragmented control frame  "_s, v}));
		}
		$set(this, opcode$, v);
	} else {
		if (v == $Frame$Opcode::TEXT || v == $Frame$Opcode::BINARY) {
			if (this->originatingOpcode != nullptr) {
				$throwNew($FailWebSocketException, $($String::format("Unexpected frame %s (fin=%s)"_s, $$new($ObjectArray, {
					$of(v),
					$($of($Boolean::valueOf(this->fin$)))
				}))));
			}
			$set(this, opcode$, v);
			if (!this->fin$) {
				$set(this, originatingOpcode, v);
			}
		} else {
			if (v == $Frame$Opcode::CONTINUATION) {
				if (this->originatingOpcode == nullptr) {
					$throwNew($FailWebSocketException, $($String::format("Unexpected frame %s (fin=%s)"_s, $$new($ObjectArray, {
						$of(v),
						$($of($Boolean::valueOf(this->fin$)))
					}))));
				}
				$set(this, opcode$, v);
			} else {
				$throwNew($FailWebSocketException, $$str({"Unexpected opcode "_s, v}));
			}
		}
	}
}

void MessageDecoder::mask(bool value) {
	$useLocalCurrentObjectStackCache();
	if ($nc(MessageDecoder::debug)->on()) {
		$nc(MessageDecoder::debug)->log("mask %s"_s, $$new($ObjectArray, {$($of($Boolean::valueOf(value)))}));
	}
	if (value) {
		$throwNew($FailWebSocketException, "Masked frame received"_s);
	}
}

void MessageDecoder::payloadLen(int64_t value) {
	$useLocalCurrentObjectStackCache();
	if ($nc(MessageDecoder::debug)->on()) {
		$nc(MessageDecoder::debug)->log("payloadLen %s"_s, $$new($ObjectArray, {$($of($Long::valueOf(value)))}));
	}
	if ($nc(this->opcode$)->isControl()) {
		if (value > $Frame::MAX_CONTROL_FRAME_PAYLOAD_LENGTH) {
			$throwNew($FailWebSocketException, $($String::format("%s\'s payload length %s"_s, $$new($ObjectArray, {
				$of(this->opcode$),
				$($of($Long::valueOf(value)))
			}))));
		}
		$init($Frame$Opcode);
		if (!MessageDecoder::$assertionsDisabled && !$Frame$Opcode::CLOSE->isControl()) {
			$throwNew($AssertionError);
		}
		if (this->opcode$ == $Frame$Opcode::CLOSE && value == 1) {
			$throwNew($FailWebSocketException, "Incomplete status code"_s);
		}
	}
	this->payloadLen$ = value;
	this->unconsumedPayloadLen = value;
}

void MessageDecoder::maskingKey(int32_t value) {
	$throwNew($InternalError);
}

void MessageDecoder::payloadData($ByteBuffer* data) {
	$useLocalCurrentObjectStackCache();
	if ($nc(MessageDecoder::debug)->on()) {
		$nc(MessageDecoder::debug)->log("payload %s"_s, $$new($ObjectArray, {$of(data)}));
	}
	this->unconsumedPayloadLen -= $nc(data)->remaining();
	bool lastPayloadChunk = this->unconsumedPayloadLen == 0;
	if ($nc(this->opcode$)->isControl()) {
		if (this->binaryData != nullptr) {
			$nc(this->binaryData)->put(data);
		} else if (!lastPayloadChunk) {
			int32_t remaining = data->remaining();
			if (!MessageDecoder::$assertionsDisabled && !(remaining < $Frame::MAX_CONTROL_FRAME_PAYLOAD_LENGTH)) {
				$throwNew($AssertionError, $($of($Utils::dump($$new($ObjectArray, {$($of($Integer::valueOf(remaining)))})))));
			}
			$set(this, binaryData, $nc($($ByteBuffer::allocate($Frame::MAX_CONTROL_FRAME_PAYLOAD_LENGTH)))->put(data));
		} else {
			$set(this, binaryData, $nc($($ByteBuffer::allocate(data->remaining())))->put(data));
		}
	} else {
		bool last = this->fin$ && lastPayloadChunk;
		$init($Frame$Opcode);
		bool text = this->opcode$ == $Frame$Opcode::TEXT || this->originatingOpcode == $Frame$Opcode::TEXT;
		if (!text) {
			$nc(this->output)->onBinary($(data->slice()), last);
			data->position(data->limit());
		} else {
			bool binaryNonEmpty = data->hasRemaining();
			$var($CharBuffer, textData, nullptr);
			try {
				$assign(textData, $nc(this->decoder)->decode(data, last));
			} catch ($CharacterCodingException& e) {
				$throw($($$new($FailWebSocketException, $$str({"Invalid UTF-8 in frame "_s, this->opcode$}), $StatusCodes::NOT_CONSISTENT)->initCause(e)));
			}
			if (!(binaryNonEmpty && !$nc(textData)->hasRemaining())) {
				$nc(this->output)->onText(textData, last);
			}
		}
	}
}

void MessageDecoder::endFrame() {
	$useLocalCurrentObjectStackCache();
	if ($nc(MessageDecoder::debug)->on()) {
		$nc(MessageDecoder::debug)->log("end frame"_s);
	}
	if ($nc(this->opcode$)->isControl()) {
		$nc(this->binaryData)->flip();
	}
	$init($MessageDecoder$1);
	{
		char16_t statusCode = 0;
		$var($String, reason, nullptr)
		switch ($nc($MessageDecoder$1::$SwitchMap$jdk$internal$net$http$websocket$Frame$Opcode)->get($nc((this->opcode$))->ordinal())) {
		case 1:
			{
				statusCode = (char16_t)1005;
				$assign(reason, ""_s);
				if (this->payloadLen$ != 0) {
					int32_t len = $nc(this->binaryData)->remaining();
					if (!MessageDecoder::$assertionsDisabled && !(2 <= len && len <= $Frame::MAX_CONTROL_FRAME_PAYLOAD_LENGTH)) {
						$throwNew($AssertionError, $($of($Utils::dump($$new($ObjectArray, {
							$($of($Integer::valueOf(len))),
							$($of($Long::valueOf(this->payloadLen$)))
						})))));
					}
					statusCode = $nc(this->binaryData)->getChar();
					if (!$StatusCodes::isLegalToReceiveFromServer(statusCode)) {
						$throwNew($FailWebSocketException, $$str({"Illegal status code: "_s, $$str(statusCode)}));
					}
					try {
						$init($StandardCharsets);
						$assign(reason, $nc($($nc($($nc($StandardCharsets::UTF_8)->newDecoder()))->decode(this->binaryData)))->toString());
					} catch ($CharacterCodingException& e) {
						$throw($($$new($FailWebSocketException, "Illegal close reason"_s)->initCause(e)));
					}
				}
				$nc(this->output)->onClose(statusCode, reason);
				break;
			}
		case 2:
			{
				$nc(this->output)->onPing(this->binaryData);
				$set(this, binaryData, nullptr);
				break;
			}
		case 3:
			{
				$nc(this->output)->onPong(this->binaryData);
				$set(this, binaryData, nullptr);
				break;
			}
		default:
			{
				if (!MessageDecoder::$assertionsDisabled && !(this->opcode$ == $Frame$Opcode::TEXT || this->opcode$ == $Frame$Opcode::BINARY || this->opcode$ == $Frame$Opcode::CONTINUATION)) {
					$throwNew($AssertionError, $($of($Utils::dump($$new($ObjectArray, {$of(this->opcode$)})))));
				}
				if (this->fin$) {
					$set(this, originatingOpcode, nullptr);
				}
				break;
			}
		}
	}
	this->payloadLen$ = 0;
	$set(this, opcode$, nullptr);
}

void clinit$MessageDecoder($Class* class$) {
	MessageDecoder::$assertionsDisabled = !MessageDecoder::class$->desiredAssertionStatus();
	$init($Utils);
	$assignStatic(MessageDecoder::debug, $Utils::getWebSocketLogger(static_cast<$Supplier*>($$new(MessageDecoder$$Lambda$toString, static_cast<$String*>("[Input]"_s))), $Utils::DEBUG_WS));
}

MessageDecoder::MessageDecoder() {
}

$Class* MessageDecoder::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(MessageDecoder$$Lambda$toString::classInfo$.name)) {
			return MessageDecoder$$Lambda$toString::load$(name, initialize);
		}
	}
	$loadClass(MessageDecoder, name, initialize, &_MessageDecoder_ClassInfo_, clinit$MessageDecoder, allocate$MessageDecoder);
	return class$;
}

$Class* MessageDecoder::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk