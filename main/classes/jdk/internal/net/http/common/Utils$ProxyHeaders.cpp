#include <jdk/internal/net/http/common/Utils$ProxyHeaders.h>

#include <java/lang/Record.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/runtime/ObjectMethods.h>
#include <java/net/http/HttpHeaders.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

using $MethodHandleArray = $Array<::java::lang::invoke::MethodHandle>;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Record = ::java::lang::Record;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ObjectMethods = ::java::lang::runtime::ObjectMethods;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _Utils$ProxyHeaders_FieldInfo_[] = {
	{"userHeaders", "Ljava/net/http/HttpHeaders;", nullptr, $PRIVATE | $FINAL, $field(Utils$ProxyHeaders, userHeaders$)},
	{"systemHeaders", "Ljava/net/http/HttpHeaders;", nullptr, $PRIVATE | $FINAL, $field(Utils$ProxyHeaders, systemHeaders$)},
	{}
};

$MethodInfo _Utils$ProxyHeaders_MethodInfo_[] = {
	{"<init>", "(Ljava/net/http/HttpHeaders;Ljava/net/http/HttpHeaders;)V", nullptr, $PUBLIC, $method(static_cast<void(Utils$ProxyHeaders::*)($HttpHeaders*,$HttpHeaders*)>(&Utils$ProxyHeaders::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL},
	{"hashCode", "()I", nullptr, $PUBLIC | $FINAL},
	{"systemHeaders", "()Ljava/net/http/HttpHeaders;", nullptr, $PUBLIC, $method(static_cast<$HttpHeaders*(Utils$ProxyHeaders::*)()>(&Utils$ProxyHeaders::systemHeaders))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{"userHeaders", "()Ljava/net/http/HttpHeaders;", nullptr, $PUBLIC, $method(static_cast<$HttpHeaders*(Utils$ProxyHeaders::*)()>(&Utils$ProxyHeaders::userHeaders))},
	{}
};

$InnerClassInfo _Utils$ProxyHeaders_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.Utils$ProxyHeaders", "jdk.internal.net.http.common.Utils", "ProxyHeaders", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _Utils$ProxyHeaders_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.Utils$ProxyHeaders",
	"java.lang.Record",
	nullptr,
	_Utils$ProxyHeaders_FieldInfo_,
	_Utils$ProxyHeaders_MethodInfo_,
	nullptr,
	nullptr,
	_Utils$ProxyHeaders_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.Utils"
};

$Object* allocate$Utils$ProxyHeaders($Class* clazz) {
	return $of($alloc(Utils$ProxyHeaders));
}

void Utils$ProxyHeaders::init$($HttpHeaders* userHeaders, $HttpHeaders* systemHeaders) {
	$Record::init$();
	$set(this, userHeaders$, userHeaders);
	$set(this, systemHeaders$, systemHeaders);
}

$HttpHeaders* Utils$ProxyHeaders::userHeaders() {
	return this->userHeaders$;
}

$HttpHeaders* Utils$ProxyHeaders::systemHeaders() {
	return this->systemHeaders$;
}

$String* Utils$ProxyHeaders::toString() {
	$useLocalCurrentObjectStackCache();
	return $cast($String, $cast($MethodHandle, $($ObjectMethods::bootstrap($($MethodHandles::lookup()), "toString"_s, $($MethodType::methodType(nullptr)), Utils$ProxyHeaders::class$, "userHeaders;systemHeaders"_s, $$new($MethodHandleArray, {nullptr, nullptr}))))->invoke($$new($ObjectArray, {$of(this)})));
}

int32_t Utils$ProxyHeaders::hashCode() {
	$useLocalCurrentObjectStackCache();
	return $intValue($cast($MethodHandle, $($ObjectMethods::bootstrap($($MethodHandles::lookup()), "hashCode"_s, $($MethodType::methodType(nullptr)), Utils$ProxyHeaders::class$, "userHeaders;systemHeaders"_s, $$new($MethodHandleArray, {nullptr, nullptr}))))->invoke($$new($ObjectArray, {$of(this)})));
}

bool Utils$ProxyHeaders::equals(Object$* o) {
	$useLocalCurrentObjectStackCache();
	return $booleanValue($cast($MethodHandle, $($ObjectMethods::bootstrap($($MethodHandles::lookup()), "equals"_s, $($MethodType::methodType(nullptr)), Utils$ProxyHeaders::class$, "userHeaders;systemHeaders"_s, $$new($MethodHandleArray, {nullptr, nullptr}))))->invoke($$new($ObjectArray, {$of(this), o})));
}

Utils$ProxyHeaders::Utils$ProxyHeaders() {
}

$Class* Utils$ProxyHeaders::load$($String* name, bool initialize) {
	$loadClass(Utils$ProxyHeaders, name, initialize, &_Utils$ProxyHeaders_ClassInfo_, allocate$Utils$ProxyHeaders);
	return class$;
}

$Class* Utils$ProxyHeaders::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk