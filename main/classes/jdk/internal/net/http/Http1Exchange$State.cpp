#include <jdk/internal/net/http/Http1Exchange$State.h>

#include <java/lang/Enum.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jcpp.h>

#undef BODY
#undef COMPLETED
#undef COMPLETING
#undef ERROR
#undef HEADERS
#undef INITIAL

using $Http1Exchange$StateArray = $Array<::jdk::internal::net::http::Http1Exchange$State>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Http1Exchange$State_FieldInfo_[] = {
	{"INITIAL", "Ljdk/internal/net/http/Http1Exchange$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1Exchange$State, INITIAL)},
	{"HEADERS", "Ljdk/internal/net/http/Http1Exchange$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1Exchange$State, HEADERS)},
	{"BODY", "Ljdk/internal/net/http/Http1Exchange$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1Exchange$State, BODY)},
	{"ERROR", "Ljdk/internal/net/http/Http1Exchange$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1Exchange$State, ERROR)},
	{"COMPLETING", "Ljdk/internal/net/http/Http1Exchange$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1Exchange$State, COMPLETING)},
	{"COMPLETED", "Ljdk/internal/net/http/Http1Exchange$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1Exchange$State, COMPLETED)},
	{"$VALUES", "[Ljdk/internal/net/http/Http1Exchange$State;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(Http1Exchange$State, $VALUES)},
	{}
};

$MethodInfo _Http1Exchange$State_MethodInfo_[] = {
	{"$values", "()[Ljdk/internal/net/http/Http1Exchange$State;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Http1Exchange$StateArray*(*)()>(&Http1Exchange$State::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(Http1Exchange$State::*)($String*,int32_t)>(&Http1Exchange$State::init$))},
	{"valueOf", "(Ljava/lang/String;)Ljdk/internal/net/http/Http1Exchange$State;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Http1Exchange$State*(*)($String*)>(&Http1Exchange$State::valueOf))},
	{"values", "()[Ljdk/internal/net/http/Http1Exchange$State;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Http1Exchange$StateArray*(*)()>(&Http1Exchange$State::values))},
	{}
};

$InnerClassInfo _Http1Exchange$State_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Exchange$State", "jdk.internal.net.http.Http1Exchange", "State", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _Http1Exchange$State_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"jdk.internal.net.http.Http1Exchange$State",
	"java.lang.Enum",
	nullptr,
	_Http1Exchange$State_FieldInfo_,
	_Http1Exchange$State_MethodInfo_,
	"Ljava/lang/Enum<Ljdk/internal/net/http/Http1Exchange$State;>;",
	nullptr,
	_Http1Exchange$State_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Exchange"
};

$Object* allocate$Http1Exchange$State($Class* clazz) {
	return $of($alloc(Http1Exchange$State));
}

Http1Exchange$State* Http1Exchange$State::INITIAL = nullptr;
Http1Exchange$State* Http1Exchange$State::HEADERS = nullptr;
Http1Exchange$State* Http1Exchange$State::BODY = nullptr;
Http1Exchange$State* Http1Exchange$State::ERROR = nullptr;
Http1Exchange$State* Http1Exchange$State::COMPLETING = nullptr;
Http1Exchange$State* Http1Exchange$State::COMPLETED = nullptr;
$Http1Exchange$StateArray* Http1Exchange$State::$VALUES = nullptr;

$Http1Exchange$StateArray* Http1Exchange$State::$values() {
	$init(Http1Exchange$State);
	return $new($Http1Exchange$StateArray, {
		Http1Exchange$State::INITIAL,
		Http1Exchange$State::HEADERS,
		Http1Exchange$State::BODY,
		Http1Exchange$State::ERROR,
		Http1Exchange$State::COMPLETING,
		Http1Exchange$State::COMPLETED
	});
}

$Http1Exchange$StateArray* Http1Exchange$State::values() {
	$init(Http1Exchange$State);
	return $cast($Http1Exchange$StateArray, Http1Exchange$State::$VALUES->clone());
}

Http1Exchange$State* Http1Exchange$State::valueOf($String* name) {
	$init(Http1Exchange$State);
	return $cast(Http1Exchange$State, $Enum::valueOf(Http1Exchange$State::class$, name));
}

void Http1Exchange$State::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void clinit$Http1Exchange$State($Class* class$) {
	$assignStatic(Http1Exchange$State::INITIAL, $new(Http1Exchange$State, "INITIAL"_s, 0));
	$assignStatic(Http1Exchange$State::HEADERS, $new(Http1Exchange$State, "HEADERS"_s, 1));
	$assignStatic(Http1Exchange$State::BODY, $new(Http1Exchange$State, "BODY"_s, 2));
	$assignStatic(Http1Exchange$State::ERROR, $new(Http1Exchange$State, "ERROR"_s, 3));
	$assignStatic(Http1Exchange$State::COMPLETING, $new(Http1Exchange$State, "COMPLETING"_s, 4));
	$assignStatic(Http1Exchange$State::COMPLETED, $new(Http1Exchange$State, "COMPLETED"_s, 5));
	$assignStatic(Http1Exchange$State::$VALUES, Http1Exchange$State::$values());
}

Http1Exchange$State::Http1Exchange$State() {
}

$Class* Http1Exchange$State::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$State, name, initialize, &_Http1Exchange$State_ClassInfo_, clinit$Http1Exchange$State, allocate$Http1Exchange$State);
	return class$;
}

$Class* Http1Exchange$State::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk