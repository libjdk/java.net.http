#include <jdk/internal/net/http/Exchange.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/ProxySelector.h>
#include <java/net/URI.h>
#include <java/net/URISyntaxException.h>
#include <java/net/URLPermission.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/net/http/HttpResponse$BodySubscribers.h>
#include <java/net/http/HttpResponse$ResponseInfo.h>
#include <java/net/http/HttpResponse.h>
#include <java/net/http/HttpTimeoutException.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AccessControlContext.h>
#include <java/security/Permission.h>
#include <java/time/Duration.h>
#include <java/util/Map.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/net/http/Exchange$ConnectionAborter.h>
#include <jdk/internal/net/http/ExchangeImpl.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jdk/internal/net/http/Http2ClientImpl.h>
#include <jdk/internal/net/http/Http2Connection.h>
#include <jdk/internal/net/http/HttpClientImpl$DelegatingExecutor.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/ProxyAuthenticationRequired.h>
#include <jdk/internal/net/http/PushGroup.h>
#include <jdk/internal/net/http/Response.h>
#include <jdk/internal/net/http/Stream.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef DEBUG

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $ProxySelector = ::java::net::ProxySelector;
using $URI = ::java::net::URI;
using $URISyntaxException = ::java::net::URISyntaxException;
using $URLPermission = ::java::net::URLPermission;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpResponse = ::java::net::http::HttpResponse;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $HttpResponse$BodySubscribers = ::java::net::http::HttpResponse$BodySubscribers;
using $HttpResponse$ResponseInfo = ::java::net::http::HttpResponse$ResponseInfo;
using $HttpTimeoutException = ::java::net::http::HttpTimeoutException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AccessControlContext = ::java::security::AccessControlContext;
using $Permission = ::java::security::Permission;
using $Duration = ::java::time::Duration;
using $Collection = ::java::util::Collection;
using $Map = ::java::util::Map;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Executor = ::java::util::concurrent::Executor;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;
using $Stream = ::java::util::stream::Stream;
using $Exchange$ConnectionAborter = ::jdk::internal::net::http::Exchange$ConnectionAborter;
using $ExchangeImpl = ::jdk::internal::net::http::ExchangeImpl;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;
using $Http2ClientImpl = ::jdk::internal::net::http::Http2ClientImpl;
using $Http2Connection = ::jdk::internal::net::http::Http2Connection;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpClientImpl$DelegatingExecutor = ::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;
using $ProxyAuthenticationRequired = ::jdk::internal::net::http::ProxyAuthenticationRequired;
using $PushGroup = ::jdk::internal::net::http::PushGroup;
using $Response = ::jdk::internal::net::http::Response;
using $1Stream = ::jdk::internal::net::http::Stream;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Exchange$$Lambda$dbgString : public $Supplier {
	$class(Exchange$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$dbgString>());
	}
	Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo Exchange$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$dbgString::*)(Exchange*)>(&Exchange$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$dbgString::class$ = nullptr;

class Exchange$$Lambda$lambda$readBodyAsync$0$1 : public $BiConsumer {
	$class(Exchange$$Lambda$lambda$readBodyAsync$0$1, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* r, Object$* t) override {
		$nc(inst$)->lambda$readBodyAsync$0(r, $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$lambda$readBodyAsync$0$1>());
	}
	Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$lambda$readBodyAsync$0$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$readBodyAsync$0$1, inst$)},
	{}
};
$MethodInfo Exchange$$Lambda$lambda$readBodyAsync$0$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$lambda$readBodyAsync$0$1::*)(Exchange*)>(&Exchange$$Lambda$lambda$readBodyAsync$0$1::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$lambda$readBodyAsync$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$lambda$readBodyAsync$0$1",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$lambda$readBodyAsync$0$1::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$lambda$readBodyAsync$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$lambda$readBodyAsync$0$1::class$ = nullptr;

class Exchange$$Lambda$lambda$checkCancelled$1$2 : public $BiFunction {
	$class(Exchange$$Lambda$lambda$checkCancelled$1$2, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(Exchange* inst, $HttpConnection* connection, $CompletableFuture* cf) {
		$set(this, inst$, inst);
		$set(this, connection, connection);
		$set(this, cf, cf);
	}
	virtual $Object* apply(Object$* r, Object$* t) override {
		 return $of($nc(inst$)->lambda$checkCancelled$1(connection, cf, r, $cast($Throwable, t)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$lambda$checkCancelled$1$2>());
	}
	Exchange* inst$ = nullptr;
	$HttpConnection* connection = nullptr;
	$CompletableFuture* cf = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$lambda$checkCancelled$1$2::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$checkCancelled$1$2, inst$)},
	{"connection", "Ljdk/internal/net/http/HttpConnection;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$checkCancelled$1$2, connection)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$checkCancelled$1$2, cf)},
	{}
};
$MethodInfo Exchange$$Lambda$lambda$checkCancelled$1$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;Ljdk/internal/net/http/HttpConnection;Ljava/util/concurrent/CompletableFuture;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$lambda$checkCancelled$1$2::*)(Exchange*,$HttpConnection*,$CompletableFuture*)>(&Exchange$$Lambda$lambda$checkCancelled$1$2::init$))},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$lambda$checkCancelled$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$lambda$checkCancelled$1$2",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$lambda$checkCancelled$1$2::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$lambda$checkCancelled$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$lambda$checkCancelled$1$2::class$ = nullptr;

class Exchange$$Lambda$lambda$establishExchange$2$3 : public $BiConsumer {
	$class(Exchange$$Lambda$lambda$establishExchange$2$3, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(Exchange* inst, $CompletableFuture* cf) {
		$set(this, inst$, inst);
		$set(this, cf, cf);
	}
	virtual void accept(Object$* r, Object$* x) override {
		$nc(inst$)->lambda$establishExchange$2(cf, $cast($ExchangeImpl, r), $cast($Throwable, x));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$lambda$establishExchange$2$3>());
	}
	Exchange* inst$ = nullptr;
	$CompletableFuture* cf = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$lambda$establishExchange$2$3::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$establishExchange$2$3, inst$)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$establishExchange$2$3, cf)},
	{}
};
$MethodInfo Exchange$$Lambda$lambda$establishExchange$2$3::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;Ljava/util/concurrent/CompletableFuture;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$lambda$establishExchange$2$3::*)(Exchange*,$CompletableFuture*)>(&Exchange$$Lambda$lambda$establishExchange$2$3::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$lambda$establishExchange$2$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$lambda$establishExchange$2$3",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$lambda$establishExchange$2$3::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$lambda$establishExchange$2$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$lambda$establishExchange$2$3::class$ = nullptr;

class Exchange$$Lambda$lambda$establishExchange$3$4 : public $Function {
	$class(Exchange$$Lambda$lambda$establishExchange$3$4, $NO_CLASS_INIT, $Function)
public:
	void init$(Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* eimpl) override {
		 return $of($nc(inst$)->lambda$establishExchange$3($cast($ExchangeImpl, eimpl)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$lambda$establishExchange$3$4>());
	}
	Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$lambda$establishExchange$3$4::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$establishExchange$3$4, inst$)},
	{}
};
$MethodInfo Exchange$$Lambda$lambda$establishExchange$3$4::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$lambda$establishExchange$3$4::*)(Exchange*)>(&Exchange$$Lambda$lambda$establishExchange$3$4::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$lambda$establishExchange$3$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$lambda$establishExchange$3$4",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$lambda$establishExchange$3$4::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$lambda$establishExchange$3$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$lambda$establishExchange$3$4::class$ = nullptr;

class Exchange$$Lambda$lambda$expectContinue$6$5 : public $Function {
	$class(Exchange$$Lambda$lambda$expectContinue$6$5, $NO_CLASS_INIT, $Function)
public:
	void init$(Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* r1) override {
		 return $of($nc(inst$)->lambda$expectContinue$6($cast($Response, r1)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$lambda$expectContinue$6$5>());
	}
	Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$lambda$expectContinue$6$5::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$expectContinue$6$5, inst$)},
	{}
};
$MethodInfo Exchange$$Lambda$lambda$expectContinue$6$5::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$lambda$expectContinue$6$5::*)(Exchange*)>(&Exchange$$Lambda$lambda$expectContinue$6$5::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$lambda$expectContinue$6$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$lambda$expectContinue$6$5",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$lambda$expectContinue$6$5::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$lambda$expectContinue$6$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$lambda$expectContinue$6$5::class$ = nullptr;

class Exchange$$Lambda$lambda$expectContinue$4$6 : public $Function {
	$class(Exchange$$Lambda$lambda$expectContinue$4$6, $NO_CLASS_INIT, $Function)
public:
	void init$(Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* exIm) override {
		 return $of($nc(inst$)->lambda$expectContinue$4($cast($ExchangeImpl, exIm)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$lambda$expectContinue$4$6>());
	}
	Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$lambda$expectContinue$4$6::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$expectContinue$4$6, inst$)},
	{}
};
$MethodInfo Exchange$$Lambda$lambda$expectContinue$4$6::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$lambda$expectContinue$4$6::*)(Exchange*)>(&Exchange$$Lambda$lambda$expectContinue$4$6::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$lambda$expectContinue$4$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$lambda$expectContinue$4$6",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$lambda$expectContinue$4$6::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$lambda$expectContinue$4$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$lambda$expectContinue$4$6::class$ = nullptr;

class Exchange$$Lambda$expectContinue$7 : public $Function {
	$class(Exchange$$Lambda$expectContinue$7, $NO_CLASS_INIT, $Function)
public:
	void init$(Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* ex) override {
		 return $of($nc(inst$)->expectContinue($cast($ExchangeImpl, ex)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$expectContinue$7>());
	}
	Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$expectContinue$7::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$expectContinue$7, inst$)},
	{}
};
$MethodInfo Exchange$$Lambda$expectContinue$7::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$expectContinue$7::*)(Exchange*)>(&Exchange$$Lambda$expectContinue$7::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$expectContinue$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$expectContinue$7",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$expectContinue$7::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$expectContinue$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$expectContinue$7::class$ = nullptr;

class Exchange$$Lambda$sendRequestBody$8 : public $Function {
	$class(Exchange$$Lambda$sendRequestBody$8, $NO_CLASS_INIT, $Function)
public:
	void init$(Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* ex) override {
		 return $of($nc(inst$)->sendRequestBody($cast($ExchangeImpl, ex)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$sendRequestBody$8>());
	}
	Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$sendRequestBody$8::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$sendRequestBody$8, inst$)},
	{}
};
$MethodInfo Exchange$$Lambda$sendRequestBody$8::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$sendRequestBody$8::*)(Exchange*)>(&Exchange$$Lambda$sendRequestBody$8::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$sendRequestBody$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$sendRequestBody$8",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$sendRequestBody$8::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$sendRequestBody$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$sendRequestBody$8::class$ = nullptr;

class Exchange$$Lambda$lambda$responseAsyncImpl0$9$9 : public $Function {
	$class(Exchange$$Lambda$lambda$responseAsyncImpl0$9$9, $NO_CLASS_INIT, $Function)
public:
	void init$(Exchange* inst, $Function* after407Check) {
		$set(this, inst$, inst);
		$set(this, after407Check, after407Check);
	}
	virtual $Object* apply(Object$* ex) override {
		 return $of($nc(inst$)->lambda$responseAsyncImpl0$9(after407Check, $cast($ExchangeImpl, ex)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$lambda$responseAsyncImpl0$9$9>());
	}
	Exchange* inst$ = nullptr;
	$Function* after407Check = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$lambda$responseAsyncImpl0$9$9::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$responseAsyncImpl0$9$9, inst$)},
	{"after407Check", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$responseAsyncImpl0$9$9, after407Check)},
	{}
};
$MethodInfo Exchange$$Lambda$lambda$responseAsyncImpl0$9$9::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;Ljava/util/function/Function;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$lambda$responseAsyncImpl0$9$9::*)(Exchange*,$Function*)>(&Exchange$$Lambda$lambda$responseAsyncImpl0$9$9::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$lambda$responseAsyncImpl0$9$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$lambda$responseAsyncImpl0$9$9",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$lambda$responseAsyncImpl0$9$9::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$lambda$responseAsyncImpl0$9$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$lambda$responseAsyncImpl0$9$9::class$ = nullptr;

class Exchange$$Lambda$lambda$responseAsyncImpl0$8$10 : public $BiFunction {
	$class(Exchange$$Lambda$lambda$responseAsyncImpl0$8$10, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(Exchange* inst, $Function* after407Check) {
		$set(this, inst$, inst);
		$set(this, after407Check, after407Check);
	}
	virtual $Object* apply(Object$* r, Object$* t) override {
		 return $of($nc(inst$)->lambda$responseAsyncImpl0$8(after407Check, $cast($ExchangeImpl, r), $cast($Throwable, t)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$lambda$responseAsyncImpl0$8$10>());
	}
	Exchange* inst$ = nullptr;
	$Function* after407Check = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$lambda$responseAsyncImpl0$8$10::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$responseAsyncImpl0$8$10, inst$)},
	{"after407Check", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$responseAsyncImpl0$8$10, after407Check)},
	{}
};
$MethodInfo Exchange$$Lambda$lambda$responseAsyncImpl0$8$10::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;Ljava/util/function/Function;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$lambda$responseAsyncImpl0$8$10::*)(Exchange*,$Function*)>(&Exchange$$Lambda$lambda$responseAsyncImpl0$8$10::init$))},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$lambda$responseAsyncImpl0$8$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$lambda$responseAsyncImpl0$8$10",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$lambda$responseAsyncImpl0$8$10::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$lambda$responseAsyncImpl0$8$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$lambda$responseAsyncImpl0$8$10::class$ = nullptr;

class Exchange$$Lambda$lambda$wrapForUpgrade$11$11 : public $Function {
	$class(Exchange$$Lambda$lambda$wrapForUpgrade$11$11, $NO_CLASS_INIT, $Function)
public:
	void init$(Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* r) override {
		 return $of($nc(inst$)->lambda$wrapForUpgrade$11($cast($Response, r)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$lambda$wrapForUpgrade$11$11>());
	}
	Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$lambda$wrapForUpgrade$11$11::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$wrapForUpgrade$11$11, inst$)},
	{}
};
$MethodInfo Exchange$$Lambda$lambda$wrapForUpgrade$11$11::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$lambda$wrapForUpgrade$11$11::*)(Exchange*)>(&Exchange$$Lambda$lambda$wrapForUpgrade$11$11::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$lambda$wrapForUpgrade$11$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$lambda$wrapForUpgrade$11$11",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$lambda$wrapForUpgrade$11$11::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$lambda$wrapForUpgrade$11$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$lambda$wrapForUpgrade$11$11::class$ = nullptr;

class Exchange$$Lambda$lambda$wrapForLog$12$12 : public $Function {
	$class(Exchange$$Lambda$lambda$wrapForLog$12$12, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* response) override {
		 return $of(Exchange::lambda$wrapForLog$12($cast($Response, response)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$lambda$wrapForLog$12$12>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Exchange$$Lambda$lambda$wrapForLog$12$12::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$lambda$wrapForLog$12$12::*)()>(&Exchange$$Lambda$lambda$wrapForLog$12$12::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$lambda$wrapForLog$12$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$lambda$wrapForLog$12$12",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Exchange$$Lambda$lambda$wrapForLog$12$12::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$lambda$wrapForLog$12$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$lambda$wrapForLog$12$12::class$ = nullptr;

class Exchange$$Lambda$ignoreBody$13 : public $HttpResponse$BodyHandler {
	$class(Exchange$$Lambda$ignoreBody$13, $NO_CLASS_INIT, $HttpResponse$BodyHandler)
public:
	void init$(Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $HttpResponse$BodySubscriber* apply($HttpResponse$ResponseInfo* hdrs) override {
		 return $nc(inst$)->ignoreBody(hdrs);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$ignoreBody$13>());
	}
	Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$ignoreBody$13::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$ignoreBody$13, inst$)},
	{}
};
$MethodInfo Exchange$$Lambda$ignoreBody$13::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$ignoreBody$13::*)(Exchange*)>(&Exchange$$Lambda$ignoreBody$13::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$ignoreBody$13::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$ignoreBody$13",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$ignoreBody$13::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$ignoreBody$13, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$ignoreBody$13::class$ = nullptr;

class Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14 : public $Function {
	$class(Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14, $NO_CLASS_INIT, $Function)
public:
	void init$(Exchange* inst, $ExchangeImpl* ex, $Http1Exchange* e) {
		$set(this, inst$, inst);
		$set(this, ex, ex);
		$set(this, e, e);
	}
	virtual $Object* apply(Object$* v) override {
		 return $of($nc(inst$)->lambda$checkForUpgradeAsync$14(ex, e, v));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14>());
	}
	Exchange* inst$ = nullptr;
	$ExchangeImpl* ex = nullptr;
	$Http1Exchange* e = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14, inst$)},
	{"ex", "Ljdk/internal/net/http/ExchangeImpl;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14, ex)},
	{"e", "Ljdk/internal/net/http/Http1Exchange;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14, e)},
	{}
};
$MethodInfo Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;Ljdk/internal/net/http/ExchangeImpl;Ljdk/internal/net/http/Http1Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14::*)(Exchange*,$ExchangeImpl*,$Http1Exchange*)>(&Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14::class$ = nullptr;

class Exchange$$Lambda$drainLeftOverBytes$15 : public $Supplier {
	$class(Exchange$$Lambda$drainLeftOverBytes$15, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Http1Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->drainLeftOverBytes());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$drainLeftOverBytes$15>());
	}
	$Http1Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$drainLeftOverBytes$15::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$drainLeftOverBytes$15, inst$)},
	{}
};
$MethodInfo Exchange$$Lambda$drainLeftOverBytes$15::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$drainLeftOverBytes$15::*)($Http1Exchange*)>(&Exchange$$Lambda$drainLeftOverBytes$15::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$drainLeftOverBytes$15::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$drainLeftOverBytes$15",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$drainLeftOverBytes$15::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$drainLeftOverBytes$15, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$drainLeftOverBytes$15::class$ = nullptr;

class Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16 : public $Function {
	$class(Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16, $NO_CLASS_INIT, $Function)
public:
	void init$(Exchange* inst, $Http1Exchange* e) {
		$set(this, inst$, inst);
		$set(this, e, e);
	}
	virtual $Object* apply(Object$* c) override {
		 return $of($nc(inst$)->lambda$checkForUpgradeAsync$13(e, $cast($Http2Connection, c)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16>());
	}
	Exchange* inst$ = nullptr;
	$Http1Exchange* e = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16, inst$)},
	{"e", "Ljdk/internal/net/http/Http1Exchange;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16, e)},
	{}
};
$MethodInfo Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Exchange;Ljdk/internal/net/http/Http1Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16::*)(Exchange*,$Http1Exchange*)>(&Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16::class$ = nullptr;

class Exchange$$Lambda$toString$17 : public $Supplier {
	$class(Exchange$$Lambda$toString$17, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Response* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$toString$17>());
	}
	$Response* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$toString$17::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Exchange$$Lambda$toString$17, inst$)},
	{}
};
$MethodInfo Exchange$$Lambda$toString$17::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Response;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$toString$17::*)($Response*)>(&Exchange$$Lambda$toString$17::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$toString$17::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$toString$17",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$toString$17::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$toString$17, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$toString$17::class$ = nullptr;

class Exchange$$Lambda$lambda$expectContinue$5$18 : public $Function {
	$class(Exchange$$Lambda$lambda$expectContinue$5$18, $NO_CLASS_INIT, $Function)
public:
	void init$($Response* r1) {
		$set(this, r1, r1);
	}
	virtual $Object* apply(Object$* v) override {
		 return $of(Exchange::lambda$expectContinue$5(r1, v));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Exchange$$Lambda$lambda$expectContinue$5$18>());
	}
	$Response* r1 = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Exchange$$Lambda$lambda$expectContinue$5$18::fieldInfos[2] = {
	{"r1", "Ljdk/internal/net/http/Response;", nullptr, $PUBLIC, $field(Exchange$$Lambda$lambda$expectContinue$5$18, r1)},
	{}
};
$MethodInfo Exchange$$Lambda$lambda$expectContinue$5$18::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Response;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange$$Lambda$lambda$expectContinue$5$18::*)($Response*)>(&Exchange$$Lambda$lambda$expectContinue$5$18::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Exchange$$Lambda$lambda$expectContinue$5$18::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Exchange$$Lambda$lambda$expectContinue$5$18",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Exchange$$Lambda$lambda$expectContinue$5$18::load$($String* name, bool initialize) {
	$loadClass(Exchange$$Lambda$lambda$expectContinue$5$18, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Exchange$$Lambda$lambda$expectContinue$5$18::class$ = nullptr;

$FieldInfo _Exchange_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Exchange, $assertionsDisabled)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(Exchange, debug)},
	{"request", "Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $FINAL, $field(Exchange, request$)},
	{"client", "Ljdk/internal/net/http/HttpClientImpl;", nullptr, $FINAL, $field(Exchange, client$)},
	{"exchImpl", "Ljdk/internal/net/http/ExchangeImpl;", "Ljdk/internal/net/http/ExchangeImpl<TT;>;", $VOLATILE, $field(Exchange, exchImpl)},
	{"exchangeCF", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<+Ljdk/internal/net/http/ExchangeImpl<TT;>;>;", $VOLATILE, $field(Exchange, exchangeCF)},
	{"bodyIgnored", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $VOLATILE, $field(Exchange, bodyIgnored)},
	{"failed", "Ljava/io/IOException;", nullptr, $PRIVATE | $VOLATILE, $field(Exchange, failed)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $FINAL, $field(Exchange, acc)},
	{"multi", "Ljdk/internal/net/http/MultiExchange;", "Ljdk/internal/net/http/MultiExchange<TT;>;", $FINAL, $field(Exchange, multi)},
	{"parentExecutor", "Ljava/util/concurrent/Executor;", nullptr, $FINAL, $field(Exchange, parentExecutor)},
	{"upgrading", "Z", nullptr, $VOLATILE, $field(Exchange, upgrading)},
	{"upgraded", "Z", nullptr, $VOLATILE, $field(Exchange, upgraded)},
	{"pushGroup", "Ljdk/internal/net/http/PushGroup;", "Ljdk/internal/net/http/PushGroup<TT;>;", $FINAL, $field(Exchange, pushGroup)},
	{"dbgTag", "Ljava/lang/String;", nullptr, $FINAL, $field(Exchange, dbgTag)},
	{"connectionAborter", "Ljdk/internal/net/http/Exchange$ConnectionAborter;", nullptr, $FINAL, $field(Exchange, connectionAborter)},
	{}
};

$MethodInfo _Exchange_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/MultiExchange;)V", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/MultiExchange<TT;>;)V", 0, $method(static_cast<void(Exchange::*)($HttpRequestImpl*,$MultiExchange*)>(&Exchange::init$))},
	{"<init>", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/MultiExchange;Ljava/security/AccessControlContext;)V", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/MultiExchange<TT;>;Ljava/security/AccessControlContext;)V", 0, $method(static_cast<void(Exchange::*)($HttpRequestImpl*,$MultiExchange*,$AccessControlContext*)>(&Exchange::init$))},
	{"cancel", "()V", nullptr, $PUBLIC, $method(static_cast<void(Exchange::*)()>(&Exchange::cancel))},
	{"cancel", "(Ljava/io/IOException;)V", nullptr, $PUBLIC, $method(static_cast<void(Exchange::*)($IOException*)>(&Exchange::cancel))},
	{"checkCancelled", "()V", nullptr, $PRIVATE, $method(static_cast<void(Exchange::*)()>(&Exchange::checkCancelled))},
	{"checkCancelled", "(Ljava/util/concurrent/CompletableFuture;Ljdk/internal/net/http/HttpConnection;)Ljava/util/concurrent/CompletableFuture;", "<T:Ljava/lang/Object;>(Ljava/util/concurrent/CompletableFuture<TT;>;Ljdk/internal/net/http/HttpConnection;)Ljava/util/concurrent/CompletableFuture<TT;>;", 0, $method(static_cast<$CompletableFuture*(Exchange::*)($CompletableFuture*,$HttpConnection*)>(&Exchange::checkCancelled))},
	{"checkFor407", "(Ljdk/internal/net/http/ExchangeImpl;Ljava/lang/Throwable;Ljava/util/function/Function;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/ExchangeImpl<TT;>;Ljava/lang/Throwable;Ljava/util/function/Function<Ljdk/internal/net/http/ExchangeImpl<TT;>;Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;>;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", $PRIVATE, $method(static_cast<$CompletableFuture*(Exchange::*)($ExchangeImpl*,$Throwable*,$Function*)>(&Exchange::checkFor407))},
	{"checkForUpgradeAsync", "(Ljdk/internal/net/http/Response;Ljdk/internal/net/http/ExchangeImpl;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/Response;Ljdk/internal/net/http/ExchangeImpl<TT;>;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", $PRIVATE, $method(static_cast<$CompletableFuture*(Exchange::*)($Response*,$ExchangeImpl*)>(&Exchange::checkForUpgradeAsync))},
	{"checkPermissions", "()Ljava/lang/SecurityException;", nullptr, $PRIVATE, $method(static_cast<$SecurityException*(Exchange::*)()>(&Exchange::checkPermissions))},
	{"client", "()Ljdk/internal/net/http/HttpClientImpl;", nullptr, 0, $method(static_cast<$HttpClientImpl*(Exchange::*)()>(&Exchange::client))},
	{"dbgString", "()Ljava/lang/String;", nullptr, 0, $method(static_cast<$String*(Exchange::*)()>(&Exchange::dbgString))},
	{"establishExchange", "(Ljdk/internal/net/http/HttpConnection;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/HttpConnection;)Ljava/util/concurrent/CompletableFuture<+Ljdk/internal/net/http/ExchangeImpl<TT;>;>;", $PRIVATE, $method(static_cast<$CompletableFuture*(Exchange::*)($HttpConnection*)>(&Exchange::establishExchange))},
	{"executor", "()Ljava/util/concurrent/Executor;", nullptr, 0, $method(static_cast<$Executor*(Exchange::*)()>(&Exchange::executor))},
	{"expectContinue", "(Ljdk/internal/net/http/ExchangeImpl;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/ExchangeImpl<TT;>;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", $PRIVATE, $method(static_cast<$CompletableFuture*(Exchange::*)($ExchangeImpl*)>(&Exchange::expectContinue))},
	{"getCancelCause", "()Ljava/io/IOException;", nullptr, $SYNCHRONIZED, $method(static_cast<$IOException*(Exchange::*)()>(&Exchange::getCancelCause))},
	{"getPushGroup", "()Ljdk/internal/net/http/PushGroup;", "()Ljdk/internal/net/http/PushGroup<TT;>;", 0, $method(static_cast<$PushGroup*(Exchange::*)()>(&Exchange::getPushGroup))},
	{"getURIForSecurityCheck", "()Ljava/net/URI;", nullptr, $PRIVATE, $method(static_cast<$URI*(Exchange::*)()>(&Exchange::getURIForSecurityCheck))},
	{"h2Upgrade", "()V", nullptr, $PUBLIC, $method(static_cast<void(Exchange::*)()>(&Exchange::h2Upgrade))},
	{"ignoreBody", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC, $method(static_cast<$CompletableFuture*(Exchange::*)()>(&Exchange::ignoreBody))},
	{"ignoreBody", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber<TT;>;", 0, $method(static_cast<$HttpResponse$BodySubscriber*(Exchange::*)($HttpResponse$ResponseInfo*)>(&Exchange::ignoreBody))},
	{"lambda$checkCancelled$1", "(Ljdk/internal/net/http/HttpConnection;Ljava/util/concurrent/CompletableFuture;Ljava/lang/Object;Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletableFuture*(Exchange::*)($HttpConnection*,$CompletableFuture*,Object$*,$Throwable*)>(&Exchange::lambda$checkCancelled$1))},
	{"lambda$checkForUpgradeAsync$13", "(Ljdk/internal/net/http/Http1Exchange;Ljdk/internal/net/http/Http2Connection;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(Exchange::*)($Http1Exchange*,$Http2Connection*)>(&Exchange::lambda$checkForUpgradeAsync$13))},
	{"lambda$checkForUpgradeAsync$14", "(Ljdk/internal/net/http/ExchangeImpl;Ljdk/internal/net/http/Http1Exchange;Ljava/lang/Object;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(Exchange::*)($ExchangeImpl*,$Http1Exchange*,Object$*)>(&Exchange::lambda$checkForUpgradeAsync$14))},
	{"lambda$establishExchange$2", "(Ljava/util/concurrent/CompletableFuture;Ljdk/internal/net/http/ExchangeImpl;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Exchange::*)($CompletableFuture*,$ExchangeImpl*,$Throwable*)>(&Exchange::lambda$establishExchange$2))},
	{"lambda$establishExchange$3", "(Ljdk/internal/net/http/ExchangeImpl;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(Exchange::*)($ExchangeImpl*)>(&Exchange::lambda$establishExchange$3))},
	{"lambda$expectContinue$4", "(Ljdk/internal/net/http/ExchangeImpl;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(Exchange::*)($ExchangeImpl*)>(&Exchange::lambda$expectContinue$4))},
	{"lambda$expectContinue$5", "(Ljdk/internal/net/http/Response;Ljava/lang/Object;)Ljdk/internal/net/http/Response;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Response*(*)($Response*,Object$*)>(&Exchange::lambda$expectContinue$5))},
	{"lambda$expectContinue$6", "(Ljdk/internal/net/http/Response;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(Exchange::*)($Response*)>(&Exchange::lambda$expectContinue$6))},
	{"lambda$readBodyAsync$0", "(Ljava/lang/Object;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Exchange::*)(Object$*,$Throwable*)>(&Exchange::lambda$readBodyAsync$0))},
	{"lambda$responseAsyncImpl0$8", "(Ljava/util/function/Function;Ljdk/internal/net/http/ExchangeImpl;Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletableFuture*(Exchange::*)($Function*,$ExchangeImpl*,$Throwable*)>(&Exchange::lambda$responseAsyncImpl0$8))},
	{"lambda$responseAsyncImpl0$9", "(Ljava/util/function/Function;Ljdk/internal/net/http/ExchangeImpl;)Ljava/util/concurrent/CompletableFuture;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletableFuture*(Exchange::*)($Function*,$ExchangeImpl*)>(&Exchange::lambda$responseAsyncImpl0$9))},
	{"lambda$wrapForLog$12", "(Ljdk/internal/net/http/Response;)Ljdk/internal/net/http/Response;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Response*(*)($Response*)>(&Exchange::lambda$wrapForLog$12))},
	{"lambda$wrapForUpgrade$11", "(Ljdk/internal/net/http/Response;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletionStage*(Exchange::*)($Response*)>(&Exchange::lambda$wrapForUpgrade$11))},
	{"nullBody", "(Ljava/net/http/HttpResponse;Ljava/lang/Throwable;)V", "(Ljava/net/http/HttpResponse<TT;>;Ljava/lang/Throwable;)V", 0, $method(static_cast<void(Exchange::*)($HttpResponse*,$Throwable*)>(&Exchange::nullBody))},
	{"permissionForServer", "(Ljava/net/URI;Ljava/lang/String;Ljava/util/Map;)Ljava/net/URLPermission;", "(Ljava/net/URI;Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;)Ljava/net/URLPermission;", $PRIVATE | $STATIC, $method(static_cast<$URLPermission*(*)($URI*,$String*,$Map*)>(&Exchange::permissionForServer))},
	{"readBodyAsync", "(Ljava/net/http/HttpResponse$BodyHandler;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/net/http/HttpResponse$BodyHandler<TT;>;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC, $method(static_cast<$CompletableFuture*(Exchange::*)($HttpResponse$BodyHandler*)>(&Exchange::readBodyAsync))},
	{"released", "()V", nullptr, $PUBLIC, $method(static_cast<void(Exchange::*)()>(&Exchange::released))},
	{"remainingConnectTimeout", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/time/Duration;>;", $PUBLIC, $method(static_cast<$Optional*(Exchange::*)()>(&Exchange::remainingConnectTimeout))},
	{"replaceHostInURI", "(Ljava/net/URI;Ljava/lang/String;)Ljava/net/URI;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$URI*(*)($URI*,$String*)>(&Exchange::replaceHostInURI))},
	{"request", "()Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PUBLIC, $method(static_cast<$HttpRequestImpl*(Exchange::*)()>(&Exchange::request))},
	{"responseAsync", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", $PUBLIC, $method(static_cast<$CompletableFuture*(Exchange::*)()>(&Exchange::responseAsync))},
	{"responseAsyncImpl", "(Ljdk/internal/net/http/HttpConnection;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/HttpConnection;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", 0, $method(static_cast<$CompletableFuture*(Exchange::*)($HttpConnection*)>(&Exchange::responseAsyncImpl))},
	{"responseAsyncImpl0", "(Ljdk/internal/net/http/HttpConnection;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/HttpConnection;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", 0, $method(static_cast<$CompletableFuture*(Exchange::*)($HttpConnection*)>(&Exchange::responseAsyncImpl0))},
	{"sendRequestBody", "(Ljdk/internal/net/http/ExchangeImpl;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/ExchangeImpl<TT;>;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", $PRIVATE, $method(static_cast<$CompletableFuture*(Exchange::*)($ExchangeImpl*)>(&Exchange::sendRequestBody))},
	{"version", "()Ljava/net/http/HttpClient$Version;", nullptr, 0, $method(static_cast<$HttpClient$Version*(Exchange::*)()>(&Exchange::version))},
	{"wrapForLog", "(Ljava/util/concurrent/CompletableFuture;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", $PRIVATE, $method(static_cast<$CompletableFuture*(Exchange::*)($CompletableFuture*)>(&Exchange::wrapForLog))},
	{"wrapForUpgrade", "(Ljava/util/concurrent/CompletableFuture;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Response;>;", $PRIVATE, $method(static_cast<$CompletableFuture*(Exchange::*)($CompletableFuture*)>(&Exchange::wrapForUpgrade))},
	{}
};

$InnerClassInfo _Exchange_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Exchange$ConnectionAborter", "jdk.internal.net.http.Exchange", "ConnectionAborter", $STATIC | $FINAL},
	{}
};

$ClassInfo _Exchange_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Exchange",
	"java.lang.Object",
	nullptr,
	_Exchange_FieldInfo_,
	_Exchange_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	_Exchange_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Exchange$ConnectionAborter"
};

$Object* allocate$Exchange($Class* clazz) {
	return $of($alloc(Exchange));
}

bool Exchange::$assertionsDisabled = false;

void Exchange::init$($HttpRequestImpl* request, $MultiExchange* multi) {
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(Exchange$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, connectionAborter, $new($Exchange$ConnectionAborter));
	$set(this, request$, request);
	this->upgrading = false;
	$set(this, client$, $nc(multi)->client());
	$set(this, multi, multi);
	$set(this, acc, multi->acc);
	$set(this, parentExecutor, multi->executor);
	$set(this, pushGroup, multi->pushGroup);
	$set(this, dbgTag, "Exchange"_s);
}

void Exchange::init$($HttpRequestImpl* request, $MultiExchange* multi, $AccessControlContext* acc) {
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(Exchange$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, connectionAborter, $new($Exchange$ConnectionAborter));
	$set(this, request$, request);
	$set(this, acc, acc);
	this->upgrading = false;
	$set(this, client$, $nc(multi)->client());
	$set(this, multi, multi);
	$set(this, parentExecutor, multi->executor);
	$set(this, pushGroup, multi->pushGroup);
	$set(this, dbgTag, "Exchange"_s);
}

$PushGroup* Exchange::getPushGroup() {
	return this->pushGroup;
}

$Executor* Exchange::executor() {
	return this->parentExecutor;
}

$HttpRequestImpl* Exchange::request() {
	return this->request$;
}

$Optional* Exchange::remainingConnectTimeout() {
	return $nc(this->multi)->remainingConnectTimeout();
}

$HttpClientImpl* Exchange::client() {
	return this->client$;
}

void Exchange::nullBody($HttpResponse* resp, $Throwable* t) {
	$nc(this->exchImpl)->nullBody(resp, t);
}

$CompletableFuture* Exchange::readBodyAsync($HttpResponse$BodyHandler* handler) {
	$useLocalCurrentObjectStackCache();
	if (this->bodyIgnored != nullptr) {
		return $MinimalFuture::completedFuture(nullptr);
	}
	return $cast($CompletableFuture, $nc($($nc(this->exchImpl)->readBodyAsync(handler, !$nc(this->request$)->isWebSocket(), this->parentExecutor)))->whenComplete(static_cast<$BiConsumer*>($$new(Exchange$$Lambda$lambda$readBodyAsync$0$1, this))));
}

$CompletableFuture* Exchange::ignoreBody() {
	if (this->bodyIgnored != nullptr) {
		return this->bodyIgnored;
	}
	return $nc(this->exchImpl)->ignoreBody();
}

void Exchange::released() {
	$var($ExchangeImpl, impl, this->exchImpl);
	if (impl != nullptr) {
		impl->released();
	}
}

void Exchange::cancel() {
	if (this->exchImpl != nullptr) {
		$nc(this->exchImpl)->cancel();
	} else {
		cancel($$new($IOException, "Request cancelled"_s));
	}
}

void Exchange::cancel($IOException* cause) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("cancel exchImpl: %s, with \"%s\""_s, $$new($ObjectArray, {
			$of(this->exchImpl),
			$of(cause)
		}));
	}
	$var($ExchangeImpl, impl, this->exchImpl);
	if (impl != nullptr) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Cancelling exchImpl: %s"_s, $$new($ObjectArray, {$of(this->exchImpl)}));
		}
		impl->cancel(cause);
	} else {
		$set(this, failed, cause);
		$nc(this->connectionAborter)->closeConnection();
		checkCancelled();
	}
}

void Exchange::checkCancelled() {
	$useLocalCurrentObjectStackCache();
	$var($ExchangeImpl, impl, nullptr);
	$var($IOException, cause, nullptr);
	$var($CompletableFuture, cf, nullptr);
	if (this->failed != nullptr) {
		$synchronized(this) {
			$assign(cause, this->failed);
			$assign(impl, this->exchImpl);
			$assign(cf, this->exchangeCF);
		}
	}
	if (cause == nullptr) {
		return;
	}
	if (impl != nullptr) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Cancelling exchImpl: %s"_s, $$new($ObjectArray, {$of(impl)}));
		}
		impl->cancel(cause);
		$set(this, failed, nullptr);
	} else {
		int64_t var$0 = 0;
		if ($nc($($nc(this->request$)->timeout()))->isPresent()) {
			int64_t var$1 = $nc(($cast($Duration, $($nc($($nc(this->request$)->timeout()))->get()))))->getSeconds() * 1000;
			var$0 = (var$1 + $nc(($cast($Duration, $($nc($($nc(this->request$)->timeout()))->get()))))->getNano() / 0x000F4240);
		} else {
			var$0 = -1;
		}
		$Log::logTrace("Exchange: request [{0}/timeout={1}ms] no impl is set.\n\tCan\'\'t cancel yet with {2}"_s, $$new($ObjectArray, {
			$($of($nc(this->request$)->uri())),
			$($of($Long::valueOf(var$0))),
			$of(cause)
		}));
		if (cf != nullptr) {
			cf->completeExceptionally(cause);
		}
	}
}

$CompletableFuture* Exchange::checkCancelled($CompletableFuture* cf, $HttpConnection* connection) {
	$useLocalCurrentObjectStackCache();
	return $cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc(cf)->handle(static_cast<$BiFunction*>($$new(Exchange$$Lambda$lambda$checkCancelled$1$2, this, connection, cf))))))->thenCompose($($Function::identity())));
}

void Exchange::h2Upgrade() {
	this->upgrading = true;
	$nc(this->request$)->setH2Upgrade($($nc(this->client$)->client2()));
}

$IOException* Exchange::getCancelCause() {
	$synchronized(this) {
		return this->failed;
	}
}

$CompletableFuture* Exchange::establishExchange($HttpConnection* connection) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("establishing exchange for %s,%n\t proxy=%s"_s, $$new($ObjectArray, {
			$of(this->request$),
			$($of($nc(this->request$)->proxy()))
		}));
	}
	$var($Throwable, t, getCancelCause());
	checkCancelled();
	if (t != nullptr) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("exchange was cancelled: returned failed cf (%s)"_s, $$new($ObjectArray, {$($of($String::valueOf($of(t))))}));
		}
		return $set(this, exchangeCF, $MinimalFuture::failedFuture(t));
	}
	$var($CompletableFuture, cf, nullptr);
	$var($CompletableFuture, res, nullptr);
	$assign(cf, $ExchangeImpl::get(this, connection));
	$synchronized(this) {
		$set(this, exchangeCF, cf);
	}
	$assign(res, $cast($CompletableFuture, $nc(cf)->whenComplete(static_cast<$BiConsumer*>($$new(Exchange$$Lambda$lambda$establishExchange$2$3, this, cf)))));
	checkCancelled();
	return $cast($CompletableFuture, $nc(res)->thenCompose(static_cast<$Function*>($$new(Exchange$$Lambda$lambda$establishExchange$3$4, this))));
}

$CompletableFuture* Exchange::responseAsync() {
	return responseAsyncImpl(nullptr);
}

$CompletableFuture* Exchange::responseAsyncImpl($HttpConnection* connection) {
	$var($SecurityException, e, checkPermissions());
	if (e != nullptr) {
		return $MinimalFuture::failedFuture(e);
	} else {
		return responseAsyncImpl0(connection);
	}
}

$CompletableFuture* Exchange::checkFor407($ExchangeImpl* ex, $Throwable* t$renamed, $Function* andThen) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, t, t$renamed);
	$assign(t, $Utils::getCompletionCause(t));
	if ($instanceOf($ProxyAuthenticationRequired, t)) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("checkFor407: ProxyAuthenticationRequired: building synthetic response"_s);
		}
		$set(this, bodyIgnored, $MinimalFuture::completedFuture(nullptr));
		$var($Response, proxyResponse, $nc(($cast($ProxyAuthenticationRequired, t)))->proxyResponse);
		$var($HttpConnection, c, ex == nullptr ? ($HttpConnection*)nullptr : $nc(ex)->connection());
		$var($Response, syntheticResponse, $new($Response, this->request$, this, $nc(proxyResponse)->headers$, c, proxyResponse->statusCode$, proxyResponse->version$, true));
		return $MinimalFuture::completedFuture(syntheticResponse);
	} else if (t != nullptr) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("checkFor407: no response - %s"_s, $$new($ObjectArray, {$of(t)}));
		}
		return $MinimalFuture::failedFuture(t);
	} else {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("checkFor407: all clear"_s);
		}
		return $cast($CompletableFuture, $nc(andThen)->apply(ex));
	}
}

$CompletableFuture* Exchange::expectContinue($ExchangeImpl* ex) {
	$useLocalCurrentObjectStackCache();
	if (!Exchange::$assertionsDisabled && !$nc(this->request$)->expectContinue()) {
		$throwNew($AssertionError);
	}
	return $cast($CompletableFuture, $nc($($nc(ex)->getResponseAsync(this->parentExecutor)))->thenCompose(static_cast<$Function*>($$new(Exchange$$Lambda$lambda$expectContinue$6$5, this))));
}

$CompletableFuture* Exchange::sendRequestBody($ExchangeImpl* ex) {
	$useLocalCurrentObjectStackCache();
	if (!Exchange::$assertionsDisabled && ! !$nc(this->request$)->expectContinue()) {
		$throwNew($AssertionError);
	}
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("sendRequestBody"_s);
	}
	$var($CompletableFuture, cf, $cast($CompletableFuture, $nc($($nc(ex)->sendBodyAsync()))->thenCompose(static_cast<$Function*>($$new(Exchange$$Lambda$lambda$expectContinue$4$6, this)))));
	$assign(cf, wrapForUpgrade(cf));
	$assign(cf, wrapForLog(cf));
	return cf;
}

$CompletableFuture* Exchange::responseAsyncImpl0($HttpConnection* connection) {
	$useLocalCurrentObjectStackCache();
	$var($Function, after407Check, nullptr);
	$set(this, bodyIgnored, nullptr);
	if ($nc(this->request$)->expectContinue()) {
		$nc(this->request$)->addSystemHeader("Expect"_s, "100-Continue"_s);
		$Log::logTrace("Sending Expect: 100-Continue"_s, $$new($ObjectArray, 0));
		$assign(after407Check, static_cast<$Function*>($new(Exchange$$Lambda$expectContinue$7, this)));
	} else {
		$assign(after407Check, static_cast<$Function*>($new(Exchange$$Lambda$sendRequestBody$8, this)));
	}
	$var($Function, afterExch407Check, static_cast<$Function*>($new(Exchange$$Lambda$lambda$responseAsyncImpl0$9$9, this, after407Check)));
	return $cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc($(establishExchange(connection)))->handle(static_cast<$BiFunction*>($$new(Exchange$$Lambda$lambda$responseAsyncImpl0$8$10, this, afterExch407Check))))))->thenCompose($($Function::identity())));
}

$CompletableFuture* Exchange::wrapForUpgrade($CompletableFuture* cf) {
	if (this->upgrading) {
		return $cast($CompletableFuture, $nc(cf)->thenCompose(static_cast<$Function*>($$new(Exchange$$Lambda$lambda$wrapForUpgrade$11$11, this))));
	}
	return cf;
}

$CompletableFuture* Exchange::wrapForLog($CompletableFuture* cf) {
	if ($Log::requests()) {
		return $cast($CompletableFuture, $nc(cf)->thenApply(static_cast<$Function*>($$new(Exchange$$Lambda$lambda$wrapForLog$12$12))));
	}
	return cf;
}

$HttpResponse$BodySubscriber* Exchange::ignoreBody($HttpResponse$ResponseInfo* hdrs) {
	return $HttpResponse$BodySubscribers::replacing(nullptr);
}

$CompletableFuture* Exchange::checkForUpgradeAsync($Response* resp, $ExchangeImpl* ex) {
	$useLocalCurrentObjectStackCache();
	int32_t rcode = $nc(resp)->statusCode();
	if (this->upgrading && (rcode == 101)) {
		$var($Http1Exchange, e, $cast($Http1Exchange, ex));
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Upgrading async %s"_s, $$new($ObjectArray, {$($of($nc(e)->connection()))}));
		}
		return $cast($CompletableFuture, $nc($($nc(e)->readBodyAsync(static_cast<$HttpResponse$BodyHandler*>($$new(Exchange$$Lambda$ignoreBody$13, this)), false, this->parentExecutor)))->thenCompose(static_cast<$Function*>($$new(Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14, this, ex, e))));
	}
	return $MinimalFuture::completedFuture(resp);
}

$URI* Exchange::getURIForSecurityCheck() {
	$useLocalCurrentObjectStackCache();
	$var($URI, u, nullptr);
	$var($String, method, $nc(this->request$)->method());
	$var($InetSocketAddress, authority, $nc(this->request$)->authority());
	$var($URI, uri, $nc(this->request$)->uri());
	if ($nc(method)->equalsIgnoreCase("CONNECT"_s)) {
		try {
			$var($String, var$0, "socket"_s);
			$var($String, var$1, $nc(authority)->getHostString());
			$assign(u, $new($URI, var$0, nullptr, var$1, authority->getPort(), nullptr, nullptr, nullptr));
		} catch ($URISyntaxException& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		}
	} else {
		$assign(u, uri);
	}
	return u;
}

$URLPermission* Exchange::permissionForServer($URI* uri, $String* method, $Map* headers) {
	$init(Exchange);
	$useLocalCurrentObjectStackCache();
	if ($nc(method)->equals("CONNECT"_s)) {
		return $new($URLPermission, $($nc(uri)->toString()), "CONNECT"_s);
	} else {
		return $Utils::permissionForServer(uri, method, $($nc($($nc(headers)->keySet()))->stream()));
	}
}

$SecurityException* Exchange::checkPermissions() {
	$useLocalCurrentObjectStackCache();
	$var($String, method, $nc(this->request$)->method());
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm == nullptr || $nc(method)->equals("CONNECT"_s)) {
		return nullptr;
	}
	$var($HttpHeaders, userHeaders, $nc(this->request$)->getUserHeaders());
	$var($URI, u, getURIForSecurityCheck());
	$var($URLPermission, p, permissionForServer(u, method, $($nc(userHeaders)->map())));
	try {
		if (!Exchange::$assertionsDisabled && !(this->acc != nullptr)) {
			$throwNew($AssertionError);
		}
		$nc(sm)->checkPermission(p, this->acc);
	} catch ($SecurityException& e) {
		return e;
	}
	$var($String, hostHeader, $cast($String, $nc($($nc(userHeaders)->firstValue("Host"_s)))->orElse(nullptr)));
	if (hostHeader != nullptr && !hostHeader->equalsIgnoreCase($($nc(u)->getHost()))) {
		$var($URI, u1, replaceHostInURI(u, hostHeader));
		$var($URLPermission, p1, permissionForServer(u1, method, $(userHeaders->map())));
		try {
			if (!Exchange::$assertionsDisabled && !(this->acc != nullptr)) {
				$throwNew($AssertionError);
			}
			$nc(sm)->checkPermission(p1, this->acc);
		} catch ($SecurityException& e) {
			return e;
		}
	}
	$var($ProxySelector, ps, $nc(this->client$)->proxySelector());
	if (ps != nullptr) {
		if (!$nc(method)->equals("CONNECT"_s)) {
			$var($URLPermission, proxyPerm, $Utils::permissionForProxy($($nc(this->request$)->proxy())));
			if (proxyPerm != nullptr) {
				try {
					$nc(sm)->checkPermission(proxyPerm, this->acc);
				} catch ($SecurityException& e) {
					return e;
				}
			}
		}
	}
	return nullptr;
}

$URI* Exchange::replaceHostInURI($URI* u, $String* hostPort) {
	$init(Exchange);
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($($nc(u)->getScheme()))->append("://"_s)->append(hostPort)->append($($nc(u)->getRawPath()));
	return $URI::create($(sb->toString()));
}

$HttpClient$Version* Exchange::version() {
	return $nc(this->multi)->version();
}

$String* Exchange::dbgString() {
	return this->dbgTag;
}

$CompletionStage* Exchange::lambda$checkForUpgradeAsync$14($ExchangeImpl* ex, $Http1Exchange* e, Object$* v) {
	$useLocalCurrentObjectStackCache();
	$nc(this->debug)->log("Ignored body"_s);
	$nc(ex)->upgraded();
	this->upgraded = true;
	$var($HttpConnection, var$0, $nc(e)->connection());
	$var($Http2ClientImpl, var$1, $nc(this->client$)->client2());
	return $nc($($Http2Connection::createAsync(var$0, var$1, this, static_cast<$Supplier*>($$new(Exchange$$Lambda$drainLeftOverBytes$15, static_cast<$Http1Exchange*>(e))))))->thenCompose(static_cast<$Function*>($$new(Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16, this, e)));
}

$CompletionStage* Exchange::lambda$checkForUpgradeAsync$13($Http1Exchange* e, $Http2Connection* c) {
	$useLocalCurrentObjectStackCache();
	bool cached = $nc(c)->offerConnection();
	if (cached) {
		$nc(this->connectionAborter)->disable();
	}
	$var($1Stream, s, c->getStream(1));
	if (s == nullptr) {
		$var($Throwable, t, c->getRecordedCause());
		$var($IOException, ioe, nullptr);
		if (t != nullptr) {
			if (!cached) {
				c->close();
			}
			$assign(ioe, $new($IOException, $$str({"Can\'t get stream 1: "_s, t}), t));
		} else {
			$assign(ioe, $new($IOException, "Can\'t get stream 1"_s));
		}
		return $MinimalFuture::failedFuture(ioe);
	}
	$nc(this->exchImpl)->released();
	$var($Throwable, t, nullptr);
	$synchronized(this) {
		$set(this, exchImpl, s);
		$assign(t, this->failed);
	}
	if (t == nullptr) {
		$assign(t, $nc(e)->getCancelCause());
	}
	if ($instanceOf($HttpTimeoutException, t) || $nc(this->multi)->requestCancelled()) {
		if (t == nullptr) {
			$assign(t, $new($IOException, "Request cancelled"_s));
		}
		$nc(s)->cancelImpl(t);
		return $MinimalFuture::failedFuture(t);
	}
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Getting response async %s"_s, $$new($ObjectArray, {$of(s)}));
	}
	return $nc(s)->getResponseAsync(nullptr);
}

$Response* Exchange::lambda$wrapForLog$12($Response* response) {
	$init(Exchange);
	$Log::logResponse(static_cast<$Supplier*>($$new(Exchange$$Lambda$toString$17, static_cast<$Response*>($nc(response)))));
	return response;
}

$CompletionStage* Exchange::lambda$wrapForUpgrade$11($Response* r) {
	return checkForUpgradeAsync(r, this->exchImpl);
}

$CompletableFuture* Exchange::lambda$responseAsyncImpl0$9($Function* after407Check, $ExchangeImpl* ex) {
	$useLocalCurrentObjectStackCache();
	return $cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc($($nc(ex)->sendHeadersAsync()))->handle(static_cast<$BiFunction*>($$new(Exchange$$Lambda$lambda$responseAsyncImpl0$8$10, this, after407Check))))))->thenCompose($($Function::identity())));
}

$CompletableFuture* Exchange::lambda$responseAsyncImpl0$8($Function* after407Check, $ExchangeImpl* r, $Throwable* t) {
	return this->checkFor407(r, t, after407Check);
}

$CompletionStage* Exchange::lambda$expectContinue$6($Response* r1) {
	$useLocalCurrentObjectStackCache();
	$Log::logResponse(static_cast<$Supplier*>($$new(Exchange$$Lambda$toString$17, static_cast<$Response*>($nc(r1)))));
	int32_t rcode = $nc(r1)->statusCode();
	if (rcode == 100) {
		$Log::logTrace("Received 100-Continue: sending body"_s, $$new($ObjectArray, 0));
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Received 100-Continue for %s"_s, $$new($ObjectArray, {$of(r1)}));
		}
		$var($CompletableFuture, cf, $cast($CompletableFuture, $nc($($nc(this->exchImpl)->sendBodyAsync()))->thenCompose(static_cast<$Function*>($$new(Exchange$$Lambda$lambda$expectContinue$4$6, this)))));
		$assign(cf, wrapForUpgrade(cf));
		$assign(cf, wrapForLog(cf));
		return cf;
	} else {
		$Log::logTrace("Expectation failed: Received {0}"_s, $$new($ObjectArray, {$($of($Integer::valueOf(rcode)))}));
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Expect-Continue failed (%d) for: %s"_s, $$new($ObjectArray, {
				$($of($Integer::valueOf(rcode))),
				$of(r1)
			}));
		}
		if (this->upgrading && rcode == 101) {
			$var($IOException, failed, $new($IOException, "Unable to handle 101 while waiting for 100"_s));
			return $MinimalFuture::failedFuture(failed);
		}
		return $nc($($nc(this->exchImpl)->readBodyAsync(static_cast<$HttpResponse$BodyHandler*>($$new(Exchange$$Lambda$ignoreBody$13, this)), false, this->parentExecutor)))->thenApply(static_cast<$Function*>($$new(Exchange$$Lambda$lambda$expectContinue$5$18, r1)));
	}
}

$Response* Exchange::lambda$expectContinue$5($Response* r1, Object$* v) {
	$init(Exchange);
	return r1;
}

$CompletionStage* Exchange::lambda$expectContinue$4($ExchangeImpl* exIm) {
	return $nc(exIm)->getResponseAsync(this->parentExecutor);
}

$CompletionStage* Exchange::lambda$establishExchange$3($ExchangeImpl* eimpl) {
	$set(this, exchImpl, eimpl);
	$var($IOException, tt, getCancelCause());
	checkCancelled();
	if (tt != nullptr) {
		return $MinimalFuture::failedFuture(tt);
	} else {
		return $MinimalFuture::completedFuture(eimpl);
	}
}

void Exchange::lambda$establishExchange$2($CompletableFuture* cf, $ExchangeImpl* r, $Throwable* x) {
	$synchronized(this) {
		if (this->exchangeCF == cf) {
			$set(this, exchangeCF, nullptr);
		}
	}
}

$CompletableFuture* Exchange::lambda$checkCancelled$1($HttpConnection* connection, $CompletableFuture* cf, Object$* r, $Throwable* t$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, t, t$renamed);
	if (t == nullptr) {
		if ($nc(this->multi)->requestCancelled()) {
			if (!this->upgraded) {
				$assign(t, getCancelCause());
				if (t == nullptr) {
					$assign(t, $new($IOException, "Request cancelled"_s));
				}
				if ($nc(this->debug)->on()) {
					$nc(this->debug)->log($$str({"exchange cancelled during connect: "_s, t}));
				}
				try {
					$nc(connection)->close();
				} catch ($Throwable& x) {
					if ($nc(this->debug)->on()) {
						$nc(this->debug)->log("Failed to close connection"_s, x);
					}
				}
				return $MinimalFuture::failedFuture(t);
			}
		}
	}
	return cf;
}

void Exchange::lambda$readBodyAsync$0(Object$* r, $Throwable* t) {
	$nc(this->exchImpl)->completed();
}

void clinit$Exchange($Class* class$) {
	Exchange::$assertionsDisabled = !Exchange::class$->desiredAssertionStatus();
}

Exchange::Exchange() {
}

$Class* Exchange::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Exchange$$Lambda$dbgString::classInfo$.name)) {
			return Exchange$$Lambda$dbgString::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$lambda$readBodyAsync$0$1::classInfo$.name)) {
			return Exchange$$Lambda$lambda$readBodyAsync$0$1::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$lambda$checkCancelled$1$2::classInfo$.name)) {
			return Exchange$$Lambda$lambda$checkCancelled$1$2::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$lambda$establishExchange$2$3::classInfo$.name)) {
			return Exchange$$Lambda$lambda$establishExchange$2$3::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$lambda$establishExchange$3$4::classInfo$.name)) {
			return Exchange$$Lambda$lambda$establishExchange$3$4::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$lambda$expectContinue$6$5::classInfo$.name)) {
			return Exchange$$Lambda$lambda$expectContinue$6$5::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$lambda$expectContinue$4$6::classInfo$.name)) {
			return Exchange$$Lambda$lambda$expectContinue$4$6::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$expectContinue$7::classInfo$.name)) {
			return Exchange$$Lambda$expectContinue$7::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$sendRequestBody$8::classInfo$.name)) {
			return Exchange$$Lambda$sendRequestBody$8::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$lambda$responseAsyncImpl0$9$9::classInfo$.name)) {
			return Exchange$$Lambda$lambda$responseAsyncImpl0$9$9::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$lambda$responseAsyncImpl0$8$10::classInfo$.name)) {
			return Exchange$$Lambda$lambda$responseAsyncImpl0$8$10::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$lambda$wrapForUpgrade$11$11::classInfo$.name)) {
			return Exchange$$Lambda$lambda$wrapForUpgrade$11$11::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$lambda$wrapForLog$12$12::classInfo$.name)) {
			return Exchange$$Lambda$lambda$wrapForLog$12$12::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$ignoreBody$13::classInfo$.name)) {
			return Exchange$$Lambda$ignoreBody$13::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14::classInfo$.name)) {
			return Exchange$$Lambda$lambda$checkForUpgradeAsync$14$14::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$drainLeftOverBytes$15::classInfo$.name)) {
			return Exchange$$Lambda$drainLeftOverBytes$15::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16::classInfo$.name)) {
			return Exchange$$Lambda$lambda$checkForUpgradeAsync$13$16::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$toString$17::classInfo$.name)) {
			return Exchange$$Lambda$toString$17::load$(name, initialize);
		}
		if (name->equals(Exchange$$Lambda$lambda$expectContinue$5$18::classInfo$.name)) {
			return Exchange$$Lambda$lambda$expectContinue$5$18::load$(name, initialize);
		}
	}
	$loadClass(Exchange, name, initialize, &_Exchange_ClassInfo_, clinit$Exchange, allocate$Exchange);
	return class$;
}

$Class* Exchange::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk