#ifndef _jdk_internal_net_http_RequestPublishers$ByteArrayPublisher_h_
#define _jdk_internal_net_http_RequestPublishers$ByteArrayPublisher_h_
//$ class jdk.internal.net.http.RequestPublishers$ByteArrayPublisher
//$ extends java.net.http.HttpRequest$BodyPublisher

#include <java/lang/Array.h>
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

class $export RequestPublishers$ByteArrayPublisher : public ::java::net::http::HttpRequest$BodyPublisher {
	$class(RequestPublishers$ByteArrayPublisher, $NO_CLASS_INIT, ::java::net::http::HttpRequest$BodyPublisher)
public:
	RequestPublishers$ByteArrayPublisher();
	void init$($bytes* content);
	void init$($bytes* content, int32_t offset, int32_t length);
	void init$($bytes* content, int32_t offset, int32_t length, int32_t bufSize);
	virtual int64_t contentLength() override;
	virtual ::java::util::List* copy($bytes* content, int32_t offset, int32_t length);
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* subscriber) override;
	int32_t length = 0;
	$bytes* content = nullptr;
	int32_t offset = 0;
	int32_t bufSize = 0;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RequestPublishers$ByteArrayPublisher_h_