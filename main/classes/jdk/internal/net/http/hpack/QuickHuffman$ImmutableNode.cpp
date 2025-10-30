#include <jdk/internal/net/http/hpack/QuickHuffman$ImmutableNode.h>

#include <java/lang/UnsupportedOperationException.h>
#include <java/util/List.h>
#include <jdk/internal/net/http/hpack/QuickHuffman$Node.h>
#include <jdk/internal/net/http/hpack/QuickHuffman.h>
#include <jcpp.h>

using $QuickHuffman$ImmutableNodeArray = $Array<::jdk::internal::net::http::hpack::QuickHuffman$ImmutableNode>;
using $QuickHuffman$NodeArray = $Array<::jdk::internal::net::http::hpack::QuickHuffman$Node>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $List = ::java::util::List;
using $QuickHuffman = ::jdk::internal::net::http::hpack::QuickHuffman;
using $QuickHuffman$Node = ::jdk::internal::net::http::hpack::QuickHuffman$Node;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _QuickHuffman$ImmutableNode_FieldInfo_[] = {
	{"symbol", "C", nullptr, $PRIVATE | $FINAL, $field(QuickHuffman$ImmutableNode, symbol)},
	{"eosPath", "Z", nullptr, $PRIVATE | $FINAL, $field(QuickHuffman$ImmutableNode, eosPath)},
	{"length", "I", nullptr, $PRIVATE | $FINAL, $field(QuickHuffman$ImmutableNode, length)},
	{"children", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/net/http/hpack/QuickHuffman$ImmutableNode;>;", $PRIVATE | $FINAL, $field(QuickHuffman$ImmutableNode, children)},
	{}
};

$MethodInfo _QuickHuffman$ImmutableNode_MethodInfo_[] = {
	{"<init>", "(CZI)V", nullptr, $PRIVATE, $method(static_cast<void(QuickHuffman$ImmutableNode::*)(char16_t,bool,int32_t)>(&QuickHuffman$ImmutableNode::init$))},
	{"<init>", "(ZI[Ljdk/internal/net/http/hpack/QuickHuffman$ImmutableNode;)V", nullptr, $PRIVATE, $method(static_cast<void(QuickHuffman$ImmutableNode::*)(bool,int32_t,$QuickHuffman$ImmutableNodeArray*)>(&QuickHuffman$ImmutableNode::init$))},
	{"copyOf", "(Ljdk/internal/net/http/hpack/QuickHuffman$Node;)Ljdk/internal/net/http/hpack/QuickHuffman$ImmutableNode;", nullptr, $PUBLIC | $STATIC, $method(static_cast<QuickHuffman$ImmutableNode*(*)($QuickHuffman$Node*)>(&QuickHuffman$ImmutableNode::copyOf))},
	{"getChild", "(I)Ljdk/internal/net/http/hpack/QuickHuffman$ImmutableNode;", nullptr, $PUBLIC},
	{"getChildren", "()[Ljdk/internal/net/http/hpack/QuickHuffman$ImmutableNode;", nullptr, $PUBLIC},
	{"getLength", "()I", nullptr, $PUBLIC},
	{"getOrCreateChild", "(I)Ljdk/internal/net/http/hpack/QuickHuffman$ImmutableNode;", nullptr, $PUBLIC},
	{"getSymbol", "()C", nullptr, $PUBLIC},
	{"isEOSPath", "()Z", nullptr, $PUBLIC},
	{"isLeaf", "()Z", nullptr, $PUBLIC},
	{"setEOSPath", "(Z)V", nullptr, $PUBLIC},
	{"setLength", "(I)V", nullptr, $PUBLIC},
	{"setSymbol", "(C)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _QuickHuffman$ImmutableNode_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.QuickHuffman$ImmutableNode", "jdk.internal.net.http.hpack.QuickHuffman", "ImmutableNode", $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.QuickHuffman$Node", "jdk.internal.net.http.hpack.QuickHuffman", "Node", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _QuickHuffman$ImmutableNode_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.QuickHuffman$ImmutableNode",
	"java.lang.Object",
	"jdk.internal.net.http.hpack.QuickHuffman$Node",
	_QuickHuffman$ImmutableNode_FieldInfo_,
	_QuickHuffman$ImmutableNode_MethodInfo_,
	nullptr,
	nullptr,
	_QuickHuffman$ImmutableNode_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.QuickHuffman"
};

$Object* allocate$QuickHuffman$ImmutableNode($Class* clazz) {
	return $of($alloc(QuickHuffman$ImmutableNode));
}

QuickHuffman$ImmutableNode* QuickHuffman$ImmutableNode::copyOf($QuickHuffman$Node* node) {
	$init(QuickHuffman$ImmutableNode);
	$useLocalCurrentObjectStackCache();
	if ($nc(node)->isLeaf()) {
		char16_t var$0 = node->getSymbol();
		bool var$1 = node->isEOSPath();
		return $new(QuickHuffman$ImmutableNode, var$0, var$1, node->getLength());
	}
	$var($QuickHuffman$NodeArray, children, $nc(node)->getChildren());
	$var($QuickHuffman$ImmutableNodeArray, immutableChildren, $new($QuickHuffman$ImmutableNodeArray, $nc(children)->length));
	for (int32_t i = 0; i < children->length; ++i) {
		immutableChildren->set(i, $(copyOf(children->get(i))));
	}
	bool var$2 = node->isEOSPath();
	return $new(QuickHuffman$ImmutableNode, var$2, node->getLength(), immutableChildren);
}

void QuickHuffman$ImmutableNode::init$(char16_t symbol, bool eosPath, int32_t length) {
	this->symbol = symbol;
	this->eosPath = eosPath;
	this->length = length;
	$set(this, children, $List::of());
}

void QuickHuffman$ImmutableNode::init$(bool eosPath, int32_t length, $QuickHuffman$ImmutableNodeArray* children) {
	this->symbol = (char16_t)0;
	this->eosPath = eosPath;
	this->length = length;
	if ($nc(children)->length == 0) {
		$throwNew($IllegalArgumentException);
	}
	$set(this, children, $List::of(children));
}

bool QuickHuffman$ImmutableNode::isLeaf() {
	return $nc(this->children)->isEmpty();
}

bool QuickHuffman$ImmutableNode::isEOSPath() {
	return this->eosPath;
}

void QuickHuffman$ImmutableNode::setEOSPath(bool value) {
	$throwNew($UnsupportedOperationException);
}

QuickHuffman$ImmutableNode* QuickHuffman$ImmutableNode::getChild(int32_t index) {
	return $cast(QuickHuffman$ImmutableNode, $nc(this->children)->get(index));
}

QuickHuffman$ImmutableNode* QuickHuffman$ImmutableNode::getOrCreateChild(int32_t index) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$QuickHuffman$NodeArray* QuickHuffman$ImmutableNode::getChildren() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

char16_t QuickHuffman$ImmutableNode::getSymbol() {
	return this->symbol;
}

void QuickHuffman$ImmutableNode::setSymbol(char16_t symbol) {
	$throwNew($UnsupportedOperationException);
}

int32_t QuickHuffman$ImmutableNode::getLength() {
	return this->length;
}

void QuickHuffman$ImmutableNode::setLength(int32_t value) {
	$throwNew($UnsupportedOperationException);
}

QuickHuffman$ImmutableNode::QuickHuffman$ImmutableNode() {
}

$Class* QuickHuffman$ImmutableNode::load$($String* name, bool initialize) {
	$loadClass(QuickHuffman$ImmutableNode, name, initialize, &_QuickHuffman$ImmutableNode_ClassInfo_, allocate$QuickHuffman$ImmutableNode);
	return class$;
}

$Class* QuickHuffman$ImmutableNode::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk