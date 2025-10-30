#include <jdk/internal/net/http/websocket/MessageQueue$QueueCallback.h>

#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/websocket/MessageQueue.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Supplier = ::java::util::function::Supplier;
using $MessageQueue = ::jdk::internal::net::http::websocket::MessageQueue;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$MethodInfo _MessageQueue$QueueCallback_MethodInfo_[] = {
	{"onBinary", "(Ljava/nio/ByteBuffer;ZLjava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;ZTT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)TR;^TE;", $PUBLIC | $ABSTRACT, nullptr, "java.lang.Throwable"},
	{"onClose", "(ILjava/nio/CharBuffer;Ljava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(ILjava/nio/CharBuffer;TT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)TR;^TE;", $PUBLIC | $ABSTRACT, nullptr, "java.lang.Throwable"},
	{"onEmpty", "()Ljava/lang/Object;", "()TR;^TE;", $PUBLIC | $ABSTRACT, nullptr, "java.lang.Throwable"},
	{"onPing", "(Ljava/nio/ByteBuffer;Ljava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;TT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)TR;^TE;", $PUBLIC | $ABSTRACT, nullptr, "java.lang.Throwable"},
	{"onPong", "(Ljava/nio/ByteBuffer;Ljava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;TT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)TR;^TE;", $PUBLIC | $ABSTRACT, nullptr, "java.lang.Throwable"},
	{"onPong", "(Ljava/util/function/Supplier;Ljava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/util/function/Supplier<+Ljava/nio/ByteBuffer;>;TT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)TR;^TE;", $PUBLIC | $ABSTRACT, nullptr, "java.lang.Throwable"},
	{"onText", "(Ljava/nio/CharBuffer;ZLjava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/nio/CharBuffer;ZTT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)TR;^TE;", $PUBLIC | $ABSTRACT, nullptr, "java.lang.Throwable"},
	{}
};

$InnerClassInfo _MessageQueue$QueueCallback_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.MessageQueue$QueueCallback", "jdk.internal.net.http.websocket.MessageQueue", "QueueCallback", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _MessageQueue$QueueCallback_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.websocket.MessageQueue$QueueCallback",
	nullptr,
	nullptr,
	nullptr,
	_MessageQueue$QueueCallback_MethodInfo_,
	"<R:Ljava/lang/Object;E:Ljava/lang/Throwable;>Ljava/lang/Object;",
	nullptr,
	_MessageQueue$QueueCallback_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.MessageQueue"
};

$Object* allocate$MessageQueue$QueueCallback($Class* clazz) {
	return $of($alloc(MessageQueue$QueueCallback));
}

$Class* MessageQueue$QueueCallback::load$($String* name, bool initialize) {
	$loadClass(MessageQueue$QueueCallback, name, initialize, &_MessageQueue$QueueCallback_ClassInfo_, allocate$MessageQueue$QueueCallback);
	return class$;
}

$Class* MessageQueue$QueueCallback::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk