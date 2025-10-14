#ifndef _jdk_internal_net_http_MultiExchange$NullSubscription_h_
#define _jdk_internal_net_http_MultiExchange$NullSubscription_h_
//$ class jdk.internal.net.http.MultiExchange$NullSubscription
//$ extends java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import MultiExchange$NullSubscription : public ::java::util::concurrent::Flow$Subscription {
	$class(MultiExchange$NullSubscription, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscription)
public:
	MultiExchange$NullSubscription();
	void init$();
	virtual void cancel() override;
	virtual void request(int64_t n) override;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_MultiExchange$NullSubscription_h_