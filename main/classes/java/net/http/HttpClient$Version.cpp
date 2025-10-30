#include <java/net/http/HttpClient$Version.h>

#include <java/lang/Enum.h>
#include <java/net/http/HttpClient.h>
#include <jcpp.h>

#undef HTTP_1_1
#undef HTTP_2

using $HttpClient$VersionArray = $Array<::java::net::http::HttpClient$Version>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpClient = ::java::net::http::HttpClient;

namespace java {
	namespace net {
		namespace http {

$FieldInfo _HttpClient$Version_FieldInfo_[] = {
	{"HTTP_1_1", "Ljava/net/http/HttpClient$Version;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(HttpClient$Version, HTTP_1_1)},
	{"HTTP_2", "Ljava/net/http/HttpClient$Version;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(HttpClient$Version, HTTP_2)},
	{"$VALUES", "[Ljava/net/http/HttpClient$Version;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(HttpClient$Version, $VALUES)},
	{}
};

$MethodInfo _HttpClient$Version_MethodInfo_[] = {
	{"$values", "()[Ljava/net/http/HttpClient$Version;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpClient$VersionArray*(*)()>(&HttpClient$Version::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(HttpClient$Version::*)($String*,int32_t)>(&HttpClient$Version::init$))},
	{"valueOf", "(Ljava/lang/String;)Ljava/net/http/HttpClient$Version;", nullptr, $PUBLIC | $STATIC, $method(static_cast<HttpClient$Version*(*)($String*)>(&HttpClient$Version::valueOf))},
	{"values", "()[Ljava/net/http/HttpClient$Version;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$HttpClient$VersionArray*(*)()>(&HttpClient$Version::values))},
	{}
};

$InnerClassInfo _HttpClient$Version_InnerClassesInfo_[] = {
	{"java.net.http.HttpClient$Version", "java.net.http.HttpClient", "Version", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _HttpClient$Version_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER | $ENUM,
	"java.net.http.HttpClient$Version",
	"java.lang.Enum",
	nullptr,
	_HttpClient$Version_FieldInfo_,
	_HttpClient$Version_MethodInfo_,
	"Ljava/lang/Enum<Ljava/net/http/HttpClient$Version;>;",
	nullptr,
	_HttpClient$Version_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.net.http.HttpClient"
};

$Object* allocate$HttpClient$Version($Class* clazz) {
	return $of($alloc(HttpClient$Version));
}

HttpClient$Version* HttpClient$Version::HTTP_1_1 = nullptr;
HttpClient$Version* HttpClient$Version::HTTP_2 = nullptr;
$HttpClient$VersionArray* HttpClient$Version::$VALUES = nullptr;

$HttpClient$VersionArray* HttpClient$Version::$values() {
	$init(HttpClient$Version);
	return $new($HttpClient$VersionArray, {
		HttpClient$Version::HTTP_1_1,
		HttpClient$Version::HTTP_2
	});
}

$HttpClient$VersionArray* HttpClient$Version::values() {
	$init(HttpClient$Version);
	return $cast($HttpClient$VersionArray, HttpClient$Version::$VALUES->clone());
}

HttpClient$Version* HttpClient$Version::valueOf($String* name) {
	$init(HttpClient$Version);
	return $cast(HttpClient$Version, $Enum::valueOf(HttpClient$Version::class$, name));
}

void HttpClient$Version::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

void clinit$HttpClient$Version($Class* class$) {
	$assignStatic(HttpClient$Version::HTTP_1_1, $new(HttpClient$Version, "HTTP_1_1"_s, 0));
	$assignStatic(HttpClient$Version::HTTP_2, $new(HttpClient$Version, "HTTP_2"_s, 1));
	$assignStatic(HttpClient$Version::$VALUES, HttpClient$Version::$values());
}

HttpClient$Version::HttpClient$Version() {
}

$Class* HttpClient$Version::load$($String* name, bool initialize) {
	$loadClass(HttpClient$Version, name, initialize, &_HttpClient$Version_ClassInfo_, clinit$HttpClient$Version, allocate$HttpClient$Version);
	return class$;
}

$Class* HttpClient$Version::class$ = nullptr;

		} // http
	} // net
} // java