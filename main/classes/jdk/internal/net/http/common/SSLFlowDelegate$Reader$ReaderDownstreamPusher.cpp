#include <jdk/internal/net/http/common/SSLFlowDelegate$Reader$ReaderDownstreamPusher.h>

#include <jdk/internal/net/http/common/SSLFlowDelegate$Reader.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $SSLFlowDelegate$Reader = ::jdk::internal::net::http::common::SSLFlowDelegate$Reader;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SSLFlowDelegate$Reader$ReaderDownstreamPusher_FieldInfo_[] = {
	{"this$1", "Ljdk/internal/net/http/common/SSLFlowDelegate$Reader;", nullptr, $FINAL | $SYNTHETIC, $field(SSLFlowDelegate$Reader$ReaderDownstreamPusher, this$1)},
	{}
};

$MethodInfo _SSLFlowDelegate$Reader$ReaderDownstreamPusher_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/SSLFlowDelegate$Reader;)V", nullptr, $PRIVATE, $method(static_cast<void(SSLFlowDelegate$Reader$ReaderDownstreamPusher::*)($SSLFlowDelegate$Reader*)>(&SSLFlowDelegate$Reader$ReaderDownstreamPusher::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SSLFlowDelegate$Reader$ReaderDownstreamPusher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SSLFlowDelegate$Reader", "jdk.internal.net.http.common.SSLFlowDelegate", "Reader", $FINAL},
	{"jdk.internal.net.http.common.SSLFlowDelegate$Reader$ReaderDownstreamPusher", "jdk.internal.net.http.common.SSLFlowDelegate$Reader", "ReaderDownstreamPusher", $PRIVATE | $FINAL},
	{}
};

$ClassInfo _SSLFlowDelegate$Reader$ReaderDownstreamPusher_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.SSLFlowDelegate$Reader$ReaderDownstreamPusher",
	"java.lang.Object",
	"java.lang.Runnable",
	_SSLFlowDelegate$Reader$ReaderDownstreamPusher_FieldInfo_,
	_SSLFlowDelegate$Reader$ReaderDownstreamPusher_MethodInfo_,
	nullptr,
	nullptr,
	_SSLFlowDelegate$Reader$ReaderDownstreamPusher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SSLFlowDelegate"
};

$Object* allocate$SSLFlowDelegate$Reader$ReaderDownstreamPusher($Class* clazz) {
	return $of($alloc(SSLFlowDelegate$Reader$ReaderDownstreamPusher));
}

void SSLFlowDelegate$Reader$ReaderDownstreamPusher::init$($SSLFlowDelegate$Reader* this$1) {
	$set(this, this$1, this$1);
}

void SSLFlowDelegate$Reader$ReaderDownstreamPusher::run() {
	this->this$1->processData();
}

SSLFlowDelegate$Reader$ReaderDownstreamPusher::SSLFlowDelegate$Reader$ReaderDownstreamPusher() {
}

$Class* SSLFlowDelegate$Reader$ReaderDownstreamPusher::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$Reader$ReaderDownstreamPusher, name, initialize, &_SSLFlowDelegate$Reader$ReaderDownstreamPusher_ClassInfo_, allocate$SSLFlowDelegate$Reader$ReaderDownstreamPusher);
	return class$;
}

$Class* SSLFlowDelegate$Reader$ReaderDownstreamPusher::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk