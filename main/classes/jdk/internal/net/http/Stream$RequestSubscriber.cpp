#include <jdk/internal/net/http/Stream$RequestSubscriber.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/ConcurrentLinkedDeque.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/Http2Connection.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/Stream.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/frame/DataFrame.h>
#include <jdk/internal/net/http/frame/ResetFrame.h>
#include <jcpp.h>

#undef COMPLETED
#undef END_STREAM
#undef PROTOCOL_ERROR

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Runnable = ::java::lang::Runnable;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $ConcurrentLinkedDeque = ::java::util::concurrent::ConcurrentLinkedDeque;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $Supplier = ::java::util::function::Supplier;
using $Http2Connection = ::jdk::internal::net::http::Http2Connection;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $Stream = ::jdk::internal::net::http::Stream;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $DataFrame = ::jdk::internal::net::http::frame::DataFrame;
using $ErrorFrame = ::jdk::internal::net::http::frame::ErrorFrame;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;
using $ResetFrame = ::jdk::internal::net::http::frame::ResetFrame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Stream$RequestSubscriber$$Lambda$trySend : public $Runnable {
	$class(Stream$RequestSubscriber$$Lambda$trySend, $NO_CLASS_INIT, $Runnable)
public:
	void init$(Stream$RequestSubscriber* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->trySend();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$RequestSubscriber$$Lambda$trySend>());
	}
	Stream$RequestSubscriber* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$RequestSubscriber$$Lambda$trySend::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Stream$RequestSubscriber$$Lambda$trySend, inst$)},
	{}
};
$MethodInfo Stream$RequestSubscriber$$Lambda$trySend::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Stream$RequestSubscriber;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$RequestSubscriber$$Lambda$trySend::*)(Stream$RequestSubscriber*)>(&Stream$RequestSubscriber$$Lambda$trySend::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$RequestSubscriber$$Lambda$trySend::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$RequestSubscriber$$Lambda$trySend",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* Stream$RequestSubscriber$$Lambda$trySend::load$($String* name, bool initialize) {
	$loadClass(Stream$RequestSubscriber$$Lambda$trySend, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$RequestSubscriber$$Lambda$trySend::class$ = nullptr;

class Stream$RequestSubscriber$$Lambda$lambda$onError$0$1 : public $Supplier {
	$class(Stream$RequestSubscriber$$Lambda$lambda$onError$0$1, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Throwable* throwable) {
		$set(this, throwable, throwable);
	}
	virtual $Object* get() override {
		 return $of(Stream$RequestSubscriber::lambda$onError$0(throwable));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$RequestSubscriber$$Lambda$lambda$onError$0$1>());
	}
	$Throwable* throwable = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$RequestSubscriber$$Lambda$lambda$onError$0$1::fieldInfos[2] = {
	{"throwable", "Ljava/lang/Throwable;", nullptr, $PUBLIC, $field(Stream$RequestSubscriber$$Lambda$lambda$onError$0$1, throwable)},
	{}
};
$MethodInfo Stream$RequestSubscriber$$Lambda$lambda$onError$0$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$RequestSubscriber$$Lambda$lambda$onError$0$1::*)($Throwable*)>(&Stream$RequestSubscriber$$Lambda$lambda$onError$0$1::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$RequestSubscriber$$Lambda$lambda$onError$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$RequestSubscriber$$Lambda$lambda$onError$0$1",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Stream$RequestSubscriber$$Lambda$lambda$onError$0$1::load$($String* name, bool initialize) {
	$loadClass(Stream$RequestSubscriber$$Lambda$lambda$onError$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$RequestSubscriber$$Lambda$lambda$onError$0$1::class$ = nullptr;

$FieldInfo _Stream$RequestSubscriber_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/Stream;", nullptr, $FINAL | $SYNTHETIC, $field(Stream$RequestSubscriber, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Stream$RequestSubscriber, $assertionsDisabled)},
	{"contentLength", "J", nullptr, $PRIVATE | $FINAL, $field(Stream$RequestSubscriber, contentLength)},
	{"remainingContentLength", "J", nullptr, $PRIVATE | $VOLATILE, $field(Stream$RequestSubscriber, remainingContentLength)},
	{"subscription", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $PRIVATE | $VOLATILE, $field(Stream$RequestSubscriber, subscription)},
	{"outgoing", "Ljava/util/concurrent/ConcurrentLinkedDeque;", "Ljava/util/concurrent/ConcurrentLinkedDeque<Ljava/nio/ByteBuffer;>;", $FINAL, $field(Stream$RequestSubscriber, outgoing)},
	{"errorRef", "Ljava/util/concurrent/atomic/AtomicReference;", "Ljava/util/concurrent/atomic/AtomicReference<Ljava/lang/Throwable;>;", $PRIVATE | $FINAL, $field(Stream$RequestSubscriber, errorRef)},
	{"sendScheduler", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $FINAL, $field(Stream$RequestSubscriber, sendScheduler)},
	{}
};

$MethodInfo _Stream$RequestSubscriber_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Stream;J)V", nullptr, 0, $method(static_cast<void(Stream$RequestSubscriber::*)($Stream*,int64_t)>(&Stream$RequestSubscriber::init$))},
	{"complete", "()V", nullptr, $PRIVATE, $method(static_cast<void(Stream$RequestSubscriber::*)()>(&Stream$RequestSubscriber::complete)), "java.io.IOException"},
	{"lambda$onError$0", "(Ljava/lang/Throwable;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($Throwable*)>(&Stream$RequestSubscriber::lambda$onError$0))},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onNextImpl", "(Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(static_cast<void(Stream$RequestSubscriber::*)($ByteBuffer*)>(&Stream$RequestSubscriber::onNextImpl))},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{"trySend", "()V", nullptr, 0},
	{}
};

$InnerClassInfo _Stream$RequestSubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Stream$RequestSubscriber", "jdk.internal.net.http.Stream", "RequestSubscriber", 0},
	{"java.util.concurrent.Flow$Subscriber", "java.util.concurrent.Flow", "Subscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Stream$RequestSubscriber_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.Stream$RequestSubscriber",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscriber",
	_Stream$RequestSubscriber_FieldInfo_,
	_Stream$RequestSubscriber_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/concurrent/Flow$Subscriber<Ljava/nio/ByteBuffer;>;",
	nullptr,
	_Stream$RequestSubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Stream"
};

$Object* allocate$Stream$RequestSubscriber($Class* clazz) {
	return $of($alloc(Stream$RequestSubscriber));
}

bool Stream$RequestSubscriber::$assertionsDisabled = false;

void Stream$RequestSubscriber::init$($Stream* this$0, int64_t contentLen) {
	$set(this, this$0, this$0);
	$set(this, outgoing, $new($ConcurrentLinkedDeque));
	$set(this, errorRef, $new($AtomicReference));
	this->contentLength = contentLen;
	this->remainingContentLength = contentLen;
	$set(this, sendScheduler, $SequentialScheduler::lockingScheduler(static_cast<$Runnable*>($$new(Stream$RequestSubscriber$$Lambda$trySend, this))));
}

void Stream$RequestSubscriber::onSubscribe($Flow$Subscription* subscription) {
	if (this->subscription != nullptr) {
		$throwNew($IllegalStateException, "already subscribed"_s);
	}
	$set(this, subscription, subscription);
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("RequestSubscriber: onSubscribe, request 1"_s);
	}
	$nc(subscription)->request(1);
}

void Stream$RequestSubscriber::onNext($ByteBuffer* item) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("RequestSubscriber: onNext(%d)"_s, $$new($ObjectArray, {$($of($Integer::valueOf($nc(item)->remaining())))}));
	}
	int32_t size = $nc(this->outgoing)->size();
	if (!Stream$RequestSubscriber::$assertionsDisabled && !(size == 0)) {
		$throwNew($AssertionError, $of($$str({"non-zero size: "_s, $$str(size)})));
	}
	onNextImpl(item);
}

void Stream$RequestSubscriber::onNextImpl($ByteBuffer* item) {
	if ($nc(this->this$0->requestBodyCF)->isDone()) {
		$nc(this->sendScheduler)->stop();
		$nc(this->subscription)->cancel();
		return;
	}
	$nc(this->outgoing)->add(item);
	$nc(this->sendScheduler)->runOrSchedule();
}

void Stream$RequestSubscriber::onError($Throwable* throwable) {
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log(static_cast<$Supplier*>($$new(Stream$RequestSubscriber$$Lambda$lambda$onError$0$1, throwable)));
	}
	if ($nc(this->errorRef)->compareAndSet(nullptr, throwable)) {
		$nc(this->sendScheduler)->runOrSchedule();
	}
}

void Stream$RequestSubscriber::onComplete() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("RequestSubscriber: onComplete"_s);
	}
	int32_t size = $nc(this->outgoing)->size();
	if (!Stream$RequestSubscriber::$assertionsDisabled && !(size == 0 || size == 1)) {
		$throwNew($AssertionError, $of($$str({"non-zero or one size: "_s, $$str(size)})));
	}
	$init($Stream);
	onNextImpl($Stream::COMPLETED);
}

void Stream$RequestSubscriber::trySend() {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Throwable, t, $cast($Throwable, $nc(this->errorRef)->get()));
		if (t != nullptr) {
			$nc(this->sendScheduler)->stop();
			if ($nc(this->this$0->requestBodyCF)->isDone()) {
				return;
			}
			$nc(this->subscription)->cancel();
			$nc(this->this$0->requestBodyCF)->completeExceptionally(t);
			this->this$0->cancelImpl(t);
			return;
		}
		int32_t state = this->this$0->streamState;
		do {
			$var($ByteBuffer, item, $cast($ByteBuffer, $nc(this->outgoing)->peekFirst()));
			if (item == nullptr) {
				return;
			} else {
				$init($Stream);
				if (item == $Stream::COMPLETED) {
					$nc(this->sendScheduler)->stop();
					complete();
					return;
				}
			}
			while ($nc(item)->hasRemaining() && state == 0) {
				if ($nc(this->this$0->debug)->on()) {
					$nc(this->this$0->debug)->log("trySend: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(item->remaining())))}));
				}
				$var($DataFrame, df, this->this$0->getDataFrame(item));
				if (df == nullptr) {
					if ($nc(this->this$0->debug)->on()) {
						$nc(this->this$0->debug)->log("trySend: can\'t send yet: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(item->remaining())))}));
					}
					return;
				}
				if (this->contentLength > 0) {
					this->remainingContentLength -= $nc(df)->getDataLength();
					if (this->remainingContentLength < 0) {
						$var($String, var$4, $$str({$($nc($(this->this$0->connection()))->getConnectionFlow()), " stream="_s, $$str(this->this$0->streamid), " ["_s}));
						$var($String, var$3, $$concat(var$4, $($($Thread::currentThread())->getName())));
						$var($String, var$2, $$concat(var$3, "] Too many bytes in request body. Expected: "));
						$var($String, var$1, $$concat(var$2, $$str(this->contentLength)));
						$var($String, var$0, $$concat(var$1, ", got: "));
						$var($String, msg, $concat(var$0, $$str((this->contentLength - this->remainingContentLength))));
						if (!Stream$RequestSubscriber::$assertionsDisabled && !(this->this$0->streamid > 0)) {
							$throwNew($AssertionError);
						}
						$nc(this->this$0->connection$)->resetStream(this->this$0->streamid, $ResetFrame::PROTOCOL_ERROR);
						$throwNew($IOException, msg);
					} else if (this->remainingContentLength == 0) {
						if (!Stream$RequestSubscriber::$assertionsDisabled && ! !this->this$0->endStreamSent) {
							$throwNew($AssertionError, $of("internal error, send data after END_STREAM flag"_s));
						}
						df->setFlag($DataFrame::END_STREAM);
						this->this$0->endStreamSent = true;
					}
				} else if (!Stream$RequestSubscriber::$assertionsDisabled && ! !this->this$0->endStreamSent) {
					$throwNew($AssertionError, $of("internal error, send data after END_STREAM flag"_s));
				}
				if ((state = this->this$0->streamState) != 0) {
					if ($nc(this->this$0->debug)->on()) {
						$nc(this->this$0->debug)->log("trySend: cancelled: %s"_s, $$new($ObjectArray, {$($of($String::valueOf($of(t))))}));
					}
					break;
				}
				if ($nc(this->this$0->debug)->on()) {
					$nc(this->this$0->debug)->log("trySend: sending: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf($nc(df)->getDataLength())))}));
				}
				this->this$0->sendDataFrame(df);
			}
			if (state != 0) {
				break;
			}
			if (!Stream$RequestSubscriber::$assertionsDisabled && ! !$nc(item)->hasRemaining()) {
				$throwNew($AssertionError);
			}
			$var($ByteBuffer, b, $cast($ByteBuffer, $nc(this->outgoing)->removeFirst()));
			if (!Stream$RequestSubscriber::$assertionsDisabled && !(b == item)) {
				$throwNew($AssertionError);
			}
		} while ($nc(this->outgoing)->peekFirst() != nullptr);
		if (state != 0) {
			$assign(t, $cast($Throwable, $nc(this->errorRef)->get()));
			if (t == nullptr) {
				$assign(t, $new($IOException, $($ResetFrame::stringForCode(this->this$0->streamState))));
			}
			$throw(t);
		}
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("trySend: request 1"_s);
		}
		$nc(this->subscription)->request(1);
	} catch ($Throwable& ex) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("trySend: "_s, ex);
		}
		$nc(this->sendScheduler)->stop();
		$nc(this->subscription)->cancel();
		$nc(this->this$0->requestBodyCF)->completeExceptionally(ex);
		this->this$0->cancelImpl(ex);
	}
}

void Stream$RequestSubscriber::complete() {
	$useLocalCurrentObjectStackCache();
	int64_t remaining = this->remainingContentLength;
	int64_t written = this->contentLength - remaining;
	if (remaining > 0) {
		$nc(this->this$0->connection$)->resetStream(this->this$0->streamid, $ResetFrame::PROTOCOL_ERROR);
		$var($String, var$5, $$str({$($nc($(this->this$0->connection()))->getConnectionFlow()), " stream="_s, $$str(this->this$0->streamid), " ["_s}));
		$var($String, var$4, $$concat(var$5, $($($Thread::currentThread())->getName())));
		$var($String, var$3, $$concat(var$4, "] Too few bytes returned by the publisher ("));
		$var($String, var$2, $$concat(var$3, $$str(written)));
		$var($String, var$1, $$concat(var$2, "/"));
		$var($String, var$0, $$concat(var$1, $$str(this->contentLength)));
		$throwNew($IOException, $$concat(var$0, ")"));
	}
	if (!this->this$0->endStreamSent) {
		this->this$0->endStreamSent = true;
		$nc(this->this$0->connection$)->sendDataFrame($(this->this$0->getEmptyEndStreamDataFrame()));
	}
	$nc(this->this$0->requestBodyCF)->complete(nullptr);
}

void Stream$RequestSubscriber::onNext(Object$* item) {
	this->onNext($cast($ByteBuffer, item));
}

$String* Stream$RequestSubscriber::lambda$onError$0($Throwable* throwable) {
	$init(Stream$RequestSubscriber);
	return $str({"RequestSubscriber: onError: "_s, throwable});
}

void clinit$Stream$RequestSubscriber($Class* class$) {
	$load($Stream);
	Stream$RequestSubscriber::$assertionsDisabled = !$Stream::class$->desiredAssertionStatus();
}

Stream$RequestSubscriber::Stream$RequestSubscriber() {
}

$Class* Stream$RequestSubscriber::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Stream$RequestSubscriber$$Lambda$trySend::classInfo$.name)) {
			return Stream$RequestSubscriber$$Lambda$trySend::load$(name, initialize);
		}
		if (name->equals(Stream$RequestSubscriber$$Lambda$lambda$onError$0$1::classInfo$.name)) {
			return Stream$RequestSubscriber$$Lambda$lambda$onError$0$1::load$(name, initialize);
		}
	}
	$loadClass(Stream$RequestSubscriber, name, initialize, &_Stream$RequestSubscriber_ClassInfo_, clinit$Stream$RequestSubscriber, allocate$Stream$RequestSubscriber);
	return class$;
}

$Class* Stream$RequestSubscriber::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk