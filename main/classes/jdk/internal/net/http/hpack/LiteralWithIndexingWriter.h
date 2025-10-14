#ifndef _jdk_internal_net_http_hpack_LiteralWithIndexingWriter_h_
#define _jdk_internal_net_http_hpack_LiteralWithIndexingWriter_h_
//$ class jdk.internal.net.http.hpack.LiteralWithIndexingWriter
//$ extends jdk.internal.net.http.hpack.IndexNameValueWriter

#include <jdk/internal/net/http/hpack/IndexNameValueWriter.h>

namespace java {
	namespace lang {
		class CharSequence;
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {
					class HeaderTable;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class LiteralWithIndexingWriter : public ::jdk::internal::net::http::hpack::IndexNameValueWriter {
	$class(LiteralWithIndexingWriter, $NO_CLASS_INIT, ::jdk::internal::net::http::hpack::IndexNameValueWriter)
public:
	LiteralWithIndexingWriter();
	void init$();
	virtual ::jdk::internal::net::http::hpack::LiteralWithIndexingWriter* index(int32_t index) override;
	virtual ::jdk::internal::net::http::hpack::LiteralWithIndexingWriter* name(::java::lang::CharSequence* name, bool useHuffman) override;
	virtual ::jdk::internal::net::http::hpack::IndexNameValueWriter* reset() override;
	virtual ::jdk::internal::net::http::hpack::LiteralWithIndexingWriter* value(::java::lang::CharSequence* value, bool useHuffman) override;
	virtual bool write(::jdk::internal::net::http::hpack::HeaderTable* table, ::java::nio::ByteBuffer* destination) override;
	bool tableUpdated = false;
	::java::lang::CharSequence* name$ = nullptr;
	::java::lang::CharSequence* value$ = nullptr;
	int32_t index$ = 0;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_LiteralWithIndexingWriter_h_