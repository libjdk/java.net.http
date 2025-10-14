#ifndef _jdk_internal_net_http_websocket_UTF8AccumulatingDecoder_h_
#define _jdk_internal_net_http_websocket_UTF8AccumulatingDecoder_h_
//$ class jdk.internal.net.http.websocket.UTF8AccumulatingDecoder
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace nio {
		class ByteBuffer;
		class CharBuffer;
	}
}
namespace java {
	namespace nio {
		namespace charset {
			class CharsetDecoder;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class UTF8AccumulatingDecoder : public ::java::lang::Object {
	$class(UTF8AccumulatingDecoder, 0, ::java::lang::Object)
public:
	UTF8AccumulatingDecoder();
	void init$();
	::java::nio::CharBuffer* decode(::java::nio::ByteBuffer* in, bool endOfInput);
	static bool $assertionsDisabled;
	::java::nio::charset::CharsetDecoder* decoder = nullptr;
	::java::nio::ByteBuffer* leftovers = nullptr;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_UTF8AccumulatingDecoder_h_