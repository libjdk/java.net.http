#ifndef _jdk_internal_net_http_common_Demand_h_
#define _jdk_internal_net_http_common_Demand_h_
//$ class jdk.internal.net.http.common.Demand
//$ extends java.lang.Object

#include <java/lang/Object.h>

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
				namespace common {

class $import Demand : public ::java::lang::Object {
	$class(Demand, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Demand();
	void init$();
	int64_t decreaseAndGet(int64_t n);
	int64_t get();
	bool increase(int64_t n);
	bool increaseIfFulfilled();
	bool isFulfilled();
	static int64_t lambda$increase$0(int64_t p, int64_t i);
	void reset();
	virtual $String* toString() override;
	bool tryDecrement();
	::java::util::concurrent::atomic::AtomicLong* val = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_Demand_h_