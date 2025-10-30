#include <jdk/internal/net/http/hpack/Decoder$State.h>

#include <java/lang/Enum.h>
#include <jdk/internal/net/http/hpack/Decoder.h>
#include <jcpp.h>

#undef INDEXED
#undef LITERAL
#undef LITERAL_NEVER_INDEXED
#undef LITERAL_WITH_INDEXING
#undef READY
#undef SIZE_UPDATE

using $Decoder$StateArray = $Array<::jdk::internal::net::http::hpack::Decoder$State>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Decoder = ::jdk::internal::net::http::hpack::Decoder;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _Decoder$State_FieldInfo_[] = {
	{"READY", "Ljdk/internal/net/http/hpack/Decoder$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Decoder$State, READY)},
	{"INDEXED", "Ljdk/internal/net/http/hpack/Decoder$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Decoder$State, INDEXED)},
	{"LITERAL_NEVER_INDEXED", "Ljdk/internal/net/http/hpack/Decoder$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Decoder$State, LITERAL_NEVER_INDEXED)},
	{"LITERAL", "Ljdk/internal/net/http/hpack/Decoder$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Decoder$State, LITERAL)},
	{"LITERAL_WITH_INDEXING", "Ljdk/internal/net/http/hpack/Decoder$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Decoder$State, LITERAL_WITH_INDEXING)},
	{"SIZE_UPDATE", "Ljdk/internal/net/http/hpack/Decoder$State;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(Decoder$State, SIZE_UPDATE)},
	{"$VALUES", "[Ljdk/internal/net/http/hpack/Decoder$State;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(Decoder$State, $VALUES)},
	{}
};

$MethodInfo _Decoder$State_MethodInfo_[] = {
	{"$values", "()[Ljdk/internal/net/http/hpack/Decoder$State;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Decoder$StateArray*(*)()>(&Decoder$State::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(Decoder$State::*)($String*,int32_t)>(&Decoder$State::init$))},
	{"valueOf", "(Ljava/lang/String;)Ljdk/internal/net/http/hpack/Decoder$State;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Decoder$State*(*)($String*)>(&Decoder$State::valueOf))},
	{"values", "()[Ljdk/internal/net/http/hpack/Decoder$State;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Decoder$StateArray*(*)()>(&Decoder$State::values))},
	{}
};

$InnerClassInfo _Decoder$State_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.Decoder$State", "jdk.internal.net.http.hpack.Decoder", "State", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _Decoder$State_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"jdk.internal.net.http.hpack.Decoder$State",
	"java.lang.Enum",
	nullptr,
	_Decoder$State_FieldInfo_,
	_Decoder$State_MethodInfo_,
	"Ljava/lang/Enum<Ljdk/internal/net/http/hpack/Decoder$State;>;",
	nullptr,
	_Decoder$State_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.Decoder"
};

$Object* allocate$Decoder$State($Class* clazz) {
	return $of($alloc(Decoder$State));
}

Decoder$State* Decoder$State::READY = nullptr;
Decoder$State* Decoder$State::INDEXED = nullptr;
Decoder$State* Decoder$State::LITERAL_NEVER_INDEXED = nullptr;
Decoder$State* Decoder$State::LITERAL = nullptr;
Decoder$State* Decoder$State::LITERAL_WITH_INDEXING = nullptr;
Decoder$State* Decoder$State::SIZE_UPDATE = nullptr;
$Decoder$StateArray* Decoder$State::$VALUES = nullptr;

$Decoder$StateArray* Decoder$State::$values() {
	$init(Decoder$State);
	return $new($Decoder$StateArray, {
		Decoder$State::READY,
		Decoder$State::INDEXED,
		Decoder$State::LITERAL_NEVER_INDEXED,
		Decoder$State::LITERAL,
		Decoder$State::LITERAL_WITH_INDEXING,
		Decoder$State::SIZE_UPDATE
	});
}

$Decoder$StateArray* Decoder$State::values() {
	$init(Decoder$State);
	return $cast($Decoder$StateArray, Decoder$State::$VALUES->clone());
}

Decoder$State* Decoder$State::valueOf($String* name) {
	$init(Decoder$State);
	return $cast(Decoder$State, $Enum::valueOf(Decoder$State::class$, name));
}

void Decoder$State::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void clinit$Decoder$State($Class* class$) {
	$assignStatic(Decoder$State::READY, $new(Decoder$State, "READY"_s, 0));
	$assignStatic(Decoder$State::INDEXED, $new(Decoder$State, "INDEXED"_s, 1));
	$assignStatic(Decoder$State::LITERAL_NEVER_INDEXED, $new(Decoder$State, "LITERAL_NEVER_INDEXED"_s, 2));
	$assignStatic(Decoder$State::LITERAL, $new(Decoder$State, "LITERAL"_s, 3));
	$assignStatic(Decoder$State::LITERAL_WITH_INDEXING, $new(Decoder$State, "LITERAL_WITH_INDEXING"_s, 4));
	$assignStatic(Decoder$State::SIZE_UPDATE, $new(Decoder$State, "SIZE_UPDATE"_s, 5));
	$assignStatic(Decoder$State::$VALUES, Decoder$State::$values());
}

Decoder$State::Decoder$State() {
}

$Class* Decoder$State::load$($String* name, bool initialize) {
	$loadClass(Decoder$State, name, initialize, &_Decoder$State_ClassInfo_, clinit$Decoder$State, allocate$Decoder$State);
	return class$;
}

$Class* Decoder$State::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk