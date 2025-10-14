#ifndef _jdk_internal_net_http_ResponseContent$ChunkedBodyParser_h_
#define _jdk_internal_net_http_ResponseContent$ChunkedBodyParser_h_
//$ class jdk.internal.net.http.ResponseContent$ChunkedBodyParser
//$ extends jdk.internal.net.http.ResponseContent$BodyParser

#include <jdk/internal/net/http/ResponseContent$BodyParser.h>

#pragma push_macro("READMORE")
#undef READMORE

namespace java {
	namespace lang {
		class Throwable;
	}
}
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
namespace java {
	namespace util {
		namespace function {
			class Consumer;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class AbstractSubscription;
				class ResponseContent;
				class ResponseContent$ChunkState;
			}
		}
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

class $export ResponseContent$ChunkedBodyParser : public ::jdk::internal::net::http::ResponseContent$BodyParser {
	$class(ResponseContent$ChunkedBodyParser, 0, ::jdk::internal::net::http::ResponseContent$BodyParser)
public:
	ResponseContent$ChunkedBodyParser();
	void init$(::jdk::internal::net::http::ResponseContent* this$0, ::java::util::function::Consumer* onComplete);
	virtual void accept(::java::nio::ByteBuffer* b);
	virtual void accept(Object$* b) override;
	virtual $String* currentStateMessage() override;
	virtual $String* dbgString();
	void debugBuffer(::java::nio::ByteBuffer* b);
	static $String* lambda$tryReadOneHunk$0(::java::nio::ByteBuffer* chunk);
	virtual void onSubscribe(::jdk::internal::net::http::AbstractSubscription* sub) override;
	int32_t toDigit(int32_t b);
	int32_t tryConsumeBytes(::java::nio::ByteBuffer* chunkbuf);
	bool tryPushOneHunk(::java::nio::ByteBuffer* b, ::java::util::List* out);
	int32_t tryReadChunkLen(::java::nio::ByteBuffer* chunkbuf);
	virtual ::java::nio::ByteBuffer* tryReadOneHunk(::java::nio::ByteBuffer* chunk);
	::jdk::internal::net::http::ResponseContent* this$0 = nullptr;
	static bool $assertionsDisabled;
	::java::nio::ByteBuffer* READMORE = nullptr;
	::java::util::function::Consumer* onComplete = nullptr;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	$String* dbgTag = nullptr;
	$volatile($Throwable*) closedExceptionally = nullptr;
	$volatile(int32_t) partialChunklen = 0;
	$volatile(int32_t) chunklen = 0;
	$volatile(int32_t) bytesremaining = 0;
	$volatile(bool) cr = false;
	$volatile(int32_t) chunkext = 0;
	$volatile(int32_t) digits = 0;
	$volatile(int32_t) bytesToConsume = 0;
	$volatile(::jdk::internal::net::http::ResponseContent$ChunkState*) state = nullptr;
	$volatile(::jdk::internal::net::http::AbstractSubscription*) sub = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("READMORE")

#endif // _jdk_internal_net_http_ResponseContent$ChunkedBodyParser_h_