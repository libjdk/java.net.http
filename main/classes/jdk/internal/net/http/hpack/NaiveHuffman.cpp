#include <jdk/internal/net/http/hpack/NaiveHuffman.h>

#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IllegalStateException.h>
#include <jdk/internal/net/http/hpack/NaiveHuffman$1.h>
#include <jdk/internal/net/http/hpack/NaiveHuffman$Code.h>
#include <jdk/internal/net/http/hpack/NaiveHuffman$Node.h>
#include <jcpp.h>

#undef EOS
#undef INSTANCE

using $NaiveHuffman$CodeArray = $Array<::jdk::internal::net::http::hpack::NaiveHuffman$Code>;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NaiveHuffman$1 = ::jdk::internal::net::http::hpack::NaiveHuffman$1;
using $NaiveHuffman$Code = ::jdk::internal::net::http::hpack::NaiveHuffman$Code;
using $NaiveHuffman$Node = ::jdk::internal::net::http::hpack::NaiveHuffman$Node;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _NaiveHuffman_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(NaiveHuffman, $assertionsDisabled)},
	{"INSTANCE", "Ljdk/internal/net/http/hpack/NaiveHuffman;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(NaiveHuffman, INSTANCE)},
	{"EOS", "Ljdk/internal/net/http/hpack/NaiveHuffman$Code;", nullptr, $PRIVATE | $FINAL, $field(NaiveHuffman, EOS)},
	{"codes", "[Ljdk/internal/net/http/hpack/NaiveHuffman$Code;", nullptr, $PRIVATE | $FINAL, $field(NaiveHuffman, codes)},
	{"root", "Ljdk/internal/net/http/hpack/NaiveHuffman$Node;", nullptr, $PRIVATE | $FINAL, $field(NaiveHuffman, root)},
	{}
};

$MethodInfo _NaiveHuffman_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(NaiveHuffman::*)()>(&NaiveHuffman::init$))},
	{"addChar", "(III)V", nullptr, $PRIVATE, $method(static_cast<void(NaiveHuffman::*)(int32_t,int32_t,int32_t)>(&NaiveHuffman::addChar))},
	{"addEOS", "(III)V", nullptr, $PRIVATE, $method(static_cast<void(NaiveHuffman::*)(int32_t,int32_t,int32_t)>(&NaiveHuffman::addEOS))},
	{"addLeaf", "(IIIZ)V", nullptr, $PRIVATE, $method(static_cast<void(NaiveHuffman::*)(int32_t,int32_t,int32_t,bool)>(&NaiveHuffman::addLeaf))},
	{"codeOf", "(C)Ljdk/internal/net/http/hpack/NaiveHuffman$Code;", nullptr, $PRIVATE, $method(static_cast<$NaiveHuffman$Code*(NaiveHuffman::*)(char16_t)>(&NaiveHuffman::codeOf))},
	{"getRoot", "()Ljdk/internal/net/http/hpack/NaiveHuffman$Node;", nullptr, 0, $method(static_cast<$NaiveHuffman$Node*(NaiveHuffman::*)()>(&NaiveHuffman::getRoot))},
	{"lengthOf", "(Ljava/lang/CharSequence;)I", nullptr, $PUBLIC, $method(static_cast<int32_t(NaiveHuffman::*)($CharSequence*)>(&NaiveHuffman::lengthOf))},
	{"lengthOf", "(Ljava/lang/CharSequence;II)I", nullptr, $PUBLIC, $method(static_cast<int32_t(NaiveHuffman::*)($CharSequence*,int32_t,int32_t)>(&NaiveHuffman::lengthOf))},
	{}
};

$InnerClassInfo _NaiveHuffman_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.NaiveHuffman$Code", "jdk.internal.net.http.hpack.NaiveHuffman", "Code", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.NaiveHuffman$Node", "jdk.internal.net.http.hpack.NaiveHuffman", "Node", $STATIC},
	{"jdk.internal.net.http.hpack.NaiveHuffman$Writer", "jdk.internal.net.http.hpack.NaiveHuffman", "Writer", $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.NaiveHuffman$Reader", "jdk.internal.net.http.hpack.NaiveHuffman", "Reader", $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.NaiveHuffman$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _NaiveHuffman_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.NaiveHuffman",
	"java.lang.Object",
	nullptr,
	_NaiveHuffman_FieldInfo_,
	_NaiveHuffman_MethodInfo_,
	nullptr,
	nullptr,
	_NaiveHuffman_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.NaiveHuffman$Code,jdk.internal.net.http.hpack.NaiveHuffman$Node,jdk.internal.net.http.hpack.NaiveHuffman$Writer,jdk.internal.net.http.hpack.NaiveHuffman$Reader,jdk.internal.net.http.hpack.NaiveHuffman$1"
};

$Object* allocate$NaiveHuffman($Class* clazz) {
	return $of($alloc(NaiveHuffman));
}

bool NaiveHuffman::$assertionsDisabled = false;
NaiveHuffman* NaiveHuffman::INSTANCE = nullptr;

void NaiveHuffman::init$() {
	$set(this, EOS, $new($NaiveHuffman$Code, 0x3FFFFFFF, 30));
	$set(this, codes, $new($NaiveHuffman$CodeArray, 257));
	$set(this, root, $new($NaiveHuffman$1, this));
	addChar(0, 8184, 13);
	addChar(1, 0x007FFFD8, 23);
	addChar(2, 0x0FFFFFE2, 28);
	addChar(3, 0x0FFFFFE3, 28);
	addChar(4, 0x0FFFFFE4, 28);
	addChar(5, 0x0FFFFFE5, 28);
	addChar(6, 0x0FFFFFE6, 28);
	addChar(7, 0x0FFFFFE7, 28);
	addChar(8, 0x0FFFFFE8, 28);
	addChar(9, 0x00FFFFEA, 24);
	addChar(10, 0x3FFFFFFC, 30);
	addChar(11, 0x0FFFFFE9, 28);
	addChar(12, 0x0FFFFFEA, 28);
	addChar(13, 0x3FFFFFFD, 30);
	addChar(14, 0x0FFFFFEB, 28);
	addChar(15, 0x0FFFFFEC, 28);
	addChar(16, 0x0FFFFFED, 28);
	addChar(17, 0x0FFFFFEE, 28);
	addChar(18, 0x0FFFFFEF, 28);
	addChar(19, 0x0FFFFFF0, 28);
	addChar(20, 0x0FFFFFF1, 28);
	addChar(21, 0x0FFFFFF2, 28);
	addChar(22, 0x3FFFFFFE, 30);
	addChar(23, 0x0FFFFFF3, 28);
	addChar(24, 0x0FFFFFF4, 28);
	addChar(25, 0x0FFFFFF5, 28);
	addChar(26, 0x0FFFFFF6, 28);
	addChar(27, 0x0FFFFFF7, 28);
	addChar(28, 0x0FFFFFF8, 28);
	addChar(29, 0x0FFFFFF9, 28);
	addChar(30, 0x0FFFFFFA, 28);
	addChar(31, 0x0FFFFFFB, 28);
	addChar(32, 20, 6);
	addChar(33, 1016, 10);
	addChar(34, 1017, 10);
	addChar(35, 4090, 12);
	addChar(36, 8185, 13);
	addChar(37, 21, 6);
	addChar(38, 248, 8);
	addChar(39, 2042, 11);
	addChar(40, 1018, 10);
	addChar(41, 1019, 10);
	addChar(42, 249, 8);
	addChar(43, 2043, 11);
	addChar(44, 250, 8);
	addChar(45, 22, 6);
	addChar(46, 23, 6);
	addChar(47, 24, 6);
	addChar(48, 0, 5);
	addChar(49, 1, 5);
	addChar(50, 2, 5);
	addChar(51, 25, 6);
	addChar(52, 26, 6);
	addChar(53, 27, 6);
	addChar(54, 28, 6);
	addChar(55, 29, 6);
	addChar(56, 30, 6);
	addChar(57, 31, 6);
	addChar(58, 92, 7);
	addChar(59, 251, 8);
	addChar(60, 32764, 15);
	addChar(61, 32, 6);
	addChar(62, 4091, 12);
	addChar(63, 1020, 10);
	addChar(64, 8186, 13);
	addChar(65, 33, 6);
	addChar(66, 93, 7);
	addChar(67, 94, 7);
	addChar(68, 95, 7);
	addChar(69, 96, 7);
	addChar(70, 97, 7);
	addChar(71, 98, 7);
	addChar(72, 99, 7);
	addChar(73, 100, 7);
	addChar(74, 101, 7);
	addChar(75, 102, 7);
	addChar(76, 103, 7);
	addChar(77, 104, 7);
	addChar(78, 105, 7);
	addChar(79, 106, 7);
	addChar(80, 107, 7);
	addChar(81, 108, 7);
	addChar(82, 109, 7);
	addChar(83, 110, 7);
	addChar(84, 111, 7);
	addChar(85, 112, 7);
	addChar(86, 113, 7);
	addChar(87, 114, 7);
	addChar(88, 252, 8);
	addChar(89, 115, 7);
	addChar(90, 253, 8);
	addChar(91, 8187, 13);
	addChar(92, 0x0007FFF0, 19);
	addChar(93, 8188, 13);
	addChar(94, 16380, 14);
	addChar(95, 34, 6);
	addChar(96, 32765, 15);
	addChar(97, 3, 5);
	addChar(98, 35, 6);
	addChar(99, 4, 5);
	addChar(100, 36, 6);
	addChar(101, 5, 5);
	addChar(102, 37, 6);
	addChar(103, 38, 6);
	addChar(104, 39, 6);
	addChar(105, 6, 5);
	addChar(106, 116, 7);
	addChar(107, 117, 7);
	addChar(108, 40, 6);
	addChar(109, 41, 6);
	addChar(110, 42, 6);
	addChar(111, 7, 5);
	addChar(112, 43, 6);
	addChar(113, 118, 7);
	addChar(114, 44, 6);
	addChar(115, 8, 5);
	addChar(116, 9, 5);
	addChar(117, 45, 6);
	addChar(118, 119, 7);
	addChar(119, 120, 7);
	addChar(120, 121, 7);
	addChar(121, 122, 7);
	addChar(122, 123, 7);
	addChar(123, 32766, 15);
	addChar(124, 2044, 11);
	addChar(125, 16381, 14);
	addChar(126, 8189, 13);
	addChar(127, 0x0FFFFFFC, 28);
	addChar(128, 0x000FFFE6, 20);
	addChar(129, 0x003FFFD2, 22);
	addChar(130, 0x000FFFE7, 20);
	addChar(131, 0x000FFFE8, 20);
	addChar(132, 0x003FFFD3, 22);
	addChar(133, 0x003FFFD4, 22);
	addChar(134, 0x003FFFD5, 22);
	addChar(135, 0x007FFFD9, 23);
	addChar(136, 0x003FFFD6, 22);
	addChar(137, 0x007FFFDA, 23);
	addChar(138, 0x007FFFDB, 23);
	addChar(139, 0x007FFFDC, 23);
	addChar(140, 0x007FFFDD, 23);
	addChar(141, 0x007FFFDE, 23);
	addChar(142, 0x00FFFFEB, 24);
	addChar(143, 0x007FFFDF, 23);
	addChar(144, 0x00FFFFEC, 24);
	addChar(145, 0x00FFFFED, 24);
	addChar(146, 0x003FFFD7, 22);
	addChar(147, 0x007FFFE0, 23);
	addChar(148, 0x00FFFFEE, 24);
	addChar(149, 0x007FFFE1, 23);
	addChar(150, 0x007FFFE2, 23);
	addChar(151, 0x007FFFE3, 23);
	addChar(152, 0x007FFFE4, 23);
	addChar(153, 0x001FFFDC, 21);
	addChar(154, 0x003FFFD8, 22);
	addChar(155, 0x007FFFE5, 23);
	addChar(156, 0x003FFFD9, 22);
	addChar(157, 0x007FFFE6, 23);
	addChar(158, 0x007FFFE7, 23);
	addChar(159, 0x00FFFFEF, 24);
	addChar(160, 0x003FFFDA, 22);
	addChar(161, 0x001FFFDD, 21);
	addChar(162, 0x000FFFE9, 20);
	addChar(163, 0x003FFFDB, 22);
	addChar(164, 0x003FFFDC, 22);
	addChar(165, 0x007FFFE8, 23);
	addChar(166, 0x007FFFE9, 23);
	addChar(167, 0x001FFFDE, 21);
	addChar(168, 0x007FFFEA, 23);
	addChar(169, 0x003FFFDD, 22);
	addChar(170, 0x003FFFDE, 22);
	addChar(171, 0x00FFFFF0, 24);
	addChar(172, 0x001FFFDF, 21);
	addChar(173, 0x003FFFDF, 22);
	addChar(174, 0x007FFFEB, 23);
	addChar(175, 0x007FFFEC, 23);
	addChar(176, 0x001FFFE0, 21);
	addChar(177, 0x001FFFE1, 21);
	addChar(178, 0x003FFFE0, 22);
	addChar(179, 0x001FFFE2, 21);
	addChar(180, 0x007FFFED, 23);
	addChar(181, 0x003FFFE1, 22);
	addChar(182, 0x007FFFEE, 23);
	addChar(183, 0x007FFFEF, 23);
	addChar(184, 0x000FFFEA, 20);
	addChar(185, 0x003FFFE2, 22);
	addChar(186, 0x003FFFE3, 22);
	addChar(187, 0x003FFFE4, 22);
	addChar(188, 0x007FFFF0, 23);
	addChar(189, 0x003FFFE5, 22);
	addChar(190, 0x003FFFE6, 22);
	addChar(191, 0x007FFFF1, 23);
	addChar(192, 0x03FFFFE0, 26);
	addChar(193, 0x03FFFFE1, 26);
	addChar(194, 0x000FFFEB, 20);
	addChar(195, 0x0007FFF1, 19);
	addChar(196, 0x003FFFE7, 22);
	addChar(197, 0x007FFFF2, 23);
	addChar(198, 0x003FFFE8, 22);
	addChar(199, 0x01FFFFEC, 25);
	addChar(200, 0x03FFFFE2, 26);
	addChar(201, 0x03FFFFE3, 26);
	addChar(202, 0x03FFFFE4, 26);
	addChar(203, 0x07FFFFDE, 27);
	addChar(204, 0x07FFFFDF, 27);
	addChar(205, 0x03FFFFE5, 26);
	addChar(206, 0x00FFFFF1, 24);
	addChar(207, 0x01FFFFED, 25);
	addChar(208, 0x0007FFF2, 19);
	addChar(209, 0x001FFFE3, 21);
	addChar(210, 0x03FFFFE6, 26);
	addChar(211, 0x07FFFFE0, 27);
	addChar(212, 0x07FFFFE1, 27);
	addChar(213, 0x03FFFFE7, 26);
	addChar(214, 0x07FFFFE2, 27);
	addChar(215, 0x00FFFFF2, 24);
	addChar(216, 0x001FFFE4, 21);
	addChar(217, 0x001FFFE5, 21);
	addChar(218, 0x03FFFFE8, 26);
	addChar(219, 0x03FFFFE9, 26);
	addChar(220, 0x0FFFFFFD, 28);
	addChar(221, 0x07FFFFE3, 27);
	addChar(222, 0x07FFFFE4, 27);
	addChar(223, 0x07FFFFE5, 27);
	addChar(224, 0x000FFFEC, 20);
	addChar(225, 0x00FFFFF3, 24);
	addChar(226, 0x000FFFED, 20);
	addChar(227, 0x001FFFE6, 21);
	addChar(228, 0x003FFFE9, 22);
	addChar(229, 0x001FFFE7, 21);
	addChar(230, 0x001FFFE8, 21);
	addChar(231, 0x007FFFF3, 23);
	addChar(232, 0x003FFFEA, 22);
	addChar(233, 0x003FFFEB, 22);
	addChar(234, 0x01FFFFEE, 25);
	addChar(235, 0x01FFFFEF, 25);
	addChar(236, 0x00FFFFF4, 24);
	addChar(237, 0x00FFFFF5, 24);
	addChar(238, 0x03FFFFEA, 26);
	addChar(239, 0x007FFFF4, 23);
	addChar(240, 0x03FFFFEB, 26);
	addChar(241, 0x07FFFFE6, 27);
	addChar(242, 0x03FFFFEC, 26);
	addChar(243, 0x03FFFFED, 26);
	addChar(244, 0x07FFFFE7, 27);
	addChar(245, 0x07FFFFE8, 27);
	addChar(246, 0x07FFFFE9, 27);
	addChar(247, 0x07FFFFEA, 27);
	addChar(248, 0x07FFFFEB, 27);
	addChar(249, 0x0FFFFFFE, 28);
	addChar(250, 0x07FFFFEC, 27);
	addChar(251, 0x07FFFFED, 27);
	addChar(252, 0x07FFFFEE, 27);
	addChar(253, 0x07FFFFEF, 27);
	addChar(254, 0x07FFFFF0, 27);
	addChar(255, 0x03FFFFEE, 26);
	addEOS(256, $nc(this->EOS)->code, $nc(this->EOS)->length);
}

int32_t NaiveHuffman::lengthOf($CharSequence* value) {
	return lengthOf(value, 0, $nc(value)->length());
}

int32_t NaiveHuffman::lengthOf($CharSequence* value, int32_t start, int32_t end) {
	$useLocalCurrentObjectStackCache();
	int32_t len = 0;
	for (int32_t i = start; i < end; ++i) {
		char16_t c = $nc(value)->charAt(i);
		len += $nc($($nc(NaiveHuffman::INSTANCE)->codeOf(c)))->length;
	}
	if (!NaiveHuffman::$assertionsDisabled && !((len / 8 + (len % 8 != 0 ? 1 : 0)) == (len + 7) / 8)) {
		$throwNew($AssertionError, len);
	}
	return (len + 7) / 8;
}

void NaiveHuffman::addChar(int32_t c, int32_t code, int32_t bitLength) {
	addLeaf(c, code, bitLength, false);
	$nc(this->codes)->set(c, $$new($NaiveHuffman$Code, code, bitLength));
}

void NaiveHuffman::addEOS(int32_t c, int32_t code, int32_t bitLength) {
	addLeaf(c, code, bitLength, true);
	$nc(this->codes)->set(c, $$new($NaiveHuffman$Code, code, bitLength));
}

void NaiveHuffman::addLeaf(int32_t c, int32_t code, int32_t bitLength, bool isEOS) {
	if (bitLength < 1) {
		$throwNew($IllegalArgumentException, "bitLength < 1"_s);
	}
	$var($NaiveHuffman$Node, curr, this->root);
	for (int32_t p = $sl(1, bitLength - 1); p != 0 && !$nc(curr)->isLeaf(); p = p >> 1) {
		curr->isEOSPath |= isEOS;
		$assign(curr, curr->addChildIfAbsent((int32_t)(p & (uint32_t)code)));
	}
	$nc(curr)->isEOSPath |= isEOS;
	if (curr->isLeaf()) {
		$throwNew($IllegalStateException, "Specified code is already taken"_s);
	}
	curr->setChar((char16_t)c);
}

$NaiveHuffman$Code* NaiveHuffman::codeOf(char16_t c) {
	$useLocalCurrentObjectStackCache();
	if (c > 255) {
		$throwNew($IllegalArgumentException, $$str({"char="_s, $$str(((int32_t)c))}));
	}
	return $nc(this->codes)->get(c);
}

$NaiveHuffman$Node* NaiveHuffman::getRoot() {
	return this->root;
}

void clinit$NaiveHuffman($Class* class$) {
	NaiveHuffman::$assertionsDisabled = !NaiveHuffman::class$->desiredAssertionStatus();
	$assignStatic(NaiveHuffman::INSTANCE, $new(NaiveHuffman));
}

NaiveHuffman::NaiveHuffman() {
}

$Class* NaiveHuffman::load$($String* name, bool initialize) {
	$loadClass(NaiveHuffman, name, initialize, &_NaiveHuffman_ClassInfo_, clinit$NaiveHuffman, allocate$NaiveHuffman);
	return class$;
}

$Class* NaiveHuffman::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk