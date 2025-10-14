#ifndef _jdk_internal_net_http_WindowController_h_
#define _jdk_internal_net_http_WindowController_h_
//$ class jdk.internal.net.http.WindowController
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("DEFAULT_INITIAL_WINDOW_SIZE")
#undef DEFAULT_INITIAL_WINDOW_SIZE

namespace java {
	namespace util {
		class Map;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace locks {
				class ReentrantLock;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Stream;
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

class $export WindowController : public ::java::lang::Object {
	$class(WindowController, 0, ::java::lang::Object)
public:
	WindowController();
	void init$();
	void adjustActiveStreams(int32_t adjustAmount);
	int32_t connectionWindowSize();
	bool increaseConnectionWindow(int32_t amount);
	bool increaseStreamWindow(int32_t amount, int32_t streamid);
	void registerStream(int32_t streamid, int32_t initialStreamWindowSize);
	void removeStream(int32_t streamid);
	int32_t streamWindowSize(int32_t streamid);
	int32_t tryAcquire(int32_t requestAmount, int32_t streamid, ::jdk::internal::net::http::Stream* stream);
	static bool $assertionsDisabled;
	static ::jdk::internal::net::http::common::Logger* debug;
	static const int32_t DEFAULT_INITIAL_WINDOW_SIZE = 65535; // 64 * 1024 - 1
	int32_t connectionWindowSize$ = 0;
	::java::util::Map* streams = nullptr;
	::java::util::Map* pending = nullptr;
	::java::util::concurrent::locks::ReentrantLock* controllerLock = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("DEFAULT_INITIAL_WINDOW_SIZE")

#endif // _jdk_internal_net_http_WindowController_h_