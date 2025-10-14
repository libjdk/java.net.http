#ifndef _jdk_internal_net_http_Http1Response$Http1BodySubscriber_h_
#define _jdk_internal_net_http_Http1Response$Http1BodySubscriber_h_
//$ class jdk.internal.net.http.Http1Response$Http1BodySubscriber
//$ extends jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber

#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpResponse$BodySubscriber;
		}
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
			class CompletionStage;
			class Flow$Subscription;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicBoolean;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Http1Response$Http1BodySubscriber : public ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber {
	$class(Http1Response$Http1BodySubscriber, 0, ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber)
public:
	Http1Response$Http1BodySubscriber();
	void init$(::java::net::http::HttpResponse$BodySubscriber* userSubscriber);
	void complete($Throwable* t);
	virtual ::java::util::concurrent::CompletionStage* getBody() override;
	virtual bool needsExecutor() override;
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	void propagateError($Throwable* t);
	static bool $assertionsDisabled;
	::java::net::http::HttpResponse$BodySubscriber* userSubscriber = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* completed = nullptr;
	$volatile($Throwable*) withError = nullptr;
	$volatile(bool) subscribed = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1Response$Http1BodySubscriber_h_