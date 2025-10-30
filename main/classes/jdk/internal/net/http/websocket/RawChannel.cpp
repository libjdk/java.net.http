#include <jdk/internal/net/http/websocket/RawChannel.h>

#include <java/nio/ByteBuffer.h>
#include <jdk/internal/net/http/websocket/RawChannel$RawEvent.h>
#include <jcpp.h>

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $Closeable = ::java::io::Closeable;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $RawChannel$RawEvent = ::jdk::internal::net::http::websocket::RawChannel$RawEvent;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$MethodInfo _RawChannel_MethodInfo_[] = {
	{"close", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{"initialByteBuffer", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.lang.IllegalStateException"},
	{"read", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"registerEvent", "(Ljdk/internal/net/http/websocket/RawChannel$RawEvent;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"shutdownInput", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"shutdownOutput", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"write", "([Ljava/nio/ByteBuffer;II)J", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _RawChannel_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.RawChannel$RawEvent", "jdk.internal.net.http.websocket.RawChannel", "RawEvent", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.websocket.RawChannel$Provider", "jdk.internal.net.http.websocket.RawChannel", "Provider", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RawChannel_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.websocket.RawChannel",
	nullptr,
	"java.io.Closeable",
	nullptr,
	_RawChannel_MethodInfo_,
	nullptr,
	nullptr,
	_RawChannel_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.RawChannel$RawEvent,jdk.internal.net.http.websocket.RawChannel$Provider"
};

$Object* allocate$RawChannel($Class* clazz) {
	return $of($alloc(RawChannel));
}

$Class* RawChannel::load$($String* name, bool initialize) {
	$loadClass(RawChannel, name, initialize, &_RawChannel_ClassInfo_, allocate$RawChannel);
	return class$;
}

$Class* RawChannel::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk