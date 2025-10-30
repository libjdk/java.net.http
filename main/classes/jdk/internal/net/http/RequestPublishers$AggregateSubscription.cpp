#include <jdk/internal/net/http/RequestPublishers$AggregateSubscription.h>

#include <java/io/Serializable.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/http/HttpRequest$BodyPublisher.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/AbstractQueue.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <java/util/Queue.h>
#include <java/util/concurrent/ConcurrentLinkedQueue.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <jdk/internal/net/http/RequestPublishers.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
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
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AbstractQueue = ::java::util::AbstractQueue;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $Queue = ::java::util::Queue;
using $ConcurrentLinkedQueue = ::java::util::concurrent::ConcurrentLinkedQueue;
using $Flow$Publisher = ::java::util::concurrent::Flow$Publisher;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $RequestPublishers = ::jdk::internal::net::http::RequestPublishers;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class RequestPublishers$AggregateSubscription$$Lambda$run : public $Runnable {
	$class(RequestPublishers$AggregateSubscription$$Lambda$run, $NO_CLASS_INIT, $Runnable)
public:
	void init$(RequestPublishers$AggregateSubscription* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->run();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RequestPublishers$AggregateSubscription$$Lambda$run>());
	}
	RequestPublishers$AggregateSubscription* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo RequestPublishers$AggregateSubscription$$Lambda$run::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(RequestPublishers$AggregateSubscription$$Lambda$run, inst$)},
	{}
};
$MethodInfo RequestPublishers$AggregateSubscription$$Lambda$run::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/RequestPublishers$AggregateSubscription;)V", nullptr, $PUBLIC, $method(static_cast<void(RequestPublishers$AggregateSubscription$$Lambda$run::*)(RequestPublishers$AggregateSubscription*)>(&RequestPublishers$AggregateSubscription$$Lambda$run::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo RequestPublishers$AggregateSubscription$$Lambda$run::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.RequestPublishers$AggregateSubscription$$Lambda$run",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* RequestPublishers$AggregateSubscription$$Lambda$run::load$($String* name, bool initialize) {
	$loadClass(RequestPublishers$AggregateSubscription$$Lambda$run, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RequestPublishers$AggregateSubscription$$Lambda$run::class$ = nullptr;

$FieldInfo _RequestPublishers$AggregateSubscription_FieldInfo_[] = {
	{"subscriber", "Ljava/util/concurrent/Flow$Subscriber;", "Ljava/util/concurrent/Flow$Subscriber<-Ljava/nio/ByteBuffer;>;", $FINAL, $field(RequestPublishers$AggregateSubscription, subscriber)},
	{"bodies", "Ljava/util/Queue;", "Ljava/util/Queue<Ljava/net/http/HttpRequest$BodyPublisher;>;", $FINAL, $field(RequestPublishers$AggregateSubscription, bodies)},
	{"scheduler", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $FINAL, $field(RequestPublishers$AggregateSubscription, scheduler)},
	{"demand", "Ljdk/internal/net/http/common/Demand;", nullptr, $FINAL, $field(RequestPublishers$AggregateSubscription, demand)},
	{"demanded", "Ljdk/internal/net/http/common/Demand;", nullptr, $FINAL, $field(RequestPublishers$AggregateSubscription, demanded)},
	{"error", "Ljava/util/concurrent/atomic/AtomicReference;", "Ljava/util/concurrent/atomic/AtomicReference<Ljava/lang/Throwable;>;", $FINAL, $field(RequestPublishers$AggregateSubscription, error)},
	{"illegalRequest", "Ljava/lang/Throwable;", nullptr, $VOLATILE, $field(RequestPublishers$AggregateSubscription, illegalRequest)},
	{"publisher", "Ljava/net/http/HttpRequest$BodyPublisher;", nullptr, $VOLATILE, $field(RequestPublishers$AggregateSubscription, publisher)},
	{"subscription", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $VOLATILE, $field(RequestPublishers$AggregateSubscription, subscription)},
	{"cancelled", "Z", nullptr, $VOLATILE, $field(RequestPublishers$AggregateSubscription, cancelled)},
	{}
};

$MethodInfo _RequestPublishers$AggregateSubscription_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/List;Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/List<Ljava/net/http/HttpRequest$BodyPublisher;>;Ljava/util/concurrent/Flow$Subscriber<-Ljava/nio/ByteBuffer;>;)V", 0, $method(static_cast<void(RequestPublishers$AggregateSubscription::*)($List*,$Flow$Subscriber*)>(&RequestPublishers$AggregateSubscription::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"cancelSubscription", "()Z", nullptr, $PRIVATE, $method(static_cast<bool(RequestPublishers$AggregateSubscription::*)()>(&RequestPublishers$AggregateSubscription::cancelSubscription))},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $method(static_cast<void(RequestPublishers$AggregateSubscription::*)($ByteBuffer*)>(&RequestPublishers$AggregateSubscription::onNext))},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{"request", "(J)V", nullptr, $PUBLIC},
	{"run", "()V", nullptr, $PUBLIC, $method(static_cast<void(RequestPublishers$AggregateSubscription::*)()>(&RequestPublishers$AggregateSubscription::run))},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _RequestPublishers$AggregateSubscription_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RequestPublishers$AggregateSubscription", "jdk.internal.net.http.RequestPublishers", "AggregateSubscription", $PRIVATE | $STATIC | $FINAL},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.Flow$Subscriber", "java.util.concurrent.Flow", "Subscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RequestPublishers$AggregateSubscription_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.RequestPublishers$AggregateSubscription",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription,java.util.concurrent.Flow$Subscriber",
	_RequestPublishers$AggregateSubscription_FieldInfo_,
	_RequestPublishers$AggregateSubscription_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/concurrent/Flow$Subscription;Ljava/util/concurrent/Flow$Subscriber<Ljava/nio/ByteBuffer;>;",
	nullptr,
	_RequestPublishers$AggregateSubscription_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RequestPublishers"
};

$Object* allocate$RequestPublishers$AggregateSubscription($Class* clazz) {
	return $of($alloc(RequestPublishers$AggregateSubscription));
}

int32_t RequestPublishers$AggregateSubscription::hashCode() {
	 return this->$Flow$Subscription::hashCode();
}

bool RequestPublishers$AggregateSubscription::equals(Object$* arg0) {
	 return this->$Flow$Subscription::equals(arg0);
}

$Object* RequestPublishers$AggregateSubscription::clone() {
	 return this->$Flow$Subscription::clone();
}

$String* RequestPublishers$AggregateSubscription::toString() {
	 return this->$Flow$Subscription::toString();
}

void RequestPublishers$AggregateSubscription::finalize() {
	this->$Flow$Subscription::finalize();
}

void RequestPublishers$AggregateSubscription::init$($List* bodies, $Flow$Subscriber* subscriber) {
	$set(this, demand, $new($Demand));
	$set(this, demanded, $new($Demand));
	$set(this, error, $new($AtomicReference));
	$set(this, bodies, $new($ConcurrentLinkedQueue, bodies));
	$set(this, subscriber, subscriber);
	$set(this, scheduler, $SequentialScheduler::lockingScheduler(static_cast<$Runnable*>($$new(RequestPublishers$AggregateSubscription$$Lambda$run, this))));
}

void RequestPublishers$AggregateSubscription::request(int64_t n) {
	if (this->cancelled || this->publisher == nullptr && $nc(this->bodies)->isEmpty()) {
		return;
	}
	try {
		$nc(this->demand)->increase(n);
	} catch ($IllegalArgumentException& x) {
		$set(this, illegalRequest, x);
	}
	$nc(this->scheduler)->runOrSchedule();
}

void RequestPublishers$AggregateSubscription::cancel() {
	this->cancelled = true;
	$nc(this->scheduler)->runOrSchedule();
}

bool RequestPublishers$AggregateSubscription::cancelSubscription() {
	$var($Flow$Subscription, subscription, this->subscription);
	if (subscription != nullptr) {
		$set(this, subscription, nullptr);
		$set(this, publisher, nullptr);
		subscription->cancel();
	}
	$nc(this->scheduler)->stop();
	return subscription != nullptr;
}

void RequestPublishers$AggregateSubscription::run() {
	$useLocalCurrentObjectStackCache();
	try {
		while (true) {
			bool var$0 = $nc(this->error)->get() == nullptr;
			if (var$0) {
				bool var$1 = !$nc(this->demand)->isFulfilled();
				var$0 = (var$1 || (this->publisher == nullptr && !$nc(this->bodies)->isEmpty()));
			}
			if (!(var$0)) {
				break;
			}
			{
				bool cancelled = this->cancelled;
				$var($HttpRequest$BodyPublisher, publisher, this->publisher);
				$var($Flow$Subscription, subscription, this->subscription);
				$var($Throwable, illegalRequest, this->illegalRequest);
				if (cancelled) {
					$nc(this->bodies)->clear();
					cancelSubscription();
					return;
				}
				if (publisher == nullptr && !$nc(this->bodies)->isEmpty()) {
					$set(this, publisher, ($assign(publisher, $cast($HttpRequest$BodyPublisher, $nc(this->bodies)->poll()))));
					$nc(publisher)->subscribe(this);
					$assign(subscription, this->subscription);
				} else if (publisher == nullptr) {
					return;
				}
				if (illegalRequest != nullptr) {
					onError(illegalRequest);
					return;
				}
				if (subscription == nullptr) {
					return;
				}
				if (!$nc(this->demand)->isFulfilled()) {
					int64_t n = $nc(this->demand)->decreaseAndGet($nc(this->demand)->get());
					$nc(this->demanded)->increase(n);
					$nc(subscription)->request(n);
				}
			}
		}
	} catch ($Throwable& t) {
		onError(t);
	}
}

void RequestPublishers$AggregateSubscription::onSubscribe($Flow$Subscription* subscription) {
	$set(this, subscription, subscription);
	$nc(this->scheduler)->runOrSchedule();
}

void RequestPublishers$AggregateSubscription::onNext($ByteBuffer* item) {
	if (this->cancelled || $nc(this->error)->get() != nullptr) {
		cancelSubscription();
		return;
	}
	$nc(this->demanded)->tryDecrement();
	$nc(this->subscriber)->onNext(item);
}

void RequestPublishers$AggregateSubscription::onError($Throwable* throwable) {
	if ($nc(this->error)->compareAndSet(nullptr, throwable)) {
		$set(this, publisher, nullptr);
		$set(this, subscription, nullptr);
		$nc(this->subscriber)->onError(throwable);
		$nc(this->scheduler)->stop();
	}
}

void RequestPublishers$AggregateSubscription::onComplete() {
	if (this->publisher != nullptr && !$nc(this->bodies)->isEmpty()) {
		while (!$nc(this->demanded)->isFulfilled()) {
			$nc(this->demand)->increase($nc(this->demanded)->decreaseAndGet($nc(this->demanded)->get()));
		}
		$set(this, publisher, nullptr);
		$set(this, subscription, nullptr);
		$nc(this->scheduler)->runOrSchedule();
	} else {
		$set(this, publisher, nullptr);
		$set(this, subscription, nullptr);
		if (!this->cancelled) {
			$nc(this->subscriber)->onComplete();
		}
		$nc(this->scheduler)->stop();
	}
}

void RequestPublishers$AggregateSubscription::onNext(Object$* item) {
	this->onNext($cast($ByteBuffer, item));
}

RequestPublishers$AggregateSubscription::RequestPublishers$AggregateSubscription() {
}

$Class* RequestPublishers$AggregateSubscription::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RequestPublishers$AggregateSubscription$$Lambda$run::classInfo$.name)) {
			return RequestPublishers$AggregateSubscription$$Lambda$run::load$(name, initialize);
		}
	}
	$loadClass(RequestPublishers$AggregateSubscription, name, initialize, &_RequestPublishers$AggregateSubscription_ClassInfo_, allocate$RequestPublishers$AggregateSubscription);
	return class$;
}

$Class* RequestPublishers$AggregateSubscription::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk