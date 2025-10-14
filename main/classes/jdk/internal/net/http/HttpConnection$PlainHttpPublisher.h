#ifndef _jdk_internal_net_http_HttpConnection$PlainHttpPublisher_h_
#define _jdk_internal_net_http_HttpConnection$PlainHttpPublisher_h_
//$ class jdk.internal.net.http.HttpConnection$PlainHttpPublisher
//$ extends jdk.internal.net.http.HttpConnection$HttpPublisher

#include <jdk/internal/net/http/HttpConnection$HttpPublisher.h>

namespace java {
	namespace util {
		class List;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class ConcurrentLinkedDeque;
			class Flow$Subscriber;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class HttpConnection;
				class HttpConnection$PlainHttpPublisher$HttpWriteSubscription;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class SequentialScheduler;
					class SequentialScheduler$DeferredCompleter;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export HttpConnection$PlainHttpPublisher : public ::jdk::internal::net::http::HttpConnection$HttpPublisher {
	$class(HttpConnection$PlainHttpPublisher, $NO_CLASS_INIT, ::jdk::internal::net::http::HttpConnection$HttpPublisher)
public:
	HttpConnection$PlainHttpPublisher();
	void init$(::jdk::internal::net::http::HttpConnection* this$0);
	void init$(::jdk::internal::net::http::HttpConnection* this$0, Object$* readingLock);
	virtual void enqueue(::java::util::List* buffers) override;
	virtual void enqueueUnordered(::java::util::List* buffers) override;
	void flushTask(::jdk::internal::net::http::common::SequentialScheduler$DeferredCompleter* completer);
	void signal();
	virtual void signalEnqueued() override;
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* subscriber) override;
	::jdk::internal::net::http::HttpConnection* this$0 = nullptr;
	$Object* reading = nullptr;
	::java::util::concurrent::ConcurrentLinkedDeque* queue = nullptr;
	::java::util::concurrent::ConcurrentLinkedDeque* priority = nullptr;
	$volatile(::java::util::concurrent::Flow$Subscriber*) subscriber = nullptr;
	$volatile(::jdk::internal::net::http::HttpConnection$PlainHttpPublisher$HttpWriteSubscription*) subscription = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* writeScheduler = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HttpConnection$PlainHttpPublisher_h_