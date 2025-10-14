#ifndef _jdk_internal_net_http_HttpClientImpl$SingleFacadeFactory_h_
#define _jdk_internal_net_http_HttpClientImpl$SingleFacadeFactory_h_
//$ class jdk.internal.net.http.HttpClientImpl$SingleFacadeFactory
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class HttpClientFacade;
				class HttpClientImpl;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export HttpClientImpl$SingleFacadeFactory : public ::java::lang::Object {
	$class(HttpClientImpl$SingleFacadeFactory, 0, ::java::lang::Object)
public:
	HttpClientImpl$SingleFacadeFactory();
	void init$();
	::jdk::internal::net::http::HttpClientFacade* createFacade(::jdk::internal::net::http::HttpClientImpl* impl);
	static bool $assertionsDisabled;
	::jdk::internal::net::http::HttpClientFacade* facade = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HttpClientImpl$SingleFacadeFactory_h_