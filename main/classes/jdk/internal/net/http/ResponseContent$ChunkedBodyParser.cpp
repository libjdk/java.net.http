#include <jdk/internal/net/http/ResponseContent$ChunkedBodyParser.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Math.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/List.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/AbstractSubscription.h>
#include <jdk/internal/net/http/ResponseContent$ChunkState.h>
#include <jdk/internal/net/http/ResponseContent.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef ASSERTIONSENABLED
#undef DEBUG
#undef DONE
#undef EMPTY_BYTEBUFFER
#undef READING_DATA
#undef READING_LENGTH
#undef READMORE

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Consumer = ::java::util::function::Consumer;
using $Supplier = ::java::util::function::Supplier;
using $AbstractSubscription = ::jdk::internal::net::http::AbstractSubscription;
using $ResponseContent = ::jdk::internal::net::http::ResponseContent;
using $ResponseContent$BodyParser = ::jdk::internal::net::http::ResponseContent$BodyParser;
using $ResponseContent$ChunkState = ::jdk::internal::net::http::ResponseContent$ChunkState;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class ResponseContent$ChunkedBodyParser$$Lambda$dbgString : public $Supplier {
	$class(ResponseContent$ChunkedBodyParser$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(ResponseContent$ChunkedBodyParser* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseContent$ChunkedBodyParser$$Lambda$dbgString>());
	}
	ResponseContent$ChunkedBodyParser* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseContent$ChunkedBodyParser$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ResponseContent$ChunkedBodyParser$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo ResponseContent$ChunkedBodyParser$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/ResponseContent$ChunkedBodyParser;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseContent$ChunkedBodyParser$$Lambda$dbgString::*)(ResponseContent$ChunkedBodyParser*)>(&ResponseContent$ChunkedBodyParser$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseContent$ChunkedBodyParser$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseContent$ChunkedBodyParser$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* ResponseContent$ChunkedBodyParser$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(ResponseContent$ChunkedBodyParser$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseContent$ChunkedBodyParser$$Lambda$dbgString::class$ = nullptr;

class ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1 : public $Supplier {
	$class(ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1, $NO_CLASS_INIT, $Supplier)
public:
	void init$($ByteBuffer* chunk) {
		$set(this, chunk, chunk);
	}
	virtual $Object* get() override {
		 return $of(ResponseContent$ChunkedBodyParser::lambda$tryReadOneHunk$0(chunk));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1>());
	}
	$ByteBuffer* chunk = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1::fieldInfos[2] = {
	{"chunk", "Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $field(ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1, chunk)},
	{}
};
$MethodInfo ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1::methodInfos[3] = {
	{"<init>", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1::*)($ByteBuffer*)>(&ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1::load$($String* name, bool initialize) {
	$loadClass(ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1::class$ = nullptr;

$FieldInfo _ResponseContent$ChunkedBodyParser_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/ResponseContent;", nullptr, $FINAL | $SYNTHETIC, $field(ResponseContent$ChunkedBodyParser, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ResponseContent$ChunkedBodyParser, $assertionsDisabled)},
	{"READMORE", "Ljava/nio/ByteBuffer;", nullptr, $FINAL, $field(ResponseContent$ChunkedBodyParser, READMORE)},
	{"onComplete", "Ljava/util/function/Consumer;", "Ljava/util/function/Consumer<Ljava/lang/Throwable;>;", $FINAL, $field(ResponseContent$ChunkedBodyParser, onComplete)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(ResponseContent$ChunkedBodyParser, debug)},
	{"dbgTag", "Ljava/lang/String;", nullptr, $FINAL, $field(ResponseContent$ChunkedBodyParser, dbgTag)},
	{"closedExceptionally", "Ljava/lang/Throwable;", nullptr, $VOLATILE, $field(ResponseContent$ChunkedBodyParser, closedExceptionally)},
	{"partialChunklen", "I", nullptr, $VOLATILE, $field(ResponseContent$ChunkedBodyParser, partialChunklen)},
	{"chunklen", "I", nullptr, $VOLATILE, $field(ResponseContent$ChunkedBodyParser, chunklen)},
	{"bytesremaining", "I", nullptr, $VOLATILE, $field(ResponseContent$ChunkedBodyParser, bytesremaining)},
	{"cr", "Z", nullptr, $VOLATILE, $field(ResponseContent$ChunkedBodyParser, cr)},
	{"chunkext", "I", nullptr, $VOLATILE, $field(ResponseContent$ChunkedBodyParser, chunkext)},
	{"digits", "I", nullptr, $VOLATILE, $field(ResponseContent$ChunkedBodyParser, digits)},
	{"bytesToConsume", "I", nullptr, $VOLATILE, $field(ResponseContent$ChunkedBodyParser, bytesToConsume)},
	{"state", "Ljdk/internal/net/http/ResponseContent$ChunkState;", nullptr, $VOLATILE, $field(ResponseContent$ChunkedBodyParser, state)},
	{"sub", "Ljdk/internal/net/http/AbstractSubscription;", nullptr, $VOLATILE, $field(ResponseContent$ChunkedBodyParser, sub)},
	{}
};

$MethodInfo _ResponseContent$ChunkedBodyParser_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/ResponseContent;Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<Ljava/lang/Throwable;>;)V", 0, $method(static_cast<void(ResponseContent$ChunkedBodyParser::*)($ResponseContent*,$Consumer*)>(&ResponseContent$ChunkedBodyParser::init$))},
	{"accept", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"currentStateMessage", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"dbgString", "()Ljava/lang/String;", nullptr, 0},
	{"debugBuffer", "(Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(static_cast<void(ResponseContent$ChunkedBodyParser::*)($ByteBuffer*)>(&ResponseContent$ChunkedBodyParser::debugBuffer))},
	{"lambda$tryReadOneHunk$0", "(Ljava/nio/ByteBuffer;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($ByteBuffer*)>(&ResponseContent$ChunkedBodyParser::lambda$tryReadOneHunk$0))},
	{"onSubscribe", "(Ljdk/internal/net/http/AbstractSubscription;)V", nullptr, $PUBLIC},
	{"toDigit", "(I)I", nullptr, $PRIVATE, $method(static_cast<int32_t(ResponseContent$ChunkedBodyParser::*)(int32_t)>(&ResponseContent$ChunkedBodyParser::toDigit)), "java.io.IOException"},
	{"tryConsumeBytes", "(Ljava/nio/ByteBuffer;)I", nullptr, $PRIVATE, $method(static_cast<int32_t(ResponseContent$ChunkedBodyParser::*)($ByteBuffer*)>(&ResponseContent$ChunkedBodyParser::tryConsumeBytes)), "java.io.IOException"},
	{"tryPushOneHunk", "(Ljava/nio/ByteBuffer;Ljava/util/List;)Z", "(Ljava/nio/ByteBuffer;Ljava/util/List<Ljava/nio/ByteBuffer;>;)Z", $PRIVATE, $method(static_cast<bool(ResponseContent$ChunkedBodyParser::*)($ByteBuffer*,$List*)>(&ResponseContent$ChunkedBodyParser::tryPushOneHunk)), "java.io.IOException"},
	{"tryReadChunkLen", "(Ljava/nio/ByteBuffer;)I", nullptr, $PRIVATE, $method(static_cast<int32_t(ResponseContent$ChunkedBodyParser::*)($ByteBuffer*)>(&ResponseContent$ChunkedBodyParser::tryReadChunkLen)), "java.io.IOException"},
	{"tryReadOneHunk", "(Ljava/nio/ByteBuffer;)Ljava/nio/ByteBuffer;", nullptr, 0, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _ResponseContent$ChunkedBodyParser_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseContent$ChunkedBodyParser", "jdk.internal.net.http.ResponseContent", "ChunkedBodyParser", 0},
	{"jdk.internal.net.http.ResponseContent$BodyParser", "jdk.internal.net.http.ResponseContent", "BodyParser", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseContent$ChunkedBodyParser_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.ResponseContent$ChunkedBodyParser",
	"java.lang.Object",
	"jdk.internal.net.http.ResponseContent$BodyParser",
	_ResponseContent$ChunkedBodyParser_FieldInfo_,
	_ResponseContent$ChunkedBodyParser_MethodInfo_,
	nullptr,
	nullptr,
	_ResponseContent$ChunkedBodyParser_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseContent"
};

$Object* allocate$ResponseContent$ChunkedBodyParser($Class* clazz) {
	return $of($alloc(ResponseContent$ChunkedBodyParser));
}

bool ResponseContent$ChunkedBodyParser::$assertionsDisabled = false;

void ResponseContent$ChunkedBodyParser::init$($ResponseContent* this$0, $Consumer* onComplete) {
	$set(this, this$0, this$0);
	$init($Utils);
	$set(this, READMORE, $Utils::EMPTY_BYTEBUFFER);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(ResponseContent$ChunkedBodyParser$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, dbgTag, $str({this->this$0->dbgTag, "/ChunkedBodyParser"_s}));
	this->partialChunklen = 0;
	this->chunklen = -1;
	this->cr = false;
	this->chunkext = 0;
	this->digits = 0;
	$init($ResponseContent$ChunkState);
	$set(this, state, $ResponseContent$ChunkState::READING_LENGTH);
	$set(this, onComplete, onComplete);
}

$String* ResponseContent$ChunkedBodyParser::dbgString() {
	return this->dbgTag;
}

void ResponseContent$ChunkedBodyParser::debugBuffer($ByteBuffer* b) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(this->debug)->on()) {
		return;
	}
	$var($ByteBuffer, printable, $nc(b)->asReadOnlyBuffer());
	int32_t var$0 = $nc(printable)->limit();
	$var($bytes, bytes, $new($bytes, var$0 - printable->position()));
	printable->get(bytes, 0, bytes->length);
	$var($String, msg, "============== accepted ==================\n"_s);
	try {
		$var($String, str, $new($String, bytes, "UTF-8"_s));
		$plusAssign(msg, str);
	} catch ($Exception& x) {
		$plusAssign(msg, x);
		x->printStackTrace();
	}
	$plusAssign(msg, "\n==========================================\n"_s);
	$nc(this->debug)->log(msg);
}

void ResponseContent$ChunkedBodyParser::onSubscribe($AbstractSubscription* sub) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log($$str({"onSubscribe: "_s, $($nc($of(this->this$0->pusher))->getClass()->getName())}));
	}
	$nc(this->this$0->pusher)->onSubscribe(($set(this, sub, sub)));
}

$String* ResponseContent$ChunkedBodyParser::currentStateMessage() {
	return $String::format("chunked transfer encoding, state: %s"_s, $$new($ObjectArray, {$of(this->state)}));
}

void ResponseContent$ChunkedBodyParser::accept($ByteBuffer* b) {
	$useLocalCurrentObjectStackCache();
	if (this->closedExceptionally != nullptr) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log($$str({"already closed: "_s, this->closedExceptionally}));
		}
		return;
	}
	bool completed = false;
	try {
		$var($List, out, $new($ArrayList));
		do {
			if (tryPushOneHunk(b, out)) {
				if (!out->isEmpty()) {
					bool hasDemand = $nc($($nc(this->sub)->demand()))->tryDecrement();
					if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !hasDemand) {
						$throwNew($AssertionError);
					}
					$nc(this->this$0->pusher)->onNext($($Collections::unmodifiableList(out)));
					if ($nc(this->debug)->on()) {
						$nc(this->debug)->log("Chunks sent"_s);
					}
				}
				if ($nc(this->debug)->on()) {
					$nc(this->debug)->log("done!"_s);
				}
				if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !(this->closedExceptionally == nullptr)) {
					$throwNew($AssertionError);
				}
				$init($ResponseContent$ChunkState);
				if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !(this->state == $ResponseContent$ChunkState::DONE)) {
					$throwNew($AssertionError);
				}
				$nc(this->this$0->onFinished)->run();
				$nc(this->this$0->pusher)->onComplete();
				if ($nc(this->debug)->on()) {
					$nc(this->debug)->log("subscriber completed"_s);
				}
				completed = true;
				$nc(this->onComplete)->accept(this->closedExceptionally);
				break;
			}
		} while ($nc(b)->hasRemaining());
		if (!completed && !out->isEmpty()) {
			bool hasDemand = $nc($($nc(this->sub)->demand()))->tryDecrement();
			if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !hasDemand) {
				$throwNew($AssertionError);
			}
			$nc(this->this$0->pusher)->onNext($($Collections::unmodifiableList(out)));
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("Chunk sent"_s);
			}
		}
		$init($ResponseContent$ChunkState);
		if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !(this->state == $ResponseContent$ChunkState::DONE || !b->hasRemaining())) {
			$throwNew($AssertionError);
		}
	} catch ($Throwable& t) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Error while processing buffer: %s"_s, $$new($ObjectArray, {$of(t)}));
		}
		$set(this, closedExceptionally, t);
		if (!completed) {
			$nc(this->onComplete)->accept(t);
		}
	}
}

int32_t ResponseContent$ChunkedBodyParser::tryReadChunkLen($ByteBuffer* chunkbuf) {
	$useLocalCurrentObjectStackCache();
	$init($ResponseContent$ChunkState);
	if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !(this->state == $ResponseContent$ChunkState::READING_LENGTH)) {
		$throwNew($AssertionError);
	}
	while ($nc(chunkbuf)->hasRemaining()) {
		if (this->chunkext + this->digits >= 2050) {
			$throwNew($IOException, $$str({"Chunk header size too long: "_s, $$str((this->chunkext + this->digits))}));
		}
		int32_t c = chunkbuf->get();
		if (this->cr) {
			if (c == 10) {
				return this->partialChunklen;
			} else {
				$throwNew($IOException, "invalid chunk header"_s);
			}
		}
		if (c == 13) {
			this->cr = true;
			if (this->digits == 0 && $nc(this->debug)->on()) {
				$nc(this->debug)->log("tryReadChunkLen: invalid chunk header? No digits in chunkLen?"_s);
			}
		} else if (this->cr == false && this->chunkext > 0) {
			++this->chunkext;
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log($$str({"tryReadChunkLen: More extraneous character after chunk length: "_s, $$str(c)}));
			}
		} else {
			int32_t digit = toDigit(c);
			if (digit < 0) {
				if (this->digits > 0) {
					++this->chunkext;
					if ($nc(this->debug)->on()) {
						$nc(this->debug)->log($$str({"tryReadChunkLen: Extraneous character after chunk length: "_s, $$str(c)}));
					}
				} else {
					$throwNew($IOException, $$str({"Illegal character in chunk size: "_s, $$str(c)}));
				}
			} else {
				++this->digits;
				this->partialChunklen = this->partialChunklen * 16 + digit;
			}
		}
	}
	return -1;
}

int32_t ResponseContent$ChunkedBodyParser::tryConsumeBytes($ByteBuffer* chunkbuf) {
	int32_t n = this->bytesToConsume;
	if (n > 0) {
		int32_t e = $Math::min($nc(chunkbuf)->remaining(), n);
		$init($Utils);
		if ($Utils::ASSERTIONSENABLED) {
			if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !(n <= 2 && e <= 2)) {
				$throwNew($AssertionError);
			}
			$var($ByteBuffer, tmp, $nc(chunkbuf)->slice());
			if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !((n == 2 && e > 0) ? $nc(tmp)->get() == 13 : true)) {
				$throwNew($AssertionError);
			}
			if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !((n == 1 || e == 2) ? $nc(tmp)->get() == 10 : true)) {
				$throwNew($AssertionError);
			}
		}
		$nc(chunkbuf)->position(chunkbuf->position() + e);
		n -= e;
		this->bytesToConsume = n;
	}
	if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !(n >= 0)) {
		$throwNew($AssertionError);
	}
	return n;
}

$ByteBuffer* ResponseContent$ChunkedBodyParser::tryReadOneHunk($ByteBuffer* chunk) {
	$useLocalCurrentObjectStackCache();
	int32_t unfulfilled = this->bytesremaining;
	int32_t toconsume = this->bytesToConsume;
	$ResponseContent$ChunkState* st = this->state;
	$init($ResponseContent$ChunkState);
	if (st == $ResponseContent$ChunkState::READING_LENGTH && this->chunklen == -1) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log(static_cast<$Supplier*>($$new(ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1, chunk)));
		}
		int32_t clen = this->chunklen = tryReadChunkLen(chunk);
		if (clen == -1) {
			return this->READMORE;
		}
		this->digits = (this->chunkext = 0);
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Got chunk len %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(clen)))}));
		}
		this->cr = false;
		this->partialChunklen = 0;
		unfulfilled = (this->bytesremaining = clen);
		if (clen == 0) {
			toconsume = (this->bytesToConsume = 2);
		} else {
			st = ($set(this, state, $ResponseContent$ChunkState::READING_DATA));
		}
	}
	if (toconsume > 0) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Trying to consume bytes: %d (remaining in buffer: %s)"_s, $$new($ObjectArray, {
				$($of($Integer::valueOf(toconsume))),
				$($of($Integer::valueOf($nc(chunk)->remaining())))
			}));
		}
		if (tryConsumeBytes(chunk) > 0) {
			return this->READMORE;
		}
	}
	toconsume = this->bytesToConsume;
	if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !(toconsume == 0)) {
		$throwNew($AssertionError);
	}
	if (st == $ResponseContent$ChunkState::READING_LENGTH) {
		int32_t clen = this->chunklen;
		if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !(clen == 0)) {
			$throwNew($AssertionError);
		}
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("No more chunks: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(clen)))}));
		}
		$set(this, state, $ResponseContent$ChunkState::DONE);
		return nullptr;
	}
	int32_t clen = this->chunklen;
	if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !(clen > 0)) {
		$throwNew($AssertionError);
	}
	if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !(st == $ResponseContent$ChunkState::READING_DATA)) {
		$throwNew($AssertionError);
	}
	$var($ByteBuffer, returnBuffer, this->READMORE);
	if (unfulfilled > 0) {
		int32_t bytesread = $nc(chunk)->remaining();
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Reading chunk: available %d, needed %d"_s, $$new($ObjectArray, {
				$($of($Integer::valueOf(bytesread))),
				$($of($Integer::valueOf(unfulfilled)))
			}));
		}
		int32_t bytes2return = $Math::min(bytesread, unfulfilled);
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Returning chunk bytes: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(bytes2return)))}));
		}
		$assign(returnBuffer, $nc($($Utils::sliceWithLimitedCapacity(chunk, bytes2return)))->asReadOnlyBuffer());
		unfulfilled = this->bytesremaining -= bytes2return;
		if (unfulfilled == 0) {
			this->bytesToConsume = 2;
		}
	}
	if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !(unfulfilled >= 0)) {
		$throwNew($AssertionError);
	}
	if (unfulfilled == 0) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("No more bytes to read - %d yet to consume."_s, $$new($ObjectArray, {$($of($Integer::valueOf(unfulfilled)))}));
		}
		if (tryConsumeBytes(chunk) == 0) {
			this->chunklen = -1;
			this->partialChunklen = 0;
			this->cr = false;
			this->digits = (this->chunkext = 0);
			$set(this, state, $ResponseContent$ChunkState::READING_LENGTH);
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("Ready to read next chunk"_s);
			}
		}
	}
	if (returnBuffer == this->READMORE) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Need more data"_s);
		}
	}
	return returnBuffer;
}

bool ResponseContent$ChunkedBodyParser::tryPushOneHunk($ByteBuffer* b, $List* out) {
	$useLocalCurrentObjectStackCache();
	$init($ResponseContent$ChunkState);
	if (!ResponseContent$ChunkedBodyParser::$assertionsDisabled && !(this->state != $ResponseContent$ChunkState::DONE)) {
		$throwNew($AssertionError);
	}
	$var($ByteBuffer, b1, tryReadOneHunk(b));
	if (b1 != nullptr) {
		if (b1->hasRemaining()) {
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("Sending chunk to consumer (%d)"_s, $$new($ObjectArray, {$($of($Integer::valueOf(b1->remaining())))}));
			}
			$nc(out)->add(b1);
		}
		return false;
	} else {
		return true;
	}
}

int32_t ResponseContent$ChunkedBodyParser::toDigit(int32_t b) {
	if (b >= 48 && b <= 57) {
		return b - 48;
	}
	if (b >= 65 && b <= 70) {
		return b - 65 + 10;
	}
	if (b >= 97 && b <= 102) {
		return b - 97 + 10;
	}
	return -1;
}

void ResponseContent$ChunkedBodyParser::accept(Object$* b) {
	this->accept($cast($ByteBuffer, b));
}

$String* ResponseContent$ChunkedBodyParser::lambda$tryReadOneHunk$0($ByteBuffer* chunk) {
	$init(ResponseContent$ChunkedBodyParser);
	return $str({"Trying to read chunk len (remaining in buffer:"_s, $$str($nc(chunk)->remaining()), ")"_s});
}

void clinit$ResponseContent$ChunkedBodyParser($Class* class$) {
	$load($ResponseContent);
	ResponseContent$ChunkedBodyParser::$assertionsDisabled = !$ResponseContent::class$->desiredAssertionStatus();
}

ResponseContent$ChunkedBodyParser::ResponseContent$ChunkedBodyParser() {
}

$Class* ResponseContent$ChunkedBodyParser::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ResponseContent$ChunkedBodyParser$$Lambda$dbgString::classInfo$.name)) {
			return ResponseContent$ChunkedBodyParser$$Lambda$dbgString::load$(name, initialize);
		}
		if (name->equals(ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1::classInfo$.name)) {
			return ResponseContent$ChunkedBodyParser$$Lambda$lambda$tryReadOneHunk$0$1::load$(name, initialize);
		}
	}
	$loadClass(ResponseContent$ChunkedBodyParser, name, initialize, &_ResponseContent$ChunkedBodyParser_ClassInfo_, clinit$ResponseContent$ChunkedBodyParser, allocate$ResponseContent$ChunkedBodyParser);
	return class$;
}

$Class* ResponseContent$ChunkedBodyParser::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk