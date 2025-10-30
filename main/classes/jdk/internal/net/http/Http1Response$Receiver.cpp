#include <jdk/internal/net/http/Http1Response$Receiver.h>

#include <java/nio/ByteBuffer.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <jdk/internal/net/http/Http1Response.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $Http1AsyncReceiver$Http1AsyncDelegate = ::jdk::internal::net::http::Http1AsyncReceiver$Http1AsyncDelegate;
using $Http1Response = ::jdk::internal::net::http::Http1Response;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$MethodInfo _Http1Response$Receiver_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(Http1Response$Receiver::*)()>(&Http1Response$Receiver::init$))},
	{"accept", "(Ljava/nio/ByteBuffer;Ljava/lang/Object;Ljava/util/concurrent/CompletableFuture;)Z", "(Ljava/nio/ByteBuffer;TT;Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Http1Response$State;>;)Z", $FINAL, $method(static_cast<bool(Http1Response$Receiver::*)($ByteBuffer*,Object$*,$CompletableFuture*)>(&Http1Response$Receiver::accept))},
	{"completion", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Http1Response$State;>;", $ABSTRACT},
	{"handle", "(Ljava/nio/ByteBuffer;Ljava/lang/Object;Ljava/util/concurrent/CompletableFuture;)V", "(Ljava/nio/ByteBuffer;TT;Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Http1Response$State;>;)V", $ABSTRACT},
	{"onReadError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"onSubscribe", "(Ljdk/internal/net/http/AbstractSubscription;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"reset", "()V", nullptr, $ABSTRACT},
	{"start", "(Ljava/lang/Object;)V", "(TT;)V", $ABSTRACT},
	{"tryAsyncReceive", "(Ljava/nio/ByteBuffer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"subscription", "()Ljdk/internal/net/http/AbstractSubscription;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _Http1Response$Receiver_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Response$Receiver", "jdk.internal.net.http.Http1Response", "Receiver", $STATIC | $ABSTRACT},
	{"jdk.internal.net.http.Http1AsyncReceiver$Http1AsyncDelegate", "jdk.internal.net.http.Http1AsyncReceiver", "Http1AsyncDelegate", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Http1Response$Receiver_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.Http1Response$Receiver",
	"java.lang.Object",
	"jdk.internal.net.http.Http1AsyncReceiver$Http1AsyncDelegate",
	nullptr,
	_Http1Response$Receiver_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegate;",
	nullptr,
	_Http1Response$Receiver_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Response"
};

$Object* allocate$Http1Response$Receiver($Class* clazz) {
	return $of($alloc(Http1Response$Receiver));
}

void Http1Response$Receiver::init$() {
}

bool Http1Response$Receiver::accept($ByteBuffer* buf, Object$* parser, $CompletableFuture* cf) {
	if (cf == nullptr || parser == nullptr || $nc(cf)->isDone()) {
		return false;
	}
	handle(buf, parser, cf);
	return !$nc(cf)->isDone();
}

Http1Response$Receiver::Http1Response$Receiver() {
}

$Class* Http1Response$Receiver::load$($String* name, bool initialize) {
	$loadClass(Http1Response$Receiver, name, initialize, &_Http1Response$Receiver_ClassInfo_, allocate$Http1Response$Receiver);
	return class$;
}

$Class* Http1Response$Receiver::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk