#include <jdk/internal/net/http/common/FlowTube$AbstractTubePublisher$TubePublisherWrapper.h>

#include <java/util/concurrent/Flow$Publisher.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <jdk/internal/net/http/common/FlowTube$AbstractTubePublisher.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Flow$Publisher = ::java::util::concurrent::Flow$Publisher;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $FlowTube$AbstractTubePublisher = ::jdk::internal::net::http::common::FlowTube$AbstractTubePublisher;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _FlowTube$AbstractTubePublisher$TubePublisherWrapper_FieldInfo_[] = {
	{"delegate", "Ljava/util/concurrent/Flow$Publisher;", "Ljava/util/concurrent/Flow$Publisher<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;", $FINAL, $field(FlowTube$AbstractTubePublisher$TubePublisherWrapper, delegate)},
	{}
};

$MethodInfo _FlowTube$AbstractTubePublisher$TubePublisherWrapper_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/Flow$Publisher;)V", "(Ljava/util/concurrent/Flow$Publisher<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", $PUBLIC, $method(static_cast<void(FlowTube$AbstractTubePublisher$TubePublisherWrapper::*)($Flow$Publisher*)>(&FlowTube$AbstractTubePublisher$TubePublisherWrapper::init$))},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", $PUBLIC},
	{}
};

$InnerClassInfo _FlowTube$AbstractTubePublisher$TubePublisherWrapper_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.FlowTube$AbstractTubePublisher", "jdk.internal.net.http.common.FlowTube", "AbstractTubePublisher", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.net.http.common.FlowTube$AbstractTubePublisher$TubePublisherWrapper", "jdk.internal.net.http.common.FlowTube$AbstractTubePublisher", "TubePublisherWrapper", $STATIC | $FINAL},
	{}
};

$ClassInfo _FlowTube$AbstractTubePublisher$TubePublisherWrapper_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.FlowTube$AbstractTubePublisher$TubePublisherWrapper",
	"jdk.internal.net.http.common.FlowTube$AbstractTubePublisher",
	nullptr,
	_FlowTube$AbstractTubePublisher$TubePublisherWrapper_FieldInfo_,
	_FlowTube$AbstractTubePublisher$TubePublisherWrapper_MethodInfo_,
	nullptr,
	nullptr,
	_FlowTube$AbstractTubePublisher$TubePublisherWrapper_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.FlowTube"
};

$Object* allocate$FlowTube$AbstractTubePublisher$TubePublisherWrapper($Class* clazz) {
	return $of($alloc(FlowTube$AbstractTubePublisher$TubePublisherWrapper));
}

void FlowTube$AbstractTubePublisher$TubePublisherWrapper::init$($Flow$Publisher* delegate) {
	$FlowTube$AbstractTubePublisher::init$();
	$set(this, delegate, delegate);
}

void FlowTube$AbstractTubePublisher$TubePublisherWrapper::subscribe($Flow$Subscriber* subscriber) {
	$nc(this->delegate)->subscribe(subscriber);
}

FlowTube$AbstractTubePublisher$TubePublisherWrapper::FlowTube$AbstractTubePublisher$TubePublisherWrapper() {
}

$Class* FlowTube$AbstractTubePublisher$TubePublisherWrapper::load$($String* name, bool initialize) {
	$loadClass(FlowTube$AbstractTubePublisher$TubePublisherWrapper, name, initialize, &_FlowTube$AbstractTubePublisher$TubePublisherWrapper_ClassInfo_, allocate$FlowTube$AbstractTubePublisher$TubePublisherWrapper);
	return class$;
}

$Class* FlowTube$AbstractTubePublisher$TubePublisherWrapper::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk