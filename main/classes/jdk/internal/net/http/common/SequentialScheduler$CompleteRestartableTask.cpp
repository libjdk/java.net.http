#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>

#include <jdk/internal/net/http/common/SequentialScheduler$DeferredCompleter.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SequentialScheduler$DeferredCompleter = ::jdk::internal::net::http::common::SequentialScheduler$DeferredCompleter;
using $SequentialScheduler$RestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$RestartableTask;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$MethodInfo _SequentialScheduler$CompleteRestartableTask_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SequentialScheduler$CompleteRestartableTask::*)()>(&SequentialScheduler$CompleteRestartableTask::init$))},
	{"run", "(Ljdk/internal/net/http/common/SequentialScheduler$DeferredCompleter;)V", nullptr, $PUBLIC | $FINAL},
	{"run", "()V", nullptr, $PROTECTED | $ABSTRACT},
	{}
};

$InnerClassInfo _SequentialScheduler$CompleteRestartableTask_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "CompleteRestartableTask", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.net.http.common.SequentialScheduler$RestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "RestartableTask", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SequentialScheduler$CompleteRestartableTask_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask",
	"java.lang.Object",
	"jdk.internal.net.http.common.SequentialScheduler$RestartableTask",
	nullptr,
	_SequentialScheduler$CompleteRestartableTask_MethodInfo_,
	nullptr,
	nullptr,
	_SequentialScheduler$CompleteRestartableTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SequentialScheduler"
};

$Object* allocate$SequentialScheduler$CompleteRestartableTask($Class* clazz) {
	return $of($alloc(SequentialScheduler$CompleteRestartableTask));
}

void SequentialScheduler$CompleteRestartableTask::init$() {
}

void SequentialScheduler$CompleteRestartableTask::run($SequentialScheduler$DeferredCompleter* taskCompleter) {
	{
		$var($Throwable, var$0, nullptr);
		try {
			run();
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(taskCompleter)->complete();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

SequentialScheduler$CompleteRestartableTask::SequentialScheduler$CompleteRestartableTask() {
}

$Class* SequentialScheduler$CompleteRestartableTask::load$($String* name, bool initialize) {
	$loadClass(SequentialScheduler$CompleteRestartableTask, name, initialize, &_SequentialScheduler$CompleteRestartableTask_ClassInfo_, allocate$SequentialScheduler$CompleteRestartableTask);
	return class$;
}

$Class* SequentialScheduler$CompleteRestartableTask::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk