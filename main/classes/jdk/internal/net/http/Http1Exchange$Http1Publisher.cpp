#include <jdk/internal/net/http/Http1Exchange$Http1Publisher.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/Http1Exchange$1.h>
#include <jdk/internal/net/http/Http1Exchange$Http1Publisher$Http1WriteSubscription.h>
#include <jdk/internal/net/http/Http1Exchange$Http1Publisher$WriteTask.h>
#include <jdk/internal/net/http/Http1Exchange$State.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef INITIAL

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Objects = ::java::util::Objects;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Supplier = ::java::util::function::Supplier;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $ExchangeImpl = ::jdk::internal::net::http::ExchangeImpl;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;
using $Http1Exchange$1 = ::jdk::internal::net::http::Http1Exchange$1;
using $Http1Exchange$Http1Publisher$Http1WriteSubscription = ::jdk::internal::net::http::Http1Exchange$Http1Publisher$Http1WriteSubscription;
using $Http1Exchange$Http1Publisher$WriteTask = ::jdk::internal::net::http::Http1Exchange$Http1Publisher$WriteTask;
using $Http1Exchange$State = ::jdk::internal::net::http::Http1Exchange$State;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $FlowTube$TubePublisher = ::jdk::internal::net::http::common::FlowTube$TubePublisher;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Http1Exchange$Http1Publisher$$Lambda$dbgString : public $Supplier {
	$class(Http1Exchange$Http1Publisher$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Http1Exchange$Http1Publisher* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$Http1Publisher$$Lambda$dbgString>());
	}
	Http1Exchange$Http1Publisher* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$Http1Publisher$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$Http1Publisher$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo Http1Exchange$Http1Publisher$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange$Http1Publisher;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$Http1Publisher$$Lambda$dbgString::*)(Http1Exchange$Http1Publisher*)>(&Http1Exchange$Http1Publisher$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$Http1Publisher$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$Http1Publisher$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$Http1Publisher$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$Http1Publisher$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$Http1Publisher$$Lambda$dbgString::class$ = nullptr;

$FieldInfo _Http1Exchange$Http1Publisher_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/Http1Exchange;", nullptr, $FINAL | $SYNTHETIC, $field(Http1Exchange$Http1Publisher, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http1Exchange$Http1Publisher, $assertionsDisabled)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(Http1Exchange$Http1Publisher, debug)},
	{"subscriber", "Ljava/util/concurrent/Flow$Subscriber;", "Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;", $VOLATILE, $field(Http1Exchange$Http1Publisher, subscriber)},
	{"cancelled", "Z", nullptr, $VOLATILE, $field(Http1Exchange$Http1Publisher, cancelled)},
	{"subscription", "Ljdk/internal/net/http/Http1Exchange$Http1Publisher$Http1WriteSubscription;", "Ljdk/internal/net/http/Http1Exchange<TT;>.Http1Publisher.Http1WriteSubscription;", $FINAL, $field(Http1Exchange$Http1Publisher, subscription)},
	{"demand", "Ljdk/internal/net/http/common/Demand;", nullptr, $FINAL, $field(Http1Exchange$Http1Publisher, demand)},
	{"writeScheduler", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $FINAL, $field(Http1Exchange$Http1Publisher, writeScheduler)},
	{"dbgTag", "Ljava/lang/String;", nullptr, $VOLATILE, $field(Http1Exchange$Http1Publisher, dbgTag)},
	{}
};

$MethodInfo _Http1Exchange$Http1Publisher_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;)V", nullptr, 0, $method(static_cast<void(Http1Exchange$Http1Publisher::*)($Http1Exchange*)>(&Http1Exchange$Http1Publisher::init$))},
	{"checkRequestCancelled", "()Z", nullptr, $PRIVATE, $method(static_cast<bool(Http1Exchange$Http1Publisher::*)()>(&Http1Exchange$Http1Publisher::checkRequestCancelled))},
	{"dbgString", "()Ljava/lang/String;", nullptr, 0, $method(static_cast<$String*(Http1Exchange$Http1Publisher::*)()>(&Http1Exchange$Http1Publisher::dbgString))},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", $PUBLIC},
	{}
};

$InnerClassInfo _Http1Exchange$Http1Publisher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Exchange$Http1Publisher", "jdk.internal.net.http.Http1Exchange", "Http1Publisher", $FINAL},
	{"jdk.internal.net.http.common.FlowTube$TubePublisher", "jdk.internal.net.http.common.FlowTube", "TubePublisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.Http1Exchange$Http1Publisher$Http1WriteSubscription", "jdk.internal.net.http.Http1Exchange$Http1Publisher", "Http1WriteSubscription", $FINAL},
	{"jdk.internal.net.http.Http1Exchange$Http1Publisher$WriteTask", "jdk.internal.net.http.Http1Exchange$Http1Publisher", "WriteTask", $FINAL},
	{}
};

$ClassInfo _Http1Exchange$Http1Publisher_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Http1Exchange$Http1Publisher",
	"java.lang.Object",
	"jdk.internal.net.http.common.FlowTube$TubePublisher",
	_Http1Exchange$Http1Publisher_FieldInfo_,
	_Http1Exchange$Http1Publisher_MethodInfo_,
	nullptr,
	nullptr,
	_Http1Exchange$Http1Publisher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Exchange"
};

$Object* allocate$Http1Exchange$Http1Publisher($Class* clazz) {
	return $of($alloc(Http1Exchange$Http1Publisher));
}

bool Http1Exchange$Http1Publisher::$assertionsDisabled = false;

void Http1Exchange$Http1Publisher::init$($Http1Exchange* this$0) {
	$useLocalCurrentObjectStackCache();
	$set(this, this$0, this$0);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(Http1Exchange$Http1Publisher$$Lambda$dbgString, this))));
	$set(this, subscription, $new($Http1Exchange$Http1Publisher$Http1WriteSubscription, this));
	$set(this, demand, $new($Demand));
	$set(this, writeScheduler, $SequentialScheduler::lockingScheduler($$new($Http1Exchange$Http1Publisher$WriteTask, this)));
}

void Http1Exchange$Http1Publisher::subscribe($Flow$Subscriber* s) {
	$init($Http1Exchange$State);
	if (!Http1Exchange$Http1Publisher::$assertionsDisabled && !(this->this$0->state == $Http1Exchange$State::INITIAL)) {
		$throwNew($AssertionError);
	}
	$Objects::requireNonNull(s);
	if (!Http1Exchange$Http1Publisher::$assertionsDisabled && !(this->subscriber == nullptr)) {
		$throwNew($AssertionError);
	}
	$set(this, subscriber, s);
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("got subscriber: %s"_s, $$new($ObjectArray, {$of(s)}));
	}
	s->onSubscribe(this->subscription);
}

$String* Http1Exchange$Http1Publisher::dbgString() {
	$useLocalCurrentObjectStackCache();
	$var($String, tag, this->dbgTag);
	$var($Object, flow, $nc(this->this$0->connection$)->getConnectionFlow());
	if (tag == nullptr && flow != nullptr) {
		$set(this, dbgTag, ($assign(tag, $str({"Http1Publisher("_s, flow, ")"_s}))));
	} else if (tag == nullptr) {
		$assign(tag, "Http1Publisher(?)"_s);
	}
	return tag;
}

bool Http1Exchange$Http1Publisher::checkRequestCancelled() {
	if ($nc($nc(this->this$0->exchange)->multi)->requestCancelled()) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("request cancelled"_s);
		}
		if (this->subscriber == nullptr) {
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("no subscriber yet"_s);
			}
			return true;
		}
		$init($Http1Exchange$1);
		{
			$var($Throwable, cause, nullptr)
			switch ($nc($Http1Exchange$1::$SwitchMap$jdk$internal$net$http$Http1Exchange$State)->get($nc(this->this$0->state)->ordinal())) {
			case 2:
				{
					this->this$0->cancelUpstreamSubscription();
				}
			case 1:
				{
					$assign(cause, this->this$0->getCancelCause());
					if (cause == nullptr) {
						$assign(cause, $new($IOException, "Request cancelled"_s));
					}
					$nc(this->subscriber)->onError(cause);
					$nc(this->writeScheduler)->stop();
					return true;
				}
			}
		}
	}
	return false;
}

void clinit$Http1Exchange$Http1Publisher($Class* class$) {
	$load($Http1Exchange);
	Http1Exchange$Http1Publisher::$assertionsDisabled = !$Http1Exchange::class$->desiredAssertionStatus();
}

Http1Exchange$Http1Publisher::Http1Exchange$Http1Publisher() {
}

$Class* Http1Exchange$Http1Publisher::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Http1Exchange$Http1Publisher$$Lambda$dbgString::classInfo$.name)) {
			return Http1Exchange$Http1Publisher$$Lambda$dbgString::load$(name, initialize);
		}
	}
	$loadClass(Http1Exchange$Http1Publisher, name, initialize, &_Http1Exchange$Http1Publisher_ClassInfo_, clinit$Http1Exchange$Http1Publisher, allocate$Http1Exchange$Http1Publisher);
	return class$;
}

$Class* Http1Exchange$Http1Publisher::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk