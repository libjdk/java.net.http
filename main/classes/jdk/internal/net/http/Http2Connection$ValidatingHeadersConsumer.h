#ifndef _jdk_internal_net_http_Http2Connection$ValidatingHeadersConsumer_h_
#define _jdk_internal_net_http_Http2Connection$ValidatingHeadersConsumer_h_
//$ class jdk.internal.net.http.Http2Connection$ValidatingHeadersConsumer
//$ extends jdk.internal.net.http.hpack.DecodingCallback

#include <jdk/internal/net/http/hpack/DecodingCallback.h>

#pragma push_macro("PSEUDO_HEADERS")
#undef PSEUDO_HEADERS

namespace java {
	namespace io {
		class UncheckedIOException;
	}
}
namespace java {
	namespace lang {
		class CharSequence;
	}
}
namespace java {
	namespace util {
		class Set;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Http2Connection$ValidatingHeadersConsumer : public ::jdk::internal::net::http::hpack::DecodingCallback {
	$class(Http2Connection$ValidatingHeadersConsumer, 0, ::jdk::internal::net::http::hpack::DecodingCallback)
public:
	Http2Connection$ValidatingHeadersConsumer();
	void init$();
	::java::io::UncheckedIOException* newException($String* message, $String* header);
	using ::jdk::internal::net::http::hpack::DecodingCallback::onDecoded;
	virtual void onDecoded(::java::lang::CharSequence* name, ::java::lang::CharSequence* value) override;
	virtual void reset();
	static ::java::util::Set* PSEUDO_HEADERS;
	bool pseudoHeadersEnded = false;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("PSEUDO_HEADERS")

#endif // _jdk_internal_net_http_Http2Connection$ValidatingHeadersConsumer_h_