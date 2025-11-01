#ifndef _jdk_internal_net_http_HttpClientImpl_h_
#define _jdk_internal_net_http_HttpClientImpl_h_
//$ class jdk.internal.net.http.HttpClientImpl
//$ extends java.net.http.HttpClient
//$ implements jdk.internal.net.http.common.OperationTrackers$Trackable

#include <java/net/http/HttpClient.h>
#include <jdk/internal/net/http/common/OperationTrackers$Trackable.h>

#pragma push_macro("ASYNC_POOL")
#undef ASYNC_POOL
#pragma push_macro("CLIENT_IDS")
#undef CLIENT_IDS
#pragma push_macro("DEBUGELAPSED")
#undef DEBUGELAPSED
#pragma push_macro("DEBUGTIMEOUT")
#undef DEBUGTIMEOUT

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace lang {
		namespace ref {
			class WeakReference;
		}
	}
}
namespace java {
	namespace net {
		class Authenticator;
		class CookieHandler;
		class ProxySelector;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpClient$Redirect;
			class HttpClient$Version;
			class HttpRequest;
			class HttpResponse;
			class HttpResponse$BodyHandler;
			class HttpResponse$PushPromiseHandler;
			class WebSocket$Builder;
		}
	}
}
namespace java {
	namespace nio {
		namespace channels {
			class SelectableChannel;
		}
	}
}
namespace java {
	namespace time {
		class Duration;
	}
}
namespace java {
	namespace util {
		class LinkedList;
		class Optional;
		class TreeSet;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
			class Executor;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicLong;
			}
		}
	}
}
namespace javax {
	namespace net {
		namespace ssl {
			class SSLContext;
			class SSLParameters;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class AsyncEvent;
				class ConnectionPool;
				class FilterFactory;
				class Http2ClientImpl;
				class HttpClientBuilderImpl;
				class HttpClientFacade;
				class HttpClientImpl$DelegatingExecutor;
				class HttpClientImpl$SSLDirectBufferSupplier;
				class HttpClientImpl$SelectorManager;
				class HttpClientImpl$SingleFacadeFactory;
				class TimeoutEvent;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class BufferSupplier;
					class Logger;
					class OperationTrackers$Tracker;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import HttpClientImpl : public ::java::net::http::HttpClient, public ::jdk::internal::net::http::common::OperationTrackers$Trackable {
	$class(HttpClientImpl, 0, ::java::net::http::HttpClient, ::jdk::internal::net::http::common::OperationTrackers$Trackable)
public:
	HttpClientImpl();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::jdk::internal::net::http::HttpClientBuilderImpl* builder, ::jdk::internal::net::http::HttpClientImpl$SingleFacadeFactory* facadeFactory);
	void addFilter($Class* f);
	virtual ::java::util::Optional* authenticator() override;
	void cancelTimer(::jdk::internal::net::http::TimeoutEvent* event);
	::jdk::internal::net::http::Http2ClientImpl* client2();
	virtual ::java::util::Optional* connectTimeout() override;
	::jdk::internal::net::http::ConnectionPool* connectionPool();
	virtual ::java::util::Optional* cookieHandler() override;
	static ::jdk::internal::net::http::HttpClientFacade* create(::jdk::internal::net::http::HttpClientBuilderImpl* builder);
	$String* dbgString();
	void debugCompleted($String* tag, int64_t startNanos, ::java::net::http::HttpRequest* req);
	$String* debugInterestOps(::java::nio::channels::SelectableChannel* channel);
	void eventUpdated(::jdk::internal::net::http::AsyncEvent* event);
	virtual ::java::util::Optional* executor() override;
	::jdk::internal::net::http::HttpClientFacade* facade();
	::java::util::LinkedList* filterChain();
	virtual ::java::net::http::HttpClient$Redirect* followRedirects() override;
	static ::javax::net::ssl::SSLParameters* getDefaultParams(::javax::net::ssl::SSLContext* ctx);
	static ::java::net::ProxySelector* getDefaultProxySelector();
	virtual ::jdk::internal::net::http::common::OperationTrackers$Tracker* getOperationsTracker() override;
	int32_t getReceiveBufferSize();
	::jdk::internal::net::http::common::BufferSupplier* getSSLBufferSupplier();
	int32_t getSendBufferSize();
	void initFilters();
	bool isReferenced();
	bool isSelectorThread();
	void lambda$sendAsync$0(::java::net::http::HttpResponse* b, $Throwable* t);
	void lambda$sendAsync$1(int64_t start, ::java::net::http::HttpRequest* userRequest, ::java::net::http::HttpResponse* b, $Throwable* t);
	static void lambda$sendAsync$2(::java::net::http::HttpResponse* r, $Throwable* t);
	virtual ::java::net::http::WebSocket$Builder* newWebSocketBuilder() override;
	virtual ::java::util::Optional* proxy() override;
	::java::net::ProxySelector* proxySelector();
	int64_t purgeTimeoutsAndReturnNextDeadline();
	int64_t reference();
	int64_t referenceCount();
	void registerEvent(::jdk::internal::net::http::AsyncEvent* exchange);
	void registerTimer(::jdk::internal::net::http::TimeoutEvent* event);
	virtual ::java::net::http::HttpResponse* send(::java::net::http::HttpRequest* req, ::java::net::http::HttpResponse$BodyHandler* responseHandler) override;
	virtual ::java::util::concurrent::CompletableFuture* sendAsync(::java::net::http::HttpRequest* userRequest, ::java::net::http::HttpResponse$BodyHandler* responseHandler) override;
	virtual ::java::util::concurrent::CompletableFuture* sendAsync(::java::net::http::HttpRequest* userRequest, ::java::net::http::HttpResponse$BodyHandler* responseHandler, ::java::net::http::HttpResponse$PushPromiseHandler* pushPromiseHandler) override;
	::java::util::concurrent::CompletableFuture* sendAsync(::java::net::http::HttpRequest* userRequest, ::java::net::http::HttpResponse$BodyHandler* responseHandler, ::java::net::http::HttpResponse$PushPromiseHandler* pushPromiseHandler, ::java::util::concurrent::Executor* exchangeExecutor);
	virtual ::javax::net::ssl::SSLContext* sslContext() override;
	virtual ::javax::net::ssl::SSLParameters* sslParameters() override;
	void start();
	void stop();
	int64_t streamReference();
	int64_t streamUnreference();
	::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor* theExecutor();
	::javax::net::ssl::SSLContext* theSSLContext();
	virtual $String* toString() override;
	int64_t unreference();
	virtual ::java::net::http::HttpClient$Version* version() override;
	int64_t webSocketClose();
	int64_t webSocketOpen();
	static bool $assertionsDisabled;
	static bool DEBUGELAPSED;
	static const bool DEBUGTIMEOUT = false;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	::jdk::internal::net::http::common::Logger* debugelapsed = nullptr;
	::jdk::internal::net::http::common::Logger* debugtimeout = nullptr;
	static ::java::util::concurrent::atomic::AtomicLong* CLIENT_IDS;
	::java::net::CookieHandler* cookieHandler$ = nullptr;
	::java::time::Duration* connectTimeout$ = nullptr;
	::java::net::http::HttpClient$Redirect* followRedirects$ = nullptr;
	::java::net::ProxySelector* userProxySelector = nullptr;
	::java::net::ProxySelector* proxySelector$ = nullptr;
	::java::net::Authenticator* authenticator$ = nullptr;
	::java::net::http::HttpClient$Version* version$ = nullptr;
	::jdk::internal::net::http::ConnectionPool* connections = nullptr;
	::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor* delegatingExecutor = nullptr;
	bool isDefaultExecutor = false;
	::javax::net::ssl::SSLContext* sslContext$ = nullptr;
	::javax::net::ssl::SSLParameters* sslParams = nullptr;
	::jdk::internal::net::http::HttpClientImpl$SelectorManager* selmgr = nullptr;
	::jdk::internal::net::http::FilterFactory* filters = nullptr;
	::jdk::internal::net::http::Http2ClientImpl* client2$ = nullptr;
	int64_t id = 0;
	$String* dbgTag = nullptr;
	::jdk::internal::net::http::HttpClientImpl$SSLDirectBufferSupplier* sslBufferSupplier = nullptr;
	::java::lang::ref::WeakReference* facadeRef = nullptr;
	::java::util::concurrent::atomic::AtomicLong* pendingOperationCount = nullptr;
	::java::util::concurrent::atomic::AtomicLong* pendingWebSocketCount = nullptr;
	::java::util::concurrent::atomic::AtomicLong* pendingHttpRequestCount = nullptr;
	::java::util::concurrent::atomic::AtomicLong* pendingHttp2StreamCount = nullptr;
	::java::util::TreeSet* timeouts = nullptr;
	static ::java::util::concurrent::Executor* ASYNC_POOL;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("ASYNC_POOL")
#pragma pop_macro("CLIENT_IDS")
#pragma pop_macro("DEBUGELAPSED")
#pragma pop_macro("DEBUGTIMEOUT")

#endif // _jdk_internal_net_http_HttpClientImpl_h_