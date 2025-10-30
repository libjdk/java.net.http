#include <jdk/internal/net/http/RequestPublishers$IterablePublisher.h>

#include <java/io/Serializable.h>
#include <java/lang/Iterable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Iterator.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <jdk/internal/net/http/PullPublisher.h>
#include <jdk/internal/net/http/RequestPublishers$IterablePublisher$ByteBufferIterator.h>
#include <jdk/internal/net/http/RequestPublishers.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Iterable = ::java::lang::Iterable;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $Iterator = ::java::util::Iterator;
using $Objects = ::java::util::Objects;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $PullPublisher = ::jdk::internal::net::http::PullPublisher;
using $RequestPublishers = ::jdk::internal::net::http::RequestPublishers;
using $RequestPublishers$IterablePublisher$ByteBufferIterator = ::jdk::internal::net::http::RequestPublishers$IterablePublisher$ByteBufferIterator;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class RequestPublishers$IterablePublisher$$Lambda$iterator : public $Iterable {
	$class(RequestPublishers$IterablePublisher$$Lambda$iterator, $NO_CLASS_INIT, $Iterable)
public:
	void init$(RequestPublishers$IterablePublisher* inst) {
		$set(this, inst$, inst);
	}
	virtual $Iterator* iterator() override {
		 return $nc(inst$)->iterator();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RequestPublishers$IterablePublisher$$Lambda$iterator>());
	}
	RequestPublishers$IterablePublisher* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo RequestPublishers$IterablePublisher$$Lambda$iterator::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(RequestPublishers$IterablePublisher$$Lambda$iterator, inst$)},
	{}
};
$MethodInfo RequestPublishers$IterablePublisher$$Lambda$iterator::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/RequestPublishers$IterablePublisher;)V", nullptr, $PUBLIC, $method(static_cast<void(RequestPublishers$IterablePublisher$$Lambda$iterator::*)(RequestPublishers$IterablePublisher*)>(&RequestPublishers$IterablePublisher$$Lambda$iterator::init$))},
	{"iterator", "()Ljava/util/Iterator;", nullptr, $PUBLIC},
	{}
};
$ClassInfo RequestPublishers$IterablePublisher$$Lambda$iterator::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.RequestPublishers$IterablePublisher$$Lambda$iterator",
	"java.lang.Object",
	"java.lang.Iterable",
	fieldInfos,
	methodInfos
};
$Class* RequestPublishers$IterablePublisher$$Lambda$iterator::load$($String* name, bool initialize) {
	$loadClass(RequestPublishers$IterablePublisher$$Lambda$iterator, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RequestPublishers$IterablePublisher$$Lambda$iterator::class$ = nullptr;

$FieldInfo _RequestPublishers$IterablePublisher_FieldInfo_[] = {
	{"content", "Ljava/lang/Iterable;", "Ljava/lang/Iterable<[B>;", $PRIVATE | $FINAL, $field(RequestPublishers$IterablePublisher, content)},
	{"contentLength", "J", nullptr, $PRIVATE | $VOLATILE, $field(RequestPublishers$IterablePublisher, contentLength$)},
	{}
};

$MethodInfo _RequestPublishers$IterablePublisher_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Iterable;)V", "(Ljava/lang/Iterable<[B>;)V", $PUBLIC, $method(static_cast<void(RequestPublishers$IterablePublisher::*)($Iterable*)>(&RequestPublishers$IterablePublisher::init$))},
	{"computeLength", "(Ljava/lang/Iterable;)J", "(Ljava/lang/Iterable<[B>;)J", $STATIC, $method(static_cast<int64_t(*)($Iterable*)>(&RequestPublishers$IterablePublisher::computeLength))},
	{"contentLength", "()J", nullptr, $PUBLIC},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/nio/ByteBuffer;>;", $PUBLIC},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/nio/ByteBuffer;>;)V", $PUBLIC},
	{}
};

$InnerClassInfo _RequestPublishers$IterablePublisher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RequestPublishers$IterablePublisher", "jdk.internal.net.http.RequestPublishers", "IterablePublisher", $PUBLIC | $STATIC},
	{"java.net.http.HttpRequest$BodyPublisher", "java.net.http.HttpRequest", "BodyPublisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.RequestPublishers$IterablePublisher$ByteBufferIterator", "jdk.internal.net.http.RequestPublishers$IterablePublisher", "ByteBufferIterator", 0},
	{}
};

$ClassInfo _RequestPublishers$IterablePublisher_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.RequestPublishers$IterablePublisher",
	"java.lang.Object",
	"java.net.http.HttpRequest$BodyPublisher",
	_RequestPublishers$IterablePublisher_FieldInfo_,
	_RequestPublishers$IterablePublisher_MethodInfo_,
	nullptr,
	nullptr,
	_RequestPublishers$IterablePublisher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RequestPublishers"
};

$Object* allocate$RequestPublishers$IterablePublisher($Class* clazz) {
	return $of($alloc(RequestPublishers$IterablePublisher));
}

void RequestPublishers$IterablePublisher::init$($Iterable* content) {
	$set(this, content, $cast($Iterable, $Objects::requireNonNull(content)));
}

$Iterator* RequestPublishers$IterablePublisher::iterator() {
	return $new($RequestPublishers$IterablePublisher$ByteBufferIterator, this);
}

void RequestPublishers$IterablePublisher::subscribe($Flow$Subscriber* subscriber) {
	$useLocalCurrentObjectStackCache();
	$var($Iterable, iterable, static_cast<$Iterable*>($new(RequestPublishers$IterablePublisher$$Lambda$iterator, this)));
	$var($PullPublisher, delegate, $new($PullPublisher, iterable));
	delegate->subscribe(subscriber);
}

int64_t RequestPublishers$IterablePublisher::computeLength($Iterable* bytes) {
	$init(RequestPublishers$IterablePublisher);
	return -1;
}

int64_t RequestPublishers$IterablePublisher::contentLength() {
	if (this->contentLength$ == 0) {
		$synchronized(this) {
			if (this->contentLength$ == 0) {
				this->contentLength$ = computeLength(this->content);
			}
		}
	}
	return this->contentLength$;
}

RequestPublishers$IterablePublisher::RequestPublishers$IterablePublisher() {
}

$Class* RequestPublishers$IterablePublisher::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RequestPublishers$IterablePublisher$$Lambda$iterator::classInfo$.name)) {
			return RequestPublishers$IterablePublisher$$Lambda$iterator::load$(name, initialize);
		}
	}
	$loadClass(RequestPublishers$IterablePublisher, name, initialize, &_RequestPublishers$IterablePublisher_ClassInfo_, allocate$RequestPublishers$IterablePublisher);
	return class$;
}

$Class* RequestPublishers$IterablePublisher::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk