#ifndef _jdk_internal_net_http_common_SubscriberWrapper_h_
#define _jdk_internal_net_http_common_SubscriberWrapper_h_
//$ class jdk.internal.net.http.common.SubscriberWrapper
//$ extends jdk.internal.net.http.common.FlowTube$TubeSubscriber
//$ implements java.io.Closeable,java.util.concurrent.Flow$Processor

#include <java/io/Closeable.h>
#include <java/util/concurrent/Flow$Processor.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>

namespace java {
	namespace lang {
		class Throwable;
		class Void;
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
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
			class ConcurrentLinkedQueue;
			class Flow$Subscriber;
			class Flow$Subscription;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicLong;
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
					class Logger;
					class SequentialScheduler;
					class SubscriberWrapper$SchedulingAction;
					class SubscriptionBase;
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

class $import SubscriberWrapper : public ::jdk::internal::net::http::common::FlowTube$TubeSubscriber, public ::java::io::Closeable, public ::java::util::concurrent::Flow$Processor {
	$class(SubscriberWrapper, 0, ::jdk::internal::net::http::common::FlowTube$TubeSubscriber, ::java::io::Closeable, ::java::util::concurrent::Flow$Processor)
public:
	SubscriberWrapper();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	void init$(::java::util::concurrent::Flow$Subscriber* downstreamWrapper);
	virtual void addData(::java::nio::ByteBuffer* l);
	virtual void checkCompletion();
	virtual void close() override;
	virtual void close($Throwable* t);
	virtual bool closing();
	virtual ::java::util::concurrent::CompletableFuture* completion();
	virtual $String* dbgString();
	virtual void downstreamCompletion();
	virtual ::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction* enterScheduling();
	virtual bool errorCommon($Throwable* throwable);
	bool hasNoOutputData();
	virtual void incoming(::java::util::List* buffers, bool complete) {}
	void incomingCaller(::java::util::List* l, bool complete);
	virtual int64_t initialUpstreamDemand();
	void lambda$new$0(::java::lang::Void* v, $Throwable* t);
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	virtual void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe();
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	virtual void outgoing(::java::nio::ByteBuffer* buffer, bool complete);
	virtual void outgoing(::java::util::List* buffers, bool complete);
	int32_t outputQueueSize();
	virtual void requestMore();
	virtual void resetDownstreamDemand();
	virtual bool signalScheduling();
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* downstreamSubscriber) override;
	virtual $String* toString() override;
	void upstreamRequest(int64_t n);
	virtual int64_t upstreamWindow();
	virtual int64_t upstreamWindowUpdate(int64_t currentWindow, int64_t downstreamQsize);
	virtual void upstreamWindowUpdate();
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	$volatile(::java::util::concurrent::Flow$Subscription*) upstreamSubscription = nullptr;
	::jdk::internal::net::http::common::SubscriptionBase* downstreamSubscription = nullptr;
	$volatile(bool) upstreamCompleted = false;
	$volatile(bool) downstreamCompleted = false;
	$volatile(bool) completionAcknowledged = false;
	$volatile(::java::util::concurrent::Flow$Subscriber*) downstreamSubscriber = nullptr;
	::java::util::concurrent::ConcurrentLinkedQueue* outputQ = nullptr;
	::java::util::concurrent::CompletableFuture* cf = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* pushScheduler = nullptr;
	::java::util::concurrent::atomic::AtomicReference* errorRef = nullptr;
	::java::util::concurrent::atomic::AtomicLong* upstreamWindow$ = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SubscriberWrapper_h_