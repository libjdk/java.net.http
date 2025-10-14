#ifndef _jdk_internal_net_http_hpack_HPACK_h_
#define _jdk_internal_net_http_hpack_HPACK_h_
//$ class jdk.internal.net.http.hpack.HPACK
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("HPACK")
#undef HPACK
#pragma push_macro("LOGGER")
#undef LOGGER
#pragma push_macro("PROPERTY")
#undef PROPERTY

namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace java {
	namespace util {
		class Map;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {
					class HPACK$BufferUpdateConsumer;
					class HPACK$Logger;
					class HPACK$Logger$Level;
					class HPACK$RootLogger;
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

class HPACK : public ::java::lang::Object {
	$class(HPACK, 0, ::java::lang::Object)
public:
	HPACK();
	void init$();
	static int32_t bytesForBits(int32_t n);
	static ::jdk::internal::net::http::hpack::HPACK$Logger* getLogger();
	static $String* lambda$static$0($String* PROPERTY);
	static $String* lambda$static$1($String* PROPERTY, $String* value);
	static $String* lambda$static$2(::jdk::internal::net::http::hpack::HPACK$Logger$Level* l);
	static int32_t read(::java::nio::ByteBuffer* source, int64_t buffer, int32_t bufferLen, ::jdk::internal::net::http::hpack::HPACK$BufferUpdateConsumer* consumer);
	static int32_t write(int64_t buffer, int32_t bufferLen, ::jdk::internal::net::http::hpack::HPACK$BufferUpdateConsumer* consumer, ::java::nio::ByteBuffer* destination);
	static bool $assertionsDisabled;
	static ::jdk::internal::net::http::hpack::HPACK$RootLogger* LOGGER;
	static ::java::util::Map* logLevels;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("HPACK")
#pragma pop_macro("LOGGER")
#pragma pop_macro("PROPERTY")

#endif // _jdk_internal_net_http_hpack_HPACK_h_