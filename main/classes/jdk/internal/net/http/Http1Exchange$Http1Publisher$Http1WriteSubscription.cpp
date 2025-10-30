#include <jdk/internal/net/http/Http1Exchange$Http1Publisher$Http1WriteSubscription.h>

#include <java/util/concurrent/Executor.h>
#include <jdk/internal/net/http/Http1Exchange$Http1Publisher.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jdk/internal/net/http/HttpClientImpl$DelegatingExecutor.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Executor = ::java::util::concurrent::Executor;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;
using $Http1Exchange$Http1Publisher = ::jdk::internal::net::http::Http1Exchange$Http1Publisher;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpClientImpl$DelegatingExecutor = ::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Http1Exchange$Http1Publisher$Http1WriteSubscription_FieldInfo_[] = {
	{"this$1", "Ljdk/internal/net/http/Http1Exchange$Http1Publisher;", nullptr, $FINAL | $SYNTHETIC, $field(Http1Exchange$Http1Publisher$Http1WriteSubscription, this$1)},
	{}
};

$MethodInfo _Http1Exchange$Http1Publisher$Http1WriteSubscription_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange$Http1Publisher;)V", nullptr, 0, $method(static_cast<void(Http1Exchange$Http1Publisher$Http1WriteSubscription::*)($Http1Exchange$Http1Publisher*)>(&Http1Exchange$Http1Publisher$Http1WriteSubscription::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"request", "(J)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Http1Exchange$Http1Publisher$Http1WriteSubscription_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Exchange$Http1Publisher", "jdk.internal.net.http.Http1Exchange", "Http1Publisher", $FINAL},
	{"jdk.internal.net.http.Http1Exchange$Http1Publisher$Http1WriteSubscription", "jdk.internal.net.http.Http1Exchange$Http1Publisher", "Http1WriteSubscription", $FINAL},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Http1Exchange$Http1Publisher$Http1WriteSubscription_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Http1Exchange$Http1Publisher$Http1WriteSubscription",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription",
	_Http1Exchange$Http1Publisher$Http1WriteSubscription_FieldInfo_,
	_Http1Exchange$Http1Publisher$Http1WriteSubscription_MethodInfo_,
	nullptr,
	nullptr,
	_Http1Exchange$Http1Publisher$Http1WriteSubscription_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Exchange"
};

$Object* allocate$Http1Exchange$Http1Publisher$Http1WriteSubscription($Class* clazz) {
	return $of($alloc(Http1Exchange$Http1Publisher$Http1WriteSubscription));
}

void Http1Exchange$Http1Publisher$Http1WriteSubscription::init$($Http1Exchange$Http1Publisher* this$1) {
	$set(this, this$1, this$1);
}

void Http1Exchange$Http1Publisher$Http1WriteSubscription::request(int64_t n) {
	$useLocalCurrentObjectStackCache();
	if (this->this$1->cancelled) {
		return;
	}
	$nc(this->this$1->demand)->increase(n);
	if ($nc(this->this$1->debug)->on()) {
		$nc(this->this$1->debug)->log("subscription request(%d), demand=%s"_s, $$new($ObjectArray, {
			$($of($Long::valueOf(n))),
			$of(this->this$1->demand)
		}));
	}
	$nc(this->this$1->writeScheduler)->runOrSchedule($($nc($nc(this->this$1->this$0)->client$)->theExecutor()));
}

void Http1Exchange$Http1Publisher$Http1WriteSubscription::cancel() {
	if ($nc(this->this$1->debug)->on()) {
		$nc(this->this$1->debug)->log("subscription cancelled"_s);
	}
	if (this->this$1->cancelled) {
		return;
	}
	this->this$1->cancelled = true;
	$nc(this->this$1->writeScheduler)->runOrSchedule($($nc($nc(this->this$1->this$0)->client$)->theExecutor()));
}

Http1Exchange$Http1Publisher$Http1WriteSubscription::Http1Exchange$Http1Publisher$Http1WriteSubscription() {
}

$Class* Http1Exchange$Http1Publisher$Http1WriteSubscription::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$Http1Publisher$Http1WriteSubscription, name, initialize, &_Http1Exchange$Http1Publisher$Http1WriteSubscription_ClassInfo_, allocate$Http1Exchange$Http1Publisher$Http1WriteSubscription);
	return class$;
}

$Class* Http1Exchange$Http1Publisher$Http1WriteSubscription::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk