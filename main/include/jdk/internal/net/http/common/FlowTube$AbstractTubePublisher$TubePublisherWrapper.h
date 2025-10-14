#ifndef _jdk_internal_net_http_common_FlowTube$AbstractTubePublisher$TubePublisherWrapper_h_
#define _jdk_internal_net_http_common_FlowTube$AbstractTubePublisher$TubePublisherWrapper_h_
//$ class jdk.internal.net.http.common.FlowTube$AbstractTubePublisher$TubePublisherWrapper
//$ extends jdk.internal.net.http.common.FlowTube$AbstractTubePublisher

#include <jdk/internal/net/http/common/FlowTube$AbstractTubePublisher.h>

namespace java {
	namespace util {
		namespace concurrent {
			class Flow$Publisher;
			class Flow$Subscriber;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $import FlowTube$AbstractTubePublisher$TubePublisherWrapper : public ::jdk::internal::net::http::common::FlowTube$AbstractTubePublisher {
	$class(FlowTube$AbstractTubePublisher$TubePublisherWrapper, $NO_CLASS_INIT, ::jdk::internal::net::http::common::FlowTube$AbstractTubePublisher)
public:
	FlowTube$AbstractTubePublisher$TubePublisherWrapper();
	void init$(::java::util::concurrent::Flow$Publisher* delegate);
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* subscriber) override;
	::java::util::concurrent::Flow$Publisher* delegate = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_FlowTube$AbstractTubePublisher$TubePublisherWrapper_h_