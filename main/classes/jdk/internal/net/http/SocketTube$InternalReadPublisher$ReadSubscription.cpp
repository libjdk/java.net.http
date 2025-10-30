#include <jdk/internal/net/http/SocketTube$InternalReadPublisher$ReadSubscription.h>

#include <java/lang/AssertionError.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/SocketTube$BufferSource.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher$InternalReadSubscription.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher.h>
#include <jdk/internal/net/http/SocketTube$SSLDirectBufferSource.h>
#include <jdk/internal/net/http/SocketTube$SliceBufferSource.h>
#include <jdk/internal/net/http/SocketTube.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $SocketTube = ::jdk::internal::net::http::SocketTube;
using $SocketTube$BufferSource = ::jdk::internal::net::http::SocketTube$BufferSource;
using $SocketTube$InternalReadPublisher = ::jdk::internal::net::http::SocketTube$InternalReadPublisher;
using $SocketTube$InternalReadPublisher$InternalReadSubscription = ::jdk::internal::net::http::SocketTube$InternalReadPublisher$InternalReadSubscription;
using $SocketTube$SSLDirectBufferSource = ::jdk::internal::net::http::SocketTube$SSLDirectBufferSource;
using $SocketTube$SliceBufferSource = ::jdk::internal::net::http::SocketTube$SliceBufferSource;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $Logger = ::jdk::internal::net::http::common::Logger;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _SocketTube$InternalReadPublisher$ReadSubscription_FieldInfo_[] = {
	{"this$1", "Ljdk/internal/net/http/SocketTube$InternalReadPublisher;", nullptr, $FINAL | $SYNTHETIC, $field(SocketTube$InternalReadPublisher$ReadSubscription, this$1)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SocketTube$InternalReadPublisher$ReadSubscription, $assertionsDisabled)},
	{"impl", "Ljdk/internal/net/http/SocketTube$InternalReadPublisher$InternalReadSubscription;", nullptr, $FINAL, $field(SocketTube$InternalReadPublisher$ReadSubscription, impl)},
	{"subscriber", "Ljdk/internal/net/http/common/FlowTube$TubeSubscriber;", nullptr, $FINAL, $field(SocketTube$InternalReadPublisher$ReadSubscription, subscriber)},
	{"errorRef", "Ljava/util/concurrent/atomic/AtomicReference;", "Ljava/util/concurrent/atomic/AtomicReference<Ljava/lang/Throwable;>;", $FINAL, $field(SocketTube$InternalReadPublisher$ReadSubscription, errorRef)},
	{"bufferSource", "Ljdk/internal/net/http/SocketTube$BufferSource;", nullptr, $FINAL, $field(SocketTube$InternalReadPublisher$ReadSubscription, bufferSource)},
	{"subscribed", "Z", nullptr, $VOLATILE, $field(SocketTube$InternalReadPublisher$ReadSubscription, subscribed)},
	{"cancelled", "Z", nullptr, $VOLATILE, $field(SocketTube$InternalReadPublisher$ReadSubscription, cancelled)},
	{"completed", "Z", nullptr, $VOLATILE, $field(SocketTube$InternalReadPublisher$ReadSubscription, completed)},
	{}
};

$MethodInfo _SocketTube$InternalReadPublisher$ReadSubscription_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/SocketTube$InternalReadPublisher;Ljdk/internal/net/http/SocketTube$InternalReadPublisher$InternalReadSubscription;Ljdk/internal/net/http/common/FlowTube$TubeSubscriber;)V", nullptr, $PUBLIC, $method(static_cast<void(SocketTube$InternalReadPublisher$ReadSubscription::*)($SocketTube$InternalReadPublisher*,$SocketTube$InternalReadPublisher$InternalReadSubscription*,$FlowTube$TubeSubscriber*)>(&SocketTube$InternalReadPublisher$ReadSubscription::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"request", "(J)V", nullptr, $PUBLIC},
	{"signalCompletion", "()V", nullptr, 0, $method(static_cast<void(SocketTube$InternalReadPublisher$ReadSubscription::*)()>(&SocketTube$InternalReadPublisher$ReadSubscription::signalCompletion))},
	{"signalOnSubscribe", "()V", nullptr, 0, $method(static_cast<void(SocketTube$InternalReadPublisher$ReadSubscription::*)()>(&SocketTube$InternalReadPublisher$ReadSubscription::signalOnSubscribe))},
	{}
};

$InnerClassInfo _SocketTube$InternalReadPublisher$ReadSubscription_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.SocketTube$InternalReadPublisher", "jdk.internal.net.http.SocketTube", "InternalReadPublisher", $PRIVATE | $FINAL},
	{"jdk.internal.net.http.SocketTube$InternalReadPublisher$ReadSubscription", "jdk.internal.net.http.SocketTube$InternalReadPublisher", "ReadSubscription", $FINAL},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SocketTube$InternalReadPublisher$ReadSubscription_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.SocketTube$InternalReadPublisher$ReadSubscription",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription",
	_SocketTube$InternalReadPublisher$ReadSubscription_FieldInfo_,
	_SocketTube$InternalReadPublisher$ReadSubscription_MethodInfo_,
	nullptr,
	nullptr,
	_SocketTube$InternalReadPublisher$ReadSubscription_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.SocketTube"
};

$Object* allocate$SocketTube$InternalReadPublisher$ReadSubscription($Class* clazz) {
	return $of($alloc(SocketTube$InternalReadPublisher$ReadSubscription));
}

bool SocketTube$InternalReadPublisher$ReadSubscription::$assertionsDisabled = false;

void SocketTube$InternalReadPublisher$ReadSubscription::init$($SocketTube$InternalReadPublisher* this$1, $SocketTube$InternalReadPublisher$InternalReadSubscription* impl, $FlowTube$TubeSubscriber* subscriber) {
	$set(this, this$1, this$1);
	$set(this, errorRef, $new($AtomicReference));
	$set(this, impl, impl);
	$set(this, bufferSource, $nc(subscriber)->supportsRecycling() ? static_cast<$SocketTube$BufferSource*>($new($SocketTube$SSLDirectBufferSource, $nc(this$1->this$0)->client)) : static_cast<$SocketTube$BufferSource*>($nc(this$1->this$0)->sliceBuffersSource));
	$set(this, subscriber, subscriber);
}

void SocketTube$InternalReadPublisher$ReadSubscription::cancel() {
	this->cancelled = true;
}

void SocketTube$InternalReadPublisher$ReadSubscription::request(int64_t n) {
	$useLocalCurrentObjectStackCache();
	if (!this->cancelled) {
		$nc(this->impl)->request(n);
	} else if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log("subscription cancelled, ignoring request %d"_s, $$new($ObjectArray, {$($of($Long::valueOf(n)))}));
	}
}

void SocketTube$InternalReadPublisher$ReadSubscription::signalCompletion() {
	$useLocalCurrentObjectStackCache();
	if (!SocketTube$InternalReadPublisher$ReadSubscription::$assertionsDisabled && !(this->subscribed || this->cancelled)) {
		$throwNew($AssertionError);
	}
	if (this->completed || this->cancelled) {
		return;
	}
	$synchronized(this) {
		if (this->completed) {
			return;
		}
		this->completed = true;
	}
	$var($Throwable, error, $cast($Throwable, $nc(this->errorRef)->get()));
	if (error != nullptr) {
		if ($nc($nc(this->this$1->this$0)->debug)->on()) {
			$nc($nc(this->this$1->this$0)->debug)->log($$str({"forwarding error to subscriber: "_s, error}));
		}
		$nc(this->subscriber)->onError(error);
	} else {
		if ($nc($nc(this->this$1->this$0)->debug)->on()) {
			$nc($nc(this->this$1->this$0)->debug)->log("completing subscriber"_s);
		}
		$nc(this->subscriber)->onComplete();
	}
}

void SocketTube$InternalReadPublisher$ReadSubscription::signalOnSubscribe() {
	if (this->subscribed || this->cancelled) {
		return;
	}
	$synchronized(this) {
		if (this->subscribed || this->cancelled) {
			return;
		}
		this->subscribed = true;
	}
	$nc(this->subscriber)->onSubscribe(this);
	if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log("onSubscribe called"_s);
	}
	if ($nc(this->errorRef)->get() != nullptr) {
		signalCompletion();
	}
}

void clinit$SocketTube$InternalReadPublisher$ReadSubscription($Class* class$) {
	$load($SocketTube);
	SocketTube$InternalReadPublisher$ReadSubscription::$assertionsDisabled = !$SocketTube::class$->desiredAssertionStatus();
}

SocketTube$InternalReadPublisher$ReadSubscription::SocketTube$InternalReadPublisher$ReadSubscription() {
}

$Class* SocketTube$InternalReadPublisher$ReadSubscription::load$($String* name, bool initialize) {
	$loadClass(SocketTube$InternalReadPublisher$ReadSubscription, name, initialize, &_SocketTube$InternalReadPublisher$ReadSubscription_ClassInfo_, clinit$SocketTube$InternalReadPublisher$ReadSubscription, allocate$SocketTube$InternalReadPublisher$ReadSubscription);
	return class$;
}

$Class* SocketTube$InternalReadPublisher$ReadSubscription::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk