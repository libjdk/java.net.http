#ifndef _jdk_internal_net_http_ConnectionPool_h_
#define _jdk_internal_net_http_ConnectionPool_h_
//$ class jdk.internal.net.http.ConnectionPool
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("KEEP_ALIVE")
#undef KEEP_ALIVE
#pragma push_macro("MAX_POOL_SIZE")
#undef MAX_POOL_SIZE

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace net {
		class InetSocketAddress;
	}
}
namespace java {
	namespace time {
		class Instant;
	}
}
namespace java {
	namespace util {
		class HashMap;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class ConnectionPool$CacheKey;
				class ConnectionPool$CleanupTrigger;
				class ConnectionPool$ExpiryEntry;
				class ConnectionPool$ExpiryList;
				class HttpConnection;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Logger;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import ConnectionPool : public ::java::lang::Object {
	$class(ConnectionPool, 0, ::java::lang::Object)
public:
	ConnectionPool();
	void init$(int64_t clientId);
	void init$($String* tag);
	static ::jdk::internal::net::http::ConnectionPool$CacheKey* cacheKey(::java::net::InetSocketAddress* destination, ::java::net::InetSocketAddress* proxy);
	void cleanup(::jdk::internal::net::http::HttpConnection* c, $Throwable* error);
	void close(::jdk::internal::net::http::HttpConnection* c);
	bool contains(::jdk::internal::net::http::HttpConnection* c);
	$String* dbgString();
	::jdk::internal::net::http::HttpConnection* findConnection(::jdk::internal::net::http::ConnectionPool$CacheKey* key, ::java::util::HashMap* pool);
	::jdk::internal::net::http::HttpConnection* getConnection(bool secure, ::java::net::InetSocketAddress* addr, ::java::net::InetSocketAddress* proxy);
	static ::jdk::internal::net::http::HttpConnection* lambda$stop$0(::jdk::internal::net::http::ConnectionPool$ExpiryEntry* e);
	int64_t purgeExpiredConnectionsAndReturnNextDeadline();
	int64_t purgeExpiredConnectionsAndReturnNextDeadline(::java::time::Instant* now);
	void putConnection(::jdk::internal::net::http::HttpConnection* c, ::java::util::HashMap* pool);
	::jdk::internal::net::http::ConnectionPool$CleanupTrigger* registerCleanupTrigger(::jdk::internal::net::http::HttpConnection* conn);
	bool removeFromPool(::jdk::internal::net::http::HttpConnection* c, ::java::util::HashMap* pool);
	void removeFromPool(::jdk::internal::net::http::HttpConnection* c);
	void returnToPool(::jdk::internal::net::http::HttpConnection* conn);
	void returnToPool(::jdk::internal::net::http::HttpConnection* conn, ::java::time::Instant* now, int64_t keepAlive);
	void start();
	void stop();
	static bool $assertionsDisabled;
	static int64_t KEEP_ALIVE;
	static int64_t MAX_POOL_SIZE;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	::java::util::HashMap* plainPool = nullptr;
	::java::util::HashMap* sslPool = nullptr;
	::jdk::internal::net::http::ConnectionPool$ExpiryList* expiryList = nullptr;
	$String* dbgTag = nullptr;
	bool stopped = false;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("KEEP_ALIVE")
#pragma pop_macro("MAX_POOL_SIZE")

#endif // _jdk_internal_net_http_ConnectionPool_h_