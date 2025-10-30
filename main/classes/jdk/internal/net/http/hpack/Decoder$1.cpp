#include <jdk/internal/net/http/hpack/Decoder$1.h>

#include <java/lang/NoSuchFieldError.h>
#include <jdk/internal/net/http/hpack/Decoder$State.h>
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
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $NoSuchFieldError = ::java::lang::NoSuchFieldError;
using $Decoder = ::jdk::internal::net::http::hpack::Decoder;
using $Decoder$State = ::jdk::internal::net::http::hpack::Decoder$State;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _Decoder$1_FieldInfo_[] = {
	{"$SwitchMap$jdk$internal$net$http$hpack$Decoder$State", "[I", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Decoder$1, $SwitchMap$jdk$internal$net$http$hpack$Decoder$State)},
	{}
};

$EnclosingMethodInfo _Decoder$1_EnclosingMethodInfo_ = {
	"jdk.internal.net.http.hpack.Decoder",
	nullptr,
	nullptr
};

$InnerClassInfo _Decoder$1_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.Decoder$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _Decoder$1_ClassInfo_ = {
	$ACC_SUPER | $SYNTHETIC,
	"jdk.internal.net.http.hpack.Decoder$1",
	"java.lang.Object",
	nullptr,
	_Decoder$1_FieldInfo_,
	nullptr,
	nullptr,
	&_Decoder$1_EnclosingMethodInfo_,
	_Decoder$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.Decoder"
};

$Object* allocate$Decoder$1($Class* clazz) {
	return $of($alloc(Decoder$1));
}

$ints* Decoder$1::$SwitchMap$jdk$internal$net$http$hpack$Decoder$State = nullptr;

void clinit$Decoder$1($Class* class$) {
	$assignStatic(Decoder$1::$SwitchMap$jdk$internal$net$http$hpack$Decoder$State, $new($ints, $($Decoder$State::values())->length));
	{
		try {
			$nc(Decoder$1::$SwitchMap$jdk$internal$net$http$hpack$Decoder$State)->set($Decoder$State::READY->ordinal(), 1);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(Decoder$1::$SwitchMap$jdk$internal$net$http$hpack$Decoder$State)->set($Decoder$State::INDEXED->ordinal(), 2);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(Decoder$1::$SwitchMap$jdk$internal$net$http$hpack$Decoder$State)->set($Decoder$State::LITERAL->ordinal(), 3);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(Decoder$1::$SwitchMap$jdk$internal$net$http$hpack$Decoder$State)->set($Decoder$State::LITERAL_WITH_INDEXING->ordinal(), 4);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(Decoder$1::$SwitchMap$jdk$internal$net$http$hpack$Decoder$State)->set($Decoder$State::LITERAL_NEVER_INDEXED->ordinal(), 5);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(Decoder$1::$SwitchMap$jdk$internal$net$http$hpack$Decoder$State)->set($Decoder$State::SIZE_UPDATE->ordinal(), 6);
		} catch ($NoSuchFieldError& ex) {
		}
	}
}

Decoder$1::Decoder$1() {
}

$Class* Decoder$1::load$($String* name, bool initialize) {
	$loadClass(Decoder$1, name, initialize, &_Decoder$1_ClassInfo_, clinit$Decoder$1, allocate$Decoder$1);
	return class$;
}

$Class* Decoder$1::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk