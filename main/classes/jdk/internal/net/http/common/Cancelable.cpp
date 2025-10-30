#include <jdk/internal/net/http/common/Cancelable.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $MethodInfo = ::java::lang::MethodInfo;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$CompoundAttribute _Cancelable_Annotations_[] = {
	{"Ljava/lang/FunctionalInterface;", nullptr},
	{}
};

$MethodInfo _Cancelable_MethodInfo_[] = {
	{"cancel", "(Z)Z", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _Cancelable_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.common.Cancelable",
	nullptr,
	nullptr,
	nullptr,
	_Cancelable_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_Cancelable_Annotations_
};

$Object* allocate$Cancelable($Class* clazz) {
	return $of($alloc(Cancelable));
}

$Class* Cancelable::load$($String* name, bool initialize) {
	$loadClass(Cancelable, name, initialize, &_Cancelable_ClassInfo_, allocate$Cancelable);
	return class$;
}

$Class* Cancelable::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk