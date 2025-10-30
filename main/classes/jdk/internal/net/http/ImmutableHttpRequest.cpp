#include <jdk/internal/net/http/ImmutableHttpRequest.h>

#include <java/net/URI.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpRequest$BodyPublisher.h>
#include <java/net/http/HttpRequest.h>
#include <java/time/Duration.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/function/BiPredicate.h>
#include <jdk/internal/net/http/HttpRequestBuilderImpl.h>
#include <jdk/internal/net/http/common/HttpHeadersBuilder.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef ALLOWED_HEADERS

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URI = ::java::net::URI;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $Duration = ::java::time::Duration;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $BiPredicate = ::java::util::function::BiPredicate;
using $HttpRequestBuilderImpl = ::jdk::internal::net::http::HttpRequestBuilderImpl;
using $HttpHeadersBuilder = ::jdk::internal::net::http::common::HttpHeadersBuilder;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ImmutableHttpRequest_FieldInfo_[] = {
	{"method", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ImmutableHttpRequest, method$)},
	{"uri", "Ljava/net/URI;", nullptr, $PRIVATE | $FINAL, $field(ImmutableHttpRequest, uri$)},
	{"headers", "Ljava/net/http/HttpHeaders;", nullptr, $PRIVATE | $FINAL, $field(ImmutableHttpRequest, headers$)},
	{"requestPublisher", "Ljava/util/Optional;", "Ljava/util/Optional<Ljava/net/http/HttpRequest$BodyPublisher;>;", $PRIVATE | $FINAL, $field(ImmutableHttpRequest, requestPublisher)},
	{"expectContinue", "Z", nullptr, $PRIVATE | $FINAL, $field(ImmutableHttpRequest, expectContinue$)},
	{"timeout", "Ljava/util/Optional;", "Ljava/util/Optional<Ljava/time/Duration;>;", $PRIVATE | $FINAL, $field(ImmutableHttpRequest, timeout$)},
	{"version", "Ljava/util/Optional;", "Ljava/util/Optional<Ljava/net/http/HttpClient$Version;>;", $PRIVATE | $FINAL, $field(ImmutableHttpRequest, version$)},
	{}
};

$MethodInfo _ImmutableHttpRequest_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpRequestBuilderImpl;)V", nullptr, 0, $method(static_cast<void(ImmutableHttpRequest::*)($HttpRequestBuilderImpl*)>(&ImmutableHttpRequest::init$))},
	{"bodyPublisher", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/http/HttpRequest$BodyPublisher;>;", $PUBLIC},
	{"expectContinue", "()Z", nullptr, $PUBLIC},
	{"headers", "()Ljava/net/http/HttpHeaders;", nullptr, $PUBLIC},
	{"method", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"timeout", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/time/Duration;>;", $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"uri", "()Ljava/net/URI;", nullptr, $PUBLIC},
	{"version", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/http/HttpClient$Version;>;", $PUBLIC},
	{}
};

$ClassInfo _ImmutableHttpRequest_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.ImmutableHttpRequest",
	"java.net.http.HttpRequest",
	nullptr,
	_ImmutableHttpRequest_FieldInfo_,
	_ImmutableHttpRequest_MethodInfo_
};

$Object* allocate$ImmutableHttpRequest($Class* clazz) {
	return $of($alloc(ImmutableHttpRequest));
}

void ImmutableHttpRequest::init$($HttpRequestBuilderImpl* builder) {
	$useLocalCurrentObjectStackCache();
	$HttpRequest::init$();
	$set(this, method$, $cast($String, $Objects::requireNonNull($($nc(builder)->method()))));
	$set(this, uri$, $cast($URI, $Objects::requireNonNull($($nc(builder)->uri()))));
	$init($Utils);
	$set(this, headers$, $HttpHeaders::of($($nc($($nc(builder)->headersBuilder()))->map()), $Utils::ALLOWED_HEADERS));
	$set(this, requestPublisher, $Optional::ofNullable($($nc(builder)->bodyPublisher())));
	this->expectContinue$ = $nc(builder)->expectContinue();
	$set(this, timeout$, $Optional::ofNullable($(builder->timeout())));
	$set(this, version$, $cast($Optional, $Objects::requireNonNull($(builder->version()))));
}

$String* ImmutableHttpRequest::method() {
	return this->method$;
}

$URI* ImmutableHttpRequest::uri() {
	return this->uri$;
}

$HttpHeaders* ImmutableHttpRequest::headers() {
	return this->headers$;
}

$Optional* ImmutableHttpRequest::bodyPublisher() {
	return this->requestPublisher;
}

bool ImmutableHttpRequest::expectContinue() {
	return this->expectContinue$;
}

$Optional* ImmutableHttpRequest::timeout() {
	return this->timeout$;
}

$Optional* ImmutableHttpRequest::version() {
	return this->version$;
}

$String* ImmutableHttpRequest::toString() {
	return $str({$($nc(this->uri$)->toString()), " "_s, this->method$});
}

ImmutableHttpRequest::ImmutableHttpRequest() {
}

$Class* ImmutableHttpRequest::load$($String* name, bool initialize) {
	$loadClass(ImmutableHttpRequest, name, initialize, &_ImmutableHttpRequest_ClassInfo_, allocate$ImmutableHttpRequest);
	return class$;
}

$Class* ImmutableHttpRequest::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk