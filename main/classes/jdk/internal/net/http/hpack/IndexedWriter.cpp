#include <jdk/internal/net/http/hpack/IndexedWriter.h>

#include <java/nio/ByteBuffer.h>
#include <jdk/internal/net/http/hpack/BinaryRepresentationWriter.h>
#include <jdk/internal/net/http/hpack/HeaderTable.h>
#include <jdk/internal/net/http/hpack/IntegerWriter.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $BinaryRepresentationWriter = ::jdk::internal::net::http::hpack::BinaryRepresentationWriter;
using $HeaderTable = ::jdk::internal::net::http::hpack::HeaderTable;
using $IntegerWriter = ::jdk::internal::net::http::hpack::IntegerWriter;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _IndexedWriter_FieldInfo_[] = {
	{"intWriter", "Ljdk/internal/net/http/hpack/IntegerWriter;", nullptr, $PRIVATE | $FINAL, $field(IndexedWriter, intWriter)},
	{}
};

$MethodInfo _IndexedWriter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(IndexedWriter::*)()>(&IndexedWriter::init$))},
	{"index", "(I)Ljdk/internal/net/http/hpack/IndexedWriter;", nullptr, 0, $method(static_cast<IndexedWriter*(IndexedWriter::*)(int32_t)>(&IndexedWriter::index))},
	{"reset", "()Ljdk/internal/net/http/hpack/BinaryRepresentationWriter;", nullptr, $PUBLIC},
	{"write", "(Ljdk/internal/net/http/hpack/HeaderTable;Ljava/nio/ByteBuffer;)Z", nullptr, $PUBLIC},
	{}
};

$ClassInfo _IndexedWriter_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.IndexedWriter",
	"java.lang.Object",
	"jdk.internal.net.http.hpack.BinaryRepresentationWriter",
	_IndexedWriter_FieldInfo_,
	_IndexedWriter_MethodInfo_
};

$Object* allocate$IndexedWriter($Class* clazz) {
	return $of($alloc(IndexedWriter));
}

void IndexedWriter::init$() {
	$set(this, intWriter, $new($IntegerWriter));
}

IndexedWriter* IndexedWriter::index(int32_t index) {
	$nc(this->intWriter)->configure(index, 7, 128);
	return this;
}

bool IndexedWriter::write($HeaderTable* table, $ByteBuffer* destination) {
	return $nc(this->intWriter)->write(destination);
}

$BinaryRepresentationWriter* IndexedWriter::reset() {
	$nc(this->intWriter)->reset();
	return this;
}

IndexedWriter::IndexedWriter() {
}

$Class* IndexedWriter::load$($String* name, bool initialize) {
	$loadClass(IndexedWriter, name, initialize, &_IndexedWriter_ClassInfo_, allocate$IndexedWriter);
	return class$;
}

$Class* IndexedWriter::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk