#include <jdk/internal/net/http/common/SubscriberWrapper$SchedulingAction.h>

#include <java/lang/Enum.h>
#include <jdk/internal/net/http/common/SubscriberWrapper.h>
#include <jcpp.h>

#undef CONTINUE
#undef RESCHEDULE
#undef RETURN

using $SubscriberWrapper$SchedulingActionArray = $Array<::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SubscriberWrapper = ::jdk::internal::net::http::common::SubscriberWrapper;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SubscriberWrapper$SchedulingAction_FieldInfo_[] = {
	{"CONTINUE", "Ljdk/internal/net/http/common/SubscriberWrapper$SchedulingAction;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SubscriberWrapper$SchedulingAction, CONTINUE)},
	{"RETURN", "Ljdk/internal/net/http/common/SubscriberWrapper$SchedulingAction;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SubscriberWrapper$SchedulingAction, RETURN)},
	{"RESCHEDULE", "Ljdk/internal/net/http/common/SubscriberWrapper$SchedulingAction;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(SubscriberWrapper$SchedulingAction, RESCHEDULE)},
	{"$VALUES", "[Ljdk/internal/net/http/common/SubscriberWrapper$SchedulingAction;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(SubscriberWrapper$SchedulingAction, $VALUES)},
	{}
};

$MethodInfo _SubscriberWrapper$SchedulingAction_MethodInfo_[] = {
	{"$values", "()[Ljdk/internal/net/http/common/SubscriberWrapper$SchedulingAction;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$SubscriberWrapper$SchedulingActionArray*(*)()>(&SubscriberWrapper$SchedulingAction::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(SubscriberWrapper$SchedulingAction::*)($String*,int32_t)>(&SubscriberWrapper$SchedulingAction::init$))},
	{"valueOf", "(Ljava/lang/String;)Ljdk/internal/net/http/common/SubscriberWrapper$SchedulingAction;", nullptr, $PUBLIC | $STATIC, $method(static_cast<SubscriberWrapper$SchedulingAction*(*)($String*)>(&SubscriberWrapper$SchedulingAction::valueOf))},
	{"values", "()[Ljdk/internal/net/http/common/SubscriberWrapper$SchedulingAction;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$SubscriberWrapper$SchedulingActionArray*(*)()>(&SubscriberWrapper$SchedulingAction::values))},
	{}
};

$InnerClassInfo _SubscriberWrapper$SchedulingAction_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SubscriberWrapper$SchedulingAction", "jdk.internal.net.http.common.SubscriberWrapper", "SchedulingAction", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _SubscriberWrapper$SchedulingAction_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER | $ENUM,
	"jdk.internal.net.http.common.SubscriberWrapper$SchedulingAction",
	"java.lang.Enum",
	nullptr,
	_SubscriberWrapper$SchedulingAction_FieldInfo_,
	_SubscriberWrapper$SchedulingAction_MethodInfo_,
	"Ljava/lang/Enum<Ljdk/internal/net/http/common/SubscriberWrapper$SchedulingAction;>;",
	nullptr,
	_SubscriberWrapper$SchedulingAction_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SubscriberWrapper"
};

$Object* allocate$SubscriberWrapper$SchedulingAction($Class* clazz) {
	return $of($alloc(SubscriberWrapper$SchedulingAction));
}

SubscriberWrapper$SchedulingAction* SubscriberWrapper$SchedulingAction::CONTINUE = nullptr;
SubscriberWrapper$SchedulingAction* SubscriberWrapper$SchedulingAction::RETURN = nullptr;
SubscriberWrapper$SchedulingAction* SubscriberWrapper$SchedulingAction::RESCHEDULE = nullptr;
$SubscriberWrapper$SchedulingActionArray* SubscriberWrapper$SchedulingAction::$VALUES = nullptr;

$SubscriberWrapper$SchedulingActionArray* SubscriberWrapper$SchedulingAction::$values() {
	$init(SubscriberWrapper$SchedulingAction);
	return $new($SubscriberWrapper$SchedulingActionArray, {
		SubscriberWrapper$SchedulingAction::CONTINUE,
		SubscriberWrapper$SchedulingAction::RETURN,
		SubscriberWrapper$SchedulingAction::RESCHEDULE
	});
}

$SubscriberWrapper$SchedulingActionArray* SubscriberWrapper$SchedulingAction::values() {
	$init(SubscriberWrapper$SchedulingAction);
	return $cast($SubscriberWrapper$SchedulingActionArray, SubscriberWrapper$SchedulingAction::$VALUES->clone());
}

SubscriberWrapper$SchedulingAction* SubscriberWrapper$SchedulingAction::valueOf($String* name) {
	$init(SubscriberWrapper$SchedulingAction);
	return $cast(SubscriberWrapper$SchedulingAction, $Enum::valueOf(SubscriberWrapper$SchedulingAction::class$, name));
}

void SubscriberWrapper$SchedulingAction::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void clinit$SubscriberWrapper$SchedulingAction($Class* class$) {
	$assignStatic(SubscriberWrapper$SchedulingAction::CONTINUE, $new(SubscriberWrapper$SchedulingAction, "CONTINUE"_s, 0));
	$assignStatic(SubscriberWrapper$SchedulingAction::RETURN, $new(SubscriberWrapper$SchedulingAction, "RETURN"_s, 1));
	$assignStatic(SubscriberWrapper$SchedulingAction::RESCHEDULE, $new(SubscriberWrapper$SchedulingAction, "RESCHEDULE"_s, 2));
	$assignStatic(SubscriberWrapper$SchedulingAction::$VALUES, SubscriberWrapper$SchedulingAction::$values());
}

SubscriberWrapper$SchedulingAction::SubscriberWrapper$SchedulingAction() {
}

$Class* SubscriberWrapper$SchedulingAction::load$($String* name, bool initialize) {
	$loadClass(SubscriberWrapper$SchedulingAction, name, initialize, &_SubscriberWrapper$SchedulingAction_ClassInfo_, clinit$SubscriberWrapper$SchedulingAction, allocate$SubscriberWrapper$SchedulingAction);
	return class$;
}

$Class* SubscriberWrapper$SchedulingAction::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk