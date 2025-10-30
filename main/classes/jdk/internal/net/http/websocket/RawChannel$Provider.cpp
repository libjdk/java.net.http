#include <jdk/internal/net/http/websocket/RawChannel$Provider.h>

#include <jdk/internal/net/http/websocket/RawChannel.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RawChannel = ::jdk::internal::net::http::websocket::RawChannel;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$MethodInfo _RawChannel$Provider_MethodInfo_[] = {
	{"closeRawChannel", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"rawChannel", "()Ljdk/internal/net/http/websocket/RawChannel;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _RawChannel$Provider_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.RawChannel$Provider", "jdk.internal.net.http.websocket.RawChannel", "Provider", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RawChannel$Provider_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.websocket.RawChannel$Provider",
	nullptr,
	nullptr,
	nullptr,
	_RawChannel$Provider_MethodInfo_,
	nullptr,
	nullptr,
	_RawChannel$Provider_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.RawChannel"
};

$Object* allocate$RawChannel$Provider($Class* clazz) {
	return $of($alloc(RawChannel$Provider));
}

$Class* RawChannel$Provider::load$($String* name, bool initialize) {
	$loadClass(RawChannel$Provider, name, initialize, &_RawChannel$Provider_ClassInfo_, allocate$RawChannel$Provider);
	return class$;
}

$Class* RawChannel$Provider::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk