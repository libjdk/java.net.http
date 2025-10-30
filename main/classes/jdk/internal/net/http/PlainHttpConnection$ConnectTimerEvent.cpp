#include <jdk/internal/net/http/PlainHttpConnection$ConnectTimerEvent.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/ConnectException.h>
#include <java/net/SocketException.h>
#include <java/time/Duration.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/HttpClientImpl$DelegatingExecutor.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/PlainHttpConnection.h>
#include <jdk/internal/net/http/TimeoutEvent.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ConnectException = ::java::net::ConnectException;
using $SocketException = ::java::net::SocketException;
using $Duration = ::java::time::Duration;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpClientImpl$DelegatingExecutor = ::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;
using $PlainHttpConnection = ::jdk::internal::net::http::PlainHttpConnection;
using $TimeoutEvent = ::jdk::internal::net::http::TimeoutEvent;
using $Logger = ::jdk::internal::net::http::common::Logger;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0 : public $Runnable {
	$class(PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0, $NO_CLASS_INIT, $Runnable)
public:
	void init$(PlainHttpConnection$ConnectTimerEvent* inst, $ConnectException* ce) {
		$set(this, inst$, inst);
		$set(this, ce, ce);
	}
	virtual void run() override {
		$nc(inst$)->lambda$handle$0(ce);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0>());
	}
	PlainHttpConnection$ConnectTimerEvent* inst$ = nullptr;
	$ConnectException* ce = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0, inst$)},
	{"ce", "Ljava/net/ConnectException;", nullptr, $PUBLIC, $field(PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0, ce)},
	{}
};
$MethodInfo PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/PlainHttpConnection$ConnectTimerEvent;Ljava/net/ConnectException;)V", nullptr, $PUBLIC, $method(static_cast<void(PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0::*)(PlainHttpConnection$ConnectTimerEvent*,$ConnectException*)>(&PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0::load$($String* name, bool initialize) {
	$loadClass(PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0::class$ = nullptr;

$FieldInfo _PlainHttpConnection$ConnectTimerEvent_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/PlainHttpConnection;", nullptr, $FINAL | $SYNTHETIC, $field(PlainHttpConnection$ConnectTimerEvent, this$0)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<*>;", $PRIVATE | $FINAL, $field(PlainHttpConnection$ConnectTimerEvent, cf)},
	{"exchange", "Ljdk/internal/net/http/Exchange;", "Ljdk/internal/net/http/Exchange<*>;", $PRIVATE | $FINAL, $field(PlainHttpConnection$ConnectTimerEvent, exchange)},
	{}
};

$MethodInfo _PlainHttpConnection$ConnectTimerEvent_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/PlainHttpConnection;Ljava/time/Duration;Ljdk/internal/net/http/Exchange;Ljava/util/concurrent/CompletableFuture;)V", "(Ljava/time/Duration;Ljdk/internal/net/http/Exchange<*>;Ljava/util/concurrent/CompletableFuture<*>;)V", 0, $method(static_cast<void(PlainHttpConnection$ConnectTimerEvent::*)($PlainHttpConnection*,$Duration*,$Exchange*,$CompletableFuture*)>(&PlainHttpConnection$ConnectTimerEvent::init$))},
	{"handle", "()V", nullptr, $PUBLIC},
	{"lambda$handle$0", "(Ljava/net/ConnectException;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(PlainHttpConnection$ConnectTimerEvent::*)($ConnectException*)>(&PlainHttpConnection$ConnectTimerEvent::lambda$handle$0))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _PlainHttpConnection$ConnectTimerEvent_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.PlainHttpConnection$ConnectTimerEvent", "jdk.internal.net.http.PlainHttpConnection", "ConnectTimerEvent", $FINAL},
	{}
};

$ClassInfo _PlainHttpConnection$ConnectTimerEvent_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.PlainHttpConnection$ConnectTimerEvent",
	"jdk.internal.net.http.TimeoutEvent",
	nullptr,
	_PlainHttpConnection$ConnectTimerEvent_FieldInfo_,
	_PlainHttpConnection$ConnectTimerEvent_MethodInfo_,
	nullptr,
	nullptr,
	_PlainHttpConnection$ConnectTimerEvent_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.PlainHttpConnection"
};

$Object* allocate$PlainHttpConnection$ConnectTimerEvent($Class* clazz) {
	return $of($alloc(PlainHttpConnection$ConnectTimerEvent));
}

void PlainHttpConnection$ConnectTimerEvent::init$($PlainHttpConnection* this$0, $Duration* duration, $Exchange* exchange, $CompletableFuture* cf) {
	$set(this, this$0, this$0);
	$TimeoutEvent::init$(duration);
	$set(this, exchange, exchange);
	$set(this, cf, cf);
}

void PlainHttpConnection$ConnectTimerEvent::handle() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("HTTP connect timed out"_s);
	}
	$var($ConnectException, ce, $new($ConnectException, "HTTP connect timed out"_s));
	$nc($nc(this->exchange)->multi)->cancel(static_cast<$IOException*>(ce));
	$nc($($nc($(this->this$0->client()))->theExecutor()))->execute(static_cast<$Runnable*>($$new(PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0, this, ce)));
}

$String* PlainHttpConnection$ConnectTimerEvent::toString() {
	return $str({"ConnectTimerEvent, "_s, $($TimeoutEvent::toString())});
}

void PlainHttpConnection$ConnectTimerEvent::lambda$handle$0($ConnectException* ce) {
	$nc(this->cf)->completeExceptionally(ce);
}

PlainHttpConnection$ConnectTimerEvent::PlainHttpConnection$ConnectTimerEvent() {
}

$Class* PlainHttpConnection$ConnectTimerEvent::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0::classInfo$.name)) {
			return PlainHttpConnection$ConnectTimerEvent$$Lambda$lambda$handle$0::load$(name, initialize);
		}
	}
	$loadClass(PlainHttpConnection$ConnectTimerEvent, name, initialize, &_PlainHttpConnection$ConnectTimerEvent_ClassInfo_, allocate$PlainHttpConnection$ConnectTimerEvent);
	return class$;
}

$Class* PlainHttpConnection$ConnectTimerEvent::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk