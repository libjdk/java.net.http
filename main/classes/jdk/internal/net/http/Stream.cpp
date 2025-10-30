#include <jdk/internal/net/http/Stream.h>

#include <java/io/EOFException.h>
#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/Math.h>
#include <java/lang/Runnable.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/VarHandle.h>
#include <java/net/URI.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpClient.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpRequest$BodyPublisher.h>
#include <java/net/http/HttpRequest.h>
#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/net/http/HttpResponse$BodySubscribers.h>
#include <java/net/http/HttpResponse$ResponseInfo.h>
#include <java/net/http/HttpResponse.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Optional.h>
#include <java/util/OptionalLong.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/ConcurrentLinkedQueue.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicReference.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiPredicate.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/ExchangeImpl.h>
#include <jdk/internal/net/http/Http2Connection$ConnectionWindowUpdateSender.h>
#include <jdk/internal/net/http/Http2Connection$ValidatingHeadersConsumer.h>
#include <jdk/internal/net/http/Http2Connection.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/PushGroup$Acceptor.h>
#include <jdk/internal/net/http/PushGroup.h>
#include <jdk/internal/net/http/Response.h>
#include <jdk/internal/net/http/ResponseInfoImpl.h>
#include <jdk/internal/net/http/ResponseSubscribers.h>
#include <jdk/internal/net/http/Stream$HeadersConsumer.h>
#include <jdk/internal/net/http/Stream$PushedStream.h>
#include <jdk/internal/net/http/Stream$RequestSubscriber.h>
#include <jdk/internal/net/http/Stream$StreamWindowUpdateSender.h>
#include <jdk/internal/net/http/WindowController.h>
#include <jdk/internal/net/http/WindowUpdateSender.h>
#include <jdk/internal/net/http/common/HttpHeadersBuilder.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/SubscriptionBase.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/frame/DataFrame.h>
#include <jdk/internal/net/http/frame/ErrorFrame.h>
#include <jdk/internal/net/http/frame/HeaderFrame.h>
#include <jdk/internal/net/http/frame/HeadersFrame.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jdk/internal/net/http/frame/OutgoingHeaders.h>
#include <jdk/internal/net/http/frame/PriorityFrame.h>
#include <jdk/internal/net/http/frame/ResetFrame.h>
#include <jdk/internal/net/http/frame/WindowUpdateFrame.h>
#include <jdk/internal/net/http/hpack/DecodingCallback.h>
#include <jcpp.h>

#undef CANCEL
#undef COMPLETED
#undef DEBUG
#undef DEREGISTERED
#undef END_STREAM
#undef FLOW_CONTROL_ERROR
#undef HTTP_2
#undef MAX_VALUE
#undef PROXY_FILTER
#undef PROXY_TUNNEL_FILTER
#undef REFUSED_STREAM
#undef STREAM_CLOSED
#undef STREAM_STATE
#undef TYPE

using $EOFException = ::java::io::EOFException;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Runnable = ::java::lang::Runnable;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $URI = ::java::net::URI;
using $HttpClient = ::java::net::http::HttpClient;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $HttpResponse = ::java::net::http::HttpResponse;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $HttpResponse$BodySubscribers = ::java::net::http::HttpResponse$BodySubscribers;
using $HttpResponse$ResponseInfo = ::java::net::http::HttpResponse$ResponseInfo;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AbstractList = ::java::util::AbstractList;
using $AbstractQueue = ::java::util::AbstractQueue;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Optional = ::java::util::Optional;
using $OptionalLong = ::java::util::OptionalLong;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $ConcurrentLinkedQueue = ::java::util::concurrent::ConcurrentLinkedQueue;
using $Executor = ::java::util::concurrent::Executor;
using $Flow$Publisher = ::java::util::concurrent::Flow$Publisher;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicReference = ::java::util::concurrent::atomic::AtomicReference;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiPredicate = ::java::util::function::BiPredicate;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $ExchangeImpl = ::jdk::internal::net::http::ExchangeImpl;
using $Http2Connection = ::jdk::internal::net::http::Http2Connection;
using $Http2Connection$ConnectionWindowUpdateSender = ::jdk::internal::net::http::Http2Connection$ConnectionWindowUpdateSender;
using $Http2Connection$ValidatingHeadersConsumer = ::jdk::internal::net::http::Http2Connection$ValidatingHeadersConsumer;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;
using $PushGroup = ::jdk::internal::net::http::PushGroup;
using $PushGroup$Acceptor = ::jdk::internal::net::http::PushGroup$Acceptor;
using $Response = ::jdk::internal::net::http::Response;
using $ResponseInfoImpl = ::jdk::internal::net::http::ResponseInfoImpl;
using $ResponseSubscribers = ::jdk::internal::net::http::ResponseSubscribers;
using $Stream$HeadersConsumer = ::jdk::internal::net::http::Stream$HeadersConsumer;
using $Stream$PushedStream = ::jdk::internal::net::http::Stream$PushedStream;
using $Stream$RequestSubscriber = ::jdk::internal::net::http::Stream$RequestSubscriber;
using $Stream$StreamWindowUpdateSender = ::jdk::internal::net::http::Stream$StreamWindowUpdateSender;
using $WindowController = ::jdk::internal::net::http::WindowController;
using $WindowUpdateSender = ::jdk::internal::net::http::WindowUpdateSender;
using $HttpHeadersBuilder = ::jdk::internal::net::http::common::HttpHeadersBuilder;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SubscriptionBase = ::jdk::internal::net::http::common::SubscriptionBase;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $DataFrame = ::jdk::internal::net::http::frame::DataFrame;
using $ErrorFrame = ::jdk::internal::net::http::frame::ErrorFrame;
using $HeaderFrame = ::jdk::internal::net::http::frame::HeaderFrame;
using $HeadersFrame = ::jdk::internal::net::http::frame::HeadersFrame;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;
using $OutgoingHeaders = ::jdk::internal::net::http::frame::OutgoingHeaders;
using $PriorityFrame = ::jdk::internal::net::http::frame::PriorityFrame;
using $ResetFrame = ::jdk::internal::net::http::frame::ResetFrame;
using $WindowUpdateFrame = ::jdk::internal::net::http::frame::WindowUpdateFrame;
using $DecodingCallback = ::jdk::internal::net::http::hpack::DecodingCallback;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Stream$$Lambda$dbgString : public $Supplier {
	$class(Stream$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Stream* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$dbgString>());
	}
	Stream* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Stream$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo Stream$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Stream;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$$Lambda$dbgString::*)(Stream*)>(&Stream$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$dbgString::class$ = nullptr;

class Stream$$Lambda$schedule$1 : public $Runnable {
	$class(Stream$$Lambda$schedule$1, $NO_CLASS_INIT, $Runnable)
public:
	void init$(Stream* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->schedule();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$schedule$1>());
	}
	Stream* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$schedule$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Stream$$Lambda$schedule$1, inst$)},
	{}
};
$MethodInfo Stream$$Lambda$schedule$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Stream;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$$Lambda$schedule$1::*)(Stream*)>(&Stream$$Lambda$schedule$1::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$$Lambda$schedule$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$$Lambda$schedule$1",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$schedule$1::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$schedule$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$schedule$1::class$ = nullptr;

class Stream$$Lambda$cancel$2 : public $Runnable {
	$class(Stream$$Lambda$cancel$2, $NO_CLASS_INIT, $Runnable)
public:
	void init$(Stream* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->cancel();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$cancel$2>());
	}
	Stream* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$cancel$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Stream$$Lambda$cancel$2, inst$)},
	{}
};
$MethodInfo Stream$$Lambda$cancel$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Stream;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$$Lambda$cancel$2::*)(Stream*)>(&Stream$$Lambda$cancel$2::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$$Lambda$cancel$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$$Lambda$cancel$2",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$cancel$2::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$cancel$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$cancel$2::class$ = nullptr;

class Stream$$Lambda$onSubscriptionError$3 : public $Consumer {
	$class(Stream$$Lambda$onSubscriptionError$3, $NO_CLASS_INIT, $Consumer)
public:
	void init$(Stream* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* t) override {
		$nc(inst$)->onSubscriptionError($cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$onSubscriptionError$3>());
	}
	Stream* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$onSubscriptionError$3::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Stream$$Lambda$onSubscriptionError$3, inst$)},
	{}
};
$MethodInfo Stream$$Lambda$onSubscriptionError$3::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Stream;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$$Lambda$onSubscriptionError$3::*)(Stream*)>(&Stream$$Lambda$onSubscriptionError$3::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$$Lambda$onSubscriptionError$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$$Lambda$onSubscriptionError$3",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$onSubscriptionError$3::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$onSubscriptionError$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$onSubscriptionError$3::class$ = nullptr;

class Stream$$Lambda$lambda$readBodyAsync$0$4 : public $BiConsumer {
	$class(Stream$$Lambda$lambda$readBodyAsync$0$4, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($PushGroup* pg) {
		$set(this, pg, pg);
	}
	virtual void accept(Object$* t, Object$* e) override {
		Stream::lambda$readBodyAsync$0(pg, t, $cast($Throwable, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$lambda$readBodyAsync$0$4>());
	}
	$PushGroup* pg = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$lambda$readBodyAsync$0$4::fieldInfos[2] = {
	{"pg", "Ljdk/internal/net/http/PushGroup;", nullptr, $PUBLIC, $field(Stream$$Lambda$lambda$readBodyAsync$0$4, pg)},
	{}
};
$MethodInfo Stream$$Lambda$lambda$readBodyAsync$0$4::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/PushGroup;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$$Lambda$lambda$readBodyAsync$0$4::*)($PushGroup*)>(&Stream$$Lambda$lambda$readBodyAsync$0$4::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$$Lambda$lambda$readBodyAsync$0$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$$Lambda$lambda$readBodyAsync$0$4",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$lambda$readBodyAsync$0$4::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$lambda$readBodyAsync$0$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$lambda$readBodyAsync$0$4::class$ = nullptr;

class Stream$$Lambda$cancelImpl$5 : public $Consumer {
	$class(Stream$$Lambda$cancelImpl$5, $NO_CLASS_INIT, $Consumer)
public:
	void init$(Stream* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* e) override {
		$nc(inst$)->cancelImpl($cast($Throwable, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$cancelImpl$5>());
	}
	Stream* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$cancelImpl$5::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Stream$$Lambda$cancelImpl$5, inst$)},
	{}
};
$MethodInfo Stream$$Lambda$cancelImpl$5::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Stream;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$$Lambda$cancelImpl$5::*)(Stream*)>(&Stream$$Lambda$cancelImpl$5::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$$Lambda$cancelImpl$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$$Lambda$cancelImpl$5",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$cancelImpl$5::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$cancelImpl$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$cancelImpl$5::class$ = nullptr;

class Stream$$Lambda$lambda$sendBodyAsync$1$6 : public $Function {
	$class(Stream$$Lambda$lambda$sendBodyAsync$1$6, $NO_CLASS_INIT, $Function)
public:
	void init$(Stream* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* v) override {
		 return $of($nc(inst$)->lambda$sendBodyAsync$1($cast($Void, v)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$lambda$sendBodyAsync$1$6>());
	}
	Stream* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$lambda$sendBodyAsync$1$6::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Stream$$Lambda$lambda$sendBodyAsync$1$6, inst$)},
	{}
};
$MethodInfo Stream$$Lambda$lambda$sendBodyAsync$1$6::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Stream;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$$Lambda$lambda$sendBodyAsync$1$6::*)(Stream*)>(&Stream$$Lambda$lambda$sendBodyAsync$1$6::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$$Lambda$lambda$sendBodyAsync$1$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$$Lambda$lambda$sendBodyAsync$1$6",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$lambda$sendBodyAsync$1$6::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$lambda$sendBodyAsync$1$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$lambda$sendBodyAsync$1$6::class$ = nullptr;

class Stream$$Lambda$lambda$handleResponse$2$7 : public $Supplier {
	$class(Stream$$Lambda$lambda$handleResponse$2$7, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(Stream::lambda$handleResponse$2());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$lambda$handleResponse$2$7>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Stream$$Lambda$lambda$handleResponse$2$7::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Stream$$Lambda$lambda$handleResponse$2$7::*)()>(&Stream$$Lambda$lambda$handleResponse$2$7::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$$Lambda$lambda$handleResponse$2$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$$Lambda$lambda$handleResponse$2$7",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Stream$$Lambda$lambda$handleResponse$2$7::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$lambda$handleResponse$2$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$lambda$handleResponse$2$7::class$ = nullptr;

class Stream$$Lambda$lambda$incoming_pushPromise$3$8 : public $BiConsumer {
	$class(Stream$$Lambda$lambda$incoming_pushPromise$3$8, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($Stream$PushedStream* pushStream, $PushGroup* pushGroup, $CompletableFuture* pushResponseCF) {
		$set(this, pushStream, pushStream);
		$set(this, pushGroup, pushGroup);
		$set(this, pushResponseCF, pushResponseCF);
	}
	virtual void accept(Object$* resp, Object$* t) override {
		Stream::lambda$incoming_pushPromise$3(pushStream, pushGroup, pushResponseCF, $cast($HttpResponse, resp), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$lambda$incoming_pushPromise$3$8>());
	}
	$Stream$PushedStream* pushStream = nullptr;
	$PushGroup* pushGroup = nullptr;
	$CompletableFuture* pushResponseCF = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$lambda$incoming_pushPromise$3$8::fieldInfos[4] = {
	{"pushStream", "Ljdk/internal/net/http/Stream$PushedStream;", nullptr, $PUBLIC, $field(Stream$$Lambda$lambda$incoming_pushPromise$3$8, pushStream)},
	{"pushGroup", "Ljdk/internal/net/http/PushGroup;", nullptr, $PUBLIC, $field(Stream$$Lambda$lambda$incoming_pushPromise$3$8, pushGroup)},
	{"pushResponseCF", "Ljava/util/concurrent/CompletableFuture;", nullptr, $PUBLIC, $field(Stream$$Lambda$lambda$incoming_pushPromise$3$8, pushResponseCF)},
	{}
};
$MethodInfo Stream$$Lambda$lambda$incoming_pushPromise$3$8::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Stream$PushedStream;Ljdk/internal/net/http/PushGroup;Ljava/util/concurrent/CompletableFuture;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$$Lambda$lambda$incoming_pushPromise$3$8::*)($Stream$PushedStream*,$PushGroup*,$CompletableFuture*)>(&Stream$$Lambda$lambda$incoming_pushPromise$3$8::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$$Lambda$lambda$incoming_pushPromise$3$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$$Lambda$lambda$incoming_pushPromise$3$8",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$lambda$incoming_pushPromise$3$8::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$lambda$incoming_pushPromise$3$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$lambda$incoming_pushPromise$3$8::class$ = nullptr;

class Stream$$Lambda$lambda$headerFrame$4$9 : public $BiPredicate {
	$class(Stream$$Lambda$lambda$headerFrame$4$9, $NO_CLASS_INIT, $BiPredicate)
public:
	void init$($HttpHeaders* uh) {
		$set(this, uh, uh);
	}
	virtual bool test(Object$* k, Object$* v) override {
		 return Stream::lambda$headerFrame$4(uh, $cast($String, k), $cast($String, v));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$lambda$headerFrame$4$9>());
	}
	$HttpHeaders* uh = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$lambda$headerFrame$4$9::fieldInfos[2] = {
	{"uh", "Ljava/net/http/HttpHeaders;", nullptr, $PUBLIC, $field(Stream$$Lambda$lambda$headerFrame$4$9, uh)},
	{}
};
$MethodInfo Stream$$Lambda$lambda$headerFrame$4$9::methodInfos[3] = {
	{"<init>", "(Ljava/net/http/HttpHeaders;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$$Lambda$lambda$headerFrame$4$9::*)($HttpHeaders*)>(&Stream$$Lambda$lambda$headerFrame$4$9::init$))},
	{"test", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$$Lambda$lambda$headerFrame$4$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$$Lambda$lambda$headerFrame$4$9",
	"java.lang.Object",
	"java.util.function.BiPredicate",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$lambda$headerFrame$4$9::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$lambda$headerFrame$4$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$lambda$headerFrame$4$9::class$ = nullptr;

class Stream$$Lambda$lambda$getResponseAsync$5$10 : public $Function {
	$class(Stream$$Lambda$lambda$getResponseAsync$5$10, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* r) override {
		 return $of(Stream::lambda$getResponseAsync$5($cast($Response, r)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$lambda$getResponseAsync$5$10>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Stream$$Lambda$lambda$getResponseAsync$5$10::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Stream$$Lambda$lambda$getResponseAsync$5$10::*)()>(&Stream$$Lambda$lambda$getResponseAsync$5$10::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$$Lambda$lambda$getResponseAsync$5$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$$Lambda$lambda$getResponseAsync$5$10",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Stream$$Lambda$lambda$getResponseAsync$5$10::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$lambda$getResponseAsync$5$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$lambda$getResponseAsync$5$10::class$ = nullptr;

class Stream$$Lambda$lambda$getResponseAsync$6$11 : public $BiConsumer {
	$class(Stream$$Lambda$lambda$getResponseAsync$6$11, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($PushGroup* pg) {
		$set(this, pg, pg);
	}
	virtual void accept(Object$* t, Object$* e) override {
		Stream::lambda$getResponseAsync$6(pg, $cast($Response, t), $cast($Throwable, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$lambda$getResponseAsync$6$11>());
	}
	$PushGroup* pg = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$lambda$getResponseAsync$6$11::fieldInfos[2] = {
	{"pg", "Ljdk/internal/net/http/PushGroup;", nullptr, $PUBLIC, $field(Stream$$Lambda$lambda$getResponseAsync$6$11, pg)},
	{}
};
$MethodInfo Stream$$Lambda$lambda$getResponseAsync$6$11::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/PushGroup;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$$Lambda$lambda$getResponseAsync$6$11::*)($PushGroup*)>(&Stream$$Lambda$lambda$getResponseAsync$6$11::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$$Lambda$lambda$getResponseAsync$6$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$$Lambda$lambda$getResponseAsync$6$11",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$lambda$getResponseAsync$6$11::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$lambda$getResponseAsync$6$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$lambda$getResponseAsync$6$11::class$ = nullptr;

class Stream$$Lambda$lambda$sendBodyImpl$7$12 : public $BiConsumer {
	$class(Stream$$Lambda$lambda$sendBodyImpl$7$12, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(Stream* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* v, Object$* t) override {
		$nc(inst$)->lambda$sendBodyImpl$7($cast($Void, v), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$$Lambda$lambda$sendBodyImpl$7$12>());
	}
	Stream* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$$Lambda$lambda$sendBodyImpl$7$12::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Stream$$Lambda$lambda$sendBodyImpl$7$12, inst$)},
	{}
};
$MethodInfo Stream$$Lambda$lambda$sendBodyImpl$7$12::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Stream;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$$Lambda$lambda$sendBodyImpl$7$12::*)(Stream*)>(&Stream$$Lambda$lambda$sendBodyImpl$7$12::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$$Lambda$lambda$sendBodyImpl$7$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$$Lambda$lambda$sendBodyImpl$7$12",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Stream$$Lambda$lambda$sendBodyImpl$7$12::load$($String* name, bool initialize) {
	$loadClass(Stream$$Lambda$lambda$sendBodyImpl$7$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$$Lambda$lambda$sendBodyImpl$7$12::class$ = nullptr;

$FieldInfo _Stream_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Stream, $assertionsDisabled)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(Stream, debug)},
	{"inputQ", "Ljava/util/concurrent/ConcurrentLinkedQueue;", "Ljava/util/concurrent/ConcurrentLinkedQueue<Ljdk/internal/net/http/frame/Http2Frame;>;", $FINAL, $field(Stream, inputQ)},
	{"sched", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $FINAL, $field(Stream, sched)},
	{"userSubscription", "Ljdk/internal/net/http/common/SubscriptionBase;", nullptr, $FINAL, $field(Stream, userSubscription)},
	{"streamid", "I", nullptr, $PROTECTED | $VOLATILE, $field(Stream, streamid)},
	{"requestContentLen", "J", nullptr, 0, $field(Stream, requestContentLen)},
	{"connection", "Ljdk/internal/net/http/Http2Connection;", nullptr, $FINAL, $field(Stream, connection$)},
	{"request", "Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $FINAL, $field(Stream, request)},
	{"rspHeadersConsumer", "Ljdk/internal/net/http/Stream$HeadersConsumer;", "Ljdk/internal/net/http/Stream<TT;>.HeadersConsumer;", $FINAL, $field(Stream, rspHeadersConsumer$)},
	{"responseHeadersBuilder", "Ljdk/internal/net/http/common/HttpHeadersBuilder;", nullptr, $FINAL, $field(Stream, responseHeadersBuilder)},
	{"requestPseudoHeaders", "Ljava/net/http/HttpHeaders;", nullptr, $FINAL, $field(Stream, requestPseudoHeaders)},
	{"responseSubscriber", "Ljava/net/http/HttpResponse$BodySubscriber;", "Ljava/net/http/HttpResponse$BodySubscriber<TT;>;", $VOLATILE, $field(Stream, responseSubscriber)},
	{"requestPublisher", "Ljava/net/http/HttpRequest$BodyPublisher;", nullptr, $FINAL, $field(Stream, requestPublisher)},
	{"requestSubscriber", "Ljdk/internal/net/http/Stream$RequestSubscriber;", "Ljdk/internal/net/http/Stream<TT;>.RequestSubscriber;", $VOLATILE, $field(Stream, requestSubscriber)},
	{"responseCode", "I", nullptr, $VOLATILE, $field(Stream, responseCode)},
	{"response", "Ljdk/internal/net/http/Response;", nullptr, $VOLATILE, $field(Stream, response)},
	{"errorRef", "Ljava/util/concurrent/atomic/AtomicReference;", "Ljava/util/concurrent/atomic/AtomicReference<Ljava/lang/Throwable;>;", $PRIVATE | $FINAL, $field(Stream, errorRef)},
	{"requestBodyCF", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $FINAL, $field(Stream, requestBodyCF)},
	{"responseBodyCF", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<TT;>;", $VOLATILE, $field(Stream, responseBodyCF)},
	{"pendingResponseSubscriber", "Ljava/net/http/HttpResponse$BodySubscriber;", "Ljava/net/http/HttpResponse$BodySubscriber<TT;>;", $VOLATILE, $field(Stream, pendingResponseSubscriber)},
	{"stopRequested", "Z", nullptr, $VOLATILE, $field(Stream, stopRequested)},
	{"remotelyClosed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(Stream, remotelyClosed)},
	{"closed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(Stream, closed)},
	{"endStreamSent", "Z", nullptr, $PRIVATE | $VOLATILE, $field(Stream, endStreamSent)},
	{"streamState", "I", nullptr, $PRIVATE | $VOLATILE, $field(Stream, streamState)},
	{"deRegistered", "Z", nullptr, $PRIVATE | $VOLATILE, $field(Stream, deRegistered)},
	{"requestSent", "Z", nullptr, $PRIVATE, $field(Stream, requestSent$)},
	{"responseReceived", "Z", nullptr, $PRIVATE, $field(Stream, responseReceived$)},
	{"sendLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(Stream, sendLock)},
	{"windowController", "Ljdk/internal/net/http/WindowController;", nullptr, $PRIVATE | $FINAL, $field(Stream, windowController)},
	{"windowUpdater", "Ljdk/internal/net/http/WindowUpdateSender;", nullptr, $PRIVATE | $FINAL, $field(Stream, windowUpdater)},
	{"COMPLETED", "Ljava/nio/ByteBuffer;", nullptr, $STATIC | $FINAL, $staticField(Stream, COMPLETED)},
	{"response_cfs", "Ljava/util/List;", "Ljava/util/List<Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;>;", $FINAL, $field(Stream, response_cfs)},
	{"STREAM_STATE", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Stream, STREAM_STATE)},
	{"DEREGISTERED", "Ljava/lang/invoke/VarHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Stream, DEREGISTERED)},
	{}
};

$MethodInfo _Stream_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Http2Connection;Ljdk/internal/net/http/Exchange;Ljdk/internal/net/http/WindowController;)V", "(Ljdk/internal/net/http/Http2Connection;Ljdk/internal/net/http/Exchange<TT;>;Ljdk/internal/net/http/WindowController;)V", 0, $method(static_cast<void(Stream::*)($Http2Connection*,$Exchange*,$WindowController*)>(&Stream::init$))},
	{"cancel", "()V", nullptr, 0},
	{"cancel", "(Ljava/io/IOException;)V", nullptr, 0},
	{"cancelImpl", "(Ljava/lang/Throwable;)V", nullptr, 0},
	{"checkRequestCancelled", "()Z", nullptr, $PRIVATE, $method(static_cast<bool(Stream::*)()>(&Stream::checkRequestCancelled))},
	{"close", "()V", nullptr, 0},
	{"completeResponse", "(Ljdk/internal/net/http/Response;)V", nullptr, 0},
	{"completeResponseExceptionally", "(Ljava/lang/Throwable;)V", nullptr, 0},
	{"completed", "()V", nullptr, 0},
	{"connection", "()Ljdk/internal/net/http/HttpConnection;", nullptr, 0},
	{"connectionClosing", "(Ljava/lang/Throwable;)V", nullptr, 0},
	{"consumed", "(Ljdk/internal/net/http/frame/DataFrame;)Z", nullptr, $PRIVATE, $method(static_cast<bool(Stream::*)($DataFrame*)>(&Stream::consumed))},
	{"createPseudoHeaders", "(Ljava/net/http/HttpRequest;)Ljava/net/http/HttpHeaders;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$HttpHeaders*(*)($HttpRequest*)>(&Stream::createPseudoHeaders))},
	{"dbgString", "()Ljava/lang/String;", nullptr, $FINAL, $method(static_cast<$String*(Stream::*)()>(&Stream::dbgString))},
	{"deRegister", "()Z", nullptr, 0},
	{"drainInputQueue", "()V", nullptr, $PRIVATE, $method(static_cast<void(Stream::*)()>(&Stream::drainInputQueue))},
	{"endStreamReceived", "()Z", nullptr, $PRIVATE, $method(static_cast<bool(Stream::*)()>(&Stream::endStreamReceived))},
	{"filterHeaders", "(Ljava/net/http/HttpHeaders;)Ljava/net/http/HttpHeaders;", nullptr, $PRIVATE, $method(static_cast<$HttpHeaders*(Stream::*)($HttpHeaders*)>(&Stream::filterHeaders))},
	{"getCancelCause", "()Ljava/lang/Throwable;", nullptr, $SYNCHRONIZED},
	{"getDataFrame", "(Ljava/nio/ByteBuffer;)Ljdk/internal/net/http/frame/DataFrame;", nullptr, 0},
	{"getEmptyEndStreamDataFrame", "()Ljdk/internal/net/http/frame/DataFrame;", nullptr, $PRIVATE, $method(static_cast<$DataFrame*(Stream::*)()>(&Stream::getEmptyEndStreamDataFrame))},
	{"getRequestPseudoHeaders", "()Ljava/net/http/HttpHeaders;", nullptr, 0},
	{"getResponseAsync", "(Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", 0},
	{"handleReset", "(Ljdk/internal/net/http/frame/ResetFrame;Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljdk/internal/net/http/frame/ResetFrame;Ljava/util/concurrent/Flow$Subscriber<*>;)V", 0},
	{"handleResponse", "()V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{"hasProxyAuthorization", "(Ljava/net/http/HttpHeaders;)Z", nullptr, $PRIVATE, $method(static_cast<bool(Stream::*)($HttpHeaders*)>(&Stream::hasProxyAuthorization))},
	{"headerFrame", "(J)Ljdk/internal/net/http/frame/OutgoingHeaders;", "(J)Ljdk/internal/net/http/frame/OutgoingHeaders<Ljdk/internal/net/http/Stream<TT;>;>;", $PRIVATE, $method(static_cast<$OutgoingHeaders*(Stream::*)(int64_t)>(&Stream::headerFrame))},
	{"ignoreBody", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC},
	{"incoming", "(Ljdk/internal/net/http/frame/Http2Frame;)V", nullptr, 0, nullptr, "java.io.IOException"},
	{"incoming_priority", "(Ljdk/internal/net/http/frame/PriorityFrame;)V", nullptr, 0},
	{"incoming_pushPromise", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/Stream$PushedStream;)V", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/Stream$PushedStream<TT;>;)V", 0, nullptr, "java.io.IOException"},
	{"incoming_reset", "(Ljdk/internal/net/http/frame/ResetFrame;)V", nullptr, 0},
	{"incoming_windowUpdate", "(Ljdk/internal/net/http/frame/WindowUpdateFrame;)V", nullptr, $PRIVATE, $method(static_cast<void(Stream::*)($WindowUpdateFrame*)>(&Stream::incoming_windowUpdate)), "java.io.IOException"},
	{"isCanceled", "()Z", nullptr, $SYNCHRONIZED},
	{"lambda$getResponseAsync$5", "(Ljdk/internal/net/http/Response;)Ljdk/internal/net/http/Response;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Response*(*)($Response*)>(&Stream::lambda$getResponseAsync$5))},
	{"lambda$getResponseAsync$6", "(Ljdk/internal/net/http/PushGroup;Ljdk/internal/net/http/Response;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($PushGroup*,$Response*,$Throwable*)>(&Stream::lambda$getResponseAsync$6))},
	{"lambda$handleResponse$2", "()Ljava/io/IOException;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$IOException*(*)()>(&Stream::lambda$handleResponse$2))},
	{"lambda$headerFrame$4", "(Ljava/net/http/HttpHeaders;Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($HttpHeaders*,$String*,$String*)>(&Stream::lambda$headerFrame$4))},
	{"lambda$incoming_pushPromise$3", "(Ljdk/internal/net/http/Stream$PushedStream;Ljdk/internal/net/http/PushGroup;Ljava/util/concurrent/CompletableFuture;Ljava/net/http/HttpResponse;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($Stream$PushedStream*,$PushGroup*,$CompletableFuture*,$HttpResponse*,$Throwable*)>(&Stream::lambda$incoming_pushPromise$3))},
	{"lambda$readBodyAsync$0", "(Ljdk/internal/net/http/PushGroup;Ljava/lang/Object;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($PushGroup*,Object$*,$Throwable*)>(&Stream::lambda$readBodyAsync$0))},
	{"lambda$sendBodyAsync$1", "(Ljava/lang/Void;)Ljdk/internal/net/http/ExchangeImpl;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$ExchangeImpl*(Stream::*)($Void*)>(&Stream::lambda$sendBodyAsync$1))},
	{"lambda$sendBodyImpl$7", "(Ljava/lang/Void;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Stream::*)($Void*,$Throwable*)>(&Stream::lambda$sendBodyImpl$7))},
	{"markStream", "(I)I", nullptr, 0},
	{"needsFiltering", "(Ljava/net/http/HttpHeaders;Ljava/util/function/BiPredicate;)Z", "(Ljava/net/http/HttpHeaders;Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;)Z", $PRIVATE, $method(static_cast<bool(Stream::*)($HttpHeaders*,$BiPredicate*)>(&Stream::needsFiltering))},
	{"nullBody", "(Ljava/net/http/HttpResponse;Ljava/lang/Throwable;)V", "(Ljava/net/http/HttpResponse<TT;>;Ljava/lang/Throwable;)V", 0},
	{"onSubscriptionError", "(Ljava/lang/Throwable;)V", nullptr, 0},
	{"otherFrame", "(Ljdk/internal/net/http/frame/Http2Frame;)V", nullptr, 0, nullptr, "java.io.IOException"},
	{"readBodyAsync", "(Ljava/net/http/HttpResponse$BodyHandler;ZLjava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/net/http/HttpResponse$BodyHandler<TT;>;ZLjava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TT;>;", 0},
	{"receiveData", "(Ljava/net/http/HttpResponse$BodySubscriber;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/net/http/HttpResponse$BodySubscriber<TT;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TT;>;", 0},
	{"receiveDataFrame", "(Ljdk/internal/net/http/frame/DataFrame;)V", nullptr, $PRIVATE, $method(static_cast<void(Stream::*)($DataFrame*)>(&Stream::receiveDataFrame))},
	{"receiveResetFrame", "(Ljdk/internal/net/http/frame/ResetFrame;)V", nullptr, $PRIVATE, $method(static_cast<void(Stream::*)($ResetFrame*)>(&Stream::receiveResetFrame))},
	{"registerStream", "(IZ)Z", nullptr, 0},
	{"released", "()V", nullptr, 0},
	{"requestSent", "()V", nullptr, $SYNCHRONIZED},
	{"responseReceived", "()V", nullptr, $SYNCHRONIZED},
	{"rspHeadersConsumer", "()Ljdk/internal/net/http/hpack/DecodingCallback;", nullptr, 0},
	{"schedule", "()V", nullptr, $PRIVATE, $method(static_cast<void(Stream::*)()>(&Stream::schedule))},
	{"sendBodyAsync", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/ExchangeImpl<TT;>;>;", 0},
	{"sendBodyImpl", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", 0},
	{"sendCancelStreamFrame", "()V", nullptr, 0},
	{"sendDataFrame", "(Ljdk/internal/net/http/frame/DataFrame;)V", nullptr, $PRIVATE, $method(static_cast<void(Stream::*)($DataFrame*)>(&Stream::sendDataFrame))},
	{"sendHeadersAsync", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/ExchangeImpl<TT;>;>;", 0},
	{"setEndStreamReceived", "()V", nullptr, 0},
	{"signalWindowUpdate", "()V", nullptr, 0},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Stream_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Stream$HeadersConsumer", "jdk.internal.net.http.Stream", "HeadersConsumer", $PRIVATE},
	{"jdk.internal.net.http.Stream$StreamWindowUpdateSender", "jdk.internal.net.http.Stream", "StreamWindowUpdateSender", $FINAL},
	{"jdk.internal.net.http.Stream$PushedStream", "jdk.internal.net.http.Stream", "PushedStream", $STATIC},
	{"jdk.internal.net.http.Stream$RequestSubscriber", "jdk.internal.net.http.Stream", "RequestSubscriber", 0},
	{}
};

$ClassInfo _Stream_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.Stream",
	"jdk.internal.net.http.ExchangeImpl",
	nullptr,
	_Stream_FieldInfo_,
	_Stream_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljdk/internal/net/http/ExchangeImpl<TT;>;",
	nullptr,
	_Stream_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Stream$HeadersConsumer,jdk.internal.net.http.Stream$StreamWindowUpdateSender,jdk.internal.net.http.Stream$PushedStream,jdk.internal.net.http.Stream$RequestSubscriber"
};

$Object* allocate$Stream($Class* clazz) {
	return $of($alloc(Stream));
}

bool Stream::$assertionsDisabled = false;
$ByteBuffer* Stream::COMPLETED = nullptr;
$VarHandle* Stream::STREAM_STATE = nullptr;
$VarHandle* Stream::DEREGISTERED = nullptr;

$HttpConnection* Stream::connection() {
	return $nc(this->connection$)->connection;
}

void Stream::schedule() {
	$useLocalCurrentObjectStackCache();
	bool onCompleteCalled = false;
	$var($HttpResponse$BodySubscriber, subscriber, this->responseSubscriber);
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				if (subscriber == nullptr) {
					$assign(subscriber, ($set(this, responseSubscriber, this->pendingResponseSubscriber)));
					if (subscriber == nullptr) {
						return$1 = true;
						goto $finally;
					} else {
						if ($nc(this->debug)->on()) {
							$nc(this->debug)->log("subscribing user subscriber"_s);
						}
						$nc(subscriber)->onSubscribe(this->userSubscription);
					}
				}
				while (!$nc(this->inputQ)->isEmpty()) {
					$var($Http2Frame, frame, $cast($Http2Frame, $nc(this->inputQ)->peek()));
					if ($instanceOf($ResetFrame, frame)) {
						$nc(this->inputQ)->remove();
						handleReset($cast($ResetFrame, frame), subscriber);
						return$1 = true;
						goto $finally;
					}
					$var($DataFrame, df, $cast($DataFrame, frame));
					bool finished = $nc(df)->getFlag($DataFrame::END_STREAM);
					$var($List, buffers, df->getData());
					$var($List, dsts, $Collections::unmodifiableList(buffers));
					int32_t size = $Utils::remaining(dsts, $Integer::MAX_VALUE);
					if (size == 0 && finished) {
						$nc(this->inputQ)->remove();
						$nc(this->connection$)->ensureWindowUpdated(df);
						$Log::logTrace("responseSubscriber.onComplete"_s, $$new($ObjectArray, 0));
						if ($nc(this->debug)->on()) {
							$nc(this->debug)->log("incoming: onComplete"_s);
						}
						$nc(this->sched)->stop();
						$nc(this->connection$)->decrementStreamsCount(this->streamid);
						$nc(subscriber)->onComplete();
						onCompleteCalled = true;
						setEndStreamReceived();
						return$1 = true;
						goto $finally;
					} else if ($nc(this->userSubscription)->tryDecrement()) {
						$nc(this->inputQ)->remove();
						$Log::logTrace("responseSubscriber.onNext {0}"_s, $$new($ObjectArray, {$($of($Integer::valueOf(size)))}));
						if ($nc(this->debug)->on()) {
							$nc(this->debug)->log("incoming: onNext(%d)"_s, $$new($ObjectArray, {$($of($Integer::valueOf(size)))}));
						}
						try {
							$nc(subscriber)->onNext(dsts);
						} catch ($Throwable& t) {
							$nc(this->connection$)->dropDataFrame(df);
							$throw(t);
						}
						if (consumed(df)) {
							$Log::logTrace("responseSubscriber.onComplete"_s, $$new($ObjectArray, 0));
							if ($nc(this->debug)->on()) {
								$nc(this->debug)->log("incoming: onComplete"_s);
							}
							$nc(this->sched)->stop();
							$nc(this->connection$)->decrementStreamsCount(this->streamid);
							$nc(subscriber)->onComplete();
							onCompleteCalled = true;
							setEndStreamReceived();
							return$1 = true;
							goto $finally;
						}
					} else {
						if (this->stopRequested) {
							break;
						}
						return$1 = true;
						goto $finally;
					}
				}
			} catch ($Throwable& throwable) {
				$nc(this->errorRef)->compareAndSet(nullptr, throwable);
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			if ($nc(this->sched)->isStopped()) {
				drainInputQueue();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
	$var($Throwable, t, $cast($Throwable, $nc(this->errorRef)->get()));
	if (t != nullptr) {
		$nc(this->sched)->stop();
		{
			$var($Throwable, var$3, nullptr);
			try {
				try {
					if (!onCompleteCalled) {
						if ($nc(this->debug)->on()) {
							$nc(this->debug)->log("calling subscriber.onError: %s"_s, $$new($ObjectArray, {$of(t)}));
						}
						$nc(subscriber)->onError(t);
					} else if ($nc(this->debug)->on()) {
						$nc(this->debug)->log("already completed: dropping error %s"_s, $$new($ObjectArray, {$of(t)}));
					}
				} catch ($Throwable& x) {
					$Log::logError("Subscriber::onError threw exception: {0}"_s, $$new($ObjectArray, {$of(t)}));
				}
			} catch ($Throwable& var$4) {
				$assign(var$3, var$4);
			} /*finally*/ {
				cancelImpl(t);
				drainInputQueue();
			}
			if (var$3 != nullptr) {
				$throw(var$3);
			}
		}
	}
}

void Stream::drainInputQueue() {
	$var($Http2Frame, frame, nullptr);
	while (($assign(frame, $cast($Http2Frame, $nc(this->inputQ)->poll()))) != nullptr) {
		if ($instanceOf($DataFrame, frame)) {
			$nc(this->connection$)->dropDataFrame($cast($DataFrame, frame));
		}
	}
}

void Stream::nullBody($HttpResponse* resp, $Throwable* t) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("nullBody: streamid=%d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
	}
	$set(this, pendingResponseSubscriber, $HttpResponse$BodySubscribers::replacing(nullptr));
	$nc(this->sched)->runOrSchedule();
}

bool Stream::consumed($DataFrame* df) {
	int32_t len = $nc(df)->payloadLength();
	bool endStream = df->getFlag($DataFrame::END_STREAM);
	if (len == 0) {
		return endStream;
	}
	$nc($nc(this->connection$)->windowUpdater)->update(len);
	if (!endStream) {
		$nc(this->windowUpdater)->update(len);
	}
	return endStream;
}

bool Stream::deRegister() {
	return $nc(Stream::DEREGISTERED)->compareAndSet($$new($ObjectArray, {$of(this), $$of(false), $$of(true)}));
}

$CompletableFuture* Stream::readBodyAsync($HttpResponse$BodyHandler* handler, bool returnConnectionToPool, $Executor* executor) {
	$useLocalCurrentObjectStackCache();
	try {
		$Log::logTrace("Reading body on stream {0}"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
		$nc(this->debug)->log($$str({"Getting BodySubscriber for: "_s, this->response}));
		$var($HttpResponse$BodySubscriber, bodySubscriber, $nc(handler)->apply($$new($ResponseInfoImpl, this->response)));
		$var($CompletableFuture, cf, receiveData(bodySubscriber, executor));
		$var($PushGroup, pg, $nc(this->exchange)->getPushGroup());
		if (pg != nullptr) {
			$assign(cf, $cast($CompletableFuture, $nc(cf)->whenComplete(static_cast<$BiConsumer*>($$new(Stream$$Lambda$lambda$readBodyAsync$0$4, pg)))));
		}
		return cf;
	} catch ($Throwable& t) {
		cancelImpl(t);
		return $MinimalFuture::failedFuture(t);
	}
	$shouldNotReachHere();
}

$String* Stream::toString() {
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("streamid: "_s)->append(this->streamid);
	return sb->toString();
}

void Stream::receiveDataFrame($DataFrame* df) {
	$nc(this->inputQ)->add(df);
	$nc(this->sched)->runOrSchedule();
}

void Stream::receiveResetFrame($ResetFrame* frame) {
	$nc(this->inputQ)->add(frame);
	$nc(this->sched)->runOrSchedule();
}

int32_t Stream::markStream(int32_t code) {
	if (code == 0) {
		return this->streamState;
	}
	$synchronized(this->sendLock) {
		return $intValue($nc(Stream::STREAM_STATE)->compareAndExchange($$new($ObjectArray, {$of(this), $$of(0), $$of(code)})));
	}
}

void Stream::sendDataFrame($DataFrame* frame) {
	$synchronized(this->sendLock) {
		if (this->streamState == 0) {
			$nc(this->connection$)->sendDataFrame(frame);
		}
	}
}

$CompletableFuture* Stream::receiveData($HttpResponse$BodySubscriber* bodySubscriber, $Executor* executor) {
	$useLocalCurrentObjectStackCache();
	$var($Executor, var$0, executor);
	$var($HttpResponse$BodySubscriber, var$1, bodySubscriber);
	$var($CompletableFuture, var$2, static_cast<$CompletableFuture*>($new($MinimalFuture)));
	$set(this, responseBodyCF, $ResponseSubscribers::getBodyAsync(var$0, var$1, var$2, static_cast<$Consumer*>($$new(Stream$$Lambda$cancelImpl$5, this))));
	if (isCanceled()) {
		$var($Throwable, t, getCancelCause());
		$nc(this->responseBodyCF)->completeExceptionally(t);
	} else {
		$set(this, pendingResponseSubscriber, bodySubscriber);
		$nc(this->sched)->runOrSchedule();
	}
	return this->responseBodyCF;
}

$CompletableFuture* Stream::sendBodyAsync() {
	$useLocalCurrentObjectStackCache();
	return $cast($CompletableFuture, $nc($(sendBodyImpl()))->thenApply(static_cast<$Function*>($$new(Stream$$Lambda$lambda$sendBodyAsync$1$6, this))));
}

void Stream::init$($Http2Connection* connection, $Exchange* e, $WindowController* windowController) {
	$useLocalCurrentObjectStackCache();
	$ExchangeImpl::init$(e);
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(Stream$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, inputQ, $new($ConcurrentLinkedQueue));
	$set(this, sched, $SequentialScheduler::lockingScheduler(static_cast<$Runnable*>($$new(Stream$$Lambda$schedule$1, this))));
	$var($SequentialScheduler, var$0, this->sched);
	$var($Runnable, var$1, static_cast<$Runnable*>($new(Stream$$Lambda$cancel$2, this)));
	$set(this, userSubscription, $new($SubscriptionBase, var$0, var$1, static_cast<$Consumer*>($$new(Stream$$Lambda$onSubscriptionError$3, this))));
	$set(this, errorRef, $new($AtomicReference));
	$set(this, requestBodyCF, $new($MinimalFuture));
	$set(this, sendLock, $new($Object));
	$set(this, response_cfs, $new($ArrayList, 5));
	$set(this, connection$, connection);
	$set(this, windowController, windowController);
	$set(this, request, $nc(e)->request());
	$set(this, requestPublisher, $nc(this->request)->requestPublisher);
	$set(this, responseHeadersBuilder, $new($HttpHeadersBuilder));
	$set(this, rspHeadersConsumer$, $new($Stream$HeadersConsumer, this));
	$set(this, requestPseudoHeaders, createPseudoHeaders(this->request));
	$set(this, windowUpdater, $new($Stream$StreamWindowUpdateSender, this, connection));
}

bool Stream::checkRequestCancelled() {
	if ($nc($nc(this->exchange)->multi)->requestCancelled()) {
		if ($nc(this->errorRef)->get() == nullptr) {
			cancel();
		} else {
			sendCancelStreamFrame();
		}
		return true;
	}
	return false;
}

void Stream::incoming($Http2Frame* frame) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("incoming: %s"_s, $$new($ObjectArray, {$of(frame)}));
	}
	bool cancelled = checkRequestCancelled() || this->closed;
	if ($instanceOf($HeaderFrame, frame)) {
		$var($HeaderFrame, hframe, $cast($HeaderFrame, frame));
		if ($nc(hframe)->endHeaders()) {
			$Log::logTrace("handling response (streamid={0})"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
			handleResponse();
		}
		if ($nc(hframe)->getFlag($HeaderFrame::END_STREAM)) {
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("handling END_STREAM: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
			}
			receiveDataFrame($$new($DataFrame, this->streamid, $DataFrame::END_STREAM, $($List::of())));
		}
	} else if ($instanceOf($DataFrame, frame)) {
		if (cancelled) {
			$nc(this->connection$)->dropDataFrame($cast($DataFrame, frame));
		} else {
			receiveDataFrame($cast($DataFrame, frame));
		}
	} else if (!cancelled) {
		otherFrame(frame);
	}
}

void Stream::otherFrame($Http2Frame* frame) {
	$useLocalCurrentObjectStackCache();
	switch ($nc(frame)->type()) {
	case $WindowUpdateFrame::TYPE:
		{
			incoming_windowUpdate($cast($WindowUpdateFrame, frame));
			break;
		}
	case $ResetFrame::TYPE:
		{
			incoming_reset($cast($ResetFrame, frame));
			break;
		}
	case $PriorityFrame::TYPE:
		{
			incoming_priority($cast($PriorityFrame, frame));
			break;
		}
	default:
		{
			$throwNew($IOException, $$str({"Unexpected frame: "_s, $(frame->toString())}));
		}
	}
}

$DecodingCallback* Stream::rspHeadersConsumer() {
	return this->rspHeadersConsumer$;
}

void Stream::handleResponse() {
	$useLocalCurrentObjectStackCache();
	$var($HttpHeaders, responseHeaders, $nc(this->responseHeadersBuilder)->build());
	this->responseCode = (int32_t)$nc($($nc(responseHeaders)->firstValueAsLong(":status"_s)))->orElseThrow(static_cast<$Supplier*>($$new(Stream$$Lambda$lambda$handleResponse$2$7)));
	$init($HttpClient$Version);
	$set(this, response, $new($Response, this->request, this->exchange, responseHeaders, $(connection()), this->responseCode, $HttpClient$Version::HTTP_2));
	responseHeaders->firstValueAsLong("content-length"_s);
	if ($Log::headers()) {
		$var($StringBuilder, sb, $new($StringBuilder, "RESPONSE HEADERS:\n"_s));
		$Log::dumpHeaders(sb, "    "_s, responseHeaders);
		$Log::logHeaders($(sb->toString()), $$new($ObjectArray, 0));
	}
	$nc(this->rspHeadersConsumer$)->reset();
	completeResponse(this->response);
}

void Stream::incoming_reset($ResetFrame* frame) {
	$useLocalCurrentObjectStackCache();
	$Log::logTrace("Received RST_STREAM on stream {0}"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
	if (endStreamReceived()) {
		$Log::logTrace("Ignoring RST_STREAM frame received on remotely closed stream {0}"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
	} else if (this->closed) {
		$Log::logTrace("Ignoring RST_STREAM frame received on closed stream {0}"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
	} else {
		$var($Flow$Subscriber, subscriber, this->responseSubscriber == nullptr ? $cast($Flow$Subscriber, this->pendingResponseSubscriber) : $cast($Flow$Subscriber, this->responseSubscriber));
		if (this->response == nullptr && subscriber == nullptr) {
			handleReset(frame, subscriber);
		} else {
			receiveResetFrame(frame);
			$Log::logTrace("RST_STREAM pushed in queue for stream {0}"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
		}
	}
}

void Stream::handleReset($ResetFrame* frame, $Flow$Subscriber* subscriber) {
	$useLocalCurrentObjectStackCache();
	$Log::logTrace("Handling RST_STREAM on stream {0}"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
	if (!this->closed) {
		$synchronized(this) {
			if (this->closed) {
				if ($nc(this->debug)->on()) {
					$nc(this->debug)->log("Stream already closed: ignoring RESET"_s);
				}
				return;
			}
			this->closed = true;
		}
		{
			$var($Throwable, var$0, nullptr);
			try {
				int32_t error = $nc(frame)->getErrorCode();
				$var($IOException, e, $new($IOException, $$str({"Received RST_STREAM: "_s, $($ErrorFrame::stringForCode(error))})));
				if ($nc(this->errorRef)->compareAndSet(nullptr, e)) {
					if (subscriber != nullptr) {
						subscriber->onError(e);
					}
				}
				completeResponseExceptionally(e);
				if (!$nc(this->requestBodyCF)->isDone()) {
					$nc(this->requestBodyCF)->completeExceptionally($cast($Throwable, $($nc(this->errorRef)->get())));
				}
				if (this->responseBodyCF != nullptr) {
					$nc(this->responseBodyCF)->completeExceptionally($cast($Throwable, $($nc(this->errorRef)->get())));
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				$nc(this->connection$)->decrementStreamsCount(this->streamid);
				$nc(this->connection$)->closeStream(this->streamid);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} else {
		$Log::logTrace("Ignoring RST_STREAM frame received on closed stream {0}"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
	}
}

void Stream::incoming_priority($PriorityFrame* frame) {
	$throwNew($UnsupportedOperationException, "Not implemented"_s);
}

void Stream::incoming_windowUpdate($WindowUpdateFrame* frame) {
	$useLocalCurrentObjectStackCache();
	int32_t amount = $nc(frame)->getUpdate();
	if (amount <= 0) {
		$Log::logTrace("Resetting stream: {0}, Window Update amount: {1}"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf(this->streamid))),
			$($of($Integer::valueOf(amount)))
		}));
		$nc(this->connection$)->resetStream(this->streamid, $ResetFrame::FLOW_CONTROL_ERROR);
	} else {
		if (!Stream::$assertionsDisabled && !(this->streamid != 0)) {
			$throwNew($AssertionError);
		}
		bool success = $nc(this->windowController)->increaseStreamWindow(amount, this->streamid);
		if (!success) {
			$nc(this->connection$)->resetStream(this->streamid, $ResetFrame::FLOW_CONTROL_ERROR);
		}
	}
}

void Stream::incoming_pushPromise($HttpRequestImpl* pushRequest, $Stream$PushedStream* pushStream) {
	$useLocalCurrentObjectStackCache();
	if ($Log::requests()) {
		$Log::logRequest($$str({"PUSH_PROMISE: "_s, $($nc(pushRequest)->toString())}), $$new($ObjectArray, 0));
	}
	$var($PushGroup, pushGroup, $nc(this->exchange)->getPushGroup());
	if (pushGroup == nullptr || $nc($nc(this->exchange)->multi)->requestCancelled()) {
		$Log::logTrace($$str({"Rejecting push promise stream "_s, $$str(this->streamid)}), $$new($ObjectArray, 0));
		$nc(this->connection$)->resetStream($nc(pushStream)->streamid, $ResetFrame::REFUSED_STREAM);
		$nc(pushStream)->close();
		return;
	}
	$var($PushGroup$Acceptor, acceptor, nullptr);
	bool accepted = false;
	try {
		$assign(acceptor, $nc(pushGroup)->acceptPushRequest(pushRequest));
		accepted = $nc(acceptor)->accepted();
	} catch ($Throwable& t) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("PushPromiseHandler::applyPushPromise threw exception %s"_s, $$new($ObjectArray, {$of(t)}));
		}
	}
	if (!accepted) {
		$var($IOException, ex, $new($IOException, $$str({"Stream "_s, $$str(this->streamid), " cancelled by users handler"_s})));
		if ($Log::trace()) {
			$Log::logTrace("No body subscriber for {0}: {1}"_s, $$new($ObjectArray, {
				$of(pushRequest),
				$($of(ex->getMessage()))
			}));
		}
		$nc(pushStream)->cancelImpl(ex);
		return;
	}
	if (!Stream::$assertionsDisabled && !(accepted && acceptor != nullptr)) {
		$throwNew($AssertionError);
	}
	$var($CompletableFuture, pushResponseCF, $nc(acceptor)->cf());
	$var($HttpResponse$BodyHandler, pushHandler, acceptor->bodyHandler());
	if (!Stream::$assertionsDisabled && !(pushHandler != nullptr)) {
		$throwNew($AssertionError);
	}
	$nc(pushStream)->requestSent();
	pushStream->setPushHandler(pushHandler);
	$var($CompletableFuture, cf, pushStream->responseCF());
	$nc(cf)->whenComplete(static_cast<$BiConsumer*>($$new(Stream$$Lambda$lambda$incoming_pushPromise$3$8, pushStream, pushGroup, pushResponseCF)));
}

$OutgoingHeaders* Stream::headerFrame(int64_t contentLength) {
	$useLocalCurrentObjectStackCache();
	$var($HttpHeadersBuilder, h, $nc(this->request)->getSystemHeadersBuilder());
	if (contentLength > 0) {
		$nc(h)->setHeader("content-length"_s, $($Long::toString(contentLength)));
	}
	$var($HttpHeaders, sysh, filterHeaders($($nc(h)->build())));
	$var($HttpHeaders, userh, filterHeaders($($nc(this->request)->getUserHeaders())));
	$var($Map, var$0, $nc(userh)->map());
	$assign(userh, $HttpHeaders::of(var$0, $($Utils::CONTEXT_RESTRICTED($(client())))));
	$var($HttpHeaders, uh, userh);
	$var($Map, var$1, $nc(sysh)->map());
	$assign(sysh, $HttpHeaders::of(var$1, static_cast<$BiPredicate*>($$new(Stream$$Lambda$lambda$headerFrame$4$9, uh))));
	$var($OutgoingHeaders, f, $new($OutgoingHeaders, sysh, userh, this));
	if (contentLength == 0) {
		f->setFlag($HeadersFrame::END_STREAM);
		this->endStreamSent = true;
	}
	return f;
}

bool Stream::hasProxyAuthorization($HttpHeaders* headers) {
	return $nc($($nc(headers)->firstValue("proxy-authorization"_s)))->isPresent();
}

bool Stream::needsFiltering($HttpHeaders* headers, $BiPredicate* filter) {
	$init($Utils);
	if (filter == $Utils::PROXY_TUNNEL_FILTER || filter == $Utils::PROXY_FILTER) {
		bool var$0 = $Utils::proxyHasDisabledSchemes(filter == $Utils::PROXY_TUNNEL_FILTER);
		return var$0 && hasProxyAuthorization(headers);
	} else {
		return hasProxyAuthorization(headers);
	}
}

$HttpHeaders* Stream::filterHeaders($HttpHeaders* headers) {
	$useLocalCurrentObjectStackCache();
	$var($HttpConnection, conn, connection());
	$var($BiPredicate, filter, $nc(conn)->headerFilter(this->request));
	if (needsFiltering(headers, filter)) {
		return $HttpHeaders::of($($nc(headers)->map()), filter);
	}
	return headers;
}

$HttpHeaders* Stream::createPseudoHeaders($HttpRequest* request) {
	$init(Stream);
	$useLocalCurrentObjectStackCache();
	$var($HttpHeadersBuilder, hdrs, $new($HttpHeadersBuilder));
	$var($String, method, $nc(request)->method());
	hdrs->setHeader(":method"_s, method);
	$var($URI, uri, request->uri());
	hdrs->setHeader(":scheme"_s, $($nc(uri)->getScheme()));
	hdrs->setHeader(":authority"_s, $($nc(uri)->getAuthority()));
	$var($String, query, $nc(uri)->getRawQuery());
	$var($String, path, uri->getRawPath());
	if (path == nullptr || $nc(path)->isEmpty()) {
		if ($nc(method)->equalsIgnoreCase("OPTIONS"_s)) {
			$assign(path, "*"_s);
		} else {
			$assign(path, "/"_s);
		}
	}
	if (query != nullptr) {
		$plusAssign(path, $$str({"?"_s, query}));
	}
	hdrs->setHeader(":path"_s, $($Utils::encode(path)));
	return hdrs->build();
}

$HttpHeaders* Stream::getRequestPseudoHeaders() {
	return this->requestPseudoHeaders;
}

void Stream::setEndStreamReceived() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("setEndStreamReceived: streamid=%d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
	}
	if (!Stream::$assertionsDisabled && !(this->remotelyClosed == false)) {
		$throwNew($AssertionError, $of("Unexpected endStream already set"_s));
	}
	this->remotelyClosed = true;
	responseReceived();
}

bool Stream::endStreamReceived() {
	return this->remotelyClosed;
}

$CompletableFuture* Stream::sendHeadersAsync() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("sendHeadersOnly()"_s);
	}
	if ($Log::requests() && this->request != nullptr) {
		$Log::logRequest($($nc(this->request)->toString()), $$new($ObjectArray, 0));
	}
	if (this->requestPublisher != nullptr) {
		this->requestContentLen = $nc(this->requestPublisher)->contentLength();
	} else {
		this->requestContentLen = 0;
	}
	$var($Throwable, t, $cast($Throwable, $nc(this->errorRef)->get()));
	if (t != nullptr) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("stream already cancelled, headers not sent: %s"_s, $$new($ObjectArray, {$of(t)}));
		}
		return $MinimalFuture::failedFuture(t);
	}
	$var($OutgoingHeaders, f, headerFrame(this->requestContentLen));
	$nc(this->connection$)->sendFrame(f);
	$var($CompletableFuture, cf, $new($MinimalFuture));
	cf->complete(this);
	return cf;
}

void Stream::released() {
	$useLocalCurrentObjectStackCache();
	if (this->streamid > 0) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Released stream %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
		}
		$nc(this->connection$)->decrementStreamsCount(this->streamid);
		$nc(this->connection$)->closeStream(this->streamid);
	} else if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Can\'t release stream %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
	}
}

void Stream::completed() {
}

bool Stream::registerStream(int32_t id, bool registerIfCancelled) {
	$useLocalCurrentObjectStackCache();
	bool cancelled = this->closed || $nc($nc(this->exchange)->multi)->requestCancelled();
	if (!cancelled || registerIfCancelled) {
		this->streamid = id;
		$nc(this->connection$)->putStream(this, this->streamid);
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Stream %d registered (cancelled: %b, registerIfCancelled: %b)"_s, $$new($ObjectArray, {
				$($of($Integer::valueOf(this->streamid))),
				$($of($Boolean::valueOf(cancelled))),
				$($of($Boolean::valueOf(registerIfCancelled)))
			}));
		}
	}
	return !cancelled;
}

void Stream::signalWindowUpdate() {
	$var($Stream$RequestSubscriber, subscriber, this->requestSubscriber);
	if (!Stream::$assertionsDisabled && !(subscriber != nullptr)) {
		$throwNew($AssertionError);
	}
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Signalling window update"_s);
	}
	$nc($nc(subscriber)->sendScheduler)->runOrSchedule();
}

$CompletableFuture* Stream::ignoreBody() {
	$useLocalCurrentObjectStackCache();
	try {
		$nc(this->connection$)->resetStream(this->streamid, $ResetFrame::STREAM_CLOSED);
		return $MinimalFuture::completedFuture(nullptr);
	} catch ($Throwable& e) {
		$Log::logTrace("Error resetting stream {0}"_s, $$new($ObjectArray, {$($of(e->toString()))}));
		return $MinimalFuture::failedFuture(e);
	}
	$shouldNotReachHere();
}

$DataFrame* Stream::getDataFrame($ByteBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	int32_t var$0 = $nc(this->connection$)->getMaxSendFrameSize();
	int32_t requestAmount = $Math::min(var$0, $nc(buffer)->remaining());
	int32_t actualAmount = $nc(this->windowController)->tryAcquire(requestAmount, this->streamid, this);
	if (actualAmount <= 0) {
		return nullptr;
	}
	$var($ByteBuffer, outBuf, $Utils::sliceWithLimitedCapacity(buffer, actualAmount));
	$var($DataFrame, df, $new($DataFrame, this->streamid, 0, outBuf));
	return df;
}

$DataFrame* Stream::getEmptyEndStreamDataFrame() {
	return $new($DataFrame, this->streamid, $DataFrame::END_STREAM, $($List::of()));
}

$CompletableFuture* Stream::getResponseAsync($Executor* executor) {
	$useLocalCurrentObjectStackCache();
	$var($CompletableFuture, cf, nullptr);
	$synchronized(this->response_cfs) {
		if (!$nc(this->response_cfs)->isEmpty()) {
			$assign(cf, $cast($CompletableFuture, $nc(this->response_cfs)->remove(0)));
			if (!Stream::$assertionsDisabled && !$nc(cf)->isDone()) {
				$throwNew($AssertionError, $of("Removing uncompleted response: could cause code to hang!"_s));
			}
		} else {
			$assign(cf, $new($MinimalFuture));
			$nc(this->response_cfs)->add(cf);
		}
	}
	if (executor != nullptr && !$nc(cf)->isDone()) {
		$assign(cf, $cast($CompletableFuture, cf->thenApplyAsync(static_cast<$Function*>($$new(Stream$$Lambda$lambda$getResponseAsync$5$10)), executor)));
	}
	$Log::logTrace("Response future (stream={0}) is: {1}"_s, $$new($ObjectArray, {
		$($of($Integer::valueOf(this->streamid))),
		$of(cf)
	}));
	$var($PushGroup, pg, $nc(this->exchange)->getPushGroup());
	if (pg != nullptr) {
		$assign(cf, $cast($CompletableFuture, $nc(cf)->whenComplete(static_cast<$BiConsumer*>($$new(Stream$$Lambda$lambda$getResponseAsync$6$11, pg)))));
	}
	return cf;
}

void Stream::completeResponse($Response* resp) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->response_cfs) {
		$var($CompletableFuture, cf, nullptr);
		int32_t cfs_len = $nc(this->response_cfs)->size();
		for (int32_t i = 0; i < cfs_len; ++i) {
			$assign(cf, $cast($CompletableFuture, $nc(this->response_cfs)->get(i)));
			if (!$nc(cf)->isDone()) {
				$Log::logTrace("Completing response (streamid={0}): {1}"_s, $$new($ObjectArray, {
					$($of($Integer::valueOf(this->streamid))),
					$of(cf)
				}));
				if ($nc(this->debug)->on()) {
					$nc(this->debug)->log("Completing responseCF(%d) with response headers"_s, $$new($ObjectArray, {$($of($Integer::valueOf(i)))}));
				}
				$nc(this->response_cfs)->remove($of(cf));
				cf->complete(resp);
				return;
			}
		}
		$assign(cf, $MinimalFuture::completedFuture(resp));
		$Log::logTrace("Created completed future (streamid={0}): {1}"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf(this->streamid))),
			$of(cf)
		}));
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Adding completed responseCF(0) with response headers"_s);
		}
		$nc(this->response_cfs)->add(cf);
	}
}

void Stream::requestSent() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		this->requestSent$ = true;
		if (this->responseReceived$) {
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("requestSent: streamid=%d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
			}
			close();
		} else if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("requestSent: streamid=%d but response not received"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
		}
	}
}

void Stream::responseReceived() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		this->responseReceived$ = true;
		if (this->requestSent$) {
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("responseReceived: streamid=%d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
			}
			close();
		} else if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("responseReceived: streamid=%d but request not sent"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
		}
	}
}

void Stream::completeResponseExceptionally($Throwable* t) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->response_cfs) {
		for (int32_t i = 0; i < $nc(this->response_cfs)->size(); ++i) {
			$var($CompletableFuture, cf, $cast($CompletableFuture, $nc(this->response_cfs)->get(i)));
			if (!$nc(cf)->isDone()) {
				$nc(this->response_cfs)->remove(i);
				cf->completeExceptionally(t);
				return;
			}
		}
		$nc(this->response_cfs)->add($($MinimalFuture::failedFuture(t)));
	}
}

$CompletableFuture* Stream::sendBodyImpl() {
	$useLocalCurrentObjectStackCache();
	$nc(this->requestBodyCF)->whenComplete(static_cast<$BiConsumer*>($$new(Stream$$Lambda$lambda$sendBodyImpl$7$12, this)));
	try {
		if (this->requestPublisher != nullptr) {
			$var($Stream$RequestSubscriber, subscriber, $new($Stream$RequestSubscriber, this, this->requestContentLen));
			$nc(this->requestPublisher)->subscribe(($set(this, requestSubscriber, subscriber)));
		} else {
			$nc(this->requestBodyCF)->complete(nullptr);
		}
	} catch ($Throwable& t) {
		cancelImpl(t);
		$nc(this->requestBodyCF)->completeExceptionally(t);
	}
	return this->requestBodyCF;
}

void Stream::cancel() {
	$useLocalCurrentObjectStackCache();
	if (this->streamid == 0) {
		cancel($$new($IOException, "Stream cancelled before streamid assigned"_s));
	} else {
		cancel($$new($IOException, $$str({"Stream "_s, $$str(this->streamid), " cancelled"_s})));
	}
}

void Stream::onSubscriptionError($Throwable* t) {
	$nc(this->errorRef)->compareAndSet(nullptr, t);
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Got subscription error: %s"_s, $$new($ObjectArray, {$of(t)}));
	}
	this->stopRequested = true;
	$nc(this->sched)->runOrSchedule();
}

void Stream::cancel($IOException* cause) {
	cancelImpl(cause);
}

void Stream::connectionClosing($Throwable* cause) {
	$var($Flow$Subscriber, subscriber, this->responseSubscriber == nullptr ? $cast($Flow$Subscriber, this->pendingResponseSubscriber) : $cast($Flow$Subscriber, this->responseSubscriber));
	$nc(this->errorRef)->compareAndSet(nullptr, cause);
	bool var$0 = subscriber != nullptr && !$nc(this->sched)->isStopped();
	if (var$0 && !$nc(this->inputQ)->isEmpty()) {
		$nc(this->sched)->runOrSchedule();
	} else {
		cancelImpl(cause);
	}
}

void Stream::cancelImpl($Throwable* e$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, e, e$renamed);
	$nc(this->errorRef)->compareAndSet(nullptr, e);
	if ($nc(this->debug)->on()) {
		if (this->streamid == 0) {
			$nc(this->debug)->log("cancelling stream: %s"_s, $$new($ObjectArray, {$of(e)}));
		} else {
			$nc(this->debug)->log("cancelling stream %d: %s"_s, $$new($ObjectArray, {
				$($of($Integer::valueOf(this->streamid))),
				$of(e)
			}));
		}
	}
	if ($Log::trace()) {
		if (this->streamid == 0) {
			$Log::logTrace("cancelling stream: {0}\n"_s, $$new($ObjectArray, {$of(e)}));
		} else {
			$Log::logTrace("cancelling stream {0}: {1}\n"_s, $$new($ObjectArray, {
				$($of($Integer::valueOf(this->streamid))),
				$of(e)
			}));
		}
	}
	bool closing = false;
	if (closing = !this->closed) {
		$synchronized(this) {
			if (closing = !this->closed) {
				this->closed = true;
			}
		}
	}
	if (closing) {
		if (this->responseSubscriber != nullptr || this->pendingResponseSubscriber != nullptr) {
			$nc(this->sched)->runOrSchedule();
		}
	}
	completeResponseExceptionally(e);
	if (!$nc(this->requestBodyCF)->isDone()) {
		$nc(this->requestBodyCF)->completeExceptionally($cast($Throwable, $($nc(this->errorRef)->get())));
	}
	if (this->responseBodyCF != nullptr) {
		$nc(this->responseBodyCF)->completeExceptionally($cast($Throwable, $($nc(this->errorRef)->get())));
	}
	try {
		if (this->streamid != 0 && this->streamState == 0) {
			$assign(e, $Utils::getCompletionCause(e));
			if ($instanceOf($EOFException, e)) {
				$nc(this->connection$)->decrementStreamsCount(this->streamid);
				$nc(this->connection$)->closeStream(this->streamid);
			} else {
				sendCancelStreamFrame();
			}
		}
	} catch ($Throwable& ex) {
		$Log::logError(ex);
	}
}

void Stream::sendCancelStreamFrame() {
	if (this->streamid > 0 && markStream($ResetFrame::CANCEL) == 0) {
		$nc(this->connection$)->resetStream(this->streamid, $ResetFrame::CANCEL);
	}
	close();
}

void Stream::close() {
	$useLocalCurrentObjectStackCache();
	if (this->closed) {
		return;
	}
	$synchronized(this) {
		if (this->closed) {
			return;
		}
		this->closed = true;
	}
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("close stream %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
	}
	$Log::logTrace("Closing stream {0}"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
	$nc(this->connection$)->closeStream(this->streamid);
	$Log::logTrace("Stream {0} closed"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->streamid)))}));
}

bool Stream::isCanceled() {
	$synchronized(this) {
		return $nc(this->errorRef)->get() != nullptr;
	}
}

$Throwable* Stream::getCancelCause() {
	$synchronized(this) {
		return $cast($Throwable, $nc(this->errorRef)->get());
	}
}

$String* Stream::dbgString() {
	$useLocalCurrentObjectStackCache();
	return $str({$($nc(this->connection$)->dbgString()), "/Stream("_s, $$str(this->streamid), ")"_s});
}

void Stream::lambda$sendBodyImpl$7($Void* v, $Throwable* t) {
	requestSent();
}

void Stream::lambda$getResponseAsync$6($PushGroup* pg, $Response* t, $Throwable* e) {
	$init(Stream);
	$nc(pg)->pushError($($Utils::getCompletionCause(e)));
}

$Response* Stream::lambda$getResponseAsync$5($Response* r) {
	$init(Stream);
	return r;
}

bool Stream::lambda$headerFrame$4($HttpHeaders* uh, $String* k, $String* v) {
	$init(Stream);
	return $nc($($nc(uh)->firstValue(k)))->isEmpty();
}

void Stream::lambda$incoming_pushPromise$3($Stream$PushedStream* pushStream, $PushGroup* pushGroup, $CompletableFuture* pushResponseCF, $HttpResponse* resp, $Throwable* t$renamed) {
	$init(Stream);
	$useLocalCurrentObjectStackCache();
	$var($Throwable, t, t$renamed);
	$assign(t, $Utils::getCompletionCause(t));
	if ($Log::trace()) {
		$Log::logTrace("Push completed on stream {0} for {1}{2}"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf($nc(pushStream)->streamid))),
			$of(resp),
			((t == nullptr) ? $of(""_s) : $of($$str({" with exception "_s, t})))
		}));
	}
	if (t != nullptr) {
		$nc(pushGroup)->pushError(t);
		$nc(pushResponseCF)->completeExceptionally(t);
	} else {
		$nc(pushResponseCF)->complete(resp);
	}
	$nc(pushGroup)->pushCompleted();
}

$IOException* Stream::lambda$handleResponse$2() {
	$init(Stream);
	return $new($IOException, "no statuscode in response"_s);
}

$ExchangeImpl* Stream::lambda$sendBodyAsync$1($Void* v) {
	return this;
}

void Stream::lambda$readBodyAsync$0($PushGroup* pg, Object$* t, $Throwable* e) {
	$init(Stream);
	$nc(pg)->pushError(e);
}

void clinit$Stream($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	Stream::$assertionsDisabled = !Stream::class$->desiredAssertionStatus();
	$assignStatic(Stream::COMPLETED, $ByteBuffer::allocate(0));
	{
		try {
			$init($Integer);
			$assignStatic(Stream::STREAM_STATE, $nc($($MethodHandles::lookup()))->findVarHandle(Stream::class$, "streamState"_s, $Integer::TYPE));
			$init($Boolean);
			$assignStatic(Stream::DEREGISTERED, $nc($($MethodHandles::lookup()))->findVarHandle(Stream::class$, "deRegistered"_s, $Boolean::TYPE));
		} catch ($Exception& x) {
			$throwNew($ExceptionInInitializerError, static_cast<$Throwable*>(x));
		}
	}
}

Stream::Stream() {
}

$Class* Stream::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Stream$$Lambda$dbgString::classInfo$.name)) {
			return Stream$$Lambda$dbgString::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$schedule$1::classInfo$.name)) {
			return Stream$$Lambda$schedule$1::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$cancel$2::classInfo$.name)) {
			return Stream$$Lambda$cancel$2::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$onSubscriptionError$3::classInfo$.name)) {
			return Stream$$Lambda$onSubscriptionError$3::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$lambda$readBodyAsync$0$4::classInfo$.name)) {
			return Stream$$Lambda$lambda$readBodyAsync$0$4::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$cancelImpl$5::classInfo$.name)) {
			return Stream$$Lambda$cancelImpl$5::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$lambda$sendBodyAsync$1$6::classInfo$.name)) {
			return Stream$$Lambda$lambda$sendBodyAsync$1$6::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$lambda$handleResponse$2$7::classInfo$.name)) {
			return Stream$$Lambda$lambda$handleResponse$2$7::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$lambda$incoming_pushPromise$3$8::classInfo$.name)) {
			return Stream$$Lambda$lambda$incoming_pushPromise$3$8::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$lambda$headerFrame$4$9::classInfo$.name)) {
			return Stream$$Lambda$lambda$headerFrame$4$9::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$lambda$getResponseAsync$5$10::classInfo$.name)) {
			return Stream$$Lambda$lambda$getResponseAsync$5$10::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$lambda$getResponseAsync$6$11::classInfo$.name)) {
			return Stream$$Lambda$lambda$getResponseAsync$6$11::load$(name, initialize);
		}
		if (name->equals(Stream$$Lambda$lambda$sendBodyImpl$7$12::classInfo$.name)) {
			return Stream$$Lambda$lambda$sendBodyImpl$7$12::load$(name, initialize);
		}
	}
	$loadClass(Stream, name, initialize, &_Stream_ClassInfo_, clinit$Stream, allocate$Stream);
	return class$;
}

$Class* Stream::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk