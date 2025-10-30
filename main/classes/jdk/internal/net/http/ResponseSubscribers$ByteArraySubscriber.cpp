#include <jdk/internal/net/http/ResponseSubscribers$ByteArraySubscriber.h>

#include <java/lang/AssertionError.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/function/Function.h>
#include <jdk/internal/net/http/ResponseSubscribers.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef MAX_VALUE

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Function = ::java::util::function::Function;
using $ResponseSubscribers = ::jdk::internal::net::http::ResponseSubscribers;
using $ResponseSubscribers$TrustedSubscriber = ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ResponseSubscribers$ByteArraySubscriber_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ResponseSubscribers$ByteArraySubscriber, $assertionsDisabled)},
	{"finisher", "Ljava/util/function/Function;", "Ljava/util/function/Function<[BTT;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$ByteArraySubscriber, finisher)},
	{"result", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<TT;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$ByteArraySubscriber, result)},
	{"received", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$ByteArraySubscriber, received)},
	{"subscription", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $PRIVATE | $VOLATILE, $field(ResponseSubscribers$ByteArraySubscriber, subscription)},
	{}
};

$MethodInfo _ResponseSubscribers$ByteArraySubscriber_MethodInfo_[] = {
	{"<init>", "(Ljava/util/function/Function;)V", "(Ljava/util/function/Function<[BTT;>;)V", $PUBLIC, $method(static_cast<void(ResponseSubscribers$ByteArraySubscriber::*)($Function*)>(&ResponseSubscribers$ByteArraySubscriber::init$))},
	{"getBody", "()Ljava/util/concurrent/CompletionStage;", "()Ljava/util/concurrent/CompletionStage<TT;>;", $PUBLIC},
	{"join", "(Ljava/util/List;)[B", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)[B", $PRIVATE | $STATIC, $method(static_cast<$bytes*(*)($List*)>(&ResponseSubscribers$ByteArraySubscriber::join))},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _ResponseSubscribers$ByteArraySubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseSubscribers$ByteArraySubscriber", "jdk.internal.net.http.ResponseSubscribers", "ByteArraySubscriber", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber", "jdk.internal.net.http.ResponseSubscribers", "TrustedSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseSubscribers$ByteArraySubscriber_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.ResponseSubscribers$ByteArraySubscriber",
	"java.lang.Object",
	"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber",
	_ResponseSubscribers$ByteArraySubscriber_FieldInfo_,
	_ResponseSubscribers$ByteArraySubscriber_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljdk/internal/net/http/ResponseSubscribers$TrustedSubscriber<TT;>;",
	nullptr,
	_ResponseSubscribers$ByteArraySubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseSubscribers"
};

$Object* allocate$ResponseSubscribers$ByteArraySubscriber($Class* clazz) {
	return $of($alloc(ResponseSubscribers$ByteArraySubscriber));
}

bool ResponseSubscribers$ByteArraySubscriber::$assertionsDisabled = false;

void ResponseSubscribers$ByteArraySubscriber::init$($Function* finisher) {
	$set(this, result, $new($MinimalFuture));
	$set(this, received, $new($ArrayList));
	$set(this, finisher, finisher);
}

void ResponseSubscribers$ByteArraySubscriber::onSubscribe($Flow$Subscription* subscription) {
	if (this->subscription != nullptr) {
		$nc(subscription)->cancel();
		return;
	}
	$set(this, subscription, subscription);
	$nc(subscription)->request($Long::MAX_VALUE);
}

void ResponseSubscribers$ByteArraySubscriber::onNext($List* items) {
	if (!ResponseSubscribers$ByteArraySubscriber::$assertionsDisabled && !$Utils::hasRemaining(items)) {
		$throwNew($AssertionError);
	}
	$nc(this->received)->addAll(items);
}

void ResponseSubscribers$ByteArraySubscriber::onError($Throwable* throwable) {
	$nc(this->received)->clear();
	$nc(this->result)->completeExceptionally(throwable);
}

$bytes* ResponseSubscribers$ByteArraySubscriber::join($List* bytes) {
	$init(ResponseSubscribers$ByteArraySubscriber);
	$useLocalCurrentObjectStackCache();
	int32_t size = $Utils::remaining(bytes, $Integer::MAX_VALUE);
	$var($bytes, res, $new($bytes, size));
	int32_t from = 0;
	{
		$var($Iterator, i$, $nc(bytes)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ByteBuffer, b, $cast($ByteBuffer, i$->next()));
			{
				int32_t l = $nc(b)->remaining();
				b->get(res, from, l);
				from += l;
			}
		}
	}
	return res;
}

void ResponseSubscribers$ByteArraySubscriber::onComplete() {
	$useLocalCurrentObjectStackCache();
	try {
		$nc(this->result)->complete($($nc(this->finisher)->apply($(join(this->received)))));
		$nc(this->received)->clear();
	} catch ($IllegalArgumentException& e) {
		$nc(this->result)->completeExceptionally(e);
	}
}

$CompletionStage* ResponseSubscribers$ByteArraySubscriber::getBody() {
	return this->result;
}

void ResponseSubscribers$ByteArraySubscriber::onNext(Object$* items) {
	this->onNext($cast($List, items));
}

void clinit$ResponseSubscribers$ByteArraySubscriber($Class* class$) {
	$load($ResponseSubscribers);
	ResponseSubscribers$ByteArraySubscriber::$assertionsDisabled = !$ResponseSubscribers::class$->desiredAssertionStatus();
}

ResponseSubscribers$ByteArraySubscriber::ResponseSubscribers$ByteArraySubscriber() {
}

$Class* ResponseSubscribers$ByteArraySubscriber::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$ByteArraySubscriber, name, initialize, &_ResponseSubscribers$ByteArraySubscriber_ClassInfo_, clinit$ResponseSubscribers$ByteArraySubscriber, allocate$ResponseSubscribers$ByteArraySubscriber);
	return class$;
}

$Class* ResponseSubscribers$ByteArraySubscriber::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk