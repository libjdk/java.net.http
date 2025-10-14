#ifndef _jdk_internal_net_http_SocketTube$InternalReadPublisher_h_
#define _jdk_internal_net_http_SocketTube$InternalReadPublisher_h_
//$ class jdk.internal.net.http.SocketTube$InternalReadPublisher
//$ extends java.util.concurrent.Flow$Publisher

#include <java/util/concurrent/Flow$Publisher.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class Flow$Subscriber;
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
				class SocketTube;
				class SocketTube$InternalReadPublisher$InternalReadSubscription;
				class SocketTube$InternalReadPublisher$ReadSubscription;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import SocketTube$InternalReadPublisher : public ::java::util::concurrent::Flow$Publisher {
	$class(SocketTube$InternalReadPublisher, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Publisher)
public:
	SocketTube$InternalReadPublisher();
	void init$(::jdk::internal::net::http::SocketTube* this$0);
	void signalError($Throwable* error);
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* s) override;
	::jdk::internal::net::http::SocketTube* this$0 = nullptr;
	::jdk::internal::net::http::SocketTube$InternalReadPublisher$InternalReadSubscription* subscriptionImpl = nullptr;
	::java::util::concurrent::atomic::AtomicReference* pendingSubscription = nullptr;
	$volatile(::jdk::internal::net::http::SocketTube$InternalReadPublisher$ReadSubscription*) subscription = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_SocketTube$InternalReadPublisher_h_