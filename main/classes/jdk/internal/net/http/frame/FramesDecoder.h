#ifndef _jdk_internal_net_http_frame_FramesDecoder_h_
#define _jdk_internal_net_http_frame_FramesDecoder_h_
//$ class jdk.internal.net.http.frame.FramesDecoder
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("COPY_THRESHOLD")
#undef COPY_THRESHOLD

namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace java {
	namespace util {
		class ArrayDeque;
		class List;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Logger;
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
					class FramesDecoder$FrameProcessor;
					class Http2Frame;
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

class $export FramesDecoder : public ::java::lang::Object {
	$class(FramesDecoder, 0, ::java::lang::Object)
public:
	FramesDecoder();
	void init$(::jdk::internal::net::http::frame::FramesDecoder$FrameProcessor* frameProcessor);
	void init$(::jdk::internal::net::http::frame::FramesDecoder$FrameProcessor* frameProcessor, int32_t maxFrameSize);
	virtual void close($String* msg);
	virtual void decode(::java::nio::ByteBuffer* inBoundBuffer);
	void frameProcessed();
	::java::util::List* getBuffers(bool isDataFrame, int32_t bytecount);
	virtual int32_t getByte();
	virtual $bytes* getBytes(int32_t n);
	virtual int32_t getInt();
	virtual int32_t getShort();
	void nextBuffer();
	::jdk::internal::net::http::frame::Http2Frame* nextFrame();
	::jdk::internal::net::http::frame::Http2Frame* parseContinuationFrame(int32_t frameLength, int32_t streamid, int32_t flags);
	::jdk::internal::net::http::frame::Http2Frame* parseDataFrame(int32_t frameLength, int32_t streamid, int32_t flags);
	::jdk::internal::net::http::frame::Http2Frame* parseFrameBody();
	void parseFrameHeader();
	::jdk::internal::net::http::frame::Http2Frame* parseGoAwayFrame(int32_t frameLength, int32_t streamid, int32_t flags);
	::jdk::internal::net::http::frame::Http2Frame* parseHeadersFrame(int32_t frameLength, int32_t streamid, int32_t flags);
	::jdk::internal::net::http::frame::Http2Frame* parsePingFrame(int32_t frameLength, int32_t streamid, int32_t flags);
	::jdk::internal::net::http::frame::Http2Frame* parsePriorityFrame(int32_t frameLength, int32_t streamid, int32_t flags);
	::jdk::internal::net::http::frame::Http2Frame* parsePushPromiseFrame(int32_t frameLength, int32_t streamid, int32_t flags);
	::jdk::internal::net::http::frame::Http2Frame* parseResetFrame(int32_t frameLength, int32_t streamid, int32_t flags);
	::jdk::internal::net::http::frame::Http2Frame* parseSettingsFrame(int32_t frameLength, int32_t streamid, int32_t flags);
	::jdk::internal::net::http::frame::Http2Frame* parseWindowUpdateFrame(int32_t frameLength, int32_t streamid, int32_t flags);
	virtual void skipBytes(int32_t bytecount);
	static bool $assertionsDisabled;
	static ::jdk::internal::net::http::common::Logger* debug;
	::jdk::internal::net::http::frame::FramesDecoder$FrameProcessor* frameProcessor = nullptr;
	int32_t maxFrameSize = 0;
	::java::nio::ByteBuffer* currentBuffer = nullptr;
	::java::util::ArrayDeque* tailBuffers = nullptr;
	int32_t tailSize = 0;
	bool slicedToDataFrame = false;
	::java::util::List* prepareToRelease = nullptr;
	bool frameHeaderParsed = false;
	int32_t frameLength = 0;
	int32_t frameType = 0;
	int32_t frameFlags = 0;
	int32_t frameStreamid = 0;
	bool closed = false;
	static const int32_t COPY_THRESHOLD = 8192;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("COPY_THRESHOLD")

#endif // _jdk_internal_net_http_frame_FramesDecoder_h_