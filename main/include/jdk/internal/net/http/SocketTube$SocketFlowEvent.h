#ifndef _jdk_internal_net_http_SocketTube$SocketFlowEvent_h_
#define _jdk_internal_net_http_SocketTube$SocketFlowEvent_h_
//$ class jdk.internal.net.http.SocketTube$SocketFlowEvent
//$ extends jdk.internal.net.http.AsyncEvent

#include <jdk/internal/net/http/AsyncEvent.h>

namespace java {
	namespace io {
		class IOException;
	}
}
namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace nio {
		namespace channels {
			class SelectableChannel;
			class SocketChannel;
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

class $import SocketTube$SocketFlowEvent : public ::jdk::internal::net::http::AsyncEvent {
	$class(SocketTube$SocketFlowEvent, $NO_CLASS_INIT, ::jdk::internal::net::http::AsyncEvent)
public:
	SocketTube$SocketFlowEvent();
	void init$(int32_t defaultInterest, ::java::nio::channels::SocketChannel* channel);
	virtual void abort(::java::io::IOException* error) override;
	virtual ::java::nio::channels::SelectableChannel* channel() override;
	virtual ::jdk::internal::net::http::common::Logger* debug() {return nullptr;}
	virtual void handle() override;
	virtual int32_t interestOps() override;
	$String* lambda$abort$0(::java::io::IOException* error);
	void pause();
	bool registered();
	void resume();
	virtual void signalError($Throwable* error) {}
	virtual void signalEvent() {}
	::java::nio::channels::SocketChannel* channel$ = nullptr;
	int32_t defaultInterest = 0;
	$volatile(int32_t) interestOps$ = 0;
	$volatile(bool) registered$ = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_SocketTube$SocketFlowEvent_h_