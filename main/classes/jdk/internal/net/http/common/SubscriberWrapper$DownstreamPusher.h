#ifndef _jdk_internal_net_http_common_SubscriberWrapper$DownstreamPusher_h_
#define _jdk_internal_net_http_common_SubscriberWrapper$DownstreamPusher_h_
//$ class jdk.internal.net.http.common.SubscriberWrapper$DownstreamPusher
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class SubscriberWrapper;
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

class $export SubscriberWrapper$DownstreamPusher : public ::java::lang::Runnable {
	$class(SubscriberWrapper$DownstreamPusher, $NO_CLASS_INIT, ::java::lang::Runnable)
public:
	SubscriberWrapper$DownstreamPusher();
	void init$(::jdk::internal::net::http::common::SubscriberWrapper* this$0);
	virtual void run() override;
	void run1();
	::jdk::internal::net::http::common::SubscriberWrapper* this$0 = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SubscriberWrapper$DownstreamPusher_h_