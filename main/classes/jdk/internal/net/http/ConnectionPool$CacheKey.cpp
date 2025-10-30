#include <jdk/internal/net/http/ConnectionPool$CacheKey.h>

#include <java/net/InetSocketAddress.h>
#include <java/util/Objects.h>
#include <jdk/internal/net/http/ConnectionPool.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $Objects = ::java::util::Objects;
using $ConnectionPool = ::jdk::internal::net::http::ConnectionPool;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ConnectionPool$CacheKey_FieldInfo_[] = {
	{"proxy", "Ljava/net/InetSocketAddress;", nullptr, $FINAL, $field(ConnectionPool$CacheKey, proxy)},
	{"destination", "Ljava/net/InetSocketAddress;", nullptr, $FINAL, $field(ConnectionPool$CacheKey, destination)},
	{}
};

$MethodInfo _ConnectionPool$CacheKey_MethodInfo_[] = {
	{"<init>", "(Ljava/net/InetSocketAddress;Ljava/net/InetSocketAddress;)V", nullptr, 0, $method(static_cast<void(ConnectionPool$CacheKey::*)($InetSocketAddress*,$InetSocketAddress*)>(&ConnectionPool$CacheKey::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _ConnectionPool$CacheKey_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ConnectionPool$CacheKey", "jdk.internal.net.http.ConnectionPool", "CacheKey", $STATIC},
	{}
};

$ClassInfo _ConnectionPool$CacheKey_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.ConnectionPool$CacheKey",
	"java.lang.Object",
	nullptr,
	_ConnectionPool$CacheKey_FieldInfo_,
	_ConnectionPool$CacheKey_MethodInfo_,
	nullptr,
	nullptr,
	_ConnectionPool$CacheKey_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ConnectionPool"
};

$Object* allocate$ConnectionPool$CacheKey($Class* clazz) {
	return $of($alloc(ConnectionPool$CacheKey));
}

void ConnectionPool$CacheKey::init$($InetSocketAddress* destination, $InetSocketAddress* proxy) {
	$set(this, proxy, proxy);
	$set(this, destination, destination);
}

bool ConnectionPool$CacheKey::equals(Object$* obj) {
	if (obj == nullptr) {
		return false;
	}
	if ($of(this)->getClass() != $nc($of(obj))->getClass()) {
		return false;
	}
	$var(ConnectionPool$CacheKey, other, $cast(ConnectionPool$CacheKey, obj));
	if (!$Objects::equals(this->proxy, $nc(other)->proxy)) {
		return false;
	}
	if (!$Objects::equals(this->destination, $nc(other)->destination)) {
		return false;
	}
	return true;
}

int32_t ConnectionPool$CacheKey::hashCode() {
	return $Objects::hash($$new($ObjectArray, {
		$of(this->proxy),
		$of(this->destination)
	}));
}

ConnectionPool$CacheKey::ConnectionPool$CacheKey() {
}

$Class* ConnectionPool$CacheKey::load$($String* name, bool initialize) {
	$loadClass(ConnectionPool$CacheKey, name, initialize, &_ConnectionPool$CacheKey_ClassInfo_, allocate$ConnectionPool$CacheKey);
	return class$;
}

$Class* ConnectionPool$CacheKey::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk