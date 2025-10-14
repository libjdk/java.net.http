#ifndef _java_net_http_HttpRequest$BodyPublisher_h_
#define _java_net_http_HttpRequest$BodyPublisher_h_
//$ interface java.net.http.HttpRequest$BodyPublisher
//$ extends java.util.concurrent.Flow$Publisher

#include <java/util/concurrent/Flow$Publisher.h>

namespace java {
	namespace net {
		namespace http {

class $export HttpRequest$BodyPublisher : public ::java::util::concurrent::Flow$Publisher {
	$interface(HttpRequest$BodyPublisher, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Publisher)
public:
	virtual int64_t contentLength() {return 0;}
};

		} // http
	} // net
} // java

#endif // _java_net_http_HttpRequest$BodyPublisher_h_