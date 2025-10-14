#ifndef _jdk_internal_net_http_SocketTube$InternalWriteSubscriber$WriteSubscription_h_
#define _jdk_internal_net_http_SocketTube$InternalWriteSubscriber$WriteSubscription_h_
//$ class jdk.internal.net.http.SocketTube$InternalWriteSubscriber$WriteSubscription
//$ extends java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class SocketTube$InternalWriteSubscriber;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import SocketTube$InternalWriteSubscriber$WriteSubscription : public ::java::util::concurrent::Flow$Subscription {
	$class(SocketTube$InternalWriteSubscriber$WriteSubscription, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscription)
public:
	SocketTube$InternalWriteSubscriber$WriteSubscription();
	void init$(::jdk::internal::net::http::SocketTube$InternalWriteSubscriber* this$1, ::java::util::concurrent::Flow$Subscription* subscription);
	virtual void cancel() override;
	void dropSubscription();
	virtual void request(int64_t n) override;
	void requestMore();
	::jdk::internal::net::http::SocketTube$InternalWriteSubscriber* this$1 = nullptr;
	::java::util::concurrent::Flow$Subscription* upstreamSubscription = nullptr;
	$volatile(bool) cancelled = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_SocketTube$InternalWriteSubscriber$WriteSubscription_h_