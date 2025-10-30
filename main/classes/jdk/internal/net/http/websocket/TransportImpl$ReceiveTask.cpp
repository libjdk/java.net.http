#include <jdk/internal/net/http/websocket/TransportImpl$ReceiveTask.h>

#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/nio/ByteBuffer.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/websocket/Frame$Consumer.h>
#include <jdk/internal/net/http/websocket/Frame$Reader.h>
#include <jdk/internal/net/http/websocket/MessageDecoder.h>
#include <jdk/internal/net/http/websocket/MessageStreamConsumer.h>
#include <jdk/internal/net/http/websocket/RawChannel$RawEvent.h>
#include <jdk/internal/net/http/websocket/RawChannel.h>
#include <jdk/internal/net/http/websocket/TransportImpl$1.h>
#include <jdk/internal/net/http/websocket/TransportImpl$ChannelState.h>
#include <jdk/internal/net/http/websocket/TransportImpl.h>
#include <jcpp.h>

#undef UNREGISTERED
#undef WAITING

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SequentialScheduler$CompleteRestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask;
using $Frame$Consumer = ::jdk::internal::net::http::websocket::Frame$Consumer;
using $Frame$Reader = ::jdk::internal::net::http::websocket::Frame$Reader;
using $MessageDecoder = ::jdk::internal::net::http::websocket::MessageDecoder;
using $MessageStreamConsumer = ::jdk::internal::net::http::websocket::MessageStreamConsumer;
using $RawChannel = ::jdk::internal::net::http::websocket::RawChannel;
using $RawChannel$RawEvent = ::jdk::internal::net::http::websocket::RawChannel$RawEvent;
using $TransportImpl = ::jdk::internal::net::http::websocket::TransportImpl;
using $TransportImpl$1 = ::jdk::internal::net::http::websocket::TransportImpl$1;
using $TransportImpl$ChannelState = ::jdk::internal::net::http::websocket::TransportImpl$ChannelState;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _TransportImpl$ReceiveTask_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/websocket/TransportImpl;", nullptr, $FINAL | $SYNTHETIC, $field(TransportImpl$ReceiveTask, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(TransportImpl$ReceiveTask, $assertionsDisabled)},
	{}
};

$MethodInfo _TransportImpl$ReceiveTask_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/websocket/TransportImpl;)V", nullptr, $PRIVATE, $method(static_cast<void(TransportImpl$ReceiveTask::*)($TransportImpl*)>(&TransportImpl$ReceiveTask::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _TransportImpl$ReceiveTask_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.TransportImpl$ReceiveTask", "jdk.internal.net.http.websocket.TransportImpl", "ReceiveTask", $PRIVATE},
	{"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "CompleteRestartableTask", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _TransportImpl$ReceiveTask_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.websocket.TransportImpl$ReceiveTask",
	"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask",
	nullptr,
	_TransportImpl$ReceiveTask_FieldInfo_,
	_TransportImpl$ReceiveTask_MethodInfo_,
	nullptr,
	nullptr,
	_TransportImpl$ReceiveTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.TransportImpl"
};

$Object* allocate$TransportImpl$ReceiveTask($Class* clazz) {
	return $of($alloc(TransportImpl$ReceiveTask));
}

bool TransportImpl$ReceiveTask::$assertionsDisabled = false;

void TransportImpl$ReceiveTask::init$($TransportImpl* this$0) {
	$set(this, this$0, this$0);
	$SequentialScheduler$CompleteRestartableTask::init$();
}

void TransportImpl$ReceiveTask::run() {
	$useLocalCurrentObjectStackCache();
	$init($TransportImpl);
	if ($nc($TransportImpl::debug)->on()) {
		$nc($TransportImpl::debug)->log("enter receive task"_s);
	}
	bool loop$continue = false;
	bool loop$break = false;
	while (!$nc(this->this$0->receiveScheduler)->isStopped()) {
		$TransportImpl$ChannelState* rs = this->this$0->readState;
		if ($nc(this->this$0->data)->hasRemaining()) {
			if ($nc($TransportImpl::debug)->on()) {
				$nc($TransportImpl::debug)->log("remaining bytes received %s"_s, $$new($ObjectArray, {$($of($Integer::valueOf($nc(this->this$0->data)->remaining())))}));
			}
			if (!$nc(this->this$0->demand)->isFulfilled()) {
				try {
					int32_t oldPos = $nc(this->this$0->data)->position();
					$nc(this->this$0->reader)->readFrame(this->this$0->data, this->this$0->decoder);
					int32_t newPos = $nc(this->this$0->data)->position();
					if (!TransportImpl$ReceiveTask::$assertionsDisabled && !(oldPos != newPos)) {
						$throwNew($AssertionError, $of(this->this$0->data));
					}
				} catch ($Throwable& e) {
					$nc(this->this$0->receiveScheduler)->stop();
					$nc(this->this$0->messageConsumer)->onError(e);
				}
				if (!$nc(this->this$0->data)->hasRemaining()) {
					$init($TransportImpl$ChannelState);
					rs = ($set(this->this$0, readState, $TransportImpl$ChannelState::UNREGISTERED));
				}
				continue;
			}
			loop$break = true;
			break;
		}
		if ($nc($TransportImpl::debug)->on()) {
			$nc($TransportImpl::debug)->log("receive state: %s"_s, $$new($ObjectArray, {$of(rs)}));
		}
		$init($TransportImpl$1);
		switch ($nc($TransportImpl$1::$SwitchMap$jdk$internal$net$http$websocket$TransportImpl$ChannelState)->get($nc((rs))->ordinal())) {
		case 1:
			{
				loop$break = true;
				break;
			}
		case 2:
			{
				try {
					$init($TransportImpl$ChannelState);
					rs = ($set(this->this$0, readState, $TransportImpl$ChannelState::WAITING));
					$nc(this->this$0->channel)->registerEvent(this->this$0->readEvent);
				} catch ($Throwable& e) {
					$nc(this->this$0->receiveScheduler)->stop();
					$nc(this->this$0->messageConsumer)->onError(e);
				}
				loop$break = true;
				break;
			}
		case 3:
			{
				try {
					$set(this->this$0, data, $nc(this->this$0->channel)->read());
				} catch ($Throwable& e) {
					$nc(this->this$0->receiveScheduler)->stop();
					$nc(this->this$0->messageConsumer)->onError(e);
					loop$break = true;
					break;
				}
				if (this->this$0->data == nullptr) {
					$nc(this->this$0->receiveScheduler)->stop();
					$nc(this->this$0->messageConsumer)->onComplete();
					loop$break = true;
					break;
				} else if (!$nc(this->this$0->data)->hasRemaining()) {
					$init($TransportImpl$ChannelState);
					rs = ($set(this->this$0, readState, $TransportImpl$ChannelState::UNREGISTERED));
				}
				continue;
			}
		default:
			{
				$throwNew($InternalError, $($String::valueOf($of(rs))));
			}
		}

		if (loop$continue) {
			loop$continue = false;
			continue;
		}
		if (loop$break) {
			break;
		}	}
	if ($nc($TransportImpl::debug)->on()) {
		$nc($TransportImpl::debug)->log("exit receive task"_s);
	}
}

void clinit$TransportImpl$ReceiveTask($Class* class$) {
	$load($TransportImpl);
	TransportImpl$ReceiveTask::$assertionsDisabled = !$TransportImpl::class$->desiredAssertionStatus();
}

TransportImpl$ReceiveTask::TransportImpl$ReceiveTask() {
}

$Class* TransportImpl$ReceiveTask::load$($String* name, bool initialize) {
	$loadClass(TransportImpl$ReceiveTask, name, initialize, &_TransportImpl$ReceiveTask_ClassInfo_, clinit$TransportImpl$ReceiveTask, allocate$TransportImpl$ReceiveTask);
	return class$;
}

$Class* TransportImpl$ReceiveTask::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk