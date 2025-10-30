#include <jdk/internal/net/http/hpack/BulkSizeUpdateWriter.h>

#include <java/lang/IllegalStateException.h>
#include <java/lang/Iterable.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Iterator.h>
#include <java/util/Objects.h>
#include <jdk/internal/net/http/hpack/BinaryRepresentationWriter.h>
#include <jdk/internal/net/http/hpack/HeaderTable.h>
#include <jdk/internal/net/http/hpack/SizeUpdateWriter.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $Integer = ::java::lang::Integer;
using $Iterable = ::java::lang::Iterable;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Iterator = ::java::util::Iterator;
using $Objects = ::java::util::Objects;
using $BinaryRepresentationWriter = ::jdk::internal::net::http::hpack::BinaryRepresentationWriter;
using $HeaderTable = ::jdk::internal::net::http::hpack::HeaderTable;
using $SizeUpdateWriter = ::jdk::internal::net::http::hpack::SizeUpdateWriter;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _BulkSizeUpdateWriter_FieldInfo_[] = {
	{"writer", "Ljdk/internal/net/http/hpack/SizeUpdateWriter;", nullptr, $PRIVATE | $FINAL, $field(BulkSizeUpdateWriter, writer)},
	{"maxSizes", "Ljava/util/Iterator;", "Ljava/util/Iterator<Ljava/lang/Integer;>;", $PRIVATE, $field(BulkSizeUpdateWriter, maxSizes)},
	{"writing", "Z", nullptr, $PRIVATE, $field(BulkSizeUpdateWriter, writing)},
	{"configured", "Z", nullptr, $PRIVATE, $field(BulkSizeUpdateWriter, configured)},
	{}
};

$MethodInfo _BulkSizeUpdateWriter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(BulkSizeUpdateWriter::*)()>(&BulkSizeUpdateWriter::init$))},
	{"maxHeaderTableSizes", "(Ljava/lang/Iterable;)Ljdk/internal/net/http/hpack/BulkSizeUpdateWriter;", "(Ljava/lang/Iterable<Ljava/lang/Integer;>;)Ljdk/internal/net/http/hpack/BulkSizeUpdateWriter;", 0, $method(static_cast<BulkSizeUpdateWriter*(BulkSizeUpdateWriter::*)($Iterable*)>(&BulkSizeUpdateWriter::maxHeaderTableSizes))},
	{"reset", "()Ljdk/internal/net/http/hpack/BulkSizeUpdateWriter;", nullptr, $PUBLIC},
	{"write", "(Ljdk/internal/net/http/hpack/HeaderTable;Ljava/nio/ByteBuffer;)Z", nullptr, $PUBLIC},
	{}
};

$ClassInfo _BulkSizeUpdateWriter_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.BulkSizeUpdateWriter",
	"java.lang.Object",
	"jdk.internal.net.http.hpack.BinaryRepresentationWriter",
	_BulkSizeUpdateWriter_FieldInfo_,
	_BulkSizeUpdateWriter_MethodInfo_
};

$Object* allocate$BulkSizeUpdateWriter($Class* clazz) {
	return $of($alloc(BulkSizeUpdateWriter));
}

void BulkSizeUpdateWriter::init$() {
	$set(this, writer, $new($SizeUpdateWriter));
}

BulkSizeUpdateWriter* BulkSizeUpdateWriter::maxHeaderTableSizes($Iterable* sizes) {
	if (this->configured) {
		$throwNew($IllegalStateException, "Already configured"_s);
	}
	$Objects::requireNonNull($of(sizes), "sizes"_s);
	$set(this, maxSizes, $nc(sizes)->iterator());
	this->configured = true;
	return this;
}

bool BulkSizeUpdateWriter::write($HeaderTable* table, $ByteBuffer* destination) {
	$useLocalCurrentObjectStackCache();
	if (!this->configured) {
		$throwNew($IllegalStateException, "Configure first"_s);
	}
	while (true) {
		if (this->writing) {
			if (!$nc(this->writer)->write(table, destination)) {
				return false;
			}
			this->writing = false;
		} else if ($nc(this->maxSizes)->hasNext()) {
			this->writing = true;
			$nc(this->writer)->reset();
			$nc(this->writer)->maxHeaderTableSize($nc(($cast($Integer, $($nc(this->maxSizes)->next()))))->intValue());
		} else {
			this->configured = false;
			return true;
		}
	}
}

BulkSizeUpdateWriter* BulkSizeUpdateWriter::reset() {
	$set(this, maxSizes, nullptr);
	this->writing = false;
	this->configured = false;
	return this;
}

BulkSizeUpdateWriter::BulkSizeUpdateWriter() {
}

$Class* BulkSizeUpdateWriter::load$($String* name, bool initialize) {
	$loadClass(BulkSizeUpdateWriter, name, initialize, &_BulkSizeUpdateWriter_ClassInfo_, allocate$BulkSizeUpdateWriter);
	return class$;
}

$Class* BulkSizeUpdateWriter::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk