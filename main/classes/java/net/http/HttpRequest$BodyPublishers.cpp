#include <java/net/http/HttpRequest$BodyPublishers.h>

#include <java/lang/Iterable.h>
#include <java/net/http/HttpRequest$BodyPublisher.h>
#include <java/net/http/HttpRequest.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/nio/file/Path.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/Flow$Publisher.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/RequestPublishers$ByteArrayPublisher.h>
#include <jdk/internal/net/http/RequestPublishers$EmptyPublisher.h>
#include <jdk/internal/net/http/RequestPublishers$FilePublisher.h>
#include <jdk/internal/net/http/RequestPublishers$InputStreamPublisher.h>
#include <jdk/internal/net/http/RequestPublishers$IterablePublisher.h>
#include <jdk/internal/net/http/RequestPublishers$PublisherAdapter.h>
#include <jdk/internal/net/http/RequestPublishers$StringPublisher.h>
#include <jdk/internal/net/http/RequestPublishers.h>
#include <jcpp.h>

#undef UTF_8

using $HttpRequest$BodyPublisherArray = $Array<::java::net::http::HttpRequest$BodyPublisher>;
using $ClassInfo = ::java::lang::ClassInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Iterable = ::java::lang::Iterable;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpRequest = ::java::net::http::HttpRequest;
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $Path = ::java::nio::file::Path;
using $Objects = ::java::util::Objects;
using $Flow$Publisher = ::java::util::concurrent::Flow$Publisher;
using $Supplier = ::java::util::function::Supplier;
using $RequestPublishers = ::jdk::internal::net::http::RequestPublishers;
using $RequestPublishers$ByteArrayPublisher = ::jdk::internal::net::http::RequestPublishers$ByteArrayPublisher;
using $RequestPublishers$EmptyPublisher = ::jdk::internal::net::http::RequestPublishers$EmptyPublisher;
using $RequestPublishers$FilePublisher = ::jdk::internal::net::http::RequestPublishers$FilePublisher;
using $RequestPublishers$InputStreamPublisher = ::jdk::internal::net::http::RequestPublishers$InputStreamPublisher;
using $RequestPublishers$IterablePublisher = ::jdk::internal::net::http::RequestPublishers$IterablePublisher;
using $RequestPublishers$PublisherAdapter = ::jdk::internal::net::http::RequestPublishers$PublisherAdapter;
using $RequestPublishers$StringPublisher = ::jdk::internal::net::http::RequestPublishers$StringPublisher;

namespace java {
	namespace net {
		namespace http {

$MethodInfo _HttpRequest$BodyPublishers_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(HttpRequest$BodyPublishers::*)()>(&HttpRequest$BodyPublishers::init$))},
	{"concat", "([Ljava/net/http/HttpRequest$BodyPublisher;)Ljava/net/http/HttpRequest$BodyPublisher;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $method(static_cast<$HttpRequest$BodyPublisher*(*)($HttpRequest$BodyPublisherArray*)>(&HttpRequest$BodyPublishers::concat))},
	{"fromPublisher", "(Ljava/util/concurrent/Flow$Publisher;)Ljava/net/http/HttpRequest$BodyPublisher;", "(Ljava/util/concurrent/Flow$Publisher<+Ljava/nio/ByteBuffer;>;)Ljava/net/http/HttpRequest$BodyPublisher;", $PUBLIC | $STATIC, $method(static_cast<$HttpRequest$BodyPublisher*(*)($Flow$Publisher*)>(&HttpRequest$BodyPublishers::fromPublisher))},
	{"fromPublisher", "(Ljava/util/concurrent/Flow$Publisher;J)Ljava/net/http/HttpRequest$BodyPublisher;", "(Ljava/util/concurrent/Flow$Publisher<+Ljava/nio/ByteBuffer;>;J)Ljava/net/http/HttpRequest$BodyPublisher;", $PUBLIC | $STATIC, $method(static_cast<$HttpRequest$BodyPublisher*(*)($Flow$Publisher*,int64_t)>(&HttpRequest$BodyPublishers::fromPublisher))},
	{"noBody", "()Ljava/net/http/HttpRequest$BodyPublisher;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$HttpRequest$BodyPublisher*(*)()>(&HttpRequest$BodyPublishers::noBody))},
	{"ofByteArray", "([B)Ljava/net/http/HttpRequest$BodyPublisher;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$HttpRequest$BodyPublisher*(*)($bytes*)>(&HttpRequest$BodyPublishers::ofByteArray))},
	{"ofByteArray", "([BII)Ljava/net/http/HttpRequest$BodyPublisher;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$HttpRequest$BodyPublisher*(*)($bytes*,int32_t,int32_t)>(&HttpRequest$BodyPublishers::ofByteArray))},
	{"ofByteArrays", "(Ljava/lang/Iterable;)Ljava/net/http/HttpRequest$BodyPublisher;", "(Ljava/lang/Iterable<[B>;)Ljava/net/http/HttpRequest$BodyPublisher;", $PUBLIC | $STATIC, $method(static_cast<$HttpRequest$BodyPublisher*(*)($Iterable*)>(&HttpRequest$BodyPublishers::ofByteArrays))},
	{"ofFile", "(Ljava/nio/file/Path;)Ljava/net/http/HttpRequest$BodyPublisher;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$HttpRequest$BodyPublisher*(*)($Path*)>(&HttpRequest$BodyPublishers::ofFile)), "java.io.FileNotFoundException"},
	{"ofInputStream", "(Ljava/util/function/Supplier;)Ljava/net/http/HttpRequest$BodyPublisher;", "(Ljava/util/function/Supplier<+Ljava/io/InputStream;>;)Ljava/net/http/HttpRequest$BodyPublisher;", $PUBLIC | $STATIC, $method(static_cast<$HttpRequest$BodyPublisher*(*)($Supplier*)>(&HttpRequest$BodyPublishers::ofInputStream))},
	{"ofString", "(Ljava/lang/String;)Ljava/net/http/HttpRequest$BodyPublisher;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$HttpRequest$BodyPublisher*(*)($String*)>(&HttpRequest$BodyPublishers::ofString))},
	{"ofString", "(Ljava/lang/String;Ljava/nio/charset/Charset;)Ljava/net/http/HttpRequest$BodyPublisher;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$HttpRequest$BodyPublisher*(*)($String*,$Charset*)>(&HttpRequest$BodyPublishers::ofString))},
	{}
};

$InnerClassInfo _HttpRequest$BodyPublishers_InnerClassesInfo_[] = {
	{"java.net.http.HttpRequest$BodyPublishers", "java.net.http.HttpRequest", "BodyPublishers", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _HttpRequest$BodyPublishers_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.net.http.HttpRequest$BodyPublishers",
	"java.lang.Object",
	nullptr,
	nullptr,
	_HttpRequest$BodyPublishers_MethodInfo_,
	nullptr,
	nullptr,
	_HttpRequest$BodyPublishers_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.net.http.HttpRequest"
};

$Object* allocate$HttpRequest$BodyPublishers($Class* clazz) {
	return $of($alloc(HttpRequest$BodyPublishers));
}

void HttpRequest$BodyPublishers::init$() {
}

$HttpRequest$BodyPublisher* HttpRequest$BodyPublishers::fromPublisher($Flow$Publisher* publisher) {
	return $new($RequestPublishers$PublisherAdapter, publisher, -1);
}

$HttpRequest$BodyPublisher* HttpRequest$BodyPublishers::fromPublisher($Flow$Publisher* publisher, int64_t contentLength) {
	$useLocalCurrentObjectStackCache();
	if (contentLength < 1) {
		$throwNew($IllegalArgumentException, $$str({"non-positive contentLength: "_s, $$str(contentLength)}));
	}
	return $new($RequestPublishers$PublisherAdapter, publisher, contentLength);
}

$HttpRequest$BodyPublisher* HttpRequest$BodyPublishers::ofString($String* body) {
	$init($StandardCharsets);
	return ofString(body, $StandardCharsets::UTF_8);
}

$HttpRequest$BodyPublisher* HttpRequest$BodyPublishers::ofString($String* s, $Charset* charset) {
	return $new($RequestPublishers$StringPublisher, s, charset);
}

$HttpRequest$BodyPublisher* HttpRequest$BodyPublishers::ofInputStream($Supplier* streamSupplier) {
	return $new($RequestPublishers$InputStreamPublisher, streamSupplier);
}

$HttpRequest$BodyPublisher* HttpRequest$BodyPublishers::ofByteArray($bytes* buf) {
	return $new($RequestPublishers$ByteArrayPublisher, buf);
}

$HttpRequest$BodyPublisher* HttpRequest$BodyPublishers::ofByteArray($bytes* buf, int32_t offset, int32_t length) {
	$Objects::checkFromIndexSize(offset, length, $nc(buf)->length);
	return $new($RequestPublishers$ByteArrayPublisher, buf, offset, length);
}

$HttpRequest$BodyPublisher* HttpRequest$BodyPublishers::ofFile($Path* path) {
	$Objects::requireNonNull(path);
	return $RequestPublishers$FilePublisher::create(path);
}

$HttpRequest$BodyPublisher* HttpRequest$BodyPublishers::ofByteArrays($Iterable* iter) {
	return $new($RequestPublishers$IterablePublisher, iter);
}

$HttpRequest$BodyPublisher* HttpRequest$BodyPublishers::noBody() {
	return $new($RequestPublishers$EmptyPublisher);
}

$HttpRequest$BodyPublisher* HttpRequest$BodyPublishers::concat($HttpRequest$BodyPublisherArray* publishers) {
	return $RequestPublishers::concat($cast($HttpRequest$BodyPublisherArray, $Objects::requireNonNull(publishers)));
}

HttpRequest$BodyPublishers::HttpRequest$BodyPublishers() {
}

$Class* HttpRequest$BodyPublishers::load$($String* name, bool initialize) {
	$loadClass(HttpRequest$BodyPublishers, name, initialize, &_HttpRequest$BodyPublishers_ClassInfo_, allocate$HttpRequest$BodyPublishers);
	return class$;
}

$Class* HttpRequest$BodyPublishers::class$ = nullptr;

		} // http
	} // net
} // java