#include <jdk/internal/net/http/TimeoutEvent.h>

#include <java/lang/AssertionError.h>
#include <java/time/Duration.h>
#include <java/time/Instant.h>
#include <java/time/temporal/TemporalAmount.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <jcpp.h>

#undef COUNTER

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Comparable = ::java::lang::Comparable;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Duration = ::java::time::Duration;
using $Instant = ::java::time::Instant;
using $TemporalAmount = ::java::time::temporal::TemporalAmount;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _TimeoutEvent_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(TimeoutEvent, $assertionsDisabled)},
	{"COUNTER", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TimeoutEvent, COUNTER)},
	{"id", "J", nullptr, $PRIVATE | $FINAL, $field(TimeoutEvent, id)},
	{"duration", "Ljava/time/Duration;", nullptr, $PRIVATE | $FINAL, $field(TimeoutEvent, duration)},
	{"deadline", "Ljava/time/Instant;", nullptr, $PRIVATE | $FINAL, $field(TimeoutEvent, deadline$)},
	{}
};

$MethodInfo _TimeoutEvent_MethodInfo_[] = {
	{"<init>", "(Ljava/time/Duration;)V", nullptr, 0, $method(static_cast<void(TimeoutEvent::*)($Duration*)>(&TimeoutEvent::init$))},
	{"compareTo", "(Ljdk/internal/net/http/TimeoutEvent;)I", nullptr, $PUBLIC},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"deadline", "()Ljava/time/Instant;", nullptr, $PUBLIC},
	{"handle", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _TimeoutEvent_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.TimeoutEvent",
	"java.lang.Object",
	"java.lang.Comparable",
	_TimeoutEvent_FieldInfo_,
	_TimeoutEvent_MethodInfo_,
	"Ljava/lang/Object;Ljava/lang/Comparable<Ljdk/internal/net/http/TimeoutEvent;>;"
};

$Object* allocate$TimeoutEvent($Class* clazz) {
	return $of($alloc(TimeoutEvent));
}

bool TimeoutEvent::$assertionsDisabled = false;
$AtomicLong* TimeoutEvent::COUNTER = nullptr;

void TimeoutEvent::init$($Duration* duration) {
	this->id = $nc(TimeoutEvent::COUNTER)->incrementAndGet();
	$set(this, duration, duration);
	$set(this, deadline$, $nc($($Instant::now()))->plus(duration));
}

$Instant* TimeoutEvent::deadline() {
	return this->deadline$;
}

int32_t TimeoutEvent::compareTo(TimeoutEvent* other) {
	if (other == this) {
		return 0;
	}
	int32_t compareDeadline = $nc(this->deadline$)->compareTo($nc(other)->deadline$);
	if (compareDeadline == 0 && !$of(this)->equals(other)) {
		int64_t diff = this->id - $nc(other)->id;
		if (diff < 0) {
			return -1;
		} else if (diff > 0) {
			return 1;
		} else if (!TimeoutEvent::$assertionsDisabled) {
			$throwNew($AssertionError, $of("Different events with same id and deadline"_s));
		}
	}
	return compareDeadline;
}

$String* TimeoutEvent::toString() {
	return $str({"TimeoutEvent[id="_s, $$str(this->id), ", duration="_s, this->duration, ", deadline="_s, this->deadline$, "]"_s});
}

int32_t TimeoutEvent::compareTo(Object$* other) {
	return this->compareTo($cast(TimeoutEvent, other));
}

void clinit$TimeoutEvent($Class* class$) {
	TimeoutEvent::$assertionsDisabled = !TimeoutEvent::class$->desiredAssertionStatus();
	$assignStatic(TimeoutEvent::COUNTER, $new($AtomicLong));
}

TimeoutEvent::TimeoutEvent() {
}

$Class* TimeoutEvent::load$($String* name, bool initialize) {
	$loadClass(TimeoutEvent, name, initialize, &_TimeoutEvent_ClassInfo_, clinit$TimeoutEvent, allocate$TimeoutEvent);
	return class$;
}

$Class* TimeoutEvent::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk