#ifndef _jdk_internal_net_http_TimeoutEvent_h_
#define _jdk_internal_net_http_TimeoutEvent_h_
//$ class jdk.internal.net.http.TimeoutEvent
//$ extends java.lang.Comparable

#include <java/lang/Comparable.h>

#pragma push_macro("COUNTER")
#undef COUNTER

namespace java {
	namespace time {
		class Duration;
		class Instant;
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

class $import TimeoutEvent : public ::java::lang::Comparable {
	$class(TimeoutEvent, 0, ::java::lang::Comparable)
public:
	TimeoutEvent();
	void init$(::java::time::Duration* duration);
	virtual int32_t compareTo(::jdk::internal::net::http::TimeoutEvent* other);
	virtual int32_t compareTo(Object$* other) override;
	virtual ::java::time::Instant* deadline();
	virtual void handle() {}
	virtual $String* toString() override;
	static bool $assertionsDisabled;
	static ::java::util::concurrent::atomic::AtomicLong* COUNTER;
	int64_t id = 0;
	::java::time::Duration* duration = nullptr;
	::java::time::Instant* deadline$ = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("COUNTER")

#endif // _jdk_internal_net_http_TimeoutEvent_h_