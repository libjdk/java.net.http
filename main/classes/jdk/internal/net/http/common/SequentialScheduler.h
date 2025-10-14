#ifndef _jdk_internal_net_http_common_SequentialScheduler_h_
#define _jdk_internal_net_http_common_SequentialScheduler_h_
//$ class jdk.internal.net.http.common.SequentialScheduler
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("AGAIN")
#undef AGAIN
#pragma push_macro("BEGIN")
#undef BEGIN
#pragma push_macro("END")
#undef END
#pragma push_macro("OFFLOAD")
#undef OFFLOAD
#pragma push_macro("STOP")
#undef STOP

namespace java {
	namespace lang {
		class Runnable;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class Executor;
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
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class SequentialScheduler$DeferredCompleter;
					class SequentialScheduler$RestartableTask;
					class SequentialScheduler$SchedulableTask;
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

class $export SequentialScheduler : public ::java::lang::Object {
	$class(SequentialScheduler, $NO_CLASS_INIT, ::java::lang::Object)
public:
	SequentialScheduler();
	void init$(::jdk::internal::net::http::common::SequentialScheduler$RestartableTask* restartableTask);
	bool isStopped();
	static ::jdk::internal::net::http::common::SequentialScheduler* lockingScheduler(::java::lang::Runnable* mainLoop);
	void runOrSchedule();
	void runOrSchedule(::java::util::concurrent::Executor* executor);
	void runOrSchedule(::jdk::internal::net::http::common::SequentialScheduler$SchedulableTask* task, ::java::util::concurrent::Executor* executor);
	void stop();
	static ::jdk::internal::net::http::common::SequentialScheduler* synchronizedScheduler(::java::lang::Runnable* mainLoop);
	static const int32_t OFFLOAD = 1;
	static const int32_t AGAIN = 2;
	static const int32_t BEGIN = 4;
	static const int32_t STOP = 8;
	static const int32_t END = 16;
	::java::util::concurrent::atomic::AtomicInteger* state = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler$RestartableTask* restartableTask = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler$DeferredCompleter* completer = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler$SchedulableTask* schedulableTask = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("AGAIN")
#pragma pop_macro("BEGIN")
#pragma pop_macro("END")
#pragma pop_macro("OFFLOAD")
#pragma pop_macro("STOP")

#endif // _jdk_internal_net_http_common_SequentialScheduler_h_