#ifndef _jdk_internal_net_http_websocket_WebSocketImpl_h_
#define _jdk_internal_net_http_websocket_WebSocketImpl_h_
//$ class jdk.internal.net.http.websocket.WebSocketImpl
//$ extends java.net.http.WebSocket

#include <java/net/http/WebSocket.h>

#pragma push_macro("DONE")
#undef DONE

namespace java {
	namespace lang {
		class CharSequence;
		class Throwable;
	}
}
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
				class AtomicBoolean;
				class AtomicLong;
				class AtomicReference;
			}
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
					class MinimalFuture;
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
					class BuilderImpl;
					class OpeningHandshake$Result;
					class Transport;
					class TransportFactory;
					class WebSocketImpl$State;
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

class WebSocketImpl : public ::java::net::http::WebSocket {
	$class(WebSocketImpl, 0, ::java::net::http::WebSocket)
public:
	WebSocketImpl();
	void init$(::java::net::URI* uri, $String* subprotocol, ::java::net::http::WebSocket$Listener* listener, ::jdk::internal::net::http::websocket::TransportFactory* transportFactory);
	virtual void abort() override;
	::java::nio::ByteBuffer* clearAutomaticPong();
	void clearPendingPingOrPong();
	void clearPendingTextOrBinary();
	void close();
	virtual $String* getSubprotocol() override;
	virtual bool isInputClosed() override;
	static bool isLegalReason($String* reason);
	virtual bool isOutputClosed() override;
	static ::java::net::http::WebSocket* lambda$newInstanceAsync$0(::jdk::internal::net::http::websocket::BuilderImpl* b, ::jdk::internal::net::http::websocket::OpeningHandshake$Result* r);
	void lambda$sendClose0$5(::java::net::http::WebSocket* r, $Throwable* e);
	static void lambda$sendCloseSilently$6(::java::net::http::WebSocket* r, $Throwable* e);
	void lambda$sendPing$3(::java::net::http::WebSocket* r, $Throwable* e);
	void lambda$sendText$1(::java::net::http::WebSocket* r, $Throwable* e);
	static ::jdk::internal::net::http::websocket::WebSocketImpl* newInstance(::java::net::URI* uri, $String* subprotocol, ::java::net::http::WebSocket$Listener* listener, ::jdk::internal::net::http::websocket::TransportFactory* transport);
	static ::java::util::concurrent::CompletableFuture* newInstanceAsync(::jdk::internal::net::http::websocket::BuilderImpl* b);
	void processCloseError($Throwable* e);
	::java::util::concurrent::CompletableFuture* replaceNull(::java::util::concurrent::CompletableFuture* cf);
	virtual void request(int64_t n) override;
	virtual ::java::util::concurrent::CompletableFuture* sendBinary(::java::nio::ByteBuffer* message, bool last) override;
	virtual ::java::util::concurrent::CompletableFuture* sendClose(int32_t statusCode, $String* reason) override;
	::java::util::concurrent::CompletableFuture* sendClose0(int32_t statusCode, $String* reason);
	void sendCloseSilently(int32_t statusCode);
	virtual ::java::util::concurrent::CompletableFuture* sendPing(::java::nio::ByteBuffer* message) override;
	virtual ::java::util::concurrent::CompletableFuture* sendPong(::java::nio::ByteBuffer* message) override;
	virtual ::java::util::concurrent::CompletableFuture* sendText(::java::lang::CharSequence* message, bool last) override;
	bool setPendingPingOrPong();
	bool setPendingTextOrBinary();
	void signalClose(int32_t statusCode, $String* reason);
	void signalError($Throwable* error);
	void signalOpen();
	virtual $String* toString() override;
	::jdk::internal::net::http::websocket::Transport* transport();
	bool tryChangeState(::jdk::internal::net::http::websocket::WebSocketImpl$State* expectedState, ::jdk::internal::net::http::websocket::WebSocketImpl$State* newState);
	bool trySetState(::jdk::internal::net::http::websocket::WebSocketImpl$State* newState);
	bool trySwapAutomaticPong(::java::nio::ByteBuffer* copy);
	static ::jdk::internal::net::http::common::Logger* debug;
	::java::util::concurrent::atomic::AtomicLong* sendCounter = nullptr;
	::java::util::concurrent::atomic::AtomicLong* receiveCounter = nullptr;
	::java::util::concurrent::atomic::AtomicReference* lastAutomaticPong = nullptr;
	::jdk::internal::net::http::common::MinimalFuture* DONE = nullptr;
	$volatile(bool) inputClosed = false;
	::java::util::concurrent::atomic::AtomicBoolean* outputClosed = nullptr;
	::java::util::concurrent::atomic::AtomicReference* state = nullptr;
	bool last = false;
	::java::nio::ByteBuffer* binaryData = nullptr;
	::java::lang::CharSequence* text = nullptr;
	int32_t statusCode = 0;
	$String* reason = nullptr;
	::java::util::concurrent::atomic::AtomicReference* error = nullptr;
	::java::net::URI* uri = nullptr;
	$String* subprotocol = nullptr;
	::java::net::http::WebSocket$Listener* listener = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* pendingTextOrBinary = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* pendingPingOrPong = nullptr;
	::jdk::internal::net::http::websocket::Transport* transport$ = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* receiveScheduler = nullptr;
	::jdk::internal::net::http::common::Demand* demand = nullptr;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("DONE")

#endif // _jdk_internal_net_http_websocket_WebSocketImpl_h_