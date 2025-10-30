#include <jdk/internal/net/http/hpack/HPACK$Logger.h>

#include <java/io/Serializable.h>
#include <java/lang/System$Logger$Level.h>
#include <java/lang/System$Logger.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/ResourceBundle.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/hpack/HPACK$Logger$Level.h>
#include <jdk/internal/net/http/hpack/HPACK.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $System$Logger = ::java::lang::System$Logger;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Supplier = ::java::util::function::Supplier;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $HPACK = ::jdk::internal::net::http::hpack::HPACK;
using $HPACK$Logger$Level = ::jdk::internal::net::http::hpack::HPACK$Logger$Level;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class HPACK$Logger$$Lambda$toString : public $Supplier {
	$class(HPACK$Logger$$Lambda$toString, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HPACK$Logger$$Lambda$toString>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HPACK$Logger$$Lambda$toString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HPACK$Logger$$Lambda$toString, inst$)},
	{}
};
$MethodInfo HPACK$Logger$$Lambda$toString::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(HPACK$Logger$$Lambda$toString::*)($String*)>(&HPACK$Logger$$Lambda$toString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HPACK$Logger$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.HPACK$Logger$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* HPACK$Logger$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(HPACK$Logger$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HPACK$Logger$$Lambda$toString::class$ = nullptr;

$FieldInfo _HPACK$Logger_FieldInfo_[] = {
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(HPACK$Logger, name)},
	{"level", "Ljdk/internal/net/http/hpack/HPACK$Logger$Level;", nullptr, $PRIVATE | $FINAL, $field(HPACK$Logger, level)},
	{"path", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(HPACK$Logger, path)},
	{"logger", "Ljava/lang/System$Logger;", nullptr, $PRIVATE | $FINAL, $field(HPACK$Logger, logger)},
	{}
};

$MethodInfo _HPACK$Logger_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljdk/internal/net/http/hpack/HPACK$Logger$Level;)V", nullptr, $PRIVATE, $method(static_cast<void(HPACK$Logger::*)($String*,$String*,$HPACK$Logger$Level*)>(&HPACK$Logger::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljdk/internal/net/http/hpack/HPACK$Logger$Level;Ljava/lang/System$Logger;)V", nullptr, $PRIVATE, $method(static_cast<void(HPACK$Logger::*)($String*,$String*,$HPACK$Logger$Level*,$System$Logger*)>(&HPACK$Logger::init$))},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{"isLoggable", "(Ljava/lang/System$Logger$Level;)Z", nullptr, $PUBLIC},
	{"isLoggable", "(Ljdk/internal/net/http/hpack/HPACK$Logger$Level;)Z", nullptr, $PUBLIC},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/util/ResourceBundle;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/util/ResourceBundle;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT},
	{"log", "(Ljdk/internal/net/http/hpack/HPACK$Logger$Level;Ljava/util/function/Supplier;)V", "(Ljdk/internal/net/http/hpack/HPACK$Logger$Level;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"subLogger", "(Ljava/lang/String;)Ljdk/internal/net/http/hpack/HPACK$Logger;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _HPACK$Logger_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.HPACK$Logger", "jdk.internal.net.http.hpack.HPACK", "Logger", $PUBLIC | $STATIC},
	{"java.lang.System$Logger", "java.lang.System", "Logger", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.hpack.HPACK$Logger$Level", "jdk.internal.net.http.hpack.HPACK$Logger", "Level", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _HPACK$Logger_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.hpack.HPACK$Logger",
	"java.lang.Object",
	"java.lang.System$Logger",
	_HPACK$Logger_FieldInfo_,
	_HPACK$Logger_MethodInfo_,
	nullptr,
	nullptr,
	_HPACK$Logger_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.HPACK"
};

$Object* allocate$HPACK$Logger($Class* clazz) {
	return $of($alloc(HPACK$Logger));
}

void HPACK$Logger::init$($String* path, $String* name, $HPACK$Logger$Level* level) {
	HPACK$Logger::init$(path, name, level, nullptr);
}

void HPACK$Logger::init$($String* p, $String* name, $HPACK$Logger$Level* level, $System$Logger* logger) {
	$set(this, path, p);
	$set(this, name, name);
	$set(this, level, level);
	$set(this, logger, $Utils::getHpackLogger(static_cast<$Supplier*>($$new(HPACK$Logger$$Lambda$toString, static_cast<$String*>($nc(this->path)))), $nc(level)->systemLevel));
}

$String* HPACK$Logger::getName() {
	return this->name;
}

bool HPACK$Logger::isLoggable($System$Logger$Level* level) {
	return $nc(this->logger)->isLoggable(level);
}

void HPACK$Logger::log($System$Logger$Level* level, $ResourceBundle* bundle, $String* msg, $Throwable* thrown) {
	$nc(this->logger)->log(level, bundle, msg, thrown);
}

void HPACK$Logger::log($System$Logger$Level* level, $ResourceBundle* bundle, $String* format, $ObjectArray* params) {
	$nc(this->logger)->log(level, bundle, format, params);
}

bool HPACK$Logger::isLoggable($HPACK$Logger$Level* level) {
	return this->level->implies(level);
}

void HPACK$Logger::log($HPACK$Logger$Level* level, $Supplier* s) {
	if (this->level->implies(level)) {
		$nc(this->logger)->log($nc(level)->systemLevel, s);
	}
}

HPACK$Logger* HPACK$Logger::subLogger($String* name) {
	return $new(HPACK$Logger, $$str({this->path, "/"_s, name}), name, this->level);
}

HPACK$Logger::HPACK$Logger() {
}

$Class* HPACK$Logger::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HPACK$Logger$$Lambda$toString::classInfo$.name)) {
			return HPACK$Logger$$Lambda$toString::load$(name, initialize);
		}
	}
	$loadClass(HPACK$Logger, name, initialize, &_HPACK$Logger_ClassInfo_, allocate$HPACK$Logger);
	return class$;
}

$Class* HPACK$Logger::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk