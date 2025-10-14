#ifndef _jdk_internal_net_http_common_SequentialScheduler$DeferredCompleter_h_
#define _jdk_internal_net_http_common_SequentialScheduler$DeferredCompleter_h_
//$ class jdk.internal.net.http.common.SequentialScheduler$DeferredCompleter
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $import SequentialScheduler$DeferredCompleter : public ::java::lang::Object {
	$class(SequentialScheduler$DeferredCompleter, $NO_CLASS_INIT, ::java::lang::Object)
public:
	SequentialScheduler$DeferredCompleter();
	void init$();
	virtual void complete() {}
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SequentialScheduler$DeferredCompleter_h_