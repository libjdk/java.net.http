#include <jdk/internal/net/http/hpack/NaiveHuffman$1.h>

#include <jdk/internal/net/http/hpack/NaiveHuffman$Node.h>
#include <jdk/internal/net/http/hpack/NaiveHuffman.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NaiveHuffman = ::jdk::internal::net::http::hpack::NaiveHuffman;
using $NaiveHuffman$Node = ::jdk::internal::net::http::hpack::NaiveHuffman$Node;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _NaiveHuffman$1_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/hpack/NaiveHuffman;", nullptr, $FINAL | $SYNTHETIC, $field(NaiveHuffman$1, this$0)},
	{}
};

$MethodInfo _NaiveHuffman$1_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/NaiveHuffman;)V", nullptr, 0, $method(static_cast<void(NaiveHuffman$1::*)($NaiveHuffman*)>(&NaiveHuffman$1::init$))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _NaiveHuffman$1_EnclosingMethodInfo_ = {
	"jdk.internal.net.http.hpack.NaiveHuffman",
	nullptr,
	nullptr
};

$InnerClassInfo _NaiveHuffman$1_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.NaiveHuffman$1", nullptr, nullptr, 0},
	{"jdk.internal.net.http.hpack.NaiveHuffman$Node", "jdk.internal.net.http.hpack.NaiveHuffman", "Node", $STATIC},
	{}
};

$ClassInfo _NaiveHuffman$1_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.hpack.NaiveHuffman$1",
	"jdk.internal.net.http.hpack.NaiveHuffman$Node",
	nullptr,
	_NaiveHuffman$1_FieldInfo_,
	_NaiveHuffman$1_MethodInfo_,
	nullptr,
	&_NaiveHuffman$1_EnclosingMethodInfo_,
	_NaiveHuffman$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.NaiveHuffman"
};

$Object* allocate$NaiveHuffman$1($Class* clazz) {
	return $of($alloc(NaiveHuffman$1));
}

void NaiveHuffman$1::init$($NaiveHuffman* this$0) {
	$set(this, this$0, this$0);
	$NaiveHuffman$Node::init$();
}

$String* NaiveHuffman$1::toString() {
	return "root"_s;
}

NaiveHuffman$1::NaiveHuffman$1() {
}

$Class* NaiveHuffman$1::load$($String* name, bool initialize) {
	$loadClass(NaiveHuffman$1, name, initialize, &_NaiveHuffman$1_ClassInfo_, allocate$NaiveHuffman$1);
	return class$;
}

$Class* NaiveHuffman$1::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk