#include <jdk/internal/net/http/Exchange$ConnectionAborter.h>

#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Exchange$ConnectionAborter_FieldInfo_[] = {
	{"connection", "Ljdk/internal/net/http/HttpConnection;", nullptr, $PRIVATE | $VOLATILE, $field(Exchange$ConnectionAborter, connection$)},
	{"closeRequested", "Z", nullptr, $PRIVATE | $VOLATILE, $field(Exchange$ConnectionAborter, closeRequested)},
	{}
};

$MethodInfo _Exchange$ConnectionAborter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(Exchange$ConnectionAborter::*)()>(&Exchange$ConnectionAborter::init$))},
	{"closeConnection", "()V", nullptr, 0, $method(static_cast<void(Exchange$ConnectionAborter::*)()>(&Exchange$ConnectionAborter::closeConnection))},
	{"connection", "(Ljdk/internal/net/http/HttpConnection;)V", nullptr, 0, $method(static_cast<void(Exchange$ConnectionAborter::*)($HttpConnection*)>(&Exchange$ConnectionAborter::connection))},
	{"disable", "()V", nullptr, 0, $method(static_cast<void(Exchange$ConnectionAborter::*)()>(&Exchange$ConnectionAborter::disable))},
	{}
};

$InnerClassInfo _Exchange$ConnectionAborter_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Exchange$ConnectionAborter", "jdk.internal.net.http.Exchange", "ConnectionAborter", $STATIC | $FINAL},
	{}
};

$ClassInfo _Exchange$ConnectionAborter_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Exchange$ConnectionAborter",
	"java.lang.Object",
	nullptr,
	_Exchange$ConnectionAborter_FieldInfo_,
	_Exchange$ConnectionAborter_MethodInfo_,
	nullptr,
	nullptr,
	_Exchange$ConnectionAborter_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Exchange"
};

$Object* allocate$Exchange$ConnectionAborter($Class* clazz) {
	return $of($alloc(Exchange$ConnectionAborter));
}

void Exchange$ConnectionAborter::init$() {
}

void Exchange$ConnectionAborter::connection($HttpConnection* connection) {
	$set(this, connection$, connection);
	if (this->closeRequested) {
		closeConnection();
	}
}

void Exchange$ConnectionAborter::closeConnection() {
	this->closeRequested = true;
	$var($HttpConnection, connection, this->connection$);
	$set(this, connection$, nullptr);
	if (connection != nullptr) {
		try {
			connection->close();
		} catch ($Throwable& t) {
		}
	}
}

void Exchange$ConnectionAborter::disable() {
	$set(this, connection$, nullptr);
	this->closeRequested = false;
}

Exchange$ConnectionAborter::Exchange$ConnectionAborter() {
}

$Class* Exchange$ConnectionAborter::load$($String* name, bool initialize) {
	$loadClass(Exchange$ConnectionAborter, name, initialize, &_Exchange$ConnectionAborter_ClassInfo_, allocate$Exchange$ConnectionAborter);
	return class$;
}

$Class* Exchange$ConnectionAborter::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk