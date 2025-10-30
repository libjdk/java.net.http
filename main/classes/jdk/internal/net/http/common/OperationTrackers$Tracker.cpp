#include <jdk/internal/net/http/common/OperationTrackers$Tracker.h>

#include <jdk/internal/net/http/common/OperationTrackers.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $OperationTrackers = ::jdk::internal::net::http::common::OperationTrackers;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$MethodInfo _OperationTrackers$Tracker_MethodInfo_[] = {
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{"getOutstandingHttp2Streams", "()J", nullptr, $PUBLIC | $ABSTRACT},
	{"getOutstandingHttpOperations", "()J", nullptr, $PUBLIC | $ABSTRACT},
	{"getOutstandingOperations", "()J", nullptr, $PUBLIC | $ABSTRACT},
	{"getOutstandingWebSocketOperations", "()J", nullptr, $PUBLIC | $ABSTRACT},
	{"isFacadeReferenced", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _OperationTrackers$Tracker_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.OperationTrackers$Tracker", "jdk.internal.net.http.common.OperationTrackers", "Tracker", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _OperationTrackers$Tracker_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.common.OperationTrackers$Tracker",
	nullptr,
	nullptr,
	nullptr,
	_OperationTrackers$Tracker_MethodInfo_,
	nullptr,
	nullptr,
	_OperationTrackers$Tracker_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.OperationTrackers"
};

$Object* allocate$OperationTrackers$Tracker($Class* clazz) {
	return $of($alloc(OperationTrackers$Tracker));
}

$Class* OperationTrackers$Tracker::load$($String* name, bool initialize) {
	$loadClass(OperationTrackers$Tracker, name, initialize, &_OperationTrackers$Tracker_ClassInfo_, allocate$OperationTrackers$Tracker);
	return class$;
}

$Class* OperationTrackers$Tracker::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk