#ifndef _jdk_internal_net_http_Http2Connection$ConnectionWindowUpdateSender_h_
#define _jdk_internal_net_http_Http2Connection$ConnectionWindowUpdateSender_h_
//$ class jdk.internal.net.http.Http2Connection$ConnectionWindowUpdateSender
//$ extends jdk.internal.net.http.WindowUpdateSender

#include <jdk/internal/net/http/WindowUpdateSender.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Http2Connection;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Http2Connection$ConnectionWindowUpdateSender : public ::jdk::internal::net::http::WindowUpdateSender {
	$class(Http2Connection$ConnectionWindowUpdateSender, $NO_CLASS_INIT, ::jdk::internal::net::http::WindowUpdateSender)
public:
	Http2Connection$ConnectionWindowUpdateSender();
	void init$(::jdk::internal::net::http::Http2Connection* connection, int32_t initialWindowSize);
	virtual int32_t getStreamId() override;
	int32_t initialWindowSize = 0;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http2Connection$ConnectionWindowUpdateSender_h_