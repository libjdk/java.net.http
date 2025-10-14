#ifndef _jdk_internal_net_http_BufferingSubscriber_h_
#define _jdk_internal_net_http_BufferingSubscriber_h_
//$ class jdk.internal.net.http.BufferingSubscriber
//$ extends jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber

#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>

#pragma push_macro("ACTIVE")
#undef ACTIVE
#pragma push_macro("CANCELLED")
#undef CANCELLED
#pragma push_macro("COMPLETE")
#undef COMPLETE
#pragma push_macro("ERROR")
#undef ERROR
#pragma push_macro("UNSUBSCRIBED")
#undef UNSUBSCRIBED

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpResponse$BodySubscriber;
		}
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace java {
	namespace util {
		class ArrayList;
		class List;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletionStage;
			class Flow$Subscription;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class BufferingSubscriber$DownstreamSubscription;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import BufferingSubscriber : public ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber {
	$class(BufferingSubscriber, 0, ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber)
public:
	BufferingSubscriber();
	void init$(::java::net::http::HttpResponse$BodySubscriber* downstreamSubscriber, int32_t bufferSize);
	::java::util::List* fromInternalBuffers();
	virtual ::java::util::concurrent::CompletionStage* getBody() override;
	bool hasEnoughAccumulatedBytes();
	static bool lambda$fromInternalBuffers$0(::java::nio::ByteBuffer* b);
	virtual bool needsExecutor() override;
	virtual void onComplete() override;
	virtual void onError($Throwable* incomingThrowable) override;
	virtual void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	static int64_t remaining(::java::util::List* buffers);
	static bool $assertionsDisabled;
	::java::net::http::HttpResponse$BodySubscriber* downstreamSubscriber = nullptr;
	int32_t bufferSize = 0;
	$volatile(::java::util::concurrent::Flow$Subscription*) subscription = nullptr;
	$volatile(::jdk::internal::net::http::BufferingSubscriber$DownstreamSubscription*) downstreamSubscription = nullptr;
	$Object* buffersLock = nullptr;
	::java::util::ArrayList* internalBuffers = nullptr;
	int32_t accumulatedBytes = 0;
	$volatile($Throwable*) throwable = nullptr;
	static const int32_t UNSUBSCRIBED = 1;
	static const int32_t ACTIVE = 2;
	static const int32_t ERROR = 4;
	static const int32_t CANCELLED = 8;
	static const int32_t COMPLETE = 16;
	$volatile(int32_t) state = 0;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("ACTIVE")
#pragma pop_macro("CANCELLED")
#pragma pop_macro("COMPLETE")
#pragma pop_macro("ERROR")
#pragma pop_macro("UNSUBSCRIBED")

#endif // _jdk_internal_net_http_BufferingSubscriber_h_