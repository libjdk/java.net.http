#include <jdk/internal/net/http/common/SSLTube$SSLTubeFlowDelegate.h>

#include <java/lang/AssertionError.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/Flow$Processor.h>
#include <java/util/concurrent/Flow$Publisher.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/function/Consumer.h>
#include <javax/net/ssl/SSLEngine.h>
#include <jdk/internal/net/http/common/FlowTube$TubePublisher.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Reader.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Writer.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate.h>
#include <jdk/internal/net/http/common/SSLTube$SSLSubscriberWrapper.h>
#include <jdk/internal/net/http/common/SSLTube$SSLSubscriptionWrapper.h>
#include <jdk/internal/net/http/common/SSLTube.h>
#include <jdk/internal/net/http/common/SubscriberWrapper$SchedulingAction.h>
#include <jdk/internal/net/http/common/SubscriberWrapper.h>
#include <jcpp.h>

#undef CONTINUE

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Executor = ::java::util::concurrent::Executor;
using $Flow$Processor = ::java::util::concurrent::Flow$Processor;
using $Flow$Publisher = ::java::util::concurrent::Flow$Publisher;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Consumer = ::java::util::function::Consumer;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $FlowTube$TubePublisher = ::jdk::internal::net::http::common::FlowTube$TubePublisher;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $SSLFlowDelegate = ::jdk::internal::net::http::common::SSLFlowDelegate;
using $SSLFlowDelegate$Reader = ::jdk::internal::net::http::common::SSLFlowDelegate$Reader;
using $SSLFlowDelegate$Writer = ::jdk::internal::net::http::common::SSLFlowDelegate$Writer;
using $SSLTube = ::jdk::internal::net::http::common::SSLTube;
using $SSLTube$SSLSubscriberWrapper = ::jdk::internal::net::http::common::SSLTube$SSLSubscriberWrapper;
using $SSLTube$SSLSubscriptionWrapper = ::jdk::internal::net::http::common::SSLTube$SSLSubscriptionWrapper;
using $SubscriberWrapper = ::jdk::internal::net::http::common::SubscriberWrapper;
using $SubscriberWrapper$SchedulingAction = ::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SSLTube$SSLTubeFlowDelegate_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/common/SSLTube;", nullptr, $FINAL | $SYNTHETIC, $field(SSLTube$SSLTubeFlowDelegate, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SSLTube$SSLTubeFlowDelegate, $assertionsDisabled)},
	{}
};

$MethodInfo _SSLTube$SSLTubeFlowDelegate_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/SSLTube;Ljavax/net/ssl/SSLEngine;Ljava/util/concurrent/Executor;Ljava/util/function/Consumer;Ljdk/internal/net/http/common/SSLTube$SSLSubscriberWrapper;Ljdk/internal/net/http/common/FlowTube;)V", "(Ljavax/net/ssl/SSLEngine;Ljava/util/concurrent/Executor;Ljava/util/function/Consumer<Ljava/nio/ByteBuffer;>;Ljdk/internal/net/http/common/SSLTube$SSLSubscriberWrapper;Ljdk/internal/net/http/common/FlowTube;)V", 0, $method(static_cast<void(SSLTube$SSLTubeFlowDelegate::*)($SSLTube*,$SSLEngine*,$Executor*,$Consumer*,$SSLTube$SSLSubscriberWrapper*,$FlowTube*)>(&SSLTube$SSLTubeFlowDelegate::init$))},
	{"checkForHandshake", "(Ljava/lang/Throwable;)Ljava/lang/Throwable;", nullptr, $PROTECTED},
	{"connect", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", 0},
	{"enterReadScheduling", "()Ljdk/internal/net/http/common/SubscriberWrapper$SchedulingAction;", nullptr, $PROTECTED},
	{}
};

$InnerClassInfo _SSLTube$SSLTubeFlowDelegate_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SSLTube$SSLTubeFlowDelegate", "jdk.internal.net.http.common.SSLTube", "SSLTubeFlowDelegate", $FINAL},
	{}
};

$ClassInfo _SSLTube$SSLTubeFlowDelegate_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.SSLTube$SSLTubeFlowDelegate",
	"jdk.internal.net.http.common.SSLFlowDelegate",
	nullptr,
	_SSLTube$SSLTubeFlowDelegate_FieldInfo_,
	_SSLTube$SSLTubeFlowDelegate_MethodInfo_,
	nullptr,
	nullptr,
	_SSLTube$SSLTubeFlowDelegate_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SSLTube"
};

$Object* allocate$SSLTube$SSLTubeFlowDelegate($Class* clazz) {
	return $of($alloc(SSLTube$SSLTubeFlowDelegate));
}

bool SSLTube$SSLTubeFlowDelegate::$assertionsDisabled = false;

void SSLTube$SSLTubeFlowDelegate::init$($SSLTube* this$0, $SSLEngine* engine, $Executor* executor, $Consumer* recycler, $SSLTube$SSLSubscriberWrapper* readSubscriber, $FlowTube* tube) {
	$set(this, this$0, this$0);
	$SSLFlowDelegate::init$(engine, executor, recycler, readSubscriber, tube);
}

$SubscriberWrapper$SchedulingAction* SSLTube$SSLTubeFlowDelegate::enterReadScheduling() {
	$nc(this->this$0->readSubscriber)->processPendingSubscriber();
	$init($SubscriberWrapper$SchedulingAction);
	return $SubscriberWrapper$SchedulingAction::CONTINUE;
}

void SSLTube$SSLTubeFlowDelegate::connect($Flow$Subscriber* downReader, $Flow$Subscriber* downWriter) {
	$useLocalCurrentObjectStackCache();
	if (!SSLTube$SSLTubeFlowDelegate::$assertionsDisabled && !$equals(downWriter, this->this$0->tube)) {
		$throwNew($AssertionError);
	}
	if (!SSLTube$SSLTubeFlowDelegate::$assertionsDisabled && !$equals(downReader, this->this$0->readSubscriber)) {
		$throwNew($AssertionError);
	}
	$nc(this->reader)->subscribe(downReader);
	$var($FlowTube$TubePublisher, var$0, $FlowTube::asTubePublisher(this->writer));
	$nc(this->this$0->tube)->connectFlows(var$0, $($FlowTube::asTubeSubscriber($(upstreamReader()))));
	$nc($(upstreamWriter()))->onSubscribe(this->this$0->writeSubscription);
}

$Throwable* SSLTube$SSLTubeFlowDelegate::checkForHandshake($Throwable* t) {
	return this->this$0->checkForHandshake(t);
}

void clinit$SSLTube$SSLTubeFlowDelegate($Class* class$) {
	$load($SSLTube);
	SSLTube$SSLTubeFlowDelegate::$assertionsDisabled = !$SSLTube::class$->desiredAssertionStatus();
}

SSLTube$SSLTubeFlowDelegate::SSLTube$SSLTubeFlowDelegate() {
}

$Class* SSLTube$SSLTubeFlowDelegate::load$($String* name, bool initialize) {
	$loadClass(SSLTube$SSLTubeFlowDelegate, name, initialize, &_SSLTube$SSLTubeFlowDelegate_ClassInfo_, clinit$SSLTube$SSLTubeFlowDelegate, allocate$SSLTube$SSLTubeFlowDelegate);
	return class$;
}

$Class* SSLTube$SSLTubeFlowDelegate::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk