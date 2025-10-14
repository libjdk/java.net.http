#ifndef _jdk_internal_net_http_LineSubscriberAdapter$LineSubscription_h_
#define _jdk_internal_net_http_LineSubscriberAdapter$LineSubscription_h_
//$ class jdk.internal.net.http.LineSubscriberAdapter$LineSubscription
//$ extends java.util.concurrent.Flow$Subscription

#include <java/lang/Array.h>
#include <java/util/concurrent/Flow$Subscription.h>

namespace java {
	namespace lang {
		class StringBuilder;
		class Throwable;
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
		class CharBuffer;
	}
}
namespace java {
	namespace nio {
		namespace charset {
			class Charset;
			class CharsetDecoder;
		}
	}
}
namespace java {
	namespace util {
		class List;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
			class ConcurrentLinkedDeque;
			class Flow$Subscriber;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicLong;
				class AtomicReference;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Demand;
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

class $import LineSubscriberAdapter$LineSubscription : public ::java::util::concurrent::Flow$Subscription {
	$class(LineSubscriberAdapter$LineSubscription, 0, ::java::util::concurrent::Flow$Subscription)
public:
	LineSubscriberAdapter$LineSubscription();
	void init$(::java::util::concurrent::Flow$Subscription* s, ::java::nio::charset::CharsetDecoder* dec, $String* separator, ::java::util::concurrent::Flow$Subscriber* subscriber, ::java::util::concurrent::CompletableFuture* completion);
	virtual void cancel() override;
	static ::jdk::internal::net::http::LineSubscriberAdapter$LineSubscription* create(::java::util::concurrent::Flow$Subscription* s, ::java::nio::charset::Charset* charset, $String* lineSeparator, ::java::util::concurrent::Flow$Subscriber* upstream, ::java::util::concurrent::CompletableFuture* cf);
	static int32_t endOfLine(::java::lang::StringBuilder* b, $String* eol, bool endOfInput);
	bool isUnderFlow(::java::nio::ByteBuffer* in, ::java::nio::CharBuffer* out, bool endOfInput);
	void loop();
	static $String* nextLine(::java::lang::StringBuilder* b, $String* eol, bool endOfInput);
	$String* nextLine();
	virtual void request(int64_t n) override;
	void signalComplete();
	void signalError($Throwable* error);
	void submit(::java::util::List* list);
	static $String* take(::java::lang::StringBuilder* b, int32_t start, int32_t end);
	static bool $assertionsDisabled;
	::java::util::concurrent::Flow$Subscription* upstreamSubscription = nullptr;
	::java::nio::charset::CharsetDecoder* decoder = nullptr;
	$String* newline = nullptr;
	::jdk::internal::net::http::common::Demand* downstreamDemand = nullptr;
	::java::util::concurrent::ConcurrentLinkedDeque* queue = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* scheduler = nullptr;
	::java::util::concurrent::Flow$Subscriber* upstream = nullptr;
	::java::util::concurrent::CompletableFuture* cf = nullptr;
	::java::util::concurrent::atomic::AtomicReference* errorRef = nullptr;
	::java::util::concurrent::atomic::AtomicLong* demanded = nullptr;
	$volatile(bool) completed = false;
	$volatile(bool) cancelled = false;
	$chars* chars = nullptr;
	::java::nio::ByteBuffer* leftover = nullptr;
	::java::nio::CharBuffer* buffer = nullptr;
	::java::lang::StringBuilder* builder = nullptr;
	$String* nextLine$ = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_LineSubscriberAdapter$LineSubscription_h_