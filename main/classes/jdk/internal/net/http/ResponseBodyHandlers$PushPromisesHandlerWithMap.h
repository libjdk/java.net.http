#ifndef _jdk_internal_net_http_ResponseBodyHandlers$PushPromisesHandlerWithMap_h_
#define _jdk_internal_net_http_ResponseBodyHandlers$PushPromisesHandlerWithMap_h_
//$ class jdk.internal.net.http.ResponseBodyHandlers$PushPromisesHandlerWithMap
//$ extends java.net.http.HttpResponse$PushPromiseHandler

#include <java/net/http/HttpResponse$PushPromiseHandler.h>

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

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export ResponseBodyHandlers$PushPromisesHandlerWithMap : public ::java::net::http::HttpResponse$PushPromiseHandler {
	$class(ResponseBodyHandlers$PushPromisesHandlerWithMap, $NO_CLASS_INIT, ::java::net::http::HttpResponse$PushPromiseHandler)
public:
	ResponseBodyHandlers$PushPromisesHandlerWithMap();
	void init$(::java::util::function::Function* pushPromiseHandler, ::java::util::concurrent::ConcurrentMap* pushPromisesMap);
	virtual void applyPushPromise(::java::net::http::HttpRequest* initiatingRequest, ::java::net::http::HttpRequest* pushRequest, ::java::util::function::Function* acceptor) override;
	::java::util::concurrent::ConcurrentMap* pushPromisesMap = nullptr;
	::java::util::function::Function* pushPromiseHandler = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseBodyHandlers$PushPromisesHandlerWithMap_h_