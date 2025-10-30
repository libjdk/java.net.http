#include <java/net/http/WebSocket.h>

#include <java/nio/ByteBuffer.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <jcpp.h>

#undef NORMAL_CLOSURE

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;

namespace java {
	namespace net {
		namespace http {

$FieldInfo _WebSocket_FieldInfo_[] = {
	{"NORMAL_CLOSURE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(WebSocket, NORMAL_CLOSURE)},
	{}
};

$MethodInfo _WebSocket_MethodInfo_[] = {
	{"abort", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{"getSubprotocol", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{"isInputClosed", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"isOutputClosed", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"request", "(J)V", nullptr, $PUBLIC | $ABSTRACT},
	{"sendBinary", "(Ljava/nio/ByteBuffer;Z)Ljava/util/concurrent/CompletableFuture;", "(Ljava/nio/ByteBuffer;Z)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/WebSocket;>;", $PUBLIC | $ABSTRACT},
	{"sendClose", "(ILjava/lang/String;)Ljava/util/concurrent/CompletableFuture;", "(ILjava/lang/String;)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/WebSocket;>;", $PUBLIC | $ABSTRACT},
	{"sendPing", "(Ljava/nio/ByteBuffer;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/nio/ByteBuffer;)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/WebSocket;>;", $PUBLIC | $ABSTRACT},
	{"sendPong", "(Ljava/nio/ByteBuffer;)Ljava/util/concurrent/CompletableFuture;", "(Ljava/nio/ByteBuffer;)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/WebSocket;>;", $PUBLIC | $ABSTRACT},
	{"sendText", "(Ljava/lang/CharSequence;Z)Ljava/util/concurrent/CompletableFuture;", "(Ljava/lang/CharSequence;Z)Ljava/util/concurrent/CompletableFuture<Ljava/net/http/WebSocket;>;", $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _WebSocket_InnerClassesInfo_[] = {
	{"java.net.http.WebSocket$Listener", "java.net.http.WebSocket", "Listener", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.net.http.WebSocket$Builder", "java.net.http.WebSocket", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _WebSocket_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.net.http.WebSocket",
	nullptr,
	nullptr,
	_WebSocket_FieldInfo_,
	_WebSocket_MethodInfo_,
	nullptr,
	nullptr,
	_WebSocket_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.net.http.WebSocket$Listener,java.net.http.WebSocket$Builder"
};

$Object* allocate$WebSocket($Class* clazz) {
	return $of($alloc(WebSocket));
}

$Class* WebSocket::load$($String* name, bool initialize) {
	$loadClass(WebSocket, name, initialize, &_WebSocket_ClassInfo_, allocate$WebSocket);
	return class$;
}

$Class* WebSocket::class$ = nullptr;

		} // http
	} // net
} // java