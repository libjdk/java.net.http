#ifndef _jdk_internal_net_http_HttpClientImpl$SSLDirectBufferSupplier_h_
#define _jdk_internal_net_http_HttpClientImpl$SSLDirectBufferSupplier_h_
//$ class jdk.internal.net.http.HttpClientImpl$SSLDirectBufferSupplier
//$ extends jdk.internal.net.http.common.BufferSupplier

#include <java/lang/Array.h>
#include <jdk/internal/net/http/SocketTube.h>
#include <jdk/internal/net/http/common/BufferSupplier.h>

#pragma push_macro("MAX_BUFFERS")
#undef MAX_BUFFERS
#pragma push_macro("POOL_SIZE")
#undef POOL_SIZE

namespace java {
	namespace nio {
		class ByteBuffer;
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
					class Logger;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import HttpClientImpl$SSLDirectBufferSupplier : public ::jdk::internal::net::http::common::BufferSupplier {
	$class(HttpClientImpl$SSLDirectBufferSupplier, 0, ::jdk::internal::net::http::common::BufferSupplier)
public:
	HttpClientImpl$SSLDirectBufferSupplier();
	void init$(::jdk::internal::net::http::HttpClientImpl* client);
	virtual $Object* get() override;
	virtual void recycle(::java::nio::ByteBuffer* buffer) override;
	static bool $assertionsDisabled;
	static const int32_t POOL_SIZE = ::jdk::internal::net::http::SocketTube::MAX_BUFFERS;
	$Array<::java::nio::ByteBuffer>* pool = nullptr;
	::jdk::internal::net::http::HttpClientImpl* client = nullptr;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	int32_t tail = 0;
	int32_t count = 0;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("MAX_BUFFERS")
#pragma pop_macro("POOL_SIZE")

#endif // _jdk_internal_net_http_HttpClientImpl$SSLDirectBufferSupplier_h_