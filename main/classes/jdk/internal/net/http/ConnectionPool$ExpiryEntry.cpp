#include <jdk/internal/net/http/ConnectionPool$ExpiryEntry.h>

#include <java/time/Instant.h>
#include <jdk/internal/net/http/ConnectionPool.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Instant = ::java::time::Instant;
using $ConnectionPool = ::jdk::internal::net::http::ConnectionPool;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ConnectionPool$ExpiryEntry_FieldInfo_[] = {
	{"connection", "Ljdk/internal/net/http/HttpConnection;", nullptr, $FINAL, $field(ConnectionPool$ExpiryEntry, connection)},
	{"expiry", "Ljava/time/Instant;", nullptr, $FINAL, $field(ConnectionPool$ExpiryEntry, expiry)},
	{}
};

$MethodInfo _ConnectionPool$ExpiryEntry_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpConnection;Ljava/time/Instant;)V", nullptr, 0, $method(static_cast<void(ConnectionPool$ExpiryEntry::*)($HttpConnection*,$Instant*)>(&ConnectionPool$ExpiryEntry::init$))},
	{}
};

$InnerClassInfo _ConnectionPool$ExpiryEntry_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ConnectionPool$ExpiryEntry", "jdk.internal.net.http.ConnectionPool", "ExpiryEntry", $STATIC | $FINAL},
	{}
};

$ClassInfo _ConnectionPool$ExpiryEntry_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.ConnectionPool$ExpiryEntry",
	"java.lang.Object",
	nullptr,
	_ConnectionPool$ExpiryEntry_FieldInfo_,
	_ConnectionPool$ExpiryEntry_MethodInfo_,
	nullptr,
	nullptr,
	_ConnectionPool$ExpiryEntry_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ConnectionPool"
};

$Object* allocate$ConnectionPool$ExpiryEntry($Class* clazz) {
	return $of($alloc(ConnectionPool$ExpiryEntry));
}

void ConnectionPool$ExpiryEntry::init$($HttpConnection* connection, $Instant* expiry) {
	$set(this, connection, connection);
	$set(this, expiry, expiry);
}

ConnectionPool$ExpiryEntry::ConnectionPool$ExpiryEntry() {
}

$Class* ConnectionPool$ExpiryEntry::load$($String* name, bool initialize) {
	$loadClass(ConnectionPool$ExpiryEntry, name, initialize, &_ConnectionPool$ExpiryEntry_ClassInfo_, allocate$ConnectionPool$ExpiryEntry);
	return class$;
}

$Class* ConnectionPool$ExpiryEntry::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk