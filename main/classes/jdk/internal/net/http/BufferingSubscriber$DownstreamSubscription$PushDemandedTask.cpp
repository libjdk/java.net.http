#include <jdk/internal/net/http/BufferingSubscriber$DownstreamSubscription$PushDemandedTask.h>

#include <java/lang/AssertionError.h>
#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <jdk/internal/net/http/BufferingSubscriber$DownstreamSubscription.h>
#include <jdk/internal/net/http/BufferingSubscriber.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $BufferingSubscriber = ::jdk::internal::net::http::BufferingSubscriber;
using $BufferingSubscriber$DownstreamSubscription = ::jdk::internal::net::http::BufferingSubscriber$DownstreamSubscription;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SequentialScheduler$CompleteRestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _BufferingSubscriber$DownstreamSubscription$PushDemandedTask_FieldInfo_[] = {
	{"this$1", "Ljdk/internal/net/http/BufferingSubscriber$DownstreamSubscription;", nullptr, $FINAL | $SYNTHETIC, $field(BufferingSubscriber$DownstreamSubscription$PushDemandedTask, this$1)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(BufferingSubscriber$DownstreamSubscription$PushDemandedTask, $assertionsDisabled)},
	{}
};

$MethodInfo _BufferingSubscriber$DownstreamSubscription$PushDemandedTask_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/BufferingSubscriber$DownstreamSubscription;)V", nullptr, 0, $method(static_cast<void(BufferingSubscriber$DownstreamSubscription$PushDemandedTask::*)($BufferingSubscriber$DownstreamSubscription*)>(&BufferingSubscriber$DownstreamSubscription$PushDemandedTask::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _BufferingSubscriber$DownstreamSubscription$PushDemandedTask_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.BufferingSubscriber$DownstreamSubscription", "jdk.internal.net.http.BufferingSubscriber", "DownstreamSubscription", $PRIVATE},
	{"jdk.internal.net.http.BufferingSubscriber$DownstreamSubscription$PushDemandedTask", "jdk.internal.net.http.BufferingSubscriber$DownstreamSubscription", "PushDemandedTask", 0},
	{"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "CompleteRestartableTask", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _BufferingSubscriber$DownstreamSubscription$PushDemandedTask_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.BufferingSubscriber$DownstreamSubscription$PushDemandedTask",
	"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask",
	nullptr,
	_BufferingSubscriber$DownstreamSubscription$PushDemandedTask_FieldInfo_,
	_BufferingSubscriber$DownstreamSubscription$PushDemandedTask_MethodInfo_,
	nullptr,
	nullptr,
	_BufferingSubscriber$DownstreamSubscription$PushDemandedTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.BufferingSubscriber"
};

$Object* allocate$BufferingSubscriber$DownstreamSubscription$PushDemandedTask($Class* clazz) {
	return $of($alloc(BufferingSubscriber$DownstreamSubscription$PushDemandedTask));
}

bool BufferingSubscriber$DownstreamSubscription$PushDemandedTask::$assertionsDisabled = false;

void BufferingSubscriber$DownstreamSubscription$PushDemandedTask::init$($BufferingSubscriber$DownstreamSubscription* this$1) {
	$set(this, this$1, this$1);
	$SequentialScheduler$CompleteRestartableTask::init$();
}

void BufferingSubscriber$DownstreamSubscription$PushDemandedTask::run() {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Throwable, t, $nc(this->this$1->this$0)->throwable);
		if (t != nullptr) {
			$nc(this->this$1->pushDemandedScheduler)->stop();
			$nc($nc(this->this$1->this$0)->downstreamSubscriber)->onError(t);
			return;
		}
		while (true) {
			$var($List, item, nullptr);
			$synchronized($nc(this->this$1->this$0)->buffersLock) {
				if ($nc(this->this$1->cancelled)->get()) {
					return;
				}
				if (!$nc(this->this$1->this$0)->hasEnoughAccumulatedBytes()) {
					break;
				}
				if (!$nc(this->this$1->demand)->tryDecrement()) {
					break;
				}
				$assign(item, $nc(this->this$1->this$0)->fromInternalBuffers());
			}
			if (!BufferingSubscriber$DownstreamSubscription$PushDemandedTask::$assertionsDisabled && !(item != nullptr)) {
				$throwNew($AssertionError);
			}
			$nc($nc(this->this$1->this$0)->downstreamSubscriber)->onNext(item);
		}
		if ($nc(this->this$1->cancelled)->get()) {
			return;
		}
		bool complete = false;
		$synchronized($nc(this->this$1->this$0)->buffersLock) {
			complete = $nc(this->this$1->this$0)->state == 16 && $nc($nc(this->this$1->this$0)->internalBuffers)->isEmpty();
		}
		if (complete) {
			if (!BufferingSubscriber$DownstreamSubscription$PushDemandedTask::$assertionsDisabled && !$nc($nc(this->this$1->this$0)->internalBuffers)->isEmpty()) {
				$throwNew($AssertionError);
			}
			$nc(this->this$1->pushDemandedScheduler)->stop();
			$nc($nc(this->this$1->this$0)->downstreamSubscriber)->onComplete();
			return;
		}
	} catch ($Throwable& t) {
		this->this$1->cancel();
		$throw(t);
	}
	bool requestMore = false;
	$synchronized($nc(this->this$1->this$0)->buffersLock) {
		bool var$0 = !$nc(this->this$1->this$0)->hasEnoughAccumulatedBytes();
		if (var$0 && !$nc(this->this$1->demand)->isFulfilled()) {
			requestMore = true;
		}
	}
	if (requestMore) {
		$nc($nc(this->this$1->this$0)->subscription)->request(1);
	}
}

void clinit$BufferingSubscriber$DownstreamSubscription$PushDemandedTask($Class* class$) {
	$load($BufferingSubscriber);
	BufferingSubscriber$DownstreamSubscription$PushDemandedTask::$assertionsDisabled = !$BufferingSubscriber::class$->desiredAssertionStatus();
}

BufferingSubscriber$DownstreamSubscription$PushDemandedTask::BufferingSubscriber$DownstreamSubscription$PushDemandedTask() {
}

$Class* BufferingSubscriber$DownstreamSubscription$PushDemandedTask::load$($String* name, bool initialize) {
	$loadClass(BufferingSubscriber$DownstreamSubscription$PushDemandedTask, name, initialize, &_BufferingSubscriber$DownstreamSubscription$PushDemandedTask_ClassInfo_, clinit$BufferingSubscriber$DownstreamSubscription$PushDemandedTask, allocate$BufferingSubscriber$DownstreamSubscription$PushDemandedTask);
	return class$;
}

$Class* BufferingSubscriber$DownstreamSubscription$PushDemandedTask::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk