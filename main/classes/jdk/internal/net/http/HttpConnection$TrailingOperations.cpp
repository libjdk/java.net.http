#include <jdk/internal/net/http/HttpConnection$TrailingOperations.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/AbstractMap.h>
#include <java/util/IdentityHashMap.h>
#include <java/util/Map.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/function/BiConsumer.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jcpp.h>

#undef TRUE

using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $AbstractMap = ::java::util::AbstractMap;
using $IdentityHashMap = ::java::util::IdentityHashMap;
using $Map = ::java::util::Map;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $BiConsumer = ::java::util::function::BiConsumer;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class HttpConnection$TrailingOperations$$Lambda$lambda$add$0 : public $BiConsumer {
	$class(HttpConnection$TrailingOperations$$Lambda$lambda$add$0, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$(HttpConnection$TrailingOperations* inst, $CompletionStage* cf) {
		$set(this, inst$, inst);
		$set(this, cf, cf);
	}
	virtual void accept(Object$* r, Object$* t) override {
		$nc(inst$)->lambda$add$0(cf, r, $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpConnection$TrailingOperations$$Lambda$lambda$add$0>());
	}
	HttpConnection$TrailingOperations* inst$ = nullptr;
	$CompletionStage* cf = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpConnection$TrailingOperations$$Lambda$lambda$add$0::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HttpConnection$TrailingOperations$$Lambda$lambda$add$0, inst$)},
	{"cf", "Ljava/util/concurrent/CompletionStage;", nullptr, $PUBLIC, $field(HttpConnection$TrailingOperations$$Lambda$lambda$add$0, cf)},
	{}
};
$MethodInfo HttpConnection$TrailingOperations$$Lambda$lambda$add$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/HttpConnection$TrailingOperations;Ljava/util/concurrent/CompletionStage;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpConnection$TrailingOperations$$Lambda$lambda$add$0::*)(HttpConnection$TrailingOperations*,$CompletionStage*)>(&HttpConnection$TrailingOperations$$Lambda$lambda$add$0::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpConnection$TrailingOperations$$Lambda$lambda$add$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpConnection$TrailingOperations$$Lambda$lambda$add$0",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* HttpConnection$TrailingOperations$$Lambda$lambda$add$0::load$($String* name, bool initialize) {
	$loadClass(HttpConnection$TrailingOperations$$Lambda$lambda$add$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpConnection$TrailingOperations$$Lambda$lambda$add$0::class$ = nullptr;

$FieldInfo _HttpConnection$TrailingOperations_FieldInfo_[] = {
	{"operations", "Ljava/util/Map;", "Ljava/util/Map<Ljava/util/concurrent/CompletionStage<*>;Ljava/lang/Boolean;>;", $PRIVATE | $FINAL, $field(HttpConnection$TrailingOperations, operations)},
	{}
};

$MethodInfo _HttpConnection$TrailingOperations_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(HttpConnection$TrailingOperations::*)()>(&HttpConnection$TrailingOperations::init$))},
	{"add", "(Ljava/util/concurrent/CompletionStage;)V", "(Ljava/util/concurrent/CompletionStage<*>;)V", 0, $method(static_cast<void(HttpConnection$TrailingOperations::*)($CompletionStage*)>(&HttpConnection$TrailingOperations::add))},
	{"lambda$add$0", "(Ljava/util/concurrent/CompletionStage;Ljava/lang/Object;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(HttpConnection$TrailingOperations::*)($CompletionStage*,Object$*,$Throwable*)>(&HttpConnection$TrailingOperations::lambda$add$0))},
	{"remove", "(Ljava/util/concurrent/CompletionStage;)Z", "(Ljava/util/concurrent/CompletionStage<*>;)Z", 0, $method(static_cast<bool(HttpConnection$TrailingOperations::*)($CompletionStage*)>(&HttpConnection$TrailingOperations::remove))},
	{}
};

$InnerClassInfo _HttpConnection$TrailingOperations_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.HttpConnection$TrailingOperations", "jdk.internal.net.http.HttpConnection", "TrailingOperations", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _HttpConnection$TrailingOperations_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.HttpConnection$TrailingOperations",
	"java.lang.Object",
	nullptr,
	_HttpConnection$TrailingOperations_FieldInfo_,
	_HttpConnection$TrailingOperations_MethodInfo_,
	nullptr,
	nullptr,
	_HttpConnection$TrailingOperations_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HttpConnection"
};

$Object* allocate$HttpConnection$TrailingOperations($Class* clazz) {
	return $of($alloc(HttpConnection$TrailingOperations));
}

void HttpConnection$TrailingOperations::init$() {
	$set(this, operations, $new($IdentityHashMap));
}

void HttpConnection$TrailingOperations::add($CompletionStage* cf) {
	$synchronized(this->operations) {
		$init($Boolean);
		$nc(this->operations)->put(cf, $Boolean::TRUE);
		$nc(cf)->whenComplete(static_cast<$BiConsumer*>($$new(HttpConnection$TrailingOperations$$Lambda$lambda$add$0, this, cf)));
	}
}

bool HttpConnection$TrailingOperations::remove($CompletionStage* cf) {
	$synchronized(this->operations) {
		return $nc(($cast($Boolean, $($nc(this->operations)->remove(cf)))))->booleanValue();
	}
}

void HttpConnection$TrailingOperations::lambda$add$0($CompletionStage* cf, Object$* r, $Throwable* t) {
	remove(cf);
}

HttpConnection$TrailingOperations::HttpConnection$TrailingOperations() {
}

$Class* HttpConnection$TrailingOperations::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HttpConnection$TrailingOperations$$Lambda$lambda$add$0::classInfo$.name)) {
			return HttpConnection$TrailingOperations$$Lambda$lambda$add$0::load$(name, initialize);
		}
	}
	$loadClass(HttpConnection$TrailingOperations, name, initialize, &_HttpConnection$TrailingOperations_ClassInfo_, allocate$HttpConnection$TrailingOperations);
	return class$;
}

$Class* HttpConnection$TrailingOperations::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk