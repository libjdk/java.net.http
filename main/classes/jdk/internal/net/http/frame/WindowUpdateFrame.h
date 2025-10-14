#ifndef _jdk_internal_net_http_frame_WindowUpdateFrame_h_
#define _jdk_internal_net_http_frame_WindowUpdateFrame_h_
//$ class jdk.internal.net.http.frame.WindowUpdateFrame
//$ extends jdk.internal.net.http.frame.Http2Frame

#include <jdk/internal/net/http/frame/Http2Frame.h>

#pragma push_macro("TYPE")
#undef TYPE

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

class $export WindowUpdateFrame : public ::jdk::internal::net::http::frame::Http2Frame {
	$class(WindowUpdateFrame, $NO_CLASS_INIT, ::jdk::internal::net::http::frame::Http2Frame)
public:
	WindowUpdateFrame();
	void init$(int32_t streamid, int32_t windowUpdate);
	virtual int32_t getUpdate();
	virtual int32_t length() override;
	virtual $String* toString() override;
	virtual int32_t type() override;
	int32_t windowUpdate = 0;
	static const int32_t TYPE = 8;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("TYPE")

#endif // _jdk_internal_net_http_frame_WindowUpdateFrame_h_