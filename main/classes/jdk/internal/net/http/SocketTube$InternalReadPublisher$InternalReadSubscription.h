#ifndef _jdk_internal_net_http_SocketTube$InternalReadPublisher$InternalReadSubscription_h_
#define _jdk_internal_net_http_SocketTube$InternalReadPublisher$InternalReadSubscription_h_
//$ class jdk.internal.net.http.SocketTube$InternalReadPublisher$InternalReadSubscription
//$ extends java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class AsyncEvent;
				class SocketTube$InternalReadPublisher;
				class SocketTube$InternalReadPublisher$ReadEvent;
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

class $export SocketTube$InternalReadPublisher$InternalReadSubscription : public ::java::util::concurrent::Flow$Subscription {
	$class(SocketTube$InternalReadPublisher$InternalReadSubscription, 0, ::java::util::concurrent::Flow$Subscription)
public:
	SocketTube$InternalReadPublisher$InternalReadSubscription();
	void init$(::jdk::internal::net::http::SocketTube$InternalReadPublisher* this$1);
	virtual void cancel() override;
	void handleError();
	bool handlePending();
	void handleSubscribeEvent();
	void pauseReadEvent();
	void read();
	virtual void request(int64_t n) override;
	void resumeReadEvent();
	void signalError($Throwable* error);
	void signalReadable();
	void signalSubscribe();
	::jdk::internal::net::http::SocketTube$InternalReadPublisher* this$1 = nullptr;
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::Demand* demand = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* readScheduler = nullptr;
	$volatile(bool) completed = false;
	::jdk::internal::net::http::SocketTube$InternalReadPublisher$ReadEvent* readEvent = nullptr;
	::jdk::internal::net::http::AsyncEvent* subscribeEvent = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_SocketTube$InternalReadPublisher$InternalReadSubscription_h_