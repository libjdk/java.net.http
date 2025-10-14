#ifndef _jdk_internal_net_http_RequestPublishers$EmptyPublisher_h_
#define _jdk_internal_net_http_RequestPublishers$EmptyPublisher_h_
//$ class jdk.internal.net.http.RequestPublishers$EmptyPublisher
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

class $import RequestPublishers$EmptyPublisher : public ::java::net::http::HttpRequest$BodyPublisher {
	$class(RequestPublishers$EmptyPublisher, $NO_CLASS_INIT, ::java::net::http::HttpRequest$BodyPublisher)
public:
	RequestPublishers$EmptyPublisher();
	void init$();
	virtual int64_t contentLength() override;
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* subscriber) override;
	::java::util::concurrent::Flow$Publisher* delegate = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RequestPublishers$EmptyPublisher_h_