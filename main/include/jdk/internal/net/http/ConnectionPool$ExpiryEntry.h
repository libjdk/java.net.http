#ifndef _jdk_internal_net_http_ConnectionPool$ExpiryEntry_h_
#define _jdk_internal_net_http_ConnectionPool$ExpiryEntry_h_
//$ class jdk.internal.net.http.ConnectionPool$ExpiryEntry
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace time {
		class Instant;
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

class $import ConnectionPool$ExpiryEntry : public ::java::lang::Object {
	$class(ConnectionPool$ExpiryEntry, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ConnectionPool$ExpiryEntry();
	void init$(::jdk::internal::net::http::HttpConnection* connection, ::java::time::Instant* expiry);
	::jdk::internal::net::http::HttpConnection* connection = nullptr;
	::java::time::Instant* expiry = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ConnectionPool$ExpiryEntry_h_