#include <jdk/internal/net/http/RequestPublishers.h>

#include <java/net/http/HttpRequest$BodyPublisher.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <jdk/internal/net/http/RequestPublishers$AggregatePublisher.h>
#include <jdk/internal/net/http/RequestPublishers$EmptyPublisher.h>
#include <jcpp.h>

using $HttpRequest$BodyPublisherArray = $Array<::java::net::http::HttpRequest$BodyPublisher>;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $RequestPublishers$AggregatePublisher = ::jdk::internal::net::http::RequestPublishers$AggregatePublisher;
using $RequestPublishers$EmptyPublisher = ::jdk::internal::net::http::RequestPublishers$EmptyPublisher;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$MethodInfo _RequestPublishers_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(RequestPublishers::*)()>(&RequestPublishers::init$))},
	{"concat", "([Ljava/net/http/HttpRequest$BodyPublisher;)Ljava/net/http/HttpRequest$BodyPublisher;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $method(static_cast<$HttpRequest$BodyPublisher*(*)($HttpRequest$BodyPublisherArray*)>(&RequestPublishers::concat))},
	{}
};

$InnerClassInfo _RequestPublishers_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RequestPublishers$AggregateSubscription", "jdk.internal.net.http.RequestPublishers", "AggregateSubscription", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.net.http.RequestPublishers$AggregatePublisher", "jdk.internal.net.http.RequestPublishers", "AggregatePublisher", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.net.http.RequestPublishers$PublisherAdapter", "jdk.internal.net.http.RequestPublishers", "PublisherAdapter", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.net.http.RequestPublishers$InputStreamPublisher", "jdk.internal.net.http.RequestPublishers", "InputStreamPublisher", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.RequestPublishers$StreamIterator", "jdk.internal.net.http.RequestPublishers", "StreamIterator", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.RequestPublishers$FilePublisher", "jdk.internal.net.http.RequestPublishers", "FilePublisher", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.RequestPublishers$EmptyPublisher", "jdk.internal.net.http.RequestPublishers", "EmptyPublisher", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.RequestPublishers$StringPublisher", "jdk.internal.net.http.RequestPublishers", "StringPublisher", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.RequestPublishers$IterablePublisher", "jdk.internal.net.http.RequestPublishers", "IterablePublisher", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.RequestPublishers$ByteArrayPublisher", "jdk.internal.net.http.RequestPublishers", "ByteArrayPublisher", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _RequestPublishers_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.RequestPublishers",
	"java.lang.Object",
	nullptr,
	nullptr,
	_RequestPublishers_MethodInfo_,
	nullptr,
	nullptr,
	_RequestPublishers_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RequestPublishers$AggregateSubscription,jdk.internal.net.http.RequestPublishers$AggregatePublisher,jdk.internal.net.http.RequestPublishers$PublisherAdapter,jdk.internal.net.http.RequestPublishers$InputStreamPublisher,jdk.internal.net.http.RequestPublishers$StreamIterator,jdk.internal.net.http.RequestPublishers$FilePublisher,jdk.internal.net.http.RequestPublishers$EmptyPublisher,jdk.internal.net.http.RequestPublishers$StringPublisher,jdk.internal.net.http.RequestPublishers$IterablePublisher,jdk.internal.net.http.RequestPublishers$IterablePublisher$ByteBufferIterator,jdk.internal.net.http.RequestPublishers$ByteArrayPublisher"
};

$Object* allocate$RequestPublishers($Class* clazz) {
	return $of($alloc(RequestPublishers));
}

void RequestPublishers::init$() {
}

$HttpRequest$BodyPublisher* RequestPublishers::concat($HttpRequest$BodyPublisherArray* publishers) {
	if ($nc(publishers)->length == 0) {
		return $new($RequestPublishers$EmptyPublisher);
	} else if (publishers->length == 1) {
		return $cast($HttpRequest$BodyPublisher, $Objects::requireNonNull(publishers->get(0)));
	} else {
		return $new($RequestPublishers$AggregatePublisher, $($List::of(publishers)));
	}
}

RequestPublishers::RequestPublishers() {
}

$Class* RequestPublishers::load$($String* name, bool initialize) {
	$loadClass(RequestPublishers, name, initialize, &_RequestPublishers_ClassInfo_, allocate$RequestPublishers);
	return class$;
}

$Class* RequestPublishers::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk