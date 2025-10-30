#include <jdk/internal/net/http/SocketTube$InternalReadPublisher$InternalReadSubscription.h>

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
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <java/util/function/Consumer.h>
#include <jdk/internal/net/http/AsyncEvent.h>
#include <jdk/internal/net/http/AsyncTriggerEvent.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/SocketTube$BufferSource.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher$ReadEvent.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher$ReadSubscription.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher.h>
#include <jdk/internal/net/http/SocketTube$SocketFlowEvent.h>
#include <jdk/internal/net/http/SocketTube$SocketFlowTask.h>
#include <jdk/internal/net/http/SocketTube.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SequentialScheduler$RestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef EOF

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
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
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $Consumer = ::java::util::function::Consumer;
using $AsyncEvent = ::jdk::internal::net::http::AsyncEvent;
using $AsyncTriggerEvent = ::jdk::internal::net::http::AsyncTriggerEvent;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $SocketTube = ::jdk::internal::net::http::SocketTube;
using $SocketTube$BufferSource = ::jdk::internal::net::http::SocketTube$BufferSource;
using $SocketTube$InternalReadPublisher = ::jdk::internal::net::http::SocketTube$InternalReadPublisher;
using $SocketTube$InternalReadPublisher$ReadEvent = ::jdk::internal::net::http::SocketTube$InternalReadPublisher$ReadEvent;
using $SocketTube$InternalReadPublisher$ReadSubscription = ::jdk::internal::net::http::SocketTube$InternalReadPublisher$ReadSubscription;
using $SocketTube$SocketFlowEvent = ::jdk::internal::net::http::SocketTube$SocketFlowEvent;
using $SocketTube$SocketFlowTask = ::jdk::internal::net::http::SocketTube$SocketFlowTask;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SequentialScheduler$RestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$RestartableTask;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read : public $Runnable {
	$class(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read, $NO_CLASS_INIT, $Runnable)
public:
	void init$(SocketTube$InternalReadPublisher$InternalReadSubscription* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->read();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read>());
	}
	SocketTube$InternalReadPublisher$InternalReadSubscription* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read, inst$)},
	{}
};
$MethodInfo SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/SocketTube$InternalReadPublisher$InternalReadSubscription;)V", nullptr, $PUBLIC, $method(static_cast<void(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read::*)(SocketTube$InternalReadPublisher$InternalReadSubscription*)>(&SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read::load$($String* name, bool initialize) {
	$loadClass(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read::class$ = nullptr;

class SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1 : public $Consumer {
	$class(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$(SocketTube$InternalReadPublisher$InternalReadSubscription* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* error) override {
		$nc(inst$)->signalError($cast($Throwable, error));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1>());
	}
	SocketTube$InternalReadPublisher$InternalReadSubscription* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1, inst$)},
	{}
};
$MethodInfo SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/SocketTube$InternalReadPublisher$InternalReadSubscription;)V", nullptr, $PUBLIC, $method(static_cast<void(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1::*)(SocketTube$InternalReadPublisher$InternalReadSubscription*)>(&SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1::load$($String* name, bool initialize) {
	$loadClass(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1::class$ = nullptr;

class SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2 : public $Runnable {
	$class(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2, $NO_CLASS_INIT, $Runnable)
public:
	void init$(SocketTube$InternalReadPublisher$InternalReadSubscription* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->handleSubscribeEvent();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2>());
	}
	SocketTube$InternalReadPublisher$InternalReadSubscription* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2, inst$)},
	{}
};
$MethodInfo SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/SocketTube$InternalReadPublisher$InternalReadSubscription;)V", nullptr, $PUBLIC, $method(static_cast<void(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2::*)(SocketTube$InternalReadPublisher$InternalReadSubscription*)>(&SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2::load$($String* name, bool initialize) {
	$loadClass(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2::class$ = nullptr;

$FieldInfo _SocketTube$InternalReadPublisher$InternalReadSubscription_FieldInfo_[] = {
	{"this$1", "Ljdk/internal/net/http/SocketTube$InternalReadPublisher;", nullptr, $FINAL | $SYNTHETIC, $field(SocketTube$InternalReadPublisher$InternalReadSubscription, this$1)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SocketTube$InternalReadPublisher$InternalReadSubscription, $assertionsDisabled)},
	{"demand", "Ljdk/internal/net/http/common/Demand;", nullptr, $PRIVATE | $FINAL, $field(SocketTube$InternalReadPublisher$InternalReadSubscription, demand)},
	{"readScheduler", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $FINAL, $field(SocketTube$InternalReadPublisher$InternalReadSubscription, readScheduler)},
	{"completed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(SocketTube$InternalReadPublisher$InternalReadSubscription, completed)},
	{"readEvent", "Ljdk/internal/net/http/SocketTube$InternalReadPublisher$ReadEvent;", nullptr, $PRIVATE | $FINAL, $field(SocketTube$InternalReadPublisher$InternalReadSubscription, readEvent)},
	{"subscribeEvent", "Ljdk/internal/net/http/AsyncEvent;", nullptr, $PRIVATE | $FINAL, $field(SocketTube$InternalReadPublisher$InternalReadSubscription, subscribeEvent)},
	{}
};

$MethodInfo _SocketTube$InternalReadPublisher$InternalReadSubscription_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/SocketTube$InternalReadPublisher;)V", nullptr, 0, $method(static_cast<void(SocketTube$InternalReadPublisher$InternalReadSubscription::*)($SocketTube$InternalReadPublisher*)>(&SocketTube$InternalReadPublisher$InternalReadSubscription::init$))},
	{"cancel", "()V", nullptr, $PUBLIC | $FINAL},
	{"handleError", "()V", nullptr, $FINAL, $method(static_cast<void(SocketTube$InternalReadPublisher$InternalReadSubscription::*)()>(&SocketTube$InternalReadPublisher$InternalReadSubscription::handleError))},
	{"handlePending", "()Z", nullptr, 0, $method(static_cast<bool(SocketTube$InternalReadPublisher$InternalReadSubscription::*)()>(&SocketTube$InternalReadPublisher$InternalReadSubscription::handlePending))},
	{"handleSubscribeEvent", "()V", nullptr, $FINAL, $method(static_cast<void(SocketTube$InternalReadPublisher$InternalReadSubscription::*)()>(&SocketTube$InternalReadPublisher$InternalReadSubscription::handleSubscribeEvent))},
	{"pauseReadEvent", "()V", nullptr, $PRIVATE, $method(static_cast<void(SocketTube$InternalReadPublisher$InternalReadSubscription::*)()>(&SocketTube$InternalReadPublisher$InternalReadSubscription::pauseReadEvent))},
	{"read", "()V", nullptr, $FINAL, $method(static_cast<void(SocketTube$InternalReadPublisher$InternalReadSubscription::*)()>(&SocketTube$InternalReadPublisher$InternalReadSubscription::read))},
	{"request", "(J)V", nullptr, $PUBLIC | $FINAL},
	{"resumeReadEvent", "()V", nullptr, $PRIVATE, $method(static_cast<void(SocketTube$InternalReadPublisher$InternalReadSubscription::*)()>(&SocketTube$InternalReadPublisher$InternalReadSubscription::resumeReadEvent))},
	{"signalError", "(Ljava/lang/Throwable;)V", nullptr, $FINAL, $method(static_cast<void(SocketTube$InternalReadPublisher$InternalReadSubscription::*)($Throwable*)>(&SocketTube$InternalReadPublisher$InternalReadSubscription::signalError))},
	{"signalReadable", "()V", nullptr, $FINAL, $method(static_cast<void(SocketTube$InternalReadPublisher$InternalReadSubscription::*)()>(&SocketTube$InternalReadPublisher$InternalReadSubscription::signalReadable))},
	{"signalSubscribe", "()V", nullptr, $FINAL, $method(static_cast<void(SocketTube$InternalReadPublisher$InternalReadSubscription::*)()>(&SocketTube$InternalReadPublisher$InternalReadSubscription::signalSubscribe))},
	{}
};

$InnerClassInfo _SocketTube$InternalReadPublisher$InternalReadSubscription_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.SocketTube$InternalReadPublisher", "jdk.internal.net.http.SocketTube", "InternalReadPublisher", $PRIVATE | $FINAL},
	{"jdk.internal.net.http.SocketTube$InternalReadPublisher$InternalReadSubscription", "jdk.internal.net.http.SocketTube$InternalReadPublisher", "InternalReadSubscription", $FINAL},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SocketTube$InternalReadPublisher$InternalReadSubscription_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.SocketTube$InternalReadPublisher$InternalReadSubscription",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription",
	_SocketTube$InternalReadPublisher$InternalReadSubscription_FieldInfo_,
	_SocketTube$InternalReadPublisher$InternalReadSubscription_MethodInfo_,
	nullptr,
	nullptr,
	_SocketTube$InternalReadPublisher$InternalReadSubscription_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.SocketTube"
};

$Object* allocate$SocketTube$InternalReadPublisher$InternalReadSubscription($Class* clazz) {
	return $of($alloc(SocketTube$InternalReadPublisher$InternalReadSubscription));
}

bool SocketTube$InternalReadPublisher$InternalReadSubscription::$assertionsDisabled = false;

void SocketTube$InternalReadPublisher$InternalReadSubscription::init$($SocketTube$InternalReadPublisher* this$1) {
	$useLocalCurrentObjectStackCache();
	$set(this, this$1, this$1);
	$set(this, demand, $new($Demand));
	$set(this, readScheduler, $new($SequentialScheduler, $$new($SocketTube$SocketFlowTask, static_cast<$Runnable*>($$new(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read, this)))));
	$var($Consumer, var$0, static_cast<$Consumer*>($new(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1, this)));
	$set(this, subscribeEvent, $new($AsyncTriggerEvent, var$0, static_cast<$Runnable*>($$new(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2, this))));
	$set(this, readEvent, $new($SocketTube$InternalReadPublisher$ReadEvent, this$1, $nc(this$1->this$0)->channel, this));
}

void SocketTube$InternalReadPublisher$InternalReadSubscription::signalSubscribe() {
	if ($nc(this->readScheduler)->isStopped() || this->completed) {
		if ($nc($nc(this->this$1->this$0)->debug)->on()) {
			$nc($nc(this->this$1->this$0)->debug)->log("handling pending subscription while completed"_s);
		}
		handlePending();
	} else {
		try {
			if ($nc($nc(this->this$1->this$0)->debug)->on()) {
				$nc($nc(this->this$1->this$0)->debug)->log("registering subscribe event"_s);
			}
			$nc($nc(this->this$1->this$0)->client)->registerEvent(this->subscribeEvent);
		} catch ($Throwable& t) {
			signalError(t);
			handlePending();
		}
	}
}

void SocketTube$InternalReadPublisher$InternalReadSubscription::handleSubscribeEvent() {
	$useLocalCurrentObjectStackCache();
	if (!SocketTube$InternalReadPublisher$InternalReadSubscription::$assertionsDisabled && !$nc($nc(this->this$1->this$0)->client)->isSelectorThread()) {
		$throwNew($AssertionError);
	}
	$nc($nc(this->this$1->this$0)->debug)->log("subscribe event raised"_s);
	if ($Log::channel()) {
		$Log::logChannel("Start reading from {0}"_s, $$new($ObjectArray, {$($of($nc(this->this$1->this$0)->channelDescr()))}));
	}
	$nc(this->readScheduler)->runOrSchedule();
	if ($nc(this->readScheduler)->isStopped() || this->completed) {
		if ($nc($nc(this->this$1->this$0)->debug)->on()) {
			$nc($nc(this->this$1->this$0)->debug)->log("handling pending subscription when completed"_s);
		}
		handlePending();
	}
}

void SocketTube$InternalReadPublisher$InternalReadSubscription::request(int64_t n) {
	$useLocalCurrentObjectStackCache();
	if (n > (int64_t)0) {
		bool wasFulfilled = $nc(this->demand)->increase(n);
		if (wasFulfilled) {
			if ($nc($nc(this->this$1->this$0)->debug)->on()) {
				$nc($nc(this->this$1->this$0)->debug)->log("got some demand for reading"_s);
			}
			resumeReadEvent();
		}
	} else {
		signalError($$new($IllegalArgumentException, "non-positive request"_s));
	}
	$nc(this->this$1->this$0)->debugState($$str({"leaving request("_s, $$str(n), "): "_s}));
}

void SocketTube$InternalReadPublisher$InternalReadSubscription::cancel() {
	$useLocalCurrentObjectStackCache();
	pauseReadEvent();
	if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log("Read subscription cancelled"_s);
	}
	if ($Log::channel()) {
		$Log::logChannel("Read subscription cancelled for channel {0}"_s, $$new($ObjectArray, {$($of($nc(this->this$1->this$0)->channelDescr()))}));
	}
	if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log("Stopping read scheduler"_s);
	}
	$nc(this->readScheduler)->stop();
}

void SocketTube$InternalReadPublisher$InternalReadSubscription::resumeReadEvent() {
	if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log("resuming read event"_s);
	}
	$nc(this->this$1->this$0)->resumeEvent(this->readEvent, static_cast<$Consumer*>($$new(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1, this)));
}

void SocketTube$InternalReadPublisher$InternalReadSubscription::pauseReadEvent() {
	if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log("pausing read event"_s);
	}
	$nc(this->this$1->this$0)->pauseEvent(this->readEvent, static_cast<$Consumer*>($$new(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1, this)));
}

void SocketTube$InternalReadPublisher$InternalReadSubscription::handleError() {
	if (!SocketTube$InternalReadPublisher$InternalReadSubscription::$assertionsDisabled && !($nc($nc(this->this$1->this$0)->errorRef)->get() != nullptr)) {
		$throwNew($AssertionError);
	}
	$nc(this->readScheduler)->runOrSchedule();
}

void SocketTube$InternalReadPublisher$InternalReadSubscription::signalError($Throwable* error) {
	$useLocalCurrentObjectStackCache();
	if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log($$str({"signal read error: "_s, error}));
	}
	if (!$nc($nc(this->this$1->this$0)->errorRef)->compareAndSet(nullptr, error)) {
		return;
	}
	if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log($$str({"got read error: "_s, error}));
	}
	if ($Log::channel()) {
		$Log::logChannel("Read error signalled on channel {0}: {1}"_s, $$new($ObjectArray, {
			$($of($nc(this->this$1->this$0)->channelDescr())),
			$of(error)
		}));
	}
	$nc(this->readScheduler)->runOrSchedule();
}

void SocketTube$InternalReadPublisher$InternalReadSubscription::signalReadable() {
	$nc(this->readScheduler)->runOrSchedule();
}

void SocketTube$InternalReadPublisher$InternalReadSubscription::read() {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				while (!$nc(this->readScheduler)->isStopped()) {
					if (this->completed) {
						return$1 = true;
						goto $finally;
					}
					if (handlePending()) {
						if ($nc($nc(this->this$1->this$0)->debug)->on()) {
							$nc($nc(this->this$1->this$0)->debug)->log("pending subscriber subscribed"_s);
						}
						return$1 = true;
						goto $finally;
					}
					$var($SocketTube$InternalReadPublisher$ReadSubscription, current, this->this$1->subscription);
					$var($Throwable, error, $cast($Throwable, $nc($nc(this->this$1->this$0)->errorRef)->get()));
					if (current == nullptr) {
						if (!SocketTube$InternalReadPublisher$InternalReadSubscription::$assertionsDisabled && !(error != nullptr)) {
							$throwNew($AssertionError);
						}
						if ($nc($nc(this->this$1->this$0)->debug)->on()) {
							$nc($nc(this->this$1->this$0)->debug)->log("error raised before subscriber subscribed: %s"_s, $$new($ObjectArray, {$of(error)}));
						}
						return$1 = true;
						goto $finally;
					}
					$var($FlowTube$TubeSubscriber, subscriber, $nc(current)->subscriber);
					if (error != nullptr) {
						this->completed = true;
						pauseReadEvent();
						if ($nc($nc(this->this$1->this$0)->debug)->on()) {
							$nc($nc(this->this$1->this$0)->debug)->log($$str({"Sending error "_s, error, " to subscriber "_s, subscriber}));
						}
						if ($Log::channel()) {
							$Log::logChannel("Raising error with subscriber for {0}: {1}"_s, $$new($ObjectArray, {
								$($of($nc(this->this$1->this$0)->channelDescr())),
								$of(error)
							}));
						}
						$nc(current->errorRef)->compareAndSet(nullptr, error);
						current->signalCompletion();
						if ($nc($nc(this->this$1->this$0)->debug)->on()) {
							$nc($nc(this->this$1->this$0)->debug)->log("Stopping read scheduler"_s);
						}
						$nc(this->readScheduler)->stop();
						$nc(this->this$1->this$0)->debugState("leaving read() loop with error: "_s);
						return$1 = true;
						goto $finally;
					}
					if (!SocketTube$InternalReadPublisher$InternalReadSubscription::$assertionsDisabled && !$nc($nc(this->this$1->this$0)->client)->isSelectorThread()) {
						$throwNew($AssertionError);
					}
					if ($nc(this->demand)->tryDecrement()) {
						try {
							$var($List, bytes, $nc(this->this$1->this$0)->readAvailable(current->bufferSource));
							if (bytes == $SocketTube::EOF) {
								if (!this->completed) {
									if ($nc($nc(this->this$1->this$0)->debug)->on()) {
										$nc($nc(this->this$1->this$0)->debug)->log("got read EOF"_s);
									}
									if ($Log::channel()) {
										$Log::logChannel("EOF read from channel: {0}"_s, $$new($ObjectArray, {$($of($nc(this->this$1->this$0)->channelDescr()))}));
									}
									this->completed = true;
									pauseReadEvent();
									current->signalCompletion();
									if ($nc($nc(this->this$1->this$0)->debug)->on()) {
										$nc($nc(this->this$1->this$0)->debug)->log("Stopping read scheduler"_s);
									}
									$nc(this->readScheduler)->stop();
								}
								$nc(this->this$1->this$0)->debugState("leaving read() loop after EOF: "_s);
								return;
							} else if ($Utils::remaining(bytes) > 0) {
								if ($nc($nc(this->this$1->this$0)->debug)->on()) {
									$nc($nc(this->this$1->this$0)->debug)->log($$str({"read bytes: "_s, $$str($Utils::remaining(bytes))}));
								}
								if (!SocketTube$InternalReadPublisher$InternalReadSubscription::$assertionsDisabled && ! !current->completed) {
									$throwNew($AssertionError);
								}
								$nc(subscriber)->onNext(bytes);
								resumeReadEvent();
								if ($nc($nc(this->this$1->this$0)->errorRef)->get() != nullptr) {
									continue;
								}
								$nc(this->this$1->this$0)->debugState("leaving read() loop after onNext: "_s);
								return;
							} else {
								if ($nc($nc(this->this$1->this$0)->debug)->on()) {
									$nc($nc(this->this$1->this$0)->debug)->log("no more bytes available"_s);
								}
								$nc(this->demand)->increase(1);
								resumeReadEvent();
								if ($nc($nc(this->this$1->this$0)->errorRef)->get() != nullptr) {
									continue;
								}
								$nc(this->this$1->this$0)->debugState("leaving read() loop with no bytes"_s);
								return;
							}
						} catch ($Throwable& x) {
							signalError(x);
							continue;
						}
					} else {
						if ($nc($nc(this->this$1->this$0)->debug)->on()) {
							$nc($nc(this->this$1->this$0)->debug)->log("no more demand for reading"_s);
						}
						if ($nc($nc(this->this$1->this$0)->errorRef)->get() != nullptr) {
							continue;
						}
						$nc(this->this$1->this$0)->debugState("leaving read() loop with no demand"_s);
						break;
					}
				}
			} catch ($Throwable& t) {
				if ($nc($nc(this->this$1->this$0)->debug)->on()) {
					$nc($nc(this->this$1->this$0)->debug)->log("Unexpected exception in read loop"_s, t);
				}
				signalError(t);
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			if ($nc(this->readScheduler)->isStopped()) {
				if ($nc($nc(this->this$1->this$0)->debug)->on()) {
					$nc($nc(this->this$1->this$0)->debug)->log("Read scheduler stopped"_s);
				}
				if ($Log::channel()) {
					$Log::logChannel("Stopped reading from channel {0}"_s, $$new($ObjectArray, {$($of($nc(this->this$1->this$0)->channelDescr()))}));
				}
			}
			handlePending();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

bool SocketTube$InternalReadPublisher$InternalReadSubscription::handlePending() {
	$useLocalCurrentObjectStackCache();
	$var($SocketTube$InternalReadPublisher$ReadSubscription, pending, $cast($SocketTube$InternalReadPublisher$ReadSubscription, $nc(this->this$1->pendingSubscription)->getAndSet(nullptr)));
	if (pending == nullptr) {
		return false;
	}
	if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log("handling pending subscription for %s"_s, $$new($ObjectArray, {$of($nc(pending)->subscriber)}));
	}
	$var($SocketTube$InternalReadPublisher$ReadSubscription, current, this->this$1->subscription);
	if (current != nullptr && current != pending && !this->completed) {
		$nc(current->subscriber)->dropSubscription();
	}
	if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log("read demand reset to 0"_s);
	}
	$nc($nc(this->this$1->subscriptionImpl)->demand)->reset();
	$nc($nc(pending)->errorRef)->compareAndSet(nullptr, $cast($Throwable, $($nc($nc(this->this$1->this$0)->errorRef)->get())));
	if (!$nc(this->readScheduler)->isStopped()) {
		$set(this->this$1, subscription, pending);
	} else if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log("socket tube is already stopped"_s);
	}
	if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log("calling onSubscribe"_s);
	}
	pending->signalOnSubscribe();
	if (this->completed) {
		$nc(pending->errorRef)->compareAndSet(nullptr, $cast($Throwable, $($nc($nc(this->this$1->this$0)->errorRef)->get())));
		pending->signalCompletion();
	}
	return true;
}

void clinit$SocketTube$InternalReadPublisher$InternalReadSubscription($Class* class$) {
	$load($SocketTube);
	SocketTube$InternalReadPublisher$InternalReadSubscription::$assertionsDisabled = !$SocketTube::class$->desiredAssertionStatus();
}

SocketTube$InternalReadPublisher$InternalReadSubscription::SocketTube$InternalReadPublisher$InternalReadSubscription() {
}

$Class* SocketTube$InternalReadPublisher$InternalReadSubscription::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read::classInfo$.name)) {
			return SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$read::load$(name, initialize);
		}
		if (name->equals(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1::classInfo$.name)) {
			return SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$signalError$1::load$(name, initialize);
		}
		if (name->equals(SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2::classInfo$.name)) {
			return SocketTube$InternalReadPublisher$InternalReadSubscription$$Lambda$handleSubscribeEvent$2::load$(name, initialize);
		}
	}
	$loadClass(SocketTube$InternalReadPublisher$InternalReadSubscription, name, initialize, &_SocketTube$InternalReadPublisher$InternalReadSubscription_ClassInfo_, clinit$SocketTube$InternalReadPublisher$InternalReadSubscription, allocate$SocketTube$InternalReadPublisher$InternalReadSubscription);
	return class$;
}

$Class* SocketTube$InternalReadPublisher$InternalReadSubscription::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk