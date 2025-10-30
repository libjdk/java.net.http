#include <jdk/internal/net/http/MultiExchange$ConnectTimeoutTracker.h>

#include <java/lang/AssertionError.h>
#include <java/time/Duration.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jcpp.h>

#undef ZERO

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Duration = ::java::time::Duration;
using $Objects = ::java::util::Objects;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _MultiExchange$ConnectTimeoutTracker_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(MultiExchange$ConnectTimeoutTracker, $assertionsDisabled)},
	{"max", "Ljava/time/Duration;", nullptr, $FINAL, $field(MultiExchange$ConnectTimeoutTracker, max)},
	{"startTime", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $FINAL, $field(MultiExchange$ConnectTimeoutTracker, startTime)},
	{}
};

$MethodInfo _MultiExchange$ConnectTimeoutTracker_MethodInfo_[] = {
	{"<init>", "(Ljava/time/Duration;)V", nullptr, 0, $method(static_cast<void(MultiExchange$ConnectTimeoutTracker::*)($Duration*)>(&MultiExchange$ConnectTimeoutTracker::init$))},
	{"getRemaining", "()Ljava/time/Duration;", nullptr, 0, $method(static_cast<$Duration*(MultiExchange$ConnectTimeoutTracker::*)()>(&MultiExchange$ConnectTimeoutTracker::getRemaining))},
	{"reset", "()V", nullptr, 0, $method(static_cast<void(MultiExchange$ConnectTimeoutTracker::*)()>(&MultiExchange$ConnectTimeoutTracker::reset))},
	{}
};

$InnerClassInfo _MultiExchange$ConnectTimeoutTracker_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.MultiExchange$ConnectTimeoutTracker", "jdk.internal.net.http.MultiExchange", "ConnectTimeoutTracker", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _MultiExchange$ConnectTimeoutTracker_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.MultiExchange$ConnectTimeoutTracker",
	"java.lang.Object",
	nullptr,
	_MultiExchange$ConnectTimeoutTracker_FieldInfo_,
	_MultiExchange$ConnectTimeoutTracker_MethodInfo_,
	nullptr,
	nullptr,
	_MultiExchange$ConnectTimeoutTracker_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.MultiExchange"
};

$Object* allocate$MultiExchange$ConnectTimeoutTracker($Class* clazz) {
	return $of($alloc(MultiExchange$ConnectTimeoutTracker));
}

bool MultiExchange$ConnectTimeoutTracker::$assertionsDisabled = false;

void MultiExchange$ConnectTimeoutTracker::init$($Duration* connectTimeout) {
	$set(this, startTime, $new($AtomicLong));
	$set(this, max, $cast($Duration, $Objects::requireNonNull(connectTimeout)));
}

$Duration* MultiExchange$ConnectTimeoutTracker::getRemaining() {
	$useLocalCurrentObjectStackCache();
	int64_t now = $System::nanoTime();
	int64_t previous = $nc(this->startTime)->compareAndExchange(0, now);
	if (previous == 0 || $nc(this->max)->isZero()) {
		return this->max;
	}
	$var($Duration, remaining, $nc(this->max)->minus($($Duration::ofNanos(now - previous))));
	if (!MultiExchange$ConnectTimeoutTracker::$assertionsDisabled && !($nc(remaining)->compareTo(this->max) <= 0)) {
		$throwNew($AssertionError);
	}
	return $nc(remaining)->isNegative() ? $Duration::ZERO : remaining;
}

void MultiExchange$ConnectTimeoutTracker::reset() {
	$nc(this->startTime)->set(0);
}

void clinit$MultiExchange$ConnectTimeoutTracker($Class* class$) {
	$load($MultiExchange);
	MultiExchange$ConnectTimeoutTracker::$assertionsDisabled = !$MultiExchange::class$->desiredAssertionStatus();
}

MultiExchange$ConnectTimeoutTracker::MultiExchange$ConnectTimeoutTracker() {
}

$Class* MultiExchange$ConnectTimeoutTracker::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$ConnectTimeoutTracker, name, initialize, &_MultiExchange$ConnectTimeoutTracker_ClassInfo_, clinit$MultiExchange$ConnectTimeoutTracker, allocate$MultiExchange$ConnectTimeoutTracker);
	return class$;
}

$Class* MultiExchange$ConnectTimeoutTracker::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk