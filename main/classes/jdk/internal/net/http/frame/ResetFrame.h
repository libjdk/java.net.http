#ifndef _jdk_internal_net_http_frame_ResetFrame_h_
#define _jdk_internal_net_http_frame_ResetFrame_h_
//$ class jdk.internal.net.http.frame.ResetFrame
//$ extends jdk.internal.net.http.frame.ErrorFrame

#include <jdk/internal/net/http/frame/ErrorFrame.h>

#pragma push_macro("TYPE")
#undef TYPE

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

class $export ResetFrame : public ::jdk::internal::net::http::frame::ErrorFrame {
	$class(ResetFrame, $NO_CLASS_INIT, ::jdk::internal::net::http::frame::ErrorFrame)
public:
	ResetFrame();
	void init$(int32_t streamid, int32_t errorCode);
	virtual int32_t length() override;
	virtual int32_t type() override;
	static const int32_t TYPE = 3;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("TYPE")

#endif // _jdk_internal_net_http_frame_ResetFrame_h_