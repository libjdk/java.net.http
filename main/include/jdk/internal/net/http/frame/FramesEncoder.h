#ifndef _jdk_internal_net_http_frame_FramesEncoder_h_
#define _jdk_internal_net_http_frame_FramesEncoder_h_
//$ class jdk.internal.net.http.frame.FramesEncoder
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("NO_FLAGS")
#undef NO_FLAGS
#pragma push_macro("ZERO_STREAM")
#undef ZERO_STREAM

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
					class ContinuationFrame;
					class DataFrame;
					class GoAwayFrame;
					class HeadersFrame;
					class Http2Frame;
					class PingFrame;
					class PriorityFrame;
					class PushPromiseFrame;
					class ResetFrame;
					class SettingsFrame;
					class WindowUpdateFrame;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

class $import FramesEncoder : public ::java::lang::Object {
	$class(FramesEncoder, 0, ::java::lang::Object)
public:
	FramesEncoder();
	void init$();
	virtual ::java::nio::ByteBuffer* encodeConnectionPreface($bytes* preface, ::jdk::internal::net::http::frame::SettingsFrame* frame);
	::java::util::List* encodeContinuationFrame(::jdk::internal::net::http::frame::ContinuationFrame* frame);
	::java::util::List* encodeDataFrame(::jdk::internal::net::http::frame::DataFrame* frame);
	::java::nio::ByteBuffer* encodeDataFrameStart(::jdk::internal::net::http::frame::DataFrame* frame);
	virtual ::java::util::List* encodeFrame(::jdk::internal::net::http::frame::Http2Frame* frame);
	virtual ::java::util::List* encodeFrames(::java::util::List* frames);
	::java::util::List* encodeGoAwayFrame(::jdk::internal::net::http::frame::GoAwayFrame* frame);
	::java::util::List* encodeHeadersFrame(::jdk::internal::net::http::frame::HeadersFrame* frame);
	::java::nio::ByteBuffer* encodeHeadersFrameStart(::jdk::internal::net::http::frame::HeadersFrame* frame);
	::java::util::List* encodePingFrame(::jdk::internal::net::http::frame::PingFrame* frame);
	::java::util::List* encodePriorityFrame(::jdk::internal::net::http::frame::PriorityFrame* frame);
	::java::util::List* encodePushPromiseFrame(::jdk::internal::net::http::frame::PushPromiseFrame* frame);
	::java::util::List* encodeResetFrame(::jdk::internal::net::http::frame::ResetFrame* frame);
	::java::util::List* encodeSettingsFrame(::jdk::internal::net::http::frame::SettingsFrame* frame);
	::java::util::List* encodeWindowUpdateFrame(::jdk::internal::net::http::frame::WindowUpdateFrame* frame);
	::java::nio::ByteBuffer* getBuffer(int32_t capacity);
	virtual ::java::nio::ByteBuffer* getPadding(int32_t length);
	::java::util::List* join(::java::nio::ByteBuffer* buf, ::java::util::List* data);
	::java::util::List* joinWithPadding(::java::nio::ByteBuffer* buf, ::java::util::List* data, int32_t padLength);
	void putHeader(::java::nio::ByteBuffer* buf, int32_t length, int32_t type, int32_t flags, int32_t streamId);
	void putPriority(::java::nio::ByteBuffer* buf, bool exclusive, int32_t streamDependency, int32_t weight);
	void putSettingsFrame(::java::nio::ByteBuffer* buf, ::jdk::internal::net::http::frame::SettingsFrame* frame, int32_t length);
	static bool $assertionsDisabled;
	static const int32_t NO_FLAGS = 0;
	static const int32_t ZERO_STREAM = 0;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("NO_FLAGS")
#pragma pop_macro("ZERO_STREAM")

#endif // _jdk_internal_net_http_frame_FramesEncoder_h_