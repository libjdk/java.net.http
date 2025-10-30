#include <jdk/internal/net/http/websocket/MessageQueue$Message.h>

#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/websocket/MessageQueue$Type.h>
#include <jdk/internal/net/http/websocket/MessageQueue.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Supplier = ::java::util::function::Supplier;
using $MessageQueue = ::jdk::internal::net::http::websocket::MessageQueue;
using $MessageQueue$Type = ::jdk::internal::net::http::websocket::MessageQueue$Type;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _MessageQueue$Message_FieldInfo_[] = {
	{"ready", "Z", nullptr, $PRIVATE | $VOLATILE, $field(MessageQueue$Message, ready)},
	{"type", "Ljdk/internal/net/http/websocket/MessageQueue$Type;", nullptr, $PRIVATE, $field(MessageQueue$Message, type)},
	{"binarySupplier", "Ljava/util/function/Supplier;", "Ljava/util/function/Supplier<+Ljava/nio/ByteBuffer;>;", $PRIVATE, $field(MessageQueue$Message, binarySupplier)},
	{"binary", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $field(MessageQueue$Message, binary)},
	{"text", "Ljava/nio/CharBuffer;", nullptr, $PRIVATE, $field(MessageQueue$Message, text)},
	{"isLast", "Z", nullptr, $PRIVATE, $field(MessageQueue$Message, isLast)},
	{"statusCode", "I", nullptr, $PRIVATE, $field(MessageQueue$Message, statusCode)},
	{"attachment", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(MessageQueue$Message, attachment)},
	{"action", "Ljava/util/function/BiConsumer;", nullptr, $PRIVATE, $field(MessageQueue$Message, action)},
	{"future", "Ljava/util/concurrent/CompletableFuture;", nullptr, $PRIVATE, $field(MessageQueue$Message, future)},
	{}
};

$MethodInfo _MessageQueue$Message_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(MessageQueue$Message::*)()>(&MessageQueue$Message::init$))},
	{}
};

$InnerClassInfo _MessageQueue$Message_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.MessageQueue$Message", "jdk.internal.net.http.websocket.MessageQueue", "Message", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _MessageQueue$Message_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.websocket.MessageQueue$Message",
	"java.lang.Object",
	nullptr,
	_MessageQueue$Message_FieldInfo_,
	_MessageQueue$Message_MethodInfo_,
	nullptr,
	nullptr,
	_MessageQueue$Message_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.MessageQueue"
};

$Object* allocate$MessageQueue$Message($Class* clazz) {
	return $of($alloc(MessageQueue$Message));
}

void MessageQueue$Message::init$() {
}

MessageQueue$Message::MessageQueue$Message() {
}

$Class* MessageQueue$Message::load$($String* name, bool initialize) {
	$loadClass(MessageQueue$Message, name, initialize, &_MessageQueue$Message_ClassInfo_, allocate$MessageQueue$Message);
	return class$;
}

$Class* MessageQueue$Message::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk