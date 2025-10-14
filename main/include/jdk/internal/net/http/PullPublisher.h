#ifndef _jdk_internal_net_http_PullPublisher_h_
#define _jdk_internal_net_http_PullPublisher_h_
//$ class jdk.internal.net.http.PullPublisher
//$ extends java.util.concurrent.Flow$Publisher

#include <java/util/concurrent/Flow$Publisher.h>

namespace java {
	namespace lang {
		class Iterable;
		class Throwable;
	}
}
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

class $import PullPublisher : public ::java::util::concurrent::Flow$Publisher {
	$class(PullPublisher, 0, ::java::util::concurrent::Flow$Publisher)
public:
	PullPublisher();
	void init$(::java::lang::Iterable* iterable, $Throwable* throwable);
	void init$(::java::lang::Iterable* iterable);
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* subscriber) override;
	static bool $assertionsDisabled;
	::java::lang::Iterable* iterable = nullptr;
	$Throwable* throwable = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_PullPublisher_h_