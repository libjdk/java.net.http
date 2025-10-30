#include <java/net/http/HttpClient$Redirect.h>

#include <java/lang/Enum.h>
#include <java/net/http/HttpClient.h>
#include <jcpp.h>

#undef ALWAYS
#undef NEVER
#undef NORMAL

using $HttpClient$RedirectArray = $Array<::java::net::http::HttpClient$Redirect>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpClient = ::java::net::http::HttpClient;

namespace java {
	namespace net {
		namespace http {

$FieldInfo _HttpClient$Redirect_FieldInfo_[] = {
	{"NEVER", "Ljava/net/http/HttpClient$Redirect;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(HttpClient$Redirect, NEVER)},
	{"ALWAYS", "Ljava/net/http/HttpClient$Redirect;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(HttpClient$Redirect, ALWAYS)},
	{"NORMAL", "Ljava/net/http/HttpClient$Redirect;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(HttpClient$Redirect, NORMAL)},
	{"$VALUES", "[Ljava/net/http/HttpClient$Redirect;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(HttpClient$Redirect, $VALUES)},
	{}
};

$MethodInfo _HttpClient$Redirect_MethodInfo_[] = {
	{"$values", "()[Ljava/net/http/HttpClient$Redirect;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpClient$RedirectArray*(*)()>(&HttpClient$Redirect::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(HttpClient$Redirect::*)($String*,int32_t)>(&HttpClient$Redirect::init$))},
	{"valueOf", "(Ljava/lang/String;)Ljava/net/http/HttpClient$Redirect;", nullptr, $PUBLIC | $STATIC, $method(static_cast<HttpClient$Redirect*(*)($String*)>(&HttpClient$Redirect::valueOf))},
	{"values", "()[Ljava/net/http/HttpClient$Redirect;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$HttpClient$RedirectArray*(*)()>(&HttpClient$Redirect::values))},
	{}
};

$InnerClassInfo _HttpClient$Redirect_InnerClassesInfo_[] = {
	{"java.net.http.HttpClient$Redirect", "java.net.http.HttpClient", "Redirect", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _HttpClient$Redirect_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER | $ENUM,
	"java.net.http.HttpClient$Redirect",
	"java.lang.Enum",
	nullptr,
	_HttpClient$Redirect_FieldInfo_,
	_HttpClient$Redirect_MethodInfo_,
	"Ljava/lang/Enum<Ljava/net/http/HttpClient$Redirect;>;",
	nullptr,
	_HttpClient$Redirect_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.net.http.HttpClient"
};

$Object* allocate$HttpClient$Redirect($Class* clazz) {
	return $of($alloc(HttpClient$Redirect));
}

HttpClient$Redirect* HttpClient$Redirect::NEVER = nullptr;
HttpClient$Redirect* HttpClient$Redirect::ALWAYS = nullptr;
HttpClient$Redirect* HttpClient$Redirect::NORMAL = nullptr;
$HttpClient$RedirectArray* HttpClient$Redirect::$VALUES = nullptr;

$HttpClient$RedirectArray* HttpClient$Redirect::$values() {
	$init(HttpClient$Redirect);
	return $new($HttpClient$RedirectArray, {
		HttpClient$Redirect::NEVER,
		HttpClient$Redirect::ALWAYS,
		HttpClient$Redirect::NORMAL
	});
}

$HttpClient$RedirectArray* HttpClient$Redirect::values() {
	$init(HttpClient$Redirect);
	return $cast($HttpClient$RedirectArray, HttpClient$Redirect::$VALUES->clone());
}

HttpClient$Redirect* HttpClient$Redirect::valueOf($String* name) {
	$init(HttpClient$Redirect);
	return $cast(HttpClient$Redirect, $Enum::valueOf(HttpClient$Redirect::class$, name));
}

void HttpClient$Redirect::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void clinit$HttpClient$Redirect($Class* class$) {
	$assignStatic(HttpClient$Redirect::NEVER, $new(HttpClient$Redirect, "NEVER"_s, 0));
	$assignStatic(HttpClient$Redirect::ALWAYS, $new(HttpClient$Redirect, "ALWAYS"_s, 1));
	$assignStatic(HttpClient$Redirect::NORMAL, $new(HttpClient$Redirect, "NORMAL"_s, 2));
	$assignStatic(HttpClient$Redirect::$VALUES, HttpClient$Redirect::$values());
}

HttpClient$Redirect::HttpClient$Redirect() {
}

$Class* HttpClient$Redirect::load$($String* name, bool initialize) {
	$loadClass(HttpClient$Redirect, name, initialize, &_HttpClient$Redirect_ClassInfo_, clinit$HttpClient$Redirect, allocate$HttpClient$Redirect);
	return class$;
}

$Class* HttpClient$Redirect::class$ = nullptr;

		} // http
	} // net
} // java