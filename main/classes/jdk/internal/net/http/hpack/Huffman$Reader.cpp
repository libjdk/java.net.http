#include <jdk/internal/net/http/hpack/Huffman$Reader.h>

#include <java/lang/Appendable.h>
#include <java/nio/ByteBuffer.h>
#include <jdk/internal/net/http/hpack/Huffman.h>
#include <jcpp.h>

using $Appendable = ::java::lang::Appendable;
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

$MethodInfo _Huffman$Reader_MethodInfo_[] = {
	{"read", "(Ljava/nio/ByteBuffer;Ljava/lang/Appendable;Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"reset", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _Huffman$Reader_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.Huffman$Reader", "jdk.internal.net.http.hpack.Huffman", "Reader", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Huffman$Reader_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.hpack.Huffman$Reader",
	nullptr,
	nullptr,
	nullptr,
	_Huffman$Reader_MethodInfo_,
	nullptr,
	nullptr,
	_Huffman$Reader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.Huffman"
};

$Object* allocate$Huffman$Reader($Class* clazz) {
	return $of($alloc(Huffman$Reader));
}

$Class* Huffman$Reader::load$($String* name, bool initialize) {
	$loadClass(Huffman$Reader, name, initialize, &_Huffman$Reader_ClassInfo_, allocate$Huffman$Reader);
	return class$;
}

$Class* Huffman$Reader::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk