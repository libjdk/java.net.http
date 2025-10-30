#include <jdk/internal/net/http/hpack/StringReader.h>

#include <java/lang/Appendable.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Arrays.h>
#include <jdk/internal/net/http/hpack/Huffman$Reader.h>
#include <jdk/internal/net/http/hpack/ISO_8859_1$Reader.h>
#include <jdk/internal/net/http/hpack/IntegerReader.h>
#include <jdk/internal/net/http/hpack/QuickHuffman$Reader.h>
#include <jcpp.h>

#undef DONE
#undef FIRST_BYTE_READ
#undef LENGTH_READ
#undef NEW

using $Appendable = ::java::lang::Appendable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Arrays = ::java::util::Arrays;
using $Huffman$Reader = ::jdk::internal::net::http::hpack::Huffman$Reader;
using $ISO_8859_1$Reader = ::jdk::internal::net::http::hpack::ISO_8859_1$Reader;
using $IntegerReader = ::jdk::internal::net::http::hpack::IntegerReader;
using $QuickHuffman$Reader = ::jdk::internal::net::http::hpack::QuickHuffman$Reader;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _StringReader_FieldInfo_[] = {
	{"NEW", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringReader, NEW)},
	{"FIRST_BYTE_READ", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringReader, FIRST_BYTE_READ)},
	{"LENGTH_READ", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringReader, LENGTH_READ)},
	{"DONE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringReader, DONE)},
	{"intReader", "Ljdk/internal/net/http/hpack/IntegerReader;", nullptr, $PRIVATE | $FINAL, $field(StringReader, intReader)},
	{"huffmanReader", "Ljdk/internal/net/http/hpack/Huffman$Reader;", nullptr, $PRIVATE | $FINAL, $field(StringReader, huffmanReader)},
	{"plainReader", "Ljdk/internal/net/http/hpack/ISO_8859_1$Reader;", nullptr, $PRIVATE | $FINAL, $field(StringReader, plainReader)},
	{"state", "I", nullptr, $PRIVATE, $field(StringReader, state)},
	{"huffman", "Z", nullptr, $PRIVATE, $field(StringReader, huffman)},
	{"remainingLength", "I", nullptr, $PRIVATE, $field(StringReader, remainingLength)},
	{}
};

$MethodInfo _StringReader_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(StringReader::*)()>(&StringReader::init$))},
	{"isHuffmanEncoded", "()Z", nullptr, 0, $method(static_cast<bool(StringReader::*)()>(&StringReader::isHuffmanEncoded))},
	{"read", "(Ljava/nio/ByteBuffer;Ljava/lang/Appendable;)Z", nullptr, 0, $method(static_cast<bool(StringReader::*)($ByteBuffer*,$Appendable*)>(&StringReader::read)), "java.io.IOException"},
	{"reset", "()V", nullptr, 0, $method(static_cast<void(StringReader::*)()>(&StringReader::reset))},
	{}
};

$ClassInfo _StringReader_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.StringReader",
	"java.lang.Object",
	nullptr,
	_StringReader_FieldInfo_,
	_StringReader_MethodInfo_
};

$Object* allocate$StringReader($Class* clazz) {
	return $of($alloc(StringReader));
}

void StringReader::init$() {
	$set(this, intReader, $new($IntegerReader));
	$set(this, huffmanReader, $new($QuickHuffman$Reader));
	$set(this, plainReader, $new($ISO_8859_1$Reader));
	this->state = StringReader::NEW;
}

bool StringReader::read($ByteBuffer* input, $Appendable* output) {
	$useLocalCurrentObjectStackCache();
	if (this->state == StringReader::DONE) {
		return true;
	}
	if (!$nc(input)->hasRemaining()) {
		return false;
	}
	if (this->state == StringReader::NEW) {
		int32_t p = $nc(input)->position();
		this->huffman = ((int32_t)(input->get(p) & (uint32_t)128)) != 0;
		this->state = StringReader::FIRST_BYTE_READ;
		$nc(this->intReader)->configure(7);
	}
	if (this->state == StringReader::FIRST_BYTE_READ) {
		bool lengthRead = $nc(this->intReader)->read(input);
		if (!lengthRead) {
			return false;
		}
		this->remainingLength = $nc(this->intReader)->get();
		this->state = StringReader::LENGTH_READ;
	}
	if (this->state == StringReader::LENGTH_READ) {
		bool isLast = $nc(input)->remaining() >= this->remainingLength;
		int32_t oldLimit = input->limit();
		if (isLast) {
			input->limit(input->position() + this->remainingLength);
		}
		this->remainingLength -= $Math::min(input->remaining(), this->remainingLength);
		if (this->huffman) {
			$nc(this->huffmanReader)->read(input, output, isLast);
		} else {
			$nc(this->plainReader)->read(input, output);
		}
		if (isLast) {
			input->limit(oldLimit);
			this->state = StringReader::DONE;
		}
		return isLast;
	}
	$throwNew($InternalError, $($Arrays::toString($$new($ObjectArray, {
		$($of($Integer::valueOf(this->state))),
		$($of($Boolean::valueOf(this->huffman))),
		$($of($Integer::valueOf(this->remainingLength)))
	}))));
}

bool StringReader::isHuffmanEncoded() {
	if (this->state < StringReader::FIRST_BYTE_READ) {
		$throwNew($IllegalStateException, "Has not been fully read yet"_s);
	}
	return this->huffman;
}

void StringReader::reset() {
	if (this->huffman) {
		$nc(this->huffmanReader)->reset();
	} else {
		$nc(this->plainReader)->reset();
	}
	$nc(this->intReader)->reset();
	this->state = StringReader::NEW;
}

StringReader::StringReader() {
}

$Class* StringReader::load$($String* name, bool initialize) {
	$loadClass(StringReader, name, initialize, &_StringReader_ClassInfo_, allocate$StringReader);
	return class$;
}

$Class* StringReader::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk