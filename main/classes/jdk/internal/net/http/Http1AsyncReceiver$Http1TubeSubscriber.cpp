#include <jdk/internal/net/http/Http1AsyncReceiver$Http1TubeSubscriber.h>

#include <java/io/EOFException.h>
#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <jdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegate.h>
#include <jdk/internal/net/http/Http1AsyncReceiver.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $EOFException = ::java::io::EOFException;
using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Executor = ::java::util::concurrent::Executor;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $Http1AsyncReceiver = ::jdk::internal::net::http::Http1AsyncReceiver;
using $Http1AsyncReceiver$Http1AsyncDelegate = ::jdk::internal::net::http::Http1AsyncReceiver$Http1AsyncDelegate;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Http1AsyncReceiver$Http1TubeSubscriber_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/Http1AsyncReceiver;", nullptr, $FINAL | $SYNTHETIC, $field(Http1AsyncReceiver$Http1TubeSubscriber, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http1AsyncReceiver$Http1TubeSubscriber, $assertionsDisabled)},
	{"subscription", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $VOLATILE, $field(Http1AsyncReceiver$Http1TubeSubscriber, subscription)},
	{"completed", "Z", nullptr, $VOLATILE, $field(Http1AsyncReceiver$Http1TubeSubscriber, completed)},
	{"dropped", "Z", nullptr, $VOLATILE, $field(Http1AsyncReceiver$Http1TubeSubscriber, dropped)},
	{}
};

$MethodInfo _Http1AsyncReceiver$Http1TubeSubscriber_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Http1AsyncReceiver;)V", nullptr, 0, $method(static_cast<void(Http1AsyncReceiver$Http1TubeSubscriber::*)($Http1AsyncReceiver*)>(&Http1AsyncReceiver$Http1TubeSubscriber::init$))},
	{"dropSubscription", "()V", nullptr, $PUBLIC},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, $method(static_cast<void(Http1AsyncReceiver$Http1TubeSubscriber::*)($List*)>(&Http1AsyncReceiver$Http1TubeSubscriber::onNext))},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{"requestMore", "()V", nullptr, 0, $method(static_cast<void(Http1AsyncReceiver$Http1TubeSubscriber::*)()>(&Http1AsyncReceiver$Http1TubeSubscriber::requestMore))},
	{}
};

$InnerClassInfo _Http1AsyncReceiver$Http1TubeSubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1AsyncReceiver$Http1TubeSubscriber", "jdk.internal.net.http.Http1AsyncReceiver", "Http1TubeSubscriber", $FINAL},
	{"jdk.internal.net.http.common.FlowTube$TubeSubscriber", "jdk.internal.net.http.common.FlowTube", "TubeSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Http1AsyncReceiver$Http1TubeSubscriber_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Http1AsyncReceiver$Http1TubeSubscriber",
	"java.lang.Object",
	"jdk.internal.net.http.common.FlowTube$TubeSubscriber",
	_Http1AsyncReceiver$Http1TubeSubscriber_FieldInfo_,
	_Http1AsyncReceiver$Http1TubeSubscriber_MethodInfo_,
	nullptr,
	nullptr,
	_Http1AsyncReceiver$Http1TubeSubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1AsyncReceiver"
};

$Object* allocate$Http1AsyncReceiver$Http1TubeSubscriber($Class* clazz) {
	return $of($alloc(Http1AsyncReceiver$Http1TubeSubscriber));
}

bool Http1AsyncReceiver$Http1TubeSubscriber::$assertionsDisabled = false;

void Http1AsyncReceiver$Http1TubeSubscriber::init$($Http1AsyncReceiver* this$0) {
	$set(this, this$0, this$0);
}

void Http1AsyncReceiver$Http1TubeSubscriber::onSubscribe($Flow$Subscription* subscription) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("Received onSubscribed from upstream"_s);
	}
	if ($Log::channel()) {
		$Log::logChannel("HTTP/1 read subscriber got subscription from {0}"_s, $$new($ObjectArray, {$($of(this->this$0->describe()))}));
	}
	if (!Http1AsyncReceiver$Http1TubeSubscriber::$assertionsDisabled && !(this->subscription == nullptr || this->dropped == false)) {
		$throwNew($AssertionError);
	}
	$set(this, subscription, subscription);
	this->dropped = false;
	$nc(this->this$0->canRequestMore)->set(true);
	if (this->this$0->delegate != nullptr) {
		$nc(this->this$0->scheduler)->runOrSchedule(this->this$0->executor);
	} else if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("onSubscribe: read delegate not present yet"_s);
	}
}

void Http1AsyncReceiver$Http1TubeSubscriber::requestMore() {
	$var($Flow$Subscription, s, this->subscription);
	if (s == nullptr) {
		return;
	}
	if ($nc(this->this$0->canRequestMore)->compareAndSet(true, false)) {
		if (!this->completed && !this->dropped) {
			if ($nc(this->this$0->debug)->on()) {
				$nc(this->this$0->debug)->log("Http1TubeSubscriber: requesting one more from upstream"_s);
			}
			$nc(s)->request(1);
			return;
		}
	}
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("Http1TubeSubscriber: no need to request more"_s);
	}
}

void Http1AsyncReceiver$Http1TubeSubscriber::onNext($List* item) {
	$useLocalCurrentObjectStackCache();
	$nc(this->this$0->canRequestMore)->set($nc(item)->isEmpty());
	{
		$var($Iterator, i$, $nc(item)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ByteBuffer, buffer, $cast($ByteBuffer, i$->next()));
			{
				this->this$0->asyncReceive(buffer);
			}
		}
	}
}

void Http1AsyncReceiver$Http1TubeSubscriber::onError($Throwable* throwable) {
	this->this$0->onReadError(throwable);
	this->completed = true;
}

void Http1AsyncReceiver$Http1TubeSubscriber::onComplete() {
	this->this$0->onReadError($$new($EOFException, "EOF reached while reading"_s));
	this->completed = true;
}

void Http1AsyncReceiver$Http1TubeSubscriber::dropSubscription() {
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("Http1TubeSubscriber: dropSubscription"_s);
	}
	this->dropped = true;
}

void Http1AsyncReceiver$Http1TubeSubscriber::onNext(Object$* item) {
	this->onNext($cast($List, item));
}

void clinit$Http1AsyncReceiver$Http1TubeSubscriber($Class* class$) {
	$load($Http1AsyncReceiver);
	Http1AsyncReceiver$Http1TubeSubscriber::$assertionsDisabled = !$Http1AsyncReceiver::class$->desiredAssertionStatus();
}

Http1AsyncReceiver$Http1TubeSubscriber::Http1AsyncReceiver$Http1TubeSubscriber() {
}

$Class* Http1AsyncReceiver$Http1TubeSubscriber::load$($String* name, bool initialize) {
	$loadClass(Http1AsyncReceiver$Http1TubeSubscriber, name, initialize, &_Http1AsyncReceiver$Http1TubeSubscriber_ClassInfo_, clinit$Http1AsyncReceiver$Http1TubeSubscriber, allocate$Http1AsyncReceiver$Http1TubeSubscriber);
	return class$;
}

$Class* Http1AsyncReceiver$Http1TubeSubscriber::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk