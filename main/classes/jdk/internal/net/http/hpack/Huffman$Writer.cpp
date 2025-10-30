#include <jdk/internal/net/http/hpack/Huffman$Writer.h>

#include <java/lang/CharSequence.h>
#include <java/nio/ByteBuffer.h>
#include <jdk/internal/net/http/hpack/Huffman.h>
#include <jcpp.h>

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Huffman = ::jdk::internal::net::http::hpack::Huffman;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$MethodInfo _Huffman$Writer_MethodInfo_[] = {
	{"from", "(Ljava/lang/CharSequence;II)Ljdk/internal/net/http/hpack/Huffman$Writer;", nullptr, $PUBLIC | $ABSTRACT},
	{"lengthOf", "(Ljava/lang/CharSequence;II)I", nullptr, $PUBLIC | $ABSTRACT},
	{"lengthOf", "(Ljava/lang/CharSequence;)I", nullptr, $PUBLIC},
	{"reset", "()Ljdk/internal/net/http/hpack/Huffman$Writer;", nullptr, $PUBLIC | $ABSTRACT},
	{"write", "(Ljava/nio/ByteBuffer;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _Huffman$Writer_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.Huffman$Writer", "jdk.internal.net.http.hpack.Huffman", "Writer", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Huffman$Writer_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.hpack.Huffman$Writer",
	nullptr,
	nullptr,
	nullptr,
	_Huffman$Writer_MethodInfo_,
	nullptr,
	nullptr,
	_Huffman$Writer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.Huffman"
};

$Object* allocate$Huffman$Writer($Class* clazz) {
	return $of($alloc(Huffman$Writer));
}

int32_t Huffman$Writer::lengthOf($CharSequence* value) {
	return lengthOf(value, 0, $nc(value)->length());
}

$Class* Huffman$Writer::load$($String* name, bool initialize) {
	$loadClass(Huffman$Writer, name, initialize, &_Huffman$Writer_ClassInfo_, allocate$Huffman$Writer);
	return class$;
}

$Class* Huffman$Writer::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk