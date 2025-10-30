#include <jdk/internal/net/http/Http1Request.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/URI.h>
#include <java/net/http/HttpClient.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpRequest$BodyPublisher.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/function/BiPredicate.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/Http1Exchange$Http1BodySubscriber.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jdk/internal/net/http/Http1Request$FixedContentSubscriber.h>
#include <jdk/internal/net/http/Http1Request$StreamSubscriber.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/common/HttpHeadersBuilder.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef COOKIE_HEADER
#undef CRLF
#undef DEBUG
#undef EMPTY_CHUNK_BYTES
#undef NOCOOKIES
#undef US_ASCII

using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $URI = ::java::net::URI;
using $HttpClient = ::java::net::http::HttpClient;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $Flow$Publisher = ::java::util::concurrent::Flow$Publisher;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $BiPredicate = ::java::util::function::BiPredicate;
using $Supplier = ::java::util::function::Supplier;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;
using $Http1Exchange$Http1BodySubscriber = ::jdk::internal::net::http::Http1Exchange$Http1BodySubscriber;
using $Http1Request$FixedContentSubscriber = ::jdk::internal::net::http::Http1Request$FixedContentSubscriber;
using $Http1Request$StreamSubscriber = ::jdk::internal::net::http::Http1Request$StreamSubscriber;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $HttpHeadersBuilder = ::jdk::internal::net::http::common::HttpHeadersBuilder;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Http1Request$$Lambda$lambda$static$0 : public $BiPredicate {
	$class(Http1Request$$Lambda$lambda$static$0, $NO_CLASS_INIT, $BiPredicate)
public:
	void init$() {
	}
	virtual bool test(Object$* k, Object$* v) override {
		 return Http1Request::lambda$static$0($cast($String, k), $cast($String, v));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Request$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Http1Request$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Http1Request$$Lambda$lambda$static$0::*)()>(&Http1Request$$Lambda$lambda$static$0::init$))},
	{"test", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Request$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Request$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.util.function.BiPredicate",
	nullptr,
	methodInfos
};
$Class* Http1Request$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(Http1Request$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Request$$Lambda$lambda$static$0::class$ = nullptr;

class Http1Request$$Lambda$toString$1 : public $Supplier {
	$class(Http1Request$$Lambda$toString$1, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Object$* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Request$$Lambda$toString$1>());
	}
	$Object* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Request$$Lambda$toString$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Request$$Lambda$toString$1, inst$)},
	{}
};
$MethodInfo Http1Request$$Lambda$toString$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Request$$Lambda$toString$1::*)(Object$*)>(&Http1Request$$Lambda$toString$1::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Request$$Lambda$toString$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Request$$Lambda$toString$1",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http1Request$$Lambda$toString$1::load$($String* name, bool initialize) {
	$loadClass(Http1Request$$Lambda$toString$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Request$$Lambda$toString$1::class$ = nullptr;

class Http1Request$$Lambda$lambda$collectHeaders0$1$2 : public $BiPredicate {
	$class(Http1Request$$Lambda$lambda$collectHeaders0$1$2, $NO_CLASS_INIT, $BiPredicate)
public:
	void init$($HttpHeaders* uh) {
		$set(this, uh, uh);
	}
	virtual bool test(Object$* k, Object$* v) override {
		 return Http1Request::lambda$collectHeaders0$1(uh, $cast($String, k), $cast($String, v));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Request$$Lambda$lambda$collectHeaders0$1$2>());
	}
	$HttpHeaders* uh = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Request$$Lambda$lambda$collectHeaders0$1$2::fieldInfos[2] = {
	{"uh", "Ljava/net/http/HttpHeaders;", nullptr, $PUBLIC, $field(Http1Request$$Lambda$lambda$collectHeaders0$1$2, uh)},
	{}
};
$MethodInfo Http1Request$$Lambda$lambda$collectHeaders0$1$2::methodInfos[3] = {
	{"<init>", "(Ljava/net/http/HttpHeaders;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Request$$Lambda$lambda$collectHeaders0$1$2::*)($HttpHeaders*)>(&Http1Request$$Lambda$lambda$collectHeaders0$1$2::init$))},
	{"test", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Request$$Lambda$lambda$collectHeaders0$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Request$$Lambda$lambda$collectHeaders0$1$2",
	"java.lang.Object",
	"java.util.function.BiPredicate",
	fieldInfos,
	methodInfos
};
$Class* Http1Request$$Lambda$lambda$collectHeaders0$1$2::load$($String* name, bool initialize) {
	$loadClass(Http1Request$$Lambda$lambda$collectHeaders0$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Request$$Lambda$lambda$collectHeaders0$1$2::class$ = nullptr;

$FieldInfo _Http1Request_FieldInfo_[] = {
	{"COOKIE_HEADER", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Http1Request, COOKIE_HEADER)},
	{"NOCOOKIES", "Ljava/util/function/BiPredicate;", "Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Http1Request, NOCOOKIES)},
	{"request", "Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PRIVATE | $FINAL, $field(Http1Request, request)},
	{"http1Exchange", "Ljdk/internal/net/http/Http1Exchange;", "Ljdk/internal/net/http/Http1Exchange<*>;", $PRIVATE | $FINAL, $field(Http1Request, http1Exchange)},
	{"connection", "Ljdk/internal/net/http/HttpConnection;", nullptr, $PRIVATE | $FINAL, $field(Http1Request, connection)},
	{"requestPublisher", "Ljava/net/http/HttpRequest$BodyPublisher;", nullptr, $PRIVATE | $FINAL, $field(Http1Request, requestPublisher)},
	{"userHeaders", "Ljava/net/http/HttpHeaders;", nullptr, $PRIVATE | $VOLATILE, $field(Http1Request, userHeaders)},
	{"systemHeadersBuilder", "Ljdk/internal/net/http/common/HttpHeadersBuilder;", nullptr, $PRIVATE | $FINAL, $field(Http1Request, systemHeadersBuilder)},
	{"streaming", "Z", nullptr, $PRIVATE | $VOLATILE, $field(Http1Request, streaming)},
	{"contentLength", "J", nullptr, $PRIVATE | $VOLATILE, $field(Http1Request, contentLength)},
	{"finished", "Z", nullptr, $PRIVATE, $field(Http1Request, finished$)},
	{"CRLF", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Http1Request, CRLF)},
	{"EMPTY_CHUNK_BYTES", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Http1Request, EMPTY_CHUNK_BYTES)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(Http1Request, debug)},
	{}
};

$MethodInfo _Http1Request_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/Http1Exchange;)V", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/Http1Exchange<*>;)V", 0, $method(static_cast<void(Http1Request::*)($HttpRequestImpl*,$Http1Exchange*)>(&Http1Request::init$)), "java.io.IOException"},
	{"authorityString", "(Ljava/net/InetSocketAddress;)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(Http1Request::*)($InetSocketAddress*)>(&Http1Request::authorityString))},
	{"collectCookies", "(Ljava/lang/StringBuilder;Ljava/net/http/HttpHeaders;Ljava/net/http/HttpHeaders;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1Request::*)($StringBuilder*,$HttpHeaders*,$HttpHeaders*)>(&Http1Request::collectCookies))},
	{"collectHeaders0", "(Ljava/lang/StringBuilder;)V", nullptr, $PUBLIC},
	{"collectHeaders1", "(Ljava/lang/StringBuilder;Ljava/net/http/HttpHeaders;Ljava/util/function/BiPredicate;)V", "(Ljava/lang/StringBuilder;Ljava/net/http/HttpHeaders;Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;)V", $PRIVATE, $method(static_cast<void(Http1Request::*)($StringBuilder*,$HttpHeaders*,$BiPredicate*)>(&Http1Request::collectHeaders1))},
	{"continueRequest", "()Ljdk/internal/net/http/Http1Exchange$Http1BodySubscriber;", nullptr, 0},
	{"finished", "()Z", nullptr, $SYNCHRONIZED},
	{"getHeader", "(I)Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$ByteBuffer*(*)(int32_t)>(&Http1Request::getHeader))},
	{"getPathAndQuery", "(Ljava/net/URI;)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(Http1Request::*)($URI*)>(&Http1Request::getPathAndQuery))},
	{"headers", "()Ljava/util/List;", "()Ljava/util/List<Ljava/nio/ByteBuffer;>;", 0},
	{"hostString", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(Http1Request::*)()>(&Http1Request::hostString))},
	{"lambda$collectHeaders0$1", "(Ljava/net/http/HttpHeaders;Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($HttpHeaders*,$String*,$String*)>(&Http1Request::lambda$collectHeaders0$1))},
	{"lambda$static$0", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($String*,$String*)>(&Http1Request::lambda$static$0))},
	{"logHeaders", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1Request::*)($String*)>(&Http1Request::logHeaders))},
	{"requestURI", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(Http1Request::*)()>(&Http1Request::requestURI))},
	{"setFinished", "()V", nullptr, $SYNCHRONIZED},
	{}
};

$InnerClassInfo _Http1Request_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Request$FixedContentSubscriber", "jdk.internal.net.http.Http1Request", "FixedContentSubscriber", $FINAL},
	{"jdk.internal.net.http.Http1Request$StreamSubscriber", "jdk.internal.net.http.Http1Request", "StreamSubscriber", $FINAL},
	{}
};

$ClassInfo _Http1Request_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.Http1Request",
	"java.lang.Object",
	nullptr,
	_Http1Request_FieldInfo_,
	_Http1Request_MethodInfo_,
	nullptr,
	nullptr,
	_Http1Request_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Request$FixedContentSubscriber,jdk.internal.net.http.Http1Request$StreamSubscriber"
};

$Object* allocate$Http1Request($Class* clazz) {
	return $of($alloc(Http1Request));
}

$String* Http1Request::COOKIE_HEADER = nullptr;
$BiPredicate* Http1Request::NOCOOKIES = nullptr;
$bytes* Http1Request::CRLF = nullptr;
$bytes* Http1Request::EMPTY_CHUNK_BYTES = nullptr;

void Http1Request::init$($HttpRequestImpl* request, $Http1Exchange* http1Exchange) {
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(Http1Request$$Lambda$toString$1, this)), $Utils::DEBUG));
	$set(this, request, request);
	$set(this, http1Exchange, http1Exchange);
	$set(this, connection, $nc(http1Exchange)->connection());
	$set(this, requestPublisher, $nc(request)->requestPublisher);
	$set(this, userHeaders, request->getUserHeaders());
	$set(this, systemHeadersBuilder, request->getSystemHeadersBuilder());
}

void Http1Request::logHeaders($String* completeHeaders) {
	$useLocalCurrentObjectStackCache();
	if ($Log::headers()) {
		$var($String, s, $nc(completeHeaders)->replaceAll("\r\n"_s, "\n"_s));
		if (s->endsWith("\n\n"_s)) {
			$assign(s, s->substring(0, s->length() - 2));
		}
		$Log::logHeaders("REQUEST HEADERS:\n{0}\n"_s, $$new($ObjectArray, {$of(s)}));
	}
}

void Http1Request::collectHeaders0($StringBuilder* sb) {
	$useLocalCurrentObjectStackCache();
	$var($BiPredicate, filter, $nc(this->connection)->headerFilter(this->request));
	$var($BiPredicate, nocookies, $nc(Http1Request::NOCOOKIES)->and$(filter));
	$var($HttpHeaders, systemHeaders, $nc(this->systemHeadersBuilder)->build());
	$var($HttpClient, client, $nc(this->http1Exchange)->client());
	$var($Map, var$0, $nc(this->userHeaders)->map());
	$set(this, userHeaders, $HttpHeaders::of(var$0, $($nc(this->connection)->contextRestricted(this->request, client))));
	$var($HttpHeaders, uh, this->userHeaders);
	$var($Map, var$1, $nc(systemHeaders)->map());
	$assign(systemHeaders, $HttpHeaders::of(var$1, static_cast<$BiPredicate*>($$new(Http1Request$$Lambda$lambda$collectHeaders0$1$2, uh))));
	collectHeaders1(sb, systemHeaders, nocookies);
	collectHeaders1(sb, this->userHeaders, nocookies);
	collectCookies(sb, systemHeaders, this->userHeaders);
	$nc(sb)->append(u'\r')->append(u'\n');
}

void Http1Request::collectCookies($StringBuilder* sb, $HttpHeaders* system, $HttpHeaders* user) {
	$useLocalCurrentObjectStackCache();
	$var($List, systemList, $nc(system)->allValues(Http1Request::COOKIE_HEADER));
	$var($List, userList, $nc(user)->allValues(Http1Request::COOKIE_HEADER));
	bool found = false;
	if (systemList != nullptr) {
		{
			$var($Iterator, i$, systemList->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, cookie, $cast($String, i$->next()));
				{
					if (!found) {
						found = true;
						$nc(sb)->append(Http1Request::COOKIE_HEADER)->append(u':')->append(u' ');
					} else {
						$nc(sb)->append(u';')->append(u' ');
					}
					$nc(sb)->append(cookie);
				}
			}
		}
	}
	if (userList != nullptr) {
		{
			$var($Iterator, i$, userList->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, cookie, $cast($String, i$->next()));
				{
					if (!found) {
						found = true;
						$nc(sb)->append(Http1Request::COOKIE_HEADER)->append(u':')->append(u' ');
					} else {
						$nc(sb)->append(u';')->append(u' ');
					}
					$nc(sb)->append(cookie);
				}
			}
		}
	}
	if (found) {
		$nc(sb)->append(u'\r')->append(u'\n');
	}
}

void Http1Request::collectHeaders1($StringBuilder* sb, $HttpHeaders* headers, $BiPredicate* filter) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($($nc($($nc(headers)->map()))->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($String, key, $cast($String, $nc(entry)->getKey()));
				$var($List, values, $cast($List, entry->getValue()));
				{
					$var($Iterator, i$, $nc(values)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, value, $cast($String, i$->next()));
						{
							if (!$nc(filter)->test(key, value)) {
								continue;
							}
							$nc(sb)->append(key)->append(u':')->append(u' ')->append(value)->append(u'\r')->append(u'\n');
						}
					}
				}
			}
		}
	}
}

$String* Http1Request::getPathAndQuery($URI* uri) {
	$useLocalCurrentObjectStackCache();
	$var($String, path, $nc(uri)->getRawPath());
	$var($String, query, uri->getRawQuery());
	if (path == nullptr || $nc(path)->isEmpty()) {
		$assign(path, "/"_s);
	}
	if (query == nullptr) {
		$assign(query, ""_s);
	}
	if ($nc(query)->isEmpty()) {
		return $Utils::encode(path);
	} else {
		return $Utils::encode($$str({path, "?"_s, query}));
	}
}

$String* Http1Request::authorityString($InetSocketAddress* addr) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $$str({$($nc(addr)->getHostString()), ":"_s}));
	return $concat(var$0, $$str(addr->getPort()));
}

$String* Http1Request::hostString() {
	$useLocalCurrentObjectStackCache();
	$var($URI, uri, $nc(this->request)->uri());
	int32_t port = $nc(uri)->getPort();
	$var($String, host, uri->getHost());
	bool defaultPort = false;
	if (port == -1) {
		defaultPort = true;
	} else if ($nc(this->request)->secure()) {
		defaultPort = port == 443;
	} else {
		defaultPort = port == 80;
	}
	if (defaultPort) {
		return host;
	} else {
		return $str({host, ":"_s, $($Integer::toString(port))});
	}
}

$String* Http1Request::requestURI() {
	$useLocalCurrentObjectStackCache();
	$var($URI, uri, $nc(this->request)->uri());
	$var($String, method, $nc(this->request)->method());
	bool var$1 = $nc(this->request)->proxy() == nullptr;
	bool var$0 = (var$1 && !$nc(method)->equals("CONNECT"_s));
	if (var$0 || $nc(this->request)->isWebSocket()) {
		return getPathAndQuery(uri);
	}
	if ($nc(this->request)->secure()) {
		if ($nc($($nc(this->request)->method()))->equals("CONNECT"_s)) {
			return authorityString($($nc(this->request)->authority()));
		} else {
			return getPathAndQuery(uri);
		}
	}
	if ($nc($($nc(this->request)->method()))->equals("CONNECT"_s)) {
		return authorityString($($nc(this->request)->authority()));
	}
	return uri == nullptr ? authorityString($($nc(this->request)->authority())) : $nc(uri)->toString();
}

bool Http1Request::finished() {
	$synchronized(this) {
		return this->finished$;
	}
}

void Http1Request::setFinished() {
	$synchronized(this) {
		this->finished$ = true;
	}
}

$List* Http1Request::headers() {
	$useLocalCurrentObjectStackCache();
	if ($Log::requests() && this->request != nullptr) {
		$Log::logRequest($($nc(this->request)->toString()), $$new($ObjectArray, 0));
	}
	$var($String, uriString, requestURI());
	$var($StringBuilder, sb, $new($StringBuilder, 64));
	sb->append($($nc(this->request)->method()))->append(u' ')->append(uriString)->append(" HTTP/1.1\r\n"_s);
	$var($URI, uri, $nc(this->request)->uri());
	if (uri != nullptr) {
		$nc(this->systemHeadersBuilder)->setHeader("Host"_s, $(hostString()));
	}
	if (this->requestPublisher == nullptr) {
		this->contentLength = 0;
	} else {
		this->contentLength = $nc(this->requestPublisher)->contentLength();
	}
	if (this->contentLength == 0) {
		$nc(this->systemHeadersBuilder)->setHeader("Content-Length"_s, "0"_s);
	} else if (this->contentLength > 0) {
		$nc(this->systemHeadersBuilder)->setHeader("Content-Length"_s, $($Long::toString(this->contentLength)));
		this->streaming = false;
	} else {
		this->streaming = true;
		$nc(this->systemHeadersBuilder)->setHeader("Transfer-encoding"_s, "chunked"_s);
	}
	collectHeaders0(sb);
	$var($String, hs, sb->toString());
	logHeaders(hs);
	$init($StandardCharsets);
	$var($ByteBuffer, b, $ByteBuffer::wrap($($nc(hs)->getBytes($StandardCharsets::US_ASCII))));
	return $List::of($of(b));
}

$Http1Exchange$Http1BodySubscriber* Http1Request::continueRequest() {
	$var($Http1Exchange$Http1BodySubscriber, subscriber, nullptr);
	if (this->streaming) {
		$assign(subscriber, $new($Http1Request$StreamSubscriber, this));
		$nc(this->requestPublisher)->subscribe(subscriber);
	} else {
		if (this->contentLength == 0) {
			return nullptr;
		}
		$assign(subscriber, $new($Http1Request$FixedContentSubscriber, this));
		$nc(this->requestPublisher)->subscribe(subscriber);
	}
	return subscriber;
}

$ByteBuffer* Http1Request::getHeader(int32_t size) {
	$init(Http1Request);
	$useLocalCurrentObjectStackCache();
	$var($String, hexStr, $Integer::toHexString(size));
	$init($StandardCharsets);
	$var($bytes, hexBytes, $nc(hexStr)->getBytes($StandardCharsets::US_ASCII));
	$var($bytes, header, $new($bytes, hexStr->length() + 2));
	$System::arraycopy(hexBytes, 0, header, 0, hexBytes->length);
	header->set(hexBytes->length, $nc(Http1Request::CRLF)->get(0));
	header->set(hexBytes->length + 1, $nc(Http1Request::CRLF)->get(1));
	return $ByteBuffer::wrap(header);
}

bool Http1Request::lambda$collectHeaders0$1($HttpHeaders* uh, $String* k, $String* v) {
	$init(Http1Request);
	return $nc($($nc(uh)->firstValue(k)))->isEmpty();
}

bool Http1Request::lambda$static$0($String* k, $String* v) {
	$init(Http1Request);
	return !$nc(Http1Request::COOKIE_HEADER)->equalsIgnoreCase(k);
}

void clinit$Http1Request($Class* class$) {
	$assignStatic(Http1Request::COOKIE_HEADER, "Cookie"_s);
	$assignStatic(Http1Request::NOCOOKIES, static_cast<$BiPredicate*>($new(Http1Request$$Lambda$lambda$static$0)));
	$assignStatic(Http1Request::CRLF, $new($bytes, {
		(int8_t)u'\r',
		(int8_t)u'\n'
	}));
	$assignStatic(Http1Request::EMPTY_CHUNK_BYTES, $new($bytes, {
		(int8_t)u'0',
		(int8_t)u'\r',
		(int8_t)u'\n'
	}));
}

Http1Request::Http1Request() {
}

$Class* Http1Request::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Http1Request$$Lambda$lambda$static$0::classInfo$.name)) {
			return Http1Request$$Lambda$lambda$static$0::load$(name, initialize);
		}
		if (name->equals(Http1Request$$Lambda$toString$1::classInfo$.name)) {
			return Http1Request$$Lambda$toString$1::load$(name, initialize);
		}
		if (name->equals(Http1Request$$Lambda$lambda$collectHeaders0$1$2::classInfo$.name)) {
			return Http1Request$$Lambda$lambda$collectHeaders0$1$2::load$(name, initialize);
		}
	}
	$loadClass(Http1Request, name, initialize, &_Http1Request_ClassInfo_, clinit$Http1Request, allocate$Http1Request);
	return class$;
}

$Class* Http1Request::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk