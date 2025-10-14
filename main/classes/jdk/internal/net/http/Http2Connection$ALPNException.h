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

class $export Http2Connection$ALPNException : public ::java::io::IOException {
	$class(Http2Connection$ALPNException, $NO_CLASS_INIT, ::java::io::IOException)
public:
	Http2Connection$ALPNException();
	void init$($String* msg, ::jdk::internal::net::http::AbstractAsyncSSLConnection* connection);
	::jdk::internal::net::http::AbstractAsyncSSLConnection* getConnection();
	static const int64_t serialVersionUID = (int64_t)0;
	::jdk::internal::net::http::AbstractAsyncSSLConnection* connection = nullptr;
	Http2Connection$ALPNException(const Http2Connection$ALPNException& e);
	Http2Connection$ALPNException wrapper$();
	virtual void throwWrapper$() override;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http2Connection$ALPNException_h_