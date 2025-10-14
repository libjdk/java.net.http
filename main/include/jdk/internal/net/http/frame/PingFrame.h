#ifndef _jdk_internal_net_http_frame_PingFrame_h_
#define _jdk_internal_net_http_frame_PingFrame_h_
//$ class jdk.internal.net.http.frame.PingFrame
//$ extends jdk.internal.net.http.frame.Http2Frame

#include <java/lang/Array.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>

#pragma push_macro("ACK")
#undef ACK
#pragma push_macro("TYPE")
#undef TYPE

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

class $import PingFrame : public ::jdk::internal::net::http::frame::Http2Frame {
	$class(PingFrame, 0, ::jdk::internal::net::http::frame::Http2Frame)
public:
	PingFrame();
	void init$(int32_t flags, $bytes* data);
	virtual $String* flagAsString(int32_t flag) override;
	virtual $bytes* getData();
	virtual int32_t length() override;
	virtual int32_t type() override;
	static bool $assertionsDisabled;
	$bytes* data = nullptr;
	static const int32_t TYPE = 6;
	static const int32_t ACK = 1;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("ACK")
#pragma pop_macro("TYPE")

#endif // _jdk_internal_net_http_frame_PingFrame_h_