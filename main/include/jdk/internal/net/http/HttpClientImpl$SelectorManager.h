#ifndef _jdk_internal_net_http_HttpClientImpl$SelectorManager_h_
#define _jdk_internal_net_http_HttpClientImpl$SelectorManager_h_
//$ class jdk.internal.net.http.HttpClientImpl$SelectorManager
//$ extends java.lang.Thread

#include <java/lang/Thread.h>

#pragma push_macro("DEF_NODEADLINE")
#undef DEF_NODEADLINE
#pragma push_macro("MAX_NODEADLINE")
#undef MAX_NODEADLINE
#pragma push_macro("MIN_NODEADLINE")
#undef MIN_NODEADLINE
#pragma push_macro("NODEADLINE")
#undef NODEADLINE

namespace java {
	namespace io {
		class IOException;
	}
}
namespace java {
	namespace lang {
		class Runnable;
	}
}
namespace java {
	namespace nio {
		namespace channels {
			class Selector;
			class SocketChannel;
		}
	}
}
namespace java {
	namespace util {
		class List;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class AsyncEvent;
				class ConnectionPool;
				class HttpClientImpl;
				class HttpClientImpl$SelectorAttachment;
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
					class Pair;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import HttpClientImpl$SelectorManager : public ::java::lang::Thread {
	$class(HttpClientImpl$SelectorManager, 0, ::java::lang::Thread)
public:
	HttpClientImpl$SelectorManager();
	void init$(::jdk::internal::net::http::HttpClientImpl* ref);
	void cancel(::java::nio::channels::SocketChannel* e);
	void eventUpdated(::jdk::internal::net::http::AsyncEvent* e);
	void handleEvent(::jdk::internal::net::http::AsyncEvent* event, ::java::io::IOException* ioe);
	static void lambda$run$0(::java::util::List* errorList, ::java::io::IOException* ex, ::jdk::internal::net::http::AsyncEvent* e);
	static void lambda$run$2(::jdk::internal::net::http::HttpClientImpl$SelectorAttachment* sa, int32_t eventsOccurred);
	void lambda$run$3(::jdk::internal::net::http::AsyncEvent* e);
	void lambda$run$4(::jdk::internal::net::http::common::Pair* p);
	static void lambda$run$5(::java::lang::Runnable* r);
	void register$(::jdk::internal::net::http::AsyncEvent* e);
	virtual void run() override;
	void shutdown();
	void wakeupSelector();
	static bool $assertionsDisabled;
	static const int32_t MIN_NODEADLINE = 1000;
	static const int32_t MAX_NODEADLINE = 1200000; // 1000 * 1200
	static const int32_t DEF_NODEADLINE = 3000;
	static int64_t NODEADLINE;
	::java::nio::channels::Selector* selector = nullptr;
	$volatile(bool) closed = false;
	::java::util::List* registrations = nullptr;
	::java::util::List* deregistrations = nullptr;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	::jdk::internal::net::http::common::Logger* debugtimeout = nullptr;
	::jdk::internal::net::http::HttpClientImpl* owner = nullptr;
	::jdk::internal::net::http::ConnectionPool* pool = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("DEF_NODEADLINE")
#pragma pop_macro("MAX_NODEADLINE")
#pragma pop_macro("MIN_NODEADLINE")
#pragma pop_macro("NODEADLINE")

#endif // _jdk_internal_net_http_HttpClientImpl$SelectorManager_h_