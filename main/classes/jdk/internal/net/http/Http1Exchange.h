#ifndef _jdk_internal_net_http_Http1Exchange_h_
#define _jdk_internal_net_http_Http1Exchange_h_
//$ class jdk.internal.net.http.Http1Exchange
//$ extends jdk.internal.net.http.ExchangeImpl

#include <jdk/internal/net/http/ExchangeImpl.h>

namespace java {
	namespace io {
		class IOException;
	}
}
namespace java {
	namespace lang {
		class Runnable;
		class Throwable;
		class Void;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpClient;
			class HttpResponse;
			class HttpResponse$BodyHandler;
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
			class ConcurrentLinkedDeque;
			class Executor;
			class Flow$Subscription;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Exchange;
				class Http1AsyncReceiver;
				class Http1Exchange$DataPair;
				class Http1Exchange$Http1BodySubscriber;
				class Http1Exchange$Http1Publisher;
				class Http1Exchange$State;
				class Http1Request;
				class Http1Response;
				class HttpClientImpl;
				class HttpConnection;
				class HttpRequestImpl;
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

class $export Http1Exchange : public ::jdk::internal::net::http::ExchangeImpl {
	$class(Http1Exchange, 0, ::jdk::internal::net::http::ExchangeImpl)
public:
	Http1Exchange();
	void init$(::jdk::internal::net::http::Exchange* exchange, ::jdk::internal::net::http::HttpConnection* connection);
	virtual void appendToOutgoing($Throwable* throwable);
	virtual void appendToOutgoing(::java::util::List* item);
	void appendToOutgoing(::jdk::internal::net::http::Http1Exchange$DataPair* dp);
	virtual void cancel() override;
	virtual void cancel(::java::io::IOException* cause) override;
	void cancelIfFailed(::java::util::concurrent::Flow$Subscription* s);
	void cancelImpl($Throwable* cause);
	void cancelUpstreamSubscription();
	virtual ::java::net::http::HttpClient* client() override;
	virtual void completed() override;
	void connectFlows(::jdk::internal::net::http::HttpConnection* connection);
	virtual ::jdk::internal::net::http::HttpConnection* connection() override;
	virtual $String* dbgString();
	virtual ::java::nio::ByteBuffer* drainLeftOverBytes();
	virtual $Throwable* getCancelCause() override;
	::jdk::internal::net::http::Http1Exchange$DataPair* getOutgoing();
	virtual ::java::util::concurrent::CompletableFuture* getResponseAsync(::java::util::concurrent::Executor* executor) override;
	bool hasOutgoing();
	virtual ::java::util::concurrent::CompletableFuture* ignoreBody() override;
	virtual bool isCanceled() override;
	void lambda$cancelIfFailed$6(::java::util::concurrent::Flow$Subscription* s, ::java::lang::Void* r, $Throwable* t);
	void lambda$cancelImpl$9(::java::util::concurrent::CompletableFuture* cf, $Throwable* x);
	void lambda$getOutgoing$12(::jdk::internal::net::http::Http1Exchange$DataPair* dp);
	void lambda$sendBodyAsync$7(::java::util::concurrent::Flow$Subscription* s);
	void lambda$sendBodyAsync$8(::java::lang::Void* s);
	::java::util::concurrent::CompletionStage* lambda$sendHeadersAsync$0(::java::lang::Void* unused);
	static void lambda$sendHeadersAsync$1(::java::util::concurrent::CompletableFuture* connectCF, $Throwable* cancelled);
	::jdk::internal::net::http::ExchangeImpl* lambda$sendHeadersAsync$2();
	void lambda$sendHeadersAsync$3(::java::lang::Void* r, $Throwable* t);
	::java::util::concurrent::CompletionStage* lambda$sendHeadersAsync$4(::java::lang::Void* unused);
	::java::util::concurrent::CompletionStage* lambda$sendHeadersAsync$5(::java::lang::Void* unused);
	virtual void nullBody(::java::net::http::HttpResponse* resp, $Throwable* t) override;
	virtual ::java::util::concurrent::CompletableFuture* readBodyAsync(::java::net::http::HttpResponse$BodyHandler* handler, bool returnConnectionToPool, ::java::util::concurrent::Executor* executor) override;
	virtual void released() override;
	virtual ::jdk::internal::net::http::HttpRequestImpl* request();
	void requestMoreBody();
	void runInline(::java::lang::Runnable* run);
	virtual ::java::util::concurrent::CompletableFuture* sendBodyAsync() override;
	virtual ::java::util::concurrent::CompletableFuture* sendHeadersAsync() override;
	virtual $String* toString() override;
	virtual void upgraded() override;
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	::jdk::internal::net::http::HttpRequestImpl* request$ = nullptr;
	::jdk::internal::net::http::Http1Request* requestAction = nullptr;
	$volatile(::jdk::internal::net::http::Http1Response*) response = nullptr;
	::jdk::internal::net::http::HttpConnection* connection$ = nullptr;
	::jdk::internal::net::http::HttpClientImpl* client$ = nullptr;
	::java::util::concurrent::Executor* executor = nullptr;
	::jdk::internal::net::http::Http1AsyncReceiver* asyncReceiver = nullptr;
	$volatile(bool) upgraded$ = false;
	$Throwable* failed = nullptr;
	::java::util::List* operations = nullptr;
	$Object* lock = nullptr;
	::java::util::concurrent::ConcurrentLinkedDeque* outgoing = nullptr;
	::jdk::internal::net::http::Http1Exchange$Http1Publisher* writePublisher = nullptr;
	::java::util::concurrent::CompletableFuture* headersSentCF = nullptr;
	::java::util::concurrent::CompletableFuture* bodySentCF = nullptr;
	$volatile(::jdk::internal::net::http::Http1Exchange$Http1BodySubscriber*) bodySubscriber = nullptr;
	::jdk::internal::net::http::Http1Exchange$State* state = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1Exchange_h_