#ifndef _jdk_internal_net_http_websocket_TransportImpl$SendTask$1_h_
#define _jdk_internal_net_http_websocket_TransportImpl$SendTask$1_h_
//$ class jdk.internal.net.http.websocket.TransportImpl$SendTask$1
//$ extends jdk.internal.net.http.websocket.MessageQueue$QueueCallback

#include <jdk/internal/net/http/websocket/MessageQueue$QueueCallback.h>

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
					class TransportImpl$SendTask;
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

class TransportImpl$SendTask$1 : public ::jdk::internal::net::http::websocket::MessageQueue$QueueCallback {
	$class(TransportImpl$SendTask$1, $NO_CLASS_INIT, ::jdk::internal::net::http::websocket::MessageQueue$QueueCallback)
public:
	TransportImpl$SendTask$1();
	void init$(::jdk::internal::net::http::websocket::TransportImpl$SendTask* this$1);
	virtual $Object* onBinary(::java::nio::ByteBuffer* message, bool isLast, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future) override;
	virtual $Object* onClose(int32_t statusCode, ::java::nio::CharBuffer* reason, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future) override;
	virtual $Object* onEmpty() override;
	virtual $Object* onPing(::java::nio::ByteBuffer* message, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future) override;
	virtual $Object* onPong(::java::nio::ByteBuffer* message, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future) override;
	virtual $Object* onPong(::java::util::function::Supplier* message, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future) override;
	virtual $Object* onText(::java::nio::CharBuffer* message, bool isLast, Object$* attachment, ::java::util::function::BiConsumer* action, ::java::util::concurrent::CompletableFuture* future) override;
	::jdk::internal::net::http::websocket::TransportImpl$SendTask* this$1 = nullptr;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_TransportImpl$SendTask$1_h_