#ifndef _java_net_http_WebSocket_h_
#define _java_net_http_WebSocket_h_
//$ interface java.net.http.WebSocket
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("NORMAL_CLOSURE")
#undef NORMAL_CLOSURE

namespace java {
	namespace lang {
		class CharSequence;
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
			class CompletableFuture;
		}
	}
}

namespace java {
	namespace net {
		namespace http {

class $import WebSocket : public ::java::lang::Object {
	$interface(WebSocket, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void abort() {}
	virtual $String* getSubprotocol() {return nullptr;}
	virtual bool isInputClosed() {return false;}
	virtual bool isOutputClosed() {return false;}
	virtual void request(int64_t n) {}
	virtual ::java::util::concurrent::CompletableFuture* sendBinary(::java::nio::ByteBuffer* data, bool last) {return nullptr;}
	virtual ::java::util::concurrent::CompletableFuture* sendClose(int32_t statusCode, $String* reason) {return nullptr;}
	virtual ::java::util::concurrent::CompletableFuture* sendPing(::java::nio::ByteBuffer* message) {return nullptr;}
	virtual ::java::util::concurrent::CompletableFuture* sendPong(::java::nio::ByteBuffer* message) {return nullptr;}
	virtual ::java::util::concurrent::CompletableFuture* sendText(::java::lang::CharSequence* data, bool last) {return nullptr;}
	static const int32_t NORMAL_CLOSURE = 1000;
};

		} // http
	} // net
} // java

#pragma pop_macro("NORMAL_CLOSURE")

#endif // _java_net_http_WebSocket_h_