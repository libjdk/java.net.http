#ifndef _jdk_internal_net_http_AuthenticationFilter$Cache_h_
#define _jdk_internal_net_http_AuthenticationFilter$Cache_h_
//$ class jdk.internal.net.http.AuthenticationFilter$Cache
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		class PasswordAuthentication;
		class URI;
	}
}
namespace java {
	namespace util {
		class LinkedList;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class AuthenticationFilter$CacheEntry;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import AuthenticationFilter$Cache : public ::java::lang::Object {
	$class(AuthenticationFilter$Cache, $NO_CLASS_INIT, ::java::lang::Object)
public:
	AuthenticationFilter$Cache();
	void init$();
	static bool equalsIgnoreCase($String* s1, $String* s2);
	::jdk::internal::net::http::AuthenticationFilter$CacheEntry* get(::java::net::URI* uri, bool proxy);
	void remove($String* authscheme, ::java::net::URI* domain, bool proxy);
	void remove(::jdk::internal::net::http::AuthenticationFilter$CacheEntry* entry);
	void store($String* authscheme, ::java::net::URI* domain, bool proxy, ::java::net::PasswordAuthentication* value, bool isUTF8);
	::java::util::LinkedList* entries = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_AuthenticationFilter$Cache_h_