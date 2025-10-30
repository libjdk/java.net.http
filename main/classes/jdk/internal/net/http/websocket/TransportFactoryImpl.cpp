#include <jdk/internal/net/http/websocket/TransportFactoryImpl.h>

#include <jdk/internal/net/http/websocket/MessageQueue.h>
#include <jdk/internal/net/http/websocket/MessageStreamConsumer.h>
#include <jdk/internal/net/http/websocket/RawChannel.h>
#include <jdk/internal/net/http/websocket/Transport.h>
#include <jdk/internal/net/http/websocket/TransportImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MessageQueue = ::jdk::internal::net::http::websocket::MessageQueue;
using $MessageStreamConsumer = ::jdk::internal::net::http::websocket::MessageStreamConsumer;
using $RawChannel = ::jdk::internal::net::http::websocket::RawChannel;
using $Transport = ::jdk::internal::net::http::websocket::Transport;
using $TransportFactory = ::jdk::internal::net::http::websocket::TransportFactory;
using $TransportImpl = ::jdk::internal::net::http::websocket::TransportImpl;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _TransportFactoryImpl_FieldInfo_[] = {
	{"channel", "Ljdk/internal/net/http/websocket/RawChannel;", nullptr, $PRIVATE | $FINAL, $field(TransportFactoryImpl, channel)},
	{}
};

$MethodInfo _TransportFactoryImpl_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/websocket/RawChannel;)V", nullptr, $PUBLIC, $method(static_cast<void(TransportFactoryImpl::*)($RawChannel*)>(&TransportFactoryImpl::init$))},
	{"createTransport", "(Ljdk/internal/net/http/websocket/MessageQueue;Ljdk/internal/net/http/websocket/MessageStreamConsumer;)Ljdk/internal/net/http/websocket/Transport;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _TransportFactoryImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.websocket.TransportFactoryImpl",
	"java.lang.Object",
	"jdk.internal.net.http.websocket.TransportFactory",
	_TransportFactoryImpl_FieldInfo_,
	_TransportFactoryImpl_MethodInfo_
};

$Object* allocate$TransportFactoryImpl($Class* clazz) {
	return $of($alloc(TransportFactoryImpl));
}

void TransportFactoryImpl::init$($RawChannel* channel) {
	$set(this, channel, channel);
}

$Transport* TransportFactoryImpl::createTransport($MessageQueue* queue, $MessageStreamConsumer* consumer) {
	return $new($TransportImpl, queue, consumer, this->channel);
}

TransportFactoryImpl::TransportFactoryImpl() {
}

$Class* TransportFactoryImpl::load$($String* name, bool initialize) {
	$loadClass(TransportFactoryImpl, name, initialize, &_TransportFactoryImpl_ClassInfo_, allocate$TransportFactoryImpl);
	return class$;
}

$Class* TransportFactoryImpl::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk