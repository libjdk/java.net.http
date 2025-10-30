#include <jdk/internal/net/http/AbstractSubscription.h>

#include <jdk/internal/net/http/common/Demand.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Demand = ::jdk::internal::net::http::common::Demand;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _AbstractSubscription_FieldInfo_[] = {
	{"demand", "Ljdk/internal/net/http/common/Demand;", nullptr, $PRIVATE | $FINAL, $field(AbstractSubscription, demand$)},
	{}
};

$MethodInfo _AbstractSubscription_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(AbstractSubscription::*)()>(&AbstractSubscription::init$))},
	{"demand", "()Ljdk/internal/net/http/common/Demand;", nullptr, $PROTECTED},
	{}
};

$InnerClassInfo _AbstractSubscription_InnerClassesInfo_[] = {
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _AbstractSubscription_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.AbstractSubscription",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription",
	_AbstractSubscription_FieldInfo_,
	_AbstractSubscription_MethodInfo_,
	nullptr,
	nullptr,
	_AbstractSubscription_InnerClassesInfo_
};

$Object* allocate$AbstractSubscription($Class* clazz) {
	return $of($alloc(AbstractSubscription));
}

void AbstractSubscription::init$() {
	$set(this, demand$, $new($Demand));
}

$Demand* AbstractSubscription::demand() {
	return this->demand$;
}

AbstractSubscription::AbstractSubscription() {
}

$Class* AbstractSubscription::load$($String* name, bool initialize) {
	$loadClass(AbstractSubscription, name, initialize, &_AbstractSubscription_ClassInfo_, allocate$AbstractSubscription);
	return class$;
}

$Class* AbstractSubscription::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk