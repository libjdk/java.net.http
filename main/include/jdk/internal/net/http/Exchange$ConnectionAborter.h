#ifndef _jdk_internal_net_http_Exchange$ConnectionAborter_h_
#define _jdk_internal_net_http_Exchange$ConnectionAborter_h_
//$ class jdk.internal.net.http.Exchange$ConnectionAborter
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

class $import Exchange$ConnectionAborter : public ::java::lang::Object {
	$class(Exchange$ConnectionAborter, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Exchange$ConnectionAborter();
	void init$();
	void closeConnection();
	void connection(::jdk::internal::net::http::HttpConnection* connection);
	void disable();
	$volatile(::jdk::internal::net::http::HttpConnection*) connection$ = nullptr;
	$volatile(bool) closeRequested = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Exchange$ConnectionAborter_h_