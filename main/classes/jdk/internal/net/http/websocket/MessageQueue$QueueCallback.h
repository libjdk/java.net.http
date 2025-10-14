#ifndef _jdk_internal_net_http_websocket_MessageQueue$QueueCallback_h_
#define _jdk_internal_net_http_websocket_MessageQueue$QueueCallback_h_
//$ interface jdk.internal.net.http.websocket.MessageQueue$QueueCallback
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace nio {
		class ByteBuffer;
		class CharBuffer;
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
	namespace util {
		namespace function {
			class BiConsumer;
			class Supplier;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class MessageQueue$QueueCallback : public ::java::lang::Object {
	$interface(MessageQueue$QueueCallback, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual $Object* onBinary(::java::nio::ByteBuffer* message, bool isLast, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future) {return nullptr;}
	virtual $Object* onClose(int32_t statusCode, ::java::nio::CharBuffer* reason, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future) {return nullptr;}
	virtual $Object* onEmpty() {return nullptr;}
	virtual $Object* onPing(::java::nio::ByteBuffer* message, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future) {return nullptr;}
	virtual $Object* onPong(::java::nio::ByteBuffer* message, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future) {return nullptr;}
	virtual $Object* onPong(::java::util::function::Supplier* message, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future) {return nullptr;}
	virtual $Object* onText(::java::nio::CharBuffer* message, bool isLast, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future) {return nullptr;}
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_MessageQueue$QueueCallback_h_