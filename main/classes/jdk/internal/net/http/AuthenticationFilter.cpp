#include <jdk/internal/net/http/AuthenticationFilter.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/InternalError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/Authenticator$RequestorType.h>
#include <java/net/Authenticator.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/PasswordAuthentication.h>
#include <java/net/URI.h>
#include <java/net/URISyntaxException.h>
#include <java/net/URL.h>
#include <java/net/http/HttpHeaders.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/util/Base64$Encoder.h>
#include <java/util/Base64.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Optional.h>
#include <java/util/WeakHashMap.h>
#include <java/util/function/BiPredicate.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/AuthenticationFilter$AuthInfo.h>
#include <jdk/internal/net/http/AuthenticationFilter$Cache.h>
#include <jdk/internal/net/http/AuthenticationFilter$CacheEntry.h>
#include <jdk/internal/net/http/HeaderParser.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/Response.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef BASIC_DUMMY
#undef DEFAULT_RETRY_LIMIT
#undef PROXY
#undef PROXY_FILTER
#undef PROXY_TUNNEL_FILTER
#undef PROXY_UNAUTHORIZED
#undef SERVER
#undef UNAUTHORIZED
#undef UTF_8

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Authenticator = ::java::net::Authenticator;
using $Authenticator$RequestorType = ::java::net::Authenticator$RequestorType;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $PasswordAuthentication = ::java::net::PasswordAuthentication;
using $URI = ::java::net::URI;
using $URISyntaxException = ::java::net::URISyntaxException;
using $URL = ::java::net::URL;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $Base64 = ::java::util::Base64;
using $Base64$Encoder = ::java::util::Base64$Encoder;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Optional = ::java::util::Optional;
using $WeakHashMap = ::java::util::WeakHashMap;
using $BiPredicate = ::java::util::function::BiPredicate;
using $Supplier = ::java::util::function::Supplier;
using $AuthenticationFilter$AuthInfo = ::jdk::internal::net::http::AuthenticationFilter$AuthInfo;
using $AuthenticationFilter$Cache = ::jdk::internal::net::http::AuthenticationFilter$Cache;
using $AuthenticationFilter$CacheEntry = ::jdk::internal::net::http::AuthenticationFilter$CacheEntry;
using $HeaderFilter = ::jdk::internal::net::http::HeaderFilter;
using $HeaderParser = ::jdk::internal::net::http::HeaderParser;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;
using $Response = ::jdk::internal::net::http::Response;
using $Log = ::jdk::internal::net::http::common::Log;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class AuthenticationFilter$$Lambda$lambda$getCredentials$0 : public $Supplier {
	$class(AuthenticationFilter$$Lambda$lambda$getCredentials$0, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of(AuthenticationFilter::lambda$getCredentials$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AuthenticationFilter$$Lambda$lambda$getCredentials$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo AuthenticationFilter$$Lambda$lambda$getCredentials$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(AuthenticationFilter$$Lambda$lambda$getCredentials$0::*)()>(&AuthenticationFilter$$Lambda$lambda$getCredentials$0::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo AuthenticationFilter$$Lambda$lambda$getCredentials$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.AuthenticationFilter$$Lambda$lambda$getCredentials$0",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* AuthenticationFilter$$Lambda$lambda$getCredentials$0::load$($String* name, bool initialize) {
	$loadClass(AuthenticationFilter$$Lambda$lambda$getCredentials$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AuthenticationFilter$$Lambda$lambda$getCredentials$0::class$ = nullptr;

$FieldInfo _AuthenticationFilter_FieldInfo_[] = {
	{"exchange", "Ljdk/internal/net/http/MultiExchange;", "Ljdk/internal/net/http/MultiExchange<*>;", $VOLATILE, $field(AuthenticationFilter, exchange)},
	{"encoder", "Ljava/util/Base64$Encoder;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AuthenticationFilter, encoder)},
	{"DEFAULT_RETRY_LIMIT", "I", nullptr, $STATIC | $FINAL, $constField(AuthenticationFilter, DEFAULT_RETRY_LIMIT)},
	{"retry_limit", "I", nullptr, $STATIC | $FINAL, $staticField(AuthenticationFilter, retry_limit)},
	{"UNAUTHORIZED", "I", nullptr, $STATIC | $FINAL, $constField(AuthenticationFilter, UNAUTHORIZED)},
	{"PROXY_UNAUTHORIZED", "I", nullptr, $STATIC | $FINAL, $constField(AuthenticationFilter, PROXY_UNAUTHORIZED)},
	{"BASIC_DUMMY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(AuthenticationFilter, BASIC_DUMMY)},
	{"caches", "Ljava/util/WeakHashMap;", "Ljava/util/WeakHashMap<Ljdk/internal/net/http/HttpClientImpl;Ljdk/internal/net/http/AuthenticationFilter$Cache;>;", $STATIC | $FINAL, $staticField(AuthenticationFilter, caches)},
	{}
};

$MethodInfo _AuthenticationFilter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(AuthenticationFilter::*)()>(&AuthenticationFilter::init$))},
	{"addBasicCredentials", "(Ljdk/internal/net/http/HttpRequestImpl;ZLjava/net/PasswordAuthentication;Z)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($HttpRequestImpl*,bool,$PasswordAuthentication*,bool)>(&AuthenticationFilter::addBasicCredentials))},
	{"getCache", "(Ljdk/internal/net/http/MultiExchange;)Ljdk/internal/net/http/AuthenticationFilter$Cache;", "(Ljdk/internal/net/http/MultiExchange<*>;)Ljdk/internal/net/http/AuthenticationFilter$Cache;", $STATIC | $SYNCHRONIZED, $method(static_cast<$AuthenticationFilter$Cache*(*)($MultiExchange*)>(&AuthenticationFilter::getCache))},
	{"getCredentials", "(Ljava/lang/String;ZLjdk/internal/net/http/HttpRequestImpl;)Ljava/net/PasswordAuthentication;", nullptr, $PRIVATE, $method(static_cast<$PasswordAuthentication*(AuthenticationFilter::*)($String*,bool,$HttpRequestImpl*)>(&AuthenticationFilter::getCredentials)), "java.io.IOException"},
	{"getProxyURI", "(Ljdk/internal/net/http/HttpRequestImpl;)Ljava/net/URI;", nullptr, $PRIVATE, $method(static_cast<$URI*(AuthenticationFilter::*)($HttpRequestImpl*)>(&AuthenticationFilter::getProxyURI))},
	{"lambda$getCredentials$0", "()Ljava/io/IOException;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$IOException*(*)()>(&AuthenticationFilter::lambda$getCredentials$0))},
	{"normalize", "(Ljava/net/URI;Z)Ljava/net/URI;", nullptr, $STATIC, $method(static_cast<$URI*(*)($URI*,bool)>(&AuthenticationFilter::normalize))},
	{"request", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/MultiExchange;)V", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/MultiExchange<*>;)V", $PUBLIC, nullptr, "java.io.IOException"},
	{"response", "(Ljdk/internal/net/http/Response;)Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"toURL", "(Ljava/net/URI;Ljava/lang/String;Z)Ljava/net/URL;", nullptr, $PRIVATE, $method(static_cast<$URL*(AuthenticationFilter::*)($URI*,$String*,bool)>(&AuthenticationFilter::toURL)), "java.net.MalformedURLException"},
	{}
};

$InnerClassInfo _AuthenticationFilter_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.AuthenticationFilter$CacheEntry", "jdk.internal.net.http.AuthenticationFilter", "CacheEntry", $STATIC | $FINAL},
	{"jdk.internal.net.http.AuthenticationFilter$Cache", "jdk.internal.net.http.AuthenticationFilter", "Cache", $STATIC | $FINAL},
	{"jdk.internal.net.http.AuthenticationFilter$AuthInfo", "jdk.internal.net.http.AuthenticationFilter", "AuthInfo", $STATIC},
	{}
};

$ClassInfo _AuthenticationFilter_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.AuthenticationFilter",
	"java.lang.Object",
	"jdk.internal.net.http.HeaderFilter",
	_AuthenticationFilter_FieldInfo_,
	_AuthenticationFilter_MethodInfo_,
	nullptr,
	nullptr,
	_AuthenticationFilter_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.AuthenticationFilter$CacheEntry,jdk.internal.net.http.AuthenticationFilter$Cache,jdk.internal.net.http.AuthenticationFilter$AuthInfo"
};

$Object* allocate$AuthenticationFilter($Class* clazz) {
	return $of($alloc(AuthenticationFilter));
}

$Base64$Encoder* AuthenticationFilter::encoder = nullptr;
int32_t AuthenticationFilter::retry_limit = 0;
$String* AuthenticationFilter::BASIC_DUMMY = nullptr;
$WeakHashMap* AuthenticationFilter::caches = nullptr;

void AuthenticationFilter::init$() {
}

$PasswordAuthentication* AuthenticationFilter::getCredentials($String* header, bool proxy, $HttpRequestImpl* req) {
	$useLocalCurrentObjectStackCache();
	$var($HttpClientImpl, client, $nc(this->exchange)->client());
	$var($Authenticator, auth, $cast($Authenticator, $nc($($nc(client)->authenticator()))->orElseThrow(static_cast<$Supplier*>($$new(AuthenticationFilter$$Lambda$lambda$getCredentials$0)))));
	$var($URI, uri, $nc(req)->uri());
	$var($HeaderParser, parser, $new($HeaderParser, header));
	$var($String, authscheme, parser->findKey(0));
	$var($String, realm, parser->findValue("realm"_s));
	$init($Authenticator$RequestorType);
	$Authenticator$RequestorType* rtype = proxy ? $Authenticator$RequestorType::PROXY : $Authenticator$RequestorType::SERVER;
	$var($URL, url, toURL(uri, $(req->method()), proxy));
	$var($String, host, nullptr);
	int32_t port = 0;
	$var($String, protocol, nullptr);
	$var($InetSocketAddress, proxyAddress, nullptr);
	if (proxy && ($assign(proxyAddress, req->proxy())) != nullptr) {
		$assign(proxyAddress, req->proxy());
		$assign(host, $nc(proxyAddress)->getHostString());
		port = proxyAddress->getPort();
		$assign(protocol, "http"_s);
	} else {
		$assign(host, $nc(uri)->getHost());
		port = uri->getPort();
		$assign(protocol, uri->getScheme());
	}
	return $nc(auth)->requestPasswordAuthenticationInstance(host, nullptr, port, protocol, realm, authscheme, url, rtype);
}

$URL* AuthenticationFilter::toURL($URI* uri, $String* method, bool proxy) {
	bool var$0 = proxy && "CONNECT"_s->equalsIgnoreCase(method);
	if (var$0 && "socket"_s->equalsIgnoreCase($($nc(uri)->getScheme()))) {
		return nullptr;
	}
	return $nc(uri)->toURL();
}

$URI* AuthenticationFilter::getProxyURI($HttpRequestImpl* r) {
	$useLocalCurrentObjectStackCache();
	$var($InetSocketAddress, proxy, $nc(r)->proxy());
	if (proxy == nullptr) {
		return nullptr;
	}
	$var($String, scheme, $str({"proxy."_s, $($nc($(r->uri()))->getScheme())}));
	try {
		$var($String, var$0, scheme);
		$var($String, var$1, $nc(proxy)->getHostString());
		return $new($URI, var$0, nullptr, var$1, proxy->getPort(), "/"_s, nullptr, nullptr);
	} catch ($URISyntaxException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void AuthenticationFilter::request($HttpRequestImpl* r, $MultiExchange* e) {
	$useLocalCurrentObjectStackCache();
	$var($AuthenticationFilter$Cache, cache, getCache(e));
	$set(this, exchange, e);
	if ($nc(this->exchange)->proxyauth == nullptr) {
		$var($URI, proxyURI, getProxyURI(r));
		if (proxyURI != nullptr) {
			$var($AuthenticationFilter$CacheEntry, ca, $nc(cache)->get(proxyURI, true));
			if (ca != nullptr) {
				$set($nc(this->exchange), proxyauth, $new($AuthenticationFilter$AuthInfo, true, ca->scheme, nullptr, ca, ca->isUTF8));
				addBasicCredentials(r, true, ca->value$, ca->isUTF8);
			}
		}
	}
	if ($nc(this->exchange)->serverauth == nullptr) {
		$var($AuthenticationFilter$CacheEntry, ca, $nc(cache)->get($($nc(r)->uri()), false));
		if (ca != nullptr) {
			$set($nc(this->exchange), serverauth, $new($AuthenticationFilter$AuthInfo, true, ca->scheme, nullptr, ca, ca->isUTF8));
			addBasicCredentials(r, false, ca->value$, ca->isUTF8);
		}
	}
}

void AuthenticationFilter::addBasicCredentials($HttpRequestImpl* r, bool proxy, $PasswordAuthentication* pw, bool isUTF8) {
	$init(AuthenticationFilter);
	$useLocalCurrentObjectStackCache();
	$var($String, hdrname, proxy ? "Proxy-Authorization"_s : "Authorization"_s);
	$var($StringBuilder, sb, $new($StringBuilder, 128));
	sb->append($($nc(pw)->getUserName()))->append(u':')->append($($nc(pw)->getPassword()));
	$init($StandardCharsets);
	$var($Charset, charset, isUTF8 ? $StandardCharsets::UTF_8 : $StandardCharsets::ISO_8859_1);
	$var($String, s, $nc(AuthenticationFilter::encoder)->encodeToString($($nc($(sb->toString()))->getBytes(charset))));
	$var($String, value, $str({"Basic "_s, s}));
	if (proxy) {
		if ($nc(r)->isConnect()) {
			$init($Utils);
			if (!$nc($Utils::PROXY_TUNNEL_FILTER)->test(hdrname, value)) {
				$Log::logError("{0} disabled"_s, $$new($ObjectArray, {$of(hdrname)}));
				return;
			}
		} else if (r->proxy() != nullptr) {
			$init($Utils);
			if (!$nc($Utils::PROXY_FILTER)->test(hdrname, value)) {
				$Log::logError("{0} disabled"_s, $$new($ObjectArray, {$of(hdrname)}));
				return;
			}
		}
	}
	$nc(r)->setSystemHeader(hdrname, value);
}

$HttpRequestImpl* AuthenticationFilter::response($Response* r) {
	$useLocalCurrentObjectStackCache();
	$var($AuthenticationFilter$Cache, cache, getCache(this->exchange));
	int32_t status = $nc(r)->statusCode();
	$var($HttpHeaders, hdrs, r->headers());
	$var($HttpRequestImpl, req, r->request());
	if (status != AuthenticationFilter::PROXY_UNAUTHORIZED) {
		if ($nc(this->exchange)->proxyauth != nullptr && !$nc($nc(this->exchange)->proxyauth)->fromcache) {
			$var($AuthenticationFilter$AuthInfo, au, $nc(this->exchange)->proxyauth);
			$var($URI, proxyURI, getProxyURI(req));
			if (proxyURI != nullptr) {
				$set($nc(this->exchange), proxyauth, nullptr);
				$nc(cache)->store($nc(au)->scheme, proxyURI, true, au->credentials, au->isUTF8);
			}
		}
		if (status != AuthenticationFilter::UNAUTHORIZED) {
			if ($nc(this->exchange)->serverauth != nullptr && !$nc($nc(this->exchange)->serverauth)->fromcache) {
				$var($AuthenticationFilter$AuthInfo, au, $nc(this->exchange)->serverauth);
				$nc(cache)->store($nc(au)->scheme, $($nc(req)->uri()), false, au->credentials, au->isUTF8);
			}
			return nullptr;
		}
	}
	bool proxy = status == AuthenticationFilter::PROXY_UNAUTHORIZED;
	$var($String, authname, proxy ? "Proxy-Authenticate"_s : "WWW-Authenticate"_s);
	$var($List, authvals, $nc(hdrs)->allValues(authname));
	bool var$0 = $nc(authvals)->isEmpty();
	if (var$0 && $nc($($nc($($nc(this->exchange)->client()))->authenticator()))->isPresent()) {
		$throwNew($IOException, $$str({authname, " header missing for response code "_s, $$str(status)}));
	}
	$var($String, authval, nullptr);
	bool isUTF8 = false;
	{
		$var($Iterator, i$, $nc(authvals)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, aval, $cast($String, i$->next()));
			{
				$var($HeaderParser, parser, $new($HeaderParser, aval));
				$var($String, scheme, parser->findKey(0));
				if (scheme != nullptr && scheme->equalsIgnoreCase("Basic"_s)) {
					$assign(authval, aval);
					$var($String, charset, parser->findValue("charset"_s));
					isUTF8 = (charset != nullptr && charset->equalsIgnoreCase("UTF-8"_s));
					break;
				}
			}
		}
	}
	if (authval == nullptr) {
		return nullptr;
	}
	if (proxy) {
		if (r->isConnectResponse) {
			$init($Utils);
			if (!$nc($Utils::PROXY_TUNNEL_FILTER)->test("Proxy-Authorization"_s, AuthenticationFilter::BASIC_DUMMY)) {
				$Log::logError("{0} disabled"_s, $$new($ObjectArray, {$of("Proxy-Authorization"_s)}));
				return nullptr;
			}
		} else if ($nc(req)->proxy() != nullptr) {
			$init($Utils);
			if (!$nc($Utils::PROXY_FILTER)->test("Proxy-Authorization"_s, AuthenticationFilter::BASIC_DUMMY)) {
				$Log::logError("{0} disabled"_s, $$new($ObjectArray, {$of("Proxy-Authorization"_s)}));
				return nullptr;
			}
		}
	}
	$var($AuthenticationFilter$AuthInfo, au, proxy ? $cast($AuthenticationFilter$AuthInfo, $nc(this->exchange)->proxyauth) : $cast($AuthenticationFilter$AuthInfo, $nc(this->exchange)->serverauth));
	if (au == nullptr) {
		if (!$nc($($nc($($nc(this->exchange)->client()))->authenticator()))->isPresent()) {
			return nullptr;
		}
		$var($PasswordAuthentication, pw, getCredentials(authval, proxy, req));
		if (pw == nullptr) {
			$throwNew($IOException, "No credentials provided"_s);
		}
		$assign(au, $new($AuthenticationFilter$AuthInfo, false, "Basic"_s, pw, isUTF8));
		if (proxy) {
			$set($nc(this->exchange), proxyauth, au);
		} else {
			$set($nc(this->exchange), serverauth, au);
		}
		$assign(req, $HttpRequestImpl::newInstanceForAuthentication(req));
		addBasicCredentials(req, proxy, pw, isUTF8);
		return req;
	} else if ($nc(au)->retries > AuthenticationFilter::retry_limit) {
		$throwNew($IOException, $$str({"too many authentication attempts. Limit: "_s, $($Integer::toString(AuthenticationFilter::retry_limit))}));
	} else {
		if (au->fromcache) {
			$nc(cache)->remove(au->cacheEntry);
		}
		if (!$nc($($nc($($nc(this->exchange)->client()))->authenticator()))->isPresent()) {
			return nullptr;
		}
		$var($PasswordAuthentication, pw, getCredentials(authval, proxy, req));
		if (pw == nullptr) {
			$throwNew($IOException, "No credentials provided"_s);
		}
		$assign(au, au->retryWithCredentials(pw, isUTF8));
		if (proxy) {
			$set($nc(this->exchange), proxyauth, au);
		} else {
			$set($nc(this->exchange), serverauth, au);
		}
		$assign(req, $HttpRequestImpl::newInstanceForAuthentication(req));
		addBasicCredentials(req, proxy, $nc(au)->credentials, isUTF8);
		++$nc(au)->retries;
		return req;
	}
}

$AuthenticationFilter$Cache* AuthenticationFilter::getCache($MultiExchange* exchange) {
	$load(AuthenticationFilter);
	$synchronized(class$) {
		$init(AuthenticationFilter);
		$useLocalCurrentObjectStackCache();
		$var($HttpClientImpl, client, $nc(exchange)->client());
		$var($AuthenticationFilter$Cache, c, $cast($AuthenticationFilter$Cache, $nc(AuthenticationFilter::caches)->get(client)));
		if (c == nullptr) {
			$assign(c, $new($AuthenticationFilter$Cache));
			$nc(AuthenticationFilter::caches)->put(client, c);
		}
		return c;
	}
}

$URI* AuthenticationFilter::normalize($URI* uri, bool isPrimaryKey) {
	$init(AuthenticationFilter);
	$useLocalCurrentObjectStackCache();
	$var($String, path, $nc(uri)->getPath());
	if (path == nullptr || $nc(path)->isEmpty()) {
		try {
			$var($String, var$0, uri->getScheme());
			return $new($URI, var$0, $(uri->getAuthority()), "/"_s, nullptr, nullptr);
		} catch ($URISyntaxException& e) {
			$throwNew($InternalError, static_cast<$Throwable*>(e));
		}
	} else if (isPrimaryKey || !"/"_s->equals(path)) {
		return uri->resolve("."_s);
	} else {
		return uri;
	}
}

$IOException* AuthenticationFilter::lambda$getCredentials$0() {
	$init(AuthenticationFilter);
	return $new($IOException, "No authenticator set"_s);
}

void clinit$AuthenticationFilter($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(AuthenticationFilter::encoder, $Base64::getEncoder());
	AuthenticationFilter::retry_limit = $Utils::getIntegerNetProperty("jdk.httpclient.auth.retrylimit"_s, AuthenticationFilter::DEFAULT_RETRY_LIMIT);
	$init($StandardCharsets);
	$assignStatic(AuthenticationFilter::BASIC_DUMMY, $str({"Basic "_s, $($nc($($Base64::getEncoder()))->encodeToString($("o:o"_s->getBytes($StandardCharsets::ISO_8859_1))))}));
	$assignStatic(AuthenticationFilter::caches, $new($WeakHashMap));
}

AuthenticationFilter::AuthenticationFilter() {
}

$Class* AuthenticationFilter::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(AuthenticationFilter$$Lambda$lambda$getCredentials$0::classInfo$.name)) {
			return AuthenticationFilter$$Lambda$lambda$getCredentials$0::load$(name, initialize);
		}
	}
	$loadClass(AuthenticationFilter, name, initialize, &_AuthenticationFilter_ClassInfo_, clinit$AuthenticationFilter, allocate$AuthenticationFilter);
	return class$;
}

$Class* AuthenticationFilter::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk