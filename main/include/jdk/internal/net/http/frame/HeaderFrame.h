#ifndef _jdk_internal_net_http_frame_HeaderFrame_h_
#define _jdk_internal_net_http_frame_HeaderFrame_h_
//$ class jdk.internal.net.http.frame.HeaderFrame
//$ extends jdk.internal.net.http.frame.Http2Frame

#include <jdk/internal/net/http/frame/Http2Frame.h>

#pragma push_macro("END_HEADERS")
#undef END_HEADERS
#pragma push_macro("END_STREAM")
#undef END_STREAM

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

class $import HeaderFrame : public ::jdk::internal::net::http::frame::Http2Frame {
	$class(HeaderFrame, $NO_CLASS_INIT, ::jdk::internal::net::http::frame::Http2Frame)
public:
	HeaderFrame();
	void init$(int32_t streamid, int32_t flags, ::java::util::List* headerBlocks);
	virtual bool endHeaders();
	virtual $String* flagAsString(int32_t flag) override;
	virtual ::java::util::List* getHeaderBlock();
	virtual int32_t getHeaderLength();
	int32_t headerLength = 0;
	::java::util::List* headerBlocks = nullptr;
	static const int32_t END_STREAM = 1;
	static const int32_t END_HEADERS = 4;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("END_HEADERS")
#pragma pop_macro("END_STREAM")

#endif // _jdk_internal_net_http_frame_HeaderFrame_h_