#ifndef _jdk_internal_net_http_hpack_LiteralWriter_h_
#define _jdk_internal_net_http_hpack_LiteralWriter_h_
//$ class jdk.internal.net.http.hpack.LiteralWriter
//$ extends jdk.internal.net.http.hpack.IndexNameValueWriter

#include <jdk/internal/net/http/hpack/IndexNameValueWriter.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class LiteralWriter : public ::jdk::internal::net::http::hpack::IndexNameValueWriter {
	$class(LiteralWriter, $NO_CLASS_INIT, ::jdk::internal::net::http::hpack::IndexNameValueWriter)
public:
	LiteralWriter();
	void init$();
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_LiteralWriter_h_