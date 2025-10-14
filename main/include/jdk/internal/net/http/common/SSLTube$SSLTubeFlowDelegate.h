#ifndef _jdk_internal_net_http_common_SSLTube$SSLTubeFlowDelegate_h_
#define _jdk_internal_net_http_common_SSLTube$SSLTubeFlowDelegate_h_
//$ class jdk.internal.net.http.common.SSLTube$SSLTubeFlowDelegate
//$ extends jdk.internal.net.http.common.SSLFlowDelegate

#include <jdk/internal/net/http/common/SSLFlowDelegate.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class Executor;
			class Flow$Subscriber;
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
namespace javax {
	namespace net {
		namespace ssl {
			class SSLEngine;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class FlowTube;
					class SSLTube;
					class SSLTube$SSLSubscriberWrapper;
					class SubscriberWrapper$SchedulingAction;
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

class $import SSLTube$SSLTubeFlowDelegate : public ::jdk::internal::net::http::common::SSLFlowDelegate {
	$class(SSLTube$SSLTubeFlowDelegate, 0, ::jdk::internal::net::http::common::SSLFlowDelegate)
public:
	SSLTube$SSLTubeFlowDelegate();
	void init$(::jdk::internal::net::http::common::SSLTube* this$0, ::javax::net::ssl::SSLEngine* engine, ::java::util::concurrent::Executor* executor, ::java::util::function::Consumer* recycler, ::jdk::internal::net::http::common::SSLTube$SSLSubscriberWrapper* readSubscriber, ::jdk::internal::net::http::common::FlowTube* tube);
	virtual $Throwable* checkForHandshake($Throwable* t) override;
	virtual void connect(::java::util::concurrent::Flow$Subscriber* downReader, ::java::util::concurrent::Flow$Subscriber* downWriter) override;
	virtual ::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction* enterReadScheduling() override;
	::jdk::internal::net::http::common::SSLTube* this$0 = nullptr;
	static bool $assertionsDisabled;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SSLTube$SSLTubeFlowDelegate_h_