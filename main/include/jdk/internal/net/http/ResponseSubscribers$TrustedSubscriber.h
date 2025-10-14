#ifndef _jdk_internal_net_http_ResponseSubscribers$TrustedSubscriber_h_
#define _jdk_internal_net_http_ResponseSubscribers$TrustedSubscriber_h_
//$ interface jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber
//$ extends java.net.http.HttpResponse$BodySubscriber

#include <java/net/http/HttpResponse$BodySubscriber.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import ResponseSubscribers$TrustedSubscriber : public ::java::net::http::HttpResponse$BodySubscriber {
	$interface(ResponseSubscribers$TrustedSubscriber, $NO_CLASS_INIT, ::java::net::http::HttpResponse$BodySubscriber)
public:
	virtual bool needsExecutor();
	static bool needsExecutor(::java::net::http::HttpResponse$BodySubscriber* bs);
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseSubscribers$TrustedSubscriber_h_