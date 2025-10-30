#include <jdk/internal/net/http/common/SSLFlowDelegate.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/InternalError.h>
#include <java/lang/Iterable.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/ConcurrentLinkedQueue.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/atomic/AtomicInteger.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/IntBinaryOperator.h>
#include <java/util/function/Supplier.h>
#include <javax/net/ssl/SSLEngine.h>
#include <javax/net/ssl/SSLEngineResult$HandshakeStatus.h>
#include <javax/net/ssl/SSLEngineResult.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <javax/net/ssl/SSLSession.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$1.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$EngineResult.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Monitor.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Monitorable.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Reader.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Writer.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/SubscriberWrapper$SchedulingAction.h>
#include <jdk/internal/net/http/common/SubscriberWrapper.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef CONTINUE
#undef DEBUG
#undef DOING_TASKS
#undef EMPTY_BYTEBUFFER
#undef FINISHED
#undef FINISH_OR_DO_TASKS
#undef HANDSHAKING
#undef HS_TRIGGER
#undef NEED_TASK
#undef NEED_WRAP
#undef NOTHING
#undef NOT_HANDSHAKING
#undef READER
#undef REQUESTING_TASKS
#undef REQUEST_OR_DO_TASKS
#undef SENTINEL
#undef TASK_BITS
#undef WRITER

using $CompletableFutureArray = $Array<::java::util::concurrent::CompletableFuture>;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Iterable = ::java::lang::Iterable;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $ConcurrentLinkedQueue = ::java::util::concurrent::ConcurrentLinkedQueue;
using $Executor = ::java::util::concurrent::Executor;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $AtomicInteger = ::java::util::concurrent::atomic::AtomicInteger;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $IntBinaryOperator = ::java::util::function::IntBinaryOperator;
using $Supplier = ::java::util::function::Supplier;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $SSLEngineResult = ::javax::net::ssl::SSLEngineResult;
using $SSLEngineResult$HandshakeStatus = ::javax::net::ssl::SSLEngineResult$HandshakeStatus;
using $SSLException = ::javax::net::ssl::SSLException;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $SSLFlowDelegate$1 = ::jdk::internal::net::http::common::SSLFlowDelegate$1;
using $SSLFlowDelegate$EngineResult = ::jdk::internal::net::http::common::SSLFlowDelegate$EngineResult;
using $SSLFlowDelegate$Monitor = ::jdk::internal::net::http::common::SSLFlowDelegate$Monitor;
using $SSLFlowDelegate$Monitorable = ::jdk::internal::net::http::common::SSLFlowDelegate$Monitorable;
using $SSLFlowDelegate$Reader = ::jdk::internal::net::http::common::SSLFlowDelegate$Reader;
using $SSLFlowDelegate$Writer = ::jdk::internal::net::http::common::SSLFlowDelegate$Writer;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SubscriberWrapper = ::jdk::internal::net::http::common::SubscriberWrapper;
using $SubscriberWrapper$SchedulingAction = ::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class SSLFlowDelegate$$Lambda$dbgString : public $Supplier {
	$class(SSLFlowDelegate$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(SSLFlowDelegate* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SSLFlowDelegate$$Lambda$dbgString>());
	}
	SSLFlowDelegate* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SSLFlowDelegate$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SSLFlowDelegate$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo SSLFlowDelegate$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/common/SSLFlowDelegate;)V", nullptr, $PUBLIC, $method(static_cast<void(SSLFlowDelegate$$Lambda$dbgString::*)(SSLFlowDelegate*)>(&SSLFlowDelegate$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SSLFlowDelegate$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.SSLFlowDelegate$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* SSLFlowDelegate$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SSLFlowDelegate$$Lambda$dbgString::class$ = nullptr;

class SSLFlowDelegate$$Lambda$monitor$1 : public $SSLFlowDelegate$Monitorable {
	$class(SSLFlowDelegate$$Lambda$monitor$1, $NO_CLASS_INIT, $SSLFlowDelegate$Monitorable)
public:
	void init$(SSLFlowDelegate* inst) {
		$set(this, inst$, inst);
	}
	virtual $String* getInfo() override {
		 return $nc(inst$)->monitor();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SSLFlowDelegate$$Lambda$monitor$1>());
	}
	SSLFlowDelegate* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SSLFlowDelegate$$Lambda$monitor$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SSLFlowDelegate$$Lambda$monitor$1, inst$)},
	{}
};
$MethodInfo SSLFlowDelegate$$Lambda$monitor$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/common/SSLFlowDelegate;)V", nullptr, $PUBLIC, $method(static_cast<void(SSLFlowDelegate$$Lambda$monitor$1::*)(SSLFlowDelegate*)>(&SSLFlowDelegate$$Lambda$monitor$1::init$))},
	{"getInfo", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SSLFlowDelegate$$Lambda$monitor$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.SSLFlowDelegate$$Lambda$monitor$1",
	"java.lang.Object",
	"jdk.internal.net.http.common.SSLFlowDelegate$Monitorable",
	fieldInfos,
	methodInfos
};
$Class* SSLFlowDelegate$$Lambda$monitor$1::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$$Lambda$monitor$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SSLFlowDelegate$$Lambda$monitor$1::class$ = nullptr;

class SSLFlowDelegate$$Lambda$lambda$static$0$2 : public $IntBinaryOperator {
	$class(SSLFlowDelegate$$Lambda$lambda$static$0$2, $NO_CLASS_INIT, $IntBinaryOperator)
public:
	void init$() {
	}
	virtual int32_t applyAsInt(int32_t current, int32_t ignored) override {
		 return SSLFlowDelegate::lambda$static$0(current, ignored);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SSLFlowDelegate$$Lambda$lambda$static$0$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SSLFlowDelegate$$Lambda$lambda$static$0$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SSLFlowDelegate$$Lambda$lambda$static$0$2::*)()>(&SSLFlowDelegate$$Lambda$lambda$static$0$2::init$))},
	{"applyAsInt", "(II)I", nullptr, $PUBLIC},
	{}
};
$ClassInfo SSLFlowDelegate$$Lambda$lambda$static$0$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.SSLFlowDelegate$$Lambda$lambda$static$0$2",
	"java.lang.Object",
	"java.util.function.IntBinaryOperator",
	nullptr,
	methodInfos
};
$Class* SSLFlowDelegate$$Lambda$lambda$static$0$2::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$$Lambda$lambda$static$0$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SSLFlowDelegate$$Lambda$lambda$static$0$2::class$ = nullptr;

class SSLFlowDelegate$$Lambda$lambda$static$1$3 : public $IntBinaryOperator {
	$class(SSLFlowDelegate$$Lambda$lambda$static$1$3, $NO_CLASS_INIT, $IntBinaryOperator)
public:
	void init$() {
	}
	virtual int32_t applyAsInt(int32_t current, int32_t ignored) override {
		 return SSLFlowDelegate::lambda$static$1(current, ignored);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SSLFlowDelegate$$Lambda$lambda$static$1$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SSLFlowDelegate$$Lambda$lambda$static$1$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SSLFlowDelegate$$Lambda$lambda$static$1$3::*)()>(&SSLFlowDelegate$$Lambda$lambda$static$1$3::init$))},
	{"applyAsInt", "(II)I", nullptr, $PUBLIC},
	{}
};
$ClassInfo SSLFlowDelegate$$Lambda$lambda$static$1$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.SSLFlowDelegate$$Lambda$lambda$static$1$3",
	"java.lang.Object",
	"java.util.function.IntBinaryOperator",
	nullptr,
	methodInfos
};
$Class* SSLFlowDelegate$$Lambda$lambda$static$1$3::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$$Lambda$lambda$static$1$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SSLFlowDelegate$$Lambda$lambda$static$1$3::class$ = nullptr;

class SSLFlowDelegate$$Lambda$stopOnError$4 : public $Function {
	$class(SSLFlowDelegate$$Lambda$stopOnError$4, $NO_CLASS_INIT, $Function)
public:
	void init$(SSLFlowDelegate* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* error) override {
		 return $of($nc(inst$)->stopOnError($cast($Throwable, error)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SSLFlowDelegate$$Lambda$stopOnError$4>());
	}
	SSLFlowDelegate* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SSLFlowDelegate$$Lambda$stopOnError$4::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SSLFlowDelegate$$Lambda$stopOnError$4, inst$)},
	{}
};
$MethodInfo SSLFlowDelegate$$Lambda$stopOnError$4::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/common/SSLFlowDelegate;)V", nullptr, $PUBLIC, $method(static_cast<void(SSLFlowDelegate$$Lambda$stopOnError$4::*)(SSLFlowDelegate*)>(&SSLFlowDelegate$$Lambda$stopOnError$4::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SSLFlowDelegate$$Lambda$stopOnError$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.SSLFlowDelegate$$Lambda$stopOnError$4",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* SSLFlowDelegate$$Lambda$stopOnError$4::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$$Lambda$stopOnError$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SSLFlowDelegate$$Lambda$stopOnError$4::class$ = nullptr;

class SSLFlowDelegate$$Lambda$normalStop$5 : public $Runnable {
	$class(SSLFlowDelegate$$Lambda$normalStop$5, $NO_CLASS_INIT, $Runnable)
public:
	void init$(SSLFlowDelegate* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->normalStop();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SSLFlowDelegate$$Lambda$normalStop$5>());
	}
	SSLFlowDelegate* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SSLFlowDelegate$$Lambda$normalStop$5::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SSLFlowDelegate$$Lambda$normalStop$5, inst$)},
	{}
};
$MethodInfo SSLFlowDelegate$$Lambda$normalStop$5::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/common/SSLFlowDelegate;)V", nullptr, $PUBLIC, $method(static_cast<void(SSLFlowDelegate$$Lambda$normalStop$5::*)(SSLFlowDelegate*)>(&SSLFlowDelegate$$Lambda$normalStop$5::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo SSLFlowDelegate$$Lambda$normalStop$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.SSLFlowDelegate$$Lambda$normalStop$5",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* SSLFlowDelegate$$Lambda$normalStop$5::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$$Lambda$normalStop$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SSLFlowDelegate$$Lambda$normalStop$5::class$ = nullptr;

class SSLFlowDelegate$$Lambda$lambda$doHandshake$2$6 : public $IntBinaryOperator {
	$class(SSLFlowDelegate$$Lambda$lambda$doHandshake$2$6, $NO_CLASS_INIT, $IntBinaryOperator)
public:
	void init$() {
	}
	virtual int32_t applyAsInt(int32_t current, int32_t unused) override {
		 return SSLFlowDelegate::lambda$doHandshake$2(current, unused);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SSLFlowDelegate$$Lambda$lambda$doHandshake$2$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SSLFlowDelegate$$Lambda$lambda$doHandshake$2$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SSLFlowDelegate$$Lambda$lambda$doHandshake$2$6::*)()>(&SSLFlowDelegate$$Lambda$lambda$doHandshake$2$6::init$))},
	{"applyAsInt", "(II)I", nullptr, $PUBLIC},
	{}
};
$ClassInfo SSLFlowDelegate$$Lambda$lambda$doHandshake$2$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.SSLFlowDelegate$$Lambda$lambda$doHandshake$2$6",
	"java.lang.Object",
	"java.util.function.IntBinaryOperator",
	nullptr,
	methodInfos
};
$Class* SSLFlowDelegate$$Lambda$lambda$doHandshake$2$6::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$$Lambda$lambda$doHandshake$2$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SSLFlowDelegate$$Lambda$lambda$doHandshake$2$6::class$ = nullptr;

class SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7 : public $Runnable {
	$class(SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7, $NO_CLASS_INIT, $Runnable)
public:
	void init$(SSLFlowDelegate* inst, $List* tasks) {
		$set(this, inst$, inst);
		$set(this, tasks, tasks);
	}
	virtual void run() override {
		$nc(inst$)->lambda$executeTasks$3(tasks);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7>());
	}
	SSLFlowDelegate* inst$ = nullptr;
	$List* tasks = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7, inst$)},
	{"tasks", "Ljava/util/List;", nullptr, $PUBLIC, $field(SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7, tasks)},
	{}
};
$MethodInfo SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/common/SSLFlowDelegate;Ljava/util/List;)V", nullptr, $PUBLIC, $method(static_cast<void(SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7::*)(SSLFlowDelegate*,$List*)>(&SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7::class$ = nullptr;

class SSLFlowDelegate$$Lambda$run$8 : public $Consumer {
	$class(SSLFlowDelegate$$Lambda$run$8, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$) override {
		$sure($Runnable, inst$)->run();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SSLFlowDelegate$$Lambda$run$8>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SSLFlowDelegate$$Lambda$run$8::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SSLFlowDelegate$$Lambda$run$8::*)()>(&SSLFlowDelegate$$Lambda$run$8::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo SSLFlowDelegate$$Lambda$run$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.SSLFlowDelegate$$Lambda$run$8",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* SSLFlowDelegate$$Lambda$run$8::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$$Lambda$run$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SSLFlowDelegate$$Lambda$run$8::class$ = nullptr;

$FieldInfo _SSLFlowDelegate_FieldInfo_[] = {
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(SSLFlowDelegate, debug)},
	{"SENTINEL", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLFlowDelegate, SENTINEL)},
	{"HS_TRIGGER", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLFlowDelegate, HS_TRIGGER)},
	{"NOTHING", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLFlowDelegate, NOTHING)},
	{"monProp", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLFlowDelegate, monProp)},
	{"isMonitored", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLFlowDelegate, isMonitored)},
	{"exec", "Ljava/util/concurrent/Executor;", nullptr, $FINAL, $field(SSLFlowDelegate, exec)},
	{"reader", "Ljdk/internal/net/http/common/SSLFlowDelegate$Reader;", nullptr, $FINAL, $field(SSLFlowDelegate, reader)},
	{"writer", "Ljdk/internal/net/http/common/SSLFlowDelegate$Writer;", nullptr, $FINAL, $field(SSLFlowDelegate, writer)},
	{"engine", "Ljavax/net/ssl/SSLEngine;", nullptr, $FINAL, $field(SSLFlowDelegate, engine)},
	{"tubeName", "Ljava/lang/String;", nullptr, $FINAL, $field(SSLFlowDelegate, tubeName)},
	{"alpnCF", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljava/lang/String;>;", $FINAL, $field(SSLFlowDelegate, alpnCF)},
	{"monitor", "Ljdk/internal/net/http/common/SSLFlowDelegate$Monitorable;", nullptr, $FINAL, $field(SSLFlowDelegate, monitor$)},
	{"close_notify_received", "Z", nullptr, $VOLATILE, $field(SSLFlowDelegate, close_notify_received)},
	{"readerCF", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $FINAL, $field(SSLFlowDelegate, readerCF)},
	{"writerCF", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $FINAL, $field(SSLFlowDelegate, writerCF)},
	{"stopCF", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $FINAL, $field(SSLFlowDelegate, stopCF)},
	{"recycler", "Ljava/util/function/Consumer;", "Ljava/util/function/Consumer<Ljava/nio/ByteBuffer;>;", $FINAL, $field(SSLFlowDelegate, recycler)},
	{"scount", "Ljava/util/concurrent/atomic/AtomicInteger;", nullptr, $STATIC, $staticField(SSLFlowDelegate, scount)},
	{"id", "I", nullptr, $FINAL, $field(SSLFlowDelegate, id)},
	{"stopped", "Z", nullptr, 0, $field(SSLFlowDelegate, stopped)},
	{"NOT_HANDSHAKING", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SSLFlowDelegate, NOT_HANDSHAKING)},
	{"HANDSHAKING", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SSLFlowDelegate, HANDSHAKING)},
	{"DOING_TASKS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SSLFlowDelegate, DOING_TASKS)},
	{"REQUESTING_TASKS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SSLFlowDelegate, REQUESTING_TASKS)},
	{"TASK_BITS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SSLFlowDelegate, TASK_BITS)},
	{"READER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SSLFlowDelegate, READER)},
	{"WRITER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SSLFlowDelegate, WRITER)},
	{"handshakeState", "Ljava/util/concurrent/atomic/AtomicInteger;", nullptr, $FINAL, $field(SSLFlowDelegate, handshakeState)},
	{"stateList", "Ljava/util/concurrent/ConcurrentLinkedQueue;", "Ljava/util/concurrent/ConcurrentLinkedQueue<Ljava/lang/String;>;", $FINAL, $field(SSLFlowDelegate, stateList)},
	{"REQUEST_OR_DO_TASKS", "Ljava/util/function/IntBinaryOperator;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLFlowDelegate, REQUEST_OR_DO_TASKS)},
	{"FINISH_OR_DO_TASKS", "Ljava/util/function/IntBinaryOperator;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SSLFlowDelegate, FINISH_OR_DO_TASKS)},
	{"packetBufferSize", "I", nullptr, $VOLATILE, $field(SSLFlowDelegate, packetBufferSize)},
	{"applicationBufferSize", "I", nullptr, $VOLATILE, $field(SSLFlowDelegate, applicationBufferSize)},
	{"adaptiveAppBufferSize", "I", nullptr, $VOLATILE, $field(SSLFlowDelegate, adaptiveAppBufferSize)},
	{}
};

$MethodInfo _SSLFlowDelegate_MethodInfo_[] = {
	{"<init>", "(Ljavax/net/ssl/SSLEngine;Ljava/util/concurrent/Executor;Ljava/util/concurrent/Flow$Subscriber;Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljavax/net/ssl/SSLEngine;Ljava/util/concurrent/Executor;Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", $PUBLIC, $method(static_cast<void(SSLFlowDelegate::*)($SSLEngine*,$Executor*,$Flow$Subscriber*,$Flow$Subscriber*)>(&SSLFlowDelegate::init$))},
	{"<init>", "(Ljavax/net/ssl/SSLEngine;Ljava/util/concurrent/Executor;Ljava/util/function/Consumer;Ljava/util/concurrent/Flow$Subscriber;Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljavax/net/ssl/SSLEngine;Ljava/util/concurrent/Executor;Ljava/util/function/Consumer<Ljava/nio/ByteBuffer;>;Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", $PUBLIC, $method(static_cast<void(SSLFlowDelegate::*)($SSLEngine*,$Executor*,$Consumer*,$Flow$Subscriber*,$Flow$Subscriber*)>(&SSLFlowDelegate::init$))},
	{"alpn", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/String;>;", $PUBLIC},
	{"checkForHandshake", "(Ljava/lang/Throwable;)Ljava/lang/Throwable;", nullptr, $PROTECTED},
	{"cleanList", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PRIVATE, $method(static_cast<void(SSLFlowDelegate::*)($List*)>(&SSLFlowDelegate::cleanList))},
	{"closeNotifyReceived", "()Z", nullptr, $PUBLIC},
	{"connect", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", 0},
	{"dbgString", "()Ljava/lang/String;", nullptr, $FINAL, $method(static_cast<$String*(SSLFlowDelegate::*)()>(&SSLFlowDelegate::dbgString))},
	{"doClosure", "(Ljdk/internal/net/http/common/SSLFlowDelegate$EngineResult;)Ljdk/internal/net/http/common/SSLFlowDelegate$EngineResult;", nullptr, 0, nullptr, "java.io.IOException"},
	{"doHandshake", "(Ljdk/internal/net/http/common/SSLFlowDelegate$EngineResult;I)Z", nullptr, $PRIVATE, $method(static_cast<bool(SSLFlowDelegate::*)($SSLFlowDelegate$EngineResult*,int32_t)>(&SSLFlowDelegate::doHandshake))},
	{"enterReadScheduling", "()Ljdk/internal/net/http/common/SubscriberWrapper$SchedulingAction;", nullptr, $PROTECTED},
	{"executeTasks", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/lang/Runnable;>;)V", $PRIVATE, $method(static_cast<void(SSLFlowDelegate::*)($List*)>(&SSLFlowDelegate::executeTasks))},
	{"getAppBuffer", "()Ljava/nio/ByteBuffer;", nullptr, $FINAL, $method(static_cast<$ByteBuffer*(SSLFlowDelegate::*)()>(&SSLFlowDelegate::getAppBuffer))},
	{"getNetBuffer", "()Ljava/nio/ByteBuffer;", nullptr, $FINAL, $method(static_cast<$ByteBuffer*(SSLFlowDelegate::*)()>(&SSLFlowDelegate::getNetBuffer))},
	{"handleError", "(Ljava/lang/Throwable;)V", nullptr, $PRIVATE, $method(static_cast<void(SSLFlowDelegate::*)($Throwable*)>(&SSLFlowDelegate::handleError))},
	{"lambda$doHandshake$2", "(II)I", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<int32_t(*)(int32_t,int32_t)>(&SSLFlowDelegate::lambda$doHandshake$2))},
	{"lambda$executeTasks$3", "(Ljava/util/List;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(SSLFlowDelegate::*)($List*)>(&SSLFlowDelegate::lambda$executeTasks$3))},
	{"lambda$static$0", "(II)I", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<int32_t(*)(int32_t,int32_t)>(&SSLFlowDelegate::lambda$static$0))},
	{"lambda$static$1", "(II)I", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<int32_t(*)(int32_t,int32_t)>(&SSLFlowDelegate::lambda$static$1))},
	{"monitor", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"normalStop", "()V", nullptr, $PRIVATE | $SYNCHRONIZED, $method(static_cast<void(SSLFlowDelegate::*)()>(&SSLFlowDelegate::normalStop))},
	{"obtainTasks", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/Runnable;>;", $PRIVATE, $method(static_cast<$List*(SSLFlowDelegate::*)()>(&SSLFlowDelegate::obtainTasks))},
	{"resetReaderDemand", "()V", nullptr, $PUBLIC},
	{"resumeActivity", "()V", nullptr, $PRIVATE, $method(static_cast<void(SSLFlowDelegate::*)()>(&SSLFlowDelegate::resumeActivity))},
	{"resumeReader", "()Z", nullptr, $PUBLIC},
	{"setALPN", "()V", nullptr, $PRIVATE, $method(static_cast<void(SSLFlowDelegate::*)()>(&SSLFlowDelegate::setALPN))},
	{"states", "(Ljava/util/concurrent/atomic/AtomicInteger;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($AtomicInteger*)>(&SSLFlowDelegate::states))},
	{"stopOnError", "(Ljava/lang/Throwable;)Ljava/lang/Void;", nullptr, $PRIVATE, $method(static_cast<$Void*(SSLFlowDelegate::*)($Throwable*)>(&SSLFlowDelegate::stopOnError))},
	{"trySetALPN", "()Z", nullptr, 0},
	{"upstreamReader", "()Ljava/util/concurrent/Flow$Subscriber;", "()Ljava/util/concurrent/Flow$Subscriber<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;", $PUBLIC},
	{"upstreamWriter", "()Ljava/util/concurrent/Flow$Subscriber;", "()Ljava/util/concurrent/Flow$Subscriber<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;", $PUBLIC},
	{}
};

$InnerClassInfo _SSLFlowDelegate_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SSLFlowDelegate$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"jdk.internal.net.http.common.SSLFlowDelegate$EngineResult", "jdk.internal.net.http.common.SSLFlowDelegate", "EngineResult", $STATIC},
	{"jdk.internal.net.http.common.SSLFlowDelegate$Writer", "jdk.internal.net.http.common.SSLFlowDelegate", "Writer", 0},
	{"jdk.internal.net.http.common.SSLFlowDelegate$Monitor", "jdk.internal.net.http.common.SSLFlowDelegate", "Monitor", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.common.SSLFlowDelegate$Monitorable", "jdk.internal.net.http.common.SSLFlowDelegate", "Monitorable", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.common.SSLFlowDelegate$Reader", "jdk.internal.net.http.common.SSLFlowDelegate", "Reader", $FINAL},
	{}
};

$ClassInfo _SSLFlowDelegate_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.common.SSLFlowDelegate",
	"java.lang.Object",
	nullptr,
	_SSLFlowDelegate_FieldInfo_,
	_SSLFlowDelegate_MethodInfo_,
	nullptr,
	nullptr,
	_SSLFlowDelegate_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SSLFlowDelegate$1,jdk.internal.net.http.common.SSLFlowDelegate$EngineResult,jdk.internal.net.http.common.SSLFlowDelegate$Writer,jdk.internal.net.http.common.SSLFlowDelegate$Writer$WriterDownstreamPusher,jdk.internal.net.http.common.SSLFlowDelegate$Monitor,jdk.internal.net.http.common.SSLFlowDelegate$Monitor$FinalMonitorable,jdk.internal.net.http.common.SSLFlowDelegate$Monitorable,jdk.internal.net.http.common.SSLFlowDelegate$Reader,jdk.internal.net.http.common.SSLFlowDelegate$Reader$ReaderDownstreamPusher"
};

$Object* allocate$SSLFlowDelegate($Class* clazz) {
	return $of($alloc(SSLFlowDelegate));
}

$ByteBuffer* SSLFlowDelegate::SENTINEL = nullptr;
$ByteBuffer* SSLFlowDelegate::HS_TRIGGER = nullptr;
$ByteBuffer* SSLFlowDelegate::NOTHING = nullptr;
$String* SSLFlowDelegate::monProp = nullptr;
bool SSLFlowDelegate::isMonitored = false;
$AtomicInteger* SSLFlowDelegate::scount = nullptr;
$IntBinaryOperator* SSLFlowDelegate::REQUEST_OR_DO_TASKS = nullptr;
$IntBinaryOperator* SSLFlowDelegate::FINISH_OR_DO_TASKS = nullptr;

void SSLFlowDelegate::init$($SSLEngine* engine, $Executor* exec, $Flow$Subscriber* downReader, $Flow$Subscriber* downWriter) {
	SSLFlowDelegate::init$(engine, exec, nullptr, downReader, downWriter);
}

void SSLFlowDelegate::init$($SSLEngine* engine, $Executor* exec, $Consumer* recycler, $Flow$Subscriber* downReader, $Flow$Subscriber* downWriter) {
	$useLocalCurrentObjectStackCache();
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(SSLFlowDelegate$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, monitor$, SSLFlowDelegate::isMonitored ? static_cast<$SSLFlowDelegate$Monitorable*>($new(SSLFlowDelegate$$Lambda$monitor$1, this)) : ($SSLFlowDelegate$Monitorable*)nullptr);
	$set(this, stateList, $nc(this->debug)->on() ? $new($ConcurrentLinkedQueue) : ($ConcurrentLinkedQueue*)nullptr);
	this->id = $nc(SSLFlowDelegate::scount)->getAndIncrement();
	$set(this, tubeName, $String::valueOf($of(downWriter)));
	$set(this, recycler, recycler);
	$set(this, reader, $new($SSLFlowDelegate$Reader, this));
	$set(this, writer, $new($SSLFlowDelegate$Writer, this));
	$set(this, engine, engine);
	$set(this, exec, exec);
	$set(this, handshakeState, $new($AtomicInteger, SSLFlowDelegate::NOT_HANDSHAKING));
	$set(this, readerCF, $nc(this->reader)->completion());
	$set(this, writerCF, $nc(this->reader)->completion());
	$nc(this->readerCF)->exceptionally(static_cast<$Function*>($$new(SSLFlowDelegate$$Lambda$stopOnError$4, this)));
	$nc(this->writerCF)->exceptionally(static_cast<$Function*>($$new(SSLFlowDelegate$$Lambda$stopOnError$4, this)));
	$set(this, stopCF, $cast($CompletableFuture, $nc($($CompletableFuture::allOf($$new($CompletableFutureArray, {
		$($nc(this->reader)->completion()),
		$($nc(this->writer)->completion())
	}))))->thenRun(static_cast<$Runnable*>($$new(SSLFlowDelegate$$Lambda$normalStop$5, this)))));
	$set(this, alpnCF, $new($MinimalFuture));
	connect(downReader, downWriter);
	if (SSLFlowDelegate::isMonitored) {
		$SSLFlowDelegate$Monitor::add(this->monitor$);
	}
}

bool SSLFlowDelegate::closeNotifyReceived() {
	return this->close_notify_received;
}

void SSLFlowDelegate::connect($Flow$Subscriber* downReader, $Flow$Subscriber* downWriter) {
	$nc(this->reader)->subscribe(downReader);
	$nc(this->writer)->subscribe(downWriter);
}

$CompletableFuture* SSLFlowDelegate::alpn() {
	return this->alpnCF;
}

void SSLFlowDelegate::setALPN() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->alpnCF)->isDone()) {
		return;
	}
	$var($String, alpn, $nc(this->engine)->getApplicationProtocol());
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("setALPN = %s"_s, $$new($ObjectArray, {$of(alpn)}));
	}
	$nc(this->alpnCF)->complete(alpn);
}

$String* SSLFlowDelegate::monitor() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("SSL: id "_s)->append(this->id);
	sb->append(" "_s)->append($(dbgString()));
	sb->append($$str({" HS state: "_s, $(states(this->handshakeState))}));
	sb->append($$str({" Engine state: "_s, $($nc($($nc(this->engine)->getHandshakeStatus()))->toString())}));
	if (this->stateList != nullptr) {
		sb->append(" LL : "_s);
		{
			$var($Iterator, i$, $nc(this->stateList)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, s, $cast($String, i$->next()));
				{
					sb->append(s)->append(" "_s);
				}
			}
		}
	}
	sb->append("\r\n"_s);
	sb->append("Reader:: "_s)->append($($nc(this->reader)->toString()));
	sb->append("\r\n"_s);
	sb->append("Writer:: "_s)->append($($nc(this->writer)->toString()));
	sb->append("\r\n==================================="_s);
	return sb->toString();
}

$SubscriberWrapper$SchedulingAction* SSLFlowDelegate::enterReadScheduling() {
	$init($SubscriberWrapper$SchedulingAction);
	return $SubscriberWrapper$SchedulingAction::CONTINUE;
}

$Throwable* SSLFlowDelegate::checkForHandshake($Throwable* t) {
	return t;
}

void SSLFlowDelegate::handleError($Throwable* t) {
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("handleError"_s, t);
	}
	$nc(this->readerCF)->completeExceptionally(t);
	$nc(this->writerCF)->completeExceptionally(t);
	$nc(this->alpnCF)->completeExceptionally(t);
	$nc(this->reader)->stop();
	$nc(this->writer)->stop();
}

void SSLFlowDelegate::normalStop() {
	$synchronized(this) {
		if (this->stopped) {
			return;
		}
		this->stopped = true;
		$nc(this->reader)->stop();
		$nc(this->writer)->stop();
		if (!$nc(this->alpnCF)->isDone()) {
			$var($Throwable, alpn, $new($SSLHandshakeException, "Connection closed before successful ALPN negotiation"_s));
			$nc(this->alpnCF)->completeExceptionally(alpn);
		}
		if (SSLFlowDelegate::isMonitored) {
			$SSLFlowDelegate$Monitor::remove(this->monitor$);
		}
	}
}

$Void* SSLFlowDelegate::stopOnError($Throwable* error) {
	if (!$nc(this->alpnCF)->isDone()) {
		$nc(this->alpnCF)->completeExceptionally(error);
	}
	normalStop();
	return nullptr;
}

void SSLFlowDelegate::cleanList($List* l) {
	$useLocalCurrentObjectStackCache();
	$synchronized(l) {
		$var($Iterator, iter, $nc(l)->iterator());
		while ($nc(iter)->hasNext()) {
			$var($ByteBuffer, b, $cast($ByteBuffer, iter->next()));
			if (!$nc(b)->hasRemaining() && b != SSLFlowDelegate::SENTINEL) {
				iter->remove();
			}
		}
	}
}

$String* SSLFlowDelegate::states($AtomicInteger* state) {
	$init(SSLFlowDelegate);
	int32_t s = $nc(state)->get();
	$var($StringBuilder, sb, $new($StringBuilder));
	int32_t x = (int32_t)(s & (uint32_t)~SSLFlowDelegate::TASK_BITS);
	switch (x) {
	case SSLFlowDelegate::NOT_HANDSHAKING:
		{
			sb->append(" NOT_HANDSHAKING "_s);
			break;
		}
	case SSLFlowDelegate::HANDSHAKING:
		{
			sb->append(" HANDSHAKING "_s);
			break;
		}
	default:
		{
			$throwNew($InternalError);
		}
	}
	if (((int32_t)(s & (uint32_t)SSLFlowDelegate::DOING_TASKS)) > 0) {
		sb->append("|DOING_TASKS"_s);
	}
	if (((int32_t)(s & (uint32_t)SSLFlowDelegate::REQUESTING_TASKS)) > 0) {
		sb->append("|REQUESTING_TASKS"_s);
	}
	return sb->toString();
}

void SSLFlowDelegate::resumeActivity() {
	$nc(this->reader)->schedule();
	$nc(this->writer)->schedule();
}

bool SSLFlowDelegate::doHandshake($SSLFlowDelegate$EngineResult* r, int32_t caller) {
	$useLocalCurrentObjectStackCache();
	$nc(this->handshakeState)->getAndAccumulate(0, static_cast<$IntBinaryOperator*>($$new(SSLFlowDelegate$$Lambda$lambda$doHandshake$2$6)));
	if (this->stateList != nullptr && $nc(this->debug)->on()) {
		$nc(this->stateList)->add($($nc($($nc(r)->handshakeStatus()))->toString()));
		$nc(this->stateList)->add($($Integer::toString(caller)));
	}
	$init($SSLFlowDelegate$1);
	{
		int32_t s = 0;
		$var($List, tasks, nullptr)
		switch ($nc($SSLFlowDelegate$1::$SwitchMap$javax$net$ssl$SSLEngineResult$HandshakeStatus)->get($nc(($($nc(r)->handshakeStatus())))->ordinal())) {
		case 1:
			{
				s = $nc(this->handshakeState)->accumulateAndGet(0, SSLFlowDelegate::REQUEST_OR_DO_TASKS);
				if (((int32_t)(s & (uint32_t)SSLFlowDelegate::REQUESTING_TASKS)) > 0) {
					return false;
				}
				if ($nc(this->debug)->on()) {
					$nc(this->debug)->log("obtaining and initiating task execution"_s);
				}
				$assign(tasks, obtainTasks());
				executeTasks(tasks);
				return false;
			}
		case 2:
			{
				if (caller == SSLFlowDelegate::READER) {
					$nc(this->writer)->triggerWrite();
					return false;
				}
				break;
			}
		case 3:
			{}
		case 4:
			{
				if (caller == SSLFlowDelegate::WRITER) {
					$nc(this->reader)->schedule();
					return false;
				}
				break;
			}
		default:
			{
				$throwNew($InternalError, $$str({"Unexpected handshake status:"_s, $(r->handshakeStatus())}));
			}
		}
	}
	return true;
}

$List* SSLFlowDelegate::obtainTasks() {
	$useLocalCurrentObjectStackCache();
	$var($List, l, $new($ArrayList));
	$var($Runnable, r, nullptr);
	while (($assign(r, $nc(this->engine)->getDelegatedTask())) != nullptr) {
		l->add(r);
	}
	return l;
}

void SSLFlowDelegate::executeTasks($List* tasks) {
	$nc(this->exec)->execute(static_cast<$Runnable*>($$new(SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7, this, tasks)));
}

bool SSLFlowDelegate::trySetALPN() {
	$useLocalCurrentObjectStackCache();
	if (((int32_t)($nc(this->handshakeState)->getAndSet(SSLFlowDelegate::NOT_HANDSHAKING) & (uint32_t)~SSLFlowDelegate::DOING_TASKS)) == SSLFlowDelegate::HANDSHAKING) {
		this->applicationBufferSize = $nc($($nc(this->engine)->getSession()))->getApplicationBufferSize();
		this->packetBufferSize = $nc($($nc(this->engine)->getSession()))->getPacketBufferSize();
		setALPN();
		return true;
	}
	return false;
}

$SSLFlowDelegate$EngineResult* SSLFlowDelegate::doClosure($SSLFlowDelegate$EngineResult* r) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("doClosure(%s): %s [isOutboundDone: %s, isInboundDone: %s]"_s, $$new($ObjectArray, {
			$of($nc(r)->result),
			$($of($nc(this->engine)->getHandshakeStatus())),
			$($of($Boolean::valueOf($nc(this->engine)->isOutboundDone()))),
			$($of($Boolean::valueOf($nc(this->engine)->isInboundDone())))
		}));
	}
	$init($SSLEngineResult$HandshakeStatus);
	if ($nc(this->engine)->getHandshakeStatus() == $SSLEngineResult$HandshakeStatus::NEED_WRAP) {
		bool var$0 = $nc(this->engine)->isInboundDone();
		if (var$0 && !$nc(this->engine)->isOutboundDone()) {
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("doClosure: close_notify received"_s);
			}
			this->close_notify_received = true;
			if (!$nc($nc(this->writer)->scheduler)->isStopped()) {
				doHandshake(r, SSLFlowDelegate::READER);
			} else {
				$synchronized($nc(this->reader)->readBufferLock) {
					$nc(this->reader)->completing = true;
				}
			}
		}
	}
	return r;
}

$Flow$Subscriber* SSLFlowDelegate::upstreamReader() {
	return static_cast<$Flow$Subscriber*>(static_cast<$FlowTube$TubeSubscriber*>(static_cast<$SubscriberWrapper*>(this->reader)));
}

$Flow$Subscriber* SSLFlowDelegate::upstreamWriter() {
	return static_cast<$Flow$Subscriber*>(static_cast<$FlowTube$TubeSubscriber*>(static_cast<$SubscriberWrapper*>(this->writer)));
}

bool SSLFlowDelegate::resumeReader() {
	return $nc(this->reader)->signalScheduling();
}

void SSLFlowDelegate::resetReaderDemand() {
	$nc(this->reader)->resetDownstreamDemand();
}

$ByteBuffer* SSLFlowDelegate::getNetBuffer() {
	int32_t netSize = this->packetBufferSize;
	if (netSize <= 0) {
		this->packetBufferSize = (netSize = $nc($($nc(this->engine)->getSession()))->getPacketBufferSize());
	}
	return $ByteBuffer::allocate(netSize);
}

$ByteBuffer* SSLFlowDelegate::getAppBuffer() {
	int32_t appSize = this->applicationBufferSize;
	if (appSize <= 0) {
		this->applicationBufferSize = (appSize = $nc($($nc(this->engine)->getSession()))->getApplicationBufferSize());
	}
	int32_t size = this->adaptiveAppBufferSize;
	if (size <= 0) {
		size = 512;
	} else if (size > appSize) {
		size = appSize;
	}
	return $ByteBuffer::allocate(size);
}

$String* SSLFlowDelegate::dbgString() {
	return $str({"SSLFlowDelegate("_s, this->tubeName, ")"_s});
}

void SSLFlowDelegate::lambda$executeTasks$3($List* tasks) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($List, nextTasks, tasks);
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log($$str({"#tasks to execute: "_s, $($Integer::toString($nc(nextTasks)->size()))}));
		}
		do {
			$nc(nextTasks)->forEach(static_cast<$Consumer*>($$new(SSLFlowDelegate$$Lambda$run$8)));
			$init($SSLEngineResult$HandshakeStatus);
			if ($nc(this->engine)->getHandshakeStatus() == $SSLEngineResult$HandshakeStatus::NEED_TASK) {
				$assign(nextTasks, obtainTasks());
			} else {
				int32_t s = $nc(this->handshakeState)->accumulateAndGet(0, SSLFlowDelegate::FINISH_OR_DO_TASKS);
				if (((int32_t)(s & (uint32_t)SSLFlowDelegate::DOING_TASKS)) != 0) {
					if ($nc(this->debug)->on()) {
						$nc(this->debug)->log("re-running tasks (B)"_s);
					}
					$assign(nextTasks, obtainTasks());
					continue;
				}
				break;
			}
		} while (true);
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("finished task execution"_s);
		}
		$SSLEngineResult$HandshakeStatus* hs = $nc(this->engine)->getHandshakeStatus();
		$init($SSLEngineResult$HandshakeStatus);
		if (hs == $SSLEngineResult$HandshakeStatus::FINISHED || hs == $SSLEngineResult$HandshakeStatus::NOT_HANDSHAKING) {
			trySetALPN();
		}
		resumeActivity();
	} catch ($Throwable& t) {
		handleError($(checkForHandshake(t)));
	}
}

int32_t SSLFlowDelegate::lambda$doHandshake$2(int32_t current, int32_t unused) {
	$init(SSLFlowDelegate);
	return SSLFlowDelegate::HANDSHAKING | ((int32_t)(current & (uint32_t)SSLFlowDelegate::TASK_BITS));
}

int32_t SSLFlowDelegate::lambda$static$1(int32_t current, int32_t ignored) {
	$init(SSLFlowDelegate);
	if (((int32_t)(current & (uint32_t)SSLFlowDelegate::REQUESTING_TASKS)) != 0) {
		return SSLFlowDelegate::DOING_TASKS | ((int32_t)(current & (uint32_t)SSLFlowDelegate::HANDSHAKING));
	}
	return ((int32_t)(current & (uint32_t)SSLFlowDelegate::HANDSHAKING));
}

int32_t SSLFlowDelegate::lambda$static$0(int32_t current, int32_t ignored) {
	$init(SSLFlowDelegate);
	if (((int32_t)(current & (uint32_t)SSLFlowDelegate::DOING_TASKS)) == 0) {
		return SSLFlowDelegate::DOING_TASKS | ((int32_t)(current & (uint32_t)SSLFlowDelegate::HANDSHAKING));
	} else {
		return (SSLFlowDelegate::DOING_TASKS | SSLFlowDelegate::REQUESTING_TASKS) | ((int32_t)(current & (uint32_t)SSLFlowDelegate::HANDSHAKING));
	}
}

void clinit$SSLFlowDelegate($Class* class$) {
	$init($Utils);
	$assignStatic(SSLFlowDelegate::SENTINEL, $Utils::EMPTY_BYTEBUFFER);
	$assignStatic(SSLFlowDelegate::HS_TRIGGER, $ByteBuffer::allocate(0));
	$assignStatic(SSLFlowDelegate::NOTHING, $ByteBuffer::allocate(0));
	$assignStatic(SSLFlowDelegate::monProp, $Utils::getProperty("jdk.internal.httpclient.monitorFlowDelegate"_s));
	bool var$0 = SSLFlowDelegate::monProp != nullptr;
	if (var$0) {
		bool var$1 = $nc(SSLFlowDelegate::monProp)->isEmpty();
		var$0 = (var$1 || $nc(SSLFlowDelegate::monProp)->equalsIgnoreCase("true"_s));
	}
	SSLFlowDelegate::isMonitored = var$0;
	$assignStatic(SSLFlowDelegate::scount, $new($AtomicInteger, 1));
	$assignStatic(SSLFlowDelegate::REQUEST_OR_DO_TASKS, static_cast<$IntBinaryOperator*>($new(SSLFlowDelegate$$Lambda$lambda$static$0$2)));
	$assignStatic(SSLFlowDelegate::FINISH_OR_DO_TASKS, static_cast<$IntBinaryOperator*>($new(SSLFlowDelegate$$Lambda$lambda$static$1$3)));
}

SSLFlowDelegate::SSLFlowDelegate() {
}

$Class* SSLFlowDelegate::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SSLFlowDelegate$$Lambda$dbgString::classInfo$.name)) {
			return SSLFlowDelegate$$Lambda$dbgString::load$(name, initialize);
		}
		if (name->equals(SSLFlowDelegate$$Lambda$monitor$1::classInfo$.name)) {
			return SSLFlowDelegate$$Lambda$monitor$1::load$(name, initialize);
		}
		if (name->equals(SSLFlowDelegate$$Lambda$lambda$static$0$2::classInfo$.name)) {
			return SSLFlowDelegate$$Lambda$lambda$static$0$2::load$(name, initialize);
		}
		if (name->equals(SSLFlowDelegate$$Lambda$lambda$static$1$3::classInfo$.name)) {
			return SSLFlowDelegate$$Lambda$lambda$static$1$3::load$(name, initialize);
		}
		if (name->equals(SSLFlowDelegate$$Lambda$stopOnError$4::classInfo$.name)) {
			return SSLFlowDelegate$$Lambda$stopOnError$4::load$(name, initialize);
		}
		if (name->equals(SSLFlowDelegate$$Lambda$normalStop$5::classInfo$.name)) {
			return SSLFlowDelegate$$Lambda$normalStop$5::load$(name, initialize);
		}
		if (name->equals(SSLFlowDelegate$$Lambda$lambda$doHandshake$2$6::classInfo$.name)) {
			return SSLFlowDelegate$$Lambda$lambda$doHandshake$2$6::load$(name, initialize);
		}
		if (name->equals(SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7::classInfo$.name)) {
			return SSLFlowDelegate$$Lambda$lambda$executeTasks$3$7::load$(name, initialize);
		}
		if (name->equals(SSLFlowDelegate$$Lambda$run$8::classInfo$.name)) {
			return SSLFlowDelegate$$Lambda$run$8::load$(name, initialize);
		}
	}
	$loadClass(SSLFlowDelegate, name, initialize, &_SSLFlowDelegate_ClassInfo_, clinit$SSLFlowDelegate, allocate$SSLFlowDelegate);
	return class$;
}

$Class* SSLFlowDelegate::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk