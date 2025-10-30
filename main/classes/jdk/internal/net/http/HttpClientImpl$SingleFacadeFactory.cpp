#include <jdk/internal/net/http/HttpClientImpl$SingleFacadeFactory.h>

#include <java/lang/AssertionError.h>
#include <jdk/internal/net/http/HttpClientFacade.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpClientFacade = ::jdk::internal::net::http::HttpClientFacade;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _HttpClientImpl$SingleFacadeFactory_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HttpClientImpl$SingleFacadeFactory, $assertionsDisabled)},
	{"facade", "Ljdk/internal/net/http/HttpClientFacade;", nullptr, 0, $field(HttpClientImpl$SingleFacadeFactory, facade)},
	{}
};

$MethodInfo _HttpClientImpl$SingleFacadeFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(HttpClientImpl$SingleFacadeFactory::*)()>(&HttpClientImpl$SingleFacadeFactory::init$))},
	{"createFacade", "(Ljdk/internal/net/http/HttpClientImpl;)Ljdk/internal/net/http/HttpClientFacade;", nullptr, 0, $method(static_cast<$HttpClientFacade*(HttpClientImpl$SingleFacadeFactory::*)($HttpClientImpl*)>(&HttpClientImpl$SingleFacadeFactory::createFacade))},
	{}
};

$InnerClassInfo _HttpClientImpl$SingleFacadeFactory_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.HttpClientImpl$SingleFacadeFactory", "jdk.internal.net.http.HttpClientImpl", "SingleFacadeFactory", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _HttpClientImpl$SingleFacadeFactory_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.HttpClientImpl$SingleFacadeFactory",
	"java.lang.Object",
	nullptr,
	_HttpClientImpl$SingleFacadeFactory_FieldInfo_,
	_HttpClientImpl$SingleFacadeFactory_MethodInfo_,
	nullptr,
	nullptr,
	_HttpClientImpl$SingleFacadeFactory_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HttpClientImpl"
};

$Object* allocate$HttpClientImpl$SingleFacadeFactory($Class* clazz) {
	return $of($alloc(HttpClientImpl$SingleFacadeFactory));
}

bool HttpClientImpl$SingleFacadeFactory::$assertionsDisabled = false;

void HttpClientImpl$SingleFacadeFactory::init$() {
}

$HttpClientFacade* HttpClientImpl$SingleFacadeFactory::createFacade($HttpClientImpl* impl) {
	if (!HttpClientImpl$SingleFacadeFactory::$assertionsDisabled && !(this->facade == nullptr)) {
		$throwNew($AssertionError);
	}
	return ($set(this, facade, $new($HttpClientFacade, impl)));
}

void clinit$HttpClientImpl$SingleFacadeFactory($Class* class$) {
	$load($HttpClientImpl);
	HttpClientImpl$SingleFacadeFactory::$assertionsDisabled = !$HttpClientImpl::class$->desiredAssertionStatus();
}

HttpClientImpl$SingleFacadeFactory::HttpClientImpl$SingleFacadeFactory() {
}

$Class* HttpClientImpl$SingleFacadeFactory::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$SingleFacadeFactory, name, initialize, &_HttpClientImpl$SingleFacadeFactory_ClassInfo_, clinit$HttpClientImpl$SingleFacadeFactory, allocate$HttpClientImpl$SingleFacadeFactory);
	return class$;
}

$Class* HttpClientImpl$SingleFacadeFactory::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk