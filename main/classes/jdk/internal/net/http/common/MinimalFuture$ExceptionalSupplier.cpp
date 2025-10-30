#include <jdk/internal/net/http/common/MinimalFuture$ExceptionalSupplier.h>

#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$CompoundAttribute _MinimalFuture$ExceptionalSupplier_Annotations_[] = {
	{"Ljava/lang/FunctionalInterface;", nullptr},
	{}
};

$MethodInfo _MinimalFuture$ExceptionalSupplier_MethodInfo_[] = {
	{"get", "()Ljava/lang/Object;", "()TU;", $PUBLIC | $ABSTRACT, nullptr, "java.lang.Throwable"},
	{}
};

$InnerClassInfo _MinimalFuture$ExceptionalSupplier_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.MinimalFuture$ExceptionalSupplier", "jdk.internal.net.http.common.MinimalFuture", "ExceptionalSupplier", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _MinimalFuture$ExceptionalSupplier_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.common.MinimalFuture$ExceptionalSupplier",
	nullptr,
	nullptr,
	nullptr,
	_MinimalFuture$ExceptionalSupplier_MethodInfo_,
	"<U:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	_MinimalFuture$ExceptionalSupplier_InnerClassesInfo_,
	_MinimalFuture$ExceptionalSupplier_Annotations_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.MinimalFuture"
};

$Object* allocate$MinimalFuture$ExceptionalSupplier($Class* clazz) {
	return $of($alloc(MinimalFuture$ExceptionalSupplier));
}

$Class* MinimalFuture$ExceptionalSupplier::load$($String* name, bool initialize) {
	$loadClass(MinimalFuture$ExceptionalSupplier, name, initialize, &_MinimalFuture$ExceptionalSupplier_ClassInfo_, allocate$MinimalFuture$ExceptionalSupplier);
	return class$;
}

$Class* MinimalFuture$ExceptionalSupplier::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk