#include <jdk/internal/net/http/hpack/HPACK$Logger$Level.h>

#include <java/lang/Enum.h>
#include <java/lang/System$Logger$Level.h>
#include <jdk/internal/net/http/hpack/HPACK$Logger.h>
#include <jcpp.h>

#undef DEBUG
#undef EXTRA
#undef NONE
#undef NORMAL
#undef OFF
#undef TRACE

using $HPACK$Logger$LevelArray = $Array<::jdk::internal::net::http::hpack::HPACK$Logger$Level>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $HPACK$Logger = ::jdk::internal::net::http::hpack::HPACK$Logger;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _HPACK$Logger$Level_FieldInfo_[] = {
	{"NONE", "Ljdk/internal/net/http/hpack/HPACK$Logger$Level;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(HPACK$Logger$Level, NONE)},
	{"NORMAL", "Ljdk/internal/net/http/hpack/HPACK$Logger$Level;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(HPACK$Logger$Level, NORMAL)},
	{"EXTRA", "Ljdk/internal/net/http/hpack/HPACK$Logger$Level;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(HPACK$Logger$Level, EXTRA)},
	{"$VALUES", "[Ljdk/internal/net/http/hpack/HPACK$Logger$Level;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(HPACK$Logger$Level, $VALUES)},
	{"level", "I", nullptr, $PRIVATE | $FINAL, $field(HPACK$Logger$Level, level)},
	{"systemLevel", "Ljava/lang/System$Logger$Level;", nullptr, $FINAL, $field(HPACK$Logger$Level, systemLevel)},
	{}
};

$MethodInfo _HPACK$Logger$Level_MethodInfo_[] = {
	{"$values", "()[Ljdk/internal/net/http/hpack/HPACK$Logger$Level;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HPACK$Logger$LevelArray*(*)()>(&HPACK$Logger$Level::$values))},
	{"<init>", "(Ljava/lang/String;IILjava/lang/System$Logger$Level;)V", "(ILjava/lang/System$Logger$Level;)V", $PRIVATE, $method(static_cast<void(HPACK$Logger$Level::*)($String*,int32_t,int32_t,$System$Logger$Level*)>(&HPACK$Logger$Level::init$))},
	{"implies", "(Ljdk/internal/net/http/hpack/HPACK$Logger$Level;)Z", nullptr, $PUBLIC | $FINAL, $method(static_cast<bool(HPACK$Logger$Level::*)(HPACK$Logger$Level*)>(&HPACK$Logger$Level::implies))},
	{"valueOf", "(Ljava/lang/String;)Ljdk/internal/net/http/hpack/HPACK$Logger$Level;", nullptr, $PUBLIC | $STATIC, $method(static_cast<HPACK$Logger$Level*(*)($String*)>(&HPACK$Logger$Level::valueOf))},
	{"values", "()[Ljdk/internal/net/http/hpack/HPACK$Logger$Level;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$HPACK$Logger$LevelArray*(*)()>(&HPACK$Logger$Level::values))},
	{}
};

$InnerClassInfo _HPACK$Logger$Level_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.HPACK$Logger", "jdk.internal.net.http.hpack.HPACK", "Logger", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.hpack.HPACK$Logger$Level", "jdk.internal.net.http.hpack.HPACK$Logger", "Level", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _HPACK$Logger$Level_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER | $ENUM,
	"jdk.internal.net.http.hpack.HPACK$Logger$Level",
	"java.lang.Enum",
	nullptr,
	_HPACK$Logger$Level_FieldInfo_,
	_HPACK$Logger$Level_MethodInfo_,
	"Ljava/lang/Enum<Ljdk/internal/net/http/hpack/HPACK$Logger$Level;>;",
	nullptr,
	_HPACK$Logger$Level_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.HPACK"
};

$Object* allocate$HPACK$Logger$Level($Class* clazz) {
	return $of($alloc(HPACK$Logger$Level));
}

HPACK$Logger$Level* HPACK$Logger$Level::NONE = nullptr;
HPACK$Logger$Level* HPACK$Logger$Level::NORMAL = nullptr;
HPACK$Logger$Level* HPACK$Logger$Level::EXTRA = nullptr;
$HPACK$Logger$LevelArray* HPACK$Logger$Level::$VALUES = nullptr;

$HPACK$Logger$LevelArray* HPACK$Logger$Level::$values() {
	$init(HPACK$Logger$Level);
	return $new($HPACK$Logger$LevelArray, {
		HPACK$Logger$Level::NONE,
		HPACK$Logger$Level::NORMAL,
		HPACK$Logger$Level::EXTRA
	});
}

$HPACK$Logger$LevelArray* HPACK$Logger$Level::values() {
	$init(HPACK$Logger$Level);
	return $cast($HPACK$Logger$LevelArray, HPACK$Logger$Level::$VALUES->clone());
}

HPACK$Logger$Level* HPACK$Logger$Level::valueOf($String* name) {
	$init(HPACK$Logger$Level);
	return $cast(HPACK$Logger$Level, $Enum::valueOf(HPACK$Logger$Level::class$, name));
}

void HPACK$Logger$Level::init$($String* $enum$name, int32_t $enum$ordinal, int32_t i, $System$Logger$Level* system) {
	$Enum::init$($enum$name, $enum$ordinal);
	this->level = i;
	$set(this, systemLevel, system);
}

bool HPACK$Logger$Level::implies(HPACK$Logger$Level* other) {
	return this->level >= $nc(other)->level;
}

void clinit$HPACK$Logger$Level($Class* class$) {
	$init($System$Logger$Level);
	$assignStatic(HPACK$Logger$Level::NONE, $new(HPACK$Logger$Level, "NONE"_s, 0, 0, $System$Logger$Level::OFF));
	$assignStatic(HPACK$Logger$Level::NORMAL, $new(HPACK$Logger$Level, "NORMAL"_s, 1, 1, $System$Logger$Level::DEBUG));
	$assignStatic(HPACK$Logger$Level::EXTRA, $new(HPACK$Logger$Level, "EXTRA"_s, 2, 2, $System$Logger$Level::TRACE));
	$assignStatic(HPACK$Logger$Level::$VALUES, HPACK$Logger$Level::$values());
}

HPACK$Logger$Level::HPACK$Logger$Level() {
}

$Class* HPACK$Logger$Level::load$($String* name, bool initialize) {
	$loadClass(HPACK$Logger$Level, name, initialize, &_HPACK$Logger$Level_ClassInfo_, clinit$HPACK$Logger$Level, allocate$HPACK$Logger$Level);
	return class$;
}

$Class* HPACK$Logger$Level::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk