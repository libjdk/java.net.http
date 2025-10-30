#include <jdk/internal/net/http/ResponseSubscribers$SubscriberAdapter.h>

#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/function/Function.h>
#include <jdk/internal/net/http/ResponseSubscribers.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Function = ::java::util::function::Function;
using $ResponseSubscribers = ::jdk::internal::net::http::ResponseSubscribers;
using $ResponseSubscribers$TrustedSubscriber = ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ResponseSubscribers$SubscriberAdapter_FieldInfo_[] = {
	{"cf", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<TR;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$SubscriberAdapter, cf)},
	{"subscriber", "Ljava/util/concurrent/Flow$Subscriber;", "TS;", $PRIVATE | $FINAL, $field(ResponseSubscribers$SubscriberAdapter, subscriber)},
	{"finisher", "Ljava/util/function/Function;", "Ljava/util/function/Function<-TS;+TR;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$SubscriberAdapter, finisher)},
	{"subscription", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $PRIVATE | $VOLATILE, $field(ResponseSubscribers$SubscriberAdapter, subscription)},
	{}
};

$MethodInfo _ResponseSubscribers$SubscriberAdapter_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/util/function/Function;)V", "(TS;Ljava/util/function/Function<-TS;+TR;>;)V", $PUBLIC, $method(static_cast<void(ResponseSubscribers$SubscriberAdapter::*)($Flow$Subscriber*,$Function*)>(&ResponseSubscribers$SubscriberAdapter::init$))},
	{"getBody", "()Ljava/util/concurrent/CompletionStage;", "()Ljava/util/concurrent/CompletionStage<TR;>;", $PUBLIC},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, $method(static_cast<void(ResponseSubscribers$SubscriberAdapter::*)($List*)>(&ResponseSubscribers$SubscriberAdapter::onNext))},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _ResponseSubscribers$SubscriberAdapter_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseSubscribers$SubscriberAdapter", "jdk.internal.net.http.ResponseSubscribers", "SubscriberAdapter", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber", "jdk.internal.net.http.ResponseSubscribers", "TrustedSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.Flow$Subscriber", "java.util.concurrent.Flow", "Subscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseSubscribers$SubscriberAdapter_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.ResponseSubscribers$SubscriberAdapter",
	"java.lang.Object",
	"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber",
	_ResponseSubscribers$SubscriberAdapter_FieldInfo_,
	_ResponseSubscribers$SubscriberAdapter_MethodInfo_,
	"<S::Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;R:Ljava/lang/Object;>Ljava/lang/Object;Ljdk/internal/net/http/ResponseSubscribers$TrustedSubscriber<TR;>;",
	nullptr,
	_ResponseSubscribers$SubscriberAdapter_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseSubscribers"
};

$Object* allocate$ResponseSubscribers$SubscriberAdapter($Class* clazz) {
	return $of($alloc(ResponseSubscribers$SubscriberAdapter));
}

void ResponseSubscribers$SubscriberAdapter::init$($Flow$Subscriber* subscriber, $Function* finisher) {
	$set(this, cf, $new($MinimalFuture));
	$set(this, subscriber, $cast($Flow$Subscriber, $Objects::requireNonNull(subscriber)));
	$set(this, finisher, $cast($Function, $Objects::requireNonNull(finisher)));
}

void ResponseSubscribers$SubscriberAdapter::onSubscribe($Flow$Subscription* subscription) {
	$Objects::requireNonNull(subscription);
	if (this->subscription != nullptr) {
		subscription->cancel();
	} else {
		$set(this, subscription, subscription);
		$nc(this->subscriber)->onSubscribe(subscription);
	}
}

void ResponseSubscribers$SubscriberAdapter::onNext($List* item) {
	$Objects::requireNonNull(item);
	try {
		$nc(this->subscriber)->onNext(item);
	} catch ($Throwable& throwable) {
		$nc(this->subscription)->cancel();
		onError(throwable);
	}
}

void ResponseSubscribers$SubscriberAdapter::onError($Throwable* throwable) {
	$Objects::requireNonNull(throwable);
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->subscriber)->onError(throwable);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->cf)->completeExceptionally(throwable);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void ResponseSubscribers$SubscriberAdapter::onComplete() {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->subscriber)->onComplete();
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			try {
				$nc(this->cf)->complete($($nc(this->finisher)->apply(this->subscriber)));
			} catch ($Throwable& throwable) {
				$nc(this->cf)->completeExceptionally(throwable);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$CompletionStage* ResponseSubscribers$SubscriberAdapter::getBody() {
	return this->cf;
}

void ResponseSubscribers$SubscriberAdapter::onNext(Object$* item) {
	this->onNext($cast($List, item));
}

ResponseSubscribers$SubscriberAdapter::ResponseSubscribers$SubscriberAdapter() {
}

$Class* ResponseSubscribers$SubscriberAdapter::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$SubscriberAdapter, name, initialize, &_ResponseSubscribers$SubscriberAdapter_ClassInfo_, allocate$ResponseSubscribers$SubscriberAdapter);
	return class$;
}

$Class* ResponseSubscribers$SubscriberAdapter::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk