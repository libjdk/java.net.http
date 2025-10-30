#include <jdk/internal/net/http/Http1Exchange$Http1Publisher$WriteTask.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/List.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/Http1Exchange$DataPair.h>
#include <jdk/internal/net/http/Http1Exchange$Http1BodySubscriber.h>
#include <jdk/internal/net/http/Http1Exchange$Http1Publisher.h>
#include <jdk/internal/net/http/Http1Exchange$State.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef COMPLETED
#undef COMPLETING

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $List = ::java::util::List;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Supplier = ::java::util::function::Supplier;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;
using $Http1Exchange$DataPair = ::jdk::internal::net::http::Http1Exchange$DataPair;
using $Http1Exchange$Http1BodySubscriber = ::jdk::internal::net::http::Http1Exchange$Http1BodySubscriber;
using $Http1Exchange$Http1Publisher = ::jdk::internal::net::http::Http1Exchange$Http1Publisher;
using $Http1Exchange$State = ::jdk::internal::net::http::Http1Exchange$State;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0 : public $Supplier {
	$class(Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Http1Exchange$Http1Publisher$WriteTask* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$run$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0>());
	}
	Http1Exchange$Http1Publisher$WriteTask* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0, inst$)},
	{}
};
$MethodInfo Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange$Http1Publisher$WriteTask;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0::*)(Http1Exchange$Http1Publisher$WriteTask*)>(&Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0::class$ = nullptr;

$FieldInfo _Http1Exchange$Http1Publisher$WriteTask_FieldInfo_[] = {
	{"this$1", "Ljdk/internal/net/http/Http1Exchange$Http1Publisher;", nullptr, $FINAL | $SYNTHETIC, $field(Http1Exchange$Http1Publisher$WriteTask, this$1)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http1Exchange$Http1Publisher$WriteTask, $assertionsDisabled)},
	{}
};

$MethodInfo _Http1Exchange$Http1Publisher$WriteTask_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange$Http1Publisher;)V", nullptr, 0, $method(static_cast<void(Http1Exchange$Http1Publisher$WriteTask::*)($Http1Exchange$Http1Publisher*)>(&Http1Exchange$Http1Publisher$WriteTask::init$))},
	{"lambda$run$0", "()Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(Http1Exchange$Http1Publisher$WriteTask::*)()>(&Http1Exchange$Http1Publisher$WriteTask::lambda$run$0))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Http1Exchange$Http1Publisher$WriteTask_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Exchange$Http1Publisher", "jdk.internal.net.http.Http1Exchange", "Http1Publisher", $FINAL},
	{"jdk.internal.net.http.Http1Exchange$Http1Publisher$WriteTask", "jdk.internal.net.http.Http1Exchange$Http1Publisher", "WriteTask", $FINAL},
	{}
};

$ClassInfo _Http1Exchange$Http1Publisher$WriteTask_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Http1Exchange$Http1Publisher$WriteTask",
	"java.lang.Object",
	"java.lang.Runnable",
	_Http1Exchange$Http1Publisher$WriteTask_FieldInfo_,
	_Http1Exchange$Http1Publisher$WriteTask_MethodInfo_,
	nullptr,
	nullptr,
	_Http1Exchange$Http1Publisher$WriteTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Exchange"
};

$Object* allocate$Http1Exchange$Http1Publisher$WriteTask($Class* clazz) {
	return $of($alloc(Http1Exchange$Http1Publisher$WriteTask));
}

bool Http1Exchange$Http1Publisher$WriteTask::$assertionsDisabled = false;

void Http1Exchange$Http1Publisher$WriteTask::init$($Http1Exchange$Http1Publisher* this$1) {
	$set(this, this$1, this$1);
}

void Http1Exchange$Http1Publisher$WriteTask::run() {
	$useLocalCurrentObjectStackCache();
	$init($Http1Exchange$State);
	if (!Http1Exchange$Http1Publisher$WriteTask::$assertionsDisabled && !($nc(this->this$1->this$0)->state != $Http1Exchange$State::COMPLETED)) {
		$throwNew($AssertionError, $of($$str({"Unexpected state:"_s, $nc(this->this$1->this$0)->state})));
	}
	if ($nc(this->this$1->debug)->on()) {
		$nc(this->this$1->debug)->log("WriteTask"_s);
	}
	if (this->this$1->cancelled) {
		if ($nc(this->this$1->debug)->on()) {
			$nc(this->this$1->debug)->log("handling cancellation"_s);
		}
		$nc(this->this$1->writeScheduler)->stop();
		$nc(this->this$1->this$0)->getOutgoing();
		return;
	}
	if (this->this$1->checkRequestCancelled()) {
		return;
	}
	if (this->this$1->subscriber == nullptr) {
		if ($nc(this->this$1->debug)->on()) {
			$nc(this->this$1->debug)->log("no subscriber yet"_s);
		}
		return;
	}
	if ($nc(this->this$1->debug)->on()) {
		$nc(this->this$1->debug)->log(static_cast<$Supplier*>($$new(Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0, this)));
	}
	while (true) {
		bool var$0 = $nc(this->this$1->this$0)->hasOutgoing();
		if (!(var$0 && $nc(this->this$1->demand)->tryDecrement())) {
			break;
		}
		{
			$var($Http1Exchange$DataPair, dp, $nc(this->this$1->this$0)->getOutgoing());
			if (dp == nullptr) {
				break;
			}
			if ($nc(dp)->throwable != nullptr) {
				if ($nc(this->this$1->debug)->on()) {
					$nc(this->this$1->debug)->log("onError"_s);
				}
				$nc(this->this$1->writeScheduler)->stop();
			} else {
				$var($List, data, dp->data);
				$init($Http1Exchange$Http1BodySubscriber);
				if (data == $Http1Exchange$Http1BodySubscriber::COMPLETED) {
					$synchronized($nc(this->this$1->this$0)->lock) {
						if (!Http1Exchange$Http1Publisher$WriteTask::$assertionsDisabled && !($nc(this->this$1->this$0)->state == $Http1Exchange$State::COMPLETING)) {
							$throwNew($AssertionError, $of($$str({"Unexpected state:"_s, $nc(this->this$1->this$0)->state})));
						}
						$set($nc(this->this$1->this$0), state, $Http1Exchange$State::COMPLETED);
					}
					if ($nc(this->this$1->debug)->on()) {
						$nc(this->this$1->debug)->log("completed, stopping %s"_s, $$new($ObjectArray, {$of(this->this$1->writeScheduler)}));
					}
					$nc(this->this$1->writeScheduler)->stop();
				} else {
					if (this->this$1->checkRequestCancelled()) {
						return;
					}
					if ($nc(this->this$1->debug)->on()) {
						$nc(this->this$1->debug)->log($$str({"onNext with "_s, $$str($Utils::remaining(data)), " bytes"_s}));
					}
					$nc(this->this$1->subscriber)->onNext(data);
				}
			}
		}
	}
}

$String* Http1Exchange$Http1Publisher$WriteTask::lambda$run$0() {
	return $str({"hasOutgoing = "_s, $$str($nc(this->this$1->this$0)->hasOutgoing())});
}

void clinit$Http1Exchange$Http1Publisher$WriteTask($Class* class$) {
	$load($Http1Exchange);
	Http1Exchange$Http1Publisher$WriteTask::$assertionsDisabled = !$Http1Exchange::class$->desiredAssertionStatus();
}

Http1Exchange$Http1Publisher$WriteTask::Http1Exchange$Http1Publisher$WriteTask() {
}

$Class* Http1Exchange$Http1Publisher$WriteTask::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0::classInfo$.name)) {
			return Http1Exchange$Http1Publisher$WriteTask$$Lambda$lambda$run$0::load$(name, initialize);
		}
	}
	$loadClass(Http1Exchange$Http1Publisher$WriteTask, name, initialize, &_Http1Exchange$Http1Publisher$WriteTask_ClassInfo_, clinit$Http1Exchange$Http1Publisher$WriteTask, allocate$Http1Exchange$Http1Publisher$WriteTask);
	return class$;
}

$Class* Http1Exchange$Http1Publisher$WriteTask::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk