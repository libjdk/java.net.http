#include <jdk/internal/net/http/PushGroup.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/http/HttpRequest.h>
#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/net/http/HttpResponse$PushPromiseHandler.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/function/Function.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/PushGroup$Acceptor.h>
#include <jdk/internal/net/http/PushGroup$AcceptorImpl.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $HttpResponse$PushPromiseHandler = ::java::net::http::HttpResponse$PushPromiseHandler;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $Executor = ::java::util::concurrent::Executor;
using $Function = ::java::util::function::Function;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $PushGroup$Acceptor = ::jdk::internal::net::http::PushGroup$Acceptor;
using $PushGroup$AcceptorImpl = ::jdk::internal::net::http::PushGroup$AcceptorImpl;
using $Log = ::jdk::internal::net::http::common::Log;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class PushGroup$$Lambda$accept : public $Function {
	$class(PushGroup$$Lambda$accept, $NO_CLASS_INIT, $Function)
public:
	void init$($PushGroup$AcceptorImpl* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* bodyHandler) override {
		 return $of($nc(inst$)->accept($cast($HttpResponse$BodyHandler, bodyHandler)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PushGroup$$Lambda$accept>());
	}
	$PushGroup$AcceptorImpl* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PushGroup$$Lambda$accept::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(PushGroup$$Lambda$accept, inst$)},
	{}
};
$MethodInfo PushGroup$$Lambda$accept::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/PushGroup$AcceptorImpl;)V", nullptr, $PUBLIC, $method(static_cast<void(PushGroup$$Lambda$accept::*)($PushGroup$AcceptorImpl*)>(&PushGroup$$Lambda$accept::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo PushGroup$$Lambda$accept::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PushGroup$$Lambda$accept",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* PushGroup$$Lambda$accept::load$($String* name, bool initialize) {
	$loadClass(PushGroup$$Lambda$accept, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PushGroup$$Lambda$accept::class$ = nullptr;

$FieldInfo _PushGroup_FieldInfo_[] = {
	{"initiatingRequest", "Ljava/net/http/HttpRequest;", nullptr, $PRIVATE | $FINAL, $field(PushGroup, initiatingRequest)},
	{"noMorePushesCF", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $FINAL, $field(PushGroup, noMorePushesCF)},
	{"error", "Ljava/lang/Throwable;", nullptr, $VOLATILE, $field(PushGroup, error)},
	{"pushPromiseHandler", "Ljava/net/http/HttpResponse$PushPromiseHandler;", "Ljava/net/http/HttpResponse$PushPromiseHandler<TT;>;", $FINAL, $field(PushGroup, pushPromiseHandler)},
	{"executor", "Ljava/util/concurrent/Executor;", nullptr, $PRIVATE | $FINAL, $field(PushGroup, executor)},
	{"numberOfPushes", "I", nullptr, 0, $field(PushGroup, numberOfPushes)},
	{"remainingPushes", "I", nullptr, 0, $field(PushGroup, remainingPushes)},
	{"noMorePushes", "Z", nullptr, 0, $field(PushGroup, noMorePushes$)},
	{}
};

$MethodInfo _PushGroup_MethodInfo_[] = {
	{"<init>", "(Ljava/net/http/HttpResponse$PushPromiseHandler;Ljdk/internal/net/http/HttpRequestImpl;Ljava/util/concurrent/Executor;)V", "(Ljava/net/http/HttpResponse$PushPromiseHandler<TT;>;Ljdk/internal/net/http/HttpRequestImpl;Ljava/util/concurrent/Executor;)V", 0, $method(static_cast<void(PushGroup::*)($HttpResponse$PushPromiseHandler*,$HttpRequestImpl*,$Executor*)>(&PushGroup::init$))},
	{"<init>", "(Ljava/net/http/HttpResponse$PushPromiseHandler;Ljdk/internal/net/http/HttpRequestImpl;Ljava/util/concurrent/CompletableFuture;Ljava/util/concurrent/Executor;)V", "(Ljava/net/http/HttpResponse$PushPromiseHandler<TT;>;Ljdk/internal/net/http/HttpRequestImpl;Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;Ljava/util/concurrent/Executor;)V", $PRIVATE, $method(static_cast<void(PushGroup::*)($HttpResponse$PushPromiseHandler*,$HttpRequestImpl*,$CompletableFuture*,$Executor*)>(&PushGroup::init$))},
	{"acceptPushRequest", "(Ljava/net/http/HttpRequest;)Ljdk/internal/net/http/PushGroup$Acceptor;", "(Ljava/net/http/HttpRequest;)Ljdk/internal/net/http/PushGroup$Acceptor<TT;>;", 0},
	{"checkIfCompleted", "()V", nullptr, $SYNCHRONIZED},
	{"noMorePushes", "(Z)V", nullptr, $SYNCHRONIZED},
	{"noMorePushes", "()Z", nullptr, $SYNCHRONIZED},
	{"pushCompleted", "()V", nullptr, $SYNCHRONIZED},
	{"pushError", "(Ljava/lang/Throwable;)V", nullptr, $SYNCHRONIZED},
	{"pushesCF", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $SYNCHRONIZED},
	{}
};

$InnerClassInfo _PushGroup_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.PushGroup$AcceptorImpl", "jdk.internal.net.http.PushGroup", "AcceptorImpl", $PRIVATE | $STATIC},
	{"jdk.internal.net.http.PushGroup$Acceptor", "jdk.internal.net.http.PushGroup", "Acceptor", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _PushGroup_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.PushGroup",
	"java.lang.Object",
	nullptr,
	_PushGroup_FieldInfo_,
	_PushGroup_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	_PushGroup_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.PushGroup$AcceptorImpl,jdk.internal.net.http.PushGroup$Acceptor"
};

$Object* allocate$PushGroup($Class* clazz) {
	return $of($alloc(PushGroup));
}

void PushGroup::init$($HttpResponse$PushPromiseHandler* pushPromiseHandler, $HttpRequestImpl* initiatingRequest, $Executor* executor) {
	PushGroup::init$(pushPromiseHandler, initiatingRequest, $$new($MinimalFuture), executor);
}

void PushGroup::init$($HttpResponse$PushPromiseHandler* pushPromiseHandler, $HttpRequestImpl* initiatingRequest, $CompletableFuture* mainResponse, $Executor* executor) {
	this->noMorePushes$ = false;
	$set(this, noMorePushesCF, $new($MinimalFuture));
	$set(this, pushPromiseHandler, pushPromiseHandler);
	$set(this, initiatingRequest, initiatingRequest);
	$set(this, executor, executor);
}

$PushGroup$Acceptor* PushGroup::acceptPushRequest($HttpRequest* pushRequest) {
	$useLocalCurrentObjectStackCache();
	$var($PushGroup$AcceptorImpl, acceptor, $new($PushGroup$AcceptorImpl, this->executor));
	try {
		$nc(this->pushPromiseHandler)->applyPushPromise(this->initiatingRequest, pushRequest, static_cast<$Function*>($$new(PushGroup$$Lambda$accept, static_cast<$PushGroup$AcceptorImpl*>(acceptor))));
	} catch ($Throwable& t) {
		if (acceptor->accepted()) {
			$var($CompletableFuture, cf, acceptor->cf());
			$nc(cf)->completeExceptionally(t);
		}
		$throw(t);
	}
	$synchronized(this) {
		if (acceptor->accepted()) {
			++this->numberOfPushes;
			++this->remainingPushes;
		}
		return acceptor;
	}
}

void PushGroup::noMorePushes(bool noMore) {
	$synchronized(this) {
		this->noMorePushes$ = noMore;
		checkIfCompleted();
		$nc(this->noMorePushesCF)->complete(nullptr);
	}
}

$CompletableFuture* PushGroup::pushesCF() {
	$synchronized(this) {
		return this->noMorePushesCF;
	}
}

bool PushGroup::noMorePushes() {
	$synchronized(this) {
		return this->noMorePushes$;
	}
}

void PushGroup::pushCompleted() {
	$synchronized(this) {
		--this->remainingPushes;
		checkIfCompleted();
	}
}

void PushGroup::checkIfCompleted() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if ($Log::trace()) {
			$Log::logTrace("PushGroup remainingPushes={0} error={1} noMorePushes={2}"_s, $$new($ObjectArray, {
				$($of($Integer::valueOf(this->remainingPushes))),
				(this->error == nullptr) ? $cast($Object, this->error) : $($of($nc($of(this->error))->getClass()->getSimpleName())),
				$($of($Boolean::valueOf(this->noMorePushes$)))
			}));
		}
		if (this->remainingPushes == 0 && this->error == nullptr && this->noMorePushes$) {
			if ($Log::trace()) {
				$Log::logTrace("push completed"_s, $$new($ObjectArray, 0));
			}
		}
	}
}

void PushGroup::pushError($Throwable* t) {
	$synchronized(this) {
		if (t == nullptr) {
			return;
		}
		$set(this, error, t);
	}
}

PushGroup::PushGroup() {
}

$Class* PushGroup::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(PushGroup$$Lambda$accept::classInfo$.name)) {
			return PushGroup$$Lambda$accept::load$(name, initialize);
		}
	}
	$loadClass(PushGroup, name, initialize, &_PushGroup_ClassInfo_, allocate$PushGroup);
	return class$;
}

$Class* PushGroup::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk