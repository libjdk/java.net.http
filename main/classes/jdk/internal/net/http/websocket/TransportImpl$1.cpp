#include <jdk/internal/net/http/websocket/TransportImpl$1.h>

#include <java/lang/NoSuchFieldError.h>
#include <jdk/internal/net/http/websocket/TransportImpl$ChannelState.h>
#include <jdk/internal/net/http/websocket/TransportImpl.h>
#include <jcpp.h>

#undef AVAILABLE
#undef CLOSED
#undef UNREGISTERED
#undef WAITING

using $TransportImpl$ChannelStateArray = $Array<::jdk::internal::net::http::websocket::TransportImpl$ChannelState>;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $NoSuchFieldError = ::java::lang::NoSuchFieldError;
using $TransportImpl = ::jdk::internal::net::http::websocket::TransportImpl;
using $TransportImpl$ChannelState = ::jdk::internal::net::http::websocket::TransportImpl$ChannelState;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _TransportImpl$1_FieldInfo_[] = {
	{"$SwitchMap$jdk$internal$net$http$websocket$TransportImpl$ChannelState", "[I", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(TransportImpl$1, $SwitchMap$jdk$internal$net$http$websocket$TransportImpl$ChannelState)},
	{}
};

$EnclosingMethodInfo _TransportImpl$1_EnclosingMethodInfo_ = {
	"jdk.internal.net.http.websocket.TransportImpl",
	nullptr,
	nullptr
};

$InnerClassInfo _TransportImpl$1_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.TransportImpl$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _TransportImpl$1_ClassInfo_ = {
	$ACC_SUPER | $SYNTHETIC,
	"jdk.internal.net.http.websocket.TransportImpl$1",
	"java.lang.Object",
	nullptr,
	_TransportImpl$1_FieldInfo_,
	nullptr,
	nullptr,
	&_TransportImpl$1_EnclosingMethodInfo_,
	_TransportImpl$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.TransportImpl"
};

$Object* allocate$TransportImpl$1($Class* clazz) {
	return $of($alloc(TransportImpl$1));
}

$ints* TransportImpl$1::$SwitchMap$jdk$internal$net$http$websocket$TransportImpl$ChannelState = nullptr;

void clinit$TransportImpl$1($Class* class$) {
	$assignStatic(TransportImpl$1::$SwitchMap$jdk$internal$net$http$websocket$TransportImpl$ChannelState, $new($ints, $($TransportImpl$ChannelState::values())->length));
	{
		try {
			$nc(TransportImpl$1::$SwitchMap$jdk$internal$net$http$websocket$TransportImpl$ChannelState)->set($TransportImpl$ChannelState::WAITING->ordinal(), 1);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(TransportImpl$1::$SwitchMap$jdk$internal$net$http$websocket$TransportImpl$ChannelState)->set($TransportImpl$ChannelState::UNREGISTERED->ordinal(), 2);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(TransportImpl$1::$SwitchMap$jdk$internal$net$http$websocket$TransportImpl$ChannelState)->set($TransportImpl$ChannelState::AVAILABLE->ordinal(), 3);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(TransportImpl$1::$SwitchMap$jdk$internal$net$http$websocket$TransportImpl$ChannelState)->set($TransportImpl$ChannelState::CLOSED->ordinal(), 4);
		} catch ($NoSuchFieldError& ex) {
		}
	}
}

TransportImpl$1::TransportImpl$1() {
}

$Class* TransportImpl$1::load$($String* name, bool initialize) {
	$loadClass(TransportImpl$1, name, initialize, &_TransportImpl$1_ClassInfo_, clinit$TransportImpl$1, allocate$TransportImpl$1);
	return class$;
}

$Class* TransportImpl$1::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk