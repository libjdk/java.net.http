#ifndef _jdk_internal_net_http_hpack_LiteralNeverIndexedWriter_h_
#define _jdk_internal_net_http_hpack_LiteralNeverIndexedWriter_h_
//$ class jdk.internal.net.http.hpack.LiteralNeverIndexedWriter
//$ extends jdk.internal.net.http.hpack.IndexNameValueWriter

#include <jdk/internal/net/http/hpack/IndexNameValueWriter.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class LiteralNeverIndexedWriter : public ::jdk::internal::net::http::hpack::IndexNameValueWriter {
	$class(LiteralNeverIndexedWriter, $NO_CLASS_INIT, ::jdk::internal::net::http::hpack::IndexNameValueWriter)
public:
	LiteralNeverIndexedWriter();
	void init$();
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_LiteralNeverIndexedWriter_h_