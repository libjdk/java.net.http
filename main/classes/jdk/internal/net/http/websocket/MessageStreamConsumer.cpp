#include <jdk/internal/net/http/websocket/MessageStreamConsumer.h>

#include <java/lang/CharSequence.h>
#include <java/nio/ByteBuffer.h>
#include <jcpp.h>

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$MethodInfo _MessageStreamConsumer_MethodInfo_[] = {
	{"onBinary", "(Ljava/nio/ByteBuffer;Z)V", nullptr, $PUBLIC | $ABSTRACT},
	{"onClose", "(ILjava/lang/CharSequence;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"onComplete", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"onPing", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"onPong", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"onText", "(Ljava/lang/CharSequence;Z)V", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _MessageStreamConsumer_ClassInfo_ = {
	$INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.websocket.MessageStreamConsumer",
	nullptr,
	nullptr,
	nullptr,
	_MessageStreamConsumer_MethodInfo_
};

$Object* allocate$MessageStreamConsumer($Class* clazz) {
	return $of($alloc(MessageStreamConsumer));
}

$Class* MessageStreamConsumer::load$($String* name, bool initialize) {
	$loadClass(MessageStreamConsumer, name, initialize, &_MessageStreamConsumer_ClassInfo_, allocate$MessageStreamConsumer);
	return class$;
}

$Class* MessageStreamConsumer::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk