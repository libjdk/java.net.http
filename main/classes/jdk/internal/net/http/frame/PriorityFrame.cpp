#include <jdk/internal/net/http/frame/PriorityFrame.h>

#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jcpp.h>

#undef TYPE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

$FieldInfo _PriorityFrame_FieldInfo_[] = {
	{"streamDependency", "I", nullptr, $PRIVATE | $FINAL, $field(PriorityFrame, streamDependency$)},
	{"weight", "I", nullptr, $PRIVATE | $FINAL, $field(PriorityFrame, weight$)},
	{"exclusive", "Z", nullptr, $PRIVATE | $FINAL, $field(PriorityFrame, exclusive$)},
	{"TYPE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(PriorityFrame, TYPE)},
	{}
};

$MethodInfo _PriorityFrame_MethodInfo_[] = {
	{"<init>", "(IIZI)V", nullptr, $PUBLIC, $method(static_cast<void(PriorityFrame::*)(int32_t,int32_t,bool,int32_t)>(&PriorityFrame::init$))},
	{"exclusive", "()Z", nullptr, $PUBLIC},
	{"length", "()I", nullptr, 0},
	{"streamDependency", "()I", nullptr, $PUBLIC},
	{"type", "()I", nullptr, $PUBLIC},
	{"weight", "()I", nullptr, $PUBLIC},
	{}
};

$ClassInfo _PriorityFrame_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.frame.PriorityFrame",
	"jdk.internal.net.http.frame.Http2Frame",
	nullptr,
	_PriorityFrame_FieldInfo_,
	_PriorityFrame_MethodInfo_
};

$Object* allocate$PriorityFrame($Class* clazz) {
	return $of($alloc(PriorityFrame));
}

void PriorityFrame::init$(int32_t streamId, int32_t streamDependency, bool exclusive, int32_t weight) {
	$Http2Frame::init$(streamId, 0);
	this->streamDependency$ = streamDependency;
	this->exclusive$ = exclusive;
	this->weight$ = weight;
}

int32_t PriorityFrame::type() {
	return PriorityFrame::TYPE;
}

int32_t PriorityFrame::length() {
	return 5;
}

int32_t PriorityFrame::streamDependency() {
	return this->streamDependency$;
}

int32_t PriorityFrame::weight() {
	return this->weight$;
}

bool PriorityFrame::exclusive() {
	return this->exclusive$;
}

PriorityFrame::PriorityFrame() {
}

$Class* PriorityFrame::load$($String* name, bool initialize) {
	$loadClass(PriorityFrame, name, initialize, &_PriorityFrame_ClassInfo_, allocate$PriorityFrame);
	return class$;
}

$Class* PriorityFrame::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk