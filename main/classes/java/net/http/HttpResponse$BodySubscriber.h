#ifndef _java_net_http_HttpResponse$BodySubscriber_h_
#define _java_net_http_HttpResponse$BodySubscriber_h_
//$ interface java.net.http.HttpResponse$BodySubscriber
//$ extends java.util.concurrent.Flow$Subscriber

#include <java/util/concurrent/Flow$Subscriber.h>

namespace java {
	namespace util {
		namespace concurrent {
			class CompletionStage;
		}
	}
}

namespace java {
	namespace net {
		namespace http {

class $export HttpResponse$BodySubscriber : public ::java::util::concurrent::Flow$Subscriber {
	$interface(HttpResponse$BodySubscriber, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscriber)
public:
	virtual ::java::util::concurrent::CompletionStage* getBody() {return nullptr;}
};

		} // http
	} // net
} // java

#endif // _java_net_http_HttpResponse$BodySubscriber_h_