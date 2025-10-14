#ifndef _jdk_internal_net_http_RawChannelTube$ReadSubscriber_h_
#define _jdk_internal_net_http_RawChannelTube$ReadSubscriber_h_
//$ class jdk.internal.net.http.RawChannelTube$ReadSubscriber
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
			class ConcurrentLinkedQueue;
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
				class RawChannelTube;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import RawChannelTube$ReadSubscriber : public ::jdk::internal::net::http::common::FlowTube$TubeSubscriber {
	$class(RawChannelTube$ReadSubscriber, $NO_CLASS_INIT, ::jdk::internal::net::http::common::FlowTube$TubeSubscriber)
public:
	RawChannelTube$ReadSubscriber();
	void init$(::jdk::internal::net::http::RawChannelTube* this$0);
	virtual void checkEvents();
	static $String* lambda$onNext$0(::java::util::List* item);
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	virtual void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	::jdk::internal::net::http::RawChannelTube* this$0 = nullptr;
	$volatile(::java::util::concurrent::Flow$Subscription*) readSubscription = nullptr;
	$volatile(bool) completed = false;
	int64_t initialRequest = 0;
	::java::util::concurrent::ConcurrentLinkedQueue* events = nullptr;
	::java::util::concurrent::ConcurrentLinkedQueue* buffers = nullptr;
	::java::util::concurrent::atomic::AtomicReference* errorRef = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RawChannelTube$ReadSubscriber_h_