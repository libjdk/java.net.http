#include <jdk/internal/net/http/AsyncSSLTunnelConnection.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/InetSocketAddress.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/SocketChannel.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <javax/net/ssl/SSLEngine.h>
#include <jdk/internal/net/http/AbstractAsyncSSLConnection.h>
#include <jdk/internal/net/http/ConnectionPool$CacheKey.h>
#include <jdk/internal/net/http/ConnectionPool.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/HttpClientImpl$DelegatingExecutor.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpConnection$HttpPublisher.h>
#include <jdk/internal/net/http/HttpConnection$PlainHttpPublisher.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/PlainTunnelingConnection.h>
#include <jdk/internal/net/http/common/BufferSupplier.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/SSLTube.h>
#include <jdk/internal/net/http/common/Utils$ProxyHeaders.h>
#include <jdk/internal/net/http/common/Utils$ServerName.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $Executor = ::java::util::concurrent::Executor;
using $BiFunction = ::java::util::function::BiFunction;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $AbstractAsyncSSLConnection = ::jdk::internal::net::http::AbstractAsyncSSLConnection;
using $ConnectionPool = ::jdk::internal::net::http::ConnectionPool;
using $ConnectionPool$CacheKey = ::jdk::internal::net::http::ConnectionPool$CacheKey;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpClientImpl$DelegatingExecutor = ::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpConnection$HttpPublisher = ::jdk::internal::net::http::HttpConnection$HttpPublisher;
using $HttpConnection$PlainHttpPublisher = ::jdk::internal::net::http::HttpConnection$PlainHttpPublisher;
using $PlainTunnelingConnection = ::jdk::internal::net::http::PlainTunnelingConnection;
using $BufferSupplier = ::jdk::internal::net::http::common::BufferSupplier;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $SSLTube = ::jdk::internal::net::http::common::SSLTube;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $Utils$ProxyHeaders = ::jdk::internal::net::http::common::Utils$ProxyHeaders;
using $Utils$ServerName = ::jdk::internal::net::http::common::Utils$ServerName;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0 : public $Function {
	$class(AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0, $NO_CLASS_INIT, $Function)
public:
	void init$(AsyncSSLTunnelConnection* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* unused) override {
		 return $of($nc(inst$)->lambda$connectAsync$0($cast($Void, unused)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0>());
	}
	AsyncSSLTunnelConnection* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0, inst$)},
	{}
};
$MethodInfo AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/AsyncSSLTunnelConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0::*)(AsyncSSLTunnelConnection*)>(&AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0::load$($String* name, bool initialize) {
	$loadClass(AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0::class$ = nullptr;

class AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1 : public $BiFunction {
	$class(AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(AsyncSSLTunnelConnection* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* unused, Object$* ex) override {
		 return $of($nc(inst$)->lambda$finishConnect$1($cast($String, unused), $cast($Throwable, ex)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1>());
	}
	AsyncSSLTunnelConnection* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1, inst$)},
	{}
};
$MethodInfo AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/AsyncSSLTunnelConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1::*)(AsyncSSLTunnelConnection*)>(&AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1::init$))},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1::load$($String* name, bool initialize) {
	$loadClass(AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1::class$ = nullptr;

class AsyncSSLTunnelConnection$$Lambda$recycle$2 : public $Consumer {
	$class(AsyncSSLTunnelConnection$$Lambda$recycle$2, $NO_CLASS_INIT, $Consumer)
public:
	void init$($BufferSupplier* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* buffer) override {
		$nc(inst$)->recycle($cast($ByteBuffer, buffer));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AsyncSSLTunnelConnection$$Lambda$recycle$2>());
	}
	$BufferSupplier* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo AsyncSSLTunnelConnection$$Lambda$recycle$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(AsyncSSLTunnelConnection$$Lambda$recycle$2, inst$)},
	{}
};
$MethodInfo AsyncSSLTunnelConnection$$Lambda$recycle$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/common/BufferSupplier;)V", nullptr, $PUBLIC, $method(static_cast<void(AsyncSSLTunnelConnection$$Lambda$recycle$2::*)($BufferSupplier*)>(&AsyncSSLTunnelConnection$$Lambda$recycle$2::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo AsyncSSLTunnelConnection$$Lambda$recycle$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.AsyncSSLTunnelConnection$$Lambda$recycle$2",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* AsyncSSLTunnelConnection$$Lambda$recycle$2::load$($String* name, bool initialize) {
	$loadClass(AsyncSSLTunnelConnection$$Lambda$recycle$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AsyncSSLTunnelConnection$$Lambda$recycle$2::class$ = nullptr;

$FieldInfo _AsyncSSLTunnelConnection_FieldInfo_[] = {
	{"plainConnection", "Ljdk/internal/net/http/PlainTunnelingConnection;", nullptr, $FINAL, $field(AsyncSSLTunnelConnection, plainConnection)},
	{"writePublisher", "Ljdk/internal/net/http/HttpConnection$PlainHttpPublisher;", nullptr, $FINAL, $field(AsyncSSLTunnelConnection, writePublisher)},
	{"flow", "Ljdk/internal/net/http/common/SSLTube;", nullptr, $VOLATILE, $field(AsyncSSLTunnelConnection, flow)},
	{}
};

$MethodInfo _AsyncSSLTunnelConnection_MethodInfo_[] = {
	{"<init>", "(Ljava/net/InetSocketAddress;Ljdk/internal/net/http/HttpClientImpl;[Ljava/lang/String;Ljava/net/InetSocketAddress;Ljdk/internal/net/http/common/Utils$ProxyHeaders;)V", nullptr, 0, $method(static_cast<void(AsyncSSLTunnelConnection::*)($InetSocketAddress*,$HttpClientImpl*,$StringArray*,$InetSocketAddress*,$Utils$ProxyHeaders*)>(&AsyncSSLTunnelConnection::init$))},
	{"cacheKey", "()Ljdk/internal/net/http/ConnectionPool$CacheKey;", nullptr, 0},
	{"channel", "()Ljava/nio/channels/SocketChannel;", nullptr, 0},
	{"close", "()V", nullptr, $PUBLIC},
	{"connectAsync", "(Ljdk/internal/net/http/Exchange;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/Exchange<*>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC},
	{"connected", "()Z", nullptr, 0},
	{"finishConnect", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC},
	{"getConnectionFlow", "()Ljdk/internal/net/http/common/SSLTube;", nullptr, 0},
	{"isProxied", "()Z", nullptr, 0},
	{"isTunnel", "()Z", nullptr, 0},
	{"lambda$connectAsync$0", "(Ljava/lang/Void;)Ljava/lang/Void;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$Void*(AsyncSSLTunnelConnection::*)($Void*)>(&AsyncSSLTunnelConnection::lambda$connectAsync$0))},
	{"lambda$finishConnect$1", "(Ljava/lang/String;Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletableFuture*(AsyncSSLTunnelConnection::*)($String*,$Throwable*)>(&AsyncSSLTunnelConnection::lambda$finishConnect$1))},
	{"proxy", "()Ljava/net/InetSocketAddress;", nullptr, 0},
	{"publisher", "()Ljdk/internal/net/http/HttpConnection$HttpPublisher;", nullptr, 0},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _AsyncSSLTunnelConnection_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.AsyncSSLTunnelConnection",
	"jdk.internal.net.http.AbstractAsyncSSLConnection",
	nullptr,
	_AsyncSSLTunnelConnection_FieldInfo_,
	_AsyncSSLTunnelConnection_MethodInfo_
};

$Object* allocate$AsyncSSLTunnelConnection($Class* clazz) {
	return $of($alloc(AsyncSSLTunnelConnection));
}

void AsyncSSLTunnelConnection::init$($InetSocketAddress* addr, $HttpClientImpl* client, $StringArray* alpn, $InetSocketAddress* proxy, $Utils$ProxyHeaders* proxyHeaders) {
	$useLocalCurrentObjectStackCache();
	$var($InetSocketAddress, var$0, addr);
	$var($HttpClientImpl, var$1, client);
	$var($Utils$ServerName, var$2, $Utils::getServerName(addr));
	$AbstractAsyncSSLConnection::init$(var$0, var$1, var$2, $nc(addr)->getPort(), alpn);
	$set(this, plainConnection, $new($PlainTunnelingConnection, addr, proxy, client, proxyHeaders));
	$set(this, writePublisher, $new($HttpConnection$PlainHttpPublisher, this));
}

$CompletableFuture* AsyncSSLTunnelConnection::connectAsync($Exchange* exchange) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Connecting plain tunnel connection"_s);
	}
	return $cast($CompletableFuture, $nc($($nc(this->plainConnection)->connectAsync(exchange)))->thenApply(static_cast<$Function*>($$new(AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0, this))));
}

$CompletableFuture* AsyncSSLTunnelConnection::finishConnect() {
	$useLocalCurrentObjectStackCache();
	return $cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc($(getALPN()))->handle(static_cast<$BiFunction*>($$new(AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1, this))))))->thenCompose($($Function::identity())));
}

bool AsyncSSLTunnelConnection::isTunnel() {
	return true;
}

bool AsyncSSLTunnelConnection::connected() {
	return $nc(this->plainConnection)->connected();
}

$HttpConnection$HttpPublisher* AsyncSSLTunnelConnection::publisher() {
	return this->writePublisher;
}

$String* AsyncSSLTunnelConnection::toString() {
	return $str({"AsyncSSLTunnelConnection: "_s, $($AbstractAsyncSSLConnection::toString())});
}

$ConnectionPool$CacheKey* AsyncSSLTunnelConnection::cacheKey() {
	return $ConnectionPool::cacheKey(this->address$, $nc(this->plainConnection)->proxyAddr);
}

void AsyncSSLTunnelConnection::close() {
	$nc(this->plainConnection)->close();
}

$SocketChannel* AsyncSSLTunnelConnection::channel() {
	return $nc(this->plainConnection)->channel();
}

bool AsyncSSLTunnelConnection::isProxied() {
	return true;
}

$InetSocketAddress* AsyncSSLTunnelConnection::proxy() {
	return $nc(this->plainConnection)->proxyAddr;
}

$FlowTube* AsyncSSLTunnelConnection::getConnectionFlow() {
	return this->flow;
}

$CompletableFuture* AsyncSSLTunnelConnection::lambda$finishConnect$1($String* unused, $Throwable* ex) {
	if (ex == nullptr) {
		return $nc(this->plainConnection)->finishConnect();
	} else {
		$nc(this->plainConnection)->close();
		return $MinimalFuture::failedFuture(ex);
	}
}

$Void* AsyncSSLTunnelConnection::lambda$connectAsync$0($Void* unused) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("creating SSLTube"_s);
	}
	$var($SSLEngine, var$0, this->engine);
	$var($Executor, var$1, static_cast<$Executor*>($nc($(client()))->theExecutor()));
	$var($Consumer, var$2, static_cast<$Consumer*>($new(AsyncSSLTunnelConnection$$Lambda$recycle$2, static_cast<$BufferSupplier*>($nc($($nc($(client()))->getSSLBufferSupplier()))))));
	$set(this, flow, $new($SSLTube, var$0, var$1, var$2, $($nc(this->plainConnection)->getConnectionFlow())));
	return nullptr;
}

AsyncSSLTunnelConnection::AsyncSSLTunnelConnection() {
}

$Class* AsyncSSLTunnelConnection::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0::classInfo$.name)) {
			return AsyncSSLTunnelConnection$$Lambda$lambda$connectAsync$0::load$(name, initialize);
		}
		if (name->equals(AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1::classInfo$.name)) {
			return AsyncSSLTunnelConnection$$Lambda$lambda$finishConnect$1$1::load$(name, initialize);
		}
		if (name->equals(AsyncSSLTunnelConnection$$Lambda$recycle$2::classInfo$.name)) {
			return AsyncSSLTunnelConnection$$Lambda$recycle$2::load$(name, initialize);
		}
	}
	$loadClass(AsyncSSLTunnelConnection, name, initialize, &_AsyncSSLTunnelConnection_ClassInfo_, allocate$AsyncSSLTunnelConnection);
	return class$;
}

$Class* AsyncSSLTunnelConnection::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk