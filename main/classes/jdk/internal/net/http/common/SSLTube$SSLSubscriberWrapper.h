#ifndef _jdk_internal_net_http_common_SSLTube$SSLSubscriberWrapper_h_
#define _jdk_internal_net_http_common_SSLTube$SSLSubscriberWrapper_h_
//$ class jdk.internal.net.http.common.SSLTube$SSLSubscriberWrapper
//$ extends jdk.internal.net.http.common.FlowTube$TubeSubscriber

#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>

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
			class Flow$Subscriber;
			class Flow$Subscription;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicReference;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class SSLTube;
					class SSLTube$DelegateWrapper;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export SSLTube$SSLSubscriberWrapper : public ::jdk::internal::net::http::common::FlowTube$TubeSubscriber {
	$class(SSLTube$SSLSubscriberWrapper, 0, ::jdk::internal::net::http::common::FlowTube$TubeSubscriber)
public:
	SSLTube$SSLSubscriberWrapper();
	void init$(::jdk::internal::net::http::common::SSLTube* this$0);
	void complete(::jdk::internal::net::http::common::SSLTube$DelegateWrapper* subscriberImpl, $Throwable* t);
	virtual void dropSubscription() override;
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	void onErrorImpl($Throwable* throwable);
	void onNewSubscription(::jdk::internal::net::http::common::SSLTube$DelegateWrapper* subscriberImpl, ::java::util::concurrent::Flow$Subscription* subscription);
	void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	void onSubscribeImpl(::java::util::concurrent::Flow$Subscription* subscription);
	void processPendingSubscriber();
	void setDelegate(::java::util::concurrent::Flow$Subscriber* delegate);
	virtual $String* toString() override;
	::jdk::internal::net::http::common::SSLTube* this$0 = nullptr;
	static bool $assertionsDisabled;
	::java::util::concurrent::atomic::AtomicReference* pendingDelegate = nullptr;
	$volatile(::jdk::internal::net::http::common::SSLTube$DelegateWrapper*) subscribed = nullptr;
	$volatile(bool) onCompleteReceived = false;
	::java::util::concurrent::atomic::AtomicReference* errorRef = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SSLTube$SSLSubscriberWrapper_h_