#include <jdk/internal/net/http/common/FlowTube.h>

#include <java/util/concurrent/Flow$Publisher.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <jdk/internal/net/http/common/FlowTube$AbstractTubePublisher$TubePublisherWrapper.h>
#include <jdk/internal/net/http/common/FlowTube$AbstractTubePublisher.h>
#include <jdk/internal/net/http/common/FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper.h>
#include <jdk/internal/net/http/common/FlowTube$AbstractTubeSubscriber.h>
#include <jdk/internal/net/http/common/FlowTube$TubePublisher.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Flow$Publisher = ::java::util::concurrent::Flow$Publisher;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $FlowTube$AbstractTubePublisher = ::jdk::internal::net::http::common::FlowTube$AbstractTubePublisher;
using $FlowTube$AbstractTubePublisher$TubePublisherWrapper = ::jdk::internal::net::http::common::FlowTube$AbstractTubePublisher$TubePublisherWrapper;
using $FlowTube$AbstractTubeSubscriber = ::jdk::internal::net::http::common::FlowTube$AbstractTubeSubscriber;
using $FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper = ::jdk::internal::net::http::common::FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper;
using $FlowTube$TubePublisher = ::jdk::internal::net::http::common::FlowTube$TubePublisher;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$MethodInfo _FlowTube_MethodInfo_[] = {
	{"asTubePublisher", "(Ljava/util/concurrent/Flow$Publisher;)Ljdk/internal/net/http/common/FlowTube$TubePublisher;", "(Ljava/util/concurrent/Flow$Publisher<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)Ljdk/internal/net/http/common/FlowTube$TubePublisher;", $PUBLIC | $STATIC, $method(static_cast<$FlowTube$TubePublisher*(*)($Flow$Publisher*)>(&FlowTube::asTubePublisher))},
	{"asTubeSubscriber", "(Ljava/util/concurrent/Flow$Subscriber;)Ljdk/internal/net/http/common/FlowTube$TubeSubscriber;", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)Ljdk/internal/net/http/common/FlowTube$TubeSubscriber;", $PUBLIC | $STATIC, $method(static_cast<$FlowTube$TubeSubscriber*(*)($Flow$Subscriber*)>(&FlowTube::asTubeSubscriber))},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"connectFlows", "(Ljdk/internal/net/http/common/FlowTube$TubePublisher;Ljdk/internal/net/http/common/FlowTube$TubeSubscriber;)V", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"isFinished", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _FlowTube_InnerClassesInfo_[] = {
	{"java.util.concurrent.Flow$Publisher", "java.util.concurrent.Flow", "Publisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.Flow$Subscriber", "java.util.concurrent.Flow", "Subscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.common.FlowTube$AbstractTubeSubscriber", "jdk.internal.net.http.common.FlowTube", "AbstractTubeSubscriber", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.net.http.common.FlowTube$AbstractTubePublisher", "jdk.internal.net.http.common.FlowTube", "AbstractTubePublisher", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.net.http.common.FlowTube$TubePublisher", "jdk.internal.net.http.common.FlowTube", "TubePublisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.common.FlowTube$TubeSubscriber", "jdk.internal.net.http.common.FlowTube", "TubeSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _FlowTube_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.common.FlowTube",
	nullptr,
	"java.util.concurrent.Flow$Publisher,java.util.concurrent.Flow$Subscriber",
	nullptr,
	_FlowTube_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/concurrent/Flow$Publisher<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;Ljava/util/concurrent/Flow$Subscriber<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;",
	nullptr,
	_FlowTube_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.FlowTube$AbstractTubeSubscriber,jdk.internal.net.http.common.FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper,jdk.internal.net.http.common.FlowTube$AbstractTubePublisher,jdk.internal.net.http.common.FlowTube$AbstractTubePublisher$TubePublisherWrapper,jdk.internal.net.http.common.FlowTube$TubePublisher,jdk.internal.net.http.common.FlowTube$TubeSubscriber"
};

$Object* allocate$FlowTube($Class* clazz) {
	return $of($alloc(FlowTube));
}

int32_t FlowTube::hashCode() {
	 return this->$Flow$Publisher::hashCode();
}

bool FlowTube::equals(Object$* arg0) {
	 return this->$Flow$Publisher::equals(arg0);
}

$Object* FlowTube::clone() {
	 return this->$Flow$Publisher::clone();
}

$String* FlowTube::toString() {
	 return this->$Flow$Publisher::toString();
}

void FlowTube::finalize() {
	this->$Flow$Publisher::finalize();
}

void FlowTube::connectFlows($FlowTube$TubePublisher* writePublisher, $FlowTube$TubeSubscriber* readSubscriber) {
	this->subscribe(readSubscriber);
	$nc(writePublisher)->subscribe(this);
}

$FlowTube$TubeSubscriber* FlowTube::asTubeSubscriber($Flow$Subscriber* s) {
	$init(FlowTube);
	if ($instanceOf($FlowTube$TubeSubscriber, s)) {
		return $cast($FlowTube$TubeSubscriber, s);
	}
	return $new($FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper, s);
}

$FlowTube$TubePublisher* FlowTube::asTubePublisher($Flow$Publisher* p) {
	$init(FlowTube);
	if ($instanceOf($FlowTube$TubePublisher, p)) {
		return $cast($FlowTube$TubePublisher, p);
	}
	return $new($FlowTube$AbstractTubePublisher$TubePublisherWrapper, p);
}

$Class* FlowTube::load$($String* name, bool initialize) {
	$loadClass(FlowTube, name, initialize, &_FlowTube_ClassInfo_, allocate$FlowTube);
	return class$;
}

$Class* FlowTube::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk