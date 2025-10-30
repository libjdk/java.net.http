#include <jdk/internal/net/http/common/FlowTube$AbstractTubeSubscriber.h>

#include <jdk/internal/net/http/common/FlowTube.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$MethodInfo _FlowTube$AbstractTubeSubscriber_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(FlowTube$AbstractTubeSubscriber::*)()>(&FlowTube$AbstractTubeSubscriber::init$))},
	{}
};

$InnerClassInfo _FlowTube$AbstractTubeSubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.FlowTube$AbstractTubeSubscriber", "jdk.internal.net.http.common.FlowTube", "AbstractTubeSubscriber", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.net.http.common.FlowTube$TubeSubscriber", "jdk.internal.net.http.common.FlowTube", "TubeSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.common.FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper", "jdk.internal.net.http.common.FlowTube$AbstractTubeSubscriber", "TubeSubscriberWrapper", $STATIC | $FINAL},
	{}
};

$ClassInfo _FlowTube$AbstractTubeSubscriber_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.common.FlowTube$AbstractTubeSubscriber",
	"java.lang.Object",
	"jdk.internal.net.http.common.FlowTube$TubeSubscriber",
	nullptr,
	_FlowTube$AbstractTubeSubscriber_MethodInfo_,
	nullptr,
	nullptr,
	_FlowTube$AbstractTubeSubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.FlowTube"
};

$Object* allocate$FlowTube$AbstractTubeSubscriber($Class* clazz) {
	return $of($alloc(FlowTube$AbstractTubeSubscriber));
}

void FlowTube$AbstractTubeSubscriber::init$() {
}

FlowTube$AbstractTubeSubscriber::FlowTube$AbstractTubeSubscriber() {
}

$Class* FlowTube$AbstractTubeSubscriber::load$($String* name, bool initialize) {
	$loadClass(FlowTube$AbstractTubeSubscriber, name, initialize, &_FlowTube$AbstractTubeSubscriber_ClassInfo_, allocate$FlowTube$AbstractTubeSubscriber);
	return class$;
}

$Class* FlowTube$AbstractTubeSubscriber::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk