#ifndef _jdk_internal_net_http_websocket_Transport_h_
#define _jdk_internal_net_http_websocket_Transport_h_
//$ interface jdk.internal.net.http.websocket.Transport
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

class Transport : public ::java::lang::Object {
	$interface(Transport, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void acknowledgeReception() {}
	virtual void closeInput() {}
	virtual void closeOutput() {}
	virtual void request(int64_t n) {}
	virtual ::java::util::concurrent::CompletableFuture* sendBinary(::java::nio::ByteBuffer* message, bool isLast, Object$* attachment, ::java::util::function::BiConsumer* action) {return nullptr;}
	virtual ::java::util::concurrent::CompletableFuture* sendClose(int32_t statusCode, $String* reason, Object$* attachment, ::java::util::function::BiConsumer* action) {return nullptr;}
	virtual ::java::util::concurrent::CompletableFuture* sendPing(::java::nio::ByteBuffer* message, Object$* attachment, ::java::util::function::BiConsumer* action) {return nullptr;}
	virtual ::java::util::concurrent::CompletableFuture* sendPong(::java::nio::ByteBuffer* message, Object$* attachment, ::java::util::function::BiConsumer* action) {return nullptr;}
	virtual ::java::util::concurrent::CompletableFuture* sendPong(::java::util::function::Supplier* message, Object$* attachment, ::java::util::function::BiConsumer* action) {return nullptr;}
	virtual ::java::util::concurrent::CompletableFuture* sendText(::java::lang::CharSequence* message, bool isLast, Object$* attachment, ::java::util::function::BiConsumer* action) {return nullptr;}
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_Transport_h_