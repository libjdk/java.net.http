#ifndef _jdk_internal_net_http_hpack_ISO_8859_1$Writer_h_
#define _jdk_internal_net_http_hpack_ISO_8859_1$Writer_h_
//$ class jdk.internal.net.http.hpack.ISO_8859_1$Writer
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("UPDATER")
#undef UPDATER

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

class ISO_8859_1$Writer : public ::java::lang::Object {
	$class(ISO_8859_1$Writer, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ISO_8859_1$Writer();
	void init$();
	::jdk::internal::net::http::hpack::ISO_8859_1$Writer* configure(::java::lang::CharSequence* source, int32_t start, int32_t end);
	void lambda$new$0(int64_t buf, int32_t bufLen);
	::jdk::internal::net::http::hpack::ISO_8859_1$Writer* reset();
	bool write(::java::nio::ByteBuffer* destination);
	::jdk::internal::net::http::hpack::HPACK$BufferUpdateConsumer* UPDATER = nullptr;
	::java::lang::CharSequence* source = nullptr;
	int32_t pos = 0;
	int32_t end = 0;
	int64_t buffer = 0;
	int32_t bufferLen = 0;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("UPDATER")

#endif // _jdk_internal_net_http_hpack_ISO_8859_1$Writer_h_