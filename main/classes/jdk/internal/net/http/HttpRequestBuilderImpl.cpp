#include <jdk/internal/net/http/HttpRequestBuilderImpl.h>

#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IllegalStateException.h>
#include <java/net/URI.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpRequest$BodyPublisher.h>
#include <java/net/http/HttpRequest$Builder.h>
#include <java/net/http/HttpRequest.h>
#include <java/time/Duration.h>
#include <java/util/Locale.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/function/BiPredicate.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/ImmutableHttpRequest.h>
#include <jdk/internal/net/http/common/HttpHeadersBuilder.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef ALLOWED_HEADERS
#undef DELETE
#undef GET
#undef POST
#undef PUT
#undef US
#undef ZERO

using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $URI = ::java::net::URI;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $HttpRequest$Builder = ::java::net::http::HttpRequest$Builder;
using $Duration = ::java::time::Duration;
using $Locale = ::java::util::Locale;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $BiPredicate = ::java::util::function::BiPredicate;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $ImmutableHttpRequest = ::jdk::internal::net::http::ImmutableHttpRequest;
using $HttpHeadersBuilder = ::jdk::internal::net::http::common::HttpHeadersBuilder;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _HttpRequestBuilderImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HttpRequestBuilderImpl, $assertionsDisabled)},
	{"headersBuilder", "Ljdk/internal/net/http/common/HttpHeadersBuilder;", nullptr, $PRIVATE, $field(HttpRequestBuilderImpl, headersBuilder$)},
	{"uri", "Ljava/net/URI;", nullptr, $PRIVATE, $field(HttpRequestBuilderImpl, uri$)},
	{"method", "Ljava/lang/String;", nullptr, $PRIVATE, $field(HttpRequestBuilderImpl, method$)},
	{"expectContinue", "Z", nullptr, $PRIVATE, $field(HttpRequestBuilderImpl, expectContinue$)},
	{"bodyPublisher", "Ljava/net/http/HttpRequest$BodyPublisher;", nullptr, $PRIVATE, $field(HttpRequestBuilderImpl, bodyPublisher$)},
	{"version", "Ljava/util/Optional;", "Ljava/util/Optional<Ljava/net/http/HttpClient$Version;>;", $PRIVATE | $VOLATILE, $field(HttpRequestBuilderImpl, version$)},
	{"duration", "Ljava/time/Duration;", nullptr, $PRIVATE, $field(HttpRequestBuilderImpl, duration)},
	{}
};

$MethodInfo _HttpRequestBuilderImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/net/URI;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequestBuilderImpl::*)($URI*)>(&HttpRequestBuilderImpl::init$))},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequestBuilderImpl::*)()>(&HttpRequestBuilderImpl::init$))},
	{"DELETE", "()Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC},
	{"GET", "()Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC},
	{"POST", "(Ljava/net/http/HttpRequest$BodyPublisher;)Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC},
	{"PUT", "(Ljava/net/http/HttpRequest$BodyPublisher;)Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC},
	{"bodyPublisher", "()Ljava/net/http/HttpRequest$BodyPublisher;", nullptr, 0},
	{"build", "()Ljava/net/http/HttpRequest;", nullptr, $PUBLIC},
	{"buildForWebSocket", "()Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PUBLIC},
	{"checkNameAndValue", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(HttpRequestBuilderImpl::*)($String*,$String*)>(&HttpRequestBuilderImpl::checkNameAndValue))},
	{"checkURI", "(Ljava/net/URI;)V", nullptr, $STATIC, $method(static_cast<void(*)($URI*)>(&HttpRequestBuilderImpl::checkURI))},
	{"copy", "()Ljdk/internal/net/http/HttpRequestBuilderImpl;", nullptr, $PUBLIC},
	{"expectContinue", "(Z)Ljdk/internal/net/http/HttpRequestBuilderImpl;", nullptr, $PUBLIC},
	{"expectContinue", "()Z", nullptr, 0},
	{"header", "(Ljava/lang/String;Ljava/lang/String;)Ljdk/internal/net/http/HttpRequestBuilderImpl;", nullptr, $PUBLIC},
	{"headers", "([Ljava/lang/String;)Ljdk/internal/net/http/HttpRequestBuilderImpl;", nullptr, $PUBLIC | $TRANSIENT},
	{"headersBuilder", "()Ljdk/internal/net/http/common/HttpHeadersBuilder;", nullptr, 0},
	{"method", "()Ljava/lang/String;", nullptr, 0},
	{"method", "(Ljava/lang/String;Ljava/net/http/HttpRequest$BodyPublisher;)Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC},
	{"method0", "(Ljava/lang/String;Ljava/net/http/HttpRequest$BodyPublisher;)Ljava/net/http/HttpRequest$Builder;", nullptr, $PRIVATE, $method(static_cast<$HttpRequest$Builder*(HttpRequestBuilderImpl::*)($String*,$HttpRequest$BodyPublisher*)>(&HttpRequestBuilderImpl::method0))},
	{"setHeader", "(Ljava/lang/String;Ljava/lang/String;)Ljdk/internal/net/http/HttpRequestBuilderImpl;", nullptr, $PUBLIC},
	{"timeout", "(Ljava/time/Duration;)Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC},
	{"timeout", "()Ljava/time/Duration;", nullptr, 0},
	{"uri", "(Ljava/net/URI;)Ljdk/internal/net/http/HttpRequestBuilderImpl;", nullptr, $PUBLIC},
	{"uri", "()Ljava/net/URI;", nullptr, 0},
	{"version", "(Ljava/net/http/HttpClient$Version;)Ljdk/internal/net/http/HttpRequestBuilderImpl;", nullptr, $PUBLIC},
	{"version", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/http/HttpClient$Version;>;", 0},
	{}
};

$InnerClassInfo _HttpRequestBuilderImpl_InnerClassesInfo_[] = {
	{"java.net.http.HttpRequest$Builder", "java.net.http.HttpRequest", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpRequestBuilderImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.HttpRequestBuilderImpl",
	"java.lang.Object",
	"java.net.http.HttpRequest$Builder",
	_HttpRequestBuilderImpl_FieldInfo_,
	_HttpRequestBuilderImpl_MethodInfo_,
	nullptr,
	nullptr,
	_HttpRequestBuilderImpl_InnerClassesInfo_
};

$Object* allocate$HttpRequestBuilderImpl($Class* clazz) {
	return $of($alloc(HttpRequestBuilderImpl));
}

bool HttpRequestBuilderImpl::$assertionsDisabled = false;

void HttpRequestBuilderImpl::init$($URI* uri) {
	$Objects::requireNonNull($of(uri), "uri must be non-null"_s);
	checkURI(uri);
	$set(this, uri$, uri);
	$set(this, headersBuilder$, $new($HttpHeadersBuilder));
	$set(this, method$, "GET"_s);
	$set(this, version$, $Optional::empty());
}

void HttpRequestBuilderImpl::init$() {
	$set(this, headersBuilder$, $new($HttpHeadersBuilder));
	$set(this, method$, "GET"_s);
	$set(this, version$, $Optional::empty());
}

HttpRequestBuilderImpl* HttpRequestBuilderImpl::uri($URI* uri) {
	$Objects::requireNonNull($of(uri), "uri must be non-null"_s);
	checkURI(uri);
	$set(this, uri$, uri);
	return this;
}

void HttpRequestBuilderImpl::checkURI($URI* uri) {
	$init(HttpRequestBuilderImpl);
	$useLocalCurrentObjectStackCache();
	$var($String, scheme, $nc(uri)->getScheme());
	if (scheme == nullptr) {
		$throw($($Utils::newIAE("URI with undefined scheme"_s, $$new($ObjectArray, 0))));
	}
	$init($Locale);
	$assign(scheme, $nc(scheme)->toLowerCase($Locale::US));
	bool var$0 = scheme->equals("https"_s);
	if (!(var$0 || scheme->equals("http"_s))) {
		$throw($($Utils::newIAE("invalid URI scheme %s"_s, $$new($ObjectArray, {$of(scheme)}))));
	}
	if (uri->getHost() == nullptr) {
		$throw($($Utils::newIAE("unsupported URI %s"_s, $$new($ObjectArray, {$of(uri)}))));
	}
}

HttpRequestBuilderImpl* HttpRequestBuilderImpl::copy() {
	$var(HttpRequestBuilderImpl, b, $new(HttpRequestBuilderImpl));
	$set(b, uri$, this->uri$);
	$set(b, headersBuilder$, $nc(this->headersBuilder$)->structuralCopy());
	$set(b, method$, this->method$);
	b->expectContinue$ = this->expectContinue$;
	$set(b, bodyPublisher$, this->bodyPublisher$);
	$set(b, uri$, this->uri$);
	$set(b, duration, this->duration);
	$set(b, version$, this->version$);
	return b;
}

void HttpRequestBuilderImpl::checkNameAndValue($String* name, $String* value) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(name), "name"_s);
	$Objects::requireNonNull($of(value), "value"_s);
	if (!$Utils::isValidName(name)) {
		$throw($($Utils::newIAE("invalid header name: \"%s\""_s, $$new($ObjectArray, {$of(name)}))));
	}
	if (!$nc($Utils::ALLOWED_HEADERS)->test(name, nullptr)) {
		$throw($($Utils::newIAE("restricted header name: \"%s\""_s, $$new($ObjectArray, {$of(name)}))));
	}
	if (!$Utils::isValidValue(value)) {
		$throw($($Utils::newIAE("invalid header value: \"%s\""_s, $$new($ObjectArray, {$of(value)}))));
	}
}

HttpRequestBuilderImpl* HttpRequestBuilderImpl::setHeader($String* name, $String* value) {
	checkNameAndValue(name, value);
	$nc(this->headersBuilder$)->setHeader(name, value);
	return this;
}

HttpRequestBuilderImpl* HttpRequestBuilderImpl::header($String* name, $String* value) {
	checkNameAndValue(name, value);
	$nc(this->headersBuilder$)->addHeader(name, value);
	return this;
}

HttpRequestBuilderImpl* HttpRequestBuilderImpl::headers($StringArray* params) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(params);
	if (params->length == 0 || params->length % 2 != 0) {
		$throw($($Utils::newIAE("wrong number, %d, of parameters"_s, $$new($ObjectArray, {$($of($Integer::valueOf(params->length)))}))));
	}
	for (int32_t i = 0; i < params->length; i += 2) {
		$var($String, name, params->get(i));
		$var($String, value, params->get(i + 1));
		header(name, value);
	}
	return this;
}

HttpRequestBuilderImpl* HttpRequestBuilderImpl::expectContinue(bool enable) {
	this->expectContinue$ = enable;
	return this;
}

HttpRequestBuilderImpl* HttpRequestBuilderImpl::version($HttpClient$Version* version) {
	$Objects::requireNonNull(version);
	$set(this, version$, $Optional::of(version));
	return this;
}

$HttpHeadersBuilder* HttpRequestBuilderImpl::headersBuilder() {
	return this->headersBuilder$;
}

$URI* HttpRequestBuilderImpl::uri() {
	return this->uri$;
}

$String* HttpRequestBuilderImpl::method() {
	return this->method$;
}

bool HttpRequestBuilderImpl::expectContinue() {
	return this->expectContinue$;
}

$HttpRequest$BodyPublisher* HttpRequestBuilderImpl::bodyPublisher() {
	return this->bodyPublisher$;
}

$Optional* HttpRequestBuilderImpl::version() {
	return this->version$;
}

$HttpRequest$Builder* HttpRequestBuilderImpl::GET() {
	return method0("GET"_s, nullptr);
}

$HttpRequest$Builder* HttpRequestBuilderImpl::POST($HttpRequest$BodyPublisher* body) {
	return method0("POST"_s, $cast($HttpRequest$BodyPublisher, $Objects::requireNonNull(body)));
}

$HttpRequest$Builder* HttpRequestBuilderImpl::DELETE() {
	return method0("DELETE"_s, nullptr);
}

$HttpRequest$Builder* HttpRequestBuilderImpl::PUT($HttpRequest$BodyPublisher* body) {
	return method0("PUT"_s, $cast($HttpRequest$BodyPublisher, $Objects::requireNonNull(body)));
}

$HttpRequest$Builder* HttpRequestBuilderImpl::method($String* method, $HttpRequest$BodyPublisher* body) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(method);
	if (method->isEmpty()) {
		$throw($($Utils::newIAE("illegal method <empty string>"_s, $$new($ObjectArray, 0))));
	}
	if (method->equals("CONNECT"_s)) {
		$throw($($Utils::newIAE("method CONNECT is not supported"_s, $$new($ObjectArray, 0))));
	}
	if (!$Utils::isValidName(method)) {
		$throw($($Utils::newIAE($$str({"illegal method \""_s, $($($(method->replace(static_cast<$CharSequence*>("\n"_s), static_cast<$CharSequence*>("\\n"_s)))->replace(static_cast<$CharSequence*>("\r"_s), static_cast<$CharSequence*>("\\r"_s)))->replace(static_cast<$CharSequence*>("\t"_s), static_cast<$CharSequence*>("\\t"_s))), "\""_s}), $$new($ObjectArray, 0))));
	}
	return method0(method, $cast($HttpRequest$BodyPublisher, $Objects::requireNonNull(body)));
}

$HttpRequest$Builder* HttpRequestBuilderImpl::method0($String* method, $HttpRequest$BodyPublisher* body) {
	if (!HttpRequestBuilderImpl::$assertionsDisabled && !(method != nullptr)) {
		$throwNew($AssertionError);
	}
	if (!HttpRequestBuilderImpl::$assertionsDisabled && ! !$nc(method)->isEmpty()) {
		$throwNew($AssertionError);
	}
	$set(this, method$, method);
	$set(this, bodyPublisher$, body);
	return this;
}

$HttpRequest* HttpRequestBuilderImpl::build() {
	if (this->uri$ == nullptr) {
		$throwNew($IllegalStateException, "uri is null"_s);
	}
	if (!HttpRequestBuilderImpl::$assertionsDisabled && !(this->method$ != nullptr)) {
		$throwNew($AssertionError);
	}
	return $new($ImmutableHttpRequest, this);
}

$HttpRequestImpl* HttpRequestBuilderImpl::buildForWebSocket() {
	if (this->uri$ == nullptr) {
		$throwNew($IllegalStateException, "uri is null"_s);
	}
	if (!HttpRequestBuilderImpl::$assertionsDisabled && !(this->method$ != nullptr)) {
		$throwNew($AssertionError);
	}
	return $new($HttpRequestImpl, this);
}

$HttpRequest$Builder* HttpRequestBuilderImpl::timeout($Duration* duration) {
	$Objects::requireNonNull(duration);
	bool var$0 = duration->isNegative();
	if (var$0 || $nc($Duration::ZERO)->equals(duration)) {
		$throwNew($IllegalArgumentException, $$str({"Invalid duration: "_s, duration}));
	}
	$set(this, duration, duration);
	return this;
}

$Duration* HttpRequestBuilderImpl::timeout() {
	return this->duration;
}

void clinit$HttpRequestBuilderImpl($Class* class$) {
	HttpRequestBuilderImpl::$assertionsDisabled = !HttpRequestBuilderImpl::class$->desiredAssertionStatus();
}

HttpRequestBuilderImpl::HttpRequestBuilderImpl() {
}

$Class* HttpRequestBuilderImpl::load$($String* name, bool initialize) {
	$loadClass(HttpRequestBuilderImpl, name, initialize, &_HttpRequestBuilderImpl_ClassInfo_, clinit$HttpRequestBuilderImpl, allocate$HttpRequestBuilderImpl);
	return class$;
}

$Class* HttpRequestBuilderImpl::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk