#include <jdk/internal/net/http/HttpConnection$HttpPublisher.h>

#include <java/util/List.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $List = ::java::util::List;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $FlowTube$TubePublisher = ::jdk::internal::net::http::common::FlowTube$TubePublisher;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$MethodInfo _HttpConnection$HttpPublisher_MethodInfo_[] = {
	{"enqueue", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"enqueueUnordered", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"signalEnqueued", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _HttpConnection$HttpPublisher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.HttpConnection$HttpPublisher", "jdk.internal.net.http.HttpConnection", "HttpPublisher", $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.common.FlowTube$TubePublisher", "jdk.internal.net.http.common.FlowTube", "TubePublisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpConnection$HttpPublisher_ClassInfo_ = {
	$INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.HttpConnection$HttpPublisher",
	nullptr,
	"jdk.internal.net.http.common.FlowTube$TubePublisher",
	nullptr,
	_HttpConnection$HttpPublisher_MethodInfo_,
	nullptr,
	nullptr,
	_HttpConnection$HttpPublisher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HttpConnection"
};

$Object* allocate$HttpConnection$HttpPublisher($Class* clazz) {
	return $of($alloc(HttpConnection$HttpPublisher));
}

$Class* HttpConnection$HttpPublisher::load$($String* name, bool initialize) {
	$loadClass(HttpConnection$HttpPublisher, name, initialize, &_HttpConnection$HttpPublisher_ClassInfo_, allocate$HttpConnection$HttpPublisher);
	return class$;
}

$Class* HttpConnection$HttpPublisher::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk