#ifndef _jdk_internal_net_http_SocketTube$InternalWriteSubscriber_h_
#define _jdk_internal_net_http_SocketTube$InternalWriteSubscriber_h_
//$ class jdk.internal.net.http.SocketTube$InternalWriteSubscriber
//$ extends java.util.concurrent.Flow$Subscriber

#include <java/util/concurrent/Flow$Subscriber.h>

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
			class Flow$Subscription;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class AsyncTriggerEvent;
				class SocketTube;
				class SocketTube$InternalWriteSubscriber$WriteEvent;
				class SocketTube$InternalWriteSubscriber$WriteSubscription;
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
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import SocketTube$InternalWriteSubscriber : public ::java::util::concurrent::Flow$Subscriber {
	$class(SocketTube$InternalWriteSubscriber, 0, ::java::util::concurrent::Flow$Subscriber)
public:
	SocketTube$InternalWriteSubscriber();
	void init$(::jdk::internal::net::http::SocketTube* this$0);
	static $String* lambda$signalError$0($Throwable* error);
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	void onNext(::java::util::List* bufs);
	virtual void onNext(Object$* bufs) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	void requestMore();
	void resumeWriteEvent(bool inSelectorThread);
	void signalError($Throwable* error);
	void signalWritable();
	void startSubscription();
	void tryFlushCurrent(bool inSelectorThread);
	::jdk::internal::net::http::SocketTube* this$0 = nullptr;
	static bool $assertionsDisabled;
	$volatile(::jdk::internal::net::http::SocketTube$InternalWriteSubscriber$WriteSubscription*) subscription = nullptr;
	$volatile(::java::util::List*) current = nullptr;
	$volatile(bool) completed = false;
	::jdk::internal::net::http::AsyncTriggerEvent* startSubscription$ = nullptr;
	::jdk::internal::net::http::SocketTube$InternalWriteSubscriber$WriteEvent* writeEvent = nullptr;
	::jdk::internal::net::http::common::Demand* writeDemand = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_SocketTube$InternalWriteSubscriber_h_