#ifndef _jdk_internal_net_http_frame_PriorityFrame_h_
#define _jdk_internal_net_http_frame_PriorityFrame_h_
//$ class jdk.internal.net.http.frame.PriorityFrame
//$ extends jdk.internal.net.http.frame.Http2Frame

#include <jdk/internal/net/http/frame/Http2Frame.h>

#pragma push_macro("TYPE")
#undef TYPE

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

class $import PriorityFrame : public ::jdk::internal::net::http::frame::Http2Frame {
	$class(PriorityFrame, $NO_CLASS_INIT, ::jdk::internal::net::http::frame::Http2Frame)
public:
	PriorityFrame();
	void init$(int32_t streamId, int32_t streamDependency, bool exclusive, int32_t weight);
	virtual bool exclusive();
	virtual int32_t length() override;
	virtual int32_t streamDependency();
	virtual int32_t type() override;
	virtual int32_t weight();
	int32_t streamDependency$ = 0;
	int32_t weight$ = 0;
	bool exclusive$ = false;
	static const int32_t TYPE = 2;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("TYPE")

#endif // _jdk_internal_net_http_frame_PriorityFrame_h_