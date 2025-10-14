#ifndef _jdk_internal_net_http_Stream$HeadersConsumer_h_
#define _jdk_internal_net_http_Stream$HeadersConsumer_h_
//$ class jdk.internal.net.http.Stream$HeadersConsumer
//$ extends jdk.internal.net.http.Http2Connection$ValidatingHeadersConsumer

#include <jdk/internal/net/http/Http2Connection$ValidatingHeadersConsumer.h>

namespace java {
	namespace lang {
		class CharSequence;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Stream;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Stream$HeadersConsumer : public ::jdk::internal::net::http::Http2Connection$ValidatingHeadersConsumer {
	$class(Stream$HeadersConsumer, $NO_CLASS_INIT, ::jdk::internal::net::http::Http2Connection$ValidatingHeadersConsumer)
public:
	Stream$HeadersConsumer();
	void init$(::jdk::internal::net::http::Stream* this$0);
	using ::jdk::internal::net::http::Http2Connection$ValidatingHeadersConsumer::onDecoded;
	virtual void onDecoded(::java::lang::CharSequence* name, ::java::lang::CharSequence* value) override;
	virtual void reset() override;
	::jdk::internal::net::http::Stream* this$0 = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Stream$HeadersConsumer_h_