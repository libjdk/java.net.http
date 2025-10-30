#include <jdk/internal/net/http/common/SSLTube$SSLSubscriberWrapper.h>

#include <java/lang/AssertionError.h>
#include <java/util/List.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate.h>
#include <jdk/internal/net/http/common/SSLTube$DelegateWrapper.h>
#include <jdk/internal/net/http/common/SSLTube$SSLSubscriptionWrapper.h>
#include <jdk/internal/net/http/common/SSLTube.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $List = ::java::util::List;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SSLFlowDelegate = ::jdk::internal::net::http::common::SSLFlowDelegate;
using $SSLTube = ::jdk::internal::net::http::common::SSLTube;
using $SSLTube$DelegateWrapper = ::jdk::internal::net::http::common::SSLTube$DelegateWrapper;
using $SSLTube$SSLSubscriptionWrapper = ::jdk::internal::net::http::common::SSLTube$SSLSubscriptionWrapper;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SSLTube$SSLSubscriberWrapper_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/common/SSLTube;", nullptr, $FINAL | $SYNTHETIC, $field(SSLTube$SSLSubscriberWrapper, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SSLTube$SSLSubscriberWrapper, $assertionsDisabled)},
	{"pendingDelegate", "Ljava/util/concurrent/atomic/AtomicReference;", "Ljava/util/concurrent/atomic/AtomicReference<Ljdk/internal/net/http/common/SSLTube$DelegateWrapper;>;", $PRIVATE, $field(SSLTube$SSLSubscriberWrapper, pendingDelegate)},
	{"subscribed", "Ljdk/internal/net/http/common/SSLTube$DelegateWrapper;", nullptr, $PRIVATE | $VOLATILE, $field(SSLTube$SSLSubscriberWrapper, subscribed)},
	{"onCompleteReceived", "Z", nullptr, $PRIVATE | $VOLATILE, $field(SSLTube$SSLSubscriberWrapper, onCompleteReceived)},
	{"errorRef", "Ljava/util/concurrent/atomic/AtomicReference;", "Ljava/util/concurrent/atomic/AtomicReference<Ljava/lang/Throwable;>;", $PRIVATE | $FINAL, $field(SSLTube$SSLSubscriberWrapper, errorRef)},
	{}
};

$MethodInfo _SSLTube$SSLSubscriberWrapper_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/SSLTube;)V", nullptr, 0, $method(static_cast<void(SSLTube$SSLSubscriberWrapper::*)($SSLTube*)>(&SSLTube$SSLSubscriberWrapper::init$))},
	{"complete", "(Ljdk/internal/net/http/common/SSLTube$DelegateWrapper;Ljava/lang/Throwable;)V", nullptr, $PRIVATE, $method(static_cast<void(SSLTube$SSLSubscriberWrapper::*)($SSLTube$DelegateWrapper*,$Throwable*)>(&SSLTube$SSLSubscriberWrapper::complete))},
	{"dropSubscription", "()V", nullptr, $PUBLIC},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onErrorImpl", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(static_cast<void(SSLTube$SSLSubscriberWrapper::*)($Throwable*)>(&SSLTube$SSLSubscriberWrapper::onErrorImpl))},
	{"onNewSubscription", "(Ljdk/internal/net/http/common/SSLTube$DelegateWrapper;Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PRIVATE, $method(static_cast<void(SSLTube$SSLSubscriberWrapper::*)($SSLTube$DelegateWrapper*,$Flow$Subscription*)>(&SSLTube$SSLSubscriberWrapper::onNewSubscription))},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, $method(static_cast<void(SSLTube$SSLSubscriberWrapper::*)($List*)>(&SSLTube$SSLSubscriberWrapper::onNext))},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{"onSubscribeImpl", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PRIVATE, $method(static_cast<void(SSLTube$SSLSubscriberWrapper::*)($Flow$Subscription*)>(&SSLTube$SSLSubscriberWrapper::onSubscribeImpl))},
	{"processPendingSubscriber", "()V", nullptr, 0, $method(static_cast<void(SSLTube$SSLSubscriberWrapper::*)()>(&SSLTube$SSLSubscriberWrapper::processPendingSubscriber))},
	{"setDelegate", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", 0, $method(static_cast<void(SSLTube$SSLSubscriberWrapper::*)($Flow$Subscriber*)>(&SSLTube$SSLSubscriberWrapper::setDelegate))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SSLTube$SSLSubscriberWrapper_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SSLTube$SSLSubscriberWrapper", "jdk.internal.net.http.common.SSLTube", "SSLSubscriberWrapper", $FINAL},
	{"jdk.internal.net.http.common.FlowTube$TubeSubscriber", "jdk.internal.net.http.common.FlowTube", "TubeSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SSLTube$SSLSubscriberWrapper_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.SSLTube$SSLSubscriberWrapper",
	"java.lang.Object",
	"jdk.internal.net.http.common.FlowTube$TubeSubscriber",
	_SSLTube$SSLSubscriberWrapper_FieldInfo_,
	_SSLTube$SSLSubscriberWrapper_MethodInfo_,
	nullptr,
	nullptr,
	_SSLTube$SSLSubscriberWrapper_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SSLTube"
};

$Object* allocate$SSLTube$SSLSubscriberWrapper($Class* clazz) {
	return $of($alloc(SSLTube$SSLSubscriberWrapper));
}

bool SSLTube$SSLSubscriberWrapper::$assertionsDisabled = false;

void SSLTube$SSLSubscriberWrapper::init$($SSLTube* this$0) {
	$set(this, this$0, this$0);
	$set(this, pendingDelegate, $new($AtomicReference));
	$set(this, errorRef, $new($AtomicReference));
}

$String* SSLTube$SSLSubscriberWrapper::toString() {
	$useLocalCurrentObjectStackCache();
	$var($SSLTube$DelegateWrapper, sub, this->subscribed);
	$var($SSLTube$DelegateWrapper, pend, $cast($SSLTube$DelegateWrapper, $nc(this->pendingDelegate)->get()));
	$var($SSLFlowDelegate, sslFD, this->this$0->sslDelegate);
	$var($String, var$5, $$str({"SSLSubscriberWrapper["_s, this->this$0, ", delegate: "_s, (sub == nullptr ? pend : sub), ", getALPN: "_s}));
	$var($String, var$4, $$concat(var$5, $((sslFD == nullptr ? ($CompletableFuture*)nullptr : $nc(sslFD)->alpn()))));
	$var($String, var$3, $$concat(var$4, ", onCompleteReceived: "));
	$var($String, var$2, $$concat(var$3, $$str(this->onCompleteReceived)));
	$var($String, var$1, $$concat(var$2, ", onError: "));
	$var($String, var$0, $$concat(var$1, $($nc(this->errorRef)->get())));
	return $concat(var$0, "]");
}

void SSLTube$SSLSubscriberWrapper::setDelegate($Flow$Subscriber* delegate) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("SSLSubscriberWrapper (reader) got delegate: %s"_s, $$new($ObjectArray, {$of(delegate)}));
	}
	if (!SSLTube$SSLSubscriberWrapper::$assertionsDisabled && !(delegate != nullptr)) {
		$throwNew($AssertionError);
	}
	$var($SSLTube$DelegateWrapper, delegateWrapper, $new($SSLTube$DelegateWrapper, delegate, this->this$0->debug));
	$var($SSLTube$DelegateWrapper, previous, nullptr);
	$var($Flow$Subscription, subscription, nullptr);
	bool handleNow = false;
	$synchronized(this) {
		$assign(previous, $cast($SSLTube$DelegateWrapper, $nc(this->pendingDelegate)->getAndSet(delegateWrapper)));
		$assign(subscription, this->this$0->readSubscription);
		handleNow = $nc(this->errorRef)->get() != nullptr || this->onCompleteReceived;
	}
	if (previous != nullptr) {
		previous->dropSubscription();
	}
	if (subscription == nullptr) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("SSLSubscriberWrapper (reader) no subscription yet"_s);
		}
		return;
	}
	if (handleNow || !$nc(this->this$0->sslDelegate)->resumeReader()) {
		processPendingSubscriber();
	}
}

void SSLTube$SSLSubscriberWrapper::processPendingSubscriber() {
	$useLocalCurrentObjectStackCache();
	$var($Flow$Subscription, subscription, nullptr);
	$var($SSLTube$DelegateWrapper, delegateWrapper, nullptr);
	$var($SSLTube$DelegateWrapper, previous, nullptr);
	$synchronized(this) {
		$assign(delegateWrapper, $cast($SSLTube$DelegateWrapper, $nc(this->pendingDelegate)->get()));
		if (delegateWrapper == nullptr) {
			return;
		}
		$assign(subscription, this->this$0->readSubscription);
		$assign(previous, this->subscribed);
	}
	if (subscription == nullptr) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("SSLSubscriberWrapper (reader) processPendingSubscriber: no subscription yet"_s);
		}
		return;
	}
	$assign(delegateWrapper, $cast($SSLTube$DelegateWrapper, $nc(this->pendingDelegate)->getAndSet(nullptr)));
	if (delegateWrapper == nullptr) {
		return;
	}
	if (previous != nullptr) {
		previous->dropSubscription();
	}
	onNewSubscription(delegateWrapper, subscription);
}

void SSLTube$SSLSubscriberWrapper::dropSubscription() {
	$var($SSLTube$DelegateWrapper, subscriberImpl, this->subscribed);
	if (subscriberImpl != nullptr) {
		subscriberImpl->dropSubscription();
	}
}

void SSLTube$SSLSubscriberWrapper::onSubscribe($Flow$Subscription* subscription) {
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("SSLSubscriberWrapper (reader) onSubscribe(%s)"_s, $$new($ObjectArray, {$of(subscription)}));
	}
	onSubscribeImpl(subscription);
}

void SSLTube$SSLSubscriberWrapper::onSubscribeImpl($Flow$Subscription* subscription) {
	$useLocalCurrentObjectStackCache();
	if (!SSLTube$SSLSubscriberWrapper::$assertionsDisabled && !(subscription != nullptr)) {
		$throwNew($AssertionError);
	}
	$var($SSLTube$DelegateWrapper, subscriberImpl, nullptr);
	$var($SSLTube$DelegateWrapper, pending, nullptr);
	$synchronized(this) {
		$set(this->this$0, readSubscription, subscription);
		$assign(subscriberImpl, this->subscribed);
		$assign(pending, $cast($SSLTube$DelegateWrapper, $nc(this->pendingDelegate)->get()));
	}
	if (subscriberImpl == nullptr && pending == nullptr) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("SSLSubscriberWrapper (reader) onSubscribeImpl: no delegate yet"_s);
		}
		return;
	}
	if (pending == nullptr) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("SSLSubscriberWrapper (reader) onSubscribeImpl: resubscribing"_s);
		}
		onNewSubscription(subscriberImpl, subscription);
	} else {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("SSLSubscriberWrapper (reader) onSubscribeImpl: subscribing pending"_s);
		}
		processPendingSubscriber();
	}
}

void SSLTube$SSLSubscriberWrapper::complete($SSLTube$DelegateWrapper* subscriberImpl, $Throwable* t$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, t, t$renamed);
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (t == nullptr) {
				$nc(subscriberImpl)->onComplete();
			} else {
				$nc(subscriberImpl)->onError($assign(t, this->this$0->checkForHandshake(t)));
			}
			if ($nc(this->this$0->debug)->on()) {
				$nc(this->this$0->debug)->log("subscriber completed %s"_s, $$new($ObjectArray, {((t == nullptr) ? $of("normally"_s) : ($of($$str({"with error: "_s, t}))))}));
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->this$0->writeSubscription)->cancel();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void SSLTube$SSLSubscriberWrapper::onNewSubscription($SSLTube$DelegateWrapper* subscriberImpl, $Flow$Subscription* subscription) {
	$useLocalCurrentObjectStackCache();
	if (!SSLTube$SSLSubscriberWrapper::$assertionsDisabled && !(subscriberImpl != nullptr)) {
		$throwNew($AssertionError);
	}
	if (!SSLTube$SSLSubscriberWrapper::$assertionsDisabled && !(subscription != nullptr)) {
		$throwNew($AssertionError);
	}
	$var($Throwable, failed, nullptr);
	bool completed = false;
	$nc(this->this$0->sslDelegate)->resetReaderDemand();
	$nc(subscriberImpl)->onSubscribe(subscription);
	$synchronized(this) {
		$assign(failed, $cast($Throwable, $nc(this->errorRef)->get()));
		completed = this->onCompleteReceived;
		$set(this, subscribed, subscriberImpl);
	}
	if (failed != nullptr) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("onNewSubscription: subscriberImpl:%s, invoking onError:%s"_s, $$new($ObjectArray, {
				$of(subscriberImpl),
				$of(failed)
			}));
		}
		complete(subscriberImpl, failed);
	} else if (completed) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("onNewSubscription: subscriberImpl:%s, invoking onCompleted"_s, $$new($ObjectArray, {$of(subscriberImpl)}));
		}
		this->this$0->finished = true;
		complete(subscriberImpl, nullptr);
	}
}

void SSLTube$SSLSubscriberWrapper::onNext($List* item) {
	$nc(this->subscribed)->onNext(item);
}

void SSLTube$SSLSubscriberWrapper::onErrorImpl($Throwable* throwable$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, throwable, throwable$renamed);
	$assign(throwable, this->this$0->checkForHandshake(throwable));
	$nc(this->errorRef)->compareAndSet(nullptr, throwable);
	$var($Throwable, failed, $cast($Throwable, $nc(this->errorRef)->get()));
	this->this$0->finished = true;
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("%s: onErrorImpl: %s"_s, $$new($ObjectArray, {
			$of(this),
			$of(throwable)
		}));
	}
	$var($SSLTube$DelegateWrapper, subscriberImpl, nullptr);
	$synchronized(this) {
		$assign(subscriberImpl, this->subscribed);
	}
	if (subscriberImpl != nullptr) {
		complete(subscriberImpl, failed);
	} else if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("%s: delegate null, stored %s"_s, $$new($ObjectArray, {
			$of(this),
			$of(failed)
		}));
	}
	processPendingSubscriber();
}

void SSLTube$SSLSubscriberWrapper::onError($Throwable* throwable) {
	if (!SSLTube$SSLSubscriberWrapper::$assertionsDisabled && !(!this->this$0->finished && !this->onCompleteReceived)) {
		$throwNew($AssertionError);
	}
	onErrorImpl(throwable);
}

void SSLTube$SSLSubscriberWrapper::onComplete() {
	$useLocalCurrentObjectStackCache();
	if (!SSLTube$SSLSubscriberWrapper::$assertionsDisabled && !(!this->this$0->finished && !this->onCompleteReceived)) {
		$throwNew($AssertionError);
	}
	$var($SSLTube$DelegateWrapper, subscriberImpl, nullptr);
	$synchronized(this) {
		$assign(subscriberImpl, this->subscribed);
	}
	$var($Throwable, handshakeFailed, this->this$0->checkForHandshake(nullptr));
	if (handshakeFailed != nullptr) {
		onErrorImpl(handshakeFailed);
	} else if (subscriberImpl != nullptr) {
		this->onCompleteReceived = (this->this$0->finished = true);
		complete(subscriberImpl, nullptr);
	} else {
		this->onCompleteReceived = true;
	}
	processPendingSubscriber();
}

void SSLTube$SSLSubscriberWrapper::onNext(Object$* item) {
	this->onNext($cast($List, item));
}

void clinit$SSLTube$SSLSubscriberWrapper($Class* class$) {
	$load($SSLTube);
	SSLTube$SSLSubscriberWrapper::$assertionsDisabled = !$SSLTube::class$->desiredAssertionStatus();
}

SSLTube$SSLSubscriberWrapper::SSLTube$SSLSubscriberWrapper() {
}

$Class* SSLTube$SSLSubscriberWrapper::load$($String* name, bool initialize) {
	$loadClass(SSLTube$SSLSubscriberWrapper, name, initialize, &_SSLTube$SSLSubscriberWrapper_ClassInfo_, clinit$SSLTube$SSLSubscriberWrapper, allocate$SSLTube$SSLSubscriberWrapper);
	return class$;
}

$Class* SSLTube$SSLSubscriberWrapper::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk