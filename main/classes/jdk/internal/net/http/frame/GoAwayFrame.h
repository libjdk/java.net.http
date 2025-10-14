#ifndef _jdk_internal_net_http_frame_GoAwayFrame_h_
#define _jdk_internal_net_http_frame_GoAwayFrame_h_
//$ class jdk.internal.net.http.frame.GoAwayFrame
//$ extends jdk.internal.net.http.frame.ErrorFrame

#include <java/lang/Array.h>
#include <jdk/internal/net/http/frame/ErrorFrame.h>

#pragma push_macro("TYPE")
#undef TYPE

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

class $export GoAwayFrame : public ::jdk::internal::net::http::frame::ErrorFrame {
	$class(GoAwayFrame, $NO_CLASS_INIT, ::jdk::internal::net::http::frame::ErrorFrame)
public:
	GoAwayFrame();
	void init$(int32_t lastStream, int32_t errorCode);
	void init$(int32_t lastStream, int32_t errorCode, $bytes* debugData);
	virtual $bytes* getDebugData();
	virtual int32_t getLastStream();
	virtual int32_t length() override;
	virtual $String* toString() override;
	virtual int32_t type() override;
	int32_t lastStream = 0;
	$bytes* debugData = nullptr;
	static const int32_t TYPE = 7;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("TYPE")

#endif // _jdk_internal_net_http_frame_GoAwayFrame_h_