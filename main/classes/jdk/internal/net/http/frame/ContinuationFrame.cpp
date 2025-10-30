#include <jdk/internal/net/http/frame/ContinuationFrame.h>

#include <java/nio/ByteBuffer.h>
#include <java/util/List.h>
#include <jdk/internal/net/http/frame/HeaderFrame.h>
#include <jcpp.h>

#undef TYPE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $List = ::java::util::List;
using $HeaderFrame = ::jdk::internal::net::http::frame::HeaderFrame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

$FieldInfo _ContinuationFrame_FieldInfo_[] = {
	{"TYPE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ContinuationFrame, TYPE)},
	{}
};

$MethodInfo _ContinuationFrame_MethodInfo_[] = {
	{"<init>", "(IILjava/util/List;)V", "(IILjava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, $method(static_cast<void(ContinuationFrame::*)(int32_t,int32_t,$List*)>(&ContinuationFrame::init$))},
	{"<init>", "(ILjava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $method(static_cast<void(ContinuationFrame::*)(int32_t,$ByteBuffer*)>(&ContinuationFrame::init$))},
	{"length", "()I", nullptr, 0},
	{"type", "()I", nullptr, $PUBLIC},
	{}
};

$ClassInfo _ContinuationFrame_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.frame.ContinuationFrame",
	"jdk.internal.net.http.frame.HeaderFrame",
	nullptr,
	_ContinuationFrame_FieldInfo_,
	_ContinuationFrame_MethodInfo_
};

$Object* allocate$ContinuationFrame($Class* clazz) {
	return $of($alloc(ContinuationFrame));
}

void ContinuationFrame::init$(int32_t streamid, int32_t flags, $List* headerBlocks) {
	$HeaderFrame::init$(streamid, flags, headerBlocks);
}

void ContinuationFrame::init$(int32_t streamid, $ByteBuffer* headersBlock) {
	ContinuationFrame::init$(streamid, 0, $($List::of($of(headersBlock))));
}

int32_t ContinuationFrame::type() {
	return ContinuationFrame::TYPE;
}

int32_t ContinuationFrame::length() {
	return this->headerLength;
}

ContinuationFrame::ContinuationFrame() {
}

$Class* ContinuationFrame::load$($String* name, bool initialize) {
	$loadClass(ContinuationFrame, name, initialize, &_ContinuationFrame_ClassInfo_, allocate$ContinuationFrame);
	return class$;
}

$Class* ContinuationFrame::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk