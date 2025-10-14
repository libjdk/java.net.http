#ifndef _jdk_internal_net_http_common_SequentialScheduler$TryEndDeferredCompleter_h_
#define _jdk_internal_net_http_common_SequentialScheduler$TryEndDeferredCompleter_h_
//$ class jdk.internal.net.http.common.SequentialScheduler$TryEndDeferredCompleter
//$ extends jdk.internal.net.http.common.SequentialScheduler$DeferredCompleter

#include <jdk/internal/net/http/common/SequentialScheduler$DeferredCompleter.h>

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
				namespace common {

class $export SequentialScheduler$TryEndDeferredCompleter : public ::jdk::internal::net::http::common::SequentialScheduler$DeferredCompleter {
	$class(SequentialScheduler$TryEndDeferredCompleter, $NO_CLASS_INIT, ::jdk::internal::net::http::common::SequentialScheduler$DeferredCompleter)
public:
	SequentialScheduler$TryEndDeferredCompleter();
	void init$(::jdk::internal::net::http::common::SequentialScheduler* this$0);
	virtual void complete() override;
	::jdk::internal::net::http::common::SequentialScheduler* this$0 = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SequentialScheduler$TryEndDeferredCompleter_h_