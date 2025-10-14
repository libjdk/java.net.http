#ifndef _jdk_internal_net_http_Http1Response$Receiver_h_
#define _jdk_internal_net_http_Http1Response$Receiver_h_
//$ class jdk.internal.net.http.Http1Response$Receiver
//$ extends jdk.internal.net.http.Http1AsyncReceiver$Http1AsyncDelegate

#include <jdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegate.h>

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

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Http1Response$Receiver : public ::jdk::internal::net::http::Http1AsyncReceiver$Http1AsyncDelegate {
	$class(Http1Response$Receiver, $NO_CLASS_INIT, ::jdk::internal::net::http::Http1AsyncReceiver$Http1AsyncDelegate)
public:
	Http1Response$Receiver();
	void init$();
	bool accept(::java::nio::ByteBuffer* buf, Object$* parser, ::java::util::concurrent::CompletableFuture* cf);
	virtual ::java::util::concurrent::CompletableFuture* completion() {return nullptr;}
	virtual void handle(::java::nio::ByteBuffer* buf, Object$* parser, ::java::util::concurrent::CompletableFuture* cf) {}
	virtual void onReadError($Throwable* t) override {}
	virtual void onSubscribe(::jdk::internal::net::http::AbstractSubscription* s) override {}
	virtual void reset() {}
	virtual void start(Object$* parser) {}
	virtual ::jdk::internal::net::http::AbstractSubscription* subscription() override {return nullptr;}
	virtual bool tryAsyncReceive(::java::nio::ByteBuffer* buffer) override {return false;}
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1Response$Receiver_h_