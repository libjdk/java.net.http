#ifndef _jdk_internal_net_http_PushGroup$AcceptorImpl_h_
#define _jdk_internal_net_http_PushGroup$AcceptorImpl_h_
//$ class jdk.internal.net.http.PushGroup$AcceptorImpl
//$ extends jdk.internal.net.http.PushGroup$Acceptor

#include <jdk/internal/net/http/PushGroup$Acceptor.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpResponse;
			class HttpResponse$BodyHandler;
		}
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

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export PushGroup$AcceptorImpl : public ::jdk::internal::net::http::PushGroup$Acceptor {
	$class(PushGroup$AcceptorImpl, $NO_CLASS_INIT, ::jdk::internal::net::http::PushGroup$Acceptor)
public:
	PushGroup$AcceptorImpl();
	void init$(::java::util::concurrent::Executor* executor);
	virtual ::java::util::concurrent::CompletableFuture* accept(::java::net::http::HttpResponse$BodyHandler* bodyHandler);
	virtual bool accepted() override;
	virtual ::java::net::http::HttpResponse$BodyHandler* bodyHandler() override;
	virtual ::java::util::concurrent::CompletableFuture* cf() override;
	static void lambda$accept$0(::java::net::http::HttpResponse* r, $Throwable* t);
	::java::util::concurrent::Executor* executor = nullptr;
	$volatile(::java::net::http::HttpResponse$BodyHandler*) bodyHandler$ = nullptr;
	$volatile(::java::util::concurrent::CompletableFuture*) cf$ = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_PushGroup$AcceptorImpl_h_