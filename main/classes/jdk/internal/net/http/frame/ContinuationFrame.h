#ifndef _jdk_internal_net_http_frame_ContinuationFrame_h_
#define _jdk_internal_net_http_frame_ContinuationFrame_h_
//$ class jdk.internal.net.http.frame.ContinuationFrame
//$ extends jdk.internal.net.http.frame.HeaderFrame

#include <jdk/internal/net/http/frame/HeaderFrame.h>

#pragma push_macro("TYPE")
#undef TYPE

namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
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

class $export ContinuationFrame : public ::jdk::internal::net::http::frame::HeaderFrame {
	$class(ContinuationFrame, $NO_CLASS_INIT, ::jdk::internal::net::http::frame::HeaderFrame)
public:
	ContinuationFrame();
	void init$(int32_t streamid, int32_t flags, ::java::util::List* headerBlocks);
	void init$(int32_t streamid, ::java::nio::ByteBuffer* headersBlock);
	virtual int32_t length() override;
	virtual int32_t type() override;
	static const int32_t TYPE = 9;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("TYPE")

#endif // _jdk_internal_net_http_frame_ContinuationFrame_h_