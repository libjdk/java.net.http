#ifndef _jdk_internal_net_http_HttpConnection$HttpPublisher_h_
#define _jdk_internal_net_http_HttpConnection$HttpPublisher_h_
//$ interface jdk.internal.net.http.HttpConnection$HttpPublisher
//$ extends jdk.internal.net.http.common.FlowTube$TubePublisher

#include <jdk/internal/net/http/common/FlowTube$TubePublisher.h>

namespace java {
	namespace util {
		class List;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export HttpConnection$HttpPublisher : public ::jdk::internal::net::http::common::FlowTube$TubePublisher {
	$interface(HttpConnection$HttpPublisher, $NO_CLASS_INIT, ::jdk::internal::net::http::common::FlowTube$TubePublisher)
public:
	virtual void enqueue(::java::util::List* buffers) {}
	virtual void enqueueUnordered(::java::util::List* buffers) {}
	virtual void signalEnqueued() {}
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HttpConnection$HttpPublisher_h_