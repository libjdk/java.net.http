#include <jdk/internal/net/http/AsyncTriggerEvent.h>

#include <java/io/IOException.h>
#include <java/lang/Runnable.h>
#include <java/nio/channels/SelectableChannel.h>
#include <java/util/Objects.h>
#include <java/util/function/Consumer.h>
#include <jdk/internal/net/http/AsyncEvent.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $SelectableChannel = ::java::nio::channels::SelectableChannel;
using $Objects = ::java::util::Objects;
using $Consumer = ::java::util::function::Consumer;
using $AsyncEvent = ::jdk::internal::net::http::AsyncEvent;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _AsyncTriggerEvent_FieldInfo_[] = {
	{"trigger", "Ljava/lang/Runnable;", nullptr, $PRIVATE | $FINAL, $field(AsyncTriggerEvent, trigger)},
	{"errorHandler", "Ljava/util/function/Consumer;", "Ljava/util/function/Consumer<-Ljava/io/IOException;>;", $PRIVATE | $FINAL, $field(AsyncTriggerEvent, errorHandler)},
	{}
};

$MethodInfo _AsyncTriggerEvent_MethodInfo_[] = {
	{"<init>", "(Ljava/util/function/Consumer;Ljava/lang/Runnable;)V", "(Ljava/util/function/Consumer<-Ljava/io/IOException;>;Ljava/lang/Runnable;)V", 0, $method(static_cast<void(AsyncTriggerEvent::*)($Consumer*,$Runnable*)>(&AsyncTriggerEvent::init$))},
	{"abort", "(Ljava/io/IOException;)V", nullptr, $PUBLIC},
	{"channel", "()Ljava/nio/channels/SelectableChannel;", nullptr, $PUBLIC},
	{"handle", "()V", nullptr, $PUBLIC},
	{"interestOps", "()I", nullptr, $PUBLIC},
	{"repeating", "()Z", nullptr, $PUBLIC},
	{}
};

$ClassInfo _AsyncTriggerEvent_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.AsyncTriggerEvent",
	"jdk.internal.net.http.AsyncEvent",
	nullptr,
	_AsyncTriggerEvent_FieldInfo_,
	_AsyncTriggerEvent_MethodInfo_
};

$Object* allocate$AsyncTriggerEvent($Class* clazz) {
	return $of($alloc(AsyncTriggerEvent));
}

void AsyncTriggerEvent::init$($Consumer* errorHandler, $Runnable* trigger) {
	$AsyncEvent::init$(0);
	$set(this, trigger, $cast($Runnable, $Objects::requireNonNull(trigger)));
	$set(this, errorHandler, $cast($Consumer, $Objects::requireNonNull(errorHandler)));
}

$SelectableChannel* AsyncTriggerEvent::channel() {
	return nullptr;
}

int32_t AsyncTriggerEvent::interestOps() {
	return 0;
}

void AsyncTriggerEvent::handle() {
	$nc(this->trigger)->run();
}

void AsyncTriggerEvent::abort($IOException* ioe) {
	$nc(this->errorHandler)->accept(ioe);
}

bool AsyncTriggerEvent::repeating() {
	return false;
}

AsyncTriggerEvent::AsyncTriggerEvent() {
}

$Class* AsyncTriggerEvent::load$($String* name, bool initialize) {
	$loadClass(AsyncTriggerEvent, name, initialize, &_AsyncTriggerEvent_ClassInfo_, allocate$AsyncTriggerEvent);
	return class$;
}

$Class* AsyncTriggerEvent::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk