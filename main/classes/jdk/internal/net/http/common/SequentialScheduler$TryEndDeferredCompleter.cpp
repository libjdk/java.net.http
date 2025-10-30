#include <jdk/internal/net/http/common/SequentialScheduler$TryEndDeferredCompleter.h>

#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/util/concurrent/atomic/AtomicInteger.h>
#include <jdk/internal/net/http/common/SequentialScheduler$DeferredCompleter.h>
#include <jdk/internal/net/http/common/SequentialScheduler$RestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $AtomicInteger = ::java::util::concurrent::atomic::AtomicInteger;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $SequentialScheduler$DeferredCompleter = ::jdk::internal::net::http::common::SequentialScheduler$DeferredCompleter;
using $SequentialScheduler$RestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$RestartableTask;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SequentialScheduler$TryEndDeferredCompleter_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $FINAL | $SYNTHETIC, $field(SequentialScheduler$TryEndDeferredCompleter, this$0)},
	{}
};

$MethodInfo _SequentialScheduler$TryEndDeferredCompleter_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/SequentialScheduler;)V", nullptr, $PRIVATE, $method(static_cast<void(SequentialScheduler$TryEndDeferredCompleter::*)($SequentialScheduler*)>(&SequentialScheduler$TryEndDeferredCompleter::init$))},
	{"complete", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SequentialScheduler$TryEndDeferredCompleter_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SequentialScheduler$TryEndDeferredCompleter", "jdk.internal.net.http.common.SequentialScheduler", "TryEndDeferredCompleter", $PRIVATE},
	{"jdk.internal.net.http.common.SequentialScheduler$DeferredCompleter", "jdk.internal.net.http.common.SequentialScheduler", "DeferredCompleter", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SequentialScheduler$TryEndDeferredCompleter_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.common.SequentialScheduler$TryEndDeferredCompleter",
	"jdk.internal.net.http.common.SequentialScheduler$DeferredCompleter",
	nullptr,
	_SequentialScheduler$TryEndDeferredCompleter_FieldInfo_,
	_SequentialScheduler$TryEndDeferredCompleter_MethodInfo_,
	nullptr,
	nullptr,
	_SequentialScheduler$TryEndDeferredCompleter_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SequentialScheduler"
};

$Object* allocate$SequentialScheduler$TryEndDeferredCompleter($Class* clazz) {
	return $of($alloc(SequentialScheduler$TryEndDeferredCompleter));
}

void SequentialScheduler$TryEndDeferredCompleter::init$($SequentialScheduler* this$0) {
	$set(this, this$0, this$0);
	$SequentialScheduler$DeferredCompleter::init$();
}

void SequentialScheduler$TryEndDeferredCompleter::complete() {
	$useLocalCurrentObjectStackCache();
	while (true) {
		int32_t s = 0;
		while (((int32_t)((s = $nc(this->this$0->state)->get()) & (uint32_t)1)) != 0) {
			if ($nc(this->this$0->state)->compareAndSet(s, (int32_t)(s & (uint32_t)~1))) {
				return;
			}
		}
		while (true) {
			if (((int32_t)(s & (uint32_t)1)) != 0) {
				$throwNew($InternalError, $($String::valueOf(s)));
			}
			if (s == 4) {
				if ($nc(this->this$0->state)->compareAndSet(4, 16)) {
					return;
				}
			} else if (s == 2) {
				if ($nc(this->this$0->state)->compareAndSet(2, 4 | 1)) {
					break;
				}
			} else if (s == 8) {
				return;
			} else if (s == 16) {
				$throwNew($IllegalStateException, "Duplicate completion"_s);
			} else {
				$throwNew($InternalError, $($String::valueOf(s)));
			}
			s = $nc(this->this$0->state)->get();
		}
		$nc(this->this$0->restartableTask)->run(this->this$0->completer);
	}
}

SequentialScheduler$TryEndDeferredCompleter::SequentialScheduler$TryEndDeferredCompleter() {
}

$Class* SequentialScheduler$TryEndDeferredCompleter::load$($String* name, bool initialize) {
	$loadClass(SequentialScheduler$TryEndDeferredCompleter, name, initialize, &_SequentialScheduler$TryEndDeferredCompleter_ClassInfo_, allocate$SequentialScheduler$TryEndDeferredCompleter);
	return class$;
}

$Class* SequentialScheduler$TryEndDeferredCompleter::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk