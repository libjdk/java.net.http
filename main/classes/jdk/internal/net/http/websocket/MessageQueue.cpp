#include <jdk/internal/net/http/websocket/MessageQueue.h>

#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/atomic/AtomicInteger.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/websocket/MessageQueue$1.h>
#include <jdk/internal/net/http/websocket/MessageQueue$Message.h>
#include <jdk/internal/net/http/websocket/MessageQueue$QueueCallback.h>
#include <jdk/internal/net/http/websocket/MessageQueue$Type.h>
#include <jcpp.h>

#undef BINARY
#undef CLOSE
#undef PING
#undef PONG
#undef TEXT

using $MessageQueue$MessageArray = $Array<::jdk::internal::net::http::websocket::MessageQueue$Message>;
using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $AtomicInteger = ::java::util::concurrent::atomic::AtomicInteger;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Supplier = ::java::util::function::Supplier;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $MessageQueue$1 = ::jdk::internal::net::http::websocket::MessageQueue$1;
using $MessageQueue$Message = ::jdk::internal::net::http::websocket::MessageQueue$Message;
using $MessageQueue$QueueCallback = ::jdk::internal::net::http::websocket::MessageQueue$QueueCallback;
using $MessageQueue$Type = ::jdk::internal::net::http::websocket::MessageQueue$Type;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _MessageQueue_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(MessageQueue, $assertionsDisabled)},
	{"elements", "[Ljdk/internal/net/http/websocket/MessageQueue$Message;", nullptr, $PRIVATE | $FINAL, $field(MessageQueue, elements)},
	{"tail", "Ljava/util/concurrent/atomic/AtomicInteger;", nullptr, $PRIVATE | $FINAL, $field(MessageQueue, tail)},
	{"head", "I", nullptr, $PRIVATE | $VOLATILE, $field(MessageQueue, head)},
	{}
};

$MethodInfo _MessageQueue_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(MessageQueue::*)(int32_t)>(&MessageQueue::init$))},
	{"add", "(Ljdk/internal/net/http/websocket/MessageQueue$Type;Ljava/util/function/Supplier;Ljava/nio/ByteBuffer;Ljava/nio/CharBuffer;ZILjava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)V", "<T:Ljava/lang/Object;>(Ljdk/internal/net/http/websocket/MessageQueue$Type;Ljava/util/function/Supplier<+Ljava/nio/ByteBuffer;>;Ljava/nio/ByteBuffer;Ljava/nio/CharBuffer;ZITT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)V", $PRIVATE, $method(static_cast<void(MessageQueue::*)($MessageQueue$Type*,$Supplier*,$ByteBuffer*,$CharBuffer*,bool,int32_t,Object$*,$BiConsumer*,$CompletableFuture*)>(&MessageQueue::add)), "java.io.IOException"},
	{"addBinary", "(Ljava/nio/ByteBuffer;ZLjava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)V", "<T:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;ZTT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)V", $PUBLIC, nullptr, "java.io.IOException"},
	{"addClose", "(ILjava/nio/CharBuffer;Ljava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)V", "<T:Ljava/lang/Object;>(ILjava/nio/CharBuffer;TT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)V", $PUBLIC, nullptr, "java.io.IOException"},
	{"addPing", "(Ljava/nio/ByteBuffer;Ljava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)V", "<T:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;TT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)V", $PUBLIC, nullptr, "java.io.IOException"},
	{"addPong", "(Ljava/nio/ByteBuffer;Ljava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)V", "<T:Ljava/lang/Object;>(Ljava/nio/ByteBuffer;TT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)V", $PUBLIC, nullptr, "java.io.IOException"},
	{"addPong", "(Ljava/util/function/Supplier;Ljava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)V", "<T:Ljava/lang/Object;>(Ljava/util/function/Supplier<+Ljava/nio/ByteBuffer;>;TT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<-TT;>;)V", $PUBLIC, nullptr, "java.io.IOException"},
	{"addText", "(Ljava/nio/CharBuffer;ZLjava/lang/Object;Ljava/util/function/BiConsumer;Ljava/util/concurrent/CompletableFuture;)V", "<T:Ljava/lang/Object;>(Ljava/nio/CharBuffer;ZTT;Ljava/util/function/BiConsumer<-TT;-Ljava/lang/Throwable;>;Ljava/util/concurrent/CompletableFuture<TT;>;)V", $PUBLIC, nullptr, "java.io.IOException"},
	{"effectiveCapacityOf", "(I)I", nullptr, $PROTECTED | $STATIC, $method(static_cast<int32_t(*)(int32_t)>(&MessageQueue::effectiveCapacityOf))},
	{"isEmpty", "()Z", nullptr, $PUBLIC},
	{"peek", "(Ljdk/internal/net/http/websocket/MessageQueue$QueueCallback;)Ljava/lang/Object;", "<R:Ljava/lang/Object;E:Ljava/lang/Throwable;>(Ljdk/internal/net/http/websocket/MessageQueue$QueueCallback<TR;TE;>;)TR;^TE;", $PUBLIC, nullptr, "java.lang.Throwable"},
	{"remove", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _MessageQueue_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.MessageQueue$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"jdk.internal.net.http.websocket.MessageQueue$Message", "jdk.internal.net.http.websocket.MessageQueue", "Message", $PRIVATE | $STATIC},
	{"jdk.internal.net.http.websocket.MessageQueue$QueueCallback", "jdk.internal.net.http.websocket.MessageQueue", "QueueCallback", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.websocket.MessageQueue$Type", "jdk.internal.net.http.websocket.MessageQueue", "Type", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _MessageQueue_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.websocket.MessageQueue",
	"java.lang.Object",
	nullptr,
	_MessageQueue_FieldInfo_,
	_MessageQueue_MethodInfo_,
	nullptr,
	nullptr,
	_MessageQueue_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.MessageQueue$1,jdk.internal.net.http.websocket.MessageQueue$Message,jdk.internal.net.http.websocket.MessageQueue$QueueCallback,jdk.internal.net.http.websocket.MessageQueue$Type"
};

$Object* allocate$MessageQueue($Class* clazz) {
	return $of($alloc(MessageQueue));
}

bool MessageQueue::$assertionsDisabled = false;

void MessageQueue::init$(int32_t capacity) {
	$useLocalCurrentObjectStackCache();
	$set(this, tail, $new($AtomicInteger));
	if (capacity < 1) {
		$throwNew($IllegalArgumentException);
	}
	int32_t s = $Utils::pow2Size(capacity + 1);
	if (!MessageQueue::$assertionsDisabled && !(s % 2 == 0)) {
		$throwNew($AssertionError, s);
	}
	$var($MessageQueue$MessageArray, array, $new($MessageQueue$MessageArray, s));
	for (int32_t i = 0; i < array->length; ++i) {
		array->set(i, $$new($MessageQueue$Message));
	}
	$set(this, elements, array);
}

int32_t MessageQueue::effectiveCapacityOf(int32_t n) {
	$init(MessageQueue);
	return $Utils::pow2Size(n + 1) - 1;
}

void MessageQueue::addText($CharBuffer* message, bool isLast, Object$* attachment, $BiConsumer* action, $CompletableFuture* future) {
	$init($MessageQueue$Type);
	add($MessageQueue$Type::TEXT, nullptr, nullptr, message, isLast, -1, attachment, action, future);
}

void MessageQueue::add($MessageQueue$Type* type, $Supplier* binarySupplier, $ByteBuffer* binary, $CharBuffer* text, bool isLast, int32_t statusCode, Object$* attachment, $BiConsumer* action, $CompletableFuture* future) {
	$init($MessageQueue$Type);
	if (!MessageQueue::$assertionsDisabled && !(type != $MessageQueue$Type::PONG || ((binary == nullptr) ^ (binarySupplier == nullptr)))) {
		$throwNew($AssertionError);
	}
	int32_t h = 0;
	int32_t currentTail = 0;
	int32_t newTail = 0;
	do {
		h = this->head;
		currentTail = $nc(this->tail)->get();
		newTail = (int32_t)((currentTail + 1) & (uint32_t)($nc(this->elements)->length - 1));
		if (newTail == h) {
			$throwNew($IOException, "Queue full"_s);
		}
	} while (!$nc(this->tail)->compareAndSet(currentTail, newTail));
	$var($MessageQueue$Message, t, $nc(this->elements)->get(currentTail));
	if ($nc(t)->ready) {
		$throwNew($InternalError);
	}
	$set($nc(t), type, type);
	$set(t, binarySupplier, binarySupplier);
	$set(t, binary, binary);
	$set(t, text, text);
	t->isLast = isLast;
	t->statusCode = statusCode;
	$set(t, attachment, attachment);
	$set(t, action, action);
	$set(t, future, future);
	t->ready = true;
}

void MessageQueue::addBinary($ByteBuffer* message, bool isLast, Object$* attachment, $BiConsumer* action, $CompletableFuture* future) {
	$init($MessageQueue$Type);
	add($MessageQueue$Type::BINARY, nullptr, message, nullptr, isLast, -1, attachment, action, future);
}

void MessageQueue::addPing($ByteBuffer* message, Object$* attachment, $BiConsumer* action, $CompletableFuture* future) {
	$init($MessageQueue$Type);
	add($MessageQueue$Type::PING, nullptr, message, nullptr, false, -1, attachment, action, future);
}

void MessageQueue::addPong($ByteBuffer* message, Object$* attachment, $BiConsumer* action, $CompletableFuture* future) {
	$init($MessageQueue$Type);
	add($MessageQueue$Type::PONG, nullptr, message, nullptr, false, -1, attachment, action, future);
}

void MessageQueue::addPong($Supplier* message, Object$* attachment, $BiConsumer* action, $CompletableFuture* future) {
	$init($MessageQueue$Type);
	add($MessageQueue$Type::PONG, message, nullptr, nullptr, false, -1, attachment, action, future);
}

void MessageQueue::addClose(int32_t statusCode, $CharBuffer* reason, Object$* attachment, $BiConsumer* action, $CompletableFuture* future) {
	$init($MessageQueue$Type);
	add($MessageQueue$Type::CLOSE, nullptr, nullptr, reason, false, statusCode, attachment, action, future);
}

$Object* MessageQueue::peek($MessageQueue$QueueCallback* callback) {
	$useLocalCurrentObjectStackCache();
	$var($MessageQueue$Message, h, $nc(this->elements)->get(this->head));
	if (!$nc(h)->ready) {
		return $of($nc(callback)->onEmpty());
	}
	$MessageQueue$Type* type = $nc(h)->type;
	$init($MessageQueue$1);
	switch ($nc($MessageQueue$1::$SwitchMap$jdk$internal$net$http$websocket$MessageQueue$Type)->get($nc((type))->ordinal())) {
	case 1:
		{
			try {
				return $of($nc(callback)->onText(h->text, h->isLast, h->attachment, h->action, h->future));
			} catch ($Throwable& t) {
				$throw(t);
			}
		}
	case 2:
		{
			try {
				return $of($nc(callback)->onBinary(h->binary, h->isLast, h->attachment, h->action, h->future));
			} catch ($Throwable& t) {
				$throw(t);
			}
		}
	case 3:
		{
			try {
				return $of($nc(callback)->onPing(h->binary, h->attachment, h->action, h->future));
			} catch ($Throwable& t) {
				$throw(t);
			}
		}
	case 4:
		{
			try {
				if (h->binarySupplier != nullptr) {
					return $of($nc(callback)->onPong(h->binarySupplier, h->attachment, h->action, h->future));
				} else {
					return $of($nc(callback)->onPong(h->binary, h->attachment, h->action, h->future));
				}
			} catch ($Throwable& t) {
				$throw(t);
			}
		}
	case 5:
		{
			try {
				return $of($nc(callback)->onClose(h->statusCode, h->text, h->attachment, h->action, h->future));
			} catch ($Throwable& t) {
				$throw(t);
			}
		}
	default:
		{
			$throwNew($InternalError, $($String::valueOf($of(type))));
		}
	}
	$shouldNotReachHere();
}

bool MessageQueue::isEmpty() {
	return !$nc($nc(this->elements)->get(this->head))->ready;
}

void MessageQueue::remove() {
	int32_t currentHead = this->head;
	$var($MessageQueue$Message, h, $nc(this->elements)->get(currentHead));
	if (!$nc(h)->ready) {
		$throwNew($InternalError, "Queue empty"_s);
	}
	$set($nc(h), type, nullptr);
	$set(h, binarySupplier, nullptr);
	$set(h, binary, nullptr);
	$set(h, text, nullptr);
	$set(h, attachment, nullptr);
	$set(h, action, nullptr);
	$set(h, future, nullptr);
	h->ready = false;
	this->head = (int32_t)((currentHead + 1) & (uint32_t)($nc(this->elements)->length - 1));
}

void clinit$MessageQueue($Class* class$) {
	MessageQueue::$assertionsDisabled = !MessageQueue::class$->desiredAssertionStatus();
}

MessageQueue::MessageQueue() {
}

$Class* MessageQueue::load$($String* name, bool initialize) {
	$loadClass(MessageQueue, name, initialize, &_MessageQueue_ClassInfo_, clinit$MessageQueue, allocate$MessageQueue);
	return class$;
}

$Class* MessageQueue::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk