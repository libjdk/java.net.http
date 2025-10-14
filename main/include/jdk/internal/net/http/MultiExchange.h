#ifndef _jdk_internal_net_http_MultiExchange_h_
#define _jdk_internal_net_http_MultiExchange_h_
//$ class jdk.internal.net.http.MultiExchange
//$ extends jdk.internal.net.http.common.Cancelable

#include <jdk/internal/net/http/common/Cancelable.h>

#pragma push_macro("DEFAULT_MAX_ATTEMPTS")
#undef DEFAULT_MAX_ATTEMPTS
#pragma push_macro("RETRY_ALWAYS")
#undef RETRY_ALWAYS
#pragma push_macro("RETRY_CONNECT")
#undef RETRY_CONNECT

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
	namespace net {
		namespace http {
			class HttpClient$Version;
			class HttpRequest;
			class HttpResponse;
			class HttpResponse$BodyHandler;
			class HttpResponse$PushPromiseHandler;
			class HttpTimeoutException;
		}
	}
}
namespace java {
	namespace security {
		class AccessControlContext;
	}
}
namespace java {
	namespace util {
		class LinkedList;
		class Optional;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
			class CompletionStage;
			class Executor;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicInteger;
				class AtomicReference;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class AuthenticationFilter$AuthInfo;
				class Exchange;
				class HttpClientImpl;
				class HttpClientImpl$DelegatingExecutor;
				class HttpRequestImpl;
				class MultiExchange$ConnectTimeoutTracker;
				class PushGroup;
				class Response;
				class ResponseTimerEvent;
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
					class MinimalFuture;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import MultiExchange : public ::jdk::internal::net::http::common::Cancelable {
	$class(MultiExchange, 0, ::jdk::internal::net::http::common::Cancelable)
public:
	MultiExchange();
	void init$(::java::net::http::HttpRequest* userRequest, ::jdk::internal::net::http::HttpRequestImpl* requestImpl, ::jdk::internal::net::http::HttpClientImpl* client, ::java::net::http::HttpResponse$BodyHandler* responseHandler, ::java::net::http::HttpResponse$PushPromiseHandler* pushPromiseHandler, ::java::security::AccessControlContext* acc);
	bool bodyIsPresent(::jdk::internal::net::http::Response* r);
	static bool bodyNotPermitted(::jdk::internal::net::http::Response* r);
	static bool canRetryRequest(::java::net::http::HttpRequest* request);
	virtual void cancel(::java::io::IOException* cause);
	virtual bool cancel(bool mayInterruptIfRunning) override;
	void cancelTimer();
	virtual ::jdk::internal::net::http::HttpClientImpl* client();
	static bool disableRetryConnect();
	::java::util::concurrent::CompletableFuture* getExceptionalCF($Throwable* t);
	virtual ::jdk::internal::net::http::Exchange* getExchange();
	::java::util::concurrent::CompletableFuture* handleNoBody(::jdk::internal::net::http::Response* r, ::jdk::internal::net::http::Exchange* exch);
	static bool isIdempotentRequest(::java::net::http::HttpRequest* request);
	void lambda$handleNoBody$1(::jdk::internal::net::http::common::MinimalFuture* result, ::jdk::internal::net::http::Response* r, ::jdk::internal::net::http::Exchange* exch, Object$* nullBody, $Throwable* exception);
	static ::java::lang::Void* lambda$responseAsync$0();
	::java::util::concurrent::CompletionStage* lambda$responseAsync0$2(::java::lang::Void* v);
	::java::net::http::HttpResponse* lambda$responseAsync0$3(::jdk::internal::net::http::Response* r, ::jdk::internal::net::http::Exchange* exch, Object$* body);
	::java::util::concurrent::CompletionStage* lambda$responseAsync0$4(::jdk::internal::net::http::Response* r);
	::java::util::concurrent::CompletableFuture* lambda$responseAsyncImpl$5(::jdk::internal::net::http::HttpRequestImpl* newrequest, ::java::lang::Void* r, $Throwable* t);
	::java::util::concurrent::CompletionStage* lambda$responseAsyncImpl$6(::jdk::internal::net::http::Exchange* exch, ::jdk::internal::net::http::Response* response);
	::java::util::concurrent::CompletableFuture* lambda$responseAsyncImpl$7(::jdk::internal::net::http::Response* response, $Throwable* ex);
	virtual ::java::util::Optional* remainingConnectTimeout();
	virtual bool requestCancelled();
	void requestFilters(::jdk::internal::net::http::HttpRequestImpl* r);
	virtual ::java::util::concurrent::CompletableFuture* responseAsync(::java::util::concurrent::Executor* executor);
	::java::util::concurrent::CompletableFuture* responseAsync0(::java::util::concurrent::CompletableFuture* start);
	::java::util::concurrent::CompletableFuture* responseAsyncImpl();
	::jdk::internal::net::http::HttpRequestImpl* responseFilters(::jdk::internal::net::http::Response* response);
	$Throwable* retryCause($Throwable* t);
	bool retryOnFailure($Throwable* t);
	static bool retryPostValue();
	void setExchange(::jdk::internal::net::http::Exchange* exchange);
	::java::net::http::HttpTimeoutException* toTimeoutException(::java::io::IOException* ioe);
	virtual ::java::net::http::HttpClient$Version* version();
	::java::util::concurrent::CompletableFuture* whenCancelled($Throwable* t);
	static bool $assertionsDisabled;
	static ::jdk::internal::net::http::common::Logger* debug;
	::java::net::http::HttpRequest* userRequest = nullptr;
	::jdk::internal::net::http::HttpRequestImpl* request = nullptr;
	::jdk::internal::net::http::MultiExchange$ConnectTimeoutTracker* connectTimeout = nullptr;
	::java::security::AccessControlContext* acc = nullptr;
	::jdk::internal::net::http::HttpClientImpl* client$ = nullptr;
	::java::net::http::HttpResponse$BodyHandler* responseHandler = nullptr;
	::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor* executor = nullptr;
	::java::util::concurrent::atomic::AtomicInteger* attempts = nullptr;
	::jdk::internal::net::http::HttpRequestImpl* currentreq = nullptr;
	::jdk::internal::net::http::HttpRequestImpl* previousreq = nullptr;
	::jdk::internal::net::http::Exchange* exchange = nullptr;
	::jdk::internal::net::http::Exchange* previous = nullptr;
	$volatile($Throwable*) retryCause$ = nullptr;
	$volatile(bool) expiredOnce = false;
	$volatile(::java::net::http::HttpResponse*) response = nullptr;
	static const int32_t DEFAULT_MAX_ATTEMPTS = 5;
	static int32_t max_attempts;
	::java::util::LinkedList* filters = nullptr;
	::jdk::internal::net::http::ResponseTimerEvent* responseTimerEvent = nullptr;
	$volatile(bool) cancelled = false;
	::java::util::concurrent::atomic::AtomicReference* interrupted = nullptr;
	::jdk::internal::net::http::PushGroup* pushGroup = nullptr;
	$volatile(::jdk::internal::net::http::AuthenticationFilter$AuthInfo*) serverauth = nullptr;
	$volatile(::jdk::internal::net::http::AuthenticationFilter$AuthInfo*) proxyauth = nullptr;
	$volatile(int32_t) numberOfRedirects = 0;
	static bool RETRY_ALWAYS;
	static bool RETRY_CONNECT;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("DEFAULT_MAX_ATTEMPTS")
#pragma pop_macro("RETRY_ALWAYS")
#pragma pop_macro("RETRY_CONNECT")

#endif // _jdk_internal_net_http_MultiExchange_h_