#include <jdk/internal/net/http/hpack/ISO_8859_1.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$MethodInfo _ISO_8859_1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(ISO_8859_1::*)()>(&ISO_8859_1::init$))},
	{}
};

$InnerClassInfo _ISO_8859_1_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.ISO_8859_1$Writer", "jdk.internal.net.http.hpack.ISO_8859_1", "Writer", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.ISO_8859_1$Reader", "jdk.internal.net.http.hpack.ISO_8859_1", "Reader", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _ISO_8859_1_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.ISO_8859_1",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ISO_8859_1_MethodInfo_,
	nullptr,
	nullptr,
	_ISO_8859_1_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.ISO_8859_1$Writer,jdk.internal.net.http.hpack.ISO_8859_1$Reader"
};

$Object* allocate$ISO_8859_1($Class* clazz) {
	return $of($alloc(ISO_8859_1));
}

void ISO_8859_1::init$() {
}

ISO_8859_1::ISO_8859_1() {
}

$Class* ISO_8859_1::load$($String* name, bool initialize) {
	$loadClass(ISO_8859_1, name, initialize, &_ISO_8859_1_ClassInfo_, allocate$ISO_8859_1);
	return class$;
}

$Class* ISO_8859_1::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk