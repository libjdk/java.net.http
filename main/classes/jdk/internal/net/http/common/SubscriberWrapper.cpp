#include <jdk/internal/net/http/common/SubscriberWrapper.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/ConcurrentLinkedQueue.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/SubscriberWrapper$DownstreamPusher.h>
#include <jdk/internal/net/http/common/SubscriberWrapper$SchedulingAction.h>
#include <jdk/internal/net/http/common/SubscriptionBase.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef CONTINUE
#undef DEBUG
#undef EMPTY_BB_LIST

using $Closeable = ::java::io::Closeable;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $ConcurrentLinkedQueue = ::java::util::concurrent::ConcurrentLinkedQueue;
using $Flow$Processor = ::java::util::concurrent::Flow$Processor;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Supplier = ::java::util::function::Supplier;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SubscriberWrapper$DownstreamPusher = ::jdk::internal::net::http::common::SubscriberWrapper$DownstreamPusher;
using $SubscriberWrapper$SchedulingAction = ::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction;
using $SubscriptionBase = ::jdk::internal::net::http::common::SubscriptionBase;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class SubscriberWrapper$$Lambda$dbgString : public $Supplier {
	$class(SubscriberWrapper$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(SubscriberWrapper* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SubscriberWrapper$$Lambda$dbgString>());
	}
	SubscriberWrapper* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SubscriberWrapper$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SubscriberWrapper$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo SubscriberWrapper$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/common/SubscriberWrapper;)V", nullptr, $PUBLIC, $method(static_cast<void(SubscriberWrapper$$Lambda$dbgString::*)(SubscriberWrapper*)>(&SubscriberWrapper$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SubscriberWrapper$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.SubscriberWrapper$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* SubscriberWrapper$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(SubscriberWrapper$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SubscriberWrapper$$Lambda$dbgString::class$ = nullptr;

class SubscriberWrapper$$Lambda$lambda$new$0$1 : public $BiConsumer {
	$class(SubscriberWrapper$$Lambda$lambda$new$0$1, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(SubscriberWrapper* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* v, Object$* t) override {
		$nc(inst$)->lambda$new$0($cast($Void, v), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SubscriberWrapper$$Lambda$lambda$new$0$1>());
	}
	SubscriberWrapper* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SubscriberWrapper$$Lambda$lambda$new$0$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SubscriberWrapper$$Lambda$lambda$new$0$1, inst$)},
	{}
};
$MethodInfo SubscriberWrapper$$Lambda$lambda$new$0$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/common/SubscriberWrapper;)V", nullptr, $PUBLIC, $method(static_cast<void(SubscriberWrapper$$Lambda$lambda$new$0$1::*)(SubscriberWrapper*)>(&SubscriberWrapper$$Lambda$lambda$new$0$1::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo SubscriberWrapper$$Lambda$lambda$new$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.SubscriberWrapper$$Lambda$lambda$new$0$1",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* SubscriberWrapper$$Lambda$lambda$new$0$1::load$($String* name, bool initialize) {
	$loadClass(SubscriberWrapper$$Lambda$lambda$new$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SubscriberWrapper$$Lambda$lambda$new$0$1::class$ = nullptr;

class SubscriberWrapper$$Lambda$downstreamCompletion$2 : public $Runnable {
	$class(SubscriberWrapper$$Lambda$downstreamCompletion$2, $NO_CLASS_INIT, $Runnable)
public:
	void init$(SubscriberWrapper* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->downstreamCompletion();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SubscriberWrapper$$Lambda$downstreamCompletion$2>());
	}
	SubscriberWrapper* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SubscriberWrapper$$Lambda$downstreamCompletion$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SubscriberWrapper$$Lambda$downstreamCompletion$2, inst$)},
	{}
};
$MethodInfo SubscriberWrapper$$Lambda$downstreamCompletion$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/common/SubscriberWrapper;)V", nullptr, $PUBLIC, $method(static_cast<void(SubscriberWrapper$$Lambda$downstreamCompletion$2::*)(SubscriberWrapper*)>(&SubscriberWrapper$$Lambda$downstreamCompletion$2::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo SubscriberWrapper$$Lambda$downstreamCompletion$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.SubscriberWrapper$$Lambda$downstreamCompletion$2",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* SubscriberWrapper$$Lambda$downstreamCompletion$2::load$($String* name, bool initialize) {
	$loadClass(SubscriberWrapper$$Lambda$downstreamCompletion$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SubscriberWrapper$$Lambda$downstreamCompletion$2::class$ = nullptr;

$FieldInfo _SubscriberWrapper_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SubscriberWrapper, $assertionsDisabled)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(SubscriberWrapper, debug)},
	{"upstreamSubscription", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $VOLATILE, $field(SubscriberWrapper, upstreamSubscription)},
	{"downstreamSubscription", "Ljdk/internal/net/http/common/SubscriptionBase;", nullptr, $FINAL, $field(SubscriberWrapper, downstreamSubscription)},
	{"upstreamCompleted", "Z", nullptr, $VOLATILE, $field(SubscriberWrapper, upstreamCompleted)},
	{"downstreamCompleted", "Z", nullptr, $VOLATILE, $field(SubscriberWrapper, downstreamCompleted)},
	{"completionAcknowledged", "Z", nullptr, $VOLATILE, $field(SubscriberWrapper, completionAcknowledged)},
	{"downstreamSubscriber", "Ljava/util/concurrent/Flow$Subscriber;", "Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;", $PRIVATE | $VOLATILE, $field(SubscriberWrapper, downstreamSubscriber)},
	{"outputQ", "Ljava/util/concurrent/ConcurrentLinkedQueue;", "Ljava/util/concurrent/ConcurrentLinkedQueue<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;", $PRIVATE | $FINAL, $field(SubscriberWrapper, outputQ)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PRIVATE | $FINAL, $field(SubscriberWrapper, cf)},
	{"pushScheduler", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $PRIVATE | $FINAL, $field(SubscriberWrapper, pushScheduler)},
	{"errorRef", "Ljava/util/concurrent/atomic/AtomicReference;", "Ljava/util/concurrent/atomic/AtomicReference<Ljava/lang/Throwable;>;", $PRIVATE | $FINAL, $field(SubscriberWrapper, errorRef)},
	{"upstreamWindow", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $FINAL, $field(SubscriberWrapper, upstreamWindow$)},
	{}
};

$MethodInfo _SubscriberWrapper_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SubscriberWrapper::*)()>(&SubscriberWrapper::init$))},
	{"<init>", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", $PUBLIC, $method(static_cast<void(SubscriberWrapper::*)($Flow$Subscriber*)>(&SubscriberWrapper::init$))},
	{"addData", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC},
	{"checkCompletion", "()V", nullptr, 0},
	{"close", "()V", nullptr, $PUBLIC},
	{"close", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"closing", "()Z", nullptr, $PUBLIC},
	{"completion", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC},
	{"dbgString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"downstreamCompletion", "()V", nullptr, 0},
	{"enterScheduling", "()Ljdk/internal/net/http/common/SubscriberWrapper$SchedulingAction;", nullptr, $PROTECTED},
	{"errorCommon", "(Ljava/lang/Throwable;)Z", nullptr, $PROTECTED},
	{"hasNoOutputData", "()Z", nullptr, $FINAL, $method(static_cast<bool(SubscriberWrapper::*)()>(&SubscriberWrapper::hasNoOutputData))},
	{"incoming", "(Ljava/util/List;Z)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;Z)V", $PROTECTED | $ABSTRACT},
	{"incomingCaller", "(Ljava/util/List;Z)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;Z)V", $PRIVATE, $method(static_cast<void(SubscriberWrapper::*)($List*,bool)>(&SubscriberWrapper::incomingCaller))},
	{"initialUpstreamDemand", "()J", nullptr, $PROTECTED},
	{"lambda$new$0", "(Ljava/lang/Void;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(SubscriberWrapper::*)($Void*,$Throwable*)>(&SubscriberWrapper::lambda$new$0))},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "()V", nullptr, $PROTECTED},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{"outgoing", "(Ljava/nio/ByteBuffer;Z)V", nullptr, $PUBLIC},
	{"outgoing", "(Ljava/util/List;Z)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;Z)V", $PUBLIC},
	{"outputQueueSize", "()I", nullptr, $FINAL, $method(static_cast<int32_t(SubscriberWrapper::*)()>(&SubscriberWrapper::outputQueueSize))},
	{"requestMore", "()V", nullptr, $PROTECTED},
	{"resetDownstreamDemand", "()V", nullptr, $PUBLIC},
	{"signalScheduling", "()Z", nullptr, $PROTECTED},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", $PUBLIC | $FINAL},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"upstreamRequest", "(J)V", nullptr, $PRIVATE, $method(static_cast<void(SubscriberWrapper::*)(int64_t)>(&SubscriberWrapper::upstreamRequest))},
	{"upstreamWindow", "()J", nullptr, $PUBLIC},
	{"upstreamWindowUpdate", "(JJ)J", nullptr, $PROTECTED},
	{"upstreamWindowUpdate", "()V", nullptr, 0},
	{}
};

$InnerClassInfo _SubscriberWrapper_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.FlowTube$TubeSubscriber", "jdk.internal.net.http.common.FlowTube", "TubeSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.Flow$Processor", "java.util.concurrent.Flow", "Processor", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.common.SubscriberWrapper$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"jdk.internal.net.http.common.SubscriberWrapper$DownstreamPusher", "jdk.internal.net.http.common.SubscriberWrapper", "DownstreamPusher", 0},
	{"jdk.internal.net.http.common.SubscriberWrapper$SchedulingAction", "jdk.internal.net.http.common.SubscriberWrapper", "SchedulingAction", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _SubscriberWrapper_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.common.SubscriberWrapper",
	"java.lang.Object",
	"jdk.internal.net.http.common.FlowTube$TubeSubscriber,java.io.Closeable,java.util.concurrent.Flow$Processor",
	_SubscriberWrapper_FieldInfo_,
	_SubscriberWrapper_MethodInfo_,
	"Ljava/lang/Object;Ljdk/internal/net/http/common/FlowTube$TubeSubscriber;Ljava/io/Closeable;Ljava/util/concurrent/Flow$Processor<Ljava/util/List<Ljava/nio/ByteBuffer;>;Ljava/util/List<Ljava/nio/ByteBuffer;>;>;",
	nullptr,
	_SubscriberWrapper_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SubscriberWrapper$1,jdk.internal.net.http.common.SubscriberWrapper$DownstreamPusher,jdk.internal.net.http.common.SubscriberWrapper$SchedulingAction"
};

$Object* allocate$SubscriberWrapper($Class* clazz) {
	return $of($alloc(SubscriberWrapper));
}

int32_t SubscriberWrapper::hashCode() {
	 return this->$FlowTube$TubeSubscriber::hashCode();
}

bool SubscriberWrapper::equals(Object$* arg0) {
	 return this->$FlowTube$TubeSubscriber::equals(arg0);
}

$Object* SubscriberWrapper::clone() {
	 return this->$FlowTube$TubeSubscriber::clone();
}

void SubscriberWrapper::finalize() {
	this->$FlowTube$TubeSubscriber::finalize();
}

bool SubscriberWrapper::$assertionsDisabled = false;

void SubscriberWrapper::init$() {
	$useLocalCurrentObjectStackCache();
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(SubscriberWrapper$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, errorRef, $new($AtomicReference));
	$set(this, upstreamWindow$, $new($AtomicLong));
	$set(this, outputQ, $new($ConcurrentLinkedQueue));
	$set(this, cf, $new($MinimalFuture));
	$nc(this->cf)->whenComplete(static_cast<$BiConsumer*>($$new(SubscriberWrapper$$Lambda$lambda$new$0$1, this)));
	$set(this, pushScheduler, $SequentialScheduler::lockingScheduler($$new($SubscriberWrapper$DownstreamPusher, this)));
	$set(this, downstreamSubscription, $new($SubscriptionBase, this->pushScheduler, static_cast<$Runnable*>($$new(SubscriberWrapper$$Lambda$downstreamCompletion$2, this))));
}

void SubscriberWrapper::subscribe($Flow$Subscriber* downstreamSubscriber) {
	$Objects::requireNonNull(downstreamSubscriber);
	$set(this, downstreamSubscriber, downstreamSubscriber);
}

void SubscriberWrapper::init$($Flow$Subscriber* downstreamWrapper) {
	SubscriberWrapper::init$();
	subscribe(downstreamWrapper);
}

int64_t SubscriberWrapper::upstreamWindowUpdate(int64_t currentWindow, int64_t downstreamQsize) {
	if (downstreamQsize > 5) {
		return 0;
	}
	if (currentWindow == 0) {
		return 1;
	} else {
		return 0;
	}
}

void SubscriberWrapper::onSubscribe() {
}

$SubscriberWrapper$SchedulingAction* SubscriberWrapper::enterScheduling() {
	$init($SubscriberWrapper$SchedulingAction);
	return $SubscriberWrapper$SchedulingAction::CONTINUE;
}

bool SubscriberWrapper::signalScheduling() {
	if (this->downstreamCompleted || $nc(this->pushScheduler)->isStopped()) {
		return false;
	}
	$nc(this->pushScheduler)->runOrSchedule();
	return true;
}

void SubscriberWrapper::outgoing($ByteBuffer* buffer, bool complete) {
	$Objects::requireNonNull(buffer);
	if (!SubscriberWrapper::$assertionsDisabled && !(!complete || !buffer->hasRemaining())) {
		$throwNew($AssertionError);
	}
	outgoing($($List::of($of(buffer))), complete);
}

bool SubscriberWrapper::closing() {
	return false;
}

void SubscriberWrapper::outgoing($List* buffers, bool complete) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(buffers);
	if (complete) {
		if (!SubscriberWrapper::$assertionsDisabled && !($Utils::remaining(buffers) == 0)) {
			$throwNew($AssertionError);
		}
		bool closing = this->closing();
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("completionAcknowledged upstreamCompleted:%s, downstreamCompleted:%s, closing:%s"_s, $$new($ObjectArray, {
				$($of($Boolean::valueOf(this->upstreamCompleted))),
				$($of($Boolean::valueOf(this->downstreamCompleted))),
				$($of($Boolean::valueOf(closing)))
			}));
		}
		if (!this->upstreamCompleted && !closing) {
			$throwNew($IllegalStateException, "upstream not completed"_s);
		}
		this->completionAcknowledged = true;
	} else {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Adding %d to outputQ queue"_s, $$new($ObjectArray, {$($of($Long::valueOf($Utils::remaining(buffers))))}));
		}
		$nc(this->outputQ)->add(buffers);
	}
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log($$str({"pushScheduler"_s, ($nc(this->pushScheduler)->isStopped() ? " is stopped!"_s : " is alive"_s)}));
	}
	$nc(this->pushScheduler)->runOrSchedule();
}

$CompletableFuture* SubscriberWrapper::completion() {
	return this->cf;
}

int32_t SubscriberWrapper::outputQueueSize() {
	return $nc(this->outputQ)->size();
}

bool SubscriberWrapper::hasNoOutputData() {
	return $nc(this->outputQ)->isEmpty();
}

void SubscriberWrapper::upstreamWindowUpdate() {
	$useLocalCurrentObjectStackCache();
	int64_t downstreamQueueSize = $nc(this->outputQ)->size();
	int64_t upstreamWindowSize = $nc(this->upstreamWindow$)->get();
	int64_t n = upstreamWindowUpdate(upstreamWindowSize, downstreamQueueSize);
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("upstreamWindowUpdate, downstreamQueueSize:%d, upstreamWindow:%d"_s, $$new($ObjectArray, {
			$($of($Long::valueOf(downstreamQueueSize))),
			$($of($Long::valueOf(upstreamWindowSize)))
		}));
	}
	if (n > 0) {
		upstreamRequest(n);
	}
}

void SubscriberWrapper::onSubscribe($Flow$Subscription* subscription) {
	if (this->upstreamSubscription != nullptr) {
		$throwNew($IllegalStateException, "Single shot publisher"_s);
	}
	$set(this, upstreamSubscription, subscription);
	upstreamRequest(initialUpstreamDemand());
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("calling downstreamSubscriber::onSubscribe on %s"_s, $$new($ObjectArray, {$of(this->downstreamSubscriber)}));
	}
	$nc(this->downstreamSubscriber)->onSubscribe(this->downstreamSubscription);
	onSubscribe();
}

void SubscriberWrapper::onNext($List* item) {
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("onNext"_s);
	}
	int64_t prev = $nc(this->upstreamWindow$)->getAndDecrement();
	if (prev <= 0) {
		$throwNew($IllegalStateException, "invalid onNext call"_s);
	}
	incomingCaller(item, false);
}

void SubscriberWrapper::upstreamRequest(int64_t n) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("requesting %d"_s, $$new($ObjectArray, {$($of($Long::valueOf(n)))}));
	}
	$nc(this->upstreamWindow$)->getAndAdd(n);
	$nc(this->upstreamSubscription)->request(n);
}

int64_t SubscriberWrapper::initialUpstreamDemand() {
	return 1;
}

void SubscriberWrapper::requestMore() {
	if ($nc(this->upstreamWindow$)->get() == 0) {
		upstreamRequest(1);
	}
}

int64_t SubscriberWrapper::upstreamWindow() {
	return $nc(this->upstreamWindow$)->get();
}

void SubscriberWrapper::onError($Throwable* throwable) {
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log($$str({"onError: "_s, throwable}));
	}
	errorCommon($cast($Throwable, $Objects::requireNonNull(throwable)));
}

bool SubscriberWrapper::errorCommon($Throwable* throwable$renamed) {
	$var($Throwable, throwable, throwable$renamed);
	if (!SubscriberWrapper::$assertionsDisabled && !(throwable != nullptr || ($assign(throwable, $new($AssertionError, $of("null throwable"_s)))) != nullptr)) {
		$throwNew($AssertionError);
	}
	if ($nc(this->errorRef)->compareAndSet(nullptr, throwable)) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("error"_s, throwable);
		}
		this->upstreamCompleted = true;
		$nc(this->pushScheduler)->runOrSchedule();
		return true;
	}
	return false;
}

void SubscriberWrapper::close() {
	errorCommon($$new($RuntimeException, "wrapper closed"_s));
}

void SubscriberWrapper::close($Throwable* t) {
	errorCommon(t);
}

void SubscriberWrapper::incomingCaller($List* l, bool complete) {
	try {
		incoming(l, complete);
	} catch ($Throwable& t) {
		errorCommon(t);
	}
}

void SubscriberWrapper::onComplete() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log($$str({"upstream completed: "_s, $(toString())}));
	}
	this->upstreamCompleted = true;
	$init($Utils);
	incomingCaller($Utils::EMPTY_BB_LIST, true);
	$nc(this->pushScheduler)->runOrSchedule();
}

void SubscriberWrapper::addData($ByteBuffer* l) {
	if (this->upstreamSubscription == nullptr) {
		$throwNew($IllegalStateException, "can\'t add data before upstream subscriber subscribes"_s);
	}
	incomingCaller($($List::of($of(l))), false);
}

void SubscriberWrapper::checkCompletion() {
	if (this->downstreamCompleted || !this->upstreamCompleted) {
		return;
	}
	if (!$nc(this->outputQ)->isEmpty()) {
		return;
	}
	if ($nc(this->errorRef)->get() != nullptr) {
		$nc(this->pushScheduler)->runOrSchedule();
		return;
	}
	if (this->completionAcknowledged) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("calling downstreamSubscriber.onComplete()"_s);
		}
		$nc(this->downstreamSubscriber)->onComplete();
		this->downstreamCompleted = true;
		$nc(this->cf)->complete(nullptr);
	}
}

void SubscriberWrapper::downstreamCompletion() {
	$nc(this->upstreamSubscription)->cancel();
	$nc(this->cf)->complete(nullptr);
}

void SubscriberWrapper::resetDownstreamDemand() {
	$nc($nc(this->downstreamSubscription)->demand)->reset();
}

$String* SubscriberWrapper::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("SubscriberWrapper:"_s)->append(" upstreamCompleted: "_s)->append($($Boolean::toString(this->upstreamCompleted)))->append(" upstreamWindow: "_s)->append($($nc(this->upstreamWindow$)->toString()))->append(" downstreamCompleted: "_s)->append($($Boolean::toString(this->downstreamCompleted)))->append(" completionAcknowledged: "_s)->append($($Boolean::toString(this->completionAcknowledged)))->append(" outputQ size: "_s)->append($($Integer::toString($nc(this->outputQ)->size())))->append(" cf: "_s)->append($($nc(this->cf)->toString()))->append(" downstreamSubscription: "_s)->append($of(this->downstreamSubscription))->append(" downstreamSubscriber: "_s)->append($of(this->downstreamSubscriber));
	return sb->toString();
}

$String* SubscriberWrapper::dbgString() {
	return "SubscriberWrapper"_s;
}

void SubscriberWrapper::onNext(Object$* item) {
	this->onNext($cast($List, item));
}

void SubscriberWrapper::lambda$new$0($Void* v, $Throwable* t) {
	if (t != nullptr) {
		errorCommon(t);
	}
}

void clinit$SubscriberWrapper($Class* class$) {
	SubscriberWrapper::$assertionsDisabled = !SubscriberWrapper::class$->desiredAssertionStatus();
}

SubscriberWrapper::SubscriberWrapper() {
}

$Class* SubscriberWrapper::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SubscriberWrapper$$Lambda$dbgString::classInfo$.name)) {
			return SubscriberWrapper$$Lambda$dbgString::load$(name, initialize);
		}
		if (name->equals(SubscriberWrapper$$Lambda$lambda$new$0$1::classInfo$.name)) {
			return SubscriberWrapper$$Lambda$lambda$new$0$1::load$(name, initialize);
		}
		if (name->equals(SubscriberWrapper$$Lambda$downstreamCompletion$2::classInfo$.name)) {
			return SubscriberWrapper$$Lambda$downstreamCompletion$2::load$(name, initialize);
		}
	}
	$loadClass(SubscriberWrapper, name, initialize, &_SubscriberWrapper_ClassInfo_, clinit$SubscriberWrapper, allocate$SubscriberWrapper);
	return class$;
}

$Class* SubscriberWrapper::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk