#include <jdk/internal/net/http/websocket/WebSocketImpl$ReceiveTask.h>

#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/InternalError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/ProtocolException.h>
#include <java/net/http/WebSocket$Listener.h>
#include <java/net/http/WebSocket.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/websocket/FailWebSocketException.h>
#include <jdk/internal/net/http/websocket/Transport.h>
#include <jdk/internal/net/http/websocket/WebSocketImpl$1.h>
#include <jdk/internal/net/http/websocket/WebSocketImpl$State.h>
#include <jdk/internal/net/http/websocket/WebSocketImpl.h>
#include <jcpp.h>

#undef BINARY
#undef DONE
#undef IDLE
#undef OPEN
#undef PING
#undef PONG
#undef TEXT
#undef WAITING

using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ProtocolException = ::java::net::ProtocolException;
using $WebSocket = ::java::net::http::WebSocket;
using $WebSocket$Listener = ::java::net::http::WebSocket$Listener;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Supplier = ::java::util::function::Supplier;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SequentialScheduler$CompleteRestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $FailWebSocketException = ::jdk::internal::net::http::websocket::FailWebSocketException;
using $Transport = ::jdk::internal::net::http::websocket::Transport;
using $WebSocketImpl = ::jdk::internal::net::http::websocket::WebSocketImpl;
using $WebSocketImpl$1 = ::jdk::internal::net::http::websocket::WebSocketImpl$1;
using $WebSocketImpl$State = ::jdk::internal::net::http::websocket::WebSocketImpl$State;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0 : public $BiConsumer {
	$class(WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(WebSocketImpl$ReceiveTask* inst, int32_t code) {
		$set(this, inst$, inst);
		this->code = code;
	}
	virtual void accept(Object$* r, Object$* e) override {
		$nc(inst$)->lambda$processClose$0(code, r, $cast($Throwable, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0>());
	}
	WebSocketImpl$ReceiveTask* inst$ = nullptr;
	int32_t code = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0, inst$)},
	{"code", "I", nullptr, $PUBLIC, $field(WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0, code)},
	{}
};
$MethodInfo WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/websocket/WebSocketImpl$ReceiveTask;I)V", nullptr, $PUBLIC, $method(static_cast<void(WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0::*)(WebSocketImpl$ReceiveTask*,int32_t)>(&WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.websocket.WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0::load$($String* name, bool initialize) {
	$loadClass(WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0::class$ = nullptr;

class WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1 : public $BiConsumer {
	$class(WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(WebSocketImpl$ReceiveTask* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* r, Object$* e) override {
		$nc(inst$)->lambda$processPing$1($cast($WebSocketImpl, r), $cast($Throwable, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1>());
	}
	WebSocketImpl$ReceiveTask* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1, inst$)},
	{}
};
$MethodInfo WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/websocket/WebSocketImpl$ReceiveTask;)V", nullptr, $PUBLIC, $method(static_cast<void(WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1::*)(WebSocketImpl$ReceiveTask*)>(&WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.websocket.WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1::load$($String* name, bool initialize) {
	$loadClass(WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1::class$ = nullptr;

class WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2 : public $Supplier {
	$class(WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2, $NO_CLASS_INIT, $Supplier)
public:
	void init$($WebSocketImpl* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->clearAutomaticPong());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2>());
	}
	$WebSocketImpl* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2, inst$)},
	{}
};
$MethodInfo WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/websocket/WebSocketImpl;)V", nullptr, $PUBLIC, $method(static_cast<void(WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2::*)($WebSocketImpl*)>(&WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.websocket.WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2::load$($String* name, bool initialize) {
	$loadClass(WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2::class$ = nullptr;

$FieldInfo _WebSocketImpl$ReceiveTask_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/websocket/WebSocketImpl;", nullptr, $FINAL | $SYNTHETIC, $field(WebSocketImpl$ReceiveTask, this$0)},
	{}
};

$MethodInfo _WebSocketImpl$ReceiveTask_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/websocket/WebSocketImpl;)V", nullptr, $PRIVATE, $method(static_cast<void(WebSocketImpl$ReceiveTask::*)($WebSocketImpl*)>(&WebSocketImpl$ReceiveTask::init$))},
	{"lambda$processClose$0", "(ILjava/lang/Object;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(WebSocketImpl$ReceiveTask::*)(int32_t,Object$*,$Throwable*)>(&WebSocketImpl$ReceiveTask::lambda$processClose$0))},
	{"lambda$processPing$1", "(Ljdk/internal/net/http/websocket/WebSocketImpl;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(WebSocketImpl$ReceiveTask::*)($WebSocketImpl*,$Throwable*)>(&WebSocketImpl$ReceiveTask::lambda$processPing$1))},
	{"processBinary", "()V", nullptr, $PRIVATE, $method(static_cast<void(WebSocketImpl$ReceiveTask::*)()>(&WebSocketImpl$ReceiveTask::processBinary))},
	{"processClose", "()V", nullptr, $PRIVATE, $method(static_cast<void(WebSocketImpl$ReceiveTask::*)()>(&WebSocketImpl$ReceiveTask::processClose)), "java.io.IOException"},
	{"processError", "()V", nullptr, $PRIVATE, $method(static_cast<void(WebSocketImpl$ReceiveTask::*)()>(&WebSocketImpl$ReceiveTask::processError)), "java.io.IOException"},
	{"processOpen", "()V", nullptr, $PRIVATE, $method(static_cast<void(WebSocketImpl$ReceiveTask::*)()>(&WebSocketImpl$ReceiveTask::processOpen))},
	{"processPing", "()V", nullptr, $PRIVATE, $method(static_cast<void(WebSocketImpl$ReceiveTask::*)()>(&WebSocketImpl$ReceiveTask::processPing))},
	{"processPong", "()V", nullptr, $PRIVATE, $method(static_cast<void(WebSocketImpl$ReceiveTask::*)()>(&WebSocketImpl$ReceiveTask::processPong))},
	{"processText", "()V", nullptr, $PRIVATE, $method(static_cast<void(WebSocketImpl$ReceiveTask::*)()>(&WebSocketImpl$ReceiveTask::processText))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _WebSocketImpl$ReceiveTask_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.WebSocketImpl$ReceiveTask", "jdk.internal.net.http.websocket.WebSocketImpl", "ReceiveTask", $PRIVATE},
	{"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "CompleteRestartableTask", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _WebSocketImpl$ReceiveTask_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.websocket.WebSocketImpl$ReceiveTask",
	"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask",
	nullptr,
	_WebSocketImpl$ReceiveTask_FieldInfo_,
	_WebSocketImpl$ReceiveTask_MethodInfo_,
	nullptr,
	nullptr,
	_WebSocketImpl$ReceiveTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.WebSocketImpl"
};

$Object* allocate$WebSocketImpl$ReceiveTask($Class* clazz) {
	return $of($alloc(WebSocketImpl$ReceiveTask));
}

void WebSocketImpl$ReceiveTask::init$($WebSocketImpl* this$0) {
	$set(this, this$0, this$0);
	$SequentialScheduler$CompleteRestartableTask::init$();
}

void WebSocketImpl$ReceiveTask::run() {
	$useLocalCurrentObjectStackCache();
	$init($WebSocketImpl);
	if ($nc($WebSocketImpl::debug)->on()) {
		$nc($WebSocketImpl::debug)->log("enter receive task"_s);
	}
	bool loop$break = false;
	while (!$nc(this->this$0->receiveScheduler)->isStopped()) {
		$WebSocketImpl$State* s = $cast($WebSocketImpl$State, $nc(this->this$0->state)->get());
		if ($nc($WebSocketImpl::debug)->on()) {
			$nc($WebSocketImpl::debug)->log("receive state: %s"_s, $$new($ObjectArray, {$of(s)}));
		}
		try {
			$init($WebSocketImpl$1);
			switch ($nc($WebSocketImpl$1::$SwitchMap$jdk$internal$net$http$websocket$WebSocketImpl$State)->get($nc((s))->ordinal())) {
			case 1:
				{
					processOpen();
					$init($WebSocketImpl$State);
					this->this$0->tryChangeState($WebSocketImpl$State::OPEN, $WebSocketImpl$State::IDLE);
					break;
				}
			case 2:
				{
					processText();
					$init($WebSocketImpl$State);
					this->this$0->tryChangeState($WebSocketImpl$State::TEXT, $WebSocketImpl$State::IDLE);
					break;
				}
			case 3:
				{
					processBinary();
					$init($WebSocketImpl$State);
					this->this$0->tryChangeState($WebSocketImpl$State::BINARY, $WebSocketImpl$State::IDLE);
					break;
				}
			case 4:
				{
					processPing();
					$init($WebSocketImpl$State);
					this->this$0->tryChangeState($WebSocketImpl$State::PING, $WebSocketImpl$State::IDLE);
					break;
				}
			case 5:
				{
					processPong();
					$init($WebSocketImpl$State);
					this->this$0->tryChangeState($WebSocketImpl$State::PONG, $WebSocketImpl$State::IDLE);
					break;
				}
			case 6:
				{
					processClose();
					loop$break = true;
					break;
				}
			case 7:
				{
					processError();
					loop$break = true;
					break;
				}
			case 8:
				{
					bool var$0 = $nc(this->this$0->demand)->tryDecrement();
					$init($WebSocketImpl$State);
					if (var$0 && this->this$0->tryChangeState($WebSocketImpl$State::IDLE, $WebSocketImpl$State::WAITING)) {
						$nc(this->this$0->transport$)->request(1);
					}
					loop$break = true;
					break;
				}
			case 9:
				{
					loop$break = true;
					break;
				}
			default:
				{
					$throwNew($InternalError, $($String::valueOf($of(s))));
				}
			}

			if (loop$break) {
				break;
			}		} catch ($Throwable& t) {
			this->this$0->signalError(t);
		}
	}
	if ($nc($WebSocketImpl::debug)->on()) {
		$nc($WebSocketImpl::debug)->log("exit receive task"_s);
	}
}

void WebSocketImpl$ReceiveTask::processError() {
	$useLocalCurrentObjectStackCache();
	$init($WebSocketImpl);
	if ($nc($WebSocketImpl::debug)->on()) {
		$nc($WebSocketImpl::debug)->log("processError"_s);
	}
	$nc(this->this$0->transport$)->closeInput();
	$nc(this->this$0->receiveScheduler)->stop();
	$var($Throwable, err, $cast($Throwable, $nc(this->this$0->error)->get()));
	if ($instanceOf($FailWebSocketException, err)) {
		int32_t code1 = $nc(($cast($FailWebSocketException, err)))->getStatusCode();
		$assign(err, $$new($ProtocolException)->initCause(err));
		if ($nc($WebSocketImpl::debug)->on()) {
			$nc($WebSocketImpl::debug)->log("failing %s with error=%s statusCode=%s"_s, $$new($ObjectArray, {
				$of(this->this$0),
				$of(err),
				$($of($Integer::valueOf(code1)))
			}));
		}
		this->this$0->sendCloseSilently(code1);
	}
	int64_t id = 0;
	if ($nc($WebSocketImpl::debug)->on()) {
		id = $nc(this->this$0->receiveCounter)->incrementAndGet();
		$nc($WebSocketImpl::debug)->log("enter onError %s error=%s"_s, $$new($ObjectArray, {
			$($of($Long::valueOf(id))),
			$of(err)
		}));
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->this$0->listener)->onError(this->this$0, err);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if ($nc($WebSocketImpl::debug)->on()) {
				$nc($WebSocketImpl::debug)->log("exit onError %s"_s, $$new($ObjectArray, {$($of($Long::valueOf(id)))}));
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void WebSocketImpl$ReceiveTask::processClose() {
	$useLocalCurrentObjectStackCache();
	$init($WebSocketImpl);
	$nc($WebSocketImpl::debug)->log("processClose"_s);
	$nc(this->this$0->transport$)->closeInput();
	$nc(this->this$0->receiveScheduler)->stop();
	$var($CompletionStage, cs, nullptr);
	int64_t id = 0;
	if ($nc($WebSocketImpl::debug)->on()) {
		id = $nc(this->this$0->receiveCounter)->incrementAndGet();
		$nc($WebSocketImpl::debug)->log("enter onClose %s statusCode=%s reason.length=%s"_s, $$new($ObjectArray, {
			$($of($Long::valueOf(id))),
			$($of($Integer::valueOf(this->this$0->statusCode))),
			$($of($Integer::valueOf($nc(this->this$0->reason)->length())))
		}));
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			$assign(cs, $nc(this->this$0->listener)->onClose(this->this$0, this->this$0->statusCode, this->this$0->reason));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc($WebSocketImpl::debug)->log("exit onClose %s returned %s"_s, $$new($ObjectArray, {
				$($of($Long::valueOf(id))),
				$of(cs)
			}));
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	if (cs == nullptr) {
		$assign(cs, this->this$0->DONE);
	}
	int32_t code = 0;
	if (this->this$0->statusCode == 1005 || this->this$0->statusCode == 1006) {
		code = 1000;
		$nc($WebSocketImpl::debug)->log("using statusCode %s instead of %s"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf(this->this$0->statusCode))),
			$($of($Integer::valueOf(code)))
		}));
	} else {
		code = this->this$0->statusCode;
	}
	$nc(cs)->whenComplete(static_cast<$BiConsumer*>($$new(WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0, this, code)));
}

void WebSocketImpl$ReceiveTask::processPong() {
	$useLocalCurrentObjectStackCache();
	int64_t id = 0;
	$init($WebSocketImpl);
	if ($nc($WebSocketImpl::debug)->on()) {
		id = $nc(this->this$0->receiveCounter)->incrementAndGet();
		$nc($WebSocketImpl::debug)->log("enter onPong %s payload=%s"_s, $$new($ObjectArray, {
			$($of($Long::valueOf(id))),
			$of(this->this$0->binaryData)
		}));
	}
	$var($CompletionStage, cs, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			$assign(cs, $nc(this->this$0->listener)->onPong(this->this$0, this->this$0->binaryData));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if ($nc($WebSocketImpl::debug)->on()) {
				$nc($WebSocketImpl::debug)->log("exit onPong %s returned %s"_s, $$new($ObjectArray, {
					$($of($Long::valueOf(id))),
					$of(cs)
				}));
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void WebSocketImpl$ReceiveTask::processPing() {
	$useLocalCurrentObjectStackCache();
	$init($WebSocketImpl);
	if ($nc($WebSocketImpl::debug)->on()) {
		$nc($WebSocketImpl::debug)->log("processPing"_s);
	}
	$var($ByteBuffer, slice, $nc(this->this$0->binaryData)->slice());
	if (!$nc(this->this$0->outputClosed)->get()) {
		$var($ByteBuffer, copy, $nc($($nc($($ByteBuffer::allocate($nc(this->this$0->binaryData)->remaining())))->put(this->this$0->binaryData)))->flip());
		if (!this->this$0->trySwapAutomaticPong(copy)) {
			$var($BiConsumer, reporter, static_cast<$BiConsumer*>($new(WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1, this)));
			$nc(this->this$0->transport$)->sendPong(static_cast<$Supplier*>($$new(WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2, this->this$0)), $of(this->this$0), reporter);
		}
	}
	int64_t id = 0;
	if ($nc($WebSocketImpl::debug)->on()) {
		id = $nc(this->this$0->receiveCounter)->incrementAndGet();
		$nc($WebSocketImpl::debug)->log("enter onPing %s payload=%s"_s, $$new($ObjectArray, {
			$($of($Long::valueOf(id))),
			$of(slice)
		}));
	}
	$var($CompletionStage, cs, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			$assign(cs, $nc(this->this$0->listener)->onPing(this->this$0, slice));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if ($nc($WebSocketImpl::debug)->on()) {
				$nc($WebSocketImpl::debug)->log("exit onPing %s returned %s"_s, $$new($ObjectArray, {
					$($of($Long::valueOf(id))),
					$of(cs)
				}));
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void WebSocketImpl$ReceiveTask::processBinary() {
	$useLocalCurrentObjectStackCache();
	int64_t id = 0;
	$init($WebSocketImpl);
	if ($nc($WebSocketImpl::debug)->on()) {
		id = $nc(this->this$0->receiveCounter)->incrementAndGet();
		$nc($WebSocketImpl::debug)->log("enter onBinary %s payload=%s last=%s"_s, $$new($ObjectArray, {
			$($of($Long::valueOf(id))),
			$of(this->this$0->binaryData),
			$($of($Boolean::valueOf(this->this$0->last)))
		}));
	}
	$var($CompletionStage, cs, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			$assign(cs, $nc(this->this$0->listener)->onBinary(this->this$0, this->this$0->binaryData, this->this$0->last));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if ($nc($WebSocketImpl::debug)->on()) {
				$nc($WebSocketImpl::debug)->log("exit onBinary %s returned %s"_s, $$new($ObjectArray, {
					$($of($Long::valueOf(id))),
					$of(cs)
				}));
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void WebSocketImpl$ReceiveTask::processText() {
	$useLocalCurrentObjectStackCache();
	int64_t id = 0;
	$init($WebSocketImpl);
	if ($nc($WebSocketImpl::debug)->on()) {
		id = $nc(this->this$0->receiveCounter)->incrementAndGet();
		$nc($WebSocketImpl::debug)->log("enter onText %s payload.length=%s last=%s"_s, $$new($ObjectArray, {
			$($of($Long::valueOf(id))),
			$($of($Integer::valueOf($nc(this->this$0->text)->length()))),
			$($of($Boolean::valueOf(this->this$0->last)))
		}));
	}
	$var($CompletionStage, cs, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			$assign(cs, $nc(this->this$0->listener)->onText(this->this$0, this->this$0->text, this->this$0->last));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if ($nc($WebSocketImpl::debug)->on()) {
				$nc($WebSocketImpl::debug)->log("exit onText %s returned %s"_s, $$new($ObjectArray, {
					$($of($Long::valueOf(id))),
					$of(cs)
				}));
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void WebSocketImpl$ReceiveTask::processOpen() {
	$useLocalCurrentObjectStackCache();
	int64_t id = 0;
	$init($WebSocketImpl);
	if ($nc($WebSocketImpl::debug)->on()) {
		id = $nc(this->this$0->receiveCounter)->incrementAndGet();
		$nc($WebSocketImpl::debug)->log("enter onOpen %s"_s, $$new($ObjectArray, {$($of($Long::valueOf(id)))}));
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->this$0->listener)->onOpen(this->this$0);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if ($nc($WebSocketImpl::debug)->on()) {
				$nc($WebSocketImpl::debug)->log("exit onOpen %s"_s, $$new($ObjectArray, {$($of($Long::valueOf(id)))}));
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void WebSocketImpl$ReceiveTask::lambda$processPing$1($WebSocketImpl* r, $Throwable* e) {
	if (e != nullptr) {
		this->this$0->signalError($($Utils::getCompletionCause(e)));
	}
}

void WebSocketImpl$ReceiveTask::lambda$processClose$0(int32_t code, Object$* r, $Throwable* e) {
	$init($WebSocketImpl);
	if ($nc($WebSocketImpl::debug)->on()) {
		$nc($WebSocketImpl::debug)->log("CompletionStage returned by onClose completed result=%s error=%s"_s, $$new($ObjectArray, {
			r,
			$of(e)
		}));
	}
	this->this$0->sendCloseSilently(code);
}

WebSocketImpl$ReceiveTask::WebSocketImpl$ReceiveTask() {
}

$Class* WebSocketImpl$ReceiveTask::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0::classInfo$.name)) {
			return WebSocketImpl$ReceiveTask$$Lambda$lambda$processClose$0::load$(name, initialize);
		}
		if (name->equals(WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1::classInfo$.name)) {
			return WebSocketImpl$ReceiveTask$$Lambda$lambda$processPing$1$1::load$(name, initialize);
		}
		if (name->equals(WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2::classInfo$.name)) {
			return WebSocketImpl$ReceiveTask$$Lambda$clearAutomaticPong$2::load$(name, initialize);
		}
	}
	$loadClass(WebSocketImpl$ReceiveTask, name, initialize, &_WebSocketImpl$ReceiveTask_ClassInfo_, allocate$WebSocketImpl$ReceiveTask);
	return class$;
}

$Class* WebSocketImpl$ReceiveTask::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk