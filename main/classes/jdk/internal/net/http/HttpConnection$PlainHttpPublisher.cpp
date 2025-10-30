#include <jdk/internal/net/http/HttpConnection$PlainHttpPublisher.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/Buffer.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/List.h>
#include <java/util/concurrent/ConcurrentLinkedDeque.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/function/ToIntFunction.h>
#include <java/util/stream/IntStream.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/net/http/HttpConnection$PlainHttpPublisher$HttpWriteSubscription.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SequentialScheduler$DeferredCompleter.h>
#include <jdk/internal/net/http/common/SequentialScheduler$RestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $ConcurrentLinkedDeque = ::java::util::concurrent::ConcurrentLinkedDeque;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $ToIntFunction = ::java::util::function::ToIntFunction;
using $IntStream = ::java::util::stream::IntStream;
using $Stream = ::java::util::stream::Stream;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpConnection$HttpPublisher = ::jdk::internal::net::http::HttpConnection$HttpPublisher;
using $HttpConnection$PlainHttpPublisher$HttpWriteSubscription = ::jdk::internal::net::http::HttpConnection$PlainHttpPublisher$HttpWriteSubscription;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SequentialScheduler$DeferredCompleter = ::jdk::internal::net::http::common::SequentialScheduler$DeferredCompleter;
using $SequentialScheduler$RestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$RestartableTask;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class HttpConnection$PlainHttpPublisher$$Lambda$flushTask : public $SequentialScheduler$RestartableTask {
	$class(HttpConnection$PlainHttpPublisher$$Lambda$flushTask, $NO_CLASS_INIT, $SequentialScheduler$RestartableTask)
public:
	void init$(HttpConnection$PlainHttpPublisher* inst) {
		$set(this, inst$, inst);
	}
	virtual void run($SequentialScheduler$DeferredCompleter* completer) override {
		$nc(inst$)->flushTask(completer);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpConnection$PlainHttpPublisher$$Lambda$flushTask>());
	}
	HttpConnection$PlainHttpPublisher* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpConnection$PlainHttpPublisher$$Lambda$flushTask::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HttpConnection$PlainHttpPublisher$$Lambda$flushTask, inst$)},
	{}
};
$MethodInfo HttpConnection$PlainHttpPublisher$$Lambda$flushTask::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/HttpConnection$PlainHttpPublisher;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpConnection$PlainHttpPublisher$$Lambda$flushTask::*)(HttpConnection$PlainHttpPublisher*)>(&HttpConnection$PlainHttpPublisher$$Lambda$flushTask::init$))},
	{"run", "(Ljdk/internal/net/http/common/SequentialScheduler$DeferredCompleter;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpConnection$PlainHttpPublisher$$Lambda$flushTask::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpConnection$PlainHttpPublisher$$Lambda$flushTask",
	"java.lang.Object",
	"jdk.internal.net.http.common.SequentialScheduler$RestartableTask",
	fieldInfos,
	methodInfos
};
$Class* HttpConnection$PlainHttpPublisher$$Lambda$flushTask::load$($String* name, bool initialize) {
	$loadClass(HttpConnection$PlainHttpPublisher$$Lambda$flushTask, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpConnection$PlainHttpPublisher$$Lambda$flushTask::class$ = nullptr;

class HttpConnection$PlainHttpPublisher$$Lambda$remaining$1 : public $ToIntFunction {
	$class(HttpConnection$PlainHttpPublisher$$Lambda$remaining$1, $NO_CLASS_INIT, $ToIntFunction)
public:
	void init$() {
	}
	virtual int32_t applyAsInt(Object$* inst$) override {
		 return $sure($Buffer, inst$)->remaining();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpConnection$PlainHttpPublisher$$Lambda$remaining$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpConnection$PlainHttpPublisher$$Lambda$remaining$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpConnection$PlainHttpPublisher$$Lambda$remaining$1::*)()>(&HttpConnection$PlainHttpPublisher$$Lambda$remaining$1::init$))},
	{"applyAsInt", "(Ljava/lang/Object;)I", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpConnection$PlainHttpPublisher$$Lambda$remaining$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpConnection$PlainHttpPublisher$$Lambda$remaining$1",
	"java.lang.Object",
	"java.util.function.ToIntFunction",
	nullptr,
	methodInfos
};
$Class* HttpConnection$PlainHttpPublisher$$Lambda$remaining$1::load$($String* name, bool initialize) {
	$loadClass(HttpConnection$PlainHttpPublisher$$Lambda$remaining$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpConnection$PlainHttpPublisher$$Lambda$remaining$1::class$ = nullptr;

$FieldInfo _HttpConnection$PlainHttpPublisher_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/HttpConnection;", nullptr, $FINAL | $SYNTHETIC, $field(HttpConnection$PlainHttpPublisher, this$0)},
	{"reading", "Ljava/lang/Object;", nullptr, $FINAL, $field(HttpConnection$PlainHttpPublisher, reading)},
	{"queue", "Ljava/util/concurrent/ConcurrentLinkedDeque;", "Ljava/util/concurrent/ConcurrentLinkedDeque<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;", $FINAL, $field(HttpConnection$PlainHttpPublisher, queue)},
	{"priority", "Ljava/util/concurrent/ConcurrentLinkedDeque;", "Ljava/util/concurrent/ConcurrentLinkedDeque<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;", $FINAL, $field(HttpConnection$PlainHttpPublisher, priority)},
	{"subscriber", "Ljava/util/concurrent/Flow$Subscriber;", "Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;", $VOLATILE, $field(HttpConnection$PlainHttpPublisher, subscriber)},
	{"subscription", "Ljdk/internal/net/http/HttpConnection$PlainHttpPublisher$HttpWriteSubscription;", nullptr, $VOLATILE, $field(HttpConnection$PlainHttpPublisher, subscription)},
	{"writeScheduler", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $FINAL, $field(HttpConnection$PlainHttpPublisher, writeScheduler)},
	{}
};

$MethodInfo _HttpConnection$PlainHttpPublisher_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpConnection;)V", nullptr, 0, $method(static_cast<void(HttpConnection$PlainHttpPublisher::*)($HttpConnection*)>(&HttpConnection$PlainHttpPublisher::init$))},
	{"<init>", "(Ljdk/internal/net/http/HttpConnection;Ljava/lang/Object;)V", nullptr, 0, $method(static_cast<void(HttpConnection$PlainHttpPublisher::*)($HttpConnection*,Object$*)>(&HttpConnection$PlainHttpPublisher::init$))},
	{"enqueue", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, nullptr, "java.io.IOException"},
	{"enqueueUnordered", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, nullptr, "java.io.IOException"},
	{"flushTask", "(Ljdk/internal/net/http/common/SequentialScheduler$DeferredCompleter;)V", nullptr, 0, $method(static_cast<void(HttpConnection$PlainHttpPublisher::*)($SequentialScheduler$DeferredCompleter*)>(&HttpConnection$PlainHttpPublisher::flushTask))},
	{"signal", "()V", nullptr, 0, $method(static_cast<void(HttpConnection$PlainHttpPublisher::*)()>(&HttpConnection$PlainHttpPublisher::signal))},
	{"signalEnqueued", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", $PUBLIC},
	{}
};

$InnerClassInfo _HttpConnection$PlainHttpPublisher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.HttpConnection$PlainHttpPublisher", "jdk.internal.net.http.HttpConnection", "PlainHttpPublisher", $FINAL},
	{"jdk.internal.net.http.HttpConnection$HttpPublisher", "jdk.internal.net.http.HttpConnection", "HttpPublisher", $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.HttpConnection$PlainHttpPublisher$HttpWriteSubscription", "jdk.internal.net.http.HttpConnection$PlainHttpPublisher", "HttpWriteSubscription", $FINAL},
	{}
};

$ClassInfo _HttpConnection$PlainHttpPublisher_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.HttpConnection$PlainHttpPublisher",
	"java.lang.Object",
	"jdk.internal.net.http.HttpConnection$HttpPublisher",
	_HttpConnection$PlainHttpPublisher_FieldInfo_,
	_HttpConnection$PlainHttpPublisher_MethodInfo_,
	nullptr,
	nullptr,
	_HttpConnection$PlainHttpPublisher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HttpConnection"
};

$Object* allocate$HttpConnection$PlainHttpPublisher($Class* clazz) {
	return $of($alloc(HttpConnection$PlainHttpPublisher));
}

void HttpConnection$PlainHttpPublisher::init$($HttpConnection* this$0) {
	HttpConnection$PlainHttpPublisher::init$(this$0, $$new($Object));
}

void HttpConnection$PlainHttpPublisher::init$($HttpConnection* this$0, Object$* readingLock) {
	$set(this, this$0, this$0);
	$set(this, queue, $new($ConcurrentLinkedDeque));
	$set(this, priority, $new($ConcurrentLinkedDeque));
	$set(this, writeScheduler, $new($SequentialScheduler, static_cast<$SequentialScheduler$RestartableTask*>($$new(HttpConnection$PlainHttpPublisher$$Lambda$flushTask, this))));
	$set(this, reading, readingLock);
}

void HttpConnection$PlainHttpPublisher::subscribe($Flow$Subscriber* subscriber) {
	$synchronized(this->reading) {
		if (this->subscription == nullptr) {
			$set(this, subscription, $new($HttpConnection$PlainHttpPublisher$HttpWriteSubscription, this));
		}
		$set(this, subscriber, subscriber);
	}
	$nc(subscriber)->onSubscribe(this->subscription);
	signal();
}

void HttpConnection$PlainHttpPublisher::flushTask($SequentialScheduler$DeferredCompleter* completer) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($HttpConnection$PlainHttpPublisher$HttpWriteSubscription, sub, this->subscription);
			if (sub != nullptr) {
				sub->flush();
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(completer)->complete();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void HttpConnection$PlainHttpPublisher::signal() {
	$nc(this->writeScheduler)->runOrSchedule();
}

void HttpConnection$PlainHttpPublisher::enqueue($List* buffers) {
	$useLocalCurrentObjectStackCache();
	$nc(this->queue)->add(buffers);
	int32_t bytes = $nc($($nc($($nc(buffers)->stream()))->mapToInt(static_cast<$ToIntFunction*>($$new(HttpConnection$PlainHttpPublisher$$Lambda$remaining$1)))))->sum();
	$nc(this->this$0->debug)->log("added %d bytes to the write queue"_s, $$new($ObjectArray, {$($of($Integer::valueOf(bytes)))}));
}

void HttpConnection$PlainHttpPublisher::enqueueUnordered($List* buffers) {
	$useLocalCurrentObjectStackCache();
	int32_t bytes = $nc($($nc($($nc(buffers)->stream()))->mapToInt(static_cast<$ToIntFunction*>($$new(HttpConnection$PlainHttpPublisher$$Lambda$remaining$1)))))->sum();
	$nc(this->priority)->add(buffers);
	$nc(this->this$0->debug)->log("added %d bytes in the priority write queue"_s, $$new($ObjectArray, {$($of($Integer::valueOf(bytes)))}));
}

void HttpConnection$PlainHttpPublisher::signalEnqueued() {
	$nc(this->this$0->debug)->log("signalling the publisher of the write queue"_s);
	signal();
}

HttpConnection$PlainHttpPublisher::HttpConnection$PlainHttpPublisher() {
}

$Class* HttpConnection$PlainHttpPublisher::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HttpConnection$PlainHttpPublisher$$Lambda$flushTask::classInfo$.name)) {
			return HttpConnection$PlainHttpPublisher$$Lambda$flushTask::load$(name, initialize);
		}
		if (name->equals(HttpConnection$PlainHttpPublisher$$Lambda$remaining$1::classInfo$.name)) {
			return HttpConnection$PlainHttpPublisher$$Lambda$remaining$1::load$(name, initialize);
		}
	}
	$loadClass(HttpConnection$PlainHttpPublisher, name, initialize, &_HttpConnection$PlainHttpPublisher_ClassInfo_, allocate$HttpConnection$PlainHttpPublisher);
	return class$;
}

$Class* HttpConnection$PlainHttpPublisher::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk