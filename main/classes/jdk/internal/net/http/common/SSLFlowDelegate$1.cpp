#include <jdk/internal/net/http/common/SSLFlowDelegate$1.h>

#include <java/lang/NoSuchFieldError.h>
#include <javax/net/ssl/SSLEngineResult$HandshakeStatus.h>
#include <javax/net/ssl/SSLEngineResult$Status.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate.h>
#include <jcpp.h>

#undef BUFFER_OVERFLOW
#undef BUFFER_UNDERFLOW
#undef CLOSED
#undef NEED_TASK
#undef NEED_UNWRAP
#undef NEED_UNWRAP_AGAIN
#undef NEED_WRAP
#undef OK

using $SSLEngineResult$HandshakeStatusArray = $Array<::javax::net::ssl::SSLEngineResult$HandshakeStatus>;
using $SSLEngineResult$StatusArray = $Array<::javax::net::ssl::SSLEngineResult$Status>;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $NoSuchFieldError = ::java::lang::NoSuchFieldError;
using $SSLEngineResult$HandshakeStatus = ::javax::net::ssl::SSLEngineResult$HandshakeStatus;
using $SSLEngineResult$Status = ::javax::net::ssl::SSLEngineResult$Status;
using $SSLFlowDelegate = ::jdk::internal::net::http::common::SSLFlowDelegate;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SSLFlowDelegate$1_FieldInfo_[] = {
	{"$SwitchMap$javax$net$ssl$SSLEngineResult$HandshakeStatus", "[I", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SSLFlowDelegate$1, $SwitchMap$javax$net$ssl$SSLEngineResult$HandshakeStatus)},
	{"$SwitchMap$javax$net$ssl$SSLEngineResult$Status", "[I", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SSLFlowDelegate$1, $SwitchMap$javax$net$ssl$SSLEngineResult$Status)},
	{}
};

$EnclosingMethodInfo _SSLFlowDelegate$1_EnclosingMethodInfo_ = {
	"jdk.internal.net.http.common.SSLFlowDelegate",
	nullptr,
	nullptr
};

$InnerClassInfo _SSLFlowDelegate$1_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SSLFlowDelegate$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _SSLFlowDelegate$1_ClassInfo_ = {
	$ACC_SUPER | $SYNTHETIC,
	"jdk.internal.net.http.common.SSLFlowDelegate$1",
	"java.lang.Object",
	nullptr,
	_SSLFlowDelegate$1_FieldInfo_,
	nullptr,
	nullptr,
	&_SSLFlowDelegate$1_EnclosingMethodInfo_,
	_SSLFlowDelegate$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SSLFlowDelegate"
};

$Object* allocate$SSLFlowDelegate$1($Class* clazz) {
	return $of($alloc(SSLFlowDelegate$1));
}

$ints* SSLFlowDelegate$1::$SwitchMap$javax$net$ssl$SSLEngineResult$HandshakeStatus = nullptr;
$ints* SSLFlowDelegate$1::$SwitchMap$javax$net$ssl$SSLEngineResult$Status = nullptr;

void clinit$SSLFlowDelegate$1($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(SSLFlowDelegate$1::$SwitchMap$javax$net$ssl$SSLEngineResult$HandshakeStatus, $new($ints, $($SSLEngineResult$HandshakeStatus::values())->length));
	{
		try {
			$nc(SSLFlowDelegate$1::$SwitchMap$javax$net$ssl$SSLEngineResult$HandshakeStatus)->set($SSLEngineResult$HandshakeStatus::NEED_TASK->ordinal(), 1);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(SSLFlowDelegate$1::$SwitchMap$javax$net$ssl$SSLEngineResult$HandshakeStatus)->set($SSLEngineResult$HandshakeStatus::NEED_WRAP->ordinal(), 2);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(SSLFlowDelegate$1::$SwitchMap$javax$net$ssl$SSLEngineResult$HandshakeStatus)->set($SSLEngineResult$HandshakeStatus::NEED_UNWRAP->ordinal(), 3);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(SSLFlowDelegate$1::$SwitchMap$javax$net$ssl$SSLEngineResult$HandshakeStatus)->set($SSLEngineResult$HandshakeStatus::NEED_UNWRAP_AGAIN->ordinal(), 4);
		} catch ($NoSuchFieldError& ex) {
		}
	}
	$assignStatic(SSLFlowDelegate$1::$SwitchMap$javax$net$ssl$SSLEngineResult$Status, $new($ints, $($SSLEngineResult$Status::values())->length));
	{
		try {
			$nc(SSLFlowDelegate$1::$SwitchMap$javax$net$ssl$SSLEngineResult$Status)->set($SSLEngineResult$Status::BUFFER_OVERFLOW->ordinal(), 1);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(SSLFlowDelegate$1::$SwitchMap$javax$net$ssl$SSLEngineResult$Status)->set($SSLEngineResult$Status::CLOSED->ordinal(), 2);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(SSLFlowDelegate$1::$SwitchMap$javax$net$ssl$SSLEngineResult$Status)->set($SSLEngineResult$Status::BUFFER_UNDERFLOW->ordinal(), 3);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(SSLFlowDelegate$1::$SwitchMap$javax$net$ssl$SSLEngineResult$Status)->set($SSLEngineResult$Status::OK->ordinal(), 4);
		} catch ($NoSuchFieldError& ex) {
		}
	}
}

SSLFlowDelegate$1::SSLFlowDelegate$1() {
}

$Class* SSLFlowDelegate$1::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$1, name, initialize, &_SSLFlowDelegate$1_ClassInfo_, clinit$SSLFlowDelegate$1, allocate$SSLFlowDelegate$1);
	return class$;
}

$Class* SSLFlowDelegate$1::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk