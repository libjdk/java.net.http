#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>

#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $ResponseSubscribers = ::jdk::internal::net::http::ResponseSubscribers;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$MethodInfo _ResponseSubscribers$TrustedSubscriber_MethodInfo_[] = {
	{"needsExecutor", "()Z", nullptr, $PUBLIC},
	{"needsExecutor", "(Ljava/net/http/HttpResponse$BodySubscriber;)Z", "(Ljava/net/http/HttpResponse$BodySubscriber<*>;)Z", $PUBLIC | $STATIC, $method(static_cast<bool(*)($HttpResponse$BodySubscriber*)>(&ResponseSubscribers$TrustedSubscriber::needsExecutor))},
	{}
};

$InnerClassInfo _ResponseSubscribers$TrustedSubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber", "jdk.internal.net.http.ResponseSubscribers", "TrustedSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.net.http.HttpResponse$BodySubscriber", "java.net.http.HttpResponse", "BodySubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseSubscribers$TrustedSubscriber_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber",
	nullptr,
	"java.net.http.HttpResponse$BodySubscriber",
	nullptr,
	_ResponseSubscribers$TrustedSubscriber_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljava/net/http/HttpResponse$BodySubscriber<TT;>;",
	nullptr,
	_ResponseSubscribers$TrustedSubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseSubscribers"
};

$Object* allocate$ResponseSubscribers$TrustedSubscriber($Class* clazz) {
	return $of($alloc(ResponseSubscribers$TrustedSubscriber));
}

bool ResponseSubscribers$TrustedSubscriber::needsExecutor() {
	return false;
}

bool ResponseSubscribers$TrustedSubscriber::needsExecutor($HttpResponse$BodySubscriber* bs) {
	$init(ResponseSubscribers$TrustedSubscriber);
	if ($instanceOf(ResponseSubscribers$TrustedSubscriber, bs)) {
		return $nc(($cast(ResponseSubscribers$TrustedSubscriber, bs)))->needsExecutor();
	} else {
		return true;
	}
}

$Class* ResponseSubscribers$TrustedSubscriber::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$TrustedSubscriber, name, initialize, &_ResponseSubscribers$TrustedSubscriber_ClassInfo_, allocate$ResponseSubscribers$TrustedSubscriber);
	return class$;
}

$Class* ResponseSubscribers$TrustedSubscriber::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk