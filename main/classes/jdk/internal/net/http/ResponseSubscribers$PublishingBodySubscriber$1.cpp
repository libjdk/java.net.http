#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$1.h>

#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $ResponseSubscribers$PublishingBodySubscriber = ::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ResponseSubscribers$PublishingBodySubscriber$1_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber;", nullptr, $FINAL | $SYNTHETIC, $field(ResponseSubscribers$PublishingBodySubscriber$1, this$0)},
	{}
};

$MethodInfo _ResponseSubscribers$PublishingBodySubscriber$1_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber;)V", nullptr, 0, $method(static_cast<void(ResponseSubscribers$PublishingBodySubscriber$1::*)($ResponseSubscribers$PublishingBodySubscriber*)>(&ResponseSubscribers$PublishingBodySubscriber$1::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"request", "(J)V", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _ResponseSubscribers$PublishingBodySubscriber$1_EnclosingMethodInfo_ = {
	"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber",
	"subscribe",
	"(Ljava/util/concurrent/Flow$Subscriber;)V"
};

$InnerClassInfo _ResponseSubscribers$PublishingBodySubscriber$1_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber", "jdk.internal.net.http.ResponseSubscribers", "PublishingBodySubscriber", $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$1", nullptr, nullptr, 0},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.Flow$Subscriber", "java.util.concurrent.Flow", "Subscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseSubscribers$PublishingBodySubscriber$1_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$1",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription",
	_ResponseSubscribers$PublishingBodySubscriber$1_FieldInfo_,
	_ResponseSubscribers$PublishingBodySubscriber$1_MethodInfo_,
	nullptr,
	&_ResponseSubscribers$PublishingBodySubscriber$1_EnclosingMethodInfo_,
	_ResponseSubscribers$PublishingBodySubscriber$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseSubscribers"
};

$Object* allocate$ResponseSubscribers$PublishingBodySubscriber$1($Class* clazz) {
	return $of($alloc(ResponseSubscribers$PublishingBodySubscriber$1));
}

void ResponseSubscribers$PublishingBodySubscriber$1::init$($ResponseSubscribers$PublishingBodySubscriber* this$0) {
	$set(this, this$0, this$0);
}

void ResponseSubscribers$PublishingBodySubscriber$1::request(int64_t n) {
}

void ResponseSubscribers$PublishingBodySubscriber$1::cancel() {
}

ResponseSubscribers$PublishingBodySubscriber$1::ResponseSubscribers$PublishingBodySubscriber$1() {
}

$Class* ResponseSubscribers$PublishingBodySubscriber$1::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$PublishingBodySubscriber$1, name, initialize, &_ResponseSubscribers$PublishingBodySubscriber$1_ClassInfo_, allocate$ResponseSubscribers$PublishingBodySubscriber$1);
	return class$;
}

$Class* ResponseSubscribers$PublishingBodySubscriber$1::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk