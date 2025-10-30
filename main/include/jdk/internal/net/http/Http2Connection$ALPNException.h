#ifndef _jdk_internal_net_http_Http2Connection$ALPNException_h_
#define _jdk_internal_net_http_Http2Connection$ALPNException_h_
//$ class jdk.internal.net.http.Http2Connection$ALPNException
//$ extends java.io.IOException

#include <java/io/IOException.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class AbstractAsyncSSLConnection;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Http2Connection$ALPNException : public ::java::io::IOException {
	$class(Http2Connection$ALPNException, $NO_CLASS_INIT, ::java::io::IOException)
public:
	Http2Connection$ALPNException();
	void init$($String* msg, ::jdk::internal::net::http::AbstractAsyncSSLConnection* connection);
	::jdk::internal::net::http::AbstractAsyncSSLConnection* getConnection();
	static const int64_t serialVersionUID = (int64_t)0;
	::jdk::internal::net::http::AbstractAsyncSSLConnection* connection = nullptr;
	Http2Connection$ALPNException(const Http2Connection$ALPNException& e);
	virtual void throw$() override;
	inline Http2Connection$ALPNException* operator ->() {
		return (Http2Connection$ALPNException*)throwing$;
	}
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http2Connection$ALPNException_h_