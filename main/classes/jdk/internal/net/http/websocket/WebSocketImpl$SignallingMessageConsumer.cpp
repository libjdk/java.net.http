#include <jdk/internal/net/http/websocket/WebSocketImpl$SignallingMessageConsumer.h>

#include <java/lang/CharSequence.h>
#include <java/nio/ByteBuffer.h>
#include <jdk/internal/net/http/websocket/Transport.h>
#include <jdk/internal/net/http/websocket/WebSocketImpl$State.h>
#include <jdk/internal/net/http/websocket/WebSocketImpl.h>
#include <jcpp.h>

#undef BINARY
#undef PING
#undef PONG
#undef TEXT
#undef WAITING

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $MessageStreamConsumer = ::jdk::internal::net::http::websocket::MessageStreamConsumer;
using $Transport = ::jdk::internal::net::http::websocket::Transport;
using $WebSocketImpl = ::jdk::internal::net::http::websocket::WebSocketImpl;
using $WebSocketImpl$State = ::jdk::internal::net::http::websocket::WebSocketImpl$State;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _WebSocketImpl$SignallingMessageConsumer_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/websocket/WebSocketImpl;", nullptr, $FINAL | $SYNTHETIC, $field(WebSocketImpl$SignallingMessageConsumer, this$0)},
	{}
};

$MethodInfo _WebSocketImpl$SignallingMessageConsumer_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/websocket/WebSocketImpl;)V", nullptr, $PRIVATE, $method(static_cast<void(WebSocketImpl$SignallingMessageConsumer::*)($WebSocketImpl*)>(&WebSocketImpl$SignallingMessageConsumer::init$))},
	{"onBinary", "(Ljava/nio/ByteBuffer;Z)V", nullptr, $PUBLIC},
	{"onClose", "(ILjava/lang/CharSequence;)V", nullptr, $PUBLIC},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onPing", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC},
	{"onPong", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC},
	{"onText", "(Ljava/lang/CharSequence;Z)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _WebSocketImpl$SignallingMessageConsumer_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.WebSocketImpl$SignallingMessageConsumer", "jdk.internal.net.http.websocket.WebSocketImpl", "SignallingMessageConsumer", $PRIVATE},
	{}
};

$ClassInfo _WebSocketImpl$SignallingMessageConsumer_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.websocket.WebSocketImpl$SignallingMessageConsumer",
	"java.lang.Object",
	"jdk.internal.net.http.websocket.MessageStreamConsumer",
	_WebSocketImpl$SignallingMessageConsumer_FieldInfo_,
	_WebSocketImpl$SignallingMessageConsumer_MethodInfo_,
	nullptr,
	nullptr,
	_WebSocketImpl$SignallingMessageConsumer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.WebSocketImpl"
};

$Object* allocate$WebSocketImpl$SignallingMessageConsumer($Class* clazz) {
	return $of($alloc(WebSocketImpl$SignallingMessageConsumer));
}

void WebSocketImpl$SignallingMessageConsumer::init$($WebSocketImpl* this$0) {
	$set(this, this$0, this$0);
}

void WebSocketImpl$SignallingMessageConsumer::onText($CharSequence* data, bool last) {
	$nc(this->this$0->transport$)->acknowledgeReception();
	$set(this->this$0, text, data);
	this->this$0->last = last;
	$init($WebSocketImpl$State);
	this->this$0->tryChangeState($WebSocketImpl$State::WAITING, $WebSocketImpl$State::TEXT);
}

void WebSocketImpl$SignallingMessageConsumer::onBinary($ByteBuffer* data, bool last) {
	$nc(this->this$0->transport$)->acknowledgeReception();
	$set(this->this$0, binaryData, data);
	this->this$0->last = last;
	$init($WebSocketImpl$State);
	this->this$0->tryChangeState($WebSocketImpl$State::WAITING, $WebSocketImpl$State::BINARY);
}

void WebSocketImpl$SignallingMessageConsumer::onPing($ByteBuffer* data) {
	$nc(this->this$0->transport$)->acknowledgeReception();
	$set(this->this$0, binaryData, data);
	$init($WebSocketImpl$State);
	this->this$0->tryChangeState($WebSocketImpl$State::WAITING, $WebSocketImpl$State::PING);
}

void WebSocketImpl$SignallingMessageConsumer::onPong($ByteBuffer* data) {
	$nc(this->this$0->transport$)->acknowledgeReception();
	$set(this->this$0, binaryData, data);
	$init($WebSocketImpl$State);
	this->this$0->tryChangeState($WebSocketImpl$State::WAITING, $WebSocketImpl$State::PONG);
}

void WebSocketImpl$SignallingMessageConsumer::onClose(int32_t statusCode, $CharSequence* reason) {
	$nc(this->this$0->transport$)->acknowledgeReception();
	this->this$0->signalClose(statusCode, $($nc(reason)->toString()));
}

void WebSocketImpl$SignallingMessageConsumer::onComplete() {
	$nc(this->this$0->transport$)->acknowledgeReception();
	this->this$0->signalClose(1006, ""_s);
}

void WebSocketImpl$SignallingMessageConsumer::onError($Throwable* error) {
	this->this$0->signalError(error);
}

WebSocketImpl$SignallingMessageConsumer::WebSocketImpl$SignallingMessageConsumer() {
}

$Class* WebSocketImpl$SignallingMessageConsumer::load$($String* name, bool initialize) {
	$loadClass(WebSocketImpl$SignallingMessageConsumer, name, initialize, &_WebSocketImpl$SignallingMessageConsumer_ClassInfo_, allocate$WebSocketImpl$SignallingMessageConsumer);
	return class$;
}

$Class* WebSocketImpl$SignallingMessageConsumer::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk