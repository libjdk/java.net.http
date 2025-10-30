#include <jdk/internal/net/http/common/SSLTube$SSLSubscriptionWrapper.h>

#include <java/util/concurrent/Flow$Subscription.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SSLTube.h>
#include <jcpp.h>

using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SSLTube = ::jdk::internal::net::http::common::SSLTube;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SSLTube$SSLSubscriptionWrapper_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/common/SSLTube;", nullptr, $FINAL | $SYNTHETIC, $field(SSLTube$SSLSubscriptionWrapper, this$0)},
	{"delegate", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $VOLATILE, $field(SSLTube$SSLSubscriptionWrapper, delegate)},
	{"cancelled", "Z", nullptr, $PRIVATE | $VOLATILE, $field(SSLTube$SSLSubscriptionWrapper, cancelled)},
	{}
};

$MethodInfo _SSLTube$SSLSubscriptionWrapper_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/SSLTube;)V", nullptr, 0, $method(static_cast<void(SSLTube$SSLSubscriptionWrapper::*)($SSLTube*)>(&SSLTube$SSLSubscriptionWrapper::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"request", "(J)V", nullptr, $PUBLIC},
	{"setSubscription", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, 0, $method(static_cast<void(SSLTube$SSLSubscriptionWrapper::*)($Flow$Subscription*)>(&SSLTube$SSLSubscriptionWrapper::setSubscription))},
	{}
};

$InnerClassInfo _SSLTube$SSLSubscriptionWrapper_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SSLTube$SSLSubscriptionWrapper", "jdk.internal.net.http.common.SSLTube", "SSLSubscriptionWrapper", $FINAL},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SSLTube$SSLSubscriptionWrapper_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.SSLTube$SSLSubscriptionWrapper",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription",
	_SSLTube$SSLSubscriptionWrapper_FieldInfo_,
	_SSLTube$SSLSubscriptionWrapper_MethodInfo_,
	nullptr,
	nullptr,
	_SSLTube$SSLSubscriptionWrapper_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SSLTube"
};

$Object* allocate$SSLTube$SSLSubscriptionWrapper($Class* clazz) {
	return $of($alloc(SSLTube$SSLSubscriptionWrapper));
}

void SSLTube$SSLSubscriptionWrapper::init$($SSLTube* this$0) {
	$set(this, this$0, this$0);
}

void SSLTube$SSLSubscriptionWrapper::setSubscription($Flow$Subscription* sub) {
	$useLocalCurrentObjectStackCache();
	int64_t demand = $nc(this->this$0->writeDemand)->get();
	$set(this, delegate, sub);
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("setSubscription: demand=%d, cancelled:%s"_s, $$new($ObjectArray, {
			$($of($Long::valueOf(demand))),
			$($of($Boolean::valueOf(this->cancelled)))
		}));
	}
	if (this->cancelled) {
		$nc(this->delegate)->cancel();
	} else if (demand > 0) {
		$nc(sub)->request(demand);
	}
}

void SSLTube$SSLSubscriptionWrapper::request(int64_t n) {
	$useLocalCurrentObjectStackCache();
	$nc(this->this$0->writeDemand)->increase(n);
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("request: n=%d"_s, $$new($ObjectArray, {$($of($Long::valueOf(n)))}));
	}
	$var($Flow$Subscription, sub, this->delegate);
	if (sub != nullptr && n > 0) {
		sub->request(n);
	}
}

void SSLTube$SSLSubscriptionWrapper::cancel() {
	this->cancelled = true;
	if (this->delegate != nullptr) {
		$nc(this->delegate)->cancel();
	}
}

SSLTube$SSLSubscriptionWrapper::SSLTube$SSLSubscriptionWrapper() {
}

$Class* SSLTube$SSLSubscriptionWrapper::load$($String* name, bool initialize) {
	$loadClass(SSLTube$SSLSubscriptionWrapper, name, initialize, &_SSLTube$SSLSubscriptionWrapper_ClassInfo_, allocate$SSLTube$SSLSubscriptionWrapper);
	return class$;
}

$Class* SSLTube$SSLSubscriptionWrapper::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk