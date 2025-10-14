#ifndef _jdk_internal_net_http_Http1Exchange$Http1Publisher_h_
#define _jdk_internal_net_http_Http1Exchange$Http1Publisher_h_
//$ class jdk.internal.net.http.Http1Exchange$Http1Publisher
//$ extends jdk.internal.net.http.common.FlowTube$TubePublisher

#include <jdk/internal/net/http/common/FlowTube$TubePublisher.h>

namespace java {
	namespace util {
		namespace concurrent {
			class Flow$Subscriber;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Http1Exchange;
				class Http1Exchange$Http1Publisher$Http1WriteSubscription;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Demand;
					class Logger;
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

class $export Http1Exchange$Http1Publisher : public ::jdk::internal::net::http::common::FlowTube$TubePublisher {
	$class(Http1Exchange$Http1Publisher, 0, ::jdk::internal::net::http::common::FlowTube$TubePublisher)
public:
	Http1Exchange$Http1Publisher();
	void init$(::jdk::internal::net::http::Http1Exchange* this$0);
	bool checkRequestCancelled();
	$String* dbgString();
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* s) override;
	::jdk::internal::net::http::Http1Exchange* this$0 = nullptr;
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	$volatile(::java::util::concurrent::Flow$Subscriber*) subscriber = nullptr;
	$volatile(bool) cancelled = false;
	::jdk::internal::net::http::Http1Exchange$Http1Publisher$Http1WriteSubscription* subscription = nullptr;
	::jdk::internal::net::http::common::Demand* demand = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* writeScheduler = nullptr;
	$volatile($String*) dbgTag = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1Exchange$Http1Publisher_h_