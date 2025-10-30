#include <jdk/internal/net/http/common/BufferSupplier.h>

#include <java/nio/ByteBuffer.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Supplier = ::java::util::function::Supplier;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$MethodInfo _BufferSupplier_MethodInfo_[] = {
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT},
	{"recycle", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _BufferSupplier_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.common.BufferSupplier",
	nullptr,
	"java.util.function.Supplier",
	nullptr,
	_BufferSupplier_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/function/Supplier<Ljava/nio/ByteBuffer;>;"
};

$Object* allocate$BufferSupplier($Class* clazz) {
	return $of($alloc(BufferSupplier));
}

$Class* BufferSupplier::load$($String* name, bool initialize) {
	$loadClass(BufferSupplier, name, initialize, &_BufferSupplier_ClassInfo_, allocate$BufferSupplier);
	return class$;
}

$Class* BufferSupplier::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk