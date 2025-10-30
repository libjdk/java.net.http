#include <jdk/internal/net/http/websocket/RawChannel$RawEvent.h>

#include <jdk/internal/net/http/websocket/RawChannel.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RawChannel = ::jdk::internal::net::http::websocket::RawChannel;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$MethodInfo _RawChannel$RawEvent_MethodInfo_[] = {
	{"handle", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{"interestOps", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _RawChannel$RawEvent_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.RawChannel$RawEvent", "jdk.internal.net.http.websocket.RawChannel", "RawEvent", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RawChannel$RawEvent_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.websocket.RawChannel$RawEvent",
	nullptr,
	nullptr,
	nullptr,
	_RawChannel$RawEvent_MethodInfo_,
	nullptr,
	nullptr,
	_RawChannel$RawEvent_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.RawChannel"
};

$Object* allocate$RawChannel$RawEvent($Class* clazz) {
	return $of($alloc(RawChannel$RawEvent));
}

$Class* RawChannel$RawEvent::load$($String* name, bool initialize) {
	$loadClass(RawChannel$RawEvent, name, initialize, &_RawChannel$RawEvent_ClassInfo_, allocate$RawChannel$RawEvent);
	return class$;
}

$Class* RawChannel$RawEvent::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk