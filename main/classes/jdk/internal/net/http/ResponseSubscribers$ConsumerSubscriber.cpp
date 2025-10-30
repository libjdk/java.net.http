#include <jdk/internal/net/http/ResponseSubscribers$ConsumerSubscriber.h>

#include <java/nio/ByteBuffer.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/function/Consumer.h>
#include <jdk/internal/net/http/ResponseSubscribers.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $Consumer = ::java::util::function::Consumer;
using $ResponseSubscribers = ::jdk::internal::net::http::ResponseSubscribers;
using $ResponseSubscribers$TrustedSubscriber = ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ResponseSubscribers$ConsumerSubscriber_FieldInfo_[] = {
	{"consumer", "Ljava/util/function/Consumer;", "Ljava/util/function/Consumer<Ljava/util/Optional<[B>;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$ConsumerSubscriber, consumer)},
	{"subscription", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $PRIVATE, $field(ResponseSubscribers$ConsumerSubscriber, subscription)},
	{"result", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$ConsumerSubscriber, result)},
	{"subscribed", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $PRIVATE | $FINAL, $field(ResponseSubscribers$ConsumerSubscriber, subscribed)},
	{}
};

$MethodInfo _ResponseSubscribers$ConsumerSubscriber_MethodInfo_[] = {
	{"<init>", "(Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<Ljava/util/Optional<[B>;>;)V", $PUBLIC, $method(static_cast<void(ResponseSubscribers$ConsumerSubscriber::*)($Consumer*)>(&ResponseSubscribers$ConsumerSubscriber::init$))},
	{"getBody", "()Ljava/util/concurrent/CompletionStage;", "()Ljava/util/concurrent/CompletionStage<Ljava/lang/Void;>;", $PUBLIC},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _ResponseSubscribers$ConsumerSubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseSubscribers$ConsumerSubscriber", "jdk.internal.net.http.ResponseSubscribers", "ConsumerSubscriber", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber", "jdk.internal.net.http.ResponseSubscribers", "TrustedSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseSubscribers$ConsumerSubscriber_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.ResponseSubscribers$ConsumerSubscriber",
	"java.lang.Object",
	"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber",
	_ResponseSubscribers$ConsumerSubscriber_FieldInfo_,
	_ResponseSubscribers$ConsumerSubscriber_MethodInfo_,
	"Ljava/lang/Object;Ljdk/internal/net/http/ResponseSubscribers$TrustedSubscriber<Ljava/lang/Void;>;",
	nullptr,
	_ResponseSubscribers$ConsumerSubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseSubscribers"
};

$Object* allocate$ResponseSubscribers$ConsumerSubscriber($Class* clazz) {
	return $of($alloc(ResponseSubscribers$ConsumerSubscriber));
}

void ResponseSubscribers$ConsumerSubscriber::init$($Consumer* consumer) {
	$set(this, result, $new($MinimalFuture));
	$set(this, subscribed, $new($AtomicBoolean));
	$set(this, consumer, $cast($Consumer, $Objects::requireNonNull(consumer)));
}

$CompletionStage* ResponseSubscribers$ConsumerSubscriber::getBody() {
	return this->result;
}

void ResponseSubscribers$ConsumerSubscriber::onSubscribe($Flow$Subscription* subscription) {
	$Objects::requireNonNull(subscription);
	if (!$nc(this->subscribed)->compareAndSet(false, true)) {
		subscription->cancel();
	} else {
		$set(this, subscription, subscription);
		subscription->request(1);
	}
}

void ResponseSubscribers$ConsumerSubscriber::onNext($List* items) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(items);
	{
		$var($Iterator, i$, items->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ByteBuffer, item, $cast($ByteBuffer, i$->next()));
			{
				$var($bytes, buf, $new($bytes, $nc(item)->remaining()));
				item->get(buf);
				$nc(this->consumer)->accept($($Optional::of(buf)));
			}
		}
	}
	$nc(this->subscription)->request(1);
}

void ResponseSubscribers$ConsumerSubscriber::onError($Throwable* throwable) {
	$Objects::requireNonNull(throwable);
	$nc(this->result)->completeExceptionally(throwable);
}

void ResponseSubscribers$ConsumerSubscriber::onComplete() {
	$nc(this->consumer)->accept($($Optional::empty()));
	$nc(this->result)->complete(nullptr);
}

void ResponseSubscribers$ConsumerSubscriber::onNext(Object$* items) {
	this->onNext($cast($List, items));
}

ResponseSubscribers$ConsumerSubscriber::ResponseSubscribers$ConsumerSubscriber() {
}

$Class* ResponseSubscribers$ConsumerSubscriber::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$ConsumerSubscriber, name, initialize, &_ResponseSubscribers$ConsumerSubscriber_ClassInfo_, allocate$ResponseSubscribers$ConsumerSubscriber);
	return class$;
}

$Class* ResponseSubscribers$ConsumerSubscriber::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk