#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>

#include <jdk/internal/net/http/common/FlowTube.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$MethodInfo _FlowTube$TubeSubscriber_MethodInfo_[] = {
	{"dropSubscription", "()V", nullptr, $PUBLIC},
	{"supportsRecycling", "()Z", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _FlowTube$TubeSubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.FlowTube$TubeSubscriber", "jdk.internal.net.http.common.FlowTube", "TubeSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.Flow$Subscriber", "java.util.concurrent.Flow", "Subscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _FlowTube$TubeSubscriber_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.common.FlowTube$TubeSubscriber",
	nullptr,
	"java.util.concurrent.Flow$Subscriber",
	nullptr,
	_FlowTube$TubeSubscriber_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/concurrent/Flow$Subscriber<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;",
	nullptr,
	_FlowTube$TubeSubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.FlowTube"
};

$Object* allocate$FlowTube$TubeSubscriber($Class* clazz) {
	return $of($alloc(FlowTube$TubeSubscriber));
}

void FlowTube$TubeSubscriber::dropSubscription() {
}

bool FlowTube$TubeSubscriber::supportsRecycling() {
	return false;
}

$Class* FlowTube$TubeSubscriber::load$($String* name, bool initialize) {
	$loadClass(FlowTube$TubeSubscriber, name, initialize, &_FlowTube$TubeSubscriber_ClassInfo_, allocate$FlowTube$TubeSubscriber);
	return class$;
}

$Class* FlowTube$TubeSubscriber::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk