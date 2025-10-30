#include <jdk/internal/net/http/HttpClientImpl$DelegatingExecutor.h>

#include <java/io/Serializable.h>
#include <java/lang/Runnable.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/BasicPermission.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/function/BooleanSupplier.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jcpp.h>

using $PermissionArray = $Array<::java::security::Permission>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $BasicPermission = ::java::security::BasicPermission;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Executor = ::java::util::concurrent::Executor;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $BooleanSupplier = ::java::util::function::BooleanSupplier;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0 : public $PrivilegedAction {
	$class(HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($ExecutorService* service) {
		$set(this, service, service);
	}
	virtual $Object* run() override {
		 return HttpClientImpl$DelegatingExecutor::lambda$shutdown$0(service);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0>());
	}
	$ExecutorService* service = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0::fieldInfos[2] = {
	{"service", "Ljava/util/concurrent/ExecutorService;", nullptr, $PUBLIC, $field(HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0, service)},
	{}
};
$MethodInfo HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/concurrent/ExecutorService;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0::*)($ExecutorService*)>(&HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0::class$ = nullptr;

$FieldInfo _HttpClientImpl$DelegatingExecutor_FieldInfo_[] = {
	{"isInSelectorThread", "Ljava/util/function/BooleanSupplier;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl$DelegatingExecutor, isInSelectorThread)},
	{"delegate", "Ljava/util/concurrent/Executor;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl$DelegatingExecutor, delegate$)},
	{}
};

$MethodInfo _HttpClientImpl$DelegatingExecutor_MethodInfo_[] = {
	{"<init>", "(Ljava/util/function/BooleanSupplier;Ljava/util/concurrent/Executor;)V", nullptr, 0, $method(static_cast<void(HttpClientImpl$DelegatingExecutor::*)($BooleanSupplier*,$Executor*)>(&HttpClientImpl$DelegatingExecutor::init$))},
	{"delegate", "()Ljava/util/concurrent/Executor;", nullptr, 0, $method(static_cast<$Executor*(HttpClientImpl$DelegatingExecutor::*)()>(&HttpClientImpl$DelegatingExecutor::delegate))},
	{"execute", "(Ljava/lang/Runnable;)V", nullptr, $PUBLIC},
	{"lambda$shutdown$0", "(Ljava/util/concurrent/ExecutorService;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Object*(*)($ExecutorService*)>(&HttpClientImpl$DelegatingExecutor::lambda$shutdown$0))},
	{"shutdown", "()V", nullptr, $PRIVATE, $method(static_cast<void(HttpClientImpl$DelegatingExecutor::*)()>(&HttpClientImpl$DelegatingExecutor::shutdown))},
	{}
};

$InnerClassInfo _HttpClientImpl$DelegatingExecutor_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.HttpClientImpl$DelegatingExecutor", "jdk.internal.net.http.HttpClientImpl", "DelegatingExecutor", $STATIC | $FINAL},
	{}
};

$ClassInfo _HttpClientImpl$DelegatingExecutor_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.HttpClientImpl$DelegatingExecutor",
	"java.lang.Object",
	"java.util.concurrent.Executor",
	_HttpClientImpl$DelegatingExecutor_FieldInfo_,
	_HttpClientImpl$DelegatingExecutor_MethodInfo_,
	nullptr,
	nullptr,
	_HttpClientImpl$DelegatingExecutor_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HttpClientImpl"
};

$Object* allocate$HttpClientImpl$DelegatingExecutor($Class* clazz) {
	return $of($alloc(HttpClientImpl$DelegatingExecutor));
}

void HttpClientImpl$DelegatingExecutor::init$($BooleanSupplier* isInSelectorThread, $Executor* delegate) {
	$set(this, isInSelectorThread, isInSelectorThread);
	$set(this, delegate$, delegate);
}

$Executor* HttpClientImpl$DelegatingExecutor::delegate() {
	return this->delegate$;
}

void HttpClientImpl$DelegatingExecutor::execute($Runnable* command) {
	if ($nc(this->isInSelectorThread)->getAsBoolean()) {
		$nc(this->delegate$)->execute(command);
	} else {
		$nc(command)->run();
	}
}

void HttpClientImpl$DelegatingExecutor::shutdown() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		$var($ExecutorService, service, nullptr);
		$var($Executor, patt6494$temp, this->delegate$);
		bool var$0 = $instanceOf($ExecutorService, patt6494$temp);
		if (var$0) {
			$assign(service, $cast($ExecutorService, patt6494$temp));
			var$0 = true;
		}
		if (var$0) {
			$var($PrivilegedAction, action, static_cast<$PrivilegedAction*>($new(HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0, service)));
			$AccessController::doPrivileged(action, ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>($$new($RuntimePermission, "modifyThread"_s))}));
		}
	}
}

$Object* HttpClientImpl$DelegatingExecutor::lambda$shutdown$0($ExecutorService* service) {
	$init(HttpClientImpl$DelegatingExecutor);
	$nc(service)->shutdown();
	return $of(nullptr);
}

HttpClientImpl$DelegatingExecutor::HttpClientImpl$DelegatingExecutor() {
}

$Class* HttpClientImpl$DelegatingExecutor::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0::classInfo$.name)) {
			return HttpClientImpl$DelegatingExecutor$$Lambda$lambda$shutdown$0::load$(name, initialize);
		}
	}
	$loadClass(HttpClientImpl$DelegatingExecutor, name, initialize, &_HttpClientImpl$DelegatingExecutor_ClassInfo_, allocate$HttpClientImpl$DelegatingExecutor);
	return class$;
}

$Class* HttpClientImpl$DelegatingExecutor::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk