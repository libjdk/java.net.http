#ifndef _java_net_http_WebSocket$Listener_h_
#define _java_net_http_WebSocket$Listener_h_
//$ interface java.net.http.WebSocket$Listener
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		class CharSequence;
		class Throwable;
	}
}
namespace java {
	namespace net {
		namespace http {
			class WebSocket;
		}
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletionStage;
		}
	}
}

namespace java {
	namespace net {
		namespace http {

class $import WebSocket$Listener : public ::java::lang::Object {
	$interface(WebSocket$Listener, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::java::util::concurrent::CompletionStage* onBinary(::java::net::http::WebSocket* webSocket, ::java::nio::ByteBuffer* data, bool last);
	virtual ::java::util::concurrent::CompletionStage* onClose(::java::net::http::WebSocket* webSocket, int32_t statusCode, $String* reason);
	virtual void onError(::java::net::http::WebSocket* webSocket, $Throwable* error);
	virtual void onOpen(::java::net::http::WebSocket* webSocket);
	virtual ::java::util::concurrent::CompletionStage* onPing(::java::net::http::WebSocket* webSocket, ::java::nio::ByteBuffer* message);
	virtual ::java::util::concurrent::CompletionStage* onPong(::java::net::http::WebSocket* webSocket, ::java::nio::ByteBuffer* message);
	virtual ::java::util::concurrent::CompletionStage* onText(::java::net::http::WebSocket* webSocket, ::java::lang::CharSequence* data, bool last);
};

		} // http
	} // net
} // java

#endif // _java_net_http_WebSocket$Listener_h_