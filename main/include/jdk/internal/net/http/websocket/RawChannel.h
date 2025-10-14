#ifndef _jdk_internal_net_http_websocket_RawChannel_h_
#define _jdk_internal_net_http_websocket_RawChannel_h_
//$ interface jdk.internal.net.http.websocket.RawChannel
//$ extends java.io.Closeable

#include <java/io/Closeable.h>
#include <java/lang/Array.h>

namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {
					class RawChannel$RawEvent;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class $import RawChannel : public ::java::io::Closeable {
	$interface(RawChannel, $NO_CLASS_INIT, ::java::io::Closeable)
public:
	virtual void close() override {}
	virtual ::java::nio::ByteBuffer* initialByteBuffer() {return nullptr;}
	virtual ::java::nio::ByteBuffer* read() {return nullptr;}
	virtual void registerEvent(::jdk::internal::net::http::websocket::RawChannel$RawEvent* event) {}
	virtual void shutdownInput() {}
	virtual void shutdownOutput() {}
	virtual int64_t write($Array<::java::nio::ByteBuffer>* srcs, int32_t offset, int32_t length) {return 0;}
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_RawChannel_h_