#include <jdk/internal/net/http/common/SubscriberWrapper$1.h>

#include <java/lang/NoSuchFieldError.h>
#include <jdk/internal/net/http/common/SubscriberWrapper$SchedulingAction.h>
#include <jdk/internal/net/http/common/SubscriberWrapper.h>
#include <jcpp.h>

#undef CONTINUE
#undef RESCHEDULE
#undef RETURN

using $SubscriberWrapper$SchedulingActionArray = $Array<::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction>;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $NoSuchFieldError = ::java::lang::NoSuchFieldError;
using $SubscriberWrapper = ::jdk::internal::net::http::common::SubscriberWrapper;
using $SubscriberWrapper$SchedulingAction = ::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SubscriberWrapper$1_FieldInfo_[] = {
	{"$SwitchMap$jdk$internal$net$http$common$SubscriberWrapper$SchedulingAction", "[I", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SubscriberWrapper$1, $SwitchMap$jdk$internal$net$http$common$SubscriberWrapper$SchedulingAction)},
	{}
};

$EnclosingMethodInfo _SubscriberWrapper$1_EnclosingMethodInfo_ = {
	"jdk.internal.net.http.common.SubscriberWrapper",
	nullptr,
	nullptr
};

$InnerClassInfo _SubscriberWrapper$1_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SubscriberWrapper$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _SubscriberWrapper$1_ClassInfo_ = {
	$ACC_SUPER | $SYNTHETIC,
	"jdk.internal.net.http.common.SubscriberWrapper$1",
	"java.lang.Object",
	nullptr,
	_SubscriberWrapper$1_FieldInfo_,
	nullptr,
	nullptr,
	&_SubscriberWrapper$1_EnclosingMethodInfo_,
	_SubscriberWrapper$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SubscriberWrapper"
};

$Object* allocate$SubscriberWrapper$1($Class* clazz) {
	return $of($alloc(SubscriberWrapper$1));
}

$ints* SubscriberWrapper$1::$SwitchMap$jdk$internal$net$http$common$SubscriberWrapper$SchedulingAction = nullptr;

void clinit$SubscriberWrapper$1($Class* class$) {
	$assignStatic(SubscriberWrapper$1::$SwitchMap$jdk$internal$net$http$common$SubscriberWrapper$SchedulingAction, $new($ints, $($SubscriberWrapper$SchedulingAction::values())->length));
	{
		try {
			$nc(SubscriberWrapper$1::$SwitchMap$jdk$internal$net$http$common$SubscriberWrapper$SchedulingAction)->set($SubscriberWrapper$SchedulingAction::CONTINUE->ordinal(), 1);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(SubscriberWrapper$1::$SwitchMap$jdk$internal$net$http$common$SubscriberWrapper$SchedulingAction)->set($SubscriberWrapper$SchedulingAction::RESCHEDULE->ordinal(), 2);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(SubscriberWrapper$1::$SwitchMap$jdk$internal$net$http$common$SubscriberWrapper$SchedulingAction)->set($SubscriberWrapper$SchedulingAction::RETURN->ordinal(), 3);
		} catch ($NoSuchFieldError& ex) {
		}
	}
}

SubscriberWrapper$1::SubscriberWrapper$1() {
}

$Class* SubscriberWrapper$1::load$($String* name, bool initialize) {
	$loadClass(SubscriberWrapper$1, name, initialize, &_SubscriberWrapper$1_ClassInfo_, clinit$SubscriberWrapper$1, allocate$SubscriberWrapper$1);
	return class$;
}

$Class* SubscriberWrapper$1::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk