#ifndef _jdk_internal_net_http_common_SSLFlowDelegate$Writer$WriterDownstreamPusher_h_
#define _jdk_internal_net_http_common_SSLFlowDelegate$Writer$WriterDownstreamPusher_h_
//$ class jdk.internal.net.http.common.SSLFlowDelegate$Writer$WriterDownstreamPusher
//$ extends jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask

#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class SSLFlowDelegate$Writer;
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

class $export SSLFlowDelegate$Writer$WriterDownstreamPusher : public ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask {
	$class(SSLFlowDelegate$Writer$WriterDownstreamPusher, $NO_CLASS_INIT, ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask)
public:
	SSLFlowDelegate$Writer$WriterDownstreamPusher();
	void init$(::jdk::internal::net::http::common::SSLFlowDelegate$Writer* this$1);
	using ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask::run;
	virtual void run() override;
	::jdk::internal::net::http::common::SSLFlowDelegate$Writer* this$1 = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SSLFlowDelegate$Writer$WriterDownstreamPusher_h_