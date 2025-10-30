#include <java/net/http/HttpRequest$Builder.h>

#include <java/net/URI.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpRequest$BodyPublisher.h>
#include <java/net/http/HttpRequest.h>
#include <java/time/Duration.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URI = ::java::net::URI;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $Duration = ::java::time::Duration;

namespace java {
	namespace net {
		namespace http {

$MethodInfo _HttpRequest$Builder_MethodInfo_[] = {
	{"DELETE", "()Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"GET", "()Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"POST", "(Ljava/net/http/HttpRequest$BodyPublisher;)Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"PUT", "(Ljava/net/http/HttpRequest$BodyPublisher;)Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"build", "()Ljava/net/http/HttpRequest;", nullptr, $PUBLIC | $ABSTRACT},
	{"copy", "()Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"expectContinue", "(Z)Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"header", "(Ljava/lang/String;Ljava/lang/String;)Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"headers", "([Ljava/lang/String;)Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC | $TRANSIENT | $ABSTRACT},
	{"method", "(Ljava/lang/String;Ljava/net/http/HttpRequest$BodyPublisher;)Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"setHeader", "(Ljava/lang/String;Ljava/lang/String;)Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"timeout", "(Ljava/time/Duration;)Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"uri", "(Ljava/net/URI;)Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"version", "(Ljava/net/http/HttpClient$Version;)Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _HttpRequest$Builder_InnerClassesInfo_[] = {
	{"java.net.http.HttpRequest$Builder", "java.net.http.HttpRequest", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpRequest$Builder_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.net.http.HttpRequest$Builder",
	nullptr,
	nullptr,
	nullptr,
	_HttpRequest$Builder_MethodInfo_,
	nullptr,
	nullptr,
	_HttpRequest$Builder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.net.http.HttpRequest"
};

$Object* allocate$HttpRequest$Builder($Class* clazz) {
	return $of($alloc(HttpRequest$Builder));
}

$Class* HttpRequest$Builder::load$($String* name, bool initialize) {
	$loadClass(HttpRequest$Builder, name, initialize, &_HttpRequest$Builder_ClassInfo_, allocate$HttpRequest$Builder);
	return class$;
}

$Class* HttpRequest$Builder::class$ = nullptr;

		} // http
	} // net
} // java