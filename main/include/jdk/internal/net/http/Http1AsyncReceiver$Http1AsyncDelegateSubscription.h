#ifndef _jdk_internal_net_http_Http1AsyncReceiver$Http1AsyncDelegateSubscription_h_
#define _jdk_internal_net_http_Http1AsyncReceiver$Http1AsyncDelegateSubscription_h_
//$ class jdk.internal.net.http.Http1AsyncReceiver$Http1AsyncDelegateSubscription
//$ extends jdk.internal.net.http.AbstractSubscription

#include <jdk/internal/net/http/AbstractSubscription.h>

namespace java {
	namespace lang {
		class Runnable;
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
					class SequentialScheduler;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Http1AsyncReceiver$Http1AsyncDelegateSubscription : public ::jdk::internal::net::http::AbstractSubscription {
	$class(Http1AsyncReceiver$Http1AsyncDelegateSubscription, $NO_CLASS_INIT, ::jdk::internal::net::http::AbstractSubscription)
public:
	Http1AsyncReceiver$Http1AsyncDelegateSubscription();
	void init$(::jdk::internal::net::http::common::SequentialScheduler* scheduler, ::java::lang::Runnable* onCancel, ::java::util::function::Consumer* onError);
	virtual void cancel() override;
	virtual void request(int64_t n) override;
	::java::lang::Runnable* onCancel = nullptr;
	::java::util::function::Consumer* onError = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* scheduler = nullptr;
	$volatile(bool) cancelled = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1AsyncReceiver$Http1AsyncDelegateSubscription_h_