#ifndef _jdk_internal_net_http_Http1Exchange$Http1BodySubscriber_h_
#define _jdk_internal_net_http_Http1Exchange$Http1BodySubscriber_h_
//$ class jdk.internal.net.http.Http1Exchange$Http1BodySubscriber
//$ extends java.util.concurrent.Flow$Subscriber

#include <java/util/concurrent/Flow$Subscriber.h>

#pragma push_macro("COMPLETED")
#undef COMPLETED

namespace java {
	namespace util {
		class List;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class Flow$Subscription;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Logger;
					class MinimalFuture;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Http1Exchange$Http1BodySubscriber : public ::java::util::concurrent::Flow$Subscriber {
	$class(Http1Exchange$Http1BodySubscriber, 0, ::java::util::concurrent::Flow$Subscriber)
public:
	Http1Exchange$Http1BodySubscriber();
	void init$(::jdk::internal::net::http::common::Logger* debug);
	void cancelSubscription();
	static ::jdk::internal::net::http::Http1Exchange$Http1BodySubscriber* completeSubscriber(::jdk::internal::net::http::common::Logger* debug);
	virtual $String* currentStateMessage() {return nullptr;}
	bool isSubscribed();
	void request(int64_t n);
	void setSubscription(::java::util::concurrent::Flow$Subscription* subscription);
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::MinimalFuture* whenSubscribed = nullptr;
	$volatile(::java::util::concurrent::Flow$Subscription*) subscription = nullptr;
	$volatile(bool) complete = false;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	static ::java::util::List* COMPLETED;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("COMPLETED")

#endif // _jdk_internal_net_http_Http1Exchange$Http1BodySubscriber_h_