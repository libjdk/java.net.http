#ifndef _jdk_internal_net_http_frame_ErrorFrame_h_
#define _jdk_internal_net_http_frame_ErrorFrame_h_
//$ class jdk.internal.net.http.frame.ErrorFrame
//$ extends jdk.internal.net.http.frame.Http2Frame

#include <java/lang/Array.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>

#pragma push_macro("CANCEL")
#undef CANCEL
#pragma push_macro("COMPRESSION_ERROR")
#undef COMPRESSION_ERROR
#pragma push_macro("CONNECT_ERROR")
#undef CONNECT_ERROR
#pragma push_macro("ENHANCE_YOUR_CALM")
#undef ENHANCE_YOUR_CALM
#pragma push_macro("FLOW_CONTROL_ERROR")
#undef FLOW_CONTROL_ERROR
#pragma push_macro("FRAME_SIZE_ERROR")
#undef FRAME_SIZE_ERROR
#pragma push_macro("HTTP_1_1_REQUIRED")
#undef HTTP_1_1_REQUIRED
#pragma push_macro("INADEQUATE_SECURITY")
#undef INADEQUATE_SECURITY
#pragma push_macro("INTERNAL_ERROR")
#undef INTERNAL_ERROR
#pragma push_macro("LAST_ERROR")
#undef LAST_ERROR
#pragma push_macro("NO_ERROR")
#undef NO_ERROR
#pragma push_macro("PROTOCOL_ERROR")
#undef PROTOCOL_ERROR
#pragma push_macro("REFUSED_STREAM")
#undef REFUSED_STREAM
#pragma push_macro("SETTINGS_TIMEOUT")
#undef SETTINGS_TIMEOUT
#pragma push_macro("STREAM_CLOSED")
#undef STREAM_CLOSED

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

class $import ErrorFrame : public ::jdk::internal::net::http::frame::Http2Frame {
	$class(ErrorFrame, 0, ::jdk::internal::net::http::frame::Http2Frame)
public:
	ErrorFrame();
	void init$(int32_t streamid, int32_t flags, int32_t errorCode);
	virtual int32_t getErrorCode();
	static $String* stringForCode(int32_t code);
	virtual $String* toString() override;
	static const int32_t NO_ERROR = 0;
	static const int32_t PROTOCOL_ERROR = 1;
	static const int32_t INTERNAL_ERROR = 2;
	static const int32_t FLOW_CONTROL_ERROR = 3;
	static const int32_t SETTINGS_TIMEOUT = 4;
	static const int32_t STREAM_CLOSED = 5;
	static const int32_t FRAME_SIZE_ERROR = 6;
	static const int32_t REFUSED_STREAM = 7;
	static const int32_t CANCEL = 8;
	static const int32_t COMPRESSION_ERROR = 9;
	static const int32_t CONNECT_ERROR = 10;
	static const int32_t ENHANCE_YOUR_CALM = 11;
	static const int32_t INADEQUATE_SECURITY = 12;
	static const int32_t HTTP_1_1_REQUIRED = 13;
	static const int32_t LAST_ERROR = 13;
	static $StringArray* errorStrings;
	int32_t errorCode = 0;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("CANCEL")
#pragma pop_macro("COMPRESSION_ERROR")
#pragma pop_macro("CONNECT_ERROR")
#pragma pop_macro("ENHANCE_YOUR_CALM")
#pragma pop_macro("FLOW_CONTROL_ERROR")
#pragma pop_macro("FRAME_SIZE_ERROR")
#pragma pop_macro("HTTP_1_1_REQUIRED")
#pragma pop_macro("INADEQUATE_SECURITY")
#pragma pop_macro("INTERNAL_ERROR")
#pragma pop_macro("LAST_ERROR")
#pragma pop_macro("NO_ERROR")
#pragma pop_macro("PROTOCOL_ERROR")
#pragma pop_macro("REFUSED_STREAM")
#pragma pop_macro("SETTINGS_TIMEOUT")
#pragma pop_macro("STREAM_CLOSED")

#endif // _jdk_internal_net_http_frame_ErrorFrame_h_