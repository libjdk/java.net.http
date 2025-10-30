#include <jdk/internal/net/http/hpack/HPACK$RootLogger.h>

#include <jdk/internal/net/http/hpack/HPACK$Logger$Level.h>
#include <jdk/internal/net/http/hpack/HPACK$Logger.h>
#include <jdk/internal/net/http/hpack/HPACK.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HPACK = ::jdk::internal::net::http::hpack::HPACK;
using $HPACK$Logger = ::jdk::internal::net::http::hpack::HPACK$Logger;
using $HPACK$Logger$Level = ::jdk::internal::net::http::hpack::HPACK$Logger$Level;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$MethodInfo _HPACK$RootLogger_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/HPACK$Logger$Level;)V", nullptr, $PROTECTED, $method(static_cast<void(HPACK$RootLogger::*)($HPACK$Logger$Level*)>(&HPACK$RootLogger::init$))},
	{}
};

$InnerClassInfo _HPACK$RootLogger_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.HPACK$RootLogger", "jdk.internal.net.http.hpack.HPACK", "RootLogger", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.HPACK$Logger", "jdk.internal.net.http.hpack.HPACK", "Logger", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _HPACK$RootLogger_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.HPACK$RootLogger",
	"jdk.internal.net.http.hpack.HPACK$Logger",
	nullptr,
	nullptr,
	_HPACK$RootLogger_MethodInfo_,
	nullptr,
	nullptr,
	_HPACK$RootLogger_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.HPACK"
};

$Object* allocate$HPACK$RootLogger($Class* clazz) {
	return $of($alloc(HPACK$RootLogger));
}

void HPACK$RootLogger::init$($HPACK$Logger$Level* level) {
	$HPACK$Logger::init$("hpack"_s, "hpack"_s, level);
}

HPACK$RootLogger::HPACK$RootLogger() {
}

$Class* HPACK$RootLogger::load$($String* name, bool initialize) {
	$loadClass(HPACK$RootLogger, name, initialize, &_HPACK$RootLogger_ClassInfo_, allocate$HPACK$RootLogger);
	return class$;
}

$Class* HPACK$RootLogger::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk