#ifndef _jdk_internal_net_http_HttpClientImpl$DefaultThreadFactory_h_
#define _jdk_internal_net_http_HttpClientImpl$DefaultThreadFactory_h_
//$ class jdk.internal.net.http.HttpClientImpl$DefaultThreadFactory
//$ extends java.util.concurrent.ThreadFactory

#include <java/util/concurrent/ThreadFactory.h>

namespace java {
	namespace lang {
		class Runnable;
		class Thread;
	}
}
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

class $import HttpClientImpl$DefaultThreadFactory : public ::java::util::concurrent::ThreadFactory {
	$class(HttpClientImpl$DefaultThreadFactory, $NO_CLASS_INIT, ::java::util::concurrent::ThreadFactory)
public:
	HttpClientImpl$DefaultThreadFactory();
	void init$(int64_t clientID);
	virtual $Thread* newThread(::java::lang::Runnable* r) override;
	$String* namePrefix = nullptr;
	::java::util::concurrent::atomic::AtomicInteger* nextId = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HttpClientImpl$DefaultThreadFactory_h_