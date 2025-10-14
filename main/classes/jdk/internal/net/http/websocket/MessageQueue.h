#ifndef _jdk_internal_net_http_websocket_MessageQueue_h_
#define _jdk_internal_net_http_websocket_MessageQueue_h_
//$ class jdk.internal.net.http.websocket.MessageQueue
//$ extends java.lang.Object

#include <java/lang/Array.h>

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
		namespace concurrent {
			namespace atomic {
				class AtomicInteger;
			}
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
					class MessageQueue$Message;
					class MessageQueue$QueueCallback;
					class MessageQueue$Type;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class MessageQueue : public ::java::lang::Object {
	$class(MessageQueue, 0, ::java::lang::Object)
public:
	MessageQueue();
	void init$(int32_t capacity);
	void add(::jdk::internal::net::http::websocket::MessageQueue$Type* type, ::java::util::function::Supplier* binarySupplier, ::java::nio::ByteBuffer* binary, ::java::nio::CharBuffer* text, bool isLast, int32_t statusCode, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future);
	virtual void addBinary(::java::nio::ByteBuffer* message, bool isLast, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future);
	virtual void addClose(int32_t statusCode, ::java::nio::CharBuffer* reason, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future);
	virtual void addPing(::java::nio::ByteBuffer* message, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future);
	virtual void addPong(::java::nio::ByteBuffer* message, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future);
	virtual void addPong(::java::util::function::Supplier* message, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future);
	virtual void addText(::java::nio::CharBuffer* message, bool isLast, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future);
	static int32_t effectiveCapacityOf(int32_t n);
	virtual bool isEmpty();
	virtual $Object* peek(::jdk::internal::net::http::websocket::MessageQueue$QueueCallback* callback);
	virtual void remove();
	static bool $assertionsDisabled;
	$Array<::jdk::internal::net::http::websocket::MessageQueue$Message>* elements = nullptr;
	::java::util::concurrent::atomic::AtomicInteger* tail = nullptr;
	$volatile(int32_t) head = 0;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_MessageQueue_h_