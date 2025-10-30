#include <jdk/internal/net/http/hpack/QuickHuffman.h>

#include <java/lang/AssertionError.h>
#include <jdk/internal/net/http/hpack/HPACK.h>
#include <jdk/internal/net/http/hpack/QuickHuffman$ImmutableNode.h>
#include <jdk/internal/net/http/hpack/QuickHuffman$Node.h>
#include <jdk/internal/net/http/hpack/QuickHuffman$TemporaryNode.h>
#include <jcpp.h>

#undef EOS_LENGTH
#undef EOS_LSB
#undef EOS_MSB

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HPACK = ::jdk::internal::net::http::hpack::HPACK;
using $QuickHuffman$ImmutableNode = ::jdk::internal::net::http::hpack::QuickHuffman$ImmutableNode;
using $QuickHuffman$Node = ::jdk::internal::net::http::hpack::QuickHuffman$Node;
using $QuickHuffman$TemporaryNode = ::jdk::internal::net::http::hpack::QuickHuffman$TemporaryNode;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _QuickHuffman_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(QuickHuffman, $assertionsDisabled)},
	{"codes", "[J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(QuickHuffman, codes)},
	{"EOS_LENGTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(QuickHuffman, EOS_LENGTH)},
	{"EOS_LSB", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(QuickHuffman, EOS_LSB)},
	{"EOS_MSB", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(QuickHuffman, EOS_MSB)},
	{"root", "Ljdk/internal/net/http/hpack/QuickHuffman$Node;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(QuickHuffman, root)},
	{}
};

$MethodInfo _QuickHuffman_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(QuickHuffman::*)()>(&QuickHuffman::init$))},
	{"addChar", "(Ljdk/internal/net/http/hpack/QuickHuffman$Node;III)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($QuickHuffman$Node*,int32_t,int32_t,int32_t)>(&QuickHuffman::addChar))},
	{"addEOS", "(Ljdk/internal/net/http/hpack/QuickHuffman$Node;III)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($QuickHuffman$Node*,int32_t,int32_t,int32_t)>(&QuickHuffman::addEOS))},
	{"addLeaf", "(Ljdk/internal/net/http/hpack/QuickHuffman$Node;CIIZ)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($QuickHuffman$Node*,char16_t,int32_t,int32_t,bool)>(&QuickHuffman::addLeaf))},
	{"buildTrie", "()Ljdk/internal/net/http/hpack/QuickHuffman$Node;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$QuickHuffman$Node*(*)()>(&QuickHuffman::buildTrie))},
	{"codeLengthOf", "(C)J", nullptr, $PRIVATE | $STATIC, $method(static_cast<int64_t(*)(char16_t)>(&QuickHuffman::codeLengthOf))},
	{"codeValueOf", "(C)J", nullptr, $PRIVATE | $STATIC, $method(static_cast<int64_t(*)(char16_t)>(&QuickHuffman::codeValueOf))},
	{}
};

$InnerClassInfo _QuickHuffman_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.QuickHuffman$Writer", "jdk.internal.net.http.hpack.QuickHuffman", "Writer", $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.QuickHuffman$Reader", "jdk.internal.net.http.hpack.QuickHuffman", "Reader", $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.QuickHuffman$ImmutableNode", "jdk.internal.net.http.hpack.QuickHuffman", "ImmutableNode", $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.QuickHuffman$TemporaryNode", "jdk.internal.net.http.hpack.QuickHuffman", "TemporaryNode", $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.QuickHuffman$Node", "jdk.internal.net.http.hpack.QuickHuffman", "Node", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _QuickHuffman_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.QuickHuffman",
	"java.lang.Object",
	nullptr,
	_QuickHuffman_FieldInfo_,
	_QuickHuffman_MethodInfo_,
	nullptr,
	nullptr,
	_QuickHuffman_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.QuickHuffman$Writer,jdk.internal.net.http.hpack.QuickHuffman$Reader,jdk.internal.net.http.hpack.QuickHuffman$ImmutableNode,jdk.internal.net.http.hpack.QuickHuffman$TemporaryNode,jdk.internal.net.http.hpack.QuickHuffman$Node"
};

$Object* allocate$QuickHuffman($Class* clazz) {
	return $of($alloc(QuickHuffman));
}

bool QuickHuffman::$assertionsDisabled = false;
$longs* QuickHuffman::codes = nullptr;
$QuickHuffman$Node* QuickHuffman::root = nullptr;

int64_t QuickHuffman::codeValueOf(char16_t c) {
	$init(QuickHuffman);
	return (int64_t)($nc(QuickHuffman::codes)->get(c) & (uint64_t)(int64_t)0xFFFFFFFF00000000);
}

int64_t QuickHuffman::codeLengthOf(char16_t c) {
	$init(QuickHuffman);
	return (int64_t)($nc(QuickHuffman::codes)->get(c) & (uint64_t)(int64_t)0x00000000FFFFFFFF);
}

$QuickHuffman$Node* QuickHuffman::buildTrie() {
	$init(QuickHuffman);
	$var($QuickHuffman$TemporaryNode, tmpRoot, $new($QuickHuffman$TemporaryNode));
	addChar(tmpRoot, 0, 8184, 13);
	addChar(tmpRoot, 1, 0x007FFFD8, 23);
	addChar(tmpRoot, 2, 0x0FFFFFE2, 28);
	addChar(tmpRoot, 3, 0x0FFFFFE3, 28);
	addChar(tmpRoot, 4, 0x0FFFFFE4, 28);
	addChar(tmpRoot, 5, 0x0FFFFFE5, 28);
	addChar(tmpRoot, 6, 0x0FFFFFE6, 28);
	addChar(tmpRoot, 7, 0x0FFFFFE7, 28);
	addChar(tmpRoot, 8, 0x0FFFFFE8, 28);
	addChar(tmpRoot, 9, 0x00FFFFEA, 24);
	addChar(tmpRoot, 10, 0x3FFFFFFC, 30);
	addChar(tmpRoot, 11, 0x0FFFFFE9, 28);
	addChar(tmpRoot, 12, 0x0FFFFFEA, 28);
	addChar(tmpRoot, 13, 0x3FFFFFFD, 30);
	addChar(tmpRoot, 14, 0x0FFFFFEB, 28);
	addChar(tmpRoot, 15, 0x0FFFFFEC, 28);
	addChar(tmpRoot, 16, 0x0FFFFFED, 28);
	addChar(tmpRoot, 17, 0x0FFFFFEE, 28);
	addChar(tmpRoot, 18, 0x0FFFFFEF, 28);
	addChar(tmpRoot, 19, 0x0FFFFFF0, 28);
	addChar(tmpRoot, 20, 0x0FFFFFF1, 28);
	addChar(tmpRoot, 21, 0x0FFFFFF2, 28);
	addChar(tmpRoot, 22, 0x3FFFFFFE, 30);
	addChar(tmpRoot, 23, 0x0FFFFFF3, 28);
	addChar(tmpRoot, 24, 0x0FFFFFF4, 28);
	addChar(tmpRoot, 25, 0x0FFFFFF5, 28);
	addChar(tmpRoot, 26, 0x0FFFFFF6, 28);
	addChar(tmpRoot, 27, 0x0FFFFFF7, 28);
	addChar(tmpRoot, 28, 0x0FFFFFF8, 28);
	addChar(tmpRoot, 29, 0x0FFFFFF9, 28);
	addChar(tmpRoot, 30, 0x0FFFFFFA, 28);
	addChar(tmpRoot, 31, 0x0FFFFFFB, 28);
	addChar(tmpRoot, 32, 20, 6);
	addChar(tmpRoot, 33, 1016, 10);
	addChar(tmpRoot, 34, 1017, 10);
	addChar(tmpRoot, 35, 4090, 12);
	addChar(tmpRoot, 36, 8185, 13);
	addChar(tmpRoot, 37, 21, 6);
	addChar(tmpRoot, 38, 248, 8);
	addChar(tmpRoot, 39, 2042, 11);
	addChar(tmpRoot, 40, 1018, 10);
	addChar(tmpRoot, 41, 1019, 10);
	addChar(tmpRoot, 42, 249, 8);
	addChar(tmpRoot, 43, 2043, 11);
	addChar(tmpRoot, 44, 250, 8);
	addChar(tmpRoot, 45, 22, 6);
	addChar(tmpRoot, 46, 23, 6);
	addChar(tmpRoot, 47, 24, 6);
	addChar(tmpRoot, 48, 0, 5);
	addChar(tmpRoot, 49, 1, 5);
	addChar(tmpRoot, 50, 2, 5);
	addChar(tmpRoot, 51, 25, 6);
	addChar(tmpRoot, 52, 26, 6);
	addChar(tmpRoot, 53, 27, 6);
	addChar(tmpRoot, 54, 28, 6);
	addChar(tmpRoot, 55, 29, 6);
	addChar(tmpRoot, 56, 30, 6);
	addChar(tmpRoot, 57, 31, 6);
	addChar(tmpRoot, 58, 92, 7);
	addChar(tmpRoot, 59, 251, 8);
	addChar(tmpRoot, 60, 32764, 15);
	addChar(tmpRoot, 61, 32, 6);
	addChar(tmpRoot, 62, 4091, 12);
	addChar(tmpRoot, 63, 1020, 10);
	addChar(tmpRoot, 64, 8186, 13);
	addChar(tmpRoot, 65, 33, 6);
	addChar(tmpRoot, 66, 93, 7);
	addChar(tmpRoot, 67, 94, 7);
	addChar(tmpRoot, 68, 95, 7);
	addChar(tmpRoot, 69, 96, 7);
	addChar(tmpRoot, 70, 97, 7);
	addChar(tmpRoot, 71, 98, 7);
	addChar(tmpRoot, 72, 99, 7);
	addChar(tmpRoot, 73, 100, 7);
	addChar(tmpRoot, 74, 101, 7);
	addChar(tmpRoot, 75, 102, 7);
	addChar(tmpRoot, 76, 103, 7);
	addChar(tmpRoot, 77, 104, 7);
	addChar(tmpRoot, 78, 105, 7);
	addChar(tmpRoot, 79, 106, 7);
	addChar(tmpRoot, 80, 107, 7);
	addChar(tmpRoot, 81, 108, 7);
	addChar(tmpRoot, 82, 109, 7);
	addChar(tmpRoot, 83, 110, 7);
	addChar(tmpRoot, 84, 111, 7);
	addChar(tmpRoot, 85, 112, 7);
	addChar(tmpRoot, 86, 113, 7);
	addChar(tmpRoot, 87, 114, 7);
	addChar(tmpRoot, 88, 252, 8);
	addChar(tmpRoot, 89, 115, 7);
	addChar(tmpRoot, 90, 253, 8);
	addChar(tmpRoot, 91, 8187, 13);
	addChar(tmpRoot, 92, 0x0007FFF0, 19);
	addChar(tmpRoot, 93, 8188, 13);
	addChar(tmpRoot, 94, 16380, 14);
	addChar(tmpRoot, 95, 34, 6);
	addChar(tmpRoot, 96, 32765, 15);
	addChar(tmpRoot, 97, 3, 5);
	addChar(tmpRoot, 98, 35, 6);
	addChar(tmpRoot, 99, 4, 5);
	addChar(tmpRoot, 100, 36, 6);
	addChar(tmpRoot, 101, 5, 5);
	addChar(tmpRoot, 102, 37, 6);
	addChar(tmpRoot, 103, 38, 6);
	addChar(tmpRoot, 104, 39, 6);
	addChar(tmpRoot, 105, 6, 5);
	addChar(tmpRoot, 106, 116, 7);
	addChar(tmpRoot, 107, 117, 7);
	addChar(tmpRoot, 108, 40, 6);
	addChar(tmpRoot, 109, 41, 6);
	addChar(tmpRoot, 110, 42, 6);
	addChar(tmpRoot, 111, 7, 5);
	addChar(tmpRoot, 112, 43, 6);
	addChar(tmpRoot, 113, 118, 7);
	addChar(tmpRoot, 114, 44, 6);
	addChar(tmpRoot, 115, 8, 5);
	addChar(tmpRoot, 116, 9, 5);
	addChar(tmpRoot, 117, 45, 6);
	addChar(tmpRoot, 118, 119, 7);
	addChar(tmpRoot, 119, 120, 7);
	addChar(tmpRoot, 120, 121, 7);
	addChar(tmpRoot, 121, 122, 7);
	addChar(tmpRoot, 122, 123, 7);
	addChar(tmpRoot, 123, 32766, 15);
	addChar(tmpRoot, 124, 2044, 11);
	addChar(tmpRoot, 125, 16381, 14);
	addChar(tmpRoot, 126, 8189, 13);
	addChar(tmpRoot, 127, 0x0FFFFFFC, 28);
	addChar(tmpRoot, 128, 0x000FFFE6, 20);
	addChar(tmpRoot, 129, 0x003FFFD2, 22);
	addChar(tmpRoot, 130, 0x000FFFE7, 20);
	addChar(tmpRoot, 131, 0x000FFFE8, 20);
	addChar(tmpRoot, 132, 0x003FFFD3, 22);
	addChar(tmpRoot, 133, 0x003FFFD4, 22);
	addChar(tmpRoot, 134, 0x003FFFD5, 22);
	addChar(tmpRoot, 135, 0x007FFFD9, 23);
	addChar(tmpRoot, 136, 0x003FFFD6, 22);
	addChar(tmpRoot, 137, 0x007FFFDA, 23);
	addChar(tmpRoot, 138, 0x007FFFDB, 23);
	addChar(tmpRoot, 139, 0x007FFFDC, 23);
	addChar(tmpRoot, 140, 0x007FFFDD, 23);
	addChar(tmpRoot, 141, 0x007FFFDE, 23);
	addChar(tmpRoot, 142, 0x00FFFFEB, 24);
	addChar(tmpRoot, 143, 0x007FFFDF, 23);
	addChar(tmpRoot, 144, 0x00FFFFEC, 24);
	addChar(tmpRoot, 145, 0x00FFFFED, 24);
	addChar(tmpRoot, 146, 0x003FFFD7, 22);
	addChar(tmpRoot, 147, 0x007FFFE0, 23);
	addChar(tmpRoot, 148, 0x00FFFFEE, 24);
	addChar(tmpRoot, 149, 0x007FFFE1, 23);
	addChar(tmpRoot, 150, 0x007FFFE2, 23);
	addChar(tmpRoot, 151, 0x007FFFE3, 23);
	addChar(tmpRoot, 152, 0x007FFFE4, 23);
	addChar(tmpRoot, 153, 0x001FFFDC, 21);
	addChar(tmpRoot, 154, 0x003FFFD8, 22);
	addChar(tmpRoot, 155, 0x007FFFE5, 23);
	addChar(tmpRoot, 156, 0x003FFFD9, 22);
	addChar(tmpRoot, 157, 0x007FFFE6, 23);
	addChar(tmpRoot, 158, 0x007FFFE7, 23);
	addChar(tmpRoot, 159, 0x00FFFFEF, 24);
	addChar(tmpRoot, 160, 0x003FFFDA, 22);
	addChar(tmpRoot, 161, 0x001FFFDD, 21);
	addChar(tmpRoot, 162, 0x000FFFE9, 20);
	addChar(tmpRoot, 163, 0x003FFFDB, 22);
	addChar(tmpRoot, 164, 0x003FFFDC, 22);
	addChar(tmpRoot, 165, 0x007FFFE8, 23);
	addChar(tmpRoot, 166, 0x007FFFE9, 23);
	addChar(tmpRoot, 167, 0x001FFFDE, 21);
	addChar(tmpRoot, 168, 0x007FFFEA, 23);
	addChar(tmpRoot, 169, 0x003FFFDD, 22);
	addChar(tmpRoot, 170, 0x003FFFDE, 22);
	addChar(tmpRoot, 171, 0x00FFFFF0, 24);
	addChar(tmpRoot, 172, 0x001FFFDF, 21);
	addChar(tmpRoot, 173, 0x003FFFDF, 22);
	addChar(tmpRoot, 174, 0x007FFFEB, 23);
	addChar(tmpRoot, 175, 0x007FFFEC, 23);
	addChar(tmpRoot, 176, 0x001FFFE0, 21);
	addChar(tmpRoot, 177, 0x001FFFE1, 21);
	addChar(tmpRoot, 178, 0x003FFFE0, 22);
	addChar(tmpRoot, 179, 0x001FFFE2, 21);
	addChar(tmpRoot, 180, 0x007FFFED, 23);
	addChar(tmpRoot, 181, 0x003FFFE1, 22);
	addChar(tmpRoot, 182, 0x007FFFEE, 23);
	addChar(tmpRoot, 183, 0x007FFFEF, 23);
	addChar(tmpRoot, 184, 0x000FFFEA, 20);
	addChar(tmpRoot, 185, 0x003FFFE2, 22);
	addChar(tmpRoot, 186, 0x003FFFE3, 22);
	addChar(tmpRoot, 187, 0x003FFFE4, 22);
	addChar(tmpRoot, 188, 0x007FFFF0, 23);
	addChar(tmpRoot, 189, 0x003FFFE5, 22);
	addChar(tmpRoot, 190, 0x003FFFE6, 22);
	addChar(tmpRoot, 191, 0x007FFFF1, 23);
	addChar(tmpRoot, 192, 0x03FFFFE0, 26);
	addChar(tmpRoot, 193, 0x03FFFFE1, 26);
	addChar(tmpRoot, 194, 0x000FFFEB, 20);
	addChar(tmpRoot, 195, 0x0007FFF1, 19);
	addChar(tmpRoot, 196, 0x003FFFE7, 22);
	addChar(tmpRoot, 197, 0x007FFFF2, 23);
	addChar(tmpRoot, 198, 0x003FFFE8, 22);
	addChar(tmpRoot, 199, 0x01FFFFEC, 25);
	addChar(tmpRoot, 200, 0x03FFFFE2, 26);
	addChar(tmpRoot, 201, 0x03FFFFE3, 26);
	addChar(tmpRoot, 202, 0x03FFFFE4, 26);
	addChar(tmpRoot, 203, 0x07FFFFDE, 27);
	addChar(tmpRoot, 204, 0x07FFFFDF, 27);
	addChar(tmpRoot, 205, 0x03FFFFE5, 26);
	addChar(tmpRoot, 206, 0x00FFFFF1, 24);
	addChar(tmpRoot, 207, 0x01FFFFED, 25);
	addChar(tmpRoot, 208, 0x0007FFF2, 19);
	addChar(tmpRoot, 209, 0x001FFFE3, 21);
	addChar(tmpRoot, 210, 0x03FFFFE6, 26);
	addChar(tmpRoot, 211, 0x07FFFFE0, 27);
	addChar(tmpRoot, 212, 0x07FFFFE1, 27);
	addChar(tmpRoot, 213, 0x03FFFFE7, 26);
	addChar(tmpRoot, 214, 0x07FFFFE2, 27);
	addChar(tmpRoot, 215, 0x00FFFFF2, 24);
	addChar(tmpRoot, 216, 0x001FFFE4, 21);
	addChar(tmpRoot, 217, 0x001FFFE5, 21);
	addChar(tmpRoot, 218, 0x03FFFFE8, 26);
	addChar(tmpRoot, 219, 0x03FFFFE9, 26);
	addChar(tmpRoot, 220, 0x0FFFFFFD, 28);
	addChar(tmpRoot, 221, 0x07FFFFE3, 27);
	addChar(tmpRoot, 222, 0x07FFFFE4, 27);
	addChar(tmpRoot, 223, 0x07FFFFE5, 27);
	addChar(tmpRoot, 224, 0x000FFFEC, 20);
	addChar(tmpRoot, 225, 0x00FFFFF3, 24);
	addChar(tmpRoot, 226, 0x000FFFED, 20);
	addChar(tmpRoot, 227, 0x001FFFE6, 21);
	addChar(tmpRoot, 228, 0x003FFFE9, 22);
	addChar(tmpRoot, 229, 0x001FFFE7, 21);
	addChar(tmpRoot, 230, 0x001FFFE8, 21);
	addChar(tmpRoot, 231, 0x007FFFF3, 23);
	addChar(tmpRoot, 232, 0x003FFFEA, 22);
	addChar(tmpRoot, 233, 0x003FFFEB, 22);
	addChar(tmpRoot, 234, 0x01FFFFEE, 25);
	addChar(tmpRoot, 235, 0x01FFFFEF, 25);
	addChar(tmpRoot, 236, 0x00FFFFF4, 24);
	addChar(tmpRoot, 237, 0x00FFFFF5, 24);
	addChar(tmpRoot, 238, 0x03FFFFEA, 26);
	addChar(tmpRoot, 239, 0x007FFFF4, 23);
	addChar(tmpRoot, 240, 0x03FFFFEB, 26);
	addChar(tmpRoot, 241, 0x07FFFFE6, 27);
	addChar(tmpRoot, 242, 0x03FFFFEC, 26);
	addChar(tmpRoot, 243, 0x03FFFFED, 26);
	addChar(tmpRoot, 244, 0x07FFFFE7, 27);
	addChar(tmpRoot, 245, 0x07FFFFE8, 27);
	addChar(tmpRoot, 246, 0x07FFFFE9, 27);
	addChar(tmpRoot, 247, 0x07FFFFEA, 27);
	addChar(tmpRoot, 248, 0x07FFFFEB, 27);
	addChar(tmpRoot, 249, 0x0FFFFFFE, 28);
	addChar(tmpRoot, 250, 0x07FFFFEC, 27);
	addChar(tmpRoot, 251, 0x07FFFFED, 27);
	addChar(tmpRoot, 252, 0x07FFFFEE, 27);
	addChar(tmpRoot, 253, 0x07FFFFEF, 27);
	addChar(tmpRoot, 254, 0x07FFFFF0, 27);
	addChar(tmpRoot, 255, 0x03FFFFEE, 26);
	addEOS(tmpRoot, 256, QuickHuffman::EOS_LSB, QuickHuffman::EOS_LENGTH);
	return $QuickHuffman$ImmutableNode::copyOf(tmpRoot);
}

void QuickHuffman::init$() {
}

void QuickHuffman::addChar($QuickHuffman$Node* root, int32_t symbol, int32_t code, int32_t bitLength) {
	$init(QuickHuffman);
	addLeaf(root, (char16_t)symbol, code, bitLength, false);
	int64_t value = $sl((int64_t)code, 64 - bitLength);
	$nc(QuickHuffman::codes)->set(symbol, value | bitLength);
}

void QuickHuffman::addEOS($QuickHuffman$Node* root, int32_t symbol, int32_t code, int32_t bitLength) {
	$init(QuickHuffman);
	addLeaf(root, (char16_t)symbol, code, bitLength, true);
}

void QuickHuffman::addLeaf($QuickHuffman$Node* root, char16_t symbol, int32_t code, int32_t bitLength, bool isEOS) {
	$init(QuickHuffman);
	$useLocalCurrentObjectStackCache();
	if (!QuickHuffman::$assertionsDisabled && !(0 < bitLength && bitLength <= 32)) {
		$throwNew($AssertionError, bitLength);
	}
	$var($QuickHuffman$Node, curr, root);
	int32_t nBytes = $HPACK::bytesForBits(bitLength);
	int32_t align = (nBytes << 3) - bitLength;
	code <<= align;
	int32_t l = 0;
	{
		int32_t i = 0;
		int32_t probe = $sl(255, (nBytes - 1) << 3);
		for (; i < nBytes - 1; ++i, $usrAssign(probe, 8)) {
			$nc(curr)->setEOSPath(curr->isEOSPath() | isEOS);
			int32_t idx = $usr((int32_t)(code & (uint32_t)probe), (nBytes - 1 - i) << 3);
			$assign(curr, curr->getOrCreateChild(idx));
			curr->setLength(8);
			l += 8;
		}
	}
	int32_t idx = (int32_t)(code & (uint32_t)255);
	$nc(curr)->setEOSPath(curr->isEOSPath() | isEOS);
	for (int32_t i = 0; i < ($sl(1, align)); ++i) {
		$var($QuickHuffman$Node, child, curr->getOrCreateChild(idx | i));
		$nc(child)->setSymbol(symbol);
		child->setEOSPath(child->isEOSPath() | isEOS);
		child->setLength(bitLength - l);
	}
}

void clinit$QuickHuffman($Class* class$) {
	QuickHuffman::$assertionsDisabled = !QuickHuffman::class$->desiredAssertionStatus();
	$assignStatic(QuickHuffman::codes, $new($longs, 256));
	$assignStatic(QuickHuffman::root, QuickHuffman::buildTrie());
}

QuickHuffman::QuickHuffman() {
}

$Class* QuickHuffman::load$($String* name, bool initialize) {
	$loadClass(QuickHuffman, name, initialize, &_QuickHuffman_ClassInfo_, clinit$QuickHuffman, allocate$QuickHuffman);
	return class$;
}

$Class* QuickHuffman::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk