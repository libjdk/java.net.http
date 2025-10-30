#include <jdk/internal/net/http/SocketTube$InternalWriteSubscriber.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/channels/SocketChannel.h>
#include <java/util/List.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/AsyncEvent.h>
#include <jdk/internal/net/http/AsyncTriggerEvent.h>
#include <jdk/internal/net/http/HttpClientImpl$DelegatingExecutor.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher$InternalReadSubscription.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher.h>
#include <jdk/internal/net/http/SocketTube$InternalWriteSubscriber$WriteEvent.h>
#include <jdk/internal/net/http/SocketTube$InternalWriteSubscriber$WriteSubscription.h>
#include <jdk/internal/net/http/SocketTube$SocketFlowEvent.h>
#include <jdk/internal/net/http/SocketTube.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $List = ::java::util::List;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Consumer = ::java::util::function::Consumer;
using $Supplier = ::java::util::function::Supplier;
using $AsyncEvent = ::jdk::internal::net::http::AsyncEvent;
using $AsyncTriggerEvent = ::jdk::internal::net::http::AsyncTriggerEvent;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpClientImpl$DelegatingExecutor = ::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor;
using $SocketTube = ::jdk::internal::net::http::SocketTube;
using $SocketTube$InternalReadPublisher = ::jdk::internal::net::http::SocketTube$InternalReadPublisher;
using $SocketTube$InternalReadPublisher$InternalReadSubscription = ::jdk::internal::net::http::SocketTube$InternalReadPublisher$InternalReadSubscription;
using $SocketTube$InternalWriteSubscriber$WriteEvent = ::jdk::internal::net::http::SocketTube$InternalWriteSubscriber$WriteEvent;
using $SocketTube$InternalWriteSubscriber$WriteSubscription = ::jdk::internal::net::http::SocketTube$InternalWriteSubscriber$WriteSubscription;
using $SocketTube$SocketFlowEvent = ::jdk::internal::net::http::SocketTube$SocketFlowEvent;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class SocketTube$InternalWriteSubscriber$$Lambda$signalError : public $Consumer {
	$class(SocketTube$InternalWriteSubscriber$$Lambda$signalError, $NO_CLASS_INIT, $Consumer)
public:
	void init$(SocketTube$InternalWriteSubscriber* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* error) override {
		$nc(inst$)->signalError($cast($Throwable, error));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SocketTube$InternalWriteSubscriber$$Lambda$signalError>());
	}
	SocketTube$InternalWriteSubscriber* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SocketTube$InternalWriteSubscriber$$Lambda$signalError::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SocketTube$InternalWriteSubscriber$$Lambda$signalError, inst$)},
	{}
};
$MethodInfo SocketTube$InternalWriteSubscriber$$Lambda$signalError::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/SocketTube$InternalWriteSubscriber;)V", nullptr, $PUBLIC, $method(static_cast<void(SocketTube$InternalWriteSubscriber$$Lambda$signalError::*)(SocketTube$InternalWriteSubscriber*)>(&SocketTube$InternalWriteSubscriber$$Lambda$signalError::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo SocketTube$InternalWriteSubscriber$$Lambda$signalError::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.SocketTube$InternalWriteSubscriber$$Lambda$signalError",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* SocketTube$InternalWriteSubscriber$$Lambda$signalError::load$($String* name, bool initialize) {
	$loadClass(SocketTube$InternalWriteSubscriber$$Lambda$signalError, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SocketTube$InternalWriteSubscriber$$Lambda$signalError::class$ = nullptr;

class SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1 : public $Runnable {
	$class(SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1, $NO_CLASS_INIT, $Runnable)
public:
	void init$(SocketTube$InternalWriteSubscriber* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->startSubscription();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1>());
	}
	SocketTube$InternalWriteSubscriber* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1, inst$)},
	{}
};
$MethodInfo SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/SocketTube$InternalWriteSubscriber;)V", nullptr, $PUBLIC, $method(static_cast<void(SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1::*)(SocketTube$InternalWriteSubscriber*)>(&SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1::load$($String* name, bool initialize) {
	$loadClass(SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1::class$ = nullptr;

class SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2 : public $Runnable {
	$class(SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2, $NO_CLASS_INIT, $Runnable)
public:
	void init$(SocketTube$InternalWriteSubscriber* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->requestMore();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2>());
	}
	SocketTube$InternalWriteSubscriber* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2, inst$)},
	{}
};
$MethodInfo SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/SocketTube$InternalWriteSubscriber;)V", nullptr, $PUBLIC, $method(static_cast<void(SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2::*)(SocketTube$InternalWriteSubscriber*)>(&SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2::load$($String* name, bool initialize) {
	$loadClass(SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2::class$ = nullptr;

class SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3 : public $Supplier {
	$class(SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Throwable* error) {
		$set(this, error, error);
	}
	virtual $Object* get() override {
		 return $of(SocketTube$InternalWriteSubscriber::lambda$signalError$0(error));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3>());
	}
	$Throwable* error = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3::fieldInfos[2] = {
	{"error", "Ljava/lang/Throwable;", nullptr, $PUBLIC, $field(SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3, error)},
	{}
};
$MethodInfo SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(static_cast<void(SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3::*)($Throwable*)>(&SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3::load$($String* name, bool initialize) {
	$loadClass(SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3::class$ = nullptr;

$FieldInfo _SocketTube$InternalWriteSubscriber_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/SocketTube;", nullptr, $FINAL | $SYNTHETIC, $field(SocketTube$InternalWriteSubscriber, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SocketTube$InternalWriteSubscriber, $assertionsDisabled)},
	{"subscription", "Ljdk/internal/net/http/SocketTube$InternalWriteSubscriber$WriteSubscription;", nullptr, $VOLATILE, $field(SocketTube$InternalWriteSubscriber, subscription)},
	{"current", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/ByteBuffer;>;", $VOLATILE, $field(SocketTube$InternalWriteSubscriber, current)},
	{"completed", "Z", nullptr, $VOLATILE, $field(SocketTube$InternalWriteSubscriber, completed)},
	{"startSubscription", "Ljdk/internal/net/http/AsyncTriggerEvent;", nullptr, $FINAL, $field(SocketTube$InternalWriteSubscriber, startSubscription$)},
	{"writeEvent", "Ljdk/internal/net/http/SocketTube$InternalWriteSubscriber$WriteEvent;", nullptr, $FINAL, $field(SocketTube$InternalWriteSubscriber, writeEvent)},
	{"writeDemand", "Ljdk/internal/net/http/common/Demand;", nullptr, $FINAL, $field(SocketTube$InternalWriteSubscriber, writeDemand)},
	{}
};

$MethodInfo _SocketTube$InternalWriteSubscriber_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/SocketTube;)V", nullptr, $PRIVATE, $method(static_cast<void(SocketTube$InternalWriteSubscriber::*)($SocketTube*)>(&SocketTube$InternalWriteSubscriber::init$))},
	{"lambda$signalError$0", "(Ljava/lang/Throwable;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($Throwable*)>(&SocketTube$InternalWriteSubscriber::lambda$signalError$0))},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, $method(static_cast<void(SocketTube$InternalWriteSubscriber::*)($List*)>(&SocketTube$InternalWriteSubscriber::onNext))},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{"requestMore", "()V", nullptr, 0, $method(static_cast<void(SocketTube$InternalWriteSubscriber::*)()>(&SocketTube$InternalWriteSubscriber::requestMore))},
	{"resumeWriteEvent", "(Z)V", nullptr, 0, $method(static_cast<void(SocketTube$InternalWriteSubscriber::*)(bool)>(&SocketTube$InternalWriteSubscriber::resumeWriteEvent))},
	{"signalError", "(Ljava/lang/Throwable;)V", nullptr, 0, $method(static_cast<void(SocketTube$InternalWriteSubscriber::*)($Throwable*)>(&SocketTube$InternalWriteSubscriber::signalError))},
	{"signalWritable", "()V", nullptr, 0, $method(static_cast<void(SocketTube$InternalWriteSubscriber::*)()>(&SocketTube$InternalWriteSubscriber::signalWritable))},
	{"startSubscription", "()V", nullptr, 0, $method(static_cast<void(SocketTube$InternalWriteSubscriber::*)()>(&SocketTube$InternalWriteSubscriber::startSubscription))},
	{"tryFlushCurrent", "(Z)V", nullptr, 0, $method(static_cast<void(SocketTube$InternalWriteSubscriber::*)(bool)>(&SocketTube$InternalWriteSubscriber::tryFlushCurrent))},
	{}
};

$InnerClassInfo _SocketTube$InternalWriteSubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.SocketTube$InternalWriteSubscriber", "jdk.internal.net.http.SocketTube", "InternalWriteSubscriber", $PRIVATE | $FINAL},
	{"java.util.concurrent.Flow$Subscriber", "java.util.concurrent.Flow", "Subscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.SocketTube$InternalWriteSubscriber$WriteSubscription", "jdk.internal.net.http.SocketTube$InternalWriteSubscriber", "WriteSubscription", $FINAL},
	{"jdk.internal.net.http.SocketTube$InternalWriteSubscriber$WriteEvent", "jdk.internal.net.http.SocketTube$InternalWriteSubscriber", "WriteEvent", $FINAL},
	{}
};

$ClassInfo _SocketTube$InternalWriteSubscriber_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.SocketTube$InternalWriteSubscriber",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscriber",
	_SocketTube$InternalWriteSubscriber_FieldInfo_,
	_SocketTube$InternalWriteSubscriber_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/concurrent/Flow$Subscriber<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;",
	nullptr,
	_SocketTube$InternalWriteSubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.SocketTube"
};

$Object* allocate$SocketTube$InternalWriteSubscriber($Class* clazz) {
	return $of($alloc(SocketTube$InternalWriteSubscriber));
}

bool SocketTube$InternalWriteSubscriber::$assertionsDisabled = false;

void SocketTube$InternalWriteSubscriber::init$($SocketTube* this$0) {
	$useLocalCurrentObjectStackCache();
	$set(this, this$0, this$0);
	$var($Consumer, var$0, static_cast<$Consumer*>($new(SocketTube$InternalWriteSubscriber$$Lambda$signalError, this)));
	$set(this, startSubscription$, $new($AsyncTriggerEvent, var$0, static_cast<$Runnable*>($$new(SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1, this))));
	$set(this, writeEvent, $new($SocketTube$InternalWriteSubscriber$WriteEvent, this, this->this$0->channel, this));
	$set(this, writeDemand, $new($Demand));
}

void SocketTube$InternalWriteSubscriber::onSubscribe($Flow$Subscription* subscription) {
	$var($SocketTube$InternalWriteSubscriber$WriteSubscription, previous, this->subscription);
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("subscribed for writing"_s);
	}
	try {
		bool needEvent = this->current == nullptr;
		if (needEvent) {
			if (previous != nullptr && previous->upstreamSubscription != subscription) {
				previous->dropSubscription();
			}
		}
		$set(this, subscription, $new($SocketTube$InternalWriteSubscriber$WriteSubscription, this, subscription));
		if (needEvent) {
			if ($nc(this->this$0->debug)->on()) {
				$nc(this->this$0->debug)->log("write: registering startSubscription event"_s);
			}
			$nc(this->this$0->client)->registerEvent(this->startSubscription$);
		}
	} catch ($Throwable& t) {
		signalError(t);
	}
}

void SocketTube$InternalWriteSubscriber::onNext($List* bufs) {
	$useLocalCurrentObjectStackCache();
	if (!SocketTube$InternalWriteSubscriber::$assertionsDisabled && !(this->current == nullptr)) {
		$throwNew($AssertionError, $of($$str({$(this->this$0->dbgString()), "w.onNext current: "_s, this->current})));
	}
	if (!SocketTube$InternalWriteSubscriber::$assertionsDisabled && !(this->subscription != nullptr)) {
		$throwNew($AssertionError, $of($$str({$(this->this$0->dbgString()), "w.onNext: subscription is null"_s})));
	}
	$set(this, current, bufs);
	tryFlushCurrent($nc(this->this$0->client)->isSelectorThread());
	this->this$0->debugState("leaving w.onNext"_s);
}

void SocketTube$InternalWriteSubscriber::tryFlushCurrent(bool inSelectorThread) {
	$useLocalCurrentObjectStackCache();
	$var($List, bufs, this->current);
	if (bufs == nullptr) {
		return;
	}
	try {
		if (!SocketTube$InternalWriteSubscriber::$assertionsDisabled && !(inSelectorThread == $nc(this->this$0->client)->isSelectorThread())) {
			$throwNew($AssertionError, $of($$str({"should "_s, (inSelectorThread ? ""_s : "not "_s), " be in the selector thread"_s})));
		}
		int64_t remaining = $Utils::remaining(bufs);
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("trying to write: %d"_s, $$new($ObjectArray, {$($of($Long::valueOf(remaining)))}));
		}
		int64_t written = this->this$0->writeAvailable(bufs);
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("wrote: %d"_s, $$new($ObjectArray, {$($of($Long::valueOf(written)))}));
		}
		if (!SocketTube$InternalWriteSubscriber::$assertionsDisabled && !(written >= 0)) {
			$throwNew($AssertionError, $of($$str({"negative number of bytes written:"_s, $$str(written)})));
		}
		if (!SocketTube$InternalWriteSubscriber::$assertionsDisabled && !(written <= remaining)) {
			$throwNew($AssertionError);
		}
		if (remaining - written == 0) {
			$set(this, current, nullptr);
			if ($nc(this->writeDemand)->tryDecrement()) {
				$var($Runnable, requestMore, static_cast<$Runnable*>($new(SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2, this)));
				if (inSelectorThread) {
					if (!SocketTube$InternalWriteSubscriber::$assertionsDisabled && !$nc(this->this$0->client)->isSelectorThread()) {
						$throwNew($AssertionError);
					}
					$nc($($nc(this->this$0->client)->theExecutor()))->execute(requestMore);
				} else {
					if (!SocketTube$InternalWriteSubscriber::$assertionsDisabled && ! !$nc(this->this$0->client)->isSelectorThread()) {
						$throwNew($AssertionError);
					}
					$nc(requestMore)->run();
				}
			}
		} else {
			resumeWriteEvent(inSelectorThread);
		}
	} catch ($Throwable& t) {
		signalError(t);
	}
}

void SocketTube$InternalWriteSubscriber::startSubscription() {
	$useLocalCurrentObjectStackCache();
	try {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("write: starting subscription"_s);
		}
		if ($Log::channel()) {
			$Log::logChannel("Start requesting bytes for writing to channel: {0}"_s, $$new($ObjectArray, {$($of(this->this$0->channelDescr()))}));
		}
		if (!SocketTube$InternalWriteSubscriber::$assertionsDisabled && !$nc(this->this$0->client)->isSelectorThread()) {
			$throwNew($AssertionError);
		}
		$nc($nc(this->this$0->readPublisher)->subscriptionImpl)->handlePending();
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("write: offloading requestMore"_s);
		}
		$nc($($nc(this->this$0->client)->theExecutor()))->execute(static_cast<$Runnable*>($$new(SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2, this)));
	} catch ($Throwable& t) {
		signalError(t);
	}
}

void SocketTube$InternalWriteSubscriber::requestMore() {
	$var($SocketTube$InternalWriteSubscriber$WriteSubscription, subscription, this->subscription);
	$nc(subscription)->requestMore();
}

void SocketTube$InternalWriteSubscriber::onError($Throwable* throwable) {
	signalError(throwable);
}

void SocketTube$InternalWriteSubscriber::onComplete() {
	$useLocalCurrentObjectStackCache();
	this->completed = true;
	$var($List, bufs, this->current);
	int64_t remaining = bufs == nullptr ? (int64_t)0 : $Utils::remaining(bufs);
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("write completed, %d yet to send"_s, $$new($ObjectArray, {$($of($Long::valueOf(remaining)))}));
	}
	this->this$0->debugState("InternalWriteSubscriber::onComplete"_s);
}

void SocketTube$InternalWriteSubscriber::resumeWriteEvent(bool inSelectorThread) {
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("scheduling write event"_s);
	}
	this->this$0->resumeEvent(this->writeEvent, static_cast<$Consumer*>($$new(SocketTube$InternalWriteSubscriber$$Lambda$signalError, this)));
}

void SocketTube$InternalWriteSubscriber::signalWritable() {
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("channel is writable"_s);
	}
	tryFlushCurrent(true);
}

void SocketTube$InternalWriteSubscriber::signalError($Throwable* error) {
	$useLocalCurrentObjectStackCache();
	$nc(this->this$0->debug)->log(static_cast<$Supplier*>($$new(SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3, error)));
	if ($Log::channel()) {
		$Log::logChannel("Failed to write to channel ({0}: {1})"_s, $$new($ObjectArray, {
			$($of(this->this$0->channelDescr())),
			$of(error)
		}));
	}
	this->completed = true;
	$nc(this->this$0->readPublisher)->signalError(error);
	$var($Flow$Subscription, subscription, this->subscription);
	if (subscription != nullptr) {
		subscription->cancel();
	}
}

void SocketTube$InternalWriteSubscriber::onNext(Object$* bufs) {
	this->onNext($cast($List, bufs));
}

$String* SocketTube$InternalWriteSubscriber::lambda$signalError$0($Throwable* error) {
	$init(SocketTube$InternalWriteSubscriber);
	return $str({"write error: "_s, error});
}

void clinit$SocketTube$InternalWriteSubscriber($Class* class$) {
	$load($SocketTube);
	SocketTube$InternalWriteSubscriber::$assertionsDisabled = !$SocketTube::class$->desiredAssertionStatus();
}

SocketTube$InternalWriteSubscriber::SocketTube$InternalWriteSubscriber() {
}

$Class* SocketTube$InternalWriteSubscriber::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SocketTube$InternalWriteSubscriber$$Lambda$signalError::classInfo$.name)) {
			return SocketTube$InternalWriteSubscriber$$Lambda$signalError::load$(name, initialize);
		}
		if (name->equals(SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1::classInfo$.name)) {
			return SocketTube$InternalWriteSubscriber$$Lambda$startSubscription$1::load$(name, initialize);
		}
		if (name->equals(SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2::classInfo$.name)) {
			return SocketTube$InternalWriteSubscriber$$Lambda$requestMore$2::load$(name, initialize);
		}
		if (name->equals(SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3::classInfo$.name)) {
			return SocketTube$InternalWriteSubscriber$$Lambda$lambda$signalError$0$3::load$(name, initialize);
		}
	}
	$loadClass(SocketTube$InternalWriteSubscriber, name, initialize, &_SocketTube$InternalWriteSubscriber_ClassInfo_, clinit$SocketTube$InternalWriteSubscriber, allocate$SocketTube$InternalWriteSubscriber);
	return class$;
}

$Class* SocketTube$InternalWriteSubscriber::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk