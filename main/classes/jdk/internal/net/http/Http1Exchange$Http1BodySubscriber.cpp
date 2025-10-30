#include <jdk/internal/net/http/Http1Exchange$Http1BodySubscriber.h>

#include <java/lang/AssertionError.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/List.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <jdk/internal/net/http/Http1Exchange$Http1BodySubscriber$1.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jcpp.h>

#undef COMPLETED

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $List = ::java::util::List;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;
using $Http1Exchange$Http1BodySubscriber$1 = ::jdk::internal::net::http::Http1Exchange$Http1BodySubscriber$1;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Http1Exchange$Http1BodySubscriber_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http1Exchange$Http1BodySubscriber, $assertionsDisabled)},
	{"whenSubscribed", "Ljdk/internal/net/http/common/MinimalFuture;", "Ljdk/internal/net/http/common/MinimalFuture<Ljava/util/concurrent/Flow$Subscription;>;", $FINAL, $field(Http1Exchange$Http1BodySubscriber, whenSubscribed)},
	{"subscription", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $PRIVATE | $VOLATILE, $field(Http1Exchange$Http1BodySubscriber, subscription)},
	{"complete", "Z", nullptr, $VOLATILE, $field(Http1Exchange$Http1BodySubscriber, complete)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $PRIVATE | $FINAL, $field(Http1Exchange$Http1BodySubscriber, debug)},
	{"COMPLETED", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/ByteBuffer;>;", $STATIC | $FINAL, $staticField(Http1Exchange$Http1BodySubscriber, COMPLETED)},
	{}
};

$MethodInfo _Http1Exchange$Http1BodySubscriber_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/Logger;)V", nullptr, 0, $method(static_cast<void(Http1Exchange$Http1BodySubscriber::*)($Logger*)>(&Http1Exchange$Http1BodySubscriber::init$))},
	{"cancelSubscription", "()V", nullptr, $FINAL, $method(static_cast<void(Http1Exchange$Http1BodySubscriber::*)()>(&Http1Exchange$Http1BodySubscriber::cancelSubscription))},
	{"completeSubscriber", "(Ljdk/internal/net/http/common/Logger;)Ljdk/internal/net/http/Http1Exchange$Http1BodySubscriber;", nullptr, $STATIC, $method(static_cast<Http1Exchange$Http1BodySubscriber*(*)($Logger*)>(&Http1Exchange$Http1BodySubscriber::completeSubscriber))},
	{"currentStateMessage", "()Ljava/lang/String;", nullptr, $ABSTRACT},
	{"isSubscribed", "()Z", nullptr, $FINAL, $method(static_cast<bool(Http1Exchange$Http1BodySubscriber::*)()>(&Http1Exchange$Http1BodySubscriber::isSubscribed))},
	{"request", "(J)V", nullptr, $FINAL, $method(static_cast<void(Http1Exchange$Http1BodySubscriber::*)(int64_t)>(&Http1Exchange$Http1BodySubscriber::request))},
	{"setSubscription", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $FINAL, $method(static_cast<void(Http1Exchange$Http1BodySubscriber::*)($Flow$Subscription*)>(&Http1Exchange$Http1BodySubscriber::setSubscription))},
	{}
};

$InnerClassInfo _Http1Exchange$Http1BodySubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Exchange$Http1BodySubscriber", "jdk.internal.net.http.Http1Exchange", "Http1BodySubscriber", $STATIC | $ABSTRACT},
	{"java.util.concurrent.Flow$Subscriber", "java.util.concurrent.Flow", "Subscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.Http1Exchange$Http1BodySubscriber$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Http1Exchange$Http1BodySubscriber_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.Http1Exchange$Http1BodySubscriber",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscriber",
	_Http1Exchange$Http1BodySubscriber_FieldInfo_,
	_Http1Exchange$Http1BodySubscriber_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/concurrent/Flow$Subscriber<Ljava/nio/ByteBuffer;>;",
	nullptr,
	_Http1Exchange$Http1BodySubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Exchange"
};

$Object* allocate$Http1Exchange$Http1BodySubscriber($Class* clazz) {
	return $of($alloc(Http1Exchange$Http1BodySubscriber));
}

bool Http1Exchange$Http1BodySubscriber::$assertionsDisabled = false;
$List* Http1Exchange$Http1BodySubscriber::COMPLETED = nullptr;

void Http1Exchange$Http1BodySubscriber::init$($Logger* debug) {
	$set(this, whenSubscribed, $new($MinimalFuture));
	if (!Http1Exchange$Http1BodySubscriber::$assertionsDisabled && !(debug != nullptr)) {
		$throwNew($AssertionError);
	}
	$set(this, debug, debug);
}

void Http1Exchange$Http1BodySubscriber::request(int64_t n) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Http1BodySubscriber requesting %d, from %s"_s, $$new($ObjectArray, {
			$($of($Long::valueOf(n))),
			$of(this->subscription)
		}));
	}
	$nc(this->subscription)->request(n);
}

bool Http1Exchange$Http1BodySubscriber::isSubscribed() {
	return this->subscription != nullptr;
}

void Http1Exchange$Http1BodySubscriber::setSubscription($Flow$Subscription* subscription) {
	$set(this, subscription, subscription);
	$nc(this->whenSubscribed)->complete(subscription);
}

void Http1Exchange$Http1BodySubscriber::cancelSubscription() {
	$useLocalCurrentObjectStackCache();
	try {
		$nc(this->subscription)->cancel();
	} catch ($Throwable& t) {
		$var($String, msg, "Ignoring exception raised when canceling BodyPublisher subscription"_s);
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("%s: %s"_s, $$new($ObjectArray, {
				$of(msg),
				$of(t)
			}));
		}
		$Log::logError("{0}: {1}"_s, $$new($ObjectArray, {
			$of(msg),
			$of(t)
		}));
	}
}

Http1Exchange$Http1BodySubscriber* Http1Exchange$Http1BodySubscriber::completeSubscriber($Logger* debug) {
	$init(Http1Exchange$Http1BodySubscriber);
	return $new($Http1Exchange$Http1BodySubscriber$1, debug);
}

void clinit$Http1Exchange$Http1BodySubscriber($Class* class$) {
	$load($Http1Exchange);
	Http1Exchange$Http1BodySubscriber::$assertionsDisabled = !$Http1Exchange::class$->desiredAssertionStatus();
	$assignStatic(Http1Exchange$Http1BodySubscriber::COMPLETED, $List::of($($of($ByteBuffer::allocate(0)))));
}

Http1Exchange$Http1BodySubscriber::Http1Exchange$Http1BodySubscriber() {
}

$Class* Http1Exchange$Http1BodySubscriber::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$Http1BodySubscriber, name, initialize, &_Http1Exchange$Http1BodySubscriber_ClassInfo_, clinit$Http1Exchange$Http1BodySubscriber, allocate$Http1Exchange$Http1BodySubscriber);
	return class$;
}

$Class* Http1Exchange$Http1BodySubscriber::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk