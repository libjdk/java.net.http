#include <jdk/internal/net/http/frame/HeaderFrame.h>

#include <java/util/List.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jcpp.h>

#undef END_HEADERS
#undef END_STREAM
#undef MAX_VALUE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $List = ::java::util::List;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

$FieldInfo _HeaderFrame_FieldInfo_[] = {
	{"headerLength", "I", nullptr, $FINAL, $field(HeaderFrame, headerLength)},
	{"headerBlocks", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/ByteBuffer;>;", $FINAL, $field(HeaderFrame, headerBlocks)},
	{"END_STREAM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HeaderFrame, END_STREAM)},
	{"END_HEADERS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(HeaderFrame, END_HEADERS)},
	{}
};

$MethodInfo _HeaderFrame_MethodInfo_[] = {
	{"<init>", "(IILjava/util/List;)V", "(IILjava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, $method(static_cast<void(HeaderFrame::*)(int32_t,int32_t,$List*)>(&HeaderFrame::init$))},
	{"endHeaders", "()Z", nullptr, $PUBLIC},
	{"flagAsString", "(I)Ljava/lang/String;", nullptr, $PUBLIC},
	{"getHeaderBlock", "()Ljava/util/List;", "()Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PUBLIC},
	{"getHeaderLength", "()I", nullptr, 0},
	{}
};

$ClassInfo _HeaderFrame_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.frame.HeaderFrame",
	"jdk.internal.net.http.frame.Http2Frame",
	nullptr,
	_HeaderFrame_FieldInfo_,
	_HeaderFrame_MethodInfo_
};

$Object* allocate$HeaderFrame($Class* clazz) {
	return $of($alloc(HeaderFrame));
}

void HeaderFrame::init$(int32_t streamid, int32_t flags, $List* headerBlocks) {
	$Http2Frame::init$(streamid, flags);
	$set(this, headerBlocks, headerBlocks);
	this->headerLength = $Utils::remaining(headerBlocks, $Integer::MAX_VALUE);
}

$String* HeaderFrame::flagAsString(int32_t flag) {

	$var($String, var$0, nullptr)
	switch (flag) {
	case HeaderFrame::END_HEADERS:
		{
			$assign(var$0, "END_HEADERS"_s);
			break;
		}
	case HeaderFrame::END_STREAM:
		{
			$assign(var$0, "END_STREAM"_s);
			break;
		}
	default:
		{
			$assign(var$0, $Http2Frame::flagAsString(flag));
			break;
		}
	}
	return var$0;
}

$List* HeaderFrame::getHeaderBlock() {
	return this->headerBlocks;
}

int32_t HeaderFrame::getHeaderLength() {
	return this->headerLength;
}

bool HeaderFrame::endHeaders() {
	return getFlag(HeaderFrame::END_HEADERS);
}

HeaderFrame::HeaderFrame() {
}

$Class* HeaderFrame::load$($String* name, bool initialize) {
	$loadClass(HeaderFrame, name, initialize, &_HeaderFrame_ClassInfo_, allocate$HeaderFrame);
	return class$;
}

$Class* HeaderFrame::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk