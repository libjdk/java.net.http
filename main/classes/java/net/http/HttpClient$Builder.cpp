#include <java/net/http/HttpClient$Builder.h>

#include <java/net/Authenticator.h>
#include <java/net/CookieHandler.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/ProxySelector.h>
#include <java/net/http/HttpClient$Redirect.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpClient.h>
#include <java/time/Duration.h>
#include <java/util/concurrent/Executor.h>
#include <javax/net/ssl/SSLContext.h>
#include <javax/net/ssl/SSLParameters.h>
#include <jcpp.h>

#undef NO_PROXY

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Authenticator = ::java::net::Authenticator;
using $CookieHandler = ::java::net::CookieHandler;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $ProxySelector = ::java::net::ProxySelector;
using $HttpClient = ::java::net::http::HttpClient;
using $HttpClient$Redirect = ::java::net::http::HttpClient$Redirect;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $Duration = ::java::time::Duration;
using $Executor = ::java::util::concurrent::Executor;
using $SSLContext = ::javax::net::ssl::SSLContext;
using $SSLParameters = ::javax::net::ssl::SSLParameters;

namespace java {
	namespace net {
		namespace http {

$FieldInfo _HttpClient$Builder_FieldInfo_[] = {
	{"NO_PROXY", "Ljava/net/ProxySelector;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(HttpClient$Builder, NO_PROXY)},
	{}
};

$MethodInfo _HttpClient$Builder_MethodInfo_[] = {
	{"authenticator", "(Ljava/net/Authenticator;)Ljava/net/http/HttpClient$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"build", "()Ljava/net/http/HttpClient;", nullptr, $PUBLIC | $ABSTRACT},
	{"connectTimeout", "(Ljava/time/Duration;)Ljava/net/http/HttpClient$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"cookieHandler", "(Ljava/net/CookieHandler;)Ljava/net/http/HttpClient$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"executor", "(Ljava/util/concurrent/Executor;)Ljava/net/http/HttpClient$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"followRedirects", "(Ljava/net/http/HttpClient$Redirect;)Ljava/net/http/HttpClient$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"priority", "(I)Ljava/net/http/HttpClient$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"proxy", "(Ljava/net/ProxySelector;)Ljava/net/http/HttpClient$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"sslContext", "(Ljavax/net/ssl/SSLContext;)Ljava/net/http/HttpClient$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"sslParameters", "(Ljavax/net/ssl/SSLParameters;)Ljava/net/http/HttpClient$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"version", "(Ljava/net/http/HttpClient$Version;)Ljava/net/http/HttpClient$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _HttpClient$Builder_InnerClassesInfo_[] = {
	{"java.net.http.HttpClient$Builder", "java.net.http.HttpClient", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpClient$Builder_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.net.http.HttpClient$Builder",
	nullptr,
	nullptr,
	_HttpClient$Builder_FieldInfo_,
	_HttpClient$Builder_MethodInfo_,
	nullptr,
	nullptr,
	_HttpClient$Builder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.net.http.HttpClient"
};

$Object* allocate$HttpClient$Builder($Class* clazz) {
	return $of($alloc(HttpClient$Builder));
}

$ProxySelector* HttpClient$Builder::NO_PROXY = nullptr;

void clinit$HttpClient$Builder($Class* class$) {
	$assignStatic(HttpClient$Builder::NO_PROXY, $ProxySelector::of(nullptr));
}

$Class* HttpClient$Builder::load$($String* name, bool initialize) {
	$loadClass(HttpClient$Builder, name, initialize, &_HttpClient$Builder_ClassInfo_, clinit$HttpClient$Builder, allocate$HttpClient$Builder);
	return class$;
}

$Class* HttpClient$Builder::class$ = nullptr;

		} // http
	} // net
} // java