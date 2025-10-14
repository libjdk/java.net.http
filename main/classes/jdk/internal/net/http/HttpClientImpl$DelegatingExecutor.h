#ifndef _jdk_internal_net_http_HttpClientImpl$DelegatingExecutor_h_
#define _jdk_internal_net_http_HttpClientImpl$DelegatingExecutor_h_
//$ class jdk.internal.net.http.HttpClientImpl$DelegatingExecutor
//$ extends java.util.concurrent.Executor

#include <java/util/concurrent/Executor.h>

namespace java {
	namespace lang {
		class Runnable;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class ExecutorService;
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class BooleanSupplier;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export HttpClientImpl$DelegatingExecutor : public ::java::util::concurrent::Executor {
	$class(HttpClientImpl$DelegatingExecutor, $NO_CLASS_INIT, ::java::util::concurrent::Executor)
public:
	HttpClientImpl$DelegatingExecutor();
	void init$(::java::util::function::BooleanSupplier* isInSelectorThread, ::java::util::concurrent::Executor* delegate);
	::java::util::concurrent::Executor* delegate();
	virtual void execute(::java::lang::Runnable* command) override;
	static $Object* lambda$shutdown$0(::java::util::concurrent::ExecutorService* service);
	void shutdown();
	::java::util::function::BooleanSupplier* isInSelectorThread = nullptr;
	::java::util::concurrent::Executor* delegate$ = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HttpClientImpl$DelegatingExecutor_h_