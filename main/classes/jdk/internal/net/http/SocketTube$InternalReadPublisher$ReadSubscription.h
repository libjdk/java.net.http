#ifndef _jdk_internal_net_http_SocketTube$InternalReadPublisher$ReadSubscription_h_
#define _jdk_internal_net_http_SocketTube$InternalReadPublisher$ReadSubscription_h_
//$ class jdk.internal.net.http.SocketTube$InternalReadPublisher$ReadSubscription
//$ extends java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>

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
				class SocketTube$BufferSource;
				class SocketTube$InternalReadPublisher;
				class SocketTube$InternalReadPublisher$InternalReadSubscription;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class FlowTube$TubeSubscriber;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export SocketTube$InternalReadPublisher$ReadSubscription : public ::java::util::concurrent::Flow$Subscription {
	$class(SocketTube$InternalReadPublisher$ReadSubscription, 0, ::java::util::concurrent::Flow$Subscription)
public:
	SocketTube$InternalReadPublisher$ReadSubscription();
	void init$(::jdk::internal::net::http::SocketTube$InternalReadPublisher* this$1, ::jdk::internal::net::http::SocketTube$InternalReadPublisher$InternalReadSubscription* impl, ::jdk::internal::net::http::common::FlowTube$TubeSubscriber* subscriber);
	virtual void cancel() override;
	virtual void request(int64_t n) override;
	void signalCompletion();
	void signalOnSubscribe();
	::jdk::internal::net::http::SocketTube$InternalReadPublisher* this$1 = nullptr;
	static bool $assertionsDisabled;
	::jdk::internal::net::http::SocketTube$InternalReadPublisher$InternalReadSubscription* impl = nullptr;
	::jdk::internal::net::http::common::FlowTube$TubeSubscriber* subscriber = nullptr;
	::java::util::concurrent::atomic::AtomicReference* errorRef = nullptr;
	::jdk::internal::net::http::SocketTube$BufferSource* bufferSource = nullptr;
	$volatile(bool) subscribed = false;
	$volatile(bool) cancelled = false;
	$volatile(bool) completed = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_SocketTube$InternalReadPublisher$ReadSubscription_h_