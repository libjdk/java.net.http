#include <jdk/internal/net/http/AsyncSSLConnection.h>

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
#include <jdk/internal/net/http/PlainHttpConnection.h>
#include <jdk/internal/net/http/common/BufferSupplier.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/SSLTube.h>
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
using $PlainHttpConnection = ::jdk::internal::net::http::PlainHttpConnection;
using $BufferSupplier = ::jdk::internal::net::http::common::BufferSupplier;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $SSLTube = ::jdk::internal::net::http::common::SSLTube;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $Utils$ServerName = ::jdk::internal::net::http::common::Utils$ServerName;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class AsyncSSLConnection$$Lambda$lambda$connectAsync$0 : public $Function {
	$class(AsyncSSLConnection$$Lambda$lambda$connectAsync$0, $NO_CLASS_INIT, $Function)
public:
	void init$(AsyncSSLConnection* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* unused) override {
		 return $of($nc(inst$)->lambda$connectAsync$0($cast($Void, unused)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AsyncSSLConnection$$Lambda$lambda$connectAsync$0>());
	}
	AsyncSSLConnection* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo AsyncSSLConnection$$Lambda$lambda$connectAsync$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(AsyncSSLConnection$$Lambda$lambda$connectAsync$0, inst$)},
	{}
};
$MethodInfo AsyncSSLConnection$$Lambda$lambda$connectAsync$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/AsyncSSLConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(AsyncSSLConnection$$Lambda$lambda$connectAsync$0::*)(AsyncSSLConnection*)>(&AsyncSSLConnection$$Lambda$lambda$connectAsync$0::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo AsyncSSLConnection$$Lambda$lambda$connectAsync$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.AsyncSSLConnection$$Lambda$lambda$connectAsync$0",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* AsyncSSLConnection$$Lambda$lambda$connectAsync$0::load$($String* name, bool initialize) {
	$loadClass(AsyncSSLConnection$$Lambda$lambda$connectAsync$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AsyncSSLConnection$$Lambda$lambda$connectAsync$0::class$ = nullptr;

class AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1 : public $BiFunction {
	$class(AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1, $NO_CLASS_INIT, $BiFunction)
public:
	void init$(AsyncSSLConnection* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* unused, Object$* ex) override {
		 return $of($nc(inst$)->lambda$finishConnect$1($cast($String, unused), $cast($Throwable, ex)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1>());
	}
	AsyncSSLConnection* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1, inst$)},
	{}
};
$MethodInfo AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/AsyncSSLConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1::*)(AsyncSSLConnection*)>(&AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1::init$))},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1::load$($String* name, bool initialize) {
	$loadClass(AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1::class$ = nullptr;

class AsyncSSLConnection$$Lambda$recycle$2 : public $Consumer {
	$class(AsyncSSLConnection$$Lambda$recycle$2, $NO_CLASS_INIT, $Consumer)
public:
	void init$($BufferSupplier* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* buffer) override {
		$nc(inst$)->recycle($cast($ByteBuffer, buffer));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<AsyncSSLConnection$$Lambda$recycle$2>());
	}
	$BufferSupplier* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo AsyncSSLConnection$$Lambda$recycle$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(AsyncSSLConnection$$Lambda$recycle$2, inst$)},
	{}
};
$MethodInfo AsyncSSLConnection$$Lambda$recycle$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/common/BufferSupplier;)V", nullptr, $PUBLIC, $method(static_cast<void(AsyncSSLConnection$$Lambda$recycle$2::*)($BufferSupplier*)>(&AsyncSSLConnection$$Lambda$recycle$2::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo AsyncSSLConnection$$Lambda$recycle$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.AsyncSSLConnection$$Lambda$recycle$2",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* AsyncSSLConnection$$Lambda$recycle$2::load$($String* name, bool initialize) {
	$loadClass(AsyncSSLConnection$$Lambda$recycle$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* AsyncSSLConnection$$Lambda$recycle$2::class$ = nullptr;

$FieldInfo _AsyncSSLConnection_FieldInfo_[] = {
	{"plainConnection", "Ljdk/internal/net/http/PlainHttpConnection;", nullptr, $FINAL, $field(AsyncSSLConnection, plainConnection)},
	{"writePublisher", "Ljdk/internal/net/http/HttpConnection$PlainHttpPublisher;", nullptr, $FINAL, $field(AsyncSSLConnection, writePublisher)},
	{"flow", "Ljdk/internal/net/http/common/SSLTube;", nullptr, $PRIVATE | $VOLATILE, $field(AsyncSSLConnection, flow)},
	{}
};

$MethodInfo _AsyncSSLConnection_MethodInfo_[] = {
	{"<init>", "(Ljava/net/InetSocketAddress;Ljdk/internal/net/http/HttpClientImpl;[Ljava/lang/String;)V", nullptr, 0, $method(static_cast<void(AsyncSSLConnection::*)($InetSocketAddress*,$HttpClientImpl*,$StringArray*)>(&AsyncSSLConnection::init$))},
	{"cacheKey", "()Ljdk/internal/net/http/ConnectionPool$CacheKey;", nullptr, 0},
	{"channel", "()Ljava/nio/channels/SocketChannel;", nullptr, 0},
	{"close", "()V", nullptr, $PUBLIC},
	{"connectAsync", "(Ljdk/internal/net/http/Exchange;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/Exchange<*>;)Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC},
	{"connected", "()Z", nullptr, 0},
	{"finishConnect", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/lang/Void;>;", $PUBLIC},
	{"getConnectionFlow", "()Ljdk/internal/net/http/common/SSLTube;", nullptr, 0},
	{"isProxied", "()Z", nullptr, 0},
	{"lambda$connectAsync$0", "(Ljava/lang/Void;)Ljava/lang/Void;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$Void*(AsyncSSLConnection::*)($Void*)>(&AsyncSSLConnection::lambda$connectAsync$0))},
	{"lambda$finishConnect$1", "(Ljava/lang/String;Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$CompletableFuture*(AsyncSSLConnection::*)($String*,$Throwable*)>(&AsyncSSLConnection::lambda$finishConnect$1))},
	{"proxy", "()Ljava/net/InetSocketAddress;", nullptr, 0},
	{"publisher", "()Ljdk/internal/net/http/HttpConnection$HttpPublisher;", nullptr, 0},
	{}
};

$ClassInfo _AsyncSSLConnection_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.AsyncSSLConnection",
	"jdk.internal.net.http.AbstractAsyncSSLConnection",
	nullptr,
	_AsyncSSLConnection_FieldInfo_,
	_AsyncSSLConnection_MethodInfo_
};

$Object* allocate$AsyncSSLConnection($Class* clazz) {
	return $of($alloc(AsyncSSLConnection));
}

void AsyncSSLConnection::init$($InetSocketAddress* addr, $HttpClientImpl* client, $StringArray* alpn) {
	$useLocalCurrentObjectStackCache();
	$var($InetSocketAddress, var$0, addr);
	$var($HttpClientImpl, var$1, client);
	$var($Utils$ServerName, var$2, $Utils::getServerName(addr));
	$AbstractAsyncSSLConnection::init$(var$0, var$1, var$2, $nc(addr)->getPort(), alpn);
	$set(this, plainConnection, $new($PlainHttpConnection, addr, client));
	$set(this, writePublisher, $new($HttpConnection$PlainHttpPublisher, this));
}

$CompletableFuture* AsyncSSLConnection::connectAsync($Exchange* exchange) {
	$useLocalCurrentObjectStackCache();
	return $cast($CompletableFuture, $nc($($nc(this->plainConnection)->connectAsync(exchange)))->thenApply(static_cast<$Function*>($$new(AsyncSSLConnection$$Lambda$lambda$connectAsync$0, this))));
}

$CompletableFuture* AsyncSSLConnection::finishConnect() {
	$useLocalCurrentObjectStackCache();
	return $cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc($(getALPN()))->handle(static_cast<$BiFunction*>($$new(AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1, this))))))->thenCompose($($Function::identity())));
}

bool AsyncSSLConnection::connected() {
	return $nc(this->plainConnection)->connected();
}

$HttpConnection$HttpPublisher* AsyncSSLConnection::publisher() {
	return this->writePublisher;
}

bool AsyncSSLConnection::isProxied() {
	return false;
}

$InetSocketAddress* AsyncSSLConnection::proxy() {
	return nullptr;
}

$SocketChannel* AsyncSSLConnection::channel() {
	return $nc(this->plainConnection)->channel();
}

$ConnectionPool$CacheKey* AsyncSSLConnection::cacheKey() {
	return $ConnectionPool::cacheKey(this->address$, nullptr);
}

void AsyncSSLConnection::close() {
	$nc(this->plainConnection)->close();
}

$FlowTube* AsyncSSLConnection::getConnectionFlow() {
	return this->flow;
}

$CompletableFuture* AsyncSSLConnection::lambda$finishConnect$1($String* unused, $Throwable* ex) {
	if (ex == nullptr) {
		return $nc(this->plainConnection)->finishConnect();
	} else {
		$nc(this->plainConnection)->close();
		return $MinimalFuture::failedFuture(ex);
	}
}

$Void* AsyncSSLConnection::lambda$connectAsync$0($Void* unused) {
	$useLocalCurrentObjectStackCache();
	$var($SSLEngine, var$0, this->engine);
	$var($Executor, var$1, static_cast<$Executor*>($nc($(client()))->theExecutor()));
	$var($Consumer, var$2, static_cast<$Consumer*>($new(AsyncSSLConnection$$Lambda$recycle$2, static_cast<$BufferSupplier*>($nc($($nc($(client()))->getSSLBufferSupplier()))))));
	$set(this, flow, $new($SSLTube, var$0, var$1, var$2, $($nc(this->plainConnection)->getConnectionFlow())));
	return nullptr;
}

AsyncSSLConnection::AsyncSSLConnection() {
}

$Class* AsyncSSLConnection::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(AsyncSSLConnection$$Lambda$lambda$connectAsync$0::classInfo$.name)) {
			return AsyncSSLConnection$$Lambda$lambda$connectAsync$0::load$(name, initialize);
		}
		if (name->equals(AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1::classInfo$.name)) {
			return AsyncSSLConnection$$Lambda$lambda$finishConnect$1$1::load$(name, initialize);
		}
		if (name->equals(AsyncSSLConnection$$Lambda$recycle$2::classInfo$.name)) {
			return AsyncSSLConnection$$Lambda$recycle$2::load$(name, initialize);
		}
	}
	$loadClass(AsyncSSLConnection, name, initialize, &_AsyncSSLConnection_ClassInfo_, allocate$AsyncSSLConnection);
	return class$;
}

$Class* AsyncSSLConnection::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk