#include <jdk/internal/net/http/Stream$PushedStream.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpRequest.h>
#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/net/http/HttpResponse.h>
#include <java/util/OptionalLong.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/ExchangeImpl.h>
#include <jdk/internal/net/http/Http2Connection.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/HttpResponseImpl.h>
#include <jdk/internal/net/http/PushGroup.h>
#include <jdk/internal/net/http/Response.h>
#include <jdk/internal/net/http/Stream$HeadersConsumer.h>
#include <jdk/internal/net/http/Stream.h>
#include <jdk/internal/net/http/WindowController.h>
#include <jdk/internal/net/http/common/HttpHeadersBuilder.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef HTTP_2

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
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
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpResponse = ::java::net::http::HttpResponse;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $OptionalLong = ::java::util::OptionalLong;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Executor = ::java::util::concurrent::Executor;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $ExchangeImpl = ::jdk::internal::net::http::ExchangeImpl;
using $Http2Connection = ::jdk::internal::net::http::Http2Connection;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $HttpResponseImpl = ::jdk::internal::net::http::HttpResponseImpl;
using $PushGroup = ::jdk::internal::net::http::PushGroup;
using $Response = ::jdk::internal::net::http::Response;
using $Stream = ::jdk::internal::net::http::Stream;
using $Stream$HeadersConsumer = ::jdk::internal::net::http::Stream$HeadersConsumer;
using $WindowController = ::jdk::internal::net::http::WindowController;
using $HttpHeadersBuilder = ::jdk::internal::net::http::common::HttpHeadersBuilder;
using $Log = ::jdk::internal::net::http::common::Log;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0 : public $BiConsumer {
	$class(Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(Stream$PushedStream* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* v, Object$* t) override {
		$nc(inst$)->lambda$sendBodyAsync$0($cast($ExchangeImpl, v), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0>());
	}
	Stream$PushedStream* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0, inst$)},
	{}
};
$MethodInfo Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Stream$PushedStream;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0::*)(Stream$PushedStream*)>(&Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0::load$($String* name, bool initialize) {
	$loadClass(Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0::class$ = nullptr;

class Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1 : public $BiConsumer {
	$class(Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(Stream$PushedStream* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* v, Object$* t) override {
		$nc(inst$)->lambda$getResponseAsync$2($cast($Response, v), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1>());
	}
	Stream$PushedStream* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1, inst$)},
	{}
};
$MethodInfo Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Stream$PushedStream;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1::*)(Stream$PushedStream*)>(&Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1::load$($String* name, bool initialize) {
	$loadClass(Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1::class$ = nullptr;

class Stream$PushedStream$$Lambda$lambda$getResponseAsync$3$2 : public $Function {
	$class(Stream$PushedStream$$Lambda$lambda$getResponseAsync$3$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* r) override {
		 return $of(Stream$PushedStream::lambda$getResponseAsync$3($cast($Response, r)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$PushedStream$$Lambda$lambda$getResponseAsync$3$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Stream$PushedStream$$Lambda$lambda$getResponseAsync$3$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Stream$PushedStream$$Lambda$lambda$getResponseAsync$3$2::*)()>(&Stream$PushedStream$$Lambda$lambda$getResponseAsync$3$2::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$PushedStream$$Lambda$lambda$getResponseAsync$3$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$PushedStream$$Lambda$lambda$getResponseAsync$3$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Stream$PushedStream$$Lambda$lambda$getResponseAsync$3$2::load$($String* name, bool initialize) {
	$loadClass(Stream$PushedStream$$Lambda$lambda$getResponseAsync$3$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$PushedStream$$Lambda$lambda$getResponseAsync$3$2::class$ = nullptr;

class Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3 : public $BiConsumer {
	$class(Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(Stream$PushedStream* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* v, Object$* t) override {
		$nc(inst$)->lambda$readBodyAsync$4(v, $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3>());
	}
	Stream$PushedStream* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3, inst$)},
	{}
};
$MethodInfo Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Stream$PushedStream;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3::*)(Stream$PushedStream*)>(&Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3::load$($String* name, bool initialize) {
	$loadClass(Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3::class$ = nullptr;

class Stream$PushedStream$$Lambda$toString$4 : public $Supplier {
	$class(Stream$PushedStream$$Lambda$toString$4, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Response* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$PushedStream$$Lambda$toString$4>());
	}
	$Response* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$PushedStream$$Lambda$toString$4::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Stream$PushedStream$$Lambda$toString$4, inst$)},
	{}
};
$MethodInfo Stream$PushedStream$$Lambda$toString$4::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Response;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$PushedStream$$Lambda$toString$4::*)($Response*)>(&Stream$PushedStream$$Lambda$toString$4::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$PushedStream$$Lambda$toString$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$PushedStream$$Lambda$toString$4",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Stream$PushedStream$$Lambda$toString$4::load$($String* name, bool initialize) {
	$loadClass(Stream$PushedStream$$Lambda$toString$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$PushedStream$$Lambda$toString$4::class$ = nullptr;

class Stream$PushedStream$$Lambda$lambda$completeResponse$5$5 : public $Function {
	$class(Stream$PushedStream$$Lambda$lambda$completeResponse$5$5, $NO_CLASS_INIT, $Function)
public:
	void init$(Stream$PushedStream* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* v) override {
		 return $of($nc(inst$)->lambda$completeResponse$5($cast($Void, v)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$PushedStream$$Lambda$lambda$completeResponse$5$5>());
	}
	Stream$PushedStream* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$PushedStream$$Lambda$lambda$completeResponse$5$5::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Stream$PushedStream$$Lambda$lambda$completeResponse$5$5, inst$)},
	{}
};
$MethodInfo Stream$PushedStream$$Lambda$lambda$completeResponse$5$5::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Stream$PushedStream;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$PushedStream$$Lambda$lambda$completeResponse$5$5::*)(Stream$PushedStream*)>(&Stream$PushedStream$$Lambda$lambda$completeResponse$5$5::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$PushedStream$$Lambda$lambda$completeResponse$5$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$PushedStream$$Lambda$lambda$completeResponse$5$5",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Stream$PushedStream$$Lambda$lambda$completeResponse$5$5::load$($String* name, bool initialize) {
	$loadClass(Stream$PushedStream$$Lambda$lambda$completeResponse$5$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$PushedStream$$Lambda$lambda$completeResponse$5$5::class$ = nullptr;

class Stream$PushedStream$$Lambda$lambda$completeResponse$6$6 : public $BiConsumer {
	$class(Stream$PushedStream$$Lambda$lambda$completeResponse$6$6, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(Stream$PushedStream* inst, $Response* r) {
		$set(this, inst$, inst);
		$set(this, r, r);
	}
	virtual void accept(Object$* body, Object$* t) override {
		$nc(inst$)->lambda$completeResponse$6(r, body, $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$PushedStream$$Lambda$lambda$completeResponse$6$6>());
	}
	Stream$PushedStream* inst$ = nullptr;
	$Response* r = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Stream$PushedStream$$Lambda$lambda$completeResponse$6$6::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Stream$PushedStream$$Lambda$lambda$completeResponse$6$6, inst$)},
	{"r", "Ljdk/internal/net/http/Response;", nullptr, $PUBLIC, $field(Stream$PushedStream$$Lambda$lambda$completeResponse$6$6, r)},
	{}
};
$MethodInfo Stream$PushedStream$$Lambda$lambda$completeResponse$6$6::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Stream$PushedStream;Ljdk/internal/net/http/Response;)V", nullptr, $PUBLIC, $method(static_cast<void(Stream$PushedStream$$Lambda$lambda$completeResponse$6$6::*)(Stream$PushedStream*,$Response*)>(&Stream$PushedStream$$Lambda$lambda$completeResponse$6$6::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$PushedStream$$Lambda$lambda$completeResponse$6$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$PushedStream$$Lambda$lambda$completeResponse$6$6",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Stream$PushedStream$$Lambda$lambda$completeResponse$6$6::load$($String* name, bool initialize) {
	$loadClass(Stream$PushedStream$$Lambda$lambda$completeResponse$6$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$PushedStream$$Lambda$lambda$completeResponse$6$6::class$ = nullptr;

class Stream$PushedStream$$Lambda$lambda$completeResponse$7$7 : public $Supplier {
	$class(Stream$PushedStream$$Lambda$lambda$completeResponse$7$7, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(Stream$PushedStream::lambda$completeResponse$7());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Stream$PushedStream$$Lambda$lambda$completeResponse$7$7>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Stream$PushedStream$$Lambda$lambda$completeResponse$7$7::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Stream$PushedStream$$Lambda$lambda$completeResponse$7$7::*)()>(&Stream$PushedStream$$Lambda$lambda$completeResponse$7$7::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Stream$PushedStream$$Lambda$lambda$completeResponse$7$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Stream$PushedStream$$Lambda$lambda$completeResponse$7$7",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* Stream$PushedStream$$Lambda$lambda$completeResponse$7$7::load$($String* name, bool initialize) {
	$loadClass(Stream$PushedStream$$Lambda$lambda$completeResponse$7$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Stream$PushedStream$$Lambda$lambda$completeResponse$7$7::class$ = nullptr;

$FieldInfo _Stream$PushedStream_FieldInfo_[] = {
	{"pushGroup", "Ljdk/internal/net/http/PushGroup;", "Ljdk/internal/net/http/PushGroup<TT;>;", $FINAL, $field(Stream$PushedStream, pushGroup)},
	{"pushCF", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", $FINAL, $field(Stream$PushedStream, pushCF)},
	{"responseCF", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;", 0, $field(Stream$PushedStream, responseCF$)},
	{"pushReq", "Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $FINAL, $field(Stream$PushedStream, pushReq)},
	{"pushHandler", "Ljava/net/http/HttpResponse$BodyHandler;", "Ljava/net/http/HttpResponse$BodyHandler<TT;>;", 0, $field(Stream$PushedStream, pushHandler)},
	{}
};

$MethodInfo _Stream$PushedStream_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/PushGroup;Ljdk/internal/net/http/Http2Connection;Ljdk/internal/net/http/Exchange;)V", "(Ljdk/internal/net/http/PushGroup<TT;>;Ljdk/internal/net/http/Http2Connection;Ljdk/internal/net/http/Exchange<TT;>;)V", 0, $method(static_cast<void(Stream$PushedStream::*)($PushGroup*,$Http2Connection*,$Exchange*)>(&Stream$PushedStream::init$))},
	{"completeResponse", "(Ljdk/internal/net/http/Response;)V", nullptr, 0},
	{"completeResponseExceptionally", "(Ljava/lang/Throwable;)V", nullptr, 0},
	{"getPushHandler", "()Ljava/net/http/HttpResponse$BodyHandler;", "()Ljava/net/http/HttpResponse$BodyHandler<TT;>;", $SYNCHRONIZED},
	{"getResponseAsync", "(Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", 0},
	{"handleResponse", "()V", nullptr, $PROTECTED},
	{"lambda$completeResponse$5", "(Ljava/lang/Void;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(Stream$PushedStream::*)($Void*)>(&Stream$PushedStream::lambda$completeResponse$5))},
	{"lambda$completeResponse$6", "(Ljdk/internal/net/http/Response;Ljava/lang/Object;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Stream$PushedStream::*)($Response*,Object$*,$Throwable*)>(&Stream$PushedStream::lambda$completeResponse$6))},
	{"lambda$completeResponse$7", "()Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Void*(*)()>(&Stream$PushedStream::lambda$completeResponse$7))},
	{"lambda$getResponseAsync$2", "(Ljdk/internal/net/http/Response;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Stream$PushedStream::*)($Response*,$Throwable*)>(&Stream$PushedStream::lambda$getResponseAsync$2))},
	{"lambda$getResponseAsync$3", "(Ljdk/internal/net/http/Response;)Ljdk/internal/net/http/Response;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Response*(*)($Response*)>(&Stream$PushedStream::lambda$getResponseAsync$3))},
	{"lambda$readBodyAsync$4", "(Ljava/lang/Object;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Stream$PushedStream::*)(Object$*,$Throwable*)>(&Stream$PushedStream::lambda$readBodyAsync$4))},
	{"lambda$sendBodyAsync$0", "(Ljdk/internal/net/http/ExchangeImpl;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Stream$PushedStream::*)($ExchangeImpl*,$Throwable*)>(&Stream$PushedStream::lambda$sendBodyAsync$0))},
	{"readBodyAsync", "(Ljava/net/http/HttpResponse$BodyHandler;ZLjava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/net/http/HttpResponse$BodyHandler<TT;>;ZLjava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<TT;>;", 0},
	{"responseCF", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;", 0},
	{"sendBodyAsync", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/ExchangeImpl<TT;>;>;", 0},
	{"sendHeadersAsync", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/ExchangeImpl<TT;>;>;", 0},
	{"setPushHandler", "(Ljava/net/http/HttpResponse$BodyHandler;)V", "(Ljava/net/http/HttpResponse$BodyHandler<TT;>;)V", $SYNCHRONIZED},
	{}
};

$InnerClassInfo _Stream$PushedStream_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Stream$PushedStream", "jdk.internal.net.http.Stream", "PushedStream", $STATIC},
	{}
};

$ClassInfo _Stream$PushedStream_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.Stream$PushedStream",
	"jdk.internal.net.http.Stream",
	nullptr,
	_Stream$PushedStream_FieldInfo_,
	_Stream$PushedStream_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljdk/internal/net/http/Stream<TT;>;",
	nullptr,
	_Stream$PushedStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Stream"
};

$Object* allocate$Stream$PushedStream($Class* clazz) {
	return $of($alloc(Stream$PushedStream));
}

void Stream$PushedStream::init$($PushGroup* pushGroup, $Http2Connection* connection, $Exchange* pushReq) {
	$Stream::init$(connection, pushReq, nullptr);
	$set(this, pushGroup, pushGroup);
	$set(this, pushReq, $nc(pushReq)->request());
	$set(this, pushCF, $new($MinimalFuture));
	$set(this, responseCF$, $new($MinimalFuture));
}

$CompletableFuture* Stream$PushedStream::responseCF() {
	return this->responseCF$;
}

void Stream$PushedStream::setPushHandler($HttpResponse$BodyHandler* pushHandler) {
	$synchronized(this) {
		$set(this, pushHandler, pushHandler);
	}
}

$HttpResponse$BodyHandler* Stream$PushedStream::getPushHandler() {
	$synchronized(this) {
		return this->pushHandler;
	}
}

$CompletableFuture* Stream$PushedStream::sendBodyAsync() {
	$useLocalCurrentObjectStackCache();
	return $cast($CompletableFuture, $nc($($Stream::sendBodyAsync()))->whenComplete(static_cast<$BiConsumer*>($$new(Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0, this))));
}

$CompletableFuture* Stream$PushedStream::sendHeadersAsync() {
	$useLocalCurrentObjectStackCache();
	return $cast($CompletableFuture, $nc($($Stream::sendHeadersAsync()))->whenComplete(static_cast<$BiConsumer*>($$new(Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0, this))));
}

$CompletableFuture* Stream$PushedStream::getResponseAsync($Executor* executor) {
	$useLocalCurrentObjectStackCache();
	$var($CompletableFuture, cf, $cast($CompletableFuture, $nc(this->pushCF)->whenComplete(static_cast<$BiConsumer*>($$new(Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1, this)))));
	if (executor != nullptr && !$nc(cf)->isDone()) {
		$assign(cf, $cast($CompletableFuture, cf->thenApplyAsync(static_cast<$Function*>($$new(Stream$PushedStream$$Lambda$lambda$getResponseAsync$3$2)), executor)));
	}
	return cf;
}

$CompletableFuture* Stream$PushedStream::readBodyAsync($HttpResponse$BodyHandler* handler, bool returnConnectionToPool, $Executor* executor) {
	$useLocalCurrentObjectStackCache();
	return $cast($CompletableFuture, $nc($($Stream::readBodyAsync(handler, returnConnectionToPool, executor)))->whenComplete(static_cast<$BiConsumer*>($$new(Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3, this))));
}

void Stream$PushedStream::completeResponse($Response* r) {
	$useLocalCurrentObjectStackCache();
	$Log::logResponse(static_cast<$Supplier*>($$new(Stream$PushedStream$$Lambda$toString$4, static_cast<$Response*>($nc(r)))));
	$nc(this->pushCF)->complete(r);
	$var($CompletableFuture, start, $new($MinimalFuture));
	$nc($($cast($CompletableFuture, start->thenCompose(static_cast<$Function*>($$new(Stream$PushedStream$$Lambda$lambda$completeResponse$5$5, this))))))->whenComplete(static_cast<$BiConsumer*>($$new(Stream$PushedStream$$Lambda$lambda$completeResponse$6$6, this, r)));
	$var($Supplier, var$0, static_cast<$Supplier*>($new(Stream$PushedStream$$Lambda$lambda$completeResponse$7$7)));
	start->completeAsync(var$0, $($nc($(getExchange()))->executor()));
}

void Stream$PushedStream::completeResponseExceptionally($Throwable* t) {
	$nc(this->pushCF)->completeExceptionally(t);
}

void Stream$PushedStream::handleResponse() {
	$useLocalCurrentObjectStackCache();
	$var($HttpHeaders, responseHeaders, $nc(this->responseHeadersBuilder)->build());
	this->responseCode = (int32_t)$nc($($nc(responseHeaders)->firstValueAsLong(":status"_s)))->orElse(-1);
	if (this->responseCode == -1) {
		completeResponseExceptionally($$new($IOException, "No status code"_s));
	}
	$init($HttpClient$Version);
	$set(this, response, $new($Response, this->pushReq, this->exchange, responseHeaders, $(connection()), this->responseCode, $HttpClient$Version::HTTP_2));
	responseHeaders->firstValueAsLong("content-length"_s);
	if ($Log::headers()) {
		$var($StringBuilder, sb, $new($StringBuilder, "RESPONSE HEADERS"_s));
		sb->append(" (streamid="_s)->append(this->streamid)->append("):\n"_s);
		$Log::dumpHeaders(sb, "    "_s, responseHeaders);
		$Log::logHeaders($(sb->toString()), $$new($ObjectArray, 0));
	}
	$nc(this->rspHeadersConsumer$)->reset();
	completeResponse(this->response);
}

$Void* Stream$PushedStream::lambda$completeResponse$7() {
	$init(Stream$PushedStream);
	return nullptr;
}

void Stream$PushedStream::lambda$completeResponse$6($Response* r, Object$* body, $Throwable* t) {
	$useLocalCurrentObjectStackCache();
	if (t != nullptr) {
		$nc(this->responseCF$)->completeExceptionally(t);
	} else {
		$var($HttpResponseImpl, resp, $new($HttpResponseImpl, $nc(r)->request$, r, nullptr, body, $(getExchange())));
		$nc(this->responseCF$)->complete(resp);
	}
}

$CompletionStage* Stream$PushedStream::lambda$completeResponse$5($Void* v) {
	$useLocalCurrentObjectStackCache();
	$var($HttpResponse$BodyHandler, var$0, getPushHandler());
	return readBodyAsync(var$0, false, $($nc($(getExchange()))->executor()));
}

void Stream$PushedStream::lambda$readBodyAsync$4(Object$* v, $Throwable* t) {
	$nc(this->pushGroup)->pushError(t);
}

$Response* Stream$PushedStream::lambda$getResponseAsync$3($Response* r) {
	$init(Stream$PushedStream);
	return r;
}

void Stream$PushedStream::lambda$getResponseAsync$2($Response* v, $Throwable* t) {
	$nc(this->pushGroup)->pushError($($Utils::getCompletionCause(t)));
}

void Stream$PushedStream::lambda$sendBodyAsync$0($ExchangeImpl* v, $Throwable* t) {
	$nc(this->pushGroup)->pushError($($Utils::getCompletionCause(t)));
}

Stream$PushedStream::Stream$PushedStream() {
}

$Class* Stream$PushedStream::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0::classInfo$.name)) {
			return Stream$PushedStream$$Lambda$lambda$sendBodyAsync$0::load$(name, initialize);
		}
		if (name->equals(Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1::classInfo$.name)) {
			return Stream$PushedStream$$Lambda$lambda$getResponseAsync$2$1::load$(name, initialize);
		}
		if (name->equals(Stream$PushedStream$$Lambda$lambda$getResponseAsync$3$2::classInfo$.name)) {
			return Stream$PushedStream$$Lambda$lambda$getResponseAsync$3$2::load$(name, initialize);
		}
		if (name->equals(Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3::classInfo$.name)) {
			return Stream$PushedStream$$Lambda$lambda$readBodyAsync$4$3::load$(name, initialize);
		}
		if (name->equals(Stream$PushedStream$$Lambda$toString$4::classInfo$.name)) {
			return Stream$PushedStream$$Lambda$toString$4::load$(name, initialize);
		}
		if (name->equals(Stream$PushedStream$$Lambda$lambda$completeResponse$5$5::classInfo$.name)) {
			return Stream$PushedStream$$Lambda$lambda$completeResponse$5$5::load$(name, initialize);
		}
		if (name->equals(Stream$PushedStream$$Lambda$lambda$completeResponse$6$6::classInfo$.name)) {
			return Stream$PushedStream$$Lambda$lambda$completeResponse$6$6::load$(name, initialize);
		}
		if (name->equals(Stream$PushedStream$$Lambda$lambda$completeResponse$7$7::classInfo$.name)) {
			return Stream$PushedStream$$Lambda$lambda$completeResponse$7$7::load$(name, initialize);
		}
	}
	$loadClass(Stream$PushedStream, name, initialize, &_Stream$PushedStream_ClassInfo_, allocate$Stream$PushedStream);
	return class$;
}

$Class* Stream$PushedStream::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk