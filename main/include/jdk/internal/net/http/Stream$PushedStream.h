#ifndef _jdk_internal_net_http_Stream$PushedStream_h_
#define _jdk_internal_net_http_Stream$PushedStream_h_
//$ class jdk.internal.net.http.Stream$PushedStream
//$ extends jdk.internal.net.http.Stream

#include <jdk/internal/net/http/Stream.h>

namespace java {
	namespace lang {
		class Throwable;
		class Void;
	}
}
namespace java {
	namespace net {
		namespace http {
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
				class ExchangeImpl;
				class Http2Connection;
				class HttpRequestImpl;
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

class $import Stream$PushedStream : public ::jdk::internal::net::http::Stream {
	$class(Stream$PushedStream, $NO_CLASS_INIT, ::jdk::internal::net::http::Stream)
public:
	Stream$PushedStream();
	void init$(::jdk::internal::net::http::PushGroup* pushGroup, ::jdk::internal::net::http::Http2Connection* connection, ::jdk::internal::net::http::Exchange* pushReq);
	virtual void completeResponse(::jdk::internal::net::http::Response* r) override;
	virtual void completeResponseExceptionally($Throwable* t) override;
	virtual ::java::net::http::HttpResponse$BodyHandler* getPushHandler();
	virtual ::java::util::concurrent::CompletableFuture* getResponseAsync(::java::util::concurrent::Executor* executor) override;
	virtual void handleResponse() override;
	::java::util::concurrent::CompletionStage* lambda$completeResponse$5(::java::lang::Void* v);
	void lambda$completeResponse$6(::jdk::internal::net::http::Response* r, Object$* body, $Throwable* t);
	static ::java::lang::Void* lambda$completeResponse$7();
	void lambda$getResponseAsync$2(::jdk::internal::net::http::Response* v, $Throwable* t);
	static ::jdk::internal::net::http::Response* lambda$getResponseAsync$3(::jdk::internal::net::http::Response* r);
	void lambda$readBodyAsync$4(Object$* v, $Throwable* t);
	void lambda$sendBodyAsync$0(::jdk::internal::net::http::ExchangeImpl* v, $Throwable* t);
	virtual ::java::util::concurrent::CompletableFuture* readBodyAsync(::java::net::http::HttpResponse$BodyHandler* handler, bool returnConnectionToPool, ::java::util::concurrent::Executor* executor) override;
	virtual ::java::util::concurrent::CompletableFuture* responseCF();
	virtual ::java::util::concurrent::CompletableFuture* sendBodyAsync() override;
	virtual ::java::util::concurrent::CompletableFuture* sendHeadersAsync() override;
	virtual void setPushHandler(::java::net::http::HttpResponse$BodyHandler* pushHandler);
	::jdk::internal::net::http::PushGroup* pushGroup = nullptr;
	::java::util::concurrent::CompletableFuture* pushCF = nullptr;
	::java::util::concurrent::CompletableFuture* responseCF$ = nullptr;
	::jdk::internal::net::http::HttpRequestImpl* pushReq = nullptr;
	::java::net::http::HttpResponse$BodyHandler* pushHandler = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Stream$PushedStream_h_