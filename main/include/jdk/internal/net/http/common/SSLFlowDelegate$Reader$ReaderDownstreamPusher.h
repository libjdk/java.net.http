#ifndef _jdk_internal_net_http_common_SSLFlowDelegate$Reader$ReaderDownstreamPusher_h_
#define _jdk_internal_net_http_common_SSLFlowDelegate$Reader$ReaderDownstreamPusher_h_
//$ class jdk.internal.net.http.common.SSLFlowDelegate$Reader$ReaderDownstreamPusher
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class SSLFlowDelegate$Reader;
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

class $import SSLFlowDelegate$Reader$ReaderDownstreamPusher : public ::java::lang::Runnable {
	$class(SSLFlowDelegate$Reader$ReaderDownstreamPusher, $NO_CLASS_INIT, ::java::lang::Runnable)
public:
	SSLFlowDelegate$Reader$ReaderDownstreamPusher();
	void init$(::jdk::internal::net::http::common::SSLFlowDelegate$Reader* this$1);
	virtual void run() override;
	::jdk::internal::net::http::common::SSLFlowDelegate$Reader* this$1 = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SSLFlowDelegate$Reader$ReaderDownstreamPusher_h_