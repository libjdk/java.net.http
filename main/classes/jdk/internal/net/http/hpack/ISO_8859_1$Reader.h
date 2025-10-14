#ifndef _jdk_internal_net_http_hpack_ISO_8859_1$Reader_h_
#define _jdk_internal_net_http_hpack_ISO_8859_1$Reader_h_
//$ class jdk.internal.net.http.hpack.ISO_8859_1$Reader
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("UPDATER")
#undef UPDATER

namespace java {
	namespace lang {
		class Appendable;
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
					class HPACK$BufferUpdateConsumer;
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

class ISO_8859_1$Reader : public ::java::lang::Object {
	$class(ISO_8859_1$Reader, 0, ::java::lang::Object)
public:
	ISO_8859_1$Reader();
	void init$();
	void lambda$new$0(int64_t buf, int32_t bufLen);
	void read(::java::nio::ByteBuffer* source, ::java::lang::Appendable* destination);
	::jdk::internal::net::http::hpack::ISO_8859_1$Reader* reset();
	static bool $assertionsDisabled;
	::jdk::internal::net::http::hpack::HPACK$BufferUpdateConsumer* UPDATER = nullptr;
	int64_t buffer = 0;
	int32_t bufferLen = 0;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("UPDATER")

#endif // _jdk_internal_net_http_hpack_ISO_8859_1$Reader_h_