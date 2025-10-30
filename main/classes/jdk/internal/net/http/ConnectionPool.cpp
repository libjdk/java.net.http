#include <jdk/internal/net/http/ConnectionPool.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Iterable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/InetSocketAddress.h>
#include <java/time/Instant.h>
#include <java/time/temporal/ChronoUnit.h>
#include <java/time/temporal/Temporal.h>
#include <java/time/temporal/TemporalUnit.h>
#include <java/util/AbstractCollection.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Optional.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/net/http/ConnectionPool$CacheKey.h>
#include <jdk/internal/net/http/ConnectionPool$CleanupTrigger.h>
#include <jdk/internal/net/http/ConnectionPool$ExpiryEntry.h>
#include <jdk/internal/net/http/ConnectionPool$ExpiryList.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/PlainHttpConnection.h>
#include <jdk/internal/net/http/common/FlowTube$TubePublisher.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef DEBUG
#undef KEEP_ALIVE
#undef MAX_POOL_SIZE
#undef MILLIS

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Iterable = ::java::lang::Iterable;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $Instant = ::java::time::Instant;
using $ChronoUnit = ::java::time::temporal::ChronoUnit;
using $Temporal = ::java::time::temporal::Temporal;
using $TemporalUnit = ::java::time::temporal::TemporalUnit;
using $AbstractCollection = ::java::util::AbstractCollection;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Optional = ::java::util::Optional;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;
using $Collector = ::java::util::stream::Collector;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $ConnectionPool$CacheKey = ::jdk::internal::net::http::ConnectionPool$CacheKey;
using $ConnectionPool$CleanupTrigger = ::jdk::internal::net::http::ConnectionPool$CleanupTrigger;
using $ConnectionPool$ExpiryEntry = ::jdk::internal::net::http::ConnectionPool$ExpiryEntry;
using $ConnectionPool$ExpiryList = ::jdk::internal::net::http::ConnectionPool$ExpiryList;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $PlainHttpConnection = ::jdk::internal::net::http::PlainHttpConnection;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $FlowTube$TubePublisher = ::jdk::internal::net::http::common::FlowTube$TubePublisher;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class ConnectionPool$$Lambda$dbgString : public $Supplier {
	$class(ConnectionPool$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(ConnectionPool* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ConnectionPool$$Lambda$dbgString>());
	}
	ConnectionPool* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ConnectionPool$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ConnectionPool$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo ConnectionPool$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/ConnectionPool;)V", nullptr, $PUBLIC, $method(static_cast<void(ConnectionPool$$Lambda$dbgString::*)(ConnectionPool*)>(&ConnectionPool$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ConnectionPool$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ConnectionPool$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* ConnectionPool$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(ConnectionPool$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ConnectionPool$$Lambda$dbgString::class$ = nullptr;

class ConnectionPool$$Lambda$close$1 : public $Consumer {
	$class(ConnectionPool$$Lambda$close$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$(ConnectionPool* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* c) override {
		$nc(inst$)->close($cast($HttpConnection, c));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ConnectionPool$$Lambda$close$1>());
	}
	ConnectionPool* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ConnectionPool$$Lambda$close$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ConnectionPool$$Lambda$close$1, inst$)},
	{}
};
$MethodInfo ConnectionPool$$Lambda$close$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/ConnectionPool;)V", nullptr, $PUBLIC, $method(static_cast<void(ConnectionPool$$Lambda$close$1::*)(ConnectionPool*)>(&ConnectionPool$$Lambda$close$1::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo ConnectionPool$$Lambda$close$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ConnectionPool$$Lambda$close$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ConnectionPool$$Lambda$close$1::load$($String* name, bool initialize) {
	$loadClass(ConnectionPool$$Lambda$close$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ConnectionPool$$Lambda$close$1::class$ = nullptr;

class ConnectionPool$$Lambda$lambda$stop$0$2 : public $Function {
	$class(ConnectionPool$$Lambda$lambda$stop$0$2, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* e) override {
		 return $of(ConnectionPool::lambda$stop$0($cast($ConnectionPool$ExpiryEntry, e)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ConnectionPool$$Lambda$lambda$stop$0$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ConnectionPool$$Lambda$lambda$stop$0$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ConnectionPool$$Lambda$lambda$stop$0$2::*)()>(&ConnectionPool$$Lambda$lambda$stop$0$2::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ConnectionPool$$Lambda$lambda$stop$0$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ConnectionPool$$Lambda$lambda$stop$0$2",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ConnectionPool$$Lambda$lambda$stop$0$2::load$($String* name, bool initialize) {
	$loadClass(ConnectionPool$$Lambda$lambda$stop$0$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ConnectionPool$$Lambda$lambda$stop$0$2::class$ = nullptr;

$FieldInfo _ConnectionPool_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ConnectionPool, $assertionsDisabled)},
	{"KEEP_ALIVE", "J", nullptr, $STATIC | $FINAL, $staticField(ConnectionPool, KEEP_ALIVE)},
	{"MAX_POOL_SIZE", "J", nullptr, $STATIC | $FINAL, $staticField(ConnectionPool, MAX_POOL_SIZE)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(ConnectionPool, debug)},
	{"plainPool", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljdk/internal/net/http/ConnectionPool$CacheKey;Ljava/util/LinkedList<Ljdk/internal/net/http/HttpConnection;>;>;", $PRIVATE | $FINAL, $field(ConnectionPool, plainPool)},
	{"sslPool", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljdk/internal/net/http/ConnectionPool$CacheKey;Ljava/util/LinkedList<Ljdk/internal/net/http/HttpConnection;>;>;", $PRIVATE | $FINAL, $field(ConnectionPool, sslPool)},
	{"expiryList", "Ljdk/internal/net/http/ConnectionPool$ExpiryList;", nullptr, $PRIVATE | $FINAL, $field(ConnectionPool, expiryList)},
	{"dbgTag", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ConnectionPool, dbgTag)},
	{"stopped", "Z", nullptr, 0, $field(ConnectionPool, stopped)},
	{}
};

$MethodInfo _ConnectionPool_MethodInfo_[] = {
	{"<init>", "(J)V", nullptr, 0, $method(static_cast<void(ConnectionPool::*)(int64_t)>(&ConnectionPool::init$))},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(ConnectionPool::*)($String*)>(&ConnectionPool::init$))},
	{"cacheKey", "(Ljava/net/InetSocketAddress;Ljava/net/InetSocketAddress;)Ljdk/internal/net/http/ConnectionPool$CacheKey;", nullptr, $STATIC, $method(static_cast<$ConnectionPool$CacheKey*(*)($InetSocketAddress*,$InetSocketAddress*)>(&ConnectionPool::cacheKey))},
	{"cleanup", "(Ljdk/internal/net/http/HttpConnection;Ljava/lang/Throwable;)V", nullptr, 0, $method(static_cast<void(ConnectionPool::*)($HttpConnection*,$Throwable*)>(&ConnectionPool::cleanup))},
	{"close", "(Ljdk/internal/net/http/HttpConnection;)V", nullptr, $PRIVATE, $method(static_cast<void(ConnectionPool::*)($HttpConnection*)>(&ConnectionPool::close))},
	{"contains", "(Ljdk/internal/net/http/HttpConnection;)Z", nullptr, $SYNCHRONIZED, $method(static_cast<bool(ConnectionPool::*)($HttpConnection*)>(&ConnectionPool::contains))},
	{"dbgString", "()Ljava/lang/String;", nullptr, $FINAL, $method(static_cast<$String*(ConnectionPool::*)()>(&ConnectionPool::dbgString))},
	{"findConnection", "(Ljdk/internal/net/http/ConnectionPool$CacheKey;Ljava/util/HashMap;)Ljdk/internal/net/http/HttpConnection;", "(Ljdk/internal/net/http/ConnectionPool$CacheKey;Ljava/util/HashMap<Ljdk/internal/net/http/ConnectionPool$CacheKey;Ljava/util/LinkedList<Ljdk/internal/net/http/HttpConnection;>;>;)Ljdk/internal/net/http/HttpConnection;", $PRIVATE, $method(static_cast<$HttpConnection*(ConnectionPool::*)($ConnectionPool$CacheKey*,$HashMap*)>(&ConnectionPool::findConnection))},
	{"getConnection", "(ZLjava/net/InetSocketAddress;Ljava/net/InetSocketAddress;)Ljdk/internal/net/http/HttpConnection;", nullptr, $SYNCHRONIZED, $method(static_cast<$HttpConnection*(ConnectionPool::*)(bool,$InetSocketAddress*,$InetSocketAddress*)>(&ConnectionPool::getConnection))},
	{"lambda$stop$0", "(Ljdk/internal/net/http/ConnectionPool$ExpiryEntry;)Ljdk/internal/net/http/HttpConnection;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpConnection*(*)($ConnectionPool$ExpiryEntry*)>(&ConnectionPool::lambda$stop$0))},
	{"purgeExpiredConnectionsAndReturnNextDeadline", "()J", nullptr, 0, $method(static_cast<int64_t(ConnectionPool::*)()>(&ConnectionPool::purgeExpiredConnectionsAndReturnNextDeadline))},
	{"purgeExpiredConnectionsAndReturnNextDeadline", "(Ljava/time/Instant;)J", nullptr, 0, $method(static_cast<int64_t(ConnectionPool::*)($Instant*)>(&ConnectionPool::purgeExpiredConnectionsAndReturnNextDeadline))},
	{"putConnection", "(Ljdk/internal/net/http/HttpConnection;Ljava/util/HashMap;)V", "(Ljdk/internal/net/http/HttpConnection;Ljava/util/HashMap<Ljdk/internal/net/http/ConnectionPool$CacheKey;Ljava/util/LinkedList<Ljdk/internal/net/http/HttpConnection;>;>;)V", $PRIVATE, $method(static_cast<void(ConnectionPool::*)($HttpConnection*,$HashMap*)>(&ConnectionPool::putConnection))},
	{"registerCleanupTrigger", "(Ljdk/internal/net/http/HttpConnection;)Ljdk/internal/net/http/ConnectionPool$CleanupTrigger;", nullptr, $PRIVATE, $method(static_cast<$ConnectionPool$CleanupTrigger*(ConnectionPool::*)($HttpConnection*)>(&ConnectionPool::registerCleanupTrigger))},
	{"removeFromPool", "(Ljdk/internal/net/http/HttpConnection;Ljava/util/HashMap;)Z", "(Ljdk/internal/net/http/HttpConnection;Ljava/util/HashMap<Ljdk/internal/net/http/ConnectionPool$CacheKey;Ljava/util/LinkedList<Ljdk/internal/net/http/HttpConnection;>;>;)Z", $PRIVATE, $method(static_cast<bool(ConnectionPool::*)($HttpConnection*,$HashMap*)>(&ConnectionPool::removeFromPool))},
	{"removeFromPool", "(Ljdk/internal/net/http/HttpConnection;)V", nullptr, $PRIVATE, $method(static_cast<void(ConnectionPool::*)($HttpConnection*)>(&ConnectionPool::removeFromPool))},
	{"returnToPool", "(Ljdk/internal/net/http/HttpConnection;)V", nullptr, 0, $method(static_cast<void(ConnectionPool::*)($HttpConnection*)>(&ConnectionPool::returnToPool))},
	{"returnToPool", "(Ljdk/internal/net/http/HttpConnection;Ljava/time/Instant;J)V", nullptr, 0, $method(static_cast<void(ConnectionPool::*)($HttpConnection*,$Instant*,int64_t)>(&ConnectionPool::returnToPool))},
	{"start", "()V", nullptr, $SYNCHRONIZED, $method(static_cast<void(ConnectionPool::*)()>(&ConnectionPool::start))},
	{"stop", "()V", nullptr, 0, $method(static_cast<void(ConnectionPool::*)()>(&ConnectionPool::stop))},
	{}
};

$InnerClassInfo _ConnectionPool_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ConnectionPool$CleanupTrigger", "jdk.internal.net.http.ConnectionPool", "CleanupTrigger", $PRIVATE | $FINAL},
	{"jdk.internal.net.http.ConnectionPool$ExpiryList", "jdk.internal.net.http.ConnectionPool", "ExpiryList", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.net.http.ConnectionPool$ExpiryEntry", "jdk.internal.net.http.ConnectionPool", "ExpiryEntry", $STATIC | $FINAL},
	{"jdk.internal.net.http.ConnectionPool$CacheKey", "jdk.internal.net.http.ConnectionPool", "CacheKey", $STATIC},
	{}
};

$ClassInfo _ConnectionPool_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.ConnectionPool",
	"java.lang.Object",
	nullptr,
	_ConnectionPool_FieldInfo_,
	_ConnectionPool_MethodInfo_,
	nullptr,
	nullptr,
	_ConnectionPool_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ConnectionPool$CleanupTrigger,jdk.internal.net.http.ConnectionPool$ExpiryList,jdk.internal.net.http.ConnectionPool$ExpiryEntry,jdk.internal.net.http.ConnectionPool$CacheKey"
};

$Object* allocate$ConnectionPool($Class* clazz) {
	return $of($alloc(ConnectionPool));
}

bool ConnectionPool::$assertionsDisabled = false;
int64_t ConnectionPool::KEEP_ALIVE = 0;
int64_t ConnectionPool::MAX_POOL_SIZE = 0;

void ConnectionPool::init$(int64_t clientId) {
	$useLocalCurrentObjectStackCache();
	ConnectionPool::init$($$str({"ConnectionPool("_s, $$str(clientId), ")"_s}));
}

void ConnectionPool::init$($String* tag) {
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(ConnectionPool$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, dbgTag, tag);
	$set(this, plainPool, $new($HashMap));
	$set(this, sslPool, $new($HashMap));
	$set(this, expiryList, $new($ConnectionPool$ExpiryList));
}

$String* ConnectionPool::dbgString() {
	return this->dbgTag;
}

void ConnectionPool::start() {
	$synchronized(this) {
		if (!ConnectionPool::$assertionsDisabled && ! !this->stopped) {
			$throwNew($AssertionError, $of("Already stopped"_s));
		}
	}
}

$ConnectionPool$CacheKey* ConnectionPool::cacheKey($InetSocketAddress* destination, $InetSocketAddress* proxy) {
	$init(ConnectionPool);
	return $new($ConnectionPool$CacheKey, destination, proxy);
}

$HttpConnection* ConnectionPool::getConnection(bool secure, $InetSocketAddress* addr$renamed, $InetSocketAddress* proxy) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($InetSocketAddress, addr, addr$renamed);
		if (this->stopped) {
			return nullptr;
		}
		$assign(addr, secure || proxy == nullptr ? addr : ($InetSocketAddress*)nullptr);
		$var($ConnectionPool$CacheKey, key, $new($ConnectionPool$CacheKey, addr, proxy));
		$var($HttpConnection, c, secure ? findConnection(key, this->sslPool) : findConnection(key, this->plainPool));
		if (!ConnectionPool::$assertionsDisabled && !(c == nullptr || $nc(c)->isSecure() == secure)) {
			$throwNew($AssertionError);
		}
		return c;
	}
}

void ConnectionPool::returnToPool($HttpConnection* conn) {
	returnToPool(conn, $($Instant::now()), ConnectionPool::KEEP_ALIVE);
}

void ConnectionPool::returnToPool($HttpConnection* conn, $Instant* now, int64_t keepAlive) {
	$useLocalCurrentObjectStackCache();
	if (!ConnectionPool::$assertionsDisabled && !(($instanceOf($PlainHttpConnection, conn)) || $nc(conn)->isSecure())) {
		$throwNew($AssertionError, $of($$str({"Attempting to return unsecure connection to SSL pool: "_s, $of(conn)->getClass()})));
	}
	$var($ConnectionPool$CleanupTrigger, cleanup, registerCleanupTrigger(conn));
	$var($HttpConnection, toClose, nullptr);
	$synchronized(this) {
		if ($nc(cleanup)->isDone()) {
			return;
		} else if (this->stopped) {
			$nc(conn)->close();
			return;
		}
		if (ConnectionPool::MAX_POOL_SIZE > 0 && $nc(this->expiryList)->size() >= ConnectionPool::MAX_POOL_SIZE) {
			$assign(toClose, $nc(this->expiryList)->removeOldest());
			if (toClose != nullptr) {
				removeFromPool(toClose);
			}
		}
		if ($instanceOf($PlainHttpConnection, conn)) {
			putConnection(conn, this->plainPool);
		} else {
			if (!ConnectionPool::$assertionsDisabled && !$nc(conn)->isSecure()) {
				$throwNew($AssertionError);
			}
			putConnection(conn, this->sslPool);
		}
		$nc(this->expiryList)->add(conn, now, keepAlive);
	}
	if (toClose != nullptr) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Maximum pool size reached: removing oldest connection %s"_s, $$new($ObjectArray, {$($of(toClose->dbgString()))}));
		}
		close(toClose);
	}
}

$ConnectionPool$CleanupTrigger* ConnectionPool::registerCleanupTrigger($HttpConnection* conn) {
	$useLocalCurrentObjectStackCache();
	$var($ConnectionPool$CleanupTrigger, cleanup, $new($ConnectionPool$CleanupTrigger, this, conn));
	$var($FlowTube, flow, $nc(conn)->getConnectionFlow());
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("registering %s"_s, $$new($ObjectArray, {$of(cleanup)}));
	}
	$nc(flow)->connectFlows(cleanup, cleanup);
	return cleanup;
}

$HttpConnection* ConnectionPool::findConnection($ConnectionPool$CacheKey* key, $HashMap* pool) {
	$useLocalCurrentObjectStackCache();
	$var($LinkedList, l, $cast($LinkedList, $nc(pool)->get(key)));
	if (l == nullptr || $nc(l)->isEmpty()) {
		return nullptr;
	} else {
		$var($HttpConnection, c, $cast($HttpConnection, l->removeFirst()));
		$nc(this->expiryList)->remove(c);
		return c;
	}
}

bool ConnectionPool::removeFromPool($HttpConnection* c, $HashMap* pool) {
	$useLocalCurrentObjectStackCache();
	if (!ConnectionPool::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	$var($ConnectionPool$CacheKey, k, $nc(c)->cacheKey());
	$var($List, l, $cast($List, $nc(pool)->get(k)));
	if (l == nullptr || $nc(l)->isEmpty()) {
		pool->remove(k);
		return false;
	}
	return $nc(l)->remove($of(c));
}

void ConnectionPool::putConnection($HttpConnection* c, $HashMap* pool) {
	$useLocalCurrentObjectStackCache();
	$var($ConnectionPool$CacheKey, key, $nc(c)->cacheKey());
	$var($LinkedList, l, $cast($LinkedList, $nc(pool)->get(key)));
	if (l == nullptr) {
		$assign(l, $new($LinkedList));
		pool->put(key, l);
	}
	$nc(l)->add(c);
}

int64_t ConnectionPool::purgeExpiredConnectionsAndReturnNextDeadline() {
	if (!$nc(this->expiryList)->purgeMaybeRequired()) {
		return 0;
	}
	return purgeExpiredConnectionsAndReturnNextDeadline($($Instant::now()));
}

int64_t ConnectionPool::purgeExpiredConnectionsAndReturnNextDeadline($Instant* now) {
	$useLocalCurrentObjectStackCache();
	int64_t nextPurge = 0;
	if (!$nc(this->expiryList)->purgeMaybeRequired()) {
		return nextPurge;
	}
	$var($List, closelist, nullptr);
	$synchronized(this) {
		$assign(closelist, $nc(this->expiryList)->purgeUntil(now));
		{
			$var($Iterator, i$, $nc(closelist)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($HttpConnection, c, $cast($HttpConnection, i$->next()));
				{
					if ($instanceOf($PlainHttpConnection, c)) {
						bool wasPresent = removeFromPool(c, this->plainPool);
						if (!ConnectionPool::$assertionsDisabled && !wasPresent) {
							$throwNew($AssertionError);
						}
					} else {
						bool wasPresent = removeFromPool(c, this->sslPool);
						if (!ConnectionPool::$assertionsDisabled && !wasPresent) {
							$throwNew($AssertionError);
						}
					}
				}
			}
		}
		$init($ChronoUnit);
		nextPurge = $nc(now)->until($cast($Temporal, $($nc($($nc(this->expiryList)->nextExpiryDeadline()))->orElse(now))), $ChronoUnit::MILLIS);
	}
	$nc(closelist)->forEach(static_cast<$Consumer*>($$new(ConnectionPool$$Lambda$close$1, this)));
	return nextPurge;
}

void ConnectionPool::close($HttpConnection* c) {
	try {
		$nc(c)->close();
	} catch ($Throwable& e) {
	}
}

void ConnectionPool::stop() {
	$useLocalCurrentObjectStackCache();
	$var($List, closelist, $Collections::emptyList());
	{
		$var($Throwable, var$0, nullptr);
		try {
			$synchronized(this) {
				this->stopped = true;
				$assign(closelist, $cast($List, $nc($($nc($($nc(this->expiryList)->stream()))->map(static_cast<$Function*>($$new(ConnectionPool$$Lambda$lambda$stop$0$2)))))->collect($($Collectors::toList()))));
				$nc(this->expiryList)->clear();
				$nc(this->plainPool)->clear();
				$nc(this->sslPool)->clear();
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(closelist)->forEach(static_cast<$Consumer*>($$new(ConnectionPool$$Lambda$close$1, this)));
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void ConnectionPool::removeFromPool($HttpConnection* c) {
	if (!ConnectionPool::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	if ($instanceOf($PlainHttpConnection, c)) {
		removeFromPool(c, this->plainPool);
	} else {
		if (!ConnectionPool::$assertionsDisabled && !$nc(c)->isSecure()) {
			$throwNew($AssertionError, $of($$str({"connection "_s, c, " is not secure!"_s})));
		}
		removeFromPool(c, this->sslPool);
	}
}

bool ConnectionPool::contains($HttpConnection* c) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($ConnectionPool$CacheKey, key, $nc(c)->cacheKey());
		$var($List, list, nullptr);
		if (($assign(list, $cast($List, $nc(this->plainPool)->get(key)))) != nullptr) {
			if ($nc(list)->contains(c)) {
				return true;
			}
		}
		if (($assign(list, $cast($List, $nc(this->sslPool)->get(key)))) != nullptr) {
			if ($nc(list)->contains(c)) {
				return true;
			}
		}
		return false;
	}
}

void ConnectionPool::cleanup($HttpConnection* c, $Throwable* error) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("%s : ConnectionPool.cleanup(%s)"_s, $$new($ObjectArray, {
			$($of($String::valueOf($($of($nc(c)->getConnectionFlow()))))),
			$of(error)
		}));
	}
	$synchronized(this) {
		removeFromPool(c);
		$nc(this->expiryList)->remove(c);
	}
	$nc(c)->close();
}

$HttpConnection* ConnectionPool::lambda$stop$0($ConnectionPool$ExpiryEntry* e) {
	$init(ConnectionPool);
	return $nc(e)->connection;
}

void clinit$ConnectionPool($Class* class$) {
	ConnectionPool::$assertionsDisabled = !ConnectionPool::class$->desiredAssertionStatus();
	ConnectionPool::KEEP_ALIVE = $Utils::getIntegerNetProperty("jdk.httpclient.keepalive.timeout"_s, 1200);
	ConnectionPool::MAX_POOL_SIZE = $Utils::getIntegerNetProperty("jdk.httpclient.connectionPoolSize"_s, 0);
}

ConnectionPool::ConnectionPool() {
}

$Class* ConnectionPool::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ConnectionPool$$Lambda$dbgString::classInfo$.name)) {
			return ConnectionPool$$Lambda$dbgString::load$(name, initialize);
		}
		if (name->equals(ConnectionPool$$Lambda$close$1::classInfo$.name)) {
			return ConnectionPool$$Lambda$close$1::load$(name, initialize);
		}
		if (name->equals(ConnectionPool$$Lambda$lambda$stop$0$2::classInfo$.name)) {
			return ConnectionPool$$Lambda$lambda$stop$0$2::load$(name, initialize);
		}
	}
	$loadClass(ConnectionPool, name, initialize, &_ConnectionPool_ClassInfo_, clinit$ConnectionPool, allocate$ConnectionPool);
	return class$;
}

$Class* ConnectionPool::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk