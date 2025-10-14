#ifndef _jdk_internal_net_http_ExchangeImpl_h_
#define _jdk_internal_net_http_ExchangeImpl_h_
//$ class jdk.internal.net.http.ExchangeImpl
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace io {
		class IOException;
	}
}
namespace java {
	namespace lang {
		class Throwable;
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
	namespace util {
		namespace concurrent {
			class CompletableFuture;
			class CompletionStage;
			class Executor;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Exchange;
				class Http1Exchange;
				class Http2Connection;
				class HttpConnection;
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

class $export ExchangeImpl : public ::java::lang::Object {
	$class(ExchangeImpl, 0, ::java::lang::Object)
public:
	ExchangeImpl();
	void init$(::jdk::internal::net::http::Exchange* e);
	virtual void cancel() {}
	virtual void cancel(::java::io::IOException* cause) {}
	virtual ::java::net::http::HttpClient* client();
	virtual void completed() {}
	virtual ::jdk::internal::net::http::HttpConnection* connection() {return nullptr;}
	static ::java::util::concurrent::CompletableFuture* createExchangeImpl(::jdk::internal::net::http::Http2Connection* c, $Throwable* t, ::jdk::internal::net::http::Exchange* exchange, ::jdk::internal::net::http::HttpConnection* connection);
	static ::java::util::concurrent::CompletableFuture* createHttp1Exchange(::jdk::internal::net::http::Exchange* ex, ::jdk::internal::net::http::HttpConnection* as);
	static ::java::util::concurrent::CompletableFuture* get(::jdk::internal::net::http::Exchange* exchange, ::jdk::internal::net::http::HttpConnection* connection);
	virtual $Throwable* getCancelCause() {return nullptr;}
	::jdk::internal::net::http::Exchange* getExchange();
	virtual ::java::util::concurrent::CompletableFuture* getResponseAsync(::java::util::concurrent::Executor* executor) {return nullptr;}
	virtual ::java::util::concurrent::CompletableFuture* ignoreBody() {return nullptr;}
	virtual bool isCanceled() {return false;}
	static ::jdk::internal::net::http::Http1Exchange* lambda$createExchangeImpl$2(::jdk::internal::net::http::Exchange* exchange, ::jdk::internal::net::http::Http1Exchange* e);
	static ::java::util::concurrent::CompletableFuture* lambda$get$0(::jdk::internal::net::http::Exchange* exchange, ::jdk::internal::net::http::HttpConnection* connection, ::jdk::internal::net::http::Http2Connection* h2c, $Throwable* t);
	static ::java::util::concurrent::CompletionStage* lambda$get$1(::java::util::concurrent::CompletableFuture* x);
	virtual void nullBody(::java::net::http::HttpResponse* resp, $Throwable* t);
	virtual ::java::util::concurrent::CompletableFuture* readBodyAsync(::java::net::http::HttpResponse$BodyHandler* handler, bool returnConnectionToPool, ::java::util::concurrent::Executor* executor) {return nullptr;}
	virtual void released() {}
	virtual ::java::util::concurrent::CompletableFuture* sendBodyAsync() {return nullptr;}
	virtual ::java::util::concurrent::CompletableFuture* sendHeadersAsync() {return nullptr;}
	virtual void upgraded();
	static ::jdk::internal::net::http::common::Logger* debug;
	::jdk::internal::net::http::Exchange* exchange = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ExchangeImpl_h_