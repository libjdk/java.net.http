#ifndef _jdk_internal_net_http_RequestPublishers$AggregateSubscription_h_
#define _jdk_internal_net_http_RequestPublishers$AggregateSubscription_h_
//$ class jdk.internal.net.http.RequestPublishers$AggregateSubscription
//$ extends java.util.concurrent.Flow$Subscription
//$ implements java.util.concurrent.Flow$Subscriber

#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpRequest$BodyPublisher;
		}
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace java {
	namespace util {
		class List;
		class Queue;
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
					class Demand;
					class SequentialScheduler;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import RequestPublishers$AggregateSubscription : public ::java::util::concurrent::Flow$Subscription, public ::java::util::concurrent::Flow$Subscriber {
	$class(RequestPublishers$AggregateSubscription, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscription, ::java::util::concurrent::Flow$Subscriber)
public:
	RequestPublishers$AggregateSubscription();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::java::util::List* bodies, ::java::util::concurrent::Flow$Subscriber* subscriber);
	virtual void cancel() override;
	bool cancelSubscription();
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	void onNext(::java::nio::ByteBuffer* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	virtual void request(int64_t n) override;
	void run();
	virtual $String* toString() override;
	::java::util::concurrent::Flow$Subscriber* subscriber = nullptr;
	::java::util::Queue* bodies = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* scheduler = nullptr;
	::jdk::internal::net::http::common::Demand* demand = nullptr;
	::jdk::internal::net::http::common::Demand* demanded = nullptr;
	::java::util::concurrent::atomic::AtomicReference* error = nullptr;
	$volatile($Throwable*) illegalRequest = nullptr;
	$volatile(::java::net::http::HttpRequest$BodyPublisher*) publisher = nullptr;
	$volatile(::java::util::concurrent::Flow$Subscription*) subscription = nullptr;
	$volatile(bool) cancelled = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RequestPublishers$AggregateSubscription_h_