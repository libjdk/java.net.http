#include <jdk/internal/net/http/PushGroup$Acceptor.h>

#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <jdk/internal/net/http/PushGroup.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $PushGroup = ::jdk::internal::net::http::PushGroup;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$MethodInfo _PushGroup$Acceptor_MethodInfo_[] = {
	{"accepted", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"bodyHandler", "()Ljava/net/http/HttpResponse$BodyHandler;", "()Ljava/net/http/HttpResponse$BodyHandler<TT;>;", $PUBLIC | $ABSTRACT},
	{"cf", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljava/net/http/HttpResponse<TT;>;>;", $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _PushGroup$Acceptor_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.PushGroup$Acceptor", "jdk.internal.net.http.PushGroup", "Acceptor", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _PushGroup$Acceptor_ClassInfo_ = {
	$INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.PushGroup$Acceptor",
	nullptr,
	nullptr,
	nullptr,
	_PushGroup$Acceptor_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	_PushGroup$Acceptor_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.PushGroup"
};

$Object* allocate$PushGroup$Acceptor($Class* clazz) {
	return $of($alloc(PushGroup$Acceptor));
}

$Class* PushGroup$Acceptor::load$($String* name, bool initialize) {
	$loadClass(PushGroup$Acceptor, name, initialize, &_PushGroup$Acceptor_ClassInfo_, allocate$PushGroup$Acceptor);
	return class$;
}

$Class* PushGroup$Acceptor::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk