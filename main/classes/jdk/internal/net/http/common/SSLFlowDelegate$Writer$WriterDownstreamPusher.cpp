#include <jdk/internal/net/http/common/SSLFlowDelegate$Writer$WriterDownstreamPusher.h>

#include <jdk/internal/net/http/common/SSLFlowDelegate$Writer.h>
#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SSLFlowDelegate$Writer = ::jdk::internal::net::http::common::SSLFlowDelegate$Writer;
using $SequentialScheduler$CompleteRestartableTask = ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SSLFlowDelegate$Writer$WriterDownstreamPusher_FieldInfo_[] = {
	{"this$1", "Ljdk/internal/net/http/common/SSLFlowDelegate$Writer;", nullptr, $FINAL | $SYNTHETIC, $field(SSLFlowDelegate$Writer$WriterDownstreamPusher, this$1)},
	{}
};

$MethodInfo _SSLFlowDelegate$Writer$WriterDownstreamPusher_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/common/SSLFlowDelegate$Writer;)V", nullptr, 0, $method(static_cast<void(SSLFlowDelegate$Writer$WriterDownstreamPusher::*)($SSLFlowDelegate$Writer*)>(&SSLFlowDelegate$Writer$WriterDownstreamPusher::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SSLFlowDelegate$Writer$WriterDownstreamPusher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SSLFlowDelegate$Writer", "jdk.internal.net.http.common.SSLFlowDelegate", "Writer", 0},
	{"jdk.internal.net.http.common.SSLFlowDelegate$Writer$WriterDownstreamPusher", "jdk.internal.net.http.common.SSLFlowDelegate$Writer", "WriterDownstreamPusher", 0},
	{"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask", "jdk.internal.net.http.common.SequentialScheduler", "CompleteRestartableTask", $PUBLIC | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SSLFlowDelegate$Writer$WriterDownstreamPusher_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.common.SSLFlowDelegate$Writer$WriterDownstreamPusher",
	"jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask",
	nullptr,
	_SSLFlowDelegate$Writer$WriterDownstreamPusher_FieldInfo_,
	_SSLFlowDelegate$Writer$WriterDownstreamPusher_MethodInfo_,
	nullptr,
	nullptr,
	_SSLFlowDelegate$Writer$WriterDownstreamPusher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SSLFlowDelegate"
};

$Object* allocate$SSLFlowDelegate$Writer$WriterDownstreamPusher($Class* clazz) {
	return $of($alloc(SSLFlowDelegate$Writer$WriterDownstreamPusher));
}

void SSLFlowDelegate$Writer$WriterDownstreamPusher::init$($SSLFlowDelegate$Writer* this$1) {
	$set(this, this$1, this$1);
	$SequentialScheduler$CompleteRestartableTask::init$();
}

void SSLFlowDelegate$Writer$WriterDownstreamPusher::run() {
	this->this$1->processData();
}

SSLFlowDelegate$Writer$WriterDownstreamPusher::SSLFlowDelegate$Writer$WriterDownstreamPusher() {
}

$Class* SSLFlowDelegate$Writer$WriterDownstreamPusher::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$Writer$WriterDownstreamPusher, name, initialize, &_SSLFlowDelegate$Writer$WriterDownstreamPusher_ClassInfo_, allocate$SSLFlowDelegate$Writer$WriterDownstreamPusher);
	return class$;
}

$Class* SSLFlowDelegate$Writer$WriterDownstreamPusher::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk