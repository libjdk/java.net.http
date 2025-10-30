#include <jdk/internal/net/http/Http2Connection$ConnectionWindowUpdateSender.h>

#include <jdk/internal/net/http/Http2Connection.h>
#include <jdk/internal/net/http/WindowUpdateSender.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Http2Connection = ::jdk::internal::net::http::Http2Connection;
using $WindowUpdateSender = ::jdk::internal::net::http::WindowUpdateSender;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Http2Connection$ConnectionWindowUpdateSender_FieldInfo_[] = {
	{"initialWindowSize", "I", nullptr, $FINAL, $field(Http2Connection$ConnectionWindowUpdateSender, initialWindowSize)},
	{}
};

$MethodInfo _Http2Connection$ConnectionWindowUpdateSender_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Http2Connection;I)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$ConnectionWindowUpdateSender::*)($Http2Connection*,int32_t)>(&Http2Connection$ConnectionWindowUpdateSender::init$))},
	{"getStreamId", "()I", nullptr, 0},
	{}
};

$InnerClassInfo _Http2Connection$ConnectionWindowUpdateSender_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http2Connection$ConnectionWindowUpdateSender", "jdk.internal.net.http.Http2Connection", "ConnectionWindowUpdateSender", $STATIC | $FINAL},
	{}
};

$ClassInfo _Http2Connection$ConnectionWindowUpdateSender_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Http2Connection$ConnectionWindowUpdateSender",
	"jdk.internal.net.http.WindowUpdateSender",
	nullptr,
	_Http2Connection$ConnectionWindowUpdateSender_FieldInfo_,
	_Http2Connection$ConnectionWindowUpdateSender_MethodInfo_,
	nullptr,
	nullptr,
	_Http2Connection$ConnectionWindowUpdateSender_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http2Connection"
};

$Object* allocate$Http2Connection$ConnectionWindowUpdateSender($Class* clazz) {
	return $of($alloc(Http2Connection$ConnectionWindowUpdateSender));
}

void Http2Connection$ConnectionWindowUpdateSender::init$($Http2Connection* connection, int32_t initialWindowSize) {
	$WindowUpdateSender::init$(connection, initialWindowSize);
	this->initialWindowSize = initialWindowSize;
}

int32_t Http2Connection$ConnectionWindowUpdateSender::getStreamId() {
	return 0;
}

Http2Connection$ConnectionWindowUpdateSender::Http2Connection$ConnectionWindowUpdateSender() {
}

$Class* Http2Connection$ConnectionWindowUpdateSender::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$ConnectionWindowUpdateSender, name, initialize, &_Http2Connection$ConnectionWindowUpdateSender_ClassInfo_, allocate$Http2Connection$ConnectionWindowUpdateSender);
	return class$;
}

$Class* Http2Connection$ConnectionWindowUpdateSender::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk