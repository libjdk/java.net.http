#include <jdk/internal/net/http/hpack/Huffman.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$MethodInfo _Huffman_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Huffman::*)()>(&Huffman::init$))},
	{}
};

$InnerClassInfo _Huffman_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.Huffman$Writer", "jdk.internal.net.http.hpack.Huffman", "Writer", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.hpack.Huffman$Reader", "jdk.internal.net.http.hpack.Huffman", "Reader", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Huffman_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.Huffman",
	"java.lang.Object",
	nullptr,
	nullptr,
	_Huffman_MethodInfo_,
	nullptr,
	nullptr,
	_Huffman_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.Huffman$Writer,jdk.internal.net.http.hpack.Huffman$Reader"
};

$Object* allocate$Huffman($Class* clazz) {
	return $of($alloc(Huffman));
}

void Huffman::init$() {
}

Huffman::Huffman() {
}

$Class* Huffman::load$($String* name, bool initialize) {
	$loadClass(Huffman, name, initialize, &_Huffman_ClassInfo_, allocate$Huffman);
	return class$;
}

$Class* Huffman::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk