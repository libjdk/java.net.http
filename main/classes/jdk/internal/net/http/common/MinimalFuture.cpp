#include <jdk/internal/net/http/common/MinimalFuture.h>

#include <java/io/Serializable.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <java/util/function/BiConsumer.h>
#include <jdk/internal/net/http/common/Cancelable.h>
#include <jdk/internal/net/http/common/MinimalFuture$ExceptionalSupplier.h>
#include <jcpp.h>

#undef TOKENS

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Objects = ::java::util::Objects;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Cancelable = ::jdk::internal::net::http::common::Cancelable;
using $MinimalFuture$ExceptionalSupplier = ::jdk::internal::net::http::common::MinimalFuture$ExceptionalSupplier;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class MinimalFuture$$Lambda$lambda$of$0 : public $BiConsumer {
	$class(MinimalFuture$$Lambda$lambda$of$0, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(MinimalFuture* cf) {
		$set(this, cf, cf);
	}
	virtual void accept(Object$* r, Object$* t) override {
		MinimalFuture::lambda$of$0(cf, r, $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MinimalFuture$$Lambda$lambda$of$0>());
	}
	MinimalFuture* cf = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo MinimalFuture$$Lambda$lambda$of$0::fieldInfos[2] = {
	{"cf", "Ljdk/internal/net/http/common/MinimalFuture;", nullptr, $PUBLIC, $field(MinimalFuture$$Lambda$lambda$of$0, cf)},
	{}
};
$MethodInfo MinimalFuture$$Lambda$lambda$of$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/common/MinimalFuture;)V", nullptr, $PUBLIC, $method(static_cast<void(MinimalFuture$$Lambda$lambda$of$0::*)(MinimalFuture*)>(&MinimalFuture$$Lambda$lambda$of$0::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo MinimalFuture$$Lambda$lambda$of$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.MinimalFuture$$Lambda$lambda$of$0",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* MinimalFuture$$Lambda$lambda$of$0::load$($String* name, bool initialize) {
	$loadClass(MinimalFuture$$Lambda$lambda$of$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MinimalFuture$$Lambda$lambda$of$0::class$ = nullptr;

$FieldInfo _MinimalFuture_FieldInfo_[] = {
	{"TOKENS", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MinimalFuture, TOKENS)},
	{"id", "J", nullptr, $PRIVATE | $FINAL, $field(MinimalFuture, id)},
	{"cancelable", "Ljdk/internal/net/http/common/Cancelable;", nullptr, $PRIVATE | $FINAL, $field(MinimalFuture, cancelable$)},
	{}
};

$MethodInfo _MinimalFuture_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(MinimalFuture::*)()>(&MinimalFuture::init$))},
	{"<init>", "(Ljdk/internal/net/http/common/Cancelable;)V", nullptr, $PUBLIC, $method(static_cast<void(MinimalFuture::*)($Cancelable*)>(&MinimalFuture::init$))},
	{"cancel", "(Z)Z", nullptr, $PUBLIC},
	{"cancelable", "()Ljdk/internal/net/http/common/Cancelable;", nullptr, $PRIVATE, $method(static_cast<$Cancelable*(MinimalFuture::*)()>(&MinimalFuture::cancelable))},
	{"complete", "(Ljava/util/concurrent/CompletableFuture;Ljava/lang/Object;Ljava/lang/Throwable;)V", "<U:Ljava/lang/Object;>(Ljava/util/concurrent/CompletableFuture<TU;>;TU;Ljava/lang/Throwable;)V", $PRIVATE | $STATIC, $method(static_cast<void(*)($CompletableFuture*,Object$*,$Throwable*)>(&MinimalFuture::complete))},
	{"completedFuture", "(Ljava/lang/Object;)Ljdk/internal/net/http/common/MinimalFuture;", "<U:Ljava/lang/Object;>(TU;)Ljdk/internal/net/http/common/MinimalFuture<TU;>;", $PUBLIC | $STATIC, $method(static_cast<MinimalFuture*(*)(Object$*)>(&MinimalFuture::completedFuture))},
	{"failedFuture", "(Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC | $STATIC, $method(static_cast<$CompletableFuture*(*)($Throwable*)>(&MinimalFuture::failedFuture))},
	{"lambda$of$0", "(Ljdk/internal/net/http/common/MinimalFuture;Ljava/lang/Object;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)(MinimalFuture*,Object$*,$Throwable*)>(&MinimalFuture::lambda$of$0))},
	{"newIncompleteFuture", "()Ljdk/internal/net/http/common/MinimalFuture;", "<U:Ljava/lang/Object;>()Ljdk/internal/net/http/common/MinimalFuture<TU;>;", $PUBLIC},
	{"obtrudeException", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"obtrudeValue", "(Ljava/lang/Object;)V", "(TT;)V", $PUBLIC},
	{"of", "(Ljava/util/concurrent/CompletionStage;)Ljdk/internal/net/http/common/MinimalFuture;", "<U:Ljava/lang/Object;>(Ljava/util/concurrent/CompletionStage<TU;>;)Ljdk/internal/net/http/common/MinimalFuture<TU;>;", $PUBLIC | $STATIC, $method(static_cast<MinimalFuture*(*)($CompletionStage*)>(&MinimalFuture::of))},
	{"supply", "(Ljdk/internal/net/http/common/MinimalFuture$ExceptionalSupplier;)Ljava/util/concurrent/CompletableFuture;", "<U:Ljava/lang/Object;>(Ljdk/internal/net/http/common/MinimalFuture$ExceptionalSupplier<TU;>;)Ljava/util/concurrent/CompletableFuture<TU;>;", $PUBLIC | $STATIC, $method(static_cast<$CompletableFuture*(*)($MinimalFuture$ExceptionalSupplier*)>(&MinimalFuture::supply))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _MinimalFuture_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.MinimalFuture$ExceptionalSupplier", "jdk.internal.net.http.common.MinimalFuture", "ExceptionalSupplier", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _MinimalFuture_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.MinimalFuture",
	"java.util.concurrent.CompletableFuture",
	nullptr,
	_MinimalFuture_FieldInfo_,
	_MinimalFuture_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/util/concurrent/CompletableFuture<TT;>;",
	nullptr,
	_MinimalFuture_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.MinimalFuture$ExceptionalSupplier"
};

$Object* allocate$MinimalFuture($Class* clazz) {
	return $of($alloc(MinimalFuture));
}

$AtomicLong* MinimalFuture::TOKENS = nullptr;

MinimalFuture* MinimalFuture::completedFuture(Object$* value) {
	$init(MinimalFuture);
	$var(MinimalFuture, f, $new(MinimalFuture));
	f->complete(value);
	return f;
}

$CompletableFuture* MinimalFuture::failedFuture($Throwable* ex) {
	$init(MinimalFuture);
	$Objects::requireNonNull(ex);
	$var(MinimalFuture, f, $new(MinimalFuture));
	f->completeExceptionally(ex);
	return f;
}

$CompletableFuture* MinimalFuture::supply($MinimalFuture$ExceptionalSupplier* supplier) {
	$init(MinimalFuture);
	$useLocalCurrentObjectStackCache();
	$var($CompletableFuture, cf, $new(MinimalFuture));
	try {
		$var($Object, value, $nc(supplier)->get());
		cf->complete(value);
	} catch ($Throwable& t) {
		cf->completeExceptionally(t);
	}
	return cf;
}

void MinimalFuture::init$() {
	MinimalFuture::init$(nullptr);
}

void MinimalFuture::init$($Cancelable* cancelable) {
	$CompletableFuture::init$();
	this->id = $nc(MinimalFuture::TOKENS)->incrementAndGet();
	$set(this, cancelable$, cancelable);
}

MinimalFuture* MinimalFuture::newIncompleteFuture() {
	return $new(MinimalFuture, this->cancelable$);
}

void MinimalFuture::obtrudeValue(Object$* value) {
	$throwNew($UnsupportedOperationException);
}

void MinimalFuture::obtrudeException($Throwable* ex) {
	$throwNew($UnsupportedOperationException);
}

$String* MinimalFuture::toString() {
	$useLocalCurrentObjectStackCache();
	return $str({$($CompletableFuture::toString()), " (id="_s, $$str(this->id), ")"_s});
}

bool MinimalFuture::cancel(bool mayInterruptIfRunning) {
	bool result = false;
	if (this->cancelable$ != nullptr && !isDone()) {
		result = $nc(this->cancelable$)->cancel(mayInterruptIfRunning);
	}
	return $CompletableFuture::cancel(mayInterruptIfRunning) || result;
}

$Cancelable* MinimalFuture::cancelable() {
	return this->cancelable$;
}

MinimalFuture* MinimalFuture::of($CompletionStage* stage) {
	$init(MinimalFuture);
	$useLocalCurrentObjectStackCache();
	$var($Cancelable, cancelable, $instanceOf(MinimalFuture, stage) ? $nc(($cast(MinimalFuture, stage)))->cancelable() : ($Cancelable*)nullptr);
	$var(MinimalFuture, cf, $new(MinimalFuture, cancelable));
	$nc(stage)->whenComplete(static_cast<$BiConsumer*>($$new(MinimalFuture$$Lambda$lambda$of$0, cf)));
	return cf;
}

void MinimalFuture::complete($CompletableFuture* cf, Object$* result, $Throwable* t) {
	$init(MinimalFuture);
	if (t == nullptr) {
		$nc(cf)->complete(result);
	} else {
		$nc(cf)->completeExceptionally(t);
	}
}

void MinimalFuture::lambda$of$0(MinimalFuture* cf, Object$* r, $Throwable* t) {
	$init(MinimalFuture);
	complete(cf, r, t);
}

void clinit$MinimalFuture($Class* class$) {
	$assignStatic(MinimalFuture::TOKENS, $new($AtomicLong));
}

MinimalFuture::MinimalFuture() {
}

$Class* MinimalFuture::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(MinimalFuture$$Lambda$lambda$of$0::classInfo$.name)) {
			return MinimalFuture$$Lambda$lambda$of$0::load$(name, initialize);
		}
	}
	$loadClass(MinimalFuture, name, initialize, &_MinimalFuture_ClassInfo_, clinit$MinimalFuture, allocate$MinimalFuture);
	return class$;
}

$Class* MinimalFuture::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk