#ifndef _jdk_internal_net_http_websocket_MessageStreamConsumer_h_
#define _jdk_internal_net_http_websocket_MessageStreamConsumer_h_
//$ interface jdk.internal.net.http.websocket.MessageStreamConsumer
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		class CharSequence;
		class Throwable;
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class MessageStreamConsumer : public ::java::lang::Object {
	$interface(MessageStreamConsumer, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void onBinary(::java::nio::ByteBuffer* data, bool last) {}
	virtual void onClose(int32_t statusCode, ::java::lang::CharSequence* reason) {}
	virtual void onComplete() {}
	virtual void onError($Throwable* e) {}
	virtual void onPing(::java::nio::ByteBuffer* data) {}
	virtual void onPong(::java::nio::ByteBuffer* data) {}
	virtual void onText(::java::lang::CharSequence* data, bool last) {}
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_MessageStreamConsumer_h_