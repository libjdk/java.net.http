#include <jdk/internal/net/http/HttpClientImpl.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Error.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/WeakReference.h>
#include <java/net/Authenticator.h>
#include <java/net/ConnectException.h>
#include <java/net/CookieHandler.h>
#include <java/net/ProxySelector.h>
#include <java/net/URI.h>
#include <java/net/http/HttpClient$Redirect.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpClient.h>
#include <java/net/http/HttpConnectTimeoutException.h>
#include <java/net/http/HttpRequest.h>
#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/net/http/HttpResponse$PushPromiseHandler.h>
#include <java/net/http/HttpResponse.h>
#include <java/net/http/HttpTimeoutException.h>
#include <java/net/http/WebSocket$Builder.h>
#include <java/nio/channels/SelectableChannel.h>
#include <java/nio/channels/SelectionKey.h>
#include <java/nio/channels/Selector.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivilegedAction.h>
#include <java/time/Duration.h>
#include <java/time/Instant.h>
#include <java/time/temporal/ChronoUnit.h>
#include <java/time/temporal/Temporal.h>
#include <java/time/temporal/TemporalUnit.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/TreeSet.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/ExecutionException.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/Executors.h>
#include <java/util/concurrent/ThreadFactory.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BooleanSupplier.h>
#include <java/util/function/Supplier.h>
#include <javax/net/ssl/SSLContext.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <javax/net/ssl/SSLParameters.h>
#include <jdk/internal/net/http/AsyncEvent.h>
#include <jdk/internal/net/http/AsyncTriggerEvent.h>
#include <jdk/internal/net/http/AuthenticationFilter.h>
#include <jdk/internal/net/http/ConnectionPool.h>
#include <jdk/internal/net/http/CookieFilter.h>
#include <jdk/internal/net/http/FilterFactory.h>
#include <jdk/internal/net/http/Http2ClientImpl.h>
#include <jdk/internal/net/http/HttpClientBuilderImpl.h>
#include <jdk/internal/net/http/HttpClientFacade.h>
#include <jdk/internal/net/http/HttpClientImpl$DefaultThreadFactory.h>
#include <jdk/internal/net/http/HttpClientImpl$DelegatingExecutor.h>
#include <jdk/internal/net/http/HttpClientImpl$HttpClientTracker.h>
#include <jdk/internal/net/http/HttpClientImpl$SSLDirectBufferSupplier.h>
#include <jdk/internal/net/http/HttpClientImpl$SelectorAttachment.h>
#include <jdk/internal/net/http/HttpClientImpl$SelectorManager.h>
#include <jdk/internal/net/http/HttpClientImpl$SingleFacadeFactory.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/RedirectFilter.h>
#include <jdk/internal/net/http/TimeoutEvent.h>
#include <jdk/internal/net/http/common/BufferSupplier.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/OperationTrackers$Tracker.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/websocket/BuilderImpl.h>
#include <jcpp.h>

#undef ASYNC_POOL
#undef CLIENT_IDS
#undef DEBUG
#undef DEBUGELAPSED
#undef DEBUGTIMEOUT
#undef HTTP_2
#undef MILLIS
#undef NEVER
#undef TESTING

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Reference = ::java::lang::ref::Reference;
using $WeakReference = ::java::lang::ref::WeakReference;
using $Authenticator = ::java::net::Authenticator;
using $ConnectException = ::java::net::ConnectException;
using $CookieHandler = ::java::net::CookieHandler;
using $ProxySelector = ::java::net::ProxySelector;
using $URI = ::java::net::URI;
using $HttpClient = ::java::net::http::HttpClient;
using $HttpClient$Redirect = ::java::net::http::HttpClient$Redirect;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpConnectTimeoutException = ::java::net::http::HttpConnectTimeoutException;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpResponse = ::java::net::http::HttpResponse;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $HttpResponse$PushPromiseHandler = ::java::net::http::HttpResponse$PushPromiseHandler;
using $HttpTimeoutException = ::java::net::http::HttpTimeoutException;
using $WebSocket$Builder = ::java::net::http::WebSocket$Builder;
using $SelectableChannel = ::java::nio::channels::SelectableChannel;
using $SelectionKey = ::java::nio::channels::SelectionKey;
using $Selector = ::java::nio::channels::Selector;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Duration = ::java::time::Duration;
using $Instant = ::java::time::Instant;
using $ChronoUnit = ::java::time::temporal::ChronoUnit;
using $Temporal = ::java::time::temporal::Temporal;
using $TemporalUnit = ::java::time::temporal::TemporalUnit;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $TreeSet = ::java::util::TreeSet;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $ExecutionException = ::java::util::concurrent::ExecutionException;
using $Executor = ::java::util::concurrent::Executor;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $Executors = ::java::util::concurrent::Executors;
using $ThreadFactory = ::java::util::concurrent::ThreadFactory;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BooleanSupplier = ::java::util::function::BooleanSupplier;
using $Supplier = ::java::util::function::Supplier;
using $SSLContext = ::javax::net::ssl::SSLContext;
using $SSLException = ::javax::net::ssl::SSLException;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $SSLParameters = ::javax::net::ssl::SSLParameters;
using $AsyncEvent = ::jdk::internal::net::http::AsyncEvent;
using $AsyncTriggerEvent = ::jdk::internal::net::http::AsyncTriggerEvent;
using $AuthenticationFilter = ::jdk::internal::net::http::AuthenticationFilter;
using $ConnectionPool = ::jdk::internal::net::http::ConnectionPool;
using $CookieFilter = ::jdk::internal::net::http::CookieFilter;
using $FilterFactory = ::jdk::internal::net::http::FilterFactory;
using $Http2ClientImpl = ::jdk::internal::net::http::Http2ClientImpl;
using $HttpClientBuilderImpl = ::jdk::internal::net::http::HttpClientBuilderImpl;
using $HttpClientFacade = ::jdk::internal::net::http::HttpClientFacade;
using $HttpClientImpl$DefaultThreadFactory = ::jdk::internal::net::http::HttpClientImpl$DefaultThreadFactory;
using $HttpClientImpl$DelegatingExecutor = ::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor;
using $HttpClientImpl$HttpClientTracker = ::jdk::internal::net::http::HttpClientImpl$HttpClientTracker;
using $HttpClientImpl$SSLDirectBufferSupplier = ::jdk::internal::net::http::HttpClientImpl$SSLDirectBufferSupplier;
using $HttpClientImpl$SelectorAttachment = ::jdk::internal::net::http::HttpClientImpl$SelectorAttachment;
using $HttpClientImpl$SelectorManager = ::jdk::internal::net::http::HttpClientImpl$SelectorManager;
using $HttpClientImpl$SingleFacadeFactory = ::jdk::internal::net::http::HttpClientImpl$SingleFacadeFactory;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;
using $RedirectFilter = ::jdk::internal::net::http::RedirectFilter;
using $TimeoutEvent = ::jdk::internal::net::http::TimeoutEvent;
using $BufferSupplier = ::jdk::internal::net::http::common::BufferSupplier;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $OperationTrackers$Trackable = ::jdk::internal::net::http::common::OperationTrackers$Trackable;
using $OperationTrackers$Tracker = ::jdk::internal::net::http::common::OperationTrackers$Tracker;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $BuilderImpl = ::jdk::internal::net::http::websocket::BuilderImpl;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class HttpClientImpl$$Lambda$dbgString : public $Supplier {
	$class(HttpClientImpl$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(HttpClientImpl* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$$Lambda$dbgString>());
	}
	HttpClientImpl* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpClientImpl$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HttpClientImpl$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo HttpClientImpl$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/HttpClientImpl;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$$Lambda$dbgString::*)(HttpClientImpl*)>(&HttpClientImpl$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* HttpClientImpl$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$$Lambda$dbgString::class$ = nullptr;

class HttpClientImpl$$Lambda$isSelectorThread$1 : public $BooleanSupplier {
	$class(HttpClientImpl$$Lambda$isSelectorThread$1, $NO_CLASS_INIT, $BooleanSupplier)
public:
	void init$(HttpClientImpl* inst) {
		$set(this, inst$, inst);
	}
	virtual bool getAsBoolean() override {
		 return $nc(inst$)->isSelectorThread();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$$Lambda$isSelectorThread$1>());
	}
	HttpClientImpl* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpClientImpl$$Lambda$isSelectorThread$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HttpClientImpl$$Lambda$isSelectorThread$1, inst$)},
	{}
};
$MethodInfo HttpClientImpl$$Lambda$isSelectorThread$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/HttpClientImpl;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$$Lambda$isSelectorThread$1::*)(HttpClientImpl*)>(&HttpClientImpl$$Lambda$isSelectorThread$1::init$))},
	{"getAsBoolean", "()Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$$Lambda$isSelectorThread$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$$Lambda$isSelectorThread$1",
	"java.lang.Object",
	"java.util.function.BooleanSupplier",
	fieldInfos,
	methodInfos
};
$Class* HttpClientImpl$$Lambda$isSelectorThread$1::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$$Lambda$isSelectorThread$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$$Lambda$isSelectorThread$1::class$ = nullptr;

class HttpClientImpl$$Lambda$getDefaultProxySelector$2 : public $Supplier {
	$class(HttpClientImpl$$Lambda$getDefaultProxySelector$2, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(HttpClientImpl::getDefaultProxySelector());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$$Lambda$getDefaultProxySelector$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpClientImpl$$Lambda$getDefaultProxySelector$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$$Lambda$getDefaultProxySelector$2::*)()>(&HttpClientImpl$$Lambda$getDefaultProxySelector$2::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$$Lambda$getDefaultProxySelector$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$$Lambda$getDefaultProxySelector$2",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* HttpClientImpl$$Lambda$getDefaultProxySelector$2::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$$Lambda$getDefaultProxySelector$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$$Lambda$getDefaultProxySelector$2::class$ = nullptr;

class HttpClientImpl$$Lambda$getDefault$3 : public $PrivilegedAction {
	$class(HttpClientImpl$$Lambda$getDefault$3, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of($ProxySelector::getDefault());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$$Lambda$getDefault$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpClientImpl$$Lambda$getDefault$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$$Lambda$getDefault$3::*)()>(&HttpClientImpl$$Lambda$getDefault$3::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$$Lambda$getDefault$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$$Lambda$getDefault$3",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* HttpClientImpl$$Lambda$getDefault$3::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$$Lambda$getDefault$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$$Lambda$getDefault$3::class$ = nullptr;

class HttpClientImpl$$Lambda$lambda$sendAsync$0$4 : public $BiConsumer {
	$class(HttpClientImpl$$Lambda$lambda$sendAsync$0$4, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(HttpClientImpl* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* b, Object$* t) override {
		$nc(inst$)->lambda$sendAsync$0($cast($HttpResponse, b), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$$Lambda$lambda$sendAsync$0$4>());
	}
	HttpClientImpl* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpClientImpl$$Lambda$lambda$sendAsync$0$4::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HttpClientImpl$$Lambda$lambda$sendAsync$0$4, inst$)},
	{}
};
$MethodInfo HttpClientImpl$$Lambda$lambda$sendAsync$0$4::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/HttpClientImpl;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$$Lambda$lambda$sendAsync$0$4::*)(HttpClientImpl*)>(&HttpClientImpl$$Lambda$lambda$sendAsync$0$4::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$$Lambda$lambda$sendAsync$0$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$$Lambda$lambda$sendAsync$0$4",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* HttpClientImpl$$Lambda$lambda$sendAsync$0$4::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$$Lambda$lambda$sendAsync$0$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$$Lambda$lambda$sendAsync$0$4::class$ = nullptr;

class HttpClientImpl$$Lambda$lambda$sendAsync$1$5 : public $BiConsumer {
	$class(HttpClientImpl$$Lambda$lambda$sendAsync$1$5, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(HttpClientImpl* inst, int64_t start, $HttpRequest* userRequest) {
		$set(this, inst$, inst);
		this->start = start;
		$set(this, userRequest, userRequest);
	}
	virtual void accept(Object$* b, Object$* t) override {
		$nc(inst$)->lambda$sendAsync$1(start, userRequest, $cast($HttpResponse, b), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$$Lambda$lambda$sendAsync$1$5>());
	}
	HttpClientImpl* inst$ = nullptr;
	int64_t start = 0;
	$HttpRequest* userRequest = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpClientImpl$$Lambda$lambda$sendAsync$1$5::fieldInfos[4] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HttpClientImpl$$Lambda$lambda$sendAsync$1$5, inst$)},
	{"start", "J", nullptr, $PUBLIC, $field(HttpClientImpl$$Lambda$lambda$sendAsync$1$5, start)},
	{"userRequest", "Ljava/net/http/HttpRequest;", nullptr, $PUBLIC, $field(HttpClientImpl$$Lambda$lambda$sendAsync$1$5, userRequest)},
	{}
};
$MethodInfo HttpClientImpl$$Lambda$lambda$sendAsync$1$5::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/HttpClientImpl;JLjava/net/http/HttpRequest;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$$Lambda$lambda$sendAsync$1$5::*)(HttpClientImpl*,int64_t,$HttpRequest*)>(&HttpClientImpl$$Lambda$lambda$sendAsync$1$5::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$$Lambda$lambda$sendAsync$1$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$$Lambda$lambda$sendAsync$1$5",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* HttpClientImpl$$Lambda$lambda$sendAsync$1$5::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$$Lambda$lambda$sendAsync$1$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$$Lambda$lambda$sendAsync$1$5::class$ = nullptr;

class HttpClientImpl$$Lambda$lambda$sendAsync$2$6 : public $BiConsumer {
	$class(HttpClientImpl$$Lambda$lambda$sendAsync$2$6, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* r, Object$* t) override {
		HttpClientImpl::lambda$sendAsync$2($cast($HttpResponse, r), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$$Lambda$lambda$sendAsync$2$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpClientImpl$$Lambda$lambda$sendAsync$2$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$$Lambda$lambda$sendAsync$2$6::*)()>(&HttpClientImpl$$Lambda$lambda$sendAsync$2$6::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$$Lambda$lambda$sendAsync$2$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$$Lambda$lambda$sendAsync$2$6",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* HttpClientImpl$$Lambda$lambda$sendAsync$2$6::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$$Lambda$lambda$sendAsync$2$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$$Lambda$lambda$sendAsync$2$6::class$ = nullptr;

$FieldInfo _HttpClientImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HttpClientImpl, $assertionsDisabled)},
	{"DEBUGELAPSED", "Z", nullptr, $STATIC | $FINAL, $staticField(HttpClientImpl, DEBUGELAPSED)},
	{"DEBUGTIMEOUT", "Z", nullptr, $STATIC | $FINAL, $constField(HttpClientImpl, DEBUGTIMEOUT)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(HttpClientImpl, debug)},
	{"debugelapsed", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(HttpClientImpl, debugelapsed)},
	{"debugtimeout", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(HttpClientImpl, debugtimeout)},
	{"CLIENT_IDS", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $STATIC | $FINAL, $staticField(HttpClientImpl, CLIENT_IDS)},
	{"cookieHandler", "Ljava/net/CookieHandler;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, cookieHandler$)},
	{"connectTimeout", "Ljava/time/Duration;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, connectTimeout$)},
	{"followRedirects", "Ljava/net/http/HttpClient$Redirect;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, followRedirects$)},
	{"userProxySelector", "Ljava/net/ProxySelector;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, userProxySelector)},
	{"proxySelector", "Ljava/net/ProxySelector;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, proxySelector$)},
	{"authenticator", "Ljava/net/Authenticator;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, authenticator$)},
	{"version", "Ljava/net/http/HttpClient$Version;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, version$)},
	{"connections", "Ljdk/internal/net/http/ConnectionPool;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, connections)},
	{"delegatingExecutor", "Ljdk/internal/net/http/HttpClientImpl$DelegatingExecutor;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, delegatingExecutor)},
	{"isDefaultExecutor", "Z", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, isDefaultExecutor)},
	{"sslContext", "Ljavax/net/ssl/SSLContext;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, sslContext$)},
	{"sslParams", "Ljavax/net/ssl/SSLParameters;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, sslParams)},
	{"selmgr", "Ljdk/internal/net/http/HttpClientImpl$SelectorManager;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, selmgr)},
	{"filters", "Ljdk/internal/net/http/FilterFactory;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, filters)},
	{"client2", "Ljdk/internal/net/http/Http2ClientImpl;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, client2$)},
	{"id", "J", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, id)},
	{"dbgTag", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, dbgTag)},
	{"sslBufferSupplier", "Ljdk/internal/net/http/HttpClientImpl$SSLDirectBufferSupplier;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, sslBufferSupplier)},
	{"facadeRef", "Ljava/lang/ref/WeakReference;", "Ljava/lang/ref/WeakReference<Ljdk/internal/net/http/HttpClientFacade;>;", $PRIVATE | $FINAL, $field(HttpClientImpl, facadeRef)},
	{"pendingOperationCount", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, pendingOperationCount)},
	{"pendingWebSocketCount", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, pendingWebSocketCount)},
	{"pendingHttpRequestCount", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, pendingHttpRequestCount)},
	{"pendingHttp2StreamCount", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl, pendingHttp2StreamCount)},
	{"timeouts", "Ljava/util/TreeSet;", "Ljava/util/TreeSet<Ljdk/internal/net/http/TimeoutEvent;>;", $PRIVATE | $FINAL, $field(HttpClientImpl, timeouts)},
	{"ASYNC_POOL", "Ljava/util/concurrent/Executor;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpClientImpl, ASYNC_POOL)},
	{}
};

$MethodInfo _HttpClientImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljdk/internal/net/http/HttpClientBuilderImpl;Ljdk/internal/net/http/HttpClientImpl$SingleFacadeFactory;)V", nullptr, $PRIVATE, $method(static_cast<void(HttpClientImpl::*)($HttpClientBuilderImpl*,$HttpClientImpl$SingleFacadeFactory*)>(&HttpClientImpl::init$))},
	{"addFilter", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<+Ljdk/internal/net/http/HeaderFilter;>;)V", $PRIVATE, $method(static_cast<void(HttpClientImpl::*)($Class*)>(&HttpClientImpl::addFilter))},
	{"authenticator", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/Authenticator;>;", $PUBLIC},
	{"cancelTimer", "(Ljdk/internal/net/http/TimeoutEvent;)V", nullptr, $SYNCHRONIZED, $method(static_cast<void(HttpClientImpl::*)($TimeoutEvent*)>(&HttpClientImpl::cancelTimer))},
	{"client2", "()Ljdk/internal/net/http/Http2ClientImpl;", nullptr, 0, $method(static_cast<$Http2ClientImpl*(HttpClientImpl::*)()>(&HttpClientImpl::client2))},
	{"connectTimeout", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/time/Duration;>;", $PUBLIC},
	{"connectionPool", "()Ljdk/internal/net/http/ConnectionPool;", nullptr, 0, $method(static_cast<$ConnectionPool*(HttpClientImpl::*)()>(&HttpClientImpl::connectionPool))},
	{"cookieHandler", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/CookieHandler;>;", $PUBLIC},
	{"create", "(Ljdk/internal/net/http/HttpClientBuilderImpl;)Ljdk/internal/net/http/HttpClientFacade;", nullptr, $STATIC, $method(static_cast<$HttpClientFacade*(*)($HttpClientBuilderImpl*)>(&HttpClientImpl::create))},
	{"dbgString", "()Ljava/lang/String;", nullptr, 0, $method(static_cast<$String*(HttpClientImpl::*)()>(&HttpClientImpl::dbgString))},
	{"debugCompleted", "(Ljava/lang/String;JLjava/net/http/HttpRequest;)V", nullptr, $PRIVATE, $method(static_cast<void(HttpClientImpl::*)($String*,int64_t,$HttpRequest*)>(&HttpClientImpl::debugCompleted))},
	{"debugInterestOps", "(Ljava/nio/channels/SelectableChannel;)Ljava/lang/String;", nullptr, $FINAL, $method(static_cast<$String*(HttpClientImpl::*)($SelectableChannel*)>(&HttpClientImpl::debugInterestOps))},
	{"eventUpdated", "(Ljdk/internal/net/http/AsyncEvent;)V", nullptr, 0, $method(static_cast<void(HttpClientImpl::*)($AsyncEvent*)>(&HttpClientImpl::eventUpdated)), "java.nio.channels.ClosedChannelException"},
	{"executor", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/util/concurrent/Executor;>;", $PUBLIC | $FINAL},
	{"facade", "()Ljdk/internal/net/http/HttpClientFacade;", nullptr, $FINAL, $method(static_cast<$HttpClientFacade*(HttpClientImpl::*)()>(&HttpClientImpl::facade))},
	{"filterChain", "()Ljava/util/LinkedList;", "()Ljava/util/LinkedList<Ljdk/internal/net/http/HeaderFilter;>;", $FINAL, $method(static_cast<$LinkedList*(HttpClientImpl::*)()>(&HttpClientImpl::filterChain))},
	{"followRedirects", "()Ljava/net/http/HttpClient$Redirect;", nullptr, $PUBLIC},
	{"getDefaultParams", "(Ljavax/net/ssl/SSLContext;)Ljavax/net/ssl/SSLParameters;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$SSLParameters*(*)($SSLContext*)>(&HttpClientImpl::getDefaultParams))},
	{"getDefaultProxySelector", "()Ljava/net/ProxySelector;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$ProxySelector*(*)()>(&HttpClientImpl::getDefaultProxySelector))},
	{"getOperationsTracker", "()Ljdk/internal/net/http/common/OperationTrackers$Tracker;", nullptr, $PUBLIC},
	{"getReceiveBufferSize", "()I", nullptr, 0, $method(static_cast<int32_t(HttpClientImpl::*)()>(&HttpClientImpl::getReceiveBufferSize))},
	{"getSSLBufferSupplier", "()Ljdk/internal/net/http/common/BufferSupplier;", nullptr, 0, $method(static_cast<$BufferSupplier*(HttpClientImpl::*)()>(&HttpClientImpl::getSSLBufferSupplier))},
	{"getSendBufferSize", "()I", nullptr, 0, $method(static_cast<int32_t(HttpClientImpl::*)()>(&HttpClientImpl::getSendBufferSize))},
	{"initFilters", "()V", nullptr, $PRIVATE, $method(static_cast<void(HttpClientImpl::*)()>(&HttpClientImpl::initFilters))},
	{"isReferenced", "()Z", nullptr, $FINAL, $method(static_cast<bool(HttpClientImpl::*)()>(&HttpClientImpl::isReferenced))},
	{"isSelectorThread", "()Z", nullptr, 0, $method(static_cast<bool(HttpClientImpl::*)()>(&HttpClientImpl::isSelectorThread))},
	{"lambda$sendAsync$0", "(Ljava/net/http/HttpResponse;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(HttpClientImpl::*)($HttpResponse*,$Throwable*)>(&HttpClientImpl::lambda$sendAsync$0))},
	{"lambda$sendAsync$1", "(JLjava/net/http/HttpRequest;Ljava/net/http/HttpResponse;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(HttpClientImpl::*)(int64_t,$HttpRequest*,$HttpResponse*,$Throwable*)>(&HttpClientImpl::lambda$sendAsync$1))},
	{"lambda$sendAsync$2", "(Ljava/net/http/HttpResponse;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($HttpResponse*,$Throwable*)>(&HttpClientImpl::lambda$sendAsync$2))},
	{"newWebSocketBuilder", "()Ljava/net/http/WebSocket$Builder;", nullptr, $PUBLIC},
	{"proxy", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/ProxySelector;>;", $PUBLIC},
	{"proxySelector", "()Ljava/net/ProxySelector;", nullptr, 0, $method(static_cast<$ProxySelector*(HttpClientImpl::*)()>(&HttpClientImpl::proxySelector))},
	{"purgeTimeoutsAndReturnNextDeadline", "()J", nullptr, $PRIVATE, $method(static_cast<int64_t(HttpClientImpl::*)()>(&HttpClientImpl::purgeTimeoutsAndReturnNextDeadline))},
	{"reference", "()J", nullptr, $FINAL, $method(static_cast<int64_t(HttpClientImpl::*)()>(&HttpClientImpl::reference))},
	{"referenceCount", "()J", nullptr, $FINAL, $method(static_cast<int64_t(HttpClientImpl::*)()>(&HttpClientImpl::referenceCount))},
	{"registerEvent", "(Ljdk/internal/net/http/AsyncEvent;)V", nullptr, 0, $method(static_cast<void(HttpClientImpl::*)($AsyncEvent*)>(&HttpClientImpl::registerEvent)), "java.io.IOException"},
	{"registerTimer", "(Ljdk/internal/net/http/TimeoutEvent;)V", nullptr, $SYNCHRONIZED, $method(static_cast<void(HttpClientImpl::*)($TimeoutEvent*)>(&HttpClientImpl::registerTimer))},
	{"send", "(Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler;)Ljava/net/http/HttpResponse;", "<T:Ljava/lang/Object;>(Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler<TT;>;)Ljava/net/http/HttpResponse<TT;>;", $PUBLIC, nullptr, "java.io.IOException,java.lang.InterruptedException"},
	{"sendAsync", "(Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler;)Ljava/util/concurrent/CompletableFuture;", "<T:Ljava/lang/Object;>(Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler<TT;>;)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;", $PUBLIC},
	{"sendAsync", "(Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler;Ljava/net/http/HttpResponse$PushPromiseHandler;)Ljava/util/concurrent/CompletableFuture;", "<T:Ljava/lang/Object;>(Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler<TT;>;Ljava/net/http/HttpResponse$PushPromiseHandler<TT;>;)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;", $PUBLIC},
	{"sendAsync", "(Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler;Ljava/net/http/HttpResponse$PushPromiseHandler;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture;", "<T:Ljava/lang/Object;>(Ljava/net/http/HttpRequest;Ljava/net/http/HttpResponse$BodyHandler<TT;>;Ljava/net/http/HttpResponse$PushPromiseHandler<TT;>;Ljava/util/concurrent/Executor;)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;", $PRIVATE, $method(static_cast<$CompletableFuture*(HttpClientImpl::*)($HttpRequest*,$HttpResponse$BodyHandler*,$HttpResponse$PushPromiseHandler*,$Executor*)>(&HttpClientImpl::sendAsync))},
	{"sslContext", "()Ljavax/net/ssl/SSLContext;", nullptr, $PUBLIC},
	{"sslParameters", "()Ljavax/net/ssl/SSLParameters;", nullptr, $PUBLIC},
	{"start", "()V", nullptr, $PRIVATE, $method(static_cast<void(HttpClientImpl::*)()>(&HttpClientImpl::start))},
	{"stop", "()V", nullptr, $PRIVATE, $method(static_cast<void(HttpClientImpl::*)()>(&HttpClientImpl::stop))},
	{"streamReference", "()J", nullptr, $FINAL, $method(static_cast<int64_t(HttpClientImpl::*)()>(&HttpClientImpl::streamReference))},
	{"streamUnreference", "()J", nullptr, $FINAL, $method(static_cast<int64_t(HttpClientImpl::*)()>(&HttpClientImpl::streamUnreference))},
	{"theExecutor", "()Ljdk/internal/net/http/HttpClientImpl$DelegatingExecutor;", nullptr, $FINAL, $method(static_cast<$HttpClientImpl$DelegatingExecutor*(HttpClientImpl::*)()>(&HttpClientImpl::theExecutor))},
	{"theSSLContext", "()Ljavax/net/ssl/SSLContext;", nullptr, 0, $method(static_cast<$SSLContext*(HttpClientImpl::*)()>(&HttpClientImpl::theSSLContext))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unreference", "()J", nullptr, $FINAL, $method(static_cast<int64_t(HttpClientImpl::*)()>(&HttpClientImpl::unreference))},
	{"version", "()Ljava/net/http/HttpClient$Version;", nullptr, $PUBLIC},
	{"webSocketClose", "()J", nullptr, $FINAL, $method(static_cast<int64_t(HttpClientImpl::*)()>(&HttpClientImpl::webSocketClose))},
	{"webSocketOpen", "()J", nullptr, $FINAL, $method(static_cast<int64_t(HttpClientImpl::*)()>(&HttpClientImpl::webSocketOpen))},
	{}
};

$InnerClassInfo _HttpClientImpl_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.OperationTrackers$Trackable", "jdk.internal.net.http.common.OperationTrackers", "Trackable", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.HttpClientImpl$SSLDirectBufferSupplier", "jdk.internal.net.http.HttpClientImpl", "SSLDirectBufferSupplier", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.net.http.HttpClientImpl$SelectorAttachment", "jdk.internal.net.http.HttpClientImpl", "SelectorAttachment", $PRIVATE | $STATIC},
	{"jdk.internal.net.http.HttpClientImpl$SelectorManager", "jdk.internal.net.http.HttpClientImpl", "SelectorManager", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.net.http.HttpClientImpl$HttpClientTracker", "jdk.internal.net.http.HttpClientImpl", "HttpClientTracker", $STATIC | $FINAL},
	{"jdk.internal.net.http.HttpClientImpl$SingleFacadeFactory", "jdk.internal.net.http.HttpClientImpl", "SingleFacadeFactory", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.net.http.HttpClientImpl$DelegatingExecutor", "jdk.internal.net.http.HttpClientImpl", "DelegatingExecutor", $STATIC | $FINAL},
	{"jdk.internal.net.http.HttpClientImpl$DefaultThreadFactory", "jdk.internal.net.http.HttpClientImpl", "DefaultThreadFactory", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _HttpClientImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.HttpClientImpl",
	"java.net.http.HttpClient",
	"jdk.internal.net.http.common.OperationTrackers$Trackable",
	_HttpClientImpl_FieldInfo_,
	_HttpClientImpl_MethodInfo_,
	nullptr,
	nullptr,
	_HttpClientImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HttpClientImpl$SSLDirectBufferSupplier,jdk.internal.net.http.HttpClientImpl$SelectorAttachment,jdk.internal.net.http.HttpClientImpl$SelectorManager,jdk.internal.net.http.HttpClientImpl$HttpClientTracker,jdk.internal.net.http.HttpClientImpl$SingleFacadeFactory,jdk.internal.net.http.HttpClientImpl$DelegatingExecutor,jdk.internal.net.http.HttpClientImpl$DefaultThreadFactory"
};

$Object* allocate$HttpClientImpl($Class* clazz) {
	return $of($alloc(HttpClientImpl));
}

int32_t HttpClientImpl::hashCode() {
	 return this->$HttpClient::hashCode();
}

bool HttpClientImpl::equals(Object$* arg0) {
	 return this->$HttpClient::equals(arg0);
}

$Object* HttpClientImpl::clone() {
	 return this->$HttpClient::clone();
}

void HttpClientImpl::finalize() {
	this->$HttpClient::finalize();
}

bool HttpClientImpl::$assertionsDisabled = false;
bool HttpClientImpl::DEBUGELAPSED = false;
$AtomicLong* HttpClientImpl::CLIENT_IDS = nullptr;
$Executor* HttpClientImpl::ASYNC_POOL = nullptr;

$HttpClientFacade* HttpClientImpl::create($HttpClientBuilderImpl* builder) {
	$init(HttpClientImpl);
	$useLocalCurrentObjectStackCache();
	$var($HttpClientImpl$SingleFacadeFactory, facadeFactory, $new($HttpClientImpl$SingleFacadeFactory));
	$var(HttpClientImpl, impl, $new(HttpClientImpl, builder, facadeFactory));
	impl->start();
	if (!HttpClientImpl::$assertionsDisabled && !(facadeFactory->facade != nullptr)) {
		$throwNew($AssertionError);
	}
	if (!HttpClientImpl::$assertionsDisabled && !$equals($nc(impl->facadeRef)->get(), facadeFactory->facade)) {
		$throwNew($AssertionError);
	}
	return facadeFactory->facade;
}

void HttpClientImpl::init$($HttpClientBuilderImpl* builder, $HttpClientImpl$SingleFacadeFactory* facadeFactory) {
	$useLocalCurrentObjectStackCache();
	$HttpClient::init$();
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(HttpClientImpl$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, debugelapsed, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(HttpClientImpl$$Lambda$dbgString, this)), HttpClientImpl::DEBUGELAPSED));
	$set(this, debugtimeout, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(HttpClientImpl$$Lambda$dbgString, this)), HttpClientImpl::DEBUGTIMEOUT));
	$set(this, sslBufferSupplier, $new($HttpClientImpl$SSLDirectBufferSupplier, this));
	$set(this, pendingOperationCount, $new($AtomicLong));
	$set(this, pendingWebSocketCount, $new($AtomicLong));
	$set(this, pendingHttpRequestCount, $new($AtomicLong));
	$set(this, pendingHttp2StreamCount, $new($AtomicLong));
	this->id = $nc(HttpClientImpl::CLIENT_IDS)->incrementAndGet();
	$set(this, dbgTag, $str({"HttpClientImpl("_s, $$str(this->id), ")"_s}));
	if ($nc(builder)->sslContext$ == nullptr) {
		try {
			$set(this, sslContext$, $SSLContext::getDefault());
		} catch ($NoSuchAlgorithmException& ex) {
			$throwNew($UncheckedIOException, $$new($IOException, static_cast<$Throwable*>(ex)));
		}
	} else {
		$set(this, sslContext$, builder->sslContext$);
	}
	$var($Executor, ex, $nc(builder)->executor$);
	if (ex == nullptr) {
		$assign(ex, $Executors::newCachedThreadPool($$new($HttpClientImpl$DefaultThreadFactory, this->id)));
		this->isDefaultExecutor = true;
	} else {
		this->isDefaultExecutor = false;
	}
	$set(this, delegatingExecutor, $new($HttpClientImpl$DelegatingExecutor, static_cast<$BooleanSupplier*>($$new(HttpClientImpl$$Lambda$isSelectorThread$1, this)), ex));
	$set(this, facadeRef, $new($WeakReference, $($nc(facadeFactory)->createFacade(this))));
	$set(this, client2$, $new($Http2ClientImpl, this));
	$set(this, cookieHandler$, builder->cookieHandler$);
	$set(this, connectTimeout$, builder->connectTimeout$);
	$init($HttpClient$Redirect);
	$set(this, followRedirects$, builder->followRedirects$ == nullptr ? $HttpClient$Redirect::NEVER : builder->followRedirects$);
	$set(this, userProxySelector, builder->proxy$);
	$set(this, proxySelector$, $cast($ProxySelector, $nc($($Optional::ofNullable(this->userProxySelector)))->orElseGet(static_cast<$Supplier*>($$new(HttpClientImpl$$Lambda$getDefaultProxySelector$2)))));
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("proxySelector is %s (user-supplied=%s)"_s, $$new($ObjectArray, {
			$of(this->proxySelector$),
			$($of($Boolean::valueOf(this->userProxySelector != nullptr)))
		}));
	}
	$set(this, authenticator$, builder->authenticator$);
	if (builder->version$ == nullptr) {
		$init($HttpClient$Version);
		$set(this, version$, $HttpClient$Version::HTTP_2);
	} else {
		$set(this, version$, builder->version$);
	}
	if (builder->sslParams == nullptr) {
		$set(this, sslParams, getDefaultParams(this->sslContext$));
	} else {
		$set(this, sslParams, builder->sslParams);
	}
	$set(this, connections, $new($ConnectionPool, this->id));
	$nc(this->connections)->start();
	$set(this, timeouts, $new($TreeSet));
	try {
		$set(this, selmgr, $new($HttpClientImpl$SelectorManager, this));
	} catch ($IOException& e) {
		$throwNew($UncheckedIOException, e);
	}
	$nc(this->selmgr)->setDaemon(true);
	$set(this, filters, $new($FilterFactory));
	initFilters();
	if (!HttpClientImpl::$assertionsDisabled && !($nc(this->facadeRef)->get() != nullptr)) {
		$throwNew($AssertionError);
	}
}

void HttpClientImpl::start() {
	$nc(this->selmgr)->start();
}

void HttpClientImpl::stop() {
	$nc(this->connections)->stop();
	$nc(this->client2$)->stop();
	if (this->isDefaultExecutor) {
		$nc(this->delegatingExecutor)->shutdown();
	}
}

$SSLParameters* HttpClientImpl::getDefaultParams($SSLContext* ctx) {
	$init(HttpClientImpl);
	$var($SSLParameters, params, $nc(ctx)->getDefaultSSLParameters());
	return params;
}

$ProxySelector* HttpClientImpl::getDefaultProxySelector() {
	$init(HttpClientImpl);
	$beforeCallerSensitive();
	$var($PrivilegedAction, action, static_cast<$PrivilegedAction*>($new(HttpClientImpl$$Lambda$getDefault$3)));
	return $cast($ProxySelector, $AccessController::doPrivileged(action));
}

$HttpClientFacade* HttpClientImpl::facade() {
	return $cast($HttpClientFacade, $nc(this->facadeRef)->get());
}

int64_t HttpClientImpl::reference() {
	$nc(this->pendingHttpRequestCount)->incrementAndGet();
	return $nc(this->pendingOperationCount)->incrementAndGet();
}

int64_t HttpClientImpl::unreference() {
	int64_t count = $nc(this->pendingOperationCount)->decrementAndGet();
	int64_t httpCount = $nc(this->pendingHttpRequestCount)->decrementAndGet();
	int64_t http2Count = $nc(this->pendingHttp2StreamCount)->get();
	int64_t webSocketCount = $nc(this->pendingWebSocketCount)->get();
	if (count == 0 && facade() == nullptr) {
		$nc(this->selmgr)->wakeupSelector();
	}
	if (!HttpClientImpl::$assertionsDisabled && !(httpCount >= 0)) {
		$throwNew($AssertionError, $of("count of HTTP/1.1 operations < 0"_s));
	}
	if (!HttpClientImpl::$assertionsDisabled && !(http2Count >= 0)) {
		$throwNew($AssertionError, $of("count of HTTP/2 operations < 0"_s));
	}
	if (!HttpClientImpl::$assertionsDisabled && !(webSocketCount >= 0)) {
		$throwNew($AssertionError, $of("count of WS operations < 0"_s));
	}
	if (!HttpClientImpl::$assertionsDisabled && !(count >= 0)) {
		$throwNew($AssertionError, $of("count of pending operations < 0"_s));
	}
	return count;
}

int64_t HttpClientImpl::streamReference() {
	$nc(this->pendingHttp2StreamCount)->incrementAndGet();
	return $nc(this->pendingOperationCount)->incrementAndGet();
}

int64_t HttpClientImpl::streamUnreference() {
	int64_t count = $nc(this->pendingOperationCount)->decrementAndGet();
	int64_t http2Count = $nc(this->pendingHttp2StreamCount)->decrementAndGet();
	int64_t httpCount = $nc(this->pendingHttpRequestCount)->get();
	int64_t webSocketCount = $nc(this->pendingWebSocketCount)->get();
	if (count == 0 && facade() == nullptr) {
		$nc(this->selmgr)->wakeupSelector();
	}
	if (!HttpClientImpl::$assertionsDisabled && !(httpCount >= 0)) {
		$throwNew($AssertionError, $of("count of HTTP/1.1 operations < 0"_s));
	}
	if (!HttpClientImpl::$assertionsDisabled && !(http2Count >= 0)) {
		$throwNew($AssertionError, $of("count of HTTP/2 operations < 0"_s));
	}
	if (!HttpClientImpl::$assertionsDisabled && !(webSocketCount >= 0)) {
		$throwNew($AssertionError, $of("count of WS operations < 0"_s));
	}
	if (!HttpClientImpl::$assertionsDisabled && !(count >= 0)) {
		$throwNew($AssertionError, $of("count of pending operations < 0"_s));
	}
	return count;
}

int64_t HttpClientImpl::webSocketOpen() {
	$nc(this->pendingWebSocketCount)->incrementAndGet();
	return $nc(this->pendingOperationCount)->incrementAndGet();
}

int64_t HttpClientImpl::webSocketClose() {
	int64_t count = $nc(this->pendingOperationCount)->decrementAndGet();
	int64_t webSocketCount = $nc(this->pendingWebSocketCount)->decrementAndGet();
	int64_t httpCount = $nc(this->pendingHttpRequestCount)->get();
	int64_t http2Count = $nc(this->pendingHttp2StreamCount)->get();
	if (count == 0 && facade() == nullptr) {
		$nc(this->selmgr)->wakeupSelector();
	}
	if (!HttpClientImpl::$assertionsDisabled && !(httpCount >= 0)) {
		$throwNew($AssertionError, $of("count of HTTP/1.1 operations < 0"_s));
	}
	if (!HttpClientImpl::$assertionsDisabled && !(http2Count >= 0)) {
		$throwNew($AssertionError, $of("count of HTTP/2 operations < 0"_s));
	}
	if (!HttpClientImpl::$assertionsDisabled && !(webSocketCount >= 0)) {
		$throwNew($AssertionError, $of("count of WS operations < 0"_s));
	}
	if (!HttpClientImpl::$assertionsDisabled && !(count >= 0)) {
		$throwNew($AssertionError, $of("count of pending operations < 0"_s));
	}
	return count;
}

int64_t HttpClientImpl::referenceCount() {
	return $nc(this->pendingOperationCount)->get();
}

$OperationTrackers$Tracker* HttpClientImpl::getOperationsTracker() {
	return $new($HttpClientImpl$HttpClientTracker, this->pendingHttpRequestCount, this->pendingHttp2StreamCount, this->pendingWebSocketCount, this->pendingOperationCount, this->facadeRef, this->dbgTag);
}

bool HttpClientImpl::isReferenced() {
	$var($HttpClient, facade, this->facade());
	return facade != nullptr || referenceCount() > 0;
}

void HttpClientImpl::registerEvent($AsyncEvent* exchange) {
	$nc(this->selmgr)->register$(exchange);
}

void HttpClientImpl::eventUpdated($AsyncEvent* event) {
	if (!HttpClientImpl::$assertionsDisabled && ! !($instanceOf($AsyncTriggerEvent, event))) {
		$throwNew($AssertionError);
	}
	$nc(this->selmgr)->eventUpdated(event);
}

bool HttpClientImpl::isSelectorThread() {
	return $equals($Thread::currentThread(), this->selmgr);
}

$Http2ClientImpl* HttpClientImpl::client2() {
	return this->client2$;
}

void HttpClientImpl::debugCompleted($String* tag, int64_t startNanos, $HttpRequest* req) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debugelapsed)->on()) {
		$var($String, var$2, $$str({tag, " elapsed "_s, $$str($div(($System::nanoTime() - startNanos), (int64_t)1000000)), " millis for "_s}));
		$var($String, var$1, $$concat(var$2, $($nc(req)->method())));
		$var($String, var$0, $$concat(var$1, " to "));
		$nc(this->debugelapsed)->log($$concat(var$0, $(req->uri())));
	}
}

$HttpResponse* HttpClientImpl::send($HttpRequest* req, $HttpResponse$BodyHandler* responseHandler) {
	$useLocalCurrentObjectStackCache();
	$var($CompletableFuture, cf, nullptr);
	if ($Thread::interrupted()) {
		$throwNew($InterruptedException);
	}
	try {
		$assign(cf, sendAsync(req, responseHandler, nullptr, nullptr));
		return $cast($HttpResponse, $nc(cf)->get());
	} catch ($InterruptedException& ie) {
		if (cf != nullptr) {
			cf->cancel(true);
		}
		$throw(ie);
	} catch ($ExecutionException& e) {
		$var($Throwable, throwable, e->getCause());
		$var($String, msg, $nc(throwable)->getMessage());
		if ($instanceOf($IllegalArgumentException, throwable)) {
			$throwNew($IllegalArgumentException, msg, throwable);
		} else if ($instanceOf($SecurityException, throwable)) {
			$throwNew($SecurityException, msg, throwable);
		} else if ($instanceOf($HttpConnectTimeoutException, throwable)) {
			$var($HttpConnectTimeoutException, hcte, $new($HttpConnectTimeoutException, msg));
			hcte->initCause(throwable);
			$throw(hcte);
		} else if ($instanceOf($HttpTimeoutException, throwable)) {
			$throwNew($HttpTimeoutException, msg);
		} else if ($instanceOf($ConnectException, throwable)) {
			$var($ConnectException, ce, $new($ConnectException, msg));
			ce->initCause(throwable);
			$throw(ce);
		} else if ($instanceOf($SSLHandshakeException, throwable)) {
			$var($SSLHandshakeException, he, $new($SSLHandshakeException, msg));
			he->initCause(throwable);
			$throw(he);
		} else if ($instanceOf($SSLException, throwable)) {
			$throwNew($SSLException, msg, throwable);
		} else if ($instanceOf($IOException, throwable)) {
			$throwNew($IOException, msg, throwable);
		} else {
			$throwNew($IOException, msg, throwable);
		}
	}
	$shouldNotReachHere();
}

$CompletableFuture* HttpClientImpl::sendAsync($HttpRequest* userRequest, $HttpResponse$BodyHandler* responseHandler) {
	return sendAsync(userRequest, responseHandler, nullptr);
}

$CompletableFuture* HttpClientImpl::sendAsync($HttpRequest* userRequest, $HttpResponse$BodyHandler* responseHandler, $HttpResponse$PushPromiseHandler* pushPromiseHandler) {
	return sendAsync(userRequest, responseHandler, pushPromiseHandler, $nc(this->delegatingExecutor)->delegate$);
}

$CompletableFuture* HttpClientImpl::sendAsync($HttpRequest* userRequest, $HttpResponse$BodyHandler* responseHandler, $HttpResponse$PushPromiseHandler* pushPromiseHandler, $Executor* exchangeExecutor) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(userRequest);
	$Objects::requireNonNull(responseHandler);
	$var($AccessControlContext, acc, nullptr);
	if ($System::getSecurityManager() != nullptr) {
		$assign(acc, $AccessController::getContext());
	}
	$var($HttpRequestImpl, requestImpl, $new($HttpRequestImpl, userRequest, this->proxySelector$));
	if ($nc($(requestImpl->method()))->equals("CONNECT"_s)) {
		$throwNew($IllegalArgumentException, "Unsupported method CONNECT"_s);
	}
	int64_t start = HttpClientImpl::DEBUGELAPSED ? $System::nanoTime() : (int64_t)0;
	reference();
	try {
		if ($nc(this->debugelapsed)->on()) {
			$nc(this->debugelapsed)->log("ClientImpl (async) send %s"_s, $$new($ObjectArray, {$of(userRequest)}));
		}
		$var($Executor, executor, exchangeExecutor == nullptr ? static_cast<$Executor*>(this->delegatingExecutor) : exchangeExecutor);
		$var($MultiExchange, mex, $new($MultiExchange, userRequest, requestImpl, this, responseHandler, pushPromiseHandler, acc));
		$var($CompletableFuture, res, $cast($CompletableFuture, $nc($(mex->responseAsync(executor)))->whenComplete(static_cast<$BiConsumer*>($$new(HttpClientImpl$$Lambda$lambda$sendAsync$0$4, this)))));
		if (HttpClientImpl::DEBUGELAPSED) {
			$assign(res, $cast($CompletableFuture, $nc(res)->whenComplete(static_cast<$BiConsumer*>($$new(HttpClientImpl$$Lambda$lambda$sendAsync$1$5, this, start, userRequest)))));
		}
		if (exchangeExecutor != nullptr) {
			$assign(res, $cast($CompletableFuture, $nc(res)->whenCompleteAsync(static_cast<$BiConsumer*>($$new(HttpClientImpl$$Lambda$lambda$sendAsync$2$6)), HttpClientImpl::ASYNC_POOL)));
		}
		return res;
	} catch ($Throwable& t) {
		unreference();
		debugCompleted("ClientImpl (async)"_s, start, userRequest);
		$throw(t);
	}
	$shouldNotReachHere();
}

$String* HttpClientImpl::debugInterestOps($SelectableChannel* channel) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($SelectionKey, key, $nc(channel)->keyFor($nc(this->selmgr)->selector));
		if (key == nullptr) {
			return "channel not registered with selector"_s;
		}
		$var($String, keyInterestOps, $nc(key)->isValid() ? $str({"key.interestOps="_s, $$str($nc(key)->interestOps())}) : "invalid key"_s);
		return $String::format("channel registered with selector, %s, sa.interestOps=%s"_s, $$new($ObjectArray, {
			$of(keyInterestOps),
			$($of($Integer::valueOf($nc(($cast($HttpClientImpl$SelectorAttachment, $(key->attachment()))))->interestOps)))
		}));
	} catch ($Throwable& t) {
		return $String::valueOf($of(t));
	}
	$shouldNotReachHere();
}

$SSLContext* HttpClientImpl::theSSLContext() {
	return this->sslContext$;
}

$SSLContext* HttpClientImpl::sslContext() {
	return this->sslContext$;
}

$SSLParameters* HttpClientImpl::sslParameters() {
	return $Utils::copySSLParameters(this->sslParams);
}

$Optional* HttpClientImpl::authenticator() {
	return $Optional::ofNullable(this->authenticator$);
}

$HttpClientImpl$DelegatingExecutor* HttpClientImpl::theExecutor() {
	return this->delegatingExecutor;
}

$Optional* HttpClientImpl::executor() {
	return this->isDefaultExecutor ? $Optional::empty() : $Optional::of($($nc(this->delegatingExecutor)->delegate()));
}

$ConnectionPool* HttpClientImpl::connectionPool() {
	return this->connections;
}

$HttpClient$Redirect* HttpClientImpl::followRedirects() {
	return this->followRedirects$;
}

$Optional* HttpClientImpl::cookieHandler() {
	return $Optional::ofNullable(this->cookieHandler$);
}

$Optional* HttpClientImpl::connectTimeout() {
	return $Optional::ofNullable(this->connectTimeout$);
}

$Optional* HttpClientImpl::proxy() {
	return $Optional::ofNullable(this->userProxySelector);
}

$ProxySelector* HttpClientImpl::proxySelector() {
	return this->proxySelector$;
}

$WebSocket$Builder* HttpClientImpl::newWebSocketBuilder() {
	return $new($BuilderImpl, $(this->facade()), this->proxySelector$);
}

$HttpClient$Version* HttpClientImpl::version() {
	return this->version$;
}

$String* HttpClientImpl::dbgString() {
	return this->dbgTag;
}

$String* HttpClientImpl::toString() {
	$useLocalCurrentObjectStackCache();
	return $str({$($HttpClient::toString()), ($$str({"("_s, $$str(this->id), ")"_s}))});
}

void HttpClientImpl::initFilters() {
	$load($AuthenticationFilter);
	addFilter($AuthenticationFilter::class$);
	$load($RedirectFilter);
	addFilter($RedirectFilter::class$);
	if (this->cookieHandler$ != nullptr) {
		$load($CookieFilter);
		addFilter($CookieFilter::class$);
	}
}

void HttpClientImpl::addFilter($Class* f) {
	$nc(this->filters)->addFilter(f);
}

$LinkedList* HttpClientImpl::filterChain() {
	return $nc(this->filters)->getFilterChain();
}

void HttpClientImpl::registerTimer($TimeoutEvent* event) {
	$synchronized(this) {
		$Log::logTrace("Registering timer {0}"_s, $$new($ObjectArray, {$of(event)}));
		$nc(this->timeouts)->add(event);
		$nc(this->selmgr)->wakeupSelector();
	}
}

void HttpClientImpl::cancelTimer($TimeoutEvent* event) {
	$synchronized(this) {
		$Log::logTrace("Canceling timer {0}"_s, $$new($ObjectArray, {$of(event)}));
		$nc(this->timeouts)->remove(event);
	}
}

int64_t HttpClientImpl::purgeTimeoutsAndReturnNextDeadline() {
	$useLocalCurrentObjectStackCache();
	int64_t diff = 0;
	$var($List, toHandle, nullptr);
	int32_t remaining = 0;
	$synchronized(this) {
		if ($nc(this->timeouts)->isEmpty()) {
			return 0;
		}
		$var($Instant, now, $Instant::now());
		$var($Iterator, itr, $nc(this->timeouts)->iterator());
		while ($nc(itr)->hasNext()) {
			$var($TimeoutEvent, event, $cast($TimeoutEvent, itr->next()));
			$init($ChronoUnit);
			diff = $nc(now)->until($($nc(event)->deadline()), $ChronoUnit::MILLIS);
			if (diff <= 0) {
				itr->remove();
				$assign(toHandle, (toHandle == nullptr) ? static_cast<$List*>($new($ArrayList)) : toHandle);
				$nc(toHandle)->add(event);
			} else {
				break;
			}
		}
		remaining = $nc(this->timeouts)->size();
	}
	if (toHandle != nullptr && $Log::trace()) {
		$Log::logTrace($$str({"purgeTimeoutsAndReturnNextDeadline: handling "_s, $$str(toHandle->size()), " events, remaining "_s, $$str(remaining), ", next deadline: "_s, $$str((diff < 0 ? (int64_t)0 : diff))}), $$new($ObjectArray, 0));
	}
	if (toHandle != nullptr) {
		$var($Throwable, failed, nullptr);
		{
			$var($Iterator, i$, toHandle->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($TimeoutEvent, event, $cast($TimeoutEvent, i$->next()));
				{
					try {
						$Log::logTrace("Firing timer {0}"_s, $$new($ObjectArray, {$of(event)}));
						$nc(event)->handle();
					} catch ($Error& e) {
						if (failed == nullptr) {
							$assign(failed, e);
						} else {
							$nc(failed)->addSuppressed(e);
						}
						$Log::logTrace("Failed to handle event {0}: {1}"_s, $$new($ObjectArray, {
							$of(event),
							$of(e)
						}));
					} catch ($RuntimeException& e) {
						if (failed == nullptr) {
							$assign(failed, e);
						} else {
							$nc(failed)->addSuppressed(e);
						}
						$Log::logTrace("Failed to handle event {0}: {1}"_s, $$new($ObjectArray, {
							$of(event),
							$of(e)
						}));
					}
				}
			}
		}
		if ($instanceOf($Error, failed)) {
			$throw($cast($Error, failed));
		}
		if ($instanceOf($RuntimeException, failed)) {
			$throw($cast($RuntimeException, failed));
		}
	}
	return diff < 0 ? (int64_t)0 : diff;
}

int32_t HttpClientImpl::getReceiveBufferSize() {
	return $Utils::getIntegerNetProperty("jdk.httpclient.receiveBufferSize"_s, 0);
}

int32_t HttpClientImpl::getSendBufferSize() {
	return $Utils::getIntegerNetProperty("jdk.httpclient.sendBufferSize"_s, 0);
}

$BufferSupplier* HttpClientImpl::getSSLBufferSupplier() {
	return this->sslBufferSupplier;
}

void HttpClientImpl::lambda$sendAsync$2($HttpResponse* r, $Throwable* t) {
	$init(HttpClientImpl);
}

void HttpClientImpl::lambda$sendAsync$1(int64_t start, $HttpRequest* userRequest, $HttpResponse* b, $Throwable* t) {
	debugCompleted("ClientImpl (async)"_s, start, userRequest);
}

void HttpClientImpl::lambda$sendAsync$0($HttpResponse* b, $Throwable* t) {
	unreference();
}

void clinit$HttpClientImpl($Class* class$) {
	HttpClientImpl::$assertionsDisabled = !HttpClientImpl::class$->desiredAssertionStatus();
	$init($Utils);
	HttpClientImpl::DEBUGELAPSED = $Utils::TESTING || $Utils::DEBUG;
	$assignStatic(HttpClientImpl::CLIENT_IDS, $new($AtomicLong));
	$assignStatic(HttpClientImpl::ASYNC_POOL, $$new($CompletableFuture)->defaultExecutor());
}

HttpClientImpl::HttpClientImpl() {
}

$Class* HttpClientImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HttpClientImpl$$Lambda$dbgString::classInfo$.name)) {
			return HttpClientImpl$$Lambda$dbgString::load$(name, initialize);
		}
		if (name->equals(HttpClientImpl$$Lambda$isSelectorThread$1::classInfo$.name)) {
			return HttpClientImpl$$Lambda$isSelectorThread$1::load$(name, initialize);
		}
		if (name->equals(HttpClientImpl$$Lambda$getDefaultProxySelector$2::classInfo$.name)) {
			return HttpClientImpl$$Lambda$getDefaultProxySelector$2::load$(name, initialize);
		}
		if (name->equals(HttpClientImpl$$Lambda$getDefault$3::classInfo$.name)) {
			return HttpClientImpl$$Lambda$getDefault$3::load$(name, initialize);
		}
		if (name->equals(HttpClientImpl$$Lambda$lambda$sendAsync$0$4::classInfo$.name)) {
			return HttpClientImpl$$Lambda$lambda$sendAsync$0$4::load$(name, initialize);
		}
		if (name->equals(HttpClientImpl$$Lambda$lambda$sendAsync$1$5::classInfo$.name)) {
			return HttpClientImpl$$Lambda$lambda$sendAsync$1$5::load$(name, initialize);
		}
		if (name->equals(HttpClientImpl$$Lambda$lambda$sendAsync$2$6::classInfo$.name)) {
			return HttpClientImpl$$Lambda$lambda$sendAsync$2$6::load$(name, initialize);
		}
	}
	$loadClass(HttpClientImpl, name, initialize, &_HttpClientImpl_ClassInfo_, clinit$HttpClientImpl, allocate$HttpClientImpl);
	return class$;
}

$Class* HttpClientImpl::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk