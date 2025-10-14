#ifndef _jdk_internal_net_http_RequestPublishers$StringPublisher_h_
#define _jdk_internal_net_http_RequestPublishers$StringPublisher_h_
//$ class jdk.internal.net.http.RequestPublishers$StringPublisher
//$ extends jdk.internal.net.http.RequestPublishers$ByteArrayPublisher

#include <jdk/internal/net/http/RequestPublishers$ByteArrayPublisher.h>

namespace java {
	namespace nio {
		namespace charset {
			class Charset;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export RequestPublishers$StringPublisher : public ::jdk::internal::net::http::RequestPublishers$ByteArrayPublisher {
	$class(RequestPublishers$StringPublisher, $NO_CLASS_INIT, ::jdk::internal::net::http::RequestPublishers$ByteArrayPublisher)
public:
	RequestPublishers$StringPublisher();
	void init$($String* content, ::java::nio::charset::Charset* charset);
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RequestPublishers$StringPublisher_h_