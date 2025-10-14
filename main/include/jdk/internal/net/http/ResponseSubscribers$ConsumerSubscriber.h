#ifndef _jdk_internal_net_http_ResponseSubscribers$ConsumerSubscriber_h_
#define _jdk_internal_net_http_ResponseSubscribers$ConsumerSubscriber_h_
//$ class jdk.internal.net.http.ResponseSubscribers$ConsumerSubscriber
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

class $import ResponseSubscribers$ConsumerSubscriber : public ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber {
	$class(ResponseSubscribers$ConsumerSubscriber, $NO_CLASS_INIT, ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber)
public:
	ResponseSubscribers$ConsumerSubscriber();
	void init$(::java::util::function::Consumer* consumer);
	virtual ::java::util::concurrent::CompletionStage* getBody() override;
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	virtual void onNext(::java::util::List* items);
	virtual void onNext(Object$* items) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	::java::util::function::Consumer* consumer = nullptr;
	::java::util::concurrent::Flow$Subscription* subscription = nullptr;
	::java::util::concurrent::CompletableFuture* result = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* subscribed = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseSubscribers$ConsumerSubscriber_h_