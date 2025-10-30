#include <jdk/internal/net/http/hpack/QuickHuffman$Node.h>

#include <jdk/internal/net/http/hpack/QuickHuffman.h>
#include <jcpp.h>

using $QuickHuffman$NodeArray = $Array<::jdk::internal::net::http::hpack::QuickHuffman$Node>;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $QuickHuffman = ::jdk::internal::net::http::hpack::QuickHuffman;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$MethodInfo _QuickHuffman$Node_MethodInfo_[] = {
	{"getChild", "(I)Ljdk/internal/net/http/hpack/QuickHuffman$Node;", nullptr, $PUBLIC | $ABSTRACT},
	{"getChildren", "()[Ljdk/internal/net/http/hpack/QuickHuffman$Node;", nullptr, $PUBLIC | $ABSTRACT},
	{"getLength", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"getOrCreateChild", "(I)Ljdk/internal/net/http/hpack/QuickHuffman$Node;", nullptr, $PUBLIC | $ABSTRACT},
	{"getSymbol", "()C", nullptr, $PUBLIC | $ABSTRACT},
	{"isEOSPath", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"isLeaf", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"setEOSPath", "(Z)V", nullptr, $PUBLIC | $ABSTRACT},
	{"setLength", "(I)V", nullptr, $PUBLIC | $ABSTRACT},
	{"setSymbol", "(C)V", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _QuickHuffman$Node_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.QuickHuffman$Node", "jdk.internal.net.http.hpack.QuickHuffman", "Node", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _QuickHuffman$Node_ClassInfo_ = {
	$INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.hpack.QuickHuffman$Node",
	nullptr,
	nullptr,
	nullptr,
	_QuickHuffman$Node_MethodInfo_,
	nullptr,
	nullptr,
	_QuickHuffman$Node_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.QuickHuffman"
};

$Object* allocate$QuickHuffman$Node($Class* clazz) {
	return $of($alloc(QuickHuffman$Node));
}

$Class* QuickHuffman$Node::load$($String* name, bool initialize) {
	$loadClass(QuickHuffman$Node, name, initialize, &_QuickHuffman$Node_ClassInfo_, allocate$QuickHuffman$Node);
	return class$;
}

$Class* QuickHuffman$Node::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk