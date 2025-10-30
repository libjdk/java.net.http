#include <jdk/internal/net/http/RequestPublishers$PublisherAdapter.h>

#include <java/util/Objects.h>
#include <java/util/concurrent/Flow$Publisher.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <jdk/internal/net/http/RequestPublishers.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $Objects = ::java::util::Objects;
using $Flow$Publisher = ::java::util::concurrent::Flow$Publisher;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $RequestPublishers = ::jdk::internal::net::http::RequestPublishers;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _RequestPublishers$PublisherAdapter_FieldInfo_[] = {
	{"publisher", "Ljava/util/concurrent/Flow$Publisher;", "Ljava/util/concurrent/Flow$Publisher<+Ljava/nio/ByteBuffer;>;", $PRIVATE | $FINAL, $field(RequestPublishers$PublisherAdapter, publisher)},
	{"contentLength", "J", nullptr, $PRIVATE | $FINAL, $field(RequestPublishers$PublisherAdapter, contentLength$)},
	{}
};

$MethodInfo _RequestPublishers$PublisherAdapter_MethodInfo_[] = {
	{"<init>", "(Ljava/util/concurrent/Flow$Publisher;J)V", "(Ljava/util/concurrent/Flow$Publisher<+Ljava/nio/ByteBuffer;>;J)V", $PUBLIC, $method(static_cast<void(RequestPublishers$PublisherAdapter::*)($Flow$Publisher*,int64_t)>(&RequestPublishers$PublisherAdapter::init$))},
	{"contentLength", "()J", nullptr, $PUBLIC | $FINAL},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/nio/ByteBuffer;>;)V", $PUBLIC | $FINAL},
	{}
};

$InnerClassInfo _RequestPublishers$PublisherAdapter_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RequestPublishers$PublisherAdapter", "jdk.internal.net.http.RequestPublishers", "PublisherAdapter", $PUBLIC | $STATIC | $FINAL},
	{"java.net.http.HttpRequest$BodyPublisher", "java.net.http.HttpRequest", "BodyPublisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RequestPublishers$PublisherAdapter_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.RequestPublishers$PublisherAdapter",
	"java.lang.Object",
	"java.net.http.HttpRequest$BodyPublisher",
	_RequestPublishers$PublisherAdapter_FieldInfo_,
	_RequestPublishers$PublisherAdapter_MethodInfo_,
	nullptr,
	nullptr,
	_RequestPublishers$PublisherAdapter_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RequestPublishers"
};

$Object* allocate$RequestPublishers$PublisherAdapter($Class* clazz) {
	return $of($alloc(RequestPublishers$PublisherAdapter));
}

void RequestPublishers$PublisherAdapter::init$($Flow$Publisher* publisher, int64_t contentLength) {
	$set(this, publisher, $cast($Flow$Publisher, $Objects::requireNonNull(publisher)));
	this->contentLength$ = contentLength;
}

int64_t RequestPublishers$PublisherAdapter::contentLength() {
	return this->contentLength$;
}

void RequestPublishers$PublisherAdapter::subscribe($Flow$Subscriber* subscriber) {
	$nc(this->publisher)->subscribe(subscriber);
}

RequestPublishers$PublisherAdapter::RequestPublishers$PublisherAdapter() {
}

$Class* RequestPublishers$PublisherAdapter::load$($String* name, bool initialize) {
	$loadClass(RequestPublishers$PublisherAdapter, name, initialize, &_RequestPublishers$PublisherAdapter_ClassInfo_, allocate$RequestPublishers$PublisherAdapter);
	return class$;
}

$Class* RequestPublishers$PublisherAdapter::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk