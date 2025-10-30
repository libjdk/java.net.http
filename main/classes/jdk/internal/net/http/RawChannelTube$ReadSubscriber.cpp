#include <jdk/internal/net/http/RawChannelTube$ReadSubscriber.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <java/util/concurrent/ConcurrentLinkedQueue.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/RawChannelTube.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/websocket/RawChannel$RawEvent.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $ConcurrentLinkedQueue = ::java::util::concurrent::ConcurrentLinkedQueue;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $Supplier = ::java::util::function::Supplier;
using $RawChannelTube = ::jdk::internal::net::http::RawChannelTube;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $RawChannel$RawEvent = ::jdk::internal::net::http::websocket::RawChannel$RawEvent;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0 : public $Supplier {
	$class(RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0, $NO_CLASS_INIT, $Supplier)
public:
	void init$($List* item) {
		$set(this, item, item);
	}
	virtual $Object* get() override {
		 return $of(RawChannelTube$ReadSubscriber::lambda$onNext$0(item));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0>());
	}
	$List* item = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0::fieldInfos[2] = {
	{"item", "Ljava/util/List;", nullptr, $PUBLIC, $field(RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0, item)},
	{}
};
$MethodInfo RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/List;)V", nullptr, $PUBLIC, $method(static_cast<void(RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0::*)($List*)>(&RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0::load$($String* name, bool initialize) {
	$loadClass(RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0::class$ = nullptr;

$FieldInfo _RawChannelTube$ReadSubscriber_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/RawChannelTube;", nullptr, $FINAL | $SYNTHETIC, $field(RawChannelTube$ReadSubscriber, this$0)},
	{"readSubscription", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $VOLATILE, $field(RawChannelTube$ReadSubscriber, readSubscription)},
	{"completed", "Z", nullptr, $VOLATILE, $field(RawChannelTube$ReadSubscriber, completed)},
	{"initialRequest", "J", nullptr, 0, $field(RawChannelTube$ReadSubscriber, initialRequest)},
	{"events", "Ljava/util/concurrent/ConcurrentLinkedQueue;", "Ljava/util/concurrent/ConcurrentLinkedQueue<Ljdk/internal/net/http/websocket/RawChannel$RawEvent;>;", $FINAL, $field(RawChannelTube$ReadSubscriber, events)},
	{"buffers", "Ljava/util/concurrent/ConcurrentLinkedQueue;", "Ljava/util/concurrent/ConcurrentLinkedQueue<Ljava/nio/ByteBuffer;>;", $FINAL, $field(RawChannelTube$ReadSubscriber, buffers)},
	{"errorRef", "Ljava/util/concurrent/atomic/AtomicReference;", "Ljava/util/concurrent/atomic/AtomicReference<Ljava/lang/Throwable;>;", $FINAL, $field(RawChannelTube$ReadSubscriber, errorRef)},
	{}
};

$MethodInfo _RawChannelTube$ReadSubscriber_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/RawChannelTube;)V", nullptr, 0, $method(static_cast<void(RawChannelTube$ReadSubscriber::*)($RawChannelTube*)>(&RawChannelTube$ReadSubscriber::init$))},
	{"checkEvents", "()V", nullptr, 0},
	{"lambda$onNext$0", "(Ljava/util/List;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($List*)>(&RawChannelTube$ReadSubscriber::lambda$onNext$0))},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _RawChannelTube$ReadSubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RawChannelTube$ReadSubscriber", "jdk.internal.net.http.RawChannelTube", "ReadSubscriber", 0},
	{"jdk.internal.net.http.common.FlowTube$TubeSubscriber", "jdk.internal.net.http.common.FlowTube", "TubeSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RawChannelTube$ReadSubscriber_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.RawChannelTube$ReadSubscriber",
	"java.lang.Object",
	"jdk.internal.net.http.common.FlowTube$TubeSubscriber",
	_RawChannelTube$ReadSubscriber_FieldInfo_,
	_RawChannelTube$ReadSubscriber_MethodInfo_,
	nullptr,
	nullptr,
	_RawChannelTube$ReadSubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RawChannelTube"
};

$Object* allocate$RawChannelTube$ReadSubscriber($Class* clazz) {
	return $of($alloc(RawChannelTube$ReadSubscriber));
}

void RawChannelTube$ReadSubscriber::init$($RawChannelTube* this$0) {
	$set(this, this$0, this$0);
	$set(this, events, $new($ConcurrentLinkedQueue));
	$set(this, buffers, $new($ConcurrentLinkedQueue));
	$set(this, errorRef, $new($AtomicReference));
}

void RawChannelTube$ReadSubscriber::checkEvents() {
	$useLocalCurrentObjectStackCache();
	$var($Flow$Subscription, subscription, this->readSubscription);
	if (subscription != nullptr) {
		$var($Throwable, error, $cast($Throwable, $nc(this->errorRef)->get()));
		while (true) {
			bool var$0 = !$nc(this->buffers)->isEmpty() || error != nullptr;
			if (!(var$0 || $nc(this->this$0->closed)->get() || this->completed)) {
				break;
			}
			{
				$var($RawChannel$RawEvent, event, $cast($RawChannel$RawEvent, $nc(this->events)->poll()));
				if (event == nullptr) {
					break;
				}
				if ($nc(this->this$0->debug)->on()) {
					$nc(this->this$0->debug)->log("ReadSubscriber: handling event"_s);
				}
				$nc(event)->handle();
			}
		}
	}
}

void RawChannelTube$ReadSubscriber::onSubscribe($Flow$Subscription* subscription) {
	$useLocalCurrentObjectStackCache();
	int64_t n = 0;
	$synchronized(this) {
		$set(this, readSubscription, subscription);
		n = this->initialRequest;
		this->initialRequest = 0;
	}
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("ReadSubscriber::onSubscribe"_s);
	}
	if (n > 0) {
		$var($Throwable, error, $cast($Throwable, $nc(this->errorRef)->get()));
		if (error == nullptr && !$nc(this->this$0->closed)->get() && !this->completed) {
			if ($nc(this->this$0->debug)->on()) {
				$nc(this->this$0->debug)->log($$str({"readSubscription: requesting "_s, $$str(n)}));
			}
			$nc(subscription)->request(n);
		}
	}
	checkEvents();
}

void RawChannelTube$ReadSubscriber::onNext($List* item) {
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log(static_cast<$Supplier*>($$new(RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0, item)));
	}
	$nc(this->buffers)->addAll(item);
	checkEvents();
}

void RawChannelTube$ReadSubscriber::onError($Throwable* throwable) {
	bool var$0 = $nc(this->this$0->closed)->get();
	if (var$0 || $nc(this->errorRef)->compareAndSet(nullptr, throwable)) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("ReadSubscriber::onError"_s, throwable);
		}
		if ($nc(this->buffers)->isEmpty()) {
			checkEvents();
			this->this$0->shutdownInput();
		}
	}
}

void RawChannelTube$ReadSubscriber::onComplete() {
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("ReadSubscriber::onComplete"_s);
	}
	this->completed = true;
	if ($nc(this->buffers)->isEmpty()) {
		checkEvents();
		this->this$0->shutdownInput();
	}
}

void RawChannelTube$ReadSubscriber::onNext(Object$* item) {
	this->onNext($cast($List, item));
}

$String* RawChannelTube$ReadSubscriber::lambda$onNext$0($List* item) {
	$init(RawChannelTube$ReadSubscriber);
	return $str({"ReadSubscriber::onNext "_s, $$str($Utils::remaining(item)), " bytes"_s});
}

RawChannelTube$ReadSubscriber::RawChannelTube$ReadSubscriber() {
}

$Class* RawChannelTube$ReadSubscriber::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0::classInfo$.name)) {
			return RawChannelTube$ReadSubscriber$$Lambda$lambda$onNext$0::load$(name, initialize);
		}
	}
	$loadClass(RawChannelTube$ReadSubscriber, name, initialize, &_RawChannelTube$ReadSubscriber_ClassInfo_, allocate$RawChannelTube$ReadSubscriber);
	return class$;
}

$Class* RawChannelTube$ReadSubscriber::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk