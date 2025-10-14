#ifndef _jdk_internal_net_http_websocket_TransportImpl_h_
#define _jdk_internal_net_http_websocket_TransportImpl_h_
//$ class jdk.internal.net.http.websocket.TransportImpl
//$ extends jdk.internal.net.http.websocket.Transport

#include <java/lang/Array.h>
#include <jdk/internal/net/http/websocket/Transport.h>

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
		namespace concurrent {
			namespace atomic {
				class AtomicLong;
				class AtomicReference;
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
				namespace common {
					class Demand;
					class Logger;
					class SequentialScheduler;
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
					class Frame$Reader;
					class MessageDecoder;
					class MessageEncoder;
					class MessageQueue;
					class MessageStreamConsumer;
					class RawChannel;
					class RawChannel$RawEvent;
					class TransportImpl$ChannelState;
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

class TransportImpl : public ::jdk::internal::net::http::websocket::Transport {
	$class(TransportImpl, 0, ::jdk::internal::net::http::websocket::Transport)
public:
	TransportImpl();
	void init$(::jdk::internal::net::http::websocket::MessageQueue* queue, ::jdk::internal::net::http::websocket::MessageStreamConsumer* consumer, ::jdk::internal::net::http::websocket::RawChannel* channel);
	virtual void acknowledgeReception() override;
	virtual void closeInput() override;
	virtual void closeOutput() override;
	::java::nio::ByteBuffer* createWriteBuffer();
	virtual void request(int64_t n) override;
	virtual ::java::util::concurrent::CompletableFuture* sendBinary(::java::nio::ByteBuffer* message, bool isLast, Object$* attachment, ::java::util::function::BiConsumer* action) override;
	virtual ::java::util::concurrent::CompletableFuture* sendClose(int32_t statusCode, $String* reason, Object$* attachment, ::java::util::function::BiConsumer* action) override;
	virtual ::java::util::concurrent::CompletableFuture* sendPing(::java::nio::ByteBuffer* message, Object$* attachment, ::java::util::function::BiConsumer* action) override;
	virtual ::java::util::concurrent::CompletableFuture* sendPong(::java::nio::ByteBuffer* message, Object$* attachment, ::java::util::function::BiConsumer* action) override;
	virtual ::java::util::concurrent::CompletableFuture* sendPong(::java::util::function::Supplier* message, Object$* attachment, ::java::util::function::BiConsumer* action) override;
	virtual ::java::util::concurrent::CompletableFuture* sendText(::java::lang::CharSequence* message, bool isLast, Object$* attachment, ::java::util::function::BiConsumer* action) override;
	bool write();
	static bool $assertionsDisabled;
	static ::jdk::internal::net::http::common::Logger* debug;
	::java::util::concurrent::atomic::AtomicLong* counter = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* sendScheduler = nullptr;
	::jdk::internal::net::http::websocket::MessageQueue* queue = nullptr;
	::jdk::internal::net::http::websocket::MessageEncoder* encoder = nullptr;
	::java::nio::ByteBuffer* dst = nullptr;
	$Array<::java::nio::ByteBuffer>* dstArray = nullptr;
	::jdk::internal::net::http::websocket::MessageStreamConsumer* messageConsumer = nullptr;
	::jdk::internal::net::http::websocket::MessageDecoder* decoder = nullptr;
	::jdk::internal::net::http::websocket::Frame$Reader* reader = nullptr;
	::jdk::internal::net::http::common::Demand* demand = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* receiveScheduler = nullptr;
	::jdk::internal::net::http::websocket::RawChannel* channel = nullptr;
	$Object* closeLock = nullptr;
	::jdk::internal::net::http::websocket::RawChannel$RawEvent* writeEvent = nullptr;
	::jdk::internal::net::http::websocket::RawChannel$RawEvent* readEvent = nullptr;
	::java::util::concurrent::atomic::AtomicReference* writeState = nullptr;
	::java::nio::ByteBuffer* data = nullptr;
	$volatile(::jdk::internal::net::http::websocket::TransportImpl$ChannelState*) readState = nullptr;
	bool inputClosed = false;
	bool outputClosed = false;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_TransportImpl_h_