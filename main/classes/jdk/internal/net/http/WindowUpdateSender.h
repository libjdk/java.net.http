#ifndef _jdk_internal_net_http_WindowUpdateSender_h_
#define _jdk_internal_net_http_WindowUpdateSender_h_
//$ class jdk.internal.net.http.WindowUpdateSender
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicInteger;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Http2Connection;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Logger;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export WindowUpdateSender : public ::java::lang::Object {
	$class(WindowUpdateSender, $NO_CLASS_INIT, ::java::lang::Object)
public:
	WindowUpdateSender();
	void init$(::jdk::internal::net::http::Http2Connection* connection);
	void init$(::jdk::internal::net::http::Http2Connection* connection, int32_t initWindowSize);
	void init$(::jdk::internal::net::http::Http2Connection* connection, int32_t maxFrameSize, int32_t initWindowSize);
	virtual $String* dbgString();
	virtual int32_t getStreamId() {return 0;}
	virtual void sendWindowUpdate(int32_t delta);
	virtual void update(int32_t delta);
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	int32_t limit = 0;
	::jdk::internal::net::http::Http2Connection* connection = nullptr;
	::java::util::concurrent::atomic::AtomicInteger* received = nullptr;
	$volatile($String*) dbgString$ = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_WindowUpdateSender_h_