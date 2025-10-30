#include <jdk/internal/net/http/common/OperationTrackers.h>

#include <java/lang/InternalError.h>
#include <java/net/http/HttpClient.h>
#include <jdk/internal/net/http/common/OperationTrackers$Trackable.h>
#include <jdk/internal/net/http/common/OperationTrackers$Tracker.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpClient = ::java::net::http::HttpClient;
using $OperationTrackers$Trackable = ::jdk::internal::net::http::common::OperationTrackers$Trackable;
using $OperationTrackers$Tracker = ::jdk::internal::net::http::common::OperationTrackers$Tracker;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$MethodInfo _OperationTrackers_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(OperationTrackers::*)()>(&OperationTrackers::init$))},
	{"getTracker", "(Ljava/net/http/HttpClient;)Ljdk/internal/net/http/common/OperationTrackers$Tracker;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$OperationTrackers$Tracker*(*)($HttpClient*)>(&OperationTrackers::getTracker))},
	{}
};

$InnerClassInfo _OperationTrackers_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.OperationTrackers$Trackable", "jdk.internal.net.http.common.OperationTrackers", "Trackable", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.common.OperationTrackers$Tracker", "jdk.internal.net.http.common.OperationTrackers", "Tracker", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _OperationTrackers_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.OperationTrackers",
	"java.lang.Object",
	nullptr,
	nullptr,
	_OperationTrackers_MethodInfo_,
	nullptr,
	nullptr,
	_OperationTrackers_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.OperationTrackers$Trackable,jdk.internal.net.http.common.OperationTrackers$Tracker"
};

$Object* allocate$OperationTrackers($Class* clazz) {
	return $of($alloc(OperationTrackers));
}

void OperationTrackers::init$() {
	$throwNew($InternalError, "not instantiable"_s);
}

$OperationTrackers$Tracker* OperationTrackers::getTracker($HttpClient* client) {
	if ($instanceOf($OperationTrackers$Trackable, client)) {
		return $nc(($cast($OperationTrackers$Trackable, client)))->getOperationsTracker();
	} else {
		return nullptr;
	}
}

OperationTrackers::OperationTrackers() {
}

$Class* OperationTrackers::load$($String* name, bool initialize) {
	$loadClass(OperationTrackers, name, initialize, &_OperationTrackers_ClassInfo_, allocate$OperationTrackers);
	return class$;
}

$Class* OperationTrackers::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk