#include <jdk/internal/net/http/common/SequentialScheduler$SchedulableTask.h>

#include <jdk/internal/net/http/common/SequentialScheduler$DeferredCompleter.h>
#include <jdk/internal/net/http/common/SequentialScheduler$RestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SequentialScheduler$DeferredCompleter = ::jdk::internal::net::http::common::SequentialScheduler$DeferredCompleter;
using $SequentialScheduler$RestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$RestartableTask;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SequentialScheduler$SchedulableTask_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $FINAL | $SYNTHETIC, $field(SequentialScheduler$SchedulableTask, this$0)},
	{}
};

$MethodInfo _SequentialScheduler$SchedulableTask_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/SequentialScheduler;)V", nullptr, $PRIVATE, $method(static_cast<void(SequentialScheduler$SchedulableTask::*)($SequentialScheduler*)>(&SequentialScheduler$SchedulableTask::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SequentialScheduler$SchedulableTask_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SequentialScheduler$SchedulableTask", "jdk.internal.net.http.common.SequentialScheduler", "SchedulableTask", $PRIVATE | $FINAL},
	{}
};

$ClassInfo _SequentialScheduler$SchedulableTask_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.SequentialScheduler$SchedulableTask",
	"java.lang.Object",
	"java.lang.Runnable",
	_SequentialScheduler$SchedulableTask_FieldInfo_,
	_SequentialScheduler$SchedulableTask_MethodInfo_,
	nullptr,
	nullptr,
	_SequentialScheduler$SchedulableTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SequentialScheduler"
};

$Object* allocate$SequentialScheduler$SchedulableTask($Class* clazz) {
	return $of($alloc(SequentialScheduler$SchedulableTask));
}

void SequentialScheduler$SchedulableTask::init$($SequentialScheduler* this$0) {
	$set(this, this$0, this$0);
}

void SequentialScheduler$SchedulableTask::run() {
	$nc(this->this$0->restartableTask)->run(this->this$0->completer);
}

SequentialScheduler$SchedulableTask::SequentialScheduler$SchedulableTask() {
}

$Class* SequentialScheduler$SchedulableTask::load$($String* name, bool initialize) {
	$loadClass(SequentialScheduler$SchedulableTask, name, initialize, &_SequentialScheduler$SchedulableTask_ClassInfo_, allocate$SequentialScheduler$SchedulableTask);
	return class$;
}

$Class* SequentialScheduler$SchedulableTask::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk