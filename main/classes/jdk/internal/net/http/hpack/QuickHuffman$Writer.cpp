#include <jdk/internal/net/http/hpack/QuickHuffman$Writer.h>

#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Objects.h>
#include <jdk/internal/net/http/hpack/HPACK$BufferUpdateConsumer.h>
#include <jdk/internal/net/http/hpack/HPACK.h>
#include <jdk/internal/net/http/hpack/QuickHuffman.h>
#include <jcpp.h>

#undef UPDATER

using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Objects = ::java::util::Objects;
using $HPACK = ::jdk::internal::net::http::hpack::HPACK;
using $HPACK$BufferUpdateConsumer = ::jdk::internal::net::http::hpack::HPACK$BufferUpdateConsumer;
using $Huffman$Writer = ::jdk::internal::net::http::hpack::Huffman$Writer;
using $QuickHuffman = ::jdk::internal::net::http::hpack::QuickHuffman;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class QuickHuffman$Writer$$Lambda$lambda$new$0 : public $HPACK$BufferUpdateConsumer {
	$class(QuickHuffman$Writer$$Lambda$lambda$new$0, $NO_CLASS_INIT, $HPACK$BufferUpdateConsumer)
public:
	void init$(QuickHuffman$Writer* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(int64_t buf, int32_t bufLen) override {
		$nc(inst$)->lambda$new$0(buf, bufLen);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<QuickHuffman$Writer$$Lambda$lambda$new$0>());
	}
	QuickHuffman$Writer* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo QuickHuffman$Writer$$Lambda$lambda$new$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(QuickHuffman$Writer$$Lambda$lambda$new$0, inst$)},
	{}
};
$MethodInfo QuickHuffman$Writer$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/QuickHuffman$Writer;)V", nullptr, $PUBLIC, $method(static_cast<void(QuickHuffman$Writer$$Lambda$lambda$new$0::*)(QuickHuffman$Writer*)>(&QuickHuffman$Writer$$Lambda$lambda$new$0::init$))},
	{"accept", "(JI)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo QuickHuffman$Writer$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.QuickHuffman$Writer$$Lambda$lambda$new$0",
	"java.lang.Object",
	"jdk.internal.net.http.hpack.HPACK$BufferUpdateConsumer",
	fieldInfos,
	methodInfos
};
$Class* QuickHuffman$Writer$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(QuickHuffman$Writer$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* QuickHuffman$Writer$$Lambda$lambda$new$0::class$ = nullptr;

$FieldInfo _QuickHuffman$Writer_FieldInfo_[] = {
	{"UPDATER", "Ljdk/internal/net/http/hpack/HPACK$BufferUpdateConsumer;", nullptr, $PRIVATE | $FINAL, $field(QuickHuffman$Writer, UPDATER)},
	{"source", "Ljava/lang/CharSequence;", nullptr, $PRIVATE, $field(QuickHuffman$Writer, source)},
	{"padded", "Z", nullptr, $PRIVATE, $field(QuickHuffman$Writer, padded)},
	{"pos", "I", nullptr, $PRIVATE, $field(QuickHuffman$Writer, pos)},
	{"end", "I", nullptr, $PRIVATE, $field(QuickHuffman$Writer, end)},
	{"buffer", "J", nullptr, $PRIVATE, $field(QuickHuffman$Writer, buffer)},
	{"bufferLen", "I", nullptr, $PRIVATE, $field(QuickHuffman$Writer, bufferLen)},
	{}
};

$MethodInfo _QuickHuffman$Writer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(QuickHuffman$Writer::*)()>(&QuickHuffman$Writer::init$))},
	{"from", "(Ljava/lang/CharSequence;II)Ljdk/internal/net/http/hpack/QuickHuffman$Writer;", nullptr, $PUBLIC},
	{"lambda$new$0", "(JI)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(QuickHuffman$Writer::*)(int64_t,int32_t)>(&QuickHuffman$Writer::lambda$new$0))},
	{"lengthOf", "(Ljava/lang/CharSequence;II)I", nullptr, $PUBLIC},
	{"reset", "()Ljdk/internal/net/http/hpack/QuickHuffman$Writer;", nullptr, $PUBLIC},
	{"write", "(Ljava/nio/ByteBuffer;)Z", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _QuickHuffman$Writer_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.QuickHuffman$Writer", "jdk.internal.net.http.hpack.QuickHuffman", "Writer", $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.Huffman$Writer", "jdk.internal.net.http.hpack.Huffman", "Writer", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _QuickHuffman$Writer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.QuickHuffman$Writer",
	"java.lang.Object",
	"jdk.internal.net.http.hpack.Huffman$Writer",
	_QuickHuffman$Writer_FieldInfo_,
	_QuickHuffman$Writer_MethodInfo_,
	nullptr,
	nullptr,
	_QuickHuffman$Writer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.QuickHuffman"
};

$Object* allocate$QuickHuffman$Writer($Class* clazz) {
	return $of($alloc(QuickHuffman$Writer));
}

void QuickHuffman$Writer::init$() {
	$set(this, UPDATER, static_cast<$HPACK$BufferUpdateConsumer*>($new(QuickHuffman$Writer$$Lambda$lambda$new$0, this)));
}

QuickHuffman$Writer* QuickHuffman$Writer::from($CharSequence* input, int32_t start, int32_t end) {
	$Objects::checkFromToIndex(start, end, $nc(input)->length());
	this->pos = start;
	this->end = end;
	$set(this, source, input);
	return this;
}

bool QuickHuffman$Writer::write($ByteBuffer* destination) {
	$useLocalCurrentObjectStackCache();
	while (true) {
		while (true) {
			if (this->pos >= this->end) {
				break;
			}
			char16_t c = $nc(this->source)->charAt(this->pos);
			if (c > 255) {
				$throwNew($IllegalArgumentException, $$str({"char="_s, $$str(((int32_t)c))}));
			}
			int64_t len = $QuickHuffman::codeLengthOf(c);
			if (this->bufferLen + len <= 64) {
				this->buffer |= ($usr($QuickHuffman::codeValueOf(c), this->bufferLen));
				this->bufferLen += len;
				++this->pos;
			} else {
				break;
			}
		}
		if (this->bufferLen == 0) {
			return true;
		}
		if (this->pos >= this->end && !this->padded) {
			this->padded = true;
			if (this->bufferLen != 64) {
				this->buffer |= ($usr((int64_t)0xFFFFFFFC00000000, this->bufferLen));
				this->bufferLen = $HPACK::bytesForBits(this->bufferLen) << 3;
			}
		}
		int32_t nBytes = $HPACK::write(this->buffer, this->bufferLen, this->UPDATER, destination);
		if (nBytes == 0) {
			return false;
		}
	}
}

QuickHuffman$Writer* QuickHuffman$Writer::reset() {
	$set(this, source, nullptr);
	this->buffer = 0;
	this->bufferLen = 0;
	this->end = 0;
	this->pos = 0;
	this->padded = false;
	return this;
}

int32_t QuickHuffman$Writer::lengthOf($CharSequence* value, int32_t start, int32_t end) {
	int32_t len = 0;
	for (int32_t i = start; i < end; ++i) {
		char16_t c = $nc(value)->charAt(i);
		len += $QuickHuffman::codeLengthOf(c);
	}
	return $HPACK::bytesForBits(len);
}

void QuickHuffman$Writer::lambda$new$0(int64_t buf, int32_t bufLen) {
	this->buffer = buf;
	this->bufferLen = bufLen;
}

QuickHuffman$Writer::QuickHuffman$Writer() {
}

$Class* QuickHuffman$Writer::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(QuickHuffman$Writer$$Lambda$lambda$new$0::classInfo$.name)) {
			return QuickHuffman$Writer$$Lambda$lambda$new$0::load$(name, initialize);
		}
	}
	$loadClass(QuickHuffman$Writer, name, initialize, &_QuickHuffman$Writer_ClassInfo_, allocate$QuickHuffman$Writer);
	return class$;
}

$Class* QuickHuffman$Writer::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk