#include <jdk/internal/net/http/SocketTube.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/SocketChannel.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/AsyncEvent.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/SocketTube$BufferSource.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher$InternalReadSubscription.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher$ReadEvent.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher.h>
#include <jdk/internal/net/http/SocketTube$InternalWriteSubscriber$WriteEvent.h>
#include <jdk/internal/net/http/SocketTube$InternalWriteSubscriber.h>
#include <jdk/internal/net/http/SocketTube$SliceBufferSource.h>
#include <jdk/internal/net/http/SocketTube$SocketFlowEvent.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/FlowTube$TubePublisher.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef DEBUG
#undef EMPTY_BB_ARRAY
#undef EMPTY_BYTEBUFFER
#undef EOF
#undef IDS
#undef MAX_BUFFERS
#undef NOTHING

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Flow$Publisher = ::java::util::concurrent::Flow$Publisher;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $Consumer = ::java::util::function::Consumer;
using $Supplier = ::java::util::function::Supplier;
using $AsyncEvent = ::jdk::internal::net::http::AsyncEvent;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $SocketTube$BufferSource = ::jdk::internal::net::http::SocketTube$BufferSource;
using $SocketTube$InternalReadPublisher = ::jdk::internal::net::http::SocketTube$InternalReadPublisher;
using $SocketTube$InternalReadPublisher$InternalReadSubscription = ::jdk::internal::net::http::SocketTube$InternalReadPublisher$InternalReadSubscription;
using $SocketTube$InternalReadPublisher$ReadEvent = ::jdk::internal::net::http::SocketTube$InternalReadPublisher$ReadEvent;
using $SocketTube$InternalWriteSubscriber = ::jdk::internal::net::http::SocketTube$InternalWriteSubscriber;
using $SocketTube$InternalWriteSubscriber$WriteEvent = ::jdk::internal::net::http::SocketTube$InternalWriteSubscriber$WriteEvent;
using $SocketTube$SliceBufferSource = ::jdk::internal::net::http::SocketTube$SliceBufferSource;
using $SocketTube$SocketFlowEvent = ::jdk::internal::net::http::SocketTube$SocketFlowEvent;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $FlowTube$TubePublisher = ::jdk::internal::net::http::common::FlowTube$TubePublisher;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class SocketTube$$Lambda$dbgString : public $Supplier {
	$class(SocketTube$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(SocketTube* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SocketTube$$Lambda$dbgString>());
	}
	SocketTube* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SocketTube$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SocketTube$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo SocketTube$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/SocketTube;)V", nullptr, $PUBLIC, $method(static_cast<void(SocketTube$$Lambda$dbgString::*)(SocketTube*)>(&SocketTube$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SocketTube$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.SocketTube$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* SocketTube$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(SocketTube$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SocketTube$$Lambda$dbgString::class$ = nullptr;

$FieldInfo _SocketTube_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SocketTube, $assertionsDisabled)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(SocketTube, debug)},
	{"IDS", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $STATIC | $FINAL, $staticField(SocketTube, IDS)},
	{"client", "Ljdk/internal/net/http/HttpClientImpl;", nullptr, $PRIVATE | $FINAL, $field(SocketTube, client)},
	{"channel", "Ljava/nio/channels/SocketChannel;", nullptr, $PRIVATE | $FINAL, $field(SocketTube, channel)},
	{"sliceBuffersSource", "Ljdk/internal/net/http/SocketTube$SliceBufferSource;", nullptr, $PRIVATE | $FINAL, $field(SocketTube, sliceBuffersSource)},
	{"lock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(SocketTube, lock)},
	{"errorRef", "Ljava/util/concurrent/atomic/AtomicReference;", "Ljava/util/concurrent/atomic/AtomicReference<Ljava/lang/Throwable;>;", $PRIVATE | $FINAL, $field(SocketTube, errorRef)},
	{"readPublisher", "Ljdk/internal/net/http/SocketTube$InternalReadPublisher;", nullptr, $PRIVATE | $FINAL, $field(SocketTube, readPublisher)},
	{"writeSubscriber", "Ljdk/internal/net/http/SocketTube$InternalWriteSubscriber;", nullptr, $PRIVATE | $FINAL, $field(SocketTube, writeSubscriber)},
	{"id", "J", nullptr, $PRIVATE | $FINAL, $field(SocketTube, id)},
	{"MAX_BUFFERS", "I", nullptr, $STATIC | $FINAL, $constField(SocketTube, MAX_BUFFERS)},
	{"EOF", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/ByteBuffer;>;", $STATIC | $FINAL, $staticField(SocketTube, EOF)},
	{"NOTHING", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/ByteBuffer;>;", $STATIC | $FINAL, $staticField(SocketTube, NOTHING)},
	{}
};

$MethodInfo _SocketTube_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpClientImpl;Ljava/nio/channels/SocketChannel;Ljava/util/function/Supplier;)V", "(Ljdk/internal/net/http/HttpClientImpl;Ljava/nio/channels/SocketChannel;Ljava/util/function/Supplier<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, $method(static_cast<void(SocketTube::*)($HttpClientImpl*,$SocketChannel*,$Supplier*)>(&SocketTube::init$))},
	{"channelDescr", "()Ljava/lang/String;", nullptr, $FINAL, $method(static_cast<$String*(SocketTube::*)()>(&SocketTube::channelDescr))},
	{"connectFlows", "(Ljdk/internal/net/http/common/FlowTube$TubePublisher;Ljdk/internal/net/http/common/FlowTube$TubeSubscriber;)V", nullptr, $PUBLIC},
	{"dbgString", "()Ljava/lang/String;", nullptr, $FINAL, $method(static_cast<$String*(SocketTube::*)()>(&SocketTube::dbgString))},
	{"debugState", "(Ljava/lang/String;)V", nullptr, 0, $method(static_cast<void(SocketTube::*)($String*)>(&SocketTube::debugState))},
	{"isFinished", "()Z", nullptr, $PUBLIC},
	{"listOf", "(Ljava/util/List;Ljava/lang/Object;)Ljava/util/List;", "<T:Ljava/lang/Object;>(Ljava/util/List<TT;>;TT;)Ljava/util/List<TT;>;", $PRIVATE | $STATIC, $method(static_cast<$List*(*)($List*,Object$*)>(&SocketTube::listOf))},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, $method(static_cast<void(SocketTube::*)($List*)>(&SocketTube::onNext))},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{"pauseEvent", "(Ljdk/internal/net/http/SocketTube$SocketFlowEvent;Ljava/util/function/Consumer;)V", "(Ljdk/internal/net/http/SocketTube$SocketFlowEvent;Ljava/util/function/Consumer<Ljava/lang/Throwable;>;)V", $PRIVATE, $method(static_cast<void(SocketTube::*)($SocketTube$SocketFlowEvent*,$Consumer*)>(&SocketTube::pauseEvent))},
	{"readAvailable", "(Ljdk/internal/net/http/SocketTube$BufferSource;)Ljava/util/List;", "(Ljdk/internal/net/http/SocketTube$BufferSource;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(SocketTube::*)($SocketTube$BufferSource*)>(&SocketTube::readAvailable)), "java.io.IOException"},
	{"resumeEvent", "(Ljdk/internal/net/http/SocketTube$SocketFlowEvent;Ljava/util/function/Consumer;)V", "(Ljdk/internal/net/http/SocketTube$SocketFlowEvent;Ljava/util/function/Consumer<Ljava/lang/Throwable;>;)V", $PRIVATE, $method(static_cast<void(SocketTube::*)($SocketTube$SocketFlowEvent*,$Consumer*)>(&SocketTube::resumeEvent))},
	{"signalClosed", "()V", nullptr, 0, $method(static_cast<void(SocketTube::*)()>(&SocketTube::signalClosed))},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeAvailable", "(Ljava/util/List;)J", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)J", $PRIVATE, $method(static_cast<int64_t(SocketTube::*)($List*)>(&SocketTube::writeAvailable)), "java.io.IOException"},
	{}
};

$InnerClassInfo _SocketTube_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.SocketTube$SSLDirectBufferSource", "jdk.internal.net.http.SocketTube", "SSLDirectBufferSource", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.net.http.SocketTube$SliceBufferSource", "jdk.internal.net.http.SocketTube", "SliceBufferSource", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.net.http.SocketTube$BufferSource", "jdk.internal.net.http.SocketTube", "BufferSource", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.SocketTube$InternalReadPublisher", "jdk.internal.net.http.SocketTube", "InternalReadPublisher", $PRIVATE | $FINAL},
	{"jdk.internal.net.http.SocketTube$InternalWriteSubscriber", "jdk.internal.net.http.SocketTube", "InternalWriteSubscriber", $PRIVATE | $FINAL},
	{"jdk.internal.net.http.SocketTube$SocketFlowEvent", "jdk.internal.net.http.SocketTube", "SocketFlowEvent", $PRIVATE | $STATIC | $ABSTRACT},
	{"jdk.internal.net.http.SocketTube$SocketFlowTask", "jdk.internal.net.http.SocketTube", "SocketFlowTask", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _SocketTube_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.SocketTube",
	"java.lang.Object",
	"jdk.internal.net.http.common.FlowTube",
	_SocketTube_FieldInfo_,
	_SocketTube_MethodInfo_,
	nullptr,
	nullptr,
	_SocketTube_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.SocketTube$SSLDirectBufferSource,jdk.internal.net.http.SocketTube$SliceBufferSource,jdk.internal.net.http.SocketTube$BufferSource,jdk.internal.net.http.SocketTube$InternalReadPublisher,jdk.internal.net.http.SocketTube$InternalReadPublisher$ReadEvent,jdk.internal.net.http.SocketTube$InternalReadPublisher$InternalReadSubscription,jdk.internal.net.http.SocketTube$InternalReadPublisher$ReadSubscription,jdk.internal.net.http.SocketTube$InternalWriteSubscriber,jdk.internal.net.http.SocketTube$InternalWriteSubscriber$WriteSubscription,jdk.internal.net.http.SocketTube$InternalWriteSubscriber$WriteEvent,jdk.internal.net.http.SocketTube$SocketFlowEvent,jdk.internal.net.http.SocketTube$SocketFlowTask"
};

$Object* allocate$SocketTube($Class* clazz) {
	return $of($alloc(SocketTube));
}

bool SocketTube::$assertionsDisabled = false;
$AtomicLong* SocketTube::IDS = nullptr;
$List* SocketTube::EOF = nullptr;
$List* SocketTube::NOTHING = nullptr;

void SocketTube::init$($HttpClientImpl* client, $SocketChannel* channel, $Supplier* buffersFactory) {
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(SocketTube$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, lock, $new($Object));
	$set(this, errorRef, $new($AtomicReference));
	this->id = $nc(SocketTube::IDS)->incrementAndGet();
	$set(this, client, client);
	$set(this, channel, channel);
	$set(this, sliceBuffersSource, $new($SocketTube$SliceBufferSource, buffersFactory));
	$set(this, readPublisher, $new($SocketTube$InternalReadPublisher, this));
	$set(this, writeSubscriber, $new($SocketTube$InternalWriteSubscriber, this));
}

bool SocketTube::isFinished() {
	$var($SocketTube$InternalReadPublisher$InternalReadSubscription, subscription, $nc(this->readPublisher)->subscriptionImpl);
	return subscription != nullptr && subscription->completed || subscription == nullptr && $nc(this->errorRef)->get() != nullptr;
}

void SocketTube::subscribe($Flow$Subscriber* s) {
	$Objects::requireNonNull(s);
	if (!SocketTube::$assertionsDisabled && !$instanceOf($FlowTube$TubeSubscriber, s)) {
		$throwNew($AssertionError, $of($$str({"Expected TubeSubscriber, got:"_s, s})));
	}
	$nc(this->readPublisher)->subscribe(s);
}

void SocketTube::onSubscribe($Flow$Subscription* subscription) {
	$nc(this->writeSubscriber)->onSubscribe(subscription);
}

void SocketTube::onNext($List* item) {
	$nc(this->writeSubscriber)->onNext(item);
}

void SocketTube::onError($Throwable* throwable) {
	$nc(this->writeSubscriber)->onError(throwable);
}

void SocketTube::onComplete() {
	$nc(this->writeSubscriber)->onComplete();
}

void SocketTube::signalClosed() {
	$useLocalCurrentObjectStackCache();
	if ($Log::channel()) {
		$Log::logChannel("Connection close signalled: connection closed locally ({0})"_s, $$new($ObjectArray, {$($of(channelDescr()))}));
	}
	$nc($nc(this->readPublisher)->subscriptionImpl)->signalError($$new($IOException, "connection closed locally"_s));
}

void SocketTube::debugState($String* when) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$var($StringBuilder, state, $new($StringBuilder));
		$var($SocketTube$InternalReadPublisher$InternalReadSubscription, sub, $nc(this->readPublisher)->subscriptionImpl);
		$var($SocketTube$InternalReadPublisher$ReadEvent, readEvent, sub == nullptr ? ($SocketTube$InternalReadPublisher$ReadEvent*)nullptr : $nc(sub)->readEvent);
		$var($Demand, rdemand, sub == nullptr ? ($Demand*)nullptr : sub->demand);
		$var($SocketTube$InternalWriteSubscriber$WriteEvent, writeEvent, $nc(this->writeSubscriber)->writeEvent);
		$var($Demand, wdemand, $nc(this->writeSubscriber)->writeDemand);
		int32_t rops = readEvent == nullptr ? 0 : $nc(readEvent)->interestOps();
		int64_t rd = rdemand == nullptr ? (int64_t)0 : $nc(rdemand)->get();
		int32_t wops = writeEvent == nullptr ? 0 : $nc(writeEvent)->interestOps();
		int64_t wd = wdemand == nullptr ? (int64_t)0 : $nc(wdemand)->get();
		state->append(when)->append(" Reading: [ops="_s)->append(rops)->append(", demand="_s)->append(rd)->append(", stopped="_s)->append((sub == nullptr ? false : $nc(sub->readScheduler)->isStopped()))->append("], Writing: [ops="_s)->append(wops)->append(", demand="_s)->append(wd)->append("]"_s);
		$nc(this->debug)->log($(state->toString()));
	}
}

$List* SocketTube::readAvailable($SocketTube$BufferSource* buffersSource) {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, buf, $nc(buffersSource)->getBuffer());
	if (!SocketTube::$assertionsDisabled && !$nc(buf)->hasRemaining()) {
		$throwNew($AssertionError);
	}
	int32_t read = 0;
	int32_t pos = $nc(buf)->position();
	$var($List, list, nullptr);
	while (buf->hasRemaining()) {
		try {
			while ((read = $nc(this->channel)->read(buf)) > 0) {
				if (!buf->hasRemaining()) {
					break;
				}
			}
		} catch ($IOException& x) {
			if (buf->position() == pos && list == nullptr) {
				buffersSource->returnUnused(buf);
				$throw(x);
			} else {
				$nc(this->errorRef)->compareAndSet(nullptr, x);
				read = 0;
			}
		}
		if (buf->position() == pos) {
			buffersSource->returnUnused(buf);
			if (list == nullptr) {
				$assign(list, read == -1 ? SocketTube::EOF : SocketTube::NOTHING);
			}
			break;
		}
		$assign(list, buffersSource->append(list, buf, pos));
		if (read <= 0 || $nc(list)->size() == SocketTube::MAX_BUFFERS) {
			break;
		}
		$assign(buf, buffersSource->getBuffer());
		pos = $nc(buf)->position();
		if (!SocketTube::$assertionsDisabled && !buf->hasRemaining()) {
			$throwNew($AssertionError);
		}
	}
	return list;
}

$List* SocketTube::listOf($List* list, Object$* item) {
	$init(SocketTube);
	$useLocalCurrentObjectStackCache();
	int32_t size = list == nullptr ? 0 : $nc(list)->size();
	{
		$var($List, res, nullptr)
		switch (size) {
		case 0:
			{
				return $List::of(item);
			}
		case 1:
			{
				return $List::of($(list->get(0)), item);
			}
		case 2:
			{
				$var($Object, var$0, list->get(0));
				return $List::of(var$0, $(list->get(1)), item);
			}
		default:
			{
				$assign(res, $instanceOf($ArrayList, list) ? list : static_cast<$List*>($new($ArrayList, static_cast<$Collection*>(list))));
				$nc(res)->add(item);
				return res;
			}
		}
	}
}

int64_t SocketTube::writeAvailable($List* bytes) {
	$useLocalCurrentObjectStackCache();
	$init($Utils);
	$var($ByteBufferArray, srcs, $fcast($ByteBufferArray, $nc(bytes)->toArray($Utils::EMPTY_BB_ARRAY)));
	int64_t remaining = $Utils::remaining(srcs);
	int64_t written = 0;
	while (remaining > written) {
		try {
			int64_t w = $nc(this->channel)->write(srcs);
			if (!SocketTube::$assertionsDisabled && !(w >= 0)) {
				$throwNew($AssertionError, $of($$str({"negative number of bytes written:"_s, $$str(w)})));
			}
			if (w == 0) {
				break;
			}
			written += w;
		} catch ($IOException& x) {
			if (written == 0) {
				$throw(x);
			} else {
				break;
			}
		}
	}
	return written;
}

void SocketTube::resumeEvent($SocketTube$SocketFlowEvent* event, $Consumer* errorSignaler) {
	bool registrationRequired = false;
	$synchronized(this->lock) {
		registrationRequired = !$nc(event)->registered();
		event->resume();
	}
	try {
		if (registrationRequired) {
			$nc(this->client)->registerEvent(event);
		} else {
			$nc(this->client)->eventUpdated(event);
		}
	} catch ($Throwable& t) {
		$nc(errorSignaler)->accept(t);
	}
}

void SocketTube::pauseEvent($SocketTube$SocketFlowEvent* event, $Consumer* errorSignaler) {
	$synchronized(this->lock) {
		$nc(event)->pause();
	}
	try {
		$nc(this->client)->eventUpdated(event);
	} catch ($Throwable& t) {
		$nc(errorSignaler)->accept(t);
	}
}

void SocketTube::connectFlows($FlowTube$TubePublisher* writePublisher, $FlowTube$TubeSubscriber* readSubscriber) {
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("connecting flows"_s);
	}
	this->subscribe(readSubscriber);
	$nc(writePublisher)->subscribe(this);
}

$String* SocketTube::toString() {
	return dbgString();
}

$String* SocketTube::dbgString() {
	return $str({"SocketTube("_s, $$str(this->id), ")"_s});
}

$String* SocketTube::channelDescr() {
	return $String::valueOf($of(this->channel));
}

void SocketTube::onNext(Object$* item) {
	this->onNext($cast($List, item));
}

void clinit$SocketTube($Class* class$) {
	SocketTube::$assertionsDisabled = !SocketTube::class$->desiredAssertionStatus();
	$assignStatic(SocketTube::IDS, $new($AtomicLong));
	$assignStatic(SocketTube::EOF, $List::of());
	$init($Utils);
	$assignStatic(SocketTube::NOTHING, $List::of($of($Utils::EMPTY_BYTEBUFFER)));
}

SocketTube::SocketTube() {
}

$Class* SocketTube::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SocketTube$$Lambda$dbgString::classInfo$.name)) {
			return SocketTube$$Lambda$dbgString::load$(name, initialize);
		}
	}
	$loadClass(SocketTube, name, initialize, &_SocketTube_ClassInfo_, clinit$SocketTube, allocate$SocketTube);
	return class$;
}

$Class* SocketTube::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk