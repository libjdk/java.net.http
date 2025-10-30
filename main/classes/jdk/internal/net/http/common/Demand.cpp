#include <jdk/internal/net/http/common/Demand.h>

#include <java/io/Serializable.h>
#include <java/lang/Math.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <java/util/function/LongBinaryOperator.h>
#include <jcpp.h>

#undef MAX_VALUE

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $LongBinaryOperator = ::java::util::function::LongBinaryOperator;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class Demand$$Lambda$lambda$increase$0 : public $LongBinaryOperator {
	$class(Demand$$Lambda$lambda$increase$0, $NO_CLASS_INIT, $LongBinaryOperator)
public:
	void init$() {
	}
	virtual int64_t applyAsLong(int64_t p, int64_t i) override {
		 return Demand::lambda$increase$0(p, i);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Demand$$Lambda$lambda$increase$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Demand$$Lambda$lambda$increase$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Demand$$Lambda$lambda$increase$0::*)()>(&Demand$$Lambda$lambda$increase$0::init$))},
	{"applyAsLong", "(JJ)J", nullptr, $PUBLIC},
	{}
};
$ClassInfo Demand$$Lambda$lambda$increase$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Demand$$Lambda$lambda$increase$0",
	"java.lang.Object",
	"java.util.function.LongBinaryOperator",
	nullptr,
	methodInfos
};
$Class* Demand$$Lambda$lambda$increase$0::load$($String* name, bool initialize) {
	$loadClass(Demand$$Lambda$lambda$increase$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Demand$$Lambda$lambda$increase$0::class$ = nullptr;

$FieldInfo _Demand_FieldInfo_[] = {
	{"val", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $FINAL, $field(Demand, val)},
	{}
};

$MethodInfo _Demand_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Demand::*)()>(&Demand::init$))},
	{"decreaseAndGet", "(J)J", nullptr, $PUBLIC, $method(static_cast<int64_t(Demand::*)(int64_t)>(&Demand::decreaseAndGet))},
	{"get", "()J", nullptr, $PUBLIC, $method(static_cast<int64_t(Demand::*)()>(&Demand::get))},
	{"increase", "(J)Z", nullptr, $PUBLIC, $method(static_cast<bool(Demand::*)(int64_t)>(&Demand::increase))},
	{"increaseIfFulfilled", "()Z", nullptr, $PUBLIC, $method(static_cast<bool(Demand::*)()>(&Demand::increaseIfFulfilled))},
	{"isFulfilled", "()Z", nullptr, $PUBLIC, $method(static_cast<bool(Demand::*)()>(&Demand::isFulfilled))},
	{"lambda$increase$0", "(JJ)J", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<int64_t(*)(int64_t,int64_t)>(&Demand::lambda$increase$0))},
	{"reset", "()V", nullptr, $PUBLIC, $method(static_cast<void(Demand::*)()>(&Demand::reset))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"tryDecrement", "()Z", nullptr, $PUBLIC, $method(static_cast<bool(Demand::*)()>(&Demand::tryDecrement))},
	{}
};

$ClassInfo _Demand_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.Demand",
	"java.lang.Object",
	nullptr,
	_Demand_FieldInfo_,
	_Demand_MethodInfo_
};

$Object* allocate$Demand($Class* clazz) {
	return $of($alloc(Demand));
}

void Demand::init$() {
	$set(this, val, $new($AtomicLong));
}

bool Demand::increase(int64_t n) {
	$useLocalCurrentObjectStackCache();
	if (n <= 0) {
		$throwNew($IllegalArgumentException, $$str({"non-positive subscription request: "_s, $($String::valueOf(n))}));
	}
	int64_t prev = $nc(this->val)->getAndAccumulate(n, static_cast<$LongBinaryOperator*>($$new(Demand$$Lambda$lambda$increase$0)));
	return prev == 0;
}

bool Demand::increaseIfFulfilled() {
	return $nc(this->val)->compareAndSet(0, 1);
}

int64_t Demand::decreaseAndGet(int64_t n) {
	if (n <= 0) {
		$throwNew($IllegalArgumentException, $($String::valueOf(n)));
	}
	int64_t p = 0;
	int64_t d = 0;
	do {
		d = $nc(this->val)->get();
		p = $Math::min(d, n);
	} while (!$nc(this->val)->compareAndSet(d, d - p));
	return p;
}

bool Demand::tryDecrement() {
	return decreaseAndGet(1) == 1;
}

bool Demand::isFulfilled() {
	return $nc(this->val)->get() == 0;
}

void Demand::reset() {
	$nc(this->val)->set(0);
}

int64_t Demand::get() {
	return $nc(this->val)->get();
}

$String* Demand::toString() {
	return $String::valueOf($nc(this->val)->get());
}

int64_t Demand::lambda$increase$0(int64_t p, int64_t i) {
	return p + i < 0 ? $Long::MAX_VALUE : p + i;
}

Demand::Demand() {
}

$Class* Demand::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Demand$$Lambda$lambda$increase$0::classInfo$.name)) {
			return Demand$$Lambda$lambda$increase$0::load$(name, initialize);
		}
	}
	$loadClass(Demand, name, initialize, &_Demand_ClassInfo_, allocate$Demand);
	return class$;
}

$Class* Demand::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk