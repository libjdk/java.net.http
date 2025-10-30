#include <jdk/internal/net/http/hpack/LiteralNeverIndexedWriter.h>

#include <jdk/internal/net/http/hpack/IndexNameValueWriter.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $IndexNameValueWriter = ::jdk::internal::net::http::hpack::IndexNameValueWriter;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$MethodInfo _LiteralNeverIndexedWriter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(LiteralNeverIndexedWriter::*)()>(&LiteralNeverIndexedWriter::init$))},
	{}
};

$ClassInfo _LiteralNeverIndexedWriter_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.LiteralNeverIndexedWriter",
	"jdk.internal.net.http.hpack.IndexNameValueWriter",
	nullptr,
	nullptr,
	_LiteralNeverIndexedWriter_MethodInfo_
};

$Object* allocate$LiteralNeverIndexedWriter($Class* clazz) {
	return $of($alloc(LiteralNeverIndexedWriter));
}

void LiteralNeverIndexedWriter::init$() {
	$IndexNameValueWriter::init$(16, 4);
}

LiteralNeverIndexedWriter::LiteralNeverIndexedWriter() {
}

$Class* LiteralNeverIndexedWriter::load$($String* name, bool initialize) {
	$loadClass(LiteralNeverIndexedWriter, name, initialize, &_LiteralNeverIndexedWriter_ClassInfo_, allocate$LiteralNeverIndexedWriter);
	return class$;
}

$Class* LiteralNeverIndexedWriter::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk