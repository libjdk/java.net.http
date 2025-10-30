#include <jdk/internal/net/http/MultiExchange.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/ConnectException.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/SocketException.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpConnectTimeoutException.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpRequest.h>
#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/net/http/HttpResponse$PushPromiseHandler.h>
#include <java/net/http/HttpResponse$ResponseInfo.h>
#include <java/net/http/HttpResponse.h>
#include <java/net/http/HttpTimeoutException.h>
#include <java/security/AccessControlContext.h>
#include <java/time/Duration.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/Optional.h>
#include <java/util/OptionalLong.h>
#include <java/util/concurrent/CancellationException.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionException.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/ExecutionException.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicInteger.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/AuthenticationFilter$AuthInfo.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/ExchangeImpl.h>
#include <jdk/internal/net/http/HeaderFilter.h>
#include <jdk/internal/net/http/HttpClientImpl$DelegatingExecutor.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/HttpResponseImpl.h>
#include <jdk/internal/net/http/MultiExchange$CancelableRef.h>
#include <jdk/internal/net/http/MultiExchange$ConnectTimeoutTracker.h>
#include <jdk/internal/net/http/MultiExchange$NullSubscription.h>
#include <jdk/internal/net/http/PrivilegedExecutor.h>
#include <jdk/internal/net/http/PushGroup.h>
#include <jdk/internal/net/http/Response.h>
#include <jdk/internal/net/http/ResponseInfoImpl.h>
#include <jdk/internal/net/http/ResponseSubscribers.h>
#include <jdk/internal/net/http/ResponseTimerEvent.h>
#include <jdk/internal/net/http/TimeoutEvent.h>
#include <jdk/internal/net/http/common/Cancelable.h>
#include <jdk/internal/net/http/common/ConnectionExpiredException.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef DEBUG
#undef DEFAULT_MAX_ATTEMPTS
#undef HTTP_1_1
#undef HTTP_2
#undef RETRY_ALWAYS
#undef RETRY_CONNECT

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ConnectException = ::java::net::ConnectException;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $SocketException = ::java::net::SocketException;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpConnectTimeoutException = ::java::net::http::HttpConnectTimeoutException;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpResponse = ::java::net::http::HttpResponse;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $HttpResponse$PushPromiseHandler = ::java::net::http::HttpResponse$PushPromiseHandler;
using $HttpResponse$ResponseInfo = ::java::net::http::HttpResponse$ResponseInfo;
using $HttpTimeoutException = ::java::net::http::HttpTimeoutException;
using $AccessControlContext = ::java::security::AccessControlContext;
using $Duration = ::java::time::Duration;
using $AbstractSequentialList = ::java::util::AbstractSequentialList;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $Optional = ::java::util::Optional;
using $OptionalLong = ::java::util::OptionalLong;
using $CancellationException = ::java::util::concurrent::CancellationException;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionException = ::java::util::concurrent::CompletionException;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $ExecutionException = ::java::util::concurrent::ExecutionException;
using $Executor = ::java::util::concurrent::Executor;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicInteger = ::java::util::concurrent::atomic::AtomicInteger;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;
using $AuthenticationFilter$AuthInfo = ::jdk::internal::net::http::AuthenticationFilter$AuthInfo;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $ExchangeImpl = ::jdk::internal::net::http::ExchangeImpl;
using $HeaderFilter = ::jdk::internal::net::http::HeaderFilter;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpClientImpl$DelegatingExecutor = ::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $HttpResponseImpl = ::jdk::internal::net::http::HttpResponseImpl;
using $MultiExchange$CancelableRef = ::jdk::internal::net::http::MultiExchange$CancelableRef;
using $MultiExchange$ConnectTimeoutTracker = ::jdk::internal::net::http::MultiExchange$ConnectTimeoutTracker;
using $MultiExchange$NullSubscription = ::jdk::internal::net::http::MultiExchange$NullSubscription;
using $PrivilegedExecutor = ::jdk::internal::net::http::PrivilegedExecutor;
using $PushGroup = ::jdk::internal::net::http::PushGroup;
using $Response = ::jdk::internal::net::http::Response;
using $ResponseInfoImpl = ::jdk::internal::net::http::ResponseInfoImpl;
using $ResponseSubscribers = ::jdk::internal::net::http::ResponseSubscribers;
using $ResponseTimerEvent = ::jdk::internal::net::http::ResponseTimerEvent;
using $TimeoutEvent = ::jdk::internal::net::http::TimeoutEvent;
using $Cancelable = ::jdk::internal::net::http::common::Cancelable;
using $ConnectionExpiredException = ::jdk::internal::net::http::common::ConnectionExpiredException;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class MultiExchange$$Lambda$toString : public $Supplier {
	$class(MultiExchange$$Lambda$toString, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MultiExchange$$Lambda$toString>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo MultiExchange$$Lambda$toString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$toString, inst$)},
	{}
};
$MethodInfo MultiExchange$$Lambda$toString::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(MultiExchange$$Lambda$toString::*)($String*)>(&MultiExchange$$Lambda$toString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MultiExchange$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.MultiExchange$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* MultiExchange$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MultiExchange$$Lambda$toString::class$ = nullptr;

class MultiExchange$$Lambda$ConnectTimeoutTracker$1 : public $Function {
	$class(MultiExchange$$Lambda$ConnectTimeoutTracker$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* connectTimeout) override {
		 return $of($new($MultiExchange$ConnectTimeoutTracker, $cast($Duration, connectTimeout)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MultiExchange$$Lambda$ConnectTimeoutTracker$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo MultiExchange$$Lambda$ConnectTimeoutTracker$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(MultiExchange$$Lambda$ConnectTimeoutTracker$1::*)()>(&MultiExchange$$Lambda$ConnectTimeoutTracker$1::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MultiExchange$$Lambda$ConnectTimeoutTracker$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.MultiExchange$$Lambda$ConnectTimeoutTracker$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* MultiExchange$$Lambda$ConnectTimeoutTracker$1::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$$Lambda$ConnectTimeoutTracker$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MultiExchange$$Lambda$ConnectTimeoutTracker$1::class$ = nullptr;

class MultiExchange$$Lambda$getRemaining$2 : public $Function {
	$class(MultiExchange$$Lambda$getRemaining$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($MultiExchange$ConnectTimeoutTracker, inst$)->getRemaining());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MultiExchange$$Lambda$getRemaining$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo MultiExchange$$Lambda$getRemaining$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(MultiExchange$$Lambda$getRemaining$2::*)()>(&MultiExchange$$Lambda$getRemaining$2::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MultiExchange$$Lambda$getRemaining$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.MultiExchange$$Lambda$getRemaining$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* MultiExchange$$Lambda$getRemaining$2::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$$Lambda$getRemaining$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MultiExchange$$Lambda$getRemaining$2::class$ = nullptr;

class MultiExchange$$Lambda$lambda$responseAsync$0$3 : public $Supplier {
	$class(MultiExchange$$Lambda$lambda$responseAsync$0$3, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(MultiExchange::lambda$responseAsync$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MultiExchange$$Lambda$lambda$responseAsync$0$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo MultiExchange$$Lambda$lambda$responseAsync$0$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(MultiExchange$$Lambda$lambda$responseAsync$0$3::*)()>(&MultiExchange$$Lambda$lambda$responseAsync$0$3::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MultiExchange$$Lambda$lambda$responseAsync$0$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.MultiExchange$$Lambda$lambda$responseAsync$0$3",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* MultiExchange$$Lambda$lambda$responseAsync$0$3::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$$Lambda$lambda$responseAsync$0$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MultiExchange$$Lambda$lambda$responseAsync$0$3::class$ = nullptr;

class MultiExchange$$Lambda$lambda$handleNoBody$1$4 : public $BiConsumer {
	$class(MultiExchange$$Lambda$lambda$handleNoBody$1$4, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(MultiExchange* inst, $MinimalFuture* result, $Response* r, $Exchange* exch) {
		$set(this, inst$, inst);
		$set(this, result, result);
		$set(this, r, r);
		$set(this, exch, exch);
	}
	virtual void accept(Object$* nullBody, Object$* exception) override {
		$nc(inst$)->lambda$handleNoBody$1(result, r, exch, nullBody, $cast($Throwable, exception));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MultiExchange$$Lambda$lambda$handleNoBody$1$4>());
	}
	MultiExchange* inst$ = nullptr;
	$MinimalFuture* result = nullptr;
	$Response* r = nullptr;
	$Exchange* exch = nullptr;
	static $FieldInfo fieldInfos[5];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo MultiExchange$$Lambda$lambda$handleNoBody$1$4::fieldInfos[5] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$lambda$handleNoBody$1$4, inst$)},
	{"result", "Ljdk/internal/net/http/common/MinimalFuture;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$lambda$handleNoBody$1$4, result)},
	{"r", "Ljdk/internal/net/http/Response;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$lambda$handleNoBody$1$4, r)},
	{"exch", "Ljdk/internal/net/http/Exchange;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$lambda$handleNoBody$1$4, exch)},
	{}
};
$MethodInfo MultiExchange$$Lambda$lambda$handleNoBody$1$4::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/MultiExchange;Ljdk/internal/net/http/common/MinimalFuture;Ljdk/internal/net/http/Response;Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(MultiExchange$$Lambda$lambda$handleNoBody$1$4::*)(MultiExchange*,$MinimalFuture*,$Response*,$Exchange*)>(&MultiExchange$$Lambda$lambda$handleNoBody$1$4::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo MultiExchange$$Lambda$lambda$handleNoBody$1$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.MultiExchange$$Lambda$lambda$handleNoBody$1$4",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* MultiExchange$$Lambda$lambda$handleNoBody$1$4::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$$Lambda$lambda$handleNoBody$1$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MultiExchange$$Lambda$lambda$handleNoBody$1$4::class$ = nullptr;

class MultiExchange$$Lambda$nullBody$5 : public $BiConsumer {
	$class(MultiExchange$$Lambda$nullBody$5, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* resp, Object$* t) override {
		$nc(inst$)->nullBody($cast($HttpResponse, resp), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MultiExchange$$Lambda$nullBody$5>());
	}
	$Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo MultiExchange$$Lambda$nullBody$5::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$nullBody$5, inst$)},
	{}
};
$MethodInfo MultiExchange$$Lambda$nullBody$5::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(MultiExchange$$Lambda$nullBody$5::*)($Exchange*)>(&MultiExchange$$Lambda$nullBody$5::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo MultiExchange$$Lambda$nullBody$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.MultiExchange$$Lambda$nullBody$5",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* MultiExchange$$Lambda$nullBody$5::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$$Lambda$nullBody$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MultiExchange$$Lambda$nullBody$5::class$ = nullptr;

class MultiExchange$$Lambda$lambda$responseAsync0$2$6 : public $Function {
	$class(MultiExchange$$Lambda$lambda$responseAsync0$2$6, $NO_CLASS_INIT, $Function)
public:
	void init$(MultiExchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* v) override {
		 return $of($nc(inst$)->lambda$responseAsync0$2($cast($Void, v)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MultiExchange$$Lambda$lambda$responseAsync0$2$6>());
	}
	MultiExchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo MultiExchange$$Lambda$lambda$responseAsync0$2$6::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$lambda$responseAsync0$2$6, inst$)},
	{}
};
$MethodInfo MultiExchange$$Lambda$lambda$responseAsync0$2$6::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/MultiExchange;)V", nullptr, $PUBLIC, $method(static_cast<void(MultiExchange$$Lambda$lambda$responseAsync0$2$6::*)(MultiExchange*)>(&MultiExchange$$Lambda$lambda$responseAsync0$2$6::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MultiExchange$$Lambda$lambda$responseAsync0$2$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.MultiExchange$$Lambda$lambda$responseAsync0$2$6",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* MultiExchange$$Lambda$lambda$responseAsync0$2$6::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$$Lambda$lambda$responseAsync0$2$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MultiExchange$$Lambda$lambda$responseAsync0$2$6::class$ = nullptr;

class MultiExchange$$Lambda$lambda$responseAsync0$4$7 : public $Function {
	$class(MultiExchange$$Lambda$lambda$responseAsync0$4$7, $NO_CLASS_INIT, $Function)
public:
	void init$(MultiExchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* r) override {
		 return $of($nc(inst$)->lambda$responseAsync0$4($cast($Response, r)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MultiExchange$$Lambda$lambda$responseAsync0$4$7>());
	}
	MultiExchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo MultiExchange$$Lambda$lambda$responseAsync0$4$7::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$lambda$responseAsync0$4$7, inst$)},
	{}
};
$MethodInfo MultiExchange$$Lambda$lambda$responseAsync0$4$7::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/MultiExchange;)V", nullptr, $PUBLIC, $method(static_cast<void(MultiExchange$$Lambda$lambda$responseAsync0$4$7::*)(MultiExchange*)>(&MultiExchange$$Lambda$lambda$responseAsync0$4$7::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MultiExchange$$Lambda$lambda$responseAsync0$4$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.MultiExchange$$Lambda$lambda$responseAsync0$4$7",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* MultiExchange$$Lambda$lambda$responseAsync0$4$7::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$$Lambda$lambda$responseAsync0$4$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MultiExchange$$Lambda$lambda$responseAsync0$4$7::class$ = nullptr;

class MultiExchange$$Lambda$whenCancelled$8 : public $Function {
	$class(MultiExchange$$Lambda$whenCancelled$8, $NO_CLASS_INIT, $Function)
public:
	void init$(MultiExchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* t) override {
		 return $of($nc(inst$)->whenCancelled($cast($Throwable, t)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MultiExchange$$Lambda$whenCancelled$8>());
	}
	MultiExchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo MultiExchange$$Lambda$whenCancelled$8::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$whenCancelled$8, inst$)},
	{}
};
$MethodInfo MultiExchange$$Lambda$whenCancelled$8::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/MultiExchange;)V", nullptr, $PUBLIC, $method(static_cast<void(MultiExchange$$Lambda$whenCancelled$8::*)(MultiExchange*)>(&MultiExchange$$Lambda$whenCancelled$8::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MultiExchange$$Lambda$whenCancelled$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.MultiExchange$$Lambda$whenCancelled$8",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* MultiExchange$$Lambda$whenCancelled$8::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$$Lambda$whenCancelled$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MultiExchange$$Lambda$whenCancelled$8::class$ = nullptr;

class MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9 : public $Function {
	$class(MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9, $NO_CLASS_INIT, $Function)
public:
	void init$(MultiExchange* inst, $Exchange* exch) {
		$set(this, inst$, inst);
		$set(this, exch, exch);
	}
	virtual $Object* apply(Object$* response) override {
		 return $of($nc(inst$)->lambda$responseAsyncImpl$6(exch, $cast($Response, response)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9>());
	}
	MultiExchange* inst$ = nullptr;
	$Exchange* exch = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9, inst$)},
	{"exch", "Ljdk/internal/net/http/Exchange;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9, exch)},
	{}
};
$MethodInfo MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/MultiExchange;Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9::*)(MultiExchange*,$Exchange*)>(&MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9::class$ = nullptr;

class MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10 : public $BiFunction {
	$class(MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(MultiExchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* response, Object$* ex) override {
		 return $of($nc(inst$)->lambda$responseAsyncImpl$7($cast($Response, response), $cast($Throwable, ex)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10>());
	}
	MultiExchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10, inst$)},
	{}
};
$MethodInfo MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/MultiExchange;)V", nullptr, $PUBLIC, $method(static_cast<void(MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10::*)(MultiExchange*)>(&MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10::init$))},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10::class$ = nullptr;

class MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11 : public $BiFunction {
	$class(MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(MultiExchange* inst, $HttpRequestImpl* newrequest) {
		$set(this, inst$, inst);
		$set(this, newrequest, newrequest);
	}
	virtual $Object* apply(Object$* r, Object$* t) override {
		 return $of($nc(inst$)->lambda$responseAsyncImpl$5(newrequest, $cast($Void, r), $cast($Throwable, t)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11>());
	}
	MultiExchange* inst$ = nullptr;
	$HttpRequestImpl* newrequest = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11, inst$)},
	{"newrequest", "Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11, newrequest)},
	{}
};
$MethodInfo MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/MultiExchange;Ljdk/internal/net/http/HttpRequestImpl;)V", nullptr, $PUBLIC, $method(static_cast<void(MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11::*)(MultiExchange*,$HttpRequestImpl*)>(&MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11::init$))},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11::class$ = nullptr;

class MultiExchange$$Lambda$lambda$responseAsync0$3$12 : public $Function {
	$class(MultiExchange$$Lambda$lambda$responseAsync0$3$12, $NO_CLASS_INIT, $Function)
public:
	void init$(MultiExchange* inst, $Response* r, $Exchange* exch) {
		$set(this, inst$, inst);
		$set(this, r, r);
		$set(this, exch, exch);
	}
	virtual $Object* apply(Object$* body) override {
		 return $of($nc(inst$)->lambda$responseAsync0$3(r, exch, body));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MultiExchange$$Lambda$lambda$responseAsync0$3$12>());
	}
	MultiExchange* inst$ = nullptr;
	$Response* r = nullptr;
	$Exchange* exch = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo MultiExchange$$Lambda$lambda$responseAsync0$3$12::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$lambda$responseAsync0$3$12, inst$)},
	{"r", "Ljdk/internal/net/http/Response;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$lambda$responseAsync0$3$12, r)},
	{"exch", "Ljdk/internal/net/http/Exchange;", nullptr, $PUBLIC, $field(MultiExchange$$Lambda$lambda$responseAsync0$3$12, exch)},
	{}
};
$MethodInfo MultiExchange$$Lambda$lambda$responseAsync0$3$12::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/MultiExchange;Ljdk/internal/net/http/Response;Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(MultiExchange$$Lambda$lambda$responseAsync0$3$12::*)(MultiExchange*,$Response*,$Exchange*)>(&MultiExchange$$Lambda$lambda$responseAsync0$3$12::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MultiExchange$$Lambda$lambda$responseAsync0$3$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.MultiExchange$$Lambda$lambda$responseAsync0$3$12",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* MultiExchange$$Lambda$lambda$responseAsync0$3$12::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$$Lambda$lambda$responseAsync0$3$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MultiExchange$$Lambda$lambda$responseAsync0$3$12::class$ = nullptr;

$FieldInfo _MultiExchange_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(MultiExchange, $assertionsDisabled)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $STATIC | $FINAL, $staticField(MultiExchange, debug)},
	{"userRequest", "Ljava/net/http/HttpRequest;", nullptr, $PRIVATE | $FINAL, $field(MultiExchange, userRequest)},
	{"request", "Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PRIVATE | $FINAL, $field(MultiExchange, request)},
	{"connectTimeout", "Ljdk/internal/net/http/MultiExchange$ConnectTimeoutTracker;", nullptr, $PRIVATE | $FINAL, $field(MultiExchange, connectTimeout)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $FINAL, $field(MultiExchange, acc)},
	{"client", "Ljdk/internal/net/http/HttpClientImpl;", nullptr, $FINAL, $field(MultiExchange, client$)},
	{"responseHandler", "Ljava/net/http/HttpResponse$BodyHandler;", "Ljava/net/http/HttpResponse$BodyHandler<TT;>;", $FINAL, $field(MultiExchange, responseHandler)},
	{"executor", "Ljdk/internal/net/http/HttpClientImpl$DelegatingExecutor;", nullptr, $FINAL, $field(MultiExchange, executor)},
	{"attempts", "Ljava/util/concurrent/atomic/AtomicInteger;", nullptr, $FINAL, $field(MultiExchange, attempts)},
	{"currentreq", "Ljdk/internal/net/http/HttpRequestImpl;", nullptr, 0, $field(MultiExchange, currentreq)},
	{"previousreq", "Ljdk/internal/net/http/HttpRequestImpl;", nullptr, 0, $field(MultiExchange, previousreq)},
	{"exchange", "Ljdk/internal/net/http/Exchange;", "Ljdk/internal/net/http/Exchange<TT;>;", 0, $field(MultiExchange, exchange)},
	{"previous", "Ljdk/internal/net/http/Exchange;", "Ljdk/internal/net/http/Exchange<TT;>;", 0, $field(MultiExchange, previous)},
	{"retryCause", "Ljava/lang/Throwable;", nullptr, $VOLATILE, $field(MultiExchange, retryCause$)},
	{"expiredOnce", "Z", nullptr, $VOLATILE, $field(MultiExchange, expiredOnce)},
	{"response", "Ljava/net/http/HttpResponse;", "Ljava/net/http/HttpResponse<TT;>;", $VOLATILE, $field(MultiExchange, response)},
	{"DEFAULT_MAX_ATTEMPTS", "I", nullptr, $STATIC | $FINAL, $constField(MultiExchange, DEFAULT_MAX_ATTEMPTS)},
	{"max_attempts", "I", nullptr, $STATIC | $FINAL, $staticField(MultiExchange, max_attempts)},
	{"filters", "Ljava/util/LinkedList;", "Ljava/util/LinkedList<Ljdk/internal/net/http/HeaderFilter;>;", $PRIVATE | $FINAL, $field(MultiExchange, filters)},
	{"responseTimerEvent", "Ljdk/internal/net/http/ResponseTimerEvent;", nullptr, 0, $field(MultiExchange, responseTimerEvent)},
	{"cancelled", "Z", nullptr, $VOLATILE, $field(MultiExchange, cancelled)},
	{"interrupted", "Ljava/util/concurrent/atomic/AtomicReference;", "Ljava/util/concurrent/atomic/AtomicReference<Ljava/util/concurrent/CancellationException;>;", 0, $field(MultiExchange, interrupted)},
	{"pushGroup", "Ljdk/internal/net/http/PushGroup;", "Ljdk/internal/net/http/PushGroup<TT;>;", $FINAL, $field(MultiExchange, pushGroup)},
	{"serverauth", "Ljdk/internal/net/http/AuthenticationFilter$AuthInfo;", nullptr, $VOLATILE, $field(MultiExchange, serverauth)},
	{"proxyauth", "Ljdk/internal/net/http/AuthenticationFilter$AuthInfo;", nullptr, $VOLATILE, $field(MultiExchange, proxyauth)},
	{"numberOfRedirects", "I", nullptr, $VOLATILE, $field(MultiExchange, numberOfRedirects)},
	{"RETRY_ALWAYS", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MultiExchange, RETRY_ALWAYS)},
	{"RETRY_CONNECT", "Z", nullptr, $STATIC | $FINAL, $staticField(MultiExchange, RETRY_CONNECT)},
	{}
};

$MethodInfo _MultiExchange_MethodInfo_[] = {
	{"<init>", "(Ljava/net/http/HttpRequest;Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/HttpClientImpl;Ljava/net/http/HttpResponse$BodyHandler;Ljava/net/http/HttpResponse$PushPromiseHandler;Ljava/security/AccessControlContext;)V", "(Ljava/net/http/HttpRequest;Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/HttpClientImpl;Ljava/net/http/HttpResponse$BodyHandler<TT;>;Ljava/net/http/HttpResponse$PushPromiseHandler<TT;>;Ljava/security/AccessControlContext;)V", 0, $method(static_cast<void(MultiExchange::*)($HttpRequest*,$HttpRequestImpl*,$HttpClientImpl*,$HttpResponse$BodyHandler*,$HttpResponse$PushPromiseHandler*,$AccessControlContext*)>(&MultiExchange::init$))},
	{"bodyIsPresent", "(Ljdk/internal/net/http/Response;)Z", nullptr, $PRIVATE, $method(static_cast<bool(MultiExchange::*)($Response*)>(&MultiExchange::bodyIsPresent))},
	{"bodyNotPermitted", "(Ljdk/internal/net/http/Response;)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)($Response*)>(&MultiExchange::bodyNotPermitted))},
	{"canRetryRequest", "(Ljava/net/http/HttpRequest;)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)($HttpRequest*)>(&MultiExchange::canRetryRequest))},
	{"cancel", "(Ljava/io/IOException;)V", nullptr, $PUBLIC},
	{"cancel", "(Z)Z", nullptr, $PUBLIC},
	{"cancelTimer", "()V", nullptr, $PRIVATE, $method(static_cast<void(MultiExchange::*)()>(&MultiExchange::cancelTimer))},
	{"client", "()Ljdk/internal/net/http/HttpClientImpl;", nullptr, 0},
	{"disableRetryConnect", "()Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)()>(&MultiExchange::disableRetryConnect))},
	{"getExceptionalCF", "(Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", $PRIVATE, $method(static_cast<$CompletableFuture*(MultiExchange::*)($Throwable*)>(&MultiExchange::getExceptionalCF))},
	{"getExchange", "()Ljdk/internal/net/http/Exchange;", "()Ljdk/internal/net/http/Exchange<TT;>;", $SYNCHRONIZED},
	{"handleNoBody", "(Ljdk/internal/net/http/Response;Ljdk/internal/net/http/Exchange;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/Response;Ljdk/internal/net/http/Exchange<TT;>;)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;", $PRIVATE, $method(static_cast<$CompletableFuture*(MultiExchange::*)($Response*,$Exchange*)>(&MultiExchange::handleNoBody))},
	{"isIdempotentRequest", "(Ljava/net/http/HttpRequest;)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)($HttpRequest*)>(&MultiExchange::isIdempotentRequest))},
	{"lambda$handleNoBody$1", "(Ljdk/internal/net/http/common/MinimalFuture;Ljdk/internal/net/http/Response;Ljdk/internal/net/http/Exchange;Ljava/lang/Object;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(MultiExchange::*)($MinimalFuture*,$Response*,$Exchange*,Object$*,$Throwable*)>(&MultiExchange::lambda$handleNoBody$1))},
	{"lambda$responseAsync$0", "()Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Void*(*)()>(&MultiExchange::lambda$responseAsync$0))},
	{"lambda$responseAsync0$2", "(Ljava/lang/Void;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(MultiExchange::*)($Void*)>(&MultiExchange::lambda$responseAsync0$2))},
	{"lambda$responseAsync0$3", "(Ljdk/internal/net/http/Response;Ljdk/internal/net/http/Exchange;Ljava/lang/Object;)Ljava/net/http/HttpResponse;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$HttpResponse*(MultiExchange::*)($Response*,$Exchange*,Object$*)>(&MultiExchange::lambda$responseAsync0$3))},
	{"lambda$responseAsync0$4", "(Ljdk/internal/net/http/Response;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(MultiExchange::*)($Response*)>(&MultiExchange::lambda$responseAsync0$4))},
	{"lambda$responseAsyncImpl$5", "(Ljdk/internal/net/http/HttpRequestImpl;Ljava/lang/Void;Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletableFuture*(MultiExchange::*)($HttpRequestImpl*,$Void*,$Throwable*)>(&MultiExchange::lambda$responseAsyncImpl$5))},
	{"lambda$responseAsyncImpl$6", "(Ljdk/internal/net/http/Exchange;Ljdk/internal/net/http/Response;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(MultiExchange::*)($Exchange*,$Response*)>(&MultiExchange::lambda$responseAsyncImpl$6))},
	{"lambda$responseAsyncImpl$7", "(Ljdk/internal/net/http/Response;Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletableFuture*(MultiExchange::*)($Response*,$Throwable*)>(&MultiExchange::lambda$responseAsyncImpl$7))},
	{"remainingConnectTimeout", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/time/Duration;>;", $PUBLIC},
	{"requestCancelled", "()Z", nullptr, 0},
	{"requestFilters", "(Ljdk/internal/net/http/HttpRequestImpl;)V", nullptr, $PRIVATE, $method(static_cast<void(MultiExchange::*)($HttpRequestImpl*)>(&MultiExchange::requestFilters)), "java.io.IOException"},
	{"responseAsync", "(Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;", $PUBLIC},
	{"responseAsync0", "(Ljava/util/concurrent/CompletableFuture;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;", $PRIVATE, $method(static_cast<$CompletableFuture*(MultiExchange::*)($CompletableFuture*)>(&MultiExchange::responseAsync0))},
	{"responseAsyncImpl", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", $PRIVATE, $method(static_cast<$CompletableFuture*(MultiExchange::*)()>(&MultiExchange::responseAsyncImpl))},
	{"responseFilters", "(Ljdk/internal/net/http/Response;)Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PRIVATE, $method(static_cast<$HttpRequestImpl*(MultiExchange::*)($Response*)>(&MultiExchange::responseFilters)), "java.io.IOException"},
	{"retryCause", "(Ljava/lang/Throwable;)Ljava/lang/Throwable;", nullptr, $PRIVATE, $method(static_cast<$Throwable*(MultiExchange::*)($Throwable*)>(&MultiExchange::retryCause))},
	{"retryOnFailure", "(Ljava/lang/Throwable;)Z", nullptr, $PRIVATE, $method(static_cast<bool(MultiExchange::*)($Throwable*)>(&MultiExchange::retryOnFailure))},
	{"retryPostValue", "()Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)()>(&MultiExchange::retryPostValue))},
	{"setExchange", "(Ljdk/internal/net/http/Exchange;)V", "(Ljdk/internal/net/http/Exchange<TT;>;)V", $PRIVATE | $SYNCHRONIZED, $method(static_cast<void(MultiExchange::*)($Exchange*)>(&MultiExchange::setExchange))},
	{"toTimeoutException", "(Ljava/io/IOException;)Ljava/net/http/HttpTimeoutException;", nullptr, $PRIVATE, $method(static_cast<$HttpTimeoutException*(MultiExchange::*)($IOException*)>(&MultiExchange::toTimeoutException))},
	{"version", "()Ljava/net/http/HttpClient$Version;", nullptr, 0},
	{"whenCancelled", "(Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;", $PRIVATE, $method(static_cast<$CompletableFuture*(MultiExchange::*)($Throwable*)>(&MultiExchange::whenCancelled))},
	{}
};

$InnerClassInfo _MultiExchange_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.MultiExchange$NullSubscription", "jdk.internal.net.http.MultiExchange", "NullSubscription", $STATIC},
	{"jdk.internal.net.http.MultiExchange$CancelableRef", "jdk.internal.net.http.MultiExchange", "CancelableRef", $STATIC | $FINAL},
	{"jdk.internal.net.http.MultiExchange$ConnectTimeoutTracker", "jdk.internal.net.http.MultiExchange", "ConnectTimeoutTracker", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _MultiExchange_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.MultiExchange",
	"java.lang.Object",
	"jdk.internal.net.http.common.Cancelable",
	_MultiExchange_FieldInfo_,
	_MultiExchange_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljdk/internal/net/http/common/Cancelable;",
	nullptr,
	_MultiExchange_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.MultiExchange$NullSubscription,jdk.internal.net.http.MultiExchange$CancelableRef,jdk.internal.net.http.MultiExchange$ConnectTimeoutTracker"
};

$Object* allocate$MultiExchange($Class* clazz) {
	return $of($alloc(MultiExchange));
}

bool MultiExchange::$assertionsDisabled = false;
$Logger* MultiExchange::debug = nullptr;
int32_t MultiExchange::max_attempts = 0;
bool MultiExchange::RETRY_ALWAYS = false;
bool MultiExchange::RETRY_CONNECT = false;

void MultiExchange::init$($HttpRequest* userRequest, $HttpRequestImpl* requestImpl, $HttpClientImpl* client, $HttpResponse$BodyHandler* responseHandler, $HttpResponse$PushPromiseHandler* pushPromiseHandler, $AccessControlContext* acc) {
	$useLocalCurrentObjectStackCache();
	$set(this, attempts, $new($AtomicInteger));
	$set(this, response, nullptr);
	$set(this, interrupted, $new($AtomicReference));
	this->numberOfRedirects = 0;
	$set(this, previous, nullptr);
	$set(this, userRequest, userRequest);
	$set(this, request, requestImpl);
	$set(this, currentreq, this->request);
	$set(this, previousreq, nullptr);
	$set(this, client$, client);
	$set(this, filters, $nc(client)->filterChain());
	$set(this, acc, acc);
	$set(this, executor, client->theExecutor());
	$set(this, responseHandler, responseHandler);
	if (pushPromiseHandler != nullptr) {
		$var($Executor, executor, acc == nullptr ? $nc(this->executor)->delegate() : static_cast<$Executor*>($new($PrivilegedExecutor, $($nc(this->executor)->delegate()), acc)));
		$set(this, pushGroup, $new($PushGroup, pushPromiseHandler, this->request, executor));
	} else {
		$set(this, pushGroup, nullptr);
	}
	$set(this, connectTimeout, $cast($MultiExchange$ConnectTimeoutTracker, $nc($($nc($(client->connectTimeout()))->map(static_cast<$Function*>($$new(MultiExchange$$Lambda$ConnectTimeoutTracker$1)))))->orElse(nullptr)));
	$set(this, exchange, $new($Exchange, this->request, this));
}

$Exchange* MultiExchange::getExchange() {
	$synchronized(this) {
		return this->exchange;
	}
}

$HttpClientImpl* MultiExchange::client() {
	return this->client$;
}

$HttpClient$Version* MultiExchange::version() {
	$useLocalCurrentObjectStackCache();
	$HttpClient$Version* vers = $cast($HttpClient$Version, $nc($($nc(this->request)->version()))->orElse($($nc(this->client$)->version())));
	$init($HttpClient$Version);
	bool var$0 = vers == $HttpClient$Version::HTTP_2 && !$nc(this->request)->secure();
	if (var$0 && $nc(this->request)->proxy() != nullptr) {
		vers = $HttpClient$Version::HTTP_1_1;
	}
	return vers;
}

void MultiExchange::setExchange($Exchange* exchange) {
	$synchronized(this) {
		if (this->exchange != nullptr && exchange != this->exchange) {
			$nc(this->exchange)->released();
			if (this->cancelled) {
				$nc(exchange)->cancel();
			}
		}
		$set(this, exchange, exchange);
	}
}

$Optional* MultiExchange::remainingConnectTimeout() {
	$useLocalCurrentObjectStackCache();
	return $nc($($Optional::ofNullable(this->connectTimeout)))->map(static_cast<$Function*>($$new(MultiExchange$$Lambda$getRemaining$2)));
}

void MultiExchange::cancelTimer() {
	if (this->responseTimerEvent != nullptr) {
		$nc(this->client$)->cancelTimer(this->responseTimerEvent);
	}
}

void MultiExchange::requestFilters($HttpRequestImpl* r) {
	$useLocalCurrentObjectStackCache();
	$Log::logTrace("Applying request filters"_s, $$new($ObjectArray, 0));
	{
		$var($Iterator, i$, $nc(this->filters)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($HeaderFilter, filter, $cast($HeaderFilter, i$->next()));
			{
				$Log::logTrace("Applying {0}"_s, $$new($ObjectArray, {$of(filter)}));
				$nc(filter)->request(r, this);
			}
		}
	}
	$Log::logTrace("All filters applied"_s, $$new($ObjectArray, 0));
}

$HttpRequestImpl* MultiExchange::responseFilters($Response* response) {
	$useLocalCurrentObjectStackCache();
	$Log::logTrace("Applying response filters"_s, $$new($ObjectArray, 0));
	$var($Iterator, reverseItr, $nc(this->filters)->descendingIterator());
	while ($nc(reverseItr)->hasNext()) {
		$var($HeaderFilter, filter, $cast($HeaderFilter, reverseItr->next()));
		$Log::logTrace("Applying {0}"_s, $$new($ObjectArray, {$of(filter)}));
		$var($HttpRequestImpl, newreq, $nc(filter)->response(response));
		if (newreq != nullptr) {
			$Log::logTrace("New request: stopping filters"_s, $$new($ObjectArray, 0));
			return newreq;
		}
	}
	$Log::logTrace("All filters applied"_s, $$new($ObjectArray, 0));
	return nullptr;
}

void MultiExchange::cancel($IOException* cause) {
	this->cancelled = true;
	$nc($(getExchange()))->cancel(cause);
}

bool MultiExchange::cancel(bool mayInterruptIfRunning) {
	$useLocalCurrentObjectStackCache();
	bool cancelled = this->cancelled;
	if (!cancelled && mayInterruptIfRunning) {
		if ($nc(this->interrupted)->get() == nullptr) {
			$nc(this->interrupted)->compareAndSet(nullptr, $$new($CancellationException, "Request cancelled"_s));
		}
		this->cancelled = true;
		$var($Exchange, exchange, getExchange());
		if (exchange != nullptr) {
			exchange->cancel();
		}
		return true;
	}
	return false;
}

$CompletableFuture* MultiExchange::responseAsync($Executor* executor) {
	$useLocalCurrentObjectStackCache();
	$var($CompletableFuture, start, $new($MinimalFuture, $$new($MultiExchange$CancelableRef, this)));
	$var($CompletableFuture, cf, responseAsync0(start));
	start->completeAsync(static_cast<$Supplier*>($$new(MultiExchange$$Lambda$lambda$responseAsync$0$3)), executor);
	return cf;
}

bool MultiExchange::bodyNotPermitted($Response* r) {
	$init(MultiExchange);
	return $nc(r)->statusCode$ == 204;
}

bool MultiExchange::bodyIsPresent($Response* r) {
	$useLocalCurrentObjectStackCache();
	$var($HttpHeaders, headers, $nc(r)->headers());
	if ($nc($($nc(headers)->firstValueAsLong("Content-length"_s)))->orElse(0) != (int64_t)0) {
		return true;
	}
	if ($nc($($nc(headers)->firstValue("Transfer-encoding"_s)))->isPresent()) {
		return true;
	}
	return false;
}

$CompletableFuture* MultiExchange::handleNoBody($Response* r, $Exchange* exch) {
	$useLocalCurrentObjectStackCache();
	int32_t var$0 = $nc(r)->statusCode();
	$var($HttpHeaders, var$1, r->headers());
	$var($HttpResponse$BodySubscriber, bs, $nc(this->responseHandler)->apply($$new($ResponseInfoImpl, var$0, var$1, $(r->version()))));
	$nc(bs)->onSubscribe($$new($MultiExchange$NullSubscription));
	bs->onComplete();
	$var($CompletionStage, cs, $ResponseSubscribers::getBodyAsync(this->executor, bs));
	$var($MinimalFuture, result, $new($MinimalFuture));
	$nc(cs)->whenComplete(static_cast<$BiConsumer*>($$new(MultiExchange$$Lambda$lambda$handleNoBody$1$4, this, result, r, exch)));
	return $cast($CompletableFuture, result->whenComplete(static_cast<$BiConsumer*>($$new(MultiExchange$$Lambda$nullBody$5, static_cast<$Exchange*>($nc(exch))))));
}

$CompletableFuture* MultiExchange::responseAsync0($CompletableFuture* start) {
	$useLocalCurrentObjectStackCache();
	return $cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc(start)->thenCompose(static_cast<$Function*>($$new(MultiExchange$$Lambda$lambda$responseAsync0$2$6, this))))))->thenCompose(static_cast<$Function*>($$new(MultiExchange$$Lambda$lambda$responseAsync0$4$7, this))))))->exceptionallyCompose(static_cast<$Function*>($$new(MultiExchange$$Lambda$whenCancelled$8, this))));
}

$CompletableFuture* MultiExchange::whenCancelled($Throwable* t$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, t, t$renamed);
	$var($CancellationException, x, $cast($CancellationException, $nc(this->interrupted)->get()));
	if (x != nullptr) {
		$assign(t, x->initCause($($Utils::getCancelCause(t))));
		if ($nc(MultiExchange::debug)->on()) {
			$nc(MultiExchange::debug)->log($$str({"MultiExchange interrupted with: "_s, $($nc(t)->getCause())}));
		}
	}
	return $MinimalFuture::failedFuture(t);
}

$CompletableFuture* MultiExchange::responseAsyncImpl() {
	$useLocalCurrentObjectStackCache();
	$var($CompletableFuture, cf, nullptr);
	if ($nc(this->attempts)->incrementAndGet() > MultiExchange::max_attempts) {
		$assign(cf, $MinimalFuture::failedFuture($$new($IOException, "Too many retries"_s, this->retryCause$)));
	} else {
		if ($nc($($nc(this->currentreq)->timeout()))->isPresent()) {
			$set(this, responseTimerEvent, $ResponseTimerEvent::of(this));
			$nc(this->client$)->registerTimer(this->responseTimerEvent);
		}
		try {
			if (this->currentreq != this->previousreq) {
				requestFilters(this->currentreq);
			}
		} catch ($IOException& e) {
			return $MinimalFuture::failedFuture(e);
		}
		$var($Exchange, exch, getExchange());
		$assign(cf, $cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc($($nc(exch)->responseAsync()))->thenCompose(static_cast<$Function*>($$new(MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9, this, exch))))))->handle(static_cast<$BiFunction*>($$new(MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10, this))))))->thenCompose($($Function::identity()))));
	}
	return cf;
}

bool MultiExchange::retryPostValue() {
	$init(MultiExchange);
	$var($String, s, $Utils::getNetProperty("jdk.httpclient.enableAllMethodRetry"_s));
	if (s == nullptr) {
		return false;
	}
	return $nc(s)->isEmpty() ? true : $Boolean::parseBoolean(s);
}

bool MultiExchange::disableRetryConnect() {
	$init(MultiExchange);
	$var($String, s, $Utils::getNetProperty("jdk.httpclient.disableRetryConnect"_s));
	if (s == nullptr) {
		return false;
	}
	return $nc(s)->isEmpty() ? true : $Boolean::parseBoolean(s);
}

bool MultiExchange::isIdempotentRequest($HttpRequest* request) {
	$init(MultiExchange);
	$useLocalCurrentObjectStackCache();
	$var($String, method, $nc(request)->method());
	$var($String, s20098$, method);
	int32_t tmp20098$ = -1;
	switch ($nc(s20098$)->hashCode()) {
	case 0x00011336:
		{
			if (s20098$->equals("GET"_s)) {
				tmp20098$ = 0;
			}
			break;
		}
	case 0x0021C5E0:
		{
			if (s20098$->equals("HEAD"_s)) {
				tmp20098$ = 1;
			}
			break;
		}
	}

	bool var$0 = false;
	switch (tmp20098$) {
	case 0:
		{}
	case 1:
		{
			var$0 = true;
			break;
		}
	default:
		{
			var$0 = false;
			break;
		}
	}
	return var$0;
}

bool MultiExchange::canRetryRequest($HttpRequest* request) {
	$init(MultiExchange);
	if (MultiExchange::RETRY_ALWAYS) {
		return true;
	}
	if (isIdempotentRequest(request)) {
		return true;
	}
	return false;
}

bool MultiExchange::requestCancelled() {
	return $nc(this->interrupted)->get() != nullptr;
}

bool MultiExchange::retryOnFailure($Throwable* t) {
	if (requestCancelled()) {
		return false;
	}
	return $instanceOf($ConnectionExpiredException, t) || (MultiExchange::RETRY_CONNECT && ($instanceOf($ConnectException, t)));
}

$Throwable* MultiExchange::retryCause($Throwable* t) {
	$var($Throwable, cause, $instanceOf($ConnectionExpiredException, t) ? $nc(t)->getCause() : t);
	return cause == nullptr ? t : cause;
}

$CompletableFuture* MultiExchange::getExceptionalCF($Throwable* t$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, t, t$renamed);
	if (($instanceOf($CompletionException, t)) || ($instanceOf($ExecutionException, t))) {
		if ($nc(t)->getCause() != nullptr) {
			$assign(t, t->getCause());
		}
	}
	if (this->cancelled && !requestCancelled() && $instanceOf($IOException, t)) {
		if (!($instanceOf($HttpTimeoutException, t))) {
			$assign(t, toTimeoutException($cast($IOException, t)));
		}
	} else if (retryOnFailure(t)) {
		$var($Throwable, cause, retryCause(t));
		if (!($instanceOf($ConnectException, t))) {
			if (this->connectTimeout != nullptr) {
				$nc(this->connectTimeout)->reset();
			}
			if (!canRetryRequest(this->currentreq)) {
				return $MinimalFuture::failedFuture(cause);
			}
		}
		$set(this, retryCause$, cause);
		if (!this->expiredOnce) {
			if ($nc(MultiExchange::debug)->on()) {
				$nc(MultiExchange::debug)->log($$str({$($nc($of(t))->getClass()->getSimpleName()), " (async): retrying..."_s}), t);
			}
			this->expiredOnce = true;
			$set(this, previousreq, this->currentreq);
			return nullptr;
		} else {
			if ($nc(MultiExchange::debug)->on()) {
				$nc(MultiExchange::debug)->log($$str({$($nc($of(t))->getClass()->getSimpleName()), " (async): already retried once."_s}), t);
			}
			$assign(t, cause);
		}
	}
	return $MinimalFuture::failedFuture(t);
}

$HttpTimeoutException* MultiExchange::toTimeoutException($IOException* ioe) {
	$useLocalCurrentObjectStackCache();
	$var($HttpTimeoutException, t, nullptr);
	$var($Exchange, exchange, getExchange());
	if (exchange != nullptr) {
		$var($ExchangeImpl, exchangeImpl, exchange->exchImpl);
		if (exchangeImpl != nullptr) {
			if ($nc($(exchangeImpl->connection()))->connected()) {
				$assign(t, $new($HttpTimeoutException, "request timed out"_s));
				t->initCause(ioe);
			}
		}
	}
	if (t == nullptr) {
		$assign(t, $new($HttpConnectTimeoutException, "HTTP connect timed out"_s));
		t->initCause($$new($ConnectException, "HTTP connect timed out"_s));
	}
	return t;
}

$CompletableFuture* MultiExchange::lambda$responseAsyncImpl$7($Response* response, $Throwable* ex) {
	cancelTimer();
	if (ex == nullptr) {
		if (!MultiExchange::$assertionsDisabled && !(response != nullptr)) {
			$throwNew($AssertionError);
		}
		return $MinimalFuture::completedFuture(response);
	}
	$var($CompletableFuture, errorCF, getExceptionalCF(ex));
	if (errorCF == nullptr) {
		return responseAsyncImpl();
	} else {
		return errorCF;
	}
}

$CompletionStage* MultiExchange::lambda$responseAsyncImpl$6($Exchange* exch, $Response* response) {
	$useLocalCurrentObjectStackCache();
	$var($HttpRequestImpl, newrequest, nullptr);
	try {
		$assign(newrequest, responseFilters(response));
	} catch ($IOException& e) {
		return $MinimalFuture::failedFuture(e);
	}
	if (newrequest == nullptr) {
		if ($nc(this->attempts)->get() > 1) {
			$Log::logError($$str({"Succeeded on attempt: "_s, this->attempts}), $$new($ObjectArray, 0));
		}
		return $MinimalFuture::completedFuture(response);
	} else {
		$set(this, response, $new($HttpResponseImpl, this->currentreq, response, this->response, nullptr, exch));
		$var($Exchange, oldExch, exch);
		if ($nc(this->currentreq)->isWebSocket()) {
			$nc($($nc($nc(exch)->exchImpl)->connection()))->close();
		}
		return $nc($($cast($CompletableFuture, $nc($($nc(exch)->ignoreBody()))->handle(static_cast<$BiFunction*>($$new(MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11, this, newrequest))))))->thenCompose($($Function::identity()));
	}
}

$CompletableFuture* MultiExchange::lambda$responseAsyncImpl$5($HttpRequestImpl* newrequest, $Void* r, $Throwable* t) {
	$set(this, previousreq, this->currentreq);
	$set(this, currentreq, newrequest);
	this->expiredOnce = false;
	setExchange($$new($Exchange, this->currentreq, this, this->acc));
	return responseAsyncImpl();
}

$CompletionStage* MultiExchange::lambda$responseAsync0$4($Response* r) {
	$useLocalCurrentObjectStackCache();
	$var($Exchange, exch, getExchange());
	if (bodyNotPermitted(r)) {
		if (bodyIsPresent(r)) {
			$var($IOException, ioe, $new($IOException, "unexpected content length header with 204 response"_s));
			$nc(exch)->cancel(ioe);
			return $MinimalFuture::failedFuture(ioe);
		} else {
			return handleNoBody(r, exch);
		}
	}
	return $nc($($nc(exch)->readBodyAsync(this->responseHandler)))->thenApply(static_cast<$Function*>($$new(MultiExchange$$Lambda$lambda$responseAsync0$3$12, this, r, exch)));
}

$HttpResponse* MultiExchange::lambda$responseAsync0$3($Response* r, $Exchange* exch, Object$* body) {
	$set(this, response, $new($HttpResponseImpl, $($nc(r)->request()), r, this->response, body, exch));
	return this->response;
}

$CompletionStage* MultiExchange::lambda$responseAsync0$2($Void* v) {
	return responseAsyncImpl();
}

void MultiExchange::lambda$handleNoBody$1($MinimalFuture* result, $Response* r, $Exchange* exch, Object$* nullBody, $Throwable* exception) {
	if (exception != nullptr) {
		$nc(result)->completeExceptionally(exception);
	} else {
		$set(this, response, $new($HttpResponseImpl, $($nc(r)->request()), r, this->response, nullBody, exch));
		$nc(result)->complete(this->response);
	}
}

$Void* MultiExchange::lambda$responseAsync$0() {
	$init(MultiExchange);
	return nullptr;
}

void clinit$MultiExchange($Class* class$) {
	MultiExchange::$assertionsDisabled = !MultiExchange::class$->desiredAssertionStatus();
	$init($Utils);
	$assignStatic(MultiExchange::debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(MultiExchange$$Lambda$toString, static_cast<$String*>("MultiExchange"_s))), $Utils::DEBUG));
	MultiExchange::max_attempts = $Utils::getIntegerNetProperty("jdk.httpclient.redirects.retrylimit"_s, MultiExchange::DEFAULT_MAX_ATTEMPTS);
	MultiExchange::RETRY_ALWAYS = MultiExchange::retryPostValue();
	MultiExchange::RETRY_CONNECT = !MultiExchange::disableRetryConnect();
}

MultiExchange::MultiExchange() {
}

$Class* MultiExchange::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(MultiExchange$$Lambda$toString::classInfo$.name)) {
			return MultiExchange$$Lambda$toString::load$(name, initialize);
		}
		if (name->equals(MultiExchange$$Lambda$ConnectTimeoutTracker$1::classInfo$.name)) {
			return MultiExchange$$Lambda$ConnectTimeoutTracker$1::load$(name, initialize);
		}
		if (name->equals(MultiExchange$$Lambda$getRemaining$2::classInfo$.name)) {
			return MultiExchange$$Lambda$getRemaining$2::load$(name, initialize);
		}
		if (name->equals(MultiExchange$$Lambda$lambda$responseAsync$0$3::classInfo$.name)) {
			return MultiExchange$$Lambda$lambda$responseAsync$0$3::load$(name, initialize);
		}
		if (name->equals(MultiExchange$$Lambda$lambda$handleNoBody$1$4::classInfo$.name)) {
			return MultiExchange$$Lambda$lambda$handleNoBody$1$4::load$(name, initialize);
		}
		if (name->equals(MultiExchange$$Lambda$nullBody$5::classInfo$.name)) {
			return MultiExchange$$Lambda$nullBody$5::load$(name, initialize);
		}
		if (name->equals(MultiExchange$$Lambda$lambda$responseAsync0$2$6::classInfo$.name)) {
			return MultiExchange$$Lambda$lambda$responseAsync0$2$6::load$(name, initialize);
		}
		if (name->equals(MultiExchange$$Lambda$lambda$responseAsync0$4$7::classInfo$.name)) {
			return MultiExchange$$Lambda$lambda$responseAsync0$4$7::load$(name, initialize);
		}
		if (name->equals(MultiExchange$$Lambda$whenCancelled$8::classInfo$.name)) {
			return MultiExchange$$Lambda$whenCancelled$8::load$(name, initialize);
		}
		if (name->equals(MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9::classInfo$.name)) {
			return MultiExchange$$Lambda$lambda$responseAsyncImpl$6$9::load$(name, initialize);
		}
		if (name->equals(MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10::classInfo$.name)) {
			return MultiExchange$$Lambda$lambda$responseAsyncImpl$7$10::load$(name, initialize);
		}
		if (name->equals(MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11::classInfo$.name)) {
			return MultiExchange$$Lambda$lambda$responseAsyncImpl$5$11::load$(name, initialize);
		}
		if (name->equals(MultiExchange$$Lambda$lambda$responseAsync0$3$12::classInfo$.name)) {
			return MultiExchange$$Lambda$lambda$responseAsync0$3$12::load$(name, initialize);
		}
	}
	$loadClass(MultiExchange, name, initialize, &_MultiExchange_ClassInfo_, clinit$MultiExchange, allocate$MultiExchange);
	return class$;
}

$Class* MultiExchange::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk