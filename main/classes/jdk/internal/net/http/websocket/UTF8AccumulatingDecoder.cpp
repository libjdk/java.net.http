#include <jdk/internal/net/http/websocket/UTF8AccumulatingDecoder.h>

#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CoderResult.h>
#include <java/nio/charset/CodingErrorAction.h>
#include <java/nio/charset/StandardCharsets.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef EMPTY_BYTEBUFFER
#undef REPORT
#undef UTF_8

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $Charset = ::java::nio::charset::Charset;
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $CoderResult = ::java::nio::charset::CoderResult;
using $CodingErrorAction = ::java::nio::charset::CodingErrorAction;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $Log = ::jdk::internal::net::http::common::Log;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _UTF8AccumulatingDecoder_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(UTF8AccumulatingDecoder, $assertionsDisabled)},
	{"decoder", "Ljava/nio/charset/CharsetDecoder;", nullptr, $PRIVATE | $FINAL, $field(UTF8AccumulatingDecoder, decoder)},
	{"leftovers", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $field(UTF8AccumulatingDecoder, leftovers)},
	{}
};

$MethodInfo _UTF8AccumulatingDecoder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(UTF8AccumulatingDecoder::*)()>(&UTF8AccumulatingDecoder::init$))},
	{"decode", "(Ljava/nio/ByteBuffer;Z)Ljava/nio/CharBuffer;", nullptr, 0, $method(static_cast<$CharBuffer*(UTF8AccumulatingDecoder::*)($ByteBuffer*,bool)>(&UTF8AccumulatingDecoder::decode)), "java.nio.charset.CharacterCodingException"},
	{}
};

$ClassInfo _UTF8AccumulatingDecoder_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.websocket.UTF8AccumulatingDecoder",
	"java.lang.Object",
	nullptr,
	_UTF8AccumulatingDecoder_FieldInfo_,
	_UTF8AccumulatingDecoder_MethodInfo_
};

$Object* allocate$UTF8AccumulatingDecoder($Class* clazz) {
	return $of($alloc(UTF8AccumulatingDecoder));
}

bool UTF8AccumulatingDecoder::$assertionsDisabled = false;

void UTF8AccumulatingDecoder::init$() {
	$init($StandardCharsets);
	$set(this, decoder, $nc($StandardCharsets::UTF_8)->newDecoder());
	{
		$init($CodingErrorAction);
		$nc(this->decoder)->onMalformedInput($CodingErrorAction::REPORT);
		$nc(this->decoder)->onUnmappableCharacter($CodingErrorAction::REPORT);
	}
	$init($Utils);
	$set(this, leftovers, $Utils::EMPTY_BYTEBUFFER);
}

$CharBuffer* UTF8AccumulatingDecoder::decode($ByteBuffer* in, bool endOfInput) {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, b, nullptr);
	int32_t rem = $nc(this->leftovers)->remaining();
	if (rem != 0) {
		$assign(b, $ByteBuffer::allocate(rem + $nc(in)->remaining()));
		$nc($($nc($($nc(b)->put(this->leftovers)))->put(in)))->flip();
	} else {
		$assign(b, in);
	}
	$var($CharBuffer, out, $CharBuffer::allocate($nc(b)->remaining()));
	$var($CoderResult, r, $nc(this->decoder)->decode(b, out, endOfInput));
	if ($nc(r)->isError()) {
		r->throwException();
	}
	if ($nc(b)->hasRemaining()) {
		$set(this, leftovers, $nc($($nc($($ByteBuffer::allocate(b->remaining())))->put(b)))->flip());
	} else {
		$init($Utils);
		$set(this, leftovers, $Utils::EMPTY_BYTEBUFFER);
	}
	if (!($nc(this->leftovers)->remaining() < 4)) {
		$Log::logError("The size of decoding leftovers is greater than expected: {0}"_s, $$new($ObjectArray, {$($of($Integer::valueOf($nc(this->leftovers)->remaining())))}));
	}
	$nc(b)->position(b->limit());
	if (!UTF8AccumulatingDecoder::$assertionsDisabled && ! !(endOfInput && $nc(this->leftovers)->hasRemaining())) {
		$throwNew($AssertionError, $of($$str({$$str(endOfInput), ", "_s, this->leftovers})));
	}
	if (endOfInput) {
		$assign(r, $nc(this->decoder)->flush(out));
		$nc(this->decoder)->reset();
		if ($nc(r)->isOverflow()) {
			$throwNew($InternalError, "Not yet implemented"_s);
		}
	}
	return $nc(out)->flip();
}

void clinit$UTF8AccumulatingDecoder($Class* class$) {
	UTF8AccumulatingDecoder::$assertionsDisabled = !UTF8AccumulatingDecoder::class$->desiredAssertionStatus();
}

UTF8AccumulatingDecoder::UTF8AccumulatingDecoder() {
}

$Class* UTF8AccumulatingDecoder::load$($String* name, bool initialize) {
	$loadClass(UTF8AccumulatingDecoder, name, initialize, &_UTF8AccumulatingDecoder_ClassInfo_, clinit$UTF8AccumulatingDecoder, allocate$UTF8AccumulatingDecoder);
	return class$;
}

$Class* UTF8AccumulatingDecoder::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk