#ifndef _jdk_internal_net_http_ProxyAuthenticationRequired_h_
#define _jdk_internal_net_http_ProxyAuthenticationRequired_h_
//$ class jdk.internal.net.http.ProxyAuthenticationRequired
//$ extends java.io.IOException

#include <java/io/IOException.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Response;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export ProxyAuthenticationRequired : public ::java::io::IOException {
	$class(ProxyAuthenticationRequired, 0, ::java::io::IOException)
public:
	ProxyAuthenticationRequired();
	void init$(::jdk::internal::net::http::Response* proxyResponse);
	static bool $assertionsDisabled;
	static const int64_t serialVersionUID = 0;
	::jdk::internal::net::http::Response* proxyResponse = nullptr;
	ProxyAuthenticationRequired(const ProxyAuthenticationRequired& e);
	virtual void throw$() override;
	inline ProxyAuthenticationRequired* operator ->() {
		return (ProxyAuthenticationRequired*)throwing$;
	}
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ProxyAuthenticationRequired_h_