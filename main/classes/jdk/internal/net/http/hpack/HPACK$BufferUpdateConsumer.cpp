#include <jdk/internal/net/http/hpack/HPACK$BufferUpdateConsumer.h>

#include <jdk/internal/net/http/hpack/HPACK.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HPACK = ::jdk::internal::net::http::hpack::HPACK;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$CompoundAttribute _HPACK$BufferUpdateConsumer_Annotations_[] = {
	{"Ljava/lang/FunctionalInterface;", nullptr},
	{}
};

$MethodInfo _HPACK$BufferUpdateConsumer_MethodInfo_[] = {
	{"accept", "(JI)V", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _HPACK$BufferUpdateConsumer_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.HPACK$BufferUpdateConsumer", "jdk.internal.net.http.hpack.HPACK", "BufferUpdateConsumer", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HPACK$BufferUpdateConsumer_ClassInfo_ = {
	$INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.hpack.HPACK$BufferUpdateConsumer",
	nullptr,
	nullptr,
	nullptr,
	_HPACK$BufferUpdateConsumer_MethodInfo_,
	nullptr,
	nullptr,
	_HPACK$BufferUpdateConsumer_InnerClassesInfo_,
	_HPACK$BufferUpdateConsumer_Annotations_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.HPACK"
};

$Object* allocate$HPACK$BufferUpdateConsumer($Class* clazz) {
	return $of($alloc(HPACK$BufferUpdateConsumer));
}

$Class* HPACK$BufferUpdateConsumer::load$($String* name, bool initialize) {
	$loadClass(HPACK$BufferUpdateConsumer, name, initialize, &_HPACK$BufferUpdateConsumer_ClassInfo_, allocate$HPACK$BufferUpdateConsumer);
	return class$;
}

$Class* HPACK$BufferUpdateConsumer::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk