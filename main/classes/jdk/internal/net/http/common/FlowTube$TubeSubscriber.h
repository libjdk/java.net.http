#ifndef _jdk_internal_net_http_common_FlowTube$TubeSubscriber_h_
#define _jdk_internal_net_http_common_FlowTube$TubeSubscriber_h_
//$ interface jdk.internal.net.http.common.FlowTube$TubeSubscriber
//$ extends java.util.concurrent.Flow$Subscriber

#include <java/util/concurrent/Flow$Subscriber.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export FlowTube$TubeSubscriber : public ::java::util::concurrent::Flow$Subscriber {
	$interface(FlowTube$TubeSubscriber, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscriber)
public:
	virtual void dropSubscription();
	virtual bool supportsRecycling();
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_FlowTube$TubeSubscriber_h_