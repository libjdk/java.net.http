#include <jdk/internal/net/http/SocketTube$SocketFlowTask.h>

#include <java/lang/AssertionError.h>
#include <java/lang/Runnable.h>
#include <java/util/concurrent/locks/Lock.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <jdk/internal/net/http/SocketTube.h>
#include <jdk/internal/net/http/common/SequentialScheduler$DeferredCompleter.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Lock = ::java::util::concurrent::locks::Lock;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $SocketTube = ::jdk::internal::net::http::SocketTube;
using $SequentialScheduler$DeferredCompleter = ::jdk::internal::net::http::common::SequentialScheduler$DeferredCompleter;
using $SequentialScheduler$RestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$RestartableTask;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _SocketTube$SocketFlowTask_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SocketTube$SocketFlowTask, $assertionsDisabled)},
	{"task", "Ljava/lang/Runnable;", nullptr, $FINAL, $field(SocketTube$SocketFlowTask, task)},
	{"lock", "Ljava/util/concurrent/locks/Lock;", nullptr, $PRIVATE | $FINAL, $field(SocketTube$SocketFlowTask, lock)},
	{}
};

$MethodInfo _SocketTube$SocketFlowTask_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Runnable;)V", nullptr, 0, $method(static_cast<void(SocketTube$SocketFlowTask::*)($Runnable*)>(&SocketTube$SocketFlowTask::init$))},
	{"run", "(Ljdk/internal/net/http/common/SequentialScheduler$DeferredCompleter;)V", nullptr, $PUBLIC | $FINAL},
	{}
};

$InnerClassInfo _SocketTube$SocketFlowTask_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.SocketTube$SocketFlowTask", "jdk.internal.net.http.SocketTube", "SocketFlowTask", $PRIVATE | $STATIC},
	{"jdk.internal.net.http.common.SequentialScheduler$RestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "RestartableTask", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SocketTube$SocketFlowTask_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.SocketTube$SocketFlowTask",
	"java.lang.Object",
	"jdk.internal.net.http.common.SequentialScheduler$RestartableTask",
	_SocketTube$SocketFlowTask_FieldInfo_,
	_SocketTube$SocketFlowTask_MethodInfo_,
	nullptr,
	nullptr,
	_SocketTube$SocketFlowTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.SocketTube"
};

$Object* allocate$SocketTube$SocketFlowTask($Class* clazz) {
	return $of($alloc(SocketTube$SocketFlowTask));
}

bool SocketTube$SocketFlowTask::$assertionsDisabled = false;

void SocketTube$SocketFlowTask::init$($Runnable* task) {
	$set(this, lock, $new($ReentrantLock));
	$set(this, task, task);
}

void SocketTube$SocketFlowTask::run($SequentialScheduler$DeferredCompleter* taskCompleter) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		try {
			bool locked = $nc(this->lock)->tryLock();
			if (!SocketTube$SocketFlowTask::$assertionsDisabled && !locked) {
				$throwNew($AssertionError, $of("contention detected in SequentialScheduler"_s));
			}
			{
				$var($Throwable, var$1, nullptr);
				try {
					$nc(this->task)->run();
				} catch ($Throwable& var$2) {
					$assign(var$1, var$2);
				} /*finally*/ {
					if (locked) {
						$nc(this->lock)->unlock();
					}
				}
				if (var$1 != nullptr) {
					$throw(var$1);
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			$nc(taskCompleter)->complete();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void clinit$SocketTube$SocketFlowTask($Class* class$) {
	$load($SocketTube);
	SocketTube$SocketFlowTask::$assertionsDisabled = !$SocketTube::class$->desiredAssertionStatus();
}

SocketTube$SocketFlowTask::SocketTube$SocketFlowTask() {
}

$Class* SocketTube$SocketFlowTask::load$($String* name, bool initialize) {
	$loadClass(SocketTube$SocketFlowTask, name, initialize, &_SocketTube$SocketFlowTask_ClassInfo_, clinit$SocketTube$SocketFlowTask, allocate$SocketTube$SocketFlowTask);
	return class$;
}

$Class* SocketTube$SocketFlowTask::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk