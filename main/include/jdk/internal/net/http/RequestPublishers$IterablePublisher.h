#ifndef _jdk_internal_net_http_RequestPublishers$IterablePublisher_h_
#define _jdk_internal_net_http_RequestPublishers$IterablePublisher_h_
//$ class jdk.internal.net.http.RequestPublishers$IterablePublisher
//$ extends java.net.http.HttpRequest$BodyPublisher

#include <java/net/http/HttpRequest$BodyPublisher.h>

namespace java {
	namespace lang {
		class Iterable;
	}
}
namespace java {
	namespace util {
		class Iterator;
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

class $import RequestPublishers$IterablePublisher : public ::java::net::http::HttpRequest$BodyPublisher {
	$class(RequestPublishers$IterablePublisher, $NO_CLASS_INIT, ::java::net::http::HttpRequest$BodyPublisher)
public:
	RequestPublishers$IterablePublisher();
	void init$(::java::lang::Iterable* content);
	static int64_t computeLength(::java::lang::Iterable* bytes);
	virtual int64_t contentLength() override;
	virtual ::java::util::Iterator* iterator();
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* subscriber) override;
	::java::lang::Iterable* content = nullptr;
	$volatile(int64_t) contentLength$ = 0;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RequestPublishers$IterablePublisher_h_