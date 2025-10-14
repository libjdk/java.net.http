#ifndef _jdk_internal_net_http_RawChannelTube$WritePublisher_h_
#define _jdk_internal_net_http_RawChannelTube$WritePublisher_h_
//$ class jdk.internal.net.http.RawChannelTube$WritePublisher
//$ extends jdk.internal.net.http.common.FlowTube$TubePublisher

#include <jdk/internal/net/http/common/FlowTube$TubePublisher.h>

namespace java {
	namespace util {
		namespace concurrent {
			class ConcurrentLinkedQueue;
			class Flow$Subscriber;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class RawChannelTube;
				class RawChannelTube$WriteSubscription;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export RawChannelTube$WritePublisher : public ::jdk::internal::net::http::common::FlowTube$TubePublisher {
	$class(RawChannelTube$WritePublisher, $NO_CLASS_INIT, ::jdk::internal::net::http::common::FlowTube$TubePublisher)
public:
	RawChannelTube$WritePublisher();
	void init$(::jdk::internal::net::http::RawChannelTube* this$0);
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* subscriber) override;
	::jdk::internal::net::http::RawChannelTube* this$0 = nullptr;
	::java::util::concurrent::ConcurrentLinkedQueue* events = nullptr;
	$volatile(::jdk::internal::net::http::RawChannelTube$WriteSubscription*) writeSubscription = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RawChannelTube$WritePublisher_h_