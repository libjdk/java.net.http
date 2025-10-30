#include <jdk/internal/net/http/common/FlowTube$AbstractTubePublisher.h>

#include <jdk/internal/net/http/common/FlowTube.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $FlowTube$TubePublisher = ::jdk::internal::net::http::common::FlowTube$TubePublisher;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$MethodInfo _FlowTube$AbstractTubePublisher_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(FlowTube$AbstractTubePublisher::*)()>(&FlowTube$AbstractTubePublisher::init$))},
	{}
};

$InnerClassInfo _FlowTube$AbstractTubePublisher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.FlowTube$AbstractTubePublisher", "jdk.internal.net.http.common.FlowTube", "AbstractTubePublisher", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.net.http.common.FlowTube$TubePublisher", "jdk.internal.net.http.common.FlowTube", "TubePublisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.common.FlowTube$AbstractTubePublisher$TubePublisherWrapper", "jdk.internal.net.http.common.FlowTube$AbstractTubePublisher", "TubePublisherWrapper", $STATIC | $FINAL},
	{}
};

$ClassInfo _FlowTube$AbstractTubePublisher_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.common.FlowTube$AbstractTubePublisher",
	"java.lang.Object",
	"jdk.internal.net.http.common.FlowTube$TubePublisher",
	nullptr,
	_FlowTube$AbstractTubePublisher_MethodInfo_,
	nullptr,
	nullptr,
	_FlowTube$AbstractTubePublisher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.FlowTube"
};

$Object* allocate$FlowTube$AbstractTubePublisher($Class* clazz) {
	return $of($alloc(FlowTube$AbstractTubePublisher));
}

void FlowTube$AbstractTubePublisher::init$() {
}

FlowTube$AbstractTubePublisher::FlowTube$AbstractTubePublisher() {
}

$Class* FlowTube$AbstractTubePublisher::load$($String* name, bool initialize) {
	$loadClass(FlowTube$AbstractTubePublisher, name, initialize, &_FlowTube$AbstractTubePublisher_ClassInfo_, allocate$FlowTube$AbstractTubePublisher);
	return class$;
}

$Class* FlowTube$AbstractTubePublisher::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk