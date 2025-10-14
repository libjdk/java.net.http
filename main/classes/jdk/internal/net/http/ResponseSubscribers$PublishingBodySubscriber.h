#ifndef _jdk_internal_net_http_ResponseSubscribers$PublishingBodySubscriber_h_
#define _jdk_internal_net_http_ResponseSubscribers$PublishingBodySubscriber_h_
//$ class jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber
//$ extends jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber

#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>

namespace java {
	namespace lang {
		class Throwable;
		class Void;
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
			class Flow$Subscriber;
			class Flow$Subscription;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicBoolean;
				class AtomicReference;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class ResponseSubscribers$PublishingBodySubscriber$SubscriberRef;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class MinimalFuture;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export ResponseSubscribers$PublishingBodySubscriber : public ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber {
	$class(ResponseSubscribers$PublishingBodySubscriber, 0, ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber)
public:
	ResponseSubscribers$PublishingBodySubscriber();
	void init$();
	void complete(::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber$SubscriberRef* ref, $Throwable* t);
	virtual ::java::util::concurrent::CompletionStage* getBody() override;
	::java::util::concurrent::CompletionStage* lambda$new$0(::java::util::concurrent::Flow$Subscription* s);
	void lambda$new$1($Throwable* t, ::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber$SubscriberRef* s);
	void lambda$new$2(::java::lang::Void* r, $Throwable* t);
	static void lambda$onNext$4(::java::util::concurrent::Flow$Subscription* s);
	void lambda$subscribe$3(::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber$SubscriberRef* ref, ::java::util::concurrent::Flow$Subscription* s);
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	virtual void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	void signalComplete();
	void signalError($Throwable* err);
	void subscribe(::java::util::concurrent::Flow$Subscriber* subscriber);
	bool suppress(bool condition, $String* assertion, $Throwable* carrier);
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::MinimalFuture* subscriptionCF = nullptr;
	::jdk::internal::net::http::common::MinimalFuture* subscribedCF = nullptr;
	::java::util::concurrent::atomic::AtomicReference* subscriberRef = nullptr;
	::java::util::concurrent::CompletionStage* body = nullptr;
	::jdk::internal::net::http::common::MinimalFuture* completionCF = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* subscribed = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseSubscribers$PublishingBodySubscriber_h_