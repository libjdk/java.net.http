#ifndef _jdk_internal_net_http_RequestPublishers_h_
#define _jdk_internal_net_http_RequestPublishers_h_
//$ class jdk.internal.net.http.RequestPublishers
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace net {
		namespace http {
			class HttpRequest$BodyPublisher;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export RequestPublishers : public ::java::lang::Object {
	$class(RequestPublishers, $NO_CLASS_INIT, ::java::lang::Object)
public:
	RequestPublishers();
	void init$();
	static ::java::net::http::HttpRequest$BodyPublisher* concat($Array<::java::net::http::HttpRequest$BodyPublisher>* publishers);
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RequestPublishers_h_