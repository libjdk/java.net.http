#ifndef _jdk_internal_net_http_hpack_BulkSizeUpdateWriter_h_
#define _jdk_internal_net_http_hpack_BulkSizeUpdateWriter_h_
//$ class jdk.internal.net.http.hpack.BulkSizeUpdateWriter
//$ extends jdk.internal.net.http.hpack.BinaryRepresentationWriter

#include <jdk/internal/net/http/hpack/BinaryRepresentationWriter.h>

namespace java {
	namespace lang {
		class Iterable;
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace java {
	namespace util {
		class Iterator;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {
					class HeaderTable;
					class SizeUpdateWriter;
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

class BulkSizeUpdateWriter : public ::jdk::internal::net::http::hpack::BinaryRepresentationWriter {
	$class(BulkSizeUpdateWriter, $NO_CLASS_INIT, ::jdk::internal::net::http::hpack::BinaryRepresentationWriter)
public:
	BulkSizeUpdateWriter();
	void init$();
	::jdk::internal::net::http::hpack::BulkSizeUpdateWriter* maxHeaderTableSizes(::java::lang::Iterable* sizes);
	virtual ::jdk::internal::net::http::hpack::BulkSizeUpdateWriter* reset() override;
	virtual bool write(::jdk::internal::net::http::hpack::HeaderTable* table, ::java::nio::ByteBuffer* destination) override;
	::jdk::internal::net::http::hpack::SizeUpdateWriter* writer = nullptr;
	::java::util::Iterator* maxSizes = nullptr;
	bool writing = false;
	bool configured = false;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_BulkSizeUpdateWriter_h_