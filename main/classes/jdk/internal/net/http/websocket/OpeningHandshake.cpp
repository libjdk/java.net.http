#include <jdk/internal/net/http/websocket/OpeningHandshake.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Error.h>
#include <java/lang/InternalError.h>
#include <java/lang/Iterable.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/Proxy$Type.h>
#include <java/net/Proxy.h>
#include <java/net/ProxySelector.h>
#include <java/net/SocketAddress.h>
#include <java/net/URI.h>
#include <java/net/URISyntaxException.h>
#include <java/net/URLPermission.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpClient.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpRequest$Builder.h>
#include <java/net/http/HttpRequest.h>
#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/net/http/HttpResponse$BodyHandlers.h>
#include <java/net/http/HttpResponse.h>
#include <java/net/http/WebSocketHandshakeException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/AccessController.h>
#include <java/security/GeneralSecurityException.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/SecureRandom.h>
#include <java/time/Duration.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractSet.h>
#include <java/util/Base64$Encoder.h>
#include <java/util/Base64.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashSet.h>
#include <java/util/List.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/TreeSet.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/function/Function.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/net/http/HttpRequestBuilderImpl.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/Pair.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/websocket/BuilderImpl.h>
#include <jdk/internal/net/http/websocket/CheckFailedException.h>
#include <jdk/internal/net/http/websocket/OpeningHandshake$Result.h>
#include <jdk/internal/net/http/websocket/RawChannel$Provider.h>
#include <jdk/internal/net/http/websocket/RawChannel.h>
#include <jdk/internal/net/http/websocket/TransportFactory.h>
#include <jdk/internal/net/http/websocket/TransportFactoryImpl.h>
#include <jcpp.h>

#undef CASE_INSENSITIVE_ORDER
#undef HEADER_ACCEPT
#undef HEADER_CONNECTION
#undef HEADER_EXTENSIONS
#undef HEADER_KEY
#undef HEADER_PROTOCOL
#undef HEADER_UPGRADE
#undef HEADER_VERSION
#undef HTTP
#undef HTTP_1_1
#undef ILLEGAL_HEADERS
#undef VERSION

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $Iterable = ::java::lang::Iterable;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityManager = ::java::lang::SecurityManager;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $Proxy = ::java::net::Proxy;
using $Proxy$Type = ::java::net::Proxy$Type;
using $ProxySelector = ::java::net::ProxySelector;
using $SocketAddress = ::java::net::SocketAddress;
using $URI = ::java::net::URI;
using $URISyntaxException = ::java::net::URISyntaxException;
using $URLPermission = ::java::net::URLPermission;
using $HttpClient = ::java::net::http::HttpClient;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpRequest$Builder = ::java::net::http::HttpRequest$Builder;
using $HttpResponse = ::java::net::http::HttpResponse;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $HttpResponse$BodyHandlers = ::java::net::http::HttpResponse$BodyHandlers;
using $WebSocketHandshakeException = ::java::net::http::WebSocketHandshakeException;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $AccessController = ::java::security::AccessController;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $SecureRandom = ::java::security::SecureRandom;
using $Duration = ::java::time::Duration;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractSet = ::java::util::AbstractSet;
using $Base64 = ::java::util::Base64;
using $Base64$Encoder = ::java::util::Base64$Encoder;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Comparator = ::java::util::Comparator;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $LinkedHashSet = ::java::util::LinkedHashSet;
using $List = ::java::util::List;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $TreeSet = ::java::util::TreeSet;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Function = ::java::util::function::Function;
using $Stream = ::java::util::stream::Stream;
using $HttpRequestBuilderImpl = ::jdk::internal::net::http::HttpRequestBuilderImpl;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $Pair = ::jdk::internal::net::http::common::Pair;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $BuilderImpl = ::jdk::internal::net::http::websocket::BuilderImpl;
using $CheckFailedException = ::jdk::internal::net::http::websocket::CheckFailedException;
using $OpeningHandshake$Result = ::jdk::internal::net::http::websocket::OpeningHandshake$Result;
using $RawChannel = ::jdk::internal::net::http::websocket::RawChannel;
using $RawChannel$Provider = ::jdk::internal::net::http::websocket::RawChannel$Provider;
using $TransportFactory = ::jdk::internal::net::http::websocket::TransportFactory;
using $TransportFactoryImpl = ::jdk::internal::net::http::websocket::TransportFactoryImpl;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class OpeningHandshake$$Lambda$lambda$send$0 : public $PrivilegedAction {
	$class(OpeningHandshake$$Lambda$lambda$send$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(OpeningHandshake* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$send$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<OpeningHandshake$$Lambda$lambda$send$0>());
	}
	OpeningHandshake* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo OpeningHandshake$$Lambda$lambda$send$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(OpeningHandshake$$Lambda$lambda$send$0, inst$)},
	{}
};
$MethodInfo OpeningHandshake$$Lambda$lambda$send$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/websocket/OpeningHandshake;)V", nullptr, $PUBLIC, $method(static_cast<void(OpeningHandshake$$Lambda$lambda$send$0::*)(OpeningHandshake*)>(&OpeningHandshake$$Lambda$lambda$send$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo OpeningHandshake$$Lambda$lambda$send$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.websocket.OpeningHandshake$$Lambda$lambda$send$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* OpeningHandshake$$Lambda$lambda$send$0::load$($String* name, bool initialize) {
	$loadClass(OpeningHandshake$$Lambda$lambda$send$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* OpeningHandshake$$Lambda$lambda$send$0::class$ = nullptr;

class OpeningHandshake$$Lambda$lambda$checkPermissions$1$1 : public $Function {
	$class(OpeningHandshake$$Lambda$lambda$checkPermissions$1$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* p) override {
		 return $of(OpeningHandshake::lambda$checkPermissions$1($cast($Pair, p)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<OpeningHandshake$$Lambda$lambda$checkPermissions$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo OpeningHandshake$$Lambda$lambda$checkPermissions$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(OpeningHandshake$$Lambda$lambda$checkPermissions$1$1::*)()>(&OpeningHandshake$$Lambda$lambda$checkPermissions$1$1::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo OpeningHandshake$$Lambda$lambda$checkPermissions$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.websocket.OpeningHandshake$$Lambda$lambda$checkPermissions$1$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* OpeningHandshake$$Lambda$lambda$checkPermissions$1$1::load$($String* name, bool initialize) {
	$loadClass(OpeningHandshake$$Lambda$lambda$checkPermissions$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* OpeningHandshake$$Lambda$lambda$checkPermissions$1$1::class$ = nullptr;

class OpeningHandshake$$Lambda$resultFrom$2 : public $Function {
	$class(OpeningHandshake$$Lambda$resultFrom$2, $NO_CLASS_INIT, $Function)
public:
	void init$(OpeningHandshake* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* response) override {
		 return $of($nc(inst$)->resultFrom($cast($HttpResponse, response)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<OpeningHandshake$$Lambda$resultFrom$2>());
	}
	OpeningHandshake* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo OpeningHandshake$$Lambda$resultFrom$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(OpeningHandshake$$Lambda$resultFrom$2, inst$)},
	{}
};
$MethodInfo OpeningHandshake$$Lambda$resultFrom$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/websocket/OpeningHandshake;)V", nullptr, $PUBLIC, $method(static_cast<void(OpeningHandshake$$Lambda$resultFrom$2::*)(OpeningHandshake*)>(&OpeningHandshake$$Lambda$resultFrom$2::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo OpeningHandshake$$Lambda$resultFrom$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.websocket.OpeningHandshake$$Lambda$resultFrom$2",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* OpeningHandshake$$Lambda$resultFrom$2::load$($String* name, bool initialize) {
	$loadClass(OpeningHandshake$$Lambda$resultFrom$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* OpeningHandshake$$Lambda$resultFrom$2::class$ = nullptr;

$FieldInfo _OpeningHandshake_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(OpeningHandshake, $assertionsDisabled)},
	{"HEADER_CONNECTION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OpeningHandshake, HEADER_CONNECTION)},
	{"HEADER_UPGRADE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OpeningHandshake, HEADER_UPGRADE)},
	{"HEADER_ACCEPT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OpeningHandshake, HEADER_ACCEPT)},
	{"HEADER_EXTENSIONS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OpeningHandshake, HEADER_EXTENSIONS)},
	{"HEADER_KEY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OpeningHandshake, HEADER_KEY)},
	{"HEADER_PROTOCOL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OpeningHandshake, HEADER_PROTOCOL)},
	{"HEADER_VERSION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OpeningHandshake, HEADER_VERSION)},
	{"VERSION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OpeningHandshake, VERSION)},
	{"ILLEGAL_HEADERS", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(OpeningHandshake, ILLEGAL_HEADERS)},
	{"random", "Ljava/security/SecureRandom;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(OpeningHandshake, random)},
	{"sha1", "Ljava/security/MessageDigest;", nullptr, $PRIVATE | $FINAL, $field(OpeningHandshake, sha1)},
	{"client", "Ljava/net/http/HttpClient;", nullptr, $PRIVATE | $FINAL, $field(OpeningHandshake, client)},
	{"request", "Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PRIVATE | $FINAL, $field(OpeningHandshake, request)},
	{"subprotocols", "Ljava/util/Collection;", "Ljava/util/Collection<Ljava/lang/String;>;", $PRIVATE | $FINAL, $field(OpeningHandshake, subprotocols)},
	{"nonce", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(OpeningHandshake, nonce)},
	{}
};

$MethodInfo _OpeningHandshake_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/websocket/BuilderImpl;)V", nullptr, $PUBLIC, $method(static_cast<void(OpeningHandshake::*)($BuilderImpl*)>(&OpeningHandshake::init$))},
	{"checkAndReturnSubprotocol", "(Ljava/net/http/HttpHeaders;)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(OpeningHandshake::*)($HttpHeaders*)>(&OpeningHandshake::checkAndReturnSubprotocol)), "jdk.internal.net.http.websocket.CheckFailedException"},
	{"checkFailed", "(Ljava/lang/String;)Ljdk/internal/net/http/websocket/CheckFailedException;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$CheckFailedException*(*)($String*)>(&OpeningHandshake::checkFailed))},
	{"checkPermissions", "(Ljdk/internal/net/http/websocket/BuilderImpl;Ljava/net/Proxy;)V", nullptr, $STATIC, $method(static_cast<void(*)($BuilderImpl*,$Proxy*)>(&OpeningHandshake::checkPermissions))},
	{"checkURI", "(Ljava/net/URI;)Ljava/net/URI;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$URI*(*)($URI*)>(&OpeningHandshake::checkURI))},
	{"createNonce", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)()>(&OpeningHandshake::createNonce))},
	{"createRequestSubprotocols", "(Ljava/util/Collection;)Ljava/util/Collection;", "(Ljava/util/Collection<Ljava/lang/String;>;)Ljava/util/Collection<Ljava/lang/String;>;", $PRIVATE | $STATIC, $method(static_cast<$Collection*(*)($Collection*)>(&OpeningHandshake::createRequestSubprotocols))},
	{"createRequestURI", "(Ljava/net/URI;)Ljava/net/URI;", nullptr, $STATIC, $method(static_cast<$URI*(*)($URI*)>(&OpeningHandshake::createRequestURI))},
	{"handleResponse", "(Ljava/net/http/HttpResponse;)Ljdk/internal/net/http/websocket/OpeningHandshake$Result;", "(Ljava/net/http/HttpResponse<*>;)Ljdk/internal/net/http/websocket/OpeningHandshake$Result;", $PRIVATE, $method(static_cast<$OpeningHandshake$Result*(OpeningHandshake::*)($HttpResponse*)>(&OpeningHandshake::handleResponse)), "java.io.IOException"},
	{"illegal", "(Ljava/lang/String;)Ljava/lang/IllegalArgumentException;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$IllegalArgumentException*(*)($String*)>(&OpeningHandshake::illegal))},
	{"lambda$checkPermissions$1", "(Ljdk/internal/net/http/common/Pair;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($Pair*)>(&OpeningHandshake::lambda$checkPermissions$1))},
	{"lambda$send$0", "()Ljava/util/concurrent/CompletableFuture;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletableFuture*(OpeningHandshake::*)()>(&OpeningHandshake::lambda$send$0))},
	{"proxyFor", "(Ljava/util/Optional;Ljava/net/URI;)Ljava/net/Proxy;", "(Ljava/util/Optional<Ljava/net/ProxySelector;>;Ljava/net/URI;)Ljava/net/Proxy;", $PRIVATE | $STATIC, $method(static_cast<$Proxy*(*)($Optional*,$URI*)>(&OpeningHandshake::proxyFor))},
	{"requireAbsent", "(Ljava/net/http/HttpHeaders;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($HttpHeaders*,$String*)>(&OpeningHandshake::requireAbsent))},
	{"requireAtMostOne", "(Ljava/net/http/HttpHeaders;Ljava/lang/String;)Ljava/util/Optional;", "(Ljava/net/http/HttpHeaders;Ljava/lang/String;)Ljava/util/Optional<Ljava/lang/String;>;", $PRIVATE | $STATIC, $method(static_cast<$Optional*(*)($HttpHeaders*,$String*)>(&OpeningHandshake::requireAtMostOne))},
	{"requireSingle", "(Ljava/net/http/HttpHeaders;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($HttpHeaders*,$String*)>(&OpeningHandshake::requireSingle))},
	{"resultFrom", "(Ljava/net/http/HttpResponse;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/net/http/HttpResponse<*>;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/websocket/OpeningHandshake$Result;>;", $PRIVATE, $method(static_cast<$CompletableFuture*(OpeningHandshake::*)($HttpResponse*)>(&OpeningHandshake::resultFrom))},
	{"send", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/websocket/OpeningHandshake$Result;>;", $PUBLIC},
	{}
};

$InnerClassInfo _OpeningHandshake_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.OpeningHandshake$Result", "jdk.internal.net.http.websocket.OpeningHandshake", "Result", $STATIC | $FINAL},
	{}
};

$ClassInfo _OpeningHandshake_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.websocket.OpeningHandshake",
	"java.lang.Object",
	nullptr,
	_OpeningHandshake_FieldInfo_,
	_OpeningHandshake_MethodInfo_,
	nullptr,
	nullptr,
	_OpeningHandshake_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.OpeningHandshake$Result"
};

$Object* allocate$OpeningHandshake($Class* clazz) {
	return $of($alloc(OpeningHandshake));
}

bool OpeningHandshake::$assertionsDisabled = false;
$String* OpeningHandshake::HEADER_CONNECTION = nullptr;
$String* OpeningHandshake::HEADER_UPGRADE = nullptr;
$String* OpeningHandshake::HEADER_ACCEPT = nullptr;
$String* OpeningHandshake::HEADER_EXTENSIONS = nullptr;
$String* OpeningHandshake::HEADER_KEY = nullptr;
$String* OpeningHandshake::HEADER_PROTOCOL = nullptr;
$String* OpeningHandshake::HEADER_VERSION = nullptr;
$String* OpeningHandshake::VERSION = nullptr;
$Set* OpeningHandshake::ILLEGAL_HEADERS = nullptr;
$SecureRandom* OpeningHandshake::random = nullptr;

void OpeningHandshake::init$($BuilderImpl* b) {
	$useLocalCurrentObjectStackCache();
	{
		try {
			$set(this, sha1, $MessageDigest::getInstance("SHA-1"_s));
		} catch ($NoSuchAlgorithmException& e) {
			$throwNew($InternalError, "Minimum requirements"_s, e);
		}
	}
	checkURI($($nc(b)->getUri()));
	$var($Optional, var$0, $nc(b)->getProxySelector());
	$var($Proxy, proxy, proxyFor(var$0, $(b->getUri())));
	checkPermissions(b, proxy);
	$set(this, client, $nc(b)->getClient());
	$var($URI, httpURI, createRequestURI($(b->getUri())));
	$var($HttpRequestBuilderImpl, requestBuilder, $new($HttpRequestBuilderImpl, httpURI));
	$var($Duration, connectTimeout, b->getConnectTimeout());
	if (connectTimeout != nullptr) {
		requestBuilder->timeout(connectTimeout);
	}
	{
		$var($Iterator, i$, $nc($(b->getHeaders()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Pair, p, $cast($Pair, i$->next()));
			{
				if ($nc(OpeningHandshake::ILLEGAL_HEADERS)->contains($nc(p)->first)) {
					$throw($(illegal($$str({"Illegal header: "_s, $cast($String, $nc(p)->first)}))));
				}
				requestBuilder->header($cast($String, $nc(p)->first), $cast($String, p->second));
			}
		}
	}
	$set(this, subprotocols, createRequestSubprotocols($(b->getSubprotocols())));
	if (!$nc(this->subprotocols)->isEmpty()) {
		$var($String, p, $String::join(static_cast<$CharSequence*>(", "_s), static_cast<$Iterable*>(this->subprotocols)));
		requestBuilder->header(OpeningHandshake::HEADER_PROTOCOL, p);
	}
	requestBuilder->header(OpeningHandshake::HEADER_VERSION, OpeningHandshake::VERSION);
	$set(this, nonce, createNonce());
	requestBuilder->header(OpeningHandshake::HEADER_KEY, this->nonce);
	$init($HttpClient$Version);
	$nc($(requestBuilder->version($HttpClient$Version::HTTP_1_1)))->GET();
	$set(this, request, requestBuilder->buildForWebSocket());
	$nc(this->request)->isWebSocket(true);
	$Utils::setWebSocketUpgradeHeaders(this->request);
	$nc(this->request)->setProxy(proxy);
}

$Collection* OpeningHandshake::createRequestSubprotocols($Collection* subprotocols) {
	$init(OpeningHandshake);
	$useLocalCurrentObjectStackCache();
	$var($LinkedHashSet, sp, $new($LinkedHashSet, $nc(subprotocols)->size(), (float)1));
	{
		$var($Iterator, i$, $nc(subprotocols)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, s, $cast($String, i$->next()));
			{
				bool var$0 = $($nc(s)->trim())->isEmpty();
				if (var$0 || !$Utils::isValidName(s)) {
					$throw($(illegal($$str({"Bad subprotocol syntax: "_s, s}))));
				}
				if (!sp->add(s)) {
					$throw($(illegal($$str({"Duplicating subprotocol: "_s, s}))));
				}
			}
		}
	}
	return $Collections::unmodifiableCollection(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractSet*>(static_cast<$HashSet*>(sp)))));
}

$URI* OpeningHandshake::createRequestURI($URI* uri) {
	$init(OpeningHandshake);
	$useLocalCurrentObjectStackCache();
	$var($String, s, $nc(uri)->getScheme());
	bool var$0 = !OpeningHandshake::$assertionsDisabled;
	if (var$0) {
		bool var$1 = "ws"_s->equalsIgnoreCase(s);
		var$0 = !(var$1 || "wss"_s->equalsIgnoreCase(s));
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	$var($String, newUri, uri->toString());
	if ($nc(s)->equalsIgnoreCase("ws"_s)) {
		$assign(newUri, $str({"http"_s, $($nc(newUri)->substring(2))}));
	} else {
		$assign(newUri, $str({"https"_s, $($nc(newUri)->substring(3))}));
	}
	try {
		return $new($URI, newUri);
	} catch ($URISyntaxException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$CompletableFuture* OpeningHandshake::send() {
	$beforeCallerSensitive();
	$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(OpeningHandshake$$Lambda$lambda$send$0, this)));
	return $cast($CompletableFuture, $AccessController::doPrivileged(pa));
}

$CompletableFuture* OpeningHandshake::resultFrom($HttpResponse* response) {
	$useLocalCurrentObjectStackCache();
	$var($OpeningHandshake$Result, result, nullptr);
	$var($Throwable, exception, nullptr);
	try {
		$assign(result, handleResponse(response));
	} catch ($IOException& e) {
		$assign(exception, e);
	} catch ($Exception& e) {
		$assign(exception, $$new($WebSocketHandshakeException, response)->initCause(e));
	} catch ($Error& e) {
		$assign(exception, e);
	}
	if (exception == nullptr) {
		return $MinimalFuture::completedFuture(result);
	}
	try {
		$nc(($cast($RawChannel$Provider, response)))->closeRawChannel();
	} catch ($IOException& e) {
		$nc(exception)->addSuppressed(e);
	}
	return $MinimalFuture::failedFuture(exception);
}

$OpeningHandshake$Result* OpeningHandshake::handleResponse($HttpResponse* response) {
	$useLocalCurrentObjectStackCache();
	int32_t c = $nc(response)->statusCode();
	if (c != 101) {
		$throw($(checkFailed($$str({"Unexpected HTTP response status code "_s, $$str(c)}))));
	}
	$var($HttpHeaders, headers, response->headers());
	$var($String, upgrade, requireSingle(headers, OpeningHandshake::HEADER_UPGRADE));
	if (!$nc(upgrade)->equalsIgnoreCase("websocket"_s)) {
		$throw($(checkFailed($$str({"Bad response field: "_s, OpeningHandshake::HEADER_UPGRADE}))));
	}
	$var($String, connection, requireSingle(headers, OpeningHandshake::HEADER_CONNECTION));
	if (!$nc(connection)->equalsIgnoreCase("Upgrade"_s)) {
		$throw($(checkFailed($$str({"Bad response field: "_s, OpeningHandshake::HEADER_CONNECTION}))));
	}
	$var($Optional, version, requireAtMostOne(headers, OpeningHandshake::HEADER_VERSION));
	bool var$0 = $nc(version)->isPresent();
	if (var$0 && !$nc(($cast($String, $(version->get()))))->equals(OpeningHandshake::VERSION)) {
		$throw($(checkFailed($$str({"Bad response field: "_s, OpeningHandshake::HEADER_VERSION}))));
	}
	requireAbsent(headers, OpeningHandshake::HEADER_EXTENSIONS);
	$var($String, x, $str({this->nonce, "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"_s}));
	$init($StandardCharsets);
	$nc(this->sha1)->update($($nc(x)->getBytes($StandardCharsets::ISO_8859_1)));
	$var($String, expected, $nc($($Base64::getEncoder()))->encodeToString($($nc(this->sha1)->digest())));
	$var($String, actual, requireSingle(headers, OpeningHandshake::HEADER_ACCEPT));
	if (!$($nc(actual)->trim())->equals(expected)) {
		$throw($(checkFailed($$str({"Bad "_s, OpeningHandshake::HEADER_ACCEPT}))));
	}
	$var($String, subprotocol, checkAndReturnSubprotocol(headers));
	$var($RawChannel, channel, $nc(($cast($RawChannel$Provider, response)))->rawChannel());
	return $new($OpeningHandshake$Result, subprotocol, $$new($TransportFactoryImpl, channel));
}

$String* OpeningHandshake::checkAndReturnSubprotocol($HttpHeaders* responseHeaders) {
	$useLocalCurrentObjectStackCache();
	$var($Optional, opt, $nc(responseHeaders)->firstValue(OpeningHandshake::HEADER_PROTOCOL));
	if (!$nc(opt)->isPresent()) {
		return ""_s;
	}
	$var($String, s, requireSingle(responseHeaders, OpeningHandshake::HEADER_PROTOCOL));
	if ($nc(this->subprotocols)->contains(s)) {
		return s;
	} else {
		$throw($(checkFailed($$str({"Unexpected subprotocol: "_s, s}))));
	}
}

void OpeningHandshake::requireAbsent($HttpHeaders* responseHeaders, $String* headerName) {
	$init(OpeningHandshake);
	$useLocalCurrentObjectStackCache();
	$var($List, values, $nc(responseHeaders)->allValues(headerName));
	if (!$nc(values)->isEmpty()) {
		$throw($(checkFailed($($String::format("Response field \'%s\' present: %s"_s, $$new($ObjectArray, {
			$of(headerName),
			$($of($Utils::stringOf(values)))
		}))))));
	}
}

$Optional* OpeningHandshake::requireAtMostOne($HttpHeaders* responseHeaders, $String* headerName) {
	$init(OpeningHandshake);
	$useLocalCurrentObjectStackCache();
	$var($List, values, $nc(responseHeaders)->allValues(headerName));
	if ($nc(values)->size() > 1) {
		$throw($(checkFailed($($String::format("Response field \'%s\' multivalued: %s"_s, $$new($ObjectArray, {
			$of(headerName),
			$($of($Utils::stringOf(values)))
		}))))));
	}
	return $nc($($nc(values)->stream()))->findFirst();
}

$String* OpeningHandshake::requireSingle($HttpHeaders* responseHeaders, $String* headerName) {
	$init(OpeningHandshake);
	$useLocalCurrentObjectStackCache();
	$var($List, values, $nc(responseHeaders)->allValues(headerName));
	if ($nc(values)->isEmpty()) {
		$throw($(checkFailed($$str({"Response field missing: "_s, headerName}))));
	} else if (values->size() > 1) {
		$throw($(checkFailed($($String::format("Response field \'%s\' multivalued: %s"_s, $$new($ObjectArray, {
			$of(headerName),
			$($of($Utils::stringOf(values)))
		}))))));
	}
	return $cast($String, $nc(values)->get(0));
}

$String* OpeningHandshake::createNonce() {
	$init(OpeningHandshake);
	$useLocalCurrentObjectStackCache();
	$var($bytes, bytes, $new($bytes, 16));
	$nc(OpeningHandshake::random)->nextBytes(bytes);
	return $nc($($Base64::getEncoder()))->encodeToString(bytes);
}

$CheckFailedException* OpeningHandshake::checkFailed($String* message) {
	$init(OpeningHandshake);
	$throwNew($CheckFailedException, message);
	$shouldNotReachHere();
}

$URI* OpeningHandshake::checkURI($URI* uri) {
	$init(OpeningHandshake);
	$useLocalCurrentObjectStackCache();
	$var($String, scheme, $nc(uri)->getScheme());
	bool var$0 = "ws"_s->equalsIgnoreCase(scheme);
	if (!(var$0 || "wss"_s->equalsIgnoreCase(scheme))) {
		$throw($(illegal($$str({"invalid URI scheme: "_s, scheme}))));
	}
	if (uri->getHost() == nullptr) {
		$throw($(illegal($$str({"URI must contain a host: "_s, uri}))));
	}
	if (uri->getFragment() != nullptr) {
		$throw($(illegal($$str({"URI must not contain a fragment: "_s, uri}))));
	}
	return uri;
}

$IllegalArgumentException* OpeningHandshake::illegal($String* message) {
	$init(OpeningHandshake);
	return $new($IllegalArgumentException, message);
}

$Proxy* OpeningHandshake::proxyFor($Optional* selector, $URI* uri) {
	$init(OpeningHandshake);
	$useLocalCurrentObjectStackCache();
	if (!$nc(selector)->isPresent()) {
		return nullptr;
	}
	$var($URI, requestURI, createRequestURI(uri));
	$var($List, pl, $nc(($cast($ProxySelector, $($nc(selector)->get()))))->select(requestURI));
	if ($nc(pl)->isEmpty()) {
		return nullptr;
	}
	$var($Proxy, proxy, $cast($Proxy, $nc(pl)->get(0)));
	$init($Proxy$Type);
	if ($nc(proxy)->type() != $Proxy$Type::HTTP) {
		return nullptr;
	}
	return proxy;
}

void OpeningHandshake::checkPermissions($BuilderImpl* b, $Proxy* proxy) {
	$init(OpeningHandshake);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm == nullptr) {
		return;
	}
	$var($Stream, headers, $nc($($nc($($nc($($nc(b)->getHeaders()))->stream()))->map(static_cast<$Function*>($$new(OpeningHandshake$$Lambda$lambda$checkPermissions$1$1)))))->distinct());
	$var($URLPermission, perm1, $Utils::permissionForServer($(b->getUri()), ""_s, headers));
	$nc(sm)->checkPermission(perm1);
	if (proxy == nullptr) {
		return;
	}
	$var($URLPermission, perm2, $Utils::permissionForProxy($cast($InetSocketAddress, $($nc(proxy)->address()))));
	if (perm2 != nullptr) {
		sm->checkPermission(perm2);
	}
}

$String* OpeningHandshake::lambda$checkPermissions$1($Pair* p) {
	$init(OpeningHandshake);
	return $cast($String, $nc(p)->first);
}

$CompletableFuture* OpeningHandshake::lambda$send$0() {
	$useLocalCurrentObjectStackCache();
	return $cast($CompletableFuture, $nc($($nc(this->client)->sendAsync(this->request, $($HttpResponse$BodyHandlers::ofString()))))->thenCompose(static_cast<$Function*>($$new(OpeningHandshake$$Lambda$resultFrom$2, this))));
}

void clinit$OpeningHandshake($Class* class$) {
	$assignStatic(OpeningHandshake::HEADER_CONNECTION, "Connection"_s);
	$assignStatic(OpeningHandshake::HEADER_UPGRADE, "Upgrade"_s);
	$assignStatic(OpeningHandshake::HEADER_ACCEPT, "Sec-WebSocket-Accept"_s);
	$assignStatic(OpeningHandshake::HEADER_EXTENSIONS, "Sec-WebSocket-Extensions"_s);
	$assignStatic(OpeningHandshake::HEADER_KEY, "Sec-WebSocket-Key"_s);
	$assignStatic(OpeningHandshake::HEADER_PROTOCOL, "Sec-WebSocket-Protocol"_s);
	$assignStatic(OpeningHandshake::HEADER_VERSION, "Sec-WebSocket-Version"_s);
	$assignStatic(OpeningHandshake::VERSION, "13"_s);
	OpeningHandshake::$assertionsDisabled = !OpeningHandshake::class$->desiredAssertionStatus();
	{
		$assignStatic(OpeningHandshake::ILLEGAL_HEADERS, static_cast<$Set*>(static_cast<$AbstractSet*>($new($TreeSet, $String::CASE_INSENSITIVE_ORDER))));
		$nc(OpeningHandshake::ILLEGAL_HEADERS)->addAll($($List::of(OpeningHandshake::HEADER_ACCEPT, OpeningHandshake::HEADER_EXTENSIONS, OpeningHandshake::HEADER_KEY, OpeningHandshake::HEADER_PROTOCOL, OpeningHandshake::HEADER_VERSION)));
	}
	$assignStatic(OpeningHandshake::random, $new($SecureRandom));
}

OpeningHandshake::OpeningHandshake() {
}

$Class* OpeningHandshake::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(OpeningHandshake$$Lambda$lambda$send$0::classInfo$.name)) {
			return OpeningHandshake$$Lambda$lambda$send$0::load$(name, initialize);
		}
		if (name->equals(OpeningHandshake$$Lambda$lambda$checkPermissions$1$1::classInfo$.name)) {
			return OpeningHandshake$$Lambda$lambda$checkPermissions$1$1::load$(name, initialize);
		}
		if (name->equals(OpeningHandshake$$Lambda$resultFrom$2::classInfo$.name)) {
			return OpeningHandshake$$Lambda$resultFrom$2::load$(name, initialize);
		}
	}
	$loadClass(OpeningHandshake, name, initialize, &_OpeningHandshake_ClassInfo_, clinit$OpeningHandshake, allocate$OpeningHandshake);
	return class$;
}

$Class* OpeningHandshake::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk