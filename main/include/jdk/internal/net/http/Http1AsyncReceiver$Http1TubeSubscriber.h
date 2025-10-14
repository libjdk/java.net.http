#ifndef _jdk_internal_net_http_Http1AsyncReceiver$Http1TubeSubscriber_h_
#define _jdk_internal_net_http_Http1AsyncReceiver$Http1TubeSubscriber_h_
//$ class jdk.internal.net.http.Http1AsyncReceiver$Http1TubeSubscriber
//$ extends jdk.internal.net.http.common.FlowTube$TubeSubscriber

#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>

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
			class Flow$Subscription;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Http1AsyncReceiver;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Http1AsyncReceiver$Http1TubeSubscriber : public ::jdk::internal::net::http::common::FlowTube$TubeSubscriber {
	$class(Http1AsyncReceiver$Http1TubeSubscriber, 0, ::jdk::internal::net::http::common::FlowTube$TubeSubscriber)
public:
	Http1AsyncReceiver$Http1TubeSubscriber();
	void init$(::jdk::internal::net::http::Http1AsyncReceiver* this$0);
	virtual void dropSubscription() override;
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	void requestMore();
	::jdk::internal::net::http::Http1AsyncReceiver* this$0 = nullptr;
	static bool $assertionsDisabled;
	$volatile(::java::util::concurrent::Flow$Subscription*) subscription = nullptr;
	$volatile(bool) completed = false;
	$volatile(bool) dropped = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1AsyncReceiver$Http1TubeSubscriber_h_