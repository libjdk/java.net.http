#ifndef _jdk_internal_net_http_Http2Connection$HeaderDecoder_h_
#define _jdk_internal_net_http_Http2Connection$HeaderDecoder_h_
//$ class jdk.internal.net.http.Http2Connection$HeaderDecoder
//$ extends jdk.internal.net.http.Http2Connection$ValidatingHeadersConsumer

#include <jdk/internal/net/http/Http2Connection$ValidatingHeadersConsumer.h>

namespace java {
	namespace lang {
		class CharSequence;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpHeaders;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class HttpHeadersBuilder;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Http2Connection$HeaderDecoder : public ::jdk::internal::net::http::Http2Connection$ValidatingHeadersConsumer {
	$class(Http2Connection$HeaderDecoder, $NO_CLASS_INIT, ::jdk::internal::net::http::Http2Connection$ValidatingHeadersConsumer)
public:
	Http2Connection$HeaderDecoder();
	void init$();
	virtual ::java::net::http::HttpHeaders* headers();
	using ::jdk::internal::net::http::Http2Connection$ValidatingHeadersConsumer::onDecoded;
	virtual void onDecoded(::java::lang::CharSequence* name, ::java::lang::CharSequence* value) override;
	::jdk::internal::net::http::common::HttpHeadersBuilder* headersBuilder = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http2Connection$HeaderDecoder_h_