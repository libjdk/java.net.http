#ifndef _jdk_internal_net_http_ResponseContent$UnknownLengthBodyParser_h_
#define _jdk_internal_net_http_ResponseContent$UnknownLengthBodyParser_h_
//$ class jdk.internal.net.http.ResponseContent$UnknownLengthBodyParser
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

class $import ResponseContent$UnknownLengthBodyParser : public ::jdk::internal::net::http::ResponseContent$BodyParser {
	$class(ResponseContent$UnknownLengthBodyParser, 0, ::jdk::internal::net::http::ResponseContent$BodyParser)
public:
	ResponseContent$UnknownLengthBodyParser();
	void init$(::jdk::internal::net::http::ResponseContent* this$0, ::java::util::function::Consumer* onComplete);
	virtual void accept(::java::nio::ByteBuffer* b);
	virtual void accept(Object$* b) override;
	virtual void complete();
	virtual $String* currentStateMessage() override;
	virtual $String* dbgString();
	virtual void onSubscribe(::jdk::internal::net::http::AbstractSubscription* sub) override;
	::jdk::internal::net::http::ResponseContent* this$0 = nullptr;
	static bool $assertionsDisabled;
	::java::util::function::Consumer* onComplete = nullptr;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	$String* dbgTag = nullptr;
	$volatile($Throwable*) closedExceptionally = nullptr;
	$volatile(::jdk::internal::net::http::AbstractSubscription*) sub = nullptr;
	$volatile(int32_t) breceived = 0;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseContent$UnknownLengthBodyParser_h_