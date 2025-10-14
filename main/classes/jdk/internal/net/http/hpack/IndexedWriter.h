#ifndef _jdk_internal_net_http_hpack_IndexedWriter_h_
#define _jdk_internal_net_http_hpack_IndexedWriter_h_
//$ class jdk.internal.net.http.hpack.IndexedWriter
//$ extends jdk.internal.net.http.hpack.BinaryRepresentationWriter

#include <jdk/internal/net/http/hpack/BinaryRepresentationWriter.h>

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
					class IntegerWriter;
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

class IndexedWriter : public ::jdk::internal::net::http::hpack::BinaryRepresentationWriter {
	$class(IndexedWriter, $NO_CLASS_INIT, ::jdk::internal::net::http::hpack::BinaryRepresentationWriter)
public:
	IndexedWriter();
	void init$();
	::jdk::internal::net::http::hpack::IndexedWriter* index(int32_t index);
	virtual ::jdk::internal::net::http::hpack::BinaryRepresentationWriter* reset() override;
	virtual bool write(::jdk::internal::net::http::hpack::HeaderTable* table, ::java::nio::ByteBuffer* destination) override;
	::jdk::internal::net::http::hpack::IntegerWriter* intWriter = nullptr;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_IndexedWriter_h_