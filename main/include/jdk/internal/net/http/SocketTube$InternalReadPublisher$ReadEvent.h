#ifndef _jdk_internal_net_http_SocketTube$InternalReadPublisher$ReadEvent_h_
#define _jdk_internal_net_http_SocketTube$InternalReadPublisher$ReadEvent_h_
//$ class jdk.internal.net.http.SocketTube$InternalReadPublisher$ReadEvent
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
				class SocketTube$InternalReadPublisher;
				class SocketTube$InternalReadPublisher$InternalReadSubscription;
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

class $import SocketTube$InternalReadPublisher$ReadEvent : public ::jdk::internal::net::http::SocketTube$SocketFlowEvent {
	$class(SocketTube$InternalReadPublisher$ReadEvent, $NO_CLASS_INIT, ::jdk::internal::net::http::SocketTube$SocketFlowEvent)
public:
	SocketTube$InternalReadPublisher$ReadEvent();
	void init$(::jdk::internal::net::http::SocketTube$InternalReadPublisher* this$1, ::java::nio::channels::SocketChannel* channel, ::jdk::internal::net::http::SocketTube$InternalReadPublisher$InternalReadSubscription* sub);
	virtual ::jdk::internal::net::http::common::Logger* debug() override;
	virtual void signalError($Throwable* error) override;
	virtual void signalEvent() override;
	::jdk::internal::net::http::SocketTube$InternalReadPublisher* this$1 = nullptr;
	::jdk::internal::net::http::SocketTube$InternalReadPublisher$InternalReadSubscription* sub = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_SocketTube$InternalReadPublisher$ReadEvent_h_