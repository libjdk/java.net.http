#ifndef _jdk_internal_net_http_Http1Response$ClientRefCountTracker_h_
#define _jdk_internal_net_http_Http1Response$ClientRefCountTracker_h_
//$ class jdk.internal.net.http.Http1Response$ClientRefCountTracker
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Http1Response;
				class HttpClientImpl;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Http1Response$ClientRefCountTracker : public ::java::lang::Object {
	$class(Http1Response$ClientRefCountTracker, 0, ::java::lang::Object)
public:
	Http1Response$ClientRefCountTracker();
	void init$(::jdk::internal::net::http::Http1Response* this$0);
	void acquire();
	void tryRelease();
	::jdk::internal::net::http::Http1Response* this$0 = nullptr;
	static bool $assertionsDisabled;
	::jdk::internal::net::http::HttpClientImpl* client = nullptr;
	int8_t state = 0;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1Response$ClientRefCountTracker_h_