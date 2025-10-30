#include <jdk/internal/net/http/common/SSLTube$DelegateWrapper.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/List.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/function/Consumer.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SSLTube.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $List = ::java::util::List;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Consumer = ::java::util::function::Consumer;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SSLTube = ::jdk::internal::net::http::common::SSLTube;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class SSLTube$DelegateWrapper$$Lambda$onSubscribe : public $Consumer {
	$class(SSLTube$DelegateWrapper$$Lambda$onSubscribe, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Flow$Subscriber* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* arg0) override {
		$nc(inst$)->onSubscribe($cast($Flow$Subscription, arg0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SSLTube$DelegateWrapper$$Lambda$onSubscribe>());
	}
	$Flow$Subscriber* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SSLTube$DelegateWrapper$$Lambda$onSubscribe::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SSLTube$DelegateWrapper$$Lambda$onSubscribe, inst$)},
	{}
};
$MethodInfo SSLTube$DelegateWrapper$$Lambda$onSubscribe::methodInfos[3] = {
	{"<init>", "(Ljava/util/concurrent/Flow$Subscriber;)V", nullptr, $PUBLIC, $method(static_cast<void(SSLTube$DelegateWrapper$$Lambda$onSubscribe::*)($Flow$Subscriber*)>(&SSLTube$DelegateWrapper$$Lambda$onSubscribe::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo SSLTube$DelegateWrapper$$Lambda$onSubscribe::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.SSLTube$DelegateWrapper$$Lambda$onSubscribe",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* SSLTube$DelegateWrapper$$Lambda$onSubscribe::load$($String* name, bool initialize) {
	$loadClass(SSLTube$DelegateWrapper$$Lambda$onSubscribe, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SSLTube$DelegateWrapper$$Lambda$onSubscribe::class$ = nullptr;

$FieldInfo _SSLTube$DelegateWrapper_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SSLTube$DelegateWrapper, $assertionsDisabled)},
	{"delegate", "Ljdk/internal/net/http/common/FlowTube$TubeSubscriber;", nullptr, $PRIVATE | $FINAL, $field(SSLTube$DelegateWrapper, delegate)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $PRIVATE | $FINAL, $field(SSLTube$DelegateWrapper, debug)},
	{"subscribedCalled", "Z", nullptr, $VOLATILE, $field(SSLTube$DelegateWrapper, subscribedCalled)},
	{"subscribedDone", "Z", nullptr, $VOLATILE, $field(SSLTube$DelegateWrapper, subscribedDone)},
	{"completed", "Z", nullptr, $VOLATILE, $field(SSLTube$DelegateWrapper, completed)},
	{"error", "Ljava/lang/Throwable;", nullptr, $VOLATILE, $field(SSLTube$DelegateWrapper, error)},
	{}
};

$MethodInfo _SSLTube$DelegateWrapper_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/Flow$Subscriber;Ljdk/internal/net/http/common/Logger;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;Ljdk/internal/net/http/common/Logger;)V", 0, $method(static_cast<void(SSLTube$DelegateWrapper::*)($Flow$Subscriber*,$Logger*)>(&SSLTube$DelegateWrapper::init$))},
	{"dropSubscription", "()V", nullptr, $PUBLIC},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, $method(static_cast<void(SSLTube$DelegateWrapper::*)($List*)>(&SSLTube$DelegateWrapper::onNext))},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{"onSubscribe", "(Ljava/util/function/Consumer;Ljava/util/concurrent/Flow$Subscription;)V", "(Ljava/util/function/Consumer<Ljava/util/concurrent/Flow$Subscription;>;Ljava/util/concurrent/Flow$Subscription;)V", $PRIVATE, $method(static_cast<void(SSLTube$DelegateWrapper::*)($Consumer*,$Flow$Subscription*)>(&SSLTube$DelegateWrapper::onSubscribe))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SSLTube$DelegateWrapper_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SSLTube$DelegateWrapper", "jdk.internal.net.http.common.SSLTube", "DelegateWrapper", $STATIC | $FINAL},
	{"jdk.internal.net.http.common.FlowTube$TubeSubscriber", "jdk.internal.net.http.common.FlowTube", "TubeSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SSLTube$DelegateWrapper_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.SSLTube$DelegateWrapper",
	"java.lang.Object",
	"jdk.internal.net.http.common.FlowTube$TubeSubscriber",
	_SSLTube$DelegateWrapper_FieldInfo_,
	_SSLTube$DelegateWrapper_MethodInfo_,
	nullptr,
	nullptr,
	_SSLTube$DelegateWrapper_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SSLTube"
};

$Object* allocate$SSLTube$DelegateWrapper($Class* clazz) {
	return $of($alloc(SSLTube$DelegateWrapper));
}

bool SSLTube$DelegateWrapper::$assertionsDisabled = false;

void SSLTube$DelegateWrapper::init$($Flow$Subscriber* delegate, $Logger* debug) {
	$set(this, delegate, $FlowTube::asTubeSubscriber(delegate));
	$set(this, debug, debug);
}

void SSLTube$DelegateWrapper::dropSubscription() {
	if (this->subscribedCalled && !this->completed) {
		$nc(this->delegate)->dropSubscription();
	}
}

void SSLTube$DelegateWrapper::onNext($List* item) {
	if (!SSLTube$DelegateWrapper::$assertionsDisabled && !this->subscribedCalled) {
		$throwNew($AssertionError);
	}
	$nc(this->delegate)->onNext(item);
}

void SSLTube$DelegateWrapper::onSubscribe($Flow$Subscription* subscription) {
	onSubscribe(static_cast<$Consumer*>($$new(SSLTube$DelegateWrapper$$Lambda$onSubscribe, static_cast<$FlowTube$TubeSubscriber*>($nc(this->delegate)))), subscription);
}

void SSLTube$DelegateWrapper::onSubscribe($Consumer* method, $Flow$Subscription* subscription) {
	$useLocalCurrentObjectStackCache();
	this->subscribedCalled = true;
	$nc(method)->accept(subscription);
	$var($Throwable, x, nullptr);
	bool finished = false;
	$synchronized(this) {
		this->subscribedDone = true;
		$assign(x, this->error);
		finished = this->completed;
	}
	if (x != nullptr) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Subscriber completed before subscribe: forwarding %s"_s, $$new($ObjectArray, {$of(x)}));
		}
		$nc(this->delegate)->onError(x);
	} else if (finished) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Subscriber completed before subscribe: calling onComplete()"_s);
		}
		$nc(this->delegate)->onComplete();
	}
}

void SSLTube$DelegateWrapper::onError($Throwable* t) {
	$useLocalCurrentObjectStackCache();
	if (this->completed) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Subscriber already completed: ignoring %s"_s, $$new($ObjectArray, {$of(t)}));
		}
		return;
	}
	bool subscribed = false;
	$synchronized(this) {
		if (this->completed) {
			return;
		}
		$set(this, error, t);
		this->completed = true;
		subscribed = this->subscribedDone;
	}
	if (subscribed) {
		$nc(this->delegate)->onError(t);
	} else if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Subscriber not yet subscribed: stored %s"_s, $$new($ObjectArray, {$of(t)}));
	}
}

void SSLTube$DelegateWrapper::onComplete() {
	if (this->completed) {
		return;
	}
	bool subscribed = false;
	$synchronized(this) {
		if (this->completed) {
			return;
		}
		this->completed = true;
		subscribed = this->subscribedDone;
	}
	if (subscribed) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("DelegateWrapper: completing subscriber"_s);
		}
		$nc(this->delegate)->onComplete();
	} else if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Subscriber not yet subscribed: stored completed=true"_s);
	}
}

$String* SSLTube$DelegateWrapper::toString() {
	$useLocalCurrentObjectStackCache();
	return $str({"DelegateWrapper[subscribedCalled: "_s, $$str(this->subscribedCalled), ", subscribedDone: "_s, $$str(this->subscribedDone), ", completed: "_s, $$str(this->completed), ", error: "_s, this->error, "]: "_s, this->delegate});
}

void SSLTube$DelegateWrapper::onNext(Object$* item) {
	this->onNext($cast($List, item));
}

void clinit$SSLTube$DelegateWrapper($Class* class$) {
	$load($SSLTube);
	SSLTube$DelegateWrapper::$assertionsDisabled = !$SSLTube::class$->desiredAssertionStatus();
}

SSLTube$DelegateWrapper::SSLTube$DelegateWrapper() {
}

$Class* SSLTube$DelegateWrapper::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SSLTube$DelegateWrapper$$Lambda$onSubscribe::classInfo$.name)) {
			return SSLTube$DelegateWrapper$$Lambda$onSubscribe::load$(name, initialize);
		}
	}
	$loadClass(SSLTube$DelegateWrapper, name, initialize, &_SSLTube$DelegateWrapper_ClassInfo_, clinit$SSLTube$DelegateWrapper, allocate$SSLTube$DelegateWrapper);
	return class$;
}

$Class* SSLTube$DelegateWrapper::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk