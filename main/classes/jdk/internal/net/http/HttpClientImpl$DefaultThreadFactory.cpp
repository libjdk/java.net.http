#include <jdk/internal/net/http/HttpClientImpl$DefaultThreadFactory.h>

#include <java/lang/Runnable.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/ThreadGroup.h>
#include <java/util/concurrent/atomic/AtomicInteger.h>
#include <jdk/internal/misc/InnocuousThread.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $SecurityManager = ::java::lang::SecurityManager;
using $ThreadGroup = ::java::lang::ThreadGroup;
using $ThreadFactory = ::java::util::concurrent::ThreadFactory;
using $AtomicInteger = ::java::util::concurrent::atomic::AtomicInteger;
using $InnocuousThread = ::jdk::internal::misc::InnocuousThread;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _HttpClientImpl$DefaultThreadFactory_FieldInfo_[] = {
	{"namePrefix", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl$DefaultThreadFactory, namePrefix)},
	{"nextId", "Ljava/util/concurrent/atomic/AtomicInteger;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl$DefaultThreadFactory, nextId)},
	{}
};

$MethodInfo _HttpClientImpl$DefaultThreadFactory_MethodInfo_[] = {
	{"<init>", "(J)V", nullptr, 0, $method(static_cast<void(HttpClientImpl$DefaultThreadFactory::*)(int64_t)>(&HttpClientImpl$DefaultThreadFactory::init$))},
	{"newThread", "(Ljava/lang/Runnable;)Ljava/lang/Thread;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _HttpClientImpl$DefaultThreadFactory_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.HttpClientImpl$DefaultThreadFactory", "jdk.internal.net.http.HttpClientImpl", "DefaultThreadFactory", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _HttpClientImpl$DefaultThreadFactory_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.HttpClientImpl$DefaultThreadFactory",
	"java.lang.Object",
	"java.util.concurrent.ThreadFactory",
	_HttpClientImpl$DefaultThreadFactory_FieldInfo_,
	_HttpClientImpl$DefaultThreadFactory_MethodInfo_,
	nullptr,
	nullptr,
	_HttpClientImpl$DefaultThreadFactory_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HttpClientImpl"
};

$Object* allocate$HttpClientImpl$DefaultThreadFactory($Class* clazz) {
	return $of($alloc(HttpClientImpl$DefaultThreadFactory));
}

void HttpClientImpl$DefaultThreadFactory::init$(int64_t clientID) {
	$set(this, nextId, $new($AtomicInteger));
	$set(this, namePrefix, $str({"HttpClient-"_s, $$str(clientID), "-Worker-"_s}));
}

$Thread* HttpClientImpl$DefaultThreadFactory::newThread($Runnable* r) {
	$useLocalCurrentObjectStackCache();
	$var($String, name, $str({this->namePrefix, $$str($nc(this->nextId)->getAndIncrement())}));
	$var($Thread, t, nullptr);
	if ($System::getSecurityManager() == nullptr) {
		$assign(t, $new($Thread, nullptr, r, name, 0, false));
	} else {
		$assign(t, $InnocuousThread::newThread(name, r));
	}
	$nc(t)->setDaemon(true);
	return t;
}

HttpClientImpl$DefaultThreadFactory::HttpClientImpl$DefaultThreadFactory() {
}

$Class* HttpClientImpl$DefaultThreadFactory::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$DefaultThreadFactory, name, initialize, &_HttpClientImpl$DefaultThreadFactory_ClassInfo_, allocate$HttpClientImpl$DefaultThreadFactory);
	return class$;
}

$Class* HttpClientImpl$DefaultThreadFactory::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk