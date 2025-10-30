#include <jdk/internal/net/http/HttpRequestImpl.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/Proxy$Type.h>
#include <java/net/Proxy.h>
#include <java/net/ProxySelector.h>
#include <java/net/SocketAddress.h>
#include <java/net/URI.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpRequest$BodyPublisher.h>
#include <java/net/http/HttpRequest.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/time/Duration.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/function/BiPredicate.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/Http2ClientImpl.h>
#include <jdk/internal/net/http/HttpRequestBuilderImpl.h>
#include <jdk/internal/net/http/common/HttpHeadersBuilder.h>
#include <jdk/internal/net/http/common/Utils$ProxyHeaders.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef ALLOWED_HEADERS
#undef HTTP
#undef HTTP_1_1
#undef US
#undef USER_AGENT
#undef VALIDATE_USER_HEADER
#undef ZERO

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $Proxy = ::java::net::Proxy;
using $Proxy$Type = ::java::net::Proxy$Type;
using $ProxySelector = ::java::net::ProxySelector;
using $SocketAddress = ::java::net::SocketAddress;
using $URI = ::java::net::URI;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Duration = ::java::time::Duration;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $BiPredicate = ::java::util::function::BiPredicate;
using $Supplier = ::java::util::function::Supplier;
using $Http2ClientImpl = ::jdk::internal::net::http::Http2ClientImpl;
using $HttpRequestBuilderImpl = ::jdk::internal::net::http::HttpRequestBuilderImpl;
using $HttpHeadersBuilder = ::jdk::internal::net::http::common::HttpHeadersBuilder;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $Utils$ProxyHeaders = ::jdk::internal::net::http::common::Utils$ProxyHeaders;
using $WebSocketRequest = ::jdk::internal::net::http::websocket::WebSocketRequest;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class HttpRequestImpl$$Lambda$lambda$userAgent$0 : public $PrivilegedAction {
	$class(HttpRequestImpl$$Lambda$lambda$userAgent$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(HttpRequestImpl::lambda$userAgent$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpRequestImpl$$Lambda$lambda$userAgent$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpRequestImpl$$Lambda$lambda$userAgent$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequestImpl$$Lambda$lambda$userAgent$0::*)()>(&HttpRequestImpl$$Lambda$lambda$userAgent$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpRequestImpl$$Lambda$lambda$userAgent$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpRequestImpl$$Lambda$lambda$userAgent$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* HttpRequestImpl$$Lambda$lambda$userAgent$0::load$($String* name, bool initialize) {
	$loadClass(HttpRequestImpl$$Lambda$lambda$userAgent$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpRequestImpl$$Lambda$lambda$userAgent$0::class$ = nullptr;

class HttpRequestImpl$$Lambda$lambda$new$1$1 : public $Supplier {
	$class(HttpRequestImpl$$Lambda$lambda$new$1$1, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(HttpRequestImpl::lambda$new$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpRequestImpl$$Lambda$lambda$new$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpRequestImpl$$Lambda$lambda$new$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequestImpl$$Lambda$lambda$new$1$1::*)()>(&HttpRequestImpl$$Lambda$lambda$new$1$1::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpRequestImpl$$Lambda$lambda$new$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpRequestImpl$$Lambda$lambda$new$1$1",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* HttpRequestImpl$$Lambda$lambda$new$1$1::load$($String* name, bool initialize) {
	$loadClass(HttpRequestImpl$$Lambda$lambda$new$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpRequestImpl$$Lambda$lambda$new$1$1::class$ = nullptr;

class HttpRequestImpl$$Lambda$lambda$new$2$2 : public $Supplier {
	$class(HttpRequestImpl$$Lambda$lambda$new$2$2, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(HttpRequestImpl::lambda$new$2());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpRequestImpl$$Lambda$lambda$new$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpRequestImpl$$Lambda$lambda$new$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequestImpl$$Lambda$lambda$new$2$2::*)()>(&HttpRequestImpl$$Lambda$lambda$new$2$2::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpRequestImpl$$Lambda$lambda$new$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpRequestImpl$$Lambda$lambda$new$2$2",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* HttpRequestImpl$$Lambda$lambda$new$2$2::load$($String* name, bool initialize) {
	$loadClass(HttpRequestImpl$$Lambda$lambda$new$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpRequestImpl$$Lambda$lambda$new$2$2::class$ = nullptr;

class HttpRequestImpl$$Lambda$lambda$new$3$3 : public $Supplier {
	$class(HttpRequestImpl$$Lambda$lambda$new$3$3, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(HttpRequestImpl::lambda$new$3());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpRequestImpl$$Lambda$lambda$new$3$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpRequestImpl$$Lambda$lambda$new$3$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequestImpl$$Lambda$lambda$new$3$3::*)()>(&HttpRequestImpl$$Lambda$lambda$new$3$3::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpRequestImpl$$Lambda$lambda$new$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpRequestImpl$$Lambda$lambda$new$3$3",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* HttpRequestImpl$$Lambda$lambda$new$3$3::load$($String* name, bool initialize) {
	$loadClass(HttpRequestImpl$$Lambda$lambda$new$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpRequestImpl$$Lambda$lambda$new$3$3::class$ = nullptr;

class HttpRequestImpl$$Lambda$lambda$new$4$4 : public $Supplier {
	$class(HttpRequestImpl$$Lambda$lambda$new$4$4, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(HttpRequestImpl::lambda$new$4());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpRequestImpl$$Lambda$lambda$new$4$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpRequestImpl$$Lambda$lambda$new$4$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequestImpl$$Lambda$lambda$new$4$4::*)()>(&HttpRequestImpl$$Lambda$lambda$new$4$4::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpRequestImpl$$Lambda$lambda$new$4$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpRequestImpl$$Lambda$lambda$new$4$4",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* HttpRequestImpl$$Lambda$lambda$new$4$4::load$($String* name, bool initialize) {
	$loadClass(HttpRequestImpl$$Lambda$lambda$new$4$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpRequestImpl$$Lambda$lambda$new$4$4::class$ = nullptr;

class HttpRequestImpl$$Lambda$lambda$getAddress$5$5 : public $PrivilegedAction {
	$class(HttpRequestImpl$$Lambda$lambda$getAddress$5$5, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* host, int32_t port) {
		$set(this, host, host);
		this->port = port;
	}
	virtual $Object* run() override {
		 return $of(HttpRequestImpl::lambda$getAddress$5(host, port));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpRequestImpl$$Lambda$lambda$getAddress$5$5>());
	}
	$String* host = nullptr;
	int32_t port = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpRequestImpl$$Lambda$lambda$getAddress$5$5::fieldInfos[3] = {
	{"host", "Ljava/lang/String;", nullptr, $PUBLIC, $field(HttpRequestImpl$$Lambda$lambda$getAddress$5$5, host)},
	{"port", "I", nullptr, $PUBLIC, $field(HttpRequestImpl$$Lambda$lambda$getAddress$5$5, port)},
	{}
};
$MethodInfo HttpRequestImpl$$Lambda$lambda$getAddress$5$5::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequestImpl$$Lambda$lambda$getAddress$5$5::*)($String*,int32_t)>(&HttpRequestImpl$$Lambda$lambda$getAddress$5$5::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpRequestImpl$$Lambda$lambda$getAddress$5$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpRequestImpl$$Lambda$lambda$getAddress$5$5",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* HttpRequestImpl$$Lambda$lambda$getAddress$5$5::load$($String* name, bool initialize) {
	$loadClass(HttpRequestImpl$$Lambda$lambda$getAddress$5$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpRequestImpl$$Lambda$lambda$getAddress$5$5::class$ = nullptr;

$FieldInfo _HttpRequestImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HttpRequestImpl, $assertionsDisabled)},
	{"userHeaders", "Ljava/net/http/HttpHeaders;", nullptr, $PRIVATE | $FINAL, $field(HttpRequestImpl, userHeaders)},
	{"systemHeadersBuilder", "Ljdk/internal/net/http/common/HttpHeadersBuilder;", nullptr, $PRIVATE | $FINAL, $field(HttpRequestImpl, systemHeadersBuilder)},
	{"uri", "Ljava/net/URI;", nullptr, $PRIVATE | $FINAL, $field(HttpRequestImpl, uri$)},
	{"proxy", "Ljava/net/Proxy;", nullptr, $PRIVATE | $VOLATILE, $field(HttpRequestImpl, proxy$)},
	{"authority", "Ljava/net/InetSocketAddress;", nullptr, $PRIVATE | $FINAL, $field(HttpRequestImpl, authority$)},
	{"method", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(HttpRequestImpl, method$)},
	{"requestPublisher", "Ljava/net/http/HttpRequest$BodyPublisher;", nullptr, $FINAL, $field(HttpRequestImpl, requestPublisher)},
	{"secure", "Z", nullptr, $FINAL, $field(HttpRequestImpl, secure$)},
	{"expectContinue", "Z", nullptr, $FINAL, $field(HttpRequestImpl, expectContinue$)},
	{"isWebSocket", "Z", nullptr, $PRIVATE | $VOLATILE, $field(HttpRequestImpl, isWebSocket$)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $VOLATILE, $field(HttpRequestImpl, acc)},
	{"timeout", "Ljava/time/Duration;", nullptr, $PRIVATE | $FINAL, $field(HttpRequestImpl, timeout$)},
	{"version", "Ljava/util/Optional;", "Ljava/util/Optional<Ljava/net/http/HttpClient$Version;>;", $PRIVATE | $FINAL, $field(HttpRequestImpl, version$)},
	{"USER_AGENT", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(HttpRequestImpl, USER_AGENT)},
	{}
};

$MethodInfo _HttpRequestImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $FINAL},
	{"<init>", "(Ljdk/internal/net/http/HttpRequestBuilderImpl;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequestImpl::*)($HttpRequestBuilderImpl*)>(&HttpRequestImpl::init$))},
	{"<init>", "(Ljava/net/http/HttpRequest;Ljava/net/ProxySelector;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequestImpl::*)($HttpRequest*,$ProxySelector*)>(&HttpRequestImpl::init$))},
	{"<init>", "(Ljava/net/URI;Ljava/lang/String;Ljdk/internal/net/http/HttpRequestImpl;Z)V", nullptr, $PRIVATE, $method(static_cast<void(HttpRequestImpl::*)($URI*,$String*,HttpRequestImpl*,bool)>(&HttpRequestImpl::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/net/InetSocketAddress;Ljdk/internal/net/http/common/Utils$ProxyHeaders;)V", nullptr, 0, $method(static_cast<void(HttpRequestImpl::*)($String*,$InetSocketAddress*,$Utils$ProxyHeaders*)>(&HttpRequestImpl::init$))},
	{"<init>", "(Ljdk/internal/net/http/HttpRequestImpl;Ljava/net/http/HttpHeaders;)V", nullptr, $PRIVATE, $method(static_cast<void(HttpRequestImpl::*)(HttpRequestImpl*,$HttpHeaders*)>(&HttpRequestImpl::init$)), "java.io.IOException"},
	{"addSystemHeader", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, 0},
	{"authority", "()Ljava/net/InetSocketAddress;", nullptr, 0},
	{"bodyPublisher", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/http/HttpRequest$BodyPublisher;>;", $PUBLIC},
	{"checkTimeout", "(Ljava/time/Duration;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($Duration*)>(&HttpRequestImpl::checkTimeout))},
	{"createPushRequest", "(Ljdk/internal/net/http/HttpRequestImpl;Ljava/net/http/HttpHeaders;)Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $STATIC, $method(static_cast<HttpRequestImpl*(*)(HttpRequestImpl*,$HttpHeaders*)>(&HttpRequestImpl::createPushRequest)), "java.io.IOException"},
	{"expectContinue", "()Z", nullptr, $PUBLIC},
	{"getAddress", "()Ljava/net/InetSocketAddress;", nullptr, 0},
	{"getSystemHeadersBuilder", "()Ljdk/internal/net/http/common/HttpHeadersBuilder;", nullptr, 0},
	{"getUserHeaders", "()Ljava/net/http/HttpHeaders;", nullptr, 0},
	{"headers", "()Ljava/net/http/HttpHeaders;", nullptr, $PUBLIC},
	{"isConnect", "()Z", nullptr, $FINAL, $method(static_cast<bool(HttpRequestImpl::*)()>(&HttpRequestImpl::isConnect))},
	{"isWebSocket", "(Z)V", nullptr, $PUBLIC},
	{"isWebSocket", "()Z", nullptr, 0},
	{"lambda$getAddress$5", "(Ljava/lang/String;I)Ljava/net/InetSocketAddress;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$InetSocketAddress*(*)($String*,int32_t)>(&HttpRequestImpl::lambda$getAddress$5))},
	{"lambda$new$1", "()Ljava/io/IOException;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$IOException*(*)()>(&HttpRequestImpl::lambda$new$1))},
	{"lambda$new$2", "()Ljava/io/IOException;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$IOException*(*)()>(&HttpRequestImpl::lambda$new$2))},
	{"lambda$new$3", "()Ljava/io/IOException;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$IOException*(*)()>(&HttpRequestImpl::lambda$new$3))},
	{"lambda$new$4", "()Ljava/io/IOException;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$IOException*(*)()>(&HttpRequestImpl::lambda$new$4))},
	{"lambda$userAgent$0", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)()>(&HttpRequestImpl::lambda$userAgent$0))},
	{"method", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"newInstanceForAuthentication", "(Ljdk/internal/net/http/HttpRequestImpl;)Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PUBLIC | $STATIC, $method(static_cast<HttpRequestImpl*(*)(HttpRequestImpl*)>(&HttpRequestImpl::newInstanceForAuthentication))},
	{"newInstanceForRedirection", "(Ljava/net/URI;Ljava/lang/String;Ljdk/internal/net/http/HttpRequestImpl;Z)Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PUBLIC | $STATIC, $method(static_cast<HttpRequestImpl*(*)($URI*,$String*,HttpRequestImpl*,bool)>(&HttpRequestImpl::newInstanceForRedirection))},
	{"proxy", "()Ljava/net/InetSocketAddress;", nullptr, 0},
	{"publisher", "(Ljdk/internal/net/http/HttpRequestImpl;)Ljava/net/http/HttpRequest$BodyPublisher;", nullptr, $PRIVATE, $method(static_cast<$HttpRequest$BodyPublisher*(HttpRequestImpl::*)(HttpRequestImpl*)>(&HttpRequestImpl::publisher))},
	{"retrieveProxy", "(Ljava/net/ProxySelector;Ljava/net/URI;)Ljava/net/Proxy;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Proxy*(*)($ProxySelector*,$URI*)>(&HttpRequestImpl::retrieveProxy))},
	{"secure", "()Z", nullptr, 0},
	{"setH2Upgrade", "(Ljdk/internal/net/http/Http2ClientImpl;)V", nullptr, 0},
	{"setProxy", "(Ljava/net/Proxy;)V", nullptr, $PUBLIC},
	{"setSystemHeader", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"timeout", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/time/Duration;>;", $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"uri", "()Ljava/net/URI;", nullptr, $PUBLIC},
	{"userAgent", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)()>(&HttpRequestImpl::userAgent))},
	{"version", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/http/HttpClient$Version;>;", $PUBLIC},
	{}
};

$ClassInfo _HttpRequestImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.HttpRequestImpl",
	"java.net.http.HttpRequest",
	"jdk.internal.net.http.websocket.WebSocketRequest",
	_HttpRequestImpl_FieldInfo_,
	_HttpRequestImpl_MethodInfo_
};

$Object* allocate$HttpRequestImpl($Class* clazz) {
	return $of($alloc(HttpRequestImpl));
}

bool HttpRequestImpl::equals(Object$* obj) {
	 return this->$HttpRequest::equals(obj);
}

int32_t HttpRequestImpl::hashCode() {
	 return this->$HttpRequest::hashCode();
}

$Object* HttpRequestImpl::clone() {
	 return this->$HttpRequest::clone();
}

void HttpRequestImpl::finalize() {
	this->$HttpRequest::finalize();
}

bool HttpRequestImpl::$assertionsDisabled = false;
$String* HttpRequestImpl::USER_AGENT = nullptr;

$String* HttpRequestImpl::userAgent() {
	$init(HttpRequestImpl);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(HttpRequestImpl$$Lambda$lambda$userAgent$0)));
	$var($String, version, $cast($String, $AccessController::doPrivileged(pa)));
	return $str({"Java-http-client/"_s, version});
}

void HttpRequestImpl::init$($HttpRequestBuilderImpl* builder) {
	$useLocalCurrentObjectStackCache();
	$HttpRequest::init$();
	$var($String, method, $nc(builder)->method());
	$set(this, method$, method == nullptr ? "GET"_s : method);
	$init($Utils);
	$set(this, userHeaders, $HttpHeaders::of($($nc($(builder->headersBuilder()))->map()), $Utils::ALLOWED_HEADERS));
	$set(this, systemHeadersBuilder, $new($HttpHeadersBuilder));
	$set(this, uri$, builder->uri());
	if (!HttpRequestImpl::$assertionsDisabled && !(this->uri$ != nullptr)) {
		$throwNew($AssertionError);
	}
	$set(this, proxy$, nullptr);
	this->expectContinue$ = builder->expectContinue();
	$init($Locale);
	this->secure$ = $($nc($($nc(this->uri$)->getScheme()))->toLowerCase($Locale::US))->equals("https"_s);
	$set(this, requestPublisher, builder->bodyPublisher());
	$set(this, timeout$, builder->timeout());
	$set(this, version$, builder->version());
	$set(this, authority$, nullptr);
}

void HttpRequestImpl::init$($HttpRequest* request, $ProxySelector* ps) {
	$useLocalCurrentObjectStackCache();
	$HttpRequest::init$();
	$var($String, method, $nc(request)->method());
	if (method != nullptr && !$Utils::isValidName(method)) {
		$throwNew($IllegalArgumentException, $$str({"illegal method \""_s, $($($(method->replace(static_cast<$CharSequence*>("\n"_s), static_cast<$CharSequence*>("\\n"_s)))->replace(static_cast<$CharSequence*>("\r"_s), static_cast<$CharSequence*>("\\r"_s)))->replace(static_cast<$CharSequence*>("\t"_s), static_cast<$CharSequence*>("\\t"_s))), "\""_s}));
	}
	$var($URI, requestURI, $cast($URI, $Objects::requireNonNull($($of(request->uri())), "uri must be non null"_s)));
	$var($Duration, timeout, $cast($Duration, $nc($(request->timeout()))->orElse(nullptr)));
	$set(this, method$, method == nullptr ? "GET"_s : method);
	$set(this, userHeaders, $HttpHeaders::of($($nc($(request->headers()))->map()), $Utils::VALIDATE_USER_HEADER));
	if ($instanceOf(HttpRequestImpl, request)) {
		this->isWebSocket$ = $nc(($cast(HttpRequestImpl, request)))->isWebSocket$;
		if (this->isWebSocket$) {
			$set(this, systemHeadersBuilder, ($cast(HttpRequestImpl, request))->systemHeadersBuilder);
		} else {
			$set(this, systemHeadersBuilder, $new($HttpHeadersBuilder));
		}
	} else {
		$HttpRequestBuilderImpl::checkURI(requestURI);
		checkTimeout(timeout);
		$set(this, systemHeadersBuilder, $new($HttpHeadersBuilder));
	}
	if (!$nc($($nc(this->userHeaders)->firstValue("User-Agent"_s)))->isPresent()) {
		$nc(this->systemHeadersBuilder)->setHeader("User-Agent"_s, HttpRequestImpl::USER_AGENT);
	}
	$set(this, uri$, requestURI);
	if (this->isWebSocket$) {
		$set(this, proxy$, $nc(($cast(HttpRequestImpl, request)))->proxy$);
	} else if (ps != nullptr) {
		$set(this, proxy$, retrieveProxy(ps, this->uri$));
	} else {
		$set(this, proxy$, nullptr);
	}
	this->expectContinue$ = request->expectContinue();
	$init($Locale);
	this->secure$ = $($nc($($nc(this->uri$)->getScheme()))->toLowerCase($Locale::US))->equals("https"_s);
	$set(this, requestPublisher, $cast($HttpRequest$BodyPublisher, $nc($(request->bodyPublisher()))->orElse(nullptr)));
	$set(this, timeout$, timeout);
	$set(this, version$, request->version());
	$set(this, authority$, nullptr);
}

void HttpRequestImpl::checkTimeout($Duration* duration) {
	$init(HttpRequestImpl);
	if (duration != nullptr) {
		bool var$0 = duration->isNegative();
		if (var$0 || $nc($Duration::ZERO)->equals(duration)) {
			$throwNew($IllegalArgumentException, $$str({"Invalid duration: "_s, duration}));
		}
	}
}

HttpRequestImpl* HttpRequestImpl::newInstanceForRedirection($URI* uri, $String* method, HttpRequestImpl* other, bool mayHaveBody) {
	$init(HttpRequestImpl);
	return $new(HttpRequestImpl, uri, method, other, mayHaveBody);
}

HttpRequestImpl* HttpRequestImpl::newInstanceForAuthentication(HttpRequestImpl* other) {
	$init(HttpRequestImpl);
	$useLocalCurrentObjectStackCache();
	$var($URI, var$0, $nc(other)->uri());
	$var(HttpRequestImpl, request, $new(HttpRequestImpl, var$0, $(other->method()), other, true));
	if (request->isWebSocket()) {
		$Utils::setWebSocketUpgradeHeaders(request);
	}
	return request;
}

void HttpRequestImpl::init$($URI* uri, $String* method, HttpRequestImpl* other, bool mayHaveBody) {
	$useLocalCurrentObjectStackCache();
	$HttpRequest::init$();
	if (!HttpRequestImpl::$assertionsDisabled && !(method == nullptr || $Utils::isValidName(method))) {
		$throwNew($AssertionError);
	}
	$set(this, method$, method == nullptr ? "GET"_s : method);
	$set(this, userHeaders, $nc(other)->userHeaders);
	this->isWebSocket$ = other->isWebSocket$;
	$set(this, systemHeadersBuilder, $new($HttpHeadersBuilder));
	if (!$nc($($nc(this->userHeaders)->firstValue("User-Agent"_s)))->isPresent()) {
		$nc(this->systemHeadersBuilder)->setHeader("User-Agent"_s, HttpRequestImpl::USER_AGENT);
	}
	$set(this, uri$, uri);
	$set(this, proxy$, other->proxy$);
	this->expectContinue$ = other->expectContinue$;
	$init($Locale);
	this->secure$ = $($nc($($nc(uri)->getScheme()))->toLowerCase($Locale::US))->equals("https"_s);
	$set(this, requestPublisher, mayHaveBody ? publisher(other) : ($HttpRequest$BodyPublisher*)nullptr);
	$set(this, acc, other->acc);
	$set(this, timeout$, other->timeout$);
	$set(this, version$, other->version());
	$set(this, authority$, nullptr);
}

$HttpRequest$BodyPublisher* HttpRequestImpl::publisher(HttpRequestImpl* other) {
	$var($HttpRequest$BodyPublisher, res, $nc(other)->requestPublisher);
	if (!$Objects::equals(this->method$, other->method$)) {
		$assign(res, nullptr);
	}
	return res;
}

void HttpRequestImpl::init$($String* method, $InetSocketAddress* authority, $Utils$ProxyHeaders* headers) {
	$useLocalCurrentObjectStackCache();
	$HttpRequest::init$();
	if (!HttpRequestImpl::$assertionsDisabled && !"CONNECT"_s->equalsIgnoreCase(method)) {
		$throwNew($AssertionError);
	}
	$set(this, method$, method);
	$set(this, systemHeadersBuilder, $new($HttpHeadersBuilder));
	$nc($($nc(this->systemHeadersBuilder)->map()))->putAll($($nc($($nc(headers)->systemHeaders()))->map()));
	$set(this, userHeaders, $nc(headers)->userHeaders());
	$var($String, var$1, $$str({"socket://"_s, $($nc(authority)->getHostString()), ":"_s}));
	$var($String, var$0, $$concat(var$1, $($Integer::toString(authority->getPort()))));
	$set(this, uri$, $URI::create($$concat(var$0, "/")));
	$set(this, proxy$, nullptr);
	$set(this, requestPublisher, nullptr);
	$set(this, authority$, authority);
	this->secure$ = false;
	this->expectContinue$ = false;
	$set(this, timeout$, nullptr);
	$init($HttpClient$Version);
	$set(this, version$, $Optional::of($HttpClient$Version::HTTP_1_1));
}

bool HttpRequestImpl::isConnect() {
	return "CONNECT"_s->equalsIgnoreCase(this->method$);
}

HttpRequestImpl* HttpRequestImpl::createPushRequest(HttpRequestImpl* parent, $HttpHeaders* headers) {
	$init(HttpRequestImpl);
	return $new(HttpRequestImpl, parent, headers);
}

void HttpRequestImpl::init$(HttpRequestImpl* parent, $HttpHeaders* headers) {
	$useLocalCurrentObjectStackCache();
	$HttpRequest::init$();
	$set(this, method$, $cast($String, $nc($($nc(headers)->firstValue(":method"_s)))->orElseThrow(static_cast<$Supplier*>($$new(HttpRequestImpl$$Lambda$lambda$new$1$1)))));
	$var($String, path, $cast($String, $nc($(headers->firstValue(":path"_s)))->orElseThrow(static_cast<$Supplier*>($$new(HttpRequestImpl$$Lambda$lambda$new$2$2)))));
	$var($String, scheme, $cast($String, $nc($(headers->firstValue(":scheme"_s)))->orElseThrow(static_cast<$Supplier*>($$new(HttpRequestImpl$$Lambda$lambda$new$3$3)))));
	$var($String, authority, $cast($String, $nc($(headers->firstValue(":authority"_s)))->orElseThrow(static_cast<$Supplier*>($$new(HttpRequestImpl$$Lambda$lambda$new$4$4)))));
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append(scheme)->append("://"_s)->append(authority)->append(path);
	$set(this, uri$, $URI::create($(sb->toString())));
	$set(this, proxy$, nullptr);
	$init($Utils);
	$set(this, userHeaders, $HttpHeaders::of($(headers->map()), $Utils::ALLOWED_HEADERS));
	$set(this, systemHeadersBuilder, $nc(parent)->systemHeadersBuilder);
	this->expectContinue$ = parent->expectContinue$;
	this->secure$ = parent->secure$;
	$set(this, requestPublisher, parent->requestPublisher);
	$set(this, acc, parent->acc);
	$set(this, timeout$, parent->timeout$);
	$set(this, version$, parent->version$);
	$set(this, authority$, nullptr);
}

$String* HttpRequestImpl::toString() {
	return $str({(this->uri$ == nullptr ? ""_s : $($nc(this->uri$)->toString())), " "_s, this->method$});
}

$HttpHeaders* HttpRequestImpl::headers() {
	return this->userHeaders;
}

$InetSocketAddress* HttpRequestImpl::authority() {
	return this->authority$;
}

void HttpRequestImpl::setH2Upgrade($Http2ClientImpl* h2client) {
	$nc(this->systemHeadersBuilder)->setHeader("Connection"_s, "Upgrade, HTTP2-Settings"_s);
	$nc(this->systemHeadersBuilder)->setHeader("Upgrade"_s, "h2c"_s);
	$nc(this->systemHeadersBuilder)->setHeader("HTTP2-Settings"_s, $($nc(h2client)->getSettingsString()));
}

bool HttpRequestImpl::expectContinue() {
	return this->expectContinue$;
}

$Proxy* HttpRequestImpl::retrieveProxy($ProxySelector* ps, $URI* uri) {
	$init(HttpRequestImpl);
	$useLocalCurrentObjectStackCache();
	$var($Proxy, proxy, nullptr);
	$var($List, pl, $nc(ps)->select(uri));
	if (!$nc(pl)->isEmpty()) {
		$var($Proxy, p, $cast($Proxy, pl->get(0)));
		$init($Proxy$Type);
		if ($nc(p)->type() == $Proxy$Type::HTTP) {
			$assign(proxy, p);
		}
	}
	return proxy;
}

$InetSocketAddress* HttpRequestImpl::proxy() {
	$init($Proxy$Type);
	bool var$0 = this->proxy$ == nullptr || $nc(this->proxy$)->type() != $Proxy$Type::HTTP;
	if (var$0 || $nc(this->method$)->equalsIgnoreCase("CONNECT"_s)) {
		return nullptr;
	}
	return $cast($InetSocketAddress, $nc(this->proxy$)->address());
}

bool HttpRequestImpl::secure() {
	return this->secure$;
}

void HttpRequestImpl::setProxy($Proxy* proxy) {
	if (!HttpRequestImpl::$assertionsDisabled && !this->isWebSocket$) {
		$throwNew($AssertionError);
	}
	$set(this, proxy$, proxy);
}

void HttpRequestImpl::isWebSocket(bool is) {
	this->isWebSocket$ = is;
}

bool HttpRequestImpl::isWebSocket() {
	return this->isWebSocket$;
}

$Optional* HttpRequestImpl::bodyPublisher() {
	return this->requestPublisher == nullptr ? $Optional::empty() : $Optional::of(this->requestPublisher);
}

$String* HttpRequestImpl::method() {
	return this->method$;
}

$URI* HttpRequestImpl::uri() {
	return this->uri$;
}

$Optional* HttpRequestImpl::timeout() {
	return this->timeout$ == nullptr ? $Optional::empty() : $Optional::of(this->timeout$);
}

$HttpHeaders* HttpRequestImpl::getUserHeaders() {
	return this->userHeaders;
}

$HttpHeadersBuilder* HttpRequestImpl::getSystemHeadersBuilder() {
	return this->systemHeadersBuilder;
}

$Optional* HttpRequestImpl::version() {
	return this->version$;
}

void HttpRequestImpl::addSystemHeader($String* name, $String* value) {
	$nc(this->systemHeadersBuilder)->addHeader(name, value);
}

void HttpRequestImpl::setSystemHeader($String* name, $String* value) {
	$nc(this->systemHeadersBuilder)->setHeader(name, value);
}

$InetSocketAddress* HttpRequestImpl::getAddress() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($URI, uri, this->uri());
	if (uri == nullptr) {
		return authority();
	}
	int32_t p = $nc(uri)->getPort();
	if (p == -1) {
		if ($nc($(uri->getScheme()))->equalsIgnoreCase("https"_s)) {
			p = 443;
		} else {
			p = 80;
		}
	}
	$var($String, host, uri->getHost());
	int32_t port = p;
	if (proxy() == nullptr) {
		$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(HttpRequestImpl$$Lambda$lambda$getAddress$5$5, host, port)));
		return $cast($InetSocketAddress, $AccessController::doPrivileged(pa));
	} else {
		return $InetSocketAddress::createUnresolved(host, port);
	}
}

$InetSocketAddress* HttpRequestImpl::lambda$getAddress$5($String* host, int32_t port) {
	$init(HttpRequestImpl);
	return $new($InetSocketAddress, host, port);
}

$IOException* HttpRequestImpl::lambda$new$4() {
	$init(HttpRequestImpl);
	return $new($IOException, "No authority in Push Promise"_s);
}

$IOException* HttpRequestImpl::lambda$new$3() {
	$init(HttpRequestImpl);
	return $new($IOException, "No scheme in Push Promise"_s);
}

$IOException* HttpRequestImpl::lambda$new$2() {
	$init(HttpRequestImpl);
	return $new($IOException, "No path in Push Promise"_s);
}

$IOException* HttpRequestImpl::lambda$new$1() {
	$init(HttpRequestImpl);
	return $new($IOException, "No method in Push Promise"_s);
}

$String* HttpRequestImpl::lambda$userAgent$0() {
	$init(HttpRequestImpl);
	return $System::getProperty("java.version"_s);
}

void clinit$HttpRequestImpl($Class* class$) {
	HttpRequestImpl::$assertionsDisabled = !HttpRequestImpl::class$->desiredAssertionStatus();
	$assignStatic(HttpRequestImpl::USER_AGENT, HttpRequestImpl::userAgent());
}

HttpRequestImpl::HttpRequestImpl() {
}

$Class* HttpRequestImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HttpRequestImpl$$Lambda$lambda$userAgent$0::classInfo$.name)) {
			return HttpRequestImpl$$Lambda$lambda$userAgent$0::load$(name, initialize);
		}
		if (name->equals(HttpRequestImpl$$Lambda$lambda$new$1$1::classInfo$.name)) {
			return HttpRequestImpl$$Lambda$lambda$new$1$1::load$(name, initialize);
		}
		if (name->equals(HttpRequestImpl$$Lambda$lambda$new$2$2::classInfo$.name)) {
			return HttpRequestImpl$$Lambda$lambda$new$2$2::load$(name, initialize);
		}
		if (name->equals(HttpRequestImpl$$Lambda$lambda$new$3$3::classInfo$.name)) {
			return HttpRequestImpl$$Lambda$lambda$new$3$3::load$(name, initialize);
		}
		if (name->equals(HttpRequestImpl$$Lambda$lambda$new$4$4::classInfo$.name)) {
			return HttpRequestImpl$$Lambda$lambda$new$4$4::load$(name, initialize);
		}
		if (name->equals(HttpRequestImpl$$Lambda$lambda$getAddress$5$5::classInfo$.name)) {
			return HttpRequestImpl$$Lambda$lambda$getAddress$5$5::load$(name, initialize);
		}
	}
	$loadClass(HttpRequestImpl, name, initialize, &_HttpRequestImpl_ClassInfo_, clinit$HttpRequestImpl, allocate$HttpRequestImpl);
	return class$;
}

$Class* HttpRequestImpl::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk