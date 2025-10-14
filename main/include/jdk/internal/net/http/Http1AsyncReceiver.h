#ifndef _jdk_internal_net_http_Http1AsyncReceiver_h_
#define _jdk_internal_net_http_Http1AsyncReceiver_h_
//$ class jdk.internal.net.http.Http1AsyncReceiver
//$ extends java.lang.Object

#include <java/lang/Array.h>

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
			class Executor;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicBoolean;
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
				class Http1AsyncReceiver$Http1AsyncDelegate;
				class Http1AsyncReceiver$Http1TubeSubscriber;
				class Http1Exchange;
				class HttpClientImpl;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class FlowTube$TubeSubscriber;
					class Logger;
					class MinimalFuture;
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

class $import Http1AsyncReceiver : public ::java::lang::Object {
	$class(Http1AsyncReceiver, 0, ::java::lang::Object)
public:
	Http1AsyncReceiver();
	void init$(::java::util::concurrent::Executor* executor, ::jdk::internal::net::http::Http1Exchange* owner);
	void asyncReceive(::java::nio::ByteBuffer* buf);
	void checkForErrors();
	void checkRequestMore();
	virtual void clear();
	virtual $String* dbgString();
	$String* debugQBB($Array<::java::nio::ByteBuffer>* qbb);
	$String* describe();
	virtual ::java::nio::ByteBuffer* drain(::java::nio::ByteBuffer* initial);
	void flush();
	bool handlePendingDelegate();
	bool hasDemand(::jdk::internal::net::http::Http1AsyncReceiver$Http1AsyncDelegate* delegate);
	$String* lambda$checkForErrors$1($Throwable* x, Object$* captured);
	$String* lambda$flush$0(int64_t remaining);
	void lambda$handlePendingDelegate$2($Throwable* x);
	void lambda$handlePendingDelegate$3(::jdk::internal::net::http::Http1AsyncReceiver$Http1AsyncDelegate* pending);
	virtual void onReadError($Throwable* ex);
	virtual int64_t remaining();
	virtual void setRetryOnError(bool retry);
	virtual void stop();
	virtual void subscribe(::jdk::internal::net::http::Http1AsyncReceiver$Http1AsyncDelegate* delegate);
	virtual ::jdk::internal::net::http::common::FlowTube$TubeSubscriber* subscriber();
	virtual void unsubscribe(::jdk::internal::net::http::Http1AsyncReceiver$Http1AsyncDelegate* delegate);
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	::java::util::concurrent::ConcurrentLinkedDeque* queue = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* scheduler = nullptr;
	::jdk::internal::net::http::common::MinimalFuture* whenFinished = nullptr;
	::java::util::concurrent::Executor* executor = nullptr;
	::jdk::internal::net::http::Http1AsyncReceiver$Http1TubeSubscriber* subscriber$ = nullptr;
	::java::util::concurrent::atomic::AtomicReference* pendingDelegateRef = nullptr;
	::java::util::concurrent::atomic::AtomicLong* received = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* canRequestMore = nullptr;
	$volatile($Throwable*) error = nullptr;
	$volatile(::jdk::internal::net::http::Http1AsyncReceiver$Http1AsyncDelegate*) delegate = nullptr;
	$volatile(::jdk::internal::net::http::Http1Exchange*) owner = nullptr;
	::jdk::internal::net::http::HttpClientImpl* client = nullptr;
	bool retry = false;
	$volatile(bool) stopRequested = false;
	$volatile($String*) dbgTag = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1AsyncReceiver_h_