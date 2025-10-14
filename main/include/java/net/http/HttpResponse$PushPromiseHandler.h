#ifndef _java_net_http_HttpResponse$PushPromiseHandler_h_
#define _java_net_http_HttpResponse$PushPromiseHandler_h_
//$ interface java.net.http.HttpResponse$PushPromiseHandler
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		namespace http {
			class HttpRequest;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class ConcurrentMap;
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Function;
		}
	}
}

namespace java {
	namespace net {
		namespace http {

class $import HttpResponse$PushPromiseHandler : public ::java::lang::Object {
	$interface(HttpResponse$PushPromiseHandler, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void applyPushPromise(::java::net::http::HttpRequest* initiatingRequest, ::java::net::http::HttpRequest* pushPromiseRequest, ::java::util::function::Function* acceptor) {}
	static ::java::net::http::HttpResponse$PushPromiseHandler* of(::java::util::function::Function* pushPromiseHandler, ::java::util::concurrent::ConcurrentMap* pushPromisesMap);
};

		} // http
	} // net
} // java

#endif // _java_net_http_HttpResponse$PushPromiseHandler_h_