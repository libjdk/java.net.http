#include <jdk/internal/net/http/common/SSLFlowDelegate$Monitorable.h>

#include <jdk/internal/net/http/common/SSLFlowDelegate.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SSLFlowDelegate = ::jdk::internal::net::http::common::SSLFlowDelegate;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$MethodInfo _SSLFlowDelegate$Monitorable_MethodInfo_[] = {
	{"getInfo", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _SSLFlowDelegate$Monitorable_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SSLFlowDelegate$Monitorable", "jdk.internal.net.http.common.SSLFlowDelegate", "Monitorable", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SSLFlowDelegate$Monitorable_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.common.SSLFlowDelegate$Monitorable",
	nullptr,
	nullptr,
	nullptr,
	_SSLFlowDelegate$Monitorable_MethodInfo_,
	nullptr,
	nullptr,
	_SSLFlowDelegate$Monitorable_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SSLFlowDelegate"
};

$Object* allocate$SSLFlowDelegate$Monitorable($Class* clazz) {
	return $of($alloc(SSLFlowDelegate$Monitorable));
}

$Class* SSLFlowDelegate$Monitorable::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$Monitorable, name, initialize, &_SSLFlowDelegate$Monitorable_ClassInfo_, allocate$SSLFlowDelegate$Monitorable);
	return class$;
}

$Class* SSLFlowDelegate$Monitorable::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk