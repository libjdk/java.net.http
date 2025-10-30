#include <jdk/internal/net/http/Http1AsyncReceiver.h>

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
#include <java/util/AbstractSet.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentLinkedDeque.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/AbstractSubscription.h>
#include <jdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegate.h>
#include <jdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegateSubscription.h>
#include <jdk/internal/net/http/Http1AsyncReceiver$Http1TubeSubscriber.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jdk/internal/net/http/HttpClientImpl$DelegatingExecutor.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/common/ConnectionExpiredException.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef DEBUG
#undef EMPTY_BB_ARRAY
#undef EMPTY_BYTEBUFFER
#undef MAX_VALUE

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
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
using $AbstractSet = ::java::util::AbstractSet;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $ConcurrentLinkedDeque = ::java::util::concurrent::ConcurrentLinkedDeque;
using $Executor = ::java::util::concurrent::Executor;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $Consumer = ::java::util::function::Consumer;
using $Supplier = ::java::util::function::Supplier;
using $AbstractSubscription = ::jdk::internal::net::http::AbstractSubscription;
using $Http1AsyncReceiver$Http1AsyncDelegate = ::jdk::internal::net::http::Http1AsyncReceiver$Http1AsyncDelegate;
using $Http1AsyncReceiver$Http1AsyncDelegateSubscription = ::jdk::internal::net::http::Http1AsyncReceiver$Http1AsyncDelegateSubscription;
using $Http1AsyncReceiver$Http1TubeSubscriber = ::jdk::internal::net::http::Http1AsyncReceiver$Http1TubeSubscriber;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpClientImpl$DelegatingExecutor = ::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $ConnectionExpiredException = ::jdk::internal::net::http::common::ConnectionExpiredException;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Http1AsyncReceiver$$Lambda$dbgString : public $Supplier {
	$class(Http1AsyncReceiver$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Http1AsyncReceiver* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1AsyncReceiver$$Lambda$dbgString>());
	}
	Http1AsyncReceiver* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1AsyncReceiver$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1AsyncReceiver$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo Http1AsyncReceiver$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1AsyncReceiver;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1AsyncReceiver$$Lambda$dbgString::*)(Http1AsyncReceiver*)>(&Http1AsyncReceiver$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1AsyncReceiver$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1AsyncReceiver$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http1AsyncReceiver$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(Http1AsyncReceiver$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1AsyncReceiver$$Lambda$dbgString::class$ = nullptr;

class Http1AsyncReceiver$$Lambda$flush$1 : public $Runnable {
	$class(Http1AsyncReceiver$$Lambda$flush$1, $NO_CLASS_INIT, $Runnable)
public:
	void init$(Http1AsyncReceiver* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->flush();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1AsyncReceiver$$Lambda$flush$1>());
	}
	Http1AsyncReceiver* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1AsyncReceiver$$Lambda$flush$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1AsyncReceiver$$Lambda$flush$1, inst$)},
	{}
};
$MethodInfo Http1AsyncReceiver$$Lambda$flush$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1AsyncReceiver;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1AsyncReceiver$$Lambda$flush$1::*)(Http1AsyncReceiver*)>(&Http1AsyncReceiver$$Lambda$flush$1::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1AsyncReceiver$$Lambda$flush$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1AsyncReceiver$$Lambda$flush$1",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* Http1AsyncReceiver$$Lambda$flush$1::load$($String* name, bool initialize) {
	$loadClass(Http1AsyncReceiver$$Lambda$flush$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1AsyncReceiver$$Lambda$flush$1::class$ = nullptr;

class Http1AsyncReceiver$$Lambda$lambda$flush$0$2 : public $Supplier {
	$class(Http1AsyncReceiver$$Lambda$lambda$flush$0$2, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Http1AsyncReceiver* inst, int64_t remaining) {
		$set(this, inst$, inst);
		this->remaining = remaining;
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$flush$0(remaining));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1AsyncReceiver$$Lambda$lambda$flush$0$2>());
	}
	Http1AsyncReceiver* inst$ = nullptr;
	int64_t remaining = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1AsyncReceiver$$Lambda$lambda$flush$0$2::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1AsyncReceiver$$Lambda$lambda$flush$0$2, inst$)},
	{"remaining", "J", nullptr, $PUBLIC, $field(Http1AsyncReceiver$$Lambda$lambda$flush$0$2, remaining)},
	{}
};
$MethodInfo Http1AsyncReceiver$$Lambda$lambda$flush$0$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1AsyncReceiver;J)V", nullptr, $PUBLIC, $method(static_cast<void(Http1AsyncReceiver$$Lambda$lambda$flush$0$2::*)(Http1AsyncReceiver*,int64_t)>(&Http1AsyncReceiver$$Lambda$lambda$flush$0$2::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1AsyncReceiver$$Lambda$lambda$flush$0$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1AsyncReceiver$$Lambda$lambda$flush$0$2",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http1AsyncReceiver$$Lambda$lambda$flush$0$2::load$($String* name, bool initialize) {
	$loadClass(Http1AsyncReceiver$$Lambda$lambda$flush$0$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1AsyncReceiver$$Lambda$lambda$flush$0$2::class$ = nullptr;

class Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3 : public $Supplier {
	$class(Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Http1AsyncReceiver* inst, $Throwable* x, Object$* captured) {
		$set(this, inst$, inst);
		$set(this, x, x);
		$set(this, captured, captured);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$checkForErrors$1(x, captured));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3>());
	}
	Http1AsyncReceiver* inst$ = nullptr;
	$Throwable* x = nullptr;
	$Object* captured = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3, inst$)},
	{"x", "Ljava/lang/Throwable;", nullptr, $PUBLIC, $field(Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3, x)},
	{"captured", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3, captured)},
	{}
};
$MethodInfo Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1AsyncReceiver;Ljava/lang/Throwable;Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3::*)(Http1AsyncReceiver*,$Throwable*,Object$*)>(&Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3::load$($String* name, bool initialize) {
	$loadClass(Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3::class$ = nullptr;

class Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4 : public $Consumer {
	$class(Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4, $NO_CLASS_INIT, $Consumer)
public:
	void init$(Http1AsyncReceiver* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* x) override {
		$nc(inst$)->lambda$handlePendingDelegate$2($cast($Throwable, x));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4>());
	}
	Http1AsyncReceiver* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4, inst$)},
	{}
};
$MethodInfo Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1AsyncReceiver;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4::*)(Http1AsyncReceiver*)>(&Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4::load$($String* name, bool initialize) {
	$loadClass(Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4::class$ = nullptr;

class Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5 : public $Runnable {
	$class(Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5, $NO_CLASS_INIT, $Runnable)
public:
	void init$(Http1AsyncReceiver* inst, $Http1AsyncReceiver$Http1AsyncDelegate* pending) {
		$set(this, inst$, inst);
		$set(this, pending, pending);
	}
	virtual void run() override {
		$nc(inst$)->lambda$handlePendingDelegate$3(pending);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5>());
	}
	Http1AsyncReceiver* inst$ = nullptr;
	$Http1AsyncReceiver$Http1AsyncDelegate* pending = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5, inst$)},
	{"pending", "Ljdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegate;", nullptr, $PUBLIC, $field(Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5, pending)},
	{}
};
$MethodInfo Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1AsyncReceiver;Ljdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegate;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5::*)(Http1AsyncReceiver*,$Http1AsyncReceiver$Http1AsyncDelegate*)>(&Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5::load$($String* name, bool initialize) {
	$loadClass(Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5::class$ = nullptr;

$FieldInfo _Http1AsyncReceiver_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http1AsyncReceiver, $assertionsDisabled)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(Http1AsyncReceiver, debug)},
	{"queue", "Ljava/util/concurrent/ConcurrentLinkedDeque;", "Ljava/util/concurrent/ConcurrentLinkedDeque<Ljava/nio/ByteBuffer;>;", $PRIVATE | $FINAL, $field(Http1AsyncReceiver, queue)},
	{"scheduler", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $PRIVATE | $FINAL, $field(Http1AsyncReceiver, scheduler)},
	{"whenFinished", "Ljdk/internal/net/http/common/MinimalFuture;", "Ljdk/internal/net/http/common/MinimalFuture<Ljava/lang/Void;>;", $FINAL, $field(Http1AsyncReceiver, whenFinished)},
	{"executor", "Ljava/util/concurrent/Executor;", nullptr, $PRIVATE | $FINAL, $field(Http1AsyncReceiver, executor)},
	{"subscriber", "Ljdk/internal/net/http/Http1AsyncReceiver$Http1TubeSubscriber;", nullptr, $PRIVATE | $FINAL, $field(Http1AsyncReceiver, subscriber$)},
	{"pendingDelegateRef", "Ljava/util/concurrent/atomic/AtomicReference;", "Ljava/util/concurrent/atomic/AtomicReference<Ljdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegate;>;", $PRIVATE | $FINAL, $field(Http1AsyncReceiver, pendingDelegateRef)},
	{"received", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $FINAL, $field(Http1AsyncReceiver, received)},
	{"canRequestMore", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $FINAL, $field(Http1AsyncReceiver, canRequestMore)},
	{"error", "Ljava/lang/Throwable;", nullptr, $PRIVATE | $VOLATILE, $field(Http1AsyncReceiver, error)},
	{"delegate", "Ljdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegate;", nullptr, $PRIVATE | $VOLATILE, $field(Http1AsyncReceiver, delegate)},
	{"owner", "Ljdk/internal/net/http/Http1Exchange;", "Ljdk/internal/net/http/Http1Exchange<*>;", $PRIVATE | $VOLATILE, $field(Http1AsyncReceiver, owner)},
	{"client", "Ljdk/internal/net/http/HttpClientImpl;", nullptr, $PRIVATE | $FINAL, $field(Http1AsyncReceiver, client)},
	{"retry", "Z", nullptr, $PRIVATE, $field(Http1AsyncReceiver, retry)},
	{"stopRequested", "Z", nullptr, $PRIVATE | $VOLATILE, $field(Http1AsyncReceiver, stopRequested)},
	{"dbgTag", "Ljava/lang/String;", nullptr, $VOLATILE, $field(Http1AsyncReceiver, dbgTag)},
	{}
};

$MethodInfo _Http1AsyncReceiver_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/Executor;Ljdk/internal/net/http/Http1Exchange;)V", "(Ljava/util/concurrent/Executor;Ljdk/internal/net/http/Http1Exchange<*>;)V", $PUBLIC, $method(static_cast<void(Http1AsyncReceiver::*)($Executor*,$Http1Exchange*)>(&Http1AsyncReceiver::init$))},
	{"asyncReceive", "(Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1AsyncReceiver::*)($ByteBuffer*)>(&Http1AsyncReceiver::asyncReceive))},
	{"checkForErrors", "()V", nullptr, $PRIVATE, $method(static_cast<void(Http1AsyncReceiver::*)()>(&Http1AsyncReceiver::checkForErrors))},
	{"checkRequestMore", "()V", nullptr, $PRIVATE, $method(static_cast<void(Http1AsyncReceiver::*)()>(&Http1AsyncReceiver::checkRequestMore))},
	{"clear", "()V", nullptr, 0},
	{"dbgString", "()Ljava/lang/String;", nullptr, 0},
	{"debugQBB", "([Ljava/nio/ByteBuffer;)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(Http1AsyncReceiver::*)($ByteBufferArray*)>(&Http1AsyncReceiver::debugQBB))},
	{"describe", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(Http1AsyncReceiver::*)()>(&Http1AsyncReceiver::describe))},
	{"drain", "(Ljava/nio/ByteBuffer;)Ljava/nio/ByteBuffer;", nullptr, 0},
	{"flush", "()V", nullptr, $PRIVATE, $method(static_cast<void(Http1AsyncReceiver::*)()>(&Http1AsyncReceiver::flush))},
	{"handlePendingDelegate", "()Z", nullptr, $PRIVATE, $method(static_cast<bool(Http1AsyncReceiver::*)()>(&Http1AsyncReceiver::handlePendingDelegate))},
	{"hasDemand", "(Ljdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegate;)Z", nullptr, $PRIVATE, $method(static_cast<bool(Http1AsyncReceiver::*)($Http1AsyncReceiver$Http1AsyncDelegate*)>(&Http1AsyncReceiver::hasDemand))},
	{"lambda$checkForErrors$1", "(Ljava/lang/Throwable;Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(Http1AsyncReceiver::*)($Throwable*,Object$*)>(&Http1AsyncReceiver::lambda$checkForErrors$1))},
	{"lambda$flush$0", "(J)Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(Http1AsyncReceiver::*)(int64_t)>(&Http1AsyncReceiver::lambda$flush$0))},
	{"lambda$handlePendingDelegate$2", "(Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Http1AsyncReceiver::*)($Throwable*)>(&Http1AsyncReceiver::lambda$handlePendingDelegate$2))},
	{"lambda$handlePendingDelegate$3", "(Ljdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegate;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Http1AsyncReceiver::*)($Http1AsyncReceiver$Http1AsyncDelegate*)>(&Http1AsyncReceiver::lambda$handlePendingDelegate$3))},
	{"onReadError", "(Ljava/lang/Throwable;)V", nullptr, 0},
	{"remaining", "()J", nullptr, 0},
	{"setRetryOnError", "(Z)V", nullptr, $SYNCHRONIZED},
	{"stop", "()V", nullptr, 0},
	{"subscribe", "(Ljdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegate;)V", nullptr, 0},
	{"subscriber", "()Ljdk/internal/net/http/common/FlowTube$TubeSubscriber;", nullptr, 0},
	{"unsubscribe", "(Ljdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegate;)V", nullptr, 0},
	{}
};

$InnerClassInfo _Http1AsyncReceiver_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1AsyncReceiver$Http1TubeSubscriber", "jdk.internal.net.http.Http1AsyncReceiver", "Http1TubeSubscriber", $FINAL},
	{"jdk.internal.net.http.Http1AsyncReceiver$Http1AsyncDelegateSubscription", "jdk.internal.net.http.Http1AsyncReceiver", "Http1AsyncDelegateSubscription", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.net.http.Http1AsyncReceiver$Http1AsyncDelegate", "jdk.internal.net.http.Http1AsyncReceiver", "Http1AsyncDelegate", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Http1AsyncReceiver_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.Http1AsyncReceiver",
	"java.lang.Object",
	nullptr,
	_Http1AsyncReceiver_FieldInfo_,
	_Http1AsyncReceiver_MethodInfo_,
	nullptr,
	nullptr,
	_Http1AsyncReceiver_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1AsyncReceiver$Http1TubeSubscriber,jdk.internal.net.http.Http1AsyncReceiver$Http1AsyncDelegateSubscription,jdk.internal.net.http.Http1AsyncReceiver$Http1AsyncDelegate"
};

$Object* allocate$Http1AsyncReceiver($Class* clazz) {
	return $of($alloc(Http1AsyncReceiver));
}

bool Http1AsyncReceiver::$assertionsDisabled = false;

void Http1AsyncReceiver::init$($Executor* executor, $Http1Exchange* owner) {
	$useLocalCurrentObjectStackCache();
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(Http1AsyncReceiver$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, queue, $new($ConcurrentLinkedDeque));
	$set(this, scheduler, $SequentialScheduler::lockingScheduler(static_cast<$Runnable*>($$new(Http1AsyncReceiver$$Lambda$flush$1, this))));
	$set(this, subscriber$, $new($Http1AsyncReceiver$Http1TubeSubscriber, this));
	$set(this, received, $new($AtomicLong));
	$set(this, canRequestMore, $new($AtomicBoolean));
	$set(this, pendingDelegateRef, $new($AtomicReference));
	$set(this, executor, executor);
	$set(this, whenFinished, $new($MinimalFuture));
	$set(this, owner, owner);
	$set(this, client, $nc(owner)->client$);
}

void Http1AsyncReceiver::flush() {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, buf, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				bool var$2 = !Http1AsyncReceiver::$assertionsDisabled;
				if (var$2) {
					bool var$3 = !$nc(this->client)->isSelectorThread();
					var$2 = !(var$3 || !($instanceOf($ExecutorService, $($nc($($nc(this->client)->theExecutor()))->delegate()))));
				}
				if (var$2) {
					$throwNew($AssertionError, $of($$str({"Http1AsyncReceiver::flush should not run in the selector: "_s, $($($Thread::currentThread())->getName())})));
				}
				handlePendingDelegate();
				while (($assign(buf, $cast($ByteBuffer, $nc(this->queue)->peek()))) != nullptr && !this->stopRequested) {
					$var($Http1AsyncReceiver$Http1AsyncDelegate, delegate, this->delegate);
					if ($nc(this->debug)->on()) {
						$nc(this->debug)->log("Got %s bytes for delegate %s"_s, $$new($ObjectArray, {
							$($of($Integer::valueOf($nc(buf)->remaining()))),
							$of(delegate)
						}));
					}
					if (!hasDemand(delegate)) {
						return$1 = true;
						goto $finally;
					}
					if (!Http1AsyncReceiver::$assertionsDisabled && !(delegate != nullptr)) {
						$throwNew($AssertionError);
					}
					if ($nc(this->debug)->on()) {
						$nc(this->debug)->log("Forwarding %s bytes to delegate %s"_s, $$new($ObjectArray, {
							$($of($Integer::valueOf($nc(buf)->remaining()))),
							$of(delegate)
						}));
					}
					if (!$nc(delegate)->tryAsyncReceive(buf)) {
						int64_t remaining = $nc(buf)->remaining();
						if ($nc(this->debug)->on()) {
							$nc(this->debug)->log(static_cast<$Supplier*>($$new(Http1AsyncReceiver$$Lambda$lambda$flush$0$2, this, remaining)));
						}
						$nc(this->canRequestMore)->set(false);
						return$1 = true;
						goto $finally;
					}
					$var($ByteBuffer, parsed, $cast($ByteBuffer, $nc(this->queue)->remove()));
					$nc(this->canRequestMore)->set($nc(this->queue)->isEmpty() && !this->stopRequested);
					if (!Http1AsyncReceiver::$assertionsDisabled && !(parsed == buf)) {
						$throwNew($AssertionError);
					}
				}
				checkRequestMore();
			} catch ($Throwable& t) {
				$var($Throwable, x, this->error);
				if (x == nullptr) {
					$set(this, error, t);
				}
				if ($nc(this->debug)->on()) {
					$nc(this->debug)->log("Unexpected error caught in flush()"_s, t);
				}
			}
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			checkForErrors();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

$String* Http1AsyncReceiver::describe() {
	$useLocalCurrentObjectStackCache();
	$var($Http1Exchange, exchange, this->owner);
	if (exchange != nullptr) {
		return $String::valueOf($($of(exchange->request())));
	}
	return "<uri unavailable>"_s;
}

void Http1AsyncReceiver::checkForErrors() {
	$useLocalCurrentObjectStackCache();
	$var($Http1AsyncReceiver$Http1AsyncDelegate, delegate, $cast($Http1AsyncReceiver$Http1AsyncDelegate, $nc(this->pendingDelegateRef)->get()));
	if (delegate == nullptr) {
		$assign(delegate, this->delegate);
	}
	$var($Throwable, x, this->error);
	if (delegate != nullptr && x != nullptr && (this->stopRequested || $nc(this->queue)->isEmpty())) {
		$var($Object, captured, delegate);
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log(static_cast<$Supplier*>($$new(Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3, this, x, captured)));
		}
		$nc(this->scheduler)->stop();
		$nc(delegate)->onReadError(x);
		$nc(this->whenFinished)->completeExceptionally(x);
		if ($Log::channel()) {
			$Log::logChannel("HTTP/1 read subscriber stopped for: {0}"_s, $$new($ObjectArray, {$($of(describe()))}));
		}
		if (this->stopRequested) {
			$var($Http1Exchange, exchg, this->owner);
			stop();
			if (exchg != nullptr) {
				$nc($(exchg->connection()))->close();
			}
		}
	}
}

void Http1AsyncReceiver::checkRequestMore() {
	$useLocalCurrentObjectStackCache();
	$var($Http1AsyncReceiver$Http1AsyncDelegate, delegate, this->delegate);
	bool more = $nc(this->canRequestMore)->get();
	bool hasDemand = this->hasDemand(delegate);
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log($$str({"checkRequestMore: canRequestMore="_s, $$str(more), ", hasDemand="_s, $$str(hasDemand), (delegate == nullptr ? ", delegate=null"_s : ""_s)}));
	}
	if (hasDemand) {
		$nc(this->subscriber$)->requestMore();
	}
}

bool Http1AsyncReceiver::hasDemand($Http1AsyncReceiver$Http1AsyncDelegate* delegate) {
	$useLocalCurrentObjectStackCache();
	if (delegate == nullptr) {
		return false;
	}
	$var($AbstractSubscription, subscription, $nc(delegate)->subscription());
	int64_t demand = $nc($($nc(subscription)->demand()))->get();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("downstream subscription demand is %s"_s, $$new($ObjectArray, {$($of($Long::valueOf(demand)))}));
	}
	return demand > 0;
}

bool Http1AsyncReceiver::handlePendingDelegate() {
	$useLocalCurrentObjectStackCache();
	$var($Http1AsyncReceiver$Http1AsyncDelegate, pending, $cast($Http1AsyncReceiver$Http1AsyncDelegate, $nc(this->pendingDelegateRef)->get()));
	if (pending != nullptr && $nc(this->pendingDelegateRef)->compareAndSet(pending, nullptr)) {
		$var($Http1AsyncReceiver$Http1AsyncDelegate, delegate, this->delegate);
		if (delegate != nullptr) {
			unsubscribe(delegate);
		}
		$var($Consumer, onSubscriptionError, static_cast<$Consumer*>($new(Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4, this)));
		$var($Runnable, cancel, static_cast<$Runnable*>($new(Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5, this, pending)));
		$var($Http1AsyncReceiver$Http1AsyncDelegateSubscription, subscription, $new($Http1AsyncReceiver$Http1AsyncDelegateSubscription, this->scheduler, cancel, onSubscriptionError));
		{
			$var($Throwable, var$0, nullptr);
			try {
				pending->onSubscribe(subscription);
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				$set(this, delegate, ($assign(delegate, pending)));
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		$var($Object, captured, delegate);
		if ($nc(this->debug)->on()) {
			$var($String, var$6, $$str({"delegate is now "_s, captured, ", demand="_s}));
			$var($String, var$5, $$concat(var$6, $$str($nc($(subscription->demand()))->get())));
			$var($String, var$4, $$concat(var$5, ", canRequestMore="));
			$var($String, var$3, $$concat(var$4, $$str($nc(this->canRequestMore)->get())));
			$var($String, var$2, $$concat(var$3, ", queue.isEmpty="));
			$nc(this->debug)->log($$concat(var$2, $$str($nc(this->queue)->isEmpty())));
		}
		return true;
	}
	return false;
}

void Http1AsyncReceiver::setRetryOnError(bool retry) {
	$synchronized(this) {
		this->retry = retry;
	}
}

void Http1AsyncReceiver::clear() {
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("cleared"_s);
	}
	$nc(this->pendingDelegateRef)->set(nullptr);
	$set(this, delegate, nullptr);
	$set(this, owner, nullptr);
}

void Http1AsyncReceiver::subscribe($Http1AsyncReceiver$Http1AsyncDelegate* delegate) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this) {
		$nc(this->pendingDelegateRef)->set(delegate);
	}
	if ($nc(this->queue)->isEmpty()) {
		$nc(this->canRequestMore)->set(true);
	}
	if ($nc(this->debug)->on()) {
		$var($String, var$0, $$str({"Subscribed pending "_s, delegate, " queue.isEmpty: "_s}));
		$nc(this->debug)->log($$concat(var$0, $$str($nc(this->queue)->isEmpty())));
	}
	if ($nc(this->client)->isSelectorThread()) {
		$nc(this->scheduler)->runOrSchedule(this->executor);
	} else {
		$nc(this->scheduler)->runOrSchedule();
	}
}

int64_t Http1AsyncReceiver::remaining() {
	$init($Utils);
	return $Utils::remaining($fcast($ByteBufferArray, $($nc(this->queue)->toArray($Utils::EMPTY_BB_ARRAY))));
}

void Http1AsyncReceiver::unsubscribe($Http1AsyncReceiver$Http1AsyncDelegate* delegate) {
	$synchronized(this) {
		if (this->delegate == delegate) {
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("Unsubscribed %s"_s, $$new($ObjectArray, {$of(delegate)}));
			}
			$set(this, delegate, nullptr);
		}
	}
}

void Http1AsyncReceiver::asyncReceive($ByteBuffer* buf) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Putting %s bytes into the queue"_s, $$new($ObjectArray, {$($of($Integer::valueOf($nc(buf)->remaining())))}));
	}
	$nc(this->received)->addAndGet($nc(buf)->remaining());
	$nc(this->queue)->offer(buf);
	$nc(this->scheduler)->runOrSchedule(this->executor);
}

void Http1AsyncReceiver::onReadError($Throwable* ex$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, ex, ex$renamed);
	$var($Http1AsyncReceiver$Http1AsyncDelegate, delegate, nullptr);
	$var($Throwable, recorded, nullptr);
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("onError: %s"_s, $$new($ObjectArray, {$of(ex)}));
	}
	$synchronized(this) {
		$assign(delegate, this->delegate);
		$assign(recorded, this->error);
		if (recorded == nullptr) {
			if (this->retry && ($instanceOf($IOException, ex))) {
				if ($nc(this->received)->get() == 0) {
					this->retry = false;
					$assign(ex, $new($ConnectionExpiredException, ex));
				}
			}
			$set(this, error, ex);
		}
	}
	$var($Throwable, t, recorded == nullptr ? ex : recorded);
	if ($nc(this->debug)->on()) {
		$var($String, var$0, $$str({"recorded "_s, t, "\n\t delegate: "_s, delegate, "\t\t queue.isEmpty: "_s}));
		$nc(this->debug)->log($$concat(var$0, $$str($nc(this->queue)->isEmpty())), ex);
	}
	if ($Log::errors()) {
		$Log::logError("HTTP/1 read subscriber recorded error: {0} - {1}"_s, $$new($ObjectArray, {
			$($of(describe())),
			$of(t)
		}));
	}
	bool var$1 = $nc(this->queue)->isEmpty();
	if (var$1 || $nc(this->pendingDelegateRef)->get() != nullptr || this->stopRequested) {
		if ($Log::errors()) {
			$Log::logError("HTTP/1 propagating recorded error: {0} - {1}"_s, $$new($ObjectArray, {
				$($of(describe())),
				$of(t)
			}));
		}
		$nc(this->scheduler)->runOrSchedule(this->executor);
	}
}

void Http1AsyncReceiver::stop() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("stopping"_s);
	}
	bool var$0 = $Log::channel();
	if (var$0 && !$nc(this->scheduler)->isStopped()) {
		$Log::logChannel("HTTP/1 read subscriber stopped for {0}"_s, $$new($ObjectArray, {$($of(describe()))}));
	}
	$nc(this->scheduler)->stop();
	$var($Http1AsyncReceiver$Http1AsyncDelegate, previous, this->delegate);
	if (previous != nullptr) {
		previous->close(this->error);
	}
	$set(this, delegate, nullptr);
	$set(this, owner, nullptr);
	$nc(this->whenFinished)->complete(nullptr);
}

$FlowTube$TubeSubscriber* Http1AsyncReceiver::subscriber() {
	return this->subscriber$;
}

$ByteBuffer* Http1AsyncReceiver::drain($ByteBuffer* initial$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, initial, initial$renamed);
	$init($Utils);
	$var($ByteBuffer, b, $assign(initial, initial == nullptr ? $Utils::EMPTY_BYTEBUFFER : initial));
	if (!Http1AsyncReceiver::$assertionsDisabled && !$nc(this->scheduler)->isStopped()) {
		$throwNew($AssertionError);
	}
	if ($nc(this->queue)->isEmpty()) {
		return b;
	}
	$var($ByteBufferArray, qbb, $fcast($ByteBufferArray, $nc(this->queue)->toArray($$new($ByteBufferArray, $nc(this->queue)->size()))));
	int32_t size = $Utils::remaining(qbb, $Integer::MAX_VALUE);
	int32_t remaining = $nc(b)->remaining();
	int32_t var$0 = b->capacity();
	int32_t free = var$0 - b->position() - remaining;
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Flushing %s bytes from queue into initial buffer (remaining=%s, free=%s)"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf(size))),
			$($of($Integer::valueOf(remaining))),
			$($of($Integer::valueOf(free)))
		}));
	}
	if (size > free) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Allocating new buffer for initial: %s"_s, $$new($ObjectArray, {$($of($Integer::valueOf((size + remaining))))}));
		}
		$assign(b, $ByteBuffer::allocate(size + remaining));
		$Utils::copy(initial, b);
		if (!Http1AsyncReceiver::$assertionsDisabled && !($nc(b)->position() == remaining)) {
			$throwNew($AssertionError);
		}
		$nc(b)->flip();
		if (!Http1AsyncReceiver::$assertionsDisabled && !(b->position() == 0)) {
			$throwNew($AssertionError);
		}
		if (!Http1AsyncReceiver::$assertionsDisabled && !(b->limit() == remaining)) {
			$throwNew($AssertionError);
		}
		if (!Http1AsyncReceiver::$assertionsDisabled && !(b->remaining() == remaining)) {
			$throwNew($AssertionError);
		}
	}
	int32_t pos = b->position();
	int32_t limit = b->limit();
	if (!Http1AsyncReceiver::$assertionsDisabled && !(limit - pos == remaining)) {
		$throwNew($AssertionError);
	}
	if (!Http1AsyncReceiver::$assertionsDisabled && !(b->capacity() >= remaining + size)) {
		$var($String, var$3, $$str({"capacity: "_s, $$str(b->capacity()), ", remaining: "_s}));
		$var($String, var$2, $$concat(var$3, $$str(b->remaining())));
		$var($String, var$1, $$concat(var$2, ", size: "));
		$throwNew($AssertionError, $of(($$concat(var$1, $$str(size)))));
	}
	b->position(limit);
	b->limit(pos + remaining + size);
	if (!Http1AsyncReceiver::$assertionsDisabled && !(b->remaining() >= size)) {
		$throwNew($AssertionError, $of($$str({"remaining: "_s, $$str(b->remaining()), ", size: "_s, $$str(size)})));
	}
	int32_t count = 0;
	for (int32_t i = 0; i < $nc(qbb)->length; ++i) {
		$var($ByteBuffer, b2, qbb->get(i));
		int32_t r = $nc(b2)->remaining();
		if (!Http1AsyncReceiver::$assertionsDisabled && !(b->remaining() >= r)) {
			$throwNew($AssertionError, $of($$str({"need at least "_s, $$str(r), " only "_s, $$str(b->remaining()), " available"_s})));
		}
		int32_t copied = $Utils::copy(b2, b);
		if (!Http1AsyncReceiver::$assertionsDisabled && !(copied == r)) {
			$throwNew($AssertionError, $of($$str({"copied="_s, $$str(copied), " available="_s, $$str(r)})));
		}
		if (!Http1AsyncReceiver::$assertionsDisabled && !(b2->remaining() == 0)) {
			$throwNew($AssertionError);
		}
		count += copied;
	}
	if (!Http1AsyncReceiver::$assertionsDisabled && !(count == size)) {
		$throwNew($AssertionError);
	}
	if (!Http1AsyncReceiver::$assertionsDisabled && !(b->position() == pos + remaining + size)) {
		$throwNew($AssertionError, $of($$str({"b.position="_s, $$str(b->position()), " != "_s, $$str(pos), "+"_s, $$str(remaining), "+"_s, $$str(size)})));
	}
	b->limit(limit + size);
	b->position(pos);
	$nc(this->queue)->clear();
	$var($ByteBuffer, bb, b);
	if ($nc(this->debug)->on()) {
		$var($String, var$6, $$str({"Initial buffer now has "_s, $$str(bb->remaining()), " pos="_s}));
		$var($String, var$5, $$concat(var$6, $$str(bb->position())));
		$var($String, var$4, $$concat(var$5, " limit="));
		$nc(this->debug)->log($$concat(var$4, $$str(bb->limit())));
	}
	return b;
}

$String* Http1AsyncReceiver::debugQBB($ByteBufferArray* qbb) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, msg, $new($StringBuilder));
	$var($List, lbb, $Arrays::asList(qbb));
	$var($Set, sbb, $new($HashSet, $(static_cast<$Collection*>($Arrays::asList(qbb)))));
	int32_t uniquebb = sbb->size();
	msg->append("qbb: "_s)->append($nc(lbb)->size())->append(" (unique: "_s)->append(uniquebb)->append("), "_s)->append("duplicates: "_s);
	$var($String, sep, ""_s);
	{
		$var($Iterator, i$, $nc(lbb)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ByteBuffer, b, $cast($ByteBuffer, i$->next()));
			{
				if (!sbb->remove(b)) {
					msg->append(sep)->append($($String::valueOf($of(b))))->append("[remaining="_s)->append($nc(b)->remaining())->append(", position="_s)->append($nc(b)->position())->append(", capacity="_s)->append($nc(b)->capacity())->append("]"_s);
					$assign(sep, ", "_s);
				}
			}
		}
	}
	return msg->toString();
}

$String* Http1AsyncReceiver::dbgString() {
	$useLocalCurrentObjectStackCache();
	$var($String, tag, this->dbgTag);
	if (tag == nullptr) {
		$var($String, flowTag, nullptr);
		$var($Http1Exchange, exchg, this->owner);
		$var($Object, flow, (exchg != nullptr) ? $of($nc($($nc(exchg)->connection()))->getConnectionFlow()) : ($Object*)nullptr);
		$assign(flowTag, ($assign(tag, flow == nullptr ? ($String*)nullptr : ($String::valueOf(flow)))));
		if (flowTag != nullptr) {
			$set(this, dbgTag, ($assign(tag, $str({"Http1AsyncReceiver("_s, flowTag, ")"_s}))));
		} else {
			$assign(tag, "Http1AsyncReceiver(?)"_s);
		}
	}
	return tag;
}

void Http1AsyncReceiver::lambda$handlePendingDelegate$3($Http1AsyncReceiver$Http1AsyncDelegate* pending) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Downstream subscription cancelled by %s"_s, $$new($ObjectArray, {$of(pending)}));
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			setRetryOnError(false);
			$nc(pending)->close(nullptr);
			onReadError($$new($IOException, "subscription cancelled"_s));
			unsubscribe(pending);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$var($Http1Exchange, exchg, this->owner);
			stop();
			if (exchg != nullptr) {
				$nc($(exchg->connection()))->close();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void Http1AsyncReceiver::lambda$handlePendingDelegate$2($Throwable* x) {
	setRetryOnError(false);
	this->stopRequested = true;
	onReadError(x);
}

$String* Http1AsyncReceiver::lambda$checkForErrors$1($Throwable* x, Object$* captured) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $$str({"flushing "_s, x, "\n\t delegate: "_s, captured, "\t\t queue.isEmpty: "_s}));
	return $concat(var$0, $$str($nc(this->queue)->isEmpty()));
}

$String* Http1AsyncReceiver::lambda$flush$0(int64_t remaining) {
	$useLocalCurrentObjectStackCache();
	$var($String, remstr, $nc(this->scheduler)->isStopped() ? ""_s : $str({" remaining in ref: "_s, $$str(remaining)}));
	$plusAssign(remstr, $$str({remstr, " total remaining: "_s, $$str(this->remaining())}));
	return $str({"Delegate done: "_s, $$str(remaining)});
}

void clinit$Http1AsyncReceiver($Class* class$) {
	Http1AsyncReceiver::$assertionsDisabled = !Http1AsyncReceiver::class$->desiredAssertionStatus();
}

Http1AsyncReceiver::Http1AsyncReceiver() {
}

$Class* Http1AsyncReceiver::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Http1AsyncReceiver$$Lambda$dbgString::classInfo$.name)) {
			return Http1AsyncReceiver$$Lambda$dbgString::load$(name, initialize);
		}
		if (name->equals(Http1AsyncReceiver$$Lambda$flush$1::classInfo$.name)) {
			return Http1AsyncReceiver$$Lambda$flush$1::load$(name, initialize);
		}
		if (name->equals(Http1AsyncReceiver$$Lambda$lambda$flush$0$2::classInfo$.name)) {
			return Http1AsyncReceiver$$Lambda$lambda$flush$0$2::load$(name, initialize);
		}
		if (name->equals(Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3::classInfo$.name)) {
			return Http1AsyncReceiver$$Lambda$lambda$checkForErrors$1$3::load$(name, initialize);
		}
		if (name->equals(Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4::classInfo$.name)) {
			return Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$2$4::load$(name, initialize);
		}
		if (name->equals(Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5::classInfo$.name)) {
			return Http1AsyncReceiver$$Lambda$lambda$handlePendingDelegate$3$5::load$(name, initialize);
		}
	}
	$loadClass(Http1AsyncReceiver, name, initialize, &_Http1AsyncReceiver_ClassInfo_, clinit$Http1AsyncReceiver, allocate$Http1AsyncReceiver);
	return class$;
}

$Class* Http1AsyncReceiver::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk