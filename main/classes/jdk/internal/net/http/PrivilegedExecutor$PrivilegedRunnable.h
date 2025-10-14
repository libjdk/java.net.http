#ifndef _jdk_internal_net_http_PrivilegedExecutor$PrivilegedRunnable_h_
#define _jdk_internal_net_http_PrivilegedExecutor$PrivilegedRunnable_h_
//$ class jdk.internal.net.http.PrivilegedExecutor$PrivilegedRunnable
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

namespace java {
	namespace lang {
		class Void;
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

class $export PrivilegedExecutor$PrivilegedRunnable : public ::java::lang::Runnable {
	$class(PrivilegedExecutor$PrivilegedRunnable, $NO_CLASS_INIT, ::java::lang::Runnable)
public:
	PrivilegedExecutor$PrivilegedRunnable();
	void init$(::java::lang::Runnable* r, ::java::security::AccessControlContext* acc);
	::java::lang::Void* lambda$run$0();
	virtual void run() override;
	::java::lang::Runnable* r = nullptr;
	::java::security::AccessControlContext* acc = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_PrivilegedExecutor$PrivilegedRunnable_h_