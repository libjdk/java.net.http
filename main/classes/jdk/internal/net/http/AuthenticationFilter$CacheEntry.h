#ifndef _jdk_internal_net_http_AuthenticationFilter$CacheEntry_h_
#define _jdk_internal_net_http_AuthenticationFilter$CacheEntry_h_
//$ class jdk.internal.net.http.AuthenticationFilter$CacheEntry
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		class PasswordAuthentication;
		class URI;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export AuthenticationFilter$CacheEntry : public ::java::lang::Object {
	$class(AuthenticationFilter$CacheEntry, $NO_CLASS_INIT, ::java::lang::Object)
public:
	AuthenticationFilter$CacheEntry();
	void init$($String* authscheme, ::java::net::URI* uri, bool proxy, ::java::net::PasswordAuthentication* value, bool isUTF8);
	bool equalsKey(::java::net::URI* uri, bool proxy);
	::java::net::PasswordAuthentication* value();
	$String* root = nullptr;
	$String* scheme = nullptr;
	bool proxy = false;
	::java::net::PasswordAuthentication* value$ = nullptr;
	bool isUTF8 = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_AuthenticationFilter$CacheEntry_h_