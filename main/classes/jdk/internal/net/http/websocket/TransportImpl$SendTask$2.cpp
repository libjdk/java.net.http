#include <jdk/internal/net/http/websocket/TransportImpl$SendTask$2.h>

#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/websocket/TransportImpl$SendTask.h>
#include <jcpp.h>

using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Supplier = ::java::util::function::Supplier;
using $MessageQueue$QueueCallback = ::jdk::internal::net::http::websocket::MessageQueue$QueueCallback;
using $TransportImpl$SendTask = ::jdk::internal::net::http::websocket::TransportImpl$SendTask;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _TransportImpl$SendTask$2_FieldInfo_[] = {
	{"this$1", "Ljdk/internal/net/http/websocket/TransportImpl$SendTask;", nullptr, $FINAL | $SYNTHETIC, $field(TransportImpl$SendTask$2, this$1)},
	{}
};

$MethodInfo _TransportImpl$SendTask$2_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/websocket/TransportImpl$SendTask;)V", nullptr, 0, $method(static_cast<void(TransportImpl$SendTask$2::*)($TransportImpl$SendTask*)>(&TransportImpl$SendTask$2::init$))},
	{"onBinary", "(Ljava/nio/ByteBuffer;ZLjava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)Ljava/lang/Boolean;", "<T:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;ZTT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)Ljava/lang/Boolean;", $PUBLIC},
	{"onClose", "(ILjava/nio/CharBuffer;Ljava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)Ljava/lang/Boolean;", "<T:Ljava/lang/Object;>(ILjava/nio/CharBuffer;TT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)Ljava/lang/Boolean;", $PUBLIC},
	{"onEmpty", "()Ljava/lang/Boolean;", nullptr, $PUBLIC},
	{"onPing", "(Ljava/nio/ByteBuffer;Ljava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)Ljava/lang/Boolean;", "<T:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;TT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)Ljava/lang/Boolean;", $PUBLIC},
	{"onPong", "(Ljava/nio/ByteBuffer;Ljava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)Ljava/lang/Boolean;", "<T:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;TT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)Ljava/lang/Boolean;", $PUBLIC},
	{"onPong", "(Ljava/util/function/Supplier;Ljava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)Ljava/lang/Boolean;", "<T:Ljava/lang/Object;>(Ljava/util/function/Supplier<+Ljava/nio/ByteBuffer;>;TT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)Ljava/lang/Boolean;", $PUBLIC},
	{"onText", "(Ljava/nio/CharBuffer;ZLjava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)Ljava/lang/Boolean;", "<T:Ljava/lang/Object;>(Ljava/nio/CharBuffer;ZTT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)Ljava/lang/Boolean;", $PUBLIC},
	{}
};

$EnclosingMethodInfo _TransportImpl$SendTask$2_EnclosingMethodInfo_ = {
	"jdk.internal.net.http.websocket.TransportImpl$SendTask",
	nullptr,
	nullptr
};

$InnerClassInfo _TransportImpl$SendTask$2_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.TransportImpl$SendTask", "jdk.internal.net.http.websocket.TransportImpl", "SendTask", $PRIVATE},
	{"jdk.internal.net.http.websocket.TransportImpl$SendTask$2", nullptr, nullptr, 0},
	{"jdk.internal.net.http.websocket.MessageQueue$QueueCallback", "jdk.internal.net.http.websocket.MessageQueue", "QueueCallback", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _TransportImpl$SendTask$2_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.websocket.TransportImpl$SendTask$2",
	"java.lang.Object",
	"jdk.internal.net.http.websocket.MessageQueue$QueueCallback",
	_TransportImpl$SendTask$2_FieldInfo_,
	_TransportImpl$SendTask$2_MethodInfo_,
	"Ljava/lang/Object;Ljdk/internal/net/http/websocket/MessageQueue$QueueCallback<Ljava/lang/Boolean;Ljava/lang/RuntimeException;>;",
	&_TransportImpl$SendTask$2_EnclosingMethodInfo_,
	_TransportImpl$SendTask$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.TransportImpl"
};

$Object* allocate$TransportImpl$SendTask$2($Class* clazz) {
	return $of($alloc(TransportImpl$SendTask$2));
}

void TransportImpl$SendTask$2::init$($TransportImpl$SendTask* this$1) {
	$set(this, this$1, this$1);
}

$Object* TransportImpl$SendTask$2::onText($CharBuffer* message, bool isLast, Object$* attachment, $BiConsumer* action, $CompletableFuture* future) {
	$set(this->this$1, attachment, attachment);
	$set(this->this$1, action, action);
	$set(this->this$1, future, future);
	return $of($Boolean::valueOf(true));
}

$Object* TransportImpl$SendTask$2::onBinary($ByteBuffer* message, bool isLast, Object$* attachment, $BiConsumer* action, $CompletableFuture* future) {
	$set(this->this$1, attachment, attachment);
	$set(this->this$1, action, action);
	$set(this->this$1, future, future);
	return $of($Boolean::valueOf(true));
}

$Object* TransportImpl$SendTask$2::onPing($ByteBuffer* message, Object$* attachment, $BiConsumer* action, $CompletableFuture* future) {
	$set(this->this$1, attachment, attachment);
	$set(this->this$1, action, action);
	$set(this->this$1, future, future);
	return $of($Boolean::valueOf(true));
}

$Object* TransportImpl$SendTask$2::onPong($ByteBuffer* message, Object$* attachment, $BiConsumer* action, $CompletableFuture* future) {
	$set(this->this$1, attachment, attachment);
	$set(this->this$1, action, action);
	$set(this->this$1, future, future);
	return $of($Boolean::valueOf(true));
}

$Object* TransportImpl$SendTask$2::onPong($Supplier* message, Object$* attachment, $BiConsumer* action, $CompletableFuture* future) {
	$set(this->this$1, attachment, attachment);
	$set(this->this$1, action, action);
	$set(this->this$1, future, future);
	return $of($Boolean::valueOf(true));
}

$Object* TransportImpl$SendTask$2::onClose(int32_t statusCode, $CharBuffer* reason, Object$* attachment, $BiConsumer* action, $CompletableFuture* future) {
	$set(this->this$1, attachment, attachment);
	$set(this->this$1, action, action);
	$set(this->this$1, future, future);
	return $of($Boolean::valueOf(true));
}

$Object* TransportImpl$SendTask$2::onEmpty() {
	return $of($Boolean::valueOf(false));
}

TransportImpl$SendTask$2::TransportImpl$SendTask$2() {
}

$Class* TransportImpl$SendTask$2::load$($String* name, bool initialize) {
	$loadClass(TransportImpl$SendTask$2, name, initialize, &_TransportImpl$SendTask$2_ClassInfo_, allocate$TransportImpl$SendTask$2);
	return class$;
}

$Class* TransportImpl$SendTask$2::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk