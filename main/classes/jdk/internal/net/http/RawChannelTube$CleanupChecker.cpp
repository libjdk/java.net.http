#include <jdk/internal/net/http/RawChannelTube$CleanupChecker.h>

#include <java/lang/System$Logger$Level.h>
#include <java/lang/System$Logger.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <jdk/internal/net/http/RawChannelTube.h>
#include <jcpp.h>

#undef DEBUG

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $System$Logger = ::java::lang::System$Logger;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $RawChannelTube = ::jdk::internal::net::http::RawChannelTube;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _RawChannelTube$CleanupChecker_FieldInfo_[] = {
	{"closed", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $FINAL, $field(RawChannelTube$CleanupChecker, closed)},
	{"debug", "Ljava/lang/System$Logger;", nullptr, $FINAL, $field(RawChannelTube$CleanupChecker, debug)},
	{}
};

$MethodInfo _RawChannelTube$CleanupChecker_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/atomic/AtomicBoolean;Ljava/lang/System$Logger;)V", nullptr, 0, $method(static_cast<void(RawChannelTube$CleanupChecker::*)($AtomicBoolean*,$System$Logger*)>(&RawChannelTube$CleanupChecker::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _RawChannelTube$CleanupChecker_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RawChannelTube$CleanupChecker", "jdk.internal.net.http.RawChannelTube", "CleanupChecker", $STATIC | $FINAL},
	{}
};

$ClassInfo _RawChannelTube$CleanupChecker_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.RawChannelTube$CleanupChecker",
	"java.lang.Object",
	"java.lang.Runnable",
	_RawChannelTube$CleanupChecker_FieldInfo_,
	_RawChannelTube$CleanupChecker_MethodInfo_,
	nullptr,
	nullptr,
	_RawChannelTube$CleanupChecker_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RawChannelTube"
};

$Object* allocate$RawChannelTube$CleanupChecker($Class* clazz) {
	return $of($alloc(RawChannelTube$CleanupChecker));
}

void RawChannelTube$CleanupChecker::init$($AtomicBoolean* closed, $System$Logger* debug) {
	$set(this, closed, closed);
	$set(this, debug, debug);
}

void RawChannelTube$CleanupChecker::run() {
	if (!$nc(this->closed)->get()) {
		$init($System$Logger$Level);
		$nc(this->debug)->log($System$Logger$Level::DEBUG, "RawChannelTube was not closed before being released"_s);
	}
}

RawChannelTube$CleanupChecker::RawChannelTube$CleanupChecker() {
}

$Class* RawChannelTube$CleanupChecker::load$($String* name, bool initialize) {
	$loadClass(RawChannelTube$CleanupChecker, name, initialize, &_RawChannelTube$CleanupChecker_ClassInfo_, allocate$RawChannelTube$CleanupChecker);
	return class$;
}

$Class* RawChannelTube$CleanupChecker::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk