#include <jdk/internal/net/http/common/OperationTrackers$Trackable.h>

#include <jdk/internal/net/http/common/OperationTrackers$Tracker.h>
#include <jdk/internal/net/http/common/OperationTrackers.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $OperationTrackers = ::jdk::internal::net::http::common::OperationTrackers;
using $OperationTrackers$Tracker = ::jdk::internal::net::http::common::OperationTrackers$Tracker;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$MethodInfo _OperationTrackers$Trackable_MethodInfo_[] = {
	{"getOperationsTracker", "()Ljdk/internal/net/http/common/OperationTrackers$Tracker;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _OperationTrackers$Trackable_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.OperationTrackers$Trackable", "jdk.internal.net.http.common.OperationTrackers", "Trackable", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _OperationTrackers$Trackable_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.common.OperationTrackers$Trackable",
	nullptr,
	nullptr,
	nullptr,
	_OperationTrackers$Trackable_MethodInfo_,
	nullptr,
	nullptr,
	_OperationTrackers$Trackable_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.OperationTrackers"
};

$Object* allocate$OperationTrackers$Trackable($Class* clazz) {
	return $of($alloc(OperationTrackers$Trackable));
}

$Class* OperationTrackers$Trackable::load$($String* name, bool initialize) {
	$loadClass(OperationTrackers$Trackable, name, initialize, &_OperationTrackers$Trackable_ClassInfo_, allocate$OperationTrackers$Trackable);
	return class$;
}

$Class* OperationTrackers$Trackable::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk