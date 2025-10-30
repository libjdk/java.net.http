#include <jdk/internal/net/http/Http1Response$2.h>

#include <java/lang/NoSuchFieldError.h>
#include <jdk/internal/net/http/Http1Response$State.h>
#include <jdk/internal/net/http/Http1Response.h>
#include <jcpp.h>

#undef READING_BODY
#undef READING_HEADERS

using $Http1Response$StateArray = $Array<::jdk::internal::net::http::Http1Response$State>;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $NoSuchFieldError = ::java::lang::NoSuchFieldError;
using $Http1Response = ::jdk::internal::net::http::Http1Response;
using $Http1Response$State = ::jdk::internal::net::http::Http1Response$State;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Http1Response$2_FieldInfo_[] = {
	{"$SwitchMap$jdk$internal$net$http$Http1Response$State", "[I", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http1Response$2, $SwitchMap$jdk$internal$net$http$Http1Response$State)},
	{}
};

$EnclosingMethodInfo _Http1Response$2_EnclosingMethodInfo_ = {
	"jdk.internal.net.http.Http1Response",
	nullptr,
	nullptr
};

$InnerClassInfo _Http1Response$2_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Response$2", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _Http1Response$2_ClassInfo_ = {
	$ACC_SUPER | $SYNTHETIC,
	"jdk.internal.net.http.Http1Response$2",
	"java.lang.Object",
	nullptr,
	_Http1Response$2_FieldInfo_,
	nullptr,
	nullptr,
	&_Http1Response$2_EnclosingMethodInfo_,
	_Http1Response$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Response"
};

$Object* allocate$Http1Response$2($Class* clazz) {
	return $of($alloc(Http1Response$2));
}

$ints* Http1Response$2::$SwitchMap$jdk$internal$net$http$Http1Response$State = nullptr;

void clinit$Http1Response$2($Class* class$) {
	$assignStatic(Http1Response$2::$SwitchMap$jdk$internal$net$http$Http1Response$State, $new($ints, $($Http1Response$State::values())->length));
	{
		try {
			$nc(Http1Response$2::$SwitchMap$jdk$internal$net$http$Http1Response$State)->set($Http1Response$State::READING_HEADERS->ordinal(), 1);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(Http1Response$2::$SwitchMap$jdk$internal$net$http$Http1Response$State)->set($Http1Response$State::READING_BODY->ordinal(), 2);
		} catch ($NoSuchFieldError& ex) {
		}
	}
}

Http1Response$2::Http1Response$2() {
}

$Class* Http1Response$2::load$($String* name, bool initialize) {
	$loadClass(Http1Response$2, name, initialize, &_Http1Response$2_ClassInfo_, clinit$Http1Response$2, allocate$Http1Response$2);
	return class$;
}

$Class* Http1Response$2::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk