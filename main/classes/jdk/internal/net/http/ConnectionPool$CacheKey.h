#ifndef _jdk_internal_net_http_ConnectionPool$CacheKey_h_
#define _jdk_internal_net_http_ConnectionPool$CacheKey_h_
//$ class jdk.internal.net.http.ConnectionPool$CacheKey
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		class InetSocketAddress;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export ConnectionPool$CacheKey : public ::java::lang::Object {
	$class(ConnectionPool$CacheKey, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ConnectionPool$CacheKey();
	void init$(::java::net::InetSocketAddress* destination, ::java::net::InetSocketAddress* proxy);
	virtual bool equals(Object$* obj) override;
	virtual int32_t hashCode() override;
	::java::net::InetSocketAddress* proxy = nullptr;
	::java::net::InetSocketAddress* destination = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ConnectionPool$CacheKey_h_