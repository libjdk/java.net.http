#include <jdk/internal/net/http/common/SequentialScheduler$SynchronizedRestartableTask.h>

#include <java/lang/Runnable.h>
#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SequentialScheduler$CompleteRestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SequentialScheduler$SynchronizedRestartableTask_FieldInfo_[] = {
	{"mainLoop", "Ljava/lang/Runnable;", nullptr, $PRIVATE | $FINAL, $field(SequentialScheduler$SynchronizedRestartableTask, mainLoop)},
	{"lock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(SequentialScheduler$SynchronizedRestartableTask, lock)},
	{}
};

$MethodInfo _SequentialScheduler$SynchronizedRestartableTask_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Runnable;)V", nullptr, $PUBLIC, $method(static_cast<void(SequentialScheduler$SynchronizedRestartableTask::*)($Runnable*)>(&SequentialScheduler$SynchronizedRestartableTask::init$))},
	{"run", "()V", nullptr, $PROTECTED},
	{}
};

$InnerClassInfo _SequentialScheduler$SynchronizedRestartableTask_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SequentialScheduler$SynchronizedRestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "SynchronizedRestartableTask", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "CompleteRestartableTask", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SequentialScheduler$SynchronizedRestartableTask_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.SequentialScheduler$SynchronizedRestartableTask",
	"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask",
	nullptr,
	_SequentialScheduler$SynchronizedRestartableTask_FieldInfo_,
	_SequentialScheduler$SynchronizedRestartableTask_MethodInfo_,
	nullptr,
	nullptr,
	_SequentialScheduler$SynchronizedRestartableTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SequentialScheduler"
};

$Object* allocate$SequentialScheduler$SynchronizedRestartableTask($Class* clazz) {
	return $of($alloc(SequentialScheduler$SynchronizedRestartableTask));
}

void SequentialScheduler$SynchronizedRestartableTask::init$($Runnable* mainLoop) {
	$SequentialScheduler$CompleteRestartableTask::init$();
	$set(this, lock, $new($Object));
	$set(this, mainLoop, mainLoop);
}

void SequentialScheduler$SynchronizedRestartableTask::run() {
	$synchronized(this->lock) {
		$nc(this->mainLoop)->run();
	}
}

SequentialScheduler$SynchronizedRestartableTask::SequentialScheduler$SynchronizedRestartableTask() {
}

$Class* SequentialScheduler$SynchronizedRestartableTask::load$($String* name, bool initialize) {
	$loadClass(SequentialScheduler$SynchronizedRestartableTask, name, initialize, &_SequentialScheduler$SynchronizedRestartableTask_ClassInfo_, allocate$SequentialScheduler$SynchronizedRestartableTask);
	return class$;
}

$Class* SequentialScheduler$SynchronizedRestartableTask::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk