#ifndef _jdk_internal_net_http_websocket_MessageQueue$Message_h_
#define _jdk_internal_net_http_websocket_MessageQueue$Message_h_
//$ class jdk.internal.net.http.websocket.MessageQueue$Message
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

class MessageQueue$Message : public ::java::lang::Object {
	$class(MessageQueue$Message, $NO_CLASS_INIT, ::java::lang::Object)
public:
	MessageQueue$Message();
	void init$();
	$volatile(bool) ready = false;
	::jdk::internal::net::http::websocket::MessageQueue$Type* type = nullptr;
	::java::util::function::Supplier* binarySupplier = nullptr;
	::java::nio::ByteBuffer* binary = nullptr;
	::java::nio::CharBuffer* text = nullptr;
	bool isLast = false;
	int32_t statusCode = 0;
	$Object* attachment = nullptr;
	::java::util::function::BiConsumer* action = nullptr;
	::java::util::concurrent::CompletableFuture* future = nullptr;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_MessageQueue$Message_h_