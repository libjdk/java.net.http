#ifndef _jdk_internal_net_http_RequestPublishers$AggregatePublisher_h_
#define _jdk_internal_net_http_RequestPublishers$AggregatePublisher_h_
//$ class jdk.internal.net.http.RequestPublishers$AggregatePublisher
//$ extends java.net.http.HttpRequest$BodyPublisher

#include <java/net/http/HttpRequest$BodyPublisher.h>

namespace java {
	namespace util {
		class List;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class Flow$Subscriber;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import RequestPublishers$AggregatePublisher : public ::java::net::http::HttpRequest$BodyPublisher {
	$class(RequestPublishers$AggregatePublisher, $NO_CLASS_INIT, ::java::net::http::HttpRequest$BodyPublisher)
public:
	RequestPublishers$AggregatePublisher();
	void init$(::java::util::List* bodies);
	virtual int64_t contentLength() override;
	static int64_t lambda$contentLength$0(int64_t a, int64_t b);
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* subscriber) override;
	::java::util::List* bodies = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RequestPublishers$AggregatePublisher_h_