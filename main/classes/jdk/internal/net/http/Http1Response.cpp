#include <jdk/internal/net/http/Http1Response.h>

#include <java/io/EOFException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/Runnable.h>
#include <java/lang/System$Logger$Level.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/net/http/HttpResponse$BodySubscribers.h>
#include <java/net/http/HttpResponse.h>
#include <java/util/Optional.h>
#include <java/util/OptionalLong.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegate.h>
#include <jdk/internal/net/http/Http1AsyncReceiver.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jdk/internal/net/http/Http1HeaderParser.h>
#include <jdk/internal/net/http/Http1Response$1.h>
#include <jdk/internal/net/http/Http1Response$2.h>
#include <jdk/internal/net/http/Http1Response$BodyReader.h>
#include <jdk/internal/net/http/Http1Response$ClientRefCountTracker.h>
#include <jdk/internal/net/http/Http1Response$HeadersReader.h>
#include <jdk/internal/net/http/Http1Response$Http1BodySubscriber.h>
#include <jdk/internal/net/http/Http1Response$Receiver.h>
#include <jdk/internal/net/http/Http1Response$State.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/Response.h>
#include <jdk/internal/net/http/ResponseContent$BodyParser.h>
#include <jdk/internal/net/http/ResponseContent.h>
#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef DEBUG
#undef DONE
#undef HTTP_1_1
#undef INITIAL
#undef MAX_IGNORE
#undef NOP
#undef READING_BODY
#undef READING_HEADERS

using $EOFException = ::java::io::EOFException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $System$Logger = ::java::lang::System$Logger;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpResponse = ::java::net::http::HttpResponse;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $HttpResponse$BodySubscribers = ::java::net::http::HttpResponse$BodySubscribers;
using $Optional = ::java::util::Optional;
using $OptionalLong = ::java::util::OptionalLong;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Executor = ::java::util::concurrent::Executor;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $ExchangeImpl = ::jdk::internal::net::http::ExchangeImpl;
using $Http1AsyncReceiver = ::jdk::internal::net::http::Http1AsyncReceiver;
using $Http1AsyncReceiver$Http1AsyncDelegate = ::jdk::internal::net::http::Http1AsyncReceiver$Http1AsyncDelegate;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;
using $Http1HeaderParser = ::jdk::internal::net::http::Http1HeaderParser;
using $Http1Response$1 = ::jdk::internal::net::http::Http1Response$1;
using $Http1Response$2 = ::jdk::internal::net::http::Http1Response$2;
using $Http1Response$BodyReader = ::jdk::internal::net::http::Http1Response$BodyReader;
using $Http1Response$ClientRefCountTracker = ::jdk::internal::net::http::Http1Response$ClientRefCountTracker;
using $Http1Response$HeadersReader = ::jdk::internal::net::http::Http1Response$HeadersReader;
using $Http1Response$Http1BodySubscriber = ::jdk::internal::net::http::Http1Response$Http1BodySubscriber;
using $Http1Response$Receiver = ::jdk::internal::net::http::Http1Response$Receiver;
using $Http1Response$State = ::jdk::internal::net::http::Http1Response$State;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $Response = ::jdk::internal::net::http::Response;
using $ResponseContent = ::jdk::internal::net::http::ResponseContent;
using $ResponseContent$BodyParser = ::jdk::internal::net::http::ResponseContent$BodyParser;
using $ResponseSubscribers = ::jdk::internal::net::http::ResponseSubscribers;
using $ResponseSubscribers$TrustedSubscriber = ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Http1Response$$Lambda$dbgString : public $Supplier {
	$class(Http1Response$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Http1Response* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Response$$Lambda$dbgString>());
	}
	Http1Response* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Response$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo Http1Response$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Response;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Response$$Lambda$dbgString::*)(Http1Response*)>(&Http1Response$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Response$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Response$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http1Response$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(Http1Response$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Response$$Lambda$dbgString::class$ = nullptr;

class Http1Response$$Lambda$advance$1 : public $Consumer {
	$class(Http1Response$$Lambda$advance$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$(Http1Response* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* previous) override {
		$nc(inst$)->advance($cast($Http1Response$State, previous));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Response$$Lambda$advance$1>());
	}
	Http1Response* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Response$$Lambda$advance$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$advance$1, inst$)},
	{}
};
$MethodInfo Http1Response$$Lambda$advance$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Response;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Response$$Lambda$advance$1::*)(Http1Response*)>(&Http1Response$$Lambda$advance$1::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Response$$Lambda$advance$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Response$$Lambda$advance$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Http1Response$$Lambda$advance$1::load$($String* name, bool initialize) {
	$loadClass(Http1Response$$Lambda$advance$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Response$$Lambda$advance$1::class$ = nullptr;

class Http1Response$$Lambda$lambda$readHeadersAsync$0$2 : public $Function {
	$class(Http1Response$$Lambda$lambda$readHeadersAsync$0$2, $NO_CLASS_INIT, $Function)
public:
	void init$(Http1Response* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* completed) override {
		 return $of($nc(inst$)->lambda$readHeadersAsync$0($cast($Http1Response$State, completed)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Response$$Lambda$lambda$readHeadersAsync$0$2>());
	}
	Http1Response* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Response$$Lambda$lambda$readHeadersAsync$0$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readHeadersAsync$0$2, inst$)},
	{}
};
$MethodInfo Http1Response$$Lambda$lambda$readHeadersAsync$0$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Response;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Response$$Lambda$lambda$readHeadersAsync$0$2::*)(Http1Response*)>(&Http1Response$$Lambda$lambda$readHeadersAsync$0$2::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Response$$Lambda$lambda$readHeadersAsync$0$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Response$$Lambda$lambda$readHeadersAsync$0$2",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Http1Response$$Lambda$lambda$readHeadersAsync$0$2::load$($String* name, bool initialize) {
	$loadClass(Http1Response$$Lambda$lambda$readHeadersAsync$0$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Response$$Lambda$lambda$readHeadersAsync$0$2::class$ = nullptr;

class Http1Response$$Lambda$lambda$readBody$3$3 : public $Runnable {
	$class(Http1Response$$Lambda$lambda$readBody$3$3, $NO_CLASS_INIT, $Runnable)
public:
	void init$(Http1Response* inst, int64_t clen, $Http1Response$Http1BodySubscriber* subscriber, $CompletableFuture* cf, $Http1Response$ClientRefCountTracker* refCountTracker) {
		$set(this, inst$, inst);
		this->clen = clen;
		$set(this, subscriber, subscriber);
		$set(this, cf, cf);
		$set(this, refCountTracker, refCountTracker);
	}
	virtual void run() override {
		$nc(inst$)->lambda$readBody$3(clen, subscriber, cf, refCountTracker);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Response$$Lambda$lambda$readBody$3$3>());
	}
	Http1Response* inst$ = nullptr;
	int64_t clen = 0;
	$Http1Response$Http1BodySubscriber* subscriber = nullptr;
	$CompletableFuture* cf = nullptr;
	$Http1Response$ClientRefCountTracker* refCountTracker = nullptr;
	static $FieldInfo fieldInfos[6];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Response$$Lambda$lambda$readBody$3$3::fieldInfos[6] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readBody$3$3, inst$)},
	{"clen", "J", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readBody$3$3, clen)},
	{"subscriber", "Ljdk/internal/net/http/Http1Response$Http1BodySubscriber;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readBody$3$3, subscriber)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readBody$3$3, cf)},
	{"refCountTracker", "Ljdk/internal/net/http/Http1Response$ClientRefCountTracker;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readBody$3$3, refCountTracker)},
	{}
};
$MethodInfo Http1Response$$Lambda$lambda$readBody$3$3::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Response;JLjdk/internal/net/http/Http1Response$Http1BodySubscriber;Ljava/util/concurrent/CompletableFuture;Ljdk/internal/net/http/Http1Response$ClientRefCountTracker;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Response$$Lambda$lambda$readBody$3$3::*)(Http1Response*,int64_t,$Http1Response$Http1BodySubscriber*,$CompletableFuture*,$Http1Response$ClientRefCountTracker*)>(&Http1Response$$Lambda$lambda$readBody$3$3::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Response$$Lambda$lambda$readBody$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Response$$Lambda$lambda$readBody$3$3",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* Http1Response$$Lambda$lambda$readBody$3$3::load$($String* name, bool initialize) {
	$loadClass(Http1Response$$Lambda$lambda$readBody$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Response$$Lambda$lambda$readBody$3$3::class$ = nullptr;

class Http1Response$$Lambda$lambda$readBody$4$4 : public $Consumer {
	$class(Http1Response$$Lambda$lambda$readBody$4$4, $NO_CLASS_INIT, $Consumer)
public:
	void init$(Http1Response* inst, $CompletableFuture* cf) {
		$set(this, inst$, inst);
		$set(this, cf, cf);
	}
	virtual void accept(Object$* t) override {
		$nc(inst$)->lambda$readBody$4(cf, $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Response$$Lambda$lambda$readBody$4$4>());
	}
	Http1Response* inst$ = nullptr;
	$CompletableFuture* cf = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Response$$Lambda$lambda$readBody$4$4::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readBody$4$4, inst$)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readBody$4$4, cf)},
	{}
};
$MethodInfo Http1Response$$Lambda$lambda$readBody$4$4::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Response;Ljava/util/concurrent/CompletableFuture;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Response$$Lambda$lambda$readBody$4$4::*)(Http1Response*,$CompletableFuture*)>(&Http1Response$$Lambda$lambda$readBody$4$4::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Response$$Lambda$lambda$readBody$4$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Response$$Lambda$lambda$readBody$4$4",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Http1Response$$Lambda$lambda$readBody$4$4::load$($String* name, bool initialize) {
	$loadClass(Http1Response$$Lambda$lambda$readBody$4$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Response$$Lambda$lambda$readBody$4$4::class$ = nullptr;

class Http1Response$$Lambda$lambda$readBody$5$5 : public $BiConsumer {
	$class(Http1Response$$Lambda$lambda$readBody$5$5, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($Http1Response$ClientRefCountTracker* refCountTracker) {
		$set(this, refCountTracker, refCountTracker);
	}
	virtual void accept(Object$* s, Object$* t) override {
		Http1Response::lambda$readBody$5(refCountTracker, s, $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Response$$Lambda$lambda$readBody$5$5>());
	}
	$Http1Response$ClientRefCountTracker* refCountTracker = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Response$$Lambda$lambda$readBody$5$5::fieldInfos[2] = {
	{"refCountTracker", "Ljdk/internal/net/http/Http1Response$ClientRefCountTracker;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readBody$5$5, refCountTracker)},
	{}
};
$MethodInfo Http1Response$$Lambda$lambda$readBody$5$5::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Response$ClientRefCountTracker;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Response$$Lambda$lambda$readBody$5$5::*)($Http1Response$ClientRefCountTracker*)>(&Http1Response$$Lambda$lambda$readBody$5$5::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Response$$Lambda$lambda$readBody$5$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Response$$Lambda$lambda$readBody$5$5",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Http1Response$$Lambda$lambda$readBody$5$5::load$($String* name, bool initialize) {
	$loadClass(Http1Response$$Lambda$lambda$readBody$5$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Response$$Lambda$lambda$readBody$5$5::class$ = nullptr;

class Http1Response$$Lambda$lambda$onReadError$6$6 : public $Supplier {
	$class(Http1Response$$Lambda$lambda$onReadError$6$6, $NO_CLASS_INIT, $Supplier)
public:
	void init$($CompletableFuture* cf) {
		$set(this, cf, cf);
	}
	virtual $Object* get() override {
		 return $of(Http1Response::lambda$onReadError$6(cf));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Response$$Lambda$lambda$onReadError$6$6>());
	}
	$CompletableFuture* cf = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Response$$Lambda$lambda$onReadError$6$6::fieldInfos[2] = {
	{"cf", "Ljava/util/concurrent/CompletableFuture;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$onReadError$6$6, cf)},
	{}
};
$MethodInfo Http1Response$$Lambda$lambda$onReadError$6$6::methodInfos[3] = {
	{"<init>", "(Ljava/util/concurrent/CompletableFuture;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Response$$Lambda$lambda$onReadError$6$6::*)($CompletableFuture*)>(&Http1Response$$Lambda$lambda$onReadError$6$6::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Response$$Lambda$lambda$onReadError$6$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Response$$Lambda$lambda$onReadError$6$6",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http1Response$$Lambda$lambda$onReadError$6$6::load$($String* name, bool initialize) {
	$loadClass(Http1Response$$Lambda$lambda$onReadError$6$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Response$$Lambda$lambda$onReadError$6$6::class$ = nullptr;

class Http1Response$$Lambda$lambda$onReadError$7$7 : public $Supplier {
	$class(Http1Response$$Lambda$lambda$onReadError$7$7, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Throwable* t) {
		$set(this, t, t);
	}
	virtual $Object* get() override {
		 return $of(Http1Response::lambda$onReadError$7(t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Response$$Lambda$lambda$onReadError$7$7>());
	}
	$Throwable* t = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Response$$Lambda$lambda$onReadError$7$7::fieldInfos[2] = {
	{"t", "Ljava/lang/Throwable;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$onReadError$7$7, t)},
	{}
};
$MethodInfo Http1Response$$Lambda$lambda$onReadError$7$7::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Response$$Lambda$lambda$onReadError$7$7::*)($Throwable*)>(&Http1Response$$Lambda$lambda$onReadError$7$7::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Response$$Lambda$lambda$onReadError$7$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Response$$Lambda$lambda$onReadError$7$7",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http1Response$$Lambda$lambda$onReadError$7$7::load$($String* name, bool initialize) {
	$loadClass(Http1Response$$Lambda$lambda$onReadError$7$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Response$$Lambda$lambda$onReadError$7$7::class$ = nullptr;

class Http1Response$$Lambda$onFinished$8 : public $Runnable {
	$class(Http1Response$$Lambda$onFinished$8, $NO_CLASS_INIT, $Runnable)
public:
	void init$(Http1Response* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->onFinished();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Response$$Lambda$onFinished$8>());
	}
	Http1Response* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Response$$Lambda$onFinished$8::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$onFinished$8, inst$)},
	{}
};
$MethodInfo Http1Response$$Lambda$onFinished$8::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Response;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Response$$Lambda$onFinished$8::*)(Http1Response*)>(&Http1Response$$Lambda$onFinished$8::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Response$$Lambda$onFinished$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Response$$Lambda$onFinished$8",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* Http1Response$$Lambda$onFinished$8::load$($String* name, bool initialize) {
	$loadClass(Http1Response$$Lambda$onFinished$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Response$$Lambda$onFinished$8::class$ = nullptr;

class Http1Response$$Lambda$lambda$readBody$1$9 : public $Consumer {
	$class(Http1Response$$Lambda$lambda$readBody$1$9, $NO_CLASS_INIT, $Consumer)
public:
	void init$(Http1Response* inst, $Http1Response$Http1BodySubscriber* subscriber, $CompletableFuture* cf) {
		$set(this, inst$, inst);
		$set(this, subscriber, subscriber);
		$set(this, cf, cf);
	}
	virtual void accept(Object$* t) override {
		$nc(inst$)->lambda$readBody$1(subscriber, cf, $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Response$$Lambda$lambda$readBody$1$9>());
	}
	Http1Response* inst$ = nullptr;
	$Http1Response$Http1BodySubscriber* subscriber = nullptr;
	$CompletableFuture* cf = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Response$$Lambda$lambda$readBody$1$9::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readBody$1$9, inst$)},
	{"subscriber", "Ljdk/internal/net/http/Http1Response$Http1BodySubscriber;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readBody$1$9, subscriber)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readBody$1$9, cf)},
	{}
};
$MethodInfo Http1Response$$Lambda$lambda$readBody$1$9::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Response;Ljdk/internal/net/http/Http1Response$Http1BodySubscriber;Ljava/util/concurrent/CompletableFuture;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Response$$Lambda$lambda$readBody$1$9::*)(Http1Response*,$Http1Response$Http1BodySubscriber*,$CompletableFuture*)>(&Http1Response$$Lambda$lambda$readBody$1$9::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Response$$Lambda$lambda$readBody$1$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Response$$Lambda$lambda$readBody$1$9",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Http1Response$$Lambda$lambda$readBody$1$9::load$($String* name, bool initialize) {
	$loadClass(Http1Response$$Lambda$lambda$readBody$1$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Response$$Lambda$lambda$readBody$1$9::class$ = nullptr;

class Http1Response$$Lambda$lambda$readBody$2$10 : public $BiConsumer {
	$class(Http1Response$$Lambda$lambda$readBody$2$10, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(Http1Response* inst, $Http1Response$Http1BodySubscriber* subscriber, $CompletableFuture* cf, $Http1Response$ClientRefCountTracker* refCountTracker) {
		$set(this, inst$, inst);
		$set(this, subscriber, subscriber);
		$set(this, cf, cf);
		$set(this, refCountTracker, refCountTracker);
	}
	virtual void accept(Object$* s, Object$* t) override {
		$nc(inst$)->lambda$readBody$2(subscriber, cf, refCountTracker, $cast($Http1Response$State, s), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Response$$Lambda$lambda$readBody$2$10>());
	}
	Http1Response* inst$ = nullptr;
	$Http1Response$Http1BodySubscriber* subscriber = nullptr;
	$CompletableFuture* cf = nullptr;
	$Http1Response$ClientRefCountTracker* refCountTracker = nullptr;
	static $FieldInfo fieldInfos[5];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Response$$Lambda$lambda$readBody$2$10::fieldInfos[5] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readBody$2$10, inst$)},
	{"subscriber", "Ljdk/internal/net/http/Http1Response$Http1BodySubscriber;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readBody$2$10, subscriber)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readBody$2$10, cf)},
	{"refCountTracker", "Ljdk/internal/net/http/Http1Response$ClientRefCountTracker;", nullptr, $PUBLIC, $field(Http1Response$$Lambda$lambda$readBody$2$10, refCountTracker)},
	{}
};
$MethodInfo Http1Response$$Lambda$lambda$readBody$2$10::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Response;Ljdk/internal/net/http/Http1Response$Http1BodySubscriber;Ljava/util/concurrent/CompletableFuture;Ljdk/internal/net/http/Http1Response$ClientRefCountTracker;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Response$$Lambda$lambda$readBody$2$10::*)(Http1Response*,$Http1Response$Http1BodySubscriber*,$CompletableFuture*,$Http1Response$ClientRefCountTracker*)>(&Http1Response$$Lambda$lambda$readBody$2$10::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Response$$Lambda$lambda$readBody$2$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Response$$Lambda$lambda$readBody$2$10",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Http1Response$$Lambda$lambda$readBody$2$10::load$($String* name, bool initialize) {
	$loadClass(Http1Response$$Lambda$lambda$readBody$2$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Response$$Lambda$lambda$readBody$2$10::class$ = nullptr;

$FieldInfo _Http1Response_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http1Response, $assertionsDisabled)},
	{"content", "Ljdk/internal/net/http/ResponseContent;", nullptr, $PRIVATE | $VOLATILE, $field(Http1Response, content)},
	{"request", "Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PRIVATE | $FINAL, $field(Http1Response, request)},
	{"response", "Ljdk/internal/net/http/Response;", nullptr, $PRIVATE, $field(Http1Response, response)},
	{"connection", "Ljdk/internal/net/http/HttpConnection;", nullptr, $PRIVATE | $FINAL, $field(Http1Response, connection)},
	{"headers", "Ljava/net/http/HttpHeaders;", nullptr, $PRIVATE, $field(Http1Response, headers)},
	{"responseCode", "I", nullptr, $PRIVATE, $field(Http1Response, responseCode$)},
	{"exchange", "Ljdk/internal/net/http/Http1Exchange;", "Ljdk/internal/net/http/Http1Exchange<TT;>;", $PRIVATE | $FINAL, $field(Http1Response, exchange)},
	{"return2Cache", "Z", nullptr, $PRIVATE, $field(Http1Response, return2Cache)},
	{"headersReader", "Ljdk/internal/net/http/Http1Response$HeadersReader;", "Ljdk/internal/net/http/Http1Response<TT;>.HeadersReader;", $PRIVATE | $FINAL, $field(Http1Response, headersReader)},
	{"bodyReader", "Ljdk/internal/net/http/Http1Response$BodyReader;", "Ljdk/internal/net/http/Http1Response<TT;>.BodyReader;", $PRIVATE | $FINAL, $field(Http1Response, bodyReader)},
	{"asyncReceiver", "Ljdk/internal/net/http/Http1AsyncReceiver;", nullptr, $PRIVATE | $FINAL, $field(Http1Response, asyncReceiver)},
	{"eof", "Ljava/io/EOFException;", nullptr, $PRIVATE | $VOLATILE, $field(Http1Response, eof)},
	{"bodyParser", "Ljdk/internal/net/http/ResponseContent$BodyParser;", nullptr, $PRIVATE | $VOLATILE, $field(Http1Response, bodyParser)},
	{"MAX_IGNORE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Http1Response, MAX_IGNORE)},
	{"readProgress", "Ljdk/internal/net/http/Http1Response$State;", nullptr, $PRIVATE | $VOLATILE, $field(Http1Response, readProgress)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(Http1Response, debug)},
	{"responseCount", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $STATIC | $FINAL, $staticField(Http1Response, responseCount)},
	{"id", "J", nullptr, $FINAL, $field(Http1Response, id)},
	{"hd", "Ljdk/internal/net/http/Http1HeaderParser;", nullptr, $PRIVATE, $field(Http1Response, hd)},
	{"dbgTag", "Ljava/lang/String;", nullptr, 0, $field(Http1Response, dbgTag)},
	{"firstTimeAround", "Z", nullptr, $PRIVATE | $VOLATILE, $field(Http1Response, firstTimeAround)},
	{"finished", "Z", nullptr, $PRIVATE, $field(Http1Response, finished$)},
	{"NOP", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $STATIC | $FINAL, $staticField(Http1Response, NOP)},
	{}
};

$MethodInfo _Http1Response_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpConnection;Ljdk/internal/net/http/Http1Exchange;Ljdk/internal/net/http/Http1AsyncReceiver;)V", "(Ljdk/internal/net/http/HttpConnection;Ljdk/internal/net/http/Http1Exchange<TT;>;Ljdk/internal/net/http/Http1AsyncReceiver;)V", 0, $method(static_cast<void(Http1Response::*)($HttpConnection*,$Http1Exchange*,$Http1AsyncReceiver*)>(&Http1Response::init$))},
	{"advance", "(Ljdk/internal/net/http/Http1Response$State;)Ljdk/internal/net/http/Http1Response$State;", nullptr, $PRIVATE, $method(static_cast<$Http1Response$State*(Http1Response::*)($Http1Response$State*)>(&Http1Response::advance))},
	{"completed", "()V", nullptr, $SYNCHRONIZED},
	{"dbgString", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(Http1Response::*)()>(&Http1Response::dbgString))},
	{"finished", "()Z", nullptr, $SYNCHRONIZED},
	{"fixupContentLen", "(J)J", nullptr, 0},
	{"ignoreBody", "(Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC},
	{"lambda$onReadError$6", "(Ljava/util/concurrent/CompletableFuture;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($CompletableFuture*)>(&Http1Response::lambda$onReadError$6))},
	{"lambda$onReadError$7", "(Ljava/lang/Throwable;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($Throwable*)>(&Http1Response::lambda$onReadError$7))},
	{"lambda$readBody$1", "(Ljdk/internal/net/http/Http1Response$Http1BodySubscriber;Ljava/util/concurrent/CompletableFuture;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Http1Response::*)($Http1Response$Http1BodySubscriber*,$CompletableFuture*,$Throwable*)>(&Http1Response::lambda$readBody$1))},
	{"lambda$readBody$2", "(Ljdk/internal/net/http/Http1Response$Http1BodySubscriber;Ljava/util/concurrent/CompletableFuture;Ljdk/internal/net/http/Http1Response$ClientRefCountTracker;Ljdk/internal/net/http/Http1Response$State;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Http1Response::*)($Http1Response$Http1BodySubscriber*,$CompletableFuture*,$Http1Response$ClientRefCountTracker*,$Http1Response$State*,$Throwable*)>(&Http1Response::lambda$readBody$2))},
	{"lambda$readBody$3", "(JLjdk/internal/net/http/Http1Response$Http1BodySubscriber;Ljava/util/concurrent/CompletableFuture;Ljdk/internal/net/http/Http1Response$ClientRefCountTracker;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Http1Response::*)(int64_t,$Http1Response$Http1BodySubscriber*,$CompletableFuture*,$Http1Response$ClientRefCountTracker*)>(&Http1Response::lambda$readBody$3))},
	{"lambda$readBody$4", "(Ljava/util/concurrent/CompletableFuture;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Http1Response::*)($CompletableFuture*,$Throwable*)>(&Http1Response::lambda$readBody$4))},
	{"lambda$readBody$5", "(Ljdk/internal/net/http/Http1Response$ClientRefCountTracker;Ljava/lang/Object;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($Http1Response$ClientRefCountTracker*,Object$*,$Throwable*)>(&Http1Response::lambda$readBody$5))},
	{"lambda$readHeadersAsync$0", "(Ljdk/internal/net/http/Http1Response$State;)Ljdk/internal/net/http/Response;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$Response*(Http1Response::*)($Http1Response$State*)>(&Http1Response::lambda$readHeadersAsync$0))},
	{"nullBody", "(Ljava/net/http/HttpResponse;Ljava/lang/Throwable;)V", "(Ljava/net/http/HttpResponse<TT;>;Ljava/lang/Throwable;)V", $PUBLIC},
	{"onFinished", "()V", nullptr, $PRIVATE, $method(static_cast<void(Http1Response::*)()>(&Http1Response::onFinished))},
	{"onReadError", "(Ljava/lang/Throwable;)V", nullptr, 0},
	{"readBody", "(Ljava/net/http/HttpResponse$BodySubscriber;ZLjava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/net/http/HttpResponse$BodySubscriber<TU;>;ZLjava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC},
	{"readHeadersAsync", "(Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", $PUBLIC},
	{"receiver", "(Ljdk/internal/net/http/Http1Response$State;)Ljdk/internal/net/http/Http1Response$Receiver;", "(Ljdk/internal/net/http/Http1Response$State;)Ljdk/internal/net/http/Http1Response$Receiver<*>;", 0},
	{"responseCode", "()I", nullptr, 0},
	{"responseHeaders", "()Ljava/net/http/HttpHeaders;", nullptr, 0},
	{}
};

$InnerClassInfo _Http1Response_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Response$2", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"jdk.internal.net.http.Http1Response$BodyReader", "jdk.internal.net.http.Http1Response", "BodyReader", $FINAL},
	{"jdk.internal.net.http.Http1Response$HeadersReader", "jdk.internal.net.http.Http1Response", "HeadersReader", $FINAL},
	{"jdk.internal.net.http.Http1Response$Receiver", "jdk.internal.net.http.Http1Response", "Receiver", $STATIC | $ABSTRACT},
	{"jdk.internal.net.http.Http1Response$Http1BodySubscriber", "jdk.internal.net.http.Http1Response", "Http1BodySubscriber", $STATIC | $FINAL},
	{"jdk.internal.net.http.Http1Response$ClientRefCountTracker", "jdk.internal.net.http.Http1Response", "ClientRefCountTracker", $PRIVATE | $FINAL},
	{"jdk.internal.net.http.Http1Response$State", "jdk.internal.net.http.Http1Response", "State", $STATIC | $FINAL | $ENUM},
	{"jdk.internal.net.http.Http1Response$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Http1Response_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.Http1Response",
	"java.lang.Object",
	nullptr,
	_Http1Response_FieldInfo_,
	_Http1Response_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	_Http1Response_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Response$2,jdk.internal.net.http.Http1Response$BodyReader,jdk.internal.net.http.Http1Response$HeadersReader,jdk.internal.net.http.Http1Response$Receiver,jdk.internal.net.http.Http1Response$Http1BodySubscriber,jdk.internal.net.http.Http1Response$ClientRefCountTracker,jdk.internal.net.http.Http1Response$State,jdk.internal.net.http.Http1Response$1"
};

$Object* allocate$Http1Response($Class* clazz) {
	return $of($alloc(Http1Response));
}

bool Http1Response::$assertionsDisabled = false;
$AtomicLong* Http1Response::responseCount = nullptr;
$Flow$Subscription* Http1Response::NOP = nullptr;

void Http1Response::init$($HttpConnection* conn, $Http1Exchange* exchange, $Http1AsyncReceiver* asyncReceiver) {
	$useLocalCurrentObjectStackCache();
	$init($Http1Response$State);
	$set(this, readProgress, $Http1Response$State::INITIAL);
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(Http1Response$$Lambda$dbgString, this)), $Utils::DEBUG));
	this->id = $nc(Http1Response::responseCount)->incrementAndGet();
	this->firstTimeAround = true;
	$set(this, readProgress, $Http1Response$State::INITIAL);
	$set(this, request, $nc(exchange)->request());
	$set(this, exchange, exchange);
	$set(this, connection, conn);
	$set(this, asyncReceiver, asyncReceiver);
	$set(this, headersReader, $new($Http1Response$HeadersReader, this, static_cast<$Consumer*>($$new(Http1Response$$Lambda$advance$1, this))));
	$set(this, bodyReader, $new($Http1Response$BodyReader, this, static_cast<$Consumer*>($$new(Http1Response$$Lambda$advance$1, this))));
	$set(this, hd, $new($Http1HeaderParser));
	$set(this, readProgress, $Http1Response$State::READING_HEADERS);
	$nc(this->headersReader)->start(this->hd);
	$nc(asyncReceiver)->subscribe(this->headersReader);
}

$String* Http1Response::dbgString() {
	$useLocalCurrentObjectStackCache();
	$var($String, dbg, this->dbgTag);
	if (dbg == nullptr) {
		$var($String, cdbg, $nc(this->connection)->dbgTag);
		if (cdbg != nullptr) {
			$set(this, dbgTag, ($assign(dbg, $str({"Http1Response(id="_s, $$str(this->id), ", "_s, cdbg, ")"_s}))));
		} else {
			$assign(dbg, $str({"Http1Response(id="_s, $$str(this->id), ")"_s}));
		}
	}
	return dbg;
}

$CompletableFuture* Http1Response::readHeadersAsync($Executor* executor) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log($$str({"Reading Headers: (remaining: "_s, $$str($nc(this->asyncReceiver)->remaining()), ") "_s, this->readProgress}));
	}
	if (this->firstTimeAround) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("First time around"_s);
		}
		this->firstTimeAround = false;
	} else {
		$nc(this->asyncReceiver)->unsubscribe(this->bodyReader);
		$nc(this->bodyReader)->reset();
		$set(this, hd, $new($Http1HeaderParser));
		$init($Http1Response$State);
		$set(this, readProgress, $Http1Response$State::READING_HEADERS);
		$nc(this->headersReader)->reset();
		$nc(this->headersReader)->start(this->hd);
		$nc(this->asyncReceiver)->subscribe(this->headersReader);
	}
	$var($CompletableFuture, cf, $nc(this->headersReader)->completion());
	if (!Http1Response::$assertionsDisabled && !(cf != nullptr)) {
		$throwNew($AssertionError, $of("parsing not started"_s));
	}
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("headersReader is %s"_s, $$new($ObjectArray, {cf == nullptr ? $of("not yet started"_s) : $nc(cf)->isDone() ? $of("already completed"_s) : $of("not yet completed"_s)}));
	}
	$var($Function, lambda, static_cast<$Function*>($new(Http1Response$$Lambda$lambda$readHeadersAsync$0$2, this)));
	if (executor != nullptr) {
		return $cast($CompletableFuture, $nc(cf)->thenApplyAsync(lambda, executor));
	} else {
		return $cast($CompletableFuture, $nc(cf)->thenApply(lambda));
	}
}

void Http1Response::completed() {
	$synchronized(this) {
		this->finished$ = true;
	}
}

bool Http1Response::finished() {
	$synchronized(this) {
		return this->finished$;
	}
}

int64_t Http1Response::fixupContentLen(int64_t clen) {
	$useLocalCurrentObjectStackCache();
	if ($nc($($nc(this->request)->method()))->equalsIgnoreCase("HEAD"_s) || this->responseCode$ == 304) {
		return 0;
	}
	if (clen == (int64_t)-1) {
		if ($nc(($cast($String, $($nc($($nc(this->headers)->firstValue("Transfer-encoding"_s)))->orElse(""_s)))))->equalsIgnoreCase("chunked"_s)) {
			return -1;
		}
		if (this->responseCode$ == 101) {
			return 0;
		}
		return -2;
	}
	return clen;
}

$CompletableFuture* Http1Response::ignoreBody($Executor* executor) {
	$useLocalCurrentObjectStackCache();
	int32_t clen = (int32_t)$nc($($nc(this->headers)->firstValueAsLong("Content-Length"_s)))->orElse(-1);
	if (clen == -1 || clen > Http1Response::MAX_IGNORE) {
		$nc(this->connection)->close();
		return $MinimalFuture::completedFuture(nullptr);
	} else {
		$var($HttpResponse$BodySubscriber, var$0, $HttpResponse$BodySubscribers::discarding());
		return readBody(var$0, !$nc(this->request)->isWebSocket(), executor);
	}
}

void Http1Response::nullBody($HttpResponse* resp, $Throwable* t) {
	if (t != nullptr) {
		$nc(this->connection)->close();
	} else {
		this->return2Cache = !$nc(this->request)->isWebSocket();
		onFinished();
	}
}

$CompletableFuture* Http1Response::readBody($HttpResponse$BodySubscriber* p, bool return2Cache, $Executor* executor) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log($$str({"readBody: return2Cache: "_s, $$str(return2Cache)}));
		if ($nc(this->request)->isWebSocket() && return2Cache && this->connection != nullptr) {
			$nc(this->debug)->log($$str({"websocket connection will be returned to cache: "_s, $nc($of(this->connection))->getClass(), "/"_s, this->connection}));
		}
	}
	if (!Http1Response::$assertionsDisabled && !(!return2Cache || !$nc(this->request)->isWebSocket())) {
		$throwNew($AssertionError);
	}
	this->return2Cache = return2Cache;
	$var($Http1Response$Http1BodySubscriber, subscriber, $new($Http1Response$Http1BodySubscriber, p));
	$var($CompletableFuture, cf, $new($MinimalFuture));
	int64_t clen0 = $nc($($nc(this->headers)->firstValueAsLong("Content-Length"_s)))->orElse(-1);
	int64_t clen = fixupContentLen(clen0);
	$nc(this->asyncReceiver)->unsubscribe(this->headersReader);
	$nc(this->headersReader)->reset();
	$var($Http1Response$ClientRefCountTracker, refCountTracker, $new($Http1Response$ClientRefCountTracker, this));
	$nc($($nc(this->connection)->client()))->reference();
	$nc(executor)->execute(static_cast<$Runnable*>($$new(Http1Response$$Lambda$lambda$readBody$3$3, this, clen, subscriber, cf, refCountTracker)));
	$ResponseSubscribers::getBodyAsync(executor, p, cf, static_cast<$Consumer*>($$new(Http1Response$$Lambda$lambda$readBody$4$4, this, cf)));
	return $cast($CompletableFuture, cf->whenComplete(static_cast<$BiConsumer*>($$new(Http1Response$$Lambda$lambda$readBody$5$5, refCountTracker))));
}

void Http1Response::onFinished() {
	$useLocalCurrentObjectStackCache();
	$nc(this->asyncReceiver)->clear();
	if (this->return2Cache) {
		$Log::logTrace("Attempting to return connection to the pool: {0}"_s, $$new($ObjectArray, {$of(this->connection)}));
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log($$str({$($nc(this->connection)->getConnectionFlow()), ": return to HTTP/1.1 pool"_s}));
		}
		$nc(this->connection)->closeOrReturnToCache(this->eof == nullptr ? this->headers : ($HttpHeaders*)nullptr);
	}
}

$HttpHeaders* Http1Response::responseHeaders() {
	return this->headers;
}

int32_t Http1Response::responseCode() {
	return this->responseCode$;
}

void Http1Response::onReadError($Throwable* t) {
	$useLocalCurrentObjectStackCache();
	$Log::logError(t);
	$var($Http1Response$Receiver, receiver, this->receiver(this->readProgress));
	if ($instanceOf($EOFException, t)) {
		$init($System$Logger$Level);
		$nc(this->debug)->log($System$Logger$Level::DEBUG, "onReadError: received EOF"_s);
		$set(this, eof, $cast($EOFException, t));
	}
	$var($CompletableFuture, cf, receiver == nullptr ? ($CompletableFuture*)nullptr : $nc(receiver)->completion());
	$init($System$Logger$Level);
	$nc(this->debug)->log($System$Logger$Level::DEBUG, static_cast<$Supplier*>($$new(Http1Response$$Lambda$lambda$onReadError$6$6, cf)));
	if (cf != nullptr) {
		cf->completeExceptionally(t);
	} else {
		$nc(this->debug)->log($System$Logger$Level::DEBUG, "onReadError"_s, t);
	}
	$nc(this->debug)->log($System$Logger$Level::DEBUG, static_cast<$Supplier*>($$new(Http1Response$$Lambda$lambda$onReadError$7$7, t)));
	$nc(this->connection)->close();
}

$Http1Response$State* Http1Response::advance($Http1Response$State* previous) {
	if (!Http1Response::$assertionsDisabled && !(this->readProgress == previous)) {
		$throwNew($AssertionError);
	}
	$init($Http1Response$2);
	switch ($nc($Http1Response$2::$SwitchMap$jdk$internal$net$http$Http1Response$State)->get($nc((previous))->ordinal())) {
	case 1:
		{
			$nc(this->asyncReceiver)->unsubscribe(this->headersReader);
			$init($Http1Response$State);
			return $set(this, readProgress, $Http1Response$State::READING_BODY);
		}
	case 2:
		{
			$nc(this->asyncReceiver)->unsubscribe(this->bodyReader);
			$init($Http1Response$State);
			return $set(this, readProgress, $Http1Response$State::DONE);
		}
	default:
		{
			$throwNew($InternalError, $$str({"can\'t advance from "_s, previous}));
		}
	}
}

$Http1Response$Receiver* Http1Response::receiver($Http1Response$State* state) {
	$init($Http1Response$2);

	$var($Http1Response$Receiver, var$0, nullptr)
	switch ($nc($Http1Response$2::$SwitchMap$jdk$internal$net$http$Http1Response$State)->get($nc((state))->ordinal())) {
	case 1:
		{
			$assign(var$0, this->headersReader);
			break;
		}
	case 2:
		{
			$assign(var$0, this->bodyReader);
			break;
		}
	default:
		{
			$assign(var$0, nullptr);
			break;
		}
	}
	return var$0;
}

$String* Http1Response::lambda$onReadError$7($Throwable* t) {
	$init(Http1Response);
	return $str({"closing connection: cause is "_s, t});
}

$String* Http1Response::lambda$onReadError$6($CompletableFuture* cf) {
	$init(Http1Response);
	return $str({"onReadError: cf is "_s, (cf == nullptr ? "null"_s : ($nc(cf)->isDone() ? "already completed"_s : "not yet completed"_s))});
}

void Http1Response::lambda$readBody$5($Http1Response$ClientRefCountTracker* refCountTracker, Object$* s, $Throwable* t) {
	$init(Http1Response);
	if (t != nullptr) {
		$nc(refCountTracker)->tryRelease();
	}
}

void Http1Response::lambda$readBody$4($CompletableFuture* cf, $Throwable* t) {
	$nc(cf)->completeExceptionally(t);
	$nc(this->asyncReceiver)->setRetryOnError(false);
	$nc(this->asyncReceiver)->onReadError(t);
}

void Http1Response::lambda$readBody$3(int64_t clen, $Http1Response$Http1BodySubscriber* subscriber, $CompletableFuture* cf, $Http1Response$ClientRefCountTracker* refCountTracker) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				$set(this, content, $new($ResponseContent, this->connection, clen, this->headers, subscriber, static_cast<$Runnable*>($$new(Http1Response$$Lambda$onFinished$8, this))));
				if ($nc(cf)->isCompletedExceptionally()) {
					$nc(this->connection)->close();
					return$1 = true;
					goto $finally;
				}
				$nc(refCountTracker)->acquire();
				$set(this, bodyParser, $nc(this->content)->getBodyParser(static_cast<$Consumer*>($$new(Http1Response$$Lambda$lambda$readBody$1$9, this, subscriber, cf))));
				$nc(this->bodyReader)->start(this->bodyParser);
				$var($CompletableFuture, bodyReaderCF, $nc(this->bodyReader)->completion());
				$nc(this->asyncReceiver)->subscribe(this->bodyReader);
				if (!Http1Response::$assertionsDisabled && !(bodyReaderCF != nullptr)) {
					$throwNew($AssertionError, $of("parsing not started"_s));
				}
				$var($CompletableFuture, trailingOp, $cast($CompletableFuture, $nc(bodyReaderCF)->whenComplete(static_cast<$BiConsumer*>($$new(Http1Response$$Lambda$lambda$readBody$2$10, this, subscriber, cf, refCountTracker)))));
				$nc(this->connection)->addTrailingOperation(trailingOp);
			} catch ($Throwable& t) {
				if ($nc(this->debug)->on()) {
					$nc(this->debug)->log($$str({"Failed reading body: "_s, t}));
				}
				{
					$var($Throwable, var$2, nullptr);
					try {
						$nc(subscriber)->onError(t);
						$nc(cf)->completeExceptionally(t);
					} catch ($Throwable& var$3) {
						$assign(var$2, var$3);
					} /*finally*/ {
						$nc(this->asyncReceiver)->onReadError(t);
					}
					if (var$2 != nullptr) {
						$throw(var$2);
					}
				}
			}
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			$nc($($nc(this->connection)->client()))->unreference();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

void Http1Response::lambda$readBody$2($Http1Response$Http1BodySubscriber* subscriber, $CompletableFuture* cf, $Http1Response$ClientRefCountTracker* refCountTracker, $Http1Response$State* s, $Throwable* t$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, t, t$renamed);
	$assign(t, $Utils::getCompletionCause(t));
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				if (t == nullptr) {
					if ($nc(this->debug)->on()) {
						$nc(this->debug)->log($$str({"Finished reading body: "_s, s}));
					}
					$init($Http1Response$State);
					if (!Http1Response::$assertionsDisabled && !(s == $Http1Response$State::READING_BODY)) {
						$throwNew($AssertionError);
					}
				}
				if (t != nullptr) {
					$nc(subscriber)->onError(t);
					$nc(cf)->completeExceptionally(t);
				}
			} catch ($Throwable& x) {
				$nc(this->asyncReceiver)->onReadError(x);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(refCountTracker)->tryRelease();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void Http1Response::lambda$readBody$1($Http1Response$Http1BodySubscriber* subscriber, $CompletableFuture* cf, $Throwable* t) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (t != nullptr) {
				{
					$var($Throwable, var$1, nullptr);
					try {
						$nc(subscriber)->onError(t);
					} catch ($Throwable& var$2) {
						$assign(var$1, var$2);
					} /*finally*/ {
						$nc(cf)->completeExceptionally(t);
					}
					if (var$1 != nullptr) {
						$throw(var$1);
					}
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			$nc(this->bodyReader)->onComplete(t);
			if (t != nullptr) {
				$nc(this->connection)->close();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$Response* Http1Response::lambda$readHeadersAsync$0($Http1Response$State* completed) {
	$useLocalCurrentObjectStackCache();
	$init($Http1Response$State);
	if (!Http1Response::$assertionsDisabled && !(completed == $Http1Response$State::READING_HEADERS)) {
		$throwNew($AssertionError);
	}
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log($$str({"Reading Headers: creating Response object; state is now "_s, this->readProgress}));
	}
	$nc(this->asyncReceiver)->unsubscribe(this->headersReader);
	this->responseCode$ = $nc(this->hd)->responseCode();
	$set(this, headers, $nc(this->hd)->headers());
	$init($HttpClient$Version);
	$set(this, response, $new($Response, this->request, $($nc(this->exchange)->getExchange()), this->headers, this->connection, this->responseCode$, $HttpClient$Version::HTTP_1_1));
	if ($Log::headers()) {
		$var($StringBuilder, sb, $new($StringBuilder, "RESPONSE HEADERS:\n"_s));
		$Log::dumpHeaders(sb, "    "_s, this->headers);
		$Log::logHeaders($(sb->toString()), $$new($ObjectArray, 0));
	}
	return this->response;
}

void clinit$Http1Response($Class* class$) {
	Http1Response::$assertionsDisabled = !Http1Response::class$->desiredAssertionStatus();
	$assignStatic(Http1Response::responseCount, $new($AtomicLong));
	$assignStatic(Http1Response::NOP, $new($Http1Response$1));
}

Http1Response::Http1Response() {
}

$Class* Http1Response::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Http1Response$$Lambda$dbgString::classInfo$.name)) {
			return Http1Response$$Lambda$dbgString::load$(name, initialize);
		}
		if (name->equals(Http1Response$$Lambda$advance$1::classInfo$.name)) {
			return Http1Response$$Lambda$advance$1::load$(name, initialize);
		}
		if (name->equals(Http1Response$$Lambda$lambda$readHeadersAsync$0$2::classInfo$.name)) {
			return Http1Response$$Lambda$lambda$readHeadersAsync$0$2::load$(name, initialize);
		}
		if (name->equals(Http1Response$$Lambda$lambda$readBody$3$3::classInfo$.name)) {
			return Http1Response$$Lambda$lambda$readBody$3$3::load$(name, initialize);
		}
		if (name->equals(Http1Response$$Lambda$lambda$readBody$4$4::classInfo$.name)) {
			return Http1Response$$Lambda$lambda$readBody$4$4::load$(name, initialize);
		}
		if (name->equals(Http1Response$$Lambda$lambda$readBody$5$5::classInfo$.name)) {
			return Http1Response$$Lambda$lambda$readBody$5$5::load$(name, initialize);
		}
		if (name->equals(Http1Response$$Lambda$lambda$onReadError$6$6::classInfo$.name)) {
			return Http1Response$$Lambda$lambda$onReadError$6$6::load$(name, initialize);
		}
		if (name->equals(Http1Response$$Lambda$lambda$onReadError$7$7::classInfo$.name)) {
			return Http1Response$$Lambda$lambda$onReadError$7$7::load$(name, initialize);
		}
		if (name->equals(Http1Response$$Lambda$onFinished$8::classInfo$.name)) {
			return Http1Response$$Lambda$onFinished$8::load$(name, initialize);
		}
		if (name->equals(Http1Response$$Lambda$lambda$readBody$1$9::classInfo$.name)) {
			return Http1Response$$Lambda$lambda$readBody$1$9::load$(name, initialize);
		}
		if (name->equals(Http1Response$$Lambda$lambda$readBody$2$10::classInfo$.name)) {
			return Http1Response$$Lambda$lambda$readBody$2$10::load$(name, initialize);
		}
	}
	$loadClass(Http1Response, name, initialize, &_Http1Response_ClassInfo_, clinit$Http1Response, allocate$Http1Response);
	return class$;
}

$Class* Http1Response::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk