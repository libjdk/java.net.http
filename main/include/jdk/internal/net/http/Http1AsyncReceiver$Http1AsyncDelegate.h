#ifndef _jdk_internal_net_http_Http1AsyncReceiver$Http1AsyncDelegate_h_
#define _jdk_internal_net_http_Http1AsyncReceiver$Http1AsyncDelegate_h_
//$ interface jdk.internal.net.http.Http1AsyncReceiver$Http1AsyncDelegate
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class AbstractSubscription;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Http1AsyncReceiver$Http1AsyncDelegate : public ::java::lang::Object {
	$interface(Http1AsyncReceiver$Http1AsyncDelegate, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void close($Throwable* error) {}
	virtual void onReadError($Throwable* ex) {}
	virtual void onSubscribe(::jdk::internal::net::http::AbstractSubscription* s) {}
	virtual ::jdk::internal::net::http::AbstractSubscription* subscription() {return nullptr;}
	virtual bool tryAsyncReceive(::java::nio::ByteBuffer* ref) {return false;}
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1AsyncReceiver$Http1AsyncDelegate_h_