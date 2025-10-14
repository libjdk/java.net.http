#ifndef _java_net_http_WebSocket$Builder_h_
#define _java_net_http_WebSocket$Builder_h_
//$ interface java.net.http.WebSocket$Builder
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace net {
		class URI;
	}
}
namespace java {
	namespace net {
		namespace http {
			class WebSocket$Listener;
		}
	}
}
namespace java {
	namespace time {
		class Duration;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
		}
	}
}

namespace java {
	namespace net {
		namespace http {

class $export WebSocket$Builder : public ::java::lang::Object {
	$interface(WebSocket$Builder, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::java::util::concurrent::CompletableFuture* buildAsync(::java::net::URI* uri, ::java::net::http::WebSocket$Listener* listener) {return nullptr;}
	virtual ::java::net::http::WebSocket$Builder* connectTimeout(::java::time::Duration* timeout) {return nullptr;}
	virtual ::java::net::http::WebSocket$Builder* header($String* name, $String* value) {return nullptr;}
	virtual ::java::net::http::WebSocket$Builder* subprotocols($String* mostPreferred, $StringArray* lesserPreferred) {return nullptr;}
};

		} // http
	} // net
} // java

#endif // _java_net_http_WebSocket$Builder_h_