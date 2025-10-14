#ifndef _jdk_internal_net_http_frame_PushPromiseFrame_h_
#define _jdk_internal_net_http_frame_PushPromiseFrame_h_
//$ class jdk.internal.net.http.frame.PushPromiseFrame
//$ extends jdk.internal.net.http.frame.HeaderFrame

#include <jdk/internal/net/http/frame/HeaderFrame.h>

#pragma push_macro("END_HEADERS")
#undef END_HEADERS
#pragma push_macro("PADDED")
#undef PADDED
#pragma push_macro("TYPE")
#undef TYPE

namespace java {
	namespace util {
		class List;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

class $export PushPromiseFrame : public ::jdk::internal::net::http::frame::HeaderFrame {
	$class(PushPromiseFrame, $NO_CLASS_INIT, ::jdk::internal::net::http::frame::HeaderFrame)
public:
	PushPromiseFrame();
	void init$(int32_t streamid, int32_t flags, int32_t promisedStream, ::java::util::List* buffers, int32_t padLength);
	virtual bool endHeaders() override;
	virtual $String* flagAsString(int32_t flag) override;
	virtual int32_t getPadLength();
	virtual int32_t getPromisedStream();
	virtual int32_t length() override;
	virtual void setPadLength(int32_t padLength);
	virtual $String* toString() override;
	virtual int32_t type() override;
	int32_t padLength = 0;
	int32_t promisedStream = 0;
	static const int32_t TYPE = 5;
	static const int32_t END_HEADERS = 4;
	static const int32_t PADDED = 8;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("END_HEADERS")
#pragma pop_macro("PADDED")
#pragma pop_macro("TYPE")

#endif // _jdk_internal_net_http_frame_PushPromiseFrame_h_