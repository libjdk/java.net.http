#include <jdk/internal/net/http/PullPublisher$Subscription$PullTask.h>

#include <java/util/Iterator.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <jdk/internal/net/http/PullPublisher$Subscription.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Iterator = ::java::util::Iterator;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $PullPublisher$Subscription = ::jdk::internal::net::http::PullPublisher$Subscription;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SequentialScheduler$CompleteRestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _PullPublisher$Subscription$PullTask_FieldInfo_[] = {
	{"this$1", "Ljdk/internal/net/http/PullPublisher$Subscription;", nullptr, $FINAL | $SYNTHETIC, $field(PullPublisher$Subscription$PullTask, this$1)},
	{}
};

$MethodInfo _PullPublisher$Subscription$PullTask_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/PullPublisher$Subscription;)V", nullptr, 0, $method(static_cast<void(PullPublisher$Subscription$PullTask::*)($PullPublisher$Subscription*)>(&PullPublisher$Subscription$PullTask::init$))},
	{"run", "()V", nullptr, $PROTECTED},
	{}
};

$InnerClassInfo _PullPublisher$Subscription$PullTask_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.PullPublisher$Subscription", "jdk.internal.net.http.PullPublisher", "Subscription", $PRIVATE},
	{"jdk.internal.net.http.PullPublisher$Subscription$PullTask", "jdk.internal.net.http.PullPublisher$Subscription", "PullTask", $FINAL},
	{"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "CompleteRestartableTask", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _PullPublisher$Subscription$PullTask_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.PullPublisher$Subscription$PullTask",
	"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask",
	nullptr,
	_PullPublisher$Subscription$PullTask_FieldInfo_,
	_PullPublisher$Subscription$PullTask_MethodInfo_,
	nullptr,
	nullptr,
	_PullPublisher$Subscription$PullTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.PullPublisher"
};

$Object* allocate$PullPublisher$Subscription$PullTask($Class* clazz) {
	return $of($alloc(PullPublisher$Subscription$PullTask));
}

void PullPublisher$Subscription$PullTask::init$($PullPublisher$Subscription* this$1) {
	$set(this, this$1, this$1);
	$SequentialScheduler$CompleteRestartableTask::init$();
}

void PullPublisher$Subscription$PullTask::run() {
	$useLocalCurrentObjectStackCache();
	if (this->this$1->completed || this->this$1->cancelled) {
		return;
	}
	$var($Throwable, t, this->this$1->error);
	if (t != nullptr) {
		this->this$1->completed = true;
		$nc(this->this$1->pullScheduler)->stop();
		$nc(this->this$1->subscriber)->onError(t);
		return;
	}
	while ($nc(this->this$1->demand)->tryDecrement() && !this->this$1->cancelled) {
		$var($Object, next, nullptr);
		try {
			if (!$nc(this->this$1->iter)->hasNext()) {
				break;
			}
			$assign(next, $nc(this->this$1->iter)->next());
		} catch ($Throwable& t1) {
			this->this$1->completed = true;
			$nc(this->this$1->pullScheduler)->stop();
			$nc(this->this$1->subscriber)->onError(t1);
			return;
		}
		$nc(this->this$1->subscriber)->onNext(next);
	}
	if (!$nc(this->this$1->iter)->hasNext() && !this->this$1->cancelled) {
		this->this$1->completed = true;
		$nc(this->this$1->pullScheduler)->stop();
		$nc(this->this$1->subscriber)->onComplete();
	}
}

PullPublisher$Subscription$PullTask::PullPublisher$Subscription$PullTask() {
}

$Class* PullPublisher$Subscription$PullTask::load$($String* name, bool initialize) {
	$loadClass(PullPublisher$Subscription$PullTask, name, initialize, &_PullPublisher$Subscription$PullTask_ClassInfo_, allocate$PullPublisher$Subscription$PullTask);
	return class$;
}

$Class* PullPublisher$Subscription$PullTask::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk