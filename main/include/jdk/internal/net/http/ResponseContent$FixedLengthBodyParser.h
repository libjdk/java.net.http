#ifndef _jdk_internal_net_http_ResponseContent$FixedLengthBodyParser_h_
#define _jdk_internal_net_http_ResponseContent$FixedLengthBodyParser_h_
//$ class jdk.internal.net.http.ResponseContent$FixedLengthBodyParser
//$ extends jdk.internal.net.http.ResponseContent$BodyParser

#include <jdk/internal/net/http/ResponseContent$BodyParser.h>

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

class $import ResponseContent$FixedLengthBodyParser : public ::jdk::internal::net::http::ResponseContent$BodyParser {
	$class(ResponseContent$FixedLengthBodyParser, 0, ::jdk::internal::net::http::ResponseContent$BodyParser)
public:
	ResponseContent$FixedLengthBodyParser();
	void init$(::jdk::internal::net::http::ResponseContent* this$0, int64_t contentLength, ::java::util::function::Consumer* onComplete);
	virtual void accept(::java::nio::ByteBuffer* b);
	virtual void accept(Object$* b) override;
	virtual $String* currentStateMessage() override;
	virtual $String* dbgString();
	virtual void onSubscribe(::jdk::internal::net::http::AbstractSubscription* sub) override;
	::jdk::internal::net::http::ResponseContent* this$0 = nullptr;
	static bool $assertionsDisabled;
	int64_t contentLength = 0;
	::java::util::function::Consumer* onComplete = nullptr;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	$String* dbgTag = nullptr;
	$volatile(int64_t) remaining = 0;
	$volatile($Throwable*) closedExceptionally = nullptr;
	$volatile(::jdk::internal::net::http::AbstractSubscription*) sub = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseContent$FixedLengthBodyParser_h_