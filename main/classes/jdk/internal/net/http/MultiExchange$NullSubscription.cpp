#include <jdk/internal/net/http/MultiExchange$NullSubscription.h>

#include <jdk/internal/net/http/MultiExchange.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$MethodInfo _MultiExchange$NullSubscription_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(MultiExchange$NullSubscription::*)()>(&MultiExchange$NullSubscription::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"request", "(J)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _MultiExchange$NullSubscription_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.MultiExchange$NullSubscription", "jdk.internal.net.http.MultiExchange", "NullSubscription", $STATIC},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _MultiExchange$NullSubscription_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.MultiExchange$NullSubscription",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription",
	nullptr,
	_MultiExchange$NullSubscription_MethodInfo_,
	nullptr,
	nullptr,
	_MultiExchange$NullSubscription_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.MultiExchange"
};

$Object* allocate$MultiExchange$NullSubscription($Class* clazz) {
	return $of($alloc(MultiExchange$NullSubscription));
}

void MultiExchange$NullSubscription::init$() {
}

void MultiExchange$NullSubscription::request(int64_t n) {
}

void MultiExchange$NullSubscription::cancel() {
}

MultiExchange$NullSubscription::MultiExchange$NullSubscription() {
}

$Class* MultiExchange$NullSubscription::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$NullSubscription, name, initialize, &_MultiExchange$NullSubscription_ClassInfo_, allocate$MultiExchange$NullSubscription);
	return class$;
}

$Class* MultiExchange$NullSubscription::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk