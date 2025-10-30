#include <jdk/internal/net/http/hpack/LiteralWriter.h>

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

$MethodInfo _LiteralWriter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(LiteralWriter::*)()>(&LiteralWriter::init$))},
	{}
};

$ClassInfo _LiteralWriter_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.LiteralWriter",
	"jdk.internal.net.http.hpack.IndexNameValueWriter",
	nullptr,
	nullptr,
	_LiteralWriter_MethodInfo_
};

$Object* allocate$LiteralWriter($Class* clazz) {
	return $of($alloc(LiteralWriter));
}

void LiteralWriter::init$() {
	$IndexNameValueWriter::init$(0, 4);
}

LiteralWriter::LiteralWriter() {
}

$Class* LiteralWriter::load$($String* name, bool initialize) {
	$loadClass(LiteralWriter, name, initialize, &_LiteralWriter_ClassInfo_, allocate$LiteralWriter);
	return class$;
}

$Class* LiteralWriter::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk