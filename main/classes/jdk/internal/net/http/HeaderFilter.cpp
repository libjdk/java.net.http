#include <jdk/internal/net/http/HeaderFilter.h>

#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/Response.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;
using $Response = ::jdk::internal::net::http::Response;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$MethodInfo _HeaderFilter_MethodInfo_[] = {
	{"request", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/MultiExchange;)V", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/MultiExchange<*>;)V", $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"response", "(Ljdk/internal/net/http/Response;)Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _HeaderFilter_ClassInfo_ = {
	$INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.HeaderFilter",
	nullptr,
	nullptr,
	nullptr,
	_HeaderFilter_MethodInfo_
};

$Object* allocate$HeaderFilter($Class* clazz) {
	return $of($alloc(HeaderFilter));
}

$Class* HeaderFilter::load$($String* name, bool initialize) {
	$loadClass(HeaderFilter, name, initialize, &_HeaderFilter_ClassInfo_, allocate$HeaderFilter);
	return class$;
}

$Class* HeaderFilter::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk