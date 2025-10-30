#include <jdk/internal/net/http/RequestPublishers$StringPublisher.h>

#include <java/nio/charset/Charset.h>
#include <jdk/internal/net/http/RequestPublishers$ByteArrayPublisher.h>
#include <jdk/internal/net/http/RequestPublishers.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $RequestPublishers = ::jdk::internal::net::http::RequestPublishers;
using $RequestPublishers$ByteArrayPublisher = ::jdk::internal::net::http::RequestPublishers$ByteArrayPublisher;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$MethodInfo _RequestPublishers$StringPublisher_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/nio/charset/Charset;)V", nullptr, $PUBLIC, $method(static_cast<void(RequestPublishers$StringPublisher::*)($String*,$Charset*)>(&RequestPublishers$StringPublisher::init$))},
	{}
};

$InnerClassInfo _RequestPublishers$StringPublisher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RequestPublishers$StringPublisher", "jdk.internal.net.http.RequestPublishers", "StringPublisher", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.RequestPublishers$ByteArrayPublisher", "jdk.internal.net.http.RequestPublishers", "ByteArrayPublisher", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _RequestPublishers$StringPublisher_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.RequestPublishers$StringPublisher",
	"jdk.internal.net.http.RequestPublishers$ByteArrayPublisher",
	nullptr,
	nullptr,
	_RequestPublishers$StringPublisher_MethodInfo_,
	nullptr,
	nullptr,
	_RequestPublishers$StringPublisher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RequestPublishers"
};

$Object* allocate$RequestPublishers$StringPublisher($Class* clazz) {
	return $of($alloc(RequestPublishers$StringPublisher));
}

void RequestPublishers$StringPublisher::init$($String* content, $Charset* charset) {
	$RequestPublishers$ByteArrayPublisher::init$($($nc(content)->getBytes(charset)));
}

RequestPublishers$StringPublisher::RequestPublishers$StringPublisher() {
}

$Class* RequestPublishers$StringPublisher::load$($String* name, bool initialize) {
	$loadClass(RequestPublishers$StringPublisher, name, initialize, &_RequestPublishers$StringPublisher_ClassInfo_, allocate$RequestPublishers$StringPublisher);
	return class$;
}

$Class* RequestPublishers$StringPublisher::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk