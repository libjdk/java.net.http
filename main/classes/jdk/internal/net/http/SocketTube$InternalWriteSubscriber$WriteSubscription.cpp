#include <jdk/internal/net/http/SocketTube$InternalWriteSubscriber$WriteSubscription.h>

#include <java/util/concurrent/Flow$Subscription.h>
#include <jdk/internal/net/http/SocketTube$InternalWriteSubscriber.h>
#include <jdk/internal/net/http/SocketTube.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $SocketTube = ::jdk::internal::net::http::SocketTube;
using $SocketTube$InternalWriteSubscriber = ::jdk::internal::net::http::SocketTube$InternalWriteSubscriber;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _SocketTube$InternalWriteSubscriber$WriteSubscription_FieldInfo_[] = {
	{"this$1", "Ljdk/internal/net/http/SocketTube$InternalWriteSubscriber;", nullptr, $FINAL | $SYNTHETIC, $field(SocketTube$InternalWriteSubscriber$WriteSubscription, this$1)},
	{"upstreamSubscription", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $FINAL, $field(SocketTube$InternalWriteSubscriber$WriteSubscription, upstreamSubscription)},
	{"cancelled", "Z", nullptr, $VOLATILE, $field(SocketTube$InternalWriteSubscriber$WriteSubscription, cancelled)},
	{}
};

$MethodInfo _SocketTube$InternalWriteSubscriber$WriteSubscription_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/SocketTube$InternalWriteSubscriber;Ljava/util/concurrent/Flow$Subscription;)V", nullptr, 0, $method(static_cast<void(SocketTube$InternalWriteSubscriber$WriteSubscription::*)($SocketTube$InternalWriteSubscriber*,$Flow$Subscription*)>(&SocketTube$InternalWriteSubscriber$WriteSubscription::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"dropSubscription", "()V", nullptr, 0, $method(static_cast<void(SocketTube$InternalWriteSubscriber$WriteSubscription::*)()>(&SocketTube$InternalWriteSubscriber$WriteSubscription::dropSubscription))},
	{"request", "(J)V", nullptr, $PUBLIC},
	{"requestMore", "()V", nullptr, 0, $method(static_cast<void(SocketTube$InternalWriteSubscriber$WriteSubscription::*)()>(&SocketTube$InternalWriteSubscriber$WriteSubscription::requestMore))},
	{}
};

$InnerClassInfo _SocketTube$InternalWriteSubscriber$WriteSubscription_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.SocketTube$InternalWriteSubscriber", "jdk.internal.net.http.SocketTube", "InternalWriteSubscriber", $PRIVATE | $FINAL},
	{"jdk.internal.net.http.SocketTube$InternalWriteSubscriber$WriteSubscription", "jdk.internal.net.http.SocketTube$InternalWriteSubscriber", "WriteSubscription", $FINAL},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SocketTube$InternalWriteSubscriber$WriteSubscription_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.SocketTube$InternalWriteSubscriber$WriteSubscription",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription",
	_SocketTube$InternalWriteSubscriber$WriteSubscription_FieldInfo_,
	_SocketTube$InternalWriteSubscriber$WriteSubscription_MethodInfo_,
	nullptr,
	nullptr,
	_SocketTube$InternalWriteSubscriber$WriteSubscription_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.SocketTube"
};

$Object* allocate$SocketTube$InternalWriteSubscriber$WriteSubscription($Class* clazz) {
	return $of($alloc(SocketTube$InternalWriteSubscriber$WriteSubscription));
}

void SocketTube$InternalWriteSubscriber$WriteSubscription::init$($SocketTube$InternalWriteSubscriber* this$1, $Flow$Subscription* subscription) {
	$set(this, this$1, this$1);
	$set(this, upstreamSubscription, subscription);
}

void SocketTube$InternalWriteSubscriber$WriteSubscription::request(int64_t n) {
	if (this->cancelled) {
		return;
	}
	$nc(this->upstreamSubscription)->request(n);
}

void SocketTube$InternalWriteSubscriber$WriteSubscription::cancel() {
	if (this->cancelled) {
		return;
	}
	if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log("write: cancel"_s);
	}
	if ($Log::channel()) {
		$Log::logChannel("Cancelling write subscription"_s, $$new($ObjectArray, 0));
	}
	dropSubscription();
	$nc(this->upstreamSubscription)->cancel();
}

void SocketTube$InternalWriteSubscriber$WriteSubscription::dropSubscription() {
	$synchronized(this->this$1) {
		this->cancelled = true;
		if ($nc($nc(this->this$1->this$0)->debug)->on()) {
			$nc($nc(this->this$1->this$0)->debug)->log("write: resetting demand to 0"_s);
		}
		$nc(this->this$1->writeDemand)->reset();
	}
}

void SocketTube$InternalWriteSubscriber$WriteSubscription::requestMore() {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				if (this->this$1->completed || this->cancelled) {
					return$1 = true;
					goto $finally;
				}
				bool requestMore = false;
				int64_t d = 0;
				$synchronized(this->this$1) {
					if (this->cancelled) {
						return$1 = true;
						goto $finally;
					}
					d = $nc(this->this$1->writeDemand)->get();
					requestMore = $nc(this->this$1->writeDemand)->increaseIfFulfilled();
				}
				if (requestMore) {
					if ($nc($nc(this->this$1->this$0)->debug)->on()) {
						$nc($nc(this->this$1->this$0)->debug)->log("write: requesting more..."_s);
					}
					$nc(this->upstreamSubscription)->request(1);
				} else if ($nc($nc(this->this$1->this$0)->debug)->on()) {
					$nc($nc(this->this$1->this$0)->debug)->log("write: no need to request more: %d"_s, $$new($ObjectArray, {$($of($Long::valueOf(d)))}));
				}
			} catch ($Throwable& t) {
				if ($nc($nc(this->this$1->this$0)->debug)->on()) {
					$nc($nc(this->this$1->this$0)->debug)->log($$str({"write: error while requesting more: "_s, t}));
				}
				this->this$1->signalError(t);
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			$nc(this->this$1->this$0)->debugState("leaving requestMore: "_s);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

SocketTube$InternalWriteSubscriber$WriteSubscription::SocketTube$InternalWriteSubscriber$WriteSubscription() {
}

$Class* SocketTube$InternalWriteSubscriber$WriteSubscription::load$($String* name, bool initialize) {
	$loadClass(SocketTube$InternalWriteSubscriber$WriteSubscription, name, initialize, &_SocketTube$InternalWriteSubscriber$WriteSubscription_ClassInfo_, allocate$SocketTube$InternalWriteSubscriber$WriteSubscription);
	return class$;
}

$Class* SocketTube$InternalWriteSubscriber$WriteSubscription::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk