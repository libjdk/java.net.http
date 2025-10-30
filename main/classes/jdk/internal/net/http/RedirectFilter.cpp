#include <jdk/internal/net/http/RedirectFilter.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/IncompatibleClassChangeError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/URI.h>
#include <java/net/http/HttpClient$Redirect.h>
#include <java/net/http/HttpHeaders.h>
#include <java/util/Optional.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/RedirectFilter$1.h>
#include <jdk/internal/net/http/Response.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef DEFAULT_MAX_REDIRECTS
#undef HTTP_NOT_MODIFIED
#undef NEVER

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $IncompatibleClassChangeError = ::java::lang::IncompatibleClassChangeError;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $URI = ::java::net::URI;
using $HttpClient$Redirect = ::java::net::http::HttpClient$Redirect;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $Optional = ::java::util::Optional;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;
using $HeaderFilter = ::jdk::internal::net::http::HeaderFilter;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;
using $RedirectFilter$1 = ::jdk::internal::net::http::RedirectFilter$1;
using $Response = ::jdk::internal::net::http::Response;
using $Log = ::jdk::internal::net::http::common::Log;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class RedirectFilter$$Lambda$create : public $Function {
	$class(RedirectFilter$$Lambda$create, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* arg0) override {
		 return $of($URI::create($cast($String, arg0)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RedirectFilter$$Lambda$create>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo RedirectFilter$$Lambda$create::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RedirectFilter$$Lambda$create::*)()>(&RedirectFilter$$Lambda$create::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo RedirectFilter$$Lambda$create::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.RedirectFilter$$Lambda$create",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* RedirectFilter$$Lambda$create::load$($String* name, bool initialize) {
	$loadClass(RedirectFilter$$Lambda$create, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RedirectFilter$$Lambda$create::class$ = nullptr;

class RedirectFilter$$Lambda$lambda$getRedirectedURI$0$1 : public $Supplier {
	$class(RedirectFilter$$Lambda$lambda$getRedirectedURI$0$1, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(RedirectFilter::lambda$getRedirectedURI$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RedirectFilter$$Lambda$lambda$getRedirectedURI$0$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo RedirectFilter$$Lambda$lambda$getRedirectedURI$0$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RedirectFilter$$Lambda$lambda$getRedirectedURI$0$1::*)()>(&RedirectFilter$$Lambda$lambda$getRedirectedURI$0$1::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo RedirectFilter$$Lambda$lambda$getRedirectedURI$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.RedirectFilter$$Lambda$lambda$getRedirectedURI$0$1",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* RedirectFilter$$Lambda$lambda$getRedirectedURI$0$1::load$($String* name, bool initialize) {
	$loadClass(RedirectFilter$$Lambda$lambda$getRedirectedURI$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RedirectFilter$$Lambda$lambda$getRedirectedURI$0$1::class$ = nullptr;

$FieldInfo _RedirectFilter_FieldInfo_[] = {
	{"request", "Ljdk/internal/net/http/HttpRequestImpl;", nullptr, 0, $field(RedirectFilter, request$)},
	{"client", "Ljdk/internal/net/http/HttpClientImpl;", nullptr, 0, $field(RedirectFilter, client)},
	{"policy", "Ljava/net/http/HttpClient$Redirect;", nullptr, 0, $field(RedirectFilter, policy)},
	{"method", "Ljava/lang/String;", nullptr, 0, $field(RedirectFilter, method)},
	{"exchange", "Ljdk/internal/net/http/MultiExchange;", "Ljdk/internal/net/http/MultiExchange<*>;", 0, $field(RedirectFilter, exchange)},
	{"DEFAULT_MAX_REDIRECTS", "I", nullptr, $STATIC | $FINAL, $constField(RedirectFilter, DEFAULT_MAX_REDIRECTS)},
	{"uri", "Ljava/net/URI;", nullptr, 0, $field(RedirectFilter, uri)},
	{"HTTP_NOT_MODIFIED", "I", nullptr, $STATIC | $FINAL, $constField(RedirectFilter, HTTP_NOT_MODIFIED)},
	{"max_redirects", "I", nullptr, $STATIC | $FINAL, $staticField(RedirectFilter, max_redirects)},
	{}
};

$MethodInfo _RedirectFilter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RedirectFilter::*)()>(&RedirectFilter::init$))},
	{"canRedirect", "(Ljava/net/URI;)Z", nullptr, $PRIVATE, $method(static_cast<bool(RedirectFilter::*)($URI*)>(&RedirectFilter::canRedirect))},
	{"getRedirectedURI", "(Ljava/net/http/HttpHeaders;)Ljava/net/URI;", nullptr, $PRIVATE, $method(static_cast<$URI*(RedirectFilter::*)($HttpHeaders*)>(&RedirectFilter::getRedirectedURI))},
	{"handleResponse", "(Ljdk/internal/net/http/Response;)Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PRIVATE, $method(static_cast<$HttpRequestImpl*(RedirectFilter::*)($Response*)>(&RedirectFilter::handleResponse))},
	{"isRedirecting", "(I)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)(int32_t)>(&RedirectFilter::isRedirecting))},
	{"lambda$getRedirectedURI$0", "()Ljava/io/UncheckedIOException;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$UncheckedIOException*(*)()>(&RedirectFilter::lambda$getRedirectedURI$0))},
	{"redirectedMethod", "(ILjava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)(int32_t,$String*)>(&RedirectFilter::redirectedMethod))},
	{"request", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/MultiExchange;)V", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/MultiExchange<*>;)V", $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{"response", "(Ljdk/internal/net/http/Response;)Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _RedirectFilter_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RedirectFilter$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _RedirectFilter_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.RedirectFilter",
	"java.lang.Object",
	"jdk.internal.net.http.HeaderFilter",
	_RedirectFilter_FieldInfo_,
	_RedirectFilter_MethodInfo_,
	nullptr,
	nullptr,
	_RedirectFilter_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RedirectFilter$1"
};

$Object* allocate$RedirectFilter($Class* clazz) {
	return $of($alloc(RedirectFilter));
}

int32_t RedirectFilter::max_redirects = 0;

void RedirectFilter::init$() {
}

void RedirectFilter::request($HttpRequestImpl* r, $MultiExchange* e) {
	$synchronized(this) {
		$set(this, request$, r);
		$set(this, client, $nc(e)->client());
		$set(this, policy, $nc(this->client)->followRedirects());
		$set(this, method, $nc(r)->method());
		$set(this, uri, r->uri());
		$set(this, exchange, e);
	}
}

$HttpRequestImpl* RedirectFilter::response($Response* r) {
	$synchronized(this) {
		return handleResponse(r);
	}
}

$String* RedirectFilter::redirectedMethod(int32_t statusCode, $String* orig) {
	$init(RedirectFilter);

	$var($String, var$0, nullptr)
	switch (statusCode) {
	case 301:
		{}
	case 302:
		{
			$assign(var$0, $nc(orig)->equals("POST"_s) ? "GET"_s : orig);
			break;
		}
	case 303:
		{
			$assign(var$0, "GET"_s);
			break;
		}
	case 307:
		{}
	case 308:
		{
			$assign(var$0, orig);
			break;
		}
	default:
		{
			$assign(var$0, orig);
			break;
		}
	}
	return var$0;
}

bool RedirectFilter::isRedirecting(int32_t statusCode) {
	$init(RedirectFilter);
	if (statusCode < 300) {
		return false;
	}
	if (statusCode > 308) {
		return false;
	}

	bool var$0 = false;
	switch (statusCode) {
	case 300:
		{}
	case 304:
		{}
	case 305:
		{}
	case 306:
		{
			var$0 = false;
			break;
		}
	default:
		{
			var$0 = true;
			break;
		}
	}
	return var$0;
}

$HttpRequestImpl* RedirectFilter::handleResponse($Response* r) {
	$useLocalCurrentObjectStackCache();
	int32_t rcode = $nc(r)->statusCode();
	$init($HttpClient$Redirect);
	if (rcode == 200 || this->policy == $HttpClient$Redirect::NEVER) {
		return nullptr;
	}
	if (rcode == RedirectFilter::HTTP_NOT_MODIFIED) {
		return nullptr;
	}
	if (isRedirecting(rcode)) {
		$var($URI, redir, getRedirectedURI($(r->headers())));
		$var($String, newMethod, redirectedMethod(rcode, this->method));
		$Log::logTrace("response code: {0}, redirected URI: {1}"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf(rcode))),
			$of(redir)
		}));
		if (canRedirect(redir) && ++$nc(this->exchange)->numberOfRedirects < RedirectFilter::max_redirects) {
			$Log::logTrace("redirect to: {0} with method: {1}"_s, $$new($ObjectArray, {
				$of(redir),
				$of(newMethod)
			}));
			return $HttpRequestImpl::newInstanceForRedirection(redir, newMethod, this->request$, rcode != 303);
		} else {
			$Log::logTrace("not redirecting"_s, $$new($ObjectArray, 0));
			return nullptr;
		}
	}
	return nullptr;
}

$URI* RedirectFilter::getRedirectedURI($HttpHeaders* headers) {
	$useLocalCurrentObjectStackCache();
	$var($URI, redirectedURI, nullptr);
	$assign(redirectedURI, $cast($URI, $nc($($nc($($nc(headers)->firstValue("Location"_s)))->map(static_cast<$Function*>($$new(RedirectFilter$$Lambda$create)))))->orElseThrow(static_cast<$Supplier*>($$new(RedirectFilter$$Lambda$lambda$getRedirectedURI$0$1)))));
	$assign(redirectedURI, $nc(this->uri)->resolve(redirectedURI));
	return redirectedURI;
}

bool RedirectFilter::canRedirect($URI* redir) {
	$useLocalCurrentObjectStackCache();
	$var($String, newScheme, $nc(redir)->getScheme());
	$var($String, oldScheme, $nc(this->uri)->getScheme());
	$init($RedirectFilter$1);

	bool var$0 = false;
	switch ($nc($RedirectFilter$1::$SwitchMap$java$net$http$HttpClient$Redirect)->get($nc((this->policy))->ordinal())) {
	default:
		{
			$throwNew($IncompatibleClassChangeError);
		}
	case 1:
		{
			var$0 = true;
			break;
		}
	case 2:
		{
			var$0 = false;
			break;
		}
	case 3:
		{
			bool var$1 = $nc(newScheme)->equalsIgnoreCase(oldScheme);
			var$0 = var$1 || $nc(newScheme)->equalsIgnoreCase("https"_s);
			break;
		}
	}
	return var$0;
}

$UncheckedIOException* RedirectFilter::lambda$getRedirectedURI$0() {
	$init(RedirectFilter);
	return $new($UncheckedIOException, $$new($IOException, "Invalid redirection"_s));
}

void clinit$RedirectFilter($Class* class$) {
	RedirectFilter::max_redirects = $Utils::getIntegerNetProperty("jdk.httpclient.redirects.retrylimit"_s, RedirectFilter::DEFAULT_MAX_REDIRECTS);
}

RedirectFilter::RedirectFilter() {
}

$Class* RedirectFilter::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RedirectFilter$$Lambda$create::classInfo$.name)) {
			return RedirectFilter$$Lambda$create::load$(name, initialize);
		}
		if (name->equals(RedirectFilter$$Lambda$lambda$getRedirectedURI$0$1::classInfo$.name)) {
			return RedirectFilter$$Lambda$lambda$getRedirectedURI$0$1::load$(name, initialize);
		}
	}
	$loadClass(RedirectFilter, name, initialize, &_RedirectFilter_ClassInfo_, clinit$RedirectFilter, allocate$RedirectFilter);
	return class$;
}

$Class* RedirectFilter::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk