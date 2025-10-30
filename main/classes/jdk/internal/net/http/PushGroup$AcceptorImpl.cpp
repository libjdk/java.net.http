#include <jdk/internal/net/http/PushGroup$AcceptorImpl.h>

#include <java/io/Serializable.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/net/http/HttpResponse.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/function/BiConsumer.h>
#include <jdk/internal/net/http/PushGroup.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $HttpResponse = ::java::net::http::HttpResponse;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $Objects = ::java::util::Objects;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $Executor = ::java::util::concurrent::Executor;
using $BiConsumer = ::java::util::function::BiConsumer;
using $PushGroup = ::jdk::internal::net::http::PushGroup;
using $PushGroup$Acceptor = ::jdk::internal::net::http::PushGroup$Acceptor;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class PushGroup$AcceptorImpl$$Lambda$lambda$accept$0 : public $BiConsumer {
	$class(PushGroup$AcceptorImpl$$Lambda$lambda$accept$0, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* r, Object$* t) override {
		PushGroup$AcceptorImpl::lambda$accept$0($cast($HttpResponse, r), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PushGroup$AcceptorImpl$$Lambda$lambda$accept$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo PushGroup$AcceptorImpl$$Lambda$lambda$accept$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(PushGroup$AcceptorImpl$$Lambda$lambda$accept$0::*)()>(&PushGroup$AcceptorImpl$$Lambda$lambda$accept$0::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo PushGroup$AcceptorImpl$$Lambda$lambda$accept$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PushGroup$AcceptorImpl$$Lambda$lambda$accept$0",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	nullptr,
	methodInfos
};
$Class* PushGroup$AcceptorImpl$$Lambda$lambda$accept$0::load$($String* name, bool initialize) {
	$loadClass(PushGroup$AcceptorImpl$$Lambda$lambda$accept$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PushGroup$AcceptorImpl$$Lambda$lambda$accept$0::class$ = nullptr;

$FieldInfo _PushGroup$AcceptorImpl_FieldInfo_[] = {
	{"executor", "Ljava/util/concurrent/Executor;", nullptr, $PRIVATE | $FINAL, $field(PushGroup$AcceptorImpl, executor)},
	{"bodyHandler", "Ljava/net/http/HttpResponse$BodyHandler;", "Ljava/net/http/HttpResponse$BodyHandler<TT;>;", $PRIVATE | $VOLATILE, $field(PushGroup$AcceptorImpl, bodyHandler$)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;", $PRIVATE | $VOLATILE, $field(PushGroup$AcceptorImpl, cf$)},
	{}
};

$MethodInfo _PushGroup$AcceptorImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/Executor;)V", nullptr, 0, $method(static_cast<void(PushGroup$AcceptorImpl::*)($Executor*)>(&PushGroup$AcceptorImpl::init$))},
	{"accept", "(Ljava/net/http/HttpResponse$BodyHandler;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/net/http/HttpResponse$BodyHandler<TT;>;)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;", 0},
	{"accepted", "()Z", nullptr, $PUBLIC},
	{"bodyHandler", "()Ljava/net/http/HttpResponse$BodyHandler;", "()Ljava/net/http/HttpResponse$BodyHandler<TT;>;", $PUBLIC},
	{"cf", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;", $PUBLIC},
	{"lambda$accept$0", "(Ljava/net/http/HttpResponse;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($HttpResponse*,$Throwable*)>(&PushGroup$AcceptorImpl::lambda$accept$0))},
	{}
};

$InnerClassInfo _PushGroup$AcceptorImpl_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.PushGroup$AcceptorImpl", "jdk.internal.net.http.PushGroup", "AcceptorImpl", $PRIVATE | $STATIC},
	{"jdk.internal.net.http.PushGroup$Acceptor", "jdk.internal.net.http.PushGroup", "Acceptor", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _PushGroup$AcceptorImpl_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.PushGroup$AcceptorImpl",
	"java.lang.Object",
	"jdk.internal.net.http.PushGroup$Acceptor",
	_PushGroup$AcceptorImpl_FieldInfo_,
	_PushGroup$AcceptorImpl_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljdk/internal/net/http/PushGroup$Acceptor<TT;>;",
	nullptr,
	_PushGroup$AcceptorImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.PushGroup"
};

$Object* allocate$PushGroup$AcceptorImpl($Class* clazz) {
	return $of($alloc(PushGroup$AcceptorImpl));
}

void PushGroup$AcceptorImpl::init$($Executor* executor) {
	$set(this, executor, executor);
}

$CompletableFuture* PushGroup$AcceptorImpl::accept($HttpResponse$BodyHandler* bodyHandler) {
	$Objects::requireNonNull(bodyHandler);
	if (this->bodyHandler$ != nullptr) {
		$throwNew($IllegalStateException, "non-null bodyHandler"_s);
	}
	$set(this, bodyHandler$, bodyHandler);
	$set(this, cf$, $new($MinimalFuture));
	return $cast($CompletableFuture, $nc(this->cf$)->whenCompleteAsync(static_cast<$BiConsumer*>($$new(PushGroup$AcceptorImpl$$Lambda$lambda$accept$0)), this->executor));
}

$HttpResponse$BodyHandler* PushGroup$AcceptorImpl::bodyHandler() {
	return this->bodyHandler$;
}

$CompletableFuture* PushGroup$AcceptorImpl::cf() {
	return this->cf$;
}

bool PushGroup$AcceptorImpl::accepted() {
	return this->cf$ != nullptr;
}

void PushGroup$AcceptorImpl::lambda$accept$0($HttpResponse* r, $Throwable* t) {
	$init(PushGroup$AcceptorImpl);
}

PushGroup$AcceptorImpl::PushGroup$AcceptorImpl() {
}

$Class* PushGroup$AcceptorImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(PushGroup$AcceptorImpl$$Lambda$lambda$accept$0::classInfo$.name)) {
			return PushGroup$AcceptorImpl$$Lambda$lambda$accept$0::load$(name, initialize);
		}
	}
	$loadClass(PushGroup$AcceptorImpl, name, initialize, &_PushGroup$AcceptorImpl_ClassInfo_, allocate$PushGroup$AcceptorImpl);
	return class$;
}

$Class* PushGroup$AcceptorImpl::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk