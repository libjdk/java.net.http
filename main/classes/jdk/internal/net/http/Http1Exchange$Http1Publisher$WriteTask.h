#ifndef _jdk_internal_net_http_Http1Exchange$Http1Publisher$WriteTask_h_
#define _jdk_internal_net_http_Http1Exchange$Http1Publisher$WriteTask_h_
//$ class jdk.internal.net.http.Http1Exchange$Http1Publisher$WriteTask
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Http1Exchange$Http1Publisher;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Http1Exchange$Http1Publisher$WriteTask : public ::java::lang::Runnable {
	$class(Http1Exchange$Http1Publisher$WriteTask, 0, ::java::lang::Runnable)
public:
	Http1Exchange$Http1Publisher$WriteTask();
	void init$(::jdk::internal::net::http::Http1Exchange$Http1Publisher* this$1);
	$String* lambda$run$0();
	virtual void run() override;
	::jdk::internal::net::http::Http1Exchange$Http1Publisher* this$1 = nullptr;
	static bool $assertionsDisabled;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1Exchange$Http1Publisher$WriteTask_h_