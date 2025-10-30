#include <jdk/internal/net/http/ConnectionPool$ExpiryList.h>

#include <java/time/Instant.h>
#include <java/time/temporal/ChronoUnit.h>
#include <java/time/temporal/TemporalUnit.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/ListIterator.h>
#include <java/util/Optional.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/net/http/ConnectionPool$ExpiryEntry.h>
#include <jdk/internal/net/http/ConnectionPool.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jcpp.h>

#undef KEEP_ALIVE
#undef SECONDS

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Instant = ::java::time::Instant;
using $ChronoUnit = ::java::time::temporal::ChronoUnit;
using $TemporalUnit = ::java::time::temporal::TemporalUnit;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $ListIterator = ::java::util::ListIterator;
using $Optional = ::java::util::Optional;
using $Stream = ::java::util::stream::Stream;
using $ConnectionPool = ::jdk::internal::net::http::ConnectionPool;
using $ConnectionPool$ExpiryEntry = ::jdk::internal::net::http::ConnectionPool$ExpiryEntry;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ConnectionPool$ExpiryList_FieldInfo_[] = {
	{"list", "Ljava/util/LinkedList;", "Ljava/util/LinkedList<Ljdk/internal/net/http/ConnectionPool$ExpiryEntry;>;", $PRIVATE | $FINAL, $field(ConnectionPool$ExpiryList, list)},
	{"mayContainEntries", "Z", nullptr, $PRIVATE | $VOLATILE, $field(ConnectionPool$ExpiryList, mayContainEntries)},
	{}
};

$MethodInfo _ConnectionPool$ExpiryList_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(ConnectionPool$ExpiryList::*)()>(&ConnectionPool$ExpiryList::init$))},
	{"add", "(Ljdk/internal/net/http/HttpConnection;)V", nullptr, 0, $method(static_cast<void(ConnectionPool$ExpiryList::*)($HttpConnection*)>(&ConnectionPool$ExpiryList::add))},
	{"add", "(Ljdk/internal/net/http/HttpConnection;Ljava/time/Instant;J)V", nullptr, 0, $method(static_cast<void(ConnectionPool$ExpiryList::*)($HttpConnection*,$Instant*,int64_t)>(&ConnectionPool$ExpiryList::add))},
	{"clear", "()V", nullptr, 0, $method(static_cast<void(ConnectionPool$ExpiryList::*)()>(&ConnectionPool$ExpiryList::clear))},
	{"nextExpiryDeadline", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/time/Instant;>;", 0, $method(static_cast<$Optional*(ConnectionPool$ExpiryList::*)()>(&ConnectionPool$ExpiryList::nextExpiryDeadline))},
	{"purgeMaybeRequired", "()Z", nullptr, 0, $method(static_cast<bool(ConnectionPool$ExpiryList::*)()>(&ConnectionPool$ExpiryList::purgeMaybeRequired))},
	{"purgeUntil", "(Ljava/time/Instant;)Ljava/util/List;", "(Ljava/time/Instant;)Ljava/util/List<Ljdk/internal/net/http/HttpConnection;>;", 0, $method(static_cast<$List*(ConnectionPool$ExpiryList::*)($Instant*)>(&ConnectionPool$ExpiryList::purgeUntil))},
	{"remove", "(Ljdk/internal/net/http/HttpConnection;)V", nullptr, 0, $method(static_cast<void(ConnectionPool$ExpiryList::*)($HttpConnection*)>(&ConnectionPool$ExpiryList::remove))},
	{"removeOldest", "()Ljdk/internal/net/http/HttpConnection;", nullptr, 0, $method(static_cast<$HttpConnection*(ConnectionPool$ExpiryList::*)()>(&ConnectionPool$ExpiryList::removeOldest))},
	{"size", "()I", nullptr, 0, $method(static_cast<int32_t(ConnectionPool$ExpiryList::*)()>(&ConnectionPool$ExpiryList::size))},
	{"stream", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljdk/internal/net/http/ConnectionPool$ExpiryEntry;>;", 0, $method(static_cast<$Stream*(ConnectionPool$ExpiryList::*)()>(&ConnectionPool$ExpiryList::stream))},
	{}
};

$InnerClassInfo _ConnectionPool$ExpiryList_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ConnectionPool$ExpiryList", "jdk.internal.net.http.ConnectionPool", "ExpiryList", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _ConnectionPool$ExpiryList_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.ConnectionPool$ExpiryList",
	"java.lang.Object",
	nullptr,
	_ConnectionPool$ExpiryList_FieldInfo_,
	_ConnectionPool$ExpiryList_MethodInfo_,
	nullptr,
	nullptr,
	_ConnectionPool$ExpiryList_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ConnectionPool"
};

$Object* allocate$ConnectionPool$ExpiryList($Class* clazz) {
	return $of($alloc(ConnectionPool$ExpiryList));
}

void ConnectionPool$ExpiryList::init$() {
	$set(this, list, $new($LinkedList));
}

int32_t ConnectionPool$ExpiryList::size() {
	return $nc(this->list)->size();
}

bool ConnectionPool$ExpiryList::purgeMaybeRequired() {
	return this->mayContainEntries;
}

$Optional* ConnectionPool$ExpiryList::nextExpiryDeadline() {
	if ($nc(this->list)->isEmpty()) {
		return $Optional::empty();
	} else {
		return $Optional::of($nc(($cast($ConnectionPool$ExpiryEntry, $($nc(this->list)->getLast()))))->expiry);
	}
}

$HttpConnection* ConnectionPool$ExpiryList::removeOldest() {
	$var($ConnectionPool$ExpiryEntry, entry, $cast($ConnectionPool$ExpiryEntry, $nc(this->list)->pollLast()));
	return entry == nullptr ? ($HttpConnection*)nullptr : $nc(entry)->connection;
}

void ConnectionPool$ExpiryList::add($HttpConnection* conn) {
	$init($ConnectionPool);
	add(conn, $($Instant::now()), $ConnectionPool::KEEP_ALIVE);
}

void ConnectionPool$ExpiryList::add($HttpConnection* conn, $Instant* now, int64_t keepAlive) {
	$useLocalCurrentObjectStackCache();
	$init($ChronoUnit);
	$var($Instant, then, $nc($($nc(now)->truncatedTo($ChronoUnit::SECONDS)))->plus(keepAlive, static_cast<$TemporalUnit*>($ChronoUnit::SECONDS)));
	$var($ListIterator, li, $nc(this->list)->listIterator());
	while ($nc(li)->hasNext()) {
		$var($ConnectionPool$ExpiryEntry, entry, $cast($ConnectionPool$ExpiryEntry, li->next()));
		if ($nc(then)->isAfter($nc(entry)->expiry)) {
			li->previous();
			li->add($$new($ConnectionPool$ExpiryEntry, conn, then));
			this->mayContainEntries = true;
			return;
		}
	}
	$nc(this->list)->add($$new($ConnectionPool$ExpiryEntry, conn, then));
	this->mayContainEntries = true;
}

void ConnectionPool$ExpiryList::remove($HttpConnection* c) {
	$useLocalCurrentObjectStackCache();
	if (c == nullptr || $nc(this->list)->isEmpty()) {
		return;
	}
	$var($ListIterator, li, $nc(this->list)->listIterator());
	while ($nc(li)->hasNext()) {
		$var($ConnectionPool$ExpiryEntry, e, $cast($ConnectionPool$ExpiryEntry, li->next()));
		if ($nc($of($nc(e)->connection))->equals(c)) {
			li->remove();
			this->mayContainEntries = !$nc(this->list)->isEmpty();
			return;
		}
	}
}

$List* ConnectionPool$ExpiryList::purgeUntil($Instant* now) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->list)->isEmpty()) {
		return $Collections::emptyList();
	}
	$var($List, closelist, $new($ArrayList));
	$var($Iterator, li, $nc(this->list)->descendingIterator());
	while ($nc(li)->hasNext()) {
		$var($ConnectionPool$ExpiryEntry, entry, $cast($ConnectionPool$ExpiryEntry, li->next()));
		if (!$nc($nc(entry)->expiry)->isAfter(now)) {
			li->remove();
			$var($HttpConnection, c, entry->connection);
			closelist->add(c);
		} else {
			break;
		}
	}
	this->mayContainEntries = !$nc(this->list)->isEmpty();
	return closelist;
}

$Stream* ConnectionPool$ExpiryList::stream() {
	return $nc(this->list)->stream();
}

void ConnectionPool$ExpiryList::clear() {
	$nc(this->list)->clear();
	this->mayContainEntries = false;
}

ConnectionPool$ExpiryList::ConnectionPool$ExpiryList() {
}

$Class* ConnectionPool$ExpiryList::load$($String* name, bool initialize) {
	$loadClass(ConnectionPool$ExpiryList, name, initialize, &_ConnectionPool$ExpiryList_ClassInfo_, allocate$ConnectionPool$ExpiryList);
	return class$;
}

$Class* ConnectionPool$ExpiryList::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk