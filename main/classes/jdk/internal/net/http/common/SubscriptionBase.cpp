#include <jdk/internal/net/http/common/SubscriptionBase.h>

#include <java/lang/Runnable.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/function/Consumer.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Runnable = ::java::lang::Runnable;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $Consumer = ::java::util::function::Consumer;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SubscriptionBase_FieldInfo_[] = {
	{"demand", "Ljdk/internal/net/http/common/Demand;", nullptr, $FINAL, $field(SubscriptionBase, demand)},
	{"scheduler", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $FINAL, $field(SubscriptionBase, scheduler)},
	{"cancelAction", "Ljava/lang/Runnable;", nullptr, $FINAL, $field(SubscriptionBase, cancelAction)},
	{"cancelled", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $FINAL, $field(SubscriptionBase, cancelled)},
	{"onError", "Ljava/util/function/Consumer;", "Ljava/util/function/Consumer<Ljava/lang/Throwable;>;", $FINAL, $field(SubscriptionBase, onError)},
	{}
};

$MethodInfo _SubscriptionBase_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/SequentialScheduler;Ljava/lang/Runnable;)V", nullptr, $PUBLIC, $method(static_cast<void(SubscriptionBase::*)($SequentialScheduler*,$Runnable*)>(&SubscriptionBase::init$))},
	{"<init>", "(Ljdk/internal/net/http/common/SequentialScheduler;Ljava/lang/Runnable;Ljava/util/function/Consumer;)V", "(Ljdk/internal/net/http/common/SequentialScheduler;Ljava/lang/Runnable;Ljava/util/function/Consumer<Ljava/lang/Throwable;>;)V", $PUBLIC, $method(static_cast<void(SubscriptionBase::*)($SequentialScheduler*,$Runnable*,$Consumer*)>(&SubscriptionBase::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"request", "(J)V", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"tryDecrement", "()Z", nullptr, $PUBLIC},
	{"window", "()J", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SubscriptionBase_InnerClassesInfo_[] = {
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SubscriptionBase_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.common.SubscriptionBase",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription",
	_SubscriptionBase_FieldInfo_,
	_SubscriptionBase_MethodInfo_,
	nullptr,
	nullptr,
	_SubscriptionBase_InnerClassesInfo_
};

$Object* allocate$SubscriptionBase($Class* clazz) {
	return $of($alloc(SubscriptionBase));
}

void SubscriptionBase::init$($SequentialScheduler* scheduler, $Runnable* cancelAction) {
	SubscriptionBase::init$(scheduler, cancelAction, nullptr);
}

void SubscriptionBase::init$($SequentialScheduler* scheduler, $Runnable* cancelAction, $Consumer* onError) {
	$set(this, demand, $new($Demand));
	$set(this, scheduler, scheduler);
	$set(this, cancelAction, cancelAction);
	$set(this, cancelled, $new($AtomicBoolean, false));
	$set(this, onError, onError);
}

void SubscriptionBase::request(int64_t n) {
	try {
		if ($nc(this->demand)->increase(n)) {
			$nc(this->scheduler)->runOrSchedule();
		}
	} catch ($Throwable& t) {
		if (this->onError != nullptr) {
			if ($nc(this->cancelled)->getAndSet(true)) {
				return;
			}
			$nc(this->onError)->accept(t);
		} else {
			$throw(t);
		}
	}
}

$String* SubscriptionBase::toString() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($String, var$0, $$str({"SubscriptionBase: window = "_s, $$str($nc(this->demand)->get()), " cancelled = "_s}));
		return $concat(var$0, $($nc(this->cancelled)->toString()));
	}
}

bool SubscriptionBase::tryDecrement() {
	return $nc(this->demand)->tryDecrement();
}

int64_t SubscriptionBase::window() {
	return $nc(this->demand)->get();
}

void SubscriptionBase::cancel() {
	if ($nc(this->cancelled)->getAndSet(true)) {
		return;
	}
	$nc(this->scheduler)->stop();
	$nc(this->cancelAction)->run();
}

SubscriptionBase::SubscriptionBase() {
}

$Class* SubscriptionBase::load$($String* name, bool initialize) {
	$loadClass(SubscriptionBase, name, initialize, &_SubscriptionBase_ClassInfo_, allocate$SubscriptionBase);
	return class$;
}

$Class* SubscriptionBase::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk