#include <jdk/internal/net/http/SocketTube$InternalReadPublisher$ReadEvent.h>

#include <java/nio/channels/SelectionKey.h>
#include <java/nio/channels/SocketChannel.h>
#include <jdk/internal/net/http/AsyncEvent.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher$InternalReadSubscription.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher.h>
#include <jdk/internal/net/http/SocketTube$SocketFlowEvent.h>
#include <jdk/internal/net/http/SocketTube.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jcpp.h>

#undef OP_READ

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SelectionKey = ::java::nio::channels::SelectionKey;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $AsyncEvent = ::jdk::internal::net::http::AsyncEvent;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $SocketTube = ::jdk::internal::net::http::SocketTube;
using $SocketTube$InternalReadPublisher = ::jdk::internal::net::http::SocketTube$InternalReadPublisher;
using $SocketTube$InternalReadPublisher$InternalReadSubscription = ::jdk::internal::net::http::SocketTube$InternalReadPublisher$InternalReadSubscription;
using $SocketTube$SocketFlowEvent = ::jdk::internal::net::http::SocketTube$SocketFlowEvent;
using $Logger = ::jdk::internal::net::http::common::Logger;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _SocketTube$InternalReadPublisher$ReadEvent_FieldInfo_[] = {
	{"this$1", "Ljdk/internal/net/http/SocketTube$InternalReadPublisher;", nullptr, $FINAL | $SYNTHETIC, $field(SocketTube$InternalReadPublisher$ReadEvent, this$1)},
	{"sub", "Ljdk/internal/net/http/SocketTube$InternalReadPublisher$InternalReadSubscription;", nullptr, $FINAL, $field(SocketTube$InternalReadPublisher$ReadEvent, sub)},
	{}
};

$MethodInfo _SocketTube$InternalReadPublisher$ReadEvent_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/SocketTube$InternalReadPublisher;Ljava/nio/channels/SocketChannel;Ljdk/internal/net/http/SocketTube$InternalReadPublisher$InternalReadSubscription;)V", nullptr, 0, $method(static_cast<void(SocketTube$InternalReadPublisher$ReadEvent::*)($SocketTube$InternalReadPublisher*,$SocketChannel*,$SocketTube$InternalReadPublisher$InternalReadSubscription*)>(&SocketTube$InternalReadPublisher$ReadEvent::init$))},
	{"debug", "()Ljdk/internal/net/http/common/Logger;", nullptr, 0},
	{"signalError", "(Ljava/lang/Throwable;)V", nullptr, $PROTECTED | $FINAL},
	{"signalEvent", "()V", nullptr, $PROTECTED | $FINAL},
	{}
};

$InnerClassInfo _SocketTube$InternalReadPublisher$ReadEvent_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.SocketTube$InternalReadPublisher", "jdk.internal.net.http.SocketTube", "InternalReadPublisher", $PRIVATE | $FINAL},
	{"jdk.internal.net.http.SocketTube$InternalReadPublisher$ReadEvent", "jdk.internal.net.http.SocketTube$InternalReadPublisher", "ReadEvent", $FINAL},
	{"jdk.internal.net.http.SocketTube$SocketFlowEvent", "jdk.internal.net.http.SocketTube", "SocketFlowEvent", $PRIVATE | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SocketTube$InternalReadPublisher$ReadEvent_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.SocketTube$InternalReadPublisher$ReadEvent",
	"jdk.internal.net.http.SocketTube$SocketFlowEvent",
	nullptr,
	_SocketTube$InternalReadPublisher$ReadEvent_FieldInfo_,
	_SocketTube$InternalReadPublisher$ReadEvent_MethodInfo_,
	nullptr,
	nullptr,
	_SocketTube$InternalReadPublisher$ReadEvent_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.SocketTube"
};

$Object* allocate$SocketTube$InternalReadPublisher$ReadEvent($Class* clazz) {
	return $of($alloc(SocketTube$InternalReadPublisher$ReadEvent));
}

void SocketTube$InternalReadPublisher$ReadEvent::init$($SocketTube$InternalReadPublisher* this$1, $SocketChannel* channel, $SocketTube$InternalReadPublisher$InternalReadSubscription* sub) {
	$set(this, this$1, this$1);
	$SocketTube$SocketFlowEvent::init$($SelectionKey::OP_READ, channel);
	$set(this, sub, sub);
}

void SocketTube$InternalReadPublisher$ReadEvent::signalEvent() {
	try {
		$nc($nc(this->this$1->this$0)->client)->eventUpdated(this);
		$nc(this->sub)->signalReadable();
	} catch ($Throwable& t) {
		$nc(this->sub)->signalError(t);
	}
}

void SocketTube$InternalReadPublisher$ReadEvent::signalError($Throwable* error) {
	if ($nc($nc(this->this$1->this$0)->debug)->on()) {
		$nc($nc(this->this$1->this$0)->debug)->log("signalError to %s (%s)"_s, $$new($ObjectArray, {
			$of(this->sub),
			$of(error)
		}));
	}
	$nc(this->sub)->signalError(error);
}

$Logger* SocketTube$InternalReadPublisher$ReadEvent::debug() {
	return $nc(this->this$1->this$0)->debug;
}

SocketTube$InternalReadPublisher$ReadEvent::SocketTube$InternalReadPublisher$ReadEvent() {
}

$Class* SocketTube$InternalReadPublisher$ReadEvent::load$($String* name, bool initialize) {
	$loadClass(SocketTube$InternalReadPublisher$ReadEvent, name, initialize, &_SocketTube$InternalReadPublisher$ReadEvent_ClassInfo_, allocate$SocketTube$InternalReadPublisher$ReadEvent);
	return class$;
}

$Class* SocketTube$InternalReadPublisher$ReadEvent::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk