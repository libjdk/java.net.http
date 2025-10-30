#ifndef _jdk_internal_net_http_websocket_FailWebSocketException_h_
#define _jdk_internal_net_http_websocket_FailWebSocketException_h_
//$ class jdk.internal.net.http.websocket.FailWebSocketException
//$ extends java.lang.RuntimeException

#include <java/lang/RuntimeException.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class FailWebSocketException : public ::java::lang::RuntimeException {
	$class(FailWebSocketException, $NO_CLASS_INIT, ::java::lang::RuntimeException)
public:
	FailWebSocketException();
	void init$($String* detail);
	void init$($String* detail, int32_t statusCode);
	int32_t getStatusCode();
	virtual ::jdk::internal::net::http::websocket::FailWebSocketException* initCause($Throwable* cause) override;
	static const int64_t serialVersionUID = (int64_t)1;
	int32_t statusCode = 0;
	FailWebSocketException(const FailWebSocketException& e);
	virtual void throw$() override;
	inline FailWebSocketException* operator ->() {
		return (FailWebSocketException*)throwing$;
	}
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_FailWebSocketException_h_