#ifndef _jdk_internal_net_http_frame_FramesDecoder$FrameProcessor_h_
#define _jdk_internal_net_http_frame_FramesDecoder$FrameProcessor_h_
//$ interface jdk.internal.net.http.frame.FramesDecoder$FrameProcessor
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {
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

class $export FramesDecoder$FrameProcessor : public ::java::lang::Object {
	$interface(FramesDecoder$FrameProcessor, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void processFrame(::jdk::internal::net::http::frame::Http2Frame* frame) {}
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_frame_FramesDecoder$FrameProcessor_h_