#ifndef _jdk_internal_net_http_AsyncEvent_h_
#define _jdk_internal_net_http_AsyncEvent_h_
//$ class jdk.internal.net.http.AsyncEvent
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("REPEATING")
#undef REPEATING

namespace java {
	namespace io {
		class IOException;
	}
}
namespace java {
	namespace nio {
		namespace channels {
			class SelectableChannel;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import AsyncEvent : public ::java::lang::Object {
	$class(AsyncEvent, $NO_CLASS_INIT, ::java::lang::Object)
public:
	AsyncEvent();
	void init$();
	void init$(int32_t flags);
	virtual void abort(::java::io::IOException* ioe) {}
	virtual ::java::nio::channels::SelectableChannel* channel() {return nullptr;}
	virtual void handle() {}
	virtual int32_t interestOps() {return 0;}
	virtual bool repeating();
	static const int32_t REPEATING = 2;
	int32_t flags = 0;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("REPEATING")

#endif // _jdk_internal_net_http_AsyncEvent_h_