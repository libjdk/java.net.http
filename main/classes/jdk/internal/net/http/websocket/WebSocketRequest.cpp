#include <jdk/internal/net/http/websocket/WebSocketRequest.h>

#include <java/net/Proxy.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Proxy = ::java::net::Proxy;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$MethodInfo _WebSocketRequest_MethodInfo_[] = {
	{"isWebSocket", "(Z)V", nullptr, $PUBLIC | $ABSTRACT},
	{"setProxy", "(Ljava/net/Proxy;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"setSystemHeader", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _WebSocketRequest_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.websocket.WebSocketRequest",
	nullptr,
	nullptr,
	nullptr,
	_WebSocketRequest_MethodInfo_
};

$Object* allocate$WebSocketRequest($Class* clazz) {
	return $of($alloc(WebSocketRequest));
}

$Class* WebSocketRequest::load$($String* name, bool initialize) {
	$loadClass(WebSocketRequest, name, initialize, &_WebSocketRequest_ClassInfo_, allocate$WebSocketRequest);
	return class$;
}

$Class* WebSocketRequest::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk