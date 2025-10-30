#include <jdk/internal/net/http/hpack/BinaryRepresentationWriter.h>

#include <java/nio/ByteBuffer.h>
#include <jdk/internal/net/http/hpack/HeaderTable.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $HeaderTable = ::jdk::internal::net::http::hpack::HeaderTable;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$MethodInfo _BinaryRepresentationWriter_MethodInfo_[] = {
	{"reset", "()Ljdk/internal/net/http/hpack/BinaryRepresentationWriter;", nullptr, $PUBLIC | $ABSTRACT},
	{"write", "(Ljdk/internal/net/http/hpack/HeaderTable;Ljava/nio/ByteBuffer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _BinaryRepresentationWriter_ClassInfo_ = {
	$INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.hpack.BinaryRepresentationWriter",
	nullptr,
	nullptr,
	nullptr,
	_BinaryRepresentationWriter_MethodInfo_
};

$Object* allocate$BinaryRepresentationWriter($Class* clazz) {
	return $of($alloc(BinaryRepresentationWriter));
}

$Class* BinaryRepresentationWriter::load$($String* name, bool initialize) {
	$loadClass(BinaryRepresentationWriter, name, initialize, &_BinaryRepresentationWriter_ClassInfo_, allocate$BinaryRepresentationWriter);
	return class$;
}

$Class* BinaryRepresentationWriter::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk