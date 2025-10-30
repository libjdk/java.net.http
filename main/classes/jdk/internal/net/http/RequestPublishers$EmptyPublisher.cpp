#include <jdk/internal/net/http/RequestPublishers$EmptyPublisher.h>

#include <java/lang/Iterable.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/List.h>
#include <java/util/concurrent/Flow$Publisher.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <jdk/internal/net/http/PullPublisher.h>
#include <jdk/internal/net/http/RequestPublishers.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Iterable = ::java::lang::Iterable;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;
using $Flow$Publisher = ::java::util::concurrent::Flow$Publisher;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $PullPublisher = ::jdk::internal::net::http::PullPublisher;
using $RequestPublishers = ::jdk::internal::net::http::RequestPublishers;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _RequestPublishers$EmptyPublisher_FieldInfo_[] = {
	{"delegate", "Ljava/util/concurrent/Flow$Publisher;", "Ljava/util/concurrent/Flow$Publisher<Ljava/nio/ByteBuffer;>;", $PRIVATE | $FINAL, $field(RequestPublishers$EmptyPublisher, delegate)},
	{}
};

$MethodInfo _RequestPublishers$EmptyPublisher_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RequestPublishers$EmptyPublisher::*)()>(&RequestPublishers$EmptyPublisher::init$))},
	{"contentLength", "()J", nullptr, $PUBLIC},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/nio/ByteBuffer;>;)V", $PUBLIC},
	{}
};

$InnerClassInfo _RequestPublishers$EmptyPublisher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RequestPublishers$EmptyPublisher", "jdk.internal.net.http.RequestPublishers", "EmptyPublisher", $PUBLIC | $STATIC},
	{"java.net.http.HttpRequest$BodyPublisher", "java.net.http.HttpRequest", "BodyPublisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RequestPublishers$EmptyPublisher_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.RequestPublishers$EmptyPublisher",
	"java.lang.Object",
	"java.net.http.HttpRequest$BodyPublisher",
	_RequestPublishers$EmptyPublisher_FieldInfo_,
	_RequestPublishers$EmptyPublisher_MethodInfo_,
	nullptr,
	nullptr,
	_RequestPublishers$EmptyPublisher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RequestPublishers"
};

$Object* allocate$RequestPublishers$EmptyPublisher($Class* clazz) {
	return $of($alloc(RequestPublishers$EmptyPublisher));
}

void RequestPublishers$EmptyPublisher::init$() {
	$set(this, delegate, $new($PullPublisher, $($Collections::emptyList()), nullptr));
}

int64_t RequestPublishers$EmptyPublisher::contentLength() {
	return 0;
}

void RequestPublishers$EmptyPublisher::subscribe($Flow$Subscriber* subscriber) {
	$nc(this->delegate)->subscribe(subscriber);
}

RequestPublishers$EmptyPublisher::RequestPublishers$EmptyPublisher() {
}

$Class* RequestPublishers$EmptyPublisher::load$($String* name, bool initialize) {
	$loadClass(RequestPublishers$EmptyPublisher, name, initialize, &_RequestPublishers$EmptyPublisher_ClassInfo_, allocate$RequestPublishers$EmptyPublisher);
	return class$;
}

$Class* RequestPublishers$EmptyPublisher::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk