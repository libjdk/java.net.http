#include <jdk/internal/net/http/PlainHttpConnection$ConnectState.h>

#include <java/lang/Enum.h>
#include <jdk/internal/net/http/PlainHttpConnection.h>
#include <jcpp.h>

#undef RETRY
#undef SUCCESS

using $PlainHttpConnection$ConnectStateArray = $Array<::jdk::internal::net::http::PlainHttpConnection$ConnectState>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PlainHttpConnection = ::jdk::internal::net::http::PlainHttpConnection;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _PlainHttpConnection$ConnectState_FieldInfo_[] = {
	{"SUCCESS", "Ljdk/internal/net/http/PlainHttpConnection$ConnectState;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(PlainHttpConnection$ConnectState, SUCCESS)},
	{"RETRY", "Ljdk/internal/net/http/PlainHttpConnection$ConnectState;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(PlainHttpConnection$ConnectState, RETRY)},
	{"$VALUES", "[Ljdk/internal/net/http/PlainHttpConnection$ConnectState;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(PlainHttpConnection$ConnectState, $VALUES)},
	{}
};

$MethodInfo _PlainHttpConnection$ConnectState_MethodInfo_[] = {
	{"$values", "()[Ljdk/internal/net/http/PlainHttpConnection$ConnectState;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$PlainHttpConnection$ConnectStateArray*(*)()>(&PlainHttpConnection$ConnectState::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(PlainHttpConnection$ConnectState::*)($String*,int32_t)>(&PlainHttpConnection$ConnectState::init$))},
	{"valueOf", "(Ljava/lang/String;)Ljdk/internal/net/http/PlainHttpConnection$ConnectState;", nullptr, $PUBLIC | $STATIC, $method(static_cast<PlainHttpConnection$ConnectState*(*)($String*)>(&PlainHttpConnection$ConnectState::valueOf))},
	{"values", "()[Ljdk/internal/net/http/PlainHttpConnection$ConnectState;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$PlainHttpConnection$ConnectStateArray*(*)()>(&PlainHttpConnection$ConnectState::values))},
	{}
};

$InnerClassInfo _PlainHttpConnection$ConnectState_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.PlainHttpConnection$ConnectState", "jdk.internal.net.http.PlainHttpConnection", "ConnectState", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _PlainHttpConnection$ConnectState_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"jdk.internal.net.http.PlainHttpConnection$ConnectState",
	"java.lang.Enum",
	nullptr,
	_PlainHttpConnection$ConnectState_FieldInfo_,
	_PlainHttpConnection$ConnectState_MethodInfo_,
	"Ljava/lang/Enum<Ljdk/internal/net/http/PlainHttpConnection$ConnectState;>;",
	nullptr,
	_PlainHttpConnection$ConnectState_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.PlainHttpConnection"
};

$Object* allocate$PlainHttpConnection$ConnectState($Class* clazz) {
	return $of($alloc(PlainHttpConnection$ConnectState));
}

PlainHttpConnection$ConnectState* PlainHttpConnection$ConnectState::SUCCESS = nullptr;
PlainHttpConnection$ConnectState* PlainHttpConnection$ConnectState::RETRY = nullptr;
$PlainHttpConnection$ConnectStateArray* PlainHttpConnection$ConnectState::$VALUES = nullptr;

$PlainHttpConnection$ConnectStateArray* PlainHttpConnection$ConnectState::$values() {
	$init(PlainHttpConnection$ConnectState);
	return $new($PlainHttpConnection$ConnectStateArray, {
		PlainHttpConnection$ConnectState::SUCCESS,
		PlainHttpConnection$ConnectState::RETRY
	});
}

$PlainHttpConnection$ConnectStateArray* PlainHttpConnection$ConnectState::values() {
	$init(PlainHttpConnection$ConnectState);
	return $cast($PlainHttpConnection$ConnectStateArray, PlainHttpConnection$ConnectState::$VALUES->clone());
}

PlainHttpConnection$ConnectState* PlainHttpConnection$ConnectState::valueOf($String* name) {
	$init(PlainHttpConnection$ConnectState);
	return $cast(PlainHttpConnection$ConnectState, $Enum::valueOf(PlainHttpConnection$ConnectState::class$, name));
}

void PlainHttpConnection$ConnectState::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void clinit$PlainHttpConnection$ConnectState($Class* class$) {
	$assignStatic(PlainHttpConnection$ConnectState::SUCCESS, $new(PlainHttpConnection$ConnectState, "SUCCESS"_s, 0));
	$assignStatic(PlainHttpConnection$ConnectState::RETRY, $new(PlainHttpConnection$ConnectState, "RETRY"_s, 1));
	$assignStatic(PlainHttpConnection$ConnectState::$VALUES, PlainHttpConnection$ConnectState::$values());
}

PlainHttpConnection$ConnectState::PlainHttpConnection$ConnectState() {
}

$Class* PlainHttpConnection$ConnectState::load$($String* name, bool initialize) {
	$loadClass(PlainHttpConnection$ConnectState, name, initialize, &_PlainHttpConnection$ConnectState_ClassInfo_, clinit$PlainHttpConnection$ConnectState, allocate$PlainHttpConnection$ConnectState);
	return class$;
}

$Class* PlainHttpConnection$ConnectState::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk