#ifndef _jdk_internal_net_http_SocketTube$SSLDirectBufferSource_h_
#define _jdk_internal_net_http_SocketTube$SSLDirectBufferSource_h_
//$ class jdk.internal.net.http.SocketTube$SSLDirectBufferSource
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
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class HttpClientImpl;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class BufferSupplier;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import SocketTube$SSLDirectBufferSource : public ::jdk::internal::net::http::SocketTube$BufferSource {
	$class(SocketTube$SSLDirectBufferSource, 0, ::jdk::internal::net::http::SocketTube$BufferSource)
public:
	SocketTube$SSLDirectBufferSource();
	void init$(::jdk::internal::net::http::HttpClientImpl* client);
	virtual ::java::util::List* append(::java::util::List* list, ::java::nio::ByteBuffer* buf, int32_t start) override;
	virtual ::java::nio::ByteBuffer* getBuffer() override;
	virtual void returnUnused(::java::nio::ByteBuffer* buffer) override;
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::BufferSupplier* factory = nullptr;
	::jdk::internal::net::http::HttpClientImpl* client = nullptr;
	::java::nio::ByteBuffer* current = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_SocketTube$SSLDirectBufferSource_h_