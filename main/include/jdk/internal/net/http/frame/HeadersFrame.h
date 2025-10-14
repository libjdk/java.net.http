#ifndef _jdk_internal_net_http_frame_HeadersFrame_h_
#define _jdk_internal_net_http_frame_HeadersFrame_h_
//$ class jdk.internal.net.http.frame.HeadersFrame
//$ extends jdk.internal.net.http.frame.HeaderFrame

#include <jdk/internal/net/http/frame/HeaderFrame.h>

#pragma push_macro("END_STREAM")
#undef END_STREAM
#pragma push_macro("PADDED")
#undef PADDED
#pragma push_macro("PRIORITY")
#undef PRIORITY
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

class $import HeadersFrame : public ::jdk::internal::net::http::frame::HeaderFrame {
	$class(HeadersFrame, $NO_CLASS_INIT, ::jdk::internal::net::http::frame::HeaderFrame)
public:
	HeadersFrame();
	void init$(int32_t streamid, int32_t flags, ::java::util::List* headerBlocks, int32_t padLength);
	void init$(int32_t streamid, int32_t flags, ::java::util::List* headerBlocks);
	void init$(int32_t streamid, int32_t flags, ::java::nio::ByteBuffer* headerBlock);
	virtual $String* flagAsString(int32_t flag) override;
	virtual bool getExclusive();
	virtual int32_t getPadLength();
	virtual int32_t getStreamDependency();
	virtual int32_t getWeight();
	virtual int32_t length() override;
	virtual void setPadLength(int32_t padLength);
	virtual void setPriority(int32_t streamDependency, bool exclusive, int32_t weight);
	virtual int32_t type() override;
	static const int32_t TYPE = 1;
	static const int32_t END_STREAM = 1;
	static const int32_t PADDED = 8;
	static const int32_t PRIORITY = 32;
	int32_t padLength = 0;
	int32_t streamDependency = 0;
	int32_t weight = 0;
	bool exclusive = false;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("END_STREAM")
#pragma pop_macro("PADDED")
#pragma pop_macro("PRIORITY")
#pragma pop_macro("TYPE")

#endif // _jdk_internal_net_http_frame_HeadersFrame_h_