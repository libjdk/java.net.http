#include <jdk/internal/net/http/SocketTube$BufferSource.h>

#include <java/nio/ByteBuffer.h>
#include <java/util/List.h>
#include <jdk/internal/net/http/SocketTube.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $List = ::java::util::List;
using $SocketTube = ::jdk::internal::net::http::SocketTube;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$MethodInfo _SocketTube$BufferSource_MethodInfo_[] = {
	{"append", "(Ljava/util/List;Ljava/nio/ByteBuffer;I)Ljava/util/List;", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;Ljava/nio/ByteBuffer;I)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PUBLIC | $ABSTRACT},
	{"getBuffer", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT},
	{"returnUnused", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SocketTube$BufferSource_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.SocketTube$BufferSource", "jdk.internal.net.http.SocketTube", "BufferSource", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SocketTube$BufferSource_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.SocketTube$BufferSource",
	nullptr,
	nullptr,
	nullptr,
	_SocketTube$BufferSource_MethodInfo_,
	nullptr,
	nullptr,
	_SocketTube$BufferSource_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.SocketTube"
};

$Object* allocate$SocketTube$BufferSource($Class* clazz) {
	return $of($alloc(SocketTube$BufferSource));
}

void SocketTube$BufferSource::returnUnused($ByteBuffer* buffer) {
}

$Class* SocketTube$BufferSource::load$($String* name, bool initialize) {
	$loadClass(SocketTube$BufferSource, name, initialize, &_SocketTube$BufferSource_ClassInfo_, allocate$SocketTube$BufferSource);
	return class$;
}

$Class* SocketTube$BufferSource::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk