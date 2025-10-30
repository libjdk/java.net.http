#include <jdk/internal/net/http/websocket/TransportImpl$WriteEvent.h>

#include <java/nio/channels/SelectionKey.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/websocket/TransportImpl$ChannelState.h>
#include <jdk/internal/net/http/websocket/TransportImpl.h>
#include <jcpp.h>

#undef AVAILABLE
#undef CLOSED
#undef OP_WRITE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SelectionKey = ::java::nio::channels::SelectionKey;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $RawChannel$RawEvent = ::jdk::internal::net::http::websocket::RawChannel$RawEvent;
using $TransportImpl = ::jdk::internal::net::http::websocket::TransportImpl;
using $TransportImpl$ChannelState = ::jdk::internal::net::http::websocket::TransportImpl$ChannelState;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _TransportImpl$WriteEvent_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/websocket/TransportImpl;", nullptr, $FINAL | $SYNTHETIC, $field(TransportImpl$WriteEvent, this$0)},
	{}
};

$MethodInfo _TransportImpl$WriteEvent_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/websocket/TransportImpl;)V", nullptr, $PRIVATE, $method(static_cast<void(TransportImpl$WriteEvent::*)($TransportImpl*)>(&TransportImpl$WriteEvent::init$))},
	{"handle", "()V", nullptr, $PUBLIC},
	{"interestOps", "()I", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _TransportImpl$WriteEvent_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.TransportImpl$WriteEvent", "jdk.internal.net.http.websocket.TransportImpl", "WriteEvent", $PRIVATE},
	{"jdk.internal.net.http.websocket.RawChannel$RawEvent", "jdk.internal.net.http.websocket.RawChannel", "RawEvent", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _TransportImpl$WriteEvent_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.websocket.TransportImpl$WriteEvent",
	"java.lang.Object",
	"jdk.internal.net.http.websocket.RawChannel$RawEvent",
	_TransportImpl$WriteEvent_FieldInfo_,
	_TransportImpl$WriteEvent_MethodInfo_,
	nullptr,
	nullptr,
	_TransportImpl$WriteEvent_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.TransportImpl"
};

$Object* allocate$TransportImpl$WriteEvent($Class* clazz) {
	return $of($alloc(TransportImpl$WriteEvent));
}

void TransportImpl$WriteEvent::init$($TransportImpl* this$0) {
	$set(this, this$0, this$0);
}

int32_t TransportImpl$WriteEvent::interestOps() {
	return $SelectionKey::OP_WRITE;
}

void TransportImpl$WriteEvent::handle() {
	$useLocalCurrentObjectStackCache();
	$init($TransportImpl);
	if ($nc($TransportImpl::debug)->on()) {
		$nc($TransportImpl::debug)->log("write event"_s);
	}
	$TransportImpl$ChannelState* s = nullptr;
	do {
		s = $cast($TransportImpl$ChannelState, $nc(this->this$0->writeState)->get());
		$init($TransportImpl$ChannelState);
		if (s == $TransportImpl$ChannelState::CLOSED) {
			if ($nc($TransportImpl::debug)->on()) {
				$nc($TransportImpl::debug)->log("write state %s"_s, $$new($ObjectArray, {$of(s)}));
			}
			break;
		}
	$init($TransportImpl$ChannelState);
	} while (!$nc(this->this$0->writeState)->compareAndSet(s, $TransportImpl$ChannelState::AVAILABLE));
	$nc(this->this$0->sendScheduler)->runOrSchedule();
}

TransportImpl$WriteEvent::TransportImpl$WriteEvent() {
}

$Class* TransportImpl$WriteEvent::load$($String* name, bool initialize) {
	$loadClass(TransportImpl$WriteEvent, name, initialize, &_TransportImpl$WriteEvent_ClassInfo_, allocate$TransportImpl$WriteEvent);
	return class$;
}

$Class* TransportImpl$WriteEvent::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk