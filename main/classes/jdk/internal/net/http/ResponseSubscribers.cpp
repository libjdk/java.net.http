#include <jdk/internal/net/http/ResponseSubscribers.h>

#include <java/io/BufferedReader.h>
#include <java/io/Closeable.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/Reader.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/stream/BaseStream.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/net/http/HttpClientImpl$DelegatingExecutor.h>
#include <jdk/internal/net/http/ResponseSubscribers$HttpResponseInputStream.h>
#include <jdk/internal/net/http/ResponseSubscribers$MappingSubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef UTF_8

using $CloseableArray = $Array<::java::io::Closeable>;
using $BufferedReader = ::java::io::BufferedReader;
using $Closeable = ::java::io::Closeable;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $Reader = ::java::io::Reader;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $Objects = ::java::util::Objects;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Executor = ::java::util::concurrent::Executor;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $BaseStream = ::java::util::stream::BaseStream;
using $Stream = ::java::util::stream::Stream;
using $HttpClientImpl$DelegatingExecutor = ::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor;
using $ResponseSubscribers$HttpResponseInputStream = ::jdk::internal::net::http::ResponseSubscribers$HttpResponseInputStream;
using $ResponseSubscribers$MappingSubscriber = ::jdk::internal::net::http::ResponseSubscribers$MappingSubscriber;
using $ResponseSubscribers$PublishingBodySubscriber = ::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber;
using $ResponseSubscribers$TrustedSubscriber = ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class ResponseSubscribers$$Lambda$lambda$createLineStream$1 : public $Function {
	$class(ResponseSubscribers$$Lambda$lambda$createLineStream$1, $NO_CLASS_INIT, $Function)
public:
	void init$($Charset* charset) {
		$set(this, charset, charset);
	}
	virtual $Object* apply(Object$* stream) override {
		 return $of(ResponseSubscribers::lambda$createLineStream$1(charset, $cast($InputStream, stream)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseSubscribers$$Lambda$lambda$createLineStream$1>());
	}
	$Charset* charset = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseSubscribers$$Lambda$lambda$createLineStream$1::fieldInfos[2] = {
	{"charset", "Ljava/nio/charset/Charset;", nullptr, $PUBLIC, $field(ResponseSubscribers$$Lambda$lambda$createLineStream$1, charset)},
	{}
};
$MethodInfo ResponseSubscribers$$Lambda$lambda$createLineStream$1::methodInfos[3] = {
	{"<init>", "(Ljava/nio/charset/Charset;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$$Lambda$lambda$createLineStream$1::*)($Charset*)>(&ResponseSubscribers$$Lambda$lambda$createLineStream$1::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseSubscribers$$Lambda$lambda$createLineStream$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseSubscribers$$Lambda$lambda$createLineStream$1",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* ResponseSubscribers$$Lambda$lambda$createLineStream$1::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$$Lambda$lambda$createLineStream$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseSubscribers$$Lambda$lambda$createLineStream$1::class$ = nullptr;

class ResponseSubscribers$$Lambda$completeExceptionally$1 : public $Consumer {
	$class(ResponseSubscribers$$Lambda$completeExceptionally$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$($CompletableFuture* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* arg0) override {
		$nc(inst$)->completeExceptionally($cast($Throwable, arg0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseSubscribers$$Lambda$completeExceptionally$1>());
	}
	$CompletableFuture* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseSubscribers$$Lambda$completeExceptionally$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ResponseSubscribers$$Lambda$completeExceptionally$1, inst$)},
	{}
};
$MethodInfo ResponseSubscribers$$Lambda$completeExceptionally$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/concurrent/CompletableFuture;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$$Lambda$completeExceptionally$1::*)($CompletableFuture*)>(&ResponseSubscribers$$Lambda$completeExceptionally$1::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseSubscribers$$Lambda$completeExceptionally$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseSubscribers$$Lambda$completeExceptionally$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ResponseSubscribers$$Lambda$completeExceptionally$1::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$$Lambda$completeExceptionally$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseSubscribers$$Lambda$completeExceptionally$1::class$ = nullptr;

class ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2 : public $Runnable {
	$class(ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2, $NO_CLASS_INIT, $Runnable)
public:
	void init$($HttpResponse$BodySubscriber* bs, $CompletableFuture* cf, $Consumer* errorHandler) {
		$set(this, bs, bs);
		$set(this, cf, cf);
		$set(this, errorHandler, errorHandler);
	}
	virtual void run() override {
		ResponseSubscribers::lambda$getBodyAsync$3(bs, cf, errorHandler);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2>());
	}
	$HttpResponse$BodySubscriber* bs = nullptr;
	$CompletableFuture* cf = nullptr;
	$Consumer* errorHandler = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2::fieldInfos[4] = {
	{"bs", "Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC, $field(ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2, bs)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", nullptr, $PUBLIC, $field(ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2, cf)},
	{"errorHandler", "Ljava/util/function/Consumer;", nullptr, $PUBLIC, $field(ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2, errorHandler)},
	{}
};
$MethodInfo ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2::methodInfos[3] = {
	{"<init>", "(Ljava/net/http/HttpResponse$BodySubscriber;Ljava/util/concurrent/CompletableFuture;Ljava/util/function/Consumer;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2::*)($HttpResponse$BodySubscriber*,$CompletableFuture*,$Consumer*)>(&ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2::class$ = nullptr;

class ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3 : public $BiConsumer {
	$class(ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($CompletableFuture* cf) {
		$set(this, cf, cf);
	}
	virtual void accept(Object$* r, Object$* t) override {
		ResponseSubscribers::lambda$getBodyAsync$2(cf, r, $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3>());
	}
	$CompletableFuture* cf = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3::fieldInfos[2] = {
	{"cf", "Ljava/util/concurrent/CompletableFuture;", nullptr, $PUBLIC, $field(ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3, cf)},
	{}
};
$MethodInfo ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3::methodInfos[3] = {
	{"<init>", "(Ljava/util/concurrent/CompletableFuture;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3::*)($CompletableFuture*)>(&ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3::class$ = nullptr;

class ResponseSubscribers$$Lambda$lambda$createLineStream$0$4 : public $Runnable {
	$class(ResponseSubscribers$$Lambda$lambda$createLineStream$0$4, $NO_CLASS_INIT, $Runnable)
public:
	void init$($InputStream* stream) {
		$set(this, stream, stream);
	}
	virtual void run() override {
		ResponseSubscribers::lambda$createLineStream$0(stream);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseSubscribers$$Lambda$lambda$createLineStream$0$4>());
	}
	$InputStream* stream = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseSubscribers$$Lambda$lambda$createLineStream$0$4::fieldInfos[2] = {
	{"stream", "Ljava/io/InputStream;", nullptr, $PUBLIC, $field(ResponseSubscribers$$Lambda$lambda$createLineStream$0$4, stream)},
	{}
};
$MethodInfo ResponseSubscribers$$Lambda$lambda$createLineStream$0$4::methodInfos[3] = {
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$$Lambda$lambda$createLineStream$0$4::*)($InputStream*)>(&ResponseSubscribers$$Lambda$lambda$createLineStream$0$4::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseSubscribers$$Lambda$lambda$createLineStream$0$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseSubscribers$$Lambda$lambda$createLineStream$0$4",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* ResponseSubscribers$$Lambda$lambda$createLineStream$0$4::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$$Lambda$lambda$createLineStream$0$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseSubscribers$$Lambda$lambda$createLineStream$0$4::class$ = nullptr;

$FieldInfo _ResponseSubscribers_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ResponseSubscribers, $assertionsDisabled)},
	{}
};

$MethodInfo _ResponseSubscribers_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers::*)()>(&ResponseSubscribers::init$))},
	{"createLineStream", "()Ljava/net/http/HttpResponse$BodySubscriber;", "()Ljava/net/http/HttpResponse$BodySubscriber<Ljava/util/stream/Stream<Ljava/lang/String;>;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)()>(&ResponseSubscribers::createLineStream))},
	{"createLineStream", "(Ljava/nio/charset/Charset;)Ljava/net/http/HttpResponse$BodySubscriber;", "(Ljava/nio/charset/Charset;)Ljava/net/http/HttpResponse$BodySubscriber<Ljava/util/stream/Stream<Ljava/lang/String;>;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Charset*)>(&ResponseSubscribers::createLineStream))},
	{"createPublisher", "()Ljava/net/http/HttpResponse$BodySubscriber;", "()Ljava/net/http/HttpResponse$BodySubscriber<Ljava/util/concurrent/Flow$Publisher<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)()>(&ResponseSubscribers::createPublisher))},
	{"getBodyAsync", "(Ljava/util/concurrent/Executor;Ljava/net/http/HttpResponse$BodySubscriber;)Ljava/util/concurrent/CompletionStage;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/Executor;Ljava/net/http/HttpResponse$BodySubscriber<TT;>;)Ljava/util/concurrent/CompletionStage<TT;>;", $PUBLIC | $STATIC, $method(static_cast<$CompletionStage*(*)($Executor*,$HttpResponse$BodySubscriber*)>(&ResponseSubscribers::getBodyAsync))},
	{"getBodyAsync", "(Ljava/util/concurrent/Executor;Ljava/net/http/HttpResponse$BodySubscriber;Ljava/util/concurrent/CompletableFuture;)Ljava/util/concurrent/CompletableFuture;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/Executor;Ljava/net/http/HttpResponse$BodySubscriber<TT;>;Ljava/util/concurrent/CompletableFuture<TT;>;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC | $STATIC, $method(static_cast<$CompletableFuture*(*)($Executor*,$HttpResponse$BodySubscriber*,$CompletableFuture*)>(&ResponseSubscribers::getBodyAsync))},
	{"getBodyAsync", "(Ljava/util/concurrent/Executor;Ljava/net/http/HttpResponse$BodySubscriber;Ljava/util/concurrent/CompletableFuture;Ljava/util/function/Consumer;)Ljava/util/concurrent/CompletableFuture;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/Executor;Ljava/net/http/HttpResponse$BodySubscriber<TT;>;Ljava/util/concurrent/CompletableFuture<TT;>;Ljava/util/function/Consumer<Ljava/lang/Throwable;>;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC | $STATIC, $method(static_cast<$CompletableFuture*(*)($Executor*,$HttpResponse$BodySubscriber*,$CompletableFuture*,$Consumer*)>(&ResponseSubscribers::getBodyAsync))},
	{"lambda$createLineStream$0", "(Ljava/io/InputStream;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($InputStream*)>(&ResponseSubscribers::lambda$createLineStream$0))},
	{"lambda$createLineStream$1", "(Ljava/nio/charset/Charset;Ljava/io/InputStream;)Ljava/util/stream/Stream;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Stream*(*)($Charset*,$InputStream*)>(&ResponseSubscribers::lambda$createLineStream$1))},
	{"lambda$getBodyAsync$2", "(Ljava/util/concurrent/CompletableFuture;Ljava/lang/Object;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($CompletableFuture*,Object$*,$Throwable*)>(&ResponseSubscribers::lambda$getBodyAsync$2))},
	{"lambda$getBodyAsync$3", "(Ljava/net/http/HttpResponse$BodySubscriber;Ljava/util/concurrent/CompletableFuture;Ljava/util/function/Consumer;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($HttpResponse$BodySubscriber*,$CompletableFuture*,$Consumer*)>(&ResponseSubscribers::lambda$getBodyAsync$3))},
	{}
};

$InnerClassInfo _ResponseSubscribers_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber", "jdk.internal.net.http.ResponseSubscribers", "PublishingBodySubscriber", $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$MappingSubscriber", "jdk.internal.net.http.ResponseSubscribers", "MappingSubscriber", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$SubscriberAdapter", "jdk.internal.net.http.ResponseSubscribers", "SubscriberAdapter", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.net.http.ResponseSubscribers$NullSubscriber", "jdk.internal.net.http.ResponseSubscribers", "NullSubscriber", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$HttpResponseInputStream", "jdk.internal.net.http.ResponseSubscribers", "HttpResponseInputStream", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$ByteArraySubscriber", "jdk.internal.net.http.ResponseSubscribers", "ByteArraySubscriber", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$PathSubscriber", "jdk.internal.net.http.ResponseSubscribers", "PathSubscriber", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$ConsumerSubscriber", "jdk.internal.net.http.ResponseSubscribers", "ConsumerSubscriber", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber", "jdk.internal.net.http.ResponseSubscribers", "TrustedSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseSubscribers_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.ResponseSubscribers",
	"java.lang.Object",
	nullptr,
	_ResponseSubscribers_FieldInfo_,
	_ResponseSubscribers_MethodInfo_,
	nullptr,
	nullptr,
	_ResponseSubscribers_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber,jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef,jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$SubscriberRef,jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$1,jdk.internal.net.http.ResponseSubscribers$MappingSubscriber,jdk.internal.net.http.ResponseSubscribers$SubscriberAdapter,jdk.internal.net.http.ResponseSubscribers$NullSubscriber,jdk.internal.net.http.ResponseSubscribers$HttpResponseInputStream,jdk.internal.net.http.ResponseSubscribers$ByteArraySubscriber,jdk.internal.net.http.ResponseSubscribers$PathSubscriber,jdk.internal.net.http.ResponseSubscribers$ConsumerSubscriber,jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber"
};

$Object* allocate$ResponseSubscribers($Class* clazz) {
	return $of($alloc(ResponseSubscribers));
}

bool ResponseSubscribers::$assertionsDisabled = false;

void ResponseSubscribers::init$() {
}

$HttpResponse$BodySubscriber* ResponseSubscribers::createLineStream() {
	$init(ResponseSubscribers);
	$init($StandardCharsets);
	return createLineStream($StandardCharsets::UTF_8);
}

$HttpResponse$BodySubscriber* ResponseSubscribers::createLineStream($Charset* charset) {
	$init(ResponseSubscribers);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(charset);
	$var($HttpResponse$BodySubscriber, s, $new($ResponseSubscribers$HttpResponseInputStream));
	return $new($ResponseSubscribers$MappingSubscriber, s, static_cast<$Function*>($$new(ResponseSubscribers$$Lambda$lambda$createLineStream$1, charset)), true);
}

$HttpResponse$BodySubscriber* ResponseSubscribers::createPublisher() {
	$init(ResponseSubscribers);
	return $new($ResponseSubscribers$PublishingBodySubscriber);
}

$CompletionStage* ResponseSubscribers::getBodyAsync($Executor* e, $HttpResponse$BodySubscriber* bs) {
	$init(ResponseSubscribers);
	if ($ResponseSubscribers$TrustedSubscriber::needsExecutor(bs)) {
		return getBodyAsync(e, bs, $$new($MinimalFuture));
	} else {
		return $nc(bs)->getBody();
	}
}

$CompletableFuture* ResponseSubscribers::getBodyAsync($Executor* e, $HttpResponse$BodySubscriber* bs, $CompletableFuture* cf) {
	$init(ResponseSubscribers);
	return getBodyAsync(e, bs, cf, static_cast<$Consumer*>($$new(ResponseSubscribers$$Lambda$completeExceptionally$1, static_cast<$CompletableFuture*>($nc(cf)))));
}

$CompletableFuture* ResponseSubscribers::getBodyAsync($Executor* e$renamed, $HttpResponse$BodySubscriber* bs, $CompletableFuture* cf, $Consumer* errorHandler) {
	$init(ResponseSubscribers);
	$useLocalCurrentObjectStackCache();
	$var($Executor, e, e$renamed);
	if (!ResponseSubscribers::$assertionsDisabled && !(errorHandler != nullptr)) {
		$throwNew($AssertionError);
	}
	try {
		if (!ResponseSubscribers::$assertionsDisabled && !(e != nullptr)) {
			$throwNew($AssertionError);
		}
		if (!ResponseSubscribers::$assertionsDisabled && !(cf != nullptr)) {
			$throwNew($AssertionError);
		}
		if ($ResponseSubscribers$TrustedSubscriber::needsExecutor(bs)) {
			$assign(e, ($instanceOf($HttpClientImpl$DelegatingExecutor, e)) ? $nc(($cast($HttpClientImpl$DelegatingExecutor, e)))->delegate() : e);
		}
		$nc(e)->execute(static_cast<$Runnable*>($$new(ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2, bs, cf, errorHandler)));
		return cf;
	} catch ($Throwable& t) {
		$nc(errorHandler)->accept(t);
	}
	return cf;
}

void ResponseSubscribers::lambda$getBodyAsync$3($HttpResponse$BodySubscriber* bs, $CompletableFuture* cf, $Consumer* errorHandler) {
	$init(ResponseSubscribers);
	$useLocalCurrentObjectStackCache();
	try {
		$nc($($nc(bs)->getBody()))->whenComplete(static_cast<$BiConsumer*>($$new(ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3, cf)));
	} catch ($Throwable& t) {
		$nc(errorHandler)->accept(t);
	}
}

void ResponseSubscribers::lambda$getBodyAsync$2($CompletableFuture* cf, Object$* r, $Throwable* t) {
	$init(ResponseSubscribers);
	if (t != nullptr) {
		$nc(cf)->completeExceptionally(t);
	} else {
		$nc(cf)->complete(r);
	}
}

$Stream* ResponseSubscribers::lambda$createLineStream$1($Charset* charset, $InputStream* stream) {
	$init(ResponseSubscribers);
	$useLocalCurrentObjectStackCache();
	return $cast($Stream, $nc($($$new($BufferedReader, $$new($InputStreamReader, stream, charset))->lines()))->onClose(static_cast<$Runnable*>($$new(ResponseSubscribers$$Lambda$lambda$createLineStream$0$4, stream))));
}

void ResponseSubscribers::lambda$createLineStream$0($InputStream* stream) {
	$init(ResponseSubscribers);
	$Utils::close($$new($CloseableArray, {static_cast<$Closeable*>(stream)}));
}

void clinit$ResponseSubscribers($Class* class$) {
	ResponseSubscribers::$assertionsDisabled = !ResponseSubscribers::class$->desiredAssertionStatus();
}

ResponseSubscribers::ResponseSubscribers() {
}

$Class* ResponseSubscribers::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ResponseSubscribers$$Lambda$lambda$createLineStream$1::classInfo$.name)) {
			return ResponseSubscribers$$Lambda$lambda$createLineStream$1::load$(name, initialize);
		}
		if (name->equals(ResponseSubscribers$$Lambda$completeExceptionally$1::classInfo$.name)) {
			return ResponseSubscribers$$Lambda$completeExceptionally$1::load$(name, initialize);
		}
		if (name->equals(ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2::classInfo$.name)) {
			return ResponseSubscribers$$Lambda$lambda$getBodyAsync$3$2::load$(name, initialize);
		}
		if (name->equals(ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3::classInfo$.name)) {
			return ResponseSubscribers$$Lambda$lambda$getBodyAsync$2$3::load$(name, initialize);
		}
		if (name->equals(ResponseSubscribers$$Lambda$lambda$createLineStream$0$4::classInfo$.name)) {
			return ResponseSubscribers$$Lambda$lambda$createLineStream$0$4::load$(name, initialize);
		}
	}
	$loadClass(ResponseSubscribers, name, initialize, &_ResponseSubscribers_ClassInfo_, clinit$ResponseSubscribers, allocate$ResponseSubscribers);
	return class$;
}

$Class* ResponseSubscribers::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk