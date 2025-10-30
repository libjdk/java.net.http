#include <jdk/internal/net/http/HttpClientBuilderImpl.h>

#include <java/net/Authenticator.h>
#include <java/net/CookieHandler.h>
#include <java/net/ProxySelector.h>
#include <java/net/http/HttpClient$Redirect.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpClient.h>
#include <java/time/Duration.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/Executor.h>
#include <javax/net/ssl/SSLContext.h>
#include <javax/net/ssl/SSLParameters.h>
#include <jdk/internal/net/http/HttpClientFacade.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef ZERO

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Authenticator = ::java::net::Authenticator;
using $CookieHandler = ::java::net::CookieHandler;
using $ProxySelector = ::java::net::ProxySelector;
using $HttpClient = ::java::net::http::HttpClient;
using $HttpClient$Builder = ::java::net::http::HttpClient$Builder;
using $HttpClient$Redirect = ::java::net::http::HttpClient$Redirect;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $Duration = ::java::time::Duration;
using $Objects = ::java::util::Objects;
using $Executor = ::java::util::concurrent::Executor;
using $SSLContext = ::javax::net::ssl::SSLContext;
using $SSLParameters = ::javax::net::ssl::SSLParameters;
using $HttpClientFacade = ::jdk::internal::net::http::HttpClientFacade;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _HttpClientBuilderImpl_FieldInfo_[] = {
	{"cookieHandler", "Ljava/net/CookieHandler;", nullptr, 0, $field(HttpClientBuilderImpl, cookieHandler$)},
	{"connectTimeout", "Ljava/time/Duration;", nullptr, 0, $field(HttpClientBuilderImpl, connectTimeout$)},
	{"followRedirects", "Ljava/net/http/HttpClient$Redirect;", nullptr, 0, $field(HttpClientBuilderImpl, followRedirects$)},
	{"proxy", "Ljava/net/ProxySelector;", nullptr, 0, $field(HttpClientBuilderImpl, proxy$)},
	{"authenticator", "Ljava/net/Authenticator;", nullptr, 0, $field(HttpClientBuilderImpl, authenticator$)},
	{"version", "Ljava/net/http/HttpClient$Version;", nullptr, 0, $field(HttpClientBuilderImpl, version$)},
	{"executor", "Ljava/util/concurrent/Executor;", nullptr, 0, $field(HttpClientBuilderImpl, executor$)},
	{"sslContext", "Ljavax/net/ssl/SSLContext;", nullptr, 0, $field(HttpClientBuilderImpl, sslContext$)},
	{"sslParams", "Ljavax/net/ssl/SSLParameters;", nullptr, 0, $field(HttpClientBuilderImpl, sslParams)},
	{"priority", "I", nullptr, 0, $field(HttpClientBuilderImpl, priority$)},
	{}
};

$MethodInfo _HttpClientBuilderImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientBuilderImpl::*)()>(&HttpClientBuilderImpl::init$))},
	{"authenticator", "(Ljava/net/Authenticator;)Ljdk/internal/net/http/HttpClientBuilderImpl;", nullptr, $PUBLIC},
	{"build", "()Ljava/net/http/HttpClient;", nullptr, $PUBLIC},
	{"connectTimeout", "(Ljava/time/Duration;)Ljdk/internal/net/http/HttpClientBuilderImpl;", nullptr, $PUBLIC},
	{"cookieHandler", "(Ljava/net/CookieHandler;)Ljdk/internal/net/http/HttpClientBuilderImpl;", nullptr, $PUBLIC},
	{"executor", "(Ljava/util/concurrent/Executor;)Ljdk/internal/net/http/HttpClientBuilderImpl;", nullptr, $PUBLIC},
	{"followRedirects", "(Ljava/net/http/HttpClient$Redirect;)Ljdk/internal/net/http/HttpClientBuilderImpl;", nullptr, $PUBLIC},
	{"priority", "(I)Ljdk/internal/net/http/HttpClientBuilderImpl;", nullptr, $PUBLIC},
	{"proxy", "(Ljava/net/ProxySelector;)Ljdk/internal/net/http/HttpClientBuilderImpl;", nullptr, $PUBLIC},
	{"sslContext", "(Ljavax/net/ssl/SSLContext;)Ljdk/internal/net/http/HttpClientBuilderImpl;", nullptr, $PUBLIC},
	{"sslParameters", "(Ljavax/net/ssl/SSLParameters;)Ljdk/internal/net/http/HttpClientBuilderImpl;", nullptr, $PUBLIC},
	{"version", "(Ljava/net/http/HttpClient$Version;)Ljdk/internal/net/http/HttpClientBuilderImpl;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _HttpClientBuilderImpl_InnerClassesInfo_[] = {
	{"java.net.http.HttpClient$Builder", "java.net.http.HttpClient", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpClientBuilderImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.HttpClientBuilderImpl",
	"java.lang.Object",
	"java.net.http.HttpClient$Builder",
	_HttpClientBuilderImpl_FieldInfo_,
	_HttpClientBuilderImpl_MethodInfo_,
	nullptr,
	nullptr,
	_HttpClientBuilderImpl_InnerClassesInfo_
};

$Object* allocate$HttpClientBuilderImpl($Class* clazz) {
	return $of($alloc(HttpClientBuilderImpl));
}

void HttpClientBuilderImpl::init$() {
	this->priority$ = -1;
}

HttpClientBuilderImpl* HttpClientBuilderImpl::cookieHandler($CookieHandler* cookieHandler) {
	$Objects::requireNonNull(cookieHandler);
	$set(this, cookieHandler$, cookieHandler);
	return this;
}

HttpClientBuilderImpl* HttpClientBuilderImpl::connectTimeout($Duration* duration) {
	$Objects::requireNonNull(duration);
	bool var$0 = duration->isNegative();
	if (var$0 || $nc($Duration::ZERO)->equals(duration)) {
		$throwNew($IllegalArgumentException, $$str({"Invalid duration: "_s, duration}));
	}
	$set(this, connectTimeout$, duration);
	return this;
}

HttpClientBuilderImpl* HttpClientBuilderImpl::sslContext($SSLContext* sslContext) {
	$Objects::requireNonNull(sslContext);
	$set(this, sslContext$, sslContext);
	return this;
}

HttpClientBuilderImpl* HttpClientBuilderImpl::sslParameters($SSLParameters* sslParameters) {
	$Objects::requireNonNull(sslParameters);
	$set(this, sslParams, $Utils::copySSLParameters(sslParameters));
	return this;
}

HttpClientBuilderImpl* HttpClientBuilderImpl::executor($Executor* s) {
	$Objects::requireNonNull(s);
	$set(this, executor$, s);
	return this;
}

HttpClientBuilderImpl* HttpClientBuilderImpl::followRedirects($HttpClient$Redirect* policy) {
	$Objects::requireNonNull(policy);
	$set(this, followRedirects$, policy);
	return this;
}

HttpClientBuilderImpl* HttpClientBuilderImpl::version($HttpClient$Version* version) {
	$Objects::requireNonNull(version);
	$set(this, version$, version);
	return this;
}

HttpClientBuilderImpl* HttpClientBuilderImpl::priority(int32_t priority) {
	if (priority < 1 || priority > 256) {
		$throwNew($IllegalArgumentException, "priority must be between 1 and 256"_s);
	}
	this->priority$ = priority;
	return this;
}

HttpClientBuilderImpl* HttpClientBuilderImpl::proxy($ProxySelector* proxy) {
	$Objects::requireNonNull(proxy);
	$set(this, proxy$, proxy);
	return this;
}

HttpClientBuilderImpl* HttpClientBuilderImpl::authenticator($Authenticator* a) {
	$Objects::requireNonNull(a);
	$set(this, authenticator$, a);
	return this;
}

$HttpClient* HttpClientBuilderImpl::build() {
	return $HttpClientImpl::create(this);
}

HttpClientBuilderImpl::HttpClientBuilderImpl() {
}

$Class* HttpClientBuilderImpl::load$($String* name, bool initialize) {
	$loadClass(HttpClientBuilderImpl, name, initialize, &_HttpClientBuilderImpl_ClassInfo_, allocate$HttpClientBuilderImpl);
	return class$;
}

$Class* HttpClientBuilderImpl::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk