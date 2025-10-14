#ifndef _jdk_internal_net_http_Http1Response$BodyReader_h_
#define _jdk_internal_net_http_Http1Response$BodyReader_h_
//$ class jdk.internal.net.http.Http1Response$BodyReader
//$ extends jdk.internal.net.http.Http1Response$Receiver

#include <jdk/internal/net/http/Http1Response$Receiver.h>

namespace java {
	namespace lang {
		class Throwable;
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
		namespace function {
			class Consumer;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class AbstractSubscription;
				class Http1Response;
				class ResponseContent$BodyParser;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Http1Response$BodyReader : public ::jdk::internal::net::http::Http1Response$Receiver {
	$class(Http1Response$BodyReader, 0, ::jdk::internal::net::http::Http1Response$Receiver)
public:
	Http1Response$BodyReader();
	void init$(::jdk::internal::net::http::Http1Response* this$0, ::java::util::function::Consumer* onComplete);
	virtual void close($Throwable* error) override;
	virtual ::java::util::concurrent::CompletableFuture* completion() override;
	void handle(::java::nio::ByteBuffer* b, ::jdk::internal::net::http::ResponseContent$BodyParser* parser, ::java::util::concurrent::CompletableFuture* cf);
	virtual void handle(::java::nio::ByteBuffer* b, Object$* parser, ::java::util::concurrent::CompletableFuture* cf) override;
	void onComplete($Throwable* closedExceptionally);
	virtual void onReadError($Throwable* t) override;
	virtual void onSubscribe(::jdk::internal::net::http::AbstractSubscription* s) override;
	virtual void reset() override;
	void start(::jdk::internal::net::http::ResponseContent$BodyParser* parser);
	virtual void start(Object$* parser) override;
	virtual ::jdk::internal::net::http::AbstractSubscription* subscription() override;
	virtual $String* toString() override;
	virtual bool tryAsyncReceive(::java::nio::ByteBuffer* b) override;
	::jdk::internal::net::http::Http1Response* this$0 = nullptr;
	static bool $assertionsDisabled;
	::java::util::function::Consumer* onComplete$ = nullptr;
	$volatile(::jdk::internal::net::http::ResponseContent$BodyParser*) parser = nullptr;
	$volatile(::java::util::concurrent::CompletableFuture*) cf = nullptr;
	$volatile(::jdk::internal::net::http::AbstractSubscription*) subscription$ = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1Response$BodyReader_h_