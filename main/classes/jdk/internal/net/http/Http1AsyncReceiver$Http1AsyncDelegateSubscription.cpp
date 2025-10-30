#include <jdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegateSubscription.h>

#include <java/lang/Runnable.h>
#include <java/util/function/Consumer.h>
#include <jdk/internal/net/http/AbstractSubscription.h>
#include <jdk/internal/net/http/Http1AsyncReceiver.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Consumer = ::java::util::function::Consumer;
using $AbstractSubscription = ::jdk::internal::net::http::AbstractSubscription;
using $Http1AsyncReceiver = ::jdk::internal::net::http::Http1AsyncReceiver;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Http1AsyncReceiver$Http1AsyncDelegateSubscription_FieldInfo_[] = {
	{"onCancel", "Ljava/lang/Runnable;", nullptr, $PRIVATE | $FINAL, $field(Http1AsyncReceiver$Http1AsyncDelegateSubscription, onCancel)},
	{"onError", "Ljava/util/function/Consumer;", "Ljava/util/function/Consumer<Ljava/lang/Throwable;>;", $PRIVATE | $FINAL, $field(Http1AsyncReceiver$Http1AsyncDelegateSubscription, onError)},
	{"scheduler", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $PRIVATE | $FINAL, $field(Http1AsyncReceiver$Http1AsyncDelegateSubscription, scheduler)},
	{"cancelled", "Z", nullptr, $PRIVATE | $VOLATILE, $field(Http1AsyncReceiver$Http1AsyncDelegateSubscription, cancelled)},
	{}
};

$MethodInfo _Http1AsyncReceiver$Http1AsyncDelegateSubscription_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/SequentialScheduler;Ljava/lang/Runnable;Ljava/util/function/Consumer;)V", "(Ljdk/internal/net/http/common/SequentialScheduler;Ljava/lang/Runnable;Ljava/util/function/Consumer<Ljava/lang/Throwable;>;)V", 0, $method(static_cast<void(Http1AsyncReceiver$Http1AsyncDelegateSubscription::*)($SequentialScheduler*,$Runnable*,$Consumer*)>(&Http1AsyncReceiver$Http1AsyncDelegateSubscription::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"request", "(J)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Http1AsyncReceiver$Http1AsyncDelegateSubscription_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1AsyncReceiver$Http1AsyncDelegateSubscription", "jdk.internal.net.http.Http1AsyncReceiver", "Http1AsyncDelegateSubscription", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _Http1AsyncReceiver$Http1AsyncDelegateSubscription_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Http1AsyncReceiver$Http1AsyncDelegateSubscription",
	"jdk.internal.net.http.AbstractSubscription",
	nullptr,
	_Http1AsyncReceiver$Http1AsyncDelegateSubscription_FieldInfo_,
	_Http1AsyncReceiver$Http1AsyncDelegateSubscription_MethodInfo_,
	nullptr,
	nullptr,
	_Http1AsyncReceiver$Http1AsyncDelegateSubscription_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1AsyncReceiver"
};

$Object* allocate$Http1AsyncReceiver$Http1AsyncDelegateSubscription($Class* clazz) {
	return $of($alloc(Http1AsyncReceiver$Http1AsyncDelegateSubscription));
}

void Http1AsyncReceiver$Http1AsyncDelegateSubscription::init$($SequentialScheduler* scheduler, $Runnable* onCancel, $Consumer* onError) {
	$AbstractSubscription::init$();
	$set(this, scheduler, scheduler);
	$set(this, onCancel, onCancel);
	$set(this, onError, onError);
}

void Http1AsyncReceiver$Http1AsyncDelegateSubscription::request(int64_t n) {
	if (this->cancelled) {
		return;
	}
	try {
		$var($Demand, demand, this->demand());
		if ($nc(demand)->increase(n)) {
			$nc(this->scheduler)->runOrSchedule();
		}
	} catch ($IllegalArgumentException& x) {
		this->cancelled = true;
		$nc(this->onError)->accept(x);
	}
}

void Http1AsyncReceiver$Http1AsyncDelegateSubscription::cancel() {
	this->cancelled = true;
	$nc(this->onCancel)->run();
}

Http1AsyncReceiver$Http1AsyncDelegateSubscription::Http1AsyncReceiver$Http1AsyncDelegateSubscription() {
}

$Class* Http1AsyncReceiver$Http1AsyncDelegateSubscription::load$($String* name, bool initialize) {
	$loadClass(Http1AsyncReceiver$Http1AsyncDelegateSubscription, name, initialize, &_Http1AsyncReceiver$Http1AsyncDelegateSubscription_ClassInfo_, allocate$Http1AsyncReceiver$Http1AsyncDelegateSubscription);
	return class$;
}

$Class* Http1AsyncReceiver$Http1AsyncDelegateSubscription::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk