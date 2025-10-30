#include <jdk/internal/net/http/Http1Exchange.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/URI.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpClient.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/net/http/HttpResponse$ResponseInfo.h>
#include <java/net/http/HttpResponse.h>
#include <java/nio/ByteBuffer.h>
#include <java/time/Duration.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractSequentialList.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Optional.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/ConcurrentLinkedDeque.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/ExchangeImpl.h>
#include <jdk/internal/net/http/Http1AsyncReceiver.h>
#include <jdk/internal/net/http/Http1Exchange$1.h>
#include <jdk/internal/net/http/Http1Exchange$DataPair.h>
#include <jdk/internal/net/http/Http1Exchange$Http1BodySubscriber.h>
#include <jdk/internal/net/http/Http1Exchange$Http1Publisher.h>
#include <jdk/internal/net/http/Http1Exchange$State.h>
#include <jdk/internal/net/http/Http1Request.h>
#include <jdk/internal/net/http/Http1Response.h>
#include <jdk/internal/net/http/HttpClientImpl$DelegatingExecutor.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/ResponseInfoImpl.h>
#include <jdk/internal/net/http/common/FlowTube$TubePublisher.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef BODY
#undef COMPLETED
#undef COMPLETING
#undef DEBUG
#undef EMPTY_BYTEBUFFER
#undef ERROR
#undef HEADERS
#undef HTTP_1_1
#undef INITIAL

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $URI = ::java::net::URI;
using $HttpClient = ::java::net::http::HttpClient;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpResponse = ::java::net::http::HttpResponse;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $HttpResponse$ResponseInfo = ::java::net::http::HttpResponse$ResponseInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Duration = ::java::time::Duration;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractList = ::java::util::AbstractList;
using $AbstractSequentialList = ::java::util::AbstractSequentialList;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Optional = ::java::util::Optional;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $ConcurrentLinkedDeque = ::java::util::concurrent::ConcurrentLinkedDeque;
using $Executor = ::java::util::concurrent::Executor;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $ExchangeImpl = ::jdk::internal::net::http::ExchangeImpl;
using $Http1AsyncReceiver = ::jdk::internal::net::http::Http1AsyncReceiver;
using $Http1Exchange$1 = ::jdk::internal::net::http::Http1Exchange$1;
using $Http1Exchange$DataPair = ::jdk::internal::net::http::Http1Exchange$DataPair;
using $Http1Exchange$Http1BodySubscriber = ::jdk::internal::net::http::Http1Exchange$Http1BodySubscriber;
using $Http1Exchange$Http1Publisher = ::jdk::internal::net::http::Http1Exchange$Http1Publisher;
using $Http1Exchange$State = ::jdk::internal::net::http::Http1Exchange$State;
using $Http1Request = ::jdk::internal::net::http::Http1Request;
using $Http1Response = ::jdk::internal::net::http::Http1Response;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpClientImpl$DelegatingExecutor = ::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $ResponseInfoImpl = ::jdk::internal::net::http::ResponseInfoImpl;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $FlowTube$TubePublisher = ::jdk::internal::net::http::common::FlowTube$TubePublisher;
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

class Http1Exchange$$Lambda$dbgString : public $Supplier {
	$class(Http1Exchange$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Http1Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$$Lambda$dbgString>());
	}
	Http1Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo Http1Exchange$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$$Lambda$dbgString::*)(Http1Exchange*)>(&Http1Exchange$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$$Lambda$dbgString::class$ = nullptr;

class Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1 : public $Function {
	$class(Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1, $NO_CLASS_INIT, $Function)
public:
	void init$(Http1Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* unused) override {
		 return $of($nc(inst$)->lambda$sendHeadersAsync$0($cast($Void, unused)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1>());
	}
	Http1Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1, inst$)},
	{}
};
$MethodInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1::*)(Http1Exchange*)>(&Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1::class$ = nullptr;

class Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2 : public $Runnable {
	$class(Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2, $NO_CLASS_INIT, $Runnable)
public:
	void init$($CompletableFuture* connectCF, $Throwable* cancelled) {
		$set(this, connectCF, connectCF);
		$set(this, cancelled, cancelled);
	}
	virtual void run() override {
		Http1Exchange::lambda$sendHeadersAsync$1(connectCF, cancelled);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2>());
	}
	$CompletableFuture* connectCF = nullptr;
	$Throwable* cancelled = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2::fieldInfos[3] = {
	{"connectCF", "Ljava/util/concurrent/CompletableFuture;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2, connectCF)},
	{"cancelled", "Ljava/lang/Throwable;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2, cancelled)},
	{}
};
$MethodInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2::methodInfos[3] = {
	{"<init>", "(Ljava/util/concurrent/CompletableFuture;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2::*)($CompletableFuture*,$Throwable*)>(&Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2::class$ = nullptr;

class Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3 : public $Function {
	$class(Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3, $NO_CLASS_INIT, $Function)
public:
	void init$(Http1Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* unused) override {
		 return $of($nc(inst$)->lambda$sendHeadersAsync$4($cast($Void, unused)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3>());
	}
	Http1Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3, inst$)},
	{}
};
$MethodInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3::*)(Http1Exchange*)>(&Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3::class$ = nullptr;

class Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4 : public $Function {
	$class(Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4, $NO_CLASS_INIT, $Function)
public:
	void init$(Http1Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* unused) override {
		 return $of($nc(inst$)->lambda$sendHeadersAsync$5($cast($Void, unused)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4>());
	}
	Http1Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4, inst$)},
	{}
};
$MethodInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4::*)(Http1Exchange*)>(&Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4::class$ = nullptr;

class Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5 : public $BiConsumer {
	$class(Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(Http1Exchange* inst, $Flow$Subscription* s) {
		$set(this, inst$, inst);
		$set(this, s, s);
	}
	virtual void accept(Object$* r, Object$* t) override {
		$nc(inst$)->lambda$cancelIfFailed$6(s, $cast($Void, r), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5>());
	}
	Http1Exchange* inst$ = nullptr;
	$Flow$Subscription* s = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5, inst$)},
	{"s", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5, s)},
	{}
};
$MethodInfo Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5::*)(Http1Exchange*,$Flow$Subscription*)>(&Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5::class$ = nullptr;

class Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6 : public $Consumer {
	$class(Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6, $NO_CLASS_INIT, $Consumer)
public:
	void init$(Http1Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* s) override {
		$nc(inst$)->lambda$sendBodyAsync$7($cast($Flow$Subscription, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6>());
	}
	Http1Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6, inst$)},
	{}
};
$MethodInfo Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6::*)(Http1Exchange*)>(&Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6::class$ = nullptr;

class Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7 : public $Consumer {
	$class(Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7, $NO_CLASS_INIT, $Consumer)
public:
	void init$(Http1Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* s) override {
		$nc(inst$)->lambda$sendBodyAsync$8($cast($Void, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7>());
	}
	Http1Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7, inst$)},
	{}
};
$MethodInfo Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7::*)(Http1Exchange*)>(&Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7::class$ = nullptr;

class Http1Exchange$$Lambda$runInline$8 : public $Executor {
	$class(Http1Exchange$$Lambda$runInline$8, $NO_CLASS_INIT, $Executor)
public:
	void init$(Http1Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual void execute($Runnable* run) override {
		$nc(inst$)->runInline(run);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$$Lambda$runInline$8>());
	}
	Http1Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$$Lambda$runInline$8::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$runInline$8, inst$)},
	{}
};
$MethodInfo Http1Exchange$$Lambda$runInline$8::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$$Lambda$runInline$8::*)(Http1Exchange*)>(&Http1Exchange$$Lambda$runInline$8::init$))},
	{"execute", "(Ljava/lang/Runnable;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$$Lambda$runInline$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$$Lambda$runInline$8",
	"java.lang.Object",
	"java.util.concurrent.Executor",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$$Lambda$runInline$8::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$$Lambda$runInline$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$$Lambda$runInline$8::class$ = nullptr;

class Http1Exchange$$Lambda$lambda$cancelImpl$9$9 : public $Runnable {
	$class(Http1Exchange$$Lambda$lambda$cancelImpl$9$9, $NO_CLASS_INIT, $Runnable)
public:
	void init$(Http1Exchange* inst, $CompletableFuture* cf, $Throwable* x) {
		$set(this, inst$, inst);
		$set(this, cf, cf);
		$set(this, x, x);
	}
	virtual void run() override {
		$nc(inst$)->lambda$cancelImpl$9(cf, x);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$$Lambda$lambda$cancelImpl$9$9>());
	}
	Http1Exchange* inst$ = nullptr;
	$CompletableFuture* cf = nullptr;
	$Throwable* x = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$$Lambda$lambda$cancelImpl$9$9::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$cancelImpl$9$9, inst$)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$cancelImpl$9$9, cf)},
	{"x", "Ljava/lang/Throwable;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$cancelImpl$9$9, x)},
	{}
};
$MethodInfo Http1Exchange$$Lambda$lambda$cancelImpl$9$9::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;Ljava/util/concurrent/CompletableFuture;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$$Lambda$lambda$cancelImpl$9$9::*)(Http1Exchange*,$CompletableFuture*,$Throwable*)>(&Http1Exchange$$Lambda$lambda$cancelImpl$9$9::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$$Lambda$lambda$cancelImpl$9$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$$Lambda$lambda$cancelImpl$9$9",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$$Lambda$lambda$cancelImpl$9$9::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$$Lambda$lambda$cancelImpl$9$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$$Lambda$lambda$cancelImpl$9$9::class$ = nullptr;

class Http1Exchange$$Lambda$cancelSubscription$10 : public $Runnable {
	$class(Http1Exchange$$Lambda$cancelSubscription$10, $NO_CLASS_INIT, $Runnable)
public:
	void init$($Http1Exchange$Http1BodySubscriber* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->cancelSubscription();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$$Lambda$cancelSubscription$10>());
	}
	$Http1Exchange$Http1BodySubscriber* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$$Lambda$cancelSubscription$10::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$cancelSubscription$10, inst$)},
	{}
};
$MethodInfo Http1Exchange$$Lambda$cancelSubscription$10::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange$Http1BodySubscriber;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$$Lambda$cancelSubscription$10::*)($Http1Exchange$Http1BodySubscriber*)>(&Http1Exchange$$Lambda$cancelSubscription$10::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$$Lambda$cancelSubscription$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$$Lambda$cancelSubscription$10",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$$Lambda$cancelSubscription$10::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$$Lambda$cancelSubscription$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$$Lambda$cancelSubscription$10::class$ = nullptr;

class Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11 : public $Supplier {
	$class(Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Http1Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$sendHeadersAsync$2());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11>());
	}
	Http1Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11, inst$)},
	{}
};
$MethodInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11::*)(Http1Exchange*)>(&Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11::class$ = nullptr;

class Http1Exchange$$Lambda$lambda$getOutgoing$12$12 : public $Runnable {
	$class(Http1Exchange$$Lambda$lambda$getOutgoing$12$12, $NO_CLASS_INIT, $Runnable)
public:
	void init$(Http1Exchange* inst, $Http1Exchange$DataPair* dp) {
		$set(this, inst$, inst);
		$set(this, dp, dp);
	}
	virtual void run() override {
		$nc(inst$)->lambda$getOutgoing$12(dp);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$$Lambda$lambda$getOutgoing$12$12>());
	}
	Http1Exchange* inst$ = nullptr;
	$Http1Exchange$DataPair* dp = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$$Lambda$lambda$getOutgoing$12$12::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$getOutgoing$12$12, inst$)},
	{"dp", "Ljdk/internal/net/http/Http1Exchange$DataPair;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$getOutgoing$12$12, dp)},
	{}
};
$MethodInfo Http1Exchange$$Lambda$lambda$getOutgoing$12$12::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;Ljdk/internal/net/http/Http1Exchange$DataPair;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$$Lambda$lambda$getOutgoing$12$12::*)(Http1Exchange*,$Http1Exchange$DataPair*)>(&Http1Exchange$$Lambda$lambda$getOutgoing$12$12::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$$Lambda$lambda$getOutgoing$12$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$$Lambda$lambda$getOutgoing$12$12",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$$Lambda$lambda$getOutgoing$12$12::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$$Lambda$lambda$getOutgoing$12$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$$Lambda$lambda$getOutgoing$12$12::class$ = nullptr;

class Http1Exchange$$Lambda$requestMoreBody$13 : public $Runnable {
	$class(Http1Exchange$$Lambda$requestMoreBody$13, $NO_CLASS_INIT, $Runnable)
public:
	void init$(Http1Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->requestMoreBody();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$$Lambda$requestMoreBody$13>());
	}
	Http1Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$$Lambda$requestMoreBody$13::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$requestMoreBody$13, inst$)},
	{}
};
$MethodInfo Http1Exchange$$Lambda$requestMoreBody$13::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$$Lambda$requestMoreBody$13::*)(Http1Exchange*)>(&Http1Exchange$$Lambda$requestMoreBody$13::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$$Lambda$requestMoreBody$13::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$$Lambda$requestMoreBody$13",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$$Lambda$requestMoreBody$13::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$$Lambda$requestMoreBody$13, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$$Lambda$requestMoreBody$13::class$ = nullptr;

class Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14 : public $BiConsumer {
	$class(Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(Http1Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* r, Object$* t) override {
		$nc(inst$)->lambda$sendHeadersAsync$3($cast($Void, r), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14>());
	}
	Http1Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14, inst$)},
	{}
};
$MethodInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14::*)(Http1Exchange*)>(&Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14::class$ = nullptr;

$FieldInfo _Http1Exchange_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http1Exchange, $assertionsDisabled)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(Http1Exchange, debug)},
	{"request", "Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $FINAL, $field(Http1Exchange, request$)},
	{"requestAction", "Ljdk/internal/net/http/Http1Request;", nullptr, $FINAL, $field(Http1Exchange, requestAction)},
	{"response", "Ljdk/internal/net/http/Http1Response;", "Ljdk/internal/net/http/Http1Response<TT;>;", $PRIVATE | $VOLATILE, $field(Http1Exchange, response)},
	{"connection", "Ljdk/internal/net/http/HttpConnection;", nullptr, $FINAL, $field(Http1Exchange, connection$)},
	{"client", "Ljdk/internal/net/http/HttpClientImpl;", nullptr, $FINAL, $field(Http1Exchange, client$)},
	{"executor", "Ljava/util/concurrent/Executor;", nullptr, $FINAL, $field(Http1Exchange, executor)},
	{"asyncReceiver", "Ljdk/internal/net/http/Http1AsyncReceiver;", nullptr, $PRIVATE | $FINAL, $field(Http1Exchange, asyncReceiver)},
	{"upgraded", "Z", nullptr, $PRIVATE | $VOLATILE, $field(Http1Exchange, upgraded$)},
	{"failed", "Ljava/lang/Throwable;", nullptr, $PRIVATE, $field(Http1Exchange, failed)},
	{"operations", "Ljava/util/List;", "Ljava/util/List<Ljava/util/concurrent/CompletableFuture<*>;>;", $PRIVATE | $FINAL, $field(Http1Exchange, operations)},
	{"lock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(Http1Exchange, lock)},
	{"outgoing", "Ljava/util/concurrent/ConcurrentLinkedDeque;", "Ljava/util/concurrent/ConcurrentLinkedDeque<Ljdk/internal/net/http/Http1Exchange$DataPair;>;", $FINAL, $field(Http1Exchange, outgoing)},
	{"writePublisher", "Ljdk/internal/net/http/Http1Exchange$Http1Publisher;", "Ljdk/internal/net/http/Http1Exchange<TT;>.Http1Publisher;", $PRIVATE | $FINAL, $field(Http1Exchange, writePublisher)},
	{"headersSentCF", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/ExchangeImpl<TT;>;>;", $PRIVATE | $FINAL, $field(Http1Exchange, headersSentCF)},
	{"bodySentCF", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/ExchangeImpl<TT;>;>;", $PRIVATE | $FINAL, $field(Http1Exchange, bodySentCF)},
	{"bodySubscriber", "Ljdk/internal/net/http/Http1Exchange$Http1BodySubscriber;", nullptr, $PRIVATE | $VOLATILE, $field(Http1Exchange, bodySubscriber)},
	{"state", "Ljdk/internal/net/http/Http1Exchange$State;", nullptr, $PRIVATE, $field(Http1Exchange, state)},
	{}
};

$MethodInfo _Http1Exchange_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;Ljdk/internal/net/http/HttpConnection;)V", "(Ljdk/internal/net/http/Exchange<TT;>;Ljdk/internal/net/http/HttpConnection;)V", 0, $method(static_cast<void(Http1Exchange::*)($Exchange*,$HttpConnection*)>(&Http1Exchange::init$)), "java.io.IOException"},
	{"appendToOutgoing", "(Ljava/lang/Throwable;)V", nullptr, 0},
	{"appendToOutgoing", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", 0},
	{"appendToOutgoing", "(Ljdk/internal/net/http/Http1Exchange$DataPair;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1Exchange::*)($Http1Exchange$DataPair*)>(&Http1Exchange::appendToOutgoing))},
	{"cancel", "()V", nullptr, 0},
	{"cancel", "(Ljava/io/IOException;)V", nullptr, 0},
	{"cancelIfFailed", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1Exchange::*)($Flow$Subscription*)>(&Http1Exchange::cancelIfFailed))},
	{"cancelImpl", "(Ljava/lang/Throwable;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1Exchange::*)($Throwable*)>(&Http1Exchange::cancelImpl))},
	{"cancelUpstreamSubscription", "()V", nullptr, $PRIVATE, $method(static_cast<void(Http1Exchange::*)()>(&Http1Exchange::cancelUpstreamSubscription))},
	{"client", "()Ljava/net/http/HttpClient;", nullptr, 0},
	{"completed", "()V", nullptr, 0},
	{"connectFlows", "(Ljdk/internal/net/http/HttpConnection;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1Exchange::*)($HttpConnection*)>(&Http1Exchange::connectFlows))},
	{"connection", "()Ljdk/internal/net/http/HttpConnection;", nullptr, 0},
	{"dbgString", "()Ljava/lang/String;", nullptr, 0},
	{"drainLeftOverBytes", "()Ljava/nio/ByteBuffer;", nullptr, 0},
	{"getCancelCause", "()Ljava/lang/Throwable;", nullptr, 0},
	{"getOutgoing", "()Ljdk/internal/net/http/Http1Exchange$DataPair;", nullptr, $PRIVATE, $method(static_cast<$Http1Exchange$DataPair*(Http1Exchange::*)()>(&Http1Exchange::getOutgoing))},
	{"getResponseAsync", "(Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", 0},
	{"hasOutgoing", "()Z", nullptr, $PRIVATE, $method(static_cast<bool(Http1Exchange::*)()>(&Http1Exchange::hasOutgoing))},
	{"ignoreBody", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", 0},
	{"isCanceled", "()Z", nullptr, 0},
	{"lambda$cancelIfFailed$6", "(Ljava/util/concurrent/Flow$Subscription;Ljava/lang/Void;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Http1Exchange::*)($Flow$Subscription*,$Void*,$Throwable*)>(&Http1Exchange::lambda$cancelIfFailed$6))},
	{"lambda$cancelImpl$9", "(Ljava/util/concurrent/CompletableFuture;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Http1Exchange::*)($CompletableFuture*,$Throwable*)>(&Http1Exchange::lambda$cancelImpl$9))},
	{"lambda$getOutgoing$12", "(Ljdk/internal/net/http/Http1Exchange$DataPair;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Http1Exchange::*)($Http1Exchange$DataPair*)>(&Http1Exchange::lambda$getOutgoing$12))},
	{"lambda$sendBodyAsync$7", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Http1Exchange::*)($Flow$Subscription*)>(&Http1Exchange::lambda$sendBodyAsync$7))},
	{"lambda$sendBodyAsync$8", "(Ljava/lang/Void;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Http1Exchange::*)($Void*)>(&Http1Exchange::lambda$sendBodyAsync$8))},
	{"lambda$sendHeadersAsync$0", "(Ljava/lang/Void;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(Http1Exchange::*)($Void*)>(&Http1Exchange::lambda$sendHeadersAsync$0))},
	{"lambda$sendHeadersAsync$1", "(Ljava/util/concurrent/CompletableFuture;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($CompletableFuture*,$Throwable*)>(&Http1Exchange::lambda$sendHeadersAsync$1))},
	{"lambda$sendHeadersAsync$2", "()Ljdk/internal/net/http/ExchangeImpl;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$ExchangeImpl*(Http1Exchange::*)()>(&Http1Exchange::lambda$sendHeadersAsync$2))},
	{"lambda$sendHeadersAsync$3", "(Ljava/lang/Void;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Http1Exchange::*)($Void*,$Throwable*)>(&Http1Exchange::lambda$sendHeadersAsync$3))},
	{"lambda$sendHeadersAsync$4", "(Ljava/lang/Void;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(Http1Exchange::*)($Void*)>(&Http1Exchange::lambda$sendHeadersAsync$4))},
	{"lambda$sendHeadersAsync$5", "(Ljava/lang/Void;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(Http1Exchange::*)($Void*)>(&Http1Exchange::lambda$sendHeadersAsync$5))},
	{"nullBody", "(Ljava/net/http/HttpResponse;Ljava/lang/Throwable;)V", "(Ljava/net/http/HttpResponse<TT;>;Ljava/lang/Throwable;)V", $PUBLIC},
	{"readBodyAsync", "(Ljava/net/http/HttpResponse$BodyHandler;ZLjava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/net/http/HttpResponse$BodyHandler<TT;>;ZLjava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TT;>;", 0},
	{"released", "()V", nullptr, 0},
	{"request", "()Ljdk/internal/net/http/HttpRequestImpl;", nullptr, 0},
	{"requestMoreBody", "()V", nullptr, $PRIVATE, $method(static_cast<void(Http1Exchange::*)()>(&Http1Exchange::requestMoreBody))},
	{"runInline", "(Ljava/lang/Runnable;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1Exchange::*)($Runnable*)>(&Http1Exchange::runInline))},
	{"sendBodyAsync", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/ExchangeImpl<TT;>;>;", 0},
	{"sendHeadersAsync", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/ExchangeImpl<TT;>;>;", 0},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"upgraded", "()V", nullptr, 0},
	{}
};

$InnerClassInfo _Http1Exchange_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Exchange$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"jdk.internal.net.http.Http1Exchange$Http1Publisher", "jdk.internal.net.http.Http1Exchange", "Http1Publisher", $FINAL},
	{"jdk.internal.net.http.Http1Exchange$Http1BodySubscriber", "jdk.internal.net.http.Http1Exchange", "Http1BodySubscriber", $STATIC | $ABSTRACT},
	{"jdk.internal.net.http.Http1Exchange$DataPair", "jdk.internal.net.http.Http1Exchange", "DataPair", $STATIC},
	{"jdk.internal.net.http.Http1Exchange$State", "jdk.internal.net.http.Http1Exchange", "State", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _Http1Exchange_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.Http1Exchange",
	"jdk.internal.net.http.ExchangeImpl",
	nullptr,
	_Http1Exchange_FieldInfo_,
	_Http1Exchange_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljdk/internal/net/http/ExchangeImpl<TT;>;",
	nullptr,
	_Http1Exchange_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Exchange$1,jdk.internal.net.http.Http1Exchange$Http1Publisher,jdk.internal.net.http.Http1Exchange$Http1Publisher$Http1WriteSubscription,jdk.internal.net.http.Http1Exchange$Http1Publisher$WriteTask,jdk.internal.net.http.Http1Exchange$Http1BodySubscriber,jdk.internal.net.http.Http1Exchange$Http1BodySubscriber$1,jdk.internal.net.http.Http1Exchange$DataPair,jdk.internal.net.http.Http1Exchange$State"
};

$Object* allocate$Http1Exchange($Class* clazz) {
	return $of($alloc(Http1Exchange));
}

bool Http1Exchange::$assertionsDisabled = false;

$String* Http1Exchange::toString() {
	return $str({"HTTP/1.1 "_s, $($nc(this->request$)->toString())});
}

$HttpRequestImpl* Http1Exchange::request() {
	return this->request$;
}

void Http1Exchange::init$($Exchange* exchange, $HttpConnection* connection) {
	$useLocalCurrentObjectStackCache();
	$ExchangeImpl::init$(exchange);
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(Http1Exchange$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, lock, $new($Object));
	$set(this, outgoing, $new($ConcurrentLinkedDeque));
	$set(this, writePublisher, $new($Http1Exchange$Http1Publisher, this));
	$set(this, headersSentCF, $new($MinimalFuture));
	$set(this, bodySentCF, $new($MinimalFuture));
	$init($Http1Exchange$State);
	$set(this, state, $Http1Exchange$State::INITIAL);
	$set(this, request$, $nc(exchange)->request());
	$set(this, client$, exchange->client());
	$set(this, executor, exchange->executor());
	$set(this, operations, $new($LinkedList));
	$nc(this->operations)->add(this->headersSentCF);
	$nc(this->operations)->add(this->bodySentCF);
	if (connection != nullptr) {
		$set(this, connection$, connection);
	} else {
		$var($InetSocketAddress, addr, $nc(this->request$)->getAddress());
		$init($HttpClient$Version);
		$set(this, connection$, $HttpConnection::getConnection(addr, this->client$, this->request$, $HttpClient$Version::HTTP_1_1));
	}
	$set(this, requestAction, $new($Http1Request, this->request$, this));
	$set(this, asyncReceiver, $new($Http1AsyncReceiver, this->executor, this));
}

$HttpConnection* Http1Exchange::connection() {
	return this->connection$;
}

void Http1Exchange::connectFlows($HttpConnection* connection) {
	$useLocalCurrentObjectStackCache();
	$var($FlowTube, tube, $nc(connection)->getConnectionFlow());
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("%s connecting flows"_s, $$new($ObjectArray, {$of(tube)}));
	}
	$nc(tube)->connectFlows(this->writePublisher, $($nc(this->asyncReceiver)->subscriber()));
}

$CompletableFuture* Http1Exchange::sendHeadersAsync() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Sending headers only"_s);
	}
	$nc(this->asyncReceiver)->setRetryOnError(true);
	if (this->response == nullptr) {
		$set(this, response, $new($Http1Response, this->connection$, this, this->asyncReceiver));
	}
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("response created in advance"_s);
	}
	$var($CompletableFuture, connectCF, nullptr);
	if (!$nc(this->connection$)->connected()) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("initiating connect async"_s);
		}
		$assign(connectCF, $cast($CompletableFuture, $nc($($nc(this->connection$)->connectAsync(this->exchange)))->thenCompose(static_cast<$Function*>($$new(Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1, this)))));
		$var($Throwable, cancelled, nullptr);
		$synchronized(this->lock) {
			if (($assign(cancelled, this->failed)) == nullptr) {
				$nc(this->operations)->add(connectCF);
			}
		}
		if (cancelled != nullptr) {
			if ($nc(this->client$)->isSelectorThread()) {
				$nc(this->executor)->execute(static_cast<$Runnable*>($$new(Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2, connectCF, cancelled)));
			} else {
				$nc(connectCF)->completeExceptionally(cancelled);
			}
		}
	} else {
		$assign(connectCF, $new($MinimalFuture));
		connectCF->complete(nullptr);
	}
	return $cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc(connectCF)->thenCompose(static_cast<$Function*>($$new(Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3, this))))))->thenCompose(static_cast<$Function*>($$new(Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4, this))));
}

void Http1Exchange::cancelIfFailed($Flow$Subscription* s) {
	$nc($nc(this->asyncReceiver)->whenFinished)->whenCompleteAsync(static_cast<$BiConsumer*>($$new(Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5, this, s)), this->executor);
}

$CompletableFuture* Http1Exchange::sendBodyAsync() {
	$useLocalCurrentObjectStackCache();
	if (!Http1Exchange::$assertionsDisabled && !$nc(this->headersSentCF)->isDone()) {
		$throwNew($AssertionError);
	}
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("sendBodyAsync"_s);
	}
	try {
		$set(this, bodySubscriber, $nc(this->requestAction)->continueRequest());
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("bodySubscriber is %s"_s, $$new($ObjectArray, {this->bodySubscriber == nullptr ? ($Object*)nullptr : $of($nc($of(this->bodySubscriber))->getClass())}));
		}
		if (this->bodySubscriber == nullptr) {
			$set(this, bodySubscriber, $Http1Exchange$Http1BodySubscriber::completeSubscriber(this->debug));
			appendToOutgoing($Http1Exchange$Http1BodySubscriber::COMPLETED);
		} else {
			$nc($($cast($CompletableFuture, $nc($nc(this->bodySubscriber)->whenSubscribed)->thenAccept(static_cast<$Consumer*>($$new(Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6, this))))))->thenAccept(static_cast<$Consumer*>($$new(Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7, this)));
		}
	} catch ($Throwable& t) {
		cancelImpl(t);
		$nc(this->bodySentCF)->completeExceptionally(t);
	}
	return $Utils::wrapForDebug(this->debug, "sendBodyAsync"_s, this->bodySentCF);
}

$CompletableFuture* Http1Exchange::getResponseAsync($Executor* executor) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("reading headers"_s);
	}
	$var($CompletableFuture, cf, $nc(this->response)->readHeadersAsync(executor));
	$var($Throwable, cause, nullptr);
	$synchronized(this->lock) {
		$nc(this->operations)->add(cf);
		$assign(cause, this->failed);
		$set(this, failed, nullptr);
	}
	if (cause != nullptr) {
		int64_t var$0 = 0;
		if ($nc($($nc(this->request$)->timeout()))->isPresent()) {
			int64_t var$1 = $nc(($cast($Duration, $($nc($($nc(this->request$)->timeout()))->get()))))->getSeconds() * 1000;
			var$0 = (var$1 + $nc(($cast($Duration, $($nc($($nc(this->request$)->timeout()))->get()))))->getNano() / 0x000F4240);
		} else {
			var$0 = -1;
		}
		$Log::logTrace("Http1Exchange: request [{0}/timeout={1}ms]\n\tCompleting exceptionally with {2}\n"_s, $$new($ObjectArray, {
			$($of($nc(this->request$)->uri())),
			$($of($Long::valueOf(var$0))),
			$of(cause)
		}));
		bool acknowledged = $nc(cf)->completeExceptionally(cause);
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log(acknowledged ? ($$str({"completed response with "_s, cause})) : ($$str({"response already completed, ignoring "_s, cause})));
		}
	}
	return $Utils::wrapForDebug(this->debug, "getResponseAsync"_s, cf);
}

$CompletableFuture* Http1Exchange::readBodyAsync($HttpResponse$BodyHandler* handler, bool returnConnectionToPool, $Executor* executor) {
	$useLocalCurrentObjectStackCache();
	int32_t var$0 = $nc(this->response)->responseCode();
	$init($HttpClient$Version);
	$var($HttpResponse$BodySubscriber, bs, $nc(handler)->apply($$new($ResponseInfoImpl, var$0, $($nc(this->response)->responseHeaders()), $HttpClient$Version::HTTP_1_1)));
	$var($CompletableFuture, bodyCF, $nc(this->response)->readBody(bs, returnConnectionToPool, executor));
	return bodyCF;
}

$CompletableFuture* Http1Exchange::ignoreBody() {
	return $nc(this->response)->ignoreBody(this->executor);
}

void Http1Exchange::nullBody($HttpResponse* resp, $Throwable* t) {
	$nc(this->response)->nullBody(resp, t);
}

$ByteBuffer* Http1Exchange::drainLeftOverBytes() {
	$synchronized(this->lock) {
		$nc(this->asyncReceiver)->stop();
		$init($Utils);
		return $nc(this->asyncReceiver)->drain($Utils::EMPTY_BYTEBUFFER);
	}
}

void Http1Exchange::released() {
	$var($Http1Response, resp, this->response);
	if (resp != nullptr) {
		resp->completed();
	}
	$nc(this->asyncReceiver)->clear();
}

void Http1Exchange::completed() {
	$var($Http1Response, resp, this->response);
	if (resp != nullptr) {
		resp->completed();
	}
}

void Http1Exchange::cancel() {
	cancelImpl($$new($IOException, "Request cancelled"_s));
}

void Http1Exchange::cancel($IOException* cause) {
	cancelImpl(cause);
}

void Http1Exchange::cancelImpl($Throwable* cause) {
	$useLocalCurrentObjectStackCache();
	$var($LinkedList, toComplete, nullptr);
	int32_t count = 0;
	$var($Throwable, error, nullptr);
	$synchronized(this->lock) {
		if (($assign(error, this->failed)) == nullptr) {
			$set(this, failed, ($assign(error, cause)));
		}
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log($$str({$($nc(this->request$)->uri()), ": "_s, error}));
		}
		bool var$0 = this->requestAction != nullptr && $nc(this->requestAction)->finished() && this->response != nullptr;
		if (var$0 && $nc(this->response)->finished()) {
			return;
		}
		$nc($nc(this->writePublisher)->writeScheduler)->stop();
		if ($nc(this->operations)->isEmpty()) {
			int64_t var$1 = 0;
			if ($nc($($nc(this->request$)->timeout()))->isPresent()) {
				int64_t var$2 = $nc(($cast($Duration, $($nc($($nc(this->request$)->timeout()))->get()))))->getSeconds() * 1000;
				var$1 = (var$2 + $nc(($cast($Duration, $($nc($($nc(this->request$)->timeout()))->get()))))->getNano() / 0x000F4240);
			} else {
				var$1 = -1;
			}
			$Log::logTrace("Http1Exchange: request [{0}/timeout={1}ms] no pending operation.\n\tCan\'\'t cancel yet with {2}"_s, $$new($ObjectArray, {
				$($of($nc(this->request$)->uri())),
				$($of($Long::valueOf(var$1))),
				$of(cause)
			}));
		} else {
			{
				$var($Iterator, i$, $nc(this->operations)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($CompletableFuture, cf, $cast($CompletableFuture, i$->next()));
					{
						if (!$nc(cf)->isDone()) {
							if (toComplete == nullptr) {
								$assign(toComplete, $new($LinkedList));
							}
							$nc(toComplete)->add(cf);
							++count;
						}
					}
				}
			}
			$nc(this->operations)->clear();
		}
	}
	{
		$var($Throwable, var$3, nullptr);
		try {
			$Log::logError($$str({"Http1Exchange.cancel: count="_s, $$str(count)}), $$new($ObjectArray, 0));
			if (toComplete != nullptr) {
				$var($Executor, exec, $nc(this->client$)->isSelectorThread() ? this->executor : static_cast<$Executor*>($new(Http1Exchange$$Lambda$runInline$8, this)));
				$var($Throwable, x, error);
				while (!toComplete->isEmpty()) {
					$var($CompletableFuture, cf, $cast($CompletableFuture, toComplete->poll()));
					$nc(exec)->execute(static_cast<$Runnable*>($$new(Http1Exchange$$Lambda$lambda$cancelImpl$9$9, this, cf, x)));
				}
			}
		} catch ($Throwable& var$4) {
			$assign(var$3, var$4);
		} /*finally*/ {
			if (!this->upgraded$) {
				$nc(this->connection$)->close();
			}
		}
		if (var$3 != nullptr) {
			$throw(var$3);
		}
	}
}

void Http1Exchange::upgraded() {
	this->upgraded$ = true;
}

void Http1Exchange::runInline($Runnable* run) {
	if (!Http1Exchange::$assertionsDisabled && ! !$nc(this->client$)->isSelectorThread()) {
		$throwNew($AssertionError);
	}
	$nc(run)->run();
}

bool Http1Exchange::isCanceled() {
	$synchronized(this->lock) {
		return this->failed != nullptr;
	}
}

$Throwable* Http1Exchange::getCancelCause() {
	$synchronized(this->lock) {
		return this->failed;
	}
}

void Http1Exchange::appendToOutgoing($Throwable* throwable) {
	appendToOutgoing($$new($Http1Exchange$DataPair, nullptr, throwable));
}

void Http1Exchange::appendToOutgoing($List* item) {
	appendToOutgoing($$new($Http1Exchange$DataPair, item, nullptr));
}

void Http1Exchange::appendToOutgoing($Http1Exchange$DataPair* dp) {
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log($$str({"appending to outgoing "_s, dp}));
	}
	$nc(this->outgoing)->add(dp);
	$nc($nc(this->writePublisher)->writeScheduler)->runOrSchedule();
}

bool Http1Exchange::hasOutgoing() {
	return !$nc(this->outgoing)->isEmpty();
}

void Http1Exchange::requestMoreBody() {
	try {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("requesting more request body from the subscriber"_s);
		}
		$nc(this->bodySubscriber)->request(1);
	} catch ($Throwable& t) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Subscription::request failed"_s, t);
		}
		cancelImpl(t);
		$nc(this->bodySentCF)->completeExceptionally(t);
	}
}

void Http1Exchange::cancelUpstreamSubscription() {
	$useLocalCurrentObjectStackCache();
	$var($Executor, exec, $nc(this->client$)->theExecutor());
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("cancelling upstream publisher"_s);
	}
	if (this->bodySubscriber != nullptr) {
		$nc(exec)->execute(static_cast<$Runnable*>($$new(Http1Exchange$$Lambda$cancelSubscription$10, static_cast<$Http1Exchange$Http1BodySubscriber*>($nc(this->bodySubscriber)))));
	} else if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("bodySubscriber is null"_s);
	}
}

$Http1Exchange$DataPair* Http1Exchange::getOutgoing() {
	$useLocalCurrentObjectStackCache();
	$var($Executor, exec, $nc(this->client$)->theExecutor());
	$var($Http1Exchange$DataPair, dp, $cast($Http1Exchange$DataPair, $nc(this->outgoing)->pollFirst()));
	if ($nc(this->writePublisher)->cancelled) {
		cancelUpstreamSubscription();
		$nc(this->headersSentCF)->completeAsync(static_cast<$Supplier*>($$new(Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11, this)), exec);
		$nc(this->bodySentCF)->completeAsync(static_cast<$Supplier*>($$new(Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11, this)), exec);
		return nullptr;
	}
	if (dp == nullptr) {
		return nullptr;
	}
	if ($nc(dp)->throwable != nullptr) {
		$synchronized(this->lock) {
			$init($Http1Exchange$State);
			$set(this, state, $Http1Exchange$State::ERROR);
		}
		$nc(exec)->execute(static_cast<$Runnable*>($$new(Http1Exchange$$Lambda$lambda$getOutgoing$12$12, this, dp)));
		return dp;
	}
	$init($Http1Exchange$1);
	switch ($nc($Http1Exchange$1::$SwitchMap$jdk$internal$net$http$Http1Exchange$State)->get($nc((this->state))->ordinal())) {
	case 1:
		{
			$synchronized(this->lock) {
				$init($Http1Exchange$State);
				$set(this, state, $Http1Exchange$State::BODY);
			}
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("initiating completion of headersSentCF"_s);
			}
			$nc(this->headersSentCF)->completeAsync(static_cast<$Supplier*>($$new(Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11, this)), exec);
			break;
		}
	case 2:
		{
			$init($Http1Exchange$Http1BodySubscriber);
			if ($nc(dp)->data == $Http1Exchange$Http1BodySubscriber::COMPLETED) {
				$synchronized(this->lock) {
					$init($Http1Exchange$State);
					$set(this, state, $Http1Exchange$State::COMPLETING);
				}
				if ($nc(this->debug)->on()) {
					$nc(this->debug)->log("initiating completion of bodySentCF"_s);
				}
				$nc(this->bodySentCF)->completeAsync(static_cast<$Supplier*>($$new(Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11, this)), exec);
			} else {
				$nc(exec)->execute(static_cast<$Runnable*>($$new(Http1Exchange$$Lambda$requestMoreBody$13, this)));
			}
			break;
		}
	case 3:
		{}
	case 4:
		{}
	case 5:
		{}
	case 6:
		{}
	default:
		{
			if (!Http1Exchange::$assertionsDisabled) {
				$throwNew($AssertionError, $of($$str({"Unexpected state:"_s, this->state})));
			}
		}
	}
	return dp;
}

$HttpClient* Http1Exchange::client() {
	return this->client$;
}

$String* Http1Exchange::dbgString() {
	return "Http1Exchange"_s;
}

void Http1Exchange::lambda$getOutgoing$12($Http1Exchange$DataPair* dp) {
	$nc(this->headersSentCF)->completeExceptionally($nc(dp)->throwable);
	$nc(this->bodySentCF)->completeExceptionally($nc(dp)->throwable);
	$nc(this->connection$)->close();
}

void Http1Exchange::lambda$cancelImpl$9($CompletableFuture* cf, $Throwable* x) {
	$useLocalCurrentObjectStackCache();
	if ($nc(cf)->completeExceptionally(x)) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("%s: completed cf with %s"_s, $$new($ObjectArray, {
				$($of($nc(this->request$)->uri())),
				$of(x)
			}));
		}
	}
}

void Http1Exchange::lambda$sendBodyAsync$8($Void* s) {
	requestMoreBody();
}

void Http1Exchange::lambda$sendBodyAsync$7($Flow$Subscription* s) {
	cancelIfFailed(s);
}

void Http1Exchange::lambda$cancelIfFailed$6($Flow$Subscription* s, $Void* r, $Throwable* t) {
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("asyncReceiver finished (failed=%s)"_s, $$new($ObjectArray, {$of(t)}));
	}
	if (t != nullptr) {
		$nc(s)->cancel();
		$nc(this->bodySentCF)->complete(this);
	}
}

$CompletionStage* Http1Exchange::lambda$sendHeadersAsync$5($Void* unused) {
	return this->headersSentCF;
}

$CompletionStage* Http1Exchange::lambda$sendHeadersAsync$4($Void* unused) {
	$useLocalCurrentObjectStackCache();
	$var($CompletableFuture, cf, $new($MinimalFuture));
	try {
		$nc($nc(this->asyncReceiver)->whenFinished)->whenComplete(static_cast<$BiConsumer*>($$new(Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14, this)));
		connectFlows(this->connection$);
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("requestAction.headers"_s);
		}
		$var($List, data, $nc(this->requestAction)->headers());
		$synchronized(this->lock) {
			$init($Http1Exchange$State);
			$set(this, state, $Http1Exchange$State::HEADERS);
		}
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("setting outgoing with headers"_s);
		}
		if (!Http1Exchange::$assertionsDisabled && !$nc(this->outgoing)->isEmpty()) {
			$throwNew($AssertionError, $of($$str({"Unexpected outgoing:"_s, this->outgoing})));
		}
		appendToOutgoing(data);
		cf->complete(nullptr);
		return cf;
	} catch ($Throwable& t) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Failed to send headers: %s"_s, t);
		}
		$nc(this->headersSentCF)->completeExceptionally(t);
		$nc(this->bodySentCF)->completeExceptionally(t);
		$nc(this->connection$)->close();
		cf->completeExceptionally(t);
		return cf;
	}
	$shouldNotReachHere();
}

void Http1Exchange::lambda$sendHeadersAsync$3($Void* r, $Throwable* t) {
	$useLocalCurrentObjectStackCache();
	if (t != nullptr) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("asyncReceiver finished (failed=%s)"_s, $$new($ObjectArray, {$of(t)}));
		}
		if (!$nc(this->headersSentCF)->isDone()) {
			$nc(this->headersSentCF)->completeAsync(static_cast<$Supplier*>($$new(Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11, this)), this->executor);
		}
	}
}

$ExchangeImpl* Http1Exchange::lambda$sendHeadersAsync$2() {
	return this;
}

void Http1Exchange::lambda$sendHeadersAsync$1($CompletableFuture* connectCF, $Throwable* cancelled) {
	$init(Http1Exchange);
	$nc(connectCF)->completeExceptionally(cancelled);
}

$CompletionStage* Http1Exchange::lambda$sendHeadersAsync$0($Void* unused) {
	return $nc(this->connection$)->finishConnect();
}

void clinit$Http1Exchange($Class* class$) {
	Http1Exchange::$assertionsDisabled = !Http1Exchange::class$->desiredAssertionStatus();
}

Http1Exchange::Http1Exchange() {
}

$Class* Http1Exchange::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Http1Exchange$$Lambda$dbgString::classInfo$.name)) {
			return Http1Exchange$$Lambda$dbgString::load$(name, initialize);
		}
		if (name->equals(Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1::classInfo$.name)) {
			return Http1Exchange$$Lambda$lambda$sendHeadersAsync$0$1::load$(name, initialize);
		}
		if (name->equals(Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2::classInfo$.name)) {
			return Http1Exchange$$Lambda$lambda$sendHeadersAsync$1$2::load$(name, initialize);
		}
		if (name->equals(Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3::classInfo$.name)) {
			return Http1Exchange$$Lambda$lambda$sendHeadersAsync$4$3::load$(name, initialize);
		}
		if (name->equals(Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4::classInfo$.name)) {
			return Http1Exchange$$Lambda$lambda$sendHeadersAsync$5$4::load$(name, initialize);
		}
		if (name->equals(Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5::classInfo$.name)) {
			return Http1Exchange$$Lambda$lambda$cancelIfFailed$6$5::load$(name, initialize);
		}
		if (name->equals(Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6::classInfo$.name)) {
			return Http1Exchange$$Lambda$lambda$sendBodyAsync$7$6::load$(name, initialize);
		}
		if (name->equals(Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7::classInfo$.name)) {
			return Http1Exchange$$Lambda$lambda$sendBodyAsync$8$7::load$(name, initialize);
		}
		if (name->equals(Http1Exchange$$Lambda$runInline$8::classInfo$.name)) {
			return Http1Exchange$$Lambda$runInline$8::load$(name, initialize);
		}
		if (name->equals(Http1Exchange$$Lambda$lambda$cancelImpl$9$9::classInfo$.name)) {
			return Http1Exchange$$Lambda$lambda$cancelImpl$9$9::load$(name, initialize);
		}
		if (name->equals(Http1Exchange$$Lambda$cancelSubscription$10::classInfo$.name)) {
			return Http1Exchange$$Lambda$cancelSubscription$10::load$(name, initialize);
		}
		if (name->equals(Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11::classInfo$.name)) {
			return Http1Exchange$$Lambda$lambda$sendHeadersAsync$2$11::load$(name, initialize);
		}
		if (name->equals(Http1Exchange$$Lambda$lambda$getOutgoing$12$12::classInfo$.name)) {
			return Http1Exchange$$Lambda$lambda$getOutgoing$12$12::load$(name, initialize);
		}
		if (name->equals(Http1Exchange$$Lambda$requestMoreBody$13::classInfo$.name)) {
			return Http1Exchange$$Lambda$requestMoreBody$13::load$(name, initialize);
		}
		if (name->equals(Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14::classInfo$.name)) {
			return Http1Exchange$$Lambda$lambda$sendHeadersAsync$3$14::load$(name, initialize);
		}
	}
	$loadClass(Http1Exchange, name, initialize, &_Http1Exchange_ClassInfo_, clinit$Http1Exchange, allocate$Http1Exchange);
	return class$;
}

$Class* Http1Exchange::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk