#ifndef _jdk_internal_net_http_common_SubscriberWrapper$SchedulingAction_h_
#define _jdk_internal_net_http_common_SubscriberWrapper$SchedulingAction_h_
//$ class jdk.internal.net.http.common.SubscriberWrapper$SchedulingAction
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("CONTINUE")
#undef CONTINUE
#pragma push_macro("RESCHEDULE")
#undef RESCHEDULE
#pragma push_macro("RETURN")
#undef RETURN

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export SubscriberWrapper$SchedulingAction : public ::java::lang::Enum {
	$class(SubscriberWrapper$SchedulingAction, 0, ::java::lang::Enum)
public:
	SubscriberWrapper$SchedulingAction();
	static $Array<::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction* valueOf($String* name);
	static $Array<::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction>* values();
	static ::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction* CONTINUE;
	static ::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction* RETURN;
	static ::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction* RESCHEDULE;
	static $Array<::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction>* $VALUES;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("CONTINUE")
#pragma pop_macro("RESCHEDULE")
#pragma pop_macro("RETURN")

#endif // _jdk_internal_net_http_common_SubscriberWrapper$SchedulingAction_h_