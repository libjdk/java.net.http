#include <jdk/internal/net/http/common/SequentialScheduler$DeferredCompleter.h>

#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$MethodInfo _SequentialScheduler$DeferredCompleter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(SequentialScheduler$DeferredCompleter::*)()>(&SequentialScheduler$DeferredCompleter::init$))},
	{"complete", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _SequentialScheduler$DeferredCompleter_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SequentialScheduler$DeferredCompleter", "jdk.internal.net.http.common.SequentialScheduler", "DeferredCompleter", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SequentialScheduler$DeferredCompleter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.common.SequentialScheduler$DeferredCompleter",
	"java.lang.Object",
	nullptr,
	nullptr,
	_SequentialScheduler$DeferredCompleter_MethodInfo_,
	nullptr,
	nullptr,
	_SequentialScheduler$DeferredCompleter_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SequentialScheduler"
};

$Object* allocate$SequentialScheduler$DeferredCompleter($Class* clazz) {
	return $of($alloc(SequentialScheduler$DeferredCompleter));
}

void SequentialScheduler$DeferredCompleter::init$() {
}

SequentialScheduler$DeferredCompleter::SequentialScheduler$DeferredCompleter() {
}

$Class* SequentialScheduler$DeferredCompleter::load$($String* name, bool initialize) {
	$loadClass(SequentialScheduler$DeferredCompleter, name, initialize, &_SequentialScheduler$DeferredCompleter_ClassInfo_, allocate$SequentialScheduler$DeferredCompleter);
	return class$;
}

$Class* SequentialScheduler$DeferredCompleter::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk