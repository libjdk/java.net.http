#ifndef _jdk_internal_net_http_Stream_h_
#define _jdk_internal_net_http_Stream_h_
//$ class jdk.internal.net.http.Stream
//$ extends jdk.internal.net.http.ExchangeImpl

#include <jdk/internal/net/http/ExchangeImpl.h>

#pragma push_macro("COMPLETED")
#undef COMPLETED
#pragma push_macro("DEREGISTERED")
#undef DEREGISTERED
#pragma push_macro("STREAM_STATE")
#undef STREAM_STATE

namespace java {
	namespace io {
		class IOException;
	}
}
namespace java {
	namespace lang {
		class Throwable;
		class Void;
	}
}
namespace java {
	namespace lang {
		namespace invoke {
			class VarHandle;
		}
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpHeaders;
			class HttpRequest;
			class HttpRequest$BodyPublisher;
			class HttpResponse;
			class HttpResponse$BodyHandler;
			class HttpResponse$BodySubscriber;
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
			class ConcurrentLinkedQueue;
			class Executor;
			class Flow$Subscriber;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicReference;
			}
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class BiPredicate;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Exchange;
				class Http2Connection;
				class HttpConnection;
				class HttpRequestImpl;
				class PushGroup;
				class Response;
				class Stream$HeadersConsumer;
				class Stream$PushedStream;
				class Stream$RequestSubscriber;
				class WindowController;
				class WindowUpdateSender;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class HttpHeadersBuilder;
					class Logger;
					class SequentialScheduler;
					class SubscriptionBase;
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
					class Http2Frame;
					class OutgoingHeaders;
					class PriorityFrame;
					class ResetFrame;
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
					class DecodingCallback;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Stream : public ::jdk::internal::net::http::ExchangeImpl {
	$class(Stream, 0, ::jdk::internal::net::http::ExchangeImpl)
public:
	Stream();
	void init$(::jdk::internal::net::http::Http2Connection* connection, ::jdk::internal::net::http::Exchange* e, ::jdk::internal::net::http::WindowController* windowController);
	virtual void cancel() override;
	virtual void cancel(::java::io::IOException* cause) override;
	virtual void cancelImpl($Throwable* e);
	bool checkRequestCancelled();
	virtual void close();
	virtual void completeResponse(::jdk::internal::net::http::Response* resp);
	virtual void completeResponseExceptionally($Throwable* t);
	virtual void completed() override;
	virtual ::jdk::internal::net::http::HttpConnection* connection() override;
	virtual void connectionClosing($Throwable* cause);
	bool consumed(::jdk::internal::net::http::frame::DataFrame* df);
	static ::java::net::http::HttpHeaders* createPseudoHeaders(::java::net::http::HttpRequest* request);
	$String* dbgString();
	virtual bool deRegister();
	void drainInputQueue();
	bool endStreamReceived();
	::java::net::http::HttpHeaders* filterHeaders(::java::net::http::HttpHeaders* headers);
	virtual $Throwable* getCancelCause() override;
	virtual ::jdk::internal::net::http::frame::DataFrame* getDataFrame(::java::nio::ByteBuffer* buffer);
	::jdk::internal::net::http::frame::DataFrame* getEmptyEndStreamDataFrame();
	virtual ::java::net::http::HttpHeaders* getRequestPseudoHeaders();
	virtual ::java::util::concurrent::CompletableFuture* getResponseAsync(::java::util::concurrent::Executor* executor) override;
	virtual void handleReset(::jdk::internal::net::http::frame::ResetFrame* frame, ::java::util::concurrent::Flow$Subscriber* subscriber);
	virtual void handleResponse();
	bool hasProxyAuthorization(::java::net::http::HttpHeaders* headers);
	::jdk::internal::net::http::frame::OutgoingHeaders* headerFrame(int64_t contentLength);
	virtual ::java::util::concurrent::CompletableFuture* ignoreBody() override;
	virtual void incoming(::jdk::internal::net::http::frame::Http2Frame* frame);
	virtual void incoming_priority(::jdk::internal::net::http::frame::PriorityFrame* frame);
	virtual void incoming_pushPromise(::jdk::internal::net::http::HttpRequestImpl* pushRequest, ::jdk::internal::net::http::Stream$PushedStream* pushStream);
	virtual void incoming_reset(::jdk::internal::net::http::frame::ResetFrame* frame);
	void incoming_windowUpdate(::jdk::internal::net::http::frame::WindowUpdateFrame* frame);
	virtual bool isCanceled() override;
	static ::jdk::internal::net::http::Response* lambda$getResponseAsync$5(::jdk::internal::net::http::Response* r);
	static void lambda$getResponseAsync$6(::jdk::internal::net::http::PushGroup* pg, ::jdk::internal::net::http::Response* t, $Throwable* e);
	static ::java::io::IOException* lambda$handleResponse$2();
	static bool lambda$headerFrame$4(::java::net::http::HttpHeaders* uh, $String* k, $String* v);
	static void lambda$incoming_pushPromise$3(::jdk::internal::net::http::Stream$PushedStream* pushStream, ::jdk::internal::net::http::PushGroup* pushGroup, ::java::util::concurrent::CompletableFuture* pushResponseCF, ::java::net::http::HttpResponse* resp, $Throwable* t);
	static void lambda$readBodyAsync$0(::jdk::internal::net::http::PushGroup* pg, Object$* t, $Throwable* e);
	::jdk::internal::net::http::ExchangeImpl* lambda$sendBodyAsync$1(::java::lang::Void* v);
	void lambda$sendBodyImpl$7(::java::lang::Void* v, $Throwable* t);
	virtual int32_t markStream(int32_t code);
	bool needsFiltering(::java::net::http::HttpHeaders* headers, ::java::util::function::BiPredicate* filter);
	virtual void nullBody(::java::net::http::HttpResponse* resp, $Throwable* t) override;
	virtual void onSubscriptionError($Throwable* t);
	virtual void otherFrame(::jdk::internal::net::http::frame::Http2Frame* frame);
	virtual ::java::util::concurrent::CompletableFuture* readBodyAsync(::java::net::http::HttpResponse$BodyHandler* handler, bool returnConnectionToPool, ::java::util::concurrent::Executor* executor) override;
	virtual ::java::util::concurrent::CompletableFuture* receiveData(::java::net::http::HttpResponse$BodySubscriber* bodySubscriber, ::java::util::concurrent::Executor* executor);
	void receiveDataFrame(::jdk::internal::net::http::frame::DataFrame* df);
	void receiveResetFrame(::jdk::internal::net::http::frame::ResetFrame* frame);
	virtual bool registerStream(int32_t id, bool registerIfCancelled);
	virtual void released() override;
	virtual void requestSent();
	virtual void responseReceived();
	virtual ::jdk::internal::net::http::hpack::DecodingCallback* rspHeadersConsumer();
	void schedule();
	virtual ::java::util::concurrent::CompletableFuture* sendBodyAsync() override;
	virtual ::java::util::concurrent::CompletableFuture* sendBodyImpl();
	virtual void sendCancelStreamFrame();
	void sendDataFrame(::jdk::internal::net::http::frame::DataFrame* frame);
	virtual ::java::util::concurrent::CompletableFuture* sendHeadersAsync() override;
	virtual void setEndStreamReceived();
	virtual void signalWindowUpdate();
	virtual $String* toString() override;
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	::java::util::concurrent::ConcurrentLinkedQueue* inputQ = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* sched = nullptr;
	::jdk::internal::net::http::common::SubscriptionBase* userSubscription = nullptr;
	$volatile(int32_t) streamid = 0;
	int64_t requestContentLen = 0;
	::jdk::internal::net::http::Http2Connection* connection$ = nullptr;
	::jdk::internal::net::http::HttpRequestImpl* request = nullptr;
	::jdk::internal::net::http::Stream$HeadersConsumer* rspHeadersConsumer$ = nullptr;
	::jdk::internal::net::http::common::HttpHeadersBuilder* responseHeadersBuilder = nullptr;
	::java::net::http::HttpHeaders* requestPseudoHeaders = nullptr;
	$volatile(::java::net::http::HttpResponse$BodySubscriber*) responseSubscriber = nullptr;
	::java::net::http::HttpRequest$BodyPublisher* requestPublisher = nullptr;
	$volatile(::jdk::internal::net::http::Stream$RequestSubscriber*) requestSubscriber = nullptr;
	$volatile(int32_t) responseCode = 0;
	$volatile(::jdk::internal::net::http::Response*) response = nullptr;
	::java::util::concurrent::atomic::AtomicReference* errorRef = nullptr;
	::java::util::concurrent::CompletableFuture* requestBodyCF = nullptr;
	$volatile(::java::util::concurrent::CompletableFuture*) responseBodyCF = nullptr;
	$volatile(::java::net::http::HttpResponse$BodySubscriber*) pendingResponseSubscriber = nullptr;
	$volatile(bool) stopRequested = false;
	$volatile(bool) remotelyClosed = false;
	$volatile(bool) closed = false;
	$volatile(bool) endStreamSent = false;
	$volatile(int32_t) streamState = 0;
	$volatile(bool) deRegistered = false;
	bool requestSent$ = false;
	bool responseReceived$ = false;
	$Object* sendLock = nullptr;
	::jdk::internal::net::http::WindowController* windowController = nullptr;
	::jdk::internal::net::http::WindowUpdateSender* windowUpdater = nullptr;
	static ::java::nio::ByteBuffer* COMPLETED;
	::java::util::List* response_cfs = nullptr;
	static ::java::lang::invoke::VarHandle* STREAM_STATE;
	static ::java::lang::invoke::VarHandle* DEREGISTERED;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("COMPLETED")
#pragma pop_macro("DEREGISTERED")
#pragma pop_macro("STREAM_STATE")

#endif // _jdk_internal_net_http_Stream_h_