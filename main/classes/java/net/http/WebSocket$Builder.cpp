#include <java/net/http/WebSocket$Builder.h>

#include <java/net/URI.h>
#include <java/net/http/WebSocket$Listener.h>
#include <java/net/http/WebSocket.h>
#include <java/time/Duration.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URI = ::java::net::URI;
using $WebSocket = ::java::net::http::WebSocket;
using $WebSocket$Listener = ::java::net::http::WebSocket$Listener;
using $Duration = ::java::time::Duration;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;

namespace java {
	namespace net {
		namespace http {

$MethodInfo _WebSocket$Builder_MethodInfo_[] = {
	{"buildAsync", "(Ljava/net/URI;Ljava/net/http/WebSocket$Listener;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/net/URI;Ljava/net/http/WebSocket$Listener;)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/WebSocket;>;", $PUBLIC | $ABSTRACT},
	{"connectTimeout", "(Ljava/time/Duration;)Ljava/net/http/WebSocket$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"header", "(Ljava/lang/String;Ljava/lang/String;)Ljava/net/http/WebSocket$Builder;", nullptr, $PUBLIC | $ABSTRACT},
	{"subprotocols", "(Ljava/lang/String;[Ljava/lang/String;)Ljava/net/http/WebSocket$Builder;", nullptr, $PUBLIC | $TRANSIENT | $ABSTRACT},
	{}
};

$InnerClassInfo _WebSocket$Builder_InnerClassesInfo_[] = {
	{"java.net.http.WebSocket$Builder", "java.net.http.WebSocket", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _WebSocket$Builder_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.net.http.WebSocket$Builder",
	nullptr,
	nullptr,
	nullptr,
	_WebSocket$Builder_MethodInfo_,
	nullptr,
	nullptr,
	_WebSocket$Builder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.net.http.WebSocket"
};

$Object* allocate$WebSocket$Builder($Class* clazz) {
	return $of($alloc(WebSocket$Builder));
}

$Class* WebSocket$Builder::load$($String* name, bool initialize) {
	$loadClass(WebSocket$Builder, name, initialize, &_WebSocket$Builder_ClassInfo_, allocate$WebSocket$Builder);
	return class$;
}

$Class* WebSocket$Builder::class$ = nullptr;

		} // http
	} // net
} // java