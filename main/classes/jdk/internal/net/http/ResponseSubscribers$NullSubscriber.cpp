#include <jdk/internal/net/http/ResponseSubscribers$NullSubscriber.h>

#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <jdk/internal/net/http/ResponseSubscribers.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jcpp.h>

#undef MAX_VALUE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $ResponseSubscribers = ::jdk::internal::net::http::ResponseSubscribers;
using $ResponseSubscribers$TrustedSubscriber = ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ResponseSubscribers$NullSubscriber_FieldInfo_[] = {
	{"cf", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<TT;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$NullSubscriber, cf)},
	{"result", "Ljava/util/Optional;", "Ljava/util/Optional<TT;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$NullSubscriber, result)},
	{"subscribed", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $PRIVATE | $FINAL, $field(ResponseSubscribers$NullSubscriber, subscribed)},
	{}
};

$MethodInfo _ResponseSubscribers$NullSubscriber_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Optional;)V", "(Ljava/util/Optional<TT;>;)V", $PUBLIC, $method(static_cast<void(ResponseSubscribers$NullSubscriber::*)($Optional*)>(&ResponseSubscribers$NullSubscriber::init$))},
	{"getBody", "()Ljava/util/concurrent/CompletionStage;", "()Ljava/util/concurrent/CompletionStage<TT;>;", $PUBLIC},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _ResponseSubscribers$NullSubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseSubscribers$NullSubscriber", "jdk.internal.net.http.ResponseSubscribers", "NullSubscriber", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber", "jdk.internal.net.http.ResponseSubscribers", "TrustedSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseSubscribers$NullSubscriber_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.ResponseSubscribers$NullSubscriber",
	"java.lang.Object",
	"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber",
	_ResponseSubscribers$NullSubscriber_FieldInfo_,
	_ResponseSubscribers$NullSubscriber_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljdk/internal/net/http/ResponseSubscribers$TrustedSubscriber<TT;>;",
	nullptr,
	_ResponseSubscribers$NullSubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseSubscribers"
};

$Object* allocate$ResponseSubscribers$NullSubscriber($Class* clazz) {
	return $of($alloc(ResponseSubscribers$NullSubscriber));
}

void ResponseSubscribers$NullSubscriber::init$($Optional* result) {
	$set(this, cf, $new($MinimalFuture));
	$set(this, subscribed, $new($AtomicBoolean));
	$set(this, result, result);
}

void ResponseSubscribers$NullSubscriber::onSubscribe($Flow$Subscription* subscription) {
	$Objects::requireNonNull(subscription);
	if (!$nc(this->subscribed)->compareAndSet(false, true)) {
		subscription->cancel();
	} else {
		subscription->request($Long::MAX_VALUE);
	}
}

void ResponseSubscribers$NullSubscriber::onNext($List* items) {
	$Objects::requireNonNull(items);
}

void ResponseSubscribers$NullSubscriber::onError($Throwable* throwable) {
	$Objects::requireNonNull(throwable);
	$nc(this->cf)->completeExceptionally(throwable);
}

void ResponseSubscribers$NullSubscriber::onComplete() {
	if ($nc(this->result)->isPresent()) {
		$nc(this->cf)->complete($($nc(this->result)->get()));
	} else {
		$nc(this->cf)->complete(nullptr);
	}
}

$CompletionStage* ResponseSubscribers$NullSubscriber::getBody() {
	return this->cf;
}

void ResponseSubscribers$NullSubscriber::onNext(Object$* items) {
	this->onNext($cast($List, items));
}

ResponseSubscribers$NullSubscriber::ResponseSubscribers$NullSubscriber() {
}

$Class* ResponseSubscribers$NullSubscriber::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$NullSubscriber, name, initialize, &_ResponseSubscribers$NullSubscriber_ClassInfo_, allocate$ResponseSubscribers$NullSubscriber);
	return class$;
}

$Class* ResponseSubscribers$NullSubscriber::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk