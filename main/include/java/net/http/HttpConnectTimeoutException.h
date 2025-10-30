#ifndef _java_net_http_HttpConnectTimeoutException_h_
#define _java_net_http_HttpConnectTimeoutException_h_
//$ class java.net.http.HttpConnectTimeoutException
//$ extends java.net.http.HttpTimeoutException

#include <java/net/http/HttpTimeoutException.h>

namespace java {
	namespace net {
		namespace http {

class $import HttpConnectTimeoutException : public ::java::net::http::HttpTimeoutException {
	$class(HttpConnectTimeoutException, $NO_CLASS_INIT, ::java::net::http::HttpTimeoutException)
public:
	HttpConnectTimeoutException();
	void init$($String* message);
	static const int64_t serialVersionUID = 332; // (int64_t)321 + (int64_t)11
	HttpConnectTimeoutException(const HttpConnectTimeoutException& e);
	virtual void throw$() override;
	inline HttpConnectTimeoutException* operator ->() {
		return (HttpConnectTimeoutException*)throwing$;
	}
};

		} // http
	} // net
} // java

#endif // _java_net_http_HttpConnectTimeoutException_h_