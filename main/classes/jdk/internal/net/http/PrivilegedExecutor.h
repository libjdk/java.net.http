#ifndef _jdk_internal_net_http_PrivilegedExecutor_h_
#define _jdk_internal_net_http_PrivilegedExecutor_h_
//$ class jdk.internal.net.http.PrivilegedExecutor
//$ extends java.util.concurrent.Executor

#include <java/util/concurrent/Executor.h>

namespace java {
	namespace lang {
		class Runnable;
	}
}
namespace java {
	namespace security {
		class AccessControlContext;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export PrivilegedExecutor : public ::java::util::concurrent::Executor {
	$class(PrivilegedExecutor, $NO_CLASS_INIT, ::java::util::concurrent::Executor)
public:
	PrivilegedExecutor();
	void init$(::java::util::concurrent::Executor* executor, ::java::security::AccessControlContext* acc);
	virtual void execute(::java::lang::Runnable* r) override;
	::java::util::concurrent::Executor* executor = nullptr;
	::java::security::AccessControlContext* acc = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_PrivilegedExecutor_h_