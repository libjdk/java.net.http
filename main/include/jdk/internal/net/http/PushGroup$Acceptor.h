#ifndef _jdk_internal_net_http_PushGroup$Acceptor_h_
#define _jdk_internal_net_http_PushGroup$Acceptor_h_
//$ interface jdk.internal.net.http.PushGroup$Acceptor
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		namespace http {
			class HttpResponse$BodyHandler;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import PushGroup$Acceptor : public ::java::lang::Object {
	$interface(PushGroup$Acceptor, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual bool accepted() {return false;}
	virtual ::java::net::http::HttpResponse$BodyHandler* bodyHandler() {return nullptr;}
	virtual ::java::util::concurrent::CompletableFuture* cf() {return nullptr;}
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_PushGroup$Acceptor_h_