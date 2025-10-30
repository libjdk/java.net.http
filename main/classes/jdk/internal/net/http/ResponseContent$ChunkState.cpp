#include <jdk/internal/net/http/ResponseContent$ChunkState.h>

#include <java/lang/Enum.h>
#include <jdk/internal/net/http/ResponseContent.h>
#include <jcpp.h>

#undef DONE
#undef READING_DATA
#undef READING_LENGTH

using $ResponseContent$ChunkStateArray = $Array<::jdk::internal::net::http::ResponseContent$ChunkState>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ResponseContent = ::jdk::internal::net::http::ResponseContent;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ResponseContent$ChunkState_FieldInfo_[] = {
	{"READING_LENGTH", "Ljdk/internal/net/http/ResponseContent$ChunkState;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(ResponseContent$ChunkState, READING_LENGTH)},
	{"READING_DATA", "Ljdk/internal/net/http/ResponseContent$ChunkState;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(ResponseContent$ChunkState, READING_DATA)},
	{"DONE", "Ljdk/internal/net/http/ResponseContent$ChunkState;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(ResponseContent$ChunkState, DONE)},
	{"$VALUES", "[Ljdk/internal/net/http/ResponseContent$ChunkState;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(ResponseContent$ChunkState, $VALUES)},
	{}
};

$MethodInfo _ResponseContent$ChunkState_MethodInfo_[] = {
	{"$values", "()[Ljdk/internal/net/http/ResponseContent$ChunkState;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$ResponseContent$ChunkStateArray*(*)()>(&ResponseContent$ChunkState::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(ResponseContent$ChunkState::*)($String*,int32_t)>(&ResponseContent$ChunkState::init$))},
	{"valueOf", "(Ljava/lang/String;)Ljdk/internal/net/http/ResponseContent$ChunkState;", nullptr, $PUBLIC | $STATIC, $method(static_cast<ResponseContent$ChunkState*(*)($String*)>(&ResponseContent$ChunkState::valueOf))},
	{"values", "()[Ljdk/internal/net/http/ResponseContent$ChunkState;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$ResponseContent$ChunkStateArray*(*)()>(&ResponseContent$ChunkState::values))},
	{}
};

$InnerClassInfo _ResponseContent$ChunkState_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseContent$ChunkState", "jdk.internal.net.http.ResponseContent", "ChunkState", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _ResponseContent$ChunkState_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"jdk.internal.net.http.ResponseContent$ChunkState",
	"java.lang.Enum",
	nullptr,
	_ResponseContent$ChunkState_FieldInfo_,
	_ResponseContent$ChunkState_MethodInfo_,
	"Ljava/lang/Enum<Ljdk/internal/net/http/ResponseContent$ChunkState;>;",
	nullptr,
	_ResponseContent$ChunkState_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseContent"
};

$Object* allocate$ResponseContent$ChunkState($Class* clazz) {
	return $of($alloc(ResponseContent$ChunkState));
}

ResponseContent$ChunkState* ResponseContent$ChunkState::READING_LENGTH = nullptr;
ResponseContent$ChunkState* ResponseContent$ChunkState::READING_DATA = nullptr;
ResponseContent$ChunkState* ResponseContent$ChunkState::DONE = nullptr;
$ResponseContent$ChunkStateArray* ResponseContent$ChunkState::$VALUES = nullptr;

$ResponseContent$ChunkStateArray* ResponseContent$ChunkState::$values() {
	$init(ResponseContent$ChunkState);
	return $new($ResponseContent$ChunkStateArray, {
		ResponseContent$ChunkState::READING_LENGTH,
		ResponseContent$ChunkState::READING_DATA,
		ResponseContent$ChunkState::DONE
	});
}

$ResponseContent$ChunkStateArray* ResponseContent$ChunkState::values() {
	$init(ResponseContent$ChunkState);
	return $cast($ResponseContent$ChunkStateArray, ResponseContent$ChunkState::$VALUES->clone());
}

ResponseContent$ChunkState* ResponseContent$ChunkState::valueOf($String* name) {
	$init(ResponseContent$ChunkState);
	return $cast(ResponseContent$ChunkState, $Enum::valueOf(ResponseContent$ChunkState::class$, name));
}

void ResponseContent$ChunkState::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void clinit$ResponseContent$ChunkState($Class* class$) {
	$assignStatic(ResponseContent$ChunkState::READING_LENGTH, $new(ResponseContent$ChunkState, "READING_LENGTH"_s, 0));
	$assignStatic(ResponseContent$ChunkState::READING_DATA, $new(ResponseContent$ChunkState, "READING_DATA"_s, 1));
	$assignStatic(ResponseContent$ChunkState::DONE, $new(ResponseContent$ChunkState, "DONE"_s, 2));
	$assignStatic(ResponseContent$ChunkState::$VALUES, ResponseContent$ChunkState::$values());
}

ResponseContent$ChunkState::ResponseContent$ChunkState() {
}

$Class* ResponseContent$ChunkState::load$($String* name, bool initialize) {
	$loadClass(ResponseContent$ChunkState, name, initialize, &_ResponseContent$ChunkState_ClassInfo_, clinit$ResponseContent$ChunkState, allocate$ResponseContent$ChunkState);
	return class$;
}

$Class* ResponseContent$ChunkState::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk