#include <jdk/internal/net/http/SocketTube$InternalReadPublisher.h>

#include <java/util/Objects.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher$InternalReadSubscription.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher$ReadSubscription.h>
#include <jdk/internal/net/http/SocketTube.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Objects = ::java::util::Objects;
using $Flow$Publisher = ::java::util::concurrent::Flow$Publisher;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $SocketTube = ::jdk::internal::net::http::SocketTube;
using $SocketTube$InternalReadPublisher$InternalReadSubscription = ::jdk::internal::net::http::SocketTube$InternalReadPublisher$InternalReadSubscription;
using $SocketTube$InternalReadPublisher$ReadSubscription = ::jdk::internal::net::http::SocketTube$InternalReadPublisher$ReadSubscription;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _SocketTube$InternalReadPublisher_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/SocketTube;", nullptr, $FINAL | $SYNTHETIC, $field(SocketTube$InternalReadPublisher, this$0)},
	{"subscriptionImpl", "Ljdk/internal/net/http/SocketTube$InternalReadPublisher$InternalReadSubscription;", nullptr, $PRIVATE | $FINAL, $field(SocketTube$InternalReadPublisher, subscriptionImpl)},
	{"pendingSubscription", "Ljava/util/concurrent/atomic/AtomicReference;", "Ljava/util/concurrent/atomic/AtomicReference<Ljdk/internal/net/http/SocketTube$InternalReadPublisher$ReadSubscription;>;", 0, $field(SocketTube$InternalReadPublisher, pendingSubscription)},
	{"subscription", "Ljdk/internal/net/http/SocketTube$InternalReadPublisher$ReadSubscription;", nullptr, $PRIVATE | $VOLATILE, $field(SocketTube$InternalReadPublisher, subscription)},
	{}
};

$MethodInfo _SocketTube$InternalReadPublisher_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/SocketTube;)V", nullptr, $PRIVATE, $method(static_cast<void(SocketTube$InternalReadPublisher::*)($SocketTube*)>(&SocketTube$InternalReadPublisher::init$))},
	{"signalError", "(Ljava/lang/Throwable;)V", nullptr, 0, $method(static_cast<void(SocketTube$InternalReadPublisher::*)($Throwable*)>(&SocketTube$InternalReadPublisher::signalError))},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", $PUBLIC},
	{}
};

$InnerClassInfo _SocketTube$InternalReadPublisher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.SocketTube$InternalReadPublisher", "jdk.internal.net.http.SocketTube", "InternalReadPublisher", $PRIVATE | $FINAL},
	{"java.util.concurrent.Flow$Publisher", "java.util.concurrent.Flow", "Publisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.SocketTube$InternalReadPublisher$ReadEvent", "jdk.internal.net.http.SocketTube$InternalReadPublisher", "ReadEvent", $FINAL},
	{"jdk.internal.net.http.SocketTube$InternalReadPublisher$InternalReadSubscription", "jdk.internal.net.http.SocketTube$InternalReadPublisher", "InternalReadSubscription", $FINAL},
	{"jdk.internal.net.http.SocketTube$InternalReadPublisher$ReadSubscription", "jdk.internal.net.http.SocketTube$InternalReadPublisher", "ReadSubscription", $FINAL},
	{}
};

$ClassInfo _SocketTube$InternalReadPublisher_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.SocketTube$InternalReadPublisher",
	"java.lang.Object",
	"java.util.concurrent.Flow$Publisher",
	_SocketTube$InternalReadPublisher_FieldInfo_,
	_SocketTube$InternalReadPublisher_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/concurrent/Flow$Publisher<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;",
	nullptr,
	_SocketTube$InternalReadPublisher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.SocketTube"
};

$Object* allocate$SocketTube$InternalReadPublisher($Class* clazz) {
	return $of($alloc(SocketTube$InternalReadPublisher));
}

void SocketTube$InternalReadPublisher::init$($SocketTube* this$0) {
	$set(this, this$0, this$0);
	$set(this, subscriptionImpl, $new($SocketTube$InternalReadPublisher$InternalReadSubscription, this));
	$set(this, pendingSubscription, $new($AtomicReference));
}

void SocketTube$InternalReadPublisher::subscribe($Flow$Subscriber* s) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(s);
	$var($FlowTube$TubeSubscriber, sub, $FlowTube::asTubeSubscriber(s));
	$var($SocketTube$InternalReadPublisher$ReadSubscription, target, $new($SocketTube$InternalReadPublisher$ReadSubscription, this, this->subscriptionImpl, sub));
	$var($SocketTube$InternalReadPublisher$ReadSubscription, previous, $cast($SocketTube$InternalReadPublisher$ReadSubscription, $nc(this->pendingSubscription)->getAndSet(target)));
	if (previous != nullptr && previous != target) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log($$str({"read publisher: dropping pending subscriber: "_s, previous->subscriber}));
		}
		$nc(previous->errorRef)->compareAndSet(nullptr, $cast($Throwable, $($nc(this->this$0->errorRef)->get())));
		previous->signalOnSubscribe();
		if ($nc(this->subscriptionImpl)->completed) {
			previous->signalCompletion();
		} else {
			$nc(previous->subscriber)->dropSubscription();
		}
	}
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("read publisher got subscriber"_s);
	}
	$nc(this->subscriptionImpl)->signalSubscribe();
	this->this$0->debugState("leaving read.subscribe: "_s);
}

void SocketTube$InternalReadPublisher::signalError($Throwable* error) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log($$str({"error signalled "_s, error}));
	}
	if (!$nc(this->this$0->errorRef)->compareAndSet(nullptr, error)) {
		return;
	}
	if ($Log::channel()) {
		$Log::logChannel("Error signalled on channel {0}: {1}"_s, $$new($ObjectArray, {
			$($of(this->this$0->channelDescr())),
			$of(error)
		}));
	}
	$nc(this->subscriptionImpl)->handleError();
}

SocketTube$InternalReadPublisher::SocketTube$InternalReadPublisher() {
}

$Class* SocketTube$InternalReadPublisher::load$($String* name, bool initialize) {
	$loadClass(SocketTube$InternalReadPublisher, name, initialize, &_SocketTube$InternalReadPublisher_ClassInfo_, allocate$SocketTube$InternalReadPublisher);
	return class$;
}

$Class* SocketTube$InternalReadPublisher::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk