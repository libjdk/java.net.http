#ifndef _jdk_internal_net_http_ResponseSubscribers$SubscriberAdapter_h_
#define _jdk_internal_net_http_ResponseSubscribers$SubscriberAdapter_h_
//$ class jdk.internal.net.http.ResponseSubscribers$SubscriberAdapter
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
			class Flow$Subscriber;
			class Flow$Subscription;
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

class $export ResponseSubscribers$SubscriberAdapter : public ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber {
	$class(ResponseSubscribers$SubscriberAdapter, $NO_CLASS_INIT, ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber)
public:
	ResponseSubscribers$SubscriberAdapter();
	void init$(::java::util::concurrent::Flow$Subscriber* subscriber, ::java::util::function::Function* finisher);
	virtual ::java::util::concurrent::CompletionStage* getBody() override;
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	::java::util::concurrent::CompletableFuture* cf = nullptr;
	::java::util::concurrent::Flow$Subscriber* subscriber = nullptr;
	::java::util::function::Function* finisher = nullptr;
	$volatile(::java::util::concurrent::Flow$Subscription*) subscription = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseSubscribers$SubscriberAdapter_h_