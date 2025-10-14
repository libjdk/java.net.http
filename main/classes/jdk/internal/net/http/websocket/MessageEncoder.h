#ifndef _jdk_internal_net_http_websocket_MessageEncoder_h_
#define _jdk_internal_net_http_websocket_MessageEncoder_h_
//$ class jdk.internal.net.http.websocket.MessageEncoder
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
			class CharsetEncoder;
		}
	}
}
namespace java {
	namespace security {
		class SecureRandom;
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
				namespace websocket {
					class Frame$HeaderWriter;
					class Frame$Masker;
					class Frame$Opcode;
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

class MessageEncoder : public ::java::lang::Object {
	$class(MessageEncoder, 0, ::java::lang::Object)
public:
	MessageEncoder();
	void init$();
	virtual ::java::nio::ByteBuffer* createIntermediateBuffer(int32_t minSize);
	virtual bool encodeBinary(::java::nio::ByteBuffer* src, bool last, ::java::nio::ByteBuffer* dst);
	virtual bool encodeClose(int32_t statusCode, ::java::nio::CharBuffer* reason, ::java::nio::ByteBuffer* dst);
	virtual bool encodePing(::java::nio::ByteBuffer* src, ::java::nio::ByteBuffer* dst);
	virtual bool encodePong(::java::nio::ByteBuffer* src, ::java::nio::ByteBuffer* dst);
	virtual bool encodeText(::java::nio::CharBuffer* src, bool last, ::java::nio::ByteBuffer* dst);
	int32_t maskAvailable(::java::nio::ByteBuffer* src, ::java::nio::ByteBuffer* dst);
	bool putAvailable(::java::nio::ByteBuffer* src, ::java::nio::ByteBuffer* dst);
	virtual void reset();
	void setupHeader(::jdk::internal::net::http::websocket::Frame$Opcode* opcode, bool fin, int64_t payloadLen);
	static ::jdk::internal::net::http::common::Logger* debug;
	::java::security::SecureRandom* maskingKeySource = nullptr;
	::jdk::internal::net::http::websocket::Frame$HeaderWriter* headerWriter = nullptr;
	::jdk::internal::net::http::websocket::Frame$Masker* payloadMasker = nullptr;
	::java::nio::charset::CharsetEncoder* charsetEncoder = nullptr;
	::java::nio::ByteBuffer* intermediateBuffer = nullptr;
	::java::nio::ByteBuffer* headerBuffer = nullptr;
	bool started = false;
	bool flushing = false;
	bool moreText = false;
	int64_t headerCount = 0;
	bool previousFin = false;
	bool previousText = false;
	bool closed = false;
	int32_t actualLen = 0;
	int32_t expectedLen = 0;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_MessageEncoder_h_