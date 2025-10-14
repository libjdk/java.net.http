#ifndef _jdk_internal_net_http_MultiExchange$CancelableRef_h_
#define _jdk_internal_net_http_MultiExchange$CancelableRef_h_
//$ class jdk.internal.net.http.MultiExchange$CancelableRef
//$ extends jdk.internal.net.http.common.Cancelable

#include <jdk/internal/net/http/common/Cancelable.h>

namespace java {
	namespace lang {
		namespace ref {
			class WeakReference;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export MultiExchange$CancelableRef : public ::jdk::internal::net::http::common::Cancelable {
	$class(MultiExchange$CancelableRef, $NO_CLASS_INIT, ::jdk::internal::net::http::common::Cancelable)
public:
	MultiExchange$CancelableRef();
	void init$(::jdk::internal::net::http::common::Cancelable* cancelable);
	virtual bool cancel(bool mayInterruptIfRunning) override;
	::java::lang::ref::WeakReference* cancelableRef = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_MultiExchange$CancelableRef_h_