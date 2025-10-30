#include <jdk/internal/net/http/Http1Response$1.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$MethodInfo _Http1Response$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(Http1Response$1::*)()>(&Http1Response$1::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"request", "(J)V", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _Http1Response$1_EnclosingMethodInfo_ = {
	"jdk.internal.net.http.Http1Response",
	nullptr,
	nullptr
};

$InnerClassInfo _Http1Response$1_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Response$1", nullptr, nullptr, 0},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Http1Response$1_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.Http1Response$1",
	"java.lang.Object",
	"java.util.concurrent.Flow$Subscription",
	nullptr,
	_Http1Response$1_MethodInfo_,
	nullptr,
	&_Http1Response$1_EnclosingMethodInfo_,
	_Http1Response$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Response"
};

$Object* allocate$Http1Response$1($Class* clazz) {
	return $of($alloc(Http1Response$1));
}

void Http1Response$1::init$() {
}

void Http1Response$1::request(int64_t n) {
}

void Http1Response$1::cancel() {
}

Http1Response$1::Http1Response$1() {
}

$Class* Http1Response$1::load$($String* name, bool initialize) {
	$loadClass(Http1Response$1, name, initialize, &_Http1Response$1_ClassInfo_, allocate$Http1Response$1);
	return class$;
}

$Class* Http1Response$1::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk