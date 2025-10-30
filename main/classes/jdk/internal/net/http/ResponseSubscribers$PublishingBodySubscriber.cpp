#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/lang/VirtualMachineError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Flow$Publisher.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$1.h>
#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriberRef.h>
#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef.h>
#include <jdk/internal/net/http/ResponseSubscribers.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $VirtualMachineError = ::java::lang::VirtualMachineError;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Flow$Publisher = ::java::util::concurrent::Flow$Publisher;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $ResponseSubscribers = ::jdk::internal::net::http::ResponseSubscribers;
using $ResponseSubscribers$PublishingBodySubscriber$1 = ::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber$1;
using $ResponseSubscribers$PublishingBodySubscriber$SubscriberRef = ::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber$SubscriberRef;
using $ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef = ::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef;
using $ResponseSubscribers$TrustedSubscriber = ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber;
using $Log = ::jdk::internal::net::http::common::Log;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0 : public $Function {
	$class(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0, $NO_CLASS_INIT, $Function)
public:
	void init$(ResponseSubscribers$PublishingBodySubscriber* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* s) override {
		 return $of($nc(inst$)->lambda$new$0($cast($Flow$Subscription, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0>());
	}
	ResponseSubscribers$PublishingBodySubscriber* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0, inst$)},
	{}
};
$MethodInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0::*)(ResponseSubscribers$PublishingBodySubscriber*)>(&ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0::class$ = nullptr;

class ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1 : public $BiConsumer {
	$class(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(ResponseSubscribers$PublishingBodySubscriber* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* r, Object$* t) override {
		$nc(inst$)->lambda$new$2($cast($Void, r), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1>());
	}
	ResponseSubscribers$PublishingBodySubscriber* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1, inst$)},
	{}
};
$MethodInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1::*)(ResponseSubscribers$PublishingBodySubscriber*)>(&ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1::class$ = nullptr;

class ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2 : public $Consumer {
	$class(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2, $NO_CLASS_INIT, $Consumer)
public:
	void init$(ResponseSubscribers$PublishingBodySubscriber* inst, $ResponseSubscribers$PublishingBodySubscriber$SubscriberRef* ref) {
		$set(this, inst$, inst);
		$set(this, ref, ref);
	}
	virtual void accept(Object$* s) override {
		$nc(inst$)->lambda$subscribe$3(ref, $cast($Flow$Subscription, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2>());
	}
	ResponseSubscribers$PublishingBodySubscriber* inst$ = nullptr;
	$ResponseSubscribers$PublishingBodySubscriber$SubscriberRef* ref = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2, inst$)},
	{"ref", "Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriberRef;", nullptr, $PUBLIC, $field(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2, ref)},
	{}
};
$MethodInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber;Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriberRef;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2::*)(ResponseSubscribers$PublishingBodySubscriber*,$ResponseSubscribers$PublishingBodySubscriber$SubscriberRef*)>(&ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2::class$ = nullptr;

class ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$onNext$4$3 : public $Consumer {
	$class(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$onNext$4$3, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* s) override {
		ResponseSubscribers$PublishingBodySubscriber::lambda$onNext$4($cast($Flow$Subscription, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$onNext$4$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$onNext$4$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$onNext$4$3::*)()>(&ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$onNext$4$3::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$onNext$4$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$onNext$4$3",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$onNext$4$3::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$onNext$4$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$onNext$4$3::class$ = nullptr;

class ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4 : public $Consumer {
	$class(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4, $NO_CLASS_INIT, $Consumer)
public:
	void init$(ResponseSubscribers$PublishingBodySubscriber* inst, $Throwable* t) {
		$set(this, inst$, inst);
		$set(this, t, t);
	}
	virtual void accept(Object$* s) override {
		$nc(inst$)->lambda$new$1(t, $cast($ResponseSubscribers$PublishingBodySubscriber$SubscriberRef, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4>());
	}
	ResponseSubscribers$PublishingBodySubscriber* inst$ = nullptr;
	$Throwable* t = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4, inst$)},
	{"t", "Ljava/lang/Throwable;", nullptr, $PUBLIC, $field(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4, t)},
	{}
};
$MethodInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4::*)(ResponseSubscribers$PublishingBodySubscriber*,$Throwable*)>(&ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4::class$ = nullptr;

class ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5 : public $Flow$Publisher {
	$class(ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5, $NO_CLASS_INIT, $Flow$Publisher)
public:
	void init$(ResponseSubscribers$PublishingBodySubscriber* inst) {
		$set(this, inst$, inst);
	}
	virtual void subscribe($Flow$Subscriber* subscriber) override {
		$nc(inst$)->subscribe(subscriber);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5>());
	}
	ResponseSubscribers$PublishingBodySubscriber* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5, inst$)},
	{}
};
$MethodInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5::*)(ResponseSubscribers$PublishingBodySubscriber*)>(&ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5::init$))},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5",
	"java.lang.Object",
	"java.util.concurrent.Flow$Publisher",
	fieldInfos,
	methodInfos
};
$Class* ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5::class$ = nullptr;

$FieldInfo _ResponseSubscribers$PublishingBodySubscriber_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ResponseSubscribers$PublishingBodySubscriber, $assertionsDisabled)},
	{"subscriptionCF", "Ljdk/internal/net/http/common/MinimalFuture;", "Ljdk/internal/net/http/common/MinimalFuture<Ljava/util/concurrent/Flow$Subscription;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$PublishingBodySubscriber, subscriptionCF)},
	{"subscribedCF", "Ljdk/internal/net/http/common/MinimalFuture;", "Ljdk/internal/net/http/common/MinimalFuture<Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriberRef;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$PublishingBodySubscriber, subscribedCF)},
	{"subscriberRef", "Ljava/util/concurrent/atomic/AtomicReference;", "Ljava/util/concurrent/atomic/AtomicReference<Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriberRef;>;", $PRIVATE, $field(ResponseSubscribers$PublishingBodySubscriber, subscriberRef)},
	{"body", "Ljava/util/concurrent/CompletionStage;", "Ljava/util/concurrent/CompletionStage<Ljava/util/concurrent/Flow$Publisher<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$PublishingBodySubscriber, body)},
	{"completionCF", "Ljdk/internal/net/http/common/MinimalFuture;", "Ljdk/internal/net/http/common/MinimalFuture<Ljava/lang/Void;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$PublishingBodySubscriber, completionCF)},
	{"subscribed", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $PRIVATE | $FINAL, $field(ResponseSubscribers$PublishingBodySubscriber, subscribed)},
	{}
};

$MethodInfo _ResponseSubscribers$PublishingBodySubscriber_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber::*)()>(&ResponseSubscribers$PublishingBodySubscriber::init$))},
	{"complete", "(Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriberRef;Ljava/lang/Throwable;)V", nullptr, $PRIVATE, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber::*)($ResponseSubscribers$PublishingBodySubscriber$SubscriberRef*,$Throwable*)>(&ResponseSubscribers$PublishingBodySubscriber::complete))},
	{"getBody", "()Ljava/util/concurrent/CompletionStage;", "()Ljava/util/concurrent/CompletionStage<Ljava/util/concurrent/Flow$Publisher<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;>;", $PUBLIC},
	{"lambda$new$0", "(Ljava/util/concurrent/Flow$Subscription;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(ResponseSubscribers$PublishingBodySubscriber::*)($Flow$Subscription*)>(&ResponseSubscribers$PublishingBodySubscriber::lambda$new$0))},
	{"lambda$new$1", "(Ljava/lang/Throwable;Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriberRef;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber::*)($Throwable*,$ResponseSubscribers$PublishingBodySubscriber$SubscriberRef*)>(&ResponseSubscribers$PublishingBodySubscriber::lambda$new$1))},
	{"lambda$new$2", "(Ljava/lang/Void;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber::*)($Void*,$Throwable*)>(&ResponseSubscribers$PublishingBodySubscriber::lambda$new$2))},
	{"lambda$onNext$4", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($Flow$Subscription*)>(&ResponseSubscribers$PublishingBodySubscriber::lambda$onNext$4))},
	{"lambda$subscribe$3", "(Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriberRef;Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber::*)($ResponseSubscribers$PublishingBodySubscriber$SubscriberRef*,$Flow$Subscription*)>(&ResponseSubscribers$PublishingBodySubscriber::lambda$subscribe$3))},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{"signalComplete", "()V", nullptr, $PRIVATE, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber::*)()>(&ResponseSubscribers$PublishingBodySubscriber::signalComplete))},
	{"signalError", "(Ljava/lang/Throwable;)V", nullptr, $PRIVATE, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber::*)($Throwable*)>(&ResponseSubscribers$PublishingBodySubscriber::signalError))},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", $PRIVATE, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber::*)($Flow$Subscriber*)>(&ResponseSubscribers$PublishingBodySubscriber::subscribe))},
	{"suppress", "(ZLjava/lang/String;Ljava/lang/Throwable;)Z", nullptr, $PRIVATE, $method(static_cast<bool(ResponseSubscribers$PublishingBodySubscriber::*)(bool,$String*,$Throwable*)>(&ResponseSubscribers$PublishingBodySubscriber::suppress))},
	{}
};

$InnerClassInfo _ResponseSubscribers$PublishingBodySubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber", "jdk.internal.net.http.ResponseSubscribers", "PublishingBodySubscriber", $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber", "jdk.internal.net.http.ResponseSubscribers", "TrustedSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef", "jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber", "SubscriptionRef", $STATIC | $FINAL},
	{"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$SubscriberRef", "jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber", "SubscriberRef", $STATIC | $FINAL},
	{"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$1", nullptr, nullptr, 0},
	{"java.util.concurrent.Flow$Publisher", "java.util.concurrent.Flow", "Publisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseSubscribers$PublishingBodySubscriber_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber",
	"java.lang.Object",
	"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber",
	_ResponseSubscribers$PublishingBodySubscriber_FieldInfo_,
	_ResponseSubscribers$PublishingBodySubscriber_MethodInfo_,
	"Ljava/lang/Object;Ljdk/internal/net/http/ResponseSubscribers$TrustedSubscriber<Ljava/util/concurrent/Flow$Publisher<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;>;",
	nullptr,
	_ResponseSubscribers$PublishingBodySubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseSubscribers"
};

$Object* allocate$ResponseSubscribers$PublishingBodySubscriber($Class* clazz) {
	return $of($alloc(ResponseSubscribers$PublishingBodySubscriber));
}

bool ResponseSubscribers$PublishingBodySubscriber::$assertionsDisabled = false;

void ResponseSubscribers$PublishingBodySubscriber::init$() {
	$useLocalCurrentObjectStackCache();
	$set(this, subscriptionCF, $new($MinimalFuture));
	$set(this, subscribedCF, $new($MinimalFuture));
	$set(this, subscriberRef, $new($AtomicReference));
	$set(this, body, $nc(this->subscriptionCF)->thenCompose(static_cast<$Function*>($$new(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0, this))));
	$set(this, subscribed, $new($AtomicBoolean));
	$set(this, completionCF, $new($MinimalFuture));
	$nc(this->completionCF)->whenComplete(static_cast<$BiConsumer*>($$new(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1, this)));
}

void ResponseSubscribers$PublishingBodySubscriber::complete($ResponseSubscribers$PublishingBodySubscriber$SubscriberRef* ref, $Throwable* t) {
	if (!ResponseSubscribers$PublishingBodySubscriber::$assertionsDisabled && !(ref != nullptr)) {
		$throwNew($AssertionError);
	}
	$var($Flow$Subscriber, s, $nc(ref)->clear());
	if (s == nullptr) {
		return;
	}
	if (t == nullptr) {
		try {
			$nc(s)->onComplete();
		} catch ($Throwable& x) {
			$nc(s)->onError(x);
		}
	} else {
		$nc(s)->onError(t);
	}
}

void ResponseSubscribers$PublishingBodySubscriber::signalError($Throwable* err$renamed) {
	$var($Throwable, err, err$renamed);
	if (err == nullptr) {
		$assign(err, $new($NullPointerException, "null throwable"_s));
	}
	$nc(this->completionCF)->completeExceptionally(err);
}

void ResponseSubscribers$PublishingBodySubscriber::signalComplete() {
	$nc(this->completionCF)->complete(nullptr);
}

void ResponseSubscribers$PublishingBodySubscriber::subscribe($Flow$Subscriber* subscriber) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(subscriber), "subscriber must not be null"_s);
	$var($ResponseSubscribers$PublishingBodySubscriber$SubscriberRef, ref, $new($ResponseSubscribers$PublishingBodySubscriber$SubscriberRef, subscriber));
	if ($nc(this->subscriberRef)->compareAndSet(nullptr, ref)) {
		$nc(this->subscriptionCF)->thenAccept(static_cast<$Consumer*>($$new(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2, this, ref)));
	} else {
		$nc(subscriber)->onSubscribe($$new($ResponseSubscribers$PublishingBodySubscriber$1, this));
		subscriber->onError($$new($IllegalStateException, "This publisher has already one subscriber"_s));
	}
}

void ResponseSubscribers$PublishingBodySubscriber::onSubscribe($Flow$Subscription* subscription) {
	$Objects::requireNonNull(subscription);
	if (!$nc(this->subscribed)->compareAndSet(false, true)) {
		subscription->cancel();
	} else {
		$nc(this->subscriptionCF)->complete(subscription);
	}
}

void ResponseSubscribers$PublishingBodySubscriber::onNext($List* item) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(item);
	try {
		if (!ResponseSubscribers$PublishingBodySubscriber::$assertionsDisabled && !$nc(this->subscriptionCF)->isDone()) {
			$throwNew($AssertionError);
		}
		$var($ResponseSubscribers$PublishingBodySubscriber$SubscriberRef, ref, $cast($ResponseSubscribers$PublishingBodySubscriber$SubscriberRef, $nc(this->subscriberRef)->get()));
		if (!ResponseSubscribers$PublishingBodySubscriber::$assertionsDisabled && !(ref != nullptr)) {
			$throwNew($AssertionError);
		}
		$var($Flow$Subscriber, subscriber, $nc(ref)->get());
		if (subscriber != nullptr) {
			subscriber->onNext(item);
		}
	} catch ($Throwable& err) {
		signalError(err);
		$nc(this->subscriptionCF)->thenAccept(static_cast<$Consumer*>($$new(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$onNext$4$3)));
	}
}

void ResponseSubscribers$PublishingBodySubscriber::onError($Throwable* throwable) {
	if (!ResponseSubscribers$PublishingBodySubscriber::$assertionsDisabled && !suppress($nc(this->subscriptionCF)->isDone(), "onError called before onSubscribe"_s, throwable)) {
		$throwNew($AssertionError);
	}
	signalError(throwable);
	$Objects::requireNonNull(throwable);
}

void ResponseSubscribers$PublishingBodySubscriber::onComplete() {
	if (!$nc(this->subscriptionCF)->isDone()) {
		signalError($$new($InternalError, "onComplete called before onSubscribed"_s));
	} else {
		signalComplete();
	}
}

$CompletionStage* ResponseSubscribers$PublishingBodySubscriber::getBody() {
	return this->body;
}

bool ResponseSubscribers$PublishingBodySubscriber::suppress(bool condition, $String* assertion, $Throwable* carrier) {
	$useLocalCurrentObjectStackCache();
	if (!condition) {
		if (carrier != nullptr) {
			carrier->addSuppressed($$new($AssertionError, $of(assertion)));
		} else if ($Log::errors()) {
			$Log::logError($$new($AssertionError, $of(assertion)));
		}
	}
	return true;
}

void ResponseSubscribers$PublishingBodySubscriber::onNext(Object$* item) {
	this->onNext($cast($List, item));
}

void ResponseSubscribers$PublishingBodySubscriber::lambda$onNext$4($Flow$Subscription* s) {
	$init(ResponseSubscribers$PublishingBodySubscriber);
	$nc(s)->cancel();
}

void ResponseSubscribers$PublishingBodySubscriber::lambda$subscribe$3($ResponseSubscribers$PublishingBodySubscriber$SubscriberRef* ref, $Flow$Subscription* s) {
	$useLocalCurrentObjectStackCache();
	$var($ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef, subscription, $new($ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef, s, ref));
	try {
		subscription->subscribe();
		$nc(this->subscribedCF)->complete(ref);
	} catch ($Throwable& t) {
		if ($Log::errors()) {
			$Log::logError($$str({"Failed to call onSubscribe: cancelling subscription: "_s, t}), $$new($ObjectArray, 0));
			$Log::logError(t);
		}
		subscription->cancel();
	}
}

void ResponseSubscribers$PublishingBodySubscriber::lambda$new$2($Void* r, $Throwable* t) {
	$nc(this->subscribedCF)->thenAccept(static_cast<$Consumer*>($$new(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4, this, t)));
}

void ResponseSubscribers$PublishingBodySubscriber::lambda$new$1($Throwable* t, $ResponseSubscribers$PublishingBodySubscriber$SubscriberRef* s) {
	complete(s, t);
}

$CompletionStage* ResponseSubscribers$PublishingBodySubscriber::lambda$new$0($Flow$Subscription* s) {
	return $MinimalFuture::completedFuture(static_cast<$Flow$Publisher*>($$new(ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5, this)));
}

void clinit$ResponseSubscribers$PublishingBodySubscriber($Class* class$) {
	$load($ResponseSubscribers);
	ResponseSubscribers$PublishingBodySubscriber::$assertionsDisabled = !$ResponseSubscribers::class$->desiredAssertionStatus();
}

ResponseSubscribers$PublishingBodySubscriber::ResponseSubscribers$PublishingBodySubscriber() {
}

$Class* ResponseSubscribers$PublishingBodySubscriber::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0::classInfo$.name)) {
			return ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$0::load$(name, initialize);
		}
		if (name->equals(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1::classInfo$.name)) {
			return ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$2$1::load$(name, initialize);
		}
		if (name->equals(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2::classInfo$.name)) {
			return ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$subscribe$3$2::load$(name, initialize);
		}
		if (name->equals(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$onNext$4$3::classInfo$.name)) {
			return ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$onNext$4$3::load$(name, initialize);
		}
		if (name->equals(ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4::classInfo$.name)) {
			return ResponseSubscribers$PublishingBodySubscriber$$Lambda$lambda$new$1$4::load$(name, initialize);
		}
		if (name->equals(ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5::classInfo$.name)) {
			return ResponseSubscribers$PublishingBodySubscriber$$Lambda$subscribe$5::load$(name, initialize);
		}
	}
	$loadClass(ResponseSubscribers$PublishingBodySubscriber, name, initialize, &_ResponseSubscribers$PublishingBodySubscriber_ClassInfo_, clinit$ResponseSubscribers$PublishingBodySubscriber, allocate$ResponseSubscribers$PublishingBodySubscriber);
	return class$;
}

$Class* ResponseSubscribers$PublishingBodySubscriber::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk