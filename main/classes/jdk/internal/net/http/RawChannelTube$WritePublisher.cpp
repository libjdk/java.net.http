#include <jdk/internal/net/http/RawChannelTube$WritePublisher.h>

#include <java/util/concurrent/ConcurrentLinkedQueue.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <jdk/internal/net/http/RawChannelTube$WriteSubscription.h>
#include <jdk/internal/net/http/RawChannelTube.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ConcurrentLinkedQueue = ::java::util::concurrent::ConcurrentLinkedQueue;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $RawChannelTube = ::jdk::internal::net::http::RawChannelTube;
using $RawChannelTube$WriteSubscription = ::jdk::internal::net::http::RawChannelTube$WriteSubscription;
using $FlowTube$TubePublisher = ::jdk::internal::net::http::common::FlowTube$TubePublisher;
using $Logger = ::jdk::internal::net::http::common::Logger;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _RawChannelTube$WritePublisher_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/RawChannelTube;", nullptr, $FINAL | $SYNTHETIC, $field(RawChannelTube$WritePublisher, this$0)},
	{"events", "Ljava/util/concurrent/ConcurrentLinkedQueue;", "Ljava/util/concurrent/ConcurrentLinkedQueue<Ljdk/internal/net/http/websocket/RawChannel$RawEvent;>;", $FINAL, $field(RawChannelTube$WritePublisher, events)},
	{"writeSubscription", "Ljdk/internal/net/http/RawChannelTube$WriteSubscription;", nullptr, $VOLATILE, $field(RawChannelTube$WritePublisher, writeSubscription)},
	{}
};

$MethodInfo _RawChannelTube$WritePublisher_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/RawChannelTube;)V", nullptr, 0, $method(static_cast<void(RawChannelTube$WritePublisher::*)($RawChannelTube*)>(&RawChannelTube$WritePublisher::init$))},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", $PUBLIC},
	{}
};

$InnerClassInfo _RawChannelTube$WritePublisher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RawChannelTube$WritePublisher", "jdk.internal.net.http.RawChannelTube", "WritePublisher", 0},
	{"jdk.internal.net.http.common.FlowTube$TubePublisher", "jdk.internal.net.http.common.FlowTube", "TubePublisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RawChannelTube$WritePublisher_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.RawChannelTube$WritePublisher",
	"java.lang.Object",
	"jdk.internal.net.http.common.FlowTube$TubePublisher",
	_RawChannelTube$WritePublisher_FieldInfo_,
	_RawChannelTube$WritePublisher_MethodInfo_,
	nullptr,
	nullptr,
	_RawChannelTube$WritePublisher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RawChannelTube"
};

$Object* allocate$RawChannelTube$WritePublisher($Class* clazz) {
	return $of($alloc(RawChannelTube$WritePublisher));
}

void RawChannelTube$WritePublisher::init$($RawChannelTube* this$0) {
	$set(this, this$0, this$0);
	$set(this, events, $new($ConcurrentLinkedQueue));
}

void RawChannelTube$WritePublisher::subscribe($Flow$Subscriber* subscriber) {
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("WritePublisher::subscribe"_s);
	}
	$var($RawChannelTube$WriteSubscription, subscription, $new($RawChannelTube$WriteSubscription, this->this$0, subscriber));
	$nc(subscriber)->onSubscribe(subscription);
	$set(this, writeSubscription, subscription);
}

RawChannelTube$WritePublisher::RawChannelTube$WritePublisher() {
}

$Class* RawChannelTube$WritePublisher::load$($String* name, bool initialize) {
	$loadClass(RawChannelTube$WritePublisher, name, initialize, &_RawChannelTube$WritePublisher_ClassInfo_, allocate$RawChannelTube$WritePublisher);
	return class$;
}

$Class* RawChannelTube$WritePublisher::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk