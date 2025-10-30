#ifndef _java_net_http_WebSocketHandshakeException_h_
#define _java_net_http_WebSocketHandshakeException_h_
//$ class java.net.http.WebSocketHandshakeException
//$ extends java.io.IOException

#include <java/io/IOException.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpResponse;
		}
	}
}

namespace java {
	namespace net {
		namespace http {

class $export WebSocketHandshakeException : public ::java::io::IOException {
	$class(WebSocketHandshakeException, $NO_CLASS_INIT, ::java::io::IOException)
public:
	WebSocketHandshakeException();
	void init$(::java::net::http::HttpResponse* response);
	::java::net::http::HttpResponse* getResponse();
	virtual ::java::net::http::WebSocketHandshakeException* initCause($Throwable* cause) override;
	static const int64_t serialVersionUID = (int64_t)1;
	::java::net::http::HttpResponse* response = nullptr;
	WebSocketHandshakeException(const WebSocketHandshakeException& e);
	virtual void throw$() override;
	inline WebSocketHandshakeException* operator ->() {
		return (WebSocketHandshakeException*)throwing$;
	}
};

		} // http
	} // net
} // java

#endif // _java_net_http_WebSocketHandshakeException_h_