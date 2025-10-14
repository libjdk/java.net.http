#ifndef _jdk_internal_net_http_Http2Connection$FramesController_h_
#define _jdk_internal_net_http_Http2Connection$FramesController_h_
//$ class jdk.internal.net.http.Http2Connection$FramesController
//$ extends java.lang.Object

#include <java/lang/Object.h>

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
				class Http2Connection;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {
					class FramesDecoder;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Http2Connection$FramesController : public ::java::lang::Object {
	$class(Http2Connection$FramesController, 0, ::java::lang::Object)
public:
	Http2Connection$FramesController();
	void init$(::jdk::internal::net::http::Http2Connection* this$0);
	static $String* lambda$processReceivedData$0(::java::util::List* pending);
	void markPrefaceSent();
	bool processReceivedData(::jdk::internal::net::http::frame::FramesDecoder* decoder, ::java::nio::ByteBuffer* buf);
	::jdk::internal::net::http::Http2Connection* this$0 = nullptr;
	static bool $assertionsDisabled;
	$volatile(bool) prefaceSent = false;
	$volatile(::java::util::List*) pending = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http2Connection$FramesController_h_