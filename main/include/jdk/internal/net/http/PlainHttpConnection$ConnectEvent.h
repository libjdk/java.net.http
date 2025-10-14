#ifndef _jdk_internal_net_http_PlainHttpConnection$ConnectEvent_h_
#define _jdk_internal_net_http_PlainHttpConnection$ConnectEvent_h_
//$ class jdk.internal.net.http.PlainHttpConnection$ConnectEvent
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
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Exchange;
				class PlainHttpConnection;
				class PlainHttpConnection$ConnectState;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import PlainHttpConnection$ConnectEvent : public ::jdk::internal::net::http::AsyncEvent {
	$class(PlainHttpConnection$ConnectEvent, 0, ::jdk::internal::net::http::AsyncEvent)
public:
	PlainHttpConnection$ConnectEvent();
	void init$(::jdk::internal::net::http::PlainHttpConnection* this$0, ::java::util::concurrent::CompletableFuture* cf, ::jdk::internal::net::http::Exchange* exchange);
	virtual void abort(::java::io::IOException* ioe) override;
	virtual ::java::nio::channels::SelectableChannel* channel() override;
	virtual void handle() override;
	virtual int32_t interestOps() override;
	void lambda$abort$3(::java::io::IOException* ioe);
	static ::jdk::internal::net::http::PlainHttpConnection$ConnectState* lambda$handle$0();
	static ::jdk::internal::net::http::PlainHttpConnection$ConnectState* lambda$handle$1();
	void lambda$handle$2($Throwable* t);
	::jdk::internal::net::http::PlainHttpConnection* this$0 = nullptr;
	static bool $assertionsDisabled;
	::java::util::concurrent::CompletableFuture* cf = nullptr;
	::jdk::internal::net::http::Exchange* exchange = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_PlainHttpConnection$ConnectEvent_h_