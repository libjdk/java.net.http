#ifndef _jdk_internal_net_http_ConnectionPool$ExpiryList_h_
#define _jdk_internal_net_http_ConnectionPool$ExpiryList_h_
//$ class jdk.internal.net.http.ConnectionPool$ExpiryList
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace time {
		class Instant;
	}
}
namespace java {
	namespace util {
		class LinkedList;
		class List;
		class Optional;
	}
}
namespace java {
	namespace util {
		namespace stream {
			class Stream;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class HttpConnection;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import ConnectionPool$ExpiryList : public ::java::lang::Object {
	$class(ConnectionPool$ExpiryList, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ConnectionPool$ExpiryList();
	void init$();
	void add(::jdk::internal::net::http::HttpConnection* conn);
	void add(::jdk::internal::net::http::HttpConnection* conn, ::java::time::Instant* now, int64_t keepAlive);
	void clear();
	::java::util::Optional* nextExpiryDeadline();
	bool purgeMaybeRequired();
	::java::util::List* purgeUntil(::java::time::Instant* now);
	void remove(::jdk::internal::net::http::HttpConnection* c);
	::jdk::internal::net::http::HttpConnection* removeOldest();
	int32_t size();
	::java::util::stream::Stream* stream();
	::java::util::LinkedList* list = nullptr;
	$volatile(bool) mayContainEntries = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ConnectionPool$ExpiryList_h_