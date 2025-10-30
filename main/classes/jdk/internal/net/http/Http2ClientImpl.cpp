#include <jdk/internal/net/http/Http2ClientImpl.h>

#include <java/io/EOFException.h>
#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/Math.h>
#include <java/lang/StackTraceElement.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/URI.h>
#include <java/util/AbstractMap.h>
#include <java/util/AbstractSet.h>
#include <java/util/Base64$Encoder.h>
#include <java/util/Base64.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/Http2Connection$ALPNException.h>
#include <jdk/internal/net/http/Http2Connection.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/frame/SettingsFrame.h>
#include <jcpp.h>

#undef DEBUG
#undef K
#undef MAX_VALUE
#undef STOPPED

using $StackTraceElementArray = $Array<::java::lang::StackTraceElement>;
using $EOFException = ::java::io::EOFException;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $Iterable = ::java::lang::Iterable;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $StackTraceElement = ::java::lang::StackTraceElement;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $URI = ::java::net::URI;
using $AbstractMap = ::java::util::AbstractMap;
using $AbstractSet = ::java::util::AbstractSet;
using $Base64 = ::java::util::Base64;
using $Base64$Encoder = ::java::util::Base64$Encoder;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Consumer = ::java::util::function::Consumer;
using $Supplier = ::java::util::function::Supplier;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $Http2Connection = ::jdk::internal::net::http::Http2Connection;
using $Http2Connection$ALPNException = ::jdk::internal::net::http::Http2Connection$ALPNException;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $SettingsFrame = ::jdk::internal::net::http::frame::SettingsFrame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Http2ClientImpl$$Lambda$toString : public $Supplier {
	$class(Http2ClientImpl$$Lambda$toString, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2ClientImpl$$Lambda$toString>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2ClientImpl$$Lambda$toString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http2ClientImpl$$Lambda$toString, inst$)},
	{}
};
$MethodInfo Http2ClientImpl$$Lambda$toString::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2ClientImpl$$Lambda$toString::*)($String*)>(&Http2ClientImpl$$Lambda$toString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2ClientImpl$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2ClientImpl$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http2ClientImpl$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(Http2ClientImpl$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2ClientImpl$$Lambda$toString::class$ = nullptr;

class Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1 : public $BiConsumer {
	$class(Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(Http2ClientImpl* inst, $String* key) {
		$set(this, inst$, inst);
		$set(this, key, key);
	}
	virtual void accept(Object$* conn, Object$* t) override {
		$nc(inst$)->lambda$getConnectionFor$0(key, $cast($Http2Connection, conn), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1>());
	}
	Http2ClientImpl* inst$ = nullptr;
	$String* key = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1, inst$)},
	{"key", "Ljava/lang/String;", nullptr, $PUBLIC, $field(Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1, key)},
	{}
};
$MethodInfo Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http2ClientImpl;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1::*)(Http2ClientImpl*,$String*)>(&Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1::load$($String* name, bool initialize) {
	$loadClass(Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1::class$ = nullptr;

class Http2ClientImpl$$Lambda$close$2 : public $Consumer {
	$class(Http2ClientImpl$$Lambda$close$2, $NO_CLASS_INIT, $Consumer)
public:
	void init$(Http2ClientImpl* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* h2c) override {
		$nc(inst$)->close($cast($Http2Connection, h2c));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2ClientImpl$$Lambda$close$2>());
	}
	Http2ClientImpl* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2ClientImpl$$Lambda$close$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http2ClientImpl$$Lambda$close$2, inst$)},
	{}
};
$MethodInfo Http2ClientImpl$$Lambda$close$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http2ClientImpl;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2ClientImpl$$Lambda$close$2::*)(Http2ClientImpl*)>(&Http2ClientImpl$$Lambda$close$2::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2ClientImpl$$Lambda$close$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2ClientImpl$$Lambda$close$2",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* Http2ClientImpl$$Lambda$close$2::load$($String* name, bool initialize) {
	$loadClass(Http2ClientImpl$$Lambda$close$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2ClientImpl$$Lambda$close$2::class$ = nullptr;

$FieldInfo _Http2ClientImpl_FieldInfo_[] = {
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $STATIC | $FINAL, $staticField(Http2ClientImpl, debug)},
	{"client", "Ljdk/internal/net/http/HttpClientImpl;", nullptr, $PRIVATE | $FINAL, $field(Http2ClientImpl, client$)},
	{"connections", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljdk/internal/net/http/Http2Connection;>;", $PRIVATE | $FINAL, $field(Http2ClientImpl, connections)},
	{"failures", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $FINAL, $field(Http2ClientImpl, failures)},
	{"STOPPED", "Ljava/io/EOFException;", nullptr, $PRIVATE, $field(Http2ClientImpl, STOPPED)},
	{"K", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Http2ClientImpl, K)},
	{}
};

$MethodInfo _Http2ClientImpl_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpClientImpl;)V", nullptr, 0, $method(static_cast<void(Http2ClientImpl::*)($HttpClientImpl*)>(&Http2ClientImpl::init$))},
	{"client", "()Ljdk/internal/net/http/HttpClientImpl;", nullptr, 0},
	{"close", "(Ljdk/internal/net/http/Http2Connection;)V", nullptr, $PRIVATE, $method(static_cast<void(Http2ClientImpl::*)($Http2Connection*)>(&Http2ClientImpl::close))},
	{"deleteConnection", "(Ljdk/internal/net/http/Http2Connection;)V", nullptr, 0},
	{"getClientSettings", "()Ljdk/internal/net/http/frame/SettingsFrame;", nullptr, 0},
	{"getConnectionFor", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/Exchange;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/Exchange<*>;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Http2Connection;>;", 0},
	{"getConnectionWindowSize", "(Ljdk/internal/net/http/frame/SettingsFrame;)I", nullptr, 0},
	{"getParameter", "(Ljava/lang/String;III)I", nullptr, $PRIVATE | $STATIC, $method(static_cast<int32_t(*)($String*,int32_t,int32_t,int32_t)>(&Http2ClientImpl::getParameter))},
	{"getSettingsString", "()Ljava/lang/String;", nullptr, 0},
	{"lambda$getConnectionFor$0", "(Ljava/lang/String;Ljdk/internal/net/http/Http2Connection;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Http2ClientImpl::*)($String*,$Http2Connection*,$Throwable*)>(&Http2ClientImpl::lambda$getConnectionFor$0))},
	{"offerConnection", "(Ljdk/internal/net/http/Http2Connection;)Z", nullptr, 0},
	{"stop", "()V", nullptr, 0},
	{}
};

$ClassInfo _Http2ClientImpl_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.Http2ClientImpl",
	"java.lang.Object",
	nullptr,
	_Http2ClientImpl_FieldInfo_,
	_Http2ClientImpl_MethodInfo_
};

$Object* allocate$Http2ClientImpl($Class* clazz) {
	return $of($alloc(Http2ClientImpl));
}

$Logger* Http2ClientImpl::debug = nullptr;

void Http2ClientImpl::init$($HttpClientImpl* client) {
	$set(this, connections, static_cast<$Map*>(static_cast<$AbstractMap*>($new($ConcurrentHashMap))));
	$set(this, failures, $Collections::synchronizedSet($$new($HashSet)));
	$set(this, client$, client);
}

$CompletableFuture* Http2ClientImpl::getConnectionFor($HttpRequestImpl* req, $Exchange* exchange) {
	$useLocalCurrentObjectStackCache();
	$var($URI, uri, $nc(req)->uri());
	$var($InetSocketAddress, proxy, req->proxy());
	$var($String, key, $Http2Connection::keyFor(uri, proxy));
	$synchronized(this) {
		$var($Http2Connection, connection, $cast($Http2Connection, $nc(this->connections)->get(key)));
		if (connection != nullptr) {
			try {
				if (connection->closed || !connection->reserveStream(true)) {
					if ($nc(Http2ClientImpl::debug)->on()) {
						$nc(Http2ClientImpl::debug)->log("removing found closed or closing connection: %s"_s, $$new($ObjectArray, {$of(connection)}));
					}
					deleteConnection(connection);
				} else {
					if ($nc(Http2ClientImpl::debug)->on()) {
						$nc(Http2ClientImpl::debug)->log("found connection in the pool: %s"_s, $$new($ObjectArray, {$of(connection)}));
					}
					return $MinimalFuture::completedFuture(connection);
				}
			} catch ($IOException& e) {
				return $MinimalFuture::failedFuture(e);
			}
		}
		bool var$0 = !req->secure();
		if (var$0 || $nc(this->failures)->contains(key)) {
			if ($nc(Http2ClientImpl::debug)->on()) {
				$nc(Http2ClientImpl::debug)->log("not found in connection pool"_s);
			}
			return $MinimalFuture::completedFuture(nullptr);
		}
	}
	return $cast($CompletableFuture, $nc($($Http2Connection::createAsync(req, this, exchange)))->whenComplete(static_cast<$BiConsumer*>($$new(Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1, this, key))));
}

bool Http2ClientImpl::offerConnection($Http2Connection* c) {
	$useLocalCurrentObjectStackCache();
	if ($nc(Http2ClientImpl::debug)->on()) {
		$nc(Http2ClientImpl::debug)->log("offering to the connection pool: %s"_s, $$new($ObjectArray, {$of(c)}));
	}
	if ($nc(c)->closed || $nc(c)->finalStream()) {
		if ($nc(Http2ClientImpl::debug)->on()) {
			$nc(Http2ClientImpl::debug)->log("skipping offered closed or closing connection: %s"_s, $$new($ObjectArray, {$of(c)}));
		}
		return false;
	}
	$var($String, key, $nc(c)->key());
	$synchronized(this) {
		$var($Http2Connection, c1, $cast($Http2Connection, $nc(this->connections)->putIfAbsent(key, c)));
		if (c1 != nullptr) {
			c->setFinalStream();
			if ($nc(Http2ClientImpl::debug)->on()) {
				$nc(Http2ClientImpl::debug)->log("existing entry in connection pool for %s"_s, $$new($ObjectArray, {$of(key)}));
			}
			return false;
		}
		if ($nc(Http2ClientImpl::debug)->on()) {
			$nc(Http2ClientImpl::debug)->log("put in the connection pool: %s"_s, $$new($ObjectArray, {$of(c)}));
		}
		return true;
	}
}

void Http2ClientImpl::deleteConnection($Http2Connection* c) {
	$useLocalCurrentObjectStackCache();
	if ($nc(Http2ClientImpl::debug)->on()) {
		$nc(Http2ClientImpl::debug)->log("removing from the connection pool: %s"_s, $$new($ObjectArray, {$of(c)}));
	}
	$synchronized(this) {
		$var($Http2Connection, c1, $cast($Http2Connection, $nc(this->connections)->get($($nc(c)->key()))));
		if (c1 != nullptr && $of(c1)->equals(c)) {
			$nc(this->connections)->remove($($nc(c)->key()));
			if ($nc(Http2ClientImpl::debug)->on()) {
				$nc(Http2ClientImpl::debug)->log("removed from the connection pool: %s"_s, $$new($ObjectArray, {$of(c)}));
			}
		}
	}
}

void Http2ClientImpl::stop() {
	$useLocalCurrentObjectStackCache();
	if ($nc(Http2ClientImpl::debug)->on()) {
		$nc(Http2ClientImpl::debug)->log("stopping"_s);
	}
	$set(this, STOPPED, $new($EOFException, "HTTP/2 client stopped"_s));
	$nc(this->STOPPED)->setStackTrace($$new($StackTraceElementArray, 0));
	$nc($($nc(this->connections)->values()))->forEach(static_cast<$Consumer*>($$new(Http2ClientImpl$$Lambda$close$2, this)));
	$nc(this->connections)->clear();
}

void Http2ClientImpl::close($Http2Connection* h2c) {
	try {
		$nc(h2c)->close();
	} catch ($Throwable& t) {
	}
	try {
		$nc(h2c)->shutdown(this->STOPPED);
	} catch ($Throwable& t) {
	}
}

$HttpClientImpl* Http2ClientImpl::client() {
	return this->client$;
}

$String* Http2ClientImpl::getSettingsString() {
	$useLocalCurrentObjectStackCache();
	$var($SettingsFrame, sf, getClientSettings());
	$var($bytes, settings, $nc(sf)->toByteArray());
	$var($Base64$Encoder, encoder, $nc($($Base64::getUrlEncoder()))->withoutPadding());
	return $nc(encoder)->encodeToString(settings);
}

int32_t Http2ClientImpl::getParameter($String* property, int32_t min, int32_t max, int32_t defaultValue) {
	$init(Http2ClientImpl);
	$useLocalCurrentObjectStackCache();
	int32_t value = $Utils::getIntegerNetProperty(property, defaultValue);
	if (value < min || value > max) {
		$Log::logError("Property value for {0}={1} not in [{2}..{3}]: using default={4}"_s, $$new($ObjectArray, {
			$of(property),
			$($of($Integer::valueOf(value))),
			$($of($Integer::valueOf(min))),
			$($of($Integer::valueOf(max))),
			$($of($Integer::valueOf(defaultValue)))
		}));
		value = defaultValue;
	}
	return value;
}

int32_t Http2ClientImpl::getConnectionWindowSize($SettingsFrame* clientSettings) {
	int32_t streamWindow = $nc(clientSettings)->getParameter(4);
	int32_t defaultValue = $Math::min($Integer::MAX_VALUE, $Math::max(streamWindow, Http2ClientImpl::K * Http2ClientImpl::K * 32));
	return getParameter("jdk.httpclient.connectionWindowSize"_s, streamWindow, $Integer::MAX_VALUE, defaultValue);
}

$SettingsFrame* Http2ClientImpl::getClientSettings() {
	$var($SettingsFrame, frame, $new($SettingsFrame));
	frame->setParameter(1, getParameter("jdk.httpclient.hpack.maxheadertablesize"_s, 0, $Integer::MAX_VALUE, 16 * Http2ClientImpl::K));
	frame->setParameter(2, getParameter("jdk.httpclient.enablepush"_s, 0, 1, 1));
	frame->setParameter(3, getParameter("jdk.httpclient.maxstreams"_s, 1, $Integer::MAX_VALUE, 100));
	frame->setParameter(4, getParameter("jdk.httpclient.windowsize"_s, 16 * Http2ClientImpl::K, $Integer::MAX_VALUE, 16 * Http2ClientImpl::K * Http2ClientImpl::K));
	frame->setParameter(5, getParameter("jdk.httpclient.maxframesize"_s, 16 * Http2ClientImpl::K, 16 * Http2ClientImpl::K * Http2ClientImpl::K - 1, 16 * Http2ClientImpl::K));
	return frame;
}

void Http2ClientImpl::lambda$getConnectionFor$0($String* key, $Http2Connection* conn, $Throwable* t) {
	$synchronized(this) {
		if (conn != nullptr) {
			try {
				conn->reserveStream(true);
			} catch ($IOException& e) {
				$throwNew($UncheckedIOException, e);
			}
			offerConnection(conn);
		} else {
			$var($Throwable, cause, $Utils::getCompletionCause(t));
			if ($instanceOf($Http2Connection$ALPNException, cause)) {
				$nc(this->failures)->add(key);
			}
		}
	}
}

void clinit$Http2ClientImpl($Class* class$) {
	$init($Utils);
	$assignStatic(Http2ClientImpl::debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(Http2ClientImpl$$Lambda$toString, static_cast<$String*>("Http2ClientImpl"_s))), $Utils::DEBUG));
}

Http2ClientImpl::Http2ClientImpl() {
}

$Class* Http2ClientImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Http2ClientImpl$$Lambda$toString::classInfo$.name)) {
			return Http2ClientImpl$$Lambda$toString::load$(name, initialize);
		}
		if (name->equals(Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1::classInfo$.name)) {
			return Http2ClientImpl$$Lambda$lambda$getConnectionFor$0$1::load$(name, initialize);
		}
		if (name->equals(Http2ClientImpl$$Lambda$close$2::classInfo$.name)) {
			return Http2ClientImpl$$Lambda$close$2::load$(name, initialize);
		}
	}
	$loadClass(Http2ClientImpl, name, initialize, &_Http2ClientImpl_ClassInfo_, clinit$Http2ClientImpl, allocate$Http2ClientImpl);
	return class$;
}

$Class* Http2ClientImpl::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk