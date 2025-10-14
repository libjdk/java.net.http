#ifndef _jdk_internal_net_http_hpack_BinaryRepresentationWriter_h_
#define _jdk_internal_net_http_hpack_BinaryRepresentationWriter_h_
//$ interface jdk.internal.net.http.hpack.BinaryRepresentationWriter
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

class BinaryRepresentationWriter : public ::java::lang::Object {
	$interface(BinaryRepresentationWriter, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::jdk::internal::net::http::hpack::BinaryRepresentationWriter* reset() {return nullptr;}
	virtual bool write(::jdk::internal::net::http::hpack::HeaderTable* table, ::java::nio::ByteBuffer* destination) {return false;}
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_BinaryRepresentationWriter_h_