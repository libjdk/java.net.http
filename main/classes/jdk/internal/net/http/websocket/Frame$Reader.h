#ifndef _jdk_internal_net_http_websocket_Frame$Reader_h_
#define _jdk_internal_net_http_websocket_Frame$Reader_h_
//$ class jdk.internal.net.http.websocket.Frame$Reader
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("AWAITING_FIRST_BYTE")
#undef AWAITING_FIRST_BYTE
#pragma push_macro("AWAITING_SECOND_BYTE")
#undef AWAITING_SECOND_BYTE
#pragma push_macro("READING_16_LENGTH")
#undef READING_16_LENGTH
#pragma push_macro("READING_64_LENGTH")
#undef READING_64_LENGTH
#pragma push_macro("READING_MASK")
#undef READING_MASK
#pragma push_macro("READING_PAYLOAD")
#undef READING_PAYLOAD

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
					class FailWebSocketException;
					class Frame$Consumer;
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

class Frame$Reader : public ::java::lang::Object {
	$class(Frame$Reader, 0, ::java::lang::Object)
public:
	Frame$Reader();
	void init$();
	static ::jdk::internal::net::http::websocket::FailWebSocketException* negativePayload(int64_t payloadLength);
	static ::jdk::internal::net::http::websocket::FailWebSocketException* notMinimalEncoding(int64_t payloadLength);
	void readFrame(::java::nio::ByteBuffer* input, ::jdk::internal::net::http::websocket::Frame$Consumer* consumer);
	static bool $assertionsDisabled;
	static const int32_t AWAITING_FIRST_BYTE = 1;
	static const int32_t AWAITING_SECOND_BYTE = 2;
	static const int32_t READING_16_LENGTH = 4;
	static const int32_t READING_64_LENGTH = 8;
	static const int32_t READING_MASK = 16;
	static const int32_t READING_PAYLOAD = 32;
	::java::nio::ByteBuffer* accumulator = nullptr;
	int32_t state = 0;
	bool mask = false;
	int64_t remainingPayloadLength = 0;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("AWAITING_FIRST_BYTE")
#pragma pop_macro("AWAITING_SECOND_BYTE")
#pragma pop_macro("READING_16_LENGTH")
#pragma pop_macro("READING_64_LENGTH")
#pragma pop_macro("READING_MASK")
#pragma pop_macro("READING_PAYLOAD")

#endif // _jdk_internal_net_http_websocket_Frame$Reader_h_