#ifndef _jdk_internal_net_http_hpack_HPACK$Logger_h_
#define _jdk_internal_net_http_hpack_HPACK$Logger_h_
//$ class jdk.internal.net.http.hpack.HPACK$Logger
//$ extends java.lang.System$Logger

#include <java/lang/Array.h>
#include <java/lang/System$Logger.h>

namespace java {
	namespace lang {
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

class HPACK$Logger : public ::java::lang::System$Logger {
	$class(HPACK$Logger, $NO_CLASS_INIT, ::java::lang::System$Logger)
public:
	HPACK$Logger();
	void init$($String* path, $String* name, ::jdk::internal::net::http::hpack::HPACK$Logger$Level* level);
	void init$($String* p, $String* name, ::jdk::internal::net::http::hpack::HPACK$Logger$Level* level, ::java::lang::System$Logger* logger);
	virtual $String* getName() override;
	virtual bool isLoggable(::java::lang::System$Logger$Level* level) override;
	virtual bool isLoggable(::jdk::internal::net::http::hpack::HPACK$Logger$Level* level);
	using ::java::lang::System$Logger::log;
	virtual void log(::java::lang::System$Logger$Level* level, ::java::util::ResourceBundle* bundle, $String* msg, $Throwable* thrown) override;
	virtual void log(::java::lang::System$Logger$Level* level, ::java::util::ResourceBundle* bundle, $String* format, $ObjectArray* params) override;
	virtual void log(::jdk::internal::net::http::hpack::HPACK$Logger$Level* level, ::java::util::function::Supplier* s);
	virtual ::jdk::internal::net::http::hpack::HPACK$Logger* subLogger($String* name);
	$String* name = nullptr;
	::jdk::internal::net::http::hpack::HPACK$Logger$Level* level = nullptr;
	$String* path = nullptr;
	::java::lang::System$Logger* logger = nullptr;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_HPACK$Logger_h_