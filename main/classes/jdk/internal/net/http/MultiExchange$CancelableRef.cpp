#include <jdk/internal/net/http/MultiExchange$CancelableRef.h>

#include <java/lang/ref/WeakReference.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/common/Cancelable.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Reference = ::java::lang::ref::Reference;
using $WeakReference = ::java::lang::ref::WeakReference;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;
using $Cancelable = ::jdk::internal::net::http::common::Cancelable;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _MultiExchange$CancelableRef_FieldInfo_[] = {
	{"cancelableRef", "Ljava/lang/ref/WeakReference;", "Ljava/lang/ref/WeakReference<Ljdk/internal/net/http/common/Cancelable;>;", $PRIVATE | $FINAL, $field(MultiExchange$CancelableRef, cancelableRef)},
	{}
};

$MethodInfo _MultiExchange$CancelableRef_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/Cancelable;)V", nullptr, 0, $method(static_cast<void(MultiExchange$CancelableRef::*)($Cancelable*)>(&MultiExchange$CancelableRef::init$))},
	{"cancel", "(Z)Z", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _MultiExchange$CancelableRef_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.MultiExchange$CancelableRef", "jdk.internal.net.http.MultiExchange", "CancelableRef", $STATIC | $FINAL},
	{}
};

$ClassInfo _MultiExchange$CancelableRef_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.MultiExchange$CancelableRef",
	"java.lang.Object",
	"jdk.internal.net.http.common.Cancelable",
	_MultiExchange$CancelableRef_FieldInfo_,
	_MultiExchange$CancelableRef_MethodInfo_,
	nullptr,
	nullptr,
	_MultiExchange$CancelableRef_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.MultiExchange"
};

$Object* allocate$MultiExchange$CancelableRef($Class* clazz) {
	return $of($alloc(MultiExchange$CancelableRef));
}

void MultiExchange$CancelableRef::init$($Cancelable* cancelable) {
	$set(this, cancelableRef, $new($WeakReference, cancelable));
}

bool MultiExchange$CancelableRef::cancel(bool mayInterruptIfRunning) {
	$var($Cancelable, cancelable, $cast($Cancelable, $nc(this->cancelableRef)->get()));
	if (cancelable != nullptr) {
		return cancelable->cancel(mayInterruptIfRunning);
	} else {
		return false;
	}
}

MultiExchange$CancelableRef::MultiExchange$CancelableRef() {
}

$Class* MultiExchange$CancelableRef::load$($String* name, bool initialize) {
	$loadClass(MultiExchange$CancelableRef, name, initialize, &_MultiExchange$CancelableRef_ClassInfo_, allocate$MultiExchange$CancelableRef);
	return class$;
}

$Class* MultiExchange$CancelableRef::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk