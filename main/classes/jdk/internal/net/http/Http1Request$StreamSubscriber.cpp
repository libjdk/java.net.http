#include <jdk/internal/net/http/Http1Request$StreamSubscriber.h>

#include <java/lang/IllegalStateException.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <jdk/internal/net/http/Http1Exchange$Http1BodySubscriber.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jdk/internal/net/http/Http1Request.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jcpp.h>

#undef COMPLETED
#undef CRLF
#undef EMPTY_CHUNK_BYTES

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Http1Exchange = ::jdk::internal::net::http::Http1Exchange;
using $Http1Exchange$Http1BodySubscriber = ::jdk::internal::net::http::Http1Exchange$Http1BodySubscriber;
using $Http1Request = ::jdk::internal::net::http::Http1Request;
using $Logger = ::jdk::internal::net::http::common::Logger;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Http1Request$StreamSubscriber_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/Http1Request;", nullptr, $FINAL | $SYNTHETIC, $field(Http1Request$StreamSubscriber, this$0)},
	{}
};

$MethodInfo _Http1Request$StreamSubscriber_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Request;)V", nullptr, 0, $method(static_cast<void(Http1Request$StreamSubscriber::*)($Http1Request*)>(&Http1Request$StreamSubscriber::init$))},
	{"currentStateMessage", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Request$StreamSubscriber::*)($ByteBuffer*)>(&Http1Request$StreamSubscriber::onNext))},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Http1Request$StreamSubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Request$StreamSubscriber", "jdk.internal.net.http.Http1Request", "StreamSubscriber", $FINAL},
	{"jdk.internal.net.http.Http1Exchange$Http1BodySubscriber", "jdk.internal.net.http.Http1Exchange", "Http1BodySubscriber", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _Http1Request$StreamSubscriber_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Http1Request$StreamSubscriber",
	"jdk.internal.net.http.Http1Exchange$Http1BodySubscriber",
	nullptr,
	_Http1Request$StreamSubscriber_FieldInfo_,
	_Http1Request$StreamSubscriber_MethodInfo_,
	nullptr,
	nullptr,
	_Http1Request$StreamSubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Request"
};

$Object* allocate$Http1Request$StreamSubscriber($Class* clazz) {
	return $of($alloc(Http1Request$StreamSubscriber));
}

void Http1Request$StreamSubscriber::init$($Http1Request* this$0) {
	$set(this, this$0, this$0);
	$Http1Exchange$Http1BodySubscriber::init$(this$0->debug);
}

void Http1Request$StreamSubscriber::onSubscribe($Flow$Subscription* subscription) {
	if (isSubscribed()) {
		$var($Throwable, t, $new($IllegalStateException, "already subscribed"_s));
		$nc(this->this$0->http1Exchange)->appendToOutgoing(t);
	} else {
		setSubscription(subscription);
	}
}

void Http1Request$StreamSubscriber::onNext($ByteBuffer* item) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(item);
	if (this->complete) {
		$var($Throwable, t, $new($IllegalStateException, "subscription already completed"_s));
		$nc(this->this$0->http1Exchange)->appendToOutgoing(t);
	} else {
		int32_t chunklen = item->remaining();
		$var($ArrayList, l, $new($ArrayList, 3));
		l->add($($Http1Request::getHeader(chunklen)));
		l->add(item);
		l->add($($ByteBuffer::wrap($Http1Request::CRLF)));
		$nc(this->this$0->http1Exchange)->appendToOutgoing(static_cast<$List*>(l));
	}
}

$String* Http1Request$StreamSubscriber::currentStateMessage() {
	return $str({"streaming request body "_s, (this->complete ? "complete"_s : "incomplete"_s)});
}

void Http1Request$StreamSubscriber::onError($Throwable* throwable) {
	if (this->complete) {
		return;
	}
	cancelSubscription();
	$nc(this->this$0->http1Exchange)->appendToOutgoing(throwable);
}

void Http1Request$StreamSubscriber::onComplete() {
	$useLocalCurrentObjectStackCache();
	if (this->complete) {
		$var($Throwable, t, $new($IllegalStateException, "subscription already completed"_s));
		$nc(this->this$0->http1Exchange)->appendToOutgoing(t);
	} else {
		$var($ArrayList, l, $new($ArrayList, 2));
		$init($Http1Request);
		l->add($($ByteBuffer::wrap($Http1Request::EMPTY_CHUNK_BYTES)));
		l->add($($ByteBuffer::wrap($Http1Request::CRLF)));
		this->complete = true;
		$nc(this->this$0->http1Exchange)->appendToOutgoing(static_cast<$List*>(l));
		$init($Http1Exchange$Http1BodySubscriber);
		$nc(this->this$0->http1Exchange)->appendToOutgoing($Http1Exchange$Http1BodySubscriber::COMPLETED);
		this->this$0->setFinished();
	}
}

void Http1Request$StreamSubscriber::onNext(Object$* item) {
	this->onNext($cast($ByteBuffer, item));
}

Http1Request$StreamSubscriber::Http1Request$StreamSubscriber() {
}

$Class* Http1Request$StreamSubscriber::load$($String* name, bool initialize) {
	$loadClass(Http1Request$StreamSubscriber, name, initialize, &_Http1Request$StreamSubscriber_ClassInfo_, allocate$Http1Request$StreamSubscriber);
	return class$;
}

$Class* Http1Request$StreamSubscriber::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk