#include <jdk/internal/net/http/Http1HeaderParser$State.h>

#include <java/lang/Enum.h>
#include <jdk/internal/net/http/Http1HeaderParser.h>
#include <jcpp.h>

#undef FINISHED
#undef HEADER
#undef HEADER_FOUND_CR
#undef HEADER_FOUND_CR_LF
#undef HEADER_FOUND_CR_LF_CR
#undef HEADER_FOUND_LF
#undef INITIAL
#undef STATUS_LINE
#undef STATUS_LINE_END
#undef STATUS_LINE_END_CR
#undef STATUS_LINE_END_LF
#undef STATUS_LINE_FOUND_CR
#undef STATUS_LINE_FOUND_LF

using $Http1HeaderParser$StateArray = $Array<::jdk::internal::net::http::Http1HeaderParser$State>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Http1HeaderParser = ::jdk::internal::net::http::Http1HeaderParser;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Http1HeaderParser$State_FieldInfo_[] = {
	{"INITIAL", "Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1HeaderParser$State, INITIAL)},
	{"STATUS_LINE", "Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1HeaderParser$State, STATUS_LINE)},
	{"STATUS_LINE_FOUND_CR", "Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1HeaderParser$State, STATUS_LINE_FOUND_CR)},
	{"STATUS_LINE_FOUND_LF", "Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1HeaderParser$State, STATUS_LINE_FOUND_LF)},
	{"STATUS_LINE_END", "Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1HeaderParser$State, STATUS_LINE_END)},
	{"STATUS_LINE_END_CR", "Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1HeaderParser$State, STATUS_LINE_END_CR)},
	{"STATUS_LINE_END_LF", "Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1HeaderParser$State, STATUS_LINE_END_LF)},
	{"HEADER", "Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1HeaderParser$State, HEADER)},
	{"HEADER_FOUND_CR", "Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1HeaderParser$State, HEADER_FOUND_CR)},
	{"HEADER_FOUND_LF", "Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1HeaderParser$State, HEADER_FOUND_LF)},
	{"HEADER_FOUND_CR_LF", "Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1HeaderParser$State, HEADER_FOUND_CR_LF)},
	{"HEADER_FOUND_CR_LF_CR", "Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1HeaderParser$State, HEADER_FOUND_CR_LF_CR)},
	{"FINISHED", "Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Http1HeaderParser$State, FINISHED)},
	{"$VALUES", "[Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(Http1HeaderParser$State, $VALUES)},
	{}
};

$MethodInfo _Http1HeaderParser$State_MethodInfo_[] = {
	{"$values", "()[Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Http1HeaderParser$StateArray*(*)()>(&Http1HeaderParser$State::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(Http1HeaderParser$State::*)($String*,int32_t)>(&Http1HeaderParser$State::init$))},
	{"valueOf", "(Ljava/lang/String;)Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Http1HeaderParser$State*(*)($String*)>(&Http1HeaderParser$State::valueOf))},
	{"values", "()[Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Http1HeaderParser$StateArray*(*)()>(&Http1HeaderParser$State::values))},
	{}
};

$InnerClassInfo _Http1HeaderParser$State_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1HeaderParser$State", "jdk.internal.net.http.Http1HeaderParser", "State", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _Http1HeaderParser$State_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"jdk.internal.net.http.Http1HeaderParser$State",
	"java.lang.Enum",
	nullptr,
	_Http1HeaderParser$State_FieldInfo_,
	_Http1HeaderParser$State_MethodInfo_,
	"Ljava/lang/Enum<Ljdk/internal/net/http/Http1HeaderParser$State;>;",
	nullptr,
	_Http1HeaderParser$State_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1HeaderParser"
};

$Object* allocate$Http1HeaderParser$State($Class* clazz) {
	return $of($alloc(Http1HeaderParser$State));
}

Http1HeaderParser$State* Http1HeaderParser$State::INITIAL = nullptr;
Http1HeaderParser$State* Http1HeaderParser$State::STATUS_LINE = nullptr;
Http1HeaderParser$State* Http1HeaderParser$State::STATUS_LINE_FOUND_CR = nullptr;
Http1HeaderParser$State* Http1HeaderParser$State::STATUS_LINE_FOUND_LF = nullptr;
Http1HeaderParser$State* Http1HeaderParser$State::STATUS_LINE_END = nullptr;
Http1HeaderParser$State* Http1HeaderParser$State::STATUS_LINE_END_CR = nullptr;
Http1HeaderParser$State* Http1HeaderParser$State::STATUS_LINE_END_LF = nullptr;
Http1HeaderParser$State* Http1HeaderParser$State::HEADER = nullptr;
Http1HeaderParser$State* Http1HeaderParser$State::HEADER_FOUND_CR = nullptr;
Http1HeaderParser$State* Http1HeaderParser$State::HEADER_FOUND_LF = nullptr;
Http1HeaderParser$State* Http1HeaderParser$State::HEADER_FOUND_CR_LF = nullptr;
Http1HeaderParser$State* Http1HeaderParser$State::HEADER_FOUND_CR_LF_CR = nullptr;
Http1HeaderParser$State* Http1HeaderParser$State::FINISHED = nullptr;
$Http1HeaderParser$StateArray* Http1HeaderParser$State::$VALUES = nullptr;

$Http1HeaderParser$StateArray* Http1HeaderParser$State::$values() {
	$init(Http1HeaderParser$State);
	return $new($Http1HeaderParser$StateArray, {
		Http1HeaderParser$State::INITIAL,
		Http1HeaderParser$State::STATUS_LINE,
		Http1HeaderParser$State::STATUS_LINE_FOUND_CR,
		Http1HeaderParser$State::STATUS_LINE_FOUND_LF,
		Http1HeaderParser$State::STATUS_LINE_END,
		Http1HeaderParser$State::STATUS_LINE_END_CR,
		Http1HeaderParser$State::STATUS_LINE_END_LF,
		Http1HeaderParser$State::HEADER,
		Http1HeaderParser$State::HEADER_FOUND_CR,
		Http1HeaderParser$State::HEADER_FOUND_LF,
		Http1HeaderParser$State::HEADER_FOUND_CR_LF,
		Http1HeaderParser$State::HEADER_FOUND_CR_LF_CR,
		Http1HeaderParser$State::FINISHED
	});
}

$Http1HeaderParser$StateArray* Http1HeaderParser$State::values() {
	$init(Http1HeaderParser$State);
	return $cast($Http1HeaderParser$StateArray, Http1HeaderParser$State::$VALUES->clone());
}

Http1HeaderParser$State* Http1HeaderParser$State::valueOf($String* name) {
	$init(Http1HeaderParser$State);
	return $cast(Http1HeaderParser$State, $Enum::valueOf(Http1HeaderParser$State::class$, name));
}

void Http1HeaderParser$State::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void clinit$Http1HeaderParser$State($Class* class$) {
	$assignStatic(Http1HeaderParser$State::INITIAL, $new(Http1HeaderParser$State, "INITIAL"_s, 0));
	$assignStatic(Http1HeaderParser$State::STATUS_LINE, $new(Http1HeaderParser$State, "STATUS_LINE"_s, 1));
	$assignStatic(Http1HeaderParser$State::STATUS_LINE_FOUND_CR, $new(Http1HeaderParser$State, "STATUS_LINE_FOUND_CR"_s, 2));
	$assignStatic(Http1HeaderParser$State::STATUS_LINE_FOUND_LF, $new(Http1HeaderParser$State, "STATUS_LINE_FOUND_LF"_s, 3));
	$assignStatic(Http1HeaderParser$State::STATUS_LINE_END, $new(Http1HeaderParser$State, "STATUS_LINE_END"_s, 4));
	$assignStatic(Http1HeaderParser$State::STATUS_LINE_END_CR, $new(Http1HeaderParser$State, "STATUS_LINE_END_CR"_s, 5));
	$assignStatic(Http1HeaderParser$State::STATUS_LINE_END_LF, $new(Http1HeaderParser$State, "STATUS_LINE_END_LF"_s, 6));
	$assignStatic(Http1HeaderParser$State::HEADER, $new(Http1HeaderParser$State, "HEADER"_s, 7));
	$assignStatic(Http1HeaderParser$State::HEADER_FOUND_CR, $new(Http1HeaderParser$State, "HEADER_FOUND_CR"_s, 8));
	$assignStatic(Http1HeaderParser$State::HEADER_FOUND_LF, $new(Http1HeaderParser$State, "HEADER_FOUND_LF"_s, 9));
	$assignStatic(Http1HeaderParser$State::HEADER_FOUND_CR_LF, $new(Http1HeaderParser$State, "HEADER_FOUND_CR_LF"_s, 10));
	$assignStatic(Http1HeaderParser$State::HEADER_FOUND_CR_LF_CR, $new(Http1HeaderParser$State, "HEADER_FOUND_CR_LF_CR"_s, 11));
	$assignStatic(Http1HeaderParser$State::FINISHED, $new(Http1HeaderParser$State, "FINISHED"_s, 12));
	$assignStatic(Http1HeaderParser$State::$VALUES, Http1HeaderParser$State::$values());
}

Http1HeaderParser$State::Http1HeaderParser$State() {
}

$Class* Http1HeaderParser$State::load$($String* name, bool initialize) {
	$loadClass(Http1HeaderParser$State, name, initialize, &_Http1HeaderParser$State_ClassInfo_, clinit$Http1HeaderParser$State, allocate$Http1HeaderParser$State);
	return class$;
}

$Class* Http1HeaderParser$State::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk