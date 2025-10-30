#include <jdk/internal/net/http/common/Pair.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _Pair_FieldInfo_[] = {
	{"first", "Ljava/lang/Object;", "TT;", $PUBLIC | $FINAL, $field(Pair, first)},
	{"second", "Ljava/lang/Object;", "TU;", $PUBLIC | $FINAL, $field(Pair, second)},
	{}
};

$MethodInfo _Pair_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Object;Ljava/lang/Object;)V", "(TT;TU;)V", $PUBLIC, $method(static_cast<void(Pair::*)(Object$*,Object$*)>(&Pair::init$))},
	{"pair", "(Ljava/lang/Object;Ljava/lang/Object;)Ljdk/internal/net/http/common/Pair;", "<T:Ljava/lang/Object;U:Ljava/lang/Object;>(TT;TU;)Ljdk/internal/net/http/common/Pair<TT;TU;>;", $PUBLIC | $STATIC, $method(static_cast<Pair*(*)(Object$*,Object$*)>(&Pair::pair))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _Pair_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.Pair",
	"java.lang.Object",
	nullptr,
	_Pair_FieldInfo_,
	_Pair_MethodInfo_,
	"<T:Ljava/lang/Object;U:Ljava/lang/Object;>Ljava/lang/Object;"
};

$Object* allocate$Pair($Class* clazz) {
	return $of($alloc(Pair));
}

void Pair::init$(Object$* first, Object$* second) {
	$set(this, second, second);
	$set(this, first, first);
}

Pair* Pair::pair(Object$* first, Object$* second) {
	return $new(Pair, first, second);
}

$String* Pair::toString() {
	return $str({"("_s, this->first, ", "_s, this->second, ")"_s});
}

Pair::Pair() {
}

$Class* Pair::load$($String* name, bool initialize) {
	$loadClass(Pair, name, initialize, &_Pair_ClassInfo_, allocate$Pair);
	return class$;
}

$Class* Pair::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk