#include <jdk/internal/net/http/hpack/NaiveHuffman$Writer.h>

#include <java/lang/CharSequence.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/nio/ByteBuffer.h>
#include <jdk/internal/net/http/hpack/NaiveHuffman$Code.h>
#include <jdk/internal/net/http/hpack/NaiveHuffman.h>
#include <jcpp.h>

#undef EOS
#undef INSTANCE

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Huffman$Writer = ::jdk::internal::net::http::hpack::Huffman$Writer;
using $NaiveHuffman = ::jdk::internal::net::http::hpack::NaiveHuffman;
using $NaiveHuffman$Code = ::jdk::internal::net::http::hpack::NaiveHuffman$Code;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _NaiveHuffman$Writer_FieldInfo_[] = {
	{"pos", "I", nullptr, $PRIVATE, $field(NaiveHuffman$Writer, pos)},
	{"avail", "I", nullptr, $PRIVATE, $field(NaiveHuffman$Writer, avail)},
	{"curr", "I", nullptr, $PRIVATE, $field(NaiveHuffman$Writer, curr)},
	{"rem", "I", nullptr, $PRIVATE, $field(NaiveHuffman$Writer, rem)},
	{"code", "I", nullptr, $PRIVATE, $field(NaiveHuffman$Writer, code)},
	{"source", "Ljava/lang/CharSequence;", nullptr, $PRIVATE, $field(NaiveHuffman$Writer, source)},
	{"end", "I", nullptr, $PRIVATE, $field(NaiveHuffman$Writer, end)},
	{}
};

$MethodInfo _NaiveHuffman$Writer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(NaiveHuffman$Writer::*)()>(&NaiveHuffman$Writer::init$))},
	{"from", "(Ljava/lang/CharSequence;II)Ljdk/internal/net/http/hpack/NaiveHuffman$Writer;", nullptr, $PUBLIC},
	{"lengthOf", "(Ljava/lang/CharSequence;II)I", nullptr, $PUBLIC},
	{"reset", "()Ljdk/internal/net/http/hpack/NaiveHuffman$Writer;", nullptr, $PUBLIC},
	{"write", "(Ljava/nio/ByteBuffer;)Z", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _NaiveHuffman$Writer_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.NaiveHuffman$Writer", "jdk.internal.net.http.hpack.NaiveHuffman", "Writer", $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.Huffman$Writer", "jdk.internal.net.http.hpack.Huffman", "Writer", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _NaiveHuffman$Writer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.NaiveHuffman$Writer",
	"java.lang.Object",
	"jdk.internal.net.http.hpack.Huffman$Writer",
	_NaiveHuffman$Writer_FieldInfo_,
	_NaiveHuffman$Writer_MethodInfo_,
	nullptr,
	nullptr,
	_NaiveHuffman$Writer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.NaiveHuffman"
};

$Object* allocate$NaiveHuffman$Writer($Class* clazz) {
	return $of($alloc(NaiveHuffman$Writer));
}

void NaiveHuffman$Writer::init$() {
	this->avail = 8;
}

NaiveHuffman$Writer* NaiveHuffman$Writer::from($CharSequence* input, int32_t start, int32_t end) {
	$useLocalCurrentObjectStackCache();
	if (start < 0 || end < 0 || end > $nc(input)->length() || start > end) {
		$throwNew($IndexOutOfBoundsException, $($String::format("input.length()=%s, start=%s, end=%s"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf($nc(input)->length()))),
			$($of($Integer::valueOf(start))),
			$($of($Integer::valueOf(end)))
		}))));
	}
	this->pos = start;
	this->end = end;
	$set(this, source, input);
	return this;
}

bool NaiveHuffman$Writer::write($ByteBuffer* destination) {
	$useLocalCurrentObjectStackCache();
	for (; this->pos < this->end; ++this->pos) {
		if (this->rem == 0) {
			$init($NaiveHuffman);
			$var($NaiveHuffman$Code, desc, $nc($NaiveHuffman::INSTANCE)->codeOf($nc(this->source)->charAt(this->pos)));
			this->rem = $nc(desc)->length;
			this->code = desc->code;
		}
		while (this->rem > 0) {
			if (this->rem < this->avail) {
				this->curr |= ($sl(this->code, this->avail - this->rem));
				this->avail -= this->rem;
				this->rem = 0;
			} else {
				int32_t c = (this->curr | ($usr(this->code, this->rem - this->avail)));
				if ($nc(destination)->hasRemaining()) {
					destination->put((int8_t)c);
				} else {
					return false;
				}
				this->curr = c;
				this->code <<= (32 - this->rem + this->avail);
				$usrAssign(this->code, 32 - this->rem + this->avail);
				this->rem -= this->avail;
				this->curr = 0;
				this->avail = 8;
			}
		}
	}
	if (this->avail < 8) {
		if ($nc(destination)->hasRemaining()) {
			$init($NaiveHuffman);
			destination->put((int8_t)(this->curr | ($usr($nc($nc($NaiveHuffman::INSTANCE)->EOS)->code, $nc($nc($NaiveHuffman::INSTANCE)->EOS)->length - this->avail))));
			this->avail = 8;
		} else {
			return false;
		}
	}
	return true;
}

NaiveHuffman$Writer* NaiveHuffman$Writer::reset() {
	$set(this, source, nullptr);
	this->end = -1;
	this->pos = -1;
	this->avail = 8;
	this->curr = 0;
	this->code = 0;
	return this;
}

int32_t NaiveHuffman$Writer::lengthOf($CharSequence* value, int32_t start, int32_t end) {
	$init($NaiveHuffman);
	return $nc($NaiveHuffman::INSTANCE)->lengthOf(value, start, end);
}

NaiveHuffman$Writer::NaiveHuffman$Writer() {
}

$Class* NaiveHuffman$Writer::load$($String* name, bool initialize) {
	$loadClass(NaiveHuffman$Writer, name, initialize, &_NaiveHuffman$Writer_ClassInfo_, allocate$NaiveHuffman$Writer);
	return class$;
}

$Class* NaiveHuffman$Writer::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk