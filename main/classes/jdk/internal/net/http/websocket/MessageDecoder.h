#ifndef _jdk_internal_net_http_websocket_MessageDecoder_h_
#define _jdk_internal_net_http_websocket_MessageDecoder_h_
//$ class jdk.internal.net.http.websocket.MessageDecoder
//$ extends jdk.internal.net.http.websocket.Frame$Consumer

#include <jdk/internal/net/http/websocket/Frame$Consumer.h>

namespace java {
	namespace nio {
		class ByteBuffer;
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
					class Frame$Opcode;
					class MessageStreamConsumer;
					class UTF8AccumulatingDecoder;
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

class MessageDecoder : public ::jdk::internal::net::http::websocket::Frame$Consumer {
	$class(MessageDecoder, 0, ::jdk::internal::net::http::websocket::Frame$Consumer)
public:
	MessageDecoder();
	void init$(::jdk::internal::net::http::websocket::MessageStreamConsumer* output);
	virtual void endFrame() override;
	virtual void fin(bool value) override;
	virtual ::jdk::internal::net::http::websocket::MessageStreamConsumer* getOutput();
	virtual void mask(bool value) override;
	virtual void maskingKey(int32_t value) override;
	virtual void opcode(::jdk::internal::net::http::websocket::Frame$Opcode* v) override;
	virtual void payloadData(::java::nio::ByteBuffer* data) override;
	virtual void payloadLen(int64_t value) override;
	virtual void rsv1(bool value) override;
	virtual void rsv2(bool value) override;
	virtual void rsv3(bool value) override;
	static bool $assertionsDisabled;
	static ::jdk::internal::net::http::common::Logger* debug;
	::jdk::internal::net::http::websocket::MessageStreamConsumer* output = nullptr;
	::jdk::internal::net::http::websocket::UTF8AccumulatingDecoder* decoder = nullptr;
	bool fin$ = false;
	::jdk::internal::net::http::websocket::Frame$Opcode* opcode$ = nullptr;
	::jdk::internal::net::http::websocket::Frame$Opcode* originatingOpcode = nullptr;
	int64_t payloadLen$ = 0;
	int64_t unconsumedPayloadLen = 0;
	::java::nio::ByteBuffer* binaryData = nullptr;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_MessageDecoder_h_