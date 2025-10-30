#include <jdk/internal/net/http/RedirectFilter$1.h>

#include <java/lang/NoSuchFieldError.h>
#include <java/net/http/HttpClient$Redirect.h>
#include <java/net/http/HttpClient.h>
#include <jdk/internal/net/http/RedirectFilter.h>
#include <jcpp.h>

#undef ALWAYS
#undef NEVER
#undef NORMAL

using $HttpClient$RedirectArray = $Array<::java::net::http::HttpClient$Redirect>;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $NoSuchFieldError = ::java::lang::NoSuchFieldError;
using $HttpClient = ::java::net::http::HttpClient;
using $HttpClient$Redirect = ::java::net::http::HttpClient$Redirect;
using $RedirectFilter = ::jdk::internal::net::http::RedirectFilter;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _RedirectFilter$1_FieldInfo_[] = {
	{"$SwitchMap$java$net$http$HttpClient$Redirect", "[I", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(RedirectFilter$1, $SwitchMap$java$net$http$HttpClient$Redirect)},
	{}
};

$EnclosingMethodInfo _RedirectFilter$1_EnclosingMethodInfo_ = {
	"jdk.internal.net.http.RedirectFilter",
	nullptr,
	nullptr
};

$InnerClassInfo _RedirectFilter$1_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RedirectFilter$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _RedirectFilter$1_ClassInfo_ = {
	$ACC_SUPER | $SYNTHETIC,
	"jdk.internal.net.http.RedirectFilter$1",
	"java.lang.Object",
	nullptr,
	_RedirectFilter$1_FieldInfo_,
	nullptr,
	nullptr,
	&_RedirectFilter$1_EnclosingMethodInfo_,
	_RedirectFilter$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RedirectFilter"
};

$Object* allocate$RedirectFilter$1($Class* clazz) {
	return $of($alloc(RedirectFilter$1));
}

$ints* RedirectFilter$1::$SwitchMap$java$net$http$HttpClient$Redirect = nullptr;

void clinit$RedirectFilter$1($Class* class$) {
	$assignStatic(RedirectFilter$1::$SwitchMap$java$net$http$HttpClient$Redirect, $new($ints, $($HttpClient$Redirect::values())->length));
	{
		try {
			$nc(RedirectFilter$1::$SwitchMap$java$net$http$HttpClient$Redirect)->set($HttpClient$Redirect::ALWAYS->ordinal(), 1);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(RedirectFilter$1::$SwitchMap$java$net$http$HttpClient$Redirect)->set($HttpClient$Redirect::NEVER->ordinal(), 2);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(RedirectFilter$1::$SwitchMap$java$net$http$HttpClient$Redirect)->set($HttpClient$Redirect::NORMAL->ordinal(), 3);
		} catch ($NoSuchFieldError& ex) {
		}
	}
}

RedirectFilter$1::RedirectFilter$1() {
}

$Class* RedirectFilter$1::load$($String* name, bool initialize) {
	$loadClass(RedirectFilter$1, name, initialize, &_RedirectFilter$1_ClassInfo_, clinit$RedirectFilter$1, allocate$RedirectFilter$1);
	return class$;
}

$Class* RedirectFilter$1::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk