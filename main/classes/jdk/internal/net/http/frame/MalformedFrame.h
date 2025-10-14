#ifndef _jdk_internal_net_http_frame_MalformedFrame_h_
#define _jdk_internal_net_http_frame_MalformedFrame_h_
//$ class jdk.internal.net.http.frame.MalformedFrame
//$ extends jdk.internal.net.http.frame.Http2Frame

#include <jdk/internal/net/http/frame/Http2Frame.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

class $export MalformedFrame : public ::jdk::internal::net::http::frame::Http2Frame {
	$class(MalformedFrame, $NO_CLASS_INIT, ::jdk::internal::net::http::frame::Http2Frame)
public:
	MalformedFrame();
	void init$(int32_t errorCode, $String* msg);
	void init$(int32_t errorCode, int32_t errorStream, $String* msg);
	virtual int32_t getErrorCode();
	virtual $String* getMessage();
	virtual $String* toString() override;
	int32_t errorCode = 0;
	int32_t errorStream = 0;
	$String* msg = nullptr;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_frame_MalformedFrame_h_