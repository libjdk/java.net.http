#include <jdk/internal/net/http/AuthenticationFilter$AuthInfo.h>

#include <java/lang/AssertionError.h>
#include <java/net/PasswordAuthentication.h>
#include <java/util/Objects.h>
#include <jdk/internal/net/http/AuthenticationFilter$CacheEntry.h>
#include <jdk/internal/net/http/AuthenticationFilter.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PasswordAuthentication = ::java::net::PasswordAuthentication;
using $Objects = ::java::util::Objects;
using $AuthenticationFilter = ::jdk::internal::net::http::AuthenticationFilter;
using $AuthenticationFilter$CacheEntry = ::jdk::internal::net::http::AuthenticationFilter$CacheEntry;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _AuthenticationFilter$AuthInfo_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(AuthenticationFilter$AuthInfo, $assertionsDisabled)},
	{"fromcache", "Z", nullptr, $FINAL, $field(AuthenticationFilter$AuthInfo, fromcache)},
	{"scheme", "Ljava/lang/String;", nullptr, $FINAL, $field(AuthenticationFilter$AuthInfo, scheme)},
	{"retries", "I", nullptr, 0, $field(AuthenticationFilter$AuthInfo, retries)},
	{"credentials", "Ljava/net/PasswordAuthentication;", nullptr, 0, $field(AuthenticationFilter$AuthInfo, credentials)},
	{"cacheEntry", "Ljdk/internal/net/http/AuthenticationFilter$CacheEntry;", nullptr, 0, $field(AuthenticationFilter$AuthInfo, cacheEntry)},
	{"isUTF8", "Z", nullptr, $FINAL, $field(AuthenticationFilter$AuthInfo, isUTF8)},
	{}
};

$MethodInfo _AuthenticationFilter$AuthInfo_MethodInfo_[] = {
	{"<init>", "(ZLjava/lang/String;Ljava/net/PasswordAuthentication;Z)V", nullptr, 0, $method(static_cast<void(AuthenticationFilter$AuthInfo::*)(bool,$String*,$PasswordAuthentication*,bool)>(&AuthenticationFilter$AuthInfo::init$))},
	{"<init>", "(ZLjava/lang/String;Ljava/net/PasswordAuthentication;Ljdk/internal/net/http/AuthenticationFilter$CacheEntry;Z)V", nullptr, 0, $method(static_cast<void(AuthenticationFilter$AuthInfo::*)(bool,$String*,$PasswordAuthentication*,$AuthenticationFilter$CacheEntry*,bool)>(&AuthenticationFilter$AuthInfo::init$))},
	{"retryWithCredentials", "(Ljava/net/PasswordAuthentication;Z)Ljdk/internal/net/http/AuthenticationFilter$AuthInfo;", nullptr, 0},
	{}
};

$InnerClassInfo _AuthenticationFilter$AuthInfo_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.AuthenticationFilter$AuthInfo", "jdk.internal.net.http.AuthenticationFilter", "AuthInfo", $STATIC},
	{}
};

$ClassInfo _AuthenticationFilter$AuthInfo_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.AuthenticationFilter$AuthInfo",
	"java.lang.Object",
	nullptr,
	_AuthenticationFilter$AuthInfo_FieldInfo_,
	_AuthenticationFilter$AuthInfo_MethodInfo_,
	nullptr,
	nullptr,
	_AuthenticationFilter$AuthInfo_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.AuthenticationFilter"
};

$Object* allocate$AuthenticationFilter$AuthInfo($Class* clazz) {
	return $of($alloc(AuthenticationFilter$AuthInfo));
}

bool AuthenticationFilter$AuthInfo::$assertionsDisabled = false;

void AuthenticationFilter$AuthInfo::init$(bool fromcache, $String* scheme, $PasswordAuthentication* credentials, bool isUTF8) {
	this->fromcache = fromcache;
	$set(this, scheme, scheme);
	$set(this, credentials, credentials);
	this->retries = 1;
	this->isUTF8 = isUTF8;
}

void AuthenticationFilter$AuthInfo::init$(bool fromcache, $String* scheme, $PasswordAuthentication* credentials, $AuthenticationFilter$CacheEntry* ca, bool isUTF8) {
	AuthenticationFilter$AuthInfo::init$(fromcache, scheme, credentials, isUTF8);
	if (!AuthenticationFilter$AuthInfo::$assertionsDisabled && !(credentials == nullptr || (ca != nullptr && ca->value$ == nullptr))) {
		$throwNew($AssertionError);
	}
	$set(this, cacheEntry, ca);
}

AuthenticationFilter$AuthInfo* AuthenticationFilter$AuthInfo::retryWithCredentials($PasswordAuthentication* pw, bool isUTF8) {
	$var(AuthenticationFilter$AuthInfo, res, this->fromcache ? $new(AuthenticationFilter$AuthInfo, false, this->scheme, pw, isUTF8) : this);
	$set($nc(res), credentials, $cast($PasswordAuthentication, $Objects::requireNonNull(pw)));
	res->retries = this->retries;
	return res;
}

void clinit$AuthenticationFilter$AuthInfo($Class* class$) {
	$load($AuthenticationFilter);
	AuthenticationFilter$AuthInfo::$assertionsDisabled = !$AuthenticationFilter::class$->desiredAssertionStatus();
}

AuthenticationFilter$AuthInfo::AuthenticationFilter$AuthInfo() {
}

$Class* AuthenticationFilter$AuthInfo::load$($String* name, bool initialize) {
	$loadClass(AuthenticationFilter$AuthInfo, name, initialize, &_AuthenticationFilter$AuthInfo_ClassInfo_, clinit$AuthenticationFilter$AuthInfo, allocate$AuthenticationFilter$AuthInfo);
	return class$;
}

$Class* AuthenticationFilter$AuthInfo::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk