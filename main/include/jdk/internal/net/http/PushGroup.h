#ifndef _jdk_internal_net_http_PushGroup_h_
#define _jdk_internal_net_http_PushGroup_h_
//$ class jdk.internal.net.http.PushGroup
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpRequest;
			class HttpResponse$PushPromiseHandler;
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
				class HttpRequestImpl;
				class PushGroup$Acceptor;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import PushGroup : public ::java::lang::Object {
	$class(PushGroup, $NO_CLASS_INIT, ::java::lang::Object)
public:
	PushGroup();
	void init$(::java::net::http::HttpResponse$PushPromiseHandler* pushPromiseHandler, ::jdk::internal::net::http::HttpRequestImpl* initiatingRequest, ::java::util::concurrent::Executor* executor);
	void init$(::java::net::http::HttpResponse$PushPromiseHandler* pushPromiseHandler, ::jdk::internal::net::http::HttpRequestImpl* initiatingRequest, ::java::util::concurrent::CompletableFuture* mainResponse, ::java::util::concurrent::Executor* executor);
	virtual ::jdk::internal::net::http::PushGroup$Acceptor* acceptPushRequest(::java::net::http::HttpRequest* pushRequest);
	virtual void checkIfCompleted();
	virtual void noMorePushes(bool noMore);
	virtual bool noMorePushes();
	virtual void pushCompleted();
	virtual void pushError($Throwable* t);
	virtual ::java::util::concurrent::CompletableFuture* pushesCF();
	::java::net::http::HttpRequest* initiatingRequest = nullptr;
	::java::util::concurrent::CompletableFuture* noMorePushesCF = nullptr;
	$volatile($Throwable*) error = nullptr;
	::java::net::http::HttpResponse$PushPromiseHandler* pushPromiseHandler = nullptr;
	::java::util::concurrent::Executor* executor = nullptr;
	int32_t numberOfPushes = 0;
	int32_t remainingPushes = 0;
	bool noMorePushes$ = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_PushGroup_h_