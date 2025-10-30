#include <jdk/internal/net/http/common/SequentialScheduler.h>

#include <java/lang/InternalError.h>
#include <java/lang/Runnable.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/atomic/AtomicInteger.h>
#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler$DeferredCompleter.h>
#include <jdk/internal/net/http/common/SequentialScheduler$LockingRestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler$RestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler$SchedulableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler$SynchronizedRestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler$TryEndDeferredCompleter.h>
#include <jcpp.h>

#undef AGAIN
#undef BEGIN
#undef END
#undef OFFLOAD
#undef STOP

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Objects = ::java::util::Objects;
using $Executor = ::java::util::concurrent::Executor;
using $AtomicInteger = ::java::util::concurrent::atomic::AtomicInteger;
using $SequentialScheduler$CompleteRestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask;
using $SequentialScheduler$DeferredCompleter = ::jdk::internal::net::http::common::SequentialScheduler$DeferredCompleter;
using $SequentialScheduler$LockingRestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$LockingRestartableTask;
using $SequentialScheduler$RestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$RestartableTask;
using $SequentialScheduler$SchedulableTask = ::jdk::internal::net::http::common::SequentialScheduler$SchedulableTask;
using $SequentialScheduler$SynchronizedRestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$SynchronizedRestartableTask;
using $SequentialScheduler$TryEndDeferredCompleter = ::jdk::internal::net::http::common::SequentialScheduler$TryEndDeferredCompleter;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SequentialScheduler_FieldInfo_[] = {
	{"OFFLOAD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SequentialScheduler, OFFLOAD)},
	{"AGAIN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SequentialScheduler, AGAIN)},
	{"BEGIN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SequentialScheduler, BEGIN)},
	{"STOP", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SequentialScheduler, STOP)},
	{"END", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SequentialScheduler, END)},
	{"state", "Ljava/util/concurrent/atomic/AtomicInteger;", nullptr, $PRIVATE | $FINAL, $field(SequentialScheduler, state)},
	{"restartableTask", "Ljdk/internal/net/http/common/SequentialScheduler$RestartableTask;", nullptr, $PRIVATE | $FINAL, $field(SequentialScheduler, restartableTask)},
	{"completer", "Ljdk/internal/net/http/common/SequentialScheduler$DeferredCompleter;", nullptr, $PRIVATE | $FINAL, $field(SequentialScheduler, completer)},
	{"schedulableTask", "Ljdk/internal/net/http/common/SequentialScheduler$SchedulableTask;", nullptr, $PRIVATE | $FINAL, $field(SequentialScheduler, schedulableTask)},
	{}
};

$MethodInfo _SequentialScheduler_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/SequentialScheduler$RestartableTask;)V", nullptr, $PUBLIC, $method(static_cast<void(SequentialScheduler::*)($SequentialScheduler$RestartableTask*)>(&SequentialScheduler::init$))},
	{"isStopped", "()Z", nullptr, $PUBLIC, $method(static_cast<bool(SequentialScheduler::*)()>(&SequentialScheduler::isStopped))},
	{"lockingScheduler", "(Ljava/lang/Runnable;)Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $PUBLIC | $STATIC, $method(static_cast<SequentialScheduler*(*)($Runnable*)>(&SequentialScheduler::lockingScheduler))},
	{"runOrSchedule", "()V", nullptr, $PUBLIC, $method(static_cast<void(SequentialScheduler::*)()>(&SequentialScheduler::runOrSchedule))},
	{"runOrSchedule", "(Ljava/util/concurrent/Executor;)V", nullptr, $PUBLIC, $method(static_cast<void(SequentialScheduler::*)($Executor*)>(&SequentialScheduler::runOrSchedule))},
	{"runOrSchedule", "(Ljdk/internal/net/http/common/SequentialScheduler$SchedulableTask;Ljava/util/concurrent/Executor;)V", nullptr, $PRIVATE, $method(static_cast<void(SequentialScheduler::*)($SequentialScheduler$SchedulableTask*,$Executor*)>(&SequentialScheduler::runOrSchedule))},
	{"stop", "()V", nullptr, $PUBLIC, $method(static_cast<void(SequentialScheduler::*)()>(&SequentialScheduler::stop))},
	{"synchronizedScheduler", "(Ljava/lang/Runnable;)Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $PUBLIC | $STATIC, $method(static_cast<SequentialScheduler*(*)($Runnable*)>(&SequentialScheduler::synchronizedScheduler))},
	{}
};

$InnerClassInfo _SequentialScheduler_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SequentialScheduler$TryEndDeferredCompleter", "jdk.internal.net.http.common.SequentialScheduler", "TryEndDeferredCompleter", $PRIVATE},
	{"jdk.internal.net.http.common.SequentialScheduler$SchedulableTask", "jdk.internal.net.http.common.SequentialScheduler", "SchedulableTask", $PRIVATE | $FINAL},
	{"jdk.internal.net.http.common.SequentialScheduler$LockingRestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "LockingRestartableTask", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.net.http.common.SequentialScheduler$SynchronizedRestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "SynchronizedRestartableTask", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "CompleteRestartableTask", $PUBLIC | $STATIC | $ABSTRACT},
	{"jdk.internal.net.http.common.SequentialScheduler$RestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "RestartableTask", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.common.SequentialScheduler$DeferredCompleter", "jdk.internal.net.http.common.SequentialScheduler", "DeferredCompleter", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SequentialScheduler_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.SequentialScheduler",
	"java.lang.Object",
	nullptr,
	_SequentialScheduler_FieldInfo_,
	_SequentialScheduler_MethodInfo_,
	nullptr,
	nullptr,
	_SequentialScheduler_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SequentialScheduler$TryEndDeferredCompleter,jdk.internal.net.http.common.SequentialScheduler$SchedulableTask,jdk.internal.net.http.common.SequentialScheduler$LockingRestartableTask,jdk.internal.net.http.common.SequentialScheduler$SynchronizedRestartableTask,jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask,jdk.internal.net.http.common.SequentialScheduler$RestartableTask,jdk.internal.net.http.common.SequentialScheduler$DeferredCompleter"
};

$Object* allocate$SequentialScheduler($Class* clazz) {
	return $of($alloc(SequentialScheduler));
}

void SequentialScheduler::init$($SequentialScheduler$RestartableTask* restartableTask) {
	$set(this, state, $new($AtomicInteger, SequentialScheduler::END));
	$set(this, restartableTask, $cast($SequentialScheduler$RestartableTask, $Objects::requireNonNull(restartableTask)));
	$set(this, completer, $new($SequentialScheduler$TryEndDeferredCompleter, this));
	$set(this, schedulableTask, $new($SequentialScheduler$SchedulableTask, this));
}

void SequentialScheduler::runOrSchedule() {
	runOrSchedule(this->schedulableTask, nullptr);
}

void SequentialScheduler::runOrSchedule($Executor* executor) {
	runOrSchedule(this->schedulableTask, executor);
}

void SequentialScheduler::runOrSchedule($SequentialScheduler$SchedulableTask* task, $Executor* executor) {
	$useLocalCurrentObjectStackCache();
	while (true) {
		int32_t s = $nc(this->state)->get();
		if (s == SequentialScheduler::END) {
			if ($nc(this->state)->compareAndSet(SequentialScheduler::END, SequentialScheduler::BEGIN)) {
				break;
			}
		} else if (((int32_t)(s & (uint32_t)SequentialScheduler::BEGIN)) != 0) {
			if ($nc(this->state)->compareAndSet(s, SequentialScheduler::AGAIN | ((int32_t)(s & (uint32_t)SequentialScheduler::OFFLOAD)))) {
				return;
			}
		} else if (((int32_t)(s & (uint32_t)SequentialScheduler::AGAIN)) != 0 || s == SequentialScheduler::STOP) {
			return;
		} else {
			$throwNew($InternalError, $($String::valueOf(s)));
		}
	}
	if (executor == nullptr) {
		$nc(task)->run();
	} else {
		$nc(executor)->execute(task);
	}
}

bool SequentialScheduler::isStopped() {
	return $nc(this->state)->get() == SequentialScheduler::STOP;
}

void SequentialScheduler::stop() {
	$nc(this->state)->set(SequentialScheduler::STOP);
}

SequentialScheduler* SequentialScheduler::synchronizedScheduler($Runnable* mainLoop) {
	return $new(SequentialScheduler, $$new($SequentialScheduler$SynchronizedRestartableTask, mainLoop));
}

SequentialScheduler* SequentialScheduler::lockingScheduler($Runnable* mainLoop) {
	return $new(SequentialScheduler, $$new($SequentialScheduler$LockingRestartableTask, mainLoop));
}

SequentialScheduler::SequentialScheduler() {
}

$Class* SequentialScheduler::load$($String* name, bool initialize) {
	$loadClass(SequentialScheduler, name, initialize, &_SequentialScheduler_ClassInfo_, allocate$SequentialScheduler);
	return class$;
}

$Class* SequentialScheduler::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk