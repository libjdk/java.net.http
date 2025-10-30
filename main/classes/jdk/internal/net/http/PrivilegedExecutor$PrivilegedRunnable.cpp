#include <jdk/internal/net/http/PrivilegedExecutor$PrivilegedRunnable.h>

#include <java/io/Serializable.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <jdk/internal/net/http/PrivilegedExecutor.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedExecutor = ::jdk::internal::net::http::PrivilegedExecutor;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0 : public $PrivilegedAction {
	$class(PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(PrivilegedExecutor$PrivilegedRunnable* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$run$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0>());
	}
	PrivilegedExecutor$PrivilegedRunnable* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0, inst$)},
	{}
};
$MethodInfo PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/PrivilegedExecutor$PrivilegedRunnable;)V", nullptr, $PUBLIC, $method(static_cast<void(PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0::*)(PrivilegedExecutor$PrivilegedRunnable*)>(&PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0::load$($String* name, bool initialize) {
	$loadClass(PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0::class$ = nullptr;

$FieldInfo _PrivilegedExecutor$PrivilegedRunnable_FieldInfo_[] = {
	{"r", "Ljava/lang/Runnable;", nullptr, $PRIVATE | $FINAL, $field(PrivilegedExecutor$PrivilegedRunnable, r)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $FINAL, $field(PrivilegedExecutor$PrivilegedRunnable, acc)},
	{}
};

$MethodInfo _PrivilegedExecutor$PrivilegedRunnable_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Runnable;Ljava/security/AccessControlContext;)V", nullptr, 0, $method(static_cast<void(PrivilegedExecutor$PrivilegedRunnable::*)($Runnable*,$AccessControlContext*)>(&PrivilegedExecutor$PrivilegedRunnable::init$))},
	{"lambda$run$0", "()Ljava/lang/Void;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$Void*(PrivilegedExecutor$PrivilegedRunnable::*)()>(&PrivilegedExecutor$PrivilegedRunnable::lambda$run$0))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _PrivilegedExecutor$PrivilegedRunnable_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.PrivilegedExecutor$PrivilegedRunnable", "jdk.internal.net.http.PrivilegedExecutor", "PrivilegedRunnable", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _PrivilegedExecutor$PrivilegedRunnable_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.PrivilegedExecutor$PrivilegedRunnable",
	"java.lang.Object",
	"java.lang.Runnable",
	_PrivilegedExecutor$PrivilegedRunnable_FieldInfo_,
	_PrivilegedExecutor$PrivilegedRunnable_MethodInfo_,
	nullptr,
	nullptr,
	_PrivilegedExecutor$PrivilegedRunnable_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.PrivilegedExecutor"
};

$Object* allocate$PrivilegedExecutor$PrivilegedRunnable($Class* clazz) {
	return $of($alloc(PrivilegedExecutor$PrivilegedRunnable));
}

void PrivilegedExecutor$PrivilegedRunnable::init$($Runnable* r, $AccessControlContext* acc) {
	$set(this, r, r);
	$set(this, acc, acc);
}

void PrivilegedExecutor$PrivilegedRunnable::run() {
	$beforeCallerSensitive();
	$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0, this)));
	$AccessController::doPrivileged(pa, this->acc);
}

$Void* PrivilegedExecutor$PrivilegedRunnable::lambda$run$0() {
	$nc(this->r)->run();
	return nullptr;
}

PrivilegedExecutor$PrivilegedRunnable::PrivilegedExecutor$PrivilegedRunnable() {
}

$Class* PrivilegedExecutor$PrivilegedRunnable::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0::classInfo$.name)) {
			return PrivilegedExecutor$PrivilegedRunnable$$Lambda$lambda$run$0::load$(name, initialize);
		}
	}
	$loadClass(PrivilegedExecutor$PrivilegedRunnable, name, initialize, &_PrivilegedExecutor$PrivilegedRunnable_ClassInfo_, allocate$PrivilegedExecutor$PrivilegedRunnable);
	return class$;
}

$Class* PrivilegedExecutor$PrivilegedRunnable::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk