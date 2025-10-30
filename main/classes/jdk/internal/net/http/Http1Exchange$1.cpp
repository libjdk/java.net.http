#include <jdk/internal/net/http/Http1Exchange$1.h>

#include <java/lang/NoSuchFieldError.h>
#include <jdk/internal/net/http/Http1Exchange$State.h>
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
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $NoSuchFieldError = ::java::lang::NoSuchFieldError;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;
using $Http1Exchange$State = ::jdk::internal::net::http::Http1Exchange$State;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Http1Exchange$1_FieldInfo_[] = {
	{"$SwitchMap$jdk$internal$net$http$Http1Exchange$State", "[I", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http1Exchange$1, $SwitchMap$jdk$internal$net$http$Http1Exchange$State)},
	{}
};

$EnclosingMethodInfo _Http1Exchange$1_EnclosingMethodInfo_ = {
	"jdk.internal.net.http.Http1Exchange",
	nullptr,
	nullptr
};

$InnerClassInfo _Http1Exchange$1_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Exchange$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _Http1Exchange$1_ClassInfo_ = {
	$ACC_SUPER | $SYNTHETIC,
	"jdk.internal.net.http.Http1Exchange$1",
	"java.lang.Object",
	nullptr,
	_Http1Exchange$1_FieldInfo_,
	nullptr,
	nullptr,
	&_Http1Exchange$1_EnclosingMethodInfo_,
	_Http1Exchange$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Exchange"
};

$Object* allocate$Http1Exchange$1($Class* clazz) {
	return $of($alloc(Http1Exchange$1));
}

$ints* Http1Exchange$1::$SwitchMap$jdk$internal$net$http$Http1Exchange$State = nullptr;

void clinit$Http1Exchange$1($Class* class$) {
	$assignStatic(Http1Exchange$1::$SwitchMap$jdk$internal$net$http$Http1Exchange$State, $new($ints, $($Http1Exchange$State::values())->length));
	{
		try {
			$nc(Http1Exchange$1::$SwitchMap$jdk$internal$net$http$Http1Exchange$State)->set($Http1Exchange$State::HEADERS->ordinal(), 1);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(Http1Exchange$1::$SwitchMap$jdk$internal$net$http$Http1Exchange$State)->set($Http1Exchange$State::BODY->ordinal(), 2);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(Http1Exchange$1::$SwitchMap$jdk$internal$net$http$Http1Exchange$State)->set($Http1Exchange$State::INITIAL->ordinal(), 3);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(Http1Exchange$1::$SwitchMap$jdk$internal$net$http$Http1Exchange$State)->set($Http1Exchange$State::ERROR->ordinal(), 4);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(Http1Exchange$1::$SwitchMap$jdk$internal$net$http$Http1Exchange$State)->set($Http1Exchange$State::COMPLETING->ordinal(), 5);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(Http1Exchange$1::$SwitchMap$jdk$internal$net$http$Http1Exchange$State)->set($Http1Exchange$State::COMPLETED->ordinal(), 6);
		} catch ($NoSuchFieldError& ex) {
		}
	}
}

Http1Exchange$1::Http1Exchange$1() {
}

$Class* Http1Exchange$1::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$1, name, initialize, &_Http1Exchange$1_ClassInfo_, clinit$Http1Exchange$1, allocate$Http1Exchange$1);
	return class$;
}

$Class* Http1Exchange$1::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk