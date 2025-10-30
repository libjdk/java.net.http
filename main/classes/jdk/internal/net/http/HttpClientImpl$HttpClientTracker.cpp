#include <jdk/internal/net/http/HttpClientImpl$HttpClientTracker.h>

#include <java/lang/ref/Reference.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Reference = ::java::lang::ref::Reference;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $OperationTrackers$Tracker = ::jdk::internal::net::http::common::OperationTrackers$Tracker;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _HttpClientImpl$HttpClientTracker_FieldInfo_[] = {
	{"httpCount", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $FINAL, $field(HttpClientImpl$HttpClientTracker, httpCount)},
	{"http2Count", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $FINAL, $field(HttpClientImpl$HttpClientTracker, http2Count)},
	{"websocketCount", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $FINAL, $field(HttpClientImpl$HttpClientTracker, websocketCount)},
	{"operationsCount", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $FINAL, $field(HttpClientImpl$HttpClientTracker, operationsCount)},
	{"reference", "Ljava/lang/ref/Reference;", "Ljava/lang/ref/Reference<*>;", $FINAL, $field(HttpClientImpl$HttpClientTracker, reference)},
	{"name", "Ljava/lang/String;", nullptr, $FINAL, $field(HttpClientImpl$HttpClientTracker, name)},
	{}
};

$MethodInfo _HttpClientImpl$HttpClientTracker_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/atomic/AtomicLong;Ljava/util/concurrent/atomic/AtomicLong;Ljava/util/concurrent/atomic/AtomicLong;Ljava/util/concurrent/atomic/AtomicLong;Ljava/lang/ref/Reference;Ljava/lang/String;)V", "(Ljava/util/concurrent/atomic/AtomicLong;Ljava/util/concurrent/atomic/AtomicLong;Ljava/util/concurrent/atomic/AtomicLong;Ljava/util/concurrent/atomic/AtomicLong;Ljava/lang/ref/Reference<*>;Ljava/lang/String;)V", 0, $method(static_cast<void(HttpClientImpl$HttpClientTracker::*)($AtomicLong*,$AtomicLong*,$AtomicLong*,$AtomicLong*,$Reference*,$String*)>(&HttpClientImpl$HttpClientTracker::init$))},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getOutstandingHttp2Streams", "()J", nullptr, $PUBLIC},
	{"getOutstandingHttpOperations", "()J", nullptr, $PUBLIC},
	{"getOutstandingOperations", "()J", nullptr, $PUBLIC},
	{"getOutstandingWebSocketOperations", "()J", nullptr, $PUBLIC},
	{"isFacadeReferenced", "()Z", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _HttpClientImpl$HttpClientTracker_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.HttpClientImpl$HttpClientTracker", "jdk.internal.net.http.HttpClientImpl", "HttpClientTracker", $STATIC | $FINAL},
	{"jdk.internal.net.http.common.OperationTrackers$Tracker", "jdk.internal.net.http.common.OperationTrackers", "Tracker", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpClientImpl$HttpClientTracker_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.HttpClientImpl$HttpClientTracker",
	"java.lang.Object",
	"jdk.internal.net.http.common.OperationTrackers$Tracker",
	_HttpClientImpl$HttpClientTracker_FieldInfo_,
	_HttpClientImpl$HttpClientTracker_MethodInfo_,
	nullptr,
	nullptr,
	_HttpClientImpl$HttpClientTracker_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HttpClientImpl"
};

$Object* allocate$HttpClientImpl$HttpClientTracker($Class* clazz) {
	return $of($alloc(HttpClientImpl$HttpClientTracker));
}

void HttpClientImpl$HttpClientTracker::init$($AtomicLong* http, $AtomicLong* http2, $AtomicLong* ws, $AtomicLong* ops, $Reference* ref, $String* name) {
	$set(this, httpCount, http);
	$set(this, http2Count, http2);
	$set(this, websocketCount, ws);
	$set(this, operationsCount, ops);
	$set(this, reference, ref);
	$set(this, name, name);
}

int64_t HttpClientImpl$HttpClientTracker::getOutstandingOperations() {
	return $nc(this->operationsCount)->get();
}

int64_t HttpClientImpl$HttpClientTracker::getOutstandingHttpOperations() {
	return $nc(this->httpCount)->get();
}

int64_t HttpClientImpl$HttpClientTracker::getOutstandingHttp2Streams() {
	return $nc(this->http2Count)->get();
}

int64_t HttpClientImpl$HttpClientTracker::getOutstandingWebSocketOperations() {
	return $nc(this->websocketCount)->get();
}

bool HttpClientImpl$HttpClientTracker::isFacadeReferenced() {
	return $nc(this->reference)->get() != nullptr;
}

$String* HttpClientImpl$HttpClientTracker::getName() {
	return this->name;
}

HttpClientImpl$HttpClientTracker::HttpClientImpl$HttpClientTracker() {
}

$Class* HttpClientImpl$HttpClientTracker::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$HttpClientTracker, name, initialize, &_HttpClientImpl$HttpClientTracker_ClassInfo_, allocate$HttpClientImpl$HttpClientTracker);
	return class$;
}

$Class* HttpClientImpl$HttpClientTracker::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk