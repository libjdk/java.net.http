#ifndef _jdk_internal_net_http_AuthenticationFilter$AuthInfo_h_
#define _jdk_internal_net_http_AuthenticationFilter$AuthInfo_h_
//$ class jdk.internal.net.http.AuthenticationFilter$AuthInfo
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		class PasswordAuthentication;
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

class $import AuthenticationFilter$AuthInfo : public ::java::lang::Object {
	$class(AuthenticationFilter$AuthInfo, 0, ::java::lang::Object)
public:
	AuthenticationFilter$AuthInfo();
	void init$(bool fromcache, $String* scheme, ::java::net::PasswordAuthentication* credentials, bool isUTF8);
	void init$(bool fromcache, $String* scheme, ::java::net::PasswordAuthentication* credentials, ::jdk::internal::net::http::AuthenticationFilter$CacheEntry* ca, bool isUTF8);
	virtual ::jdk::internal::net::http::AuthenticationFilter$AuthInfo* retryWithCredentials(::java::net::PasswordAuthentication* pw, bool isUTF8);
	static bool $assertionsDisabled;
	bool fromcache = false;
	$String* scheme = nullptr;
	int32_t retries = 0;
	::java::net::PasswordAuthentication* credentials = nullptr;
	::jdk::internal::net::http::AuthenticationFilter$CacheEntry* cacheEntry = nullptr;
	bool isUTF8 = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_AuthenticationFilter$AuthInfo_h_