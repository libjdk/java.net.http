#include <jdk/internal/net/http/common/Logger.h>

#include <java/lang/System$Logger$Level.h>
#include <java/util/function/Supplier.h>
#include <jcpp.h>

#undef DEBUG

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $System$Logger = ::java::lang::System$Logger;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $Supplier = ::java::util::function::Supplier;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$MethodInfo _Logger_MethodInfo_[] = {
	{"log", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"log", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/util/function/Supplier;Ljava/lang/Throwable;)V", "(Ljava/util/function/Supplier<Ljava/lang/String;>;Ljava/lang/Throwable;)V", $PUBLIC},
	{"log", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT},
	{"on", "()Z", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Logger_InnerClassesInfo_[] = {
	{"java.lang.System$Logger", "java.lang.System", "Logger", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Logger_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.common.Logger",
	nullptr,
	"java.lang.System$Logger",
	nullptr,
	_Logger_MethodInfo_,
	nullptr,
	nullptr,
	_Logger_InnerClassesInfo_
};

$Object* allocate$Logger($Class* clazz) {
	return $of($alloc(Logger));
}

bool Logger::on() {
	$init($System$Logger$Level);
	return isLoggable($System$Logger$Level::DEBUG);
}

void Logger::log($String* msg) {
	$init($System$Logger$Level);
	log($System$Logger$Level::DEBUG, msg);
}

void Logger::log($Supplier* msgSupplier) {
	$init($System$Logger$Level);
	log($System$Logger$Level::DEBUG, msgSupplier);
}

void Logger::log(Object$* obj) {
	$init($System$Logger$Level);
	log($System$Logger$Level::DEBUG, obj);
}

void Logger::log($String* msg, $Throwable* thrown) {
	$init($System$Logger$Level);
	this->log($System$Logger$Level::DEBUG, msg, thrown);
}

void Logger::log($Supplier* msgSupplier, $Throwable* thrown) {
	$init($System$Logger$Level);
	log($System$Logger$Level::DEBUG, msgSupplier, thrown);
}

void Logger::log($String* format, $ObjectArray* params) {
	$init($System$Logger$Level);
	log($System$Logger$Level::DEBUG, format, params);
}

$Class* Logger::load$($String* name, bool initialize) {
	$loadClass(Logger, name, initialize, &_Logger_ClassInfo_, allocate$Logger);
	return class$;
}

$Class* Logger::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk