#include <jdk/internal/net/http/PullPublisher$Subscription.h>

#include <java/util/Iterator.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <jdk/internal/net/http/PullPublisher$Subscription$PullTask.h>
#include <jdk/internal/net/http/PullPublisher.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler$RestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Iterator = ::java::util::Iterator;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $PullPublisher = ::jdk::internal::net::http::PullPublisher;
using $PullPublisher$Subscription$PullTask = ::jdk::internal::net::http::PullPublisher$Subscription$PullTask;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SequentialScheduler$CompleteRestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask;
using $SequentialScheduler$RestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$RestartableTask;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _PullPublisher$Subscription_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/PullPublisher;", nullptr, $FINAL | $SYNTHETIC, $field(PullPublisher$Subscription, this$0)},
	{"subscriber", "Ljava/util/concurrent/Flow$Subscriber;", "Ljava/util/concurrent/Flow$Subscriber<-TT;>;", $PRIVATE | $FINAL, $field(PullPublisher$Subscription, subscriber)},
	{"iter", "Ljava/util/Iterator;", "Ljava/util/Iterator<TT;>;", $PRIVATE | $FINAL, $field(PullPublisher$Subscription, iter)},
	{"completed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(PullPublisher$Subscription, completed)},
	{"cancelled", "Z", nullptr, $PRIVATE | $VOLATILE, $field(PullPublisher$Subscription, cancelled)},
	{"error", "Ljava/lang/Throwable;", nullptr, $PRIVATE | $VOLATILE, $field(PullPublisher$Subscription, error)},
	{"pullScheduler", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $FINAL, $field(PullPublisher$Subscription, pullScheduler)},
	{"demand", "Ljdk/internal/net/http/common/Demand;", nullptr, $PRIVATE | $FINAL, $field(PullPublisher$Subscription, demand)},
	{}
};

$MethodInfo _PullPublisher$Subscription_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/PullPublisher;Ljava/util/concurrent/Flow$Subscriber;Ljava/util/Iterator;Ljava/lang/Throwable;)V", "(Ljava/util/concurrent/Flow$Subscriber<-TT;>;Ljava/util/Iterator<TT;>;Ljava/lang/Throwable;)V", 0, $method(static_cast<void(PullPublisher$Subscription::*)($PullPublisher*,$Flow$Subscriber*,$Iterator*,$Throwable*)>(&PullPublisher$Subscription::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"request", "(J)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _PullPublisher$Subscription_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.PullPublisher$Subscription", "jdk.internal.net.http.PullPublisher", "Subscription", $PRIVATE},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.PullPublisher$Subscription$PullTask", "jdk.internal.net.http.PullPublisher$Subscription", "PullTask", $FINAL},
	{}
};

$ClassInfo _PullPublisher$Subscription_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.PullPublisher$Subscription",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription",
	_PullPublisher$Subscription_FieldInfo_,
	_PullPublisher$Subscription_MethodInfo_,
	nullptr,
	nullptr,
	_PullPublisher$Subscription_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.PullPublisher"
};

$Object* allocate$PullPublisher$Subscription($Class* clazz) {
	return $of($alloc(PullPublisher$Subscription));
}

void PullPublisher$Subscription::init$($PullPublisher* this$0, $Flow$Subscriber* subscriber, $Iterator* iter, $Throwable* throwable) {
	$set(this, this$0, this$0);
	$set(this, pullScheduler, $new($SequentialScheduler, $$new($PullPublisher$Subscription$PullTask, this)));
	$set(this, demand, $new($Demand));
	$set(this, subscriber, subscriber);
	$set(this, iter, iter);
	$set(this, error, throwable);
}

void PullPublisher$Subscription::request(int64_t n) {
	$useLocalCurrentObjectStackCache();
	if (this->cancelled) {
		return;
	}
	if (n <= 0) {
		$set(this, error, $new($IllegalArgumentException, $$str({"non-positive subscription request: "_s, $$str(n)})));
	} else {
		$nc(this->demand)->increase(n);
	}
	$nc(this->pullScheduler)->runOrSchedule();
}

void PullPublisher$Subscription::cancel() {
	this->cancelled = true;
}

PullPublisher$Subscription::PullPublisher$Subscription() {
}

$Class* PullPublisher$Subscription::load$($String* name, bool initialize) {
	$loadClass(PullPublisher$Subscription, name, initialize, &_PullPublisher$Subscription_ClassInfo_, allocate$PullPublisher$Subscription);
	return class$;
}

$Class* PullPublisher$Subscription::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk