#include <jdk/internal/net/http/common/SSLFlowDelegate$Monitor$FinalMonitorable.h>

#include <java/util/List.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Monitor.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Monitorable.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $List = ::java::util::List;
using $SSLFlowDelegate$Monitor = ::jdk::internal::net::http::common::SSLFlowDelegate$Monitor;
using $SSLFlowDelegate$Monitorable = ::jdk::internal::net::http::common::SSLFlowDelegate$Monitorable;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SSLFlowDelegate$Monitor$FinalMonitorable_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/common/SSLFlowDelegate$Monitor;", nullptr, $FINAL | $SYNTHETIC, $field(SSLFlowDelegate$Monitor$FinalMonitorable, this$0)},
	{"finalState", "Ljava/lang/String;", nullptr, $FINAL, $field(SSLFlowDelegate$Monitor$FinalMonitorable, finalState)},
	{}
};

$MethodInfo _SSLFlowDelegate$Monitor$FinalMonitorable_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/SSLFlowDelegate$Monitor;Ljdk/internal/net/http/common/SSLFlowDelegate$Monitorable;)V", nullptr, 0, $method(static_cast<void(SSLFlowDelegate$Monitor$FinalMonitorable::*)($SSLFlowDelegate$Monitor*,$SSLFlowDelegate$Monitorable*)>(&SSLFlowDelegate$Monitor$FinalMonitorable::init$))},
	{"getInfo", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SSLFlowDelegate$Monitor$FinalMonitorable_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SSLFlowDelegate$Monitor", "jdk.internal.net.http.common.SSLFlowDelegate", "Monitor", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.common.SSLFlowDelegate$Monitor$FinalMonitorable", "jdk.internal.net.http.common.SSLFlowDelegate$Monitor", "FinalMonitorable", $FINAL},
	{"jdk.internal.net.http.common.SSLFlowDelegate$Monitorable", "jdk.internal.net.http.common.SSLFlowDelegate", "Monitorable", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SSLFlowDelegate$Monitor$FinalMonitorable_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.SSLFlowDelegate$Monitor$FinalMonitorable",
	"java.lang.Object",
	"jdk.internal.net.http.common.SSLFlowDelegate$Monitorable",
	_SSLFlowDelegate$Monitor$FinalMonitorable_FieldInfo_,
	_SSLFlowDelegate$Monitor$FinalMonitorable_MethodInfo_,
	nullptr,
	nullptr,
	_SSLFlowDelegate$Monitor$FinalMonitorable_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SSLFlowDelegate"
};

$Object* allocate$SSLFlowDelegate$Monitor$FinalMonitorable($Class* clazz) {
	return $of($alloc(SSLFlowDelegate$Monitor$FinalMonitorable));
}

void SSLFlowDelegate$Monitor$FinalMonitorable::init$($SSLFlowDelegate$Monitor* this$0, $SSLFlowDelegate$Monitorable* o) {
	$set(this, this$0, this$0);
	$set(this, finalState, $nc(o)->getInfo());
	$nc(this$0->finalList)->add(this);
}

$String* SSLFlowDelegate$Monitor$FinalMonitorable::getInfo() {
	$nc(this->this$0->finalList)->remove($of(this));
	return this->finalState;
}

SSLFlowDelegate$Monitor$FinalMonitorable::SSLFlowDelegate$Monitor$FinalMonitorable() {
}

$Class* SSLFlowDelegate$Monitor$FinalMonitorable::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$Monitor$FinalMonitorable, name, initialize, &_SSLFlowDelegate$Monitor$FinalMonitorable_ClassInfo_, allocate$SSLFlowDelegate$Monitor$FinalMonitorable);
	return class$;
}

$Class* SSLFlowDelegate$Monitor$FinalMonitorable::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk