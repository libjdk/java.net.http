#include <jdk/internal/net/http/common/Utils$ServerName.h>

#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _Utils$ServerName_FieldInfo_[] = {
	{"name", "Ljava/lang/String;", nullptr, $FINAL, $field(Utils$ServerName, name)},
	{"isLiteral", "Z", nullptr, $FINAL, $field(Utils$ServerName, isLiteral$)},
	{}
};

$MethodInfo _Utils$ServerName_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Z)V", nullptr, 0, $method(static_cast<void(Utils$ServerName::*)($String*,bool)>(&Utils$ServerName::init$))},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"isLiteral", "()Z", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Utils$ServerName_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.Utils$ServerName", "jdk.internal.net.http.common.Utils", "ServerName", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _Utils$ServerName_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.common.Utils$ServerName",
	"java.lang.Object",
	nullptr,
	_Utils$ServerName_FieldInfo_,
	_Utils$ServerName_MethodInfo_,
	nullptr,
	nullptr,
	_Utils$ServerName_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.Utils"
};

$Object* allocate$Utils$ServerName($Class* clazz) {
	return $of($alloc(Utils$ServerName));
}

void Utils$ServerName::init$($String* name, bool isLiteral) {
	$set(this, name, name);
	this->isLiteral$ = isLiteral;
}

$String* Utils$ServerName::getName() {
	return this->name;
}

bool Utils$ServerName::isLiteral() {
	return this->isLiteral$;
}

Utils$ServerName::Utils$ServerName() {
}

$Class* Utils$ServerName::load$($String* name, bool initialize) {
	$loadClass(Utils$ServerName, name, initialize, &_Utils$ServerName_ClassInfo_, allocate$Utils$ServerName);
	return class$;
}

$Class* Utils$ServerName::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk