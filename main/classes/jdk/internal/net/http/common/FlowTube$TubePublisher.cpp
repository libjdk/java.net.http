#include <jdk/internal/net/http/common/FlowTube$TubePublisher.h>

#include <jdk/internal/net/http/common/FlowTube.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Flow$Publisher = ::java::util::concurrent::Flow$Publisher;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$InnerClassInfo _FlowTube$TubePublisher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.FlowTube$TubePublisher", "jdk.internal.net.http.common.FlowTube", "TubePublisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.Flow$Publisher", "java.util.concurrent.Flow", "Publisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _FlowTube$TubePublisher_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.common.FlowTube$TubePublisher",
	nullptr,
	"java.util.concurrent.Flow$Publisher",
	nullptr,
	nullptr,
	"Ljava/lang/Object;Ljava/util/concurrent/Flow$Publisher<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;",
	nullptr,
	_FlowTube$TubePublisher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.FlowTube"
};

$Object* allocate$FlowTube$TubePublisher($Class* clazz) {
	return $of($alloc(FlowTube$TubePublisher));
}

$Class* FlowTube$TubePublisher::load$($String* name, bool initialize) {
	$loadClass(FlowTube$TubePublisher, name, initialize, &_FlowTube$TubePublisher_ClassInfo_, allocate$FlowTube$TubePublisher);
	return class$;
}

$Class* FlowTube$TubePublisher::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk