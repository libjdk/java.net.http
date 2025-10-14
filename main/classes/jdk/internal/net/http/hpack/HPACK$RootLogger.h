#ifndef _jdk_internal_net_http_hpack_HPACK$RootLogger_h_
#define _jdk_internal_net_http_hpack_HPACK$RootLogger_h_
//$ class jdk.internal.net.http.hpack.HPACK$RootLogger
//$ extends jdk.internal.net.http.hpack.HPACK$Logger

#include <jdk/internal/net/http/hpack/HPACK$Logger.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {
					class HPACK$Logger$Level;
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

class HPACK$RootLogger : public ::jdk::internal::net::http::hpack::HPACK$Logger {
	$class(HPACK$RootLogger, $NO_CLASS_INIT, ::jdk::internal::net::http::hpack::HPACK$Logger)
public:
	HPACK$RootLogger();
	void init$(::jdk::internal::net::http::hpack::HPACK$Logger$Level* level);
	using ::jdk::internal::net::http::hpack::HPACK$Logger::log;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_HPACK$RootLogger_h_