#ifndef _jdk_internal_net_http_Stream$StreamWindowUpdateSender_h_
#define _jdk_internal_net_http_Stream$StreamWindowUpdateSender_h_
//$ class jdk.internal.net.http.Stream$StreamWindowUpdateSender
//$ extends jdk.internal.net.http.WindowUpdateSender

#include <jdk/internal/net/http/WindowUpdateSender.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Http2Connection;
				class Stream;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Stream$StreamWindowUpdateSender : public ::jdk::internal::net::http::WindowUpdateSender {
	$class(Stream$StreamWindowUpdateSender, $NO_CLASS_INIT, ::jdk::internal::net::http::WindowUpdateSender)
public:
	Stream$StreamWindowUpdateSender();
	void init$(::jdk::internal::net::http::Stream* this$0, ::jdk::internal::net::http::Http2Connection* connection);
	virtual $String* dbgString() override;
	virtual int32_t getStreamId() override;
	::jdk::internal::net::http::Stream* this$0 = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Stream$StreamWindowUpdateSender_h_