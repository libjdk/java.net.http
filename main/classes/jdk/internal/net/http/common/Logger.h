#ifndef _jdk_internal_net_http_common_Logger_h_
#define _jdk_internal_net_http_common_Logger_h_
//$ interface jdk.internal.net.http.common.Logger
//$ extends java.lang.System$Logger

#include <java/lang/Array.h>
#include <java/lang/System$Logger.h>

namespace java {
	namespace lang {
		class Throwable;
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

class $export Logger : public ::java::lang::System$Logger {
	$interface(Logger, $NO_CLASS_INIT, ::java::lang::System$Logger)
public:
	using ::java::lang::System$Logger::log;
	virtual void log($String* msg);
	virtual void log(::java::util::function::Supplier* msgSupplier);
	virtual void log(Object$* obj);
	virtual void log($String* msg, $Throwable* thrown);
	virtual void log(::java::util::function::Supplier* msgSupplier, $Throwable* thrown);
	virtual void log($String* format, $ObjectArray* params);
	virtual bool on();
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_Logger_h_