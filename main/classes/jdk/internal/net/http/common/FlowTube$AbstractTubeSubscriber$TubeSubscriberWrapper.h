#ifndef _jdk_internal_net_http_common_FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper_h_
#define _jdk_internal_net_http_common_FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper_h_
//$ class jdk.internal.net.http.common.FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper
//$ extends jdk.internal.net.http.common.FlowTube$AbstractTubeSubscriber

#include <jdk/internal/net/http/common/FlowTube$AbstractTubeSubscriber.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace util {
		class List;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class Flow$Subscriber;
			class Flow$Subscription;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper : public ::jdk::internal::net::http::common::FlowTube$AbstractTubeSubscriber {
	$class(FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper, $NO_CLASS_INIT, ::jdk::internal::net::http::common::FlowTube$AbstractTubeSubscriber)
public:
	FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper();
	void init$(::java::util::concurrent::Flow$Subscriber* delegate);
	virtual void dropSubscription() override;
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	::java::util::concurrent::Flow$Subscriber* delegate = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper_h_