#ifndef _jdk_internal_net_http_HttpConnection$PlainHttpPublisher$HttpWriteSubscription_h_
#define _jdk_internal_net_http_HttpConnection$PlainHttpPublisher$HttpWriteSubscription_h_
//$ class jdk.internal.net.http.HttpConnection$PlainHttpPublisher$HttpWriteSubscription
//$ extends java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>

namespace java {
	namespace util {
		class List;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class HttpConnection$PlainHttpPublisher;
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
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import HttpConnection$PlainHttpPublisher$HttpWriteSubscription : public ::java::util::concurrent::Flow$Subscription {
	$class(HttpConnection$PlainHttpPublisher$HttpWriteSubscription, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Subscription)
public:
	HttpConnection$PlainHttpPublisher$HttpWriteSubscription();
	void init$(::jdk::internal::net::http::HttpConnection$PlainHttpPublisher* this$1);
	virtual void cancel() override;
	void flush();
	bool isEmpty();
	::java::util::List* poll();
	virtual void request(int64_t n) override;
	::jdk::internal::net::http::HttpConnection$PlainHttpPublisher* this$1 = nullptr;
	::jdk::internal::net::http::common::Demand* demand = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HttpConnection$PlainHttpPublisher$HttpWriteSubscription_h_