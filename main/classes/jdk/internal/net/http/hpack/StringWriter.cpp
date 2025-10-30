#include <jdk/internal/net/http/hpack/StringWriter.h>

#include <java/lang/CharSequence.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/InternalError.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Arrays.h>
#include <jdk/internal/net/http/hpack/Huffman$Writer.h>
#include <jdk/internal/net/http/hpack/ISO_8859_1$Writer.h>
#include <jdk/internal/net/http/hpack/IntegerWriter.h>
#include <jdk/internal/net/http/hpack/QuickHuffman$Writer.h>
#include <jcpp.h>

#undef CONFIGURED
#undef DONE
#undef LENGTH_WRITTEN
#undef NEW

using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Arrays = ::java::util::Arrays;
using $Huffman$Writer = ::jdk::internal::net::http::hpack::Huffman$Writer;
using $ISO_8859_1$Writer = ::jdk::internal::net::http::hpack::ISO_8859_1$Writer;
using $IntegerWriter = ::jdk::internal::net::http::hpack::IntegerWriter;
using $QuickHuffman$Writer = ::jdk::internal::net::http::hpack::QuickHuffman$Writer;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _StringWriter_FieldInfo_[] = {
	{"NEW", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringWriter, NEW)},
	{"CONFIGURED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringWriter, CONFIGURED)},
	{"LENGTH_WRITTEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringWriter, LENGTH_WRITTEN)},
	{"DONE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StringWriter, DONE)},
	{"intWriter", "Ljdk/internal/net/http/hpack/IntegerWriter;", nullptr, $PRIVATE | $FINAL, $field(StringWriter, intWriter)},
	{"huffmanWriter", "Ljdk/internal/net/http/hpack/Huffman$Writer;", nullptr, $PRIVATE | $FINAL, $field(StringWriter, huffmanWriter)},
	{"plainWriter", "Ljdk/internal/net/http/hpack/ISO_8859_1$Writer;", nullptr, $PRIVATE | $FINAL, $field(StringWriter, plainWriter)},
	{"state", "I", nullptr, $PRIVATE, $field(StringWriter, state)},
	{"huffman", "Z", nullptr, $PRIVATE, $field(StringWriter, huffman)},
	{}
};

$MethodInfo _StringWriter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(StringWriter::*)()>(&StringWriter::init$))},
	{"configure", "(Ljava/lang/CharSequence;Z)Ljdk/internal/net/http/hpack/StringWriter;", nullptr, 0, $method(static_cast<StringWriter*(StringWriter::*)($CharSequence*,bool)>(&StringWriter::configure))},
	{"configure", "(Ljava/lang/CharSequence;IIZ)Ljdk/internal/net/http/hpack/StringWriter;", nullptr, 0, $method(static_cast<StringWriter*(StringWriter::*)($CharSequence*,int32_t,int32_t,bool)>(&StringWriter::configure))},
	{"reset", "()V", nullptr, 0, $method(static_cast<void(StringWriter::*)()>(&StringWriter::reset))},
	{"write", "(Ljava/nio/ByteBuffer;)Z", nullptr, 0, $method(static_cast<bool(StringWriter::*)($ByteBuffer*)>(&StringWriter::write))},
	{}
};

$ClassInfo _StringWriter_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.StringWriter",
	"java.lang.Object",
	nullptr,
	_StringWriter_FieldInfo_,
	_StringWriter_MethodInfo_
};

$Object* allocate$StringWriter($Class* clazz) {
	return $of($alloc(StringWriter));
}

void StringWriter::init$() {
	$set(this, intWriter, $new($IntegerWriter));
	$set(this, huffmanWriter, $new($QuickHuffman$Writer));
	$set(this, plainWriter, $new($ISO_8859_1$Writer));
	this->state = StringWriter::NEW;
}

StringWriter* StringWriter::configure($CharSequence* input, bool huffman) {
	return configure(input, 0, $nc(input)->length(), huffman);
}

StringWriter* StringWriter::configure($CharSequence* input, int32_t start, int32_t end, bool huffman) {
	$useLocalCurrentObjectStackCache();
	if (start < 0 || end < 0 || end > $nc(input)->length() || start > end) {
		$throwNew($IndexOutOfBoundsException, $($String::format("input.length()=%s, start=%s, end=%s"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf($nc(input)->length()))),
			$($of($Integer::valueOf(start))),
			$($of($Integer::valueOf(end)))
		}))));
	}
	if (!huffman) {
		$nc(this->plainWriter)->configure(input, start, end);
		$nc(this->intWriter)->configure(end - start, 7, 0);
	} else {
		$nc(this->huffmanWriter)->from(input, start, end);
		$nc(this->intWriter)->configure($nc(this->huffmanWriter)->lengthOf(input, start, end), 7, 128);
	}
	this->huffman = huffman;
	this->state = StringWriter::CONFIGURED;
	return this;
}

bool StringWriter::write($ByteBuffer* output) {
	$useLocalCurrentObjectStackCache();
	if (this->state == StringWriter::DONE) {
		return true;
	}
	if (this->state == StringWriter::NEW) {
		$throwNew($IllegalStateException, "Configure first"_s);
	}
	if (!$nc(output)->hasRemaining()) {
		return false;
	}
	if (this->state == StringWriter::CONFIGURED) {
		if ($nc(this->intWriter)->write(output)) {
			this->state = StringWriter::LENGTH_WRITTEN;
		} else {
			return false;
		}
	}
	if (this->state == StringWriter::LENGTH_WRITTEN) {
		bool written = this->huffman ? $nc(this->huffmanWriter)->write(output) : $nc(this->plainWriter)->write(output);
		if (written) {
			this->state = StringWriter::DONE;
			return true;
		} else {
			return false;
		}
	}
	$throwNew($InternalError, $($Arrays::toString($$new($ObjectArray, {
		$($of($Integer::valueOf(this->state))),
		$($of($Boolean::valueOf(this->huffman)))
	}))));
}

void StringWriter::reset() {
	$nc(this->intWriter)->reset();
	if (this->huffman) {
		$nc(this->huffmanWriter)->reset();
	} else {
		$nc(this->plainWriter)->reset();
	}
	this->state = StringWriter::NEW;
}

StringWriter::StringWriter() {
}

$Class* StringWriter::load$($String* name, bool initialize) {
	$loadClass(StringWriter, name, initialize, &_StringWriter_ClassInfo_, allocate$StringWriter);
	return class$;
}

$Class* StringWriter::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk