#ifndef _jdk_internal_net_http_SocketTube$InternalWriteSubscriber$WriteEvent_h_
#define _jdk_internal_net_http_SocketTube$InternalWriteSubscriber$WriteEvent_h_
//$ class jdk.internal.net.http.SocketTube$InternalWriteSubscriber$WriteEvent
//$ extends jdk.internal.net.http.SocketTube$SocketFlowEvent

#include <jdk/internal/net/http/SocketTube$SocketFlowEvent.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace nio {
		namespace channels {
			class SocketChannel;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class SocketTube$InternalWriteSubscriber;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Logger;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import SocketTube$InternalWriteSubscriber$WriteEvent : public ::jdk::internal::net::http::SocketTube$SocketFlowEvent {
	$class(SocketTube$InternalWriteSubscriber$WriteEvent, $NO_CLASS_INIT, ::jdk::internal::net::http::SocketTube$SocketFlowEvent)
public:
	SocketTube$InternalWriteSubscriber$WriteEvent();
	void init$(::jdk::internal::net::http::SocketTube$InternalWriteSubscriber* this$1, ::java::nio::channels::SocketChannel* channel, ::jdk::internal::net::http::SocketTube$InternalWriteSubscriber* sub);
	virtual ::jdk::internal::net::http::common::Logger* debug() override;
	virtual void signalError($Throwable* error) override;
	virtual void signalEvent() override;
	::jdk::internal::net::http::SocketTube$InternalWriteSubscriber* this$1 = nullptr;
	::jdk::internal::net::http::SocketTube$InternalWriteSubscriber* sub = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_SocketTube$InternalWriteSubscriber$WriteEvent_h_