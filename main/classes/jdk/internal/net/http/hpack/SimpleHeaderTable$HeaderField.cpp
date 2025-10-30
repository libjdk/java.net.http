#include <jdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField.h>

#include <jdk/internal/net/http/hpack/SimpleHeaderTable.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SimpleHeaderTable = ::jdk::internal::net::http::hpack::SimpleHeaderTable;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _SimpleHeaderTable$HeaderField_FieldInfo_[] = {
	{"name", "Ljava/lang/String;", nullptr, $FINAL, $field(SimpleHeaderTable$HeaderField, name)},
	{"value", "Ljava/lang/String;", nullptr, $FINAL, $field(SimpleHeaderTable$HeaderField, value)},
	{}
};

$MethodInfo _SimpleHeaderTable$HeaderField_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(SimpleHeaderTable$HeaderField::*)($String*)>(&SimpleHeaderTable$HeaderField::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(SimpleHeaderTable$HeaderField::*)($String*,$String*)>(&SimpleHeaderTable$HeaderField::init$))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SimpleHeaderTable$HeaderField_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.SimpleHeaderTable$HeaderField", "jdk.internal.net.http.hpack.SimpleHeaderTable", "HeaderField", $PROTECTED | $STATIC | $FINAL},
	{}
};

$ClassInfo _SimpleHeaderTable$HeaderField_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.SimpleHeaderTable$HeaderField",
	"java.lang.Object",
	nullptr,
	_SimpleHeaderTable$HeaderField_FieldInfo_,
	_SimpleHeaderTable$HeaderField_MethodInfo_,
	nullptr,
	nullptr,
	_SimpleHeaderTable$HeaderField_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.SimpleHeaderTable"
};

$Object* allocate$SimpleHeaderTable$HeaderField($Class* clazz) {
	return $of($alloc(SimpleHeaderTable$HeaderField));
}

void SimpleHeaderTable$HeaderField::init$($String* name) {
	SimpleHeaderTable$HeaderField::init$(name, ""_s);
}

void SimpleHeaderTable$HeaderField::init$($String* name, $String* value) {
	$set(this, name, name);
	$set(this, value, value);
}

$String* SimpleHeaderTable$HeaderField::toString() {
	return $nc(this->value)->isEmpty() ? this->name : $str({this->name, ": "_s, this->value});
}

SimpleHeaderTable$HeaderField::SimpleHeaderTable$HeaderField() {
}

$Class* SimpleHeaderTable$HeaderField::load$($String* name, bool initialize) {
	$loadClass(SimpleHeaderTable$HeaderField, name, initialize, &_SimpleHeaderTable$HeaderField_ClassInfo_, allocate$SimpleHeaderTable$HeaderField);
	return class$;
}

$Class* SimpleHeaderTable$HeaderField::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk