#ifndef _jdk_internal_net_http_common_SSLFlowDelegate_h_
#define _jdk_internal_net_http_common_SSLFlowDelegate_h_
//$ class jdk.internal.net.http.common.SSLFlowDelegate
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("DOING_TASKS")
#undef DOING_TASKS
#pragma push_macro("FINISH_OR_DO_TASKS")
#undef FINISH_OR_DO_TASKS
#pragma push_macro("HANDSHAKING")
#undef HANDSHAKING
#pragma push_macro("HS_TRIGGER")
#undef HS_TRIGGER
#pragma push_macro("NOTHING")
#undef NOTHING
#pragma push_macro("NOT_HANDSHAKING")
#undef NOT_HANDSHAKING
#pragma push_macro("READER")
#undef READER
#pragma push_macro("REQUESTING_TASKS")
#undef REQUESTING_TASKS
#pragma push_macro("REQUEST_OR_DO_TASKS")
#undef REQUEST_OR_DO_TASKS
#pragma push_macro("SENTINEL")
#undef SENTINEL
#pragma push_macro("TASK_BITS")
#undef TASK_BITS
#pragma push_macro("WRITER")
#undef WRITER

namespace java {
	namespace lang {
		class Throwable;
		class Void;
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
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
			class ConcurrentLinkedQueue;
			class Executor;
			class Flow$Subscriber;
		}
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
namespace java {
	namespace util {
		namespace function {
			class Consumer;
			class IntBinaryOperator;
		}
	}
}
namespace javax {
	namespace net {
		namespace ssl {
			class SSLEngine;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Logger;
					class SSLFlowDelegate$EngineResult;
					class SSLFlowDelegate$Monitorable;
					class SSLFlowDelegate$Reader;
					class SSLFlowDelegate$Writer;
					class SubscriberWrapper$SchedulingAction;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $import SSLFlowDelegate : public ::java::lang::Object {
	$class(SSLFlowDelegate, 0, ::java::lang::Object)
public:
	SSLFlowDelegate();
	void init$(::javax::net::ssl::SSLEngine* engine, ::java::util::concurrent::Executor* exec, ::java::util::concurrent::Flow$Subscriber* downReader, ::java::util::concurrent::Flow$Subscriber* downWriter);
	void init$(::javax::net::ssl::SSLEngine* engine, ::java::util::concurrent::Executor* exec, ::java::util::function::Consumer* recycler, ::java::util::concurrent::Flow$Subscriber* downReader, ::java::util::concurrent::Flow$Subscriber* downWriter);
	virtual ::java::util::concurrent::CompletableFuture* alpn();
	virtual $Throwable* checkForHandshake($Throwable* t);
	void cleanList(::java::util::List* l);
	virtual bool closeNotifyReceived();
	virtual void connect(::java::util::concurrent::Flow$Subscriber* downReader, ::java::util::concurrent::Flow$Subscriber* downWriter);
	$String* dbgString();
	virtual ::jdk::internal::net::http::common::SSLFlowDelegate$EngineResult* doClosure(::jdk::internal::net::http::common::SSLFlowDelegate$EngineResult* r);
	bool doHandshake(::jdk::internal::net::http::common::SSLFlowDelegate$EngineResult* r, int32_t caller);
	virtual ::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction* enterReadScheduling();
	void executeTasks(::java::util::List* tasks);
	::java::nio::ByteBuffer* getAppBuffer();
	::java::nio::ByteBuffer* getNetBuffer();
	void handleError($Throwable* t);
	static int32_t lambda$doHandshake$2(int32_t current, int32_t unused);
	void lambda$executeTasks$3(::java::util::List* tasks);
	static int32_t lambda$static$0(int32_t current, int32_t ignored);
	static int32_t lambda$static$1(int32_t current, int32_t ignored);
	virtual $String* monitor();
	void normalStop();
	::java::util::List* obtainTasks();
	virtual void resetReaderDemand();
	void resumeActivity();
	virtual bool resumeReader();
	void setALPN();
	static $String* states(::java::util::concurrent::atomic::AtomicInteger* state);
	::java::lang::Void* stopOnError($Throwable* error);
	virtual bool trySetALPN();
	virtual ::java::util::concurrent::Flow$Subscriber* upstreamReader();
	virtual ::java::util::concurrent::Flow$Subscriber* upstreamWriter();
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	static ::java::nio::ByteBuffer* SENTINEL;
	static ::java::nio::ByteBuffer* HS_TRIGGER;
	static ::java::nio::ByteBuffer* NOTHING;
	static $String* monProp;
	static bool isMonitored;
	::java::util::concurrent::Executor* exec = nullptr;
	::jdk::internal::net::http::common::SSLFlowDelegate$Reader* reader = nullptr;
	::jdk::internal::net::http::common::SSLFlowDelegate$Writer* writer = nullptr;
	::javax::net::ssl::SSLEngine* engine = nullptr;
	$String* tubeName = nullptr;
	::java::util::concurrent::CompletableFuture* alpnCF = nullptr;
	::jdk::internal::net::http::common::SSLFlowDelegate$Monitorable* monitor$ = nullptr;
	$volatile(bool) close_notify_received = false;
	::java::util::concurrent::CompletableFuture* readerCF = nullptr;
	::java::util::concurrent::CompletableFuture* writerCF = nullptr;
	::java::util::concurrent::CompletableFuture* stopCF = nullptr;
	::java::util::function::Consumer* recycler = nullptr;
	static ::java::util::concurrent::atomic::AtomicInteger* scount;
	int32_t id = 0;
	bool stopped = false;
	static const int32_t NOT_HANDSHAKING = 0;
	static const int32_t HANDSHAKING = 1;
	static const int32_t DOING_TASKS = 4;
	static const int32_t REQUESTING_TASKS = 8;
	static const int32_t TASK_BITS = 12;
	static const int32_t READER = 1;
	static const int32_t WRITER = 2;
	::java::util::concurrent::atomic::AtomicInteger* handshakeState = nullptr;
	::java::util::concurrent::ConcurrentLinkedQueue* stateList = nullptr;
	static ::java::util::function::IntBinaryOperator* REQUEST_OR_DO_TASKS;
	static ::java::util::function::IntBinaryOperator* FINISH_OR_DO_TASKS;
	$volatile(int32_t) packetBufferSize = 0;
	$volatile(int32_t) applicationBufferSize = 0;
	$volatile(int32_t) adaptiveAppBufferSize = 0;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("DOING_TASKS")
#pragma pop_macro("FINISH_OR_DO_TASKS")
#pragma pop_macro("HANDSHAKING")
#pragma pop_macro("HS_TRIGGER")
#pragma pop_macro("NOTHING")
#pragma pop_macro("NOT_HANDSHAKING")
#pragma pop_macro("READER")
#pragma pop_macro("REQUESTING_TASKS")
#pragma pop_macro("REQUEST_OR_DO_TASKS")
#pragma pop_macro("SENTINEL")
#pragma pop_macro("TASK_BITS")
#pragma pop_macro("WRITER")

#endif // _jdk_internal_net_http_common_SSLFlowDelegate_h_