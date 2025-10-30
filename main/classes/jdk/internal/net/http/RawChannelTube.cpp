#include <jdk/internal/net/http/RawChannelTube.h>

#include <java/io/EOFException.h>
#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Math.h>
#include <java/lang/Runnable.h>
#include <java/lang/System$Logger.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/Cleaner$Cleanable.h>
#include <java/lang/ref/Cleaner.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/SelectionKey.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/concurrent/ConcurrentLinkedQueue.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/RawChannelTube$CleanupChecker.h>
#include <jdk/internal/net/http/RawChannelTube$ReadSubscriber.h>
#include <jdk/internal/net/http/RawChannelTube$WritePublisher.h>
#include <jdk/internal/net/http/RawChannelTube$WriteSubscription.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/FlowTube$TubePublisher.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/websocket/RawChannel$RawEvent.h>
#include <jcpp.h>

#undef ASSERTIONSENABLED
#undef DEBUG_WS
#undef EMPTY_BB_LIST
#undef EMPTY_BYTEBUFFER
#undef OP_READ
#undef OP_WRITE

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $EOFException = ::java::io::EOFException;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Runnable = ::java::lang::Runnable;
using $System$Logger = ::java::lang::System$Logger;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Cleaner = ::java::lang::ref::Cleaner;
using $Cleaner$Cleanable = ::java::lang::ref::Cleaner$Cleanable;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $SelectionKey = ::java::nio::channels::SelectionKey;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $ConcurrentLinkedQueue = ::java::util::concurrent::ConcurrentLinkedQueue;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $Supplier = ::java::util::function::Supplier;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $RawChannelTube$CleanupChecker = ::jdk::internal::net::http::RawChannelTube$CleanupChecker;
using $RawChannelTube$ReadSubscriber = ::jdk::internal::net::http::RawChannelTube$ReadSubscriber;
using $RawChannelTube$WritePublisher = ::jdk::internal::net::http::RawChannelTube$WritePublisher;
using $RawChannelTube$WriteSubscription = ::jdk::internal::net::http::RawChannelTube$WriteSubscription;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $FlowTube$TubePublisher = ::jdk::internal::net::http::common::FlowTube$TubePublisher;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $RawChannel = ::jdk::internal::net::http::websocket::RawChannel;
using $RawChannel$RawEvent = ::jdk::internal::net::http::websocket::RawChannel$RawEvent;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class RawChannelTube$$Lambda$toString : public $Supplier {
	$class(RawChannelTube$$Lambda$toString, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RawChannelTube$$Lambda$toString>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo RawChannelTube$$Lambda$toString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(RawChannelTube$$Lambda$toString, inst$)},
	{}
};
$MethodInfo RawChannelTube$$Lambda$toString::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(RawChannelTube$$Lambda$toString::*)($String*)>(&RawChannelTube$$Lambda$toString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo RawChannelTube$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.RawChannelTube$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* RawChannelTube$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(RawChannelTube$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RawChannelTube$$Lambda$toString::class$ = nullptr;

$FieldInfo _RawChannelTube_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(RawChannelTube, $assertionsDisabled)},
	{"connection", "Ljdk/internal/net/http/HttpConnection;", nullptr, $FINAL, $field(RawChannelTube, connection)},
	{"tube", "Ljdk/internal/net/http/common/FlowTube;", nullptr, $FINAL, $field(RawChannelTube, tube)},
	{"writePublisher", "Ljdk/internal/net/http/RawChannelTube$WritePublisher;", nullptr, $FINAL, $field(RawChannelTube, writePublisher)},
	{"readSubscriber", "Ljdk/internal/net/http/RawChannelTube$ReadSubscriber;", nullptr, $FINAL, $field(RawChannelTube, readSubscriber)},
	{"initial", "Ljava/util/function/Supplier;", "Ljava/util/function/Supplier<Ljava/nio/ByteBuffer;>;", $FINAL, $field(RawChannelTube, initial)},
	{"inited", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $FINAL, $field(RawChannelTube, inited)},
	{"outputClosed", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $FINAL, $field(RawChannelTube, outputClosed)},
	{"inputClosed", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $FINAL, $field(RawChannelTube, inputClosed)},
	{"closed", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $FINAL, $field(RawChannelTube, closed)},
	{"dbgTag", "Ljava/lang/String;", nullptr, $FINAL, $field(RawChannelTube, dbgTag)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(RawChannelTube, debug)},
	{"cleaner", "Ljava/lang/ref/Cleaner;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RawChannelTube, cleaner)},
	{}
};

$MethodInfo _RawChannelTube_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpConnection;Ljava/util/function/Supplier;)V", "(Ljdk/internal/net/http/HttpConnection;Ljava/util/function/Supplier<Ljava/nio/ByteBuffer;>;)V", 0, $method(static_cast<void(RawChannelTube::*)($HttpConnection*,$Supplier*)>(&RawChannelTube::init$))},
	{"close", "()V", nullptr, $PUBLIC},
	{"connectFlows", "()V", nullptr, $PRIVATE, $method(static_cast<void(RawChannelTube::*)()>(&RawChannelTube::connectFlows))},
	{"copy", "([Ljava/nio/ByteBuffer;II)Ljava/util/List;", "([Ljava/nio/ByteBuffer;II)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE | $STATIC, $method(static_cast<$List*(*)($ByteBufferArray*,int32_t,int32_t)>(&RawChannelTube::copy))},
	{"initialByteBuffer", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, nullptr, "java.lang.IllegalStateException"},
	{"read", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"registerEvent", "(Ljdk/internal/net/http/websocket/RawChannel$RawEvent;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"shutdownInput", "()V", nullptr, $PUBLIC},
	{"shutdownOutput", "()V", nullptr, $PUBLIC},
	{"write", "([Ljava/nio/ByteBuffer;II)J", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _RawChannelTube_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RawChannelTube$ReadSubscriber", "jdk.internal.net.http.RawChannelTube", "ReadSubscriber", 0},
	{"jdk.internal.net.http.RawChannelTube$WritePublisher", "jdk.internal.net.http.RawChannelTube", "WritePublisher", 0},
	{"jdk.internal.net.http.RawChannelTube$WriteSubscription", "jdk.internal.net.http.RawChannelTube", "WriteSubscription", 0},
	{"jdk.internal.net.http.RawChannelTube$CleanupChecker", "jdk.internal.net.http.RawChannelTube", "CleanupChecker", $STATIC | $FINAL},
	{}
};

$ClassInfo _RawChannelTube_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.RawChannelTube",
	"java.lang.Object",
	"jdk.internal.net.http.websocket.RawChannel",
	_RawChannelTube_FieldInfo_,
	_RawChannelTube_MethodInfo_,
	nullptr,
	nullptr,
	_RawChannelTube_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RawChannelTube$ReadSubscriber,jdk.internal.net.http.RawChannelTube$WritePublisher,jdk.internal.net.http.RawChannelTube$WriteSubscription,jdk.internal.net.http.RawChannelTube$CleanupChecker"
};

$Object* allocate$RawChannelTube($Class* clazz) {
	return $of($alloc(RawChannelTube));
}

bool RawChannelTube::$assertionsDisabled = false;
$Cleaner* RawChannelTube::cleaner = nullptr;

void RawChannelTube::init$($HttpConnection* connection, $Supplier* initial) {
	$useLocalCurrentObjectStackCache();
	$set(this, inited, $new($AtomicBoolean));
	$set(this, outputClosed, $new($AtomicBoolean));
	$set(this, inputClosed, $new($AtomicBoolean));
	$set(this, closed, $new($AtomicBoolean));
	$set(this, connection, connection);
	$set(this, tube, $nc(connection)->getConnectionFlow());
	$set(this, initial, initial);
	$set(this, writePublisher, $new($RawChannelTube$WritePublisher, this));
	$set(this, readSubscriber, $new($RawChannelTube$ReadSubscriber, this));
	$set(this, dbgTag, $str({"[WebSocket] RawChannelTube("_s, this->tube, ")"_s}));
	$init($Utils);
	$set(this, debug, $Utils::getWebSocketLogger(static_cast<$Supplier*>($$new(RawChannelTube$$Lambda$toString, static_cast<$String*>($nc(this->dbgTag)))), $Utils::DEBUG_WS));
	$nc($(connection->client()))->webSocketOpen();
	connectFlows();
	if ($Utils::ASSERTIONSENABLED && $Utils::DEBUG_WS) {
		$nc(RawChannelTube::cleaner)->register$(this, $$new($RawChannelTube$CleanupChecker, this->closed, this->debug));
	}
}

void RawChannelTube::connectFlows() {
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("connectFlows"_s);
	}
	$nc(this->tube)->connectFlows(this->writePublisher, this->readSubscriber);
}

void RawChannelTube::registerEvent($RawChannel$RawEvent* event$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($RawChannel$RawEvent, event, event$renamed);
	int32_t interestOps = $nc(event)->interestOps();
	if (((int32_t)(interestOps & (uint32_t)$SelectionKey::OP_WRITE)) != 0) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("register write event"_s);
		}
		if ($nc(this->outputClosed)->get()) {
			$throwNew($IOException, "closed output"_s);
		}
		$nc($nc(this->writePublisher)->events)->add(event);
		$var($RawChannelTube$WriteSubscription, writeSubscription, $nc(this->writePublisher)->writeSubscription);
		if (writeSubscription != nullptr) {
			while (!$nc(writeSubscription->demand)->isFulfilled()) {
				$assign(event, $cast($RawChannel$RawEvent, $nc($nc(this->writePublisher)->events)->poll()));
				if (event == nullptr) {
					break;
				}
				$nc(event)->handle();
			}
		}
	}
	if (((int32_t)(interestOps & (uint32_t)$SelectionKey::OP_READ)) != 0) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("register read event"_s);
		}
		if ($nc(this->inputClosed)->get()) {
			$throwNew($IOException, "closed input"_s);
		}
		$nc($nc(this->readSubscriber)->events)->add(event);
		$nc(this->readSubscriber)->checkEvents();
		bool var$0 = $nc($nc(this->readSubscriber)->buffers)->isEmpty();
		if (var$0 && !$nc($nc(this->readSubscriber)->events)->isEmpty()) {
			$var($Flow$Subscription, readSubscription, $nc(this->readSubscriber)->readSubscription);
			if (readSubscription == nullptr) {
				$synchronized(this->readSubscriber) {
					$assign(readSubscription, $nc(this->readSubscriber)->readSubscription);
					if (readSubscription == nullptr) {
						$nc(this->readSubscriber)->initialRequest = 1;
						return;
					}
				}
			}
			if (!RawChannelTube::$assertionsDisabled && !(readSubscription != nullptr)) {
				$throwNew($AssertionError);
			}
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("readSubscription: requesting 1"_s);
			}
			$nc(readSubscription)->request(1);
		}
	}
}

$ByteBuffer* RawChannelTube::initialByteBuffer() {
	if ($nc(this->inited)->compareAndSet(false, true)) {
		return $cast($ByteBuffer, $nc(this->initial)->get());
	} else {
		$throwNew($IllegalStateException, "initial buffer already drained"_s);
	}
}

$ByteBuffer* RawChannelTube::read() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("read"_s);
	}
	$var($Flow$Subscription, readSubscription, $nc(this->readSubscriber)->readSubscription);
	if (readSubscription == nullptr) {
		$init($Utils);
		return $Utils::EMPTY_BYTEBUFFER;
	}
	$var($ByteBuffer, buffer, $cast($ByteBuffer, $nc($nc(this->readSubscriber)->buffers)->poll()));
	if (buffer != nullptr) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log($$str({"read: "_s, $$str(buffer->remaining())}));
		}
		return buffer;
	}
	$var($Throwable, error, $cast($Throwable, $nc($nc(this->readSubscriber)->errorRef)->get()));
	if (error != nullptr) {
		$assign(error, $Utils::getIOException(error));
	}
	if ($instanceOf($EOFException, error)) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("read: EOFException"_s);
		}
		shutdownInput();
		return nullptr;
	}
	if (error != nullptr) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log($$str({"read: "_s, error}));
		}
		if ($nc(this->closed)->get()) {
			return nullptr;
		}
		shutdownInput();
		$throw($($Utils::getIOException(error)));
	}
	if ($nc(this->readSubscriber)->completed) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("read: EOF"_s);
		}
		shutdownInput();
		return nullptr;
	}
	if ($nc(this->inputClosed)->get()) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("read: CLOSED"_s);
		}
		$throwNew($IOException, "closed output"_s);
	}
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("read: nothing to read"_s);
	}
	$init($Utils);
	return $Utils::EMPTY_BYTEBUFFER;
}

int64_t RawChannelTube::write($ByteBufferArray* srcs, int32_t offset, int32_t length) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->outputClosed)->get()) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("write: CLOSED"_s);
		}
		$throwNew($IOException, "closed output"_s);
	}
	$var($RawChannelTube$WriteSubscription, writeSubscription, $nc(this->writePublisher)->writeSubscription);
	if (writeSubscription == nullptr) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("write: unsubscribed: 0"_s);
		}
		return 0;
	}
	if ($nc(writeSubscription)->cancelled) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("write: CANCELLED"_s);
		}
		shutdownOutput();
		$throwNew($IOException, "closed output"_s);
	}
	if ($nc($nc(writeSubscription)->demand)->tryDecrement()) {
		$var($List, buffers, copy(srcs, offset, length));
		int64_t res = $Utils::remaining(buffers);
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("write: writing %d"_s, $$new($ObjectArray, {$($of($Long::valueOf(res)))}));
		}
		$nc(writeSubscription->subscriber)->onNext(buffers);
		return res;
	} else {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("write: no demand: 0"_s);
		}
		return 0;
	}
}

void RawChannelTube::shutdownInput() {
	if ($nc(this->inputClosed)->compareAndSet(false, true)) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("shutdownInput"_s);
		}
	}
}

void RawChannelTube::shutdownOutput() {
	if ($nc(this->outputClosed)->compareAndSet(false, true)) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("shutdownOutput"_s);
		}
	}
}

void RawChannelTube::close() {
	if ($nc(this->closed)->compareAndSet(false, true)) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("close"_s);
		}
		$nc($($nc(this->connection)->client()))->webSocketClose();
		$nc(this->connection)->close();
	}
}

$List* RawChannelTube::copy($ByteBufferArray* src, int32_t offset, int32_t len) {
	$init(RawChannelTube);
	$useLocalCurrentObjectStackCache();
	int32_t count = $Math::min(len, $nc(src)->length - offset);
	if (count <= 0) {
		$init($Utils);
		return $Utils::EMPTY_BB_LIST;
	}
	if (count == 1) {
		return $List::of($($of($Utils::copy($nc(src)->get(offset)))));
	}
	if (count == 2) {
		$var($Object, var$0, $of($Utils::copy($nc(src)->get(offset))));
		return $List::of(var$0, $($Utils::copy($nc(src)->get(offset + 1))));
	}
	$var($List, list, $new($ArrayList, count));
	for (int32_t i = 0; i < count; ++i) {
		list->add($($Utils::copy($nc(src)->get(offset + i))));
	}
	return list;
}

void clinit$RawChannelTube($Class* class$) {
	RawChannelTube::$assertionsDisabled = !RawChannelTube::class$->desiredAssertionStatus();
	$init($Utils);
	$assignStatic(RawChannelTube::cleaner, $Utils::ASSERTIONSENABLED && $Utils::DEBUG_WS ? $Cleaner::create() : ($Cleaner*)nullptr);
}

RawChannelTube::RawChannelTube() {
}

$Class* RawChannelTube::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RawChannelTube$$Lambda$toString::classInfo$.name)) {
			return RawChannelTube$$Lambda$toString::load$(name, initialize);
		}
	}
	$loadClass(RawChannelTube, name, initialize, &_RawChannelTube_ClassInfo_, clinit$RawChannelTube, allocate$RawChannelTube);
	return class$;
}

$Class* RawChannelTube::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk