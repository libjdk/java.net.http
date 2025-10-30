#include <jdk/internal/net/http/RequestPublishers$AggregatePublisher.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/http/HttpRequest$BodyPublisher.h>
#include <java/util/List.h>
#include <java/util/OptionalLong.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/function/LongBinaryOperator.h>
#include <java/util/function/ToLongFunction.h>
#include <java/util/stream/LongStream.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/net/http/RequestPublishers$AggregateSubscription.h>
#include <jdk/internal/net/http/RequestPublishers.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $OptionalLong = ::java::util::OptionalLong;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $LongBinaryOperator = ::java::util::function::LongBinaryOperator;
using $ToLongFunction = ::java::util::function::ToLongFunction;
using $LongStream = ::java::util::stream::LongStream;
using $Stream = ::java::util::stream::Stream;
using $RequestPublishers = ::jdk::internal::net::http::RequestPublishers;
using $RequestPublishers$AggregateSubscription = ::jdk::internal::net::http::RequestPublishers$AggregateSubscription;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class RequestPublishers$AggregatePublisher$$Lambda$contentLength : public $ToLongFunction {
	$class(RequestPublishers$AggregatePublisher$$Lambda$contentLength, $NO_CLASS_INIT, $ToLongFunction)
public:
	void init$() {
	}
	virtual int64_t applyAsLong(Object$* inst$) override {
		 return $sure($HttpRequest$BodyPublisher, inst$)->contentLength();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RequestPublishers$AggregatePublisher$$Lambda$contentLength>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo RequestPublishers$AggregatePublisher$$Lambda$contentLength::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RequestPublishers$AggregatePublisher$$Lambda$contentLength::*)()>(&RequestPublishers$AggregatePublisher$$Lambda$contentLength::init$))},
	{"applyAsLong", "(Ljava/lang/Object;)J", nullptr, $PUBLIC},
	{}
};
$ClassInfo RequestPublishers$AggregatePublisher$$Lambda$contentLength::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.RequestPublishers$AggregatePublisher$$Lambda$contentLength",
	"java.lang.Object",
	"java.util.function.ToLongFunction",
	nullptr,
	methodInfos
};
$Class* RequestPublishers$AggregatePublisher$$Lambda$contentLength::load$($String* name, bool initialize) {
	$loadClass(RequestPublishers$AggregatePublisher$$Lambda$contentLength, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RequestPublishers$AggregatePublisher$$Lambda$contentLength::class$ = nullptr;

class RequestPublishers$AggregatePublisher$$Lambda$lambda$contentLength$0$1 : public $LongBinaryOperator {
	$class(RequestPublishers$AggregatePublisher$$Lambda$lambda$contentLength$0$1, $NO_CLASS_INIT, $LongBinaryOperator)
public:
	void init$() {
	}
	virtual int64_t applyAsLong(int64_t a, int64_t b) override {
		 return RequestPublishers$AggregatePublisher::lambda$contentLength$0(a, b);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RequestPublishers$AggregatePublisher$$Lambda$lambda$contentLength$0$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo RequestPublishers$AggregatePublisher$$Lambda$lambda$contentLength$0$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RequestPublishers$AggregatePublisher$$Lambda$lambda$contentLength$0$1::*)()>(&RequestPublishers$AggregatePublisher$$Lambda$lambda$contentLength$0$1::init$))},
	{"applyAsLong", "(JJ)J", nullptr, $PUBLIC},
	{}
};
$ClassInfo RequestPublishers$AggregatePublisher$$Lambda$lambda$contentLength$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.RequestPublishers$AggregatePublisher$$Lambda$lambda$contentLength$0$1",
	"java.lang.Object",
	"java.util.function.LongBinaryOperator",
	nullptr,
	methodInfos
};
$Class* RequestPublishers$AggregatePublisher$$Lambda$lambda$contentLength$0$1::load$($String* name, bool initialize) {
	$loadClass(RequestPublishers$AggregatePublisher$$Lambda$lambda$contentLength$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RequestPublishers$AggregatePublisher$$Lambda$lambda$contentLength$0$1::class$ = nullptr;

$FieldInfo _RequestPublishers$AggregatePublisher_FieldInfo_[] = {
	{"bodies", "Ljava/util/List;", "Ljava/util/List<Ljava/net/http/HttpRequest$BodyPublisher;>;", $FINAL, $field(RequestPublishers$AggregatePublisher, bodies)},
	{}
};

$MethodInfo _RequestPublishers$AggregatePublisher_MethodInfo_[] = {
	{"<init>", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/net/http/HttpRequest$BodyPublisher;>;)V", 0, $method(static_cast<void(RequestPublishers$AggregatePublisher::*)($List*)>(&RequestPublishers$AggregatePublisher::init$))},
	{"contentLength", "()J", nullptr, $PUBLIC},
	{"lambda$contentLength$0", "(JJ)J", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<int64_t(*)(int64_t,int64_t)>(&RequestPublishers$AggregatePublisher::lambda$contentLength$0))},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/nio/ByteBuffer;>;)V", $PUBLIC},
	{}
};

$InnerClassInfo _RequestPublishers$AggregatePublisher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RequestPublishers$AggregatePublisher", "jdk.internal.net.http.RequestPublishers", "AggregatePublisher", $PRIVATE | $STATIC | $FINAL},
	{"java.net.http.HttpRequest$BodyPublisher", "java.net.http.HttpRequest", "BodyPublisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RequestPublishers$AggregatePublisher_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.RequestPublishers$AggregatePublisher",
	"java.lang.Object",
	"java.net.http.HttpRequest$BodyPublisher",
	_RequestPublishers$AggregatePublisher_FieldInfo_,
	_RequestPublishers$AggregatePublisher_MethodInfo_,
	nullptr,
	nullptr,
	_RequestPublishers$AggregatePublisher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RequestPublishers"
};

$Object* allocate$RequestPublishers$AggregatePublisher($Class* clazz) {
	return $of($alloc(RequestPublishers$AggregatePublisher));
}

void RequestPublishers$AggregatePublisher::init$($List* bodies) {
	$set(this, bodies, bodies);
}

int64_t RequestPublishers$AggregatePublisher::contentLength() {
	$useLocalCurrentObjectStackCache();
	int64_t length = $nc($($nc($($nc($($nc(this->bodies)->stream()))->mapToLong(static_cast<$ToLongFunction*>($$new(RequestPublishers$AggregatePublisher$$Lambda$contentLength)))))->reduce(static_cast<$LongBinaryOperator*>($$new(RequestPublishers$AggregatePublisher$$Lambda$lambda$contentLength$0$1)))))->orElse(0);
	if (length < 0) {
		return -1;
	}
	return length;
}

void RequestPublishers$AggregatePublisher::subscribe($Flow$Subscriber* subscriber) {
	$nc(subscriber)->onSubscribe($$new($RequestPublishers$AggregateSubscription, this->bodies, subscriber));
}

int64_t RequestPublishers$AggregatePublisher::lambda$contentLength$0(int64_t a, int64_t b) {
	$init(RequestPublishers$AggregatePublisher);
	return a < 0 || b < 0 ? (int64_t)-1 : a + b;
}

RequestPublishers$AggregatePublisher::RequestPublishers$AggregatePublisher() {
}

$Class* RequestPublishers$AggregatePublisher::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RequestPublishers$AggregatePublisher$$Lambda$contentLength::classInfo$.name)) {
			return RequestPublishers$AggregatePublisher$$Lambda$contentLength::load$(name, initialize);
		}
		if (name->equals(RequestPublishers$AggregatePublisher$$Lambda$lambda$contentLength$0$1::classInfo$.name)) {
			return RequestPublishers$AggregatePublisher$$Lambda$lambda$contentLength$0$1::load$(name, initialize);
		}
	}
	$loadClass(RequestPublishers$AggregatePublisher, name, initialize, &_RequestPublishers$AggregatePublisher_ClassInfo_, allocate$RequestPublishers$AggregatePublisher);
	return class$;
}

$Class* RequestPublishers$AggregatePublisher::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk