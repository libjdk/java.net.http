#include <jdk/internal/net/http/frame/FramesDecoder$FrameProcessor.h>

#include <jdk/internal/net/http/frame/FramesDecoder.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $FramesDecoder = ::jdk::internal::net::http::frame::FramesDecoder;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

$CompoundAttribute _FramesDecoder$FrameProcessor_Annotations_[] = {
	{"Ljava/lang/FunctionalInterface;", nullptr},
	{}
};

$MethodInfo _FramesDecoder$FrameProcessor_MethodInfo_[] = {
	{"processFrame", "(Ljdk/internal/net/http/frame/Http2Frame;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _FramesDecoder$FrameProcessor_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.frame.FramesDecoder$FrameProcessor", "jdk.internal.net.http.frame.FramesDecoder", "FrameProcessor", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _FramesDecoder$FrameProcessor_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.frame.FramesDecoder$FrameProcessor",
	nullptr,
	nullptr,
	nullptr,
	_FramesDecoder$FrameProcessor_MethodInfo_,
	nullptr,
	nullptr,
	_FramesDecoder$FrameProcessor_InnerClassesInfo_,
	_FramesDecoder$FrameProcessor_Annotations_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.frame.FramesDecoder"
};

$Object* allocate$FramesDecoder$FrameProcessor($Class* clazz) {
	return $of($alloc(FramesDecoder$FrameProcessor));
}

$Class* FramesDecoder$FrameProcessor::load$($String* name, bool initialize) {
	$loadClass(FramesDecoder$FrameProcessor, name, initialize, &_FramesDecoder$FrameProcessor_ClassInfo_, allocate$FramesDecoder$FrameProcessor);
	return class$;
}

$Class* FramesDecoder$FrameProcessor::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk