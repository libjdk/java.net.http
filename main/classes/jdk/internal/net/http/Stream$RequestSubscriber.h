#ifndef _jdk_internal_net_http_Stream$RequestSubscriber_h_
#define _jdk_internal_net_http_Stream$RequestSubscriber_h_
//$ class jdk.internal.net.http.Stream$RequestSubscriber
//$ extends java.util.concurrent.Flow$Subscriber

#include <java/util/concurrent/Flow$Subscriber.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class ConcurrentLinkedDeque;
			class Flow$Subscription;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicReference;
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
					class SequentialScheduler;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Stream$RequestSubscriber : public ::java::util::concurrent::Flow$Subscriber {
	$class(Stream$RequestSubscriber, 0, ::java::util::concurrent::Flow$Subscriber)
public:
	Stream$RequestSubscriber();
	void init$(::jdk::internal::net::http::Stream* this$0, int64_t contentLen);
	void complete();
	static $String* lambda$onError$0($Throwable* throwable);
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	virtual void onNext(::java::nio::ByteBuffer* item);
	virtual void onNext(Object$* item) override;
	void onNextImpl(::java::nio::ByteBuffer* item);
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	virtual void trySend();
	::jdk::internal::net::http::Stream* this$0 = nullptr;
	static bool $assertionsDisabled;
	int64_t contentLength = 0;
	$volatile(int64_t) remainingContentLength = 0;
	$volatile(::java::util::concurrent::Flow$Subscription*) subscription = nullptr;
	::java::util::concurrent::ConcurrentLinkedDeque* outgoing = nullptr;
	::java::util::concurrent::atomic::AtomicReference* errorRef = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* sendScheduler = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Stream$RequestSubscriber_h_