#ifndef _jdk_internal_net_http_SocketTube$SliceBufferSource_h_
#define _jdk_internal_net_http_SocketTube$SliceBufferSource_h_
//$ class jdk.internal.net.http.SocketTube$SliceBufferSource
//$ extends jdk.internal.net.http.SocketTube$BufferSource

#include <jdk/internal/net/http/SocketTube$BufferSource.h>

namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace java {
	namespace util {
		class List;
	}
}
namespace java {
	namespace util {
		namespace function {
			class Supplier;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import SocketTube$SliceBufferSource : public ::jdk::internal::net::http::SocketTube$BufferSource {
	$class(SocketTube$SliceBufferSource, 0, ::jdk::internal::net::http::SocketTube$BufferSource)
public:
	SocketTube$SliceBufferSource();
	void init$();
	void init$(::java::util::function::Supplier* factory);
	virtual ::java::util::List* append(::java::util::List* list, ::java::nio::ByteBuffer* buf, int32_t start) override;
	virtual ::java::nio::ByteBuffer* getBuffer() override;
	static bool $assertionsDisabled;
	::java::util::function::Supplier* factory = nullptr;
	$volatile(::java::nio::ByteBuffer*) current = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_SocketTube$SliceBufferSource_h_