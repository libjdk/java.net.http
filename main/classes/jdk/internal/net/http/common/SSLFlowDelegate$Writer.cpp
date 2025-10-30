#include <jdk/internal/net/http/common/SSLFlowDelegate$Writer.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractSequentialList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/function/Supplier.h>
#include <javax/net/ssl/SSLEngine.h>
#include <javax/net/ssl/SSLEngineResult$HandshakeStatus.h>
#include <javax/net/ssl/SSLEngineResult$Status.h>
#include <javax/net/ssl/SSLEngineResult.h>
#include <javax/net/ssl/SSLSession.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$1.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$EngineResult.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Writer$WriterDownstreamPusher.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate.h>
#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler$RestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/SubscriberWrapper.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef CLOSED
#undef DEBUG
#undef EMPTY_BB_ARRAY
#undef EMPTY_BB_LIST
#undef HS_TRIGGER
#undef NEED_WRAP
#undef NOTHING
#undef SENTINEL

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AbstractList = ::java::util::AbstractList;
using $AbstractSequentialList = ::java::util::AbstractSequentialList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Supplier = ::java::util::function::Supplier;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $SSLEngineResult = ::javax::net::ssl::SSLEngineResult;
using $SSLEngineResult$HandshakeStatus = ::javax::net::ssl::SSLEngineResult$HandshakeStatus;
using $SSLEngineResult$Status = ::javax::net::ssl::SSLEngineResult$Status;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SSLFlowDelegate = ::jdk::internal::net::http::common::SSLFlowDelegate;
using $SSLFlowDelegate$1 = ::jdk::internal::net::http::common::SSLFlowDelegate$1;
using $SSLFlowDelegate$EngineResult = ::jdk::internal::net::http::common::SSLFlowDelegate$EngineResult;
using $SSLFlowDelegate$Writer$WriterDownstreamPusher = ::jdk::internal::net::http::common::SSLFlowDelegate$Writer$WriterDownstreamPusher;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SequentialScheduler$CompleteRestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask;
using $SequentialScheduler$RestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$RestartableTask;
using $SubscriberWrapper = ::jdk::internal::net::http::common::SubscriberWrapper;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class SSLFlowDelegate$Writer$$Lambda$dbgString : public $Supplier {
	$class(SSLFlowDelegate$Writer$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(SSLFlowDelegate$Writer* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SSLFlowDelegate$Writer$$Lambda$dbgString>());
	}
	SSLFlowDelegate$Writer* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SSLFlowDelegate$Writer$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SSLFlowDelegate$Writer$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo SSLFlowDelegate$Writer$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/common/SSLFlowDelegate$Writer;)V", nullptr, $PUBLIC, $method(static_cast<void(SSLFlowDelegate$Writer$$Lambda$dbgString::*)(SSLFlowDelegate$Writer*)>(&SSLFlowDelegate$Writer$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SSLFlowDelegate$Writer$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.SSLFlowDelegate$Writer$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* SSLFlowDelegate$Writer$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$Writer$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SSLFlowDelegate$Writer$$Lambda$dbgString::class$ = nullptr;

$FieldInfo _SSLFlowDelegate$Writer_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/common/SSLFlowDelegate;", nullptr, $FINAL | $SYNTHETIC, $field(SSLFlowDelegate$Writer, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SSLFlowDelegate$Writer, $assertionsDisabled)},
	{"scheduler", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $FINAL, $field(SSLFlowDelegate$Writer, scheduler)},
	{"writeList", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/ByteBuffer;>;", $FINAL, $field(SSLFlowDelegate$Writer, writeList)},
	{"debugw", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(SSLFlowDelegate$Writer, debugw)},
	{"completing", "Z", nullptr, $VOLATILE, $field(SSLFlowDelegate$Writer, completing)},
	{"completed", "Z", nullptr, 0, $field(SSLFlowDelegate$Writer, completed)},
	{"writeBuffer", "Ljava/nio/ByteBuffer;", nullptr, $VOLATILE, $field(SSLFlowDelegate$Writer, writeBuffer)},
	{"lastWrappedStatus", "Ljavax/net/ssl/SSLEngineResult$Status;", nullptr, $PRIVATE | $VOLATILE, $field(SSLFlowDelegate$Writer, lastWrappedStatus)},
	{}
};

$MethodInfo _SSLFlowDelegate$Writer_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/SSLFlowDelegate;)V", nullptr, 0, $method(static_cast<void(SSLFlowDelegate$Writer::*)($SSLFlowDelegate*)>(&SSLFlowDelegate$Writer::init$))},
	{"closing", "()Z", nullptr, $PUBLIC},
	{"dbgString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{"hsTriggered", "()Z", nullptr, $PRIVATE, $method(static_cast<bool(SSLFlowDelegate$Writer::*)()>(&SSLFlowDelegate$Writer::hsTriggered))},
	{"incoming", "(Ljava/util/List;Z)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;Z)V", $PROTECTED},
	{"isCompleting", "()Z", nullptr, $PRIVATE, $method(static_cast<bool(SSLFlowDelegate$Writer::*)()>(&SSLFlowDelegate$Writer::isCompleting))},
	{"needWrap", "()Z", nullptr, $PRIVATE, $method(static_cast<bool(SSLFlowDelegate$Writer::*)()>(&SSLFlowDelegate$Writer::needWrap))},
	{"onSubscribe", "()V", nullptr, $PROTECTED},
	{"processData", "()V", nullptr, $PRIVATE, $method(static_cast<void(SSLFlowDelegate$Writer::*)()>(&SSLFlowDelegate$Writer::processData))},
	{"schedule", "()V", nullptr, 0},
	{"sendResultBytes", "(Ljdk/internal/net/http/common/SSLFlowDelegate$EngineResult;)V", nullptr, $PRIVATE, $method(static_cast<void(SSLFlowDelegate$Writer::*)($SSLFlowDelegate$EngineResult*)>(&SSLFlowDelegate$Writer::sendResultBytes))},
	{"stop", "()V", nullptr, 0},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"triggerWrite", "()V", nullptr, 0},
	{"upstreamWindowUpdate", "(JJ)J", nullptr, $PROTECTED},
	{"wrapBuffers", "([Ljava/nio/ByteBuffer;)Ljdk/internal/net/http/common/SSLFlowDelegate$EngineResult;", nullptr, 0, nullptr, "javax.net.ssl.SSLException"},
	{}
};

$InnerClassInfo _SSLFlowDelegate$Writer_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SSLFlowDelegate$Writer", "jdk.internal.net.http.common.SSLFlowDelegate", "Writer", 0},
	{"jdk.internal.net.http.common.SSLFlowDelegate$Writer$WriterDownstreamPusher", "jdk.internal.net.http.common.SSLFlowDelegate$Writer", "WriterDownstreamPusher", 0},
	{}
};

$ClassInfo _SSLFlowDelegate$Writer_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.common.SSLFlowDelegate$Writer",
	"jdk.internal.net.http.common.SubscriberWrapper",
	nullptr,
	_SSLFlowDelegate$Writer_FieldInfo_,
	_SSLFlowDelegate$Writer_MethodInfo_,
	nullptr,
	nullptr,
	_SSLFlowDelegate$Writer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SSLFlowDelegate"
};

$Object* allocate$SSLFlowDelegate$Writer($Class* clazz) {
	return $of($alloc(SSLFlowDelegate$Writer));
}

bool SSLFlowDelegate$Writer::$assertionsDisabled = false;

void SSLFlowDelegate$Writer::init$($SSLFlowDelegate* this$0) {
	$useLocalCurrentObjectStackCache();
	$set(this, this$0, this$0);
	$SubscriberWrapper::init$();
	$init($Utils);
	$set(this, debugw, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(SSLFlowDelegate$Writer$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, writeList, $Collections::synchronizedList($$new($LinkedList)));
	$set(this, scheduler, $new($SequentialScheduler, $$new($SSLFlowDelegate$Writer$WriterDownstreamPusher, this)));
}

void SSLFlowDelegate$Writer::incoming($List* buffers, bool complete) {
	$useLocalCurrentObjectStackCache();
	$init($Utils);
	if (!SSLFlowDelegate$Writer::$assertionsDisabled && !(complete ? buffers == $Utils::EMPTY_BB_LIST : true)) {
		$throwNew($AssertionError);
	}
	if (!SSLFlowDelegate$Writer::$assertionsDisabled && !(buffers != $Utils::EMPTY_BB_LIST ? complete == false : true)) {
		$throwNew($AssertionError);
	}
	if (complete) {
		if ($nc(this->debugw)->on()) {
			$nc(this->debugw)->log("adding SENTINEL"_s);
		}
		this->completing = true;
		$init($SSLFlowDelegate);
		$nc(this->writeList)->add($SSLFlowDelegate::SENTINEL);
	} else {
		$nc(this->writeList)->addAll(buffers);
	}
	if ($nc(this->debugw)->on()) {
		$var($String, var$1, $$str({"added "_s, $$str($nc(buffers)->size()), " ("_s}));
		$var($String, var$0, $$concat(var$1, $$str($Utils::remaining(buffers))));
		$nc(this->debugw)->log($$concat(var$0, " bytes) to the writeList"));
	}
	$nc(this->scheduler)->runOrSchedule();
}

$String* SSLFlowDelegate$Writer::dbgString() {
	return $str({"SSL Writer("_s, this->this$0->tubeName, ")"_s});
}

void SSLFlowDelegate$Writer::onSubscribe() {
	if ($nc(this->debugw)->on()) {
		$nc(this->debugw)->log("onSubscribe initiating handshaking"_s);
	}
	$init($SSLFlowDelegate);
	addData($SSLFlowDelegate::HS_TRIGGER);
}

void SSLFlowDelegate$Writer::schedule() {
	$nc(this->scheduler)->runOrSchedule();
}

void SSLFlowDelegate$Writer::stop() {
	if ($nc(this->debugw)->on()) {
		$nc(this->debugw)->log("stop"_s);
	}
	$nc(this->scheduler)->stop();
}

bool SSLFlowDelegate$Writer::closing() {
	return this->this$0->closeNotifyReceived();
}

bool SSLFlowDelegate$Writer::isCompleting() {
	return this->completing;
}

int64_t SSLFlowDelegate$Writer::upstreamWindowUpdate(int64_t currentWindow, int64_t downstreamQsize) {
	if ($nc(this->writeList)->size() > 10) {
		return 0;
	} else {
		return $SubscriberWrapper::upstreamWindowUpdate(currentWindow, downstreamQsize);
	}
}

bool SSLFlowDelegate$Writer::hsTriggered() {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->writeList) {
		{
			$var($Iterator, i$, $nc(this->writeList)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ByteBuffer, b, $cast($ByteBuffer, i$->next()));
				$init($SSLFlowDelegate);
				if (b == $SSLFlowDelegate::HS_TRIGGER) {
					return true;
				}
			}
		}
		return false;
	}
}

void SSLFlowDelegate$Writer::triggerWrite() {
	$synchronized(this->writeList) {
		if ($nc(this->writeList)->isEmpty()) {
			$init($SSLFlowDelegate);
			$nc(this->writeList)->add($SSLFlowDelegate::HS_TRIGGER);
		}
	}
	$nc(this->scheduler)->runOrSchedule();
}

void SSLFlowDelegate$Writer::processData() {
	$useLocalCurrentObjectStackCache();
	bool completing = isCompleting();
	try {
		if ($nc(this->debugw)->on()) {
			$var($String, var$2, $$str({"processData, writeList remaining:"_s, $$str($Utils::synchronizedRemaining(this->writeList)), ", hsTriggered:"_s}));
			$var($String, var$1, $$concat(var$2, $$str(hsTriggered())));
			$var($String, var$0, $$concat(var$1, ", needWrap:"));
			$nc(this->debugw)->log($$concat(var$0, $$str(needWrap())));
		}
		while (true) {
			bool var$4 = $Utils::synchronizedRemaining(this->writeList) > 0;
			bool var$3 = var$4 || hsTriggered();
			if (!(var$3 || needWrap())) {
				break;
			}
			{
				$var($ByteBufferArray, outbufs, $fcast($ByteBufferArray, $nc(this->writeList)->toArray($Utils::EMPTY_BB_ARRAY)));
				$var($SSLFlowDelegate$EngineResult, result, wrapBuffers(outbufs));
				if ($nc(this->debugw)->on()) {
					$nc(this->debugw)->log("wrapBuffer returned %s"_s, $$new($ObjectArray, {$of($nc(result)->result)}));
				}
				$init($SSLEngineResult$Status);
				if ($nc(result)->status() == $SSLEngineResult$Status::CLOSED) {
					if (!this->upstreamCompleted) {
						this->upstreamCompleted = true;
						$nc(this->upstreamSubscription)->cancel();
						this->this$0->setALPN();
					}
					if (result->bytesProduced() <= 0) {
						return;
					}
					if (!completing && !this->completed) {
						completing = (this->completing = true);
						$init($SSLFlowDelegate);
						$nc(this->writeList)->add($SSLFlowDelegate::SENTINEL);
					}
				}
				bool handshaking = false;
				if ($nc(result)->handshaking()) {
					if ($nc(this->debugw)->on()) {
						$nc(this->debugw)->log("handshaking"_s);
					}
					this->this$0->doHandshake(result, 2);
					handshaking = true;
				} else if (this->this$0->trySetALPN()) {
					this->this$0->resumeActivity();
				}
				this->this$0->cleanList(this->writeList);
				sendResultBytes(result);
				if (handshaking) {
					if (!completing && needWrap()) {
						continue;
					} else {
						return;
					}
				}
			}
		}
		if (completing && $Utils::synchronizedRemaining(this->writeList) == 0) {
			if (!this->completed) {
				this->completed = true;
				$nc(this->writeList)->clear();
				$init($Utils);
				outgoing($Utils::EMPTY_BB_LIST, true);
			}
			return;
		}
		bool var$5 = $nc(this->writeList)->isEmpty();
		if (var$5 && needWrap()) {
			$init($SSLFlowDelegate);
			$nc(this->this$0->writer)->addData($SSLFlowDelegate::HS_TRIGGER);
		}
	} catch ($Throwable& ex) {
		$assign(ex, this->this$0->checkForHandshake(ex));
		errorCommon(ex);
		this->this$0->handleError(ex);
	}
}

$SSLFlowDelegate$EngineResult* SSLFlowDelegate$Writer::wrapBuffers($ByteBufferArray* src) {
	$useLocalCurrentObjectStackCache();
	int64_t len = $Utils::remaining(src);
	if ($nc(this->debugw)->on()) {
		$nc(this->debugw)->log($$str({"wrapping "_s, $$str(len), " bytes"_s}));
	}
	$var($ByteBuffer, dst, this->writeBuffer);
	if (dst == nullptr) {
		$assign(dst, ($set(this, writeBuffer, this->this$0->getNetBuffer())));
	}
	if (!SSLFlowDelegate$Writer::$assertionsDisabled && !($nc(dst)->position() == 0)) {
		$throwNew($AssertionError, $of($$str({"buffer position is "_s, $$str(dst->position())})));
	}
	if (!SSLFlowDelegate$Writer::$assertionsDisabled && !$nc(dst)->hasRemaining()) {
		$throwNew($AssertionError, $of($$str({"buffer has no remaining space: capacity="_s, $$str(dst->capacity())})));
	}
	while (true) {
		$var($SSLEngineResult, sslResult, $nc(this->this$0->engine)->wrap(src, dst));
		if ($nc(this->debugw)->on()) {
			$nc(this->debugw)->log($$str({"SSLResult: "_s, sslResult}));
		}
		$init($SSLFlowDelegate$1);
		{
			int32_t netSize = 0;
			$var($ByteBuffer, b, nullptr)
			$var($ByteBuffer, dest, nullptr)
			switch ($nc($SSLFlowDelegate$1::$SwitchMap$javax$net$ssl$SSLEngineResult$Status)->get($nc(($set(this, lastWrappedStatus, $nc(sslResult)->getStatus())))->ordinal())) {
			case 1:
				{
					if ($nc(this->debugw)->on()) {
						$nc(this->debugw)->log("BUFFER_OVERFLOW"_s);
					}
					netSize = (this->this$0->packetBufferSize = $nc($($nc(this->this$0->engine)->getSession()))->getPacketBufferSize());
					$assign(b, ($set(this, writeBuffer, $ByteBuffer::allocate(netSize + $nc(dst)->position()))));
					$nc(dst)->flip();
					$nc(b)->put(dst);
					$assign(dst, b);
					break;
				}
			case 2:
				{
					if ($nc(this->debugw)->on()) {
						$nc(this->debugw)->log("CLOSED"_s);
					}
				}
			case 4:
				{
					if ($nc(dst)->position() == 0) {
						$init($SSLFlowDelegate);
						$assign(dest, $SSLFlowDelegate::NOTHING);
					} else {
						int32_t var$1 = dst->position();
						if (var$1 < dst->capacity() / 2) {
							dst->flip();
							$assign(dest, $Utils::copyAligned(dst));
							dst->clear();
						} else {
							dst->flip();
							$assign(dest, dst);
							$set(this, writeBuffer, nullptr);
						}
					}
					if ($nc(this->debugw)->on()) {
						$nc(this->debugw)->log("OK => produced: %d bytes into %d, not wrapped: %d"_s, $$new($ObjectArray, {
							$($of($Integer::valueOf($nc(dest)->remaining()))),
							$($of($Integer::valueOf($nc(dest)->capacity()))),
							$($of($Long::valueOf($Utils::remaining(src))))
						}));
					}
					return $new($SSLFlowDelegate$EngineResult, sslResult, dest);
				}
			case 3:
				{
					if ($nc(this->debug)->on()) {
						$nc(this->debug)->log("BUFFER_UNDERFLOW"_s);
					}
					return $new($SSLFlowDelegate$EngineResult, sslResult);
				}
			default:
				{
					if ($nc(this->debugw)->on()) {
						$nc(this->debugw)->log("result: %s"_s, $$new($ObjectArray, {$($of(sslResult->getStatus()))}));
					}
					if (!SSLFlowDelegate$Writer::$assertionsDisabled) {
						$throwNew($AssertionError, $of($$str({"result:"_s, $(sslResult->getStatus())})));
					}
				}
			}
		}
	}
}

bool SSLFlowDelegate$Writer::needWrap() {
	$init($SSLEngineResult$HandshakeStatus);
	return $nc(this->this$0->engine)->getHandshakeStatus() == $SSLEngineResult$HandshakeStatus::NEED_WRAP;
}

void SSLFlowDelegate$Writer::sendResultBytes($SSLFlowDelegate$EngineResult* result) {
	$useLocalCurrentObjectStackCache();
	if ($nc(result)->bytesProduced() > 0) {
		if ($nc(this->debugw)->on()) {
			$nc(this->debugw)->log("Sending %d bytes downstream"_s, $$new($ObjectArray, {$($of($Integer::valueOf(result->bytesProduced())))}));
		}
		outgoing(result->destBuffer, false);
	}
}

$String* SSLFlowDelegate$Writer::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$4, $$str({"WRITER: "_s, $($SubscriberWrapper::toString()), ", writeList size: "_s}));
	$var($String, var$3, $$concat(var$4, $($Integer::toString($nc(this->writeList)->size()))));
	$var($String, var$2, $$concat(var$3, ", scheduler: "));
	$var($String, var$1, $$concat(var$2, ($nc(this->scheduler)->isStopped() ? "stopped"_s : "running"_s)));
	$var($String, var$0, $$concat(var$1, ", status: "));
	return $concat(var$0, this->lastWrappedStatus);
}

void clinit$SSLFlowDelegate$Writer($Class* class$) {
	$load($SSLFlowDelegate);
	SSLFlowDelegate$Writer::$assertionsDisabled = !$SSLFlowDelegate::class$->desiredAssertionStatus();
}

SSLFlowDelegate$Writer::SSLFlowDelegate$Writer() {
}

$Class* SSLFlowDelegate$Writer::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SSLFlowDelegate$Writer$$Lambda$dbgString::classInfo$.name)) {
			return SSLFlowDelegate$Writer$$Lambda$dbgString::load$(name, initialize);
		}
	}
	$loadClass(SSLFlowDelegate$Writer, name, initialize, &_SSLFlowDelegate$Writer_ClassInfo_, clinit$SSLFlowDelegate$Writer, allocate$SSLFlowDelegate$Writer);
	return class$;
}

$Class* SSLFlowDelegate$Writer::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk