#ifndef _jdk_internal_net_http_common_SSLTube$DelegateWrapper_h_
#define _jdk_internal_net_http_common_SSLTube$DelegateWrapper_h_
//$ class jdk.internal.net.http.common.SSLTube$DelegateWrapper
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
			class Flow$Subscriber;
			class Flow$Subscription;
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Consumer;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Logger;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export SSLTube$DelegateWrapper : public ::jdk::internal::net::http::common::FlowTube$TubeSubscriber {
	$class(SSLTube$DelegateWrapper, 0, ::jdk::internal::net::http::common::FlowTube$TubeSubscriber)
public:
	SSLTube$DelegateWrapper();
	void init$(::java::util::concurrent::Flow$Subscriber* delegate, ::jdk::internal::net::http::common::Logger* debug);
	virtual void dropSubscription() override;
	virtual void onComplete() override;
	virtual void onError($Throwable* t) override;
	void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	void onSubscribe(::java::util::function::Consumer* method, ::java::util::concurrent::Flow$Subscription* subscription);
	virtual $String* toString() override;
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::FlowTube$TubeSubscriber* delegate = nullptr;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	$volatile(bool) subscribedCalled = false;
	$volatile(bool) subscribedDone = false;
	$volatile(bool) completed = false;
	$volatile($Throwable*) error = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SSLTube$DelegateWrapper_h_