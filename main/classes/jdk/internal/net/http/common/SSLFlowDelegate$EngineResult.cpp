#include <jdk/internal/net/http/common/SSLFlowDelegate$EngineResult.h>

#include <java/nio/ByteBuffer.h>
#include <javax/net/ssl/SSLEngineResult$HandshakeStatus.h>
#include <javax/net/ssl/SSLEngineResult$Status.h>
#include <javax/net/ssl/SSLEngineResult.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate.h>
#include <jcpp.h>

#undef CLOSED
#undef FINISHED
#undef NEED_UNWRAP
#undef NOT_HANDSHAKING

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $SSLEngineResult = ::javax::net::ssl::SSLEngineResult;
using $SSLEngineResult$HandshakeStatus = ::javax::net::ssl::SSLEngineResult$HandshakeStatus;
using $SSLEngineResult$Status = ::javax::net::ssl::SSLEngineResult$Status;
using $SSLFlowDelegate = ::jdk::internal::net::http::common::SSLFlowDelegate;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SSLFlowDelegate$EngineResult_FieldInfo_[] = {
	{"result", "Ljavax/net/ssl/SSLEngineResult;", nullptr, $FINAL, $field(SSLFlowDelegate$EngineResult, result)},
	{"destBuffer", "Ljava/nio/ByteBuffer;", nullptr, $FINAL, $field(SSLFlowDelegate$EngineResult, destBuffer)},
	{}
};

$MethodInfo _SSLFlowDelegate$EngineResult_MethodInfo_[] = {
	{"<init>", "(Ljavax/net/ssl/SSLEngineResult;)V", nullptr, 0, $method(static_cast<void(SSLFlowDelegate$EngineResult::*)($SSLEngineResult*)>(&SSLFlowDelegate$EngineResult::init$))},
	{"<init>", "(Ljavax/net/ssl/SSLEngineResult;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(static_cast<void(SSLFlowDelegate$EngineResult::*)($SSLEngineResult*,$ByteBuffer*)>(&SSLFlowDelegate$EngineResult::init$))},
	{"bytesConsumed", "()I", nullptr, 0},
	{"bytesProduced", "()I", nullptr, 0},
	{"handshakeStatus", "()Ljavax/net/ssl/SSLEngineResult$HandshakeStatus;", nullptr, 0},
	{"handshaking", "()Z", nullptr, 0},
	{"needUnwrap", "()Z", nullptr, 0},
	{"status", "()Ljavax/net/ssl/SSLEngineResult$Status;", nullptr, 0},
	{}
};

$InnerClassInfo _SSLFlowDelegate$EngineResult_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SSLFlowDelegate$EngineResult", "jdk.internal.net.http.common.SSLFlowDelegate", "EngineResult", $STATIC},
	{}
};

$ClassInfo _SSLFlowDelegate$EngineResult_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.common.SSLFlowDelegate$EngineResult",
	"java.lang.Object",
	nullptr,
	_SSLFlowDelegate$EngineResult_FieldInfo_,
	_SSLFlowDelegate$EngineResult_MethodInfo_,
	nullptr,
	nullptr,
	_SSLFlowDelegate$EngineResult_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SSLFlowDelegate"
};

$Object* allocate$SSLFlowDelegate$EngineResult($Class* clazz) {
	return $of($alloc(SSLFlowDelegate$EngineResult));
}

void SSLFlowDelegate$EngineResult::init$($SSLEngineResult* result) {
	SSLFlowDelegate$EngineResult::init$(result, nullptr);
}

void SSLFlowDelegate$EngineResult::init$($SSLEngineResult* result, $ByteBuffer* destBuffer) {
	$set(this, result, result);
	$set(this, destBuffer, destBuffer);
}

bool SSLFlowDelegate$EngineResult::handshaking() {
	$SSLEngineResult$HandshakeStatus* s = $nc(this->result)->getHandshakeStatus();
	$init($SSLEngineResult$HandshakeStatus);
	$init($SSLEngineResult$Status);
	return s != $SSLEngineResult$HandshakeStatus::FINISHED && s != $SSLEngineResult$HandshakeStatus::NOT_HANDSHAKING && $nc(this->result)->getStatus() != $SSLEngineResult$Status::CLOSED;
}

bool SSLFlowDelegate$EngineResult::needUnwrap() {
	$SSLEngineResult$HandshakeStatus* s = $nc(this->result)->getHandshakeStatus();
	$init($SSLEngineResult$HandshakeStatus);
	return s == $SSLEngineResult$HandshakeStatus::NEED_UNWRAP;
}

int32_t SSLFlowDelegate$EngineResult::bytesConsumed() {
	return $nc(this->result)->bytesConsumed();
}

int32_t SSLFlowDelegate$EngineResult::bytesProduced() {
	return $nc(this->result)->bytesProduced();
}

$SSLEngineResult$HandshakeStatus* SSLFlowDelegate$EngineResult::handshakeStatus() {
	return $nc(this->result)->getHandshakeStatus();
}

$SSLEngineResult$Status* SSLFlowDelegate$EngineResult::status() {
	return $nc(this->result)->getStatus();
}

SSLFlowDelegate$EngineResult::SSLFlowDelegate$EngineResult() {
}

$Class* SSLFlowDelegate$EngineResult::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$EngineResult, name, initialize, &_SSLFlowDelegate$EngineResult_ClassInfo_, allocate$SSLFlowDelegate$EngineResult);
	return class$;
}

$Class* SSLFlowDelegate$EngineResult::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk