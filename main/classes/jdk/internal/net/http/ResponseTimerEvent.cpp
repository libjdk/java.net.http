#include <jdk/internal/net/http/ResponseTimerEvent.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/ConnectException.h>
#include <java/net/SocketException.h>
#include <java/net/http/HttpConnectTimeoutException.h>
#include <java/net/http/HttpTimeoutException.h>
#include <java/time/Duration.h>
#include <java/time/Instant.h>
#include <java/util/Optional.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/ExchangeImpl.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/TimeoutEvent.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef DEBUG

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ConnectException = ::java::net::ConnectException;
using $SocketException = ::java::net::SocketException;
using $HttpConnectTimeoutException = ::java::net::http::HttpConnectTimeoutException;
using $HttpTimeoutException = ::java::net::http::HttpTimeoutException;
using $Duration = ::java::time::Duration;
using $Instant = ::java::time::Instant;
using $Optional = ::java::util::Optional;
using $Supplier = ::java::util::function::Supplier;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $ExchangeImpl = ::jdk::internal::net::http::ExchangeImpl;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;
using $TimeoutEvent = ::jdk::internal::net::http::TimeoutEvent;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class ResponseTimerEvent$$Lambda$toString : public $Supplier {
	$class(ResponseTimerEvent$$Lambda$toString, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseTimerEvent$$Lambda$toString>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseTimerEvent$$Lambda$toString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ResponseTimerEvent$$Lambda$toString, inst$)},
	{}
};
$MethodInfo ResponseTimerEvent$$Lambda$toString::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseTimerEvent$$Lambda$toString::*)($String*)>(&ResponseTimerEvent$$Lambda$toString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseTimerEvent$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseTimerEvent$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* ResponseTimerEvent$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(ResponseTimerEvent$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseTimerEvent$$Lambda$toString::class$ = nullptr;

$FieldInfo _ResponseTimerEvent_FieldInfo_[] = {
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ResponseTimerEvent, debug)},
	{"multiExchange", "Ljdk/internal/net/http/MultiExchange;", "Ljdk/internal/net/http/MultiExchange<*>;", $PRIVATE | $FINAL, $field(ResponseTimerEvent, multiExchange)},
	{}
};

$MethodInfo _ResponseTimerEvent_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/MultiExchange;)V", "(Ljdk/internal/net/http/MultiExchange<*>;)V", $PRIVATE, $method(static_cast<void(ResponseTimerEvent::*)($MultiExchange*)>(&ResponseTimerEvent::init$))},
	{"compareTo", "(Ljdk/internal/net/http/TimeoutEvent;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"deadline", "()Ljava/time/Instant;", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"handle", "()V", nullptr, $PUBLIC},
	{"of", "(Ljdk/internal/net/http/MultiExchange;)Ljdk/internal/net/http/ResponseTimerEvent;", "(Ljdk/internal/net/http/MultiExchange<*>;)Ljdk/internal/net/http/ResponseTimerEvent;", $STATIC, $method(static_cast<ResponseTimerEvent*(*)($MultiExchange*)>(&ResponseTimerEvent::of))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _ResponseTimerEvent_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.ResponseTimerEvent",
	"jdk.internal.net.http.TimeoutEvent",
	nullptr,
	_ResponseTimerEvent_FieldInfo_,
	_ResponseTimerEvent_MethodInfo_
};

$Object* allocate$ResponseTimerEvent($Class* clazz) {
	return $of($alloc(ResponseTimerEvent));
}

$Logger* ResponseTimerEvent::debug = nullptr;

ResponseTimerEvent* ResponseTimerEvent::of($MultiExchange* exchange) {
	$init(ResponseTimerEvent);
	return $new(ResponseTimerEvent, exchange);
}

void ResponseTimerEvent::init$($MultiExchange* multiExchange) {
	$useLocalCurrentObjectStackCache();
	$TimeoutEvent::init$($cast($Duration, $($nc($($nc($nc($nc(multiExchange)->exchange)->request$)->timeout()))->get())));
	$set(this, multiExchange, multiExchange);
}

void ResponseTimerEvent::handle() {
	$useLocalCurrentObjectStackCache();
	if ($nc(ResponseTimerEvent::debug)->on()) {
		$nc(ResponseTimerEvent::debug)->log("Cancelling MultiExchange due to timeout for request %s"_s, $$new($ObjectArray, {$of($nc($nc(this->multiExchange)->exchange)->request$)}));
	}
	$var($HttpTimeoutException, t, nullptr);
	$var($Exchange, exchange, $nc(this->multiExchange)->getExchange());
	if (exchange != nullptr) {
		$var($ExchangeImpl, exchangeImpl, exchange->exchImpl);
		if (exchangeImpl != nullptr) {
			if ($nc($(exchangeImpl->connection()))->connected()) {
				$assign(t, $new($HttpTimeoutException, "request timed out"_s));
			}
		}
	}
	if (t == nullptr) {
		$assign(t, $new($HttpConnectTimeoutException, "HTTP connect timed out"_s));
		t->initCause($$new($ConnectException, "HTTP connect timed out"_s));
	}
	$nc(this->multiExchange)->cancel(static_cast<$IOException*>(t));
}

$String* ResponseTimerEvent::toString() {
	return $str({"ResponseTimerEvent["_s, $($TimeoutEvent::toString()), "]"_s});
}

int32_t ResponseTimerEvent::compareTo($TimeoutEvent* other) {
	return $TimeoutEvent::compareTo(other);
}

$Instant* ResponseTimerEvent::deadline() {
	return $TimeoutEvent::deadline();
}

void clinit$ResponseTimerEvent($Class* class$) {
	$init($Utils);
	$assignStatic(ResponseTimerEvent::debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(ResponseTimerEvent$$Lambda$toString, static_cast<$String*>("ResponseTimerEvent"_s))), $Utils::DEBUG));
}

ResponseTimerEvent::ResponseTimerEvent() {
}

$Class* ResponseTimerEvent::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ResponseTimerEvent$$Lambda$toString::classInfo$.name)) {
			return ResponseTimerEvent$$Lambda$toString::load$(name, initialize);
		}
	}
	$loadClass(ResponseTimerEvent, name, initialize, &_ResponseTimerEvent_ClassInfo_, clinit$ResponseTimerEvent, allocate$ResponseTimerEvent);
	return class$;
}

$Class* ResponseTimerEvent::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk