#include <jdk/internal/net/http/ResponseSubscribers$MappingSubscriber.h>

#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/function/Function.h>
#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Function = ::java::util::function::Function;
using $ResponseSubscribers = ::jdk::internal::net::http::ResponseSubscribers;
using $ResponseSubscribers$TrustedSubscriber = ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ResponseSubscribers$MappingSubscriber_FieldInfo_[] = {
	{"upstream", "Ljava/net/http/HttpResponse$BodySubscriber;", "Ljava/net/http/HttpResponse$BodySubscriber<TT;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$MappingSubscriber, upstream)},
	{"mapper", "Ljava/util/function/Function;", "Ljava/util/function/Function<-TT;+TU;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$MappingSubscriber, mapper)},
	{"trusted", "Z", nullptr, $PRIVATE | $FINAL, $field(ResponseSubscribers$MappingSubscriber, trusted)},
	{}
};

$MethodInfo _ResponseSubscribers$MappingSubscriber_MethodInfo_[] = {
	{"<init>", "(Ljava/net/http/HttpResponse$BodySubscriber;Ljava/util/function/Function;)V", "(Ljava/net/http/HttpResponse$BodySubscriber<TT;>;Ljava/util/function/Function<-TT;+TU;>;)V", $PUBLIC, $method(static_cast<void(ResponseSubscribers$MappingSubscriber::*)($HttpResponse$BodySubscriber*,$Function*)>(&ResponseSubscribers$MappingSubscriber::init$))},
	{"<init>", "(Ljava/net/http/HttpResponse$BodySubscriber;Ljava/util/function/Function;Z)V", "(Ljava/net/http/HttpResponse$BodySubscriber<TT;>;Ljava/util/function/Function<-TT;+TU;>;Z)V", 0, $method(static_cast<void(ResponseSubscribers$MappingSubscriber::*)($HttpResponse$BodySubscriber*,$Function*,bool)>(&ResponseSubscribers$MappingSubscriber::init$))},
	{"getBody", "()Ljava/util/concurrent/CompletionStage;", "()Ljava/util/concurrent/CompletionStage<TU;>;", $PUBLIC},
	{"needsExecutor", "()Z", nullptr, $PUBLIC},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _ResponseSubscribers$MappingSubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseSubscribers$MappingSubscriber", "jdk.internal.net.http.ResponseSubscribers", "MappingSubscriber", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber", "jdk.internal.net.http.ResponseSubscribers", "TrustedSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseSubscribers$MappingSubscriber_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.ResponseSubscribers$MappingSubscriber",
	"java.lang.Object",
	"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber",
	_ResponseSubscribers$MappingSubscriber_FieldInfo_,
	_ResponseSubscribers$MappingSubscriber_MethodInfo_,
	"<T:Ljava/lang/Object;U:Ljava/lang/Object;>Ljava/lang/Object;Ljdk/internal/net/http/ResponseSubscribers$TrustedSubscriber<TU;>;",
	nullptr,
	_ResponseSubscribers$MappingSubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseSubscribers"
};

$Object* allocate$ResponseSubscribers$MappingSubscriber($Class* clazz) {
	return $of($alloc(ResponseSubscribers$MappingSubscriber));
}

void ResponseSubscribers$MappingSubscriber::init$($HttpResponse$BodySubscriber* upstream, $Function* mapper) {
	ResponseSubscribers$MappingSubscriber::init$(upstream, mapper, false);
}

void ResponseSubscribers$MappingSubscriber::init$($HttpResponse$BodySubscriber* upstream, $Function* mapper, bool trusted) {
	$set(this, upstream, $cast($HttpResponse$BodySubscriber, $Objects::requireNonNull(upstream)));
	$set(this, mapper, $cast($Function, $Objects::requireNonNull(mapper)));
	this->trusted = trusted;
}

bool ResponseSubscribers$MappingSubscriber::needsExecutor() {
	return !this->trusted || $ResponseSubscribers$TrustedSubscriber::needsExecutor(this->upstream);
}

$CompletionStage* ResponseSubscribers$MappingSubscriber::getBody() {
	return $nc($($nc(this->upstream)->getBody()))->thenApply(this->mapper);
}

void ResponseSubscribers$MappingSubscriber::onSubscribe($Flow$Subscription* subscription) {
	$nc(this->upstream)->onSubscribe(subscription);
}

void ResponseSubscribers$MappingSubscriber::onNext($List* item) {
	$nc(this->upstream)->onNext(item);
}

void ResponseSubscribers$MappingSubscriber::onError($Throwable* throwable) {
	$nc(this->upstream)->onError(throwable);
}

void ResponseSubscribers$MappingSubscriber::onComplete() {
	$nc(this->upstream)->onComplete();
}

void ResponseSubscribers$MappingSubscriber::onNext(Object$* item) {
	this->onNext($cast($List, item));
}

ResponseSubscribers$MappingSubscriber::ResponseSubscribers$MappingSubscriber() {
}

$Class* ResponseSubscribers$MappingSubscriber::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$MappingSubscriber, name, initialize, &_ResponseSubscribers$MappingSubscriber_ClassInfo_, allocate$ResponseSubscribers$MappingSubscriber);
	return class$;
}

$Class* ResponseSubscribers$MappingSubscriber::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk