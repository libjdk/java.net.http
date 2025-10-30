#include <jdk/internal/net/http/common/SSLFlowDelegate$Reader.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicInteger.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Supplier.h>
#include <javax/net/ssl/SSLEngine.h>
#include <javax/net/ssl/SSLEngineResult$HandshakeStatus.h>
#include <javax/net/ssl/SSLEngineResult$Status.h>
#include <javax/net/ssl/SSLEngineResult.h>
#include <javax/net/ssl/SSLSession.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$1.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$EngineResult.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Reader$ReaderDownstreamPusher.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/SubscriberWrapper$SchedulingAction.h>
#include <jdk/internal/net/http/common/SubscriberWrapper.h>
#include <jdk/internal/net/http/common/SubscriptionBase.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef BUFFER_UNDERFLOW
#undef CLOSED
#undef DEBUG
#undef EMPTY_BB_LIST
#undef NEED_UNWRAP
#undef TARGET_BUFSIZE

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Executor = ::java::util::concurrent::Executor;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicInteger = ::java::util::concurrent::atomic::AtomicInteger;
using $Consumer = ::java::util::function::Consumer;
using $Supplier = ::java::util::function::Supplier;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $SSLEngineResult = ::javax::net::ssl::SSLEngineResult;
using $SSLEngineResult$HandshakeStatus = ::javax::net::ssl::SSLEngineResult$HandshakeStatus;
using $SSLEngineResult$Status = ::javax::net::ssl::SSLEngineResult$Status;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SSLFlowDelegate = ::jdk::internal::net::http::common::SSLFlowDelegate;
using $SSLFlowDelegate$1 = ::jdk::internal::net::http::common::SSLFlowDelegate$1;
using $SSLFlowDelegate$EngineResult = ::jdk::internal::net::http::common::SSLFlowDelegate$EngineResult;
using $SSLFlowDelegate$Reader$ReaderDownstreamPusher = ::jdk::internal::net::http::common::SSLFlowDelegate$Reader$ReaderDownstreamPusher;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SubscriberWrapper = ::jdk::internal::net::http::common::SubscriberWrapper;
using $SubscriberWrapper$SchedulingAction = ::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction;
using $SubscriptionBase = ::jdk::internal::net::http::common::SubscriptionBase;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class SSLFlowDelegate$Reader$$Lambda$dbgString : public $Supplier {
	$class(SSLFlowDelegate$Reader$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(SSLFlowDelegate$Reader* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SSLFlowDelegate$Reader$$Lambda$dbgString>());
	}
	SSLFlowDelegate$Reader* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SSLFlowDelegate$Reader$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SSLFlowDelegate$Reader$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo SSLFlowDelegate$Reader$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/common/SSLFlowDelegate$Reader;)V", nullptr, $PUBLIC, $method(static_cast<void(SSLFlowDelegate$Reader$$Lambda$dbgString::*)(SSLFlowDelegate$Reader*)>(&SSLFlowDelegate$Reader$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SSLFlowDelegate$Reader$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.SSLFlowDelegate$Reader$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* SSLFlowDelegate$Reader$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$Reader$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SSLFlowDelegate$Reader$$Lambda$dbgString::class$ = nullptr;

$FieldInfo _SSLFlowDelegate$Reader_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/common/SSLFlowDelegate;", nullptr, $FINAL | $SYNTHETIC, $field(SSLFlowDelegate$Reader, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SSLFlowDelegate$Reader, $assertionsDisabled)},
	{"TARGET_BUFSIZE", "I", nullptr, $STATIC | $FINAL, $constField(SSLFlowDelegate$Reader, TARGET_BUFSIZE)},
	{"scheduler", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $FINAL, $field(SSLFlowDelegate$Reader, scheduler)},
	{"readBuf", "Ljava/nio/ByteBuffer;", nullptr, $VOLATILE, $field(SSLFlowDelegate$Reader, readBuf)},
	{"completing", "Z", nullptr, $VOLATILE, $field(SSLFlowDelegate$Reader, completing)},
	{"readBufferLock", "Ljava/lang/Object;", nullptr, $FINAL, $field(SSLFlowDelegate$Reader, readBufferLock)},
	{"debugr", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(SSLFlowDelegate$Reader, debugr)},
	{"count", "Ljava/util/concurrent/atomic/AtomicInteger;", nullptr, 0, $field(SSLFlowDelegate$Reader, count)},
	{"minBytesRequired", "I", nullptr, $VOLATILE, $field(SSLFlowDelegate$Reader, minBytesRequired)},
	{"lastUnwrapStatus", "Ljavax/net/ssl/SSLEngineResult$Status;", nullptr, $PRIVATE | $VOLATILE, $field(SSLFlowDelegate$Reader, lastUnwrapStatus)},
	{}
};

$MethodInfo _SSLFlowDelegate$Reader_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/SSLFlowDelegate;)V", nullptr, 0, $method(static_cast<void(SSLFlowDelegate$Reader::*)($SSLFlowDelegate*)>(&SSLFlowDelegate$Reader::init$))},
	{"addToReadBuf", "(Ljava/util/List;Z)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;Z)V", $PRIVATE, $method(static_cast<void(SSLFlowDelegate$Reader::*)($List*,bool)>(&SSLFlowDelegate$Reader::addToReadBuf))},
	{"dbgString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{"enterScheduling", "()Ljdk/internal/net/http/common/SubscriberWrapper$SchedulingAction;", nullptr, $PROTECTED},
	{"errorCommon", "(Ljava/lang/Throwable;)Z", nullptr, $PROTECTED},
	{"incoming", "(Ljava/util/List;Z)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;Z)V", $PUBLIC},
	{"needsMoreData", "()Z", nullptr, 0, $method(static_cast<bool(SSLFlowDelegate$Reader::*)()>(&SSLFlowDelegate$Reader::needsMoreData))},
	{"processData", "()V", nullptr, $FINAL, $method(static_cast<void(SSLFlowDelegate$Reader::*)()>(&SSLFlowDelegate$Reader::processData))},
	{"reallocReadBuf", "()V", nullptr, $PRIVATE, $method(static_cast<void(SSLFlowDelegate$Reader::*)()>(&SSLFlowDelegate$Reader::reallocReadBuf))},
	{"requestMoreDataIfNeeded", "()V", nullptr, 0, $method(static_cast<void(SSLFlowDelegate$Reader::*)()>(&SSLFlowDelegate$Reader::requestMoreDataIfNeeded))},
	{"schedule", "()V", nullptr, 0, $method(static_cast<void(SSLFlowDelegate$Reader::*)()>(&SSLFlowDelegate$Reader::schedule))},
	{"stop", "()V", nullptr, 0, $method(static_cast<void(SSLFlowDelegate$Reader::*)()>(&SSLFlowDelegate$Reader::stop))},
	{"supportsRecycling", "()Z", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unwrapBuffer", "(Ljava/nio/ByteBuffer;)Ljdk/internal/net/http/common/SSLFlowDelegate$EngineResult;", nullptr, 0, $method(static_cast<$SSLFlowDelegate$EngineResult*(SSLFlowDelegate$Reader::*)($ByteBuffer*)>(&SSLFlowDelegate$Reader::unwrapBuffer)), "java.io.IOException"},
	{"upstreamWindowUpdate", "(JJ)J", nullptr, $PROTECTED},
	{}
};

$InnerClassInfo _SSLFlowDelegate$Reader_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SSLFlowDelegate$Reader", "jdk.internal.net.http.common.SSLFlowDelegate", "Reader", $FINAL},
	{"jdk.internal.net.http.common.SSLFlowDelegate$Reader$ReaderDownstreamPusher", "jdk.internal.net.http.common.SSLFlowDelegate$Reader", "ReaderDownstreamPusher", $PRIVATE | $FINAL},
	{}
};

$ClassInfo _SSLFlowDelegate$Reader_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.SSLFlowDelegate$Reader",
	"jdk.internal.net.http.common.SubscriberWrapper",
	nullptr,
	_SSLFlowDelegate$Reader_FieldInfo_,
	_SSLFlowDelegate$Reader_MethodInfo_,
	nullptr,
	nullptr,
	_SSLFlowDelegate$Reader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SSLFlowDelegate"
};

$Object* allocate$SSLFlowDelegate$Reader($Class* clazz) {
	return $of($alloc(SSLFlowDelegate$Reader));
}

bool SSLFlowDelegate$Reader::$assertionsDisabled = false;

void SSLFlowDelegate$Reader::init$($SSLFlowDelegate* this$0) {
	$useLocalCurrentObjectStackCache();
	$set(this, this$0, this$0);
	$SubscriberWrapper::init$();
	$set(this, readBufferLock, $new($Object));
	$init($Utils);
	$set(this, debugr, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(SSLFlowDelegate$Reader$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, count, $new($AtomicInteger));
	$set(this, scheduler, $SequentialScheduler::lockingScheduler($$new($SSLFlowDelegate$Reader$ReaderDownstreamPusher, this)));
	$set(this, readBuf, $ByteBuffer::allocate(1024));
	$nc(this->readBuf)->limit(0);
}

bool SSLFlowDelegate$Reader::supportsRecycling() {
	return this->this$0->recycler != nullptr;
}

$SubscriberWrapper$SchedulingAction* SSLFlowDelegate$Reader::enterScheduling() {
	return this->this$0->enterReadScheduling();
}

$String* SSLFlowDelegate$Reader::dbgString() {
	return $str({"SSL Reader("_s, this->this$0->tubeName, ")"_s});
}

void SSLFlowDelegate$Reader::incoming($List* buffers, bool complete) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debugr)->on()) {
		$nc(this->debugr)->log("Adding %d bytes to read buffer"_s, $$new($ObjectArray, {$($of($Long::valueOf($Utils::remaining(buffers))))}));
	}
	addToReadBuf(buffers, complete);
	$nc(this->scheduler)->runOrSchedule(this->this$0->exec);
}

$String* SSLFlowDelegate$Reader::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$10, $$str({"READER: "_s, $($SubscriberWrapper::toString()), ", readBuf: "_s}));
	$var($String, var$9, $$concat(var$10, $($nc(this->readBuf)->toString())));
	$var($String, var$8, $$concat(var$9, ", count: "));
	$var($String, var$7, $$concat(var$8, $($nc(this->count)->toString())));
	$var($String, var$6, $$concat(var$7, ", scheduler: "));
	$var($String, var$5, $$concat(var$6, ($nc(this->scheduler)->isStopped() ? "stopped"_s : "running"_s)));
	$var($String, var$4, $$concat(var$5, ", status: "));
	$var($String, var$3, $$concat(var$4, this->lastUnwrapStatus));
	$var($String, var$2, $$concat(var$3, ", handshakeState: "));
	$var($String, var$1, $$concat(var$2, $$str($nc(this->this$0->handshakeState)->get())));
	$var($String, var$0, $$concat(var$1, ", engine: "));
	return $concat(var$0, $($nc(this->this$0->engine)->getHandshakeStatus()));
}

void SSLFlowDelegate$Reader::reallocReadBuf() {
	int32_t sz = $nc(this->readBuf)->capacity();
	$var($ByteBuffer, newb, $ByteBuffer::allocate(sz * 2));
	$nc(this->readBuf)->flip();
	$Utils::copy(this->readBuf, newb);
	$set(this, readBuf, newb);
}

int64_t SSLFlowDelegate$Reader::upstreamWindowUpdate(int64_t currentWindow, int64_t downstreamQsize) {
	$useLocalCurrentObjectStackCache();
	if (needsMoreData()) {
		if ($nc(this->debugr)->on()) {
			int32_t remaining = $nc(this->readBuf)->remaining();
			if (remaining > SSLFlowDelegate$Reader::TARGET_BUFSIZE) {
				$nc(this->debugr)->log("readBuf has more than TARGET_BUFSIZE: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(remaining)))}));
			}
		}
		$nc(this->scheduler)->runOrSchedule();
	}
	return 0;
}

void SSLFlowDelegate$Reader::addToReadBuf($List* buffers, bool complete) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = !SSLFlowDelegate$Reader::$assertionsDisabled;
	if (var$0) {
		bool var$1 = $Utils::remaining(buffers) > 0;
		var$0 = !(var$1 || $nc(buffers)->isEmpty());
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	$synchronized(this->readBufferLock) {
		{
			$var($Iterator, i$, $nc(buffers)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ByteBuffer, buf, $cast($ByteBuffer, i$->next()));
				{
					$nc(this->readBuf)->compact();
					while (true) {
						int32_t var$2 = $nc(this->readBuf)->remaining();
						if (!(var$2 < $nc(buf)->remaining())) {
							break;
						}
						{
							reallocReadBuf();
						}
					}
					$nc(this->readBuf)->put(buf);
					$nc(this->readBuf)->flip();
					if (this->this$0->recycler != nullptr) {
						$nc(this->this$0->recycler)->accept(buf);
					}
				}
			}
		}
		if (complete) {
			this->completing = complete;
			this->minBytesRequired = 0;
		}
	}
}

bool SSLFlowDelegate$Reader::errorCommon($Throwable* throwable$renamed) {
	$var($Throwable, throwable, throwable$renamed);
	$assign(throwable, this->this$0->checkForHandshake(throwable));
	return $SubscriberWrapper::errorCommon(throwable);
}

void SSLFlowDelegate$Reader::schedule() {
	$nc(this->scheduler)->runOrSchedule(this->this$0->exec);
}

void SSLFlowDelegate$Reader::stop() {
	if ($nc(this->debugr)->on()) {
		$nc(this->debugr)->log("stop"_s);
	}
	$nc(this->scheduler)->stop();
}

bool SSLFlowDelegate$Reader::needsMoreData() {
	bool var$0 = this->upstreamSubscription != nullptr && $nc(this->readBuf)->remaining() <= this->minBytesRequired;
	if (var$0) {
		$init($SSLEngineResult$HandshakeStatus);
		bool var$1 = $nc(this->this$0->engine)->getHandshakeStatus() == $SSLEngineResult$HandshakeStatus::NEED_UNWRAP;
		if (!var$1) {
			bool var$2 = !$nc($nc(this->downstreamSubscription)->demand)->isFulfilled();
			var$1 = var$2 && hasNoOutputData();
		}
		var$0 = (var$1);
	}
	if (var$0) {
		return true;
	}
	return false;
}

void SSLFlowDelegate$Reader::requestMoreDataIfNeeded() {
	if (needsMoreData()) {
		requestMore();
	}
}

void SSLFlowDelegate$Reader::processData() {
	$useLocalCurrentObjectStackCache();
	try {
		if ($nc(this->debugr)->on()) {
			$var($String, var$2, $$str({"processData: readBuf remaining:"_s, $$str($nc(this->readBuf)->remaining()), ", state:"_s}));
			$var($String, var$1, $$concat(var$2, $($SSLFlowDelegate::states(this->this$0->handshakeState))));
			$var($String, var$0, $$concat(var$1, ", engine handshake status:"));
			$nc(this->debugr)->log($$concat(var$0, $($nc(this->this$0->engine)->getHandshakeStatus())));
		}
		int32_t len = 0;
		bool complete = false;
		while ($nc(this->readBuf)->remaining() > (len = this->minBytesRequired)) {
			bool handshaking = false;
			try {
				$var($SSLFlowDelegate$EngineResult, result, nullptr);
				$synchronized(this->readBufferLock) {
					complete = this->completing;
					if ($nc(this->debugr)->on()) {
						$nc(this->debugr)->log("Unwrapping: %s"_s, $$new($ObjectArray, {$($of($Integer::valueOf($nc(this->readBuf)->remaining())))}));
					}
					len = len > 0 ? this->minBytesRequired = 0 : len;
					$assign(result, unwrapBuffer(this->readBuf));
					len = $nc(this->readBuf)->remaining();
					if ($nc(this->debugr)->on()) {
						$nc(this->debugr)->log("Unwrapped: result: %s"_s, $$new($ObjectArray, {$of($nc(result)->result)}));
						$nc(this->debugr)->log("Unwrapped: consumed: %s"_s, $$new($ObjectArray, {$($of($Integer::valueOf($nc(result)->bytesConsumed())))}));
					}
				}
				if ($nc(result)->bytesProduced() > 0) {
					if ($nc(this->debugr)->on()) {
						$nc(this->debugr)->log("sending %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(result->bytesProduced())))}));
					}
					$nc(this->count)->addAndGet(result->bytesProduced());
					outgoing(result->destBuffer, false);
				}
				$init($SSLEngineResult$Status);
				if ($nc(result)->status() == $SSLEngineResult$Status::BUFFER_UNDERFLOW) {
					if ($nc(this->debugr)->on()) {
						$nc(this->debugr)->log("BUFFER_UNDERFLOW"_s);
					}
					$synchronized(this->readBufferLock) {
						this->minBytesRequired = len;
						if (!SSLFlowDelegate$Reader::$assertionsDisabled && !($nc(this->readBuf)->remaining() >= len)) {
							$throwNew($AssertionError);
						}
						if ($nc(this->readBuf)->remaining() > len) {
							continue;
						} else if (this->completing) {
							if ($nc(this->debug)->on()) {
								$nc(this->debugr)->log("BUFFER_UNDERFLOW with EOF, %d bytes non decrypted."_s, $$new($ObjectArray, {$($of($Integer::valueOf(len)))}));
							}
							$throwNew($IOException, $$str({"BUFFER_UNDERFLOW with EOF, "_s, $$str(len), " bytes non decrypted."_s}));
						}
					}
					requestMore();
					return;
				}
				if (complete && $nc(result)->status() == $SSLEngineResult$Status::CLOSED) {
					if ($nc(this->debugr)->on()) {
						$nc(this->debugr)->log("Closed: completing"_s);
					}
					$init($Utils);
					outgoing($Utils::EMPTY_BB_LIST, true);
					this->this$0->setALPN();
					requestMoreDataIfNeeded();
					return;
				}
				if ($nc(result)->handshaking()) {
					handshaking = true;
					if ($nc(this->debugr)->on()) {
						$nc(this->debugr)->log("handshaking"_s);
					}
					if (this->this$0->doHandshake(result, 1)) {
						continue;
					} else {
						break;
					}
				} else if (this->this$0->trySetALPN()) {
					this->this$0->resumeActivity();
				}
			} catch ($IOException& ex) {
				$var($Throwable, cause, this->this$0->checkForHandshake(ex));
				errorCommon(cause);
				this->this$0->handleError(cause);
				return;
			}
			if (handshaking && !complete) {
				requestMoreDataIfNeeded();
				return;
			}
		}
		if (!complete) {
			$synchronized(this->readBufferLock) {
				complete = this->completing && !$nc(this->readBuf)->hasRemaining();
			}
		}
		if (complete) {
			if ($nc(this->debugr)->on()) {
				$nc(this->debugr)->log("completing"_s);
			}
			this->this$0->setALPN();
			$init($Utils);
			outgoing($Utils::EMPTY_BB_LIST, true);
		} else {
			requestMoreDataIfNeeded();
		}
	} catch ($Throwable& ex) {
		$assign(ex, this->this$0->checkForHandshake(ex));
		errorCommon(ex);
		this->this$0->handleError(ex);
	}
}

$SSLFlowDelegate$EngineResult* SSLFlowDelegate$Reader::unwrapBuffer($ByteBuffer* src) {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, dst, this->this$0->getAppBuffer());
	int32_t len = $nc(src)->remaining();
	while (true) {
		$var($SSLEngineResult, sslResult, $nc(this->this$0->engine)->unwrap(src, dst));
		$init($SSLFlowDelegate$1);
		{
			int32_t appSize = 0;
			$var($ByteBuffer, b, nullptr)
			int32_t size = 0;
			switch ($nc($SSLFlowDelegate$1::$SwitchMap$javax$net$ssl$SSLEngineResult$Status)->get($nc(($set(this, lastUnwrapStatus, $nc(sslResult)->getStatus())))->ordinal())) {
			case 1:
				{
					appSize = (this->this$0->applicationBufferSize = $nc($($nc(this->this$0->engine)->getSession()))->getApplicationBufferSize());
					$assign(b, $ByteBuffer::allocate(appSize + $nc(dst)->position()));
					$nc(dst)->flip();
					$nc(b)->put(dst);
					$assign(dst, b);
					break;
				}
			case 2:
				{
					if (!SSLFlowDelegate$Reader::$assertionsDisabled && !($nc(dst)->position() == 0)) {
						$throwNew($AssertionError);
					}
					return this->this$0->doClosure($$new($SSLFlowDelegate$EngineResult, sslResult));
				}
			case 3:
				{
					if (!SSLFlowDelegate$Reader::$assertionsDisabled && !($nc(dst)->position() == 0)) {
						$throwNew($AssertionError);
					}
					return $new($SSLFlowDelegate$EngineResult, sslResult);
				}
			case 4:
				{
					size = $nc(dst)->position();
					if ($nc(this->debug)->on()) {
						$var($String, var$0, $$str({"Decoded "_s, $$str(size), " bytes out of "_s, $$str(len), " into buffer of "_s, $$str(dst->capacity()), " remaining to decode: "_s}));
						$nc(this->debugr)->log($$concat(var$0, $$str(src->remaining())));
					}
					if (size > this->this$0->adaptiveAppBufferSize) {
						this->this$0->adaptiveAppBufferSize = ((int32_t)((uint32_t)(size + 7) >> 3)) << 3;
					}
					dst->flip();
					return $new($SSLFlowDelegate$EngineResult, sslResult, dst);
				}
			}
		}
	}
}

void clinit$SSLFlowDelegate$Reader($Class* class$) {
	$load($SSLFlowDelegate);
	SSLFlowDelegate$Reader::$assertionsDisabled = !$SSLFlowDelegate::class$->desiredAssertionStatus();
}

SSLFlowDelegate$Reader::SSLFlowDelegate$Reader() {
}

$Class* SSLFlowDelegate$Reader::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SSLFlowDelegate$Reader$$Lambda$dbgString::classInfo$.name)) {
			return SSLFlowDelegate$Reader$$Lambda$dbgString::load$(name, initialize);
		}
	}
	$loadClass(SSLFlowDelegate$Reader, name, initialize, &_SSLFlowDelegate$Reader_ClassInfo_, clinit$SSLFlowDelegate$Reader, allocate$SSLFlowDelegate$Reader);
	return class$;
}

$Class* SSLFlowDelegate$Reader::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk