#include <java/net/http/HttpResponse$ResponseInfo.h>

#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpResponse.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpResponse = ::java::net::http::HttpResponse;

namespace java {
	namespace net {
		namespace http {

$MethodInfo _HttpResponse$ResponseInfo_MethodInfo_[] = {
	{"headers", "()Ljava/net/http/HttpHeaders;", nullptr, $PUBLIC | $ABSTRACT},
	{"statusCode", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"version", "()Ljava/net/http/HttpClient$Version;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _HttpResponse$ResponseInfo_InnerClassesInfo_[] = {
	{"java.net.http.HttpResponse$ResponseInfo", "java.net.http.HttpResponse", "ResponseInfo", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpResponse$ResponseInfo_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.net.http.HttpResponse$ResponseInfo",
	nullptr,
	nullptr,
	nullptr,
	_HttpResponse$ResponseInfo_MethodInfo_,
	nullptr,
	nullptr,
	_HttpResponse$ResponseInfo_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.net.http.HttpResponse"
};

$Object* allocate$HttpResponse$ResponseInfo($Class* clazz) {
	return $of($alloc(HttpResponse$ResponseInfo));
}

$Class* HttpResponse$ResponseInfo::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$ResponseInfo, name, initialize, &_HttpResponse$ResponseInfo_ClassInfo_, allocate$HttpResponse$ResponseInfo);
	return class$;
}

$Class* HttpResponse$ResponseInfo::class$ = nullptr;

		} // http
	} // net
} // java