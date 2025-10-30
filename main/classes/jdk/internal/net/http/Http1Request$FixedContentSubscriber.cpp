#include <jdk/internal/net/http/Http1Request$FixedContentSubscriber.h>

#include <java/io/IOException.h>
#include <java/lang/IllegalStateException.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <jdk/internal/net/http/Http1Exchange$Http1BodySubscriber.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jdk/internal/net/http/Http1Request.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jcpp.h>

#undef COMPLETED

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;
using $Http1Exchange$Http1BodySubscriber = ::jdk::internal::net::http::Http1Exchange$Http1BodySubscriber;
using $Http1Request = ::jdk::internal::net::http::Http1Request;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $Logger = ::jdk::internal::net::http::common::Logger;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Http1Request$FixedContentSubscriber_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/Http1Request;", nullptr, $FINAL | $SYNTHETIC, $field(Http1Request$FixedContentSubscriber, this$0)},
	{"contentWritten", "J", nullptr, $PRIVATE | $VOLATILE, $field(Http1Request$FixedContentSubscriber, contentWritten)},
	{}
};

$MethodInfo _Http1Request$FixedContentSubscriber_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Request;)V", nullptr, 0, $method(static_cast<void(Http1Request$FixedContentSubscriber::*)($Http1Request*)>(&Http1Request$FixedContentSubscriber::init$))},
	{"currentStateMessage", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Request$FixedContentSubscriber::*)($ByteBuffer*)>(&Http1Request$FixedContentSubscriber::onNext))},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Http1Request$FixedContentSubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Request$FixedContentSubscriber", "jdk.internal.net.http.Http1Request", "FixedContentSubscriber", $FINAL},
	{"jdk.internal.net.http.Http1Exchange$Http1BodySubscriber", "jdk.internal.net.http.Http1Exchange", "Http1BodySubscriber", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _Http1Request$FixedContentSubscriber_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Http1Request$FixedContentSubscriber",
	"jdk.internal.net.http.Http1Exchange$Http1BodySubscriber",
	nullptr,
	_Http1Request$FixedContentSubscriber_FieldInfo_,
	_Http1Request$FixedContentSubscriber_MethodInfo_,
	nullptr,
	nullptr,
	_Http1Request$FixedContentSubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Request"
};

$Object* allocate$Http1Request$FixedContentSubscriber($Class* clazz) {
	return $of($alloc(Http1Request$FixedContentSubscriber));
}

void Http1Request$FixedContentSubscriber::init$($Http1Request* this$0) {
	$set(this, this$0, this$0);
	$Http1Exchange$Http1BodySubscriber::init$(this$0->debug);
}

void Http1Request$FixedContentSubscriber::onSubscribe($Flow$Subscription* subscription) {
	if (isSubscribed()) {
		$var($Throwable, t, $new($IllegalStateException, "already subscribed"_s));
		$nc(this->this$0->http1Exchange)->appendToOutgoing(t);
	} else {
		setSubscription(subscription);
	}
}

void Http1Request$FixedContentSubscriber::onNext($ByteBuffer* item) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("onNext"_s);
	}
	$Objects::requireNonNull(item);
	if (this->complete) {
		$var($Throwable, t, $new($IllegalStateException, "subscription already completed"_s));
		$nc(this->this$0->http1Exchange)->appendToOutgoing(t);
	} else {
		int64_t writing = item->remaining();
		int64_t written = (this->contentWritten += writing);
		if (written > this->this$0->contentLength) {
			cancelSubscription();
			$var($String, var$4, $$str({$($nc(this->this$0->connection)->getConnectionFlow()), " ["_s}));
			$var($String, var$3, $$concat(var$4, $($($Thread::currentThread())->getName())));
			$var($String, var$2, $$concat(var$3, "] Too many bytes in request body. Expected: "));
			$var($String, var$1, $$concat(var$2, $$str(this->this$0->contentLength)));
			$var($String, var$0, $$concat(var$1, ", got: "));
			$var($String, msg, $concat(var$0, $$str(written)));
			$nc(this->this$0->http1Exchange)->appendToOutgoing(static_cast<$Throwable*>($$new($IOException, msg)));
		} else {
			$nc(this->this$0->http1Exchange)->appendToOutgoing($($List::of($of(item))));
		}
	}
}

$String* Http1Request$FixedContentSubscriber::currentStateMessage() {
	$useLocalCurrentObjectStackCache();
	return $String::format("fixed content-length: %d, bytes sent: %d"_s, $$new($ObjectArray, {
		$($of($Long::valueOf(this->this$0->contentLength))),
		$($of($Long::valueOf(this->contentWritten)))
	}));
}

void Http1Request$FixedContentSubscriber::onError($Throwable* throwable) {
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("onError"_s);
	}
	if (this->complete) {
		return;
	}
	cancelSubscription();
	$nc(this->this$0->http1Exchange)->appendToOutgoing(throwable);
}

void Http1Request$FixedContentSubscriber::onComplete() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("onComplete"_s);
	}
	if (this->complete) {
		$var($Throwable, t, $new($IllegalStateException, "subscription already completed"_s));
		$nc(this->this$0->http1Exchange)->appendToOutgoing(t);
	} else {
		this->complete = true;
		int64_t written = this->contentWritten;
		if (this->this$0->contentLength > written) {
			cancelSubscription();
			$var($String, var$5, $$str({$($nc(this->this$0->connection)->getConnectionFlow()), " ["_s}));
			$var($String, var$4, $$concat(var$5, $($($Thread::currentThread())->getName())));
			$var($String, var$3, $$concat(var$4, "] Too few bytes returned by the publisher ("));
			$var($String, var$2, $$concat(var$3, $$str(written)));
			$var($String, var$1, $$concat(var$2, "/"));
			$var($String, var$0, $$concat(var$1, $$str(this->this$0->contentLength)));
			$var($Throwable, t, $new($IOException, $$concat(var$0, ")")));
			$nc(this->this$0->http1Exchange)->appendToOutgoing(t);
		} else {
			$init($Http1Exchange$Http1BodySubscriber);
			$nc(this->this$0->http1Exchange)->appendToOutgoing($Http1Exchange$Http1BodySubscriber::COMPLETED);
		}
	}
}

void Http1Request$FixedContentSubscriber::onNext(Object$* item) {
	this->onNext($cast($ByteBuffer, item));
}

Http1Request$FixedContentSubscriber::Http1Request$FixedContentSubscriber() {
}

$Class* Http1Request$FixedContentSubscriber::load$($String* name, bool initialize) {
	$loadClass(Http1Request$FixedContentSubscriber, name, initialize, &_Http1Request$FixedContentSubscriber_ClassInfo_, allocate$Http1Request$FixedContentSubscriber);
	return class$;
}

$Class* Http1Request$FixedContentSubscriber::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk