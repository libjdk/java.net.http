#include <jdk/internal/net/http/common/SubscriberWrapper$DownstreamPusher.h>

#include <java/lang/InternalError.h>
#include <java/util/List.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/ConcurrentLinkedQueue.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/SubscriberWrapper$1.h>
#include <jdk/internal/net/http/common/SubscriberWrapper$SchedulingAction.h>
#include <jdk/internal/net/http/common/SubscriberWrapper.h>
#include <jdk/internal/net/http/common/SubscriptionBase.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $List = ::java::util::List;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $ConcurrentLinkedQueue = ::java::util::concurrent::ConcurrentLinkedQueue;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SubscriberWrapper = ::jdk::internal::net::http::common::SubscriberWrapper;
using $SubscriberWrapper$1 = ::jdk::internal::net::http::common::SubscriberWrapper$1;
using $SubscriberWrapper$SchedulingAction = ::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction;
using $SubscriptionBase = ::jdk::internal::net::http::common::SubscriptionBase;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SubscriberWrapper$DownstreamPusher_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/common/SubscriberWrapper;", nullptr, $FINAL | $SYNTHETIC, $field(SubscriberWrapper$DownstreamPusher, this$0)},
	{}
};

$MethodInfo _SubscriberWrapper$DownstreamPusher_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/SubscriberWrapper;)V", nullptr, 0, $method(static_cast<void(SubscriberWrapper$DownstreamPusher::*)($SubscriberWrapper*)>(&SubscriberWrapper$DownstreamPusher::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{"run1", "()V", nullptr, $PRIVATE, $method(static_cast<void(SubscriberWrapper$DownstreamPusher::*)()>(&SubscriberWrapper$DownstreamPusher::run1))},
	{}
};

$InnerClassInfo _SubscriberWrapper$DownstreamPusher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SubscriberWrapper$DownstreamPusher", "jdk.internal.net.http.common.SubscriberWrapper", "DownstreamPusher", 0},
	{}
};

$ClassInfo _SubscriberWrapper$DownstreamPusher_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.common.SubscriberWrapper$DownstreamPusher",
	"java.lang.Object",
	"java.lang.Runnable",
	_SubscriberWrapper$DownstreamPusher_FieldInfo_,
	_SubscriberWrapper$DownstreamPusher_MethodInfo_,
	nullptr,
	nullptr,
	_SubscriberWrapper$DownstreamPusher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SubscriberWrapper"
};

$Object* allocate$SubscriberWrapper$DownstreamPusher($Class* clazz) {
	return $of($alloc(SubscriberWrapper$DownstreamPusher));
}

void SubscriberWrapper$DownstreamPusher::init$($SubscriberWrapper* this$0) {
	$set(this, this$0, this$0);
}

void SubscriberWrapper$DownstreamPusher::run() {
	try {
		run1();
	} catch ($Throwable& t) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log($$str({"DownstreamPusher threw: "_s, t}));
		}
		this->this$0->errorCommon(t);
	}
}

void SubscriberWrapper$DownstreamPusher::run1() {
	$useLocalCurrentObjectStackCache();
	if (this->this$0->downstreamCompleted) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("DownstreamPusher: downstream is already completed"_s);
		}
		return;
	}
	$init($SubscriberWrapper$1);
	switch ($nc($SubscriberWrapper$1::$SwitchMap$jdk$internal$net$http$common$SubscriberWrapper$SchedulingAction)->get($nc(($(this->this$0->enterScheduling())))->ordinal())) {
	case 1:
		{
			break;
		}
	case 2:
		{
			$nc(this->this$0->pushScheduler)->runOrSchedule();
			return;
		}
	case 3:
		{
			return;
		}
	default:
		{
			$nc(this->this$0->errorRef)->compareAndSet(nullptr, $$new($InternalError, "unknown scheduling command"_s));
			break;
		}
	}
	$var($Throwable, error, $cast($Throwable, $nc(this->this$0->errorRef)->get()));
	if (error != nullptr && $nc(this->this$0->outputQ)->isEmpty()) {
		$synchronized(this) {
			if (this->this$0->downstreamCompleted) {
				return;
			}
			this->this$0->downstreamCompleted = true;
		}
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log($$str({"DownstreamPusher: forwarding error downstream: "_s, error}));
		}
		$nc(this->this$0->pushScheduler)->stop();
		$nc(this->this$0->outputQ)->clear();
		$nc(this->this$0->downstreamSubscriber)->onError(error);
		$nc(this->this$0->cf)->completeExceptionally(error);
		return;
	}
	if (!$nc(this->this$0->outputQ)->isEmpty()) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("DownstreamPusher: queue not empty, downstreamSubscription: %s"_s, $$new($ObjectArray, {$of(this->this$0->downstreamSubscription)}));
		}
	} else if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("DownstreamPusher: queue empty, downstreamSubscription: %s"_s, $$new($ObjectArray, {$of(this->this$0->downstreamSubscription)}));
	}
	bool datasent = false;
	while (true) {
		bool var$0 = !$nc(this->this$0->outputQ)->isEmpty();
		if (!(var$0 && $nc(this->this$0->downstreamSubscription)->tryDecrement())) {
			break;
		}
		{
			$var($List, b, $cast($List, $nc(this->this$0->outputQ)->poll()));
			if ($nc(this->this$0->debug)->on()) {
				$nc(this->this$0->debug)->log("DownstreamPusher: Pushing %d bytes downstream"_s, $$new($ObjectArray, {$($of($Long::valueOf($Utils::remaining(b))))}));
			}
			$nc(this->this$0->downstreamSubscriber)->onNext(b);
			datasent = true;
		}
	}
	bool var$1 = datasent;
	if (!var$1) {
		bool var$3 = $nc(this->this$0->outputQ)->isEmpty();
		bool var$2 = var$3 && !$nc($nc(this->this$0->downstreamSubscription)->demand)->isFulfilled() && !this->this$0->upstreamCompleted;
		var$1 = var$2 && $nc(this->this$0->upstreamWindow$)->get() == 0;
	}
	if (var$1) {
		this->this$0->upstreamWindowUpdate();
	}
	this->this$0->checkCompletion();
}

SubscriberWrapper$DownstreamPusher::SubscriberWrapper$DownstreamPusher() {
}

$Class* SubscriberWrapper$DownstreamPusher::load$($String* name, bool initialize) {
	$loadClass(SubscriberWrapper$DownstreamPusher, name, initialize, &_SubscriberWrapper$DownstreamPusher_ClassInfo_, allocate$SubscriberWrapper$DownstreamPusher);
	return class$;
}

$Class* SubscriberWrapper$DownstreamPusher::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk