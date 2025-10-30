#include <jdk/internal/net/http/common/SequentialScheduler$LockingRestartableTask.h>

#include <java/lang/AssertionError.h>
#include <java/lang/Runnable.h>
#include <java/util/concurrent/locks/Lock.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Lock = ::java::util::concurrent::locks::Lock;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SequentialScheduler$CompleteRestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SequentialScheduler$LockingRestartableTask_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SequentialScheduler$LockingRestartableTask, $assertionsDisabled)},
	{"mainLoop", "Ljava/lang/Runnable;", nullptr, $PRIVATE | $FINAL, $field(SequentialScheduler$LockingRestartableTask, mainLoop)},
	{"lock", "Ljava/util/concurrent/locks/Lock;", nullptr, $PRIVATE | $FINAL, $field(SequentialScheduler$LockingRestartableTask, lock)},
	{}
};

$MethodInfo _SequentialScheduler$LockingRestartableTask_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Runnable;)V", nullptr, $PUBLIC, $method(static_cast<void(SequentialScheduler$LockingRestartableTask::*)($Runnable*)>(&SequentialScheduler$LockingRestartableTask::init$))},
	{"run", "()V", nullptr, $PROTECTED},
	{}
};

$InnerClassInfo _SequentialScheduler$LockingRestartableTask_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SequentialScheduler$LockingRestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "LockingRestartableTask", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "CompleteRestartableTask", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SequentialScheduler$LockingRestartableTask_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.SequentialScheduler$LockingRestartableTask",
	"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask",
	nullptr,
	_SequentialScheduler$LockingRestartableTask_FieldInfo_,
	_SequentialScheduler$LockingRestartableTask_MethodInfo_,
	nullptr,
	nullptr,
	_SequentialScheduler$LockingRestartableTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SequentialScheduler"
};

$Object* allocate$SequentialScheduler$LockingRestartableTask($Class* clazz) {
	return $of($alloc(SequentialScheduler$LockingRestartableTask));
}

bool SequentialScheduler$LockingRestartableTask::$assertionsDisabled = false;

void SequentialScheduler$LockingRestartableTask::init$($Runnable* mainLoop) {
	$SequentialScheduler$CompleteRestartableTask::init$();
	$set(this, lock, $new($ReentrantLock));
	$set(this, mainLoop, mainLoop);
}

void SequentialScheduler$LockingRestartableTask::run() {
	bool locked = $nc(this->lock)->tryLock();
	if (!SequentialScheduler$LockingRestartableTask::$assertionsDisabled && !locked) {
		$throwNew($AssertionError, $of("contention detected in SequentialScheduler"_s));
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->mainLoop)->run();
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (locked) {
				$nc(this->lock)->unlock();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void clinit$SequentialScheduler$LockingRestartableTask($Class* class$) {
	$load($SequentialScheduler);
	SequentialScheduler$LockingRestartableTask::$assertionsDisabled = !$SequentialScheduler::class$->desiredAssertionStatus();
}

SequentialScheduler$LockingRestartableTask::SequentialScheduler$LockingRestartableTask() {
}

$Class* SequentialScheduler$LockingRestartableTask::load$($String* name, bool initialize) {
	$loadClass(SequentialScheduler$LockingRestartableTask, name, initialize, &_SequentialScheduler$LockingRestartableTask_ClassInfo_, clinit$SequentialScheduler$LockingRestartableTask, allocate$SequentialScheduler$LockingRestartableTask);
	return class$;
}

$Class* SequentialScheduler$LockingRestartableTask::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk