#include <jdk/internal/net/http/LineSubscriberAdapter$LineSubscription.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Math.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CoderResult.h>
#include <java/nio/charset/CodingErrorAction.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/ConcurrentLinkedDeque.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <jdk/internal/net/http/LineSubscriberAdapter.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

#undef REPLACE

using $Serializable = ::java::io::Serializable;
using $AbstractStringBuilder = ::java::lang::AbstractStringBuilder;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $Charset = ::java::nio::charset::Charset;
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $CoderResult = ::java::nio::charset::CoderResult;
using $CodingErrorAction = ::java::nio::charset::CodingErrorAction;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $ConcurrentLinkedDeque = ::java::util::concurrent::ConcurrentLinkedDeque;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $LineSubscriberAdapter = ::jdk::internal::net::http::LineSubscriberAdapter;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class LineSubscriberAdapter$LineSubscription$$Lambda$loop : public $Runnable {
	$class(LineSubscriberAdapter$LineSubscription$$Lambda$loop, $NO_CLASS_INIT, $Runnable)
public:
	void init$(LineSubscriberAdapter$LineSubscription* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->loop();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LineSubscriberAdapter$LineSubscription$$Lambda$loop>());
	}
	LineSubscriberAdapter$LineSubscription* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LineSubscriberAdapter$LineSubscription$$Lambda$loop::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(LineSubscriberAdapter$LineSubscription$$Lambda$loop, inst$)},
	{}
};
$MethodInfo LineSubscriberAdapter$LineSubscription$$Lambda$loop::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/LineSubscriberAdapter$LineSubscription;)V", nullptr, $PUBLIC, $method(static_cast<void(LineSubscriberAdapter$LineSubscription$$Lambda$loop::*)(LineSubscriberAdapter$LineSubscription*)>(&LineSubscriberAdapter$LineSubscription$$Lambda$loop::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo LineSubscriberAdapter$LineSubscription$$Lambda$loop::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.LineSubscriberAdapter$LineSubscription$$Lambda$loop",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* LineSubscriberAdapter$LineSubscription$$Lambda$loop::load$($String* name, bool initialize) {
	$loadClass(LineSubscriberAdapter$LineSubscription$$Lambda$loop, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LineSubscriberAdapter$LineSubscription$$Lambda$loop::class$ = nullptr;

$FieldInfo _LineSubscriberAdapter$LineSubscription_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(LineSubscriberAdapter$LineSubscription, $assertionsDisabled)},
	{"upstreamSubscription", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $FINAL, $field(LineSubscriberAdapter$LineSubscription, upstreamSubscription)},
	{"decoder", "Ljava/nio/charset/CharsetDecoder;", nullptr, $FINAL, $field(LineSubscriberAdapter$LineSubscription, decoder)},
	{"newline", "Ljava/lang/String;", nullptr, $FINAL, $field(LineSubscriberAdapter$LineSubscription, newline)},
	{"downstreamDemand", "Ljdk/internal/net/http/common/Demand;", nullptr, $FINAL, $field(LineSubscriberAdapter$LineSubscription, downstreamDemand)},
	{"queue", "Ljava/util/concurrent/ConcurrentLinkedDeque;", "Ljava/util/concurrent/ConcurrentLinkedDeque<Ljava/nio/ByteBuffer;>;", $FINAL, $field(LineSubscriberAdapter$LineSubscription, queue)},
	{"scheduler", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $FINAL, $field(LineSubscriberAdapter$LineSubscription, scheduler)},
	{"upstream", "Ljava/util/concurrent/Flow$Subscriber;", "Ljava/util/concurrent/Flow$Subscriber<-Ljava/lang/String;>;", $FINAL, $field(LineSubscriberAdapter$LineSubscription, upstream)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<*>;", $FINAL, $field(LineSubscriberAdapter$LineSubscription, cf)},
	{"errorRef", "Ljava/util/concurrent/atomic/AtomicReference;", "Ljava/util/concurrent/atomic/AtomicReference<Ljava/lang/Throwable;>;", $PRIVATE | $FINAL, $field(LineSubscriberAdapter$LineSubscription, errorRef)},
	{"demanded", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $FINAL, $field(LineSubscriberAdapter$LineSubscription, demanded)},
	{"completed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(LineSubscriberAdapter$LineSubscription, completed)},
	{"cancelled", "Z", nullptr, $PRIVATE | $VOLATILE, $field(LineSubscriberAdapter$LineSubscription, cancelled)},
	{"chars", "[C", nullptr, $PRIVATE | $FINAL, $field(LineSubscriberAdapter$LineSubscription, chars)},
	{"leftover", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $FINAL, $field(LineSubscriberAdapter$LineSubscription, leftover)},
	{"buffer", "Ljava/nio/CharBuffer;", nullptr, $PRIVATE | $FINAL, $field(LineSubscriberAdapter$LineSubscription, buffer)},
	{"builder", "Ljava/lang/StringBuilder;", nullptr, $PRIVATE | $FINAL, $field(LineSubscriberAdapter$LineSubscription, builder)},
	{"nextLine", "Ljava/lang/String;", nullptr, $PRIVATE, $field(LineSubscriberAdapter$LineSubscription, nextLine$)},
	{}
};

$MethodInfo _LineSubscriberAdapter$LineSubscription_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/Flow$Subscription;Ljava/nio/charset/CharsetDecoder;Ljava/lang/String;Ljava/util/concurrent/Flow$Subscriber;Ljava/util/concurrent/CompletableFuture;)V", "(Ljava/util/concurrent/Flow$Subscription;Ljava/nio/charset/CharsetDecoder;Ljava/lang/String;Ljava/util/concurrent/Flow$Subscriber<-Ljava/lang/String;>;Ljava/util/concurrent/CompletableFuture<*>;)V", $PRIVATE, $method(static_cast<void(LineSubscriberAdapter$LineSubscription::*)($Flow$Subscription*,$CharsetDecoder*,$String*,$Flow$Subscriber*,$CompletableFuture*)>(&LineSubscriberAdapter$LineSubscription::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"create", "(Ljava/util/concurrent/Flow$Subscription;Ljava/nio/charset/Charset;Ljava/lang/String;Ljava/util/concurrent/Flow$Subscriber;Ljava/util/concurrent/CompletableFuture;)Ljdk/internal/net/http/LineSubscriberAdapter$LineSubscription;", "(Ljava/util/concurrent/Flow$Subscription;Ljava/nio/charset/Charset;Ljava/lang/String;Ljava/util/concurrent/Flow$Subscriber<-Ljava/lang/String;>;Ljava/util/concurrent/CompletableFuture<*>;)Ljdk/internal/net/http/LineSubscriberAdapter$LineSubscription;", $STATIC, $method(static_cast<LineSubscriberAdapter$LineSubscription*(*)($Flow$Subscription*,$Charset*,$String*,$Flow$Subscriber*,$CompletableFuture*)>(&LineSubscriberAdapter$LineSubscription::create))},
	{"endOfLine", "(Ljava/lang/StringBuilder;Ljava/lang/String;Z)I", nullptr, $PRIVATE | $STATIC, $method(static_cast<int32_t(*)($StringBuilder*,$String*,bool)>(&LineSubscriberAdapter$LineSubscription::endOfLine))},
	{"isUnderFlow", "(Ljava/nio/ByteBuffer;Ljava/nio/CharBuffer;Z)Z", nullptr, $PRIVATE, $method(static_cast<bool(LineSubscriberAdapter$LineSubscription::*)($ByteBuffer*,$CharBuffer*,bool)>(&LineSubscriberAdapter$LineSubscription::isUnderFlow)), "java.nio.charset.CharacterCodingException"},
	{"loop", "()V", nullptr, $PRIVATE, $method(static_cast<void(LineSubscriberAdapter$LineSubscription::*)()>(&LineSubscriberAdapter$LineSubscription::loop))},
	{"nextLine", "(Ljava/lang/StringBuilder;Ljava/lang/String;Z)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($StringBuilder*,$String*,bool)>(&LineSubscriberAdapter$LineSubscription::nextLine))},
	{"nextLine", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(LineSubscriberAdapter$LineSubscription::*)()>(&LineSubscriberAdapter$LineSubscription::nextLine)), "java.nio.charset.CharacterCodingException"},
	{"request", "(J)V", nullptr, $PUBLIC},
	{"signalComplete", "()V", nullptr, $PUBLIC, $method(static_cast<void(LineSubscriberAdapter$LineSubscription::*)()>(&LineSubscriberAdapter$LineSubscription::signalComplete))},
	{"signalError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(static_cast<void(LineSubscriberAdapter$LineSubscription::*)($Throwable*)>(&LineSubscriberAdapter$LineSubscription::signalError))},
	{"submit", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, $method(static_cast<void(LineSubscriberAdapter$LineSubscription::*)($List*)>(&LineSubscriberAdapter$LineSubscription::submit))},
	{"take", "(Ljava/lang/StringBuilder;II)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($StringBuilder*,int32_t,int32_t)>(&LineSubscriberAdapter$LineSubscription::take))},
	{}
};

$InnerClassInfo _LineSubscriberAdapter$LineSubscription_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.LineSubscriberAdapter$LineSubscription", "jdk.internal.net.http.LineSubscriberAdapter", "LineSubscription", $STATIC | $FINAL},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _LineSubscriberAdapter$LineSubscription_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.LineSubscriberAdapter$LineSubscription",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription",
	_LineSubscriberAdapter$LineSubscription_FieldInfo_,
	_LineSubscriberAdapter$LineSubscription_MethodInfo_,
	nullptr,
	nullptr,
	_LineSubscriberAdapter$LineSubscription_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.LineSubscriberAdapter"
};

$Object* allocate$LineSubscriberAdapter$LineSubscription($Class* clazz) {
	return $of($alloc(LineSubscriberAdapter$LineSubscription));
}

bool LineSubscriberAdapter$LineSubscription::$assertionsDisabled = false;

void LineSubscriberAdapter$LineSubscription::init$($Flow$Subscription* s, $CharsetDecoder* dec, $String* separator, $Flow$Subscriber* subscriber, $CompletableFuture* completion) {
	$useLocalCurrentObjectStackCache();
	$set(this, errorRef, $new($AtomicReference));
	$set(this, demanded, $new($AtomicLong));
	$set(this, chars, $new($chars, 1024));
	$set(this, leftover, $ByteBuffer::wrap($$new($bytes, 64)));
	$set(this, buffer, $CharBuffer::wrap(this->chars));
	$set(this, builder, $new($StringBuilder));
	$set(this, downstreamDemand, $new($Demand));
	$set(this, queue, $new($ConcurrentLinkedDeque));
	$set(this, upstreamSubscription, $cast($Flow$Subscription, $Objects::requireNonNull(s)));
	$set(this, decoder, $cast($CharsetDecoder, $Objects::requireNonNull(dec)));
	$set(this, newline, separator);
	$set(this, upstream, $cast($Flow$Subscriber, $Objects::requireNonNull(subscriber)));
	$set(this, cf, $cast($CompletableFuture, $Objects::requireNonNull(completion)));
	$set(this, scheduler, $SequentialScheduler::lockingScheduler(static_cast<$Runnable*>($$new(LineSubscriberAdapter$LineSubscription$$Lambda$loop, this))));
}

void LineSubscriberAdapter$LineSubscription::request(int64_t n) {
	if (this->cancelled) {
		return;
	}
	if ($nc(this->downstreamDemand)->increase(n)) {
		$nc(this->scheduler)->runOrSchedule();
	}
}

void LineSubscriberAdapter$LineSubscription::cancel() {
	this->cancelled = true;
	$nc(this->upstreamSubscription)->cancel();
}

void LineSubscriberAdapter$LineSubscription::submit($List* list) {
	$nc(this->queue)->addAll(list);
	$nc(this->demanded)->decrementAndGet();
	$nc(this->scheduler)->runOrSchedule();
}

void LineSubscriberAdapter$LineSubscription::signalComplete() {
	this->completed = true;
	$nc(this->scheduler)->runOrSchedule();
}

void LineSubscriberAdapter$LineSubscription::signalError($Throwable* error) {
	if ($nc(this->errorRef)->compareAndSet(nullptr, $cast($Throwable, $Objects::requireNonNull(error)))) {
		$nc(this->scheduler)->runOrSchedule();
	}
}

bool LineSubscriberAdapter$LineSubscription::isUnderFlow($ByteBuffer* in, $CharBuffer* out, bool endOfInput) {
	int32_t limit = $nc(this->leftover)->position();
	if (limit == 0) {
		return false;
	} else {
		$var($CoderResult, res, nullptr);
		while ($nc(in)->hasRemaining()) {
			$nc(this->leftover)->position(limit);
			$nc(this->leftover)->limit(++limit);
			$nc(this->leftover)->put(in->get());
			$nc(this->leftover)->position(0);
			$assign(res, $nc(this->decoder)->decode(this->leftover, out, endOfInput && !in->hasRemaining()));
			int32_t remaining = $nc(this->leftover)->remaining();
			if (remaining > 0) {
				if (!LineSubscriberAdapter$LineSubscription::$assertionsDisabled && !($nc(this->leftover)->position() == 0)) {
					$throwNew($AssertionError);
				}
				$nc(this->leftover)->position(remaining);
			} else {
				$nc(this->leftover)->position(0);
			}
			$nc(this->leftover)->limit($nc(this->leftover)->capacity());
			bool var$0 = $nc(res)->isUnderflow() && remaining > 0;
			if (var$0 && in->hasRemaining()) {
				continue;
			}
			if ($nc(res)->isError()) {
				res->throwException();
			}
			if (!LineSubscriberAdapter$LineSubscription::$assertionsDisabled && ! !$nc(res)->isOverflow()) {
				$throwNew($AssertionError);
			}
			return false;
		}
		return !endOfInput;
	}
}

$String* LineSubscriberAdapter$LineSubscription::take($StringBuilder* b, int32_t start, int32_t end) {
	$init(LineSubscriberAdapter$LineSubscription);
	if (!LineSubscriberAdapter$LineSubscription::$assertionsDisabled && !(start == 0)) {
		$throwNew($AssertionError);
	}
	$var($String, line, nullptr);
	if (end == start) {
		return ""_s;
	}
	$assign(line, $nc(b)->substring(start, end));
	b->delete$(start, end);
	return line;
}

int32_t LineSubscriberAdapter$LineSubscription::endOfLine($StringBuilder* b, $String* eol, bool endOfInput) {
	$init(LineSubscriberAdapter$LineSubscription);
	int32_t len = $nc(b)->length();
	if (eol != nullptr) {
		int32_t i = b->indexOf(eol);
		if (i >= 0) {
			b->delete$(i, i + eol->length());
			return i;
		}
	} else {
		bool crfound = false;
		for (int32_t i = 0; i < len; ++i) {
			char16_t c = b->charAt(i);
			if (c == u'\n') {
				b->delete$(crfound ? i - 1 : i, i + 1);
				return crfound ? i - 1 : i;
			} else if (crfound) {
				if (!LineSubscriberAdapter$LineSubscription::$assertionsDisabled && !(i != 0)) {
					$throwNew($AssertionError);
				}
				b->delete$(i - 1, i);
				return i - 1;
			}
			crfound = c == u'\r';
		}
		if (crfound && endOfInput) {
			b->delete$(len - 1, len);
			return len - 1;
		}
	}
	return endOfInput && len > 0 ? len : -1;
}

$String* LineSubscriberAdapter$LineSubscription::nextLine($StringBuilder* b, $String* eol, bool endOfInput) {
	$init(LineSubscriberAdapter$LineSubscription);
	int32_t next = endOfLine(b, eol, endOfInput);
	return (next > -1) ? take(b, 0, next) : ($String*)nullptr;
}

$String* LineSubscriberAdapter$LineSubscription::nextLine() {
	$useLocalCurrentObjectStackCache();
	if (!LineSubscriberAdapter$LineSubscription::$assertionsDisabled && !(this->nextLine$ == nullptr)) {
		$throwNew($AssertionError);
	}
	bool LINES$continue = false;
	while (this->nextLine$ == nullptr) {
		bool endOfInput = this->completed && $nc(this->queue)->isEmpty();
		$set(this, nextLine$, nextLine(this->builder, this->newline, endOfInput && $nc(this->leftover)->position() == 0));
		if (this->nextLine$ != nullptr) {
			return this->nextLine$;
		}
		$var($ByteBuffer, b, nullptr);
		bool BUFFERS$continue = false;
		while (($assign(b, $cast($ByteBuffer, $nc(this->queue)->peek()))) != nullptr) {
			if (!$nc(b)->hasRemaining()) {
				$nc(this->queue)->poll();
				continue;
			}
			while ($nc(b)->hasRemaining()) {
				$nc(this->buffer)->position(0);
				$nc(this->buffer)->limit($nc(this->buffer)->capacity());
				bool endofInput = this->completed && $nc(this->queue)->size() <= 1;
				if (isUnderFlow(b, this->buffer, endofInput)) {
					if (!LineSubscriberAdapter$LineSubscription::$assertionsDisabled && ! !b->hasRemaining()) {
						$throwNew($AssertionError);
					}
					if ($nc(this->buffer)->position() > 0) {
						$nc(this->buffer)->flip();
						$nc(this->builder)->append(static_cast<$CharSequence*>(this->buffer));
					}
					BUFFERS$continue = true;
					break;
				}
				$var($CoderResult, res, $nc(this->decoder)->decode(b, this->buffer, endofInput));
				if ($nc(res)->isError()) {
					res->throwException();
				}
				if ($nc(this->buffer)->position() > 0) {
					$nc(this->buffer)->flip();
					$nc(this->builder)->append(static_cast<$CharSequence*>(this->buffer));
					LINES$continue = true;
					break;
				}
				bool var$0 = $nc(res)->isUnderflow();
				if (var$0 && b->hasRemaining()) {
					$nc(this->leftover)->put(b);
					if (!LineSubscriberAdapter$LineSubscription::$assertionsDisabled && ! !b->hasRemaining()) {
						$throwNew($AssertionError);
					}
					BUFFERS$continue = true;
					break;
				}
			}
			if (LINES$continue) {
				break;
			}
			if (BUFFERS$continue) {
				BUFFERS$continue = false;
				continue;
			}
		}
		if (LINES$continue) {
			LINES$continue = false;
			continue;
		}
		if (!LineSubscriberAdapter$LineSubscription::$assertionsDisabled && !$nc(this->queue)->isEmpty()) {
			$throwNew($AssertionError);
		}
		if (endOfInput) {
			$nc(this->leftover)->flip();
			$nc(this->buffer)->position(0);
			$nc(this->buffer)->limit($nc(this->buffer)->capacity());
			$var($CoderResult, res, $nc(this->decoder)->decode(this->leftover, this->buffer, endOfInput));
			if ($nc(this->buffer)->position() > 0) {
				$nc(this->buffer)->flip();
				$nc(this->builder)->append(static_cast<$CharSequence*>(this->buffer));
			}
			if ($nc(res)->isError()) {
				res->throwException();
			}
			$nc(this->buffer)->position(0);
			$nc(this->buffer)->limit($nc(this->buffer)->capacity());
			$assign(res, $nc(this->decoder)->flush(this->buffer));
			if ($nc(this->buffer)->position() > 0) {
				$nc(this->buffer)->flip();
				$nc(this->builder)->append(static_cast<$CharSequence*>(this->buffer));
			}
			if ($nc(res)->isError()) {
				res->throwException();
			}
			$nc(this->leftover)->position(0);
			$nc(this->leftover)->limit($nc(this->leftover)->capacity());
			$nc(this->decoder)->reset();
			return $set(this, nextLine$, nextLine(this->builder, this->newline, endOfInput));
		}
		return nullptr;
	}
	return nullptr;
}

void LineSubscriberAdapter$LineSubscription::loop() {
	$useLocalCurrentObjectStackCache();
	try {
		while (!this->cancelled) {
			$var($Throwable, error, $cast($Throwable, $nc(this->errorRef)->get()));
			if (error != nullptr) {
				this->cancelled = true;
				$nc(this->scheduler)->stop();
				$nc(this->upstream)->onError(error);
				$nc(this->cf)->completeExceptionally(error);
				return;
			}
			if (this->nextLine$ == nullptr) {
				$set(this, nextLine$, nextLine());
			}
			if (this->nextLine$ == nullptr) {
				if (this->completed) {
					$nc(this->scheduler)->stop();
					if ($nc(this->leftover)->position() != 0) {
						$nc(this->errorRef)->compareAndSet(nullptr, $$new($IllegalStateException, $$str({"premature end of input ("_s, $$str($nc(this->leftover)->position()), " undecoded bytes)"_s})));
						continue;
					} else {
						$nc(this->upstream)->onComplete();
					}
					return;
				} else {
					bool var$1 = $nc(this->demanded)->get() == 0;
					if (var$1 && !$nc(this->downstreamDemand)->isFulfilled()) {
						int64_t incr = $Math::max((int64_t)1, $nc(this->downstreamDemand)->get());
						$nc(this->demanded)->addAndGet(incr);
						$nc(this->upstreamSubscription)->request(incr);
						continue;
					} else {
						return;
					}
				}
			}
			if (!LineSubscriberAdapter$LineSubscription::$assertionsDisabled && !(this->nextLine$ != nullptr)) {
				$throwNew($AssertionError);
			}
			bool var$2 = !LineSubscriberAdapter$LineSubscription::$assertionsDisabled;
			if (var$2) {
				bool var$4 = this->newline != nullptr && !$nc(this->nextLine$)->endsWith(this->newline);
				bool var$3 = var$4 || !$nc(this->nextLine$)->endsWith("\n"_s);
				var$2 = !(var$3 || !$nc(this->nextLine$)->endsWith("\r"_s));
			}
			if (var$2) {
				$throwNew($AssertionError);
			}
			if ($nc(this->downstreamDemand)->tryDecrement()) {
				$var($String, forward, this->nextLine$);
				$set(this, nextLine$, nullptr);
				$nc(this->upstream)->onNext(forward);
			} else {
				return;
			}
		}
	} catch ($Throwable& t) {
		{
			$var($Throwable, var$5, nullptr);
			try {
				$nc(this->upstreamSubscription)->cancel();
			} catch ($Throwable& var$6) {
				$assign(var$5, var$6);
			} /*finally*/ {
				signalError(t);
			}
			if (var$5 != nullptr) {
				$throw(var$5);
			}
		}
	}
}

LineSubscriberAdapter$LineSubscription* LineSubscriberAdapter$LineSubscription::create($Flow$Subscription* s, $Charset* charset, $String* lineSeparator, $Flow$Subscriber* upstream, $CompletableFuture* cf) {
	$init(LineSubscriberAdapter$LineSubscription);
	$useLocalCurrentObjectStackCache();
	$var($Flow$Subscription, var$0, $cast($Flow$Subscription, $Objects::requireNonNull(s)));
	$init($CodingErrorAction);
	$var($CharsetDecoder, var$1, $nc($($nc($($nc(($cast($Charset, $Objects::requireNonNull(charset))))->newDecoder()))->onMalformedInput($CodingErrorAction::REPLACE)))->onUnmappableCharacter($CodingErrorAction::REPLACE));
	$var($String, var$2, lineSeparator);
	$var($Flow$Subscriber, var$3, $cast($Flow$Subscriber, $Objects::requireNonNull(upstream)));
	return $new(LineSubscriberAdapter$LineSubscription, var$0, var$1, var$2, var$3, $cast($CompletableFuture, $Objects::requireNonNull(cf)));
}

void clinit$LineSubscriberAdapter$LineSubscription($Class* class$) {
	$load($LineSubscriberAdapter);
	LineSubscriberAdapter$LineSubscription::$assertionsDisabled = !$LineSubscriberAdapter::class$->desiredAssertionStatus();
}

LineSubscriberAdapter$LineSubscription::LineSubscriberAdapter$LineSubscription() {
}

$Class* LineSubscriberAdapter$LineSubscription::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LineSubscriberAdapter$LineSubscription$$Lambda$loop::classInfo$.name)) {
			return LineSubscriberAdapter$LineSubscription$$Lambda$loop::load$(name, initialize);
		}
	}
	$loadClass(LineSubscriberAdapter$LineSubscription, name, initialize, &_LineSubscriberAdapter$LineSubscription_ClassInfo_, clinit$LineSubscriberAdapter$LineSubscription, allocate$LineSubscriberAdapter$LineSubscription);
	return class$;
}

$Class* LineSubscriberAdapter$LineSubscription::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk