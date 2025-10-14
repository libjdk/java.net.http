#ifndef _jdk_internal_net_http_Exchange_h_
#define _jdk_internal_net_http_Exchange_h_
//$ class jdk.internal.net.http.Exchange
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace io {
		class IOException;
	}
}
namespace java {
	namespace lang {
		class SecurityException;
		class Throwable;
	}
}
namespace java {
	namespace net {
		class URI;
		class URLPermission;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpClient$Version;
			class HttpResponse;
			class HttpResponse$BodyHandler;
			class HttpResponse$BodySubscriber;
			class HttpResponse$ResponseInfo;
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
		class Map;
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
		namespace function {
			class Function;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Exchange$ConnectionAborter;
				class ExchangeImpl;
				class Http1Exchange;
				class Http2Connection;
				class HttpClientImpl;
				class HttpConnection;
				class HttpRequestImpl;
				class MultiExchange;
				class PushGroup;
				class Response;
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

class $export Exchange : public ::java::lang::Object {
	$class(Exchange, 0, ::java::lang::Object)
public:
	Exchange();
	void init$(::jdk::internal::net::http::HttpRequestImpl* request, ::jdk::internal::net::http::MultiExchange* multi);
	void init$(::jdk::internal::net::http::HttpRequestImpl* request, ::jdk::internal::net::http::MultiExchange* multi, ::java::security::AccessControlContext* acc);
	void cancel();
	void cancel(::java::io::IOException* cause);
	void checkCancelled();
	::java::util::concurrent::CompletableFuture* checkCancelled(::java::util::concurrent::CompletableFuture* cf, ::jdk::internal::net::http::HttpConnection* connection);
	::java::util::concurrent::CompletableFuture* checkFor407(::jdk::internal::net::http::ExchangeImpl* ex, $Throwable* t, ::java::util::function::Function* andThen);
	::java::util::concurrent::CompletableFuture* checkForUpgradeAsync(::jdk::internal::net::http::Response* resp, ::jdk::internal::net::http::ExchangeImpl* ex);
	::java::lang::SecurityException* checkPermissions();
	::jdk::internal::net::http::HttpClientImpl* client();
	$String* dbgString();
	::java::util::concurrent::CompletableFuture* establishExchange(::jdk::internal::net::http::HttpConnection* connection);
	::java::util::concurrent::Executor* executor();
	::java::util::concurrent::CompletableFuture* expectContinue(::jdk::internal::net::http::ExchangeImpl* ex);
	::java::io::IOException* getCancelCause();
	::jdk::internal::net::http::PushGroup* getPushGroup();
	::java::net::URI* getURIForSecurityCheck();
	void h2Upgrade();
	::java::util::concurrent::CompletableFuture* ignoreBody();
	::java::net::http::HttpResponse$BodySubscriber* ignoreBody(::java::net::http::HttpResponse$ResponseInfo* hdrs);
	::java::util::concurrent::CompletableFuture* lambda$checkCancelled$1(::jdk::internal::net::http::HttpConnection* connection, ::java::util::concurrent::CompletableFuture* cf, Object$* r, $Throwable* t);
	::java::util::concurrent::CompletionStage* lambda$checkForUpgradeAsync$13(::jdk::internal::net::http::Http1Exchange* e, ::jdk::internal::net::http::Http2Connection* c);
	::java::util::concurrent::CompletionStage* lambda$checkForUpgradeAsync$14(::jdk::internal::net::http::ExchangeImpl* ex, ::jdk::internal::net::http::Http1Exchange* e, Object$* v);
	void lambda$establishExchange$2(::java::util::concurrent::CompletableFuture* cf, ::jdk::internal::net::http::ExchangeImpl* r, $Throwable* x);
	::java::util::concurrent::CompletionStage* lambda$establishExchange$3(::jdk::internal::net::http::ExchangeImpl* eimpl);
	::java::util::concurrent::CompletionStage* lambda$expectContinue$4(::jdk::internal::net::http::ExchangeImpl* exIm);
	static ::jdk::internal::net::http::Response* lambda$expectContinue$5(::jdk::internal::net::http::Response* r1, Object$* v);
	::java::util::concurrent::CompletionStage* lambda$expectContinue$6(::jdk::internal::net::http::Response* r1);
	void lambda$readBodyAsync$0(Object$* r, $Throwable* t);
	::java::util::concurrent::CompletableFuture* lambda$responseAsyncImpl0$8(::java::util::function::Function* after407Check, ::jdk::internal::net::http::ExchangeImpl* r, $Throwable* t);
	::java::util::concurrent::CompletableFuture* lambda$responseAsyncImpl0$9(::java::util::function::Function* after407Check, ::jdk::internal::net::http::ExchangeImpl* ex);
	static ::jdk::internal::net::http::Response* lambda$wrapForLog$12(::jdk::internal::net::http::Response* response);
	::java::util::concurrent::CompletionStage* lambda$wrapForUpgrade$11(::jdk::internal::net::http::Response* r);
	void nullBody(::java::net::http::HttpResponse* resp, $Throwable* t);
	static ::java::net::URLPermission* permissionForServer(::java::net::URI* uri, $String* method, ::java::util::Map* headers);
	::java::util::concurrent::CompletableFuture* readBodyAsync(::java::net::http::HttpResponse$BodyHandler* handler);
	void released();
	::java::util::Optional* remainingConnectTimeout();
	static ::java::net::URI* replaceHostInURI(::java::net::URI* u, $String* hostPort);
	::jdk::internal::net::http::HttpRequestImpl* request();
	::java::util::concurrent::CompletableFuture* responseAsync();
	::java::util::concurrent::CompletableFuture* responseAsyncImpl(::jdk::internal::net::http::HttpConnection* connection);
	::java::util::concurrent::CompletableFuture* responseAsyncImpl0(::jdk::internal::net::http::HttpConnection* connection);
	::java::util::concurrent::CompletableFuture* sendRequestBody(::jdk::internal::net::http::ExchangeImpl* ex);
	::java::net::http::HttpClient$Version* version();
	::java::util::concurrent::CompletableFuture* wrapForLog(::java::util::concurrent::CompletableFuture* cf);
	::java::util::concurrent::CompletableFuture* wrapForUpgrade(::java::util::concurrent::CompletableFuture* cf);
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	::jdk::internal::net::http::HttpRequestImpl* request$ = nullptr;
	::jdk::internal::net::http::HttpClientImpl* client$ = nullptr;
	$volatile(::jdk::internal::net::http::ExchangeImpl*) exchImpl = nullptr;
	$volatile(::java::util::concurrent::CompletableFuture*) exchangeCF = nullptr;
	$volatile(::java::util::concurrent::CompletableFuture*) bodyIgnored = nullptr;
	$volatile(::java::io::IOException*) failed = nullptr;
	::java::security::AccessControlContext* acc = nullptr;
	::jdk::internal::net::http::MultiExchange* multi = nullptr;
	::java::util::concurrent::Executor* parentExecutor = nullptr;
	$volatile(bool) upgrading = false;
	$volatile(bool) upgraded = false;
	::jdk::internal::net::http::PushGroup* pushGroup = nullptr;
	$String* dbgTag = nullptr;
	::jdk::internal::net::http::Exchange$ConnectionAborter* connectionAborter = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Exchange_h_