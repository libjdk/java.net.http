#include <jdk/internal/net/http/websocket/TransportImpl$ReadEvent.h>

#include <java/nio/channels/SelectionKey.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/websocket/TransportImpl$ChannelState.h>
#include <jdk/internal/net/http/websocket/TransportImpl.h>
#include <jcpp.h>

#undef AVAILABLE
#undef OP_READ

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SelectionKey = ::java::nio::channels::SelectionKey;
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

$FieldInfo _TransportImpl$ReadEvent_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/websocket/TransportImpl;", nullptr, $FINAL | $SYNTHETIC, $field(TransportImpl$ReadEvent, this$0)},
	{}
};

$MethodInfo _TransportImpl$ReadEvent_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/websocket/TransportImpl;)V", nullptr, $PRIVATE, $method(static_cast<void(TransportImpl$ReadEvent::*)($TransportImpl*)>(&TransportImpl$ReadEvent::init$))},
	{"handle", "()V", nullptr, $PUBLIC},
	{"interestOps", "()I", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _TransportImpl$ReadEvent_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.TransportImpl$ReadEvent", "jdk.internal.net.http.websocket.TransportImpl", "ReadEvent", $PRIVATE},
	{"jdk.internal.net.http.websocket.RawChannel$RawEvent", "jdk.internal.net.http.websocket.RawChannel", "RawEvent", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _TransportImpl$ReadEvent_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.websocket.TransportImpl$ReadEvent",
	"java.lang.Object",
	"jdk.internal.net.http.websocket.RawChannel$RawEvent",
	_TransportImpl$ReadEvent_FieldInfo_,
	_TransportImpl$ReadEvent_MethodInfo_,
	nullptr,
	nullptr,
	_TransportImpl$ReadEvent_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.TransportImpl"
};

$Object* allocate$TransportImpl$ReadEvent($Class* clazz) {
	return $of($alloc(TransportImpl$ReadEvent));
}

void TransportImpl$ReadEvent::init$($TransportImpl* this$0) {
	$set(this, this$0, this$0);
}

int32_t TransportImpl$ReadEvent::interestOps() {
	return $SelectionKey::OP_READ;
}

void TransportImpl$ReadEvent::handle() {
	$init($TransportImpl);
	if ($nc($TransportImpl::debug)->on()) {
		$nc($TransportImpl::debug)->log("read event"_s);
	}
	$init($TransportImpl$ChannelState);
	$set(this->this$0, readState, $TransportImpl$ChannelState::AVAILABLE);
	$nc(this->this$0->receiveScheduler)->runOrSchedule();
}

TransportImpl$ReadEvent::TransportImpl$ReadEvent() {
}

$Class* TransportImpl$ReadEvent::load$($String* name, bool initialize) {
	$loadClass(TransportImpl$ReadEvent, name, initialize, &_TransportImpl$ReadEvent_ClassInfo_, allocate$TransportImpl$ReadEvent);
	return class$;
}

$Class* TransportImpl$ReadEvent::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk