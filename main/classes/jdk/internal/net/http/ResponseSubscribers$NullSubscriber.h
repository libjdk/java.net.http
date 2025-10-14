#ifndef _jdk_internal_net_http_ResponseSubscribers$NullSubscriber_h_
#define _jdk_internal_net_http_ResponseSubscribers$NullSubscriber_h_
//$ class jdk.internal.net.http.ResponseSubscribers$NullSubscriber
//$ extends jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber

#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace util {
		class List;
		class Optional;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
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

class $export ResponseSubscribers$NullSubscriber : public ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber {
	$class(ResponseSubscribers$NullSubscriber, $NO_CLASS_INIT, ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber)
public:
	ResponseSubscribers$NullSubscriber();
	void init$(::java::util::Optional* result);
	virtual ::java::util::concurrent::CompletionStage* getBody() override;
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	virtual void onNext(::java::util::List* items);
	virtual void onNext(Object$* items) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	::java::util::concurrent::CompletableFuture* cf = nullptr;
	::java::util::Optional* result = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* subscribed = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseSubscribers$NullSubscriber_h_