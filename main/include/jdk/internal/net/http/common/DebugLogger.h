#ifndef _jdk_internal_net_http_common_DebugLogger_h_
#define _jdk_internal_net_http_common_DebugLogger_h_
//$ class jdk.internal.net.http.common.DebugLogger
//$ extends jdk.internal.net.http.common.Logger

#include <java/lang/Array.h>
#include <jdk/internal/net/http/common/Logger.h>

#pragma push_macro("HPACK")
#undef HPACK
#pragma push_macro("HPACK_NAME")
#undef HPACK_NAME
#pragma push_macro("HTTP")
#undef HTTP
#pragma push_macro("HTTP_NAME")
#undef HTTP_NAME
#pragma push_macro("NO_HPACK_LOGGER")
#undef NO_HPACK_LOGGER
#pragma push_macro("NO_HTTP_LOGGER")
#undef NO_HTTP_LOGGER
#pragma push_macro("NO_WS_LOGGER")
#undef NO_WS_LOGGER
#pragma push_macro("START_NANOS")
#undef START_NANOS
#pragma push_macro("WS")
#undef WS
#pragma push_macro("WS_NAME")
#undef WS_NAME

namespace java {
	namespace io {
		class PrintStream;
	}
}
namespace java {
	namespace lang {
		class StringBuilder;
		class System$Logger;
		class System$Logger$Level;
		class Throwable;
	}
}
namespace java {
	namespace util {
		class ResourceBundle;
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
				namespace common {

class $import DebugLogger : public ::jdk::internal::net::http::common::Logger {
	$class(DebugLogger, 0, ::jdk::internal::net::http::common::Logger)
public:
	DebugLogger();
	void init$(::java::lang::System$Logger* logger, ::java::util::function::Supplier* dbgTag, ::java::lang::System$Logger$Level* outLevel, ::java::lang::System$Logger$Level* errLevel);
	static ::jdk::internal::net::http::common::DebugLogger* createHpackLogger(::java::util::function::Supplier* dbgTag, ::java::lang::System$Logger$Level* outLevel, ::java::lang::System$Logger$Level* errLevel);
	static ::jdk::internal::net::http::common::DebugLogger* createHttpLogger(::java::util::function::Supplier* dbgTag, ::java::lang::System$Logger$Level* outLevel, ::java::lang::System$Logger$Level* errLevel);
	static ::jdk::internal::net::http::common::DebugLogger* createWebSocketLogger(::java::util::function::Supplier* dbgTag, ::java::lang::System$Logger$Level* outLevel, ::java::lang::System$Logger$Level* errLevel);
	::java::lang::StringBuilder* decorate(::java::lang::StringBuilder* sb, $String* msg);
	::java::lang::StringBuilder* format(::java::lang::StringBuilder* sb, $String* format, $ObjectArray* params);
	::java::lang::StringBuilder* getFormat(::java::lang::StringBuilder* sb, $String* format, $ObjectArray* params);
	virtual $String* getName() override;
	bool isEnabled(::java::lang::System$Logger$Level* level);
	virtual bool isLoggable(::java::lang::System$Logger$Level* level) override;
	static bool levelEnabledFor(::java::lang::System$Logger$Level* level, ::java::lang::System$Logger$Level* outLevel, ::java::lang::System$Logger$Level* errLevel, ::java::lang::System$Logger* logger);
	using ::jdk::internal::net::http::common::Logger::log;
	virtual void log(::java::lang::System$Logger$Level* level, ::java::util::ResourceBundle* unused, $String* format, $ObjectArray* params) override;
	virtual void log(::java::lang::System$Logger$Level* level, ::java::util::ResourceBundle* unused, $String* msg, $Throwable* thrown) override;
	virtual bool on() override;
	void print(::java::io::PrintStream* out, ::java::lang::System$Logger$Level* level, $String* msg, $ObjectArray* params, $Throwable* t);
	static $String* HTTP_NAME;
	static $String* WS_NAME;
	static $String* HPACK_NAME;
	static ::java::lang::System$Logger* HTTP;
	static ::java::lang::System$Logger* WS;
	static ::java::lang::System$Logger* HPACK;
	static ::jdk::internal::net::http::common::DebugLogger* NO_HTTP_LOGGER;
	static ::jdk::internal::net::http::common::DebugLogger* NO_WS_LOGGER;
	static ::jdk::internal::net::http::common::DebugLogger* NO_HPACK_LOGGER;
	static int64_t START_NANOS;
	::java::util::function::Supplier* dbgTag = nullptr;
	::java::lang::System$Logger$Level* errLevel = nullptr;
	::java::lang::System$Logger$Level* outLevel = nullptr;
	::java::lang::System$Logger* logger = nullptr;
	bool debugOn = false;
	bool traceOn = false;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("HPACK")
#pragma pop_macro("HPACK_NAME")
#pragma pop_macro("HTTP")
#pragma pop_macro("HTTP_NAME")
#pragma pop_macro("NO_HPACK_LOGGER")
#pragma pop_macro("NO_HTTP_LOGGER")
#pragma pop_macro("NO_WS_LOGGER")
#pragma pop_macro("START_NANOS")
#pragma pop_macro("WS")
#pragma pop_macro("WS_NAME")

#endif // _jdk_internal_net_http_common_DebugLogger_h_