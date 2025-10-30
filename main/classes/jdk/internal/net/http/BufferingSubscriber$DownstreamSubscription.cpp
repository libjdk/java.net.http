#include <jdk/internal/net/http/BufferingSubscriber$DownstreamSubscription.h>

#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <jdk/internal/net/http/BufferingSubscriber$DownstreamSubscription$PushDemandedTask.h>
#include <jdk/internal/net/http/BufferingSubscriber.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler$RestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $BufferingSubscriber = ::jdk::internal::net::http::BufferingSubscriber;
using $BufferingSubscriber$DownstreamSubscription$PushDemandedTask = ::jdk::internal::net::http::BufferingSubscriber$DownstreamSubscription$PushDemandedTask;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SequentialScheduler$CompleteRestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask;
using $SequentialScheduler$RestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$RestartableTask;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _BufferingSubscriber$DownstreamSubscription_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/BufferingSubscriber;", nullptr, $FINAL | $SYNTHETIC, $field(BufferingSubscriber$DownstreamSubscription, this$0)},
	{"cancelled", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $PRIVATE | $FINAL, $field(BufferingSubscriber$DownstreamSubscription, cancelled)},
	{"demand", "Ljdk/internal/net/http/common/Demand;", nullptr, $PRIVATE | $FINAL, $field(BufferingSubscriber$DownstreamSubscription, demand)},
	{"illegalArg", "Z", nullptr, $PRIVATE | $VOLATILE, $field(BufferingSubscriber$DownstreamSubscription, illegalArg)},
	{"pushDemandedScheduler", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $PRIVATE | $FINAL, $field(BufferingSubscriber$DownstreamSubscription, pushDemandedScheduler)},
	{}
};

$MethodInfo _BufferingSubscriber$DownstreamSubscription_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/BufferingSubscriber;)V", nullptr, $PRIVATE, $method(static_cast<void(BufferingSubscriber$DownstreamSubscription::*)($BufferingSubscriber*)>(&BufferingSubscriber$DownstreamSubscription::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"pushDemanded", "()V", nullptr, 0},
	{"request", "(J)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _BufferingSubscriber$DownstreamSubscription_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.BufferingSubscriber$DownstreamSubscription", "jdk.internal.net.http.BufferingSubscriber", "DownstreamSubscription", $PRIVATE},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.BufferingSubscriber$DownstreamSubscription$PushDemandedTask", "jdk.internal.net.http.BufferingSubscriber$DownstreamSubscription", "PushDemandedTask", 0},
	{}
};

$ClassInfo _BufferingSubscriber$DownstreamSubscription_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.BufferingSubscriber$DownstreamSubscription",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription",
	_BufferingSubscriber$DownstreamSubscription_FieldInfo_,
	_BufferingSubscriber$DownstreamSubscription_MethodInfo_,
	nullptr,
	nullptr,
	_BufferingSubscriber$DownstreamSubscription_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.BufferingSubscriber"
};

$Object* allocate$BufferingSubscriber$DownstreamSubscription($Class* clazz) {
	return $of($alloc(BufferingSubscriber$DownstreamSubscription));
}

void BufferingSubscriber$DownstreamSubscription::init$($BufferingSubscriber* this$0) {
	$set(this, this$0, this$0);
	$set(this, cancelled, $new($AtomicBoolean));
	$set(this, demand, $new($Demand));
	$set(this, pushDemandedScheduler, $new($SequentialScheduler, $$new($BufferingSubscriber$DownstreamSubscription$PushDemandedTask, this)));
}

void BufferingSubscriber$DownstreamSubscription::request(int64_t n) {
	if ($nc(this->cancelled)->get() || this->illegalArg) {
		return;
	}
	if (n <= (int64_t)0) {
		this->illegalArg = true;
		$nc(this->this$0->subscription)->request(n);
		return;
	}
	$nc(this->demand)->increase(n);
	pushDemanded();
}

void BufferingSubscriber$DownstreamSubscription::pushDemanded() {
	if ($nc(this->cancelled)->get()) {
		return;
	}
	$nc(this->pushDemandedScheduler)->runOrSchedule();
}

void BufferingSubscriber$DownstreamSubscription::cancel() {
	if ($nc(this->cancelled)->compareAndExchange(false, true)) {
		return;
	}
	this->this$0->state = 8;
	$nc(this->this$0->subscription)->cancel();
	$nc(this->pushDemandedScheduler)->stop();
}

BufferingSubscriber$DownstreamSubscription::BufferingSubscriber$DownstreamSubscription() {
}

$Class* BufferingSubscriber$DownstreamSubscription::load$($String* name, bool initialize) {
	$loadClass(BufferingSubscriber$DownstreamSubscription, name, initialize, &_BufferingSubscriber$DownstreamSubscription_ClassInfo_, allocate$BufferingSubscriber$DownstreamSubscription);
	return class$;
}

$Class* BufferingSubscriber$DownstreamSubscription::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk