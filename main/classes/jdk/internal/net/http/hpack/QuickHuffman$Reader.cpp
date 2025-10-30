#include <jdk/internal/net/http/hpack/QuickHuffman$Reader.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/Appendable.h>
#include <java/lang/Math.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <jdk/internal/net/http/hpack/HPACK$BufferUpdateConsumer.h>
#include <jdk/internal/net/http/hpack/HPACK.h>
#include <jdk/internal/net/http/hpack/QuickHuffman$Node.h>
#include <jdk/internal/net/http/hpack/QuickHuffman.h>
#include <jcpp.h>

#undef UPDATER

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $Appendable = ::java::lang::Appendable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $HPACK = ::jdk::internal::net::http::hpack::HPACK;
using $HPACK$BufferUpdateConsumer = ::jdk::internal::net::http::hpack::HPACK$BufferUpdateConsumer;
using $Huffman$Reader = ::jdk::internal::net::http::hpack::Huffman$Reader;
using $QuickHuffman = ::jdk::internal::net::http::hpack::QuickHuffman;
using $QuickHuffman$Node = ::jdk::internal::net::http::hpack::QuickHuffman$Node;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class QuickHuffman$Reader$$Lambda$lambda$new$0 : public $HPACK$BufferUpdateConsumer {
	$class(QuickHuffman$Reader$$Lambda$lambda$new$0, $NO_CLASS_INIT, $HPACK$BufferUpdateConsumer)
public:
	void init$(QuickHuffman$Reader* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(int64_t buf, int32_t bufLen) override {
		$nc(inst$)->lambda$new$0(buf, bufLen);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<QuickHuffman$Reader$$Lambda$lambda$new$0>());
	}
	QuickHuffman$Reader* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo QuickHuffman$Reader$$Lambda$lambda$new$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(QuickHuffman$Reader$$Lambda$lambda$new$0, inst$)},
	{}
};
$MethodInfo QuickHuffman$Reader$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/QuickHuffman$Reader;)V", nullptr, $PUBLIC, $method(static_cast<void(QuickHuffman$Reader$$Lambda$lambda$new$0::*)(QuickHuffman$Reader*)>(&QuickHuffman$Reader$$Lambda$lambda$new$0::init$))},
	{"accept", "(JI)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo QuickHuffman$Reader$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.QuickHuffman$Reader$$Lambda$lambda$new$0",
	"java.lang.Object",
	"jdk.internal.net.http.hpack.HPACK$BufferUpdateConsumer",
	fieldInfos,
	methodInfos
};
$Class* QuickHuffman$Reader$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(QuickHuffman$Reader$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* QuickHuffman$Reader$$Lambda$lambda$new$0::class$ = nullptr;

$FieldInfo _QuickHuffman$Reader_FieldInfo_[] = {
	{"UPDATER", "Ljdk/internal/net/http/hpack/HPACK$BufferUpdateConsumer;", nullptr, $PRIVATE | $FINAL, $field(QuickHuffman$Reader, UPDATER)},
	{"curr", "Ljdk/internal/net/http/hpack/QuickHuffman$Node;", nullptr, $PRIVATE, $field(QuickHuffman$Reader, curr)},
	{"buffer", "J", nullptr, $PRIVATE, $field(QuickHuffman$Reader, buffer)},
	{"bufferLen", "I", nullptr, $PRIVATE, $field(QuickHuffman$Reader, bufferLen)},
	{"len", "I", nullptr, $PRIVATE, $field(QuickHuffman$Reader, len)},
	{"done", "Z", nullptr, $PRIVATE, $field(QuickHuffman$Reader, done)},
	{}
};

$MethodInfo _QuickHuffman$Reader_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(QuickHuffman$Reader::*)()>(&QuickHuffman$Reader::init$))},
	{"lambda$new$0", "(JI)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(QuickHuffman$Reader::*)(int64_t,int32_t)>(&QuickHuffman$Reader::lambda$new$0))},
	{"read", "(Ljava/nio/ByteBuffer;Ljava/lang/Appendable;Z)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"reset", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _QuickHuffman$Reader_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.QuickHuffman$Reader", "jdk.internal.net.http.hpack.QuickHuffman", "Reader", $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.Huffman$Reader", "jdk.internal.net.http.hpack.Huffman", "Reader", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _QuickHuffman$Reader_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.QuickHuffman$Reader",
	"java.lang.Object",
	"jdk.internal.net.http.hpack.Huffman$Reader",
	_QuickHuffman$Reader_FieldInfo_,
	_QuickHuffman$Reader_MethodInfo_,
	nullptr,
	nullptr,
	_QuickHuffman$Reader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.QuickHuffman"
};

$Object* allocate$QuickHuffman$Reader($Class* clazz) {
	return $of($alloc(QuickHuffman$Reader));
}

void QuickHuffman$Reader::init$() {
	$set(this, UPDATER, static_cast<$HPACK$BufferUpdateConsumer*>($new(QuickHuffman$Reader$$Lambda$lambda$new$0, this)));
	$init($QuickHuffman);
	$set(this, curr, $QuickHuffman::root);
}

void QuickHuffman$Reader::read($ByteBuffer* source, $Appendable* destination, bool isLast) {
	$useLocalCurrentObjectStackCache();
	while (!this->done) {
		int32_t remaining = $nc(source)->remaining();
		int32_t nBytes = $HPACK::read(source, this->buffer, this->bufferLen, this->UPDATER);
		while (true) {
			if (this->bufferLen < 8) {
				if (nBytes < remaining) {
					break;
				} else if (!isLast) {
					return;
				} else if (this->bufferLen > 0) {
					this->buffer |= ((int64_t)(($usr((int64_t)0xFF00000000000000, this->bufferLen)) & (uint64_t)(int64_t)0xFF00000000000000));
				} else {
					this->done = true;
					break;
				}
			}
			int32_t idx = (int32_t)((int64_t)((uint64_t)this->buffer >> 56));
			$var($QuickHuffman$Node, node, $nc(this->curr)->getChild(idx));
			if (node == nullptr) {
				$throwNew($IOException, "Unexpected byte"_s);
			}
			if ($nc(node)->isLeaf()) {
				if (node->getLength() > this->bufferLen) {
					$throwNew($IOException, "Not a EOS prefix padding or unexpected end of data"_s);
				}
				if (node->isEOSPath()) {
					$throwNew($IOException, "Encountered EOS"_s);
				}
				$nc(destination)->append(node->getSymbol());
				$init($QuickHuffman);
				$set(this, curr, $QuickHuffman::root);
				this->len = 0;
			} else {
				$set(this, curr, node);
				this->len += $Math::min(this->bufferLen, node->getLength());
			}
			this->buffer <<= $nc(node)->getLength();
			this->bufferLen -= node->getLength();
		}
		if (this->done && ($nc(this->curr)->isEOSPath() && this->len > 7)) {
			$throwNew($IOException, $$str({"Padding is too long (len="_s, $$str(this->len), ") or unexpected end of data"_s}));
		}
	}
}

void QuickHuffman$Reader::reset() {
	$init($QuickHuffman);
	$set(this, curr, $QuickHuffman::root);
	this->len = 0;
	this->buffer = 0;
	this->bufferLen = 0;
	this->done = false;
}

void QuickHuffman$Reader::lambda$new$0(int64_t buf, int32_t bufLen) {
	this->buffer = buf;
	this->bufferLen = bufLen;
}

QuickHuffman$Reader::QuickHuffman$Reader() {
}

$Class* QuickHuffman$Reader::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(QuickHuffman$Reader$$Lambda$lambda$new$0::classInfo$.name)) {
			return QuickHuffman$Reader$$Lambda$lambda$new$0::load$(name, initialize);
		}
	}
	$loadClass(QuickHuffman$Reader, name, initialize, &_QuickHuffman$Reader_ClassInfo_, allocate$QuickHuffman$Reader);
	return class$;
}

$Class* QuickHuffman$Reader::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk