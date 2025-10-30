#include <jdk/internal/net/http/ProxyAuthenticationRequired.h>

#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <jdk/internal/net/http/Response.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Response = ::jdk::internal::net::http::Response;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ProxyAuthenticationRequired_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ProxyAuthenticationRequired, $assertionsDisabled)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ProxyAuthenticationRequired, serialVersionUID)},
	{"proxyResponse", "Ljdk/internal/net/http/Response;", nullptr, $FINAL | $TRANSIENT, $field(ProxyAuthenticationRequired, proxyResponse)},
	{}
};

$MethodInfo _ProxyAuthenticationRequired_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Response;)V", nullptr, $PUBLIC, $method(static_cast<void(ProxyAuthenticationRequired::*)($Response*)>(&ProxyAuthenticationRequired::init$))},
	{}
};

$ClassInfo _ProxyAuthenticationRequired_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.ProxyAuthenticationRequired",
	"java.io.IOException",
	nullptr,
	_ProxyAuthenticationRequired_FieldInfo_,
	_ProxyAuthenticationRequired_MethodInfo_
};

$Object* allocate$ProxyAuthenticationRequired($Class* clazz) {
	return $of($alloc(ProxyAuthenticationRequired));
}

bool ProxyAuthenticationRequired::$assertionsDisabled = false;

void ProxyAuthenticationRequired::init$($Response* proxyResponse) {
	$IOException::init$("Proxy Authentication Required"_s);
	if (!ProxyAuthenticationRequired::$assertionsDisabled && !($nc(proxyResponse)->statusCode() == 407)) {
		$throwNew($AssertionError);
	}
	$set(this, proxyResponse, proxyResponse);
}

void clinit$ProxyAuthenticationRequired($Class* class$) {
	ProxyAuthenticationRequired::$assertionsDisabled = !ProxyAuthenticationRequired::class$->desiredAssertionStatus();
}

ProxyAuthenticationRequired::ProxyAuthenticationRequired() {
}

ProxyAuthenticationRequired::ProxyAuthenticationRequired(const ProxyAuthenticationRequired& e) : $IOException(e) {
}

void ProxyAuthenticationRequired::throw$() {
	throw *this;
}

$Class* ProxyAuthenticationRequired::load$($String* name, bool initialize) {
	$loadClass(ProxyAuthenticationRequired, name, initialize, &_ProxyAuthenticationRequired_ClassInfo_, clinit$ProxyAuthenticationRequired, allocate$ProxyAuthenticationRequired);
	return class$;
}

$Class* ProxyAuthenticationRequired::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk