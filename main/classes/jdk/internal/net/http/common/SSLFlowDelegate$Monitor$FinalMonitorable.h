#ifndef _jdk_internal_net_http_common_SSLFlowDelegate$Monitor$FinalMonitorable_h_
#define _jdk_internal_net_http_common_SSLFlowDelegate$Monitor$FinalMonitorable_h_
//$ class jdk.internal.net.http.common.SSLFlowDelegate$Monitor$FinalMonitorable
//$ extends jdk.internal.net.http.common.SSLFlowDelegate$Monitorable

#include <jdk/internal/net/http/common/SSLFlowDelegate$Monitorable.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class SSLFlowDelegate$Monitor;
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

class $export SSLFlowDelegate$Monitor$FinalMonitorable : public ::jdk::internal::net::http::common::SSLFlowDelegate$Monitorable {
	$class(SSLFlowDelegate$Monitor$FinalMonitorable, $NO_CLASS_INIT, ::jdk::internal::net::http::common::SSLFlowDelegate$Monitorable)
public:
	SSLFlowDelegate$Monitor$FinalMonitorable();
	void init$(::jdk::internal::net::http::common::SSLFlowDelegate$Monitor* this$0, ::jdk::internal::net::http::common::SSLFlowDelegate$Monitorable* o);
	virtual $String* getInfo() override;
	::jdk::internal::net::http::common::SSLFlowDelegate$Monitor* this$0 = nullptr;
	$String* finalState = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SSLFlowDelegate$Monitor$FinalMonitorable_h_