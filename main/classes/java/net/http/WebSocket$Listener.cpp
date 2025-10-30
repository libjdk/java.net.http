#include <java/net/http/WebSocket$Listener.h>

#include <java/lang/CharSequence.h>
#include <java/net/http/WebSocket.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/concurrent/CompletionStage.h>
#include <jcpp.h>

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $WebSocket = ::java::net::http::WebSocket;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CompletionStage = ::java::util::concurrent::CompletionStage;

namespace java {
	namespace net {
		namespace http {

$MethodInfo _WebSocket$Listener_MethodInfo_[] = {
	{"onBinary", "(Ljava/net/http/WebSocket;Ljava/nio/ByteBuffer;Z)Ljava/util/concurrent/CompletionStage;", "(Ljava/net/http/WebSocket;Ljava/nio/ByteBuffer;Z)Ljava/util/concurrent/CompletionStage<*>;", $PUBLIC},
	{"onClose", "(Ljava/net/http/WebSocket;ILjava/lang/String;)Ljava/util/concurrent/CompletionStage;", "(Ljava/net/http/WebSocket;ILjava/lang/String;)Ljava/util/concurrent/CompletionStage<*>;", $PUBLIC},
	{"onError", "(Ljava/net/http/WebSocket;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onOpen", "(Ljava/net/http/WebSocket;)V", nullptr, $PUBLIC},
	{"onPing", "(Ljava/net/http/WebSocket;Ljava/nio/ByteBuffer;)Ljava/util/concurrent/CompletionStage;", "(Ljava/net/http/WebSocket;Ljava/nio/ByteBuffer;)Ljava/util/concurrent/CompletionStage<*>;", $PUBLIC},
	{"onPong", "(Ljava/net/http/WebSocket;Ljava/nio/ByteBuffer;)Ljava/util/concurrent/CompletionStage;", "(Ljava/net/http/WebSocket;Ljava/nio/ByteBuffer;)Ljava/util/concurrent/CompletionStage<*>;", $PUBLIC},
	{"onText", "(Ljava/net/http/WebSocket;Ljava/lang/CharSequence;Z)Ljava/util/concurrent/CompletionStage;", "(Ljava/net/http/WebSocket;Ljava/lang/CharSequence;Z)Ljava/util/concurrent/CompletionStage<*>;", $PUBLIC},
	{}
};

$InnerClassInfo _WebSocket$Listener_InnerClassesInfo_[] = {
	{"java.net.http.WebSocket$Listener", "java.net.http.WebSocket", "Listener", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _WebSocket$Listener_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.net.http.WebSocket$Listener",
	nullptr,
	nullptr,
	nullptr,
	_WebSocket$Listener_MethodInfo_,
	nullptr,
	nullptr,
	_WebSocket$Listener_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.net.http.WebSocket"
};

$Object* allocate$WebSocket$Listener($Class* clazz) {
	return $of($alloc(WebSocket$Listener));
}

void WebSocket$Listener::onOpen($WebSocket* webSocket) {
	$nc(webSocket)->request(1);
}

$CompletionStage* WebSocket$Listener::onText($WebSocket* webSocket, $CharSequence* data, bool last) {
	$nc(webSocket)->request(1);
	return nullptr;
}

$CompletionStage* WebSocket$Listener::onBinary($WebSocket* webSocket, $ByteBuffer* data, bool last) {
	$nc(webSocket)->request(1);
	return nullptr;
}

$CompletionStage* WebSocket$Listener::onPing($WebSocket* webSocket, $ByteBuffer* message) {
	$nc(webSocket)->request(1);
	return nullptr;
}

$CompletionStage* WebSocket$Listener::onPong($WebSocket* webSocket, $ByteBuffer* message) {
	$nc(webSocket)->request(1);
	return nullptr;
}

$CompletionStage* WebSocket$Listener::onClose($WebSocket* webSocket, int32_t statusCode, $String* reason) {
	return nullptr;
}

void WebSocket$Listener::onError($WebSocket* webSocket, $Throwable* error) {
}

$Class* WebSocket$Listener::load$($String* name, bool initialize) {
	$loadClass(WebSocket$Listener, name, initialize, &_WebSocket$Listener_ClassInfo_, allocate$WebSocket$Listener);
	return class$;
}

$Class* WebSocket$Listener::class$ = nullptr;

		} // http
	} // net
} // java