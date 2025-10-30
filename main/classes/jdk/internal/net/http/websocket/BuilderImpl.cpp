#include <jdk/internal/net/http/websocket/BuilderImpl.h>

#include <java/lang/AssertionError.h>
#include <java/net/ProxySelector.h>
#include <java/net/URI.h>
#include <java/net/http/HttpClient.h>
#include <java/net/http/WebSocket$Builder.h>
#include <java/net/http/WebSocket$Listener.h>
#include <java/time/Duration.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <jdk/internal/net/http/common/Pair.h>
#include <jdk/internal/net/http/websocket/WebSocketImpl.h>
#include <jcpp.h>

using $PairArray = $Array<::jdk::internal::net::http::common::Pair>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ProxySelector = ::java::net::ProxySelector;
using $URI = ::java::net::URI;
using $HttpClient = ::java::net::http::HttpClient;
using $WebSocket$Builder = ::java::net::http::WebSocket$Builder;
using $WebSocket$Listener = ::java::net::http::WebSocket$Listener;
using $Duration = ::java::time::Duration;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $Pair = ::jdk::internal::net::http::common::Pair;
using $WebSocketImpl = ::jdk::internal::net::http::websocket::WebSocketImpl;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _BuilderImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(BuilderImpl, $assertionsDisabled)},
	{"client", "Ljava/net/http/HttpClient;", nullptr, $PRIVATE | $FINAL, $field(BuilderImpl, client)},
	{"uri", "Ljava/net/URI;", nullptr, $PRIVATE, $field(BuilderImpl, uri)},
	{"listener", "Ljava/net/http/WebSocket$Listener;", nullptr, $PRIVATE, $field(BuilderImpl, listener)},
	{"proxySelector", "Ljava/util/Optional;", "Ljava/util/Optional<Ljava/net/ProxySelector;>;", $PRIVATE | $FINAL, $field(BuilderImpl, proxySelector)},
	{"headers", "Ljava/util/Collection;", "Ljava/util/Collection<Ljdk/internal/net/http/common/Pair<Ljava/lang/String;Ljava/lang/String;>;>;", $PRIVATE | $FINAL, $field(BuilderImpl, headers)},
	{"subprotocols", "Ljava/util/Collection;", "Ljava/util/Collection<Ljava/lang/String;>;", $PRIVATE | $FINAL, $field(BuilderImpl, subprotocols$)},
	{"timeout", "Ljava/time/Duration;", nullptr, $PRIVATE, $field(BuilderImpl, timeout)},
	{}
};

$MethodInfo _BuilderImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/net/http/HttpClient;Ljava/net/ProxySelector;)V", nullptr, $PUBLIC, $method(static_cast<void(BuilderImpl::*)($HttpClient*,$ProxySelector*)>(&BuilderImpl::init$))},
	{"<init>", "(Ljava/net/http/HttpClient;Ljava/net/URI;Ljava/net/http/WebSocket$Listener;Ljava/util/Optional;Ljava/util/Collection;Ljava/util/Collection;Ljava/time/Duration;)V", "(Ljava/net/http/HttpClient;Ljava/net/URI;Ljava/net/http/WebSocket$Listener;Ljava/util/Optional<Ljava/net/ProxySelector;>;Ljava/util/Collection<Ljdk/internal/net/http/common/Pair<Ljava/lang/String;Ljava/lang/String;>;>;Ljava/util/Collection<Ljava/lang/String;>;Ljava/time/Duration;)V", $PRIVATE, $method(static_cast<void(BuilderImpl::*)($HttpClient*,$URI*,$WebSocket$Listener*,$Optional*,$Collection*,$Collection*,$Duration*)>(&BuilderImpl::init$))},
	{"buildAsync", "(Ljava/net/URI;Ljava/net/http/WebSocket$Listener;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/net/URI;Ljava/net/http/WebSocket$Listener;)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/WebSocket;>;", $PUBLIC},
	{"connectTimeout", "(Ljava/time/Duration;)Ljava/net/http/WebSocket$Builder;", nullptr, $PUBLIC},
	{"getClient", "()Ljava/net/http/HttpClient;", nullptr, 0, $method(static_cast<$HttpClient*(BuilderImpl::*)()>(&BuilderImpl::getClient))},
	{"getConnectTimeout", "()Ljava/time/Duration;", nullptr, 0, $method(static_cast<$Duration*(BuilderImpl::*)()>(&BuilderImpl::getConnectTimeout))},
	{"getHeaders", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljdk/internal/net/http/common/Pair<Ljava/lang/String;Ljava/lang/String;>;>;", 0, $method(static_cast<$Collection*(BuilderImpl::*)()>(&BuilderImpl::getHeaders))},
	{"getListener", "()Ljava/net/http/WebSocket$Listener;", nullptr, 0, $method(static_cast<$WebSocket$Listener*(BuilderImpl::*)()>(&BuilderImpl::getListener))},
	{"getProxySelector", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/ProxySelector;>;", 0, $method(static_cast<$Optional*(BuilderImpl::*)()>(&BuilderImpl::getProxySelector))},
	{"getSubprotocols", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljava/lang/String;>;", 0, $method(static_cast<$Collection*(BuilderImpl::*)()>(&BuilderImpl::getSubprotocols))},
	{"getUri", "()Ljava/net/URI;", nullptr, 0, $method(static_cast<$URI*(BuilderImpl::*)()>(&BuilderImpl::getUri))},
	{"header", "(Ljava/lang/String;Ljava/lang/String;)Ljava/net/http/WebSocket$Builder;", nullptr, $PUBLIC},
	{"immutableCopy", "()Ljdk/internal/net/http/websocket/BuilderImpl;", nullptr, $PRIVATE, $method(static_cast<BuilderImpl*(BuilderImpl::*)()>(&BuilderImpl::immutableCopy))},
	{"subprotocols", "(Ljava/lang/String;[Ljava/lang/String;)Ljava/net/http/WebSocket$Builder;", nullptr, $PUBLIC | $TRANSIENT},
	{}
};

$InnerClassInfo _BuilderImpl_InnerClassesInfo_[] = {
	{"java.net.http.WebSocket$Builder", "java.net.http.WebSocket", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _BuilderImpl_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.websocket.BuilderImpl",
	"java.lang.Object",
	"java.net.http.WebSocket$Builder",
	_BuilderImpl_FieldInfo_,
	_BuilderImpl_MethodInfo_,
	nullptr,
	nullptr,
	_BuilderImpl_InnerClassesInfo_
};

$Object* allocate$BuilderImpl($Class* clazz) {
	return $of($alloc(BuilderImpl));
}

bool BuilderImpl::$assertionsDisabled = false;

void BuilderImpl::init$($HttpClient* client, $ProxySelector* proxySelector) {
	$useLocalCurrentObjectStackCache();
	$var($HttpClient, var$0, client);
	$var($Optional, var$1, $Optional::ofNullable(proxySelector));
	$var($Collection, var$2, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($new($ArrayList)))));
	BuilderImpl::init$(var$0, nullptr, nullptr, var$1, var$2, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($$new($ArrayList)))), nullptr);
}

void BuilderImpl::init$($HttpClient* client, $URI* uri, $WebSocket$Listener* listener, $Optional* proxySelector, $Collection* headers, $Collection* subprotocols, $Duration* timeout) {
	$useLocalCurrentObjectStackCache();
	$set(this, client, client);
	$set(this, uri, uri);
	$set(this, listener, listener);
	$set(this, proxySelector, proxySelector);
	bool var$0 = !BuilderImpl::$assertionsDisabled;
	if (var$0) {
		bool var$1 = !$nc($($nc(client)->proxy()))->isPresent();
		var$0 = !(var$1 || $nc($($nc(client)->proxy()))->equals(proxySelector));
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	$set(this, headers, headers);
	$set(this, subprotocols$, subprotocols);
	$set(this, timeout, timeout);
}

$WebSocket$Builder* BuilderImpl::header($String* name, $String* value) {
	$Objects::requireNonNull($of(name), "name"_s);
	$Objects::requireNonNull($of(value), "value"_s);
	$nc(this->headers)->add($($Pair::pair(name, value)));
	return this;
}

$WebSocket$Builder* BuilderImpl::subprotocols($String* mostPreferred, $StringArray* lesserPreferred) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(mostPreferred), "mostPreferred"_s);
	$Objects::requireNonNull($of(lesserPreferred), "lesserPreferred"_s);
	$var($List, subprotocols, $new($ArrayList, $nc(lesserPreferred)->length + 1));
	subprotocols->add(mostPreferred);
	for (int32_t i = 0; i < $nc(lesserPreferred)->length; ++i) {
		$var($String, p, lesserPreferred->get(i));
		$Objects::requireNonNull($of(p), $$str({"lesserPreferred["_s, $$str(i), "]"_s}));
		subprotocols->add(p);
	}
	$nc(this->subprotocols$)->clear();
	$nc(this->subprotocols$)->addAll(subprotocols);
	return this;
}

$WebSocket$Builder* BuilderImpl::connectTimeout($Duration* timeout) {
	$set(this, timeout, $cast($Duration, $Objects::requireNonNull($of(timeout), "timeout"_s)));
	return this;
}

$CompletableFuture* BuilderImpl::buildAsync($URI* uri, $WebSocket$Listener* listener) {
	$set(this, uri, $cast($URI, $Objects::requireNonNull($of(uri), "uri"_s)));
	$set(this, listener, $cast($WebSocket$Listener, $Objects::requireNonNull($of(listener), "listener"_s)));
	$var(BuilderImpl, copy, immutableCopy());
	return $WebSocketImpl::newInstanceAsync(copy);
}

$HttpClient* BuilderImpl::getClient() {
	return this->client;
}

$URI* BuilderImpl::getUri() {
	return this->uri;
}

$WebSocket$Listener* BuilderImpl::getListener() {
	return this->listener;
}

$Collection* BuilderImpl::getHeaders() {
	return this->headers;
}

$Collection* BuilderImpl::getSubprotocols() {
	return this->subprotocols$;
}

$Duration* BuilderImpl::getConnectTimeout() {
	return this->timeout;
}

$Optional* BuilderImpl::getProxySelector() {
	return this->proxySelector;
}

BuilderImpl* BuilderImpl::immutableCopy() {
	$useLocalCurrentObjectStackCache();
	$var($HttpClient, var$0, this->client);
	$var($URI, var$1, this->uri);
	$var($WebSocket$Listener, var$2, this->listener);
	$var($Optional, var$3, this->proxySelector);
	$var($Collection, var$4, static_cast<$Collection*>($List::of($fcast($PairArray, $($nc(this->headers)->toArray($$new($PairArray, 0)))))));
	$var(BuilderImpl, copy, $new(BuilderImpl, var$0, var$1, var$2, var$3, var$4, $($List::of($fcast($StringArray, $($nc(this->subprotocols$)->toArray($$new($StringArray, 0)))))), this->timeout));
	return copy;
}

void clinit$BuilderImpl($Class* class$) {
	BuilderImpl::$assertionsDisabled = !BuilderImpl::class$->desiredAssertionStatus();
}

BuilderImpl::BuilderImpl() {
}

$Class* BuilderImpl::load$($String* name, bool initialize) {
	$loadClass(BuilderImpl, name, initialize, &_BuilderImpl_ClassInfo_, clinit$BuilderImpl, allocate$BuilderImpl);
	return class$;
}

$Class* BuilderImpl::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk