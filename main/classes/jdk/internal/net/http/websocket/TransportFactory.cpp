#include <jdk/internal/net/http/websocket/TransportFactory.h>

#include <jdk/internal/net/http/websocket/MessageQueue.h>
#include <jdk/internal/net/http/websocket/MessageStreamConsumer.h>
#include <jdk/internal/net/http/websocket/Transport.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $MethodInfo = ::java::lang::MethodInfo;
using $MessageQueue = ::jdk::internal::net::http::websocket::MessageQueue;
using $MessageStreamConsumer = ::jdk::internal::net::http::websocket::MessageStreamConsumer;
using $Transport = ::jdk::internal::net::http::websocket::Transport;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$CompoundAttribute _TransportFactory_Annotations_[] = {
	{"Ljava/lang/FunctionalInterface;", nullptr},
	{}
};

$MethodInfo _TransportFactory_MethodInfo_[] = {
	{"createTransport", "(Ljdk/internal/net/http/websocket/MessageQueue;Ljdk/internal/net/http/websocket/MessageStreamConsumer;)Ljdk/internal/net/http/websocket/Transport;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _TransportFactory_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.websocket.TransportFactory",
	nullptr,
	nullptr,
	nullptr,
	_TransportFactory_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_TransportFactory_Annotations_
};

$Object* allocate$TransportFactory($Class* clazz) {
	return $of($alloc(TransportFactory));
}

$Class* TransportFactory::load$($String* name, bool initialize) {
	$loadClass(TransportFactory, name, initialize, &_TransportFactory_ClassInfo_, allocate$TransportFactory);
	return class$;
}

$Class* TransportFactory::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk