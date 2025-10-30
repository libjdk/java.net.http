#include <jdk/internal/net/http/Http1Exchange$DataPair.h>

#include <java/util/List.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $List = ::java::util::List;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Http1Exchange$DataPair_FieldInfo_[] = {
	{"throwable", "Ljava/lang/Throwable;", nullptr, 0, $field(Http1Exchange$DataPair, throwable)},
	{"data", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/ByteBuffer;>;", 0, $field(Http1Exchange$DataPair, data)},
	{}
};

$MethodInfo _Http1Exchange$DataPair_MethodInfo_[] = {
	{"<init>", "(Ljava/util/List;Ljava/lang/Throwable;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;Ljava/lang/Throwable;)V", 0, $method(static_cast<void(Http1Exchange$DataPair::*)($List*,$Throwable*)>(&Http1Exchange$DataPair::init$))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Http1Exchange$DataPair_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Exchange$DataPair", "jdk.internal.net.http.Http1Exchange", "DataPair", $STATIC},
	{}
};

$ClassInfo _Http1Exchange$DataPair_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.Http1Exchange$DataPair",
	"java.lang.Object",
	nullptr,
	_Http1Exchange$DataPair_FieldInfo_,
	_Http1Exchange$DataPair_MethodInfo_,
	nullptr,
	nullptr,
	_Http1Exchange$DataPair_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Exchange"
};

$Object* allocate$Http1Exchange$DataPair($Class* clazz) {
	return $of($alloc(Http1Exchange$DataPair));
}

void Http1Exchange$DataPair::init$($List* data, $Throwable* throwable) {
	$set(this, data, data);
	$set(this, throwable, throwable);
}

$String* Http1Exchange$DataPair::toString() {
	return $str({"DataPair [data="_s, this->data, ", throwable="_s, this->throwable, "]"_s});
}

Http1Exchange$DataPair::Http1Exchange$DataPair() {
}

$Class* Http1Exchange$DataPair::load$($String* name, bool initialize) {
	$loadClass(Http1Exchange$DataPair, name, initialize, &_Http1Exchange$DataPair_ClassInfo_, allocate$Http1Exchange$DataPair);
	return class$;
}

$Class* Http1Exchange$DataPair::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk