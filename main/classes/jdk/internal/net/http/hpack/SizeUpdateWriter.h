#ifndef _jdk_internal_net_http_hpack_SizeUpdateWriter_h_
#define _jdk_internal_net_http_hpack_SizeUpdateWriter_h_
//$ class jdk.internal.net.http.hpack.SizeUpdateWriter
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

class SizeUpdateWriter : public ::jdk::internal::net::http::hpack::BinaryRepresentationWriter {
	$class(SizeUpdateWriter, $NO_CLASS_INIT, ::jdk::internal::net::http::hpack::BinaryRepresentationWriter)
public:
	SizeUpdateWriter();
	void init$();
	::jdk::internal::net::http::hpack::SizeUpdateWriter* maxHeaderTableSize(int32_t size);
	virtual ::jdk::internal::net::http::hpack::BinaryRepresentationWriter* reset() override;
	virtual bool write(::jdk::internal::net::http::hpack::HeaderTable* table, ::java::nio::ByteBuffer* destination) override;
	::jdk::internal::net::http::hpack::IntegerWriter* intWriter = nullptr;
	int32_t maxSize = 0;
	bool tableUpdated = false;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_SizeUpdateWriter_h_