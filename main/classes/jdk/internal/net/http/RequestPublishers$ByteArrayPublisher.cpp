#include <jdk/internal/net/http/RequestPublishers$ByteArrayPublisher.h>

#include <java/lang/Iterable.h>
#include <java/lang/Math.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <jdk/internal/net/http/PullPublisher.h>
#include <jdk/internal/net/http/RequestPublishers.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef BUFSIZE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Iterable = ::java::lang::Iterable;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $PullPublisher = ::jdk::internal::net::http::PullPublisher;
using $RequestPublishers = ::jdk::internal::net::http::RequestPublishers;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _RequestPublishers$ByteArrayPublisher_FieldInfo_[] = {
	{"length", "I", nullptr, $PRIVATE | $FINAL, $field(RequestPublishers$ByteArrayPublisher, length)},
	{"content", "[B", nullptr, $PRIVATE | $FINAL, $field(RequestPublishers$ByteArrayPublisher, content)},
	{"offset", "I", nullptr, $PRIVATE | $FINAL, $field(RequestPublishers$ByteArrayPublisher, offset)},
	{"bufSize", "I", nullptr, $PRIVATE | $FINAL, $field(RequestPublishers$ByteArrayPublisher, bufSize)},
	{}
};

$MethodInfo _RequestPublishers$ByteArrayPublisher_MethodInfo_[] = {
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(RequestPublishers$ByteArrayPublisher::*)($bytes*)>(&RequestPublishers$ByteArrayPublisher::init$))},
	{"<init>", "([BII)V", nullptr, $PUBLIC, $method(static_cast<void(RequestPublishers$ByteArrayPublisher::*)($bytes*,int32_t,int32_t)>(&RequestPublishers$ByteArrayPublisher::init$))},
	{"<init>", "([BIII)V", nullptr, 0, $method(static_cast<void(RequestPublishers$ByteArrayPublisher::*)($bytes*,int32_t,int32_t,int32_t)>(&RequestPublishers$ByteArrayPublisher::init$))},
	{"contentLength", "()J", nullptr, $PUBLIC},
	{"copy", "([BII)Ljava/util/List;", "([BII)Ljava/util/List<Ljava/nio/ByteBuffer;>;", 0},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/nio/ByteBuffer;>;)V", $PUBLIC},
	{}
};

$InnerClassInfo _RequestPublishers$ByteArrayPublisher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RequestPublishers$ByteArrayPublisher", "jdk.internal.net.http.RequestPublishers", "ByteArrayPublisher", $PUBLIC | $STATIC},
	{"java.net.http.HttpRequest$BodyPublisher", "java.net.http.HttpRequest", "BodyPublisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RequestPublishers$ByteArrayPublisher_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.RequestPublishers$ByteArrayPublisher",
	"java.lang.Object",
	"java.net.http.HttpRequest$BodyPublisher",
	_RequestPublishers$ByteArrayPublisher_FieldInfo_,
	_RequestPublishers$ByteArrayPublisher_MethodInfo_,
	nullptr,
	nullptr,
	_RequestPublishers$ByteArrayPublisher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RequestPublishers"
};

$Object* allocate$RequestPublishers$ByteArrayPublisher($Class* clazz) {
	return $of($alloc(RequestPublishers$ByteArrayPublisher));
}

void RequestPublishers$ByteArrayPublisher::init$($bytes* content) {
	RequestPublishers$ByteArrayPublisher::init$(content, 0, $nc(content)->length);
}

void RequestPublishers$ByteArrayPublisher::init$($bytes* content, int32_t offset, int32_t length) {
	$init($Utils);
	RequestPublishers$ByteArrayPublisher::init$(content, offset, length, $Utils::BUFSIZE);
}

void RequestPublishers$ByteArrayPublisher::init$($bytes* content, int32_t offset, int32_t length, int32_t bufSize) {
	$set(this, content, content);
	this->offset = offset;
	this->length = length;
	this->bufSize = bufSize;
}

$List* RequestPublishers$ByteArrayPublisher::copy($bytes* content, int32_t offset, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$var($List, bufs, $new($ArrayList));
	while (length > 0) {
		$var($ByteBuffer, b, $ByteBuffer::allocate($Math::min(this->bufSize, length)));
		int32_t max = $nc(b)->capacity();
		int32_t tocopy = $Math::min(max, length);
		b->put(content, offset, tocopy);
		offset += tocopy;
		length -= tocopy;
		b->flip();
		bufs->add(b);
	}
	return bufs;
}

void RequestPublishers$ByteArrayPublisher::subscribe($Flow$Subscriber* subscriber) {
	$useLocalCurrentObjectStackCache();
	$var($List, copy, this->copy(this->content, this->offset, this->length));
	$var($PullPublisher, delegate, $new($PullPublisher, copy));
	delegate->subscribe(subscriber);
}

int64_t RequestPublishers$ByteArrayPublisher::contentLength() {
	return this->length;
}

RequestPublishers$ByteArrayPublisher::RequestPublishers$ByteArrayPublisher() {
}

$Class* RequestPublishers$ByteArrayPublisher::load$($String* name, bool initialize) {
	$loadClass(RequestPublishers$ByteArrayPublisher, name, initialize, &_RequestPublishers$ByteArrayPublisher_ClassInfo_, allocate$RequestPublishers$ByteArrayPublisher);
	return class$;
}

$Class* RequestPublishers$ByteArrayPublisher::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk