#include <jdk/internal/net/http/hpack/IndexNameValueWriter.h>

#include <java/lang/CharSequence.h>
#include <java/nio/ByteBuffer.h>
#include <jdk/internal/net/http/hpack/HeaderTable.h>
#include <jdk/internal/net/http/hpack/IntegerWriter.h>
#include <jdk/internal/net/http/hpack/StringWriter.h>
#include <jcpp.h>

#undef NAME_PART_WRITTEN
#undef NEW
#undef VALUE_WRITTEN

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $BinaryRepresentationWriter = ::jdk::internal::net::http::hpack::BinaryRepresentationWriter;
using $HeaderTable = ::jdk::internal::net::http::hpack::HeaderTable;
using $IntegerWriter = ::jdk::internal::net::http::hpack::IntegerWriter;
using $StringWriter = ::jdk::internal::net::http::hpack::StringWriter;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _IndexNameValueWriter_FieldInfo_[] = {
	{"pattern", "I", nullptr, $PRIVATE | $FINAL, $field(IndexNameValueWriter, pattern)},
	{"prefix", "I", nullptr, $PRIVATE | $FINAL, $field(IndexNameValueWriter, prefix)},
	{"intWriter", "Ljdk/internal/net/http/hpack/IntegerWriter;", nullptr, $PRIVATE | $FINAL, $field(IndexNameValueWriter, intWriter)},
	{"nameWriter", "Ljdk/internal/net/http/hpack/StringWriter;", nullptr, $PRIVATE | $FINAL, $field(IndexNameValueWriter, nameWriter)},
	{"valueWriter", "Ljdk/internal/net/http/hpack/StringWriter;", nullptr, $PRIVATE | $FINAL, $field(IndexNameValueWriter, valueWriter)},
	{"indexedRepresentation", "Z", nullptr, $PROTECTED, $field(IndexNameValueWriter, indexedRepresentation)},
	{"NEW", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(IndexNameValueWriter, NEW)},
	{"NAME_PART_WRITTEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(IndexNameValueWriter, NAME_PART_WRITTEN)},
	{"VALUE_WRITTEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(IndexNameValueWriter, VALUE_WRITTEN)},
	{"state", "I", nullptr, $PRIVATE, $field(IndexNameValueWriter, state)},
	{}
};

$MethodInfo _IndexNameValueWriter_MethodInfo_[] = {
	{"<init>", "(II)V", nullptr, $PROTECTED, $method(static_cast<void(IndexNameValueWriter::*)(int32_t,int32_t)>(&IndexNameValueWriter::init$))},
	{"index", "(I)Ljdk/internal/net/http/hpack/IndexNameValueWriter;", nullptr, 0},
	{"name", "(Ljava/lang/CharSequence;Z)Ljdk/internal/net/http/hpack/IndexNameValueWriter;", nullptr, 0},
	{"reset", "()Ljdk/internal/net/http/hpack/IndexNameValueWriter;", nullptr, $PUBLIC},
	{"value", "(Ljava/lang/CharSequence;Z)Ljdk/internal/net/http/hpack/IndexNameValueWriter;", nullptr, 0},
	{"write", "(Ljdk/internal/net/http/hpack/HeaderTable;Ljava/nio/ByteBuffer;)Z", nullptr, $PUBLIC},
	{}
};

$ClassInfo _IndexNameValueWriter_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.hpack.IndexNameValueWriter",
	"java.lang.Object",
	"jdk.internal.net.http.hpack.BinaryRepresentationWriter",
	_IndexNameValueWriter_FieldInfo_,
	_IndexNameValueWriter_MethodInfo_
};

$Object* allocate$IndexNameValueWriter($Class* clazz) {
	return $of($alloc(IndexNameValueWriter));
}

void IndexNameValueWriter::init$(int32_t pattern, int32_t prefix) {
	$set(this, intWriter, $new($IntegerWriter));
	$set(this, nameWriter, $new($StringWriter));
	$set(this, valueWriter, $new($StringWriter));
	this->state = IndexNameValueWriter::NEW;
	this->pattern = pattern;
	this->prefix = prefix;
}

IndexNameValueWriter* IndexNameValueWriter::index(int32_t index) {
	this->indexedRepresentation = true;
	$nc(this->intWriter)->configure(index, this->prefix, this->pattern);
	return this;
}

IndexNameValueWriter* IndexNameValueWriter::name($CharSequence* name, bool useHuffman) {
	this->indexedRepresentation = false;
	$nc(this->intWriter)->configure(0, this->prefix, this->pattern);
	$nc(this->nameWriter)->configure(name, useHuffman);
	return this;
}

IndexNameValueWriter* IndexNameValueWriter::value($CharSequence* value, bool useHuffman) {
	$nc(this->valueWriter)->configure(value, useHuffman);
	return this;
}

bool IndexNameValueWriter::write($HeaderTable* table, $ByteBuffer* destination) {
	if (this->state < IndexNameValueWriter::NAME_PART_WRITTEN) {
		if (this->indexedRepresentation) {
			if (!$nc(this->intWriter)->write(destination)) {
				return false;
			}
		} else {
			bool var$1 = !$nc(this->intWriter)->write(destination);
			if (var$1 || !$nc(this->nameWriter)->write(destination)) {
				return false;
			}
		}
		this->state = IndexNameValueWriter::NAME_PART_WRITTEN;
	}
	if (this->state < IndexNameValueWriter::VALUE_WRITTEN) {
		if (!$nc(this->valueWriter)->write(destination)) {
			return false;
		}
		this->state = IndexNameValueWriter::VALUE_WRITTEN;
	}
	return this->state == IndexNameValueWriter::VALUE_WRITTEN;
}

IndexNameValueWriter* IndexNameValueWriter::reset() {
	$nc(this->intWriter)->reset();
	if (!this->indexedRepresentation) {
		$nc(this->nameWriter)->reset();
	}
	$nc(this->valueWriter)->reset();
	this->state = IndexNameValueWriter::NEW;
	return this;
}

IndexNameValueWriter::IndexNameValueWriter() {
}

$Class* IndexNameValueWriter::load$($String* name, bool initialize) {
	$loadClass(IndexNameValueWriter, name, initialize, &_IndexNameValueWriter_ClassInfo_, allocate$IndexNameValueWriter);
	return class$;
}

$Class* IndexNameValueWriter::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk