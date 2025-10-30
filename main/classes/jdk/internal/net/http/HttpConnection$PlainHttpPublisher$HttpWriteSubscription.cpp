#include <jdk/internal/net/http/HttpConnection$PlainHttpPublisher$HttpWriteSubscription.h>

#include <java/util/List.h>
#include <java/util/concurrent/ConcurrentLinkedDeque.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <jdk/internal/net/http/HttpConnection$PlainHttpPublisher.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $List = ::java::util::List;
using $ConcurrentLinkedDeque = ::java::util::concurrent::ConcurrentLinkedDeque;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpConnection$PlainHttpPublisher = ::jdk::internal::net::http::HttpConnection$PlainHttpPublisher;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _HttpConnection$PlainHttpPublisher$HttpWriteSubscription_FieldInfo_[] = {
	{"this$1", "Ljdk/internal/net/http/HttpConnection$PlainHttpPublisher;", nullptr, $FINAL | $SYNTHETIC, $field(HttpConnection$PlainHttpPublisher$HttpWriteSubscription, this$1)},
	{"demand", "Ljdk/internal/net/http/common/Demand;", nullptr, $FINAL, $field(HttpConnection$PlainHttpPublisher$HttpWriteSubscription, demand)},
	{}
};

$MethodInfo _HttpConnection$PlainHttpPublisher$HttpWriteSubscription_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpConnection$PlainHttpPublisher;)V", nullptr, 0, $method(static_cast<void(HttpConnection$PlainHttpPublisher$HttpWriteSubscription::*)($HttpConnection$PlainHttpPublisher*)>(&HttpConnection$PlainHttpPublisher$HttpWriteSubscription::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"flush", "()V", nullptr, 0, $method(static_cast<void(HttpConnection$PlainHttpPublisher$HttpWriteSubscription::*)()>(&HttpConnection$PlainHttpPublisher$HttpWriteSubscription::flush))},
	{"isEmpty", "()Z", nullptr, $PRIVATE, $method(static_cast<bool(HttpConnection$PlainHttpPublisher$HttpWriteSubscription::*)()>(&HttpConnection$PlainHttpPublisher$HttpWriteSubscription::isEmpty))},
	{"poll", "()Ljava/util/List;", "()Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(HttpConnection$PlainHttpPublisher$HttpWriteSubscription::*)()>(&HttpConnection$PlainHttpPublisher$HttpWriteSubscription::poll))},
	{"request", "(J)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _HttpConnection$PlainHttpPublisher$HttpWriteSubscription_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.HttpConnection$PlainHttpPublisher", "jdk.internal.net.http.HttpConnection", "PlainHttpPublisher", $FINAL},
	{"jdk.internal.net.http.HttpConnection$PlainHttpPublisher$HttpWriteSubscription", "jdk.internal.net.http.HttpConnection$PlainHttpPublisher", "HttpWriteSubscription", $FINAL},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpConnection$PlainHttpPublisher$HttpWriteSubscription_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.HttpConnection$PlainHttpPublisher$HttpWriteSubscription",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription",
	_HttpConnection$PlainHttpPublisher$HttpWriteSubscription_FieldInfo_,
	_HttpConnection$PlainHttpPublisher$HttpWriteSubscription_MethodInfo_,
	nullptr,
	nullptr,
	_HttpConnection$PlainHttpPublisher$HttpWriteSubscription_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HttpConnection"
};

$Object* allocate$HttpConnection$PlainHttpPublisher$HttpWriteSubscription($Class* clazz) {
	return $of($alloc(HttpConnection$PlainHttpPublisher$HttpWriteSubscription));
}

void HttpConnection$PlainHttpPublisher$HttpWriteSubscription::init$($HttpConnection$PlainHttpPublisher* this$1) {
	$set(this, this$1, this$1);
	$set(this, demand, $new($Demand));
}

void HttpConnection$PlainHttpPublisher$HttpWriteSubscription::request(int64_t n) {
	$useLocalCurrentObjectStackCache();
	if (n <= 0) {
		$throwNew($IllegalArgumentException, "non-positive request"_s);
	}
	$nc(this->demand)->increase(n);
	if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log($$str({"HttpPublisher: got request of "_s, $$str(n), " from "_s, $($nc(this->this$1->this$0)->getConnectionFlow())}));
	}
	$nc(this->this$1->writeScheduler)->runOrSchedule();
}

void HttpConnection$PlainHttpPublisher$HttpWriteSubscription::cancel() {
	$useLocalCurrentObjectStackCache();
	if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log($$str({"HttpPublisher: cancelled by "_s, $($nc(this->this$1->this$0)->getConnectionFlow())}));
	}
}

bool HttpConnection$PlainHttpPublisher$HttpWriteSubscription::isEmpty() {
	bool var$0 = $nc(this->this$1->queue)->isEmpty();
	return var$0 && $nc(this->this$1->priority)->isEmpty();
}

$List* HttpConnection$PlainHttpPublisher$HttpWriteSubscription::poll() {
	$var($List, elem, $cast($List, $nc(this->this$1->priority)->poll()));
	return elem == nullptr ? $cast($List, $nc(this->this$1->queue)->poll()) : elem;
}

void HttpConnection$PlainHttpPublisher$HttpWriteSubscription::flush() {
	$useLocalCurrentObjectStackCache();
	while (true) {
		bool var$0 = !isEmpty();
		if (!(var$0 && $nc(this->demand)->tryDecrement())) {
			break;
		}
		{
			$var($List, elem, poll());
			if ($nc($nc(this->this$1->this$0)->debug)->on()) {
				$var($String, var$3, $$str({"HttpPublisher: sending "_s, $$str($Utils::remaining(elem)), " bytes ("_s}));
				$var($String, var$2, $$concat(var$3, $$str($nc(elem)->size())));
				$var($String, var$1, $$concat(var$2, " buffers) to "));
				$nc($nc(this->this$1->this$0)->debug)->log($$concat(var$1, $($nc(this->this$1->this$0)->getConnectionFlow())));
			}
			$nc(this->this$1->subscriber)->onNext(elem);
		}
	}
}

HttpConnection$PlainHttpPublisher$HttpWriteSubscription::HttpConnection$PlainHttpPublisher$HttpWriteSubscription() {
}

$Class* HttpConnection$PlainHttpPublisher$HttpWriteSubscription::load$($String* name, bool initialize) {
	$loadClass(HttpConnection$PlainHttpPublisher$HttpWriteSubscription, name, initialize, &_HttpConnection$PlainHttpPublisher$HttpWriteSubscription_ClassInfo_, allocate$HttpConnection$PlainHttpPublisher$HttpWriteSubscription);
	return class$;
}

$Class* HttpConnection$PlainHttpPublisher$HttpWriteSubscription::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk