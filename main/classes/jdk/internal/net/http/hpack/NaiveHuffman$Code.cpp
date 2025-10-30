#include <jdk/internal/net/http/hpack/NaiveHuffman$Code.h>

#include <jdk/internal/net/http/hpack/NaiveHuffman.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NaiveHuffman = ::jdk::internal::net::http::hpack::NaiveHuffman;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _NaiveHuffman$Code_FieldInfo_[] = {
	{"code", "I", nullptr, $FINAL, $field(NaiveHuffman$Code, code)},
	{"length", "I", nullptr, $FINAL, $field(NaiveHuffman$Code, length)},
	{}
};

$MethodInfo _NaiveHuffman$Code_MethodInfo_[] = {
	{"<init>", "(II)V", nullptr, $PRIVATE, $method(static_cast<void(NaiveHuffman$Code::*)(int32_t,int32_t)>(&NaiveHuffman$Code::init$))},
	{"getCode", "()I", nullptr, $PUBLIC, $method(static_cast<int32_t(NaiveHuffman$Code::*)()>(&NaiveHuffman$Code::getCode))},
	{"getLength", "()I", nullptr, $PUBLIC, $method(static_cast<int32_t(NaiveHuffman$Code::*)()>(&NaiveHuffman$Code::getLength))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _NaiveHuffman$Code_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.NaiveHuffman$Code", "jdk.internal.net.http.hpack.NaiveHuffman", "Code", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _NaiveHuffman$Code_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.NaiveHuffman$Code",
	"java.lang.Object",
	nullptr,
	_NaiveHuffman$Code_FieldInfo_,
	_NaiveHuffman$Code_MethodInfo_,
	nullptr,
	nullptr,
	_NaiveHuffman$Code_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.NaiveHuffman"
};

$Object* allocate$NaiveHuffman$Code($Class* clazz) {
	return $of($alloc(NaiveHuffman$Code));
}

void NaiveHuffman$Code::init$(int32_t code, int32_t length) {
	this->code = code;
	this->length = length;
}

int32_t NaiveHuffman$Code::getCode() {
	return this->code;
}

int32_t NaiveHuffman$Code::getLength() {
	return this->length;
}

$String* NaiveHuffman$Code::toString() {
	$useLocalCurrentObjectStackCache();
	int64_t p = $sl(1, this->length);
	return $str({$($nc($($Long::toBinaryString(this->code + p)))->substring(1)), ", length="_s, $$str(this->length)});
}

NaiveHuffman$Code::NaiveHuffman$Code() {
}

$Class* NaiveHuffman$Code::load$($String* name, bool initialize) {
	$loadClass(NaiveHuffman$Code, name, initialize, &_NaiveHuffman$Code_ClassInfo_, allocate$NaiveHuffman$Code);
	return class$;
}

$Class* NaiveHuffman$Code::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk