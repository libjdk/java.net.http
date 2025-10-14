#ifndef _jdk_internal_net_http_common_Log_h_
#define _jdk_internal_net_http_common_Log_h_
//$ class jdk.internal.net.http.common.Log
//$ extends java.lang.System$Logger

#include <java/lang/Array.h>
#include <java/lang/System$Logger.h>

#pragma push_macro("ALL")
#undef ALL
#pragma push_macro("CHANNEL")
#undef CHANNEL
#pragma push_macro("CONTENT")
#undef CONTENT
#pragma push_macro("CONTROL")
#undef CONTROL
#pragma push_macro("DATA")
#undef DATA
#pragma push_macro("ERRORS")
#undef ERRORS
#pragma push_macro("FRAMES")
#undef FRAMES
#pragma push_macro("HEADERS")
#undef HEADERS
#pragma push_macro("OFF")
#undef OFF
#pragma push_macro("REQUESTS")
#undef REQUESTS
#pragma push_macro("SSL")
#undef SSL
#pragma push_macro("TRACE")
#undef TRACE
#pragma push_macro("WINDOW_UPDATES")
#undef WINDOW_UPDATES

namespace java {
	namespace lang {
		class StringBuilder;
		class Throwable;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpHeaders;
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Supplier;
		}
	}
}
namespace javax {
	namespace net {
		namespace ssl {
			class SSLParameters;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {
					class Http2Frame;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export Log : public ::java::lang::System$Logger {
	$class(Log, 0, ::java::lang::System$Logger)
public:
	Log();
	void init$();
	static bool channel();
	static void dumpHeaders(::java::lang::StringBuilder* sb, $String* prefix, ::java::net::http::HttpHeaders* headers);
	static bool errors();
	static bool frames();
	static bool headers();
	static void logChannel($String* s, $ObjectArray* s1);
	static void logChannel(::java::util::function::Supplier* msgSupplier);
	static void logError($String* s, $ObjectArray* s1);
	static void logError($Throwable* t);
	static void logFrames(::jdk::internal::net::http::frame::Http2Frame* f, $String* direction);
	static void logHeaders($String* s, $ObjectArray* s1);
	static void logParams(::javax::net::ssl::SSLParameters* p);
	static void logRequest($String* s, $ObjectArray* s1);
	static void logResponse(::java::util::function::Supplier* supplier);
	static void logSSL($String* s, $ObjectArray* s1);
	static void logSSL(::java::util::function::Supplier* msgSupplier);
	static void logTrace($String* s, $ObjectArray* s1);
	static bool loggingFrame($Class* clazz);
	static bool requests();
	static bool ssl();
	static bool trace();
	static $String* logProp;
	static const int32_t OFF = 0;
	static const int32_t ERRORS = 1;
	static const int32_t REQUESTS = 2;
	static const int32_t HEADERS = 4;
	static const int32_t CONTENT = 8;
	static const int32_t FRAMES = 16;
	static const int32_t SSL = 32;
	static const int32_t TRACE = 64;
	static const int32_t CHANNEL = 128;
	static int32_t logging;
	static const int32_t CONTROL = 1;
	static const int32_t DATA = 2;
	static const int32_t WINDOW_UPDATES = 4;
	static const int32_t ALL = 7; // CONTROL | DATA | WINDOW_UPDATES
	static int32_t frametypes;
	static ::java::lang::System$Logger* logger;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("ALL")
#pragma pop_macro("CHANNEL")
#pragma pop_macro("CONTENT")
#pragma pop_macro("CONTROL")
#pragma pop_macro("DATA")
#pragma pop_macro("ERRORS")
#pragma pop_macro("FRAMES")
#pragma pop_macro("HEADERS")
#pragma pop_macro("OFF")
#pragma pop_macro("REQUESTS")
#pragma pop_macro("SSL")
#pragma pop_macro("TRACE")
#pragma pop_macro("WINDOW_UPDATES")

#endif // _jdk_internal_net_http_common_Log_h_