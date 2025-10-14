#ifndef _jdk_internal_net_http_Http1Response$1_h_
#define _jdk_internal_net_http_Http1Response$1_h_
//$ class jdk.internal.net.http.Http1Response$1
//$ extends java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Http1Response$1 : public ::java::util::concurrent::Flow$Subscription {
	$class(Http1Response$1, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscription)
public:
	Http1Response$1();
	void init$();
	virtual void cancel() override;
	virtual void request(int64_t n) override;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1Response$1_h_