#include <jdk/internal/net/http/HttpResponseImpl$RawChannelProvider.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/ExchangeImpl.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/HttpResponseImpl.h>
#include <jdk/internal/net/http/RawChannelTube.h>
#include <jdk/internal/net/http/Response.h>
#include <jdk/internal/net/http/websocket/RawChannel.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Supplier = ::java::util::function::Supplier;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $ExchangeImpl = ::jdk::internal::net::http::ExchangeImpl;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $HttpResponseImpl = ::jdk::internal::net::http::HttpResponseImpl;
using $RawChannelTube = ::jdk::internal::net::http::RawChannelTube;
using $Response = ::jdk::internal::net::http::Response;
using $RawChannel = ::jdk::internal::net::http::websocket::RawChannel;
using $RawChannel$Provider = ::jdk::internal::net::http::websocket::RawChannel$Provider;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes : public $Supplier {
	$class(HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Http1Exchange* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->drainLeftOverBytes());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes>());
	}
	$Http1Exchange* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes, inst$)},
	{}
};
$MethodInfo HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Exchange;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes::*)($Http1Exchange*)>(&HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes::load$($String* name, bool initialize) {
	$loadClass(HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes::class$ = nullptr;

$FieldInfo _HttpResponseImpl$RawChannelProvider_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HttpResponseImpl$RawChannelProvider, $assertionsDisabled)},
	{"connection", "Ljdk/internal/net/http/HttpConnection;", nullptr, $PRIVATE | $FINAL, $field(HttpResponseImpl$RawChannelProvider, connection$)},
	{"exchange", "Ljdk/internal/net/http/Exchange;", "Ljdk/internal/net/http/Exchange<*>;", $PRIVATE | $FINAL, $field(HttpResponseImpl$RawChannelProvider, exchange)},
	{"rawchan", "Ljdk/internal/net/http/websocket/RawChannel;", nullptr, $PRIVATE, $field(HttpResponseImpl$RawChannelProvider, rawchan)},
	{}
};

$MethodInfo _HttpResponseImpl$RawChannelProvider_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpConnection;Ljdk/internal/net/http/Exchange;)V", "(Ljdk/internal/net/http/HttpConnection;Ljdk/internal/net/http/Exchange<*>;)V", 0, $method(static_cast<void(HttpResponseImpl$RawChannelProvider::*)($HttpConnection*,$Exchange*)>(&HttpResponseImpl$RawChannelProvider::init$))},
	{"closeRawChannel", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{"connection", "(Ljdk/internal/net/http/Response;Ljdk/internal/net/http/Exchange;)Ljdk/internal/net/http/HttpConnection;", "(Ljdk/internal/net/http/Response;Ljdk/internal/net/http/Exchange<*>;)Ljdk/internal/net/http/HttpConnection;", $PRIVATE | $STATIC, $method(static_cast<$HttpConnection*(*)($Response*,$Exchange*)>(&HttpResponseImpl$RawChannelProvider::connection))},
	{"create", "(Ljdk/internal/net/http/Response;Ljdk/internal/net/http/Exchange;)Ljdk/internal/net/http/HttpResponseImpl$RawChannelProvider;", "(Ljdk/internal/net/http/Response;Ljdk/internal/net/http/Exchange<*>;)Ljdk/internal/net/http/HttpResponseImpl$RawChannelProvider;", $STATIC, $method(static_cast<HttpResponseImpl$RawChannelProvider*(*)($Response*,$Exchange*)>(&HttpResponseImpl$RawChannelProvider::create))},
	{"exchangeImpl", "()Ljdk/internal/net/http/ExchangeImpl;", "()Ljdk/internal/net/http/ExchangeImpl<*>;", $PRIVATE, $method(static_cast<$ExchangeImpl*(HttpResponseImpl$RawChannelProvider::*)()>(&HttpResponseImpl$RawChannelProvider::exchangeImpl))},
	{"rawChannel", "()Ljdk/internal/net/http/websocket/RawChannel;", nullptr, $PUBLIC | $SYNCHRONIZED},
	{}
};

$InnerClassInfo _HttpResponseImpl$RawChannelProvider_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.HttpResponseImpl$RawChannelProvider", "jdk.internal.net.http.HttpResponseImpl", "RawChannelProvider", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.net.http.websocket.RawChannel$Provider", "jdk.internal.net.http.websocket.RawChannel", "Provider", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpResponseImpl$RawChannelProvider_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.HttpResponseImpl$RawChannelProvider",
	"java.lang.Object",
	"jdk.internal.net.http.websocket.RawChannel$Provider",
	_HttpResponseImpl$RawChannelProvider_FieldInfo_,
	_HttpResponseImpl$RawChannelProvider_MethodInfo_,
	nullptr,
	nullptr,
	_HttpResponseImpl$RawChannelProvider_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HttpResponseImpl"
};

$Object* allocate$HttpResponseImpl$RawChannelProvider($Class* clazz) {
	return $of($alloc(HttpResponseImpl$RawChannelProvider));
}

bool HttpResponseImpl$RawChannelProvider::$assertionsDisabled = false;

void HttpResponseImpl$RawChannelProvider::init$($HttpConnection* conn, $Exchange* exch) {
	$set(this, connection$, conn);
	$set(this, exchange, exch);
}

HttpResponseImpl$RawChannelProvider* HttpResponseImpl$RawChannelProvider::create($Response* resp, $Exchange* exch) {
	$init(HttpResponseImpl$RawChannelProvider);
	$useLocalCurrentObjectStackCache();
	if ($nc($($nc(resp)->request()))->isWebSocket()) {
		return $new(HttpResponseImpl$RawChannelProvider, $(connection(resp, exch)), exch);
	}
	return nullptr;
}

$RawChannel* HttpResponseImpl$RawChannelProvider::rawChannel() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->rawchan == nullptr) {
			$var($ExchangeImpl, exchImpl, exchangeImpl());
			if (!($instanceOf($Http1Exchange, exchImpl))) {
				$throwNew($UnsupportedOperationException, "RawChannel is not supported over HTTP/2"_s);
			}
			$var($Supplier, initial, static_cast<$Supplier*>($new(HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes, static_cast<$Http1Exchange*>($nc(($cast($Http1Exchange, exchImpl)))))));
			$set(this, rawchan, $new($RawChannelTube, this->connection$, initial));
		}
		return this->rawchan;
	}
}

void HttpResponseImpl$RawChannelProvider::closeRawChannel() {
	$synchronized(this) {
		if (this->rawchan != nullptr) {
			$nc(this->rawchan)->close();
		} else {
			$nc(this->connection$)->close();
		}
	}
}

$HttpConnection* HttpResponseImpl$RawChannelProvider::connection($Response* resp, $Exchange* exch) {
	$init(HttpResponseImpl$RawChannelProvider);
	if (exch == nullptr || $nc(exch)->exchImpl == nullptr) {
		if (!HttpResponseImpl$RawChannelProvider::$assertionsDisabled && !($nc(resp)->statusCode$ == 407)) {
			$throwNew($AssertionError);
		}
		return nullptr;
	}
	return $nc($nc(exch)->exchImpl)->connection();
}

$ExchangeImpl* HttpResponseImpl$RawChannelProvider::exchangeImpl() {
	return this->exchange != nullptr ? $cast($ExchangeImpl, $nc(this->exchange)->exchImpl) : ($ExchangeImpl*)nullptr;
}

void clinit$HttpResponseImpl$RawChannelProvider($Class* class$) {
	$load($HttpResponseImpl);
	HttpResponseImpl$RawChannelProvider::$assertionsDisabled = !$HttpResponseImpl::class$->desiredAssertionStatus();
}

HttpResponseImpl$RawChannelProvider::HttpResponseImpl$RawChannelProvider() {
}

$Class* HttpResponseImpl$RawChannelProvider::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes::classInfo$.name)) {
			return HttpResponseImpl$RawChannelProvider$$Lambda$drainLeftOverBytes::load$(name, initialize);
		}
	}
	$loadClass(HttpResponseImpl$RawChannelProvider, name, initialize, &_HttpResponseImpl$RawChannelProvider_ClassInfo_, clinit$HttpResponseImpl$RawChannelProvider, allocate$HttpResponseImpl$RawChannelProvider);
	return class$;
}

$Class* HttpResponseImpl$RawChannelProvider::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk