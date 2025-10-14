#ifndef _jdk_internal_net_http_RequestPublishers$PublisherAdapter_h_
#define _jdk_internal_net_http_RequestPublishers$PublisherAdapter_h_
//$ class jdk.internal.net.http.RequestPublishers$PublisherAdapter
//$ extends java.net.http.HttpRequest$BodyPublisher

#include <java/net/http/HttpRequest$BodyPublisher.h>

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

class $export RequestPublishers$PublisherAdapter : public ::java::net::http::HttpRequest$BodyPublisher {
	$class(RequestPublishers$PublisherAdapter, $NO_CLASS_INIT, ::java::net::http::HttpRequest$BodyPublisher)
public:
	RequestPublishers$PublisherAdapter();
	void init$(::java::util::concurrent::Flow$Publisher* publisher, int64_t contentLength);
	virtual int64_t contentLength() override;
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* subscriber) override;
	::java::util::concurrent::Flow$Publisher* publisher = nullptr;
	int64_t contentLength$ = 0;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RequestPublishers$PublisherAdapter_h_