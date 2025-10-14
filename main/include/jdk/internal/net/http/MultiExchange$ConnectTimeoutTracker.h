#ifndef _jdk_internal_net_http_MultiExchange$ConnectTimeoutTracker_h_
#define _jdk_internal_net_http_MultiExchange$ConnectTimeoutTracker_h_
//$ class jdk.internal.net.http.MultiExchange$ConnectTimeoutTracker
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace time {
		class Duration;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicLong;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import MultiExchange$ConnectTimeoutTracker : public ::java::lang::Object {
	$class(MultiExchange$ConnectTimeoutTracker, 0, ::java::lang::Object)
public:
	MultiExchange$ConnectTimeoutTracker();
	void init$(::java::time::Duration* connectTimeout);
	::java::time::Duration* getRemaining();
	void reset();
	static bool $assertionsDisabled;
	::java::time::Duration* max = nullptr;
	::java::util::concurrent::atomic::AtomicLong* startTime = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_MultiExchange$ConnectTimeoutTracker_h_