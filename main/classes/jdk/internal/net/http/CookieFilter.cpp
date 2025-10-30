#include <jdk/internal/net/http/CookieFilter.h>

#include <java/net/CookieHandler.h>
#include <java/net/URI.h>
#include <java/net/http/HttpHeaders.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/Response.h>
#include <jdk/internal/net/http/common/HttpHeadersBuilder.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CookieHandler = ::java::net::CookieHandler;
using $URI = ::java::net::URI;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $HeaderFilter = ::jdk::internal::net::http::HeaderFilter;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;
using $Response = ::jdk::internal::net::http::Response;
using $HttpHeadersBuilder = ::jdk::internal::net::http::common::HttpHeadersBuilder;
using $Log = ::jdk::internal::net::http::common::Log;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$MethodInfo _CookieFilter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(CookieFilter::*)()>(&CookieFilter::init$))},
	{"request", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/MultiExchange;)V", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/MultiExchange<*>;)V", $PUBLIC, nullptr, "java.io.IOException"},
	{"response", "(Ljdk/internal/net/http/Response;)Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _CookieFilter_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.CookieFilter",
	"java.lang.Object",
	"jdk.internal.net.http.HeaderFilter",
	nullptr,
	_CookieFilter_MethodInfo_
};

$Object* allocate$CookieFilter($Class* clazz) {
	return $of($alloc(CookieFilter));
}

void CookieFilter::init$() {
}

void CookieFilter::request($HttpRequestImpl* r, $MultiExchange* e) {
	$useLocalCurrentObjectStackCache();
	$var($HttpClientImpl, client, $nc(e)->client());
	$var($Optional, cookieHandlerOpt, $nc(client)->cookieHandler());
	if ($nc(cookieHandlerOpt)->isPresent()) {
		$var($CookieHandler, cookieHandler, $cast($CookieHandler, cookieHandlerOpt->get()));
		$var($Map, userheaders, $nc($($nc(r)->getUserHeaders()))->map());
		$var($Map, cookies, $nc(cookieHandler)->get($(r->uri()), userheaders));
		$var($HttpHeadersBuilder, systemHeadersBuilder, r->getSystemHeadersBuilder());
		if ($nc(cookies)->isEmpty()) {
			$Log::logTrace("Request: no cookie to add for {0}"_s, $$new($ObjectArray, {$($of(r->uri()))}));
		} else {
			$Log::logTrace("Request: adding cookies for {0}"_s, $$new($ObjectArray, {$($of(r->uri()))}));
		}
		{
			$var($Iterator, i$, $nc($($nc(cookies)->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
				{
					$var($String, hdrname, $cast($String, $nc(entry)->getKey()));
					bool var$0 = !$nc(hdrname)->equalsIgnoreCase("Cookie"_s);
					if (var$0 && !hdrname->equalsIgnoreCase("Cookie2"_s)) {
						continue;
					}
					$var($List, values, $cast($List, entry->getValue()));
					if (values == nullptr || $nc(values)->isEmpty()) {
						continue;
					}
					{
						$var($Iterator, i$, $nc(values)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($String, val, $cast($String, i$->next()));
							{
								if ($Utils::isValidValue(val)) {
									$nc(systemHeadersBuilder)->addHeader(hdrname, val);
								}
							}
						}
					}
				}
			}
		}
	} else {
		$Log::logTrace("Request: No cookie manager found for {0}"_s, $$new($ObjectArray, {$($of($nc(r)->uri()))}));
	}
}

$HttpRequestImpl* CookieFilter::response($Response* r) {
	$useLocalCurrentObjectStackCache();
	$var($HttpHeaders, hdrs, $nc(r)->headers());
	$var($HttpRequestImpl, request, r->request());
	$var($Exchange, e, r->exchange);
	$Log::logTrace("Response: processing cookies for {0}"_s, $$new($ObjectArray, {$($of($nc(request)->uri()))}));
	$var($Optional, cookieHandlerOpt, $nc($($nc(e)->client()))->cookieHandler());
	if ($nc(cookieHandlerOpt)->isPresent()) {
		$var($CookieHandler, cookieHandler, $cast($CookieHandler, cookieHandlerOpt->get()));
		$Log::logTrace("Response: parsing cookies from {0}"_s, $$new($ObjectArray, {$($of($nc(hdrs)->map()))}));
		$var($URI, var$0, $nc(request)->uri());
		$nc(cookieHandler)->put(var$0, $($nc(hdrs)->map()));
	} else {
		$Log::logTrace("Response: No cookie manager found for {0}"_s, $$new($ObjectArray, {$($of($nc(request)->uri()))}));
	}
	return nullptr;
}

CookieFilter::CookieFilter() {
}

$Class* CookieFilter::load$($String* name, bool initialize) {
	$loadClass(CookieFilter, name, initialize, &_CookieFilter_ClassInfo_, allocate$CookieFilter);
	return class$;
}

$Class* CookieFilter::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk