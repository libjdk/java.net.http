#include <jdk/internal/net/http/PrivilegedExecutor.h>

#include <java/lang/Runnable.h>
#include <java/security/AccessControlContext.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/Executor.h>
#include <jdk/internal/net/http/PrivilegedExecutor$PrivilegedRunnable.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $AccessControlContext = ::java::security::AccessControlContext;
using $Objects = ::java::util::Objects;
using $Executor = ::java::util::concurrent::Executor;
using $PrivilegedExecutor$PrivilegedRunnable = ::jdk::internal::net::http::PrivilegedExecutor$PrivilegedRunnable;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _PrivilegedExecutor_FieldInfo_[] = {
	{"executor", "Ljava/util/concurrent/Executor;", nullptr, $FINAL, $field(PrivilegedExecutor, executor)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $FINAL, $field(PrivilegedExecutor, acc)},
	{}
};

$MethodInfo _PrivilegedExecutor_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/Executor;Ljava/security/AccessControlContext;)V", nullptr, $PUBLIC, $method(static_cast<void(PrivilegedExecutor::*)($Executor*,$AccessControlContext*)>(&PrivilegedExecutor::init$))},
	{"execute", "(Ljava/lang/Runnable;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _PrivilegedExecutor_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.PrivilegedExecutor$PrivilegedRunnable", "jdk.internal.net.http.PrivilegedExecutor", "PrivilegedRunnable", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _PrivilegedExecutor_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.PrivilegedExecutor",
	"java.lang.Object",
	"java.util.concurrent.Executor",
	_PrivilegedExecutor_FieldInfo_,
	_PrivilegedExecutor_MethodInfo_,
	nullptr,
	nullptr,
	_PrivilegedExecutor_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.PrivilegedExecutor$PrivilegedRunnable"
};

$Object* allocate$PrivilegedExecutor($Class* clazz) {
	return $of($alloc(PrivilegedExecutor));
}

void PrivilegedExecutor::init$($Executor* executor, $AccessControlContext* acc) {
	$Objects::requireNonNull(executor);
	$Objects::requireNonNull(acc);
	$set(this, executor, executor);
	$set(this, acc, acc);
}

void PrivilegedExecutor::execute($Runnable* r) {
	$nc(this->executor)->execute($$new($PrivilegedExecutor$PrivilegedRunnable, r, this->acc));
}

PrivilegedExecutor::PrivilegedExecutor() {
}

$Class* PrivilegedExecutor::load$($String* name, bool initialize) {
	$loadClass(PrivilegedExecutor, name, initialize, &_PrivilegedExecutor_ClassInfo_, allocate$PrivilegedExecutor);
	return class$;
}

$Class* PrivilegedExecutor::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk