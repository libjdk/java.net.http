#ifndef _jdk_internal_net_http_Http2Connection_h_
#define _jdk_internal_net_http_Http2Connection_h_
//$ class jdk.internal.net.http.Http2Connection
//$ extends java.lang.Object

#include <java/lang/Array.h>
#include <java/lang/Integer.h>

#pragma push_macro("BUFFER")
#undef BUFFER
#pragma push_macro("CLIENT_PREFACE")
#undef CLIENT_PREFACE
#pragma push_macro("DEBUG_LOGGER")
#undef DEBUG_LOGGER
#pragma push_macro("DEFAULT_FRAME_SIZE")
#undef DEFAULT_FRAME_SIZE
#pragma push_macro("EMPTY_TRIGGER")
#undef EMPTY_TRIGGER
#pragma push_macro("MAX_CLIENT_STREAM_ID")
#undef MAX_CLIENT_STREAM_ID
#pragma push_macro("MAX_SERVER_STREAM_ID")
#undef MAX_SERVER_STREAM_ID
#pragma push_macro("MAX_VALUE")
#undef MAX_VALUE
#pragma push_macro("PREFACE_BYTES")
#undef PREFACE_BYTES

namespace java {
	namespace lang {
		class Throwable;
		class Void;
	}
}
namespace java {
	namespace net {
		class InetSocketAddress;
		class URI;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpHeaders;
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
		class List;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
			class CompletionStage;
			class ConcurrentMap;
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Supplier;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class AbstractAsyncSSLConnection;
				class Exchange;
				class Http2ClientImpl;
				class Http2Connection$ConnectionWindowUpdateSender;
				class Http2Connection$FramesController;
				class Http2Connection$Http2TubeSubscriber;
				class HttpClientImpl;
				class HttpConnection;
				class HttpConnection$HttpPublisher;
				class HttpRequestImpl;
				class Stream;
				class Stream$PushedStream;
				class WindowController;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Logger;
				}
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {
					class DataFrame;
					class FramesDecoder;
					class FramesEncoder;
					class GoAwayFrame;
					class HeaderFrame;
					class Http2Frame;
					class OutgoingHeaders;
					class PingFrame;
					class PushPromiseFrame;
					class SettingsFrame;
					class WindowUpdateFrame;
				}
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {
					class Decoder;
					class DecodingCallback;
					class Encoder;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Http2Connection : public ::java::lang::Object {
	$class(Http2Connection, 0, ::java::lang::Object)
public:
	Http2Connection();
	void init$(::jdk::internal::net::http::HttpConnection* connection, ::jdk::internal::net::http::Http2ClientImpl* client2, int32_t nextstreamid, $String* key);
	void init$(::jdk::internal::net::http::HttpConnection* connection, ::jdk::internal::net::http::Http2ClientImpl* client2, ::jdk::internal::net::http::Exchange* exchange, ::java::util::function::Supplier* initial);
	void init$(::jdk::internal::net::http::HttpRequestImpl* request, ::jdk::internal::net::http::Http2ClientImpl* h2client, ::jdk::internal::net::http::HttpConnection* connection);
	void asyncReceive(::java::nio::ByteBuffer* buffer);
	static ::java::util::concurrent::CompletableFuture* checkSSLConfig(::jdk::internal::net::http::AbstractAsyncSSLConnection* aconn);
	::jdk::internal::net::http::HttpClientImpl* client();
	virtual void close();
	virtual void closeStream(int32_t streamid);
	void connectFlows(::jdk::internal::net::http::HttpConnection* connection);
	static ::java::util::concurrent::CompletableFuture* createAsync(::jdk::internal::net::http::HttpConnection* connection, ::jdk::internal::net::http::Http2ClientImpl* client2, ::jdk::internal::net::http::Exchange* exchange, ::java::util::function::Supplier* initial);
	static ::java::util::concurrent::CompletableFuture* createAsync(::jdk::internal::net::http::HttpRequestImpl* request, ::jdk::internal::net::http::Http2ClientImpl* h2client, ::jdk::internal::net::http::Exchange* exchange);
	virtual ::jdk::internal::net::http::Stream$PushedStream* createPushStream(::jdk::internal::net::http::Stream* parent, ::jdk::internal::net::http::Exchange* pushEx);
	::jdk::internal::net::http::Stream* createStream(::jdk::internal::net::http::Exchange* exchange);
	$String* dbgString();
	void decodeHeaders(::jdk::internal::net::http::frame::HeaderFrame* frame, ::jdk::internal::net::http::hpack::DecodingCallback* decoder);
	virtual void decrementStreamsCount(int32_t streamid);
	void dropDataFrame(::jdk::internal::net::http::frame::DataFrame* df);
	::java::util::List* encodeFrame(::jdk::internal::net::http::frame::Http2Frame* frame);
	::java::util::List* encodeFrames(::java::util::List* frames);
	::java::util::List* encodeHeaders(::jdk::internal::net::http::frame::OutgoingHeaders* frame);
	::java::util::List* encodeHeaders(::jdk::internal::net::http::frame::OutgoingHeaders* oh, ::jdk::internal::net::http::Stream* stream);
	::java::util::List* encodeHeadersImpl(int32_t bufferSize, $Array<::java::net::http::HttpHeaders>* headers);
	void ensureWindowUpdated(::jdk::internal::net::http::frame::DataFrame* df);
	virtual bool finalStream();
	::java::nio::ByteBuffer* getHeaderBuffer(int32_t size);
	int32_t getInitialSendWindowSize();
	virtual int32_t getMaxReceiveFrameSize();
	virtual int32_t getMaxSendFrameSize();
	virtual $Throwable* getRecordedCause();
	virtual ::jdk::internal::net::http::Stream* getStream(int32_t streamid);
	void handleConnectionFrame(::jdk::internal::net::http::frame::Http2Frame* frame);
	void handleGoAway(::jdk::internal::net::http::frame::GoAwayFrame* frame);
	void handlePing(::jdk::internal::net::http::frame::PingFrame* frame);
	void handlePushPromise(::jdk::internal::net::http::Stream* parent, ::jdk::internal::net::http::frame::PushPromiseFrame* pp);
	void handleSettings(::jdk::internal::net::http::frame::SettingsFrame* frame);
	void handleWindowUpdate(::jdk::internal::net::http::frame::WindowUpdateFrame* f);
	virtual bool isActive();
	static bool isServerInitiatedStream(int32_t streamid);
	virtual $String* key();
	static $String* keyFor(::jdk::internal::net::http::HttpConnection* connection);
	static $String* keyFor(::java::net::URI* uri, ::java::net::InetSocketAddress* proxy);
	static $String* keyString(bool secure, ::java::net::InetSocketAddress* proxy, $String* host, int32_t port);
	static $String* lambda$asyncReceive$6(int64_t c, ::java::nio::ByteBuffer* b);
	static ::java::util::concurrent::CompletableFuture* lambda$checkSSLConfig$4(::jdk::internal::net::http::AbstractAsyncSSLConnection* aconn, $String* alpn);
	static void lambda$checkSSLConfig$5(::jdk::internal::net::http::AbstractAsyncSSLConnection* aconn, $String* r, $Throwable* t);
	static ::jdk::internal::net::http::Http2Connection* lambda$createAsync$0(::jdk::internal::net::http::HttpConnection* connection, ::jdk::internal::net::http::Http2ClientImpl* client2, ::jdk::internal::net::http::Exchange* exchange, ::java::util::function::Supplier* initial);
	static ::java::util::concurrent::CompletionStage* lambda$createAsync$1(::jdk::internal::net::http::AbstractAsyncSSLConnection* connection, ::java::lang::Void* unused);
	static ::java::util::concurrent::CompletionStage* lambda$createAsync$2(::jdk::internal::net::http::AbstractAsyncSSLConnection* connection, ::java::lang::Void* unused);
	static ::java::util::concurrent::CompletionStage* lambda$createAsync$3(::jdk::internal::net::http::HttpRequestImpl* request, ::jdk::internal::net::http::Http2ClientImpl* h2client, ::jdk::internal::net::http::AbstractAsyncSSLConnection* connection, Object$* notused);
	static void lambda$encodeFrames$9(::jdk::internal::net::http::frame::HeaderFrame* f);
	static $String* lambda$processFrame$8(::jdk::internal::net::http::frame::Http2Frame* frame);
	$String* lambda$shutdown$7($Throwable* t);
	void markStream(int32_t streamid, int32_t code);
	int32_t maxConcurrentClientInitiatedStreams();
	int32_t maxConcurrentServerInitiatedStreams();
	virtual bool offerConnection();
	virtual void processFrame(::jdk::internal::net::http::frame::Http2Frame* frame);
	void protocolError(int32_t errorCode);
	void protocolError(int32_t errorCode, $String* msg);
	::jdk::internal::net::http::HttpConnection$HttpPublisher* publisher();
	virtual void putStream(::jdk::internal::net::http::Stream* stream, int32_t streamid);
	::jdk::internal::net::http::Stream* registerNewStream(::jdk::internal::net::http::frame::OutgoingHeaders* oh);
	virtual bool reserveStream(bool clientInitiated);
	virtual void resetStream(int32_t streamid, int32_t code);
	void sendConnectionPreface();
	virtual void sendDataFrame(::jdk::internal::net::http::frame::DataFrame* frame);
	virtual void sendFrame(::jdk::internal::net::http::frame::Http2Frame* frame);
	virtual void sendUnorderedFrame(::jdk::internal::net::http::frame::Http2Frame* frame);
	virtual void setFinalStream();
	virtual void shutdown($Throwable* t);
	virtual $String* toString() override;
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	static ::jdk::internal::net::http::common::Logger* DEBUG_LOGGER;
	::jdk::internal::net::http::common::Logger* debugHpack = nullptr;
	static ::java::nio::ByteBuffer* EMPTY_TRIGGER;
	static const int32_t MAX_CLIENT_STREAM_ID = ::java::lang::Integer::MAX_VALUE;
	static const int32_t MAX_SERVER_STREAM_ID = 0x7FFFFFFE; // ::java::lang::Integer::MAX_VALUE - 1
	static const int32_t BUFFER = 8;
	bool finalStream$ = false;
	$volatile(bool) closed = false;
	::jdk::internal::net::http::HttpConnection* connection = nullptr;
	::jdk::internal::net::http::Http2ClientImpl* client2 = nullptr;
	::java::util::concurrent::ConcurrentMap* streams = nullptr;
	int32_t nextstreamid = 0;
	int32_t nextPushStream = 0;
	int32_t lastReservedClientStreamid = 0;
	int32_t lastReservedServerStreamid = 0;
	int32_t numReservedClientStreams = 0;
	int32_t numReservedServerStreams = 0;
	::jdk::internal::net::http::hpack::Encoder* hpackOut = nullptr;
	::jdk::internal::net::http::hpack::Decoder* hpackIn = nullptr;
	::jdk::internal::net::http::frame::SettingsFrame* clientSettings = nullptr;
	$volatile(::jdk::internal::net::http::frame::SettingsFrame*) serverSettings = nullptr;
	$String* key$ = nullptr;
	::jdk::internal::net::http::frame::FramesDecoder* framesDecoder = nullptr;
	::jdk::internal::net::http::frame::FramesEncoder* framesEncoder = nullptr;
	::jdk::internal::net::http::WindowController* windowController = nullptr;
	::jdk::internal::net::http::Http2Connection$FramesController* framesController = nullptr;
	::jdk::internal::net::http::Http2Connection$Http2TubeSubscriber* subscriber = nullptr;
	::jdk::internal::net::http::Http2Connection$ConnectionWindowUpdateSender* windowUpdater = nullptr;
	$volatile($Throwable*) cause = nullptr;
	$volatile(::java::util::function::Supplier*) initial = nullptr;
	static const int32_t DEFAULT_FRAME_SIZE = 16384; // 16 * 1024
	int64_t count = 0;
	static $String* CLIENT_PREFACE;
	static $bytes* PREFACE_BYTES;
	$Object* sendlock = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("BUFFER")
#pragma pop_macro("CLIENT_PREFACE")
#pragma pop_macro("DEBUG_LOGGER")
#pragma pop_macro("DEFAULT_FRAME_SIZE")
#pragma pop_macro("EMPTY_TRIGGER")
#pragma pop_macro("MAX_CLIENT_STREAM_ID")
#pragma pop_macro("MAX_SERVER_STREAM_ID")
#pragma pop_macro("MAX_VALUE")
#pragma pop_macro("PREFACE_BYTES")

#endif // _jdk_internal_net_http_Http2Connection_h_