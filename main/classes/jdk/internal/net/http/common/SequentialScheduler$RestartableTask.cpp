#include <jdk/internal/net/http/common/SequentialScheduler$RestartableTask.h>

#include <jdk/internal/net/http/common/SequentialScheduler$DeferredCompleter.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SequentialScheduler$DeferredCompleter = ::jdk::internal::net::http::common::SequentialScheduler$DeferredCompleter;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$CompoundAttribute _SequentialScheduler$RestartableTask_Annotations_[] = {
	{"Ljava/lang/FunctionalInterface;", nullptr},
	{}
};

$MethodInfo _SequentialScheduler$RestartableTask_MethodInfo_[] = {
	{"run", "(Ljdk/internal/net/http/common/SequentialScheduler$DeferredCompleter;)V", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _SequentialScheduler$RestartableTask_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SequentialScheduler$RestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "RestartableTask", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SequentialScheduler$RestartableTask_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.common.SequentialScheduler$RestartableTask",
	nullptr,
	nullptr,
	nullptr,
	_SequentialScheduler$RestartableTask_MethodInfo_,
	nullptr,
	nullptr,
	_SequentialScheduler$RestartableTask_InnerClassesInfo_,
	_SequentialScheduler$RestartableTask_Annotations_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SequentialScheduler"
};

$Object* allocate$SequentialScheduler$RestartableTask($Class* clazz) {
	return $of($alloc(SequentialScheduler$RestartableTask));
}

$Class* SequentialScheduler$RestartableTask::load$($String* name, bool initialize) {
	$loadClass(SequentialScheduler$RestartableTask, name, initialize, &_SequentialScheduler$RestartableTask_ClassInfo_, allocate$SequentialScheduler$RestartableTask);
	return class$;
}

$Class* SequentialScheduler$RestartableTask::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk