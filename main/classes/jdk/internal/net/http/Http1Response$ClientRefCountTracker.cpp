#include <jdk/internal/net/http/Http1Response$ClientRefCountTracker.h>

#include <java/lang/AssertionError.h>
#include <jdk/internal/net/http/Http1Response.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Http1Response = ::jdk::internal::net::http::Http1Response;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $Logger = ::jdk::internal::net::http::common::Logger;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Http1Response$ClientRefCountTracker_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/Http1Response;", nullptr, $FINAL | $SYNTHETIC, $field(Http1Response$ClientRefCountTracker, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http1Response$ClientRefCountTracker, $assertionsDisabled)},
	{"client", "Ljdk/internal/net/http/HttpClientImpl;", nullptr, $FINAL, $field(Http1Response$ClientRefCountTracker, client)},
	{"state", "B", nullptr, 0, $field(Http1Response$ClientRefCountTracker, state)},
	{}
};

$MethodInfo _Http1Response$ClientRefCountTracker_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Response;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1Response$ClientRefCountTracker::*)($Http1Response*)>(&Http1Response$ClientRefCountTracker::init$))},
	{"acquire", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, $method(static_cast<void(Http1Response$ClientRefCountTracker::*)()>(&Http1Response$ClientRefCountTracker::acquire))},
	{"tryRelease", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, $method(static_cast<void(Http1Response$ClientRefCountTracker::*)()>(&Http1Response$ClientRefCountTracker::tryRelease))},
	{}
};

$InnerClassInfo _Http1Response$ClientRefCountTracker_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Response$ClientRefCountTracker", "jdk.internal.net.http.Http1Response", "ClientRefCountTracker", $PRIVATE | $FINAL},
	{}
};

$ClassInfo _Http1Response$ClientRefCountTracker_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Http1Response$ClientRefCountTracker",
	"java.lang.Object",
	nullptr,
	_Http1Response$ClientRefCountTracker_FieldInfo_,
	_Http1Response$ClientRefCountTracker_MethodInfo_,
	nullptr,
	nullptr,
	_Http1Response$ClientRefCountTracker_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Response"
};

$Object* allocate$Http1Response$ClientRefCountTracker($Class* clazz) {
	return $of($alloc(Http1Response$ClientRefCountTracker));
}

bool Http1Response$ClientRefCountTracker::$assertionsDisabled = false;

void Http1Response$ClientRefCountTracker::init$($Http1Response* this$0) {
	$set(this, this$0, this$0);
	$set(this, client, $nc(this->this$0->connection)->client());
}

void Http1Response$ClientRefCountTracker::acquire() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->state == 0) {
			if ($nc(this->this$0->debug)->on()) {
				$nc(this->this$0->debug)->log("Operation started: incrementing ref count for %s"_s, $$new($ObjectArray, {$of(this->client)}));
			}
			$nc(this->client)->reference();
			this->state = (int8_t)1;
		} else {
			if ($nc(this->this$0->debug)->on()) {
				$nc(this->this$0->debug)->log("Operation ref count for %s is already %s"_s, $$new($ObjectArray, {
					$of(this->client),
					(((int32_t)(this->state & (uint32_t)2)) == 2) ? $of("released."_s) : $of("incremented!"_s)
				}));
			}
			if (!Http1Response$ClientRefCountTracker::$assertionsDisabled && !(((int32_t)(this->state & (uint32_t)1)) == 0)) {
				$throwNew($AssertionError, $of("reference count already incremented"_s));
			}
		}
	}
}

void Http1Response$ClientRefCountTracker::tryRelease() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->state == 1) {
			if ($nc(this->this$0->debug)->on()) {
				$nc(this->this$0->debug)->log("Operation finished: decrementing ref count for %s"_s, $$new($ObjectArray, {$of(this->client)}));
			}
			$nc(this->client)->unreference();
		} else if (this->state == 0) {
			if ($nc(this->this$0->debug)->on()) {
				$nc(this->this$0->debug)->log("Operation finished: releasing ref count for %s"_s, $$new($ObjectArray, {$of(this->client)}));
			}
		} else if (((int32_t)(this->state & (uint32_t)2)) == 2) {
			if ($nc(this->this$0->debug)->on()) {
				$nc(this->this$0->debug)->log("ref count for %s already released"_s, $$new($ObjectArray, {$of(this->client)}));
			}
		}
		this->state |= 2;
	}
}

void clinit$Http1Response$ClientRefCountTracker($Class* class$) {
	$load($Http1Response);
	Http1Response$ClientRefCountTracker::$assertionsDisabled = !$Http1Response::class$->desiredAssertionStatus();
}

Http1Response$ClientRefCountTracker::Http1Response$ClientRefCountTracker() {
}

$Class* Http1Response$ClientRefCountTracker::load$($String* name, bool initialize) {
	$loadClass(Http1Response$ClientRefCountTracker, name, initialize, &_Http1Response$ClientRefCountTracker_ClassInfo_, clinit$Http1Response$ClientRefCountTracker, allocate$Http1Response$ClientRefCountTracker);
	return class$;
}

$Class* Http1Response$ClientRefCountTracker::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk